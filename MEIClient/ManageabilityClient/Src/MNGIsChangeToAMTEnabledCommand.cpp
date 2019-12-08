/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2010-2015 Intel Corporation
 */
/*++

@file: MNGIsChangeToAMTEnabledCommand.cpp

--*/

#include "MNGIsChangeToAMTEnabledCommand.h"
#include "StatusCodeDefinitions.h"
#include <string.h>

using namespace std;

using namespace Intel::MEI_Client::Manageability_Client;

MNGIsChangeToAMTEnabledCommand::MNGIsChangeToAMTEnabledCommand()
{
	shared_ptr<MEICommandRequest> tmp(new MNGIsChangeToAMTEnabledRequest());
	m_request = tmp;
	Transact();
}

void MNGIsChangeToAMTEnabledCommand::reTransact()
{
	shared_ptr<MEICommandRequest> tmp(new MNGIsChangeToAMTEnabledRequest());
	m_request = tmp;
	Transact();
}

IsChangedEnabledResponse MNGIsChangeToAMTEnabledCommand::getResponse()
{
	return m_response->getResponse();
}

void MNGIsChangeToAMTEnabledCommand::parseResponse(const vector<uint8_t>& buffer)
{
	shared_ptr<ManageabilityCommandResponse<IsChangedEnabledResponse>> tmp(new ManageabilityCommandResponse<IsChangedEnabledResponse>(buffer));
	m_response = tmp;
}

std::vector<uint8_t> MNGIsChangeToAMTEnabledRequest::SerializeData()
{
	vector<uint8_t> output;
	return output;
}
