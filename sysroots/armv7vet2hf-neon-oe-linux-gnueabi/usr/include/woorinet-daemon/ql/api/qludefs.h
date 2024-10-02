/*************
 *
 * Filename:  qludefs.h
 *
 * Purpose:   user definitions for queue management
 *
 * Copyright: (c) 2020 WOORINET. All rights reserved.
 *
 *************/

#ifndef QLUDEFS_H
#define QLUDEFS_H

#include "aaglobal.h"

/*************
 *
 * Name:      qllink
 *
 * Purpose:   An individual queue link
 *
 * Notes:     none
 *
 *************/
struct qllink
{
  struct qllink *qlnextp;       /* pointer to next queue link */
  struct qllink *qlprevp;       /* pointer to previous queue link */
  void *qluserp;                /* pointer to user data being linked */
};

#include "qluproto.h"

#endif /* QLUDEFS_H */
