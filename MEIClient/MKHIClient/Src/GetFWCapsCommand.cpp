/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2010-2015 Intel Corporation
 */
/*++

@file: GetFWCapsCommand.cpp

--*/

#include "GetFWCapsCommand.h"

using namespace std;

using namespace Intel::MEI_Client::MKHI_Client;

GetFWCapsCommand::GetFWCapsCommand(CapsRule rule)
{
	m_rule = rule;
	shared_ptr<MEICommandRequest> tmp(new GetFWCapsRequest(rule));
	m_request = tmp;
	Transact();
}

void GetFWCapsCommand::reTransact()
{
	shared_ptr<MEICommandRequest> tmp(new GetFWCapsRequest(m_rule));
	m_request = tmp;
	Transact();
}


MEFWCAPS_SKU_MKHI GetFWCapsCommand::getResponse()
{
	return m_response->getResponse();
}

void  GetFWCapsCommand::parseResponse(const vector<uint8_t>& buffer)
{
shared_ptr<MKHIGetRuleCommandResponse<MEFWCAPS_SKU_MKHI>> tmp(
	new MKHIGetRuleCommandResponse<MEFWCAPS_SKU_MKHI>(buffer,  RESPONSE_COMMAND_NUMBER, MKHI_FWCAPS_GROUP_ID,m_rule));
	m_response = tmp;
}

std::vector<uint8_t>
GetFWCapsRequest::SerializeData()
{
	vector<uint8_t> output((std::uint8_t*)&m_rule, (std::uint8_t*)&m_rule + sizeof(m_rule));
	return output;
}
