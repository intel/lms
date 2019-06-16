/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2010-2019 Intel Corporation
 */

#include "global.h"
#include "GmsService.h"
#include "ace/Reactor.h"
#include "ace/Service_Config.h"
#include "ace/Service_Types.h"
#ifdef WIN32
#include "VerifyFile.h"
#include "StringManager.h"
#include "WindowsStringLoader.h"
#else
#include <syslog.h>
#endif // WIN32
#include "StringsDefinitions.h"

#include "servicesNames.h"
#include "EventManagment.h"
#include "GMSExternalLogger.h"
#include <sstream>

//Localized strings to load
unsigned int strings[] = {SHUTDOWN_MSG_ID,REBOOT_MSG_ID};
#define numOfStrings 2

GmsService::GmsService(void) : stopped(false), loading(false), 
#ifdef WIN32
	m_hServiceHandle(NULL),
#endif // WIN32
	m_closeHeciHandle(NULL), m_notifyHeciEnable(NULL), m_portForwardingService(NULL), m_isPortForwardingStarted(false)
{
#ifdef WIN32
	svc_status_.dwControlsAccepted=SERVICE_ACCEPT_STOP |SERVICE_ACCEPT_PAUSE_CONTINUE|SERVICE_ACCEPT_POWEREVENT|SERVICE_ACCEPT_SHUTDOWN;
#endif // WIN32
	ACE_Service_Repository *repo = ACE_Service_Repository::instance();
	if (repo == NULL)
		throw std::runtime_error("Failed to instantiate ACE_Service_Repository");
	ACE_Reactor *a_reactor = ACE_Reactor::instance();
	if (a_reactor == NULL)
		throw std::runtime_error("Failed to instantiate ACE_Reactor");
	reactor(a_reactor);
}

GmsService::~GmsService(void)
{
	reactor()->close();
}

void GmsService::CloseHeciHandle()
{
	if ((m_closeHeciHandle != NULL) && (m_portForwardingService != NULL))
	{
		m_closeHeciHandle(m_portForwardingService);
	}
}

void GmsService::NotifyHeciEnable()
{
	if ((m_notifyHeciEnable != NULL) && (m_portForwardingService != NULL))
	{
		m_notifyHeciEnable(m_portForwardingService);
	}
}

#ifdef WIN32
void GmsService::handle_control(DWORD control_code, DWORD dwEventType, bool wasOnOurGUID)
{
	UNS_DEBUG(L"GmsService::handle_control %d", L"\n", control_code);
	switch (control_code)
	{
	case SERVICE_CONTROL_SHUTDOWN:

	case SERVICE_CONTROL_STOP:

		this->stop_requested (dwEventType);
		break;
	case SERVICE_CONTROL_PAUSE:

		this->pause_requested (control_code);
		break;
	case SERVICE_CONTROL_CONTINUE:

		this->continue_requested (control_code);
		break;
	case SERVICE_CONTROL_INTERROGATE:

		this->interrogate_requested (control_code);
		break;
	case SERVICE_CONTROL_POWEREVENT:

		this->powerEvent_requested (control_code,dwEventType);
		break;
	case SERVICE_CONTROL_SESSIONCHANGE:
		if (dwEventType == WTS_SESSION_UNLOCK)
		{
			MessageBlockPtr mbPtr(new ACE_Message_Block(), deleteMessageBlockPtr);
			mbPtr->msg_type(MB_WTS_SESSION_UNLOCK);
			mbPtr->msg_priority(4);//priority higher than other messages (except stop service).
			sendMessage(GMS_CONFIGURATOR, mbPtr);
		}
		else
		{
			UNS_DEBUG(L"Unsupported event type: %d",L"\n", dwEventType);
		}
		break;
	case SERVICE_CONTROL_DEVICEEVENT:

		MessageBlockPtr mbPtr(new ACE_Message_Block(), deleteMessageBlockPtr);
		mbPtr->data_block(new DeviceEventDataBlock(dwEventType, wasOnOurGUID));
		mbPtr->msg_type(MB_DEVICE_EVENT);
		mbPtr->msg_priority(4);//priority higher than other messages (except stop service).
		sendMessage(GMS_CONFIGURATOR, mbPtr);
		break;
	}


}
void GmsService::stop_requested (DWORD dwEventType)
{
	this->stop();
}

void GmsService::pause_requested (DWORD)
{
  this->suspend ();
}


void GmsService::continue_requested (DWORD)
{
  this->resume ();
}

void GmsService::interrogate_requested (DWORD)
{
  this->report_status (0);
}

void GmsService::powerEvent_requested(DWORD ,DWORD dwEventType)
{
	switch (dwEventType)
	{
		case PBT_APMSUSPEND:
			this->suspend ();
			break;
		case PBT_APMRESUMEAUTOMATIC:
			this->resume ();
			break;
		default:
			UNS_DEBUG(L"_ServiceCtrlHandler SERVICE_CONTROL_POWEREVENT EventType=0x%X",L"\n",dwEventType);
	}
}
#endif // WIN32

