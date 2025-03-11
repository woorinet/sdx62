/*************
 *
 * Filename:  wsmem.h
 *
 * Purpose:   WSMEM structure defines
 *
 * Note:
 *   SBL, MODEM, and kernel include wsmem.h.
 *
 **************/
#ifndef _WSMEM_H
#define _WSMEM_H

/* Include files */

#if defined(WOORINET_IMAGE_LK) || defined(__KERNEL__)
#include "aaglobal.h"
#endif

/* Structure */

enum wsmem_blsp_num
{
  wsmem_blsp1 = 0,  /* 0 */
  wsmem_blsp2,      /* 1 */
  wsmem_blsp3,      /* 2 */
  wsmem_blsp4,      /* 3 */
  wsmem_blsp5,      /* 4 */
  wsmem_blsp6,      /* 5 */
};

enum wsmem_blsp_func
{
  func_default = 0,         /* 0 */
  func_4pin_uart,           /* 1 */
  func_2pin_uart_2pin_i2c,  /* 2 */
  func_4pin_spi,            /* 3 */
  func_2pin_gpio_2pin_i2c,  /* 4 */
  func_4pin_gpio,           /* 5 */
  func_2pin_uart_2pin_gpio, /* 6 */
  /* Only for blsp 1 */
  func_4pin_sdcdata,        /* 7 */
  /* Only for blsp 4 */
  func_2pin_sdc_clk_cmd,    /* 8 */
  /* Only for blsp 6 */
  func_4pin_mi2s,           /* 9 */
};

enum wsmem_blsp_sub_func
{
  sub_func_default = 0, /* 0 */
  sub_func_gpio_export, /* 1 */
  sub_func_uart_debug,  /* 2 */
  sub_func_uart_raw,    /* 3 */
  sub_func_uart_bt,     /* 4 */
  sub_func_uart_modem,  /* 5 */
  sub_func_uart_smd11,  /* 6 */
};

enum wsmem_blsp_owner
{
  owner_default = 0,  /* 0 */
  owner_apps,         /* 1 */
  owner_mpss          /* 2 */
};

enum wsmem_fota_mode
{
  fota_mode_normal = 0, /* 0 */
  fota_mode_reboot,     /* 1 */
  fota_mode_atcmd,      /* 2 */
};

/*
 * It should be updated by /wnet/blsp<n>_conf.
 * e.g. /wnet/blsp1_conf for blsp1
 */
typedef PACKED struct PACKED_POST wsmem_blsp_configure
{
  uint8 func;       /* enum wsmem_blsp_func */
  uint8 sub_func;   /* enum wsmem_blsp_sub_func */
  uint8 owner;      /* enum wsmem_blsp_owner */
  uint8 reserved;
}wsmem_blsp_configure;

/* wsmem->usb_composite MSB 16bit(0xFFFF0000)
 *
 * e.g.
 * if (((wsmem->usb_composite&0xFFFF0000)>>16) & (1<<BS_USB_DIS_BITMASK_DIAG))
 * {
 *   USB DIAG interface disabled.
 * }
 */
enum wsmem_composite_disable{
  BS_USB_DIS_BITMASK_DIAG,              /* 0x0001 is (1<<BS_USB_DIS_BITMASK_DIAG) */
  BS_USB_DIS_BITMASK_ADB,               /* 0x0002 is (1<<BS_USB_DIS_BITMASK_ADB) */
  BS_USB_DIS_BITMASK_NMEA,              /* 0x0004 is (1<<BS_USB_DIS_BITMASK_NMEA) */
  BS_USB_DIS_BITMASK_MODEM,             /* 0x0008 is (1<<BS_USB_DIS_BITMASK_MODEM) */
  BS_USB_DIS_BITMASK_RMNET0,            /* 0x0010 is (1<<BS_USB_DIS_BITMASK_RMNET0) */
  BS_USB_DIS_BITMASK_CCID,              /* 0x0020 is (1<<BS_USB_DIS_BITMASK_CCID) */
  BS_USB_DIS_BITMASK_DPL,               /* 0x0040 is (1<<BS_USB_DIS_BITMASK_DPL) */
  BS_USB_DIS_BITMASK_MBIM,              /* 0x0080 is (1<<BS_USB_DIS_BITMASK_MBIM) */
  BS_USB_DIS_BITMASK_RNDIS,             /* 0x0100 is (1<<BS_USB_DIS_BITMASK_RNDIS) */
  BS_USB_DIS_BITMASK_AUDIO,             /* 0x0200 is (1<<BS_USB_DIS_BITMASK_AUDIO) */
  BS_USB_DIS_BITMASK_DIAG_MDM,          /* 0x0400 is (1<<BS_USB_DIS_BITMASK_DIAG_MDM) */
  BS_USB_DIS_BITMASK_ECM,               /* 0x0800 is (1<<BS_USB_DIS_BITMASK_ECM) */
  BS_USB_DIS_BITMASK_QDSS,              /* 0x1000 is (1<<BS_USB_DIS_BITMASK_QDSS) */
  BS_USB_DIS_BITMASK_QDSS_MDM,          /* 0x2000 is (1<<BS_USB_DIS_BITMASK_QDSS_MDM) */
  BS_USB_DIS_BITMASK_MASS_STORAGE,      /* 0x4000 is (1<<BS_USB_DIS_BITMASK_MASS_STORAGE) */
  BS_USB_DIS_BITMASK_RESERVED2,         /* 0x8000 is (1<<BS_USB_DIS_BITMASK_RESERVED2) */
};

