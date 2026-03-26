/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2026 Intel Corporation
 */
/*++

@file: WiFiPortWSManClient.h

--*/

// WS-Man client for enumerating CIM Wi-Fi port instances.

#ifndef _WIFI_PORT_WSMAN_CLIENT_H
#define _WIFI_PORT_WSMAN_CLIENT_H

#include "BaseWSManClient.h"
#include <string>
#include <vector>

struct WiFiPortWSMan
{
	uint16_t EnabledState = 0;
	std::string PermanentAddress;
};

class WiFiPortWSManClient : public BaseWSManClient
{
public:
	WiFiPortWSManClient(unsigned int port);
	virtual ~WiFiPortWSManClient();
	bool GetWiFiPorts(std::vector<WiFiPortWSMan>& ports);
private:
};

#endif //_WIFI_PORT_WSMAN_CLIENT_H
