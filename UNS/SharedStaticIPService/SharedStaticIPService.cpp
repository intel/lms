/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2010-2022 Intel Corporation
 */

#include "SharedStaticIPService.h"
#include "GetLanInterfaceSettingsCommand.h"
#include "Tools.h"
#include "UNSEventsDefinition.h"
#include <ace/SString.h>
#ifdef WIN32
#include <iphlpapi.h>
#else
#include <netlink/route/addr.h>
#endif //WIN32

const ACE_TString SYNC_FW_UPDATE_FAILED(ACE_TEXT("Failed to update Intel(R) ME firmware with new network configuration"));
const ACE_TString SYNC_VALIDATION_FAILED(ACE_TEXT("Failed to verify that the new network configuration is valid and did not update the Intel(R) ME firmware with the configuration"));

// TODO Revert values to original
const unsigned long SharedStaticIPService::CheckDNSInterval = 150 * GMS_ACE_SECOND;
const unsigned long SharedStaticIPService::RetryInterval = 10 * GMS_ACE_SECOND;

const unsigned long Immediately = 0;

const unsigned int	MAX_SyncRetries = 10;

SharedStaticIPService::SSIP_Message_Block::~SSIP_Message_Block()
{}

#ifdef WIN32
void SharedStaticIPService::free_event()
{
	if (!CancelIPChangeNotify(&m_overlap))
		UNS_ERROR(L"CancelIPChangeNotify error... %d\n", WSAGetLastError());
	if (!WSACloseEvent(m_overlap.hEvent))
		UNS_ERROR(L"WSACloseEvent error... %d\n", WSAGetLastError());
}
#else
void SharedStaticIPService::free_event()
{
	nl_socket_free(m_sock);
	m_sock = NULL;
}
#endif // WIN32

ACE_HANDLE SharedStaticIPService::get_handle(void) const
{
  return m_event;
}

int SharedStaticIPService::init (int argc, ACE_TCHAR *argv[])
{
	FuncEntryExit<void> fee(this, L"init");

	int retVal = EventHandler::init(argc, argv);
	if (retVal != 0)
	{
		UNS_ERROR(L"EventHandler::init failed. retVal: %d\n", retVal);
		return retVal;
	}

	m_HandleStateRequiredButNoPfw = false;
	m_SharedStaticIP = false;
	m_SyncStaticIPStateOnce = true;
	m_SyncStaticIP = false;
	m_SyncRetries = 0;

#ifdef WIN32
	DWORD ret = 0;
	m_hand = NULL;
	m_event = m_overlap.hEvent = WSACreateEvent();
	ret = NotifyRouteChange(&m_hand, &m_overlap);
	if (ret != NO_ERROR)
	{
		int err = WSAGetLastError();
		if (err != WSA_IO_PENDING)
		{
			UNS_ERROR(L"NotifyRouteChange error... %d, SharedStaticIP will stop - failure to initialize\n", err);
			m_hand = NULL;
			free_event();
			return -1;
		}
	}
	if ((ret = ACE_Reactor::instance()->register_handler(this, m_event)) != 0)
	{
		UNS_ERROR(L"Register handler error... %d, SharedStaticIP will stop - failure to initialize\n", ret);
		int ret = 0;
		if ((ret = ACE_Reactor::instance()->remove_handler(m_event, ACE_Event_Handler::ALL_EVENTS_MASK |
																	ACE_Event_Handler::DONT_CALL)) != 0)  // Don't call handle_close
			UNS_ERROR(L"Remove handler error... %d\n", ret);
		free_event();
		return -1;
	}
#else
	int ret;

	m_sock = nl_socket_alloc();
	if (!m_sock) {
		UNS_ERROR(L"nl_socket_alloc error... %d, SharedStaticIP will stop - failure to initialize\n", errno);
		return -1;
	}
	ret = nl_connect(m_sock, NETLINK_ROUTE);
	if (ret) {
		UNS_ERROR(L"nl_connect failed %d, SharedStaticIP will stop - failure to initialize\n", ret);
		nl_socket_free(m_sock);
		m_sock = NULL;
		return -1;
	}
	nl_socket_add_memberships(m_sock, RTNLGRP_LINK,
				  RTNLGRP_IPV4_NETCONF, RTNLGRP_IPV6_NETCONF,
				  RTNLGRP_IPV4_IFADDR, RTNLGRP_IPV6_IFADDR,
				  RTNLGRP_IPV4_ROUTE, RTNLGRP_IPV6_ROUTE,
				  RTNLGRP_IPV4_MROUTE, RTNLGRP_IPV6_MROUTE,
				  RTNLGRP_IPV4_RULE, RTNLGRP_IPV6_RULE,
				  RTNLGRP_IPV6_PREFIX,
				  0);
	nl_socket_set_nonblocking(m_sock);

	m_event = nl_socket_get_fd(m_sock);
	if ((ret = ACE_Reactor::instance()->register_handler(m_event, this, ACE_Event_Handler::READ_MASK)) != 0)
	{
		UNS_ERROR(L"Register handler error...%d, SharedStaticIP will stop - failure to initialize\n", ret);
		if ((ret = ACE_Reactor::instance()->remove_handler(m_event,
		     ACE_Event_Handler::ALL_EVENTS_MASK | ACE_Event_Handler::DONT_CALL)) != 0)  // Don't call handle_close
			UNS_ERROR(L"Remove handler error... %d\n", ret);
		free_event();
		return -1;
	}
#endif // WIN32

	ACE_Time_Value interval (CheckDNSInterval);
	if (ACE_Reactor::instance()->schedule_timer(this, (void*)(SSIP_Message_Block::SSIP_STATE::GETSHAREDSTATICIPSTATE), interval, interval) == -1)
	{
		UNS_ERROR(L"failed to schedule timer first time\n");
		return -1;
	}

	//MoveToState(SSIP_Message_Block::SSIP_GETSHAREDSTATICIPSTATE, CheckDNSInterval);

	return 0;
}

