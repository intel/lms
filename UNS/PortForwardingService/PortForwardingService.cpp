/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2010-2019 Intel Corporation
 */
#include "PortForwardingService.h"

#include "ace/OS_NS_stdio.h"
#include "ace/OS_NS_string.h"
#include "ace/Event.h"

#include "global.h"

#ifdef WIN32
#include <dbt.h>
#endif // WIN32

#include "EventManagment.h"
#include "UNSEventsDefinition.h"
#include "Protocol.h"
#include "GMSExternalLogger.h"
#include "LMEConnection.h"

#include <FuncEntryExit.h>
#include <sstream>

namespace 
{
	const int DELAY_BETWEEN_CONNECT_RETRIES = 1; //Seconds
	const int MAX_CONNECT_RETRIES = 35;
}
void FlowLog(const wchar_t * pref, const wchar_t * func) 
{
	std::wstringstream ss;
	ss << pref << func;
	auto l = ss.str();
	UNS_DEBUG(L"%W\n", l.c_str());
}

void FuncEntry(const wchar_t * func) 
{
	FlowLog(L"PFWS: --> ", func);
}

void FuncExit(const wchar_t * func) 
{
	FlowLog(L"PFWS: <-- ", func);
}

void FuncExitWithStatus(const wchar_t * func, uint64_t status) 
{
	std::wstringstream ss;
	ss << L"PFWS: <-- " << func << L" Status: " << status;
	auto l = ss.str();
	UNS_DEBUG(L"%W\n", l.c_str());
}

void _SEventLogCallbackWrn(void *param, const char* message)
{
	PortForwardingService *service = (PortForwardingService *)param;

	service->AddWarningToMessageLog(message);
}

void _SEventLogCallbackDbg(void *param, const char* message)
{
	PortForwardingService *service = (PortForwardingService *)param;

	service->AddDebugToMessageLog(message);
}

#ifdef WIN32
bool _SDeviceNotifyCallBack(void *param, HDEVNOTIFY *hNotify, HANDLE drvHandle, bool regOrUnreg)
{
	PortForwardingService *father = (PortForwardingService*) param;
	// Reg
	if (regOrUnreg)
	{

		if (hNotify != NULL &&  drvHandle != INVALID_HANDLE_VALUE && drvHandle != NULL)
		{
			if (*hNotify != NULL)
			{
				father->_unregisterDeviceNotifications(*hNotify);
			}
			*hNotify = father->_registerDeviceNotifications(drvHandle);
		}
	}else //Unreg
	{
		if (hNotify != NULL && *hNotify != NULL && *hNotify != INVALID_HANDLE_VALUE && father->GetUnregisterDeviceEvents())
		{
			father->_unregisterDeviceNotifications(*hNotify);
			father->SetUnregisterDeviceEvents(false);
		}
		else{
			return false;
		}
	}
	return true;
}
#else
bool _SDeviceNotifyCallBack(void *param, HDEVNOTIFY *hNotify, HANDLE drvHandle, bool regOrUnreg)
{
	return true;
}
#endif // WIN32


void _SCloseHeciHandleCallback(void *param)
{
	PortForwardingService *service = (PortForwardingService *)param;
	
	service->CloseHeciHandle();
}

void _SNotifyHeciEnableCallback(void *param)
{
	PortForwardingService *service = (PortForwardingService *)param;
	
	service->NotifyHeciEnable();
}

