#ifndef QAPI_COMMON_SERVICE_01_H
#define QAPI_COMMON_SERVICE_01_H
/**
  @file qapi_common_v01.h

  @brief This is the public header file which defines the qapi_common service Data structures.

  This header file defines the types and structures that were defined in
  qapi_common. It contains the constant values defined, enums, structures,
  messages, and service message IDs (in that order) Structures that were
  defined in the IDL as messages contain mandatory elements, optional
  elements, a combination of mandatory and optional elements (mandatory
  always come before optionals in the structure), or nothing (null message)

  An optional element in a message is preceded by a uint8_t value that must be
  set to true if the element is going to be included. When decoding a received
  message, the uint8_t values will be set to true or false by the decode
  routine, and should be checked before accessing the values that they
  correspond to.

  Variable sized arrays are defined as static sized arrays with an unsigned
  integer (32 bit) preceding it that must be set to the number of elements
  in the array that are valid. For Example:

  uint32_t test_opaque_len;
  uint8_t test_opaque[16];

  If only 4 elements are added to test_opaque[] then test_opaque_len must be
  set to 4 before sending the message.  When decoding, the _len value is set
  by the decode routine and should be checked so that the correct number of
  elements in the array will be accessed.

*/
/*====*====*====*====*====*====*====*====*====*====*====*====*====*====*====*
  

  
 *====*====*====*====*====*====*====*====*====*====*====*====*====*====*====*/
/*====*====*====*====*====*====*====*====*====*====*====*====*====*====*====*
 *THIS IS AN AUTO GENERATED FILE. DO NOT ALTER IN ANY WAY
 *====*====*====*====*====*====*====*====*====*====*====*====*====*====*====*/

/* This file was generated with Tool version 6.14.9 
   It was generated on: Wed Jun 23 2021 (Spin 0)
   From IDL File: qapi_common_v01.idl */

/** @defgroup qapi_common_qmi_consts Constant values defined in the IDL */
/** @defgroup qapi_common_qmi_msg_ids Constant values for QMI message IDs */
/** @defgroup qapi_common_qmi_enums Enumerated types used in QMI messages */
/** @defgroup qapi_common_qmi_messages Structures sent as QMI messages */
/** @defgroup qapi_common_qmi_aggregates Aggregate types used in QMI messages */
/** @defgroup qapi_common_qmi_accessor Accessor for QMI service object */
/** @defgroup qapi_common_qmi_version Constant values for versioning information */

#include <stdint.h>
#include "qmi_idl_lib.h"

#define QAPI_PING_REQ_V01 0x0001
#define QAPI_PING_RESP_V01 0x0001
#define QAPI_PING_IND_V01 0x0001
#define QAPI_LINUX_FM_OP_REQ_V01 0x0002
#define QAPI_LINUX_FM_OP_RESP_V01 0x0002
#define QAPI_FOTA_FLAG_OP_REQ_V01 0x0003
#define QAPI_FOTA_FLAG_OP_RESP_V01 0x0003
#define QAPI_WAKELOCK_OP_REQ_V01 0x0004
#define QAPI_WAKELOCK_OP_RESP_V01 0x0004
#define QAPI_ERR_OPTION_REQ_V01 0x0005
#define QAPI_ERR_OPTION_RESP_V01 0x0005
#define QAPI_LINUX_POPEN_OP_REQ_V01 0x0006
#define QAPI_LINUX_POPEN_OP_RESP_V01 0x0006
#define QAPI_NV_OP_REQ_V01 0x0007
#define QAPI_NV_OP_RESP_V01 0x0007
#define QAPI_NV_OP_IND_V01 0x0007

