/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2009-2019 Intel Corporation
 */
/*++

@file: WifiPortClient.cpp

--*/

#include "WifiPortClient.h"
#include "CIM_WiFiPort.h"
#include "global.h"
#include "WsmanClientCatch.h"

WifiPortClient::WifiPortClient()
{
}

WifiPortClient::~WifiPortClient()
{
}

bool WifiPortClient::PortsNum(size_t &ports)
{
	try {
		if (!m_endpoint)
			SetEndpoint();
		//Lock WsMan to prevent reentry
		std::lock_guard<std::mutex> lock(WsManSemaphore());

		using Intel::Manageability::Cim::Typed::CIM_WiFiPort;

		std::vector<std::shared_ptr<CIM_WiFiPort>> ethernetSettings =
			CIM_WiFiPort::Enumerate(m_client.get());

		ports = ethernetSettings.size();
		return true;
	}
	CATCH_exception("WifiPortClient::PortsNum")
	return false;
}