/* arch/arm/mach-msm/woorinet/ercommon.c
*
* Copyright: (c) 2016 WOORINET. All rights reserved.
*
*/

#include <linux/string.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/export.h>
#include <linux/mutex.h>
#include <linux/uaccess.h>
#include <linux/time.h>
#include <linux/random.h>
#include <linux/kmsg_dump.h>
#include <asm/stacktrace.h>
#include <linux/soc/qcom/smem.h>
#include <linux/mtd/mtd.h>

#include "eridefs.h"
#include <woorinet/aaglobal.h>
#include <woorinet/aadebug.h>
#include <woorinet/aaudefs.h>
#include <woorinet/bsudefs.h>

#define ERDUMP_PARTITION_NAME "erdump"

static struct er_log_part_metadata_s erdump_meta;
static uint8 page_buffer[4096] = {0,};
static uint8 block_buffer[4096*64] = {0,};
static struct mtd_info *erdump_mtd = NULL;
static int erdump_mtd_index = -1;

static void erdump_kmsg_dump_handler(struct kmsg_dumper *dumper,
  enum kmsg_dump_reason reason);
static void erdump_mtd_notify_add(struct mtd_info *mtd);
static void erdump_mtd_notify_remove(struct mtd_info *mtd);;

static DEFINE_MUTEX(errdump_lock);

static unsigned char *erbase_addr = NULL;
static unsigned char *erdump_kmsg_addr = NULL;
static struct kmsg_dumper erdump_kmsg_dumper = {
  .dump = erdump_kmsg_dump_handler
};
static struct mtd_notifier erdump_mtd_notifier = {
  .add = erdump_mtd_notify_add,
  .remove = erdump_mtd_notify_remove,
};

static void erdump_mtd_notify_add(struct mtd_info *mtd)
{
  size_t retlen = 0;
  int rc = 0;

  if (!strcmp(mtd->name, ERDUMP_PARTITION_NAME))
  {
    erdump_mtd_index = mtd->index;
  }
  if (mtd->index != erdump_mtd_index || erdump_mtd_index < 0)
  {
    return;
  }
  erdump_mtd = mtd;

  memset(page_buffer, 0, sizeof(page_buffer));
  rc = mtd_read(erdump_mtd, 0, sizeof(erdump_meta), &retlen, (u_char *)&page_buffer);
  if (rc != 0)
  {
    WOORINET_PRINT(WOORINET_ERROR, "mtd_read() failed; returned %d", rc);
  }
  else
  {
    memcpy(&erdump_meta, page_buffer, sizeof(erdump_meta));
  }

  /* 1. Read metadata */
  WOORINET_PRINT(WOORINET_HIGH, "magic_beg  = 0x%x",erdump_meta.magic_beg);
  WOORINET_PRINT(WOORINET_HIGH, "magic_end  = 0x%x",erdump_meta.magic_end);
  WOORINET_PRINT(WOORINET_HIGH, "err_count  = %d",erdump_meta.err_count);
  if (erdump_meta.magic_beg != ERROR_START_MARKER)
  {
    erdump_meta.magic_beg = ERROR_START_MARKER;
    erdump_meta.magic_end = ERROR_END_MARKER;
    erdump_meta.cur_offset = 0;
    erdump_meta.err_count = 0;
  }

  rc = kmsg_dump_register(&erdump_kmsg_dumper);
  if (rc != 0)
  {
    WOORINET_PRINT(WOORINET_ERROR, "kmsg_dump_register() failed; returned %d", rc);
  }
  WOORINET_PRINT(WOORINET_HIGH, "Attached to MTD device %d for %s", mtd->index, ERDUMP_PARTITION_NAME);
}

static void erdump_mtd_notify_remove(struct mtd_info *mtd)
{
  if (mtd->index != erdump_mtd_index || erdump_mtd_index < 0)
  {
    return;
  }
  if (kmsg_dump_unregister(&erdump_kmsg_dumper) < 0)
  {
    WOORINET_PRINT(WOORINET_ERROR, "Could not unregister kmsg_dumper");
  }

  erdump_mtd = NULL;
  erdump_mtd_index = -1;
}

