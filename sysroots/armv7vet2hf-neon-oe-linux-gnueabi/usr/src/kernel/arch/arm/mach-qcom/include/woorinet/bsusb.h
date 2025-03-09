/*************
 *
 * Name:      bsusb.h
 *
 * Purpose:   external definitions for Board Support package
 *
 * Copyright: (c) 2016 WOORINET. All rights reserved.
 *
 *************/

#ifndef BSUSB_H_
#define BSUSB_H_

#include <woorinet/aaudefs.h>
#include <woorinet/bsudefs.h>

/* Local constants and enumerated types */
#define BS_USB_QCT_VENDOR_ID          0x05C6
#define BS_USB_INVALID_INTERFACE      255
#define BS_USB_MAX_INTERFACES         16 /* MAX_CONFIG_INTERFACES */
#define BS_USB_MAX_CONFIGS            3


/* Structures */

/************
 *
 * Name:     bs_usb_interface_info
 *
 * Purpose:  Woorinet USB Interface Information
 *
 * Notes:    none
 *
 ************/
struct bs_usb_interface_info {
  uint16        pid;
  uint8         config_number;
  unsigned      interface_number;
  const char    *function_instance;
  uint16        mask;
};

/* 4EE7 : # DESCRIPTION: ADB */
static struct bs_usb_interface_info usb_interface_4EE7[] =
{
  {0X4EE7, 1, 0, "ffs.adb",            BS_USB_DIS_BITMASK_ADB },
};

/* 901D : # DESCRIPTION: DIAG + ADB */
static struct bs_usb_interface_info usb_interface_901D[] =
{
  {0X901D, 1, 0, "ffs.diag",           BS_USB_DIS_BITMASK_DIAG },
  {0X901D, 1, 1, "ffs.adb",            BS_USB_DIS_BITMASK_ADB },
};

/* 901F : # DESCRIPTION: DIAG + ADB + DUN*/
static struct bs_usb_interface_info usb_interface_901F[] =
{
  {0X901F, 1, 0, "ffs.diag",           BS_USB_DIS_BITMASK_DIAG },
  {0X901F, 1, 1, "ffs.adb",            BS_USB_DIS_BITMASK_ADB },
  {0X901F, 1, 2, "cser.dun.0",         BS_USB_DIS_BITMASK_MODEM },
};

/* 9021 : # DESCRIPTION: DIAG + QMI_RMNET (Android)*/
static struct bs_usb_interface_info usb_interface_9021[] =
{
  {0X9021, 1, 0, "ffs.diag",           BS_USB_DIS_BITMASK_DIAG },
  {0X9021, 1, 1, "gsi.rmnet",          BS_USB_DIS_BITMASK_RMNET0 },
};

/* 9022 : # DESCRIPTION: DIAG + ADB + QMI_RMNET (Android)*/
static struct bs_usb_interface_info usb_interface_9022[] =
{
  {0X9022, 1, 0, "ffs.diag",           BS_USB_DIS_BITMASK_DIAG },
  {0X9022, 1, 1, "ffs.adb",            BS_USB_DIS_BITMASK_ADB },
  {0X9022, 1, 2, "gsi.rmnet",          BS_USB_DIS_BITMASK_RMNET0 },
};

/* 9024 : # DESCRIPTION: RNDIS + ADB [Android]*/
static struct bs_usb_interface_info usb_interface_9024[] =
{
  {0X9024, 1, 0, "gsi.rndis",          BS_USB_DIS_BITMASK_RNDIS },
  {0X9024, 1, 1, "gsi.rndis",          BS_USB_DIS_BITMASK_RNDIS },
  {0X9024, 1, 2, "ffs.adb",            BS_USB_DIS_BITMASK_ADB },
};

/* 9025 : # DESCRIPTION: DIAG + ADB + MODEM + NMEA + QMI_RMNET + Mass Storage (Android)*/
static struct bs_usb_interface_info usb_interface_9025[] =
{
  {0X9025, 1, 0, "ffs.diag",           BS_USB_DIS_BITMASK_DIAG },
  {0X9025, 1, 1, "ffs.adb",            BS_USB_DIS_BITMASK_ADB },
  {0X9025, 1, 2, "cser.dun.0",         BS_USB_DIS_BITMASK_MODEM },
  {0X9025, 1, 3, "cser.nmea.1",        BS_USB_DIS_BITMASK_NMEA },
  {0X9025, 1, 4, "gsi.rmnet",          BS_USB_DIS_BITMASK_RMNET0 },
  {0X9025, 1, 5, "mass_storage.0",     BS_USB_DIS_BITMASK_MASS_STORAGE },
};

/* 902B : # DESCRIPTION: RNDIS + ADB + Mass Storage*/
static struct bs_usb_interface_info usb_interface_902B[] =
{
  {0X902B, 1, 0, "gsi.rndis",          BS_USB_DIS_BITMASK_RNDIS },
  {0X902B, 1, 1, "gsi.rndis",          BS_USB_DIS_BITMASK_RNDIS },
  {0X902B, 1, 2, "ffs.adb",            BS_USB_DIS_BITMASK_ADB },
  {0X902B, 1, 3, "mass_storage.0",     BS_USB_DIS_BITMASK_MASS_STORAGE },
};


