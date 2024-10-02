/************
 *
 * Filename:  qapiudefs.h
 *
 * Purpose:   external definitions for QAPI package
 *
 * NOTES:
 *
 * Copyright: (c) 2020 WOORINET. All rights reserved.
 *
 ************/

#ifndef QAPIUDEFS_H
#define QAPIUDEFS_H

/* Include files */
#include "aaglobal.h"

/* Constants and enumerated types */

/* Used by apps only, and accessed by su package */
/* WOORINET_TBD - imorrison 2015:03:03 - these are probably larger than needed */
#define QAPI_QCCI_STACK_SIZE (64*1024)
#define QAPI_QCSI_STACK_SIZE (64*1024)

/************
 *
 * Name:     qapi_service_id_e
 *
 * Purpose:  To enumerate the service ID when registering with QAPI
 *
 * Notes:
 *
 ************/
enum qapi_service_id_e
{
  QAPI_SERVICE_COMMON = 0,
  QAPI_SERVICE_MAX = QAPI_SERVICE_COMMON,
  QAPI_SERVICE_COUNT,
};

/************
 *
 * Name:     qapi_result_code_e
 *
 * Purpose:  Defines result code used for QAPI service
 *
 * Notes:    similar to QCT qmi_result_e_type
 *
 ************/
enum qapi_result_code_e
{
  QAPI_RESULT_SUCCESS = 0,    /* No Error */
  QAPI_RESULT_FAILURE = 1,    /* failure */
  QAPI_RESULT_MAX,
  QAPI_RESULT_WIDTH = 0xFFFF
};

/************
 *
 * Name:     qapi_err_code_e
 *
 * Purpose:  Defines error code used for QAPI service
 *
 * Notes:    similar to qmi_error_e_type
 *
 ************/
enum qapi_err_code_e
{
  QAPI_ERR_NONE          = 0,
  QAPI_ERR_MALFORMED_MSG = 1,
  QAPI_ERR_NO_MEMORY     = 2,
  QAPI_ERR_INTERNAL      = 3,
  QAPI_ERR_MISSING_ARG   = 17,
  QAPI_ERR_ARG_TOO_LONG  = 19,
  QAPI_ERR_GENERAL       = 46,
  QAPI_ERR_UNKNOWN       = 47,
  QAPI_ERR_INVALID_ARG   = 48,
  QAPI_ERR_INVALID_MSG_ID= 57,
  QAPI_ERR_MAX,
  QAPI_ERROR_WIDTH = 0xFFFF
};

/* structures */

/*
 * QAPI SERVICE Types
 */

/************
 *
 * Name:     qapi_qcsi_cli_handle
 *
 * Purpose:  Opaque handle to be used by services when referring to a
 *           connected client
 *
 * Notes:
 *
 ************/
typedef struct qapi_qcsi_client_s *qapi_qcsi_cli_handle;

/************
 *
 * Name:     qapi_qcsi_req_handle
 *
 * Purpose:  Opaque request handle to be used by services when responding
 *           to a request
 *
 * Notes:
 *
 ************/
typedef void *qapi_qcsi_req_handle;

/************
 *
 * Name:     qapi_qcsi_req_handler
 *
 * Purpose:  QAPI request handler prototype.  Services must register a
 *           request handler with a server via qapi_qcsi_handler_register()
 *
 * Notes:
 *
 ************/
typedef boolean (*qapi_qcsi_req_handler) (
  qapi_qcsi_cli_handle client,         /* client handle                          */
  qapi_qcsi_req_handle req_handle,     /* needed if service will send a response */
  unsigned int         msg_id,         /* message id of request                  */
  void                *c_struct,       /* message data                           */
  unsigned int         c_struct_len,   /* message data length                    */
  void                *cb_data);       /* opaque data returned to the registrant */

/************
 *
 * Name:     qapi_qcsi_cli_conn_cb
 *
 * Purpose:  QAPI QCSI connect and disconnect handler prototype.
 *           Services may optionally register these handlers when
 *           registering a request handler via qapi_qcsi_handler_register()
 *
 * Notes:
 *
 ************/
typedef void (*qapi_qcsi_cli_conn_cb) (
  qapi_qcsi_cli_handle client,     /* client handle                          */
  void                *cb_data);   /* opaque data returned to the registrant */

/*
 * QAPI CLIENT Types
 */

/************
 *
 * Name:     qapi_qcci_client_handle
 *
 * Purpose:  Opaque handle to be used by clients
 *
 *
 * Notes:
 *
 ************/
typedef struct qapi_qcci_client_s *qapi_qcci_client_handle;

/************
 *
 * Name:     qapi_qcci_ind_callback
 *
 * Purpose:  QAPI QCSI indication callback
 *           Clients may optionally register this callback when
 *           requesting a handle via qapi_qcci_register()
 *
 * Notes:
 *
 ************/
typedef void (*qapi_qcci_ind_callback) (
  unsigned int  msg_id,         /* message id of request                  */
  const void   *c_struct,       /* message data                           */
  unsigned int  c_struct_len,   /* message data length                    */
  void         *cb_data);       /* opaque data returned to the registrant */

/************
 *
 * Name:     qapi_qcci_conn_callback
 *
 * Purpose:  QAPI QCSI connect and disconnect callback
 *           Clients may optionally register these callbacks when
 *           requesting a handle via qapi_qcci_register()
 *
 * Notes:
 *
 ************/
typedef void (*qapi_qcci_conn_callback) (
  void *cb_data);   /* opaque data returned to the registrant */

/************
 *
 * Name:     qapi_qcci_resp_callback
 *
 * Purpose:  QAPI QCSI indication callback
 *           Clients may optionally register this callback when
 *           sending a message via qapi_qcci_request_send_async()
 *
 * Notes:    !Callers must check the message data pointer for NULL!
 *           Message data will not be returned if communication was
 *           lost while a request is being processed
 *
 ************/
typedef void (*qapi_qcci_resp_callback) (
  unsigned int  msg_id,         /* message id of request                  */
  void         *c_struct,       /* message data                           */
  unsigned int  c_struct_len,   /* message data length                    */
  boolean       status,         /* result of the request TRUE/FALSE       */
  void         *cb_data);       /* opaque data returned to the caller     */


/* include files */
#include "qapiuproto.h"

#endif /* QAPIUDEFS_H */
