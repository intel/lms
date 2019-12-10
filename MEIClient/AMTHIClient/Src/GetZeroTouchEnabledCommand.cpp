/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2010-2019 Intel Corporation
 */
/*++

@file: GetZeroTouchEnabledCommand.cpp

--*/

#include "GetZeroTouchEnabledCommand.h"
#include "StatusCodeDefinitions.h"
#include <string.h>

using namespace std;

using namespace Intel::MEI_Client::AMTHI_Client;

GetZeroTouchEnabledCommand::GetZeroTouchEnabledCommand()
{
	shared_ptr<MEICommandRequest> tmp(new GetZeroTouchEnabledRequest());
	m_request = tmp;
	Transact();
}

ZTC_ENABLED_STATUS GetZeroTouchEnabledCommand::getResponse()
{
	return m_response->getResponse();
}

void
GetZeroTouchEnabledCommand::parseResponse(const vector<uint8_t>& buffer)
{
	shared_ptr<AMTHICommandResponse<ZTC_ENABLED_STATUS>> tmp(new AMTHICommandResponse<ZTC_ENABLED_STATUS>(buffer, RESPONSE_COMMAND_NUMBER));
	m_response = tmp;
}

std::vector<uint8_t> 
GetZeroTouchEnabledRequest::SerializeData()
{
	vector<uint8_t> output;
	return output;
}

