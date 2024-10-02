/*
 *  Package Name:   MM - Memory Management
 *
 *  Purpose:        This package provides memory management functions
 *
 *  Notes:          None.
 *
 *  Copyright: (c) 2020 WOORINET. All rights reserved.
 *
 */

 ***********
MM Overview
 ***********

The MM package handles fixed size memory pool management.
It supplies the user with the following 3 functions:

/* for creating the fixed size memory pool */
extern enum mmrcode mmpoolcreate(
    struct mmpoolcb *poolp,
    char *namep,
    uint32 numblocks,
    uint32 blocksize );

/* for allocating a fixed size memory block for the pool */
extern enum mmrcode mmblockget(
    struct mmpoolcb *poolp,
    void **blockpp );

/* for releasing a memory block */
extern enum mmrcode mmblockrel(
    void *memp );
