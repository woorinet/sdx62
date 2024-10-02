/*************
 *
 * Name:      bsudefs.h
 *
 * Purpose: external definitions for Board Support package
 *
 * Copyright: (c) 2016 WOORINET. All rights reserved.
 *
 *************/

#ifndef BSUDEFS_H
#define BSUDEFS_H

#include <linux/soc/qcom/smem.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/io.h>
#include <linux/of.h>
#include <linux/of_address.h>
#include <generated/utsrelease.h>

#ifndef SMEM_ID_VENDOR0
#define SMEM_ID_VENDOR0           134
#endif
#ifndef SMEM_ID_VENDOR1
#define SMEM_ID_VENDOR1           135
#endif
#ifndef SMEM_ID_VENDOR2
#define SMEM_ID_VENDOR2           136
#endif

#ifndef SMEM_IMAGE_VERSION_TABLE
#define SMEM_IMAGE_VERSION_TABLE  469
#endif

#include "wsmem.h"

#include "bsuproto.h"
#endif /* BSUDEFS_H */