static struct error_data *erdump_addr_get(
  uint8 err_type)
{
  unsigned erdump_size = ERDUMP_SMEM_ERR_SIZE;
  unsigned char *erdump_addr = NULL;

  if (erbase_addr == NULL)
  {
    erbase_addr = qcom_smem_get(QCOM_SMEM_HOST_ANY, SMEM_ID_VENDOR1, &erdump_size);
    if (IS_ERR_OR_NULL(erbase_addr))
    {
      WOORINET_PRINTF(WOORINET_ERROR,"%s: smem_get_entry failed", __func__);
      erbase_addr = NULL;
      erdump_addr = NULL;
    }
    else
    {
      erdump_addr = (unsigned char *)erbase_addr + ((err_type == ER_APPS)?ERDUMP_SMEM_ERR_DUMP_SIZE:0);
    }
  }
  else
  {
    erdump_addr = (unsigned char *)erbase_addr + ((err_type == ER_APPS)?ERDUMP_SMEM_ERR_DUMP_SIZE:0);
  }

  return (struct error_data *)erdump_addr;
}

static char *erdump_kmsg_addr_get(void)
{
  return (char *)erdump_kmsg_addr;
}


void erdump_save_start(void)
{
  struct error_data *errdatap = erdump_addr_get(ER_APPS);
  char *carrier  = NULL;

  if (!errdatap)
  {
    return;
  }

  if (mutex_trylock(&errdump_lock))
  {
    /* note that the errdatap can only be accessible after
     * paging_init at kernel start. If there is a panic
     * before paging_init, the following line will likely
     * cause another panic
     */
    memset((void *)errdatap, 0x00, sizeof(struct error_data));

    errdatap->start_marker = ERROR_START_MARKER;
    errdatap->error_source = ERROR_FATAL_ERROR;
    errdatap->end_marker = ERROR_END_MARKER;

    /* also write ID and proc type here */
    get_random_bytes(&errdatap->error_id, sizeof(errdatap->error_id));
    errdatap->proc_type = ERDUMP_PROC_TYPE_APPS;

    bs_carrier_pointer_get(&carrier);
    strncpy(errdatap->version, aa_build_tag_get(carrier), MAX_VER_LEN);
    errdatap->version[MAX_VER_LEN - 1] = 0x00;

    bs_woorinet_magic_set();
    mutex_unlock(&errdump_lock);
  }
  /* else, reentry, don't save */
}
EXPORT_SYMBOL(erdump_save_start);

void erdump_save_timestamp(uint32_t time_stamp)
{
  struct error_data *errdatap = erdump_addr_get(ER_APPS);

  if (!errdatap)
  {
    return;
  }

  if (mutex_trylock(&errdump_lock))
  {
    if ((errdatap->time_stamp == 0) &&
      (errdatap->start_marker == ERROR_START_MARKER))
    {
      errdatap->time_stamp = time_stamp;
    }
    /* else time_stamp has something, should not happen since
     * it should be cleared at erdump_save_start
     */

    mutex_unlock(&errdump_lock);
  }
  /* else, reentry, don't save */
}
EXPORT_SYMBOL(erdump_save_timestamp);

void erdump_save_errstr(char *errstrp)
{
  struct error_data *errdatap = erdump_addr_get(ER_APPS);
  char *carrier = NULL;
  char *build_tag = NULL;

  if (!errdatap)
  {
    return;
  }

  if (mutex_trylock(&errdump_lock))
  {

    if (errdatap->error_string[0] == 0x00 &&
       errdatap->start_marker == ERROR_START_MARKER)
    {
      strncpy(errdatap->error_string, errstrp, ERROR_STRING_LEN);
      errdatap->error_string[ERROR_STRING_LEN - 1] = 0x00;
    }
    /* else error_string has something, should not happen since
     * it should be cleared at erdump_save_start
     */
    mutex_unlock(&errdump_lock);
  }
  /* else, reentry, don't save */
}
EXPORT_SYMBOL(erdump_save_errstr);

void erdump_save_taskname(char *errstrp)
{
  struct error_data *errdatap = erdump_addr_get(ER_APPS);

  if (!errdatap)
  {
    return;
  }

  if (mutex_trylock(&errdump_lock))
  {

    if (errdatap->task_name[0] == 0x00 &&
       errdatap->start_marker == ERROR_START_MARKER)
    {
      strncpy(errdatap->task_name, errstrp, MAX_TASK_NAME);
      errdatap->task_name[MAX_TASK_NAME - 1] = 0x00;
    }
    /* else error_string has something, should not happen since
     * it should be cleared at erdump_save_start
     */

    mutex_unlock(&errdump_lock);
  }
  /* else, reentry, don't save */
}
EXPORT_SYMBOL(erdump_save_taskname);

