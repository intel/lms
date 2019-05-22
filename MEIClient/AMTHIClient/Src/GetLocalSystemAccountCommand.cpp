/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2010-2015 Intel Corporation
 */
/*++

@file: GetLocalSystemAccountCommand.cpp

--*/

#include "GetLocalSystemAccountCommand.h"
#include "StatusCodeDefinitions.h"
//#include <string.h>

using namespace std;

using namespace Intel::MEI_Client::AMTHI_Client;

GetLocalSystemAccountCommand::GetLocalSystemAccountCommand()
{
	shared_ptr<MEICommandRequest> tmp(new GetLocalSystemAccountRequest());
	m_request = tmp;
	Transact();
}

void GetLocalSystemAccountCommand::reTransact()
{
	shared_ptr<MEICommandRequest> tmp(new GetLocalSystemAccountRequest());
	m_request = tmp;
	Transact();
}

GET_LOCAL_SYSTEM_ACCOUNT_RESPONSE GetLocalSystemAccountCommand::getResponse()
{
	return m_response->getResponse();
}

void
GetLocalSystemAccountCommand::parseResponse(const vector<uint8_t>& buffer)
{
	shared_ptr<AMTHICommandResponse<GET_LOCAL_SYSTEM_ACCOUNT_RESPONSE>> tmp(new AMTHICommandResponse<GET_LOCAL_SYSTEM_ACCOUNT_RESPONSE>(buffer, RESPONSE_COMMAND_NUMBER));
	m_response = tmp;
}

std::vector<uint8_t> 
GetLocalSystemAccountRequest::SerializeData()
{
	vector<uint8_t> output(40,0); //"Reserved"
	return output;
}

