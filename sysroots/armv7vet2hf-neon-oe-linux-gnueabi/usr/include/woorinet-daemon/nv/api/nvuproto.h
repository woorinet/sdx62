/************
 *
 * Filename:  nvuproto.h
 *
 * Purpose:   External function prototypes
 *
 * Copyright: (c) 2016 WOORINET. All rights reserved.
 *
 ************/

/* Constants */

/* Callbacks */

/* Prototypes */

/* NV and WOORINET NV general access */
extern void nvinit(void);
extern boolean nvready(void);
extern boolean nvread(uint32 tag, uint16 *length, uint8 *datap);
extern boolean nvwrite(uint32 tag, uint16 length, const uint8 *datap);
extern boolean nvdelete(uint32 tag, uint16 arrayindex);

