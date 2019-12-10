/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2010-2019 Intel Corporation
 */
/*++

@file: GetTcpipParametersCommand.cpp

--*/

#include "GetTcpipParametersCommand.h"
#include "StatusCodeDefinitions.h"
#include <string.h>

using namespace std;

using namespace Intel::MEI_Client::AMTHI_Client;

GetTcpipParametersCommand::GetTcpipParametersCommand()
{
	shared_ptr<MEICommandRequest> tmp(new GetTcpipParametersRequest());
	m_request = tmp;
	Transact();
}

TCPIP_PARAMETERS GetTcpipParametersCommand::getResponse()
{
	return m_response->getResponse();
}

void
GetTcpipParametersCommand::parseResponse(const vector<uint8_t>& buffer)
{
	shared_ptr<AMTHICommandResponse<TCPIP_PARAMETERS>> tmp(new AMTHICommandResponse<TCPIP_PARAMETERS>(buffer, RESPONSE_COMMAND_NUMBER));
	m_response = tmp;
}

