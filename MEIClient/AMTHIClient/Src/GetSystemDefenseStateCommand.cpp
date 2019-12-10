/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2010-2019 Intel Corporation
 */
/*++

@file: GetSystemDefenseStateCommand.cpp

--*/

#include <iostream>
#include "GetSystemDefenseStateCommand.h"
#include "StatusCodeDefinitions.h"
#include <string.h>

using namespace std;
using namespace Intel::MEI_Client::AMTHI_Client;

GetSystemDefenseStateCommand::GetSystemDefenseStateCommand()
{
	shared_ptr<MEICommandRequest> tmp(new GetSystemDefenseStateRequest());
	m_request = tmp;
	Transact();
}

GET_SYSTEM_DEFENSE_STATE_RESPONSE GetSystemDefenseStateCommand::getResponse()
{
	return m_response->getResponse();
}

void
GetSystemDefenseStateCommand::parseResponse(const vector<uint8_t>& buffer)
{
	shared_ptr<AMTHICommandResponse<GET_SYSTEM_DEFENSE_STATE_RESPONSE>> tmp(
		new AMTHICommandResponse<GET_SYSTEM_DEFENSE_STATE_RESPONSE>(buffer, RESPONSE_COMMAND_NUMBER));
	m_response = tmp;
}




std::vector<uint8_t> 
GetSystemDefenseStateRequest::SerializeData()
{
	uint32_t id = SYSTEM_DEFENSE_ID;
	vector<uint8_t> output((std::uint8_t*)&id, (std::uint8_t*)&id + sizeof(uint32_t));
	return output;
}




	
