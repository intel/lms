/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2010-2019 Intel Corporation
 */
/*++

@file: GetCurrentPowerPolicyCommand.cpp

--*/


#include <iostream>
#include "GetCurrentPowerPolicyCommand.h"
#include "StatusCodeDefinitions.h"
#include <string.h>

using namespace std;
using namespace Intel::MEI_Client::AMTHI_Client;

GetCurrentPowerPolicyCommand::GetCurrentPowerPolicyCommand()
{
	shared_ptr<MEICommandRequest> tmp(new GetCurrentPowerPolicyRequest());
	m_request = tmp;
	Transact();
}

void GetCurrentPowerPolicyCommand::reTransact()
{
	shared_ptr<MEICommandRequest> tmp(new GetCurrentPowerPolicyRequest());
	m_request = tmp;
	Transact();
}

string GetCurrentPowerPolicyCommand::getResponse()
{
	return m_response->getResponse().powerPolicy;
}

void
GetCurrentPowerPolicyCommand::parseResponse(const vector<uint8_t>& buffer)
{
	shared_ptr<AMTHICommandResponse<GetCurrentPowerPolicy_RESPONSE>> tmp(new AMTHICommandResponse<GetCurrentPowerPolicy_RESPONSE>(buffer, RESPONSE_COMMAND_NUMBER));
	m_response = tmp;
}

std::vector<uint8_t> 
GetCurrentPowerPolicyRequest::SerializeData()
{
	vector<uint8_t> output;
	return output;
}

