/************
 *
 * $Id$
 *
 * Filename:  osudefs_apps
 *
 * Purpose:   Platform-specific definitions for OS on the application
 *            processor
 *
 * Notes:     These definitions are not intended to be referenced 
 *            explicitly by clients of the API.  These are here ONLY
 *            in order to make public the size of these structures.
 *
 *            Consider these definitions to be private
 *
 * Copyright: (c) 2020 WOORINET. All rights reserved.
 *
 ************/
#ifndef OSUDEFS_APSS_H
#define OSUDEFS_APSS_H

/* Include files */
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <sys/types.h>


#ifndef PTHREAD_MUTEX_INITIALIZER
#error "PTHREAD_MUTEX_INITIALIZER not defined"
#endif

#define OS_MUTEX_INITIALIZER {PTHREAD_MUTEX_INITIALIZER}

/************
 *
 * Name:     os_mutex_s
 *
 * Purpose:  To abstract the underlying OS/Kernel mutex structure
 *
 * Notes:    THIS STRUCTURE IS NOT PUBLIC.  DO NOT ACCESS FIELDS WITHIN IT
 *
 ************/
struct os_mutex_s
{
  pthread_mutex_t     mtx;
  pthread_mutexattr_t mtx_attr;
};

/************
 *
 * Name:     os_sem_s
 *
 * Purpose:  To abstract the underlying OS/Kernel semaphore structure
 *
 * Notes:    THIS STRUCTURE IS NOT PUBLIC.  DO NOT ACCESS FIELDS WITHIN IT
 *
 ************/
struct os_sem_s
{
  sem_t sem;
};

/************
 *
 * Name:     oswaiter
 *
 * Purpose:  Thread waiter structure - contains information necessary
 *           for thread waiting and waking
 *
 * Notes:    THIS STRUCTURE IS NOT PUBLIC.  DO NOT ACCESS FIELDS WITHIN IT
 *
 ************/
struct oswaiter 
{
  pthread_mutex_t mutex;          /* pthread mutex */
  pthread_cond_t  cond_var;       /* pthread condition variable */
  volatile uint32 wait_state;     /* OSWAITSTATE_xxx */
};

/************
 *
 * Name:     ostimer
 *
 * Purpose:  This structure contains all information necessary for dealing
 *           with starting/stopping and expiring a particular timer.
 *
 * Notes:    THIS STRUCTURE IS NOT PUBLIC.  DO NOT ACCESS FIELDS WITHIN IT
 *
 ************/
struct ostimer
{
  timer_t             timer;       /* control block used by underlying OS */
  enum ostimerstate   state;       /* timer state                         */
  uint32              message;     /* message to send when timer expires  */
  uint32              period;      /* period in milliseconds              */
  struct ostcb      * tcbp;        /* TCB of the task owning this timer   */
  struct os_mutex_s   mutex;       /* mutex                               */
};

/************
 *
 * Name:     ostcb
 *
 * Purpose:  This control block is the primary handle for a task.
 *
 * Notes:    THIS STRUCTURE IS NOT PUBLIC.  DO NOT ACCESS FIELDS WITHIN IT
 *
 ************/
struct ostcb
{
  pthread_t             ostaskp;   /* underlying os task pointer                 */
  struct os_msg_queue_s msg_queue; /* Messaging queue structure                  */
  struct os_mutex_s     mutex;     /* Enables exclusive access to this structure */
  struct oswaiter       wait_q;    /* Waiter structure to allow thread to block  */
};

#endif /* OSUDEFS_APSS_H */

