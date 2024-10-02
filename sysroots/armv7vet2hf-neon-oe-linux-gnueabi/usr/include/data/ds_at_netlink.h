/**
  @file
  ds_at_netlink.h

  @brief
  This file provides an APIs to send/recv netlink messages
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

#ifndef DS_AT_NETLINK_H
#define DS_AT_NETLINK_H


#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <pthread.h>
#include <sys/select.h>
#include <sys/socket.h>
#include <linux/if.h>
#include <linux/if_addr.h>
#include <linux/rtnetlink.h>
#include <linux/netlink.h>
#include <linux/xfrm.h>

#define NL_MSG_MAX_LEN                   (4096)

#define DS_AT_NL_TYPE           NETLINK_GENERIC   /* Netlink type used */
#define DS_AT_NL_GRP_EVENTS             (1<<30)   /* Multicast group for indications */
#define DS_AT_NL_MULTICAST_SEND             (0)

#define DS_AT_NL_PARAM_NONE            (0x0000)
#define DS_AT_NL_PARAM_EVENT           (0x0001)
#define DS_AT_NL_EVENT                   (0x01)

/*---------------------------------------------------------------------------
   Type representing collection of control info related to a netlink socket
---------------------------------------------------------------------------*/
typedef struct {
  int                 sk_fd;       /* socket descriptor */
  struct sockaddr_nl  sk_addr_loc; /* local address of socket */
  struct sockaddr_nl  sk_addr_rem; /* remote endpoint's address */
} ds_at_nl_sk_info_t;

/*---------------------------------------------------------------------------
   Type representing function callback registered with a socket listener
   thread for reading from a socket on receipt of an incoming message
---------------------------------------------------------------------------*/
typedef int (* ds_at_socklthrd_fd_read_f)
(
  int fd
);

/*---------------------------------------------------------------------------
   Type representing collection of info registered with a socket listener
   thread by clients
---------------------------------------------------------------------------*/
typedef struct {
  int                       fd;     /* Socket descriptor */
  ds_at_socklthrd_fd_read_f read_f; /* Incoming data notify handler */
} ds_at_socklthrd_fdmap_t;

/*---------------------------------------------------------------------------
   Type representing a handle to a socket listener thread. Clients must
   use this as an opaque pointer.
---------------------------------------------------------------------------*/
typedef struct {
  pthread_t                thrd;      /* Pthread object for the thread */
  ds_at_socklthrd_fdmap_t *fdmap;     /* Ptr to array of fdmap structs */
  unsigned int             nfd;       /* Number of valid fds in fdmap */
  unsigned int             maxnfd;    /* Size of fdmap array */
  int                      maxfd;     /* Maximum valued fd */
  fd_set                   fdset;     /* fdset used in select() operation */
  boolean                  running;   /* Flag for processing thread state */
} ds_at_socklthrd_info_t;

/*===========================================================================
                            GLOBAL FUNCTION DEFINITIONS
===========================================================================*/


/*===========================================================================
  FUNCTION  ds_at_nl_alloc_msg
===========================================================================*/
/*!
@brief
  Allocate a NETLINK message structure from dynamic memory.
  The msglen parameter denotes the size of the message payload in bytes.
  Client is responsible for releasing message dynamic memory.

@return
  struct msghdr * - Pointer on successful allocaiton, NULL otherwise.

@note

  - Dependencies
    - None

  - Side Effects
    - Memory is allocated from system heap.
*/
/*=========================================================================*/
struct msghdr *
ds_at_nl_alloc_msg
(
  uint32  msglen
);

/*===========================================================================
  FUNCTION  ds_at_nl_release_msg
===========================================================================*/
/*!
@brief
  Release a NETLINK message structure from dynamic memory.

@return
  void

@note

  - Dependencies
    - None

  - Side Effects
    - Memory is returned to system heap
*/
/*=========================================================================*/
void
ds_at_nl_release_msg
(
  struct msghdr * msgh
);

