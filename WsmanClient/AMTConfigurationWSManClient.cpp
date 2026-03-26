/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2026 Intel Corporation
 */
/*++

@file: AMTConfigurationWSManClient.cpp

--*/

// Implements retrieval of AMT setup and provisioning configuration data.

#include "AMTConfigurationWSManClient.h"
#include "WsmanClientLog.h"
#include "WsmanClientCatch.h"

AMTConfigurationWSManClient::AMTConfigurationWSManClient(unsigned int port) : BaseWSManClient(port)
{
}

AMTConfigurationWSManClient::~AMTConfigurationWSManClient()
{
}

bool AMTConfigurationWSManClient::GetAMTConfiguration(AMTConfigurationWSMan& config)
{
	try
	{
		// Read setup-and-configuration service values into the output structure.
		if (!m_endpoint)
			SetEndpoint();
		//Lock WsMan to prevent reentry
		std::lock_guard<std::mutex> lock(WsManSemaphore());
		m_service.WsmanClient(m_client.get());
		m_service.Get();

		if (m_service.DhcpDNSSuffixExists()) config.DhcpDNSSuffix = m_service.DhcpDNSSuffix();
		if (m_service.TrustedDNSSuffixExists()) config.TrustedDNSSuffix = m_service.TrustedDNSSuffix();
		if (m_service.ZeroTouchConfigurationEnabledExists()) config.ZeroTouchConfigurationEnabled = m_service.ZeroTouchConfigurationEnabled();
		if (m_service.ProvisioningModeExists()) config.ProvisioningMode = m_service.ProvisioningMode();
	}
	CATCH_exception_return("AMTConfigurationWSManClient::GetAMTConfiguration")

	return true;
}
