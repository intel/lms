/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2009-2019 Intel Corporation
 */
/*++

@file: EthernetSettingsWSManClient.cpp

--*/

#include "EthernetSettingsWSManClient.h"
#include "UNSDebug.h"

using namespace Intel::Manageability::Cim::Typed;
using namespace std;

const std::string EthernetSettingsWSManClient::DEFAULT_USER = "$$uns";
const std::string EthernetSettingsWSManClient::DEFAULT_PASS = "$$uns";

EthernetSettingsWSManClient::EthernetSettingsWSManClient() : BaseWSManClient(DEFAULT_USER, DEFAULT_PASS)
{
	m_isInit = false;
	
}

EthernetSettingsWSManClient::EthernetSettingsWSManClient(
	const std::string &userName, 
	const std::string &password) : BaseWSManClient(userName, password)
{
	m_isInit = false;
	
}

EthernetSettingsWSManClient::~EthernetSettingsWSManClient()
{
}

unsigned int EthernetSettingsWSManClient::Enumerate(vector<shared_ptr<Intel::Manageability::Cim::Typed::AMT_EthernetPortSettings>> &EthernetSettings)
{
	unsigned int retValue = ERROR_UNKNOWN_ERROR;

	try {
		if (!m_endpoint)
			SetEndpoint(false);
		//Lock WsMan to prevent reentry
		std::lock_guard<std::mutex> lock(WsManSemaphore());
		EthernetSettings = AMT_EthernetPortSettings::Enumerate(m_client.get());
		retValue = 0;
	}
	catch (exception& e)
	{
		const char* reason =  e.what();
		retValue = ERROR_UNKNOWN_ERROR;
		DbgPrint("\nError: failed while calling get AMT_EthernetPortSettings\n");
		DbgPrint("%s\n", reason);
		m_endpoint = false;
	}	
	return retValue;
}