int
SharedStaticIPService::fini (void)
{
	UNS_DEBUG(L"SharedStaticIP service stopped\n");
	return 0;
}


// handle close
int
SharedStaticIPService::handle_close(ACE_HANDLE, ACE_Reactor_Mask)
{
	FuncEntryExit<void> fee(this, L"handle_close");

	int ret = 0;
	if ((ret = ACE_Reactor::instance()->remove_handler(m_event, ACE_Event_Handler::ALL_EVENTS_MASK |
																ACE_Event_Handler::DONT_CALL)) != 0)  // Don't call handle_close
		UNS_ERROR(L"Remove handler error... %d\n", ret);
	free_event();
	if (ACE_Reactor::instance()->cancel_timer(this) != 1)
		UNS_ERROR(L"Cancel timer error...\n");
	this->reactor(0);
	return 0;
}

#ifdef WIN32
int
SharedStaticIPService::handle_signal (int, siginfo_t *, ucontext_t *)
{
	FuncEntryExit<void> fee(this, L"handle_signal");

	bool ret = NotifyRouteChange(&m_hand, &m_overlap); //Reset overlap
	if (ret != NO_ERROR)
	{
		int err = WSAGetLastError();
		if (err != WSA_IO_PENDING)
		{
			UNS_ERROR(L"NotifyRouteChange error...%d\n", WSAGetLastError());
			m_hand = NULL;
			return 0;
		}
	}
	MoveToState(SSIP_Message_Block::SSIP_STATE::GETSHAREDSTATICIPSTATE, Immediately);
	return 0;
}
#else
int SharedStaticIPService::handle_input(ACE_HANDLE)
{
	FuncEntryExit<void> fee(this, L"handle_input");

	nl_recvmsgs_default(m_sock);
	MoveToState(SSIP_Message_Block::SSIP_STATE::GETSHAREDSTATICIPSTATE, Immediately);
	return 0;
}
#endif // WIN32

const ACE_TString SharedStaticIPService::name()
{
	return GMS_SHAREDSTATICIPSERVICE;
}


