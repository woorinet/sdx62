/************
 *
 * $Id$
 *
 * Filename:  suudefs - user definitions for su
 *
 * Copyright: (c) 2020 WOORINET. All rights reserved.
 *
 ************/
#ifndef SUUDEFS_H
#define SUUDEFS_H

/* Include files */

/* Local constants and enumerated types */

/* Timeout for tmc_init to complete.
 *
 * Some measured times:
 *   EFS rebuild with no NV restore:  ~6 sec
 *   EFS rebuild with NV restore:     >16 sec
 *   FILE write remote API sync:      30 sec
 *   NVUP remote API sync:            30 sec
 *
 *   2013:02:17 - another 100 s added to allow for image switching
 */
#define SU_INIT_COMPLETION_TIMEOUT 200000    /* in ms */

/* timeout to clear smart recovery counter */
#define SU_INIT_ERROR_COUNT_TIMEOUT 30000     /* in ms */

/* Structures */

#include "suuproto.h"
#endif