/* Structure for WOORINET SMEM for SBL and LK.
 * It should be allocated by SBL with ID SMEM_ID_VENDOR0.
 */
typedef PACKED struct PACKED_POST wsmem_bl_boot
{
  uint32 rfhwid;                  /*  4 bytes */
  uint32 rfhwbid;                 /*  4 bytes */
  uint32 hwid;                    /*  4 bytes */
  wsmem_blsp_configure blsp[6];   /* 24 bytes */

  /* MSB 16bit for wsmem_composite_disable
   * LSB 16bit for PID e.g. 9025,902D,9091
   */
  uint32 usb_composite;           /*  4 bytes */
  /* 40 bytes */

  uint8 debug_uart;               /* 1 byte */
  uint8 customer[7];              /* 7 bytes */
  /* 48 bytes */

  uint32 feature[4];              /* 16 bytes */
  uint32 reserved[4];             /* 16 bytes */
  /* 80 bytes */

  /* enum wsmem_fota_mode for uint32 fota_mode */
  uint8 project_name[16];         /* 16 bytes */
  uint8 carrier[16];              /* 16 bytes */
  uint8 mcfg_carrier[12];         /* 12 bytes */
  uint32 fota_mode;               /*  4 bytes */
  uint32 fota_conf;               /*  4 bytes */
  uint8 model_name[16];           /* 16 bytes */
  uint8 embbeded_call_prof_num;   /*  1 bytes */
  uint8 rndis_mac[6];             /*  6 bytes */
  uint32 net_conf[8];             /* 32 bytes */
  /* 187 bytes */
  uint8 pad_reserved[837];        /* 869 bytes */
  /* 1024 bytes */
}wsmem_bl_boot;

/* boot_shared_imem_cookie_ptr->woorinet_magic is set by SBL and LK and cleared by LK and Kernel when boot up successfully. */
#define WOORINET_BL_BOOT_MAGIC          0xABCDEF01 /* SBL set it and LK will change to WOORINET_BL_BOOT_MAGIC_KERNEL */
#define WOORINET_BL_BOOT_MAGIC_KERNEL   0xABCDEF02 /* kernel must clear it */
#define WOORINET_BL_BOOT_MAGIC_DEAD     0xDEADDEAD /* Kernel set if exception occurs */

#define WOORINET_HW_PLATFORM_WNET_TM    0x00000080

