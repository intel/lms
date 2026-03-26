/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2026 Intel Corporation
 */
/*++

@file: AMTConfigurationWSManClient.h

--*/

// WS-Man client for AMT setup and provisioning configuration state.

#ifndef _AMT_CONFIGURATION_WSMAN_CLIENT_H
#define _AMT_CONFIGURATION_WSMAN_CLIENT_H

#include "AMT_SetupAndConfigurationService.h"
#include "BaseWSManClient.h"
#include <string>

struct AMTConfigurationWSMan
{
	std::string DhcpDNSSuffix;
	std::string TrustedDNSSuffix;
	bool ZeroTouchConfigurationEnabled = false;
	unsigned char ProvisioningMode = 0;
};

class AMTConfigurationWSManClient : public BaseWSManClient
{
public:
	AMTConfigurationWSManClient(unsigned int port);
	virtual ~AMTConfigurationWSManClient();
	// Retrieves key AMT provisioning parameters.
	bool GetAMTConfiguration(AMTConfigurationWSMan& config);
private:
	LOCK_BEFORE;
	Intel::Manageability::Cim::Typed::AMT_SetupAndConfigurationService m_service;
	UNLOCK_AFTER;
};

#endif //_AMT_CONFIGURATION_WSMAN_CLIENT_H
