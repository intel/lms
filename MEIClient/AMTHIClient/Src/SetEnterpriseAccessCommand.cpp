/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2010-2015 Intel Corporation
 */
/*++

@file: SetEnterpriseAccessCommand.cpp

--*/

#include "SetEnterpriseAccessCommand.h"
#include <string.h>

using namespace std;

using namespace Intel::MEI_Client::AMTHI_Client;

SetEnterpriseAccessRequest::SetEnterpriseAccessRequest(uint8_t Flags, uint8_t HostIPAddress[HOST_IP_ADDRESS_SIZE], uint8_t EnterpiseAccess):_Flags(Flags), _EnterpiseAccess(EnterpiseAccess)
{
	for (int i = 0; i < HOST_IP_ADDRESS_SIZE; i++) 
	{
		_HostIPAddress[i] = HostIPAddress[i];
	}
}


SetEnterpriseAccessCommand::SetEnterpriseAccessCommand(uint8_t Flags, uint8_t HostIPAddress[HOST_IP_ADDRESS_SIZE], uint8_t EnterpiseAccess)
{
	shared_ptr<MEICommandRequest> tmp(new SetEnterpriseAccessRequest(Flags, HostIPAddress, EnterpiseAccess));
	m_request = tmp;
	Transact();
}

void
SetEnterpriseAccessCommand::reTransact(uint8_t Flags, uint8_t HostIPAddress[HOST_IP_ADDRESS_SIZE], uint8_t EnterpiseAccess)
{
	shared_ptr<MEICommandRequest> tmp(new SetEnterpriseAccessRequest(Flags, HostIPAddress, EnterpiseAccess));
	m_request = tmp;
	Transact();
}

SetEnterpriseAccess_RESPONSE 
SetEnterpriseAccessCommand::getResponse()
{
	return m_response->getResponse();
}

void
SetEnterpriseAccessCommand::parseResponse(const vector<uint8_t>& buffer)
{
	shared_ptr<AMTHICommandResponse<SetEnterpriseAccess_RESPONSE>> tmp(
		new AMTHICommandResponse<SetEnterpriseAccess_RESPONSE>(buffer, RESPONSE_COMMAND_NUMBER));
	m_response = tmp;
}

std::vector<uint8_t> 
SetEnterpriseAccessRequest::SerializeData()
{
	const uint32_t outputSize = requestDataSize();
	vector<uint8_t> output(outputSize, 0);
	vector<uint8_t>::iterator it = output.begin();

	*it = _Flags;
	it++;
	std::copy(&_HostIPAddress[0], &_HostIPAddress[0] + HOST_IP_ADDRESS_SIZE, it);
	it += HOST_IP_ADDRESS_SIZE;
	*it = _EnterpiseAccess;
	return output;
}


	

	