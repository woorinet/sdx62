/* arch/arm/mach-msm/woorinet/bsuser.c
 *
 * Copyright: (c) 2016 WOORINET. All rights reserved.
 *
 */

#include <aaudefs.h>
#include "bsidefs.h"

#include <linux/etherdevice.h>

static wsmem_bl_boot * wsmem_base = NULL;
static uint8 rndis_mac_addr[6] = {0,};

/************
 *
 * Name:     bs_get_wsmem_addr()
 *
 * Purpose:  Provide to get allocated wsmem address
 *
 * Parms:    none
 *
 * Return:   true - success
 *
 * Abort:    none
 *
 * Notes:
 *
 ************/
_global wsmem_bl_boot * bs_get_wsmem_addr(
  void)
{
  size_t wsmem_size = sizeof(wsmem_bl_boot);

  if (wsmem_base == NULL)
  {
    wsmem_base = (wsmem_bl_boot *)qcom_smem_get(QCOM_SMEM_HOST_ANY, SMEM_ID_VENDOR0, &wsmem_size);
    if (IS_ERR_OR_NULL(wsmem_base))
    {
      WOORINET_PRINT(WOORINET_ERROR, "%s: smem_get_entry failed : x%08X\n", __func__, (unsigned int)wsmem_base);
      wsmem_base = NULL;
    }
  }
  return wsmem_base;
}
EXPORT_SYMBOL(bs_get_wsmem_addr);

/************
 *
 * Name:    wnet_get_usb_mode()
 *
 * Purpose: return USB MODE in Woorinet Shared Memory
 *
 * Parms:   none
 *
 * Return:  enum usb_mode_type {
 *            USB_NONE = 0,
 *            USB_PERIPHERAL,
 *            USB_HOST,
 *            USB_OTG,
 *          };
 *
 * Abort:   none
 *
 * Notes:
 *
 ************/

enum usb_mode_type wnet_get_usb_mode(void)
{
  wsmem_bl_boot *wsmem_addr = NULL;
  uint32 default_usb_mode = 0;

  wsmem_addr = bs_get_wsmem_addr();
  if (!wsmem_addr)
  {
    pr_err("%s: error getting WSMEM address x%x\n", __func__, wsmem_addr);
    default_usb_mode = 0;
  }
  else
  {
    default_usb_mode = (wsmem_addr->feature[0] & (WNET_FEAT1_MASK_USB_MODE_BIT0|WNET_FEAT1_MASK_USB_MODE_BIT1));
    default_usb_mode = (default_usb_mode>>3);
  }

  return default_usb_mode;
}
EXPORT_SYMBOL(wnet_get_usb_mode);

/************
 *
 * Name:     bs_customer_get
 *
 * Purpose:  Returns TRUE/FALSE if contain the customer name
 *
 * Parms:    (out) strp - pointer to customer name string
 *
 * Return:   TRUE - OK
 *
 * Abort:    none
 *
 ************/
_global boolean bs_customer_get(
  char *strp)
{
  wsmem_bl_boot * wsmem_addr = NULL;

  wsmem_addr = bs_get_wsmem_addr();
  if (!wsmem_addr)
  {
    WOORINET_PRINT(WOORINET_ERROR, "Failed smem_get_addr() SMEM_ID_VENDOR0");
    return FALSE;
  }
  if (!wsmem_addr)
  {
    return FALSE;
  }
  if(strcpy(strp, wsmem_addr->customer))
  {
    return TRUE;
  }
  return FALSE;
}
EXPORT_SYMBOL(bs_customer_get);

/************
 *
 * Name:     bs_feature_get
 *
 * Purpose:  To check if the woorinet supports a particular feature
 *
 * Parms:    feature - feature to check
 *
 * Return:   Boolean value of the feature bit in Woorinet SMEM
 *
 * Abort:    none
 *
 ************/