/*===========================================================================
  FUNCTION  ds_at_nl_recv_msg
===========================================================================*/
/*!
@brief
  Reads a complete NETLINK message incoming over the specified socket
  descriptor and returns it. Note that the memory for the message is
  dynamically allocated.

@return
  int - DS_AT_SUCCESS on successful operation, DS_AT_FAILURE otherwise

@note

  - Dependencies
    - None

  - Side Effects
    - Message buffer allocated from system heap
*/
/*=========================================================================*/
int
ds_at_nl_recv_msg
(
  int             fd,
  struct msghdr **msg_pptr,
  unsigned int   *msglen_ptr
);


/*===========================================================================
  FUNCTION ds_at_nl_open_sock
===========================================================================*/
/*!
@brief
  Opens a netlink socket for the specified protocol and multicast group
  memberships.

@return
  int - DS_AT_SUCCESS if socket is successfully opened,
        DS_AT_FAILURE otherwise

@note

  - Dependencies
    - None

  - Side Effects
    - None
*/
/*=========================================================================*/
int
ds_at_nl_open_sock
(
  ds_at_nl_sk_info_t *sk_info,
  int                 proto,
  unsigned int        grps
);


/*===========================================================================
  FUNCTION  ds_at_nl_send_msg
===========================================================================*/
/*!
@brief
  Writes a complete NETLINK message over the specified socket
  descriptor. The specified buffer is assumed to conform with NETLINK
  message format specified in include/net/netlink.h

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
ds_at_nl_send_msg
(
  int     fd,
  pid_t   pid,
  void   *buffer,
  uint16  buflen
);

/*===========================================================================
  FUNCTION  ds_at_nl_encode_ds_at_event
===========================================================================*/
/*!
@brief
  Encode event parameters into Netlink attribute TLVs.  Octet buffer
  is allocated internally and returned to caller; caller must release
  buffer when done with it.

@return
  int - DS_AT_SUCCESS on successful operation, DS_AT_FAILURE otherwise

@note

  - Dependencies
    - None

  - Side Effects
    - Buffer allocated from dynamic memory
*/
/*=========================================================================*/
extern int
ds_at_nl_encode_ds_at_event
(
  const ds_at_nl_event_info_t  *event_info,
  char                        **buffer,
  unsigned int                 *buflen
);


/*===========================================================================
  FUNCTION  ds_at_nl_decode_ds_at_event
===========================================================================*/
/*!
@brief
  Decode ds_at event parameters from Netlink attribute TLVs.

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
ds_at_nl_decode_ds_at_event
(
  const char              *buffer,
  unsigned int             buflen,
  ds_at_nl_event_info_t   *event_info
);


/*===========================================================================
  FUNCTION  ds_at_nl_decode_nlmsg
===========================================================================*/
/*!
@brief
  Decode Netlink message TLVs.

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
ds_at_nl_decode_nlmsg
(
  const char         *buffer,
  unsigned int        buflen,
  ds_at_nl_msg_t     *msg_ptr
);


/*===========================================================================
  FUNCTION  ds_at_nl_listener_init
===========================================================================*/
/*!
@brief
  Initialization routine for listener on NetLink sockets interface.

@return
  int - DS_AT_SUCCESS on successful operation, DS_AT_FAILURE otherwise

@note

  - Dependencies
    - None

  - Side Effects
    - Listening thread is created
*/
/*=========================================================================*/
int
ds_at_nl_listener_init
(
  ds_at_socklthrd_info_t   *sk_thrd_info,
  ds_at_socklthrd_fdmap_t  *sk_thrd_fdmap,
  unsigned int              sk_thrd_fdmap_size,
  ds_at_nl_sk_info_t       *sk_info,
  unsigned int              nl_type,
  unsigned int              nl_groups,
  ds_at_socklthrd_fd_read_f read_f
);

#endif /*DS_AT_NETLINK_H */

#ifdef __cplusplus
}
#endif

