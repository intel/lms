/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2009-2019 Intel Corporation
 */
/*++

@file: WifiPortClient.cpp

--*/

#include "WifiPortClient.h"
#include "CIM_WiFiPort.h"
#include "UNSDebug.h"
#include "WsmanClientCatch.h"

using namespace std; 

const string WifiPortClient::DEFAULT_USER = "$$uns";
const string WifiPortClient::DEFAULT_PASS = "$$uns";

using namespace Intel::Manageability::Cim::Typed;
WifiPortClient::WifiPortClient() : BaseWSManClient(DEFAULT_USER, DEFAULT_PASS)
{
}

WifiPortClient::~WifiPortClient()
{
}

bool WifiPortClient::PortsNum(size_t &ports)
{
	try {
		if (!m_endpoint)
			SetEndpoint(false);
		//Lock WsMan to prevent reentry
		std::lock_guard<std::mutex> lock(WsManSemaphore());
		
		vector<shared_ptr<CIM_WiFiPort>> ethernetSettings =
			CIM_WiFiPort::Enumerate(m_client.get());

		ports = ethernetSettings.size();
		return true;
	}
	CATCH_exception("WifiPortClient::PortsNum")
	return false;
}