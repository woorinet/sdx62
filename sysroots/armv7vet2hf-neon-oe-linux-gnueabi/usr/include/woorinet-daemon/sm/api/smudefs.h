/************
 *
 * Filename:  smudefs.h
 *
 * Purpose:   External definitions for the sm package
 *
 * Copyright: (c) 2020 WOORINET. All rights reserved.
 *
 * PLEASE READ smreadme.txt FOR NOTES AND EXAMPLES ON USING THIS PACKAGE
 *
 ************/

#ifndef SMUDEFS_H
#define SMUDEFS_H

/* include files */
#include "aaglobal.h"

/*************
 *
 * Name:     Special States
 *
 * Purpose:  The definitions are used to signal the state machine
 *           to take special actions, instead of transitioning to
 *           another state
 *
 * Members:  SM_INVAL - Received event is invalid for this state - ABORT
 *           SM_IGNOR - Ignore event in this state
 *
 * Notes:
 *
 **************/
#define SM_INVAL 0xFF
#define SM_IGNOR 0xFE

/*************
 *
 * Name:     smaction_t
 *
 * Purpose:  definition for action functions to be executed upon
 *           entering a state.  Used in the state action table.
 *
 * Notes:
 *
 **************/
typedef void (*smaction_t)(void *pdata);

/*************
 *
 * Name:     sm_t
 *
 * Purpose:  State machine type.  Allows multiple state machines
 *           to be managed
 *
 * Members:  state   - current state
 *           evnum   - number of possible events
 *           sat     - state action table
 *           stt     - state transition table
 *           udata   - user data, passed to action functions in the stt
 *
 * Notes:    Events MUST be numbered from 0 to evnum-1.  They are used
 *           to index into the state transition table
 *
 **************/
typedef struct
{
  int         state;
  int         evnum;
  smaction_t  *sat;
  uint8_t     *stt;
  void        *udata;
} sm_t;

/*
 * Package global entry point definitions - these come last
 */
#include "smuproto.h"

#endif /* SMUDEFS_H */

