/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2026 Intel Corporation
 */
/*++

@file: ManagementPresenceRemoteSAPWSManClient.h

--*/

// WS-Man client for AMT management presence remote SAP entries.

#ifndef _MANAGEMENT_PRESENCE_REMOTE_SAP_WSMAN_CLIENT_H
#define _MANAGEMENT_PRESENCE_REMOTE_SAP_WSMAN_CLIENT_H

#include "BaseWSManClient.h"
#include <string>

struct ManagementPresenceSAPWSMan
{
	uint16_t InfoFormat = 0;
	std::string AccessInfo;
	uint16_t Port = 0;
	std::string CN;
};

class ManagementPresenceRemoteSAPWSManClient : public BaseWSManClient
{
public:
	ManagementPresenceRemoteSAPWSManClient(unsigned int port);
	virtual ~ManagementPresenceRemoteSAPWSManClient();
	bool GetManagementPresenceRemoteSAP(ManagementPresenceSAPWSMan& sap);
private:
};

#endif //_MANAGEMENT_PRESENCE_REMOTE_SAP_WSMAN_CLIENT_H
