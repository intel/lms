/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2010-2019 Intel Corporation
 */
/*++

@file: GetIPv6LanInterfaceStatusCommand.cpp

--*/

#include "GetIPv6LanInterfaceStatusCommand.h"
//#include "StatusCodeDefinitions.h"
#include <string.h>

using namespace std;

using namespace Intel::MEI_Client::AMTHI_Client;

GetIPv6LanInterfaceStatusCommand::GetIPv6LanInterfaceStatusCommand(uint32_t interfaceIndex)	//INTERFACE_SETTINGS
{
	shared_ptr<MEICommandRequest> tmp(new GetIPv6LanInterfaceStatusRequest(interfaceIndex));
	m_request = tmp;
	Transact();
}

GET_IPv6_LAN_INTERFACE_STATUS_RESPONSE GetIPv6LanInterfaceStatusCommand::getResponse()
{
	return m_response->getResponse();
}

void
GetIPv6LanInterfaceStatusCommand::parseResponse(const vector<uint8_t>& buffer)
{
	shared_ptr<AMTHICommandResponse<GET_IPv6_LAN_INTERFACE_STATUS_RESPONSE>> tmp(new AMTHICommandResponse<GET_IPv6_LAN_INTERFACE_STATUS_RESPONSE>(buffer, RESPONSE_COMMAND_NUMBER));
	m_response = tmp;
}

std::vector<uint8_t> 
GetIPv6LanInterfaceStatusRequest::SerializeData()
{
	vector<uint8_t> output((std::uint8_t*)&m_interfaceIndex, (std::uint8_t*)&m_interfaceIndex + sizeof(uint32_t));
	return output;
}






	

	