/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2013-2019 Intel Corporation
 */
#include "IPS_KvmSessionUsingPort.h"
#include "AMT_EthernetPortSettings.h"
#include "IPSKVMSessionUsingPortClient.h"
#include "UNSDebug.h"
#include "WsmanClientCatch.h"

using namespace Intel::Manageability::Cim::Typed;
using namespace std;

const std::string IPSKVMSessionUsingPortClient::DEFAULT_USER = "$$uns";
const std::string IPSKVMSessionUsingPortClient::DEFAULT_PASS = "$$uns";

IPSKVMSessionUsingPortClient::IPSKVMSessionUsingPortClient() : BaseWSManClient(DEFAULT_USER, DEFAULT_PASS), m_LinkTechnology(0)
{
}

IPSKVMSessionUsingPortClient::IPSKVMSessionUsingPortClient(const std::string &User, const std::string &Password) : BaseWSManClient(User, Password), m_LinkTechnology(0)
{
}

IPSKVMSessionUsingPortClient::~IPSKVMSessionUsingPortClient()
{
}

bool IPSKVMSessionUsingPortClient::init()
{
	try
	{
		if (!m_endpoint)
			SetEndpoint(false);
		std::lock_guard<std::mutex> lock(WsManSemaphore());

		IPS_KvmSessionUsingPort kvmSession(m_client.get());
		
		kvmSession.Get();
		
		AMT_EthernetPortSettings portSettings(m_client.get());
		portSettings.Get(kvmSession.Antecedent());
		string instanceId = portSettings.InstanceID();
		if(instanceId[instanceId.length()-1] == '0')
			m_LinkTechnology = 0;
		else
			m_LinkTechnology = 1;

		m_endpoint = true;
		return true;
	}
	CATCH_exception_return("IPSKVMSessionUsingPortClient::Init")
}

bool IPSKVMSessionUsingPortClient::GetSessionLinkTechnology(short *pLinkTechnology)
{
	if(!init())
		return false;
	
	DbgPrint("GetSessionLinkTechnology LinkTechnology=%d \n", m_LinkTechnology);

	*pLinkTechnology = m_LinkTechnology;

	return true;
}