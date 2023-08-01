/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2013-2023 Intel Corporation
 */
#include "IPS_IderSessionUsingPort.h"
#include "AMT_EthernetPortSettings.h"
#include "IPSIderSessionUsingPortClient.h"
#include "WsmanClientLog.h"
#include "WsmanClientCatch.h"

IPSIderSessionUsingPortClient::IPSIderSessionUsingPortClient(unsigned int port) : BaseWSManClient(port), m_LinkTechnology(0)
{
}

IPSIderSessionUsingPortClient::IPSIderSessionUsingPortClient(unsigned int port, const std::string &User, const std::string &Password) :
	BaseWSManClient(port, User, Password), m_LinkTechnology(0)
{
}

IPSIderSessionUsingPortClient::~IPSIderSessionUsingPortClient()
{
}

bool IPSIderSessionUsingPortClient::init()
{
	try
	{
		if (!m_endpoint)
			SetEndpoint();
		std::lock_guard<std::mutex> lock(WsManSemaphore());

		namespace CimTyped = Intel::Manageability::Cim::Typed;

		CimTyped::IPS_IderSessionUsingPort iderSession(m_client.get());
		iderSession.Get();
		
		CimTyped::AMT_EthernetPortSettings portSettings(m_client.get());
		portSettings.Get(iderSession.Antecedent());
		std::string instanceId = portSettings.InstanceID();
		if(instanceId[instanceId.length()-1] == '0')
			m_LinkTechnology = 0;
		else
			m_LinkTechnology = 1;

		m_endpoint = true;
		return true;
	}
	CATCH_exception_return("IPSIderSessionUsingPortClient::Init")
}

bool IPSIderSessionUsingPortClient::GetSessionLinkTechnology(short *pLinkTechnology)
{
	if(!init())
		return false;
	
	WSMAN_DEBUG("GetSessionLinkTechnology LinkTechnology=%d \n", m_LinkTechnology);

	*pLinkTechnology = m_LinkTechnology;

	return true;
}