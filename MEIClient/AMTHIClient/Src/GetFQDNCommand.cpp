/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2010-2019 Intel Corporation
 */
/*++

@file: GetFQDNCommand.cpp

--*/

#include "GetFQDNCommand.h"
#include "StatusCodeDefinitions.h"
#include <string.h>

using namespace std;

using namespace Intel::MEI_Client::AMTHI_Client;

GetFQDNCommand::GetFQDNCommand()
{
	shared_ptr<MEICommandRequest> tmp(new GetFQDNRequest());
	m_request = tmp;
	Transact();
}

GET_FQDN_RESPONSE GetFQDNCommand::getResponse()
{
	return m_response->getResponse();
}

void
GetFQDNCommand::parseResponse(const vector<uint8_t>& buffer)
{
	shared_ptr<AMTHICommandResponse<GET_FQDN_RESPONSE>> tmp(new AMTHICommandResponse<GET_FQDN_RESPONSE>(buffer, RESPONSE_COMMAND_NUMBER));
	m_response = tmp;
}




	

	