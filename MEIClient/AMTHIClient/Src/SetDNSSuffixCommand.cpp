/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2010-2019 Intel Corporation
 */
/*++

@file: SetDNSSuffixCommand.cpp

--*/

#include "SetDNSSuffixCommand.h"
#include "StatusCodeDefinitions.h"
#include <string.h>

using namespace std;
using namespace Intel::MEI_Client::AMTHI_Client;

SetDNSSuffixCommand::SetDNSSuffixCommand(const std::string &suffix)
{
	shared_ptr<MEICommandRequest> tmp(new SetDNSSuffixRequest(suffix));
	m_request = tmp;
	Transact();
}

void SetDNSSuffixCommand::reTransact(const std::string &suffix)
{
	shared_ptr<MEICommandRequest> tmp(new SetDNSSuffixRequest(suffix));
	m_request = tmp;
	Transact();
}

void
SetDNSSuffixCommand::parseResponse(const vector<uint8_t>& buffer)
{
	shared_ptr<AMTHICommandResponse<SetDNSSuffix_RESPONSE>> tmp(new AMTHICommandResponse<SetDNSSuffix_RESPONSE>(buffer, RESPONSE_COMMAND_NUMBER));
	m_response = tmp;
}

std::vector<uint8_t> 
SetDNSSuffixRequest::SerializeData()
{
	
	vector<uint8_t> output = m_str.serialize();
	return output;
}

