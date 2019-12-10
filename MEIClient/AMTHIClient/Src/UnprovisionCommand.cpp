/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2010-2019 Intel Corporation
 */
/*++

@file: UnprovisionCommand.cpp

--*/

#include "UnprovisionCommand.h"
#include "StatusCodeDefinitions.h"
#include <string.h>

using namespace std;

using namespace Intel::MEI_Client::AMTHI_Client;

UnprovisionCommand::UnprovisionCommand(const CFG_PROVISIONING_MODE Mode)
{
	shared_ptr<MEICommandRequest> tmp(new UnprovisionRequest(Mode));
	m_request = tmp;
	Transact();
}

void
 UnprovisionCommand::parseResponse(const vector<uint8_t>& buffer)
{
	shared_ptr<AMTHICommandResponse<Unprovision_RESPONSE>> tmp(new AMTHICommandResponse<Unprovision_RESPONSE>(buffer, RESPONSE_COMMAND_NUMBER));
	m_response = tmp;
}

std::vector<uint8_t> 
UnprovisionRequest::SerializeData()
{
	vector<uint8_t> output((std::uint8_t*)&m_mode, (std::uint8_t*)&m_mode + sizeof(m_mode));
	return output;
}






	

	