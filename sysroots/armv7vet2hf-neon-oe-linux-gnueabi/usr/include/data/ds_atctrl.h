/**
  @file
  ds_atctrl.h

  @brief
  This file provides an API to interact with underlying at-fwd daemon
  plane.

*/

/*===========================================================================

  Copyright (c) 2020 Qualcomm Technologies, Inc.
  All Rights Reserved.
  Confidential and Proprietary - Qualcomm Technologies, Inc.

===========================================================================*/

#ifdef __cplusplus
extern "C" {
#endif

#ifndef DS_ATCTRL_H
#define DS_ATCTRL_H

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/time.h>
#include <time.h>
#include <inttypes.h>
#include <sys/select.h>
#include <qmi_atcop_srvc.h>

#include "ds_util.h"

#define DS_AT_TRUE                                                    1
#define DS_AT_FALSE                                                   0
#define DS_AT_EINITED                                               101 /* <indicated that library is already inited> */
#define DS_AT_SUCCESS                                               (0)
#define DS_AT_FAILURE                                              (-1)
#define DS_AT_EVT_PARAM_NONE                                   (0x0000)
#define DS_AT_EVT_PARAM_USER_CMD                               (0x0001)
#define DS_AT_EVT_PARAM_CMD_DATA                               (0x0002)

/*---------------------------------------------------------------------
   Constant representing maximum timeout to be used for waiting on a
   poll event. Timeout value is in milliseconds.
----------------------------------------------------------------------*/
#define DS_AT_UNIX_MESSAGE_RECV_TIMEOUT                            5000
#define DS_AT_USER_CMD_STATUS_FAILED                                 -1
#define DS_AT_USER_CMD_STATUS_SUCCESS                                 1
#define DS_AT_MAX_REGISTERED_CMD                                     20
#define DS_AT_NUM_TOKEN_MAX_V01                                     100
#define DS_AT_CMD_NAME_MAX_LEN                                       20

#define DS_AT_USER_CMD_REGISTER                                       1
#define DS_AT_USER_CMD_RESP                                           2
#define DS_AT_USER_CMD_DEREGISTER                                     3
#define DS_AT_USER_CMD_URC_RESP                                       4

#define DS_AT_RESP_MAX_LEN                                          200
#define DS_AT_URC_MAX_LEN                                            64
#define DS_AT_RTATYPE_BASE                                     (0x1000)
#define DS_AT_RTATYPE_EVENT                      (DS_AT_RTATYPE_BASE+0) /* Event ID           */
#define DS_AT_RTATYPE_USER_CMD                   (DS_AT_RTATYPE_BASE+1) /* User Command       */
#define DS_AT_RTATYPE_CMD_DATA                   (DS_AT_RTATYPE_BASE+2) /* Command data for
                                                                           user command*/
#define DS_AT_RTASIZE_EVENT        RTA_SPACE(sizeof(ds_at_nl_events_t))
#define DS_AT_RTASIZE_USER_CMD          RTA_SPACE(sizeof(unsigned int))
#define DS_AT_RTASIZE_CMD_DATA RTA_SPACE(sizeof(ds_at_user_cmd_data_t))

#define ds_at_malloc(size)                                 malloc(size)
#define ds_at_free(ptr)              if( ptr ){ free(ptr); ptr = NULL;}

#define DS_AT_ENTRY  ds_log_low("[ds_at_client][%d] %s() : entry",getpid(),__func__);
#define DS_AT_EXIT    ds_log_low("[ds_at_client][%d] %s() : exit",getpid(),__func__);

#define DS_AT_ASSERT(a)                                    ds_assert(a)

#define DS_AT_LOCK_MUTEX(mutex) \
  { \
    pthread_mutex_lock(mutex); \
    ds_log_high("mutex [%p] locked", mutex); \
  }

#define DS_AT_UNLOCK_MUTEX(mutex) \
  { \
    pthread_mutex_unlock(mutex); \
    ds_log_high("mutex [%p] unlocked", mutex); \
  }

#define DS_AT_GLOBAL_LOCK \
  DS_AT_LOCK_MUTEX(&ds_at_global_mutex)

#define DS_AT_GLOBAL_UNLOCK \
  DS_AT_UNLOCK_MUTEX(&ds_at_global_mutex)

#define DS_AT_ABORT(...)                                       \
        ds_log_err("abort");                                   \
        exit(-1);

typedef enum
{
  DS_AT_CMD_ABORTABLE      =  1,
  DS_AT_CMD_NOT_ABORTABLE  =  0
}ds_at_abort_type;

/*-----------------------------------------------------------------------
   Type representing enumeration of NetLink event indication messages
------------------------------------------------------------------------*/
typedef enum ds_at_nl_events_e {
  DS_AT_INVALID_EV,         /* Internal value                           */
  DS_AT_UP_EV,              /* Atfwd service UP state                   */
  DS_AT_DOWN_EV,            /* Atfwd service DOWN state                 */
  DS_AT_READY_REQ,          /* Atfwd daemon readiness query             */
  DS_AT_READY_RESP,         /* Atfwd daemon readiness response          */
  DS_AT_USER_CMD,           /* Atfwd daemon user generated command      */
  DS_AT_USER_RESP,          /* Atfwd daemon user generated response     */
  DS_AT_MAX_EV              /* Internal value                           */
} ds_at_nl_events_t;

/*======================================================================
*Definitions associated with ds_at_cmd_resp
========================================================================*/

/* enum for cmd ind resp result type*/
typedef enum
{
  DS_AT_RESULT_ERROR = 0, /* error or CME error, Response Buffer should
                             contain Error details                      */
  DS_AT_RESULT_OK    = 1, /* OK result Code to terminal, Response Buffer
                             SHOULD NOT contain OK.                     */
  DS_AT_RESULT_OTHER = 2  /* For all other result codes.                */
}ds_at_resp_result_type;

/* enum for cmd ind resp type */
typedef enum
{
  DS_AT_RESP_START = 0,
  DS_AT_RESP_END,
  DS_AT_RESP_INTERMEDIATE,
  DS_AT_RESP_COMPLETE,     /* Response Buffer contains Complete Response
                              and Should Not contain 'OK'. If only OK
                              needs to be sent set 'DS_AT_RESP_COMPLETE'
                              and Response as NULL.                     */
  DS_AT_RESP_TYPE_MAX = DS_AT_RESP_COMPLETE
}ds_at_resp_response_type;

/* handle type to communicate with atfwd deamon*/
typedef unsigned int                         atfwd_daemon_client_hdl_t;

/* atfwd daemon client handle */
atfwd_daemon_client_hdl_t                            atfwd_daemon_hndl;

typedef unsigned long                                ds_at_opcode_type;

/* at command info (req/ind) structure*/
typedef struct
{
  ds_at_abort_type        abort_flag;
  unsigned char           at_cmd_name[DS_AT_CMD_NAME_MAX_LEN + 1];
  ds_at_opcode_type       op_code;
  uint32_t                token_len;
  uint8_t                 token[DS_AT_NUM_TOKEN_MAX_V01];
}ds_at_cmd_info_type;

/* urc resp structure */
typedef struct {

  uint8_t  urc_type;
  uint32_t at_urc_len;
  uint8_t  at_urc[DS_AT_URC_MAX_LEN];
}ds_at_urc_resp_type;

/* cmd ind resp structure */
typedef struct {

  ds_at_resp_result_type          result;
  ds_at_resp_response_type        response_type;
  uint32_t                        at_resp_len;
  uint8_t                         at_resp[DS_AT_RESP_MAX_LEN];
}ds_at_cmd_resp_type;

/* at ind/urc response info structure */
typedef struct
{
  union
  {
    ds_at_cmd_resp_type ind_resp;
    ds_at_urc_resp_type urc_resp;
  };
}ds_at_resp_info_type;

/* at comand req/ind info structure*/
typedef struct
{
  ds_at_cmd_info_type     req_cmd_info[DS_AT_MAX_REGISTERED_CMD];
  ds_at_resp_info_type    resp_info;
}ds_at_cmd_req_type_t;

/* format of cmd handler for client */
typedef void (*ds_at_cmd_handler)
(
  ds_at_cmd_req_type_t  cmd_info,
  void                 *user_data
);

/* struct to store successfully registered cmds*/
typedef struct
{
  ds_at_cmd_info_type cmd_info;
  ds_at_cmd_handler   cmd_hndlr;
}ds_at_registered_cmd_list_t;

/* netlink msg txn info structure */
typedef struct ds_at_usr_cmd_txn_s
{
  unsigned int   pid;
  unsigned int   txn_id;
  int            txn_status;
}ds_at_usr_cmd_txn_t;

/* usr cmd data structure for netlink msg */
typedef struct ds_at_user_cmd_data_s {
  ds_at_usr_cmd_txn_t   txn;
  unsigned int          cmd_id;
  int                   num_of_cmds;
  ds_at_cmd_req_type_t  cmd_info;
}ds_at_user_cmd_data_t;

/* netlink event info structure */
typedef struct ds_at_nl_event_info_s {
  unsigned int               param_mask;
  ds_at_nl_events_t          event;
  unsigned int               user_cmd;
  ds_at_user_cmd_data_t      cmd_data;
} ds_at_nl_event_info_t;

/* netlink msg type */
typedef struct ds_at_nl_msg_s {
  unsigned int               type;
  unsigned int               param_mask;
  ds_at_nl_event_info_t      event_info;
} ds_at_nl_msg_t;

/*---------------------------------------------------------------------------
  Type representing callback function registered by client subscribing
  for asynchronous event indications.
---------------------------------------------------------------------------*/
typedef void (*ds_at_event_ind_f)
(
  ds_at_nl_events_t       event,
  ds_at_nl_event_info_t  *info,
  void                   *data
);

/* client cb fn format for UP/DOWN event */
typedef void (*ds_at_ev_cb)
(
  void                *user_data,    /**< Application-provided user data. */
  ds_at_nl_events_t    evt           /**< Event identifier. */
);

/* structure to store clinet cb data */
typedef struct ds_at_init_cb_info_s
{
  ds_at_ev_cb   user_cb_fn;
  void         *cb_data;
} ds_at_init_cb_info_t;

ds_at_init_cb_info_t ds_at_init_cb_info;

/*===========================================================================
                            GLOBAL FUNCTION DECLARATIONS
===========================================================================*/

/*===========================================================================
  FUNCTION:  ds_at_init
===========================================================================*/
/*!
    @brief
    used to initialize ds_atctrl module.

    @return
    DS_AT_SUCCESS
    DS_AT_FAILURE
*/
/*=========================================================================*/
extern int
ds_at_init
(
  ds_at_ev_cb   cb_fn,
  void         *cb_data
);

/*===========================================================================
  FUNCTION  ds_at_deinit
===========================================================================*/
/*!
@brief
  Function to deinit DS AT client.

@return
  int - DS_AT_SUCCESS

*/
/*=========================================================================*/
extern int
ds_at_deinit
(
  void
);

/*===========================================================================
  FUNCTION  ds_at_register_cmds
===========================================================================*/
/*!
@brief
  Function to register AT commands.

@return
  int - DS_AT_SUCCESS on successful operation, DS_AT_FAILURE otherwise

@note

  - Dependencies
    - None

  - Side Effects
    - None
*/
/*=========================================================================*/
extern int
ds_at_register_cmds
(
  int                   num_of_cmds,
  ds_at_cmd_info_type  *at_cmd_list,
  ds_at_cmd_handler     cmd_hndlr,
  void                 *user_data
);

/*===========================================================================
  FUNCTION:  ds_at_deregister_cmds
===========================================================================*/
/*!
    @brief
    used to de-register AT commands.

    @return
    DS_AT_ERROR
    DS_AT_SUCCESS
*/
/*=========================================================================*/
extern int
ds_at_deregister_cmds
(
  int                  num_of_cmds,
  ds_at_cmd_info_type *at_cmd_list,
  void                *user_data
);

/*===========================================================================
  FUNCTION:  ds_at_send_resp
===========================================================================*/
/*!
    @brief
    used to send response for indication.

    @return
    DS_AT_SUCCESS
    DS_AT_FAILURE
*/
/*=========================================================================*/
extern int
ds_at_send_cmd_resp
(
  ds_at_cmd_info_type   *cmd_info,
  ds_at_resp_info_type  *resp
);

/*===========================================================================
  FUNCTION:  ds_at_send_urc_resp
===========================================================================*/
/*!
    @brief
    used to send un-solicited response.

    @return
    DS_AT_SUCCESS
    DS_AT_FAILURE
*/
/*=========================================================================*/
extern int
ds_at_send_urc_resp
(
  ds_at_cmd_info_type   *cmd_info,
  ds_at_resp_info_type  *resp
);


#endif /* DS_ATCTRL_H */

#ifdef __cplusplus
}
#endif

