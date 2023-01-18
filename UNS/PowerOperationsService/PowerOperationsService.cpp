/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2010-2023 Intel Corporation
 */
// PowerOperationsService.cpp : Defines the exported functions for the DLL application.

#include "PowerOperationsService.h"
#ifdef WIN32
#include <Windows.h>
#include <powrprof.h>
#include "StringManager.h"
#endif // WIN32
#include "PowerManagementCapabilitiesWsManClient.h"
#include "StringsDefinitions.h"
#include "UNSEventsDefinition.h"
#include <string>

const ACE_TString EVENT_REMOTE_GRACEFUL_SHUTDOWN_FAILED_MSG(ACE_TEXT("Remote administrator shutdown request failed with error "));
const ACE_TString EVENT_REMOTE_GRACEFUL_SHUTDOWN_SUCCEED_MSG(ACE_TEXT("Remote administrator shutdown request was executed"));
const ACE_TString EVENT_REMOTE_GRACEFUL_REBOOT_SUCCEED_MSG(ACE_TEXT("Remote administrator reboot request was executed"));
const ACE_TString EVENT_REMOTE_GRACEFUL_REBOOT_FAILED_MSG(ACE_TEXT("Remote administrator reboot request failed with error "));
const ACE_TString EVENT_REMOTE_SLEEP_FAILED_MSG(ACE_TEXT("Remote administrator sleep request failed with error "));
const ACE_TString EVENT_REMOTE_HIBERNATE_FAILED_MSG(ACE_TEXT("Remote administrator hibernate request failed with error "));

//for graceful shutdown
#ifdef DEBUG
	const unsigned int SHUTDOWN_TIMEOUT = 72000;//only for localization!!
#else
const unsigned int SHUTDOWN_TIMEOUT = 60;
#endif
const unsigned int MAX_PWR_OPR_ATTEMPTS =  3; //max attempts on ERROR_NOT_READY
const unsigned int RETRY_TIMEOUT = 30;
const ACE_TString DEFAULT_SHUTDOWN_MSG(ACE_TEXT("The remote administrator has initiated a shutdown on this computer..."));
const ACE_TString DEFAULT_REBOOT_MSG(ACE_TEXT("The remote administrator has initiated a reboot on this computer..."));

#ifdef WIN32
bool PowerOperationsService::suspendOp(bool hibernate)
{
	return SetSuspendState(hibernate, TRUE, FALSE);
}

bool PowerOperationsService::shutdownOp(bool reboot, int attempt, std::wstringstream &ss)
{
	bool ret;
	unsigned long err;

	//get privileges (do not exit in failure, since not always needed)
	//TODO -  : check when needed

	HANDLE hToken;
	TOKEN_PRIVILEGES prv;

	ret = OpenProcessToken(GetCurrentProcess(), TOKEN_ADJUST_PRIVILEGES | TOKEN_QUERY, &hToken);
	if (!ret)
	{
		UNS_ERROR(L"PowerOperationsService::initiateShutDown - OpenProcessToken failed, error %lu\n", GetLastError());
	}
	else
	{
		ret = LookupPrivilegeValue(NULL,SE_SHUTDOWN_NAME, &prv.Privileges[0].Luid);
		if (!ret)
		{
			UNS_ERROR(L"PowerOperationsService::initiateShutDown - LookupPrivilegeValue failed, error %lu\n", GetLastError());
		}
		else
		{
			prv.PrivilegeCount = 1;
			prv.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED;
			ret = AdjustTokenPrivileges(hToken, FALSE, &prv, 0, (PTOKEN_PRIVILEGES)NULL, 0);
			if (!ret)
				UNS_ERROR(L"PowerOperationsService::initiateShutDown - AdjustTokenPrivileges failed, error %lu\n", GetLastError());
		}
		CloseHandle(hToken);
	}
	//initiate shutdown/reboot
	std::wstring& msg = reboot ? m_rebootMessageStr : m_shutdownMessageStr;
	ret = InitiateSystemShutdownEx(NULL, const_cast<wchar_t*>(msg.c_str()),
					SHUTDOWN_TIMEOUT, FALSE, reboot,
					SHTDN_REASON_MAJOR_OTHER | SHTDN_REASON_MINOR_OTHER);
	if (!ret)
	{//get error code
		err = GetLastError();
		if (err == ERROR_NOT_READY && attempt < MAX_PWR_OPR_ATTEMPTS) //try MAX_PWR_OPR_ATTEMPTS times
		{
			m_retryReboot = reboot;
			m_retryAttempt = attempt + 1;
			ACE_Reactor::instance()->schedule_timer(this, NULL,
				ACE_Time_Value(RETRY_TIMEOUT), ACE_Time_Value::zero);
			return 0;
		}
		ss<<err;
		UNS_ERROR(L"remote graceful getLastError %lu\n",err);
	}
	return ret;
}

