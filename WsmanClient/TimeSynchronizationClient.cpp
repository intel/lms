/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2011-2023 Intel Corporation
 */
/*++

@file: TimeSynchronizationClient.cpp

--*/

#include "TimeSynchronizationClient.h"
#include "WsmanClientLog.h"
#include "WsmanClientCatch.h"

TimeSynchronizationClient::TimeSynchronizationClient(unsigned int port) :
	BaseWSManClient(port), m_TimeSyncState(TIMESYNCSTATE_DEFAULT_TRUE), m_isInit(false)
{
}

TimeSynchronizationClient::TimeSynchronizationClient(unsigned int port, const std::string &User, const std::string &Password) :
	BaseWSManClient(port, User, Password), m_TimeSyncState(TIMESYNCSTATE_DEFAULT_TRUE), m_isInit(false)
{
}

TimeSynchronizationClient::~TimeSynchronizationClient()
{
}

bool TimeSynchronizationClient::Init()
{
	if (m_isInit) return true;
	try 
	{
		if (!m_endpoint)
			SetEndpoint();
		//Lock WsMan to prevent reentry
		std::lock_guard<std::mutex> lock(WsManSemaphore());
		m_service.WsmanClient(m_client.get());
		m_service.Get();
		m_isInit = true;
	}
	CATCH_exception("TimeSynchronizationClient::Init")
	return m_isInit;
}

bool TimeSynchronizationClient::UpdateTimeSyncState()
{
	bool ret = false;
	m_TimeSyncState = TIMESYNCSTATE_TIMESYNC_DISABLED; //These is FALSE value if the LocalTimeSyncEnabled FW property.
	try
	{
		if (m_service.LocalTimeSyncEnabledExists())
		{
			unsigned int state = m_service.LocalTimeSyncEnabled();
			if (state == TIMESYNCSTATE_TIMESYNC_DISABLED || state == TIMESYNCSTATE_CONFIGURED_TRUE || state == TIMESYNCSTATE_DEFAULT_TRUE)
			{
				m_TimeSyncState = state;
				ret = true;
			}
		}
	}
	CATCH_exception("TimeSynchronizationClient::UpdateTimeSyncState")
	return ret;
}

bool TimeSynchronizationClient::GetLocalTimeSyncEnabledState(bool & state)
{
	if (!Init())
	{
		WSMAN_ERROR("GetLocalTimeSyncEnabledState Init return false!\n");
		return false;
	}
	//recheck the update state (in case it was changed since the last init.
	if (!UpdateTimeSyncState())
	{
		WSMAN_ERROR("Error: Failed to Get the time sync state in in TimeSynchronizationClient::GetLocalTimeSyncEnabledState\n");
		return false;
	}

	state = ((m_TimeSyncState == TIMESYNCSTATE_CONFIGURED_TRUE || m_TimeSyncState == TIMESYNCSTATE_DEFAULT_TRUE) ? true : false);

	return true;
}

bool TimeSynchronizationClient::GetAMTTime(unsigned int & time)
{	
	if (!Init())
	{
		WSMAN_ERROR("GetAMTTime Init return false!\n");
		return false;
	}

	try
	{
		int ret = m_service.GetLowAccuracyTimeSynch(m_time);
		if (ret != 0)
		{
			WSMAN_ERROR("Error: Failed while calling GetLowAccuracyTimeSynch\n");
			return false;
		}
		if (!m_time.Ta0Exists())
		{
			WSMAN_ERROR("Error: Time object doesn't exist\n");
			return false;
		}
		time = m_time.Ta0();
	}
	CATCH_exception_return("TimeSynchronizationClient::GetAMTTime")
	return true;
}

bool TimeSynchronizationClient::SetAMTTime(unsigned int time)
{
	if (!Init())
		return false;
	
	unsigned int currTime = 0;
	if (!GetAMTTime(currTime))
	{
		return false;
	}

	try {
		Intel::Manageability::Cim::Typed::AMT_TimeSynchronizationService::SetHighAccuracyTimeSynch_INPUT input;

		input.Ta0(currTime);
		input.Tm1(time);
		input.Tm2(time);

		int ret = m_service.SetHighAccuracyTimeSynch(input);
		if (ret != 0)
		{
			WSMAN_ERROR("Error: failed while calling SetHighAccuracyTimeSynch\n");
			return false;
		}
	}
	CATCH_exception_return("TimeSynchronizationClient::SetAMTTime")
	return true;
}