enum bsfeature{
  /* wsmem_bl_boot->feature[0] */
  BS_FEATURE_SDC2_EN = 0,                                   /* feature[0] 0 bit */
  BS_FEATURE_ADBROOT_EN,                                    /* feature[0] 1 bit */
  BS_FEATURE_ADBCONN_EN,                                    /* feature[0] 2 bit */
  /*
   * enum usb_mode_type {
   *   USB_NONE = 0,    BIT1 - 0, BIT0 - 0,
   *   USB_PERIPHERAL,  BIT1 - 0, BIT0 - 1,
   *   USB_HOST,        BIT1 - 1, BIT0 - 0,
   *   USB_OTG,         BIT1 - 1, BIT0 - 1,
   * };
   */
  BS_FEATURE_USB_MODE_BIT0,                                 /* feature[0] 3 bit */
  BS_FEATURE_USB_MODE_BIT1,                                 /* feature[0] 4 bit */
  BS_FEATURE_CAT1_EN,                                       /* feature[0] 5 bit */
  BS_FEATURE_ROUTER_EN,                                     /* feature[0] 6 bit */
  BS_FEATURE_AUTOSLEEP_DIS,                                 /* feature[0] 7 bit */
  BS_FEATURE_RF_OVERRIDE,                                   /* feature[0] 8 bit */
  BS_FEATURE_GPS_AUTO_EN,                                   /* feature[0] 9 bit */
  BS_FEATURE_USBDUMP_EN,                                    /* feature[0] 10 bit */
  BS_FEATURE_AUDIO_EN,                                      /* feature[0] 11 bit */
  BS_FEATURE_WDM_ACTIVE,                                    /* feature[0] 12 bit */
  BS_FEATURE_RESERVED_PSM_P_MODE,                           /* feature[0] 13 bit */
  BS_FEATURE_AUTO_OTASTART,                                 /* feature[0] 14 bit */
  /*
   * BS_FEATURE_GPIO78_CTRL_UART2_EN added for customer Samsung S1.
   * if BS_FEATURE_GPIO78_CTRL_UART2_EN is set and GPIO78 input value
   * is HIGH, SBL changes wsmem->blsp2 configuration as modem AT.
   * After SBL jumps to appsboot, GPIO78 value change doesn't affect
   * UART2 function.
   *
   * GPIO78 HIGH - UART2 MODEM AT command
   */
  BS_FEATURE_GPIO78_CTRL_UART2_EN,                          /* feature[0] 15 bit */
  BS_FEATURE_SUPPORT_STATUS_LED,                            /* feature[0] 16 bit */
  /*
   * Enabled QTI Flash scrub feature, but it will be skipped
   * without BS_FEATURE_FLASH_SCRUB_EN
   * 1 - enabled, 0 - disabled.
   */
  BS_FEATURE_FLASH_SCRUB_EN,                                /* feature[0] 17 bit */
  BS_FEATURE_PS_LTE_EN,                                     /* feature[0] 18 bit */
  /*
   * Flash scrubbing code region is very risky on Woorinet partition design.
   * It's because Woorinet backup IMEI, cal, and importatnt NV items
   * to code region(rawdata) and product line also can switch firmware
   * regardless reliabiltiy testing on rawdata partition.
   * Therefore, flash scrubbing code region should be restricted.
   *
   * Enabled/diable code region flash scrub.
   * 1 - enabled, 0 - disabled.
   *
   * To enable code region flash scrub, both BS_FEATURE_FLASH_SCRUB_CODE_EN and
   * BS_FEATURE_FLASH_SCRUB_CODE_EN must be 1.
   */
  BS_FEATURE_FLASH_SCRUB_CODE_EN,                           /* feature[0] 19 bit */
  /*
   * BS_FEATURE_WOORINET_L5_DIS added to disable L5 control in woorinet gpio driver,
   * so other driver can control L5
   */
  BS_FEATURE_WOORINET_L5_DIS,                               /* feature[0] 20 bit */
  /*
   * BS_FEATURE_EMM19_ESM8_APP_CTRL added to coltrol for EMM19+ESM8 action,
   * block TryToConnect for 48hour timer
   */
  BS_FEATURE_EMM19_ESM8_APP_CTRL,                           /* feature[0] 21 bit */
  /*
   * BS_FEATURE_EXTENED_UART_LINES added to support DCD, DTR, DSR, RTS pins
   */
  BS_FEATURE_EXTENED_UART_LINES,                            /* feature[0] 22 bit */

  /*
   * BS_FEATURE_BOOTING_DELAY_EN added to support initial booting delay for load balancing during 0 to 25 secs
   */
  BS_FEATURE_BOOTING_DELAY_EN,                              /* feature[0] 23 bit */


  /*
   * BS_FEATURE_SDC2_CD_GPIO_EN added to enable SD card detection by GPIO interrupt
   */
  BS_FEATURE_SDC2_CD_GPIO_EN,                               /* feature[0] 24 bit */

  /*
   * BS_FEATURE_UART_SLEEP_EN added to support AT UART Sleep.
   *
   * AT Uart go sleep mode when it's enabled.
   * The inactivity time can be modified by AT command 'AT*WUARTSLEEP=<secs>'
   * When AT Uart is in sleep mode, the first character input only make UART
   * wake up, and it's not recognized as a character.
   * For example, if 'AT' inputed via UART in sleep mode, Modem UART only
   * recognize 'T' after UART wake up by 'A'
   *
   * 1 - enabled
   * 0 - disabled
   */
  BS_FEATURE_UART_SLEEP_EN,                                 /* feature[0] 25 bit */

  /*
   * BS_FEATURE_AR8033_EN added to support AR8033.
   * AR8033 uses L1, L3, L5, L11, so both BS_FEATURE_WOORINET_L5_DIS and
   * BS_FEATURE_AR8033_EN must be defined to support AR8033
   *
   */
  BS_FEATURE_AR8033_EN,                                     /* feature[0] 26 bit */

  /*
   * BS_FEATURE_LPM_PERSISTENCE_EN added to support LPM Persistence function.
   * When this feature is set to "1", UE will remain Low Power Mode after booting.
   */
  BS_FEATURE_LPM_PERSISTENCE_EN,                            /* feature[0] 27 bit */

  /*
   * BS_FEATURE_KT_NON_POWERED_DEVICE_EN added to support KT Non-Powerd device features
   * KT Non-Powered Device : set to "1"
   * KT Powered Device : set to "0" (default)
   */
  BS_FEATURE_KT_NON_POWERED_DEVICE_EN,                      /* feature[0] 28 bit */