LMS_SUBSERVICE_DEFINE (SHAREDSTATICIPSERVICE, SharedStaticIPService)

int SharedStaticIPService::handle_timeout (const ACE_Time_Value &current_time, const void *arg)
{
	FuncEntryExit<void> fee(this, L"handle_timeout");
	size_t state = (size_t)arg;
	UNS_DEBUG(L"%d\n", (ACE_UINT32_MAX & state));
	MessageBlockPtr mbPtr(new ACE_Message_Block(), deleteMessageBlockPtr);
	mbPtr->data_block(new SSIP_Message_Block((SSIP_Message_Block::SSIP_STATE) (0xFFFFFFFF & state)));
	mbPtr->msg_type(MB_TIMER_EXPIRED);
	this->putq(mbPtr->duplicate());

	return 0;
}

void SharedStaticIPService::MoveToState(SSIP_Message_Block::SSIP_STATE State, unsigned long Interval)
{
	FuncEntryExit<void> fee(this, L"MoveTo");
	UNS_DEBUG(L"%d %d\n", Interval, State);

	if (Interval == 0)
	{
		MessageBlockPtr mbPtr(new ACE_Message_Block(), deleteMessageBlockPtr);
		mbPtr->data_block(new SSIP_Message_Block(State));
		mbPtr->msg_type(MB_TIMER_EXPIRED);
		this->putq(mbPtr->duplicate());
		return ;
	}
	setTimer(Interval, State);
}


void SharedStaticIPService::HandleState(SSIP_Message_Block::SSIP_STATE State)
{
	FuncEntryExit<void> fee(this, L"HandleState");
	UNS_DEBUG(L"%d\n", State);
	bool enabled = false;
	unsigned long TimerInterval = 0;

	if (!m_mainService->GetPortForwardingStarted()) {
		UNS_DEBUG(L"%s: Error - Port Forwarding did not start yet, aborting HandleState operation. (Will perform it when gets event of EVENT_PORT_FORWARDING_SERVICE_AVAILABLE\n", name().c_str());
		m_HandleStateRequiredButNoPfw = true;
		return;
	}

	switch (State)
	{
	case SSIP_Message_Block::SSIP_STATE::GETSHAREDSTATICIPSTATE:

		if (GetSharedStaticIpState(&enabled))
		{
			MoveToState(enabled ?
								SSIP_Message_Block::SSIP_STATE::SHAREDSTATICIPSTATE_ENABLED :
								SSIP_Message_Block::SSIP_STATE::SHAREDSTATICIPSTATE_DISABLED,
						Immediately);
		}
		else
		{
			MoveToState(SSIP_Message_Block::SSIP_STATE::GETSHAREDSTATICIPSTATE, CheckDNSInterval);
		}
		break;

	case SSIP_Message_Block::SSIP_STATE::SHAREDSTATICIPSTATE_DISABLED:
		MoveToState(SSIP_Message_Block::SSIP_STATE::GETSHAREDSTATICIPSTATE, CheckDNSInterval);
		break;

	case SSIP_Message_Block::SSIP_STATE::SHAREDSTATICIPSTATE_ENABLED:

		if (!NetworkSettingsChanged())
		{
			MoveToState(SSIP_Message_Block::SSIP_STATE::SHAREDSTATICIPSTATE_ENABLED, CheckDNSInterval);
			break;
		}

		if (SyncSettings(TimerInterval))
		{
			MoveToState(SSIP_Message_Block::SSIP_STATE::SHAREDSTATICIPSTATE_ENABLED, TimerInterval);
		}
		else
		{
			MoveToState(SSIP_Message_Block::SSIP_STATE::GETSHAREDSTATICIPSTATE, CheckDNSInterval);
		}
		break;

	default:
		UNS_ERROR(L"Error state: %d\n", State);
		MoveToState(SSIP_Message_Block::SSIP_STATE::GETSHAREDSTATICIPSTATE, CheckDNSInterval);
		break;

	}
}

