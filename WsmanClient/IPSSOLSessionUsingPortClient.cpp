/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2013-2019 Intel Corporation
 */
#include "IPS_SolSessionUsingPort.h"
#include "AMT_EthernetPortSettings.h"
#include "IPSSOLSessionUsingPortClient.h"
#include "global.h"
#include "WsmanClientCatch.h"

IPSSolSessionUsingPortClient::IPSSolSessionUsingPortClient() : m_LinkTechnology(0)
{
}

IPSSolSessionUsingPortClient::IPSSolSessionUsingPortClient(const std::string &User, const std::string &Password) : BaseWSManClient(User, Password), m_LinkTechnology(0)
{
}

IPSSolSessionUsingPortClient::~IPSSolSessionUsingPortClient()
{
}

bool IPSSolSessionUsingPortClient::init()
{
	try
	{
		if (!m_endpoint)
			SetEndpoint();
		std::lock_guard<std::mutex> lock(WsManSemaphore());

		namespace CimTyped = Intel::Manageability::Cim::Typed;

		CimTyped::IPS_SolSessionUsingPort solSession(m_client.get());
		solSession.Get();
		
		CimTyped::AMT_EthernetPortSettings portSettings(m_client.get());
		portSettings.Get(solSession.Antecedent());
		std::string instanceId = portSettings.InstanceID();
		if(instanceId[instanceId.length()-1] == '0')
			m_LinkTechnology = 0;
		else
			m_LinkTechnology = 1;

		m_endpoint = true;
		return true;
	}
	CATCH_exception_return("IPSSolSessionUsingPortClient::Init")
}

bool IPSSolSessionUsingPortClient::GetSessionLinkTechnology(short *pLinkTechnology)
{
	if(!init())
		return false;
	
	UNS_DEBUG("GetSessionLinkTechnology LinkTechnology=%d \n", m_LinkTechnology);

	*pLinkTechnology = m_LinkTechnology;

	return true;
}