  /*
   * BS_FEATURE_AR8033_PWR_CTL_EN added to make GPIO_79 high when enable AR8033.
   * GPIO 79 power control is needed for only TD6 and TD12 to use AR8033.
   * BS_FEATURE_AR8033_EN must be defined to support BS_FEATURE_AR8033_PWR_CTL_EN
   */
  BS_FEATURE_AR8033_PWR_CTL_EN,                             /* feature[0] 29 bit */

  /*
   * BS_FEATURE_WAN_DISABLE
   *
   * BS_FEATURE_WAN_DISABLE added to disable WAN by CFG
   * if BS_FEATURE_WAN_DISABLE is set, /proc/sys/net/ipv4/ip_forward is 0.
   * if BS_FEATURE_WAN_DISABLE is clear, /proc/sys/net/ipv4/ip_forward is 1.
   */
  BS_FEATURE_WAN_DISABLE,                                   /* feature[0] 30 bit */

  /*
   * BS_FEATURE_WEBSERVER_EN
   * BS_FEATURE_WEBSERVER_EN added to enable webserver
   */
  BS_FEATURE_WEBSERVER_EN,                                  /* feature[0] 31 bit */

  /* wsmem_bl_boot->feature[1] */

  /*
   * BS_FEATURE_TD6_UART_EN
   * BS_FEATURE_TD6_UART_EN added to support TD6 UART LINE DRIVER
   * TD6 and TD12 UART RS232 : PM GPIO1 1, MDM GPIO38 0
   * TD6 and TD12 UART TTL   : PM GPIO1 0, MDM GPIO38 1
   * BS_FEATURE_UART_SLEEP_EN must be clear for BS_FEATURE_TD6_UART_EN
   * BS_FEATURE_TD6_UART_EN feature will control PM GPIO 1 in a different way than
   * legacy module. BS_FEATURE_TD6_UART_EN will keep the PM GPIO1 value high during
   * suspend.
   */
  BS_FEATURE_TD6_UART_EN,                                   /* feature[1] 0 bit */

  /*
   * BS_FEATURE_TD6_UART_TTL_EN
   * BS_FEATURE_TD6_UART_TTL_EN added to support TD6 UART TTL
   * BS_FEATURE_TD6_UART_TTL_EN is set   : PM GPIO1 0, MDM GPIO38 1 (RS232)
   * BS_FEATURE_TD6_UART_TTL_EN is clear : PM GPIO1 1, MDM GPIO38 0 (TTL)
   * BS_FEATURE_TD6_UART_EN must be set for BS_FEATURE_TD6_UART_TTL_EN
   * BS_FEATURE_UART_SLEEP_EN must be clear for BS_FEATURE_TD6_UART_TTL_EN
   */
  BS_FEATURE_TD6_UART_TTL_EN,                               /* feature[1] 1 bit */

  /*
   * BS_FEATURE_TX_ON_INDICATION_EN
   * BS_FEATURE_TX_ON_INDICATION_EN added to support TX on indication
   * with GPIO43(GRFC2)
   */
  BS_FEATURE_TX_ON_INDICATION_EN,                           /* feature[1] 2 bit */

  /*
   * For LTE only target, UE cannot be changed LW mode via AT$$WLMODE
   */
  BS_FEATURE_LOCKUP_LTE_ONLY_EN,                            /* feature[1] 3 bit */

  /*
   * BS_FEATURE_AT_PASSWORD_EN
   * If BS_FEATURE_AT_PASSWORD_EN is set, AT*WPWD="W353" or AT!UNLOCK is needed to
   * enable all AT command.
   */
  BS_FEATURE_AT_PASSWORD_EN,                                /* feature[1] 4 bit */

  /*
   * BS_FEATURE_L13_1_8V_EN
   * If BS_FEATURE_L13_1_8V_EN is set, L13 is set to 1.8V.
   * BS_FEATURE_SDC2_EN can't work with BS_FEATURE_L13_1_8V_EN.
   */
  BS_FEATURE_L13_1_8V_EN,                                   /* feature[1] 5 bit */

  /*
   * BS_FEATURE_EMG_DLOAD_GPIO_ADVANCED_EN
   * if BS_FEATURE_EMG_DLOAD_GPIO_ADVANCED_EN is set,
   * Emergency Dload is detected by GPIO25 Low -> High -> Low -> High
   */
  BS_FEATURE_EMG_DLOAD_GPIO_ADVANCED_EN,                    /* feature[1] 6 bit */


  /*
   * BS_FEATURE_I2C_LOW_SPEED_EN
   * if BS_FEATURE_I2C_LOW_SPEED_EN is set,
   * i2c clk speed set to 100kHz
   */
  BS_FEATURE_I2C_LOW_SPEED_EN,                              /* feature[1] 7 bit */

