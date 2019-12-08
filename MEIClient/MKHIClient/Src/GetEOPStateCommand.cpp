/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2010-2018 Intel Corporation
 */
/*++

@file: GetEOPStateCommand.cpp

--*/

#include "GetEOPStateCommand.h"

using namespace Intel::MEI_Client::MKHI_Client;

GetEOPStateCommand::GetEOPStateCommand()
{
	std::shared_ptr<MEICommandRequest> tmp(new GetEOPStateRequest());
	m_request = tmp;
	Transact();
}

void GetEOPStateCommand::reTransact()
{
	std::shared_ptr<MEICommandRequest> tmp(new GetEOPStateRequest());
	m_request = tmp;
	Transact();
}

GET_EOP_STATE_RESPONSE GetEOPStateCommand::getResponse()
{
	return m_response->getResponse();
}

void GetEOPStateCommand::parseResponse(const std::vector<uint8_t>& buffer)
{
	std::shared_ptr<MKHICommandResponse<GET_EOP_STATE_RESPONSE>> tmp(
		new MKHICommandResponse<GET_EOP_STATE_RESPONSE>(buffer,  RESPONSE_COMMAND_NUMBER, MKHI_GEN_GROUP_ID));
	m_response = tmp;
}

std::vector<uint8_t> GetEOPStateRequest::SerializeData()
{
	std::vector<uint8_t> output(0, 0);
	return output;
}
