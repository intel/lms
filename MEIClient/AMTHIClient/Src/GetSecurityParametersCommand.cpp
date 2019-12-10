/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2010-2019 Intel Corporation
 */
/*++

@file: GetSecurityParametersCommand.cpp

--*/

#include "GetSecurityParametersCommand.h"
#include "StatusCodeDefinitions.h"


using namespace std;

using namespace Intel::MEI_Client::AMTHI_Client;



GetSecurityParametersCommand::GetSecurityParametersCommand()
{
	shared_ptr<MEICommandRequest> tmp(new GetSecurityParametersRequest());
	m_request = tmp;
	Transact();
}

SECURITY_PARAMETERS GetSecurityParametersCommand::getResponse()
{
	return m_response->getResponse();
}

void
GetSecurityParametersCommand::parseResponse(const vector<uint8_t>& buffer)
{
	shared_ptr<AMTHICommandResponse<SECURITY_PARAMETERS>> tmp(new AMTHICommandResponse<SECURITY_PARAMETERS>(buffer, RESPONSE_COMMAND_NUMBER));
	m_response = tmp;
}

