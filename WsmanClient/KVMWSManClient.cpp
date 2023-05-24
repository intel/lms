/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2009-2023 Intel Corporation
 */
/*++

@file: KVMWSManClient.cpp

--*/

#include "KVMWSManClient.h"
#include "WsmanClientLog.h"
#include "WsmanClientCatch.h"

KVMWSManClient::KVMWSManClient(unsigned int port) : BaseWSManClient(port), m_isInit(false), m_isSAPInit(false)
{

}

KVMWSManClient::~KVMWSManClient()
{
}

bool KVMWSManClient::GetMEBxState(bool* MEBxState)
{
	try 
	{
		if (!Init())
			return false;
		if (m_service.EnabledByMEBxExists())
		{
			*MEBxState = m_service.EnabledByMEBx(); 			
			return true;
		}
		WSMAN_DEBUG("ERROR: IPS_KVMRedirectionSettingData.EnabledByMEBxExists returned false!\n");
	}
	CATCH_exception("KVMWSManClient::GetMEBxState")

	return false;
}

bool KVMWSManClient::TerminateKVMSession(void)
{
	try 
	{
		if (!Init())
			return false;
		//Lock WsMan to prevent reentry
		std::lock_guard<std::mutex> lock(WsManSemaphore());
		unsigned int returnVal = m_service.TerminateSession();
		if (returnVal != WSMAN_AMT_ERROR_SUCCESS)
		{
			WSMAN_DEBUG("ERROR: IPS_KVMRedirectionSettingData.TerminateSessiin returned %d\n", returnVal);
			return false;
		}
	}
	CATCH_exception_return("KVMWSManClient::TerminateKVMSession")

	return true;
}


bool KVMWSManClient::KVMRedirectionState(unsigned short* state) 
{
	try 
	{ 
		if (!SAPInit())
		{
			return false;
		}
		if (m_SAPService.EnabledStateExists())
		{
			*state = m_SAPService.EnabledState();
			return true;
		}
		return false;
	}
	CATCH_exception_return("KVMWSManClient::EnabledStateExists")
	return true;
}

bool KVMWSManClient::Init(bool forceGet)
{
	if (!forceGet && m_isInit) return true;
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
	CATCH_exception("KVMWSManClient::Init")

	return m_isInit;	
}

bool KVMWSManClient::SAPInit(bool forceGet)
{
	if (!forceGet && m_isSAPInit) return true;
	m_isSAPInit = false;
	
	try 
	{
		if (!m_endpoint)
			SetEndpoint();

		//Lock WsMan to prevent reentry
		std::lock_guard<std::mutex> lock(WsManSemaphore());
		m_SAPService.WsmanClient(m_client.get());
		m_SAPService.Get();
		m_isSAPInit = true;
	}
	CATCH_exception("KVMWSManClient::SAPInit")

	return m_isSAPInit;	
}