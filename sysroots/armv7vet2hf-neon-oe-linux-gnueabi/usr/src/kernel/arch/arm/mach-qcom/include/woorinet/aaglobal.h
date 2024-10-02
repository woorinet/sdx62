/*************
 *
 *  Name:      aaglobal_linux.h
 *
 *  Purpose:   global definitions for Little Kernel and Linux Kernel
 *
 *  Note:      this file is open source
 *
 **************/

#ifndef AAGLOBAL_LINUX_H
#define AAGLOBAL_LINUX_H

#if defined(WOORINET_IMAGE_LK)
#include <stdint.h>
#else
#include <linux/types.h>
#endif


/* function and variable scope modifiers
 *
 * Note: currently package and global are only used manually,
 * someday tools should make use of these indentifiers ie. prototype
 * generation tools
 */
#define _local static  /* function/variable accessed within local file only */
#define _package       /* accessable within package only, used for fns only */
#define _global        /* function accessed globally, used for functions only */

typedef int boolean;
typedef uint8_t uint8;
typedef uint16_t uint16;
typedef uint32_t uint32;
typedef uint64_t uint64;
typedef int8_t int8;
typedef int16_t int16;
typedef int32_t int32;

#ifndef FALSE
#define FALSE 0
#endif

#ifndef TRUE
#define TRUE  1
#endif

#ifndef NULL
#define NULL ((void *)0)
#endif

#define PACKED
#define PACKED_POST __attribute__((packed))

#endif /* AAGLOBAL_LINUX_H */