/*************
 *
 * Filename:	woorinet-button.c
 *
 * Purpose:	 Woorinet button driver
 *
 * Copyright: (c) 2022 WOORINET. All rights reserved.
 *
 **************/

#include <linux/device.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/platform_device.h>
#include <linux/input.h>
#include <linux/interrupt.h>
#include <linux/err.h>
#include <linux/pm.h>
#include <linux/gpio.h>
#include <linux/of_gpio.h>

#include <woorinet/aaudefs.h>
#include <woorinet/bsudefs.h>

struct button_data {
	int gpio;
	int irq;
	unsigned int key_code;
	char name[64];
	struct platform_device *pdev;
	struct input_dev *input;
	struct delayed_work check_work;
};

/************
 *
 * Name:     woorinet_button_check_work
 *
 * Purpose:  check specfic gpio to trigger the factory reset action
 *
 * Parms:    work - work queue pointer
 *
 * Return:   none
 *
 * Abort:    none
 *
 ************/
static void woorinet_button_check_work(struct work_struct *work)
{
	int gpioval;
	struct button_data *btndata;
	struct platform_device *pdev;

	btndata = container_of(work, struct button_data, check_work.work);
	pdev = btndata->pdev;
	gpioval = gpio_get_value(btndata->gpio);
	if (!gpioval)
	{
		dev_info(&pdev->dev, "Factory Reset\n");
		input_report_key(btndata->input, btndata->key_code, 1);
		input_sync(btndata->input);
	}
}

/************
 *
 * Name:     woorinet_button_irq_handler
 *
 * Purpose:  woorinet gpio intterrupt handler
 *
 * Parms:    irq - interrupt id
 *           dev_id - device pointer
 *
 * Return:   IRQ_HANDLED
 *
 * Abort:    none
 *
 ************/
static irqreturn_t woorinet_button_irq_handler(int irq, void *data)
{
	struct button_data *btndata = (struct button_data*)data;
	struct platform_device *pdev = btndata->pdev;
	int gpioval;

	gpioval = gpio_get_value(btndata->gpio);

	if (!gpioval)
	{
		schedule_delayed_work(&btndata->check_work, msecs_to_jiffies(5000));
	}
	else
	{
		cancel_delayed_work(&btndata->check_work);
	}
	dev_info(&pdev->dev,"GPIO %d is %d\n", btndata->gpio, gpioval);

	return IRQ_HANDLED;
}

static int woorinet_button_probe(struct platform_device *pdev)
{
	int error;
	struct button_data *btndata = NULL;

	if (bs_feature_get(BS_FEATURE_FACTORY_RESET_KEY_DIS))
	{
		dev_info(&pdev->dev, "woorinet_button is not supported.\n");
		return -EPERM;
	}

	btndata = devm_kzalloc(&pdev->dev, sizeof(struct button_data), GFP_KERNEL);
	if (!btndata)
	{
		return -ENOMEM;
	}
	dev_set_drvdata(&pdev->dev, btndata);

	error = of_property_read_u32(pdev->dev.of_node, "linux,code", &btndata->key_code);
	if (error)
	{
		dev_err(&pdev->dev, "Unable to read linux,code, error=%d\n", error);
		return error;
	}

	btndata->input = devm_input_allocate_device(&pdev->dev);
	if (!btndata->input)
		return -ENOMEM;
	btndata->input->name = "wnet_btn";
	btndata->input->phys = "wnet_btn/input0";

	input_set_capability(btndata->input, EV_KEY, btndata->key_code);

	error = input_register_device(btndata->input);
	if (error)
	{
		dev_err(&pdev->dev, "Can't register input device: %d\n", error);
		goto release_input_alloc;
	}

	btndata->gpio = of_get_named_gpio(pdev->dev.of_node, "factotry-reset-gpio", 0);
	if (!gpio_is_valid(btndata->gpio))
	{
		goto release_input_alloc;
	}

	error = gpio_request(btndata->gpio, "factory-reset");
	if (error)
	{
		dev_err(&pdev->dev,"Failed to get GPIO %d, error code is %d\n", btndata->gpio, error);
		goto release_input_reg;
	}
	if (gpio_pull_up(gpio_to_desc(btndata->gpio)))
	{
		dev_err(&pdev->dev, "Failed to pull up GPIO %d\n", btndata->gpio);
	}
	if (gpio_direction_input(btndata->gpio))
	{
		dev_err(&pdev->dev, "Failed to set GPIO %d to input\n", btndata->gpio);
		goto release_gpio;
	}

	btndata->irq = gpio_to_irq(btndata->gpio);
	if(btndata->irq < 0)
	{
		dev_err(&pdev->dev, "no IRQ associated with GPIO %d\n", btndata->gpio);
		goto release_gpio;
	}

	btndata->pdev = pdev;

	INIT_DELAYED_WORK(&btndata->check_work, woorinet_button_check_work);
	error = devm_request_irq(&pdev->dev, btndata->irq, woorinet_button_irq_handler,
			IRQF_ONESHOT | IRQF_TRIGGER_FALLING | IRQF_TRIGGER_RISING,
			btndata->name, btndata);
	if (error)
	{
		dev_err(&pdev->dev, "request_irq failed for GPIO %d (IRQ %d)\n", btndata->gpio, btndata->irq);
		goto release_gpio;
	}

	error = enable_irq_wake(btndata->irq);
	if (error)
	{
		dev_err(&pdev->dev, "enable_irq failed for GPIO %d\n", btndata->gpio);
		goto release_irq;

	}

	if (gpio_get_value(btndata->gpio) == 0)
	{
		schedule_delayed_work(&btndata->check_work, msecs_to_jiffies(5000));
	}

	device_init_wakeup(&pdev->dev, 1);
	return 0;

release_irq:
	free_irq(btndata->irq, NULL);
release_gpio:
	gpio_free(btndata->gpio);
release_input_reg:
	input_unregister_device(btndata->input);
release_input_alloc:
	input_free_device(btndata->input);
	return -EPERM;
}

#ifdef CONFIG_PM
static int woorinet_button_suspend(struct device *dev)
{
	struct button_data *btndata = dev_get_drvdata(dev);

	if (btndata->gpio >= 0)
		enable_irq_wake(btndata->irq);
	return 0;
}

static int woorinet_button_resume(struct device *dev)
{
	struct button_data *btndata = dev_get_drvdata(dev);

	if (btndata->gpio >= 0)
		disable_irq_wake(btndata->irq);
	return 0;
}

static const struct dev_pm_ops woorinet_button_pm_ops = {
	.suspend  = woorinet_button_suspend,
	.resume = woorinet_button_resume,
};
#endif

#ifdef CONFIG_OF
static const struct of_device_id woorinet_button_match[] = {
	{ .compatible = "woorinet-button", },
	{ }
};
MODULE_DEVICE_TABLE(of, woorinet_button_match);
#endif

static struct platform_driver woorinet_button_driver = {
	.driver = {
		.name = "woorinet-button",
		.of_match_table = of_match_ptr(woorinet_button_match),
#ifdef CONFIG_PM
		.pm = &woorinet_button_pm_ops,
#endif
	},
	.probe = woorinet_button_probe,
};
module_platform_driver(woorinet_button_driver);

MODULE_DESCRIPTION("Woorinet Factory reset Button driver");
MODULE_AUTHOR("Dongyup Shin <dongyup.shin@woori-net.com>");
MODULE_LICENSE("GPL v2");
