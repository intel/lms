/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2026 Intel Corporation
 */
/*++

@file: OptInConfigWSManClient.cpp

--*/

// Implements retrieval of AMT user-consent (opt-in) configuration values.

#include "OptInConfigWSManClient.h"
#include "WsmanClientLog.h"
#include "WsmanClientCatch.h"

OptInConfigWSManClient::OptInConfigWSManClient(unsigned int port) : BaseWSManClient(port)
{
}

OptInConfigWSManClient::~OptInConfigWSManClient()
{
}

bool OptInConfigWSManClient::GetOptInConfig(OptInConfigWSMan& config)
{
	try
	{
		// Read IPS_OptInService state and map available fields to output.
		if (!m_endpoint)
			SetEndpoint();
		//Lock WsMan to prevent reentry
		std::lock_guard<std::mutex> lock(WsManSemaphore());
		m_service.WsmanClient(m_client.get());
		m_service.Get();

		if (m_service.OptInCodeTimeoutExists()) config.OptInCodeTimeout = m_service.OptInCodeTimeout();
		if (m_service.OptInRequiredExists()) config.OptInRequired = m_service.OptInRequired();
		if (m_service.OptInStateExists()) config.OptInState = m_service.OptInState();
		if (m_service.OptInDisplayTimeoutExists()) config.OptInDisplayTimeout = m_service.OptInDisplayTimeout();
	}
	CATCH_exception_return("OptInConfigWSManClient::GetOptInConfig")

	return true;
}
