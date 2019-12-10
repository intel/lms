/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2010-2019 Intel Corporation
 */
/*++

@file: FWUGetInfoCommand.cpp

--*/

#include "FWUGetInfoCommand.h"
#include "StatusCodeDefinitions.h"
#include <string.h>

using namespace std;

using namespace Intel::MEI_Client::FWUpdate_Client;

FWUGetInfoCommand::FWUGetInfoCommand()
{
	shared_ptr<MEICommandRequest> tmp(new FWUGetInfoRequest());
	m_request = tmp;
	Transact();
}

GET_INFO_RESPONSE FWUGetInfoCommand::getResponse()
{
	return m_response->getResponse();
}

void
FWUGetInfoCommand::parseResponse(const vector<uint8_t>& buffer)
{
	shared_ptr<FWUpdateCommandResponse<GET_INFO_RESPONSE>> tmp(new FWUpdateCommandResponse<GET_INFO_RESPONSE>(buffer, RESPONSE_COMMAND_NUMBER));
	m_response = tmp;
}

std::vector<uint8_t> 
FWUGetInfoRequest::SerializeData()
{
	vector<uint8_t> output;
	return output;
}

