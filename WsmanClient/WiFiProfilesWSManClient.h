/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2026 Intel Corporation
 */
/*++

@file: WiFiProfilesWSManClient.h

--*/

// WS-Man client for enumerating AMT-managed Wi-Fi profiles.

#ifndef _WIFI_PROFILES_WSMAN_CLIENT_H
#define _WIFI_PROFILES_WSMAN_CLIENT_H

#include "BaseWSManClient.h"
#include <string>
#include <vector>

struct WiFiProfileWSMan
{
	std::string ProfileName;
	uint8_t Priority = 0;
	std::string SSID;
	uint16_t EncryptionMethod = 0;
	uint16_t AuthenticationMethod = 0;
};

class WiFiProfilesWSManClient : public BaseWSManClient
{
public:
	WiFiProfilesWSManClient(unsigned int port);
	virtual ~WiFiProfilesWSManClient();
	bool GetWiFiProfiles(std::vector<WiFiProfileWSMan>& profiles);
private:
};

#endif //_WIFI_PROFILES_WSMAN_CLIENT_H
