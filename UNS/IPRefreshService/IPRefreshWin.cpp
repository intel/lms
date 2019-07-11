/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2010-2019 Intel Corporation
 */
#include "IPRefreshService.h"
#include "Tools.h"
#include <iphlpapi.h>
#include <FuncEntryExit.h>

/* Note: could also use malloc() and free() */
#define MALLOC(x) HeapAlloc(GetProcessHeap(), 0, (x))
#define FREE(x) HeapFree(GetProcessHeap(), 0, (x))

//Main flow
bool IPRefreshService::IPRefresh(unsigned int nicType)
{
	FuncEntryExit<void> fee(L"IPRefresh");

	// Before calling IpRenewAddress we use GetInterfaceInfo to retrieve a handle to the adapter
    PIP_INTERFACE_INFO pInfo;
    pInfo = (IP_INTERFACE_INFO *) MALLOC( sizeof(IP_INTERFACE_INFO) );
	if(pInfo == NULL)
	{
		UNS_ERROR(L"IPRefresh failed - indufficient memory.\n");
		return false;
	}
    ULONG ulOutBufLen = 0;
    DWORD dwRetVal = 0;
	int adaptorID = 0;
    // Make an initial call to GetInterfaceInfo to get the necessary size into the ulOutBufLen variable
	if (GetInterfaceInfo(pInfo, &ulOutBufLen) == ERROR_INSUFFICIENT_BUFFER) {
		FREE(pInfo);
		pInfo = (IP_INTERFACE_INFO *)MALLOC(ulOutBufLen);
		if (pInfo == NULL)
		{
			UNS_ERROR(L"IPRefresh failed - indufficient memory.\n");
			return false;
		}
	}
    // Make a second call to GetInterfaceInfo to get the actual data we want
    if ((dwRetVal = GetInterfaceInfo(pInfo, &ulOutBufLen)) == NO_ERROR ) 
	{
		UNS_DEBUG(L"\tNum Adapters: %d\n", pInfo->NumAdapters);

		if (pInfo->NumAdapters ==0 ) return false;

		for (int i = 0; i < pInfo->NumAdapters; i++)
		{
			UNS_DEBUG(L"\tAdapter Name: %ws,\n", pInfo->Adapter[i].Name);
			UNS_DEBUG(L"\tAdapter Index: %d\n", pInfo->Adapter[i].Index);
		}
    }
	else if (dwRetVal == ERROR_NO_DATA)
	{
		UNS_ERROR(L"There are no network adapters with IPv4 enabled on the local system\n");
		FREE(pInfo);
		pInfo = NULL;
		return false;
	}
	else
	{
		UNS_ERROR(L"GetInterfaceInfo failed.\n");
		LPVOID lpMsgBuf;
		// to remove                
		if (FormatMessage(
			FORMAT_MESSAGE_ALLOCATE_BUFFER |
			FORMAT_MESSAGE_FROM_SYSTEM |
			FORMAT_MESSAGE_IGNORE_INSERTS,
			NULL,
			dwRetVal,
			MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), // Default language
			(LPTSTR)&lpMsgBuf,
			0,
			NULL)) {
			UNS_DEBUG(L"\tError: %C\n", lpMsgBuf);
		}
		LocalFree(lpMsgBuf);
		// to remove
		return false;
	}

    // Call IpReleaseAddress and IpRenewAddress to release and renew the IP address on the first network adapter returned by the call to GetInterfaceInfo.
    //if ((dwRetVal = IpReleaseAddress(&pInfo->Adapter[adaptorID])) == NO_ERROR) {   //  UNS_DEBUG("IP release succeeded.\n");   //}
    //else {   //  UNS_ERROR("IP release failed.\n");   //}
	
	// Populate the Adaptor ID of wired and wireless NICs
	GetAdaptorIDs();
	if (nicType == 0) adaptorID = wiredAdaptorID;
	else adaptorID = wirelessAdaptorID;
	for (int i = 0; i<pInfo->NumAdapters; i++)
	{
		if (pInfo->Adapter[i].Index != adaptorID) continue;
		if ((dwRetVal = IpRenewAddress(&pInfo->Adapter[i])) == NO_ERROR)
		{
			UNS_DEBUG(L"IP renew succeeded.\n");
			publishIPRefreshEvent(nicType == 1);
		}
		else 
		{
			UNS_ERROR(L"IP renew failed.\n");
		}
	}
    /* Free allocated memory no longer needed */
    if (pInfo) {
        FREE(pInfo);
        pInfo = NULL;
    }
	return (dwRetVal == NO_ERROR);
}

bool IPRefreshService::FillAdaptorIDs()
{
	int ret;
	// Populate the network settings			
	PIP_ADAPTER_INFO pAdapterList = NULL;
	PIP_ADAPTER_INFO pAdapter = NULL;
	ULONG ulBufLen = 0;
		
	pAdapterList = (IP_ADAPTER_INFO *) malloc(sizeof (IP_ADAPTER_INFO));
	if (pAdapterList == NULL) 
	{
		UNS_ERROR(L"GetAdaptorIDs - Can't allocate memory\n");
		return false;
	}
	if (GetAdaptersInfo(pAdapterList, &ulBufLen) == ERROR_BUFFER_OVERFLOW) 
	{
		free(pAdapterList);
		pAdapterList = (IP_ADAPTER_INFO *) malloc(ulBufLen);
		if (pAdapterList == NULL) 
		{
			UNS_ERROR(L"GetAdaptorIDs - Error allocating memory needed to call GetAdaptersinfo\n");
			return false;
		}
	}
	ret = GetAdaptersInfo(pAdapterList, &ulBufLen);
	if (ret != NO_ERROR)
	{
		UNS_ERROR(L"GetAdaptorIDs - GetAdaptersInfo failed with error: %d\n", ret);
		if (pAdapterList)
			free(pAdapterList);
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
		}
		else if (MacAddrTmp.compare(wirelessMacAddress)==0)
		{
			wirelessAdaptorID = pAdapter->Index; 
			wirelessAdaptorID_updated = true;
		}
		pAdapter = pAdapter->Next;
	}
	return true;
}