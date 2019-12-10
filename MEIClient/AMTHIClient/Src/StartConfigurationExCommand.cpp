/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2010-2019 Intel Corporation
 */
/*++

@file: StartConfigurationExCommand.cpp

--*/

#include "StartConfigurationExCommand.h"
#include <string.h>

using namespace std;

using namespace Intel::MEI_Client::AMTHI_Client;

StartConfigurationExCommand::StartConfigurationExCommand(bool IPv6Enable)
{
	shared_ptr<MEICommandRequest> tmp(new StartConfigurationExRequest(IPv6Enable));
	m_request = tmp;
	Transact();
}

START_CONFIGURATION_EX_RESPONSE
StartConfigurationExCommand::getResponse()
{
	return m_response->getResponse();
}

void
StartConfigurationExCommand::parseResponse(const vector<uint8_t>& buffer)
{
	shared_ptr<AMTHICommandResponse<START_CONFIGURATION_EX_RESPONSE>> tmp(
		new AMTHICommandResponse<START_CONFIGURATION_EX_RESPONSE>(buffer, RESPONSE_COMMAND_NUMBER));
	m_response = tmp;
}

std::vector<uint8_t> 
StartConfigurationExRequest::SerializeData()
{
	vector<uint8_t> output((std::uint8_t*)&_IPv6Enable, (std::uint8_t*)&_IPv6Enable + sizeof(_IPv6Enable));
	return output;
}
	