//get system's power capabilities from OS
//sleep/hibernate parameters are filled according to OS API results,
//both false if OS API fails.
void getPowerCapabilities(bool& sleep,bool& hibernate)
{
	SYSTEM_POWER_CAPABILITIES systemCaps;
	if (!GetPwrCapabilities(&systemCaps))
	{
		UNS_ERROR(L"getPowerCapabilities - GetPwrCapabilities failed with error %lu\n", GetLastError());
		sleep = hibernate = false;
	}
	//systemCaps.HiberFilePresent shows if hibernation was enabled/disabled (such as using "powercfg.exe /h off")
	//systemCaps.SystemS4 shows if hibernation is available or not because of internal reasons (such as disabling gfx driver)
	hibernate = (systemCaps.HiberFilePresent && systemCaps.SystemS4);
	sleep	  = systemCaps.SystemS3;
}
#else
#include <gio/gio.h>

bool dbusPowerIsEnabledOne(GDBusProxy *proxy, const char* op, bool &res)
{
	GVariant *ret;
	GError *error = NULL;
	char *str;

	ret = g_dbus_proxy_call_sync(proxy, op, NULL, G_DBUS_CALL_FLAGS_NONE,
				     -1, NULL, &error);
	if (!ret) {
		g_dbus_error_strip_remote_error(error);
		UNS_ERROR(L"failed to dbus_proxy_call_sync %C\n",
			 error->message);
		g_error_free(error);
		return false;
	}

	g_variant_get(ret, "(&s)", &str);

	UNS_DEBUG(L"op=%C rsp=%C\n", op, str);
	res = (std::string(str) == std::string("yes"));
	g_variant_unref(ret);
	return true;
}

bool dbusPowerIsEnabled(bool &suspend, bool &hibernate)
{
	GDBusProxy *proxy;
	bool result;

	proxy = g_dbus_proxy_new_for_bus_sync(G_BUS_TYPE_SYSTEM,
					      G_DBUS_PROXY_FLAGS_NONE,
					      NULL,
					      "org.freedesktop.login1",
					      "/org/freedesktop/login1",
					      "org.freedesktop.login1.Manager",
					      NULL, NULL);
	if (!proxy) {
		UNS_ERROR(L"can't have dbus proxy\n");
		return false;
	}

	if (!dbusPowerIsEnabledOne(proxy, "CanSuspend", suspend)) {
		result = false;
		goto disconn;
	}
	if (!dbusPowerIsEnabledOne(proxy, "CanHibernate", hibernate)) {
		result = false;
		goto disconn;
	}

	result = true;
disconn:
	g_object_unref(proxy);
	return result;
}

