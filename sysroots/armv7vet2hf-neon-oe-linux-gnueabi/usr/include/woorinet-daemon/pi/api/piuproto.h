/*************
 *
 * $Id$
 *
 * Filename:  piuproto.h
 *
 * Purpose:   external function prototypes
 *
 * Copyright: (c) 2020 WOORINET. All rights reserved.
 *
 *************/

extern void piput16(uint16 field, uint8 **packetpp);
extern void piput32(uint32 field, uint8 **packetpp);
extern void piput64(uint64 field, uint8 **packetpp);
extern void piputmulti(uint8 *fieldsp, uint8 **packetpp, uint16 numfields);
extern uint16 piget16(uint8 **packetpp);
extern uint32 piget32(uint8 **packetpp);
extern uint64 piget64(uint8 **packetpp);
extern void pigetmulti(uint8 **packetpp, uint8 *bufferp, uint16 numfields);
extern uint16 piget16_noinc(uint8 **packetpp);
extern uint32 piget32_noinc(uint8 **packetpp);
extern void piput16_host(uint16 field, uint8 **packetpp);
extern void piput32_host(uint32 field, uint8 ** packetpp);
extern void piput16_noinc(uint16 field, uint8 **packetpp, uint32 inc);
extern uint16 piget16_host(uint8 **packetpp);
extern uint32 piget32_host(uint8 **packetpp);
extern uint32 piget32_host_noinc(uint8 **packetpp);

