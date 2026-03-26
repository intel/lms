/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2026 Intel Corporation
 */
/*++

@file: WiFiPortConfigWSManClient.h

--*/

// WS-Man client for AMT Wi-Fi port configuration data.

#ifndef _WIFI_PORT_CONFIG_WSMAN_CLIENT_H
#define _WIFI_PORT_CONFIG_WSMAN_CLIENT_H

#include "AMT_WiFiPortConfigurationService.h"
#include "BaseWSManClient.h"
#include <string>

struct WiFiPortConfigWSMan
{
	std::string LastConnectedSsidUnderMeControl;
	bool UEFIWiFiProfileShareEnabled = false;
	unsigned int LocalProfileSynchronizationEnabled = 0;
};

class WiFiPortConfigWSManClient : public BaseWSManClient
{
public:
	WiFiPortConfigWSManClient(unsigned int port);
	virtual ~WiFiPortConfigWSManClient();
	// Reads Wi-Fi profile sharing and synchronization settings.
	bool GetWiFiPortConfiguration(WiFiPortConfigWSMan& config);
private:
	LOCK_BEFORE;
	Intel::Manageability::Cim::Typed::AMT_WiFiPortConfigurationService m_service;
	UNLOCK_AFTER;
};

#endif //_WIFI_PORT_CONFIG_WSMAN_CLIENT_H
