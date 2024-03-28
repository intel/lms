/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2010-2023 Intel Corporation
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
#include "version.h"
#include "StringsDefinitions.h"
#include "DataStorageGenerator.h"

#include "servicesNames.h"
#include "EventManagment.h"
#include "GMSExternalLogger.h"
#include <sstream>

#ifdef WIN32
//Localized strings to load
static unsigned int strings[] = {SHUTDOWN_MSG_ID,REBOOT_MSG_ID};
static const size_t numOfStrings = 2;
#endif // WIN32

GmsService::GmsService(void) : stopped(false), loading(false), 
#ifdef WIN32
	m_hServiceHandle(NULL),
#endif // WIN32
	m_closeHeciHandle(NULL), m_notifyHeciEnable(NULL), m_portForwardingService(NULL), m_portForwardingPort(0)
{
#ifdef WIN32
	svc_status_.dwControlsAccepted=SERVICE_ACCEPT_STOP |SERVICE_ACCEPT_PAUSE_CONTINUE|SERVICE_ACCEPT_POWEREVENT|SERVICE_ACCEPT_SHUTDOWN;
#endif // WIN32
	initServiceMap();
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
	std::lock_guard<std::mutex> lock(m_HECINotifyMutex);

	if ((m_closeHeciHandle != NULL) && (m_portForwardingService != NULL))
	{
		m_closeHeciHandle(m_portForwardingService);
	}
}

void GmsService::NotifyHeciEnable()
{
	std::lock_guard<std::mutex> lock(m_HECINotifyMutex);

	if ((m_notifyHeciEnable != NULL) && (m_portForwardingService != NULL))
	{
		m_notifyHeciEnable(m_portForwardingService);
	}
}

#ifdef WIN32
void GmsService::handle_control(DWORD control_code, DWORD dwEventType, bool wasOnOurGUID)
{
	UNS_DEBUG(L"GmsService::handle_control %d\n", control_code);
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
			UNS_DEBUG(L"Unsupported event type: %d\n", dwEventType);
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
			UNS_DEBUG(L"_ServiceCtrlHandler SERVICE_CONTROL_POWEREVENT EventType=0x%X\n",dwEventType);
	}
}
#endif // WIN32

int GmsService::handle_exception(ACE_HANDLE)
{
	return 0;
}

