/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2010-2018 Intel Corporation
 */
#ifndef _GMS_SERVICE
#define _GMS_SERVICE

#include "ace/NT_Service.h"
#include "ace/Singleton.h"
#include "ace/Mutex.h"
#include "MessageBlockPtr.h"
#include "ace/streams.h"
#include "IServicesManager.h"
#include "ACEInitializer.h"
#include <memory>
#define ACTIVE_MESSAGEID ACE_TEXT("iAMT0080")

typedef void (*HeciEventCallBack) (void *param);

class GMS_COMMON_EXPORT GmsService :
#ifdef WIN32
	public ACE_NT_Service,
#else
	public ACE_Task<ACE_MT_SYNCH>,
#endif // WIN32
	public IServicesManager
{
public:
	GmsService(void);
	virtual ~GmsService(void);

#ifdef WIN32
	void handle_control(DWORD control_code, DWORD dwEventType=0, bool wasOnOurGUID = true);
	 /// Called by <handle_control> when a stop/shutdown was requested.
	virtual void stop_requested (DWORD control_code);

	 /// Called by <handle_control> when a pause was requested.
	virtual void pause_requested (DWORD control_code);

	 /// Called by <handle_control> when a continue was requested.
	virtual void continue_requested (DWORD control_code);

	void powerEvent_requested(DWORD control_code,DWORD dwEventType);

	 /// Called by <handle_control> when a interrogate was requested.
	virtual void interrogate_requested (DWORD control_code);
#endif // WIN32
	virtual int handle_exception(ACE_HANDLE h);
	virtual int svc(void);
	virtual int suspend();
	virtual int resume();
	int stop();

	virtual bool sendMessage(const ACE_TString  name,MessageBlockPtr mb) const;

	//implement IServicesManager
	virtual bool StartAceService(const ACE_TString &serviceName);
	virtual bool StopAceService(const ACE_TString &serviceName);
	virtual bool SuspendAceService(const ACE_TString &serviceName);
	virtual bool ResumeAceService(const ACE_TString &serviceName);
		
	void SetStop();
	void SetSuspend();
	bool GetStopped();
	bool Loading();
	void SetStopped(bool stop);
#ifdef WIN32
	void SetServiceHandle(SERVICE_STATUS_HANDLE& handle) {m_hServiceHandle = handle;}
	SERVICE_STATUS_HANDLE& GetServiceHandle() {return m_hServiceHandle;}
#endif // WIN32

	void SetHeciEventCB(HeciEventCallBack closeHeciHandle, HeciEventCallBack notifyHeciEnable, void* portForwardingService) 
	{
		m_closeHeciHandle = closeHeciHandle;
		m_notifyHeciEnable = notifyHeciEnable;
		m_portForwardingService = portForwardingService;
	}
	void CloseHeciHandle();
	void NotifyHeciEnable();

	bool GetPortForwardingStarted();
	void SetPortForwardingStarted(bool isPfwStarted);


private:
	bool stopped;
	bool loading;
#ifdef WIN32
	SERVICE_STATUS_HANDLE m_hServiceHandle;
#endif // WIN32
	HeciEventCallBack m_closeHeciHandle;
	HeciEventCallBack m_notifyHeciEnable;
	void* m_portForwardingService;
	bool m_isPortForwardingStarted;
};

typedef ACE_Unmanaged_Singleton<GmsService, ACE_Mutex> theService;

#endif // _GMS_SERVICE
