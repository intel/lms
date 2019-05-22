/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2010-2015 Intel Corporation
 */
/*++

@file: GetDNSSuffixListCommand.cpp

--*/

#include "GetDNSSuffixListCommand.h"
#include <string.h>

using namespace std;

using namespace Intel::MEI_Client::AMTHI_Client;

GetDNSSuffixListCommand::GetDNSSuffixListCommand ()
{
	shared_ptr<MEICommandRequest> tmp(new GetDNSSuffixListRequest ());
	m_request = tmp;
	Transact();
}

void GetDNSSuffixListCommand::reTransact()
{
	shared_ptr<MEICommandRequest> tmp(new GetDNSSuffixListRequest ());
	m_request = tmp;
	Transact();
}

GET_DNS_SUFFIX_LIST_RESPONSE
GetDNSSuffixListCommand::getResponse() 
{
	return m_response->getResponse();
}
				
void 
GetDNSSuffixListCommand::parseResponse(const vector<uint8_t>& buffer)
{
shared_ptr<AMTHICommandResponse<GET_DNS_SUFFIX_LIST_RESPONSE> > tmp (
	new AMTHICommandResponse<GET_DNS_SUFFIX_LIST_RESPONSE>(buffer, RESPONSE_COMMAND_NUMBER));
	m_response = tmp;
}

std::vector<uint8_t> 
GetDNSSuffixListRequest::SerializeData()
{	
	vector<uint8_t> output;
	return output;
}
	