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

#define WOORINET_ERROR                       3
#define WOORINET_HIGH                        2
#define WOORINET_MED                         1
#define WOORINET_LOW                         0

#define WOORINET_PRINT(lvl, fmt, ...)        do { if (lvl) { printk(KERN_ERR "WOORINET %s: " fmt "\n", __func__, ##__VA_ARGS__); }} while (0)
#define WOORINET_PRINTF(lvl, fmt, ...)       do { if (lvl) { printk(KERN_ERR "WOORINET %s: " fmt "\n", __func__, ##__VA_ARGS__); }} while (0)

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
