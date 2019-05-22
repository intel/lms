/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2010-2015 Intel Corporation
 */
/*++

@file: EnumerateHashHandlesCommand.cpp

--*/

#include "EnumerateHashHandlesCommand.h"
#include <string.h>

using namespace std;

using namespace Intel::MEI_Client::AMTHI_Client;

EnumerateHashHandlesCommand::EnumerateHashHandlesCommand ()
{
	shared_ptr<MEICommandRequest> tmp(new EnumerateHashHandlesRequest ());
	m_request = tmp;
	Transact();
}

void EnumerateHashHandlesCommand::reTransact()
{
	shared_ptr<MEICommandRequest> tmp(new EnumerateHashHandlesRequest ());
	m_request = tmp;
	Transact();
}

ENUMERATE_HASH_HANDLES_RESPONSE
EnumerateHashHandlesCommand::getResponse() 
{
	return m_response->getResponse();
}
				
void 
EnumerateHashHandlesCommand::parseResponse(const vector<uint8_t>& buffer)
{
shared_ptr<AMTHICommandResponse<ENUMERATE_HASH_HANDLES_RESPONSE> > tmp (
	new AMTHICommandResponse<ENUMERATE_HASH_HANDLES_RESPONSE>(buffer, RESPONSE_COMMAND_NUMBER));
	m_response = tmp;
}

std::vector<uint8_t> 
EnumerateHashHandlesRequest::SerializeData()
{	
	vector<uint8_t> output;
	return output;
}
	