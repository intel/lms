/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2026 Intel Corporation
 */
/*++

@file: WiFiEndpointStateWSManClient.h

--*/

// WS-Man client for reading Wi-Fi endpoint operational state.

#ifndef _WIFI_ENDPOINT_STATE_WSMAN_CLIENT_H
#define _WIFI_ENDPOINT_STATE_WSMAN_CLIENT_H

#include "BaseWSManClient.h"
#include <string>

struct WiFiEndpointStateWSMan
{
	std::string MACAddress;
	unsigned short HealthState = 0;
	unsigned short EnabledState = 0;
};

class WiFiEndpointStateWSManClient : public BaseWSManClient
{
public:
	WiFiEndpointStateWSManClient(unsigned int port);
	virtual ~WiFiEndpointStateWSManClient();
	// Retrieves MAC and health/enabled state for the primary Wi-Fi endpoint.
	bool GetWiFiEndpointState(WiFiEndpointStateWSMan& state);
private:
};

#endif //_WIFI_ENDPOINT_STATE_WSMAN_CLIENT_H
