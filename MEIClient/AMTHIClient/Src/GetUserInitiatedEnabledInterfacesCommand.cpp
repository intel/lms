/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2010-2015 Intel Corporation
 */
/*++

@file: GetUserInitiatedEnabledInterfacesCommand.cpp

--*/

#include "GetUserInitiatedEnabledInterfacesCommand.h"
#include <string.h>

using namespace std;

using namespace Intel::MEI_Client::AMTHI_Client;

GetUserInitiatedEnabledInterfacesCommand::GetUserInitiatedEnabledInterfacesCommand()
{
	shared_ptr<MEICommandRequest> tmp(new GetUserInitiatedEnabledInterfacesRequest());
	m_request = tmp;
	Transact();
}

void GetUserInitiatedEnabledInterfacesCommand::reTransact()
{
	shared_ptr<MEICommandRequest> tmp(new GetUserInitiatedEnabledInterfacesRequest());
	m_request = tmp;
	Transact();
}

GET_USER_INITIATED_ENABLED_INTERFACES_RESPONSE
GetUserInitiatedEnabledInterfacesCommand::getResponse()
{
	return m_response->getResponse();
}

void
GetUserInitiatedEnabledInterfacesCommand::parseResponse(const vector<uint8_t>& buffer)
{
	shared_ptr<AMTHICommandResponse<GET_USER_INITIATED_ENABLED_INTERFACES_RESPONSE>> tmp(
		new AMTHICommandResponse<GET_USER_INITIATED_ENABLED_INTERFACES_RESPONSE> (buffer, RESPONSE_COMMAND_NUMBER));
	m_response = tmp;
}

std::vector<uint8_t> 
GetUserInitiatedEnabledInterfacesRequest::SerializeData()
{
	vector<uint8_t> output;
	return output;
}
