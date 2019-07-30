/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2011-2019 Intel Corporation
 */
/*++

@file: TimeSynchronizationClient.h

--*/

#ifndef  _TimeSynchronizationClient_H
#define  _TimeSynchronizationClient_H

#include "AMT_TimeSynchronizationService.h"
#include "BaseWSManClient.h"
#include <string>

class WSMAN_DLL_API TimeSynchronizationClient : public BaseWSManClient
{
public:
	enum ENABLED_STATE
	{
		DEFAULT_TRUE = 0,
		CONFIGURED_TRUE,
		TIMESYNC_DISABLED //These is FALSE value if the LocalTimeSyncEnabled FW property.
	};

	TimeSynchronizationClient();
	TimeSynchronizationClient(const std::string &User, const std::string &Password);
	virtual ~TimeSynchronizationClient();

	bool GetAMTTime(unsigned int & time);
	bool SetAMTTime(unsigned int time);
	bool GetLocalTimeSyncEnabledState(bool & state);

private:
	bool Init();
	bool UpdateTimeSyncState();
	bool m_isInit;
	
	Intel::Manageability::Cim::Typed::AMT_TimeSynchronizationService::GetLowAccuracyTimeSynch_OUTPUT m_time;
	LOCK_BEFORE;
	Intel::Manageability::Cim::Typed::AMT_TimeSynchronizationService m_service;
	UNLOCK_AFTER;

	ENABLED_STATE m_TimeSyncState;
};

#endif //_TimeSynchronizationClient_H
