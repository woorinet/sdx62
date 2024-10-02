/*************
 *
 * $Id$
 *
 * Filename:  sludefs - user definitions for sl
 *
 * Copyright: (c) 2020 WOORINET. All rights reserved.
 *
 **************/
#ifndef SLUDEFS_H
#define SLUDEFS_H

/* Include files */
#include "aaglobal.h"
#include <stdarg.h>
#include <string.h>
#include <time.h>
#include <stdio.h> 
 
/* Local constants and enumerated types */
#define SLCR    0x0D        /* carriage return */
#define SLLF    0x0A        /* line feed */

#define SLUINT64MAX 0xFFFFFFFFFFFFFFFFULL

/* Structures */

/*************
 *
 * Name:     slstrtokblk - string token control block
 *
 * Purpose:  This structure contains the pointer to where the untokenized
 *           character sequence is located.
 *
 * Members:  slstrtokevalp - points to first character after the delimiter.
 *                           Used to evaluate whether the sequence of
 *                           characters after the delimiter is a token.
 *
 * Notes:    Supports static data for slstrtok() reentrancy.
 *
 **************/
struct slstrtokblk
{
  char *slstrtokevalp;
};

/*************
 *
 * Name:     time_julian_type
 *
 * Purpose:  Same structure as on modem_proc.
 *
 * Members:
 *
 * Notes:
 *
 **************/
struct time_julian_type
{
  uint16 year;   /**< Year [1980 through 2100]. */
  uint16 month;  /**< Month of year [1 through 12]. */
  uint16 day;    /**< Day of month [1 through 31]. */
  uint16 hour;   /**< Hour of day [0 through 23]. */
  uint16 minute; /**< Minute of hour [0 through 59]. */
  uint16 second; /**< Second of minute [0 through 59]. */
  uint16 day_of_week; /**< Day of the week [0 through 6] or [Monday through
                           Sunday]. */
};

#include "sluproto.h"
#endif