bool PowerOperationsService::suspendOp(bool hibernate)
{
	GDBusProxy *proxy;
	GVariant *ret;
	GError *error = NULL;
	const char *op = hibernate ? "Hibernate" : "Suspend";
	bool result;

	proxy = g_dbus_proxy_new_for_bus_sync(G_BUS_TYPE_SYSTEM,
					      G_DBUS_PROXY_FLAGS_NONE,
					      NULL,
					      "org.freedesktop.login1",
					      "/org/freedesktop/login1",
					      "org.freedesktop.login1.Manager",
					      NULL, NULL);
	if (!proxy) {
		UNS_ERROR(L"can't have dbus proxy\n");
		return false;
	}

	ret = g_dbus_proxy_call_sync(proxy, op,
				     g_variant_new ("(b)", false),
				     G_DBUS_CALL_FLAGS_NONE,
				     -1, NULL, &error);
	if (!ret) {
		g_dbus_error_strip_remote_error(error);
		UNS_ERROR(L"failed to dbus_proxy_call_sync %C\n",
			  error->message);
		g_error_free(error);
		result = false;
		goto disconn;
	}
	g_variant_unref(ret);
	result = true;
disconn:
	g_object_unref(proxy);
	return result;
}

#define USEC_PER_SEC (1000000ULL)

bool PowerOperationsService::shutdownOp(bool reboot, int attempt, std::wstringstream &ss)
{
	GDBusProxy *proxy;
	GVariant *ret;
	GError *error = NULL;

	const char *op = reboot ? "reboot" : "poweroff";
	const ACE_TString &wall = reboot ? DEFAULT_REBOOT_MSG : DEFAULT_SHUTDOWN_MSG;
	uint64_t when;
	bool show = true;
	bool result;
	struct timeval tv = {0};

	if (::gettimeofday(&tv, NULL))
	{
		UNS_ERROR(L"gettimeofday failed %d\n", errno);
		return false;
	}
	if (tv.tv_sec > (UINT64_MAX - tv.tv_usec) / USEC_PER_SEC - SHUTDOWN_TIMEOUT)
	{
		UNS_ERROR(L"Wrong timeofday %d %d\n", tv.tv_sec, tv.tv_usec);
		return false;
	}
	when = USEC_PER_SEC * tv.tv_sec + tv.tv_usec + SHUTDOWN_TIMEOUT * USEC_PER_SEC;

	proxy = g_dbus_proxy_new_for_bus_sync(G_BUS_TYPE_SYSTEM,
					      G_DBUS_PROXY_FLAGS_NONE,
					      NULL,
					      "org.freedesktop.login1",
					      "/org/freedesktop/login1",
					      "org.freedesktop.login1.Manager",
					      NULL, NULL);
	if (!proxy) {
		UNS_ERROR(L"can't have dbus proxy\n");
		return false;
	}

	ret = g_dbus_proxy_call_sync(proxy, "SetWallMessage",
				     g_variant_new ("(sb)", ACE_TEXT_ALWAYS_CHAR(wall.c_str()), show),
				     G_DBUS_CALL_FLAGS_NONE,
				     -1, NULL, &error);
	if (!ret) {
		g_dbus_error_strip_remote_error(error);
		UNS_ERROR(L"failed to dbus_proxy_call_sync %C\n",
			  error->message);
		g_error_free(error);
		result = false;
		goto disconn;
	}
	g_variant_unref(ret);

	ret = g_dbus_proxy_call_sync(proxy, "ScheduleShutdown",
				     g_variant_new ("(st)", op, when),
				     G_DBUS_CALL_FLAGS_NONE,
				     -1, NULL, &error);
	if (!ret) {
		g_dbus_error_strip_remote_error(error);
		UNS_ERROR(L"failed to dbus_proxy_call_sync %C\n",
			  error->message);
		g_error_free(error);
		result = false;
		goto disconn;
	}
	g_variant_unref(ret);
	result = true;
disconn:
	g_object_unref(proxy);
	return result;
}

void getPowerCapabilities(bool& sleep,bool& hibernate)
{
	if (!dbusPowerIsEnabled(sleep, hibernate)) {
		UNS_ERROR(L"getPowerCapabilities - dbusPowerIsEnabled failed\n");
		sleep = false;
		hibernate = false;
	}
}
#endif // WIN32