/* 902D : # DESCRIPTION: RNDIS + DIAG + ADB [Android]*/
static struct bs_usb_interface_info usb_interface_902D[] =
{
  {0X902D, 1, 0, "gsi.rndis",          BS_USB_DIS_BITMASK_RNDIS },
  {0X902D, 1, 1, "gsi.rndis",          BS_USB_DIS_BITMASK_RNDIS },
  {0X902D, 1, 2, "ffs.diag",           BS_USB_DIS_BITMASK_DIAG },
  {0X902D, 1, 3, "ffs.adb",            BS_USB_DIS_BITMASK_ADB },
};

/* 9049 : # DESCRIPTION: DIAG + ADB + DUN + RMNET + Mass Storage + QDSS [Android]*/
static struct bs_usb_interface_info usb_interface_9049[] =
{
  {0X9049, 1, 0, "ffs.diag",           BS_USB_DIS_BITMASK_DIAG },
  {0X9049, 1, 1, "ffs.adb",            BS_USB_DIS_BITMASK_ADB },
  {0X9049, 1, 2, "cser.dun.0",         BS_USB_DIS_BITMASK_MODEM },
  {0X9049, 1, 3, "gsi.rmnet",          BS_USB_DIS_BITMASK_RMNET0 },
  {0X9049, 1, 4, "mass_storage.0",     BS_USB_DIS_BITMASK_MASS_STORAGE },
  {0X9049, 1, 5, "qdss.qdss",          BS_USB_DIS_BITMASK_QDSS },
  {0X9049, 1, 6, "qdss.qdss",          BS_USB_DIS_BITMASK_QDSS },
};

/* 904A : # DESCRIPTION: DIAG + QDSS [Android]*/
static struct bs_usb_interface_info usb_interface_904A[] =
{
  {0X904A, 1, 0, "ffs.diag",           BS_USB_DIS_BITMASK_DIAG },
  {0X904A, 1, 1, "qdss.qdss",          BS_USB_DIS_BITMASK_QDSS },
  {0X904A, 1, 2, "qdss.qdss",          BS_USB_DIS_BITMASK_QDSS },
};

/* 9056 : # DESCRIPTION: DIAG + ADB + SERIAL + RMNET + Mass Storage + Audio [Android]*/
static struct bs_usb_interface_info usb_interface_9056[] =
{
  {0X9056, 1, 0, "ffs.diag",           BS_USB_DIS_BITMASK_DIAG },
  {0X9056, 1, 1, "ffs.adb",            BS_USB_DIS_BITMASK_ADB },
  {0X9056, 1, 2, "cser.dun.0",         BS_USB_DIS_BITMASK_MODEM },
  {0X9056, 1, 3, "gsi.rmnet",          BS_USB_DIS_BITMASK_RMNET0 },
  {0X9056, 1, 4, "mass_storage.0",     BS_USB_DIS_BITMASK_MASS_STORAGE },
  {0X9056, 1, 5, "uac1.uac1",          BS_USB_DIS_BITMASK_AUDIO },
  {0X9056, 1, 6, "uac1.uac1",          BS_USB_DIS_BITMASK_AUDIO },
  {0X9056, 1, 7, "uac1.uac1",          BS_USB_DIS_BITMASK_AUDIO },
};

/* 9057 : # DESCRIPTION:  RNDIS : ECM*/
static struct bs_usb_interface_info usb_interface_9057[] =
{
  {0X9057, 1, 0, "gsi.rndis",          BS_USB_DIS_BITMASK_RNDIS },
  {0X9057, 1, 1, "gsi.rndis",          BS_USB_DIS_BITMASK_RNDIS },
  {0X9057, 2, 0, "gsi.ecm",            BS_USB_DIS_BITMASK_ECM },
  {0X9057, 2, 1, "gsi.ecm",            BS_USB_DIS_BITMASK_ECM },
};

/* 9059 : # DESCRIPTION:  DIAG+ADB+RNDIS : ECM*/
static struct bs_usb_interface_info usb_interface_9059[] =
{
  {0X9059, 1, 0, "gsi.rndis",          BS_USB_DIS_BITMASK_RNDIS },
  {0X9059, 1, 1, "gsi.rndis",          BS_USB_DIS_BITMASK_RNDIS },
  {0X9059, 1, 2, "ffs.diag",           BS_USB_DIS_BITMASK_DIAG },
  {0X9059, 1, 3, "ffs.adb",            BS_USB_DIS_BITMASK_ADB },
  {0X9059, 2, 0, "gsi.ecm",            BS_USB_DIS_BITMASK_ECM },
  {0X9059, 2, 1, "gsi.ecm",            BS_USB_DIS_BITMASK_ECM },
};

/* 905B : # DESCRIPTION: MBIM*/
static struct bs_usb_interface_info usb_interface_905B[] =
{
  {0X905B, 1, 0, "gsi.mbim",           BS_USB_DIS_BITMASK_MBIM },
  {0X905B, 1, 1, "gsi.mbim",           BS_USB_DIS_BITMASK_MBIM },
};