  /*
   * KT eMTC LTE B8 enable
   */
  BS_FEATURE_KT_EMTC_LTE_B8_EN,                             /* feature[1] 8 bit */

  /*
   * VoLTE enable
   */
  BS_FEATURE_VOLTE_EN,                                      /* feature[1] 9 bit */

  /*
   * SKT Repeater Mode enable
   */
  BS_FEATURE_SKT_REP_MODE_EN,                               /* feature[1] 10 bit */

  /*
   * BS_FEATURE_USB_OTG_USER_CONTROL
   * If BS_FEATURE_USB_OTG_USER_CONTROL is set,
   * USB Id/VBUS notifcations comes from User via sysfs.
   */
  BS_FEATURE_USB_OTG_USER_CONTROL,                          /* feature[1] 11 bit */

  /*
   * BS_FEATURE_M2_RESET_PIN_DISABLE
   * If BS_FEATURE_M2_RESET_PIN_DISABLE is set,
   * disable SDX PM_GPIO_14 reset.
   */
  BS_FEATURE_M2_RESET_PIN_DISABLE,                          /* feature[1] 12 bit */

  /*
   * BS_FEATURE_DEBUG_TRANSPORT_TO_PCIE_EN
   * If BS_FEATURE_DEBUG_TRANSPORT_TO_PCIE_EN is set,
   * Debug transport mode is set to pcie
   */
  BS_FEATURE_DEBUG_TRANSPORT_TO_PCIE_EN,                    /* feature[1] 13 bit */

  /*
   * For Private 5G Network
   */
  BS_FEATURE_PRIVATE_NR_SUPPORT_EN,                         /* feature[1] 14 bit */

  /*
   * For FR2 Support
   */
  BS_FEATURE_FR2_SUPPORT_EN,                                /* feature[1] 15 bit */

  /*
   * BS_FEATURE_PCIE_VOLTAGE_SEL_DIS
   *
   * If BS_FEATURE_PCIE_VOLTAGE_SEL_DIS is clear,
   * Contrl SDX GPIO5 to select PCIE voltage level.
   *
   * V1.8 is set when BS_FEATURE_PCIE_VOLAGE_SELECT_DIS is FALSE,
   * and BS_FEATURE_PCIE_VOLTAGE_3P3_EN is FALSE.
   * V3.3 is set when BS_FEATURE_PCIE_VOLAGE_SELECT_DIS is FALSE,
   * and BS_FEATURE_PCIE_VOLTAGE_3P3_EN is TRUE.
   *
   */
  BS_FEATURE_PCIE_VOLTAGE_SEL_DIS,                          /* feature[1] 16 bit */

  /*
   * BS_FEATURE_PCIE_VOLTAGE_3P3_EN
   *
   * Control SDX GPIO5 to select PCIE voltage level
   *
   * V1.8 is set when BS_FEATURE_PCIE_VOLAGE_SELECT_DIS is FALSE,
   * and BS_FEATURE_PCIE_VOLTAGE_3P3_EN is FALSE.
   * V3.3 is set when BS_FEATURE_PCIE_VOLAGE_SELECT_DIS is FALSE,
   * and BS_FEATURE_PCIE_VOLTAGE_3P3_EN is TRUE.
   *
   * Note:
   *  BS_FEATURE_PCIE_VOLTAGE_SEL_DIS must be clear
   */
  BS_FEATURE_PCIE_VOLTAGE_3P3_EN,                            /* feature[1] 17 bit */

  /*
   * FEATURE_SKY_CP_NETWORK_ACCESS_RESTRICT
   */
  BS_FEATURE_HOME_ACCESS_ONLY,                               /* feature[1] 18 bit */

  /*
   * BS_FEATURE_GNSS_ANT_CONTROL_HIGH
   * if BS_FEATURE_GNSS_ANT_CONTROL_HIGH is set, control GNSS antenna GPIO HIGH.
   */
  BS_FEATURE_GNSS_ANT_CONTROL_HIGH,                          /* feature[1] 19 bit */

  /*
   * BS_FEATURE_FACTORY_RESET_KEY_DIS
   * If BS_FEATURE_GNSS_ANT_CONTROL_HIGH is set,
   * GPIO 32 HIGH is not working for Facktory Reset.
   */
  BS_FEATURE_FACTORY_RESET_KEY_DIS,                          /* feature[1] 20 bit */

  /*
   * BS_FEATURE_RTL8125_IPA_DIS
   * If BS_FEATURE_RTL8125_IPA_DIS is set,
   * Disable RTL8125 IPA
   */
  BS_FEATURE_RTL8125_IPA_DIS,                                /* feature[1] 21 bit */

