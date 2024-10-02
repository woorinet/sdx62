/************
 *
 * Filename:  swocuproto.h
 *
 * Purpose:   external prototypes for SWoC
 *
 * Copyright: (c) 2020 WOORINET. All rights reserved.
 *
 ************/

extern void sminit(sm_t       *sm,
                   smaction_t *sat,
                   uint8_t    *stt,
                   int        evnum,
                   int        stnum,
                   int        state,
                   void       *udata);

extern void smrun(sm_t *sm, int ev);

