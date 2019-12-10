/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2010-2019 Intel Corporation
 */
/*++

@file: GetPIDCommand.cpp

--*/

#include "GetPIDCommand.h"
#include "StatusCodeDefinitions.h"
#include <string.h>

using namespace std;

using namespace Intel::MEI_Client::AMTHI_Client;

GetPIDCommand::GetPIDCommand()
{
	shared_ptr<MEICommandRequest> tmp(new GetPIDRequest());
	m_request = tmp;
	Transact();
}

GET_PID_RESPONSE GetPIDCommand::getResponse()
{
	return m_response->getResponse();
}

void
GetPIDCommand::parseResponse(const vector<uint8_t>& buffer)
{
	shared_ptr<AMTHICommandResponse<GET_PID_RESPONSE>> tmp(
		new AMTHICommandResponse<GET_PID_RESPONSE>(buffer, RESPONSE_COMMAND_NUMBER));
	m_response = tmp;
}

std::vector<uint8_t> 
GetPIDRequest::SerializeData()
{
	vector<uint8_t> output;
	return output;
}
