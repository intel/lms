/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2010-2017 Intel Corporation
 */
/*++

@file: GetImageTypeCommand.cpp

--*/

#include "GetImageTypeCommand.h"

using namespace std;

using namespace Intel::MEI_Client::MKHI_Client;

GetImageTypeCommand::GetImageTypeCommand()
{
	shared_ptr<MEICommandRequest> tmp(new GetImageTypeRequest());
	m_request = tmp;
	Transact();
}

void GetImageTypeCommand::reTransact()
{
	shared_ptr<MEICommandRequest> tmp(new GetImageTypeRequest());
	m_request = tmp;
	Transact();
}

MKHI_IMAGE_TYPE GetImageTypeCommand::getResponse()
{
	return m_response->getResponse();
}

void  GetImageTypeCommand::parseResponse(const vector<uint8_t>& buffer)
{
	shared_ptr<MKHICommandResponse<MKHI_IMAGE_TYPE>> tmp(
		new MKHICommandResponse<MKHI_IMAGE_TYPE>(buffer, RESPONSE_COMMAND_NUMBER, MKHI_GEN_GROUP_ID));
	m_response = tmp;
}

std::vector<uint8_t> GetImageTypeRequest::SerializeData()
{
	vector<uint8_t> output(0, 0);

	return output;
}
