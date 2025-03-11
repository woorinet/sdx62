/************
 *
 * $Id$
 *
 * Filename:  bsidefs.h
 *
 * Purpose:   internal definitions for bs
 *
 * Copyright: (c) 2016 WOORINET. All rights reserved.
 *
 ************/

/* Include files */
#include "bsudefs.h"

/* Local constants and enumerated types */

/* from modem_proc/core/debugtools/version/src/image_version.h */
#define ZERO_SEP                          '0'
#define SPACE_SEP                         ' '
#define COLON_SEP                         ':'
#define EQUAL_SEP                         '='
#define SMEM_IMAGE_VERSION_TABLE_SIZE     4096
#define SMEM_IMAGE_VERSION_ENTRY_SIZE     128

#define IMAGE_INDEX_LENGTH                2
#define IMAGE_SEP1_LENGTH                 1
#define IMAGE_QC_VERSION_STRING_LENGTH    72
#define IMAGE_VARIANT_STRING_LENGTH       20
#define IMAGE_SEP2_LENGTH                 1
#define IMAGE_OEM_VERSION_STRING_LENGTH   32

/************
 *
 * Name:     image_index_type
 *
 * Purpose:  image_index_type
 *
 * Notes:    none
 *
 ************/
typedef enum
{
  IMAGE_INDEX_SBL = 0,
  IMAGE_INDEX_TZ = 1,
  IMAGE_INDEX_RPM = 3,
  IMAGE_INDEX_APPSBL = 9,
  IMAGE_INDEX_APPS = 10,
  IMAGE_INDEX_MPSS = 11,
  IMAGE_INDEX_MAX = 32,
  IMAGE_INDEX_ENUM_SIZE = 99 // facilitate compiler optimization
} image_index_type;

/* Structures */

/************
 *
 * Name:     image_version_entry
 *
 * Purpose:  image_version_entry
 *
 * Notes:    none
 *
 ************/
struct image_version_entry
{
  char image_index[IMAGE_INDEX_LENGTH];
  char image_colon_sep1[IMAGE_SEP1_LENGTH];
  char image_qc_version_string[IMAGE_QC_VERSION_STRING_LENGTH];
  char image_variant_string[IMAGE_VARIANT_STRING_LENGTH];
  char image_colon_sep2[IMAGE_SEP2_LENGTH];
  char image_oem_version_string[IMAGE_OEM_VERSION_STRING_LENGTH];
};

#include "bsiproto.h"
