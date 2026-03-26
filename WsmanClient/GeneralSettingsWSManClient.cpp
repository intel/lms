/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2026 Intel Corporation
 */
/*++

@file: GeneralSettingsWSManClient.cpp

--*/

// Implements retrieval of AMT general settings properties via WS-Man.

#include "GeneralSettingsWSManClient.h"
#include "WsmanClientLog.h"
#include "WsmanClientCatch.h"

GeneralSettingsWSManClient::GeneralSettingsWSManClient(unsigned int port) : BaseWSManClient(port)
{
}

GeneralSettingsWSManClient::~GeneralSettingsWSManClient()
{
}

bool GeneralSettingsWSManClient::GetGeneralSettings(GeneralSettingsWSMan& settings)
{
	try
	{
		// Fetch the AMT general settings singleton and copy present properties.
		if (!m_endpoint)
			SetEndpoint();
		//Lock WsMan to prevent reentry
		std::lock_guard<std::mutex> lock(WsManSemaphore());
		m_service.WsmanClient(m_client.get());
		m_service.Get();

		if (m_service.NetworkInterfaceEnabledExists()) settings.NetworkInterfaceEnabled = m_service.NetworkInterfaceEnabled();
		if (m_service.DigestRealmExists()) settings.DigestRealm = m_service.DigestRealm();
		if (m_service.IdleWakeTimeoutExists()) settings.IdleWakeTimeout = m_service.IdleWakeTimeout();
		if (m_service.HostNameExists()) settings.HostName = m_service.HostName();
		if (m_service.DomainNameExists()) settings.DomainName = m_service.DomainName();
		if (m_service.PingResponseEnabledExists()) settings.PingResponseEnabled = m_service.PingResponseEnabled();
		if (m_service.WsmanOnlyModeExists()) settings.WsmanOnlyMode = m_service.WsmanOnlyMode();
		if (m_service.PreferredAddressFamilyExists()) settings.PreferredAddressFamily = m_service.PreferredAddressFamily();
		if (m_service.DHCPv6ConfigurationTimeoutExists()) settings.DHCPv6ConfigurationTimeout = m_service.DHCPv6ConfigurationTimeout();
		if (m_service.SharedFQDNExists()) settings.SharedFQDN = m_service.SharedFQDN();
		if (m_service.HostOSFQDNExists()) settings.HostOSFQDN = m_service.HostOSFQDN();
		if (m_service.AMTNetworkEnabledExists()) settings.AMTNetworkEnabled = m_service.AMTNetworkEnabled();
		if (m_service.RmcpPingResponseEnabledExists()) settings.RmcpPingResponseEnabled = m_service.RmcpPingResponseEnabled();
		if (m_service.PresenceNotificationIntervalExists()) settings.PresenceNotificationInterval = m_service.PresenceNotificationInterval();
		if (m_service.PrivacyLevelExists()) settings.PrivacyLevel = m_service.PrivacyLevel();
		if (m_service.PowerSourceExists()) settings.PowerSource = m_service.PowerSource();
		if (m_service.ThunderboltDockEnabledExists()) settings.ThunderboltDockEnabled = m_service.ThunderboltDockEnabled();
		if (m_service.OemIDExists()) settings.OemID = m_service.OemID();
	}
	CATCH_exception_return("GeneralSettingsWSManClient::GetGeneralSettings")

	return true;
}
