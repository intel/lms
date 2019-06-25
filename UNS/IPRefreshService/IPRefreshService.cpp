/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2010-2019 Intel Corporation
 */
#include <sstream>

#include "IPRefreshService.h"
#include "GetLanInterfaceSettingsCommand.h"
#include "Tools.h"
#include "UNSEventsDefinition.h"

#include <FuncEntryExit.h>

void FlowLog(const wchar_t * pref, const wchar_t * func)
{
	std::wstringstream ss;
	ss << pref << func;
	auto l = ss.str();
	UNS_DEBUG(L"%W\n", l.c_str());
}

void FuncEntry(const wchar_t * func)
{
	FlowLog(L"IPR: --> ", func);
}

void FuncExit(const wchar_t * func)
{
	FlowLog(L"IPR: <-- ", func);
}

void FuncExitWithStatus(const wchar_t * func, uint64_t status)
{
	std::wstringstream ss;
	ss << L"IPR: <-- " << func << L" Status: " << status;
	auto l = ss.str();
	UNS_DEBUG(L"%W\n", l.c_str());
}

const ACE_TString IPREFRESHEVENT(ACE_TEXT("IP Renew request performed for Intel(R) ME synchronization"));

int IPRefreshService::init (int argc, ACE_TCHAR *argv[])
{
	UNS_DEBUG(L"IPRefresh service started\n");
	initSubService(argc,argv);
	wiredMacAddress_exisits	= false;
	wirelessMacAddress_exisits = false;
	wiredAdaptorID_updated	= false;
	wirelessAdaptorID_updated = false;
	wiredAdaptorID		= -1;
	wirelessAdaptorID	= -1;
	startSubService();
	return 0;
}


const ACE_TString IPRefreshService::name()
{
	return GMS_IPREFRESHSERVICE;
}

ACE_FACTORY_DEFINE (IPREFRESHSERVICE , IPRefreshService)
	
/* Business logic */

void 
IPRefreshService::HandleAceMessage(int type, MessageBlockPtr &mbPtr)
{
	UNS_DEBUG(L"IPRefreshService::HandleAceMessage\n");

	switch (type) 
	{
	case MB_IPREFRESH_LAN:
		IPRefresh(0);
		break;
	case MB_IPREFRESH_WLAN:
		IPRefresh(1);	
		break;
	default:
		GmsSubService::HandleAceMessage(type, mbPtr);
	}
}

void IPRefreshService::publishIPRefreshEvent(bool wlan)
{	
	unsigned long id = wlan ? EVENT_IP_REFRESH_REQUESTED_WLAN : EVENT_IP_REFRESH_REQUESTED_LAN;

	sendAlertIndicationMessage(CATEGORY_IPSYNC, id, IPREFRESHEVENT);
}

bool IPRefreshService::GetMacAddresses(unsigned short adaptorType)
{
	using namespace Intel::MEI_Client;
	bool res = false;	
	
	try
	{
		AMTHI_Client::GetLanInterfaceSettingsCommand getLanInterfaceSettingsCommand(adaptorType); //AMTHI_Client::WIRED
		AMTHI_Client::LAN_SETTINGS lanSettings = getLanInterfaceSettingsCommand.getResponse();
	
		if (adaptorType == AMTHI_Client::WIRED)
		{
			wiredMacAddress = MacAddressToString(lanSettings.MacAddress,6);
			UNS_DEBUG(L"UpdateMacAddress successfully - MacAddress=%C\n",wiredMacAddress.c_str());
		}
		else
		{		
			wirelessMacAddress = MacAddressToString(lanSettings.MacAddress,6);
			UNS_DEBUG(L"UpdateMacAddress successfully - MacAddress=%C\n",wirelessMacAddress.c_str());
		}		
		res = true;
	}
#ifdef _DEBUG
	catch (MEIClientException& e)
	{	
		UNS_DEBUG(L"UpdateMacAddress failed\n");
		UNS_DEBUG(L"GetLanInterfaceSettingsCommand failed %C\n",e.what());
	}
	catch (AMTHI_Client::AMTHIErrorException& e)
	{
		UNS_DEBUG(L"UpdateMacAddress failed\n");
		UNS_DEBUG(L"GetLanInterfaceSettingsCommand failed ret=%d\n",e.getErr());
	}
	catch (std::exception& e)
	{
		UNS_DEBUG(L"UpdateMacAddress failed\n");
		UNS_DEBUG(L"\nException in GetLanInterfaceSettingsCommand %C\n", e.what());
	}		
#else
	catch(...){}
#endif
	return res;
}

bool IPRefreshService::GetAdaptorIDs()
{
	using namespace Intel::MEI_Client;
	if (!wiredMacAddress_exisits)
	{
		if (GetMacAddresses(AMTHI_Client::WIRED))
			wiredMacAddress_exisits = true;
	}
	if (!wirelessMacAddress_exisits)
	{
		if (GetMacAddresses(AMTHI_Client::WIRELESS))
			wirelessMacAddress_exisits = true;
	}
	if ((wiredMacAddress_exisits && (!wiredAdaptorID_updated)) || (wirelessMacAddress_exisits && (!wiredAdaptorID_updated)))
	{
		return FillAdaptorIDs();
	}
	return true;
}