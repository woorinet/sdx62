/*====*====*====*====*====*====*====*====*====*====*====*====*====*====*====*
  Copyright (c) 2020-2022 Qualcomm Technologies, Inc.
  All Rights Reserved.
  Confidential and Proprietary - Qualcomm Technologies, Inc.

  Copyright (c) 2017, 2020 The Linux Foundation. All rights reserved
=============================================================================*/
#ifndef LOC_NET_IFACE_H
#define LOC_NET_IFACE_H

#include <functional>
#include <loc_pla.h>
#include <LocNetIfaceBase.h>
#include <QCMAP_Client.h>
#include <mutex>
#include <gps_extended.h>
#include "LocQmiWds.h"
#ifdef NO_UNORDERED_SET_OR_MAP
    #include <set>
    #include <map>
    #define unordered_map map
    #define unordered_set set
#else
    #include <unordered_set>
    #include <unordered_map>
#endif

using namespace std;

// Storing details of backhaul client requests
typedef unordered_set<BackhaulContext, BackhaulContext::hash> ClientBackhaulRequest;
// {ProfileHdl ->(list(client_backhaul_ctxt)} - (one to many)
// eg: 0 -> xtra-ctx;ntp-ctx, 1 -> ntrip-ctx, 2 -> supl-ctx, 3 -> es-supl-ctx
typedef unordered_map<uint32_t, ClientBackhaulRequest> ProfileHdlToBackhaulCtxtMap;
// {Client -> Profile_Hdl} (one to one)
// eg: xtra -> 0, ntp -> 0, ntrip -> 1, supl -> 2, es-supl -> 3
typedef unordered_map<string, uint32_t> ClientToProfileHdlMap;

//Timeout to wait for wds service notification from qmi
#define DS_CLIENT_SERVICE_TIMEOUT (4000)
//Max timeout for the service to come up
#define DS_CLIENT_SERVICE_TIMEOUT_TOTAL (40000)
/*Request messages the WDS client can send to the WDS service*/
typedef union {
    /*Requests the service for a list of all profiles present*/
    wds_get_profile_list_req_msg_v01 *p_get_profile_list_req;
    /*Requests the service for a profile's settings*/
    wds_get_profile_settings_req_msg_v01 *p_get_profile_settings_req;
} ds_client_req_union_type;


/*Response indications that are sent by the WDS service*/
typedef union {
    wds_get_profile_list_resp_msg_v01 *p_get_profile_list_resp;
    wds_get_profile_settings_resp_msg_v01 *p_get_profile_setting_resp;
} ds_client_resp_union_type;

/*--------------------------------------------------------------------
 *  LE platform specific implementation for LocNetIface
 *-------------------------------------------------------------------*/
class LocNetIface : public LocNetIfaceBase {

public:
    static LocNetIface* getInstance() {
        if (nullptr == mInstance) {
            mInstance = new LocNetIface;
        }
        return mInstance;
    }
private:
    /* Constructor */
    LocNetIface() :
        LocNetIfaceBase(), mQcmapClientPtr(NULL),
        mIsConnectV4V6calledOnce(false), mIsDisconnectV4V6calledOnce(false),
        mLocNetBackHaulState(LOC_NET_CONN_STATE_INVALID),
        mLocNetBackHaulType(LOC_NET_CONN_TYPE_INVALID),
        mLocNetWlanState(LOC_NET_CONN_STATE_INVALID),
        mInternetSubId(LOC_DEFAULT_SUB),
        mInternetIpType(LOC_APN_IP_IPV4),
        mInternetApnName(""),
        mSuplClientCnt(0),
        mIsRoaming(false),
        mIsMobileApEnabled(false),
        mMutex(),
        mSetRoaming(false), mLocQmiWds(LocQmiWds::getInstance()) {}
public:
    LocNetIface(LocNetIface const&) = delete;
    void operator=(LocNetIface const&) = delete;

    /* Override base class pure virtual methods */

    void subscribe(const std::list<DataItemId>& itemListToSubscribe);
    void unsubscribe(const std::list<DataItemId>& itemListToUnsubscribe);
    void unsubscribeAll();
    void requestData(const std::list<DataItemId>& itemListToRequestData);

    /* Setup WWAN backhaul via QCMAP
     * This sets up IP routes as well for any AP socket */
    bool connectBackhaul(const string& clientName,
                         bool async = true,
                         const LocSubId subId = LOC_DEFAULT_SUB,
                         const string& apn = string(),
                         const LocApnIpType ipType = LOC_APN_IP_IPV4);
    /* Disconnects the WWANbackhaul, only if it was setup by us */
    bool disconnectBackhaul(const string& clientName,
                            bool async = true,
                            const LocSubId subId = LOC_DEFAULT_SUB,
                            const string& apn = string(),
                            const LocApnIpType ipType = LOC_APN_IP_IPV4);

    /* APIs to fetch current WWAN status */
    bool isWwanConnected();
    /* APIs to fetch current Backhaul Network Interface status */
    bool isAnyBackHaulConnected();
    /* API to check if any non-metered backhaul type (eg: wifi, ethernet etc) status*/
    bool isNonMeteredBackHaulTypeConnected();
    /* API to check wwan roaming status */
    bool isWwanRoaming();
    qcmap_msgr_wwan_call_type_v01 getWwanCallType(const LocApnIpType ipType);

