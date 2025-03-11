/************
 *
 * Filename:  eridefs
 *
 * Purpose:   internal definitions for er
 *
 * Copyright: (c) 2016 WOORINET. All rights reserved.
 *
 ************/

#include "erudefs.h"

/* Local constants and enumerated types */
/* below ER related defines and structures need to keep in sync with:
 * modem_proc/woorinet/er/src/eridefs.h
 */
#define ERROR_START_MARKER  0x45524552  /* "ER" in ASCII */
#define ERROR_END_MARKER    0x45524552  /* "ER" in ASCII */
#define ERROR_START_MARKER_LATEST 0x45524c41  /* "ERLA" in ASCII */
#define ERROR_END_MARKER_LATEST   0x45524c41  /* "ERLA" in ASCII */
#define ERROR_USER          0x0101
#define ERROR_EXCEPTION     0x0202
#define ERROR_FATAL_ERROR   0x0404
#define ERROR_LOCK_MARKER   0x0303
#define ERROR_START_GLOBALTIME_MARKER   0x47744774
#define ERROR_END_GLOBALTIME_MARKER     0x47744774

#define MAX_VER_LEN         24
#define DATE_TIME_LEN       16

#define ERROR_STRING_LEN    256
#define ERROR_FILE_LEN      64
#define ERROR_AUX_LEN       64
#define MAX_STACK_DATA      32
#define MAX_TASK_NAME       16
#define MAX_ARM_REGISTERS   15
#define MAX_EXT_REGISTERS   17
#define QDSP6_REG_SP        (29 - MAX_ARM_REGISTERS)  /* R29 = SP */
#define QDSP6_REG_FP        (30 - MAX_ARM_REGISTERS)  /* R30 = FP */
#define QDSP6_REG_LR        (31 - MAX_ARM_REGISTERS)  /* R31 = LR */

#define MAX_FORMAT_PARAM    4

#define LOG_PART_META_BLOCK_OFFSET    0
#define LOG_PART_META_BLOCK_SIZE      1
#define LOG_PART_ERDATA_BLOCK_OFFSET  (LOG_PART_META_BLOCK_OFFSET+LOG_PART_META_BLOCK_SIZE)
#define LOG_PART_ERDATA_BLOCK_SIZE    1
#define LOG_PART_KMSG_BLOCK_OFFSET    (LOG_PART_ERDATA_BLOCK_OFFSET+LOG_PART_ERDATA_BLOCK_SIZE)
#define LOG_PART_KMSG_BLOCK_SIZE      16

#define DUMP_SET_FLAG       0x0001

#define ERDUMP_SAVE_CMD_START             0xFF00
#define ERDUMP_SAVE_CMD_ERRSTR            0xFF01
#define ERDUMP_SAVE_CMD_ERRDATA           0xFF02
#define ERDUMP_SAVE_CMD_FMTSTR            0xFF03
#define ERDUMP_SAVE_CMD_FMTDATA           0xFF04
#define ERDUMP_SAVE_CMD_REGISTERS         0xFF05
#define ERDUMP_SAVE_CMD_FRAME             0xFF06
#define ERDUMP_SAVE_CMD_END               0xFF0F
#define ERDUMP_PROC_TYPE_APPS             0x41505053 /* "APPS" in ascii hex */

#define ERDUMP_SMEM_ERR_DUMP_SIZE         0x7F8
#define ERDUMP_SMEM_KMSG_DUMP_SIZE        0x20000
#define ERDUMP_SMEM_ERR_SIZE              0x01000   /* (0x07F8 + 0x07F8 + 0x0010) */

/***********
 *
 * Name:    er_processor_e
 *
 * Purpose: Enumerates the processor type
 *
 * Notes:   none
 *
 ***********/
enum er_processor_e
{
  ER_APPS,                      /* APPS  processor */
  ER_MODEM,                     /* MODEM processor */
  ER_RPM,                       /* RPM   processor */
  ER_PROCESSOR_MAX              /* Internal Use    */
};

/* Structures */

/*************
 *
 * Name:     error_data - ER Data structure
 *
 * Purpose:  Contains ER data dumps
 *
 * Members:  see below
 *
 * Notes:   make sure uint32 fields is 4-byte aligned
 *
 **************/
struct __attribute__((packed)) error_data
{
  uint32_t start_marker;                   /* Magic number marking the satart */
  uint32_t program_counter;                /* PC at the time of crash */
  uint32_t cpsr;                           /* Program Status Register */
  uint32_t registers[MAX_ARM_REGISTERS];   /* registers */
  uint32_t ext_registers[MAX_EXT_REGISTERS]; /* extra register set for QDSP6 (R15-R31) */
  uint32_t stack_data[MAX_STACK_DATA];     /* Stack dump at the time of crash */
  uint32_t error_source;                   /* user or exception vector */
  uint32_t flags;                          /* bit-mapped flag */
  uint32_t error_id;                       /* unique error ID */
  uint32_t proc_type;                      /* which processor caused the crash */
  uint32_t time_stamp;                     /* up time in seconds since power up */
  uint32_t line;                           /* line number of the crash */
  char     file_name[ERROR_FILE_LEN];      /* file name of the crash */
  char     error_string[ERROR_STRING_LEN]; /* Null-terminated crash message string */
  uint32_t param[MAX_FORMAT_PARAM];        /* params for error_string */
  char     aux_string[ERROR_AUX_LEN];      /* 2nd error string */
  char     task_name[MAX_TASK_NAME];       /* task name or ID that caused the crash */
  char     version[MAX_VER_LEN];           /* release at the time of crash */
  char     date_time[DATE_TIME_LEN];       /* date/time at the time of crash */
  uint32_t reserved;                       /* reserved for future use */
  uint32_t end_marker;                     /* end marker */
};


/************
 *
 * Name:     er_log_part_metadata_s
 *
 * Purpose:  control structure
 *
 ************/
PACKED struct PACKED_POST er_log_part_metadata_s
{
  uint32_t  magic_beg;      /* magic number                       */
  uint32_t  version;        /* version of the structure           */
  uint32_t  cur_offset;     /* current offset of partition        */
  uint32_t  err_count;      /* number of errdump in log partition */
  uint32_t  magic_end;      /* magic number                       */
};


#include "eriproto.h"