  /*
   * BS_FEATURE_DONGLE_USB_TO_RTL8152_EN
   * If BS_FEATURE_DONGLE_USB_TO_RTL8152_EN is set, RTL8152 USB is enabled,
   * and SDX USB is disabled.
   */
  BS_FEATURE_DONGLE_USB_TO_RTL8152_EN,                       /* feature[1] 22 bit */

  /*
   * BS_FEATURE_IGNORE_DNSMASQ_EN
   * If BS_FEATURE_IGNORE_DNSMASQ_EN is set, WWAN DNS server address is directly assgigned,then dnsmasq is ignored.
   * and SDX USB is disabled.
   */
  BS_FEATURE_IGNORE_DNSMASQ_EN,                       /* feature[1] 23 bit */

  /*
   * BS_FEATURE_FIX_RMNET_DATA_INDEX_EN,
   * If BS_FEATURE_FIX_RMNET_DATA_INDEX_EN is set, the interface name for wwan is fixed to rmnet_data0.
   */
  BS_FEATURE_FIX_RMNET_DATA_INDEX_EN,                       /* feature[1] 24 bit */

  /*
   * FEATURE_SKT_CP_M_ATTACH_CONTROL
   */
  BS_FEATURE_SKT_ATTACH_CTRL_EN,                            /* feature[1] 25 bit */

  /*
   * BS_FEATURE_DISABLE_MASQ_INDEX_EN,
   * If BS_FEATURE_FIX_RMNET_DATA_INDEX_EN is set, the interface name for wwan is fixed to rmnet_data0.
   */
  BS_FEATURE_DISABLE_MASQ_EN,                       /* feature[1] 26 bit */

  /*
   * FEATURE_GMG_EN
   */
  BS_FEATURE_GMG_EN,                                        /* feature[1] 27 bit */

  /*
   * FEATURE_GMG_EN
   */
  BS_FEATURE_DNSMASQ_DAEMON_OFF_IF_DHCP_OFF_EN,                         /* feature[1] 28 bit */

  /*
   * BS_FEATURE_PCI_LINK_FAILURE_RESET_EN,
   * When BS_FEATURE_PCI_LINK_FAILURE_RESET_EN is set,
   * RC0 PCIe link failure will make device to reset.
   */
  BS_FEATURE_PCI_LINK_FAILURE_RESET_EN,                     /* feature[1] 29 bit */

  /*
   * BS_FEATURE_PCI_LINK_FAILURE_RESET_EN,
   * When BS_FEATURE_PCI_LINK_FAILURE_RESET_EN is set,
   * RC0 PCIe link failure will make device to reset.
   */
  BS_FEATURE_MCFG_DISABLE,                                  /* feature[1] 30 bit */

  BS_FEATURE_AXGATE_VPN_EN,                                  /* feature[1] 31 bit */
  /* wsmem_bl_boot->feature[2] */
  /* wsmem_bl_boot->feature[3] */
  /* wsmem_bl_boot->reserved[0] */
  /* wsmem_bl_boot->reserved[1] */
  /* wsmem_bl_boot->reserved[2] */
  /* wsmem_bl_boot->reserved[3] */

  BS_FEATURE_MAX = 255,      /* 255 */
};

/* wsmem_bl_boot->supported_feature1 MASK */
#define WNET_FEAT1_MASK_SDC2_EN                             0x00000001
#define WNET_FEAT1_MASK_ADBROOT_EN                          0x00000002
#define WNET_FEAT1_MASK_ADBCONN_EN                          0x00000004
#define WNET_FEAT1_MASK_USB_MODE_BIT0                       0x00000008
#define WNET_FEAT1_MASK_USB_MODE_BIT1                       0x00000010
#define WNET_FEAT1_MASK_CAT1_EN                             0x00000020
#define WNET_FEAT1_MASK_ROUTER_EN                           0x00000040
#define WNET_FEAT1_MASK_AUTOSLEEP_DIS                       0x00000080
#define WNET_FEAT1_MASK_RF_OVERRIDE                         0x00000100
#define WNET_FEAT1_MASK_GPS_AUTO_EN                         0x00000200
#define WNET_FEAT1_MASK_USBDUMP                             0x00000400
#define WNET_FEAT1_MASK_AUDIO_EN                            0x00000800
#define WNET_FEAT1_MASK_WDM_ACTIVE                          0x00001000
#define WNET_FEAT1_MASK_RESERVED_PSM_P_MODE                 0x00002000
#define WNET_FEAT1_MASK_AUTO_OTASTART                       0x00004000
#define WNET_FEAT1_MASK_GPIO78_CTRL_UART2_EN                0x00008000
#define WNET_FEAT1_MASK_SUPPORT_STATUS_LED                  0x00010000
#define WNET_FEAT1_MASK_FLASH_SCRUB_EN                      0x00020000
#define WNET_FEAT1_MASK_PS_LTE_EN                           0x00040000
#define WNET_FEAT1_MASK_FLASH_SCRUB_CODE_EN                 0x00080000
#define WNET_FEAT1_MASK_WOORINET_L5_DIS                     0x00100000
#define WNET_FEAT1_MASK_EMM19_ESM8_APP_CTRL                 0x00200000
#define WNET_FEAT1_MASK_EXTENED_UART_LINES                  0x00400000
#define WNET_FEAT1_MASK_BOOTING_DELAY_EN                    0x00800000
#define WNET_FEAT1_MASK_SDC2_CD_GPIO_EN                     0x01000000
#define WNET_FEAT1_MASK_UART_SLEEP_EN                       0x02000000
#define WNET_FEAT1_MASK_AR8033_EN                           0x04000000
#define WNET_FEAT1_MASK_LPM_PERSISTENCE_EN                  0x08000000
#define WNET_FEAT1_MASK_KT_NON_POWERED_DEVICE_EN            0x10000000
#define WNET_FEAT1_MASK_AR8033_PWR_CTL_EN                   0x20000000
#define WNET_FEAT1_MASK_WAN_DISABLE                         0x40000000
#define WNET_FEAT1_MASK_WEBSERVER_EN                        0x80000000

