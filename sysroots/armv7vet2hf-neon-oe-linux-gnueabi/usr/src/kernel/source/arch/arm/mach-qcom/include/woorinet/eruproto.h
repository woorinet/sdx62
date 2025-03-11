/* arch/arm/mach-msm/include/woorinet/eruproto.h
 *
 * Copyright: (c) 2016 WOORINET. All rights reserved.
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 */

#ifndef ERUPROTO_H
#define ERUPROTO_H

void erdump_save_start(void);
void erdump_save_timestamp(uint32_t time_stamp);
void erdump_save_errstr(char *errstrp);
void erdump_save_taskname(char *errstrp);
void erdump_save_frame(void *regs, void *taskp, void *framedatap);
#endif /* ERUPROTO_H */
