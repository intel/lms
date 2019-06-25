/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2009-2019 Intel Corporation
 */
/*++

@file: SyncNetworkData.cpp

--*/
#include "SyncNetworkData.h"
#include "SyncIpClient.h"

#include "global.h" 
#include <FuncEntryExit.h>

SyncNetworkData::SyncNetworkData() : m_NICindex(0)
{
	ResetSettings();
}


void SyncNetworkData::ResetSettings()
{
	FuncEntryExit<void> fee(L"ResetSettings");
	m_DHCPEnabled		= false;
	m_IpAddress.clear();
	m_SubnetMask.clear();
	m_DefaultGateway.clear();
	m_PrimaryDNS.clear();
	m_SecondaryDNS.clear();
	m_MacAddress.clear();
	m_ValidationFailed	= false;
}

SyncNetworkData::~SyncNetworkData(void)
{
}

// Sync between the Host and ME network configurations
bool SyncNetworkData::SyncNetworkConfiguration()
{
	bool		res = false;
	FuncEntryExit<decltype(res)> fee(L"SyncNetworkConfiguration", res);

	bool		DHCPEnabled = true;
	std::string IPAddress;
	std::string SubNet;
	std::string GateWay;
	std::string PrimaryDNS;
	std::string SecondaryDNS;
	SyncIpClient syncIpClient;	

	if (!syncIpClient.GetNetworkData(DHCPEnabled, IPAddress, SubNet, GateWay, PrimaryDNS, SecondaryDNS))
	{
		return res;
	}


	bool needToValidateConnectivity = false;
	bool needToSync = false;	
	if (m_DHCPEnabled != DHCPEnabled)
	{			
		UNS_DEBUG(L"DHCPEnabled changed %d <--> %d\n", DHCPEnabled, m_DHCPEnabled);			
		DHCPEnabled = m_DHCPEnabled;			
		needToSync = true;
	}		
	// On DHCP enabled only need to update the DCHP status
	// On DHCP disabled we need to update all the network settings and also validate them
	if (!m_DHCPEnabled)
	{
		if (m_IpAddress != IPAddress)
		{			
			UNS_DEBUG(L"IPAddress changed %C <--> %C\n", IPAddress.c_str(), m_IpAddress.c_str());			
			IPAddress.assign(m_IpAddress);
			needToSync = true;
			needToValidateConnectivity = true;
		}
		if (m_SubnetMask != SubNet)
		{			
			UNS_DEBUG(L"SubnetMask changed  %C <--> %C\n", SubNet.c_str(), m_SubnetMask.c_str());			
			SubNet.assign(m_SubnetMask);
			needToSync = true;
			needToValidateConnectivity = true;
		}		
		if (m_DefaultGateway != GateWay)
		{			
			UNS_DEBUG(L"DefaultGateway changed  %C <--> %C\n", GateWay.c_str(), m_DefaultGateway.c_str());			
			GateWay.assign(m_DefaultGateway);
			needToSync = true;
			needToValidateConnectivity = true;
		}		
		if (m_PrimaryDNS != PrimaryDNS)
		{
			UNS_DEBUG(L"PrimaryDNS changed  %C <--> %C\n", PrimaryDNS.c_str(), m_PrimaryDNS.c_str());			
			PrimaryDNS.assign(m_PrimaryDNS);			
			needToValidateConnectivity = true;
			needToSync = true;
		}		
		if (m_SecondaryDNS != SecondaryDNS)
		{			
			UNS_DEBUG(L"SecondaryDNS changed  %C <--> %C\n", SecondaryDNS.c_str(), m_SecondaryDNS.c_str());			
			SecondaryDNS.assign(m_SecondaryDNS);
			needToValidateConnectivity = true;
			needToSync = true;
		}
	}
	if (!needToSync)
	{
		res = true;
		UNS_DEBUG(L"no sync needed - all settings remains the same\n");
		return res;
	}


	// Sync the SharedStaticIp configuration
	if (needToValidateConnectivity)
	{
		UNS_DEBUG(L"Need to validate the new network settings\n");
		if (ValidateLinkStatus())
		{
			UNS_DEBUG(L"New network settings are validated\n");
			m_ValidationFailed = false;
		}
		else
		{
			UNS_DEBUG(L"New network settings are not validated\n");
			m_ValidationFailed = true;
			return res; // false
		}				
	}
	
	if (PrimaryDNS.empty()) //So sync will succeed even if primary DNS is empty (this is valid by Windows)
	{
		PrimaryDNS = "0.0.0.0";
	}
	if (SecondaryDNS.empty()) //So sync will succeed even if secondary DNS is empty
	{	
		SecondaryDNS = "0.0.0.0";
	}
	
	res = syncIpClient.SetNetworkData(DHCPEnabled, IPAddress, SubNet, GateWay, PrimaryDNS, SecondaryDNS);
	UNS_DEBUG(L"SetNetworkData %d\n", res);	

	return res;
}

// Check if the SharedStatic property is enabled
bool SyncNetworkData::getSharedStaticIpState(bool* state)
{	
	bool res = false;	

	FuncEntryExit<decltype(res)> fee(L"getSharedStaticIpState", res);

	SyncIpClient syncIpClient;
	res = syncIpClient.GetSharedStaticIpState(state);
	return res;
}
