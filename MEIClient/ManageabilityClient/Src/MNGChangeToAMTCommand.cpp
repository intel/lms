/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2010-2019 Intel Corporation
 */
/*++

@file: MNGChangeToAMTCommand.cpp

--*/

#include "MNGChangeToAMTCommand.h"
#include "StatusCodeDefinitions.h"
#include <string.h>

using namespace std;

using namespace Intel::MEI_Client::Manageability_Client;

MNGChangeToAMTCommand::MNGChangeToAMTCommand()
{
	shared_ptr<MEICommandRequest> tmp(new MNGChangeToAMTRequest());
	m_request = tmp;
	Transact();
}

ChangeToAMT_RESPONSE MNGChangeToAMTCommand::getResponse()
{
	return m_response->getResponse();
}

void MNGChangeToAMTCommand::parseResponse(const vector<uint8_t>& buffer)
{
	shared_ptr<ManageabilityCommandResponse<ChangeToAMT_RESPONSE>> tmp(new ManageabilityCommandResponse<ChangeToAMT_RESPONSE>(buffer));
	m_response = tmp;
}

std::vector<uint8_t> MNGChangeToAMTRequest::SerializeData()
{
	vector<uint8_t> output;
	return output;
}
