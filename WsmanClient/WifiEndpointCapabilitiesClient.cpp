/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2025 Intel Corporation
 */
/*++

@file: WifiEndpointCapabilitiesClient.cpp

--*/

#include "WifiEndpointCapabilitiesClient.h"
#include "CIM_WiFiEndpointCapabilities.h"
#include "WsmanClientLog.h"
#include "WsmanClientCatch.h"

WifiEndpointCapabilitiesClient::WifiEndpointCapabilitiesClient(unsigned int port) : BaseWSManClient(port)
{
}

WifiEndpointCapabilitiesClient::~WifiEndpointCapabilitiesClient()
{
}

bool WifiEndpointCapabilitiesClient::isTransitionModeSupported(bool &supported)
{
	try {
		if (!m_endpoint)
			SetEndpoint();
		//Lock WsMan to prevent reentry
		std::lock_guard<std::mutex> lock(WsManSemaphore());

		using Intel::Manageability::Cim::Typed::CIM_WiFiEndpointCapabilities;

		CIM_WiFiEndpointCapabilities capabilities(m_client.get());
		capabilities.Get();
		std::vector<unsigned short> authMethods = capabilities.SupportedAuthenticationMethods();

		// AuthenticationMethodWPA3SAE_TM = 32772
		supported = (std::find(authMethods.begin(), authMethods.end(), 32772) != authMethods.end());
		return true;
	}
	CATCH_exception("WifiEndpointCapabilitiesClient::isTransitionModeSupported")
	supported = false;
	return false;
}