_global boolean bs_feature_get(
  enum bsfeature feature)
{
  boolean result = FALSE;
  wsmem_bl_boot * wsmem_addr = NULL;
  uint8 arrayindex = feature/32;
  uint8 lsh = feature%32;
  /* feature[4] + reserved[4] */
  uint32 *parray = NULL;

  if (feature > BS_FEATURE_MAX)
  {
    WOORINET_PRINT(WOORINET_ERROR, "Invalid argument");
    return FALSE;
  }

  wsmem_addr = bs_get_wsmem_addr();
  if (!wsmem_addr)
  {
    WOORINET_PRINT(WOORINET_ERROR, "Failed smem_get_addr() SMEM_ID_VENDOR0");
    return FALSE;
  }

  parray = &wsmem_addr->feature[0];
  result = (parray[arrayindex]&(1<<lsh))? TRUE : FALSE;

  return result;
}
EXPORT_SYMBOL(bs_feature_get);

/************
 *
 * Name:     bs_hwid_get
 *
 * Purpose:  To get value of hwid
 *
 * Parms:    None
 *
 * Return:   uint32 value of hwid
 *
 * Abort:    none
 *
 ************/
_global uint32 bs_hwid_get(
  void)
{
  boolean result = FALSE;
  wsmem_bl_boot * wsmem_addr = NULL;

  wsmem_addr = bs_get_wsmem_addr();
  if (!wsmem_addr)
  {
    WOORINET_PRINT(WOORINET_ERROR, "Failed smem_get_addr() SMEM_ID_VENDOR0");
    return (uint32)0x40;
  }

  return wsmem_addr->hwid;
}
EXPORT_SYMBOL(bs_hwid_get);

/************
 *
 * Name:     bs_firmware_version_set
 *
 * Purpose:  Set firmware version to Shared memory.
 *
 * Parms:    True if succeed.
 *
 * Return:   none
 *
 ************/
_global boolean bs_firmware_version_set(
  void)
{
  unsigned int fw_version_len = 0;
  size_t smem_block_size;
  struct image_version_entry* apps_version_p;
  uint32_t * smem_version_p;
  char *carrier = NULL;

  bs_carrier_pointer_get(&carrier);

  smem_version_p = (uint32_t *)qcom_smem_get(QCOM_SMEM_HOST_ANY, SMEM_IMAGE_VERSION_TABLE, &smem_block_size);
  if (NULL == smem_version_p)
  {
    return FALSE;
  }
  // block from smem must be correct size
  if (SMEM_IMAGE_VERSION_TABLE_SIZE != smem_block_size)
  {
    return FALSE;
  }

  // entry structure must be exact size (primarily double checks compilation)
  if (SMEM_IMAGE_VERSION_ENTRY_SIZE != sizeof(struct image_version_entry))
  {
    return FALSE;
  }


  // get the base pointer
  apps_version_p = (struct image_version_entry*)((uint32)smem_version_p + (SMEM_IMAGE_VERSION_ENTRY_SIZE * (uint32)IMAGE_INDEX_APPS));

  // prepare structure being filled
  memset((void*)apps_version_p, 0, sizeof(struct image_version_entry));

  apps_version_p->image_index[1] = ZERO_SEP + (IMAGE_INDEX_APPS % 10);
  apps_version_p->image_index[0] = ZERO_SEP + ((IMAGE_INDEX_APPS/10) % 10);
  apps_version_p->image_colon_sep1[0] = COLON_SEP;
  apps_version_p->image_colon_sep2[0] = COLON_SEP;

  snprintf(apps_version_p->image_qc_version_string, IMAGE_QC_VERSION_STRING_LENGTH, "%s", aa_git_qti_apps_version_get());
  snprintf(apps_version_p->image_oem_version_string, IMAGE_OEM_VERSION_STRING_LENGTH, "OS.%s %s %s", aa_build_tag_get(carrier), (const char *)UTS_RELEASE, aa_build_machine_get());

  return TRUE;
}
EXPORT_SYMBOL(bs_firmware_version_set);

