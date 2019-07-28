/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2013-2019 Intel Corporation
 */
#include "IPS_IderSessionUsingPort.h"
#include "AMT_EthernetPortSettings.h"
#include "IPSIderSessionUsingPortClient.h"
#include "global.h"
#include "WsmanClientCatch.h"

using namespace Intel::Manageability::Cim::Typed;
using namespace std;

const std::string IPSIderSessionUsingPortClient::DEFAULT_USER = "$$uns";
const std::string IPSIderSessionUsingPortClient::DEFAULT_PASS = "$$uns";

IPSIderSessionUsingPortClient::IPSIderSessionUsingPortClient() : BaseWSManClient(DEFAULT_USER, DEFAULT_PASS), m_LinkTechnology(0)
{
}

IPSIderSessionUsingPortClient::IPSIderSessionUsingPortClient(const std::string &User, const std::string &Password) : BaseWSManClient(User, Password), m_LinkTechnology(0)
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
			SetEndpoint(false);
		std::lock_guard<std::mutex> lock(WsManSemaphore());

		IPS_IderSessionUsingPort iderSession(m_client.get());
		iderSession.Get();
		
		AMT_EthernetPortSettings portSettings(m_client.get());
		portSettings.Get(iderSession.Antecedent());
		string instanceId = portSettings.InstanceID();
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
	
	UNS_DEBUG("GetSessionLinkTechnology LinkTechnology=%d \n", m_LinkTechnology);

	*pLinkTechnology = m_LinkTechnology;

	return true;
}