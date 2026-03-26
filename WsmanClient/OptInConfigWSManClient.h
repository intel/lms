/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2026 Intel Corporation
 */
/*++

@file: OptInConfigWSManClient.h

--*/

// WS-Man client for reading user-consent / opt-in policy configuration.

#ifndef _OPT_IN_CONFIG_WSMAN_CLIENT_H
#define _OPT_IN_CONFIG_WSMAN_CLIENT_H

#include "IPS_OptInService.h"
#include "BaseWSManClient.h"

struct OptInConfigWSMan
{
	unsigned int OptInCodeTimeout = 0;
	unsigned int OptInRequired = 0;
	unsigned char OptInState = 0;
	unsigned short OptInDisplayTimeout = 0;
};

class OptInConfigWSManClient : public BaseWSManClient
{
public:
	OptInConfigWSManClient(unsigned int port);
	virtual ~OptInConfigWSManClient();
	// Retrieves opt-in policy and runtime state values.
	bool GetOptInConfig(OptInConfigWSMan& config);
private:
	LOCK_BEFORE;
	Intel::Manageability::Cim::Typed::IPS_OptInService m_service;
	UNLOCK_AFTER;
};

#endif //_OPT_IN_CONFIG_WSMAN_CLIENT_H
