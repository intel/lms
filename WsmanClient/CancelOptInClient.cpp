/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2009-2023 Intel Corporation
 */
/*++

@file: CancelOptInClient.cpp

--*/

#include "CancelOptInClient.h"
#include "WsmanClientLog.h"
#include "WsmanClientCatch.h"

CancelOptInClient::CancelOptInClient(unsigned int port) : BaseWSManClient(port), m_isInit(false)
{
}

CancelOptInClient::~CancelOptInClient()
{
}

bool CancelOptInClient::CancelOptIn(unsigned int* pReturnValue)
{
	WSMAN_DEBUG("CancelOptInClient::CancelOptIn\n");

	try 
	{
		if (!Init(false))
			return false;
		
		//Lock WsMan to prevent reentry
		std::lock_guard<std::mutex> lock(WsManSemaphore());
		unsigned int returnVal = m_service.CancelOptIn();
		WSMAN_DEBUG("CancelOptInClient::CancelOptIn ReturnValue=%d\n",returnVal);
		*pReturnValue=returnVal;
		return true;
	}
	CATCH_exception("CancelOptInClient::CancelOptIn")
	return false;
}

bool CancelOptInClient::Init(bool forceGet)
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
	CATCH_exception("CancelOptInClient::Init")

	return m_isInit;
}


bool CancelOptInClient::GetUserConsentState(short* pState, short* pPolicy)
{
	try {
	
		if(!Init())
		{
			return false;
		}
		if (m_service.OptInStateExists() && m_service.OptInRequiredExists())
		{
			*pState =  m_service.OptInState();	
			*pPolicy = (short) m_service.OptInRequired();
			return true;
		}
		return false;
		
	}
	CATCH_exception_return("CancelOptInClient::GetUserConsentState")

	return true;
}
