/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2010-2020 Intel Corporation
 */
#include <sstream>

#include "IPRefreshService.h"
#include "GetLanInterfaceSettingsCommand.h"
#include "Tools.h"
#include "UNSEventsDefinition.h"

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

LMS_SUBSERVICE_DEFINE (IPREFRESHSERVICE , IPRefreshService)
	
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
			UNS_DEBUG(L"Updated Wired Mac Address successfully - MacAddress=%C\n",wiredMacAddress.c_str());
		}
		else
		{		
			wirelessMacAddress = MacAddressToString(lanSettings.MacAddress,6);
			UNS_DEBUG(L"Updated Wireless Mac Address successfully - MacAddress=%C\n",wirelessMacAddress.c_str());
		}		
		res = true;
	}
	catch (AMTHI_Client::AMTHIErrorException& e)
	{
		UNS_ERROR(L"UpdateMacAddress: GetLanInterfaceSettingsCommand failed ret=%d\n", e.getErr());
	}
	catch (MEIClientException& e)
	{
		UNS_ERROR(L"UpdateMacAddress: GetLanInterfaceSettingsCommand failed %C\n", e.what());
	}
	catch (std::exception& e)
	{
		UNS_ERROR(L"UpdateMacAddress: Exception in GetLanInterfaceSettingsCommand %C\n", e.what());
	}		
	catch(...)
	{
		UNS_ERROR(L"UpdateMacAddress: Exception in GetLanInterfaceSettingsCommand\n");
	}

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
	if ((wiredMacAddress_exisits && (!wiredAdaptorID_updated)) || (wirelessMacAddress_exisits && (!wirelessAdaptorID_updated)))
	{
		return FillAdaptorIDs();
	}
	return true;
}
