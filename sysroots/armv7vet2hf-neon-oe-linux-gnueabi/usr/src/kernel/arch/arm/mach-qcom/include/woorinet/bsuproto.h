/************
 *
 * Filename:  bsuproto.h
 *
 * Purpose:   user prototypes for bs
 *
 * Copyright: (c) 2016 WOORINET. All rights reserved.
 *
 ************/

#ifndef BSUPROTO_H
#define BSUPROTO_H

extern wsmem_bl_boot * bs_get_wsmem_addr(
  void);
extern boolean bs_feature_get(enum bsfeature feature);
extern boolean bs_firmware_version_set(void);
extern void bs_woorinet_magic_clr(void);
extern void bs_woorinet_magic_set(void);
extern enum usb_mode_type wnet_get_usb_mode(void);
extern int wnet_virtual_vbus_power_vreg(bool on);
extern boolean bs_customer_get(char *strp);
extern boolean bs_usbcomp_get(
  uint32 *usb_comp);
extern boolean bs_carrier_pointer_get(
  char **strpp);

#endif /* BSUPROTO_H */
