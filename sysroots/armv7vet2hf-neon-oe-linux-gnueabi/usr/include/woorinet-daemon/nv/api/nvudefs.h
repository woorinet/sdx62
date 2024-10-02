/************
 *
 * Filename:   nvudefs.h
 *
 * Purpose:    user definitions for NV package
 *
 * Copyright: (c) 2016 WOORINET. All rights reserved.
 *
 ************/
#ifndef NVUDEFS_H
#define NVUDEFS_H

/* Include files */
#include "aaglobal.h"
#include "nv_efs_items.h"
#include "nv_woorinet_items.h"

#ifdef WOORINET_IMAGE_MODEM
#include "nv.h"
#endif

/* Local constants and enumerated types */

#define NV_APPS_STACK_SIZE (64*1024)

/* Special value to indicate that a tag is not known */
#define NV_TAG_UNKNOWN               ((unsigned int)(-1))

/************
 *
 * Name:     nv_backup_option_e
 *
 * Purpose:  Enumerate all supported NV Backup options
 *
 * Notes:
 *
 ************/
enum nv_backup_option_e
{
  NV_BACKUP_MIN     = 0,                 /* Internal use                           */
  NV_BACKUP_BACKUP  = NV_BACKUP_MIN,     /* backup                                 */
  NV_BACKUP_DELETE  = 1,                 /* delete                                 */
  NV_BACKUP_RESTORE = 2,                 /* restore                                */
  NV_BACKUP_MAX     = NV_BACKUP_RESTORE, /* Max                                    */
 };

/************
 *
 * Name:     nvtype
 *
 * Purpose:  To allow other functions to differentiate between
 *           NV types
 *
 * Notes:
 *
 ************/
enum nvtype
{
  NV_TYPE_QCT_LEGACY,
  NV_TYPE_QCT_RFNV,
  NV_TYPE_WOORINET_MODEM,
  NV_TYPE_EFS,
  NV_TYPE_UNKNOWN,
};

/************
 *
 * Name:     nvmanagementtype
 *
 * Purpose:  Enumerate all supported NV management type
 *
 * Notes:    WARNING - these enums are also used by scripts to generate
 *                     NV default files.  Scripts must be updated to
 *                     match
 *
 ************/
enum nvmanagementtype
{
  NVMMT_TYPE_MIN = 0,                  /* Start of list - Internal         */
  NVMMT_TYPE_QCTNV = NVMMT_TYPE_MIN,   /* Qualcomm legacy and RF NV items  */
  NVMMT_TYPE_WOORINETNV,               /* Woorinet NV items                */
  NVMMT_TYPE_EFS,                      /* Regular file                     */
  NVMMT_TYPE_EFSITEM,                  /* EFS item file                    */
  NVMMT_TYPE_DIRBU,                    /* Directory backup                 */
  NVMMT_TYPE_LINK,                     /* Symbolic Link                    */
  NVMMT_TYPE_CMD = 0x80,               /* command                          */
  NVMMT_TYPE_MAX,                      /* End of list - Internal           */
  NVMMT_TYPE_PAD = 0xFFFFU,            /* force to uint16                  */
  NVMMT_TYPE_UNKNOWN = NVMMT_TYPE_PAD  /* Unknown - use instead of MAX     */
}PACKED_POST;


/* Structures */


#include "nvuproto.h"

#endif /* NVUDEFS_H */