int PowerOperationsService::init (int argc, ACE_TCHAR *argv[])
{
	int retVal = EventHandler::init(argc, argv);
	if (retVal != 0)
	{
		UNS_ERROR(L"EventHandler::init failed. retVal: %d\n", retVal);
		return retVal;
	}

	m_addCapabilitiesRequiredButNoPfw = false;

	//send message to the service to start it self after init - we want to start after the handlers have started
	MessageBlockPtr mbPtr(new ACE_Message_Block(), deleteMessageBlockPtr);
	mbPtr->data_block(new ACE_Data_Block());
	mbPtr->msg_type(MB_PWR_OPR_START_EVENT);
	mbPtr->msg_priority(3);//higher than normal messages
	this->putq(mbPtr->duplicate());

	return 0;
}

int PowerOperationsService::fini (void)
{
	UNS_DEBUG(L"PowerOperationsService finalized\n");
	ACE_Reactor::instance()->cancel_timer (this);
	return 0;
}

int PowerOperationsService::suspend()
{
	ACE_Reactor::instance()->cancel_timer (this);
	return EventHandler::suspend();
}

//Note : the return value is not used (see EventHandler::HandleAceMessage)
int
PowerOperationsService::handle_event (MessageBlockPtr mbPtr )
{
	int type=mbPtr->msg_type();
	switch (type)
	{
		case MB_PWR_OPR_START_EVENT:
		{
			loadStrings();
			addPowerCapabilities();
			break;
		}
		case MB_PUBLISH_EVENT:
		{
			GMS_AlertIndication * pGMS_AlertIndication = nullptr;
			pGMS_AlertIndication = dynamic_cast<GMS_AlertIndication*>(mbPtr->data_block());
			if (pGMS_AlertIndication != nullptr)
			{

				switch (pGMS_AlertIndication->category)
				{

				case CATEGORY_REMOTE_GRACEFUL_POWER_OPERATION:
					return handleRemoteGracefulPowerEvents(*pGMS_AlertIndication);
					break;

				case CATEGORY_UNS:
					return handlePublishEvent(*pGMS_AlertIndication);
					break;

				default:
					ACE_ERROR_RETURN((LM_ERROR, ACE_TEXT("PowerOperationsService::Invalid Message category.\n")), -1);
					break;
				}
			}
			else
			{
				ACE_ERROR_RETURN((LM_ERROR, ACE_TEXT("PowerOperationsService::Invalid data block.\n")), -1);
			}
		}
		default:
			ACE_ERROR_RETURN((LM_ERROR, ACE_TEXT ("PowerOperationsService::Invalid Message.\n")), -1);
	}
	return 0;
}


int PowerOperationsService::handlePublishEvent(const GMS_AlertIndication & alert)
{
	switch (alert.id)
	{
	case EVENT_PORT_FORWARDING_SERVICE_AVAILABLE:
		UNS_DEBUG(L"%s got EVENT_PORT_FORWARDING_SERVICE_AVAILABLE. m_addCapabilitiesRequiredButNoPfw: %d\n", name().c_str(), m_addCapabilitiesRequiredButNoPfw);
		if (m_addCapabilitiesRequiredButNoPfw)
		{
			addPowerCapabilities();
			m_addCapabilitiesRequiredButNoPfw = false;
			return 1;
		}
		break;
	default:
		ACE_ERROR_RETURN((LM_ERROR, ACE_TEXT("Invalid Message id.\n")), -1);
		break;
	}
	return 0;
}


const ACE_TString
PowerOperationsService::name()
{
	return POWER_OPERATIONS_SERVICE;
}


//get localized stringsfrom StringManager
//Note : currently used only for graceful power operations
#ifdef WIN32
void PowerOperationsService::loadStrings()
{
	m_shutdownMessageStr = StringManager::instance()->getString(SHUTDOWN_MSG_ID);
	if (m_shutdownMessageStr.empty())
		m_shutdownMessageStr = ACE_TEXT_ALWAYS_WCHAR(DEFAULT_SHUTDOWN_MSG.c_str());
	m_rebootMessageStr = StringManager::instance()->getString(REBOOT_MSG_ID);
	if (m_rebootMessageStr.empty())
		m_rebootMessageStr = ACE_TEXT_ALWAYS_WCHAR(DEFAULT_REBOOT_MSG.c_str());
}
#else
void PowerOperationsService::loadStrings() {}
#endif // WIN32