/* 9060 : # DESCRIPTION: DIAG + QDSS + ADB*/
static struct bs_usb_interface_info usb_interface_9060[] =
{
  {0X9060, 1, 0, "ffs.diag",           BS_USB_DIS_BITMASK_DIAG },
  {0X9060, 1, 1, "qdss.qdss",          BS_USB_DIS_BITMASK_QDSS },
  {0X9060, 1, 2, "qdss.qdss",          BS_USB_DIS_BITMASK_QDSS },
  {0X9060, 1, 3, "ffs.adb",            BS_USB_DIS_BITMASK_ADB },
};

/* 9063 : # DESCRIPTION: RNDIS : ECM : MBIM*/
static struct bs_usb_interface_info usb_interface_9063[] =
{
  {0X9063, 1, 0, "gsi.rndis",          BS_USB_DIS_BITMASK_RNDIS },
  {0X9063, 1, 1, "gsi.rndis",          BS_USB_DIS_BITMASK_RNDIS },
  {0X9063, 2, 0, "gsi.ecm",            BS_USB_DIS_BITMASK_ECM },
  {0X9063, 2, 1, "gsi.ecm",            BS_USB_DIS_BITMASK_ECM },
  {0X9063, 3, 0, "gsi.mbim",           BS_USB_DIS_BITMASK_MBIM },
  {0X9063, 3, 1, "gsi.mbim",           BS_USB_DIS_BITMASK_MBIM },
};

/* 9064 : # DESCRIPTION: DIAG + ADB + MODEM + QMI_RMNET : ECM : MBIM*/
static struct bs_usb_interface_info usb_interface_9064[] =
{
  {0X9064, 1, 0, "ffs.diag",           BS_USB_DIS_BITMASK_DIAG },
  {0X9064, 1, 1, "ffs.adb",            BS_USB_DIS_BITMASK_ADB },
  {0X9064, 1, 2, "cser.dun.0",         BS_USB_DIS_BITMASK_MODEM },
  {0X9064, 1, 3, "gsi.rmnet",          BS_USB_DIS_BITMASK_RMNET0 },
  {0X9064, 2, 0, "gsi.ecm",            BS_USB_DIS_BITMASK_ECM },
  {0X9064, 2, 1, "gsi.ecm",            BS_USB_DIS_BITMASK_ECM },
  {0X9064, 3, 0, "gsi.mbim",           BS_USB_DIS_BITMASK_MBIM },
  {0X9064, 3, 1, "gsi.mbim",           BS_USB_DIS_BITMASK_MBIM },
};

/* 9067 : # DESCRIPTION: Mass storage + QMI_RMNET : Mass Storage + MBIM*/
static struct bs_usb_interface_info usb_interface_9067[] =
{
  {0X9067, 1, 0, "mass_storage.0",     BS_USB_DIS_BITMASK_MASS_STORAGE },
  {0X9067, 1, 1, "gsi.rmnet",          BS_USB_DIS_BITMASK_RMNET0 },
  {0X9067, 2, 0, "mass_storage.1",     BS_USB_DIS_BITMASK_MASS_STORAGE },
  {0X9067, 2, 1, "gsi.mbim",           BS_USB_DIS_BITMASK_MBIM },
  {0X9067, 2, 2, "gsi.mbim",           BS_USB_DIS_BITMASK_MBIM },
};

/* 9084 : # DESCRIPTION: DIAG + QDSS + ADB + RMNET*/
static struct bs_usb_interface_info usb_interface_9084[] =
{
  {0X9084, 1, 0, "ffs.diag",           BS_USB_DIS_BITMASK_DIAG },
  {0X9084, 1, 1, "qdss.qdss",          BS_USB_DIS_BITMASK_QDSS },
  {0X9084, 1, 2, "qdss.qdss",          BS_USB_DIS_BITMASK_QDSS },
  {0X9084, 1, 3, "ffs.adb",            BS_USB_DIS_BITMASK_ADB },
  {0X9084, 1, 4, "gsi.rmnet",          BS_USB_DIS_BITMASK_RMNET0 },
};

/* 9085 : # DESCRIPTION:  DIAG+ADB+MBIM+GNSS*/
static struct bs_usb_interface_info usb_interface_9085[] =
{
  {0X9085, 1, 0, "ffs.diag",           BS_USB_DIS_BITMASK_DIAG },
  {0X9085, 1, 1, "ffs.adb",            BS_USB_DIS_BITMASK_ADB },
  {0X9085, 1, 2, "gsi.mbim",           BS_USB_DIS_BITMASK_MBIM },
  {0X9085, 1, 3, "gsi.mbim",           BS_USB_DIS_BITMASK_MBIM },
  {0X9085, 1, 4, "gsi.gps",            BS_USB_DIS_BITMASK_NMEA },
};

/* 9091 : # DESCRIPTION: DIAG + MODEM + QMI_RMNET + ADB*/
static struct bs_usb_interface_info usb_interface_9091[] =
{
  {0X9091, 1, 0, "ffs.diag",           BS_USB_DIS_BITMASK_DIAG },
  {0X9091, 1, 1, "cser.dun.0",         BS_USB_DIS_BITMASK_MODEM },
  {0X9091, 1, 2, "gsi.rmnet",          BS_USB_DIS_BITMASK_RMNET0 },
  {0X9091, 1, 3, "ffs.adb",            BS_USB_DIS_BITMASK_ADB },
};