//Note : the return value is not used (see EventHandler::HandleAceMessage)
int SharedStaticIPService::handle_event (MessageBlockPtr mbPtr )
{
	UNS_DEBUG(L"%s::handle_event\n", name().c_str());

	int type = mbPtr->msg_type();
	switch (type)
	{
	case MB_TIMER_EXPIRED:
		{
			SSIP_Message_Block * mb = dynamic_cast<SSIP_Message_Block *>(mbPtr->data_block());
			if (mb != nullptr)
			{
				HandleState(mb->Value);
				return 1;
			}
		}
		break;
	case MB_PUBLISH_EVENT:
		{
			GMS_AlertIndication * pGMS_AlertIndication = nullptr;
			pGMS_AlertIndication = dynamic_cast<GMS_AlertIndication*>(mbPtr->data_block());
			if (pGMS_AlertIndication != nullptr)
			{
				return handlePublishEvent(*pGMS_AlertIndication);
			}
			else
			{
				ACE_ERROR_RETURN((LM_ERROR, ACE_TEXT("SharedStaticIPService::Invalid data block.\n")), -1);
			}
		}
		break;
	}

	ACE_ERROR_RETURN((LM_ERROR, ACE_TEXT("SharedStaticIPService::Invalid Message.\n")), -1);
}

int SharedStaticIPService::handlePublishEvent(const GMS_AlertIndication & alert)
{
	switch (alert.category)
	{

	case CATEGORY_UNS:
		switch (alert.id)
		{
		case EVENT_PORT_FORWARDING_SERVICE_AVAILABLE:
			UNS_DEBUG(L"%s got EVENT_PORT_FORWARDING_SERVICE_AVAILABLE. m_HandleStateRequiredButNoPfw: %d\n", name().c_str(), m_HandleStateRequiredButNoPfw);
			if (m_HandleStateRequiredButNoPfw)
			{
				m_HandleStateRequiredButNoPfw = false;
				MoveToState(SSIP_Message_Block::SSIP_STATE::GETSHAREDSTATICIPSTATE, Immediately);
				return 1;
			}
			break;
		default:
			ACE_ERROR_RETURN((LM_ERROR, ACE_TEXT("SharedStaticIPService::Invalid Message id.\n")), -1);
			break;

		}
		break;

	default:
		ACE_ERROR_RETURN((LM_ERROR, ACE_TEXT("SharedStaticIPService::Invalid Message category.\n")), -1);
		break;
	}
	return 1;
}

void
SharedStaticIPService::PreStop(int type, bool meiEnabled)
{
	this->handle_close(0, 0);
}

bool SharedStaticIPService::GetSharedStaticIpState(bool * isEnabled)
{
	FuncEntryExit<void> fee(this, L"GetSharedStaticIpState");
	if (m_syncNetData.getSharedStaticIpState(isEnabled))
	{
		m_SyncRetries = 0;
		m_SyncStaticIP = true;	// Need to sync the settings for the first time
	}

	if (m_syncNetData.m_MacAddress.empty())
	{
		if (!UpdateMacAddress())
		{
			return false;
		}
	}
	UNS_DEBUG(L"%d\n", *isEnabled);
	return true;

}

bool SharedStaticIPService::NetworkSettingsChanged()
{
	bool res = false;
	FuncEntryExit<decltype(res)> fee(this, L"NetworkSettingsChanged", res);

	//UNS_DEBUG(L"m_SharedStaticIP: %d\n", m_SharedStaticIP);

	bool isEmptyAddress = false;
	bool IPv4Enabled = false;
	bool dataChanged = false;

	if (!m_syncNetData.CheckNetworkData(dataChanged, isEmptyAddress, IPv4Enabled))
	{
		return res;
	}

	UNS_DEBUG(L"Change: %d Empty: %d IPv4: %d\n", dataChanged, isEmptyAddress, IPv4Enabled);

	if (!dataChanged)
	{
		UNS_DEBUG(L"No change\n");
		return res;
	}

	if (!IPv4Enabled)
	{
		UNS_DEBUG(L"IPv4 is disabled\n");
		return res;
	}
	if (isEmptyAddress)
	{
		UNS_DEBUG(L"IP or gateway addresses are empty\n");
		SyncValidationFailed();
		return res;
	}

	res = true;
	return res;
}

