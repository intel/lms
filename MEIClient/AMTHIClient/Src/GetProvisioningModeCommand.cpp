/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2010-2015 Intel Corporation
 */
/*++

@file: GetProvisioningModeCommand.cpp

--*/

#include "GetProvisioningModeCommand.h"
#include "StatusCodeDefinitions.h"
#include <string.h>

using namespace std;

using namespace Intel::MEI_Client::AMTHI_Client;

GetProvisioningModeCommand::GetProvisioningModeCommand()
{
	shared_ptr<MEICommandRequest> tmp(new GetProvisioningModeRequest());
	m_request = tmp;
	Transact();
}

void GetProvisioningModeCommand::reTransact()
{
	shared_ptr<MEICommandRequest> tmp(new GetProvisioningModeRequest());
	m_request = tmp;
	Transact();
}

PROVISIONING_MODE_SETTINGS GetProvisioningModeCommand::getResponse()
{
	return m_response->getResponse();
}

void GetProvisioningModeCommand::parseResponse(const vector<uint8_t>& buffer)
{
	shared_ptr<AMTHICommandResponse<PROVISIONING_MODE_SETTINGS>> tmp(new AMTHICommandResponse<PROVISIONING_MODE_SETTINGS>(buffer, RESPONSE_COMMAND_NUMBER));
	m_response = tmp;
}

std::vector<uint8_t> 
GetProvisioningModeRequest::SerializeData()
{	
	vector<uint8_t> output;
	return output;
}