/* 90A1 : # DESCRIPTION: DIAG + ADB + (multiplexed) QMI_RMNET (Android)*/
static struct bs_usb_interface_info usb_interface_90A1[] =
{
  {0X90A1, 1, 0, "ffs.diag",           BS_USB_DIS_BITMASK_DIAG },
  {0X90A1, 1, 1, "ffs.adb",            BS_USB_DIS_BITMASK_ADB },
  {0X90A1, 1, 2, "gsi.rmnet",          BS_USB_DIS_BITMASK_RMNET0 },
};

/* 90A9 : # DESCRIPTION: DIAG + ADB + MODEM + NMEA + QDSS (bulk in) + RMNET : ECM : MBIM*/
static struct bs_usb_interface_info usb_interface_90A9[] =
{
  {0X90A9, 1, 0, "ffs.diag",           BS_USB_DIS_BITMASK_DIAG },
  {0X90A9, 1, 1, "ffs.adb",            BS_USB_DIS_BITMASK_ADB },
  {0X90A9, 1, 2, "cser.dun.0",         BS_USB_DIS_BITMASK_MODEM },
  {0X90A9, 1, 3, "cser.nmea.1",        BS_USB_DIS_BITMASK_NMEA },
  {0X90A9, 1, 4, "qdss.qdss_mdm",      BS_USB_DIS_BITMASK_QDSS_MDM },
  {0X90A9, 1, 5, "gsi.rmnet",          BS_USB_DIS_BITMASK_RMNET0 },
  {0X90A9, 2, 0, "gsi.ecm",            BS_USB_DIS_BITMASK_ECM },
  {0X90A9, 2, 1, "gsi.ecm",            BS_USB_DIS_BITMASK_ECM },
  {0X90A9, 3, 0, "gsi.mbim",           BS_USB_DIS_BITMASK_MBIM },
  {0X90A9, 3, 1, "gsi.mbim",           BS_USB_DIS_BITMASK_MBIM },
};

/* 90AD : # DESCRIPTION: DIAG + ADB + MODEM + NMEA + QMI_RMNET + Mass Storage + DPL*/
static struct bs_usb_interface_info usb_interface_90AD[] =
{
  {0X90AD, 1, 0, "ffs.diag",           BS_USB_DIS_BITMASK_DIAG },
  {0X90AD, 1, 1, "ffs.adb",            BS_USB_DIS_BITMASK_ADB },
  {0X90AD, 1, 2, "cser.dun.0",         BS_USB_DIS_BITMASK_MODEM },
  {0X90AD, 1, 3, "cser.nmea.1",        BS_USB_DIS_BITMASK_NMEA },
  {0X90AD, 1, 4, "gsi.rmnet",          BS_USB_DIS_BITMASK_RMNET0 },
  {0X90AD, 1, 5, "mass_storage.0",     BS_USB_DIS_BITMASK_MASS_STORAGE },
  {0X90AD, 1, 6, "gsi.dpl",            BS_USB_DIS_BITMASK_DPL },
};

/* 90B1 : # DESCRIPTION:  ECM*/
static struct bs_usb_interface_info usb_interface_90B1[] =
{
  {0X90B1, 1, 0, "gsi.ecm",            BS_USB_DIS_BITMASK_ECM },
  {0X90B1, 1, 1, "gsi.ecm",            BS_USB_DIS_BITMASK_ECM },
};

/* 90B8 : # DESCRIPTION: DIAG + DUN + RMNET + DPL + ADB*/
static struct bs_usb_interface_info usb_interface_90B8[] =
{
  {0X90B8, 1, 0, "ffs.diag",           BS_USB_DIS_BITMASK_DIAG },
  {0X90B8, 1, 1, "cser.dun.0",         BS_USB_DIS_BITMASK_MODEM },
  {0X90B8, 1, 2, "gsi.rmnet",          BS_USB_DIS_BITMASK_RMNET0 },
  {0X90B8, 1, 3, "gsi.dpl",            BS_USB_DIS_BITMASK_DPL },
  {0X90B8, 1, 4, "ffs.adb",            BS_USB_DIS_BITMASK_ADB },
};

/* 90C0 : # DESCRIPTION: RNDIS + DIAG + DPL + ADB (Android)*/
static struct bs_usb_interface_info usb_interface_90C0[] =
{
  {0X90C0, 1, 0, "gsi.rndis",          BS_USB_DIS_BITMASK_RNDIS },
  {0X90C0, 1, 1, "gsi.rndis",          BS_USB_DIS_BITMASK_RNDIS },
  {0X90C0, 1, 2, "ffs.diag",           BS_USB_DIS_BITMASK_DIAG },
  {0X90C0, 1, 3, "gsi.dpl",            BS_USB_DIS_BITMASK_DPL },
  {0X90C0, 1, 4, "ffs.adb",            BS_USB_DIS_BITMASK_ADB },
};

/* 90CA : # DESCRIPTION: DIAG + ADB + UAC2*/
static struct bs_usb_interface_info usb_interface_90CA[] =
{
  {0X90CA, 1, 0, "ffs.diag",           BS_USB_DIS_BITMASK_DIAG },
  {0X90CA, 1, 1, "ffs.adb",            BS_USB_DIS_BITMASK_ADB },
  {0X90CA, 1, 2, "uac2.0",             BS_USB_DIS_BITMASK_AUDIO },
  {0X90CA, 1, 3, "uac2.0",             BS_USB_DIS_BITMASK_AUDIO },
  {0X90CA, 1, 4, "uac2.0",             BS_USB_DIS_BITMASK_AUDIO },
};

