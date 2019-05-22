/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2010-2015 Intel Corporation
 */
/*++

@file: GetDNSSuffixCommand.cpp

--*/

#include "GetDNSSuffixCommand.h"
#include "StatusCodeDefinitions.h"
#include <string.h>

using namespace std;

using namespace Intel::MEI_Client::AMTHI_Client;

GetDNSSuffixCommand::GetDNSSuffixCommand()
{
	shared_ptr<MEICommandRequest> tmp(new GetDNSSuffixRequest());
	m_request = tmp;
	Transact();
}

void GetDNSSuffixCommand::reTransact()
{
	shared_ptr<MEICommandRequest> tmp(new GetDNSSuffixRequest());
	m_request = tmp;
	Transact();
}

string GetDNSSuffixCommand::getResponse()
{
	return m_response->getResponse().DNSSuffix;
}

void GetDNSSuffixCommand::parseResponse(const vector<uint8_t>& buffer)
{
	shared_ptr<AMTHICommandResponse<GetDNSSuffix_RESPONSE>> tmp(new AMTHICommandResponse<GetDNSSuffix_RESPONSE>(buffer, RESPONSE_COMMAND_NUMBER));
	m_response = tmp;
}

std::vector<uint8_t> 
GetDNSSuffixRequest::SerializeData()
{	
	vector<uint8_t> output;
	return output;
}

