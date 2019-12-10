/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2010-2019 Intel Corporation
 */
/*++

@file: HTMGetFLogCommand.cpp

--*/

#include "HTMGetFLogCommand.h"

using namespace std;

using namespace Intel::MEI_Client::HOTHAM_Client;

HTMGetFatalErrorsCommand::HTMGetFatalErrorsCommand()
{
	shared_ptr<MEICommandRequest> tmp(new HTMGetFatalErrorsRequest());
	m_request = tmp;
	Transact();
}

GET_FLOG_RESP
HTMGetFatalErrorsCommand::getResponse()
{
	return m_response->getResponse();
}

void  HTMGetFatalErrorsCommand::parseResponse(const vector<uint8_t>& buffer)
{
	shared_ptr<HOTHAMCommandResponse<GET_FLOG_RESP>> tmp(new HOTHAMCommandResponse<GET_FLOG_RESP>(buffer));
	m_response = tmp;
}

std::vector<uint8_t> 
HTMGetFatalErrorsRequest::SerializeData()
{
	vector<uint8_t> output;
	return output;
}