bool SharedStaticIPService::SyncSettings(unsigned long & TimerInterval)
{
	bool res = false;
	FuncEntryExit<decltype(res)> fee(this, L"SyncSettings", res);

	UNS_DEBUG(L"Need to sync network settings %d ? %d\n", m_SyncRetries, MAX_SyncRetries);
	if (m_SyncRetries < MAX_SyncRetries)
	{
		if (m_syncNetData.SyncNetworkConfiguration())
		{
			TimerInterval = CheckDNSInterval;
			m_SyncRetries = 0;
		}
		else
		{
			m_SyncRetries++;
			UNS_ERROR(L"Failed to sync network configuration %d times\n", m_SyncRetries);
			TimerInterval = RetryInterval;
			m_syncNetData.ResetSettings();
		}
		res = true;
		return res;
	}

	if (m_syncNetData.m_ValidationFailed)
	{
		UNS_ERROR(L"Failed to validate the network configuration - stop syncing after passing the MAX retries\n");
		SyncValidationFailed();
	}
	else
	{
		UNS_ERROR(L"Failed to sync network configuration - stop syncing after passing the MAX retries\n");
		SyncFwUpdateFailed();
	}

	m_syncNetData.ResetSettings();
	TimerInterval = CheckDNSInterval;
	m_SyncRetries = 0;

	return res;
}

bool SharedStaticIPService::setTimer(unsigned long Interval, SSIP_Message_Block::SSIP_STATE State)
{
	FuncEntryExit<void> fee(this, L"setTimer");
	UNS_DEBUG(L"%d %d\n", Interval, State);

	if ((ACE_Reactor::instance()->cancel_timer(this)) != 1)
	{
		UNS_ERROR(L"failed to cancel timer\n");
		return false;
	}
	ACE_Time_Value interval (Interval);
	if (ACE_Reactor::instance()->schedule_timer(this, (void*)State, interval, interval) == -1)
	{
		UNS_ERROR(L"failed to schedule timer\n");
		return false;
	}
	return true;
}

void SharedStaticIPService::SyncFwUpdateFailed()
{
	FuncEntryExit<void> fee(this, L"SyncFwUpdateFailed");

	sendAlertIndicationMessage(CATEGORY_IPSYNC, EVENT_IP_SYNC_FW_UPDATE_FAILED, SYNC_FW_UPDATE_FAILED);
}

void SharedStaticIPService::SyncValidationFailed()
{
	FuncEntryExit<void> fee(this, L"SyncValidationFailed");

	sendAlertIndicationMessage(CATEGORY_IPSYNC, EVENT_IP_SYNC_VALIDATION_FAILED, SYNC_VALIDATION_FAILED);
}

bool SharedStaticIPService::UpdateMacAddress()
{
	using namespace Intel::MEI_Client;
	bool res = false;

	FuncEntryExit<decltype(res)> fee(this, L"UpdateMacAddress", res);

	try
	{
		in_addr addr;
		AMTHI_Client::GetLanInterfaceSettingsCommand getLanInterfaceSettingsCommand(AMTHI_Client::WIRED);
		AMTHI_Client::LAN_SETTINGS lanSettings = getLanInterfaceSettingsCommand.getResponse();
		addr.s_addr = lanSettings.Ipv4Address;

		std::string wiredMacAddress = MacAddressToString(lanSettings.MacAddress,6);
		m_syncNetData.m_MacAddress.assign(wiredMacAddress);

		UNS_DEBUG(L"DhcpEnabled=%d IpAddress=%C MacAddress=%C LinkStatus=%d\n", lanSettings.DhcpEnabled, inet_ntoa(addr), m_syncNetData.m_MacAddress.c_str(), lanSettings.LinkStatus);
		res = true;
	}
	catch (std::exception& e)
	{
		UNS_ERROR(L"Exception: %C\n", e.what());
	}
	catch(...)
	{
		UNS_ERROR(L"Unknown exception\n");
	}
	return res;
}