/* wsmem_bl_boot->supported_feature2 MASK */
#define WNET_FEAT2_MASK_TD6_UART_EN                         0x00000001
#define WNET_FEAT2_MASK_TD6_UART_TTL_EN                     0x00000002
#define WNET_FEAT2_MASK_TX_ON_INDICATION_EN                 0x00000004
#define WNET_FEAT2_MASK_LOCKUP_LTE_ONLY_EN                  0x00000008
#define WNET_FEAT2_MASK_AT_PASSWORD_EN                      0x00000010
#define WNET_FEAT2_MASK_L13_1_8V_EN                         0x00000020
#define WNET_FEAT2_MASK_EMG_DLOAD_GPIO_ADVANCED_EN          0x00000040
#define WNET_FEAT2_MASK_I2C_LOW_SPEED_EN                    0x00000080
#define WNET_FEAT2_MASK_KT_EMTC_LTE_B8_EN                   0x00000100
#define WNET_FEAT2_MASK_VOLTE_EN                            0x00000200
#define WNET_FEAT2_MASK_SKT_REP_MODE_EN                     0x00000400
#define WNET_FEAT2_MASK_USB_OTG_USER_CONTROL                0x00000800
#define WNET_FEAT2_MASK_M2_RESET_PIN_DISABLE                0x00001000
#define WNET_FEAT2_MASK_DEBUG_TRANSPORT_TO_PCIE_EN          0x00002000
#define WNET_FEAT2_MASK_PRIVATE_NR_SUPPORT_EN               0x00004000
#define WNET_FEAT2_MASK_FR2_SUPPORT_EN                      0x00008000
#define WNET_FEAT2_MASK_PCIE_VOLTAGE_SEL_DIS                0x00010000
#define WNET_FEAT2_MASK_PCIE_VOLTAGE_3P3_EN                 0x00020000
#define WNET_FEAT2_MASK_HOME_ACCESS_ONLY                    0x00040000
#define WNET_FEAT2_MASK_GNSS_ANT_CONTROL_HIGH               0x00080000
#define WNET_FEAT2_MASK_FACTORY_RESET_KEY_DIS               0x00100000
#define WNET_FEAT2_MASK_RTL8125_IPA_DIS                     0x00200000
#define WNET_FEAT2_MASK_DONGLE_USB_TO_RTL8152_EN            0x00400000
#define WNET_FEAT2_MASK_IGNORE_DNSMASQ_EN                   0x00800000
#define WNET_FEAT2_MASK_FIX_RMNET_DATA_INDEX_EN             0x01000000
#define WNET_FEAT2_MASK_SKT_ATTACH_CTRL_EN                  0x02000000
#define WNET_FEAT2_MASK_DISABLE_MASQ_EN                     0x04000000
#define WNET_FEAT2_MASK_GMG_EN                              0x08000000
#define WNET_FEAT2_MASK_DNSMASQ_DAEMON_OFF_IF_DHCP_OFF_EN   0x10000000
#define WNET_FEAT2_MASK_PCI_LINK_FAILURE_RESET_EN           0x20000000
#define WNET_FEAT2_MASK_MCFG_DISABLE                        0x40000000
#define WNET_FEAT2_MASK_AXGATE_VPN_EN                       0x80000000

