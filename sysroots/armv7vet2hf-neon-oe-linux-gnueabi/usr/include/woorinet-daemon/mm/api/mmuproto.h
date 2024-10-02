/************
 *
 * Filename -  mmuproto.h
 *
 * Purpose -   MM package external function prototypes
 *
 * Copyright: (c) 2020 WOORINET. All rights reserved.
 *
 ************/

extern struct mmpoolcb *mmstats ( void );

extern enum mmrcode mmpoolcreate ( struct mmpoolcb *poolp,
                                   char *namep,
                                   uint32 numblocks, uint32 blocksize );

extern enum mmrcode mmblockget ( struct mmpoolcb *poolp, void **blockpp );

extern enum mmrcode mmblockrel ( void *memp );

extern uint32 mmblocksize(void *memp);

extern void   mm_dyn_pool_init(struct mm_dyn_pool_s *pool,
                               const char           *name,
                               unsigned int          element_size,
                               unsigned int          initial_count,
                               unsigned int          increment_count);

extern void   mm_dyn_pool_free(struct mm_dyn_pool_s *pool,
                               void (*free_fcn)(void *));

extern void   *mm_dyn_pool_get(struct mm_dyn_pool_s *pool,
                               unsigned int          count);