    recursive_mutex& getMutex(){ return mMutex; }

    /* Callback registered with QCMAP */
    void qcmapClientCallbackInternal
    (
        qmi_client_type user_handle,   /* QMI user handle. */
        unsigned int msg_id,           /* Indicator message ID. */
        void *ind_buf,                 /* Raw indication data. */
        unsigned int ind_buf_len,      /* Raw data length. */
        void *ind_cb_data              /* User callback handle. */
    );

private:
    static LocNetIface* mInstance;
    LocQmiWds* mLocQmiWds;
    /* QCMAP client handle
     * This will be set only for static sQcmapInstance. */
    QCMAP_Client* mQcmapClientPtr;

    // Keep track of backhaul client requests
    // Map of Profile Handle to Client backhaul list
    ProfileHdlToBackhaulCtxtMap mProfileHdlToBackhaulCtxt;
    // Map of Client to Profile Handle
    ClientToProfileHdlMap  mClientToProfileHdl;

    // Flag for tracking
    bool mIsConnectV4V6calledOnce;
    bool mIsDisconnectV4V6calledOnce;

    /* Internet APN, IPType and SubId configuration */
    uint32_t mInternetSubId;
    uint32_t mInternetIpType;
    string   mInternetApnName;

    /* Track if SUPL call is active */
    uint32_t mSuplClientCnt;

    /* Current connection status */
    LocNetConnState mLocNetBackHaulState;
    /* Current Backhaul type include wwan, wifi, BT, USB cradle, Ethernet etc*/
    LocNetConnType  mLocNetBackHaulType;
    /* Check wifi hardware state */
    LocNetConnState mLocNetWlanState;
    /* Roaming status */
    bool mIsRoaming;
    /* Keep track of whether EnableMobileAP is done */
    bool mIsMobileApEnabled;
    /* Flag to check if we are supposed to set roaming or not
       based on SET_ROAMING flag in gps.conf */
    bool mSetRoaming;

    // log print the details of client and profile-id details
    void printProfileListInformation();

    // Remove client from client and profile-id details map.
    // Returns true if profileHdl was cleared
    void removeClientFromInternalClientCache(string clientName, uint32_t& profileHdl,
            bool& profileHdlCleared);
    // Clean up any items if connect api call fails.
    void cleanUpForConnectApiCallfailure(string clientName);
    // functionality for disable mobile app
    bool disableMobileApInternal();

#ifdef FEATURE_DSDA_ENABLED
    bool getHandleForSuplEs(qcmap_msgr_subscription_enum_v01 qcmapSubId,
                            profile_handle_type_v01& profile_handle,
                            uint8_t esProfileIndex,
                            bool& bProfileIsInTheList);
#endif
    bool getProfileHandleForApn(const LocSubId subId, const string& apn, bool isSuplEs,
                             uint32_t& profileHandle);

    // internal implementation for connectBackhaul
    bool connectBackhaulInternal(const string& clientName,
                                 LocSubId subId = LOC_PRIMARY_SUB,
                                 const string& apn = string(),
                                 const LocApnIpType ipType = LOC_APN_IP_IPV4);
    bool disconnectBackhaulInternal(const string& clientName,
                                    LocSubId subId = LOC_PRIMARY_SUB,
                                    const string& apn = string(),
                                    const LocApnIpType ipType = LOC_APN_IP_IPV4);
    /* Private APIs to interact with QCMAP module */
    void subscribeWithQcmap();
    void unsubscribeWithQcmap();
    void handleQcmapCallback(
            qcmap_msgr_wlan_status_ind_msg_v01 &wlanStatusIndData);
    void handleQcmapCallback(
            qcmap_msgr_bring_up_wwan_ind_msg_v01 &bringUpWwanIndData);
    void handleQcmapCallback(
            qcmap_msgr_tear_down_wwan_ind_msg_v01 &teardownWwanIndData);
#ifdef FEATURE_ROAMING_BACKHAUL_STATUS_INDICATION
    void handleQcmapCallback(
            qcmap_msgr_backhaul_status_ind_msg_v01 &backhaulStatusIndData);
    void handleQcmapCallback(
            qcmap_msgr_wwan_roaming_status_ind_msg_v01 &roamingStatusIndData);
#else
    // Older Pls which does not have backhaul status and roaming status indications.
    void handleQcmapCallback(
            qcmap_msgr_station_mode_status_ind_msg_v01 &stationModeIndData);
    void handleQcmapCallback(
            qcmap_msgr_wwan_status_ind_msg_v01 &wwanStatusIndData);
#endif
    void notifyObserverForWlanStatus(bool isWlanEnabled);
    void notifyObserverForNetworkInfo(boolean isConnected, LocNetConnType connType);
    void notifyCurrentNetworkInfo(bool queryQcmap,
            LocNetConnType connType = LOC_NET_CONN_TYPE_INVALID);
    void notifyCurrentWifiHardwareState(bool queryQcmap);
#ifdef FEATURE_ROAMING_BACKHAUL_STATUS_INDICATION
    void setCurrentBackHaulStatus(qcmap_msgr_backhaul_type_enum_v01  backhaulType,
            boolean backhaulIPv4Available, boolean backhaulIPv6Available);
#endif

    /* Mutex for synchronization */
    recursive_mutex mMutex;
};

#endif /* #ifndef LOC_NET_IFACE_H */