class LMS_Thread_Impl : public ACE_Task<ACE_MT_SYNCH>
{

public:
	LMS_Thread_Impl(PortForwardingService *father) : m_initProtStop(1), m_father(father), m_suspended(false), m_unregisterDeviceEvents(false){}
	Protocol m_prot;
	ACE_Event m_initProtStop;
	virtual int svc()
	{
		UNS_DEBUG(L"Main LMS Thread started\n");
		ACE_Thread_Manager *mgr = this->thr_mgr();

		
		bool init = false;
		bool warningMessageWasShown = false;
		bool alreadyFailed = false;
		//Note : "Connection lost" message means "not initialized" state after initialization succeed (init==true),
		//while "Conntection failed" message means initialization just failed at the beginning

		//indicates that a connection was lost, warning will be sent after second failure (bug #214560)
		bool secondTryConnectionLost = false; 
		//indicates that a connection failed, warning will be sent after second failure (bug #214560)
		bool secondTryConnectionFailed = false; 



		Protocol::InitParameters protInitParams(_SEventLogCallbackWrn, _SEventLogCallbackDbg, _SDeviceNotifyCallBack, m_father, mgr);
		
		// even if service could not connect to LME - it should register to get HandleAceMessage
		// otherwise it could miss events, MB_STOP_SERVICE for example
		// it does early in init() or resume() methods

		int counter = 1;
		bool publishFailure = false; // if true - will cause configurator to log to event viewer

		while(1)
		{
			if (mgr->testcancel(mgr->thr_self()))
				break;
			
			if (!m_prot.IsInitialized())
			{
				if (init)
				{
					if (!m_suspended)
					{
						if (!warningMessageWasShown && !m_prot.GetLMEConnection().IsSelfDisconnect())
						{
							secondTryConnectionLost = true; //give another chance before sending the warning
							UNS_DEBUG(L"first time connection lost\n");
							m_father->BroadcastFailure(false);
						}
					}
	
					init = false;
				}

				if (m_suspended || !m_prot.Init(protInitParams))
				{

					if (!warningMessageWasShown && !m_prot.GetLMEConnection().IsSelfDisconnect()
						&& !m_suspended && !m_prot.IsClientNotFound())
					{
						if (secondTryConnectionFailed)
						{
							//this is the second failure, check which message should be shown
							if (secondTryConnectionLost)
							{
								m_father->AddWarningToMessageLog("LMS lost connection to Intel(R) MEI driver");
								UNS_DEBUG(L"second time connection lost\n");
							}
							else
							{
								m_father->AddWarningToMessageLog("LMS cannot connect to Intel(R) MEI driver");
								UNS_DEBUG(L"second time connection failed\n");
							}
							warningMessageWasShown = true;
						} 
						else
						{
							secondTryConnectionFailed = true; //give another chance before sending the warning
							UNS_DEBUG(L"first time connection failed\n");
						}
					}

					// Failed to connect to the HECI driver.
					// Sleep for a second and try again.
					ACE_Time_Value till(DELAY_BETWEEN_CONNECT_RETRIES);
					m_initProtStop.wait(&till, 0);
					
					if (!m_suspended)  //in case of suspend, the counter should not be increased nor checked. only in case of init failure.
					{
						if (counter >= MAX_CONNECT_RETRIES)
						{
							UNS_DEBUG(L"Too many failures. Will break, broadcast failure and log to Event Viewer.\n");
							publishFailure = true;
							break;
						}
						counter++;
					}

					continue;
				}

				init = true;

				counter = 1;

				// Sleep for check if lme disconnect for some reason
				ACE_Time_Value till(0, 500000);
				m_initProtStop.wait(&till, 0);


				if (warningMessageWasShown)
				{
					m_father->AddDebugToMessageLog("Port Forwarding Service connected to Intel(R) MEI driver");
					secondTryConnectionLost = secondTryConnectionFailed = false; //restart the failures count
					warningMessageWasShown = false;
				}


				UNS_DEBUG(L"Connected to HECI driver\n");
			}

			if (!m_prot.SocketsCreated())
			{
				// TBD Comment Try to create Signal socket.
				if (!m_prot.CreateSockets())
				{
					if (alreadyFailed == false)
					{
						m_father->AddWarningToMessageLog("Cannot create a network connection");
						alreadyFailed = true;
					}
					continue;
				}
			}

			m_father->BroadcastActive();

			// Select on active sockets (IANA ports and open connections).
			if (m_prot.Select() < 0) {
				m_father->BroadcastFailure(false);
				m_prot.Deinit();
			}		
		}

		m_father->BroadcastFailure(publishFailure);
		m_prot.Deinit();
		return 0;
	}

