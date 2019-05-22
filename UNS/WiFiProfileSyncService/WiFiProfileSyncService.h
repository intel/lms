/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2018-2019 Intel Corporation
 */
#ifndef __WIFIPROFILE_SYNC_SERVICE_H_
#define __WIFIPROFILE_SYNC_SERVICE_H_
#include "EventHandler.h"
#include "WiFiProfileSyncEventFilter.h"
#include "WIFIPROFILESYNCSERVICE_export.h"
#include "WlanDefs.h"
#include "ace/Message_Block.h"

class WIFIPROFILESYNCSERVICE_Export WiFiProfileSyncService : public EventHandler
{
public:

	WiFiProfileSyncService() : m_syncRequiredButNoPfw(false), m_filter(new WiFiProfileSyncEventFilter), deferredInitTimerId_(-1), m_initNum(1), m_wlanHandle(nullptr) {}

	// ********************* ACE PART ********************************
	
	virtual int init (int argc, ACE_TCHAR *argv[]);

	virtual int fini (void);

	virtual const ACE_TString name();

	//*********************** business logic ****************************

	class WPFS_Message_Block : public ACE_Data_Block
	{
	public:
		WPFS_Message_Block() {}
		virtual ~WPFS_Message_Block() {}
		// Data members
		wlanps::INTEL_PROFILE_DATA _profileData;
	};

protected:
	virtual int handle_event (MessageBlockPtr mbPtr);

	virtual std::shared_ptr<EventsFilter> getFilter()
	{
		return m_filter;
	}

private:

	int handlePublishEvent(const GMS_AlertIndication & alert);
	void InitAndPerformSync();
	int InitWlan();
	int handle_timeout(const ACE_Time_Value &current_time, const void *arg);

	void PerformSync();

	bool m_syncRequiredButNoPfw;
	std::shared_ptr<WiFiProfileSyncEventFilter> m_filter;
	long deferredInitTimerId_;
	int m_initNum;
	HANDLE m_wlanHandle;
};

#endif /* __WIFIPROFILE_SYNC_SERVICE_H_ */