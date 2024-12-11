/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2024 Intel Corporation
 */
#include "FWCIRAWorkaroundService.h"
#include "UNSEventsDefinition.h"
#include "DataStorageGenerator.h"

#include "GetLanInterfaceSettingsCommand.h"
#include "OpenUserInitiatedConnectionCommand.h"
#include "GetRemoteAccessConnectionStatusCommand.h"

int FWCIRAWorkaroundService::init(int argc, ACE_TCHAR *argv[])
{
	FuncEntryExit<void> fee(this, L"init");
	int ret = initSubService(argc, argv);
	if (ret)
		return ret;

	DataStorageWrapper& ds = DSinstance();
	if (!ds.GetDataValue(FWCIRAWorkaround, timeout, true))
	{
		UNS_DEBUG(L"FWCIRAWorkaroundService::init Failed to get workaround timeout\n");
		return 0;
	}
	if (timeout < 0x01 || timeout > 0xFE)
	{
		UNS_DEBUG(L"FWCIRAWorkaroundService::init disabled, timeout 0x%x out of range\n", timeout);
		return 0;
	}

	UNS_DEBUG(L"FWCIRAWorkaroundService::init timeout 0x%x\n", timeout);
	// Start timer to have first ping immediately
	ACE_Time_Value ace_interval(timeout * GMS_ACE_MINUTE);
	ACE_Reactor::instance()->schedule_timer(this, 0, ace_interval, ace_interval);
	startSubService();
	return 0;
}

int FWCIRAWorkaroundService::fini(void)
{
	FuncEntryExit<void> fee(this, L"fini");
	ACE_Reactor::instance()->cancel_timer(this);
	return 0;
}

const ACE_TString FWCIRAWorkaroundService::name()
{
	return GMS_FWCIRAWORKAROUNDSERVICE;
}

LMS_SUBSERVICE_DEFINE (FWCIRAWORKAROUNDSERVICE, FWCIRAWorkaroundService)

void FWCIRAWorkaroundService::HandleAceMessage(int type, MessageBlockPtr &mbPtr)
{
	FuncEntryExit<void> fee(this, L"HandleAceMessage");

	switch (type)
	{
	case MB_TIMER_EXPIRED:
		CheckCIRA();
		break;
	default:
		GmsSubService::HandleAceMessage(type, mbPtr);
		break;
	}
}

int FWCIRAWorkaroundService::handle_timeout(const ACE_Time_Value &current_time, const void *arg)
{
	FuncEntryExit<void> fee(this, L"handle_timeout");

	MessageBlockPtr mbPtr(new ACE_Message_Block(), deleteMessageBlockPtr);
	mbPtr->data_block(new ACE_Data_Block());
	mbPtr->msg_type(MB_TIMER_EXPIRED);
	this->putq(mbPtr->duplicate());

	return 0;
}

int FWCIRAWorkaroundService::resume()
{
	GmsSubService::resume();
	CheckCIRA();

	return 0;
}

bool FWCIRAWorkaroundService::CheckCIRA()
{
	bool res = true;
	FuncEntryExit<decltype(res)> fee(this, L"CheckCIRA", res);

	try {
		Intel::MEI_Client::AMTHI_Client::GetRemoteAccessConnectionStatusCommand getRemoteAccessConnectionStatus;
		Intel::MEI_Client::AMTHI_Client::REMOTE_ACCESS_STATUS Status = getRemoteAccessConnectionStatus.getResponse();
		if (Status.RemoteAccessConnectionStatus == Intel::MEI_Client::AMTHI_Client::REMOTE_ACCESS_CONNECTION_STATUS_CONNECTED)
		{
			UNS_DEBUG(L"FWCIRAWorkaroundService::CheckCIRA no need - connected\n");
			return false;
		}
		if (Status.AmtNetworkConnectionStatus != Intel::MEI_Client::AMTHI_Client::AMT_NETWORK_CONNECTION_OUTSIDE_ENTERPRISE)
		{
			UNS_DEBUG(L"FWCIRAWorkaroundService::CheckCIRA no need - not out of enterprise\n");
			return false;
		}
	}
	catch (const std::exception& e)
	{
		UNS_ERROR(L"Exception in GetRemoteAccessConnectionStatusCommand %C\n", e.what());
		return false;
	}

	try {
		Intel::MEI_Client::AMTHI_Client::GetLanInterfaceSettingsCommand lasSettingWired(Intel::MEI_Client::AMTHI_Client::WIRED);
		Intel::MEI_Client::AMTHI_Client::LAN_SETTINGS responseWired = lasSettingWired.getResponse();
		Intel::MEI_Client::AMTHI_Client::GetLanInterfaceSettingsCommand lasSettingWireless(Intel::MEI_Client::AMTHI_Client::WIRELESS);
		Intel::MEI_Client::AMTHI_Client::LAN_SETTINGS responseWireless = lasSettingWireless.getResponse();

		if ((responseWired.LinkStatus != 1) && (responseWireless.LinkStatus != 1))
		{
			UNS_DEBUG(L"FWCIRAWorkaroundService::CheckCIRA no need - no valid link\n");
			return false;
		}
	}
	catch (const std::exception& e)
	{
		UNS_ERROR("Exception in GetLanInterfaceSettingsCommand %C\n", e.what());
		return false;
	}

	// restore session
	bool success_in_restore;
	try {
		Intel::MEI_Client::AMTHI_Client::OpenUserInitiatedConnectionCommand openUserInitiatedConnection;
		UNS_DEBUG(L"OpenUserInitiatedConnection opened\n");
		success_in_restore = true;
	}
	catch (const Intel::MEI_Client::AMTHI_Client::AMTHIErrorException& e)
	{
		unsigned int status = e.getErr();
		if ((status == AMT_STATUS_NOT_READY) || (status == AMT_STATUS_DATA_MISSING))
		{
			UNS_DEBUG(L"OpenUserInitiatedConnection failed, but returned status=%d\n", status);
			success_in_restore = true;
		}
		else
		{
			UNS_DEBUG(L"OpenUserInitiatedConnection failed, status=%d\n", status);
			success_in_restore = false;
		}
	}
	catch (const std::exception& e)
	{
		UNS_ERROR("Exception in OpenUserInitiatedConnection %C\n", e.what());
		success_in_restore = false;
	}

	if (success_in_restore)
	{
		sendAlertIndicationMessage(CATEGORY_GENERAL, EVENT_FWCIRAWORKAROUND_SUCCESS, ACE_TEXT(""), ACE_TEXT(""));
	}
	else
	{
		sendAlertIndicationMessage(CATEGORY_GENERAL, EVENT_FWCIRAWORKAROUND_FAILURE, ACE_TEXT(""), ACE_TEXT(""));
	}

	return success_in_restore;
}