void PowerOperationsService::addPowerCapabilities()
{
	if (!m_mainService->GetPortForwardingStarted()) {
		m_addCapabilitiesRequiredButNoPfw = true;
		UNS_DEBUG(L"%s: Error - Port Forwarding did not start yet, aborting addPowerCapabilities operation. (Will perform it when gets event of EVENT_PORT_FORWARDING_SERVICE_AVAILABLE\n", name().c_str());
		return;
	}
	//update graceful power capabilities
	UNS_DEBUG(L"adding graceful power operations\n");
	PowerManagementCapabilitiesClient powerManagementCapabilitiesClient;
	bool sleep,hibernate;
	getPowerCapabilities(sleep,hibernate);
	UNS_DEBUG(L"adding graceful power operations %d %d\n", sleep,hibernate);
	if (!powerManagementCapabilitiesClient.addGracefulOperations(sleep,hibernate))
	{
		UNS_ERROR(L"powerManagementCapabilitiesClient.addGracefulOperations() failed with error %lu\n",GetLastError());
		return;
	}
}

ACE_THR_FUNC_RETURN CallSetSuspendState(void* voidArgs)
{
	PowerOperationsService::CallSetSuspendStateArgs* args = (PowerOperationsService::CallSetSuspendStateArgs*)voidArgs;

	bool success = true;


	/*
	This "if" is due to a bug in WIN API - if hibernate became non functional after LMS rise,
	calling hibernate will make the system *sleep*, rather than return an error.
	Thus, we shall make sure hibernate is still supported in the system
	*/
	bool hibernate_disabled = false; // indicates whether hibernate became disabled
	if(args->hibernate){
		bool sleep, hibernate;
		getPowerCapabilities(sleep, hibernate);
		if(!hibernate){
			//if hibernate is the command requested, but the system no longer supports hibernation:
			hibernate_disabled = true;
			success = false;
		}
	}
	if (!hibernate_disabled) { //whether sleep was called, or hibernate, and hibernate is still supported
		success = args->service->suspendOp(args->hibernate);
	}

	std::string dbgMsg;
	std::string action((args->hibernate) ? "hibernate" : "sleep");

	if (!success)
	{//failed

		//debug message.

		dbgMsg = "remote " + action + " failed,";
		std::wstringstream ss;
		if(hibernate_disabled) //if the error was that hibernate no longer valid - the error.
		{
			UNS_DEBUG(L"%C  Hibernate no longer supported in the system\n", dbgMsg.c_str());
			ss<<L" ";
		}
		else
		{
			unsigned long err = GetLastError();
			UNS_ERROR(L"%C  GetLastError: %u\n", dbgMsg.c_str(), err);
			ss<<err;
		}

		//send failed event to event log
		unsigned long eventID = (args->hibernate) ?  EVENT_REMOTE_HIBERNATE_FAILED : EVENT_REMOTE_SLEEP_FAILED;
		ACE_TString msgStr = (args->hibernate) ?  EVENT_REMOTE_HIBERNATE_FAILED_MSG : EVENT_REMOTE_SLEEP_FAILED_MSG;

		//do the actual sending - if the error was that hibernate no longer valid - the error code is " ".
		GmsSubService::sendAlertIndicationMessage(CATEGORY_REMOTE_GRACEFUL_POWER_OPERATION, eventID,
			msgStr, ACE_TEXT_WCHAR_TO_TCHAR(ss.str().c_str()));
	}
	else
	{ //success

		//debug message
		dbgMsg = "remote " + action + " API call succeed";
		UNS_DEBUG(L"%C , returned %d\n",dbgMsg.c_str(),(int)success);
	}

	delete args;
	return (ACE_THR_FUNC_RETURN)success;
}

