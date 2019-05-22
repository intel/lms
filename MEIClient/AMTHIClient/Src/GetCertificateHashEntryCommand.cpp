/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2010-2015 Intel Corporation
 */
/*++

@file: GetCertificateHashEntryCommand.cpp

--*/

#include "GetCertificateHashEntryCommand.h"
#include <string.h>

using namespace std;

using namespace Intel::MEI_Client::AMTHI_Client;

GetCertificateHashEntryCommand::GetCertificateHashEntryCommand(uint32_t hashHandle)
{
	shared_ptr<MEICommandRequest> tmp(new GetCertificateHashEntryRequest(hashHandle));
	m_request = tmp;
	Transact();
}

void GetCertificateHashEntryCommand::reTransact(uint32_t hashHandle)
{
	shared_ptr<MEICommandRequest> tmp(new GetCertificateHashEntryRequest(hashHandle));
	m_request = tmp;
	Transact();
}


GET_CERTIFICATE_HASH_ENTRY_RESPONSE 
GetCertificateHashEntryCommand::getResponse()
{
	return m_response->getResponse();
}

void GetCertificateHashEntryCommand::parseResponse(const vector<uint8_t>& buffer)
{
shared_ptr<AMTHICommandResponse<GET_CERTIFICATE_HASH_ENTRY_RESPONSE>> tmp(
	new AMTHICommandResponse<GET_CERTIFICATE_HASH_ENTRY_RESPONSE>(buffer, RESPONSE_COMMAND_NUMBER));
	m_response = tmp;
}

std::vector<uint8_t> 
GetCertificateHashEntryRequest::SerializeData()
{	
	vector<uint8_t> output((std::uint8_t*)&_hashHandle, (std::uint8_t*)&_hashHandle + sizeof(uint32_t));
	return output;
}

