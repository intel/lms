/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2009-2023 Intel Corporation
 */
/*++

@file: HostBootReasonClient.cpp

--*/

#include "HostBootReasonClient.h"
#include "IPS_HostBootReason.h"
#include "WsmanClientLog.h"
#include "WsmanClientCatch.h"

HostBootReasonClient::HostBootReasonClient(unsigned int port) : BaseWSManClient(port), m_isInit(false)
{
}

HostBootReasonClient::HostBootReasonClient(unsigned int port, const std::string &User, const std::string &Password) :
	BaseWSManClient(port, User, Password), m_isInit(false)
{
}

HostBootReasonClient::~HostBootReasonClient()
{
}

bool HostBootReasonClient::Init()
{
	
	if (m_isInit)
	{
		return true;
	}
	m_isInit = false;
	try {
		if (!m_endpoint)
		{
			SetEndpoint();
		
			m_isInit = true;
			
		}
	}
	CATCH_exception("HostBootReasonClient::Init")
	return m_isInit;
}

bool HostBootReasonClient::GetHostResetReason(HOST_RESET_REASON& resetReason, SX_STATES& previousSxState)
{	
	if (!Init())
	{
		return false;
	}
	try 
	{
		//Lock WsMan to prevent reentry
		std::lock_guard<std::mutex> lock(WsManSemaphore());
		std::vector<std::shared_ptr<Intel::Manageability::Cim::Typed::IPS_HostBootReason>> HostBootReason =
			Intel::Manageability::Cim::Typed::IPS_HostBootReason::Enumerate(m_client.get());
		if (HostBootReason.empty())
			return false;
		//only one instance of IPS_HostBootReason should be queried from the FW
		if (HostBootReason[0]->ReasonExists() && HostBootReason[0]->PreviousSxStateExists())
		{
			resetReason = (HOST_RESET_REASON)(HostBootReason[0]->Reason());

			previousSxState = (SX_STATES)(HostBootReason[0]->PreviousSxState());
			WSMAN_DEBUG("HostBootReasonClient::GetHostResetReason ended successfully\n");
			return true;
		}
	}
	CATCH_exception("HostBootReasonClient::GetHostResetReason")
	return false;
}