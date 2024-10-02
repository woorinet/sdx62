/************
 *
 * Filename: bsudefs.h
 *
 * Purpose: external definitions for Board Support package
 *
 * Copyright: (c) 2016 WOORINET. All rights reserved.
 *
 ************/

#ifndef BSUDEFS_H
#define BSUDEFS_H

/* include files */
#include "aaglobal.h"

/* Arbitrary max length for flash device name */
#define BS_FLASH_DEVICE_NAME_MAX 64

/* Partition names
 *
 * MUST BE KEPT IN SYNC WITH common/build/partition_nand.xml
 */
#define MIBIB_LINUX_SYSTEM_PARTI_NAME   "0:system"     /* Linux System       */
#define MIBIB_LINUX_BOOT_PARTI_NAME     "0:boot"       /* Linux Kernel       */
#define MIBIB_ABOOT_PARTI_NAME          "0:aboot"      /* appsboot           */
#define MIBIB_SBL_PARTI_NAME            "0:SBL"        /* Secondary Boot     */
#define MIBIB_MODEM_PARTI_NAME          "0:modem"
#define MIBIB_MIBIB_PARTI_NAME          "0:MIBIB"      /* MIBIB partition */
#define MIBIB_RPM_PARTI_NAME            "0:RPM"        /* Resource power management */
#define MIBIB_TZ_PARTI_NAME             "0:TZ"         /* Trust Zone */

#define BS_LED_ON                      TRUE
#define BS_LED_OFF                     FALSE

/************
 *
 * Name:     bs_led_e
 *
 * Purpose:  To enumerate the LEDs
 *
 * Members:  See below
 *
 * Notes:
 *
 ************/
enum bs_led_e
{
  BS_LED_MIN,
  BS_LED_POWERON = BS_LED_MIN,
  BS_LED_PROTOCOL_RED,
  BS_LED_PROTOCOL_GREEN,
  BS_LED_PROTOCOL_BLUE,
  BS_LED_MEMSTRESS,
  BS_LED_MAX = BS_LED_MEMSTRESS,
};

/************
 *
 * Name:     bs_uart_srv_e
 *
 * Purpose:  Enumerated list of possible over uart services
 *
 * Members:  see below
 *
 * Notes:    None
 *
 ************/
enum bs_uart_srv_e{
  BS_UART_SRV_NULL          = 0,  /* Null service mapped to UART device    */
  BS_UART_SRV_AT_PORT       = 1,  /* 4pin UART AT service by MODEM */
  BS_UART_SRV_LINUX_RAW_HS  = 2,  /* 4pin UART Linux rawdata */
  BS_UART_SRV_LINUX_CONSOLE = 3,  /* 2pin UART Linux Console */
  BS_UART_SRV_LINUX_RAW     = 4,  /* 2pin UART Linux rawdata */
  BS_UART_SRV_MAX
};


/************
 *
 * Name:     bs_uart_interface_e
 *
 * Purpose:  Enumerated list of possible uart interface
 *
 * Members:  see below
 *
 * Notes:    None
 *
 ************/
enum bs_uart_interface_e{
  BS_UART_IFACE_UART2     = 0,    /* AT/DATA service mapped as default */
  BS_UART_IFACE_UART5     = 1,    /* Linux Console is mapped as default */
  BS_UART_IFACE_MAX
};

/* structures */

/* Package global entry point definitions come last */
#include "wsmem.h"
#if !defined(WOORINET_IMAGE_APPS)
#include "smem.h"
#endif

#include "bsuproto.h"

#endif /* BSUDEFS_H */
