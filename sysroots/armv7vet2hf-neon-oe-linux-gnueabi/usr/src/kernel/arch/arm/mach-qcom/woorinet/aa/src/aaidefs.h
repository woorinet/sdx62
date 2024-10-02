/*************
 *
 * Filename:  aaidefs.h
 *
 * Purpose:   internal definitions for aa
 *
 * Copyright: (c) 2016 WOORINET. All rights reserved.
 *
 **************/

/* Include files */
#include "aaudefs.h"


/************
 *
 * Name:     aa_carrier_version_s
 *
 * Purpose:  carrier version
 *
 * Notes:    aa_carrier       - carrier name
 *           aa_build_tag     - internal version
 *           aa_build_ofc_tag - official version
 *           aa_version_tag   - internal full version tag
 *
 ************/
struct aa_carrier_version_s
{
  const char *aa_carrier;
  const char *aa_build_tag;
  const char *aa_build_ofc_tag;
  const char *aa_version_tag;
};

#include "aaiproto.h"