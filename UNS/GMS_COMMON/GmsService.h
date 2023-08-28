/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2010-2023 Intel Corporation
 */
#ifndef _GMS_SERVICE
#define _GMS_SERVICE

#include <mutex>
#include <map>
#include "ace/NT_Service.h"
#include "ace/Mutex.h"
#include "MessageBlockPtr.h"
#include "ace/streams.h"
#include "IServicesManager.h"
#include "ACEInitializer.h"

#define ACTIVE_MESSAGEID ACE_TEXT("iAMT0080")

typedef void (*HeciEventCallBack) (void *param);

class GmsService;

typedef ACE_Unmanaged_Singleton<GmsService, ACE_Mutex> theService;

class GmsService :
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

	virtual bool sendMessage(const ACE_TString &name, const MessageBlockPtr &mb) const;

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
		std::lock_guard<std::mutex> lock(m_HECINotifyMutex);
		m_closeHeciHandle = closeHeciHandle;
		m_notifyHeciEnable = notifyHeciEnable;
		m_portForwardingService = portForwardingService;
	}
	void CloseHeciHandle();
	void NotifyHeciEnable();
	std::mutex m_HECINotifyMutex;

	unsigned int GetPortForwardingPort() const;
	void SetPortForwardingPort(unsigned int portForwardingPort);


	static GmsService* getService()
	{
		try
		{
			return theService::instance();
		}
		catch (const std::runtime_error&)
		{
			return nullptr;
		}
	}

private:
	bool stopped;
	bool loading;
#ifdef WIN32
	SERVICE_STATUS_HANDLE m_hServiceHandle;
#endif // WIN32
	HeciEventCallBack m_closeHeciHandle;
	HeciEventCallBack m_notifyHeciEnable;
	void* m_portForwardingService;
	unsigned int m_portForwardingPort;

	typedef std::map<ACE_TString, ACE_Static_Svc_Descriptor&> svc_map;
	svc_map m_svcMap;
	void initServiceMap();
};

#endif // _GMS_SERVICE
