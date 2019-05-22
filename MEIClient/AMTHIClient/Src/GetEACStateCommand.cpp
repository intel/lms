/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2010-2019 Intel Corporation
 */
/*++

@file: GetEACStateCommand.cpp

--*/

#include <iostream>
#include "GetEACStateCommand.h"
#include "StatusCodeDefinitions.h"
#include <string.h>

using namespace std;
using namespace Intel::MEI_Client::AMTHI_Client;

GetEACStateCommand::GetEACStateCommand()
{
	shared_ptr<MEICommandRequest> tmp(new GetEACStateRequest());
	m_request = tmp;
	Transact();
}

void GetEACStateCommand::reTransact()
{
	shared_ptr<MEICommandRequest> tmp(new GetEACStateRequest());
	m_request = tmp;
	Transact();
}

GET_EAC_STATE_RESPONSE GetEACStateCommand::getResponse()
{
	return m_response->getResponse();
}

void
GetEACStateCommand::parseResponse(const vector<uint8_t>& buffer)
{
	shared_ptr<AMTHICommandResponse<GET_EAC_STATE_RESPONSE>> tmp(
		new AMTHICommandResponse<GET_EAC_STATE_RESPONSE>(buffer, RESPONSE_COMMAND_NUMBER));
	m_response = tmp;
}

std::vector<uint8_t> 
GetEACStateRequest::SerializeData()
{
	uint32_t id = EAC_ID;
	vector<uint8_t> output((std::uint8_t*)&id, (std::uint8_t*)&id + sizeof(uint32_t));
	return output;
}




	
