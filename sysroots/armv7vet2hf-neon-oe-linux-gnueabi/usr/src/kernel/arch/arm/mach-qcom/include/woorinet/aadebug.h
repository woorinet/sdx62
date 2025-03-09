/*************
 *
 * Name:      aadebug_linux.h
 *
 * Purpose:   LK and Linux kernel include file for Woorinet debugging utilities
 *
 * Copyright: (c) 2016 WOORINET. All rights reserved.
 *
 *************/

#ifndef AADEBUG_LINUX_H
#define AADEBUG_LINUX_H

/*
 * Little kernel
 */
#if defined(WOORINET_IMAGE_LK)

#include <debug.h>

#define WOORINET_ERROR                       CRITICAL
#define WOORINET_HIGH                        ALWAYS
#define WOORINET_MED                         INFO
#define WOORINET_LOW                         SPEW

#define WOORINET_PRINT                       dprintf
#define WOORINET_PRINTF                      dprintf

#define WOORINET_ASSERT                      assert

/*
 * Linux kernel images
 */
#elif defined(__KERNEL__)
#include <linux/module.h>

#define WOORINET_ERROR                       KERN_ERR
#define WOORINET_HIGH                        KERN_WARNING
#define WOORINET_MED                         KERN_NOTICE
#define WOORINET_LOW                         KERN_INFO

#define WOORINET_PRINT(lvl, fmt, ...)        do { if (lvl) { printk(lvl "WOORINET %s: " fmt "\n", __func__, ##__VA_ARGS__); }} while (0)
#define WOORINET_PRINTF(lvl, fmt, ...)       do { if (lvl) { printk(lvl "WOORINET %s: " fmt "\n", __func__, ##__VA_ARGS__); }} while (0)

#define WOORINET_ASSERT(x)                   BUG_ON(!(x))


/*
 * Default - Linux/Cygwin
 */
#else

#define WOORINET_PROC_PREFIX

#define WOORINET_PRINT(lvl, ...)         fprintf(stderr, FMT_PFX __VA_ARGS__)
#define WOORINET_PRINTF(lvl, ...)        fprintf(stderr, FMT_PFX __VA_ARGS__)
#define WOORINET_LOG(lvl, ...)           fprintf(stderr, FMT_PFX __VA_ARGS__)

#define WOORINET_ASSERT(condition)

#endif



#endif /* AADEBUG_LINUX_H */
