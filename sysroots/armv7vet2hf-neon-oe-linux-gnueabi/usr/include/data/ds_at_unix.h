/**
  @file
  ds_at_unix.h

  @brief
  This file provides an APIs to send/print messages on unix socket
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

#ifndef DS_AT_UNIX_H
#define DS_AT_UNIX_H

#include <stdio.h>

/*---------------------------------------------------------------------------
   Constant representing integer value returned for errors occurring in
   system calls
---------------------------------------------------------------------------*/
#define DS_AT_UNIX_API_ERROR                                    (-1)

/*---------------------------------------------------------------------------
   Constant representing maximum number of clients that can connect to
   ds_at daemon before they are dropped.
---------------------------------------------------------------------------*/
#define DS_AT_UNIX_MAX_CLIENTS                                  (20)

/*---------------------------------------------------------------------------
   Constant representing maximum size of a message to be used for
   communication.
---------------------------------------------------------------------------*/
#define DS_AT_UNIX_MAX_MESSAGE_SIZE                           (4096)

#define UNIX_PATH_MAX                                          (108)
#define DS_AT_UNIX_CLIENT_CONN_SOCK_PATH "/dev/socket/atfwd/ds_at_connect_socket"


/*===========================================================================
  FUNCTION  ds_at_util_print_packet
===========================================================================*/
/*!
@brief
  Prints a pkt of size pktlen bytes. If pktlen is greater than 2048,
  then the first 2048 bytes are printed. If pktlen is 0 or lesser, or if
  the buffer is NULL, we do not print anything.

@return
  int - DS_AT_SUCCESS on operation success, DS_AT_FAILURE otherwise

@note

  - Dependencies
    - None

  - Side Effects
    - None
*/
/*=========================================================================*/
void
ds_at_util_print_packet
(
  char  *pkt,
  int    pktlen,
  char  *direction
);

/*===========================================================================
  FUNCTION  ds_at_unix_ipc_send_msg
===========================================================================*/
/*!
@brief
  Function to send unicast NETLINK messages to ds_at daemon and to receive the
  responses from ds_at daemon. This is interface for clients of ds_at daemon to
  communicate with ds_at daemon

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
ds_at_unix_ipc_send_msg
(
  char           *req_buffer,
  int             req_bufflen,
  char          **resp_buffer,
  unsigned int   *resp_bufflen,
  int             resp_timeout
);

#endif /*DS_AT_UNIX_H */

#ifdef __cplusplus
}
#endif

