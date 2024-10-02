/*************
 *
 * $Id:$
 *
 * Name:      aadebug.h
 *
 * Purpose:   Include file for Woorinet debugging utilities
 *
 * Notes:
 *
 * Copyright: (c) 2020 WOORINET. All rights reserved.
 *
 *************/

#ifndef AADEBUG_H
#define AADEBUG_H


/*
 * Woorinet trace and logging macros
 */

/* Woorinet log levels */
#define WOORINET_ERROR                       MSG_LEGACY_ERROR
#define WOORINET_HIGH                        MSG_LEGACY_HIGH
#define WOORINET_MED                         MSG_LEGACY_MED
#define WOORINET_LOW                         MSG_LEGACY_MED

/* Prefix string for log messages */
#define FMT_PFX WOORINET_PROC_PREFIX


/*************
 *
 * Name:     WOORINET_PRINT
 *
 * Purpose:  To print debugging information with minimal overhead
 *
 * Parms:    level  - message severity
 *           format - format specifier
 *           ...    - values to be printed
 *
 * Return:   none
 *
 * Abort:    none
 *
 * Notes:    This macro is for use with direct values only.  E.g: char
 *           int, long, etc.  Strings and floating point values are
 *           not supported.  Use WOORINET_PRINTF in those cases
 *
 *           Format specifier must be a literal
 *
 *           Message severities defined by Woorinet Log Levels
 *
 **************/
/* #define WOORINET_PRINT(lvl, fmt, ...)  <platform-dependent macro> */

/*************
 *
 * Name:     WOORINET_PRINTF
 *
 * Purpose:  To print debugging information
 *
 * Parms:    level  - message severity
 *           format - format specifier
 *           ...    - values to be printed
 *
 * Return:   none
 *
 * Abort:    none
 *
 * Notes:    This macro supports strings and floating point values
 *
 *           Format specifier must be a literal
 *
 *           Message severities defined by Woorinet Log Levels
 *
 **************/
/* #define WOORINET_PRINTF(lvl, fmt, ...)  <platform-dependent macro> */

/*************
 *
 * Name:     WOORINET_LOG
 *
 * Purpose:  To print and also log debugging information
 *
 * Parms:    level  - message severity
 *           format - format specifier
 *           ...    - values to be printed
 *
 * Return:   none
 *
 * Abort:    none
 *
 * Notes:    On QCT platforms, this macro is for use with direct
 *           values only.  E.g: char int, long, etc.  Strings and
 *           floating point values are not supported.
 *
 *           Format specifier must be a literal
 *
 *           Message severities defined by Woorinet Log Levels
 *
 **************/
/* #define WOORINET_LOG(lvl, fmt, ...)  <platform-dependent macro> */

/*************
 *
 * Name:     WOORINET_ABORT
 *
 * Purpose:  ABORT in case of fatal error
 *
 * Parms:    format - crash message
 *           code1  - extra parameter with format
 *           code2  - extra parameter with format
 *           code3  - extra parameter with format
 *
 * Return:   none
 *
 * Abort:    always
 *
 * Notes:    none
 *
 **************/
/* #define WOORINET_ABORT(format, code1, code2, code3)  <platform-dependent macro> */

/*************
 *
 * Name:     WOORINET_ASSERT
 *
 * Purpose:  Given a boolean expression, WOORINET_ASSERT verifies that the condition
 *           is TRUE. If the condition is FALSE, perform WOORINET_ABORT.
 *
 * Parms:    condition - condition to evaluate
 *
 * Return:   none
 *
 * Abort:    if condition is FALSE
 *
 * Notes:    none
 *
 **************/
/* #define WOORINET_ASSERT(condition)  <platform-dependent macro> */


#define WOORINET_ABORT_PFX  "WOORINET_ABORT-"

/*
 * QCT Modem image
 */
#if defined WOORINET_IMAGE_MODEM

#include "err.h"
#include "msg.h"                   /* Clients must: RequirePublicApi('SERVICES') */

#define WOORINET_PROC_PREFIX             "M: "