/************
 *
 * Name:     bs_woorinet_magic_clr
 *
 * Purpose:  Clear Woorinet magic number
 *
 * Parms:    none
 *
 * Return:   none
 *
 ************/
_global void bs_woorinet_magic_clr(
  void)
{
  struct device_node *np;
  void *imem_cookie_woorinet_magic_addr = NULL;

  np = of_find_compatible_node(NULL, NULL, "qcom,msm-imem-cookie-woorinet-magic");
  if (!np)
  {
    pr_err("Unable to find DT woorinet_magic node\n");
  }
  else
  {
    imem_cookie_woorinet_magic_addr = of_iomap(np, 0);
    if (!imem_cookie_woorinet_magic_addr)
    {
      pr_err("unable to map imem woorinet_magic\n");
    }
    else
    {
      __raw_writel(0, imem_cookie_woorinet_magic_addr);
    }
  }
}
EXPORT_SYMBOL(bs_woorinet_magic_clr);

/************
 *
 * Name:     bs_woorinet_magic_set
 *
 * Purpose:  Set Woorinet magic number for dump
 *
 * Parms:    none
 *
 * Return:   none
 *
 ************/
_global void bs_woorinet_magic_set(
  void)
{
  struct device_node *np;
  void *imem_cookie_woorinet_magic_addr = NULL;

  np = of_find_compatible_node(NULL, NULL, "qcom,msm-imem-cookie-woorinet-magic");
  if (!np)
  {
    pr_err("Unable to find DT woorinet_magic node\n");
  }
  else
  {
    imem_cookie_woorinet_magic_addr = of_iomap(np, 0);
    if (!imem_cookie_woorinet_magic_addr)
    {
      pr_err("unable to map imem woorinet_magic\n");
    }
    else
    {
      __raw_writel(WOORINET_BL_BOOT_MAGIC_DEAD, imem_cookie_woorinet_magic_addr);
    }
  }
}
EXPORT_SYMBOL(bs_woorinet_magic_set);

/************
 *
 * Name:     bs_usbcomp_get
 *
 * Purpose:  get USB composite pid
 *
 * Parms:    uint32 usb_comp
 *
 * Return:   True - no error
 *
 * Abort:    none
 *
 * Notes:
 *
 ************/
_global boolean bs_usbcomp_get(
  uint32 *usb_comp)
{
  wsmem_bl_boot * wsmem_addr = NULL;

  if (!usb_comp)
  {
    return FALSE;
  }
  *usb_comp = 0;

  wsmem_addr = bs_get_wsmem_addr();
  if (!wsmem_addr)
  {
    WOORINET_PRINT(WOORINET_ERROR, "Failed smem_get_addr() SMEM_ID_VENDOR0");
    return FALSE;
  }
  *usb_comp = wsmem_base->usb_composite;

  return TRUE;
}
EXPORT_SYMBOL(bs_usbcomp_get);

/************
 *
 * Name:     bs_carrier_pointer_get
 *
 * Purpose:  Returns a string containing the carrier
 *
 * Parms:    (OUT) strpp - pointer to carrier string
 *
 * Return:   TRUE - no errors
 *
 * Abort:    none
 *
 * Notes:    Always returns TRUE since this string should always be defined.
 *
 ************/
_global boolean bs_carrier_pointer_get(
  char **strpp)
{
  wsmem_bl_boot * wsmem_addr = NULL;
  if (strpp == NULL)
  {
    return FALSE;
  }
  wsmem_addr = bs_get_wsmem_addr();
  if (!wsmem_addr)
  {
    return FALSE;
  }
  *strpp = (char *)wsmem_addr->carrier;

  return TRUE;
}
EXPORT_SYMBOL(bs_carrier_pointer_get);

/************
 *
 * Name:     bs_debuguart_get
 *
 * Purpose:  get debuguart
 *
 * Parms:    boolean debuguart
 *
 * Return:   True - no error
 *
 * Abort:    none
 *
 * Notes:
 *
 ************/
