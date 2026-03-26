/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2026 Intel Corporation
 */
/*++

@file: TimeSyncConfigWSManClient.cpp

--*/

// Implements retrieval of AMT time synchronization state and current firmware time.

#include "TimeSyncConfigWSManClient.h"
#include "WsmanClientLog.h"
#include "WsmanClientCatch.h"

TimeSyncConfigWSManClient::TimeSyncConfigWSManClient(unsigned int port) : BaseWSManClient(port)
{
}

TimeSyncConfigWSManClient::~TimeSyncConfigWSManClient()
{
}

bool TimeSyncConfigWSManClient::GetTimeSyncConfig(TimeSyncConfigWSMan& config)
{
	try
	{
		// Read time synchronization service properties and low-accuracy timestamp.
		if (!m_endpoint)
			SetEndpoint();
		//Lock WsMan to prevent reentry
		std::lock_guard<std::mutex> lock(WsManSemaphore());
		m_service.WsmanClient(m_client.get());
		m_service.Get();

		if (m_service.LocalTimeSyncEnabledExists()) config.LocalTimeSyncEnabled = m_service.LocalTimeSyncEnabled();
		if (m_service.TimeSourceExists()) config.TimeSource = m_service.TimeSource();

		Intel::Manageability::Cim::Typed::AMT_TimeSynchronizationService::GetLowAccuracyTimeSynch_OUTPUT timeOutput;
		int ret = m_service.GetLowAccuracyTimeSynch(timeOutput);
		if (ret == 0 && timeOutput.Ta0Exists()) config.AMTTime = timeOutput.Ta0();
	}
	CATCH_exception_return("TimeSyncConfigWSManClient::GetTimeSyncConfig")

	return true;
}
