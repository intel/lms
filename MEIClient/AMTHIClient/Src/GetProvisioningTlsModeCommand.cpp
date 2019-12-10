/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2010-2019 Intel Corporation
 */
/*++

@file: GetProvisioningTLSModeCommand.cpp

--*/

#include "GetProvisioningTlsModeCommand.h"
#include "StatusCodeDefinitions.h"
#include <string.h>

using namespace std;

using namespace Intel::MEI_Client::AMTHI_Client;

GetProvisioningTLSModeCommand::GetProvisioningTLSModeCommand()
{
	shared_ptr<MEICommandRequest> tmp(new GetProvisioningTLSModeRequest());
	m_request = tmp;
	Transact();
}

PROV_TLS_MODE_RESPONSE GetProvisioningTLSModeCommand::getResponse()
{
	return m_response->getResponse();
}

void
GetProvisioningTLSModeCommand::parseResponse(const vector<uint8_t>& buffer)
{
	shared_ptr<AMTHICommandResponse<PROV_TLS_MODE_RESPONSE>> tmp(new AMTHICommandResponse<PROV_TLS_MODE_RESPONSE>(buffer, RESPONSE_COMMAND_NUMBER));
	m_response = tmp;
}

std::vector<uint8_t> 
GetProvisioningTLSModeRequest::SerializeData()
{
	vector<uint8_t> output;
	return output; 
}

	