/*************
 *
 * $Id$
 *
 * Filename:  osuproto - user prototypes for os
 *
 * Copyright: (c) 2020 WOORINET. All rights reserved.
 *
 **************/

/* Prototypes */

extern void     osinit(void);

extern boolean  os_mutex_init(struct os_mutex_s * mtxp);
extern boolean  os_mutex_destroy(struct os_mutex_s * mtxp);
extern boolean  os_mutex_lock(struct os_mutex_s * mtxp);
extern boolean  os_mutex_unlock(struct os_mutex_s * mtxp);

extern boolean  os_sem_init(struct os_sem_s * semp, int shared, unsigned int count);
extern boolean  os_sem_destroy(struct os_sem_s * semp);
extern boolean  os_sem_wait(struct os_sem_s * semp);
extern boolean  os_sem_trywait(struct os_sem_s * semp);
extern boolean  os_sem_post(struct os_sem_s * semp);

/* Messaging */
extern void     osmsgsend(struct ostcb *tcbp, uint32 msg);
extern uint32   osmsgrcv(struct ostcb *tcbp);

extern uint32   os_signal_alloc(struct ostcb *tcbp);
extern uint32_t os_signal_register(struct ostcb *tcbp, uint32_t sigmask, 
                                   void (*handler)(uint32_t sigmask, void *uptr),
                                   void *uptr);

/* Task management */
extern void     ostaskcreate(struct ostcb * tcbp, 
                             void (*)(void * param), void * paramp,
                             size_t stack_size, int priority,
                             char *msg_q_name, int msg_q_depth);
extern void     ostaskstart(struct ostcb *tcbp, boolean dog_enable, void (*)(void));
extern void     ostaskself(struct ostcb * tcbp);
extern boolean  os_task_self_verify(struct ostcb *tcbp);
extern boolean  ostasksuspend(struct ostcb *tcbp, uint32 timeout);
extern void     ostaskresume(struct ostcb *tcbp);
extern boolean  os_task_stop_notif_register(struct ostcb *tcbp, enum os_init_group_e group, void (*fcn)(void));

extern uint32   ostaskactivetag(void);

/* apps only */
extern void     osprocessinit(char *procnamep);

/* Time and timer functions */
extern void     ostimercreate(struct ostimer *timerp, char *name, 
                              struct ostcb *tcbp, uint32 timermsg, 
                              enum ossleepmode sleepmode);
extern void     ostimerstart(struct ostimer *timerp, uint32 duration);
extern void     ostimerrestart(struct ostimer *timerp, uint32 duration);
extern void     ostimerstop(struct ostimer *timerp);
extern boolean  ostimerrunning(struct ostimer *timerp);

extern void     osdelay(unsigned int timeout_ms);

extern uint32   ostimelapsed(uint32 lasttime);
extern uint32   ostime(void);
extern void     osmsec2time(uint32 msec, long *secp, long *usecp, long *nsecp);
extern void     osusec2time(uint32 usec, long *secp, long *nsecp);
extern uint32   ostime2msec(long sec, long usec, long nsec);

extern void     osdogreport(struct ostcb *tcbp);

/* Helper functions to work with DSM items */
/* TBD - these belong in a separate module */
extern uint16 osdsmcopyflattochain(uint8 *, struct osdsmhndl *, uint16);
extern uint8 *osdsmptrget(struct osdsmhndl *oshandlep);
extern void osdsmvalidatesize (enum ospoolnames ospool_id, uint32 size );
extern struct osdsmhndl *osdsmgetbysize (uint16 maxsize);
extern struct osdsmhndl *osdsmgetbyname (enum ospoolnames poolname);
extern void osdsmrel(struct osdsmhndl **osdsmpp);

/* OS NV functions - only on modem */
#if defined WOORINET_IMAGE_MODEM
extern nv_stat_enum_type osnvread(nv_items_enum_type nv_item,
                                  nv_item_type *data_ptr);
extern nv_stat_enum_type osnvwrite(nv_items_enum_type nv_item,
                                   nv_item_type *data_ptr);
#endif

/* Memory functions */
extern void  *os_malloc(size_t size);
extern void  *os_realloc(void * oldblock, size_t newsize);
extern void   os_free(void * ptr);
extern size_t os_mem_available_get(void);
extern size_t os_mem_used_peak_get(void);

/* Misc */
extern void     osrandseed(void);
extern void     os_client_usage_get(int client, struct os_task_stats_s *client_statsp);
extern int      oswakelockinit(void);
extern int      oswakelocktake(char *name);
extern int      oswakelockrelease(char *name);
extern int      ostimeoutwakelocktake(char *name, uint64 timeout);

#if !defined(WOORINET_IMAGE_MODEM)
extern void os_apps_abort(const char *file, uint32 line, char *stringp,
                          uint32 code1, uint32 code2, uint32 code3);
#endif