	void OnHeciDisable()
	{
		m_suspended = true;
		m_father->BroadcastFailure(false);
		m_prot.Deinit();
	}

	void OnHeciEnable() 
	{
		m_suspended = false;
	}

	bool GetUnregisterDeviceEvents()
	{
		return m_unregisterDeviceEvents;
	}

	void SetUnregisterDeviceEvents(bool unreg)
	{
		m_unregisterDeviceEvents = unreg;
	}

private:
	PortForwardingService *m_father;
	bool m_suspended;
	bool m_unregisterDeviceEvents;
};


PortForwardingService::PortForwardingService()
{
	m_lmsMainThread = NULL;
	m_needBroadcastStarted = true;
	m_needBroadcastResumed = false;
	m_needBroadcastPfwActivated = false;
}

int
PortForwardingService::init (int argc, ACE_TCHAR *argv[])
{
	UNS_DEBUG(L"PFWS: started\n");
	initSubService(argc, argv);

	m_lmsMainThread = new LMS_Thread_Impl(this);
	m_lmsMainThread->activate();

	m_mainService->SetHeciEventCB(_SCloseHeciHandleCallback, _SNotifyHeciEnableCallback, this);

	startSubService();

	return 0;
}

int
PortForwardingService::fini (void)
{
	delete m_lmsMainThread;
	UNS_DEBUG(L"PFWS: finalized\n");
	return 0;
}

int PortForwardingService::suspend() 
{
	GmsSubService::suspend();
	m_lmsMainThread->OnHeciDisable();
	m_needBroadcastResumed = true;
	UNS_DEBUG(L"PFWS: suspended\n");
	return 0;
}

int PortForwardingService::resume() 
{
	m_lmsMainThread->OnHeciEnable();
	UNS_DEBUG(L"PFWS: started resume\n");
	GmsSubService::resume();
	return 0;
}


void PortForwardingService::BroadcastActive()
{
	if (!m_needBroadcastStarted && !m_needBroadcastStarted && !m_needBroadcastPfwActivated)
	{
		return;
	}

	if (m_needBroadcastStarted)
	{
		m_needBroadcastStarted = false;
		UNS_DEBUG(L"PFWS: BroadcastActive - signalled start\n");
	}

	if (m_needBroadcastResumed)
	{
		m_needBroadcastResumed = false;
		UNS_DEBUG(L"PFWS: BroadcastActive - signalled resume\n");
	}

	if (m_needBroadcastPfwActivated)
	{
		m_needBroadcastPfwActivated = false;
		UNS_DEBUG(L"PFWS: BroadcastActive - signalled PFW activated\n");
	}

	MessageBlockPtr mbPtr(new ACE_Message_Block(), deleteMessageBlockPtr);
	mbPtr->data_block(new ACE_Data_Block());
	mbPtr->msg_type(MB_PORT_FORWARDING_STARTED);
	m_mainService->sendMessage(GMS_CONFIGURATOR, mbPtr);
}

void PortForwardingService::BroadcastFailure(bool publishFailure)
{
	UNS_DEBUG(L"PFWS: BroadcastFailure\n");

	if (m_needBroadcastPfwActivated) //When this is not the first time we fail and the flag is still on
	{
		return;
	}

	m_needBroadcastPfwActivated = true;

	MessageBlockPtr mbPtr(new ACE_Message_Block(), deleteMessageBlockPtr);
	mbPtr->data_block(new PortForwardingStoppedBlock(publishFailure));
	mbPtr->msg_type(MB_PORT_FORWARDING_STOPPED);
	m_mainService->sendMessage(GMS_CONFIGURATOR, mbPtr);
}

const ACE_TString
PortForwardingService::name()
{
	return GMS_PORTFORWARDINGSERVICE;
}


ACE_FACTORY_DEFINE (PORTFORWARDINGSERVICE, PortForwardingService)



