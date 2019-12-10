/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2010-2019 Intel Corporation
 */
/*++

@file: GetUUIDCommand.cpp

--*/

#include "GetUUIDCommand.h"
#include <string.h>

using namespace std;

using namespace Intel::MEI_Client::AMTHI_Client;

GetUUIDCommand::GetUUIDCommand()
{
	shared_ptr<MEICommandRequest> tmp(new GetUUIDRequest());
	m_request = tmp;
	Transact();
}

GET_UUID_RESPONSE
GetUUIDCommand::getResponse()
{
	return m_response->getResponse();
}

void
GetUUIDCommand::parseResponse(const vector<uint8_t>& buffer)
{
	shared_ptr<AMTHICommandResponse<GET_UUID_RESPONSE>> tmp(
		new AMTHICommandResponse<GET_UUID_RESPONSE>(buffer, RESPONSE_COMMAND_NUMBER));
	m_response = tmp;
}

std::vector<uint8_t> 
GetUUIDRequest::SerializeData()
{
	vector<uint8_t> output;
	return output;
}
