/************
 *
 * Package Name: SM - state machine
 *
 * Purpose:      This package provides simple methods for a table
 *               driven state machine
 *
 * Notes:        
 *
 * Copyright: (c) 2020 WOORINET. All rights reserved.
 *
 ************/

/*
 * This state machine package simplifies the implementation of state
 * machines with some structurs and an smrun() function.  The smrun
 * function is to be called whenever an event is recieved.  Using the
 * existing os message functions (osmsgrcv) ensures that events will
 * be processed in sequence.
 *
 * The following is an example of how to use the sm package.  The
 * string: "<module>" can be replaced with the state machine/package
 * name.
 *
 * 0. Draw a state diagram
 *
 * 1. Define the events to be sent to the machine: <module>event_t.
 *    These enumerations must be sequential and zero-based.
 *
 * 2. Define the states which the machine can occupy: <module>state_t
 * 
 * 3. Define the actions that are to be taken upon entering each
 *    state.  These "action functions" are placed in the 
 *    "State Action Table".  No action (NULL) is perfectly valid.
 *
 * 4. Fill in the state transition table.  Use these "special states"
 *    where required:
 *
 *    Special states:
 *
 *      SM_IGNOR:  State will not change, action will not be called
 *      SM_INVAL:  An ABORT will be called
 *
 * NOTES:
 * 
 *    The API should not expose any of the internal state machine
 *    structures.  Externalized functions should only send events to
 *    the state machine.
 *
 *    Processing an event which causes the machine to remain in the
 *    same state will not call the action function again 
 *
 *    Action functions should not block.  Instead, callbacks should be
 *    used to send "completion" events to the machine.  Extra states
 *    may be needed to wait for the callback(s).
 *
 *    Multiple machines can run in the same task with some simple
 *    logic in the task processing loop (see end of this file).
 */

/* include files */
#include "osudefs.h"
#include "smudefs.h"

/*
 *  local constants and enumerated types
 */

/* Length of event queue for state machine */
#define <MODULE>_MAX_MSG_BUFS              <length_of_event_queue>

/*************
 *
 * Name:     <module>event_t
 *
 * Purpose:  Enumerated events to drive state machine
 *       
 * Members:  evZERO     -
 *           evONE      -
 *           evTWO      - 
 *           ...
 *           evMAX      - Number of events
 *
 * Notes:    EVENTS MUST BE ENUMERATED FROM 0 (zero)
 *
 **************/
enum <module>event_t
{
  evZERO,
  evONE,
  evTWO,

  evMAX
};

/*************
 *
 * Name:     <module>state_t
 *
 * Purpose:  Enumerated states, managed by state machine
 *       
 * Members:  stZERO     -
 *           stONE      - 
 *           stTWO      - 
 *           stMAX      - Number of states
 *
 * Notes:    STATES MUST BE ENUMERATED FROM 0 (zero)
 *
 **************/
enum <module>state_t
{
  stZERO,
  stONE,
  stTWO,

  stMAX
};

/*************
 *
 * Name:     <module>_action_<state>
 *
 * Purpose:  State action functions, executed upon entering a given 
 *           state
 *
 * Parms:    void * pdata - User data passed in via udata pointer
 *                          argument to sminit()
 *
 * Return:   none
 *
 * Abort:    
 *
 * Notes:    These forward declarations required for <module>_sat[]
 *
 **************/
_local void <module>_action_state_zero (void *pdata);
#define     <module>_action_state_one  NULL
_local void <module>_action_state_two  (void *pdata);


/*
 *  local variables
 */
/* task control block for os package functions */
_local struct ostcb <module>tcb;

/*************
 *
 * Name:     <module>_sm
 *
 * Purpose:  local state machine instance
 *
 * Notes:    
 *
 **************/
_local sm_t <module>_sm;

/*************
 *
 * Name:     <module>_stt
 *
 * Purpose:  Describes state transistions used by the <module> state machine
 *
 * Notes:    
 *
 **************/
