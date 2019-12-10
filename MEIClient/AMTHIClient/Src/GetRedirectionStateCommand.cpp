/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2010-2019 Intel Corporation
 */
/*++

@file: GetRedirectionStateCommand.cpp

--*/

#include "GetRedirectionStateCommand.h"
#include "StatusCodeDefinitions.h"
#include <string.h>

using namespace std;

using namespace Intel::MEI_Client::AMTHI_Client;

GetRedirectionStateCommand::GetRedirectionStateCommand()
{
	shared_ptr<MEICommandRequest> tmp(new GetRedirectionStateRequest());
	m_request = tmp;
	Transact();
}

REDIRECTION_STATE GetRedirectionStateCommand::getResponse()
{
	return m_response->getResponse();
}

void
GetRedirectionStateCommand::parseResponse(const vector<uint8_t>& buffer)
{
	shared_ptr<AMTHICommandResponse<REDIRECTION_STATE>> tmp(new AMTHICommandResponse<REDIRECTION_STATE>(buffer, RESPONSE_COMMAND_NUMBER));
	m_response = tmp;
}







	

	