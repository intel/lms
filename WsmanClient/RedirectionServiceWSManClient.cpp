/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2009-2019 Intel Corporation
 */
/*++

@file: RedirectionServiceWSManClient.cpp

--*/

#include "RedirectionServiceWSManClient.h"
#include "global.h"
#include "WsmanClientCatch.h"

RedirectionServiceWSManClient::RedirectionServiceWSManClient() : m_isInit(false)
{
}

RedirectionServiceWSManClient::~RedirectionServiceWSManClient()
{
}

bool RedirectionServiceWSManClient::RedirectionState(unsigned short *state)
{
	if (!Init(true))
		return false;
	if (m_service.EnabledStateExists())
	{
		*state = m_service.EnabledState();
		return true;
	}
	return false;
}

bool RedirectionServiceWSManClient::Init(bool forceGet)
{
	if (!forceGet && m_isInit)
	{
		return true;
	}
	m_isInit = false;
	
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
	CATCH_exception("RedirectionServiceWSManClient::Init")
	
	return m_isInit;
}