int GmsService::handle_exception(ACE_HANDLE)
{
	return 0;
}

#ifdef WIN32
static inline ACE_TString serviceName2objectName(const ACE_TString &serviceName)
{
	ACE_TString serviceDll = serviceName;
	std::transform(serviceDll.begin(), serviceDll.end(), serviceDll.begin(), toupper);
	return serviceDll;
}
#else
static inline ACE_TString serviceName2objectName(const ACE_TString &serviceName)
{
	return ACE_TEXT("libLms") + serviceName + ACE_TEXT(".so");
}
#endif // WIN32

bool GmsService::StartAceService(const ACE_TString &serviceName)
{
	ACE_TString serviceDll;

	if (serviceName != FIRST_SERVICE && serviceName != LAST_SERVICE && serviceName != AMT_ENABLE_LAST_SERVICE && serviceName != WAITING_FOR_PFW_LAST_SERVICE)
	{
#ifdef WIN32
		std::wstring service(serviceName.c_str());
		if (!VerifyFile::VerifyService(service))
		{
			return false;
		}
#endif // WIN32
		serviceDll = serviceName2objectName(serviceName);
	}
	else
	{
		serviceDll = serviceName2objectName(ACE_TEXT("Configurator"));
	}
	
	ACE_TString directive;
	std::wstringstream ss;
	ss<<(unsigned long long)this;
	directive = ACE_TEXT("dynamic ") + serviceName + ACE_TEXT(" Service_Object * ") + serviceDll +
		ACE_TEXT(":_make_") + serviceName + ACE_TEXT("() \"-g ") +
		ACE_TEXT_WCHAR_TO_TCHAR(ss.str().c_str()) + ACE_TEXT("\"");

	int i=ACE_Service_Config::process_directive(directive.c_str());
	if (i==-1)
	{
		UNS_DEBUG(L"The configuration file for service: %s is not found or cannot be opened",L"\n", serviceName.c_str());
		return false;
	}
	if (i>0)
	{
		UNS_DEBUG(L"Couldn't start service: %s %d", L"\n", serviceName.c_str(), i);
		return false;
	}

	return true;
}

bool GmsService::StopAceService(const ACE_TString &serviceName)
{
	return (ACE_Service_Repository::instance()->remove(serviceName.c_str()) == 0);
}

bool GmsService::SuspendAceService(const ACE_TString &serviceName)
{
	return (ACE_Service_Repository::instance()->suspend(serviceName.c_str()) == 0);
}

bool GmsService::ResumeAceService(const ACE_TString &serviceName)
{
	return (ACE_Service_Repository::instance()->resume(serviceName.c_str()) == 0);
}

int GmsService::svc(void)
{
	int ret=0;
#ifdef WIN32
	ofstream *output_file = new ofstream("Gms.log", ios::out);
	if (output_file && output_file->rdstate() == ios::goodbit)
		ACE_LOG_MSG->msg_ostream(output_file, 1);
	ACE_LOG_MSG->open(L"lms.exe",
		ACE_Log_Msg::STDERR | ACE_Log_Msg::OSTREAM,
		0);
#else // WIN32
#ifdef _DEBUG
	unsigned long flags = ACE_Log_Msg::SYSLOG | ACE_Log_Msg::STDERR;
#else // _DEBUG
	unsigned long flags = ACE_Log_Msg::SYSLOG;
#endif // _DEBUG
	ACE_LOG_MSG->open(0, flags, 0);
	openlog("lms_svc", LOG_CONS, LOG_DAEMON);
	if (!getenv("LMS_ENABLE_DEBUG"))
	{
		u_long mask = ACE_LOG_MSG->priority_mask(ACE_Log_Msg::PROCESS);
		ACE_LOG_MSG->priority_mask(mask & ~LM_DEBUG, ACE_Log_Msg::PROCESS);
	}
#endif // WIN32

	UNS_DEBUG(L"GmsService:Starting service", L"\n");
	 
	reactor()->owner(ACE_Thread::self());
#ifdef WIN32
	//windows only********************** Dan::Need to check why and if needed
	HANDLE hUNSstarted=CreateEvent(NULL,TRUE,TRUE,L"Global\\UNSstarted");
	if (hUNSstarted==NULL)
	{
		UNS_DEBUG(L"CreateEvent UNSstarted failed, err=%d",L"\n",GetLastError());
	}
	if (!SetEvent(hUNSstarted))
	{
		UNS_DEBUG(L"SetEvent UNSstarted failed, err=%d",L"\n",GetLastError());
	}
	//*************************
#endif // WIN32
	GMSExternalLogger::instance().ServiceStart();

	
#ifdef WIN32
	if (!VerifyFile::Init())
	{
		stopped = loading = true;
		UNS_DEBUG(L"VerifyFile::Init failed, Shutting down.",L"\n");
		return 0;
	}


	UNS_DEBUG(L"loading strings",L"\n");
	WindowsStringLoader loader;
	std::vector<unsigned int> ids(strings,strings+numOfStrings);
	try
	{
		StringManager::instance()->loadStrings(loader,ids);
	}
	catch(...)
	{
		UNS_DEBUG(L"GmsService::svc - loadStrings failed, will use default strings",L"\n");
	}
#endif // WIN32


	if (!StartAceService(GMS_CONFIGURATOR))
	{
		stopped = loading = true;
		UNS_DEBUG(L"StartAceService failed, Shutting down.",L"\n");
		return 0;
	}
	

	MessageBlockPtr mbPtr(new ACE_Message_Block(), deleteMessageBlockPtr);
	mbPtr->data_block(new ChangeConfiguration());
	mbPtr->msg_type(MB_CONFIGURATION_START);
	sendMessage(GMS_CONFIGURATOR, mbPtr);

	loading = true;
	try
	{
		reactor()->run_reactor_event_loop();
	}
	catch (std::exception &e)
	{
		UNS_DEBUG(L"Exception %C", L"\n", e.what());
		SetStopped(true);
		ret = -1;
	}
	catch(...)
	{
		UNS_DEBUG(L"Exception", L"\n");
		SetStopped(true);
		ret=-1;
	}

	ACE_Service_Repository::instance()->remove(GMS_CONFIGURATOR.c_str());
	

	// Cleanly terminate connections, terminate threads.
	UNS_DEBUG(L"Shutting down", L"\n");
	return ret;
}