/* 90CD : # DESCRIPTION: DIAG + ADB + GNSS*/
static struct bs_usb_interface_info usb_interface_90CD[] =
{
  {0X90CD, 1, 0, "ffs.diag",           BS_USB_DIS_BITMASK_DIAG },
  {0X90CD, 1, 1, "ffs.adb",            BS_USB_DIS_BITMASK_ADB },
  {0X90CD, 1, 2, "gsi.gps",            BS_USB_DIS_BITMASK_NMEA },
};

/* 90CE : # DESCRIPTION: CCID*/
static struct bs_usb_interface_info usb_interface_90CE[] =
{
  {0X90CE, 1, 0, "ccid.ccid",          BS_USB_DIS_BITMASK_CCID },
};

/* 90D1 : # DESCRIPTION: CCID + DIAG + ADB*/
static struct bs_usb_interface_info usb_interface_90D1[] =
{
  {0X90D1, 1, 0, "ccid.ccid",          BS_USB_DIS_BITMASK_CCID },
  {0X90D1, 1, 1, "ffs.diag",           BS_USB_DIS_BITMASK_DIAG },
  {0X90D1, 1, 2, "ffs.adb",            BS_USB_DIS_BITMASK_ADB },
};

/* 90D5 : # DESCRIPTION:  DIAG + ADB + MBIM + GNSS + DUN*/
static struct bs_usb_interface_info usb_interface_90D5[] =
{
  {0X90D5, 1, 0, "ffs.diag",           BS_USB_DIS_BITMASK_DIAG },
  {0X90D5, 1, 1, "ffs.adb",            BS_USB_DIS_BITMASK_ADB },
  {0X90D5, 1, 2, "gsi.mbim",           BS_USB_DIS_BITMASK_MBIM },
  {0X90D5, 1, 3, "gsi.mbim",           BS_USB_DIS_BITMASK_MBIM },
  {0X90D5, 1, 4, "gsi.gps",            BS_USB_DIS_BITMASK_NMEA },
  {0X90D5, 1, 5, "cser.dun.0",         BS_USB_DIS_BITMASK_MODEM },
};

/* 90D6 : # DESCRIPTION:  DIAG + MBIM + GNSS + DUN*/
static struct bs_usb_interface_info usb_interface_90D6[] =
{
  {0X90D6, 1, 0, "ffs.diag",           BS_USB_DIS_BITMASK_DIAG },
  {0X90D6, 1, 1, "gsi.mbim",           BS_USB_DIS_BITMASK_MBIM },
  {0X90D6, 1, 2, "gsi.mbim",           BS_USB_DIS_BITMASK_MBIM },
  {0X90D6, 1, 3, "gsi.gps",            BS_USB_DIS_BITMASK_NMEA },
  {0X90D6, 1, 4, "cser.dun.0",         BS_USB_DIS_BITMASK_MODEM },
};

/* 90DB : # DESCRIPTION: DIAG + DUN + RMNET + DPL + QDSS(Trace) + ADB*/
static struct bs_usb_interface_info usb_interface_90DB[] =
{
  {0X90DB, 1, 0, "ffs.diag",           BS_USB_DIS_BITMASK_DIAG },
  {0X90DB, 1, 1, "cser.dun.0",         BS_USB_DIS_BITMASK_MODEM },
  {0X90DB, 1, 2, "gsi.rmnet",          BS_USB_DIS_BITMASK_RMNET0 },
  {0X90DB, 1, 3, "gsi.dpl",            BS_USB_DIS_BITMASK_DPL },
  {0X90DB, 1, 4, "qdss.qdss_mdm",      BS_USB_DIS_BITMASK_QDSS_MDM },
  {0X90DB, 1, 5, "ffs.adb",            BS_USB_DIS_BITMASK_ADB },
};

/* 90E2 : # DESCRIPTION:  MBIM + GNSS*/
static struct bs_usb_interface_info usb_interface_90E2[] =
{
  {0X90E2, 1, 0, "gsi.mbim",           BS_USB_DIS_BITMASK_MBIM },
  {0X90E2, 1, 1, "gsi.mbim",           BS_USB_DIS_BITMASK_MBIM },
  {0X90E2, 1, 2, "gsi.gps",            BS_USB_DIS_BITMASK_NMEA },
};

/* 90E5 : # DESCRIPTION:  DIAG MSM + DIAG_MDM + QDSS MSM + QDSS_MDM + DUN + DPL + RMNET + ADB */
static struct bs_usb_interface_info usb_interface_90E5[] =
{
  {0X90E5, 1, 0, "ffs.diag",           BS_USB_DIS_BITMASK_DIAG },
  {0X90E5, 1, 1, "diag.diag_mdm",      BS_USB_DIS_BITMASK_DIAG_MDM },
  {0X90E5, 1, 2, "qdss.qdss",          BS_USB_DIS_BITMASK_QDSS },
  {0X90E5, 1, 3, "qdss.qdss_mdm",      BS_USB_DIS_BITMASK_QDSS_MDM },
  {0X90E5, 1, 4, "cser.dun.0",         BS_USB_DIS_BITMASK_MODEM },
  {0X90E5, 1, 5, "gsi.dpl",            BS_USB_DIS_BITMASK_DPL },
  {0X90E5, 1, 6, "gsi.rmnet",          BS_USB_DIS_BITMASK_RMNET0 },
  {0X90E5, 1, 7, "ffs.adb",            BS_USB_DIS_BITMASK_ADB },
};

