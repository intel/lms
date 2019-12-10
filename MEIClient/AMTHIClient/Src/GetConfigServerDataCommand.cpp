/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2010-2019 Intel Corporation
 */
/*++

@file: GetConfigServerDataCommand.cpp

--*/

#include "GetConfigServerDataCommand.h"
#include "StatusCodeDefinitions.h"
#include <string.h>

using namespace std;

using namespace Intel::MEI_Client::AMTHI_Client;

GetConfigServerDataCommand::GetConfigServerDataCommand()
{
	shared_ptr<MEICommandRequest> tmp(new GetConfigServerDataRequest());
	m_request = tmp;
	Transact();
}

CFG_GET_CONFIG_SERVER_DATA_RESPONSE GetConfigServerDataCommand::getResponse()
{
	return m_response->getResponse();
}

void
GetConfigServerDataCommand::parseResponse(const vector<uint8_t>& buffer)
{
	shared_ptr<AMTHICommandResponse<CFG_GET_CONFIG_SERVER_DATA_RESPONSE>> tmp(new AMTHICommandResponse<CFG_GET_CONFIG_SERVER_DATA_RESPONSE>(buffer, RESPONSE_COMMAND_NUMBER));
	m_response = tmp;
}