#define WOORINET_PRINT(lvl, fmt, ...)    MAKE_PRINT(_WOORINET_PRINT_,  lvl, FMT_PFX fmt, ##__VA_ARGS__)
#define WOORINET_PRINTF(lvl, fmt, ...)   MAKE_PRINT(_WOORINET_PRINTF_, lvl, FMT_PFX fmt, ##__VA_ARGS__)
#define WOORINET_LOG(lvl, fmt, ...)      MAKE_LOG  (_WOORINET_LOG_,    lvl, FMT_PFX fmt, ##__VA_ARGS__)

/* WOORINET_ABORT */
#define WOORINET_ABORT(format, code1, code2, code3)  ERR_FATAL(WOORINET_ABORT_PFX WOORINET_PROC_PREFIX format, code1, code2, code3)
#define WOORINET_ASSERT(condition)  if(!(condition)) { WOORINET_ABORT("WOORINET_ASSERT(" #condition ")", 0, 0, 0); }

/*
 * Application images
 */
#elif defined WOORINET_IMAGE_APPS

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <errno.h>

#include "msg.h"

#define WOORINET_PROC_PREFIX             "A: "

#define WOORINET_PRINT(lvl, fmt, ...)    MAKE_PRINT(_WOORINET_PRINT_,  lvl, FMT_PFX fmt, ##__VA_ARGS__)
#define WOORINET_PRINTF(lvl, fmt, ...)   MAKE_PRINT(_WOORINET_PRINTF_, lvl, FMT_PFX fmt, ##__VA_ARGS__)
#define WOORINET_LOG(lvl, fmt, ...)      MAKE_LOG  (_WOORINET_LOG_,    lvl, FMT_PFX fmt, ##__VA_ARGS__)

/* WOORINET_ABORT - to be defined with APSS ER package */
#define WOORINET_ABORT(format, code1, code2, code3) os_apps_abort(__FILE__, __LINE__, format, code1, code2, code3)
#define WOORINET_ASSERT(condition)   if(!(condition)) { WOORINET_ABORT("WOORINET_ASSERT(" #condition ")", 0, 0, 0); }

/*
 * Default - Linux/Cygwin
 */
#else

#include <stdio.h>
#include <errno.h>

#define WOORINET_PROC_PREFIX

#define WOORINET_PRINT(lvl, ...)         {fprintf(stderr, FMT_PFX __VA_ARGS__);fprintf(stderr, "\r\n");}
#define WOORINET_PRINTF(lvl, ...)        {fprintf(stderr, FMT_PFX __VA_ARGS__);fprintf(stderr, "\r\n");}
#define WOORINET_LOG(lvl, ...)           {fprintf(stderr, FMT_PFX __VA_ARGS__);fprintf(stderr, "\r\n");}

/* WOORINET_ABORT */
#define WOORINET_ABORT(format, code1, code2, code3)
#define WOORINET_ASSERT(condition)

#endif


/* Utility macros to convert variadic macros to fixed argument
 * versions
 *
 * Thanks to:
 * http://stackoverflow.com/questions/2308243/macro-returning-the-number-of-arguments-it-is-given-in-c
 */
#define MAKE_PRINT(fn, ...) \
  MAKE_PRINT_(fn,lvl,fmt,##__VA_ARGS__,9,8,7,6,5,4,3,2,1,0)(__VA_ARGS__)

#define MAKE_PRINT_(fn, lvl, fmt, \
                    n0, n1, n2, n3, n4, n5, n6, n7, n8, \
                    _fmt, _lvl, n, ...) fn##n

#define MAKE_LOG(fn, ...) \
  MAKE_LOG_(fn,lvl,fmt,##__VA_ARGS__,9,8,7,6,5,4,3,2,1,0)(__VA_ARGS__)

#define MAKE_LOG_(fn, lvl, fmt,                         \
                  n0, n1, n2, n3, n4, n5, n6, n7, n8,   \
                  _fmt, _lvl, n, ...) fn##n


