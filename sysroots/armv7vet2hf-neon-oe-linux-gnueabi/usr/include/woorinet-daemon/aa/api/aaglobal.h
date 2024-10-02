/*************
 *
 *  Name:      aaglobal.h
 *
 *  Purpose:   Include file for typedefs required in the Woorinet
 *             portion of the system. Third party code
 *             may not follow this standard.
 *
 *  Note:      These definitions are for use in the internal
 *             portion of the API. The definitions used by the public
 *             part are defined separately.
 *
 * Copyright: (c) 2020 WOORINET. All rights reserved.
 *
 **************/

#ifndef AAGLOBAL_H
#define AAGLOBAL_H
#include <stdint.h>
#include <string.h>

#include "comdef.h"

#ifndef STDC99
#include <stdbool.h>
#endif

/************
 *
 * Name:     STATIC_ASSERT, GLOBAL_STATIC_ASSERT
 *
 * Purpose:  Macros for compile time size checking
 *
 * Parms:    e - expression to evaluate
 *           m - message to print if expression evaluates to 0
 *
 * Notes:    Use as follows:
 *
 *           STATIC_ASSERT         function scope
 *           GLOBAL_STATIC_ASSERT  global scope
 *
 *           When the expression is evaluated as false, a divide by zero
 *           compilation error will occur.
 *
 *           For more info:
 *             http://www.pixelbeat.org/programming/gcc/static_assert.html
 *
 ************/
#if defined(static_assert)

  #define STATIC_ASSERT(e, m)       static_assert(e, m)
  #define GLOBAL_STATIC_ASSERT(e,m) static_assert(e, m)

#else
 /* Note we need the 2 concats below because arguments to ##
  * are not expanded, so we need to expand __LINE__ with one
  * indirection before doing the actual concatenation.
  */
  #define ASSERT_CONCAT_(a, b) a##b
  #define ASSERT_CONCAT(a, b) ASSERT_CONCAT_(a, b)

  /* These can't be used after statements in c89. */
  #ifdef __COUNTER__

    #define STATIC_ASSERT(e,m) \
      { enum { ASSERT_CONCAT(static_assert_, __COUNTER__) = 1/(!!(e)) }; }

    #define GLOBAL_STATIC_ASSERT(e,m) \
      enum { ASSERT_CONCAT(static_assert_, __COUNTER__) = 1/(!!(e)) };
  #else
  /* This can't be used twice on the same line so ensure if using in headers
   * that the headers are not included twice (by wrapping in #ifndef...#endif)
   * Note it doesn't cause an issue when used on same line of separate modules
   * compiled with gcc -combine -fwhole-program.
   */
    #define STATIC_ASSERT(e,m) \
      { enum { ASSERT_CONCAT(assert_line_, __LINE__) = 1/(!!(e)) }; }

    #define GLOBAL_STATIC_ASSERT(e,m) \
      enum { ASSERT_CONCAT(assert_line_, __LINE__) = 1/(!!(e)) };
  #endif

#endif  /* defined(static_assert) */


/* function and variable scope modifiers
 *
 * Note: currently package and global are only used manually,
 * someday tools should make use of these indentifiers ie. prototype
 * generation tools
 */
#define _local static  /* function/variable accessed within local file only */
#define _package       /* accessable within package only, used for fns only */
#define _global        /* function accessed globally, used for functions only */


#define EOS '\0'

#define FALSE 0
#define TRUE  1

#ifndef NULL
#define NULL ((void *)0)
#endif


/* The modem returns some strings in UCS2 format.  UCS2 is 16-bits
 * max. The definition here is to aid in copying UCS2 data from the
 * modem
 */
typedef unsigned short  UCS2;
typedef UCS2           *UCS2p;

/* Alignment operators */
#define ALIGN4 (sizeof(uint32) -1)
#define ALIGN2 (sizeof(uint16) -1)


/* Apps-only definitions */

#if defined(WOORINET_IMAGE_APPS)

#define UTF8_MAX_CHAR_SIZE 4
#define PACKED

/* condef.h has defined necessary types */
#ifndef COMDEF_H
typedef unsigned char      uint8;   /* 8  bit integer unsigned  */
typedef unsigned short     uint16;  /* 16 bit integer unsigned  */
typedef unsigned long long uint64;  /* 64 bit integer unsigned  */
typedef signed char        int8;    /* 8  bit integer signed    */
typedef signed short       int16;   /* 16 bit integer signed    */
typedef signed long long   int64;   /* 64 bit integer signed    */

/* This section is for building for 64-bit Linux hosts */

#ifdef __LP64__                     /* GCC macro indicating longs are 64-bits */
typedef unsigned int       uint32;  /* 32 bit integer unsigned  */
typedef signed int         int32;   /* 32 bit integer signed    */
#else                               /* longs are 32-bits (default) */
typedef unsigned long      uint32;  /* 32 bit integer unsigned  */
typedef signed long        int32;   /* 32 bit integer signed    */
#endif /* __LP64__ */
#endif

#endif /* WOORINET_IMAGE_APPS */


/* Boot-only definitions */

#if defined (WOORINET_IMAGE_BOOT)
/* Some posix types are not defined in the bootloader.  Also, there
 * is no readily available types.h or stddef.h which will define all
 * the needed types.  The types are defined here to match the sizes
 * in fs_sys_types.h
 */

#ifndef dev_t
typedef uint32_t dev_t;         /* fs_dev_t is smaller than fs_devspecial_t */
#endif

#ifndef ino_t
typedef uint32_t ino_t;         /* fs_inode_t */
#endif

#ifndef mode_t
typedef uint16_t mode_t;        /* fs_mode_t */
#endif

#ifndef nlink_t
typedef uint8_t nlink_t;        /* fs_nlink_t */
#endif

#ifndef uid_t
typedef uint16_t uid_t;         /* fs_stat uses uint16 instead of fs_uid_t */
#endif

#ifndef gid_t
typedef uint16_t gid_t;         /* fs_stat uses uint16 instead of fs_gid_t */
#endif

#ifndef off_t
typedef int32_t off_t;          /* fs_off_t */
#endif

#ifndef blksize_t
typedef unsigned long blksize_t;
#endif

#ifndef blkcnt_t
typedef unsigned long blkcnt_t; /* fs_stat uses unsigned long instead of fs_fsblkcnt_t */
#endif

#ifndef time_t
typedef uint32_t time_t;        /* fs_time_t */
#endif

#ifndef ssize_t
typedef int32_t ssize_t;        /* fs_ssize_t */
#endif

#ifndef size_t
typedef uint32_t size_t;        /* fs_ssize_t */
#endif

#ifndef boolean
typedef uint8_t boolean;
#endif

#endif  /* WOORINET_IMAGE_BOOT */

#ifndef MAX_UINT8
#define MAX_UINT8          0xFF
#endif

#endif /* AAGLOBAL_H */
