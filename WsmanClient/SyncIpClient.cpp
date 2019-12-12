/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2009-2019 Intel Corporation
 */
/*++

@file: SyncIpClient.cpp

--*/

#include "AMT_EthernetPortSettings.h"
#include "SyncIpClient.h"
#include "global.h"
#include "WsmanClientCatch.h"

SyncIpClient::SyncIpClient() : m_SharedStaticIpState(false), m_isInit(false)
{
}

SyncIpClient::SyncIpClient(const std::string &User, const std::string &Password) :
	BaseWSManClient(User, Password), m_SharedStaticIpState(false), m_isInit(false)
{
}


SyncIpClient::~SyncIpClient()
{
}

bool SyncIpClient::Init(bool forceGet)
{
	if (!forceGet && m_isInit) return true;

	try {
		if (!m_endpoint)
			SetEndpoint();
		//Lock WsMan to prevent reentry
		std::lock_guard<std::mutex> lock(WsManSemaphore());

		using Intel::Manageability::Cim::Typed::AMT_EthernetPortSettings;

		m_SharedStaticIpState = false;
		std::vector<std::shared_ptr<AMT_EthernetPortSettings>> ethernetSettings =
			AMT_EthernetPortSettings::Enumerate(m_client.get());
		std::vector<std::shared_ptr<AMT_EthernetPortSettings>>::iterator settingsIterator;
		for (settingsIterator = ethernetSettings.begin(); 
			 settingsIterator != ethernetSettings.end() ; 
			 settingsIterator++)
		{				
			AMT_EthernetPortSettings *currSetting = settingsIterator->get();
			if(!currSetting)
				continue;

			if (currSetting->IpSyncEnabledExists())
				m_SharedStaticIpState |= currSetting->IpSyncEnabled();
		}
	}
	CATCH_exception("SyncIpClient::Init")
	m_isInit = false;
	try {	
		//Lock WsMan to prevent reentry
		std::lock_guard<std::mutex> lock(WsManSemaphore());
		m_HostIpSettings.WsmanClient(m_client.get());
		m_HostIpSettings.Get(); 
		m_isInit = true;
	}
	CATCH_exception("SyncIpClient::Init")
		
	return m_isInit;
}

bool SyncIpClient::GetNetworkData(bool& DHCPEnabled, std::string& IPAddress, std::string& SubNet, std::string& GateWay,
	std::string& DNSAddress1, std::string& DNSAddress2)
{	
	if (!Init(true))
		return false;
	if (m_HostIpSettings.DHCPEnabledExists())
		DHCPEnabled	= m_HostIpSettings.DHCPEnabled();
	if (m_HostIpSettings.IpAddressExists()) 
		IPAddress.assign(m_HostIpSettings.IpAddress());
	if (m_HostIpSettings.SubnetMaskExists())
		SubNet.assign(m_HostIpSettings.SubnetMask());
	if (m_HostIpSettings.DefaultGatewayExists())
		GateWay.assign(m_HostIpSettings.DefaultGateway());
	if (m_HostIpSettings.PrimaryDNSExists())
		DNSAddress1.assign(m_HostIpSettings.PrimaryDNS());
	if (m_HostIpSettings.SecondaryDNSExists())
		DNSAddress2.assign(m_HostIpSettings.SecondaryDNS());
	UNS_DEBUG("GetNetworkData Network Settings::	DhcpEnabled=%d IpAddress=%C SubnetMask=%C DefaultGateway=%C\n", DHCPEnabled, IPAddress.c_str(), SubNet.c_str(), GateWay.c_str());
	UNS_DEBUG("GetNetworkData DNS Settings::		PrimaryDNS %C, SecondaryDNS %C\n", DNSAddress1.c_str(), DNSAddress2.c_str());
	return true;
}

bool SyncIpClient::SetNetworkData(bool DHCPEnabled, const std::string &IPAddress, const std::string &SubNet,
	const std::string &GateWay, const std::string &DNSAddress1, const std::string &DNSAddress2)
{
	try {
		if (!Init(true))
			return false;	
			//Lock WsMan to prevent reentry
		std::lock_guard<std::mutex> lock(WsManSemaphore());
		m_HostIpSettings.DHCPEnabled(DHCPEnabled);
		if (!DHCPEnabled)
		{	
			m_HostIpSettings.IpAddress(IPAddress);	
			
			m_HostIpSettings.SubnetMask(SubNet);		
			
			m_HostIpSettings.DefaultGateway(GateWay);	
			
			m_HostIpSettings.PrimaryDNS(DNSAddress1);
			
			m_HostIpSettings.SecondaryDNS(DNSAddress2);

			UNS_DEBUG("SetNetworkData Network Settings::	DhcpEnabled=%d IpAddress=%C SubnetMask=%C DefaultGateway=%C\n", m_HostIpSettings.DHCPEnabled(), m_HostIpSettings.IpAddress().c_str(), m_HostIpSettings.SubnetMask().c_str(), m_HostIpSettings.DefaultGateway().c_str());
			UNS_DEBUG("SetNetworkData DNS Settings::		PrimaryDNS %C, SecondaryDNS %C\n", m_HostIpSettings.PrimaryDNS().c_str(), m_HostIpSettings.SecondaryDNS().c_str());

		}
		else
		{
			m_HostIpSettings.RemoveIpAddress();	
			
			m_HostIpSettings.RemoveSubnetMask();		
			
			m_HostIpSettings.RemoveDefaultGateway();	
			
			m_HostIpSettings.RemovePrimaryDNS();
			
			m_HostIpSettings.RemoveSecondaryDNS();
		}
		m_HostIpSettings.Put();
	}
	CATCH_exception_return("SyncIpClient::SetNetworkData Put")

	return true;
}

bool SyncIpClient::GetSharedStaticIpState(bool* SharedStaticIpState)
{
	if (!Init(true))
	{
		UNS_ERROR("GetSharedStaticIpState Init return false!\n");
		return false;
	}
	*SharedStaticIpState = m_SharedStaticIpState;
	return true;
}