/* These definitions are needed because the expansion of MSG_SSID_DFLT
 * must be delayed until the underlying QCT macro is called.  If this
 * could be handled in MAKE_PRINT_, then the QCT macros could be
 * generated directly (MSG_0() would still require mapping to MSG())
 * #define MSG_0(...) MSG(__VA_ARGS__)
 */

#define _WOORINET_PRINT_0(lvl,fmt)                    MSG  (MSG_SSID_DFLT,lvl,fmt)
#define _WOORINET_PRINT_1(lvl,fmt,a)                  MSG_1(MSG_SSID_DFLT,lvl,fmt,a)
#define _WOORINET_PRINT_2(lvl,fmt,a,b)                MSG_2(MSG_SSID_DFLT,lvl,fmt,a,b)
#define _WOORINET_PRINT_3(lvl,fmt,a,b,c)              MSG_3(MSG_SSID_DFLT,lvl,fmt,a,b,c)
#define _WOORINET_PRINT_4(lvl,fmt,a,b,c,d)            MSG_4(MSG_SSID_DFLT,lvl,fmt,a,b,c,d)
#define _WOORINET_PRINT_5(lvl,fmt,a,b,c,d,e)          MSG_5(MSG_SSID_DFLT,lvl,fmt,a,b,c,d,e)
#define _WOORINET_PRINT_6(lvl,fmt,a,b,c,d,e,f)        MSG_6(MSG_SSID_DFLT,lvl,fmt,a,b,c,d,e,f)
#define _WOORINET_PRINT_7(lvl,fmt,a,b,c,d,e,f,g)      MSG_7(MSG_SSID_DFLT,lvl,fmt,a,b,c,d,e,f,g)
#define _WOORINET_PRINT_8(lvl,fmt,a,b,c,d,e,f,g,h)    MSG_8(MSG_SSID_DFLT,lvl,fmt,a,b,c,d,e,f,g,h)
#define _WOORINET_PRINT_9(lvl,fmt,a,b,c,d,e,f,g,h,i)  MSG_9(MSG_SSID_DFLT,lvl,fmt,a,b,c,d,e,f,g,h,i)

#define _WOORINET_PRINTF_0(lvl,fmt)                   MSG          (MSG_SSID_DFLT,lvl,fmt)
#define _WOORINET_PRINTF_1(lvl,fmt,a)                 MSG_SPRINTF_1(MSG_SSID_DFLT,lvl,fmt,a)
#define _WOORINET_PRINTF_2(lvl,fmt,a,b)               MSG_SPRINTF_2(MSG_SSID_DFLT,lvl,fmt,a,b)
#define _WOORINET_PRINTF_3(lvl,fmt,a,b,c)             MSG_SPRINTF_3(MSG_SSID_DFLT,lvl,fmt,a,b,c)
#define _WOORINET_PRINTF_4(lvl,fmt,a,b,c,d)           MSG_SPRINTF_4(MSG_SSID_DFLT,lvl,fmt,a,b,c,d)
#define _WOORINET_PRINTF_5(lvl,fmt,a,b,c,d,e)         MSG_SPRINTF_5(MSG_SSID_DFLT,lvl,fmt,a,b,c,d,e)
#define _WOORINET_PRINTF_6(lvl,fmt,a,b,c,d,e,f)       MSG_SPRINTF_6(MSG_SSID_DFLT,lvl,fmt,a,b,c,d,e,f)
#define _WOORINET_PRINTF_7(lvl,fmt,a,b,c,d,e,f,g)     MSG_SPRINTF_7(MSG_SSID_DFLT,lvl,fmt,a,b,c,d,e,f,g)
#define _WOORINET_PRINTF_8(lvl,fmt,a,b,c,d,e,f,g,h)   MSG_SPRINTF_8(MSG_SSID_DFLT,lvl,fmt,a,b,c,d,e,f,g,h)
/* Note: MSG_SPRINTF_9 does not exist */