_local uint8 <module>_stt[stMAX*evMAX] = 
{
/* evZERO     evONE     evTWO     ...                        <-Events
  ------------------------------------------------------------------- */
   stONE,     SM_IGNOR, SM_IGNOR, ...                       /* stZERO */
   SM_IGNOR,  stZERO,   stTWO,    ...                       /* stONE  */
   SM_INVAL,  stZERO,   SM_IGNOR, ...                       /* stTWO  */
};

/*************
 *
 * Name:     <module>_sat
 *
 * Purpose:  set of functions executed upon entering a state
 *
 * Members:  one for each state
 *
 * Notes:    
 *
 **************/
smaction_t <module>_sat[stMAX] = 
{
  <module>_action_state_zero,
  <module>_action_state_one,
  <module>_action_state_two,
};


/*
 * Internal functions
 */

/*************
 *
 * Name:     <module>_action_switch_to_modem
 *
 * Purpose:  state action function - calls external function to initiate 
 *           switching to modem mode
 *
 * Parms:    void * pdata - unused
 *
 * Return:   none
 *
 * Abort:    none
 *
 * Notes:    
 *
 **************/
_local void <module>_action_state_zero (void *pdata)
{
  /* Execute code here.  All operations inside an action function
   * should be non-blocking. */
}

/* 
 * Externalized Functions
 */

/*************
 *
 * Name:     <module>_externalized_function
 *
 * Purpose:  To send events to the state machine
 *
 * Params:   
 *
 * Return:   none
 *
 * Abort:    none
 *
 * Notes:    Functions on the external API should only send events
 *           to the state machine.  They may also query the state but
 *           the user should be aware that the state is managed in a 
 *           separate context
 *
 **************/
_global void <module>_externalized_function
(
  uint16 colour
)
{
  switch(colour)
  {
    case PURPLE:
    {
      osmsgsend(&swoctcb, evZERO);
      break;
    }

    case ORANGE:
    {
      osmsgsend(&<module>tcb, evTWO);
      break;
    }

    default:
      WOORINET_ABORT("Unrecognized Colour", mode, 0, 0);
      break;
  }
}

/*************
 *
 * Name:     <module>_task_init
 * 
 * Purpose:  To initialize the <module>_task
 * 
 * Params:   none
 *
 * Return:   none
 *
 * Abort:    none
 *
 * Notes:    
 *
 **************/
_package void <module>_task_init (void)
{
  /* Initialize task block */
  <module>tcb.ostaskp = &<module>_tcb;

  /* Setup data structures for task */
  ostaskcreate(&<module>tcb, NULL, NULL, 0, 0, "<MODULE> Task", <MODULE>_MAX_MSG_BUFS);
}

/*************
 *
 * Name:     <module>task
 *
 * Purpose:  To synchronously process state machine events
 *
 * Parms:    parm - from REX (ignored)
 *
 * Return:   no value
 *
 * Abort:    Invalid event
 *
 * Notes:    This function does not return
 *
 **************/
_global void <module>_task
(
  dword parm
)
{
  ostaskstart(&<module>tcb, DOG_<MODULE>_RPT, DOG_<MODULE>_RPT_TIME);

  /* initialize and run the state machine */
  sminit(&<module>_sm, <module>_sat, <module>_stt, evMAX, stMAX, stINIT, udata);
  while(1)
  {
    smrun(&<module>_sm, osmsgrcv(&<module>tcb));
  }
}



/* Example of task with multiple state machines (there are other ways
 * to accomplish this) */
_global void <module>_task
(
  dword parm
)
{
  ostaskstart(&<module>tcb, DOG_<MODULE>_RPT, DOG_<MODULE>_RPT_TIME);
  
  /* initialize and run the state machine */
  sminit(&<module>_sm, <module>_sat, <module>_stt, evMAX, stMAX, stINIT, udata);
  while(1)
  {
    event = osmsgrcv(&tcb);
    
    if (event < sm1_evMax)
    {
      smrun(&sm1, event);
      continue;
    }
    event -= sm1_evMax;
    
    if (event < sm2_evMax)
    {
      smrun(&sm2, event);
      continue;
    }
    event -= sm2_evMax;
    
    etc...
  }
}