/* 90E7 : # DESCRIPTION:  RNDIS + DIAG MSM + DIAG_MDM + QDSS MSM + QDSS_MDM + DUN + DPL + ADB */
static struct bs_usb_interface_info usb_interface_90E7[] =
{
  {0X90E7, 1, 0, "gsi.rndis",          BS_USB_DIS_BITMASK_RNDIS },
  {0X90E7, 1, 1, "gsi.rndis",          BS_USB_DIS_BITMASK_RNDIS },
  {0X90E7, 1, 2, "ffs.diag",           BS_USB_DIS_BITMASK_DIAG },
  {0X90E7, 1, 3, "diag.diag_mdm",      BS_USB_DIS_BITMASK_DIAG_MDM },
  {0X90E7, 1, 4, "qdss.qdss",          BS_USB_DIS_BITMASK_QDSS },
  {0X90E7, 1, 5, "qdss.qdss_mdm",      BS_USB_DIS_BITMASK_QDSS_MDM },
  {0X90E7, 1, 6, "cser.dun.0",         BS_USB_DIS_BITMASK_MODEM },
  {0X90E7, 1, 7, "gsi.dpl",            BS_USB_DIS_BITMASK_DPL },
  {0X90E7, 1, 8, "ffs.adb",            BS_USB_DIS_BITMASK_ADB },
};

/* 90EC : # DESCRIPTION:  DIAG + ADB + MBIM + GNSS + DUN + DPL */
static struct bs_usb_interface_info usb_interface_90EC[] =
{
  {0X90EC, 1, 0, "ffs.diag",           BS_USB_DIS_BITMASK_DIAG },
  {0X90EC, 1, 1, "ffs.adb",            BS_USB_DIS_BITMASK_ADB },
  {0X90EC, 1, 2, "gsi.mbim",           BS_USB_DIS_BITMASK_MBIM },
  {0X90EC, 1, 3, "gsi.mbim",           BS_USB_DIS_BITMASK_MBIM },
  {0X90EC, 1, 4, "gsi.gps",            BS_USB_DIS_BITMASK_NMEA },
  {0X90EC, 1, 5, "cser.dun.0",         BS_USB_DIS_BITMASK_MODEM },
  {0X90EC, 1, 6, "gsi.dpl",            BS_USB_DIS_BITMASK_DPL },
};

/* 90F2 : # DESCRIPTION: DIAG + ADB + DUN + DPL */
static struct bs_usb_interface_info usb_interface_90F2[] =
{
  {0X90F2, 1, 0, "ffs.diag",           BS_USB_DIS_BITMASK_DIAG },
  {0X90F2, 1, 1, "ffs.adb",            BS_USB_DIS_BITMASK_ADB },
  {0X90F2, 1, 2, "cser.dun.0",         BS_USB_DIS_BITMASK_MODEM },
  {0X90F2, 1, 3, "gsi.dpl",            BS_USB_DIS_BITMASK_DPL },
};

/* 90FC : # DESCRIPTION: DIAG + DUN + Muliplexed 15 pdn RMNET + DPL + QDSS MSM DATA + ADB */
static struct bs_usb_interface_info usb_interface_90FC[] =
{
  {0X90FC, 1, 0, "ffs.diag",           BS_USB_DIS_BITMASK_DIAG },
  {0X90FC, 1, 1, "cser.dun.0",         BS_USB_DIS_BITMASK_MODEM },
  {0X90FC, 1, 2, "gsi.rmnet",          BS_USB_DIS_BITMASK_RMNET0 },
  {0X90FC, 1, 3, "gsi.dpl",            BS_USB_DIS_BITMASK_DPL },
  {0X90FC, 1, 4, "qdss.qdss_mdm",      BS_USB_DIS_BITMASK_QDSS_MDM },
  {0X90FC, 1, 5, "ffs.adb",            BS_USB_DIS_BITMASK_ADB },
};
/* F000 : # DESCRIPTION: Mass Storage */
static struct bs_usb_interface_info usb_interface_F000[] =
{
  {0XF000, 1, 0, "mass_storage.0",     BS_USB_DIS_BITMASK_MASS_STORAGE },
};

static boolean interface_reserved[BS_USB_MAX_CONFIGS][BS_USB_MAX_INTERFACES];

/* functions */

/************
 *
 * Name:     bs_usb_interface_get
 *
 * Purpose:  get USB interfae info
 *
 * Parms:    (in)pid                - usb pid
 *           (out)bs_usb_interface  - bs_usb_interface
 *           (out)arraysz           - size of bs_usb_interface
 *
 * Return:   True if successful
 *
 * Notes:
 *
 ************/
