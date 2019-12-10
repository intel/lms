/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2010-2019 Intel Corporation
 */
/*++

@file: GetLastHostResetReasonCommand.cpp

--*/

#include "GetLastHostResetReasonCommand.h"
#include "StatusCodeDefinitions.h"
#include <string.h>

using namespace std;

using namespace Intel::MEI_Client::AMTHI_Client;

GetLastHostResetReasonCommand::GetLastHostResetReasonCommand()
{
	shared_ptr<MEICommandRequest> tmp(new GetLastHostResetReasonRequest());
	m_request = tmp;
	Transact();
}

LAST_HOST_RESET_REASON_RESPONSE GetLastHostResetReasonCommand::getResponse()
{
	return m_response->getResponse();
}

void
GetLastHostResetReasonCommand::parseResponse(const vector<uint8_t>& buffer)
{
	shared_ptr<AMTHICommandResponse<LAST_HOST_RESET_REASON_RESPONSE>> tmp(new AMTHICommandResponse<LAST_HOST_RESET_REASON_RESPONSE>(buffer, RESPONSE_COMMAND_NUMBER));
	m_response = tmp;
}

std::vector<uint8_t> 
GetLastHostResetReasonRequest::SerializeData()
{
	vector<uint8_t> output;
	return output;
}