_global boolean bs_debuguart_get(
  boolean *debuguart)
{
  wsmem_bl_boot * wsmem_addr = NULL;

   wsmem_addr = bs_get_wsmem_addr();
  if (!wsmem_addr)
  {
    WOORINET_PRINT(WOORINET_ERROR, "Failed smem_get_addr() SMEM_ID_VENDOR0");
    return FALSE;
  }
  *debuguart = (wsmem_addr->debug_uart) ? TRUE:FALSE;

  return TRUE;
}
EXPORT_SYMBOL(bs_debuguart_get);


/************
 *
 * Name:     bs_rndis_mac_addr_get
 *
 * Purpose:  Returns RNDIS MAC Address
 *
 * Parms:    (out) host_addr - pointer to mac address string
 *
 * Return:   TRUE - OK
 *
 * Abort:    none
 *
 ************/
_global boolean bs_rndis_mac_addr_get(
  char *host_addr)
{
  wsmem_bl_boot * wsmem_addr = NULL;
  uint8 * macaddr = NULL;

  wsmem_addr = bs_get_wsmem_addr();
  if (!wsmem_addr)
  {
    WOORINET_PRINT(WOORINET_ERROR, "Failed smem_get_addr() SMEM_ID_VENDOR0");
    return FALSE;
  }
  if (!wsmem_addr)
  {
    return FALSE;
  }
  macaddr = is_valid_ether_addr(rndis_mac_addr) ? rndis_mac_addr : wsmem_addr->rndis_mac;
  sprintf(host_addr, "%02X:%02X:%02X:%02X:%02X:%02X",
                     macaddr[0],
                     macaddr[1],
                     macaddr[2],
                     macaddr[3],
                     macaddr[4],
                     macaddr[5]);
  WOORINET_PRINTF(WOORINET_MED, "%s", host_addr);
  return TRUE;
}
EXPORT_SYMBOL(bs_rndis_mac_addr_get);

/************
 *
 * Name:     bs_rndis_mac_addr_set
 *
 * Purpose:  Set RNDIS MAC Address temporarily
 *
 * Parms:    (in) host_addr - pointer to mac address string
 *
 * Return:   TRUE - OK
 *
 * Abort:    none
 *
 ************/
_global boolean bs_rndis_mac_addr_set(
  char *host_addr)
{
  wsmem_bl_boot * wsmem_addr = NULL;

  wsmem_addr = bs_get_wsmem_addr();
  if (!wsmem_addr)
  {
    WOORINET_PRINT(WOORINET_ERROR, "Failed smem_get_addr() SMEM_ID_VENDOR0");
    return FALSE;
  }
  if (!wsmem_addr)
  {
    return FALSE;
  }

  if (host_addr)
  {
    unsigned int i;

    for (i = 0; i < 6; i++) {
      unsigned char num;

      if ((*host_addr == '.') || (*host_addr == ':'))
        host_addr++;
      num = hex_to_bin(*host_addr++) << 4;
      num |= hex_to_bin(*host_addr++);
      rndis_mac_addr[i] = num;
    }
  }

  WOORINET_PRINTF(WOORINET_MED, "%02X:%02X:%02X:%02X:%02X:%02X",
                     rndis_mac_addr[0],
                     rndis_mac_addr[1],
                     rndis_mac_addr[2],
                     rndis_mac_addr[3],
                     rndis_mac_addr[4],
                     rndis_mac_addr[5]);
  return TRUE;
}
EXPORT_SYMBOL(bs_rndis_mac_addr_set);

static int __init bs_late_init(void)
{
  if (!bs_firmware_version_set())
  {
    WOORINET_PRINT(WOORINET_ERROR, "Failed bs_firmware_version_set()");
  }

  WOORINET_PRINT(WOORINET_MED, "bs_late_init done");
  return 0;
}
late_initcall(bs_late_init);

