/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2010-2019 Intel Corporation
 */
/*++

@file: OpenUserInitiatedConnectionCommand.cpp

--*/

#include "OpenUserInitiatedConnectionCommand.h"
#include "StatusCodeDefinitions.h"
#include <string.h>

using namespace std;

using namespace Intel::MEI_Client::AMTHI_Client;

OpenUserInitiatedConnectionCommand::OpenUserInitiatedConnectionCommand()
{
	shared_ptr<MEICommandRequest> tmp(new OpenUserInitiatedConnectionRequest());
	m_request = tmp;
	Transact();
}

void
OpenUserInitiatedConnectionCommand::parseResponse(const vector<uint8_t>& buffer)
{
	shared_ptr<AMTHICommandResponse<OpenUserInitiatedConnection_RESPONSE>> tmp(new AMTHICommandResponse<OpenUserInitiatedConnection_RESPONSE>(buffer, RESPONSE_COMMAND_NUMBER));
	m_response = tmp;
}

std::vector<uint8_t> 
OpenUserInitiatedConnectionRequest::SerializeData()
{
	vector<uint8_t> output;
	return output;
}

	