/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2009-2019 Intel Corporation
 */
/*++

@file: EthernetSettingsWSManClient.cpp

--*/

#include "EthernetSettingsWSManClient.h"
#include "global.h"

EthernetSettingsWSManClient::EthernetSettingsWSManClient() : m_isInit(false)
{
}

EthernetSettingsWSManClient::EthernetSettingsWSManClient(const std::string &userName, const std::string &password) :
	BaseWSManClient(userName, password), m_isInit(false)
{
}

EthernetSettingsWSManClient::~EthernetSettingsWSManClient()
{
}

unsigned int EthernetSettingsWSManClient::Enumerate(std::vector<std::shared_ptr<Intel::Manageability::Cim::Typed::AMT_EthernetPortSettings>> &EthernetSettings)
{
	unsigned int retValue = ERROR_UNKNOWN_ERROR;

	try {
		if (!m_endpoint)
			SetEndpoint();
		//Lock WsMan to prevent reentry
		std::lock_guard<std::mutex> lock(WsManSemaphore());
		EthernetSettings = Intel::Manageability::Cim::Typed::AMT_EthernetPortSettings::Enumerate(m_client.get());
		retValue = 0;
	}
	catch (std::exception& e)
	{
		const char* reason =  e.what();
		retValue = ERROR_UNKNOWN_ERROR;
		UNS_DEBUG("Error: failed while calling get AMT_EthernetPortSettings: %C\n", reason);
		m_endpoint = false;
	}	
	return retValue;
}