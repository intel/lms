/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2010-2015 Intel Corporation
 */
/*++

@file: GetCodeVersionCommand.cpp

--*/

#include "GetCodeVersionCommand.h"
#include "StatusCodeDefinitions.h"
#include <string.h>

using namespace std;

using namespace Intel::MEI_Client::AMTHI_Client;

GetCodeVersionCommand::GetCodeVersionCommand()
{
	shared_ptr<MEICommandRequest> tmp(new GetCodeVersionRequest());
	m_request = tmp;
	Transact();

}

CODE_VERSIONS 
GetCodeVersionCommand::getResponse()
{
	return m_response->getResponse();
}

void
GetCodeVersionCommand::parseResponse(const vector<uint8_t>& buffer)
{
	shared_ptr<AMTHICommandResponse<CODE_VERSIONS>> tmp(new AMTHICommandResponse<CODE_VERSIONS>(buffer, RESPONSE_COMMAND_NUMBER));
	m_response = tmp;
}

	

	