//returns 0 on success, -1 otherwise
int PowerOperationsService::handleRemoteGracefulPowerEvents(const GMS_AlertIndication &OrgEvent)
{
	switch (OrgEvent.id)
	{
		case EVENT_REMOTE_GRACEFUL_SHUTDOWN_REQUESTED:
		case EVENT_REMOTE_GRACEFUL_REBOOT_REQUESTED:
			return initiateShutDown ((OrgEvent.id==EVENT_REMOTE_GRACEFUL_REBOOT_REQUESTED),1);
			break;
		//FW blocks any request which is not supported by the capabilities
		case EVENT_REMOTE_SLEEP:
			{
				CallSetSuspendStateArgs* args = new CallSetSuspendStateArgs;
				args->hibernate = false;
				args->service = this;
				ACE_Thread::spawn(CallSetSuspendState, (void*)args);
				UNS_DEBUG(L"remote sleep thread was spawned\n");
				//_beginthread(CallSetSuspendState, 0, (void*)hibernate);
				return 0;
			}
			break;
		case EVENT_REMOTE_HIBERNATE:
			{
				CallSetSuspendStateArgs* args = new CallSetSuspendStateArgs;
				args->hibernate = true;
				args->service = this;
				ACE_Thread::spawn(CallSetSuspendState, (void*)args);
				//_beginthread(CallSetSuspendState, 0, (void*)&hibernate);
				UNS_DEBUG(L"remote hibernate thread was spawned\n");;
				return 0;
			}
			break;
		default:
			break;
	}
	return 0;
}

//returns 0 on success, -1 otherwise
int PowerOperationsService::initiateShutDown(bool reboot, int attempt)
{
	bool ret;
	ACE_TString msgStr;
	unsigned long eventID;
	std::wstringstream ss;

	ret = shutdownOp(reboot, attempt, ss);
	if (!reboot)
	{//shut down
		UNS_DEBUG(L"remote graceful shutdown, returned %d \n",(int)ret);
		if (!ret)
		{//shutdown failed
			msgStr = EVENT_REMOTE_GRACEFUL_SHUTDOWN_FAILED_MSG;
			eventID = EVENT_REMOTE_GRACEFUL_SHUTDOWN_FAILED;
		}
		else
		{//shutdown succeeded
			msgStr = EVENT_REMOTE_GRACEFUL_SHUTDOWN_SUCCEED_MSG;
			eventID = EVENT_REMOTE_GRACEFUL_SHUTDOWN_SUCCEED;
		}
	}
	else //reboot
	{
		UNS_DEBUG(L"remote graceful reboot, returned %d\n",(int)ret);
		if (!ret)
		{//reboot failed
			msgStr = EVENT_REMOTE_GRACEFUL_REBOOT_FAILED_MSG;
			eventID = EVENT_REMOTE_GRACEFUL_REBOOT_FAILED;
		}
		else
		{//reboot succeeded
			msgStr = EVENT_REMOTE_GRACEFUL_REBOOT_SUCCEED_MSG;
			eventID = EVENT_REMOTE_GRACEFUL_REBOOT_SUCCEED;
		}
	}

	//send messages
	if (!ret)
	{
		sendAlertIndicationMessage(CATEGORY_REMOTE_GRACEFUL_POWER_OPERATION, eventID,
			msgStr, ACE_TEXT_WCHAR_TO_TCHAR(ss.str().c_str()));
		return -1;
	}
	else
	{
		sendAlertIndicationMessage(CATEGORY_REMOTE_GRACEFUL_POWER_OPERATION, eventID, msgStr);
		return 0;
	}
}

int
PowerOperationsService::handle_timeout (const ACE_Time_Value &current_time,const void *arg)
{
	UNS_DEBUG(L"%s service handle timeout\n",name().c_str());

	UNS_DEBUG(L"retrying graceful power operation, reboot=%d,attempt=%d\n",m_retryReboot,m_retryAttempt);
	initiateShutDown(m_retryReboot, m_retryAttempt);

	return 0;
}

LMS_SUBSERVICE_DEFINE (POWEROPERATIONSSERVICE, PowerOperationsService)
