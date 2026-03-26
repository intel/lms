/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2026 Intel Corporation
 */
/*++

@file: WiFiEndpointStateWSManClient.cpp

--*/

// Implements retrieval of operational Wi-Fi endpoint state from CIM_WiFiEndpoint.

#include <memory>
#include <vector>
#include "WiFiEndpointStateWSManClient.h"
#include "CIM_WiFiEndpoint.h"
#include "WsmanClientLog.h"
#include "WsmanClientCatch.h"

WiFiEndpointStateWSManClient::WiFiEndpointStateWSManClient(unsigned int port) : BaseWSManClient(port)
{
}

WiFiEndpointStateWSManClient::~WiFiEndpointStateWSManClient()
{
}

bool WiFiEndpointStateWSManClient::GetWiFiEndpointState(WiFiEndpointStateWSMan& state)
{
	try
	{
		// Enumerate endpoint instances and map first available entry to response state.
		if (!m_endpoint)
			SetEndpoint();
		//Lock WsMan to prevent reentry
		std::lock_guard<std::mutex> lock(WsManSemaphore());
		std::vector<std::shared_ptr<Intel::Manageability::Cim::Typed::CIM_WiFiEndpoint>> results =
			Intel::Manageability::Cim::Typed::CIM_WiFiEndpoint::Enumerate(m_client.get());
		if (results.empty())
			return false;

		auto& ep = *results[0];
		if (ep.MACAddressExists()) state.MACAddress = ep.MACAddress();
		if (ep.HealthStateExists()) state.HealthState = ep.HealthState();
		if (ep.EnabledStateExists()) state.EnabledState = ep.EnabledState();
	}
	CATCH_exception_return("WiFiEndpointStateWSManClient::GetWiFiEndpointState")

	return true;
}
