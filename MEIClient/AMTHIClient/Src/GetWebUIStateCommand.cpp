/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2010-2019 Intel Corporation
 */
/*++

@file: GetWebUIStateCommand.cpp

--*/

#include <iostream>
#include "GetWebUIStateCommand.h"
#include "StatusCodeDefinitions.h"
#include <string.h>

using namespace std;
using namespace Intel::MEI_Client::AMTHI_Client;

GetWebUIStateCommand::GetWebUIStateCommand()
{
	shared_ptr<MEICommandRequest> tmp(new GetWebUIStateRequest());
	m_request = tmp;
	Transact();
}

void GetWebUIStateCommand::reTransact()
{
	shared_ptr<MEICommandRequest> tmp(new GetWebUIStateRequest());
	m_request = tmp;
	Transact();
}

GET_WEB_UI_STATE_RESPONSE GetWebUIStateCommand::getResponse()
{
	return m_response->getResponse();
}

void
GetWebUIStateCommand::parseResponse(const vector<uint8_t>& buffer)
{
	shared_ptr<AMTHICommandResponse<GET_WEB_UI_STATE_RESPONSE>> tmp(
		new AMTHICommandResponse<GET_WEB_UI_STATE_RESPONSE>(buffer, RESPONSE_COMMAND_NUMBER));
	m_response = tmp;
}




std::vector<uint8_t> 
GetWebUIStateRequest::SerializeData()
{
	uint32_t id = WEB_UI_STATE_ID;
	vector<uint8_t> output((std::uint8_t*)&id, (std::uint8_t*)&id + sizeof(uint32_t));
	return output;
}




	
