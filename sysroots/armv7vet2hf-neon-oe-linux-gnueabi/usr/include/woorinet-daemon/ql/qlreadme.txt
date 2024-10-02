/*************
 *
 * Package Name: QL - Queue Link Manager
 *
 * Purpose:   To provide queuing functionality by use of a circular
 *            doubly-linked list. 
 *
 *            The caller of the queue functions is responsible for the
 *            following things: 
 *
 *            1. all memory allocation/de-allocation of queue blocks
 *               and links
 * 
 *            2. all concurrent control (locks)
 *
 *            3. keeping a pointer to the queue (headerp etc)
 *
 *            It is meaningless to add or remove the initial or final
 *            queue link in the queue. 
 *
 * Notes:     None
 *
 * Copyright: (c) 2020 WOORINET. All rights reserved.
 *
 **************/
 