void erdump_save_frame(void * regs, void *taskp, void *framedatap)
{
  struct error_data *errdatap = erdump_addr_get(ER_APPS);
  unsigned long *stackp, stack_index;
  struct stackframe *framep = (struct stackframe *)framedatap;
  struct pt_regs * regsp = (struct pt_regs *)regs;

  if (!errdatap)
  {
    return;
  }

  if (mutex_trylock(&errdump_lock))
  {

    if ((errdatap->program_counter == 0) &&
      (errdatap->start_marker == ERROR_START_MARKER))
    {
      if (regsp)
      {
        errdatap->registers[0] = regsp->ARM_r0;
        errdatap->registers[1] = regsp->ARM_r1;
        errdatap->registers[2] = regsp->ARM_r2;
        errdatap->registers[3] = regsp->ARM_r3;
        errdatap->registers[4] = regsp->ARM_r4;
        errdatap->registers[5] = regsp->ARM_r5;
        errdatap->registers[6] = regsp->ARM_r6;
        errdatap->registers[7] = regsp->ARM_r7;
        errdatap->registers[8] = regsp->ARM_r8;
        errdatap->registers[9] = regsp->ARM_r9;
        errdatap->registers[10] = regsp->ARM_r10;
        errdatap->registers[12] = regsp->ARM_ip;
        errdatap->cpsr = regsp->ARM_cpsr;
      }
      errdatap->program_counter = framep->pc;
      errdatap->registers[11] = framep->fp;
      errdatap->registers[13] = framep->sp;
      errdatap->registers[14] = framep->lr;

      /* taskp != 0: kernel space stack processing
       */
      if (taskp && framep->sp)
      {
        /* stack data */
        stackp = (unsigned long *)framep->sp;
        /* match mpss side pattern */
        for (stack_index = 0; stack_index < MAX_STACK_DATA; stack_index++)
        {
          errdatap->stack_data[MAX_STACK_DATA - stack_index - 1] =  stackp[stack_index];
        }
      }
      /* taskp == 0: user space stack processing: */
      else if (taskp == 0 && access_ok((char __user *)framep->sp, MAX_STACK_DATA * sizeof(long)))
      {
        /* match mpss side pattern */
        for (stack_index = 0; stack_index < MAX_STACK_DATA; stack_index++)
        {
          get_user(errdatap->stack_data[MAX_STACK_DATA - stack_index - 1],
                   (unsigned long __user *)(framep->sp + (sizeof(long) * stack_index)));
        }
      }
      sprintf(errdatap->aux_string, "%pS", (void *)framep->pc);
    }

    mutex_unlock(&errdump_lock);
  }
  /* else, reentry, don't save */
}
EXPORT_SYMBOL(erdump_save_frame);

/************
 *
 * Name:     erdump_to_partition
 *
 * Purpose:  erdump data to partition.
 *
 * Parms:    none
 *
 * Return:   TRUE if success
 *           FALSE otherwise
 *
 ************/
