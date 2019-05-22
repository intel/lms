/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2010-2015 Intel Corporation
 */
/*++

@file: GetRemoteAccessConnectionStatusCommand.cpp

--*/

#include "GetRemoteAccessConnectionStatusCommand.h"
#include "StatusCodeDefinitions.h"
#include <string.h>

using namespace std;

using namespace Intel::MEI_Client::AMTHI_Client;

GetRemoteAccessConnectionStatusCommand::GetRemoteAccessConnectionStatusCommand()
{
	shared_ptr<MEICommandRequest> tmp(new GetRemoteAccessConnectionStatusRequest());
	m_request = tmp;
	Transact();
}

void GetRemoteAccessConnectionStatusCommand::reTransact()
{
	shared_ptr<MEICommandRequest> tmp(new GetRemoteAccessConnectionStatusRequest());
	m_request = tmp;
	Transact();
}

REMOTE_ACCESS_STATUS GetRemoteAccessConnectionStatusCommand::getResponse()
{
	return m_response->getResponse();
}

void
GetRemoteAccessConnectionStatusCommand::parseResponse(const vector<uint8_t>& buffer)
{
	shared_ptr<AMTHICommandResponse<REMOTE_ACCESS_STATUS>> tmp(new AMTHICommandResponse<REMOTE_ACCESS_STATUS>(buffer, RESPONSE_COMMAND_NUMBER));
	m_response = tmp;
}

std::vector<uint8_t> 
GetRemoteAccessConnectionStatusRequest::SerializeData()
{
	
	vector<uint8_t> output;
	return output;
}






	

	