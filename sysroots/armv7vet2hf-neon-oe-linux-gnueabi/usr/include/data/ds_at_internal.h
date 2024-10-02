/**
  @file
  ds_at_internal.h

  @brief
  This file provides an APIs to interact with internal functions
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

#ifndef DS_AT_INTERNAL_H
#define DS_AT_INTERNAL_H

#include "ds_list.h"
#include "ds_cmdq.h"

extern boolean                        ds_at_inited;
extern boolean                      ds_at_released;
extern pthread_mutex_t          ds_at_global_mutex;
extern pthread_mutex_t        ds_at_ping_tid_mutex;
extern ds_at_init_cb_info_t     ds_at_init_cb_info;
extern ds_dll_el_t                 *ds_at_dll_head;
extern ds_dll_el_t                 *ds_at_dll_tail;
extern ds_cmdq_info_t                ds_at_cb_cmdq;

/* ds_at_cb cmd : contains type and data */
typedef struct ds_atctrl_cb_cmd_s
{
  ds_cmd_t cmd;
  ds_at_nl_events_t cmd_data;
} ds_at_cb_cmd_t;

/*===========================================================================
  FUNCTION  ds_at_match_node
===========================================================================*/
/*!
@brief
  Compares nodes to determine if they match.  Used by
  linked-list search route.

@return
  void

@note

  - Dependencies
    - None

  - Side Effects
    - None
*/
/*=========================================================================*/
long int
ds_at_match_node
(
  const void * first,
  const void * second
);

/*===========================================================================
  FUNCTION:  ds_at_init_log
===========================================================================*/
/*!
    @brief
    This function initializes the ds_at logging module

    @return
    DS_AT_SUCCESS
    DS_AT_FAILURE
*/
/*=========================================================================*/
int
ds_at_init_log
(
  void
);

/*===========================================================================
  FUNCTION:  ds_at_init_cmdq
===========================================================================*/
/*!
    @brief
    This function initializes the cmdq for event processing

    @return
    DS_AT_SUCCESS
    DS_AT_FAILURE
*/
/*=========================================================================*/
int
ds_at_init_cmdq
(
  void
);

/*===========================================================================
  FUNCTION:  ds_at_cb_cmd_exec
===========================================================================*/
/*!
    @brief
    This function is registered as executive function in each command that
    is posted to ds_at_cb global queue.
    When called, this function further calls appropriate functions based
    on the command types.

    @return
    none
*/
/*=========================================================================*/
void
ds_at_cb_cmd_exec
(
  ds_cmd_t *cmd,
  void     *data
);

/*===========================================================================
  FUNCTION:  ds_at_exec_cmd_free
===========================================================================*/
/*!
    @brief
    releases memory for the ds_at_cb cmd

    @return
    none
*/
/*=========================================================================*/
void
ds_at_cb_cmd_free
(
  ds_cmd_t *cmd,
  void     *data
);

/*===========================================================================
  FUNCTION:  ds_at_notify_users
===========================================================================*/
/*!
    @brief
    notify the client for the AT events

    event is a AT event

    @return
    none
*/
/*=========================================================================*/

void
ds_at_notify_users
(
  int event
);

/*===========================================================================
  FUNCTION:  ds_at_init_dll
===========================================================================*/
/*!
    @brief
    Initializes link list to store cmds and respective handlers

    @return
    DS_AT_SUCCESS
    DS_AT_ERROR
*/
/*=========================================================================*/
int
ds_at_init_dll
(
  void
);

/*===========================================================================
  FUNCTION:  ds_at_deinit_dll
===========================================================================*/
/*!
    @brief
    Release memory used for linked list

    @return
    none
*/
/*=========================================================================*/
void
ds_at_deinit_dll
(
  void
);

/*===========================================================================
  FUNCTION:  ds_at_daemon_cb
===========================================================================*/
/*!
    @brief
    callback function registered with ds_at_daemon

    @return
    void
*/
/*=========================================================================*/
void
ds_at_daemon_cb
(
  ds_at_nl_events_t      event,
  ds_at_nl_event_info_t *info,
  void                  *data
);

/*===========================================================================
  FUNCTION:  ds_at_init_query_daemon
===========================================================================*/
/*!
    @brief
    seperate thread to query ds_at daemon for readiness status. It updates
    ds_at_inited accordingly.
    Repeat query periodically if ds_at_inited is not TRUE

    @return
    DS_AT_SUCCESS
    DS_AT_ERROR
*/
/*=========================================================================*/
int
ds_at_init_query_atfwd_daemon
(
  void
);

/*===========================================================================
  FUNCTION:  ds_at_init_register_cb
===========================================================================*/
/*!
    @brief
    Initializes ds_at client

    @return
    DS_AT_SUCCESS
    DS_AT_ERROR
*/
/*=========================================================================*/
int
ds_at_init_register_cb
(
  void
);

/*===========================================================================
  FUNCTION  ds_at_client_register
===========================================================================*/
/*!
@brief
  Function to register client for ds_at asynchronous envents.

@return
  int - DS_AT_SUCCESS on successful operation, DS_AT_FAILURE otherwise

@note

  - Dependencies
    - None

  - Side Effects
    - None
*/
/*=========================================================================*/
int
ds_at_client_register
(
  ds_at_event_ind_f          cb_f,
  void                      *data,
  atfwd_daemon_client_hdl_t *client_hndl
);

/*===========================================================================
  FUNCTION  ds_at_client_send_ping_msg
===========================================================================*/
/*!
@brief
  Function to query DS_AT DAEMON for its readiness status. @param timeout is
  the interval to wait for a response.

@return
  int - DS_AT_SUCCESS on successful operation, DS_AT_FAILURE otherwise

@note

  - Dependencies
    - None

  - Side Effects
    - None
*/
/*=========================================================================*/
int
ds_at_client_send_ping_msg
(
  int resp_timeout
);

/*===========================================================================
  FUNCTION  ds_at_client_send_user_resp
===========================================================================*/
/*!
@brief
  Function to send reponse to atfwd daemon.

@return
  int - DS_AT_SUCCESS on successful operation, DS_AT_FAILURE otherwise

*/
/*=========================================================================*/
int
ds_at_client_send_user_resp
(
  int                   cmd_id,
  ds_at_cmd_info_type  *cmd_info,
  ds_at_resp_info_type *resp
);

/*===========================================================================
  FUNCTION  ds_at_client_send_user_cmd
===========================================================================*/
/*!
@brief
  Function to send proprietary commands to atfwd daemon.
  @param timeout is the
  interval to wait for a response.

@return
  int - DS_AT_SUCCESS on successful operation, DS_AT_FAILURE otherwise

*/
/*=========================================================================*/
int
ds_at_client_send_user_cmd
(
  int                     cmd,
  ds_at_user_cmd_data_t  *cmd_data,
  ds_at_nl_event_info_t  *resp_info,
  int                     resp_timeout
);

#endif /* DS_AT_INTERNAL_H */

#ifdef __cplusplus
}
#endif