static inline boolean bs_usb_interface_get(
  uint16  pid,
  struct bs_usb_interface_info **bs_usb_interface,
  unsigned *arraysz)
{
  boolean retval = TRUE;

  switch (pid)
  {
  case 0x4EE7:
    *bs_usb_interface = &usb_interface_4EE7[0];
    *arraysz = ARRAY_SIZE(usb_interface_4EE7);
    break;
  case 0x901D:
    *bs_usb_interface = &usb_interface_901D[0];
    *arraysz = ARRAY_SIZE(usb_interface_901D);
    break;
  case 0x901F:
    *bs_usb_interface = &usb_interface_901F[0];
    *arraysz = ARRAY_SIZE(usb_interface_901F);
    break;
  case 0x9021:
    *bs_usb_interface = &usb_interface_9021[0];
    *arraysz = ARRAY_SIZE(usb_interface_9021);
    break;
  case 0x9022:
    *bs_usb_interface = &usb_interface_9022[0];
    *arraysz = ARRAY_SIZE(usb_interface_9022);
    break;
  case 0x9024:
    *bs_usb_interface = &usb_interface_9024[0];
    *arraysz = ARRAY_SIZE(usb_interface_9024);
    break;
  case 0x9025:
    *bs_usb_interface = &usb_interface_9025[0];
    *arraysz = ARRAY_SIZE(usb_interface_9025);
    break;
  case 0x902B:
    *bs_usb_interface = &usb_interface_902B[0];
    *arraysz = ARRAY_SIZE(usb_interface_902B);
    break;
  case 0x902D:
    *bs_usb_interface = &usb_interface_902D[0];
    *arraysz = ARRAY_SIZE(usb_interface_902D);
    break;
  case 0x9049:
    *bs_usb_interface = &usb_interface_9049[0];
    *arraysz = ARRAY_SIZE(usb_interface_9049);
    break;
  case 0x904A:
    *bs_usb_interface = &usb_interface_904A[0];
    *arraysz = ARRAY_SIZE(usb_interface_904A);
    break;
  case 0x9056:
    *bs_usb_interface = &usb_interface_9056[0];
    *arraysz = ARRAY_SIZE(usb_interface_9056);
    break;
  case 0x9057:
    *bs_usb_interface = &usb_interface_9057[0];
    *arraysz = ARRAY_SIZE(usb_interface_9057);
    break;
  case 0x9059:
    *bs_usb_interface = &usb_interface_9059[0];
    *arraysz = ARRAY_SIZE(usb_interface_9059);
    break;
  case 0x905B:
    *bs_usb_interface = &usb_interface_905B[0];
    *arraysz = ARRAY_SIZE(usb_interface_905B);
    break;
  case 0x9060:
    *bs_usb_interface = &usb_interface_9060[0];
    *arraysz = ARRAY_SIZE(usb_interface_9060);
    break;
  case 0x9063:
    *bs_usb_interface = &usb_interface_9063[0];
    *arraysz = ARRAY_SIZE(usb_interface_9063);
    break;
  case 0x9064:
    *bs_usb_interface = &usb_interface_9064[0];
    *arraysz = ARRAY_SIZE(usb_interface_9064);
    break;
  case 0x9067:
    *bs_usb_interface = &usb_interface_9067[0];
    *arraysz = ARRAY_SIZE(usb_interface_9067);
    break;
  case 0x9084:
    *bs_usb_interface = &usb_interface_9084[0];
    *arraysz = ARRAY_SIZE(usb_interface_9084);
    break;
  case 0x9085:
    *bs_usb_interface = &usb_interface_9085[0];
    *arraysz = ARRAY_SIZE(usb_interface_9085);
    break;
  case 0x9091:
    *bs_usb_interface = &usb_interface_9091[0];
    *arraysz = ARRAY_SIZE(usb_interface_9091);
    break;
  case 0x90A1:
    *bs_usb_interface = &usb_interface_90A1[0];
    *arraysz = ARRAY_SIZE(usb_interface_90A1);
    break;
  case 0x90A9:
    *bs_usb_interface = &usb_interface_90A9[0];
    *arraysz = ARRAY_SIZE(usb_interface_90A9);
    break;
  case 0x90AD:
    *bs_usb_interface = &usb_interface_90AD[0];
    *arraysz = ARRAY_SIZE(usb_interface_90AD);
    break;
  case 0x90B1:
    *bs_usb_interface = &usb_interface_90B1[0];
    *arraysz = ARRAY_SIZE(usb_interface_90B1);
    break;
  case 0x90B8:
    *bs_usb_interface = &usb_interface_90B8[0];
    *arraysz = ARRAY_SIZE(usb_interface_90B8);
    break;
  case 0x90C0:
    *bs_usb_interface = &usb_interface_90C0[0];
    *arraysz = ARRAY_SIZE(usb_interface_90C0);
    break;
  case 0x90CA:
    *bs_usb_interface = &usb_interface_90CA[0];
    *arraysz = ARRAY_SIZE(usb_interface_90CA);
    break;
  case 0x90CD:
    *bs_usb_interface = &usb_interface_90CD[0];
    *arraysz = ARRAY_SIZE(usb_interface_90CD);
    break;
  case 0x90CE:
    *bs_usb_interface = &usb_interface_90CE[0];
    *arraysz = ARRAY_SIZE(usb_interface_90CE);
    break;
  case 0x90D1:
    *bs_usb_interface = &usb_interface_90D1[0];
    *arraysz = ARRAY_SIZE(usb_interface_90D1);
    break;
  case 0x90D5:
    *bs_usb_interface = &usb_interface_90D5[0];
    *arraysz = ARRAY_SIZE(usb_interface_90D5);
    break;
  case 0x90D6:
    *bs_usb_interface = &usb_interface_90D6[0];
    *arraysz = ARRAY_SIZE(usb_interface_90D6);
    break;
  case 0x90DB:
    *bs_usb_interface = &usb_interface_90DB[0];
    *arraysz = ARRAY_SIZE(usb_interface_90DB);
    break;
  case 0x90E2:
    *bs_usb_interface = &usb_interface_90E2[0];
    *arraysz = ARRAY_SIZE(usb_interface_90E2);
    break;
  case 0x90E5:
    *bs_usb_interface = &usb_interface_90E5[0];
    *arraysz = ARRAY_SIZE(usb_interface_90E5);
    break;
  case 0x90E7:
    *bs_usb_interface = &usb_interface_90E7[0];
    *arraysz = ARRAY_SIZE(usb_interface_90E7);
    break;
  case 0x90EC:
    *bs_usb_interface = &usb_interface_90EC[0];
    *arraysz = ARRAY_SIZE(usb_interface_90EC);
    break;
  case 0x90F2:
    *bs_usb_interface = &usb_interface_90F2[0];
    *arraysz = ARRAY_SIZE(usb_interface_90F2);
    break;
  case 0x90FC:
    *bs_usb_interface = &usb_interface_90FC[0];
    *arraysz = ARRAY_SIZE(usb_interface_90FC);
    break;
  case 0xF000:
    *bs_usb_interface = &usb_interface_F000[0];
    *arraysz = ARRAY_SIZE(usb_interface_F000);
    break;
  default:
    retval = FALSE;
    break;
  }

  return retval;
}

