/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2009-2020 Intel Corporation
 */
/*++

@file: SyncNetworkDataWin32.cpp

--*/

#include <winsock2.h>
#include <iphlpapi.h>
#include "global.h"
#include "SyncNetworkData.h"
#include "Tools.h"

// Check if the DNS values changed and update the latest ones
bool SyncNetworkData::ValidateLinkStatus()
{
	/* Variables used by GetIpAddrTable */
	PMIB_IPADDRTABLE pIPAddrTable = NULL;
	DWORD ret, dwSize = 0;
	bool res = false;

	FuncEntryExit<decltype(res)> fee(this, L"ValidateLinkStatus", res);
	// Before calling AddIPAddress we use GetIpAddrTable to get an adapter to which we can add the IP.
	pIPAddrTable = (MIB_IPADDRTABLE *) malloc(sizeof (MIB_IPADDRTABLE));
	if (pIPAddrTable == NULL) {
		UNS_ERROR(L"malloc 1 failed\n");
		return res;
	}
	if (pIPAddrTable) {
		// Make an initial call to GetIpAddrTable to get the necessary size into the dwSize variable
		if (GetIpAddrTable(pIPAddrTable, &dwSize, 0) == ERROR_INSUFFICIENT_BUFFER) 
		{
			free(pIPAddrTable);
			pIPAddrTable = (MIB_IPADDRTABLE *) malloc(dwSize);
			if (pIPAddrTable == NULL) {
				UNS_ERROR(L"malloc 2 failed\n");
				return res;
			}
		}
	}
	
	for (int trialsCounter=1 ; trialsCounter<=3 ; trialsCounter++)
	{
		Sleep(1000); // otherwise, GetIpAddrTable function will not achieve all the adapters. (in case of Symc IP and changing the IP address of the adapter, the API will not avhieve the updated adapter. Bug 1304805284)
	
		UNS_DEBUG(L"Trial # %d\n", trialsCounter);

		memset(pIPAddrTable, 0x0, dwSize);
		// Make a second call to GetIpAddrTable to get the actual data we want
		if ( (ret = GetIpAddrTable( pIPAddrTable, &dwSize, 0 )) != NO_ERROR ) { 
			UNS_ERROR(L"GetIpAddrTable failed with error %d\n", ret);
			free(pIPAddrTable);
			return res;
		}

		UNS_DEBUG(L"Num Entries: %d\n", pIPAddrTable->dwNumEntries);
		for (int i=0; i < (int) pIPAddrTable->dwNumEntries; i++) {

			UNS_DEBUG(L"Interface Index[%d]:\t%d %d\n", i, pIPAddrTable->table[i].dwIndex, m_NICindex);
			UNS_DEBUG(L"Type: %u\n", pIPAddrTable->table[i].wType);

			if (pIPAddrTable->table[i].dwIndex != m_NICindex)
				continue;	

			if (pIPAddrTable->table[i].wType & (MIB_IPADDR_PRIMARY|MIB_IPADDR_DYNAMIC))
			{			
				res = true;
				UNS_DEBUG(L"Address is on Primary or Dynamic interface\n");
			}

			if (pIPAddrTable->table[i].wType & MIB_IPADDR_DISCONNECTED)
			{
				res = false;
				UNS_DEBUG(L"Address is on disconected interface\n");
			}
			else if (pIPAddrTable->table[i].wType & MIB_IPADDR_DELETED)
			{
				res = false;
				UNS_DEBUG(L"Address is deleted\n");
			}
			goto end;
		}
	}

end:
	if (pIPAddrTable) 
	{
		free(pIPAddrTable);
		pIPAddrTable = NULL;
	}
	return res;

}

// Check if there were changes in the DNS settings
bool SyncNetworkData::SyncDNSData()
{	
	IP_PER_ADAPTER_INFO* pPerAdapterInfo = NULL;
	ULONG ulBufLen = 0;
	DWORD err = ERROR_SUCCESS;
	bool res = false;

	FuncEntryExit<decltype(res)> fee(this, L"SyncDNSData", res);

	err = GetPerAdapterInfo(m_NICindex, pPerAdapterInfo, &ulBufLen);
	if (err == ERROR_BUFFER_OVERFLOW) 
	{
		pPerAdapterInfo = (IP_PER_ADAPTER_INFO*)HeapAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY, ulBufLen);
		err = GetPerAdapterInfo(m_NICindex, pPerAdapterInfo, &ulBufLen);
	}

	if (pPerAdapterInfo == NULL) 
	{
		UNS_ERROR(L"Can't allocate memory on heap for DNS server list (%d bytes): EnumDnsServers\n", ulBufLen);
		return res;
	}

	IP_ADDR_STRING *dnsServerList = &pPerAdapterInfo->DnsServerList;

	if (dnsServerList != NULL && strlen(dnsServerList->IpAddress.String)>0)
	{
		UNS_DEBUG(L"Primary DNS Server - exists\n");
		if (m_PrimaryDNS.compare(dnsServerList->IpAddress.String) != 0)// && (strcmp(dnsServerList->IpAddress.String,"0.0.0.0")))
		{
			UNS_DEBUG(L"Primary DNS Server - update required\n");
			m_PrimaryDNS.assign(dnsServerList->IpAddress.String);		  
			res = true;
		}	  
		if ((dnsServerList = dnsServerList->Next)!= NULL)
		{			
			UNS_DEBUG(L"Secondary DNS Server - exists\n");
			if (m_SecondaryDNS.compare(dnsServerList->IpAddress.String)!= 0)//&& (strcmp(dnsServerList->IpAddress.String,"0.0.0.0")))
			{	
				UNS_DEBUG(L"Secondary DNS Server - update required\n");
				m_SecondaryDNS.assign(dnsServerList->IpAddress.String);				  
				res = true;
			}						
		}
		else
		{
			UNS_DEBUG(L"Secondary DNS Server - empty\n");
			if (!m_SecondaryDNS.empty())
			{	
				UNS_DEBUG(L"Secondary DNS Server - update required\n");
				m_SecondaryDNS.clear();
				res = true;
			}						
		}	
	}
	else 
	{
		UNS_DEBUG(L"Primary DNS Server - empty\n", m_PrimaryDNS.empty(), m_PrimaryDNS.c_str());
		if (!m_PrimaryDNS.empty())
		{
			UNS_DEBUG(L"Primary DNS Server - update required\n");
			m_PrimaryDNS.clear();
			res = true;
		}
	}
	
	HeapFree(GetProcessHeap(), 0, pPerAdapterInfo);
	UNS_DEBUG(L"DNS Settings:: PrimaryDNS %C, SecondaryDNS %C, return %d\n", m_PrimaryDNS.c_str(), m_SecondaryDNS.c_str(),res);
	return res;
}