void 
PortForwardingService::HandleAceMessage(int type, MessageBlockPtr &mbPtr)
{
	UNS_DEBUG(L"PortForwardingService::HandleAceMessage, type: %d\n", type);

	switch (type) 
	{
	case MB_STOP_SERVICE:
		OnStop();
		break;
	case MB_SUSPEND_SERVICE:
		suspendSubService();
		break;
	case MB_MEI_DISABLE_FAILED:			
		UNS_DEBUG(L"Got MEI remove failed Notification\n");
		m_lmsMainThread->OnHeciEnable();
		break;
	default:
		UNS_DEBUG(L"SubService:%s got invalid message\n", name().c_str());				
	}
}


void PortForwardingService::AddWarningToMessageLog(const char* message)
{
	GMSExternalLogger	*logger = &GMSExternalLogger::instance();
	logger->WarningLog(ACE_TEXT_CHAR_TO_TCHAR(message));
}

void PortForwardingService::AddDebugToMessageLog(const char* message)
{
	GMSExternalLogger	*logger = &GMSExternalLogger::instance();
	logger->DebugLog(ACE_TEXT_CHAR_TO_TCHAR(message));
}

void PortForwardingService::OnStop()
{
	m_lmsMainThread->SetUnregisterDeviceEvents(true);

	ACE_Thread_Manager *mng = ACE_Thread_Manager::instance();
	if (mng != NULL) {
		mng->cancel_task(m_lmsMainThread);

		m_lmsMainThread->m_prot.SignalSelect(); //causes m_lmsMainThread to get out from "select" to see it was asked to cancel
		m_lmsMainThread->m_initProtStop.signal();
		m_lmsMainThread->wait();
	}
	m_mainService->SetHeciEventCB(NULL, NULL, NULL);
	closeSubService();
}


bool PortForwardingService::GetUnregisterDeviceEvents()
{
	return m_lmsMainThread->GetUnregisterDeviceEvents();
}

void PortForwardingService::SetUnregisterDeviceEvents(bool unreg)
{
	m_lmsMainThread->SetUnregisterDeviceEvents(unreg);
}

#ifdef WIN32
HDEVNOTIFY PortForwardingService::_registerDeviceNotifications(HANDLE drvHandle)
{
	static bool alreadyLoggedFailure = false;
	HDEVNOTIFY notifyHandle = NULL;

	DEV_BROADCAST_HANDLE filter;
	memset(&filter, 0, sizeof(filter));

	filter.dbch_size = sizeof(filter);
	filter.dbch_devicetype = DBT_DEVTYP_HANDLE;
	filter.dbch_handle = drvHandle;

	SERVICE_STATUS_HANDLE& sshStatusHandle = m_mainService->GetServiceHandle();
	notifyHandle = RegisterDeviceNotification(sshStatusHandle, &filter, DEVICE_NOTIFY_SERVICE_HANDLE);
	if (notifyHandle == NULL) {
		if (!alreadyLoggedFailure) {

			UNS_DEBUG(L"failed to register LME notification\n");

			alreadyLoggedFailure = true;
		}
	}
	else {
		alreadyLoggedFailure = false;
	}
	return notifyHandle;
}

void PortForwardingService::_unregisterDeviceNotifications(HDEVNOTIFY notifyHandle)
{
	static bool alreadyLoggedFailure = false;

	if (notifyHandle != NULL) {
		if (!UnregisterDeviceNotification(notifyHandle)) {
			if (!alreadyLoggedFailure) 
			{
				UNS_DEBUG(L"failed to unregister LME notification\n");
				alreadyLoggedFailure = true;
			}
		}
		else {
			alreadyLoggedFailure = false;
		}
	}
}
#else
HDEVNOTIFY PortForwardingService::_registerDeviceNotifications(HANDLE drvHandle)
{
	return NULL;
}

void PortForwardingService::_unregisterDeviceNotifications(HDEVNOTIFY notifyHandle)
{
}
#endif // WIN32


void PortForwardingService::CloseHeciHandle()
{
	m_lmsMainThread->OnHeciDisable();
}

void PortForwardingService::NotifyHeciEnable()
{
	m_lmsMainThread->OnHeciEnable();
}
