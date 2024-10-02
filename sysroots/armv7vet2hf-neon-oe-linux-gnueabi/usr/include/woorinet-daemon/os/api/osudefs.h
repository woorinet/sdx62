/************
 *
 * $Id$
 *
 * Filename:  osudefs
 *
 * Purpose:   User definitions for OS
 *
 * Copyright: (c) 2020 WOORINET. All rights reserved.
 *
 ************/
#ifndef OSUDEFS_H
#define OSUDEFS_H

/* Include files */
#include "aaglobal.h"

/* Global constants and enumerated types */

/* Max. # of timers supported. There are 32 task signals and 10 are 
 * taken (see ostaskcreate()), so the rest are available for timers. 
 */ 
#define OS_TIMERS_MAX 22         

/* value to indicate unlimited pool size */
#define OS_TIMEOUT_NEVER   ((unsigned int)(-1))

/* Maximum string length of messsage queue name (not incl. null) */
#define OS_MSG_Q_NAME_LEN_MAX 15         

/* Local constants and enumerated types */

/* Structures */

/************
 *
 * Name:     ostimerstate
 *
 * Purpose:  used to track state of a timer
 *
 * Notes:
 *
 ************/
enum ostimerstate
{
  OSRUNNING = 0,           /* timer is running  */
  OSSTOPPED,               /* timer is stopped  */
  OSEXPIRED,               /* timer has expired */
};

/************
 *
 * Name:     ospoolnames
 *
 * Purpose:  To provide a set of identifiers for DSM pools that callers must
 *           use to reference where they want to obtain a block from when
 *           calling osdsmgetbyname().
 *
 * Notes:    Whenever adding new pools to DSM, this list must also be updated
 *           if the new pool is to be exposed to Woorinet code.
 *
 ************/
enum ospoolnames
{
  OSDSMMIN = 0,
  OSDSMSMALL = OSDSMMIN,   /* Small pool */
  OSDSMLARGE,              /* Large pool */
  OSDSMMAX,
};

/************
 *
 * Name:     ossleepmode
 *
 * Purpose:  used to define timer behaviour during sleep
 *
 * Notes:
 *
 ************/
enum ossleepmode
{
  OSSLEEP = 0,             /* timer gets disabled during sleep  */
  OSNOSLEEP                /* timer remains active during sleep */
};

/************
 *
 * Name:     os_init_group_e
 *
 * Purpose:  To enumerate the init groups
 *
 * Notes:    Keep in sync with QCT RCINIT_GROUP
 *
 ************/
enum os_init_group_e
{
  OS_INIT_GROUP_0    = 0,
  OS_INIT_GROUP_1    = 1,
  OS_INIT_GROUP_2    = 2,
  OS_INIT_GROUP_3    = 3,
  OS_INIT_GROUP_4    = 4,
  OS_INIT_GROUP_5    = 5,
  OS_INIT_GROUP_6    = 6,
  OS_INIT_GROUP_7    = 7,
  OS_INIT_GROUP_NONE = 8,
  OS_INIT_GROUP_MAX  = OS_INIT_GROUP_NONE,
};

/* Structures */

/************
 *
 * Name:     osdsmhndl
 *
 * Purpose:  DSM handle
 *
 * Notes:    This structure is purposely left empty. Using this fake struct
 *           definition is better than using a (void *) type because it 
 *           forces the compiler checking to be done even if the structure 
 *           doesn't actually exist.
 *
 ************/
struct osdsmhndl;

/************
 *
 * Name:     ostcb
 *
 * Purpose:  OS task control block type
 *
 * Notes:    
 *
 ************/
struct ostcb;

/************
 *
 * Name:     os_mutex_s
 *
 * Purpose:  OS mutex type
 *
 * Notes:    platform independent
 *
 ************/
struct os_mutex_s;

/************
 *
 * Name:     os_sem_s
 *
 * Purpose:  OS semaphore type
 *
 * Notes:    platform independent
 *
 ************/
struct os_sem_s;

/************
 *
 * Name:     ostimer
 *
 * Purpose:  OS timer type.  For use with os timer functions
 *
 * Notes:    
 *
 ************/
struct ostimer;

/************
 *
 * Name:     os_msg_queue_s
 *
 * Purpose:  Structure for message passing
 *
 * Notes:    THIS STRUCTURE IS NOT PUBLIC.  DO NOT ACCESS FIELDS WITHIN IT
 *
 *           The field mtxp must be a pointer in order to preserved the 
 *           opaque nature of struct os_mutex_s
 *
 ************/
struct os_msg_queue_s
{
  struct os_mutex_s *mtxp;     /* mutex to synchronize access          */
  uint32            *startp;   /* start of the message area            */
  uint32            *endp;     /* end of the message area              */
  uint32            *putp;     /* location to put the next message     */
  uint32            *getp;     /* location to get the next message     */
  char name[OS_MSG_Q_NAME_LEN_MAX + 1];  /* name string                */

  struct {
    uint32 rx_tot;         /* messages received (dequeued) since boot  */
    uint32 tx_tot;         /* messages sent (enqueued) since boot      */
    uint32 q_curr;         /* current number of messages on queue      */
    uint32 q_peak;         /* maximum messages that were on a queue    */
  } stats;
};

/************
 *
 * Name:     oswaiter
 *
 * Purpose:  Thread waiter structure
 *
 * Notes:    Opaque structure
 *
 ************/
struct oswaiter;

/************
 *
 * Name:     os_task_stats_s
 *
 * Purpose:  This structure contains the current and maximum heap usage
 *           of a given client
 *
 * Notes:    
 *
 ************/
struct os_task_stats_s
{
  uint32 current_usage;   /* Current usage of task */
  uint32 max_usage;       /* Maximum usage of task */
};

/* conditional inclusion for platform-specific definitions */
#if defined WOORINET_IMAGE_MODEM
#include "osudefs_modem.h"

#elif defined WOORINET_IMAGE_APPS
#include "osudefs_apps.h"

#elif defined WOORINET_IMAGE_BOOT
#include "osudefs_boot.h"

#elif defined PCLINUX
#include "osudefs_pc.h"

#endif

#include "osuproto.h"

#endif  /* OSUDEFS_H */