// Check if the network configuration changed and update the latest ones
bool SyncNetworkData::CheckNetworkData(bool &needSync, bool &isEmptyAddress, bool &IPv4Enabled)
{
	bool res = false;
	FuncEntryExit<decltype(res)> fee(this, L"CheckNetworkData", res);

	needSync = false;
	IPv4Enabled = false;

	UNS_DEBUG(L"DhcpEnabled=%d IpAddress=%C SubnetMask=%C MacAddress=%C DefaultGateway=%C\n", m_DHCPEnabled, m_IpAddress.c_str(), m_SubnetMask.c_str(), m_MacAddress.c_str(), m_DefaultGateway.c_str());		

	if (m_MacAddress.empty()) 
	{
		return res;
	}

	// Populate the network settings			
	PIP_ADAPTER_INFO pAdapterList = NULL;
	PIP_ADAPTER_INFO pAdapter = NULL;
	ULONG ulBufLen = 0;

	pAdapterList = (IP_ADAPTER_INFO *) malloc(sizeof (IP_ADAPTER_INFO));
	if (pAdapterList == NULL) 
	{
		UNS_ERROR(L"malloc 1 failed\n");
		return res;
	}
	if (GetAdaptersInfo(pAdapterList, &ulBufLen) == ERROR_BUFFER_OVERFLOW) 
	{
		free(pAdapterList);
		pAdapterList = (IP_ADAPTER_INFO *) malloc(ulBufLen);
		if (pAdapterList == NULL) 
		{
			UNS_ERROR(L"malloc 2 failed\n");
			return res;
		}
	}

	DWORD ret = GetAdaptersInfo(pAdapterList, &ulBufLen);
	if (ret != NO_ERROR)
	{
		UNS_ERROR(L"GetAdaptersInfo returned error: %d\n", ret);
		if (pAdapterList)
			free(pAdapterList);
		return (ret == ERROR_NO_DATA);
	}				
	// Enumerate the network adapters and check the wired one with the same MAC address of the AMT
	pAdapter = pAdapterList;
	std::string emptyAddress("0.0.0.0");
	while (pAdapter != NULL) 
	{
		std::string MacAddrTmp (MacAddressToString(pAdapter->Address, pAdapter->AddressLength));
		if (m_MacAddress.compare(MacAddrTmp)==0)
		{
			IPv4Enabled = true;
			m_NICindex = pAdapter->Index; 
			if (m_IpAddress.compare(pAdapter->IpAddressList.IpAddress.String) != 0)
			{
				m_IpAddress.assign(pAdapter->IpAddressList.IpAddress.String);	
				needSync = true;
			}
			if (m_SubnetMask.compare(pAdapter->IpAddressList.IpMask.String)!=0)
			{
				m_SubnetMask.assign(pAdapter->IpAddressList.IpMask.String);
				needSync = true;
			}
			// Check if gateway is present - if not - not connected to a network;
			if (strlen(pAdapter->GatewayList.IpAddress.String) > 0)
			{
				if (m_DefaultGateway.compare(pAdapter->GatewayList.IpAddress.String) != 0)
				{
					m_DefaultGateway.assign(pAdapter->GatewayList.IpAddress.String);
					needSync = true;
				}
			}
			else
			{
				if (!m_DefaultGateway.empty())
				{
					m_DefaultGateway.clear();
				}
			}
			if (m_DHCPEnabled != (pAdapter->DhcpEnabled ? true : false))
			{
				m_DHCPEnabled = pAdapter->DhcpEnabled ? true : false;
				needSync = true;
			}

			if (!m_DHCPEnabled && ((m_IpAddress.compare(emptyAddress) == 0) || (m_DefaultGateway.compare(emptyAddress) == 0)))
			{
				needSync = false;
				isEmptyAddress = true;
			}

			UNS_DEBUG(L"new settings updated::  DhcpEnabled=%d IpAddress=%C SubnetMask=%C MacAddress=%C DefaultGateway=%C\n", m_DHCPEnabled, m_IpAddress.c_str(), m_SubnetMask.c_str(), m_MacAddress.c_str(), m_DefaultGateway.c_str());
			break;
		}
		// go on to the next adapter item
		pAdapter = pAdapter->Next;
	}	

	if (pAdapterList)
		free(pAdapterList);

	res = true;
	if (!IPv4Enabled || isEmptyAddress)
		return res;

	if (!m_DHCPEnabled)
	{
		if (SyncDNSData())
		{
			UNS_DEBUG(L"SyncDNSData update DNS records\n");
			needSync = true;
		}
		else
		{
			UNS_DEBUG(L"No new DNS servers\n");
		}
	}		
	return res;
}
