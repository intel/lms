/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2009-2020 Intel Corporation
 */
/*++

@file: HostBootReasonClient.cpp

--*/

#include "HostBootReasonClient.h"
#include "IPS_HostBootReason.h"
#include "WsmanClientLog.h"
#include "WsmanClientCatch.h"

HostBootReasonClient::HostBootReasonClient() : m_isInit(false)
{
}

HostBootReasonClient::HostBootReasonClient(const std::string &User, const std::string &Password) :
	BaseWSManClient(User, Password), m_isInit(false)
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
		using Intel::Manageability::Cim::Typed::IPS_HostBootReason;
		//Lock WsMan to prevent reentry
		std::lock_guard<std::mutex> lock(WsManSemaphore());
		std::vector<std::shared_ptr<IPS_HostBootReason>> HostBootReason =
			IPS_HostBootReason::Enumerate(m_client.get()); 	
		std::vector<std::shared_ptr<IPS_HostBootReason>>::iterator HostBootReasonIterator;
				
		for (HostBootReasonIterator = HostBootReason.begin(); 
			 HostBootReasonIterator != HostBootReason.end() ; 
			 HostBootReasonIterator++)
		{
			IPS_HostBootReason *curReason = HostBootReasonIterator->get();
			if (!curReason)
				return false;
			//only one instance of IPS_HostBootReason should be queried from the FW
			if (curReason->ReasonExists() && curReason->PreviousSxStateExists())
			{
				resetReason = (HOST_RESET_REASON)(curReason->Reason());
				
				previousSxState = (SX_STATES)(curReason->PreviousSxState());
				WSMAN_DEBUG("HostBootReasonClient::GetHostResetReason ended successfully\n");
				return true;
			}
			else 
			{
				return false;		
			}
		}
	}
	CATCH_exception("HostBootReasonClient::GetHostResetReason")
	return false;
}