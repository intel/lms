/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2010-2019 Intel Corporation
 */
/*++

@file: SetHostFQDNCommand.cpp

--*/

#include "SetHostFQDNCommand.h"

using namespace std;

using namespace Intel::MEI_Client::AMTHI_Client;


SetHostFQDNCommand::SetHostFQDNCommand(const std::string &FQDN)
{
	shared_ptr<MEICommandRequest> tmp(new SetHostFQDNRequest(FQDN));
	m_request = tmp;
	Transact();
}

void SetHostFQDNCommand::reTransact(const std::string &FQDN)
{
	shared_ptr<MEICommandRequest> tmp(new SetHostFQDNRequest(FQDN));
	m_request = tmp;
	Transact();
}

SET_HOST_FQDN_RESPONSE
SetHostFQDNCommand::getResponse()
{
	return m_response->getResponse();
}

void
SetHostFQDNCommand::parseResponse(const vector<uint8_t>& buffer)
{
	shared_ptr<AMTHICommandResponse<SET_HOST_FQDN_RESPONSE>> tmp(
		new AMTHICommandResponse<SET_HOST_FQDN_RESPONSE>(buffer, RESPONSE_COMMAND_NUMBER));
	m_response = tmp;
}

std::vector<uint8_t> 
SetHostFQDNRequest::SerializeData() {
	std::vector<uint8_t> output(_FQDN.serialize());
	return output;
}