void GmsService::SetSuspend()
{
	UNS_DEBUG(L"GmsService::SetSuspend()", L"\n");
	SuspendAceService(GMS_CONFIGURATOR);
	reactor()->suspend_handlers();
}

void GmsService::SetStop()
{
	UNS_DEBUG(L"GmsService::SetStop()", L"\n");
	reactor()->end_reactor_event_loop();
}

bool GmsService::GetStopped()
{
	return stopped;
}

bool GmsService::Loading()
{
	return loading;
}

void GmsService::SetStopped(bool stop)
{
	stopped = stop;
}

int GmsService::suspend()
{	
	UNS_DEBUG(L"gms_suspend", L"\n");
	// we are sending a special message to configurator
	MessageBlockPtr mbPtr(new ACE_Message_Block(), deleteMessageBlockPtr);
	mbPtr->data_block(new ChangeConfiguration());
	mbPtr->msg_type(MB_CONFIGURATION_SUSPEND);
	sendMessage(GMS_CONFIGURATOR, mbPtr);
	
	UNS_DEBUG(L"end of gms_suspend", L"\n");
	return 0;
}

int GmsService::stop()
{
	UNS_DEBUG(L"GmsService::stop SIGNALLED", L"\n");
	
	// we are sending a special message to configurator
	MessageBlockPtr mbPtr(new ACE_Message_Block(), deleteMessageBlockPtr);
	mbPtr->data_block(new ChangeConfiguration());
	mbPtr->msg_type(MB_CONFIGURATION_STOP);
	sendMessage(GMS_CONFIGURATOR, mbPtr);
	return 0;
}

int GmsService::resume()
{	
	UNS_DEBUG(L"gms_resume", L"\n");

	//enable messaging inside reactor. 
	reactor()->resume_handlers();

	ResumeAceService(GMS_CONFIGURATOR);
	MessageBlockPtr mbPtr(new ACE_Message_Block(), deleteMessageBlockPtr);
	mbPtr->data_block(new ChangeConfiguration());
	mbPtr->msg_type(MB_CONFIGURATION_RESUME);
	sendMessage(GMS_CONFIGURATOR, mbPtr);


	UNS_DEBUG(L"end of gms resume", L"\n");
	
	return 0;
}

bool GmsService::sendMessage(const ACE_TString dest,MessageBlockPtr mb) const
{
	UNS_DEBUG(L"GmsService: sending message to %s", L"\n", dest.c_str());
	const ACE_Service_Type *svc_rec;
	int i=ACE_Service_Repository::instance ()->find (dest.c_str(), &svc_rec);
	if (i != 0)
	{
		if (i == -2) // the subService is suspended
		{
			UNS_DEBUG(L"The desired service is suspended", L"\n");
		}
		else
			UNS_DEBUG(L"The desired service doesn't exists", L"\n");
		
		return false;
	}

	//the subService is active
	UNS_DEBUG(L"GmsService: sending message - found destination service", L"\n");
	const ACE_Service_Type_Impl *type = svc_rec->type (); 
	if (type == 0) return false; 

	ACE_Service_Object *obj = static_cast<ACE_Service_Object *>(type->object ()); 
	ACE_Task *subServiceTask = dynamic_cast<ACE_Task*>(obj); 
	subServiceTask->putq(mb->duplicate()); 

	return true;
}

bool GmsService::GetPortForwardingStarted()
{
	return m_isPortForwardingStarted;
}

void GmsService::SetPortForwardingStarted(bool isPfwStarted)
{
	m_isPortForwardingStarted = isPfwStarted;
}