static boolean erdump_to_partition(
  void)
{
  uint32_t erdump_sz = 0;
  struct error_data * errdata_modem_p = NULL;
  struct error_data * errdata_apps_p = NULL;
  char * errdata_kmsg_p = NULL;
  unsigned page_sz = 0, block_sz = 0, offset = 0;
  struct erase_info eraseinfo;
  int retlen = 0, rc;

  errdata_modem_p = (struct error_data *)erdump_addr_get(ER_MODEM);
  errdata_apps_p = (struct error_data *)erdump_addr_get(ER_APPS);
  errdata_kmsg_p = (char *)erdump_kmsg_addr_get();

  if ((errdata_modem_p->start_marker == ERROR_START_MARKER) ||
    (errdata_apps_p->start_marker == ERROR_START_MARKER))
  {
    page_sz = erdump_mtd->writesize;
    block_sz = erdump_mtd->erasesize;

    erdump_meta.cur_offset = erdump_meta.err_count%64;
    erdump_meta.err_count++;
    memset(page_buffer, 0, sizeof(page_buffer));
    memcpy(page_buffer, &erdump_meta, sizeof(erdump_meta));

    WOORINET_PRINT(WOORINET_HIGH, "MPSS: %s",errdata_modem_p->error_string);
    WOORINET_PRINT(WOORINET_HIGH, "APPS: %s",errdata_apps_p->error_string);
    WOORINET_PRINT(WOORINET_HIGH, "APPS Aux: %s",errdata_apps_p->aux_string);

    /* 2. Write error_data */
    if (erdump_meta.cur_offset%64 == 0)
    {
      eraseinfo.addr = (LOG_PART_ERDATA_BLOCK_OFFSET*block_sz);
      eraseinfo.len = erdump_mtd->erasesize;
      rc = mtd_erase(erdump_mtd, &eraseinfo);
      if (rc != 0)
      {
        WOORINET_PRINT(WOORINET_ERROR, "Can't erase error_data");
      }
    }
    offset = (LOG_PART_ERDATA_BLOCK_OFFSET*block_sz) + (erdump_meta.cur_offset*page_sz);
    rc = mtd_write(erdump_mtd, offset, page_sz, &retlen, (const u_char *)errdata_modem_p);
    if (rc != 0)
    {
      WOORINET_PRINT(WOORINET_ERROR, "Can't write error_data to partition %s, rc = %d", erdump_mtd->name, rc);
      return FALSE;
    }

    /* 3. Write KMSG to a block */
    offset = (LOG_PART_KMSG_BLOCK_OFFSET*block_sz) + ((erdump_meta.cur_offset%16)*block_sz);
    eraseinfo.addr = offset;
    eraseinfo.len = erdump_mtd->erasesize;
    rc = mtd_erase(erdump_mtd, &eraseinfo);
    if (rc != 0)
    {
      WOORINET_PRINT(WOORINET_ERROR, "Can't erase KMSG block offset %d", offset);
    }
    rc = mtd_write(erdump_mtd, offset, block_sz, &retlen, errdata_kmsg_p);
    if (rc != 0)
    {
      WOORINET_PRINT(WOORINET_ERROR, "Can't write kmsg to partition %s, rc = %d", erdump_mtd->name, rc);
      return FALSE;
    }

    /* 4. Write metadata */
    offset = LOG_PART_META_BLOCK_OFFSET*block_sz;
    eraseinfo.addr = offset;
    eraseinfo.len = erdump_mtd->erasesize;
    rc = mtd_erase(erdump_mtd, &eraseinfo);
    if (rc != 0)
    {
      WOORINET_PRINT(WOORINET_ERROR, "Can't erase metadata block offset %d", offset);
    }
    rc = mtd_write(erdump_mtd, offset, page_sz, &retlen, page_buffer);
    if (rc != 0)
    {
      WOORINET_PRINT(WOORINET_ERROR, "Can't write meta to partition %s, rc = %d", erdump_mtd->name, rc);
      return FALSE;
    }
    /* Update SMEM start and end marker not to flash the same log */
    errdata_modem_p->start_marker = ERROR_START_MARKER_LATEST;
    errdata_modem_p->end_marker = ERROR_END_MARKER_LATEST;
    errdata_apps_p->start_marker = ERROR_START_MARKER_LATEST;
    errdata_apps_p->end_marker = ERROR_END_MARKER_LATEST;
  }

  return TRUE;
}


static void erdump_kmsg_dump_handler(struct kmsg_dumper *dumper,
  enum kmsg_dump_reason reason)
{
  static DEFINE_SPINLOCK(erdump_kmsg_lock);
  unsigned long flags;
  char *kmsg_buf = erdump_kmsg_addr_get();
  size_t text_len;

  if (!spin_trylock_irqsave(&erdump_kmsg_lock, flags))
    return;

  if (reason != KMSG_DUMP_OOPS)
  {
    kmsg_dump_rewind(dumper);
    kmsg_dump_get_buffer(dumper, true,
       kmsg_buf, ERDUMP_SMEM_KMSG_DUMP_SIZE, &text_len);
    erdump_to_partition();
  }

  spin_unlock_irqrestore(&erdump_kmsg_lock, flags);
}

static int __init erdump_late_init(void)
{
  int rc = 0;

  register_mtd_user(&erdump_mtd_notifier);

  erdump_kmsg_addr = block_buffer;
  if (!erdump_kmsg_addr)
  {
    WOORINET_PRINT(WOORINET_ERROR, "kmsg address is NULL");
    return -ENOMEM;
  }

  return 0;
}
late_initcall(erdump_late_init);
