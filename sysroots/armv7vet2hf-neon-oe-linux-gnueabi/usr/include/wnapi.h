#ifndef _WOORINET_APPLICATION_INTERFACE_HEADER_
#define _WOORINET_APPLICATION_INTERFACE_HEADER_

/*******************************************************************************
 *
 *
 *******************************************************************************/
/*
 *  wnapi.h
 *
 *  Callback for value changes.
 *
 *  Created on: 01.07.2022
 *  Author: pkang
 *  Copyright (c) 2022 woorinet
 */


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define uint8_t unsigned char

typedef struct {
    double latitude;
    double longitude;
    time_t time;
} gps_info;

extern int GetIntValue(char *pid_file);
extern int GetStrValue(char *pid_file, char * dest);

extern int dms_getLibraryVersion();
extern char* dms_getProductName(void);
extern char* dms_getCustomerName(void);
extern char* dms_getDevceType(void);
extern char* dms_getSerialNumber(void);
extern char* dms_getHardwareVersion(void);
extern char* dms_getSoftwareVersion(void);
extern char* dms_getFirmwareVersion(void);
extern char* dms_getPhonenumber(void);
extern char* dms_getIccid(void);
extern char* dms_getImei(void);
extern char* dms_getImsi(void);

extern int nas_initInstance(void);
extern int nas_releaseInstance(void);
extern int nas_getLibraryVersion(void);
extern int nas_getNetBearerCurrent(void);
extern int nas_getNetBearerAvailable(void);
extern int nas_getServiceStatus(void);
extern int nas_getRadioSignal(void);
extern int nas_getRsrp(void);
extern int nas_getRsrp_nr5g(void);
extern int nas_getLinkQuality(void);
extern int nas_getLinkQuality_nr5g(void);
extern float nas_getSINR(void);
extern float nas_getSINR_nr5g(void);
extern char* nas_getIpAddr(void);
extern char* nas_getIpAddrInterface(int rmnetIndex);
extern int nas_getPci(void);
extern int nas_getCellID(void);
extern int nas_getSMNC(void);
extern int nas_getSMCC(void);
extern int nas_getTxPower(void);
extern int nas_getLteBand(void);
extern int nas_getRejectCause(void);     // will be deprecated use nas_getRejectCauseEMM instead
extern int nas_getRejectCauseEMM(void);
extern int nas_getRejectCauseESM(void);
extern void nas_setLibraryType(int t);
///////////////////////////////////////////////////////////////////////////
// NAS_CIOT_SYS_MODE_NO_SRV_V01 = 0x00, /**<  No service \n  */
// NAS_CIOT_SYS_MODE_LTE_WB_V01 = 0x01, /**<  Camped on LTE wideband \n  */
// NAS_CIOT_SYS_MODE_LTE_M1_V01 = 0x02, /**<  Camped on LTE M1 \n  */
// NAS_CIOT_SYS_MODE_LTE_NB1_V01 = 0x03, /**< Camped on LTE NB1  */
extern int nas_getOperationMode(void);

extern int nas_getBand(void);
extern int nas_getEarfcn(void);
extern int nas_getBandWidth(void);
extern int nas_getRadioMode(void);

extern int gps_getInfo(gps_info * p);

// WMS SERVICE
typedef int (*wms_recv_hdlr_f)(char * number, char * data);

extern int wms_getLibraryVersion(void);
extern int wms_initInstance(void);
extern int wms_registerFunc(wms_recv_hdlr_f func);
extern int wms_releaseInstance(void);

// WDS SERVICE
extern bool wds_init(void);
extern bool wds_deinit();
extern bool wds_start_network(uint32_t profile_index, uint32_t rmnet_index);
extern bool wds_stop_network(uint32_t profile_index);
extern bool convert_ipv4_to_ipv6_address(const char *ipv4_address, char *ipv6_address);
extern bool is_ipv6_address(const char *address);
extern bool is_ipv4_address(const char *address);

extern void output_buffer(FILE * stream,
                    uint8_t * buffer,
                    int length,
                    int indent);

/********************************************************************************/

enum {
  LTE_EMM_STATE_NULL,
  LTE_EMM_STATE_DEREGISTERED,
  LTE_EMM_STATE_REG_INIT,
  LTE_EMM_STATE_REGISTERED,
  LTE_EMM_STATE_TAU_INIT,
  LTE_EMM_STATE_SVC_REQ_INIT,
  LTE_EMM_STATE_DEREGINIT,
  LTE_EMM_STATE_INVALID
}; // lte regi

enum {
  LTE_RRC_ALL = -1,
  LTE_RRC_IDLE,
  LTE_RRC_WAIT_RRC_CONFIRM,
  LTE_RRC_CONNECTED,
  LTE_RRC_RELEASING
}; // lte rrc

enum {
  NR_MODE_NULL,
  NR_MODE_NSA,
  NR_MODE_SA
}; // 5g mode

enum {
  NR_RRC_ALL = -1,
  NR_RRC_IDLE,
  NR_RRC_CONNECTED
}; // 5g rrc

enum {
  NR_UPPER_LAYER_IND_ALL = -1,
  NR_UPPER_LAYER_IND_FALSE,
  NR_UPPER_LAYER_IND_TRUE
};// 5g upper ind

enum {
  NR_SCG_ALL = -1,
  NR_SCG_RELEASE,
  NR_SCG_ADD
}; // 5g sgc

enum {
  NR_RESTRICT_DCNR_FALSE,
  NR_RESTRICT_DCNR_TRUE,
}; // 5g restrict

#endif // _WOORINET_APPLICATION_INTERFACE_HEADER_
