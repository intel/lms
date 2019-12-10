/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2010-2019 Intel Corporation
 */
/*++

@file: GetMESetupAuditRecordCommand.cpp

--*/

#include "GetMESetupAuditRecordCommand.h"
#include <string.h>

using namespace std;

using namespace Intel::MEI_Client::AMTHI_Client;

GetMESetupAuditRecordCommand::GetMESetupAuditRecordCommand()
{
	shared_ptr<MEICommandRequest> tmp(new GetMESetupAuditRecordRequest());
	m_request = tmp;
	Transact();
}

GetMESetupAuditRecord_RESPONSE 
GetMESetupAuditRecordCommand::getResponse()
{
	return m_response->getResponse();
}

void
GetMESetupAuditRecordCommand::parseResponse(const vector<uint8_t>& buffer)
{
	shared_ptr<AMTHICommandResponse<GetMESetupAuditRecord_RESPONSE>> tmp(
		new AMTHICommandResponse<GetMESetupAuditRecord_RESPONSE>(buffer, RESPONSE_COMMAND_NUMBER));
	m_response = tmp;
}

std::vector<uint8_t> 
GetMESetupAuditRecordRequest::SerializeData()
{
	vector<uint8_t> output;
	return output;
}


	

	