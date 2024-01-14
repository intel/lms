/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2009-2023 Intel Corporation
 */
/*++

@file: EthernetSettingsWSManClient.cpp

--*/

#include "EthernetSettingsWSManClient.h"
#include "WsmanClientLog.h"
#include "WsmanClientCatch.h"

EthernetSettingsWSManClient::EthernetSettingsWSManClient(unsigned int port) : BaseWSManClient(port), m_isInit(false)
{
}

EthernetSettingsWSManClient::~EthernetSettingsWSManClient()
{
}

unsigned int EthernetSettingsWSManClient::Enumerate(std::vector<std::shared_ptr<Intel::Manageability::Cim::Typed::AMT_EthernetPortSettings>> &EthernetSettings)
{
	try
	{
		if (!m_endpoint)
			SetEndpoint();
		//Lock WsMan to prevent reentry
		std::lock_guard<std::mutex> lock(WsManSemaphore());
		EthernetSettings = Intel::Manageability::Cim::Typed::AMT_EthernetPortSettings::Enumerate(m_client.get());
	}
	CATCH_exception_return("HBPWSManClient::GetConfigurationInfo")

	return true;
}