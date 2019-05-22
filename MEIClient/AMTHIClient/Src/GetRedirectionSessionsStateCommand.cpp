/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2010-2019 Intel Corporation
 */
/*++

@file: GetRedirectionSessionsStateCommand.cpp

--*/

#include <iostream>
#include "GetRedirectionSessionsStateCommand.h"
#include "StatusCodeDefinitions.h"
#include <string.h>

using namespace std;
using namespace Intel::MEI_Client::AMTHI_Client;

GetRedirectionSessionsStateCommand::GetRedirectionSessionsStateCommand()
{
	shared_ptr<MEICommandRequest> tmp(new GetRedirectionSessionsStateRequest());
	m_request = tmp;
	Transact();
}

void GetRedirectionSessionsStateCommand::reTransact()
{
	shared_ptr<MEICommandRequest> tmp(new GetRedirectionSessionsStateRequest());
	m_request = tmp;
	Transact();
}

GET_REDIRECTION_SESSIONS_STATE_RESPONSE GetRedirectionSessionsStateCommand::getResponse()
{
	return m_response->getResponse();
}

void
GetRedirectionSessionsStateCommand::parseResponse(const vector<uint8_t>& buffer)
{
	shared_ptr<AMTHICommandResponse<GET_REDIRECTION_SESSIONS_STATE_RESPONSE>> tmp(
		new AMTHICommandResponse<GET_REDIRECTION_SESSIONS_STATE_RESPONSE>(buffer, RESPONSE_COMMAND_NUMBER));
	m_response = tmp;
}




std::vector<uint8_t> 
GetRedirectionSessionsStateRequest::SerializeData()
{
	uint32_t id = REDIRECTION_ID;
	vector<uint8_t> output((std::uint8_t*)&id, (std::uint8_t*)&id + sizeof(uint32_t));
	return output;
}




	
