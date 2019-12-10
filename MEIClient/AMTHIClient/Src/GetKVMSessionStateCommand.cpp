/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2010-2019 Intel Corporation
 */
/*++

@file: GetKVMSessionStateCommand.cpp

--*/

#include <iostream>
#include "GetKVMSessionStateCommand.h"
#include "StatusCodeDefinitions.h"
#include <string.h>

using namespace std;
using namespace Intel::MEI_Client::AMTHI_Client;

GetKVMSessionStateCommand::GetKVMSessionStateCommand()
{
	shared_ptr<MEICommandRequest> tmp(new GetKVMSessionStateRequest());
	m_request = tmp;
	Transact();
}

GET_KVM_SESSION_STATE_RESPONSE GetKVMSessionStateCommand::getResponse()
{
	return m_response->getResponse();
}

void
GetKVMSessionStateCommand::parseResponse(const vector<uint8_t>& buffer)
{
	shared_ptr<AMTHICommandResponse<GET_KVM_SESSION_STATE_RESPONSE>> tmp(
		new AMTHICommandResponse<GET_KVM_SESSION_STATE_RESPONSE>(buffer, RESPONSE_COMMAND_NUMBER));
	m_response = tmp;
}




std::vector<uint8_t> 
GetKVMSessionStateRequest::SerializeData()
{
	uint32_t id = KVM_SESSION_ID;
	vector<uint8_t> output((std::uint8_t*)&id, (std::uint8_t*)&id + sizeof(uint32_t));
	return output;
}




	