/************
 *
 * Name:     bs_usb_interface_number_get
 *
 * Purpose:  get USB interface info
 *
 * Parms:    interface_name  - interface name
 *           vid             - vendor id
 *           pid             - product id
 *           config_number   - config number
 *           id              - interface id
 *
 * Return:   unsigned - interface number
 *
 * Notes:
 *
 ************/
static inline unsigned bs_usb_interface_number_get(
  const char *interface_name,
  uint16 vid,
  uint16 pid,
  uint8 config_number,
  unsigned id)
{
  unsigned interface_number = BS_USB_INVALID_INTERFACE;
  unsigned i, max;
  struct bs_usb_interface_info * bs_usb_interface = NULL;

  if (vid != BS_USB_QCT_VENDOR_ID)
  {
    WOORINET_PRINT(WOORINET_ERROR,"Invalied vid 0x%04X", vid);
    return BS_USB_INVALID_INTERFACE;
  }

  if (!bs_usb_interface_get(pid, &bs_usb_interface, &max))
  {
    WOORINET_PRINT(WOORINET_ERROR,"Invalied pid 0x%04X", pid);
    return BS_USB_INVALID_INTERFACE;
  }

  if (id == 0)
  {
    memset(&interface_reserved[config_number][0], 0, sizeof(boolean)*BS_USB_MAX_INTERFACES);
  }

  for (i = 0 ; i < max ; i++ )
  {
    if ((strcmp(interface_name, bs_usb_interface->function_instance) == 0) &&
        (config_number == bs_usb_interface->config_number) && !interface_reserved[config_number][bs_usb_interface->interface_number])
    {
      /* Strings match */
      interface_number = bs_usb_interface->interface_number;
      interface_reserved[config_number][bs_usb_interface->interface_number] = true;
      break;
    }
    bs_usb_interface++;
  }

  return interface_number;
}

/************
 *
 * Name:     bs_usb_interface_enable_get
 *
 * Purpose:  get USB interface info
 *
 * Parms:    interface_name  - interface name
 *           vid             - vendor id
 *           pid             - product id
 *           config_number   - config number
 *
 * Return:   TRUE if interface is enabled
 *
 * Notes:
 *
 ************/
static inline boolean bs_usb_interface_enable_get(
  const char *interface_name,
  uint16 vid,
  uint16 pid,
  uint8 config_number)
{
  unsigned i, max;
  struct bs_usb_interface_info * bs_usb_interface = NULL;
  uint32 usbcomp = 0;
  boolean retval = FALSE;

  if (vid != BS_USB_QCT_VENDOR_ID)
  {
    WOORINET_PRINT(WOORINET_ERROR,"Invalied vid 0x%04X", vid);
    return retval;
  }

  if (!bs_usb_interface_get(pid, &bs_usb_interface, &max))
  {
    WOORINET_PRINT(WOORINET_ERROR,"Invalied pid 0x%04X", pid);
    return retval;
  }

  if (!bs_usbcomp_get(&usbcomp))
  {
    WOORINET_PRINT(WOORINET_ERROR,"can't get usbcomp");
    return retval;
  }

  for (i = 0 ; i < max ; i++ )
  {
    if ((strcmp(interface_name, bs_usb_interface->function_instance) == 0) &&
        (config_number == bs_usb_interface->config_number))
    {
      if (((usbcomp&0xFFFF0000)>>16) & (1<<(bs_usb_interface->mask)))
      {
        /* interface disabled */
        retval = FALSE;
      }
      else
      {
        /* interface enabled */
        retval = TRUE;
      }
      break;
    }
    bs_usb_interface++;
  }

  return retval;
}

#endif /* BSUSB_H_ */