#ifdef __cplusplus
extern "C" {
#endif

/** @addtogroup qapi_common_qmi_version
    @{
  */
/** Major Version Number of the IDL used to generate this file */
#define QAPI_COMMON_V01_IDL_MAJOR_VERS 0x01
/** Revision Number of the IDL used to generate this file */
#define QAPI_COMMON_V01_IDL_MINOR_VERS 0x01
/** Major Version Number of the qmi_idl_compiler used to generate this file */
#define QAPI_COMMON_V01_IDL_TOOL_VERS 0x06

/**
    @}
  */


/** @addtogroup qapi_common_qmi_consts
    @{
  */

/**  Maximum size of Linux File data */
#define QAPI_LINUX_FM_OP_SIZE_MAX_V01 4000

/**  Maximum size of Linux Path and NAme */
#define QAPI_LINUX_FM_OP_NAME_SIZE_MAX_V01 256

/**  Maximum size of WAKELOCK name */
#define WAKELOCK_NAME_LEN_MAX_V01 64

/**  Maximum size of Linux popen data */
#define QAPI_LINUX_POPEN_OP_SIZE_MAX_V01 4000

/**  Maximum size of NV data */
#define QAPI_NV_DATA_SIZE_MAX_V01 4096

/**  Maximum number of NV tag to delete */
#define QAPI_NV_DEL_TAG_MAX_V01 255
/**
    @}
  */

/** @addtogroup qapi_common_qmi_aggregates
    @{
  */
/** 
 Message Status

    The status structure is used to report the result of a request.  Services
    must set it and clients may read it

 */
typedef struct {

  /*  0=Success, 1=Failure */
  uint16_t result;

  /*  OEM defined error values */
  uint16_t error;
}qapi_status_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup qapi_common_qmi_messages
    @{
  */
/** Request Message; This message tests basic message passing between
  client and service */
typedef struct {

  /* Mandatory */
  /*  Ping */
  char ping[5];
  /**<   Simple 'ping' request */
}qapi_ping_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qapi_common_qmi_messages
    @{
  */
/** Response Message; This message tests basic message passing between
  client and service */
typedef struct {

  /* Mandatory */
  /*  Status of the request */
  qapi_status_type_v01 status;

  /* Mandatory */
  /*  Pong */
  char pong[5];
  /**<   Simple 'pong' response */
}qapi_ping_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qapi_common_qmi_messages
    @{
  */
/** Indication Message; This message tests basic message passing between
  client and service */
typedef struct {

  /* Mandatory */
  /*  Status of the indication */
  qapi_status_type_v01 status;

  /* Mandatory */
  /*  temporary workaround to avoid
 duplicate indications.
 !!! Private data, not to be used by clients or services !!! */
  uint32_t ind_count;

  /* Mandatory */
  /*  Hello indication */
  char hello[6];
  /**<   Simple 'hello' indication */
}qapi_ping_ind_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qapi_common_qmi_enums
    @{
  */
typedef enum {
  QAPI_LINUX_FM_OP_STATUS_ENUM_TYPE_MIN_ENUM_VAL_V01 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  QAPI_LINUX_FM_OP_OPEN_V01 = 0, 
  QAPI_LINUX_FM_OP_CLOSE_V01 = 1, 
  QAPI_LINUX_FM_OP_WRITE_V01 = 2, 
  QAPI_LINUX_FM_OP_MOVE_V01 = 3, 
  QAPI_LINUX_FM_OP_DELETE_V01 = 4, 
  QAPI_LINUX_FM_OP_VERIFY_MD5_V01 = 5, 
  QAPI_LINUX_FM_OP_STATUS_ENUM_TYPE_MAX_ENUM_VAL_V01 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}qapi_linux_fm_op_status_enum_type_v01;
/**
    @}
  */

/** @addtogroup qapi_common_qmi_messages
    @{
  */
/** Request Message; This message sends a Linux FM operation */
typedef struct {

  /* Mandatory */
  /*  FOTA Data Mode
 enum {
   QAPI_LINUX_FM_OP_OPEN = 0,
   QAPI_LINUX_FM_OP_CLOSE = 1,
   QAPI_LINUX_FM_OP_WRITE = 2,
   QAPI_LINUX_FM_OP_MOVE = 3,
   QAPI_LINUX_FM_OP_DELETE = 4,
   QAPI_LINUX_FM_OP_VERIFY_MD5 = 5,
 } qapi_linux_fm_op_status_enum_type; */
  qapi_linux_fm_op_status_enum_type_v01 datamode;

  /* Optional */
  /*  FOTA Data Path and Name */
  uint8_t dataname_valid;  /**< Must be set to true if dataname is being passed */
  uint32_t dataname_len;  /**< Must be set to # of elements in dataname */
  uint8_t dataname[QAPI_LINUX_FM_OP_NAME_SIZE_MAX_V01];

  /* Optional */
  /*  FOTA Data */
  uint8_t data_valid;  /**< Must be set to true if data is being passed */
  uint32_t data_len;  /**< Must be set to # of elements in data */
  uint8_t data[QAPI_LINUX_FM_OP_SIZE_MAX_V01];
}qapi_linux_fm_op_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qapi_common_qmi_messages
    @{
  */
/** Response Message; This message sends a Linux FM operation */
typedef struct {

  /* Mandatory */
  /*  Status of the request */
  qapi_status_type_v01 status;

  /* Optional */
  /*  FOTA Data Path and Name */
  uint8_t dataname_valid;  /**< Must be set to true if dataname is being passed */
  uint32_t dataname_len;  /**< Must be set to # of elements in dataname */
  uint8_t dataname[QAPI_LINUX_FM_OP_NAME_SIZE_MAX_V01];

  /* Optional */
  /*  FOTA Data */
  uint8_t data_valid;  /**< Must be set to true if data is being passed */
  uint32_t data_len;  /**< Must be set to # of elements in data */
  uint8_t data[QAPI_LINUX_FM_OP_SIZE_MAX_V01];
}qapi_linux_fm_op_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qapi_common_qmi_messages
    @{
  */
/** Request Message; This message send a command to apps to set fota flag */
typedef struct {

  /* Mandatory */
  /*  Fota flag operation type
 1 - set flag */
  uint8_t optype;
}qapi_fota_flag_op_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qapi_common_qmi_messages
    @{
  */
/** Response Message; This message send a command to apps to set fota flag */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qapi_status_type_v01 status;
}qapi_fota_flag_op_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qapi_common_qmi_messages
    @{
  */
/** Request Message; This message send a command to apps to acquire/release a wakelock */
typedef struct {

  /* Mandatory */
  /*  Wakelock operation type
 0 - unlock
 1 - lock */
  uint8_t optype;

  /* Mandatory */
  /*  Wakelock name */
  uint32_t name_len;  /**< Must be set to # of elements in name */
  char name[WAKELOCK_NAME_LEN_MAX_V01];
}qapi_wakelock_op_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qapi_common_qmi_messages
    @{
  */
/** Response Message; This message send a command to apps to acquire/release a wakelock */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qapi_status_type_v01 status;

  /* Mandatory */
  /*  Wakelock operation type
 0 - unlock
 1 - lock */
  uint8_t optype;

  /* Mandatory */
  /*  Wakelock name */
  uint32_t name_len;  /**< Must be set to # of elements in name */
  char name[WAKELOCK_NAME_LEN_MAX_V01];
}qapi_wakelock_op_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qapi_common_qmi_messages
    @{
  */
/** Request Message; This message send a command to apps to set error option */
typedef struct {

  /* Mandatory */
  /*  err_action_type type
 0 - ERR_RESET
 1 - ERR_DLOAD
 2 - ERR_NO_ACTION */
  uint8_t err_opt;
}qapi_err_opt_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qapi_common_qmi_messages
    @{
  */
/** Response Message; This message send a command to apps to set error option */
typedef struct {

  /* Mandatory */
  /*  Result Code */
  qapi_status_type_v01 status;
}qapi_err_opt_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qapi_common_qmi_messages
    @{
  */
/** Request Message; This message sends a Linux popen operation */
typedef struct {

  /* Mandatory */
  /*  popen data */
  uint32_t data_len;  /**< Must be set to # of elements in data */
  uint8_t data[QAPI_LINUX_POPEN_OP_SIZE_MAX_V01];
}qapi_linux_popen_op_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qapi_common_qmi_messages
    @{
  */
/** Response Message; This message sends a Linux popen operation */
typedef struct {

  /* Mandatory */
  /*  Status of the request */
  qapi_status_type_v01 status;

  /* Optional */
  /*  popen data */
  uint8_t data_valid;  /**< Must be set to true if data is being passed */
  uint32_t data_len;  /**< Must be set to # of elements in data */
  uint8_t data[QAPI_LINUX_POPEN_OP_SIZE_MAX_V01];
}qapi_linux_popen_op_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qapi_common_qmi_aggregates
    @{
  */
typedef struct {

  uint8_t delallflag;

  uint8_t arrayidx;

  uint32_t nvdeltag;
}qapi_nv_del_info_type_v01;  /* Type */
/**
    @}
  */

/** @addtogroup qapi_common_qmi_messages
    @{
  */
/** Request Message; This message sends an NV request message */
typedef struct {

  /* Mandatory */
  /*  NV Operation Type */
  uint16_t operation;

  /* Optional */
  /*  NV Item Tag */
  uint8_t nvtag_valid;  /**< Must be set to true if nvtag is being passed */
  uint32_t nvtag;

  /* Optional */
  /*  NV Item Data */
  uint8_t nvdata_valid;  /**< Must be set to true if nvdata is being passed */
  uint32_t nvdata_len;  /**< Must be set to # of elements in nvdata */
  uint8_t nvdata[QAPI_NV_DATA_SIZE_MAX_V01];

  /* Optional */
  /*  NV delete tag */
  uint8_t nvdelinfo_valid;  /**< Must be set to true if nvdelinfo is being passed */
  uint32_t nvdelinfo_len;  /**< Must be set to # of elements in nvdelinfo */
  qapi_nv_del_info_type_v01 nvdelinfo[QAPI_NV_DEL_TAG_MAX_V01];
}qapi_nv_op_req_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qapi_common_qmi_messages
    @{
  */
/** Response Message; This message sends an NV request message */
typedef struct {

  /* Mandatory */
  /*  Status of the request */
  qapi_status_type_v01 status;

  /* Mandatory */
  /*  NV Operation Type */
  uint16_t operation;

  /* Optional */
  /*  NV Item Tag */
  uint8_t nvtag_valid;  /**< Must be set to true if nvtag is being passed */
  uint32_t nvtag;

  /* Optional */
  /*  NV Item Data */
  uint8_t nvdata_valid;  /**< Must be set to true if nvdata is being passed */
  uint32_t nvdata_len;  /**< Must be set to # of elements in nvdata */
  uint8_t nvdata[QAPI_NV_DATA_SIZE_MAX_V01];
}qapi_nv_op_resp_msg_v01;  /* Message */
/**
    @}
  */

/** @addtogroup qapi_common_qmi_messages
    @{
  */
/** Indication Message; This message sends an NV request message */
typedef struct {

  /* Mandatory */
  /*  Status of the indication */
  qapi_status_type_v01 status;

  /* Mandatory */
  /*  TBD - temporary workaround to avoid
 duplicate indications.
 !!! Private data, not to be used by clients or services !!! */
  uint32_t ind_count;

  /* Mandatory */
  /*  NV Operation Type */
  uint16_t operation;

  /* Optional */
  /*  NV Item Tag */
  uint8_t nvtag_valid;  /**< Must be set to true if nvtag is being passed */
  uint32_t nvtag;

  /* Optional */
  /*  NV Item Data */
  uint8_t nvdata_valid;  /**< Must be set to true if nvdata is being passed */
  uint32_t nvdata_len;  /**< Must be set to # of elements in nvdata */
  uint8_t nvdata[QAPI_NV_DATA_SIZE_MAX_V01];
}qapi_nv_op_ind_msg_v01;  /* Message */
/**
    @}
  */

/* Conditional compilation tags for message removal */ 

/*Extern Definition of Type Table Object*/
/*THIS IS AN INTERNAL OBJECT AND SHOULD ONLY*/
/*BE ACCESSED BY AUTOGENERATED FILES*/
extern const qmi_idl_type_table_object qapi_common_qmi_idl_type_table_object_v01;


#ifdef __cplusplus
}
#endif
#endif

