/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2010-2015 Intel Corporation
 */
/*++

@file: GetAMTStateCommand.cpp

--*/

#include "GetAMTStateCommand.h"
#include "StatusCodeDefinitions.h"
#include <string.h>

using namespace std;

using namespace Intel::MEI_Client::AMTHI_Client;

GetAMTStateCommand::GetAMTStateCommand(AMT_UUID StateVariableIdentifier)
{
	shared_ptr<MEICommandRequest> tmp(new GetAMTStateRequest(StateVariableIdentifier));
	m_request = tmp;
	Transact();
}

void GetAMTStateCommand::reTransact(AMT_UUID StateVariableIdentifier)
{
	shared_ptr<MEICommandRequest> tmp(new GetAMTStateRequest(StateVariableIdentifier));
	m_request = tmp;
	Transact();
}

AMT_STATE_RESPONSE GetAMTStateCommand::getResponse()
{
	return m_response->getResponse();
}

void
GetAMTStateCommand::parseResponse(const vector<uint8_t>& buffer)
{
	shared_ptr<AMTHICommandResponse<AMT_STATE_RESPONSE>> tmp(new AMTHICommandResponse<AMT_STATE_RESPONSE>(buffer, RESPONSE_COMMAND_NUMBER));
	m_response = tmp;
}

std::vector<uint8_t> 
GetAMTStateRequest::SerializeData()
{
	vector<uint8_t> output(m_stateVariableIdentifier.amt_uuid, m_stateVariableIdentifier.amt_uuid + sizeof(AMT_UUID));
	return output;
}





	

	