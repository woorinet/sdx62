/*************
 *
 * Filename:  qluproto.h
 *
 * Purpose:   global prototypes
 *
 * Copyright: (c) 2020 WOORINET. All rights reserved.
 *
 *************/

extern void qlinitlink (struct qllink *linkp, void *userp);
extern void qladdnext (struct qllink *curlinkp, struct qllink *newlinkp);
extern void qladdprev (struct qllink *curlinkp, struct qllink *newlinkp);
extern void *qlgetnext (struct qllink *linkp);
extern void *qlgetprev (struct qllink *linkp);
extern void *qlremnext (struct qllink *curlinkp);
extern void *qlremprev (struct qllink *curlinkp);
extern void *qlremcur (struct qllink *curlinkp);