/* wsmem_bl_boot->supported_feature3 MASK */
#define WNET_FEAT3_MASK_RESERVED1                           0x00000001
#define WNET_FEAT3_MASK_RESERVED2                           0x00000002
#define WNET_FEAT3_MASK_RESERVED3                           0x00000004
#define WNET_FEAT3_MASK_RESERVED4                           0x00000008
#define WNET_FEAT3_MASK_RESERVED5                           0x00000010
#define WNET_FEAT3_MASK_RESERVED6                           0x00000020
#define WNET_FEAT3_MASK_RESERVED7                           0x00000040
#define WNET_FEAT3_MASK_RESERVED8                           0x00000080
#define WNET_FEAT3_MASK_RESERVED9                           0x00000100
#define WNET_FEAT3_MASK_RESERVED10                          0x00000200
#define WNET_FEAT3_MASK_RESERVED11                          0x00000400
#define WNET_FEAT3_MASK_RESERVED12                          0x00000800
#define WNET_FEAT3_MASK_RESERVED13                          0x00001000
#define WNET_FEAT3_MASK_RESERVED14                          0x00002000
#define WNET_FEAT3_MASK_RESERVED15                          0x00004000
#define WNET_FEAT3_MASK_RESERVED16                          0x00008000
#define WNET_FEAT3_MASK_RESERVED17                          0x00010000
#define WNET_FEAT3_MASK_RESERVED18                          0x00020000
#define WNET_FEAT3_MASK_RESERVED19                          0x00040000
#define WNET_FEAT3_MASK_RESERVED20                          0x00080000
#define WNET_FEAT3_MASK_RESERVED21                          0x00100000
#define WNET_FEAT3_MASK_RESERVED22                          0x00200000
#define WNET_FEAT3_MASK_RESERVED23                          0x00400000
#define WNET_FEAT3_MASK_RESERVED24                          0x00800000
#define WNET_FEAT3_MASK_RESERVED25                          0x01000000
#define WNET_FEAT3_MASK_RESERVED26                          0x02000000
#define WNET_FEAT3_MASK_RESERVED27                          0x04000000
#define WNET_FEAT3_MASK_RESERVED28                          0x08000000
#define WNET_FEAT3_MASK_RESERVED29                          0x10000000
#define WNET_FEAT3_MASK_RESERVED30                          0x20000000
#define WNET_FEAT3_MASK_RESERVED31                          0x40000000
#define WNET_FEAT3_MASK_RESERVED32                          0x80000000

/* wsmem_bl_boot->supported_feature4 MASK */
#define WNET_FEAT4_MASK_RESERVED1                           0x00000001
#define WNET_FEAT4_MASK_RESERVED2                           0x00000002
#define WNET_FEAT4_MASK_RESERVED3                           0x00000004
#define WNET_FEAT4_MASK_RESERVED4                           0x00000008
#define WNET_FEAT4_MASK_RESERVED5                           0x00000010
#define WNET_FEAT4_MASK_RESERVED6                           0x00000020
#define WNET_FEAT4_MASK_RESERVED7                           0x00000040
#define WNET_FEAT4_MASK_RESERVED8                           0x00000080
#define WNET_FEAT4_MASK_RESERVED9                           0x00000100
#define WNET_FEAT4_MASK_RESERVED10                          0x00000200
#define WNET_FEAT4_MASK_RESERVED11                          0x00000400
#define WNET_FEAT4_MASK_RESERVED12                          0x00000800
#define WNET_FEAT4_MASK_RESERVED13                          0x00001000
#define WNET_FEAT4_MASK_RESERVED14                          0x00002000
#define WNET_FEAT4_MASK_RESERVED15                          0x00004000
#define WNET_FEAT4_MASK_RESERVED16                          0x00008000
#define WNET_FEAT4_MASK_RESERVED17                          0x00010000
#define WNET_FEAT4_MASK_RESERVED18                          0x00020000
#define WNET_FEAT4_MASK_RESERVED19                          0x00040000
#define WNET_FEAT4_MASK_RESERVED20                          0x00080000
#define WNET_FEAT4_MASK_RESERVED21                          0x00100000
#define WNET_FEAT4_MASK_RESERVED22                          0x00200000
#define WNET_FEAT4_MASK_RESERVED23                          0x00400000
#define WNET_FEAT4_MASK_RESERVED24                          0x00800000
#define WNET_FEAT4_MASK_RESERVED25                          0x01000000
#define WNET_FEAT4_MASK_RESERVED26                          0x02000000
#define WNET_FEAT4_MASK_RESERVED27                          0x04000000
#define WNET_FEAT4_MASK_RESERVED28                          0x08000000
#define WNET_FEAT4_MASK_RESERVED29                          0x10000000
#define WNET_FEAT4_MASK_RESERVED30                          0x20000000
#define WNET_FEAT4_MASK_RESERVED31                          0x40000000
#define WNET_FEAT4_MASK_RESERVED32                          0x80000000

#endif /* _WSMEM_H */
