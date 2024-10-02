/*====*====*====*====*====*====*====*====*====*====*====*====*====*====*====*

GENERAL DESCRIPTION
  Izat Manager

  Copyright (c) 2015-2016, 2018-2021 Qualcomm Technologies, Inc.
  All Rights Reserved.
  Confidential and Proprietary - Qualcomm Technologies, Inc.
=============================================================================*/
#ifndef __IZAT_MANAGER_IZATMANAGER_H__
#define __IZAT_MANAGER_IZATMANAGER_H__

#include <set>
#include <string>
#include <comdef.h>
#include "IIzatManager.h"
#include <mq_client/IPCMessagingProxy.h>
#include "ILocationResponse.h"
#include "IzatLocation.h"
#include "IzatContext.h"
#include "IzatNmea.h"
#include "IzatSvInfo.h"
#include "IDataItemCore.h"
#include "DataItemConcreteTypes.h"
#include "ILocationAPI.h"
#include "location_interface.h"
#include "loc_misc_utils.h"
#include "ContextBase.h"
#include <LBSProxy.h>

namespace qc_loc_fw {
    class InPostcard;
}

using namespace loc_util;
using loc_core::IDataItemCore;
using loc_core::IDataItemObserver;
using loc_core::ENHDataItem;
using lbs_core::IzatProviderBase;
namespace izat_manager
{
class LocationReport;
class IZatLocationError;
class IzatManager :
    public IIzatManager,
    public IIPCMessagingResponse,
    public ILocationResponse {
public:
    static IzatManager* getInstance(IOSFramework* pOSFrameworkObj);
    static int destroyInstance();
    virtual ~IzatManager();
    void init();

    // IIzatManager overrides used by framework
    virtual int32 subscribeListener(IOSListener* osLocationListener);
    virtual int32 unsubscribeListener(IOSListener* osLocationListener);
    virtual int32 addRequest(const IzatRequest* request);
    virtual int32 removeRequest(const IzatRequest* request);
    virtual int32 enableProvider(const IzatRequest::IzatProviderType provider);
    virtual int32 disableProvider(const IzatRequest::IzatProviderType provider);

    // ILocationResponse overrides
    virtual void reportLocation(const LocationReport* report, const ILocationProvider* providerSrc = NULL);
    virtual void reportError(const IZatLocationError* error, const ILocationProvider* providerSrc = NULL);

    // IIPCMessagingResponse overrides
    virtual void handleMsg(InPostcard* const in_card);
    virtual inline MsgTask* getMsgTask() {return mIzatContext.mMsgTask;};

    // callback for LocationAPI, the first three are mandatory
    inline void onCapabilitiesCb(LocationCapabilitiesMask) {};
    inline void onResponseCb(LocationError, uint32_t) {};
    inline void onCollectiveResponseCb(size_t, LocationError*, uint32_t*) {};
    void onTrackingCb(Location locInfo);
    void registerIzatOdcpiCallback();
    void registerEsStatusCallback();
    const GnssInterface* getGnssInterface();
    void odcpiRequestCb(const OdcpiRequestInfo& odcpiRequest,
            IzatRequest::IzatProviderType provider);
    IzatRequest* createIzatReqest(const OdcpiRequestInfo& odcpiRequest,
            IzatRequest::IzatProviderType provider);
    static const std::string mConfFile;
    static const std::string mIzatConfFile;
    const GnssInterface* mGnssInterface = nullptr;
    typedef const GnssInterface* (getLocationInterface)();
    // Registers callback to get gnss enable/diablement signal
    void registerGnssStatusCallback();
    typedef void (registerGnssStatuscb)(std::function<void(bool)>);
    // notify the subscribers by loading FW_glue
    typedef void (notifyOptinStatusToSubscriberExt)(std::list<IDataItemCore*> dataItemList);
    // report emergency status
    void reportEsStatus(bool isEmergencyMode);
    void setIzatFusedProviderOverride(bool izatFused);
    bool getIzatFusedProviderOverride();

private:
    // Internal Methods
    IzatManager(IOSFramework* pOSFrameworkObj);
    int deinit();

    // used to inform NLP position session status down to ULP for ZPP purpose
    static IzatLocation izatLocationFromUlpLocation(const UlpLocation *ulpLoc,
                                                    const GpsLocationExtended* locExtended);
    void handleNLPSettingChange(bool nlpSettingsEnabled);

    void printUlpLocation(UlpLocation * ulpLocation,
                          GpsLocationExtended * locationExtended,
                          enum loc_sess_status status);
    void registerLocationAPICb();

    // Data Types
    typedef set<IOSListener*> TListenerCol;

    // Class instance
    static IzatManager* mIzatManager;

    // Data members
    const std::string mSelfName;
    const std::string mOSAgentIPCAddressName;

    loc_core::ContextBase* mContext;
    s_IzatContext mIzatContext;
    TListenerCol mListeners;
    bool mFLPProviderEnabled;
    bool mNLPProviderEnabled;
    bool mEmergencyStatus;
    IDataItemObserver *mWiper;
    // location api client to be linked with both GNSS and FLP adapter stack
    ILocationAPI* mLocAPI;
    // callbacks registered with both GNSS adapter and FLP stack
    LocationCallbacks mLocAPICb;

    // Network provider stuff
    ILocationProvider* mComboNetworkProvider;

    typedef void (setXtAdapterUserPref)(bool userPref);
    class OptInObserver : public IDataItemObserver {
        setXtAdapterUserPref* mSetUserPrefFn;
        IOsObserver* mOsObserver;
    public:
        inline OptInObserver(setXtAdapterUserPref fn, IOsObserver* osObsrvr) :
                mSetUserPrefFn(fn), mOsObserver(osObsrvr) {
            const std::list<DataItemId> dl({ENH_DATA_ITEM_ID});
            mOsObserver->subscribe(dl, this);
        }
        inline ~OptInObserver() {
            const std::list<DataItemId> dl({ENH_DATA_ITEM_ID});
            mOsObserver->unsubscribe(dl, this);
        }
        inline virtual void getName(string& name) override { name = "OptInObserver"; }
        inline virtual void notify(const std::list<IDataItemCore*>& dlist) override {
            for (auto d : dlist) {
                if (d->getId() == ENH_DATA_ITEM_ID) {
                    mSetUserPrefFn(((ENHDataItem*)d)->mEnabled);
                }
            }
        }
    };
    OptInObserver* mOptInObserver;

    // IzatProvider
    IzatProviderBase* mIzatProvider;
    struct subscribeListenerMsg : public LocMsg {
        IzatManager* mIzatManager;
        IOSListener* mListener;

        inline subscribeListenerMsg(IzatManager *mgrObj,
            IOSListener* listener)
        :mIzatManager(mgrObj), mListener(listener) {}

        virtual void proc() const;
    };

    struct unsubscribeListenerMsg : public LocMsg {
        IzatManager* mIzatManager;
        IOSListener* mListener;

        inline unsubscribeListenerMsg(IzatManager *mgrObj,
            IOSListener* listener)
        :mIzatManager(mgrObj), mListener(listener) {}

        virtual void proc() const;
    };

    struct addRemoveRequestMsg : public LocMsg {
        IzatManager* mIzatManager;
        bool         mIsAddRequest; // true: add, false: remove
        IzatRequest  mRequest;    // only valid if addRequest is true

        inline addRemoveRequestMsg(IzatManager *mgrObj, bool isAddRequest,
                const IzatRequest* request) : mIzatManager(mgrObj),
                mIsAddRequest(isAddRequest) {
                    mRequest = *request;
                }

        virtual void proc() const;
    };

    struct enableProviderMsg : public LocMsg {
        IzatManager* mIzatManager;
        IzatRequest::IzatProviderType mProvider;

        inline enableProviderMsg(IzatManager *mgrObj, IzatRequest::IzatProviderType prov)
        :mIzatManager(mgrObj)
        ,mProvider(prov) {}

        virtual void proc() const;
    };

    struct disableProviderMsg : public LocMsg {
        IzatManager* mIzatManager;
        IzatRequest::IzatProviderType mProvider;

        inline disableProviderMsg(IzatManager *mgrObj, IzatRequest::IzatProviderType prov)
        :mIzatManager(mgrObj)
        ,mProvider(prov) {}

        virtual void proc() const;
    };

    struct startPassiveLocationListenerMsg : public LocMsg {
        IzatManager *mIzatManager;
        std::string mClientName;
        IzatListenerMask mListensTo;
        bool mIntermediateFixAccepted;

        inline startPassiveLocationListenerMsg(IzatManager *mgrObj,
                                               const char *clientName,
                                               IzatListenerMask listensTo,
                                               bool intermediateFixAccepted)
            : mIzatManager(mgrObj)
            , mClientName(clientName)
            , mListensTo(listensTo)
            , mIntermediateFixAccepted(intermediateFixAccepted)
            { }

        virtual void proc() const;
    };

    struct trackingCbMsg : public LocMsg {
        IzatManager *mIzatManager;
        Location mLocation;

        inline trackingCbMsg(IzatManager *mgrObj,
                             Location &locInfo)
            : mIzatManager(mgrObj)
            , mLocation(locInfo)
            { }

        virtual void proc() const;
    };

    struct registerIzatOdcpiCallbackAsync : public LocMsg {
        IzatManager* mIzatManager;

        inline registerIzatOdcpiCallbackAsync(IzatManager *mgrObj)
        :mIzatManager(mgrObj) {}

        virtual void proc() const;
    };

    struct connectToZaxisProviderAsync : public LocMsg {
        IzatManager* mIzatManager;

        inline connectToZaxisProviderAsync(IzatManager *mgrObj)
            :mIzatManager(mgrObj) {}

        virtual void proc() const;
    };

    struct registerGnssStatusCallbackAsync : public LocMsg {
        IzatManager* mIzatManager;

        inline registerGnssStatusCallbackAsync(IzatManager *mgrObj)
        :mIzatManager(mgrObj) {}

        virtual void proc() const;
    };
};

} // namespace izat_manager

#endif // #ifndef __IZAT_MANAGER_IZATMANAGER_H__
