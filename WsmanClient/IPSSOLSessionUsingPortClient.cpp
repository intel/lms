/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2013-2019 Intel Corporation
 */
#include "IPS_SolSessionUsingPort.h"
#include "AMT_EthernetPortSettings.h"
#include "IPSSOLSessionUsingPortClient.h"
#include "UNSDebug.h"
#include "WsmanClientCatch.h"

using namespace Intel::Manageability::Cim::Typed;
using namespace std;

const std::string IPSSolSessionUsingPortClient::DEFAULT_USER = "$$uns";
const std::string IPSSolSessionUsingPortClient::DEFAULT_PASS = "$$uns";

IPSSolSessionUsingPortClient::IPSSolSessionUsingPortClient() : BaseWSManClient(DEFAULT_USER, DEFAULT_PASS), m_LinkTechnology(0)
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
			SetEndpoint(false);
		std::lock_guard<std::mutex> lock(WsManSemaphore());

		IPS_SolSessionUsingPort solSession(m_client.get());
		solSession.Get();
		
		AMT_EthernetPortSettings portSettings(m_client.get());
		portSettings.Get(solSession.Antecedent());
		string instanceId = portSettings.InstanceID();
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
	
	DbgPrint("GetSessionLinkTechnology LinkTechnology=%d \n", m_LinkTechnology);

	*pLinkTechnology = m_LinkTechnology;

	return true;
}