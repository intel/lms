/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2026 Intel Corporation
 */
/*++

@file: GeneralSettingsWSManClient.h

--*/

// WS-Man client for retrieving AMT general configuration properties.

#ifndef _GENERAL_SETTINGS_WSMAN_CLIENT_H
#define _GENERAL_SETTINGS_WSMAN_CLIENT_H

#include "AMT_GeneralSettings.h"
#include "BaseWSManClient.h"
#include <string>

struct GeneralSettingsWSMan
{
	bool NetworkInterfaceEnabled = false;
	std::string DigestRealm;
	unsigned int IdleWakeTimeout = 0;
	std::string HostName;
	std::string DomainName;
	bool PingResponseEnabled = false;
	bool WsmanOnlyMode = false;
	unsigned int PreferredAddressFamily = 0;
	unsigned short DHCPv6ConfigurationTimeout = 0;
	bool SharedFQDN = false;
	std::string HostOSFQDN;
	unsigned int AMTNetworkEnabled = 0;
	bool RmcpPingResponseEnabled = false;
	unsigned int PresenceNotificationInterval = 0;
	unsigned int PrivacyLevel = 0;
	unsigned int PowerSource = 0;
	unsigned int ThunderboltDockEnabled = 0;
	unsigned short OemID = 0;
};

class GeneralSettingsWSManClient : public BaseWSManClient
{
public:
	GeneralSettingsWSManClient(unsigned int port);
	virtual ~GeneralSettingsWSManClient();
	// Reads AMT general settings into the output structure.
	bool GetGeneralSettings(GeneralSettingsWSMan& settings);
private:
	LOCK_BEFORE;
	Intel::Manageability::Cim::Typed::AMT_GeneralSettings m_service;
	UNLOCK_AFTER;
};

#endif //_GENERAL_SETTINGS_WSMAN_CLIENT_H
