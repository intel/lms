/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2010-2024 Intel Corporation
 */
#include "IPRefreshService.h"
#include "Tools.h"
#include <iphlpapi.h>

//Main flow
bool IPRefreshService::IPRefresh(unsigned int nicType)
{
	FuncEntryExit<void> fee(this, L"IPRefresh");

	// Before calling IpRenewAddress we use GetInterfaceInfo to retrieve a handle to the adapter
	std::unique_ptr<uint8_t[]> buf(new uint8_t[sizeof(IP_INTERFACE_INFO)]);
	PIP_INTERFACE_INFO pInfo = (IP_INTERFACE_INFO*)(buf.get());

	ULONG ulOutBufLen = 0;
	DWORD dwRetVal = 0;
	int adaptorID = 0;
	bool adaptorDHCP = false;
	// Make an initial call to GetInterfaceInfo to get the necessary size into the ulOutBufLen variable
	if (GetInterfaceInfo(pInfo, &ulOutBufLen) == ERROR_INSUFFICIENT_BUFFER)
	{
		buf.reset(new uint8_t[ulOutBufLen]);
		pInfo = (IP_INTERFACE_INFO*)(buf.get());
	}
	// Make a second call to GetInterfaceInfo to get the actual data we want
	if ((dwRetVal = GetInterfaceInfo(pInfo, &ulOutBufLen)) == NO_ERROR)
	{
		UNS_DEBUG(L"\tNum Adapters: %d\n", pInfo->NumAdapters);

		if (pInfo->NumAdapters == 0)
		{
			return false;
		}

		for (size_t i = 0; i < (size_t)pInfo->NumAdapters; i++)
		{
			UNS_DEBUG(L"\tAdapter Name: %W,\n", pInfo->Adapter[i].Name);
			UNS_DEBUG(L"\tAdapter Index: %d\n", pInfo->Adapter[i].Index);
		}
	}
	else if (dwRetVal == ERROR_NO_DATA)
	{
		UNS_ERROR(L"There are no network adapters with IPv4 enabled on the local system\n");
		return false;
	}
	else
	{
		UNS_ERROR(L"GetInterfaceInfo failed Error: %u.\n", dwRetVal);
		return false;
	}

	// Populate the Adaptor ID of wired and wireless NICs
	GetAdaptorIDs();
	if (nicType == 0)
	{
		adaptorID = wiredAdaptorID;
		adaptorDHCP = wiredAdaptorDHCP;
	}
	else
	{
		adaptorID = wirelessAdaptorID;
		adaptorDHCP = wirelessAdaptorDHCP;
	}
	for (size_t i = 0; i < (size_t)pInfo->NumAdapters; i++)
	{
		if (pInfo->Adapter[i].Index != adaptorID) continue;
		if (!adaptorDHCP)
		{
			UNS_DEBUG(L"Adapter not in DHCP mode. No renew. Adapter Index: %d\n", adaptorID);
			break;
		}
		if ((dwRetVal = IpRenewAddress(&pInfo->Adapter[i])) == NO_ERROR)
		{
			UNS_DEBUG(L"IP renew succeeded. Adapter Index: %d\n", adaptorID);
			publishIPRefreshEvent(nicType == 1);
		}
		else 
		{
			UNS_ERROR(L"IP renew failed. Adapter Index: %d Error: %u\n", adaptorID, dwRetVal);
		}
		break;
	}
	return (dwRetVal == NO_ERROR);
}

bool IPRefreshService::FillAdaptorIDs()
{
	int ret;
	// Populate the network settings			
	PIP_ADAPTER_INFO pAdapter = NULL;
	ULONG ulBufLen = 0;

	std::unique_ptr<uint8_t[]> buf(new uint8_t[sizeof(IP_ADAPTER_INFO)]);
	PIP_ADAPTER_INFO pAdapterList = (IP_ADAPTER_INFO *)(buf.get());

	if (GetAdaptersInfo(pAdapterList, &ulBufLen) == ERROR_BUFFER_OVERFLOW) 
	{
		buf.reset(new uint8_t[ulBufLen]);
		pAdapterList = (IP_ADAPTER_INFO *)(buf.get());
	}
	ret = GetAdaptersInfo(pAdapterList, &ulBufLen);
	if (ret != NO_ERROR)
	{
		UNS_ERROR(L"GetAdaptorIDs - GetAdaptersInfo failed with error: %d\n", ret);
		return false; //(ret == ERROR_NO_DATA); --> cause it happens each request and not periodic...
	}				
	// Enumerate the network adapters and check the wired one with the same MAC address of the AMT
	pAdapter = pAdapterList;
	while (pAdapter != NULL) 
	{			
		std::string MacAddrTmp = MacAddressToString(pAdapter->Address, pAdapter->AddressLength);
		if (MacAddrTmp.compare(wiredMacAddress)==0)
		{
			wiredAdaptorID = pAdapter->Index; 
			wiredAdaptorID_updated = true;
			wiredAdaptorDHCP = (pAdapter->DhcpEnabled != 0);
		}
		else if (MacAddrTmp.compare(wirelessMacAddress)==0)
		{
			wirelessAdaptorID = pAdapter->Index; 
			wirelessAdaptorID_updated = true;
			wirelessAdaptorDHCP = (pAdapter->DhcpEnabled != 0);
		}
		pAdapter = pAdapter->Next;
	}
	return true;
}