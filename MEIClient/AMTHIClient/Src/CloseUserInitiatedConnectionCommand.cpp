/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2010-2019 Intel Corporation
 */
/*++

@file: CloseUserInitiatedConnectionCommand.cpp

--*/

#include "CloseUserInitiatedConnectionCommand.h"
#include "StatusCodeDefinitions.h"
#include <string.h>

using namespace std;

using namespace Intel::MEI_Client::AMTHI_Client;

CloseUserInitiatedConnectionCommand::CloseUserInitiatedConnectionCommand()
{
	shared_ptr<MEICommandRequest> tmp(new CloseUserInitiatedConnectionRequest());
	m_request = tmp;
	Transact();
}

void
CloseUserInitiatedConnectionCommand::parseResponse(const vector<uint8_t>& buffer)
{
	shared_ptr<AMTHICommandResponse<CloseUserInitiatedConnection_RESPONSE>> tmp(new AMTHICommandResponse<CloseUserInitiatedConnection_RESPONSE>(buffer, RESPONSE_COMMAND_NUMBER));
	m_response = tmp;
}

std::vector<uint8_t> 
CloseUserInitiatedConnectionRequest::SerializeData()
{
	vector<uint8_t> output;
	return output;
}





	

	