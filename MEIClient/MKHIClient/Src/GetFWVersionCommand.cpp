/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2010-2015 Intel Corporation
 */
/*++

@file: GetFWVersionCommand.cpp

--*/

#include "GetFWVersionCommand.h"

using namespace std;

using namespace Intel::MEI_Client::MKHI_Client;

GetFWVersionCommand::GetFWVersionCommand()
{
	shared_ptr<MEICommandRequest> tmp(new GetFWVersionRequest());
	m_request = tmp;
	Transact();
}

void GetFWVersionCommand::reTransact()
{
	shared_ptr<MEICommandRequest> tmp(new GetFWVersionRequest());
	m_request = tmp;
	Transact();
}

GET_FW_VER_RESPONSE GetFWVersionCommand::getResponse()
{
	return m_response->getResponse();
}

void GetFWVersionCommand::parseResponse(const vector<uint8_t>& buffer)
{
	shared_ptr<MKHICommandResponse<GET_FW_VER_RESPONSE>> tmp(
		new MKHICommandResponse<GET_FW_VER_RESPONSE>(buffer, RESPONSE_COMMAND_NUMBER, MKHI_GEN_GROUP_ID));
	m_response = tmp;
}

std::vector<uint8_t> GetFWVersionRequest::SerializeData()
{
	vector<uint8_t> output(0, 0);

	return output;
}
