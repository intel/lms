/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2010-2015 Intel Corporation
 */
/*++

@file: GetCodeVersionCommand.cpp

--*/

#include "CFG_SetOverrideProsetAdapterSwitchingCommand.h"
#include "StatusCodeDefinitions.h"
#include <string.h>

using namespace std;

using namespace Intel::MEI_Client::AMTHI_Client;


CFG_SetOverrideProsetAdapterSwitchingCommand::~CFG_SetOverrideProsetAdapterSwitchingCommand()
{}


CFG_SetOverrideProsetAdapterSwitchingCommandRequest::~CFG_SetOverrideProsetAdapterSwitchingCommandRequest()
{}



CFG_SetOverrideProsetAdapterSwitchingCommandRequest::CFG_SetOverrideProsetAdapterSwitchingCommandRequest(bool OverrideEnabled) : overrideEnabled_(OverrideEnabled)
{}

std::vector<uint8_t> CFG_SetOverrideProsetAdapterSwitchingCommandRequest::SerializeData()
{
	std::vector<uint8_t> tmp((uint8_t*)&overrideEnabled_, (uint8_t*)&overrideEnabled_ + sizeof(overrideEnabled_));
	return tmp;
}

CFG_SetOverrideProsetAdapterSwitchingCommand::CFG_SetOverrideProsetAdapterSwitchingCommand(bool OverrideEnabled)
{
	shared_ptr<MEICommandRequest> tmp(new CFG_SetOverrideProsetAdapterSwitchingCommandRequest(OverrideEnabled));
	m_request = tmp;
	Transact();
}

AMT_HOSTIF_CFG_SET_OVERRIDE_PROSET_ADAPTER_SWITCHING_RESPONSE 
CFG_SetOverrideProsetAdapterSwitchingCommand::getResponse()
{
	return m_response->getResponse();
}

void
CFG_SetOverrideProsetAdapterSwitchingCommand::parseResponse(const vector<uint8_t>& buffer)
{
	shared_ptr<AMTHICommandResponse<AMT_HOSTIF_CFG_SET_OVERRIDE_PROSET_ADAPTER_SWITCHING_RESPONSE>> tmp(new AMTHICommandResponse<AMT_HOSTIF_CFG_SET_OVERRIDE_PROSET_ADAPTER_SWITCHING_RESPONSE>(buffer, RESPONSE_COMMAND_NUMBER));
	m_response = tmp;
}

	

	