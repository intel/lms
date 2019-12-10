/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2010-2019 Intel Corporation
 */
/*++

@file: StopConfigurationCommand.cpp

--*/

#include "StopConfigurationCommand.h"
#include "StatusCodeDefinitions.h"

using namespace std;

using namespace Intel::MEI_Client::AMTHI_Client;

StopConfigurationCommand::StopConfigurationCommand()
{
	shared_ptr<MEICommandRequest> tmp(new StopConfigurationRequest());
	m_request = tmp;
	Transact();
}

void
StopConfigurationCommand::parseResponse(const vector<uint8_t>& buffer)
{
	shared_ptr<AMTHICommandResponse<StopConfig_RESPONSE>> tmp(new AMTHICommandResponse<StopConfig_RESPONSE>(buffer, RESPONSE_COMMAND_NUMBER));
	m_response = tmp;
}

