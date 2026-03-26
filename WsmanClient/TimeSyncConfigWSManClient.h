/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2026 Intel Corporation
 */
/*++

@file: TimeSyncConfigWSManClient.h

--*/

// WS-Man client for AMT time synchronization service properties.

#ifndef _TIME_SYNC_CONFIG_WSMAN_CLIENT_H
#define _TIME_SYNC_CONFIG_WSMAN_CLIENT_H

#include "AMT_TimeSynchronizationService.h"
#include "BaseWSManClient.h"

struct TimeSyncConfigWSMan
{
	unsigned int AMTTime = 0;
	unsigned int LocalTimeSyncEnabled = 0;
	unsigned int TimeSource = 0;
};

class TimeSyncConfigWSManClient : public BaseWSManClient
{
public:
	TimeSyncConfigWSManClient(unsigned int port);
	virtual ~TimeSyncConfigWSManClient();
	// Reads time sync policy and current AMT time snapshot.
	bool GetTimeSyncConfig(TimeSyncConfigWSMan& config);
private:
	LOCK_BEFORE;
	Intel::Manageability::Cim::Typed::AMT_TimeSynchronizationService m_service;
	UNLOCK_AFTER;
};

#endif //_TIME_SYNC_CONFIG_WSMAN_CLIENT_H