void GmsService::initServiceMap()
{
#define ACE_STATIC_SVC_DECLARE_ALL(_serviceName_, SERVICE_CLASS) ACE_STATIC_SVC_DECLARE(SERVICE_CLASS); \
 m_svcMap.insert({_serviceName_, ace_svc_desc_##SERVICE_CLASS})
#ifdef WIN32
#define ACE_STATIC_SVC_DECLARE_WIN32(_serviceName_, SERVICE_CLASS) ACE_STATIC_SVC_DECLARE_ALL(_serviceName_, SERVICE_CLASS);
#define ACE_STATIC_SVC_DECLARE_UNIX(_serviceName_, SERVICE_CLASS)
#else // WIN32
#define ACE_STATIC_SVC_DECLARE_WIN32(_serviceName_, SERVICE_CLASS)
#define ACE_STATIC_SVC_DECLARE_UNIX(_serviceName_, SERVICE_CLASS) ACE_STATIC_SVC_DECLARE_ALL(_serviceName_, SERVICE_CLASS);
#endif // WIN32

	ACE_STATIC_SVC_DECLARE_ALL(EVENT_MANAGER, EventManager);
	ACE_STATIC_SVC_DECLARE_ALL(WINLOG_EVENT_HANDLER, WinLogEventHandler);
	ACE_STATIC_SVC_DECLARE_ALL(GMS_CONFIGURATOR, Configurator);
	ACE_STATIC_SVC_DECLARE_WIN32(COM_EVENT_HANDLER, COMEventHandler);
	ACE_STATIC_SVC_DECLARE_WIN32(WMI_EVENT_HANDLER, WMIEventHandler);
	ACE_STATIC_SVC_DECLARE_ALL(HISTORY_EVENT_HANDLER, HistoryEventHandler);
	ACE_STATIC_SVC_DECLARE_ALL(STATUS_EVENT_HANDLER, StatusEventHandler);
	ACE_STATIC_SVC_DECLARE_ALL(GMS_SHAREDSTATICIPSERVICE, SharedStaticIPService);
	ACE_STATIC_SVC_DECLARE_WIN32(GMS_PARTIALFWUPDATESERVICE, PartialFWUpdateService);
	ACE_STATIC_SVC_DECLARE_WIN32(GMS_IPREFRESHSERVICE, IPRefreshService);
	ACE_STATIC_SVC_DECLARE_ALL(GMS_TIMESYNCSERVICE, TimeSyncService);
	ACE_STATIC_SVC_DECLARE_ALL(GMS_PORTFORWARDINGSERVICE, PortForwardingService);
	ACE_STATIC_SVC_DECLARE_ALL(GMS_HOSTCHANGESNOTIFICATIONSERVICE, HostChangesNotificationService);
	ACE_STATIC_SVC_DECLARE_ALL(POWER_OPERATIONS_SERVICE, PowerOperationsService);
	ACE_STATIC_SVC_DECLARE_UNIX(GMS_DBUSSERVICE, DBusService);
	ACE_STATIC_SVC_DECLARE_WIN32(GMS_WIFIPROFILESYNCSERVICE, WiFiProfileSyncService);
	ACE_STATIC_SVC_DECLARE_UNIX(GMS_WATCHDOGSERVICE, WatchdogService);
	ACE_STATIC_SVC_DECLARE_ALL(FIRST_SERVICE, FirstService);
	ACE_STATIC_SVC_DECLARE_ALL(LAST_SERVICE, LastService);
	ACE_STATIC_SVC_DECLARE_ALL(AMT_ENABLE_LAST_SERVICE, AmtEnableLastService);
	ACE_STATIC_SVC_DECLARE_ALL(WAITING_FOR_PFW_LAST_SERVICE, WaitingForPfwLastService);
#undef ACE_STATIC_SVC_DECLARE_ALL
#undef ACE_STATIC_SVC_DECLARE_WIN32
#undef ACE_STATIC_SVC_DECLARE_LINUX
}

bool GmsService::StartAceService(const ACE_TString &serviceName)
{
	UNS_DEBUG(L"Starting: %s\n", serviceName.c_str());
	auto svc = m_svcMap.find(serviceName);
	if (svc == m_svcMap.end())
	{
		UNS_ERROR(L"The service: %s is not found\n", serviceName.c_str());
		return false;
	}
	int i = ACE_Service_Config::process_directive(svc->second);
	if (i == -1)
	{
		UNS_ERROR(L"The configuration file for service: %s is not found or cannot be opened\n", serviceName.c_str());
		return false;
	}
	if (i > 0)
	{
		UNS_ERROR(L"Couldn't prepare service: %s %d\n", serviceName.c_str(), i);
		return false;
	}
	i = ACE_Service_Config::initialize(serviceName.c_str(), NULL);
	if (i > 0)
	{
		UNS_ERROR(L"Couldn't initialize service: %s %d\n", serviceName.c_str(), i);
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
	try
	{
		ofstream *output_file = new ofstream("Gms.log", ios::out);
		if (output_file && output_file->rdstate() == ios::goodbit)
			ACE_LOG_MSG->msg_ostream(output_file, 1);
		ACE_LOG_MSG->open(L"lms.exe",
			ACE_Log_Msg::STDERR | ACE_Log_Msg::OSTREAM,
			0);
	}
	catch (const std::exception&)
	{
		ACE_LOG_MSG->open(L"lms.exe", ACE_Log_Msg::STDERR, 0);
		UNS_ERROR("Failed to configure logger file\n");
	}
#else // WIN32
#ifdef _DEBUG
	unsigned long flags = ACE_Log_Msg::SYSLOG | ACE_Log_Msg::STDERR;
#else // _DEBUG
	unsigned long flags = ACE_Log_Msg::SYSLOG;
#endif // _DEBUG
	ACE_LOG_MSG->open(0, flags, 0);
	openlog("lms_svc", LOG_CONS, LOG_DAEMON);
#endif // WIN32

	u_long mask = ACE_LOG_MSG->priority_mask(ACE_Log_Msg::PROCESS);

#ifdef WIN32
	u_long requiredLoggingMask = mask & ~LM_TRACE; // Default Logging value is Debug
#else // WIN32
	u_long requiredLoggingMask = mask & ~LM_TRACE & ~LM_DEBUG; // Default Logging value is Warning
#endif // WIN32

	DataStorageWrapper& ds = DSinstance();
	unsigned long severity = 2; //LMS_DEBUG
	if (ds.GetDataValue(LMSLoggingSeverity, severity, true))
	{
		UNS_DEBUG(L"Logging Severity from Registry: %d\n", severity);
		switch (severity)
		{
		case 1: //LMS_TRACE
			requiredLoggingMask = mask;
			break;
		case 2: //LMS_DEBUG
			requiredLoggingMask = mask & ~LM_TRACE;
			break;
		case 3: //LMS_WARNING
			requiredLoggingMask = mask & ~LM_TRACE & ~LM_DEBUG;
			break;
		case 4: //LMS_ERROR
			requiredLoggingMask = mask & ~LM_TRACE & ~LM_DEBUG & ~LM_WARNING;
			break;
		case 5: //LMS_CRITICAL
			requiredLoggingMask = mask & ~LM_TRACE & ~LM_DEBUG & ~LM_WARNING & ~LM_ERROR;
			break;
		default:
			break;
		}
	}
	ACE_LOG_MSG->priority_mask(requiredLoggingMask, ACE_Log_Msg::PROCESS);
#ifdef WIN32
	capture_log_msg_attributes();
#endif // WIN32
	UNS_DEBUG(L"GmsService:Starting service\n");
	UNS_DEBUG(L"LMS Version: %d.%d.%d.%d\n", MAJOR_VERSION, MINOR_VERSION, QUICK_FIX_NUMBER, VER_BUILD);
	 
	reactor()->owner(ACE_Thread::self());

	GMSExternalLogger::instance().ServiceStart();

#ifdef WIN32
	if (!VerifyFile::Init())
	{
		stopped = loading = true;
		UNS_ERROR(L"VerifyFile::Init failed, Shutting down.\n");
		return 0;
	}

	UNS_DEBUG(L"loading strings\n");
	try
	{
		WindowsStringLoader loader;
		std::vector<unsigned int> ids(strings, strings + numOfStrings);
		StringManager::instance()->loadStrings(loader,ids);
	}
	catch(...)
	{
		UNS_ERROR(L"GmsService::svc - loadStrings failed, will use default strings\n");
	}
#endif // WIN32

	if (!StartAceService(GMS_CONFIGURATOR))
	{
		stopped = loading = true;
		UNS_ERROR(L"StartAceService failed, Shutting down.\n");
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
		UNS_ERROR(L"Exception %C\n", e.what());
		SetStopped(true);
		ret = -1;
	}
	catch(...)
	{
		UNS_ERROR(L"Exception\n");
		SetStopped(true);
		ret=-1;
	}

	ACE_Service_Repository::instance()->remove(GMS_CONFIGURATOR.c_str());

	// Cleanly terminate connections, terminate threads.
	UNS_DEBUG(L"Shutting down\n");
	return ret;
}

void GmsService::SetSuspend()
{
	UNS_DEBUG(L"GmsService::SetSuspend()\n");
	SuspendAceService(GMS_CONFIGURATOR);
	reactor()->suspend_handlers();
}

void GmsService::SetStop()
{
	UNS_DEBUG(L"GmsService::SetStop()\n");
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
	UNS_DEBUG(L"gms_suspend\n");
	// we are sending a special message to configurator
	MessageBlockPtr mbPtr(new ACE_Message_Block(), deleteMessageBlockPtr);
	mbPtr->data_block(new ChangeConfiguration());
	mbPtr->msg_type(MB_CONFIGURATION_SUSPEND);
	sendMessage(GMS_CONFIGURATOR, mbPtr);
	
	UNS_DEBUG(L"end of gms_suspend\n");
	return 0;
}

int GmsService::stop()
{
	UNS_DEBUG(L"GmsService::stop SIGNALLED\n");
	
	// we are sending a special message to configurator
	MessageBlockPtr mbPtr(new ACE_Message_Block(), deleteMessageBlockPtr);
	mbPtr->data_block(new ChangeConfiguration());
	mbPtr->msg_type(MB_CONFIGURATION_STOP);
	sendMessage(GMS_CONFIGURATOR, mbPtr);
	return 0;
}

int GmsService::resume()
{	
	UNS_DEBUG(L"gms_resume\n");

	//enable messaging inside reactor. 
	reactor()->resume_handlers();

	ResumeAceService(GMS_CONFIGURATOR);
	MessageBlockPtr mbPtr(new ACE_Message_Block(), deleteMessageBlockPtr);
	mbPtr->data_block(new ChangeConfiguration());
	mbPtr->msg_type(MB_CONFIGURATION_RESUME);
	sendMessage(GMS_CONFIGURATOR, mbPtr);


	UNS_DEBUG(L"end of gms resume\n");
	
	return 0;
}

bool GmsService::sendMessage(const ACE_TString &dest, const MessageBlockPtr &mb) const
{
	UNS_DEBUG(L"GmsService: sending message to %s\n", dest.c_str());
	const ACE_Service_Type *svc_rec;
	int i=ACE_Service_Repository::instance ()->find (dest.c_str(), &svc_rec);
	if (i != 0)
	{
		if (i == -2) // the subService is suspended
		{
			UNS_DEBUG(L"The desired service is suspended\n");
		}
		else
			UNS_ERROR(L"The desired service doesn't exists\n");
		
		return false;
	}

	//the subService is active
	UNS_DEBUG(L"GmsService: sending message - found destination service\n");
	const ACE_Service_Type_Impl *type = svc_rec->type (); 
	if (type == 0) return false; 

	ACE_Service_Object *obj = static_cast<ACE_Service_Object *>(type->object ()); 
	ACE_Task *subServiceTask = dynamic_cast<ACE_Task*>(obj);
	if (subServiceTask == nullptr)
	{
		UNS_ERROR(L"GmsService: sending message - Object is not an ACE_Task\n");
		return false;
	}
	subServiceTask->putq(mb->duplicate()); 

	return true;
}

unsigned int GmsService::GetPortForwardingPort() const
{
	return m_portForwardingPort;
}

void GmsService::SetPortForwardingPort(unsigned int portForwardingPort)
{
	m_portForwardingPort = portForwardingPort;
}
