/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2026 Intel Corporation
 */
/*++

@file: WiFiPortConfigWSManClient.cpp

--*/

// Implements retrieval of Wi-Fi port configuration policy data.

#include "WiFiPortConfigWSManClient.h"
#include "WsmanClientLog.h"
#include "WsmanClientCatch.h"

WiFiPortConfigWSManClient::WiFiPortConfigWSManClient(unsigned int port) : BaseWSManClient(port)
{
}

WiFiPortConfigWSManClient::~WiFiPortConfigWSManClient()
{
}

bool WiFiPortConfigWSManClient::GetWiFiPortConfiguration(WiFiPortConfigWSMan& config)
{
	try
	{
		// Read Wi-Fi port configuration service and copy present fields.
		if (!m_endpoint)
			SetEndpoint();
		//Lock WsMan to prevent reentry
		std::lock_guard<std::mutex> lock(WsManSemaphore());
		m_service.WsmanClient(m_client.get());
		m_service.Get();

		if (m_service.LastConnectedSsidUnderMeControlExists()) config.LastConnectedSsidUnderMeControl = m_service.LastConnectedSsidUnderMeControl();
		if (m_service.UEFIWiFiProfileShareEnabledExists()) config.UEFIWiFiProfileShareEnabled = m_service.UEFIWiFiProfileShareEnabled();
		if (m_service.localProfileSynchronizationEnabledExists()) config.LocalProfileSynchronizationEnabled = m_service.localProfileSynchronizationEnabled();
	}
	CATCH_exception_return("WiFiPortConfigWSManClient::GetWiFiPortConfiguration")

	return true;
}
