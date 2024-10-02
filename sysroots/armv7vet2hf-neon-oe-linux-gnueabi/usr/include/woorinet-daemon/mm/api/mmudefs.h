/************
 *
 * Filename:  mmudefs.h
 *
 * Purpose:   MM package public header file
 *
 * Copyright: (c) 2020 WOORINET. All rights reserved.
 *
 ************/

#ifndef MMUDEFS_H
#define MMUDEFS_H

#include "osudefs.h"
#include "qludefs.h"

/* maximum pool name length (not incl. null)*/
#define MMMAXNAME 15

/************
 *
 * Name:     mmrcode - memory function return codes
 *
 * Purpose:  This is an enumeration of all memory function return codes.
 *
 * Members:  MMOK        - success
 *           MMNOMEM     - no memory could be allocated to create the pool
 *           MMBADPOOL   - invalid pool control block
 *           MMBADBLOCK  - invalid block
 *
 * Notes:    none
 *
 ************/
enum mmrcode
{
  MMOK = 0,
  MMNOMEM,
  MMBADPOOL,
  MMBADBLOCK
};

/************
 *
 * Name:     mmusedblockheader - used memory block header structure
 *
 * Purpose:  This structure contains information used to associate a particular
 *           allocated block with its pool
 *
 * Members:  memcheck    - 32 bit check value
 *           mempoolp    - pointer to the block's memory pool control block
 *
 * Notes:    none
 *
 ************/
struct mmusedblockheader
{
  uint32 memcheck;
  struct mmpoolcb *mempoolp;
};

/************
 *
 * Name:     mmfreeblockheader - free memory block header structure
 *
 * Purpose:  This structure contains pointers used to put a memory block
 *           on the free block list.
 *
 * Members:  memnextp  - pointer to the next free memory block
 *           memprevp  - pointer to the previous free memory block
 *
 * Notes:    none
 *
 ************/
struct mmfreeblockheader
{
  struct mmfreeblockheader *memnextp;
  struct mmfreeblockheader *memprevp;
};

/************
 *
 * Name:     mmpoolcb - memory pool control block structure
 *
 * Purpose:  This structure contains the free block list header and
 *           basic information and statistic such as the size of the pool
 *           and its maximum usage.
 *
 * Members:  memblocksp      - pointer to memory chunk allocated for the blocks
 *           memcheck        - check bytes to ensure a valid pool control block
 *           memnumblk       - number of blocks in the pool
 *           memblksize      - number of bytes in each block (this value has been
 *                             rounded up to the nearest 32 bit boundary
 *           memnumallocated - number of blocks currently in use
 *           memmaxallocated - maximum number of blocks in use at one time
 *           memsemaphore    - critical section lock
 *           memfreeheader   - free block list header
 *           memname         - name of the pool
 *           memlink         - head of memory pool linked list
 *
 * Notes:  none
 *
 ************/
struct mmpoolcb
{
  uint8 *memblocksp;
  uint32 memcheck;
  uint32 memnumblk;
  uint32 memblksize;
  uint32 memnumallocated;
  uint32 memmaxallocated;
  struct os_mutex_s mem_mutex;
  struct mmfreeblockheader memfreeheader;
  char memname[MMMAXNAME+1];
  struct qllink memlink;
};

/************
 *
 * Name:     mmblockheader - block header union
 *
 * Purpose:  This union allows the free block header structure to be used when the
 *           memory block is added or removed from the free block list and the
 *           used block header structure to be used when the block is being allocated
 *           or released.  This union saves the amount of overhead need to manage a
 *           particular memory block.
 *
 * Members:  memused - used block header structure
 *           memfree - free block header structure
 *
 * Notes:    none
 *
 ************/
union mmblockheader
{
  struct mmusedblockheader memused;
  struct mmfreeblockheader memfree;
};

/************
 *
 * Name:     mm_dyn_pool_s
 *
 * Purpose:  Head structure for dynamically allocated pools
 *
 * Notes:    
 *
 ************/
struct mm_dyn_pool_s 
{
  struct qllink que;                     /* linked list of allocated memory */
  unsigned int  elem_sz;                 /* element (block) size            */
  unsigned int  incr_cnt;                /* number of elements to increment */
  unsigned int  total;                   /* current total allocation        */
  unsigned int  used;                    /* current total used              */
  char          name[MMMAXNAME + 1];     /* pool name                       */
};


#include "mmuproto.h"

#endif