#ifdef WOORINET_IMAGE_MODEM
/* Convert to fixed number of args for QCT MSG_LOG_ERR() for args up to 3 */
#define _WOORINET_LOG_0(lvl,fmt)                      MSG_ERR_LOG(0,fmt,0,0,0)
#define _WOORINET_LOG_1(lvl,fmt,a)                    MSG_ERR_LOG(1,fmt,a,0,0)
#define _WOORINET_LOG_2(lvl,fmt,a,b)                  MSG_ERR_LOG(2,fmt,a,b,0)
#define _WOORINET_LOG_3(lvl,fmt,a,b,c)                MSG_ERR_LOG(3,fmt,a,b,c)
#else
/* NOTE: IM:14:07:30 - MSG_ERR_LOG not defined on QCT apss */
#define _WOORINET_LOG_0(lvl,fmt)                      MSG  (MSG_SSID_DFLT,lvl,fmt)
#define _WOORINET_LOG_1(lvl,fmt,a)                    MSG_1(MSG_SSID_DFLT,lvl,fmt,a)
#define _WOORINET_LOG_2(lvl,fmt,a,b)                  MSG_2(MSG_SSID_DFLT,lvl,fmt,a,b)
#define _WOORINET_LOG_3(lvl,fmt,a,b,c)                MSG_3(MSG_SSID_DFLT,lvl,fmt,a,b,c)
#endif

#define _WOORINET_LOG_4(lvl,fmt,a,b,c,d)              MSG_4(MSG_SSID_DFLT,lvl,fmt,a,b,c,d)
#define _WOORINET_LOG_5(lvl,fmt,a,b,c,d,e)            MSG_5(MSG_SSID_DFLT,lvl,fmt,a,b,c,d,e)
#define _WOORINET_LOG_6(lvl,fmt,a,b,c,d,e,f)          MSG_6(MSG_SSID_DFLT,lvl,fmt,a,b,c,d,e,f)
#define _WOORINET_LOG_7(lvl,fmt,a,b,c,d,e,f,g)        MSG_7(MSG_SSID_DFLT,lvl,fmt,a,b,c,d,e,f,g)
#define _WOORINET_LOG_8(lvl,fmt,a,b,c,d,e,f,g,h)      MSG_8(MSG_SSID_DFLT,lvl,fmt,a,b,c,d,e,f,g,h)
#define _WOORINET_LOG_9(lvl,fmt,a,b,c,d,e,f,g,h,i)    MSG_9(MSG_SSID_DFLT,lvl,fmt,a,b,c,d,e,f,g,h,i)

/* Developers may use the __func__ macro to include the function
 * name in debug strings.
 *
 * Ensure __func__ is defined as something
 */
#if !defined(__func__)
  #define __func__ __FUNCTION__
#endif  /* ! __func__ */


/* VA_NUM_ARGS() evaluates to the length of it's argument list
 * zero-length is supported.
 *
 * Thanks to:
 * http://stackoverflow.com/questions/2308243/macro-returning-the-number-of-arguments-it-is-given-in-c
 *
 * Note dummy first argument _ and ##__VA_ARGS__ instead of __VA_ARGS__
 */
#define VA_NUM_ARGS(...)     VA_NUM_ARGS_(_, ##__VA_ARGS__, _REV_N())

#define VA_NUM_ARGS_(...)    _ARG_N(__VA_ARGS__)

#define _ARG_N( \
          _1,  _2,  _3,  _4,  _5,  _6,  _7,  _8,  _9, _10, \
         _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, \
         _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, \
         _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, \
         _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, \
         _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, \
         _61, _62, _63, N, ...) N

/* Note 63 is removed to allow for zero arguments */
#define _REV_N()                                           \
          62, 61, 60,                                      \
          59, 58, 57, 56, 55, 54, 53, 52, 51, 50,          \
          49, 48, 47, 46, 45, 44, 43, 42, 41, 40,          \
          39, 38, 37, 36, 35, 34, 33, 32, 31, 30,          \
          29, 28, 27, 26, 25, 24, 23, 22, 21, 20,          \
          19, 18, 17, 16, 15, 14, 13, 12, 11, 10,          \
          9,  8,  7,  6,  5,  4,  3,  2,  1,  0,


#endif /* AADEBUG_H */
