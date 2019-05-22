/*++
/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2010-2018 Intel Corporation
 */
/*++

@file: GetImageFWVersionCommand.cpp

--*/

#include "GetImageFWVersionCommand.h"

using namespace Intel::MEI_Client::MKHI_Client;

GetImageFWVersionCommand::GetImageFWVersionCommand(uint32_t PartitionId): _partitionId(PartitionId)
{
	std::shared_ptr<MEICommandRequest> tmp(new GetImageFWVersionRequest(_partitionId));
	m_request = tmp;
	Transact();
}

void GetImageFWVersionCommand::reTransact()
{
	std::shared_ptr<MEICommandRequest> tmp(new GetImageFWVersionRequest(_partitionId));
	m_request = tmp;
	Transact();
}

GET_IMAGE_FW_VERSION_RESPONSE GetImageFWVersionCommand::getResponse()
{
	return m_response->getResponse();
}

void  GetImageFWVersionCommand::parseResponse(const std::vector<uint8_t>& buffer)
{
	std::shared_ptr<MKHICommandResponse<GET_IMAGE_FW_VERSION_RESPONSE>> tmp(
		new MKHICommandResponse<GET_IMAGE_FW_VERSION_RESPONSE>(buffer,  RESPONSE_COMMAND_NUMBER, MKHI_GEN_GROUP_ID));
	m_response = tmp;
}

std::vector<uint8_t> GetImageFWVersionRequest::SerializeData()
{
	GET_IMAGE_FW_VERSION_REQUEST req;
	req.PartitionId = _partitionId;
	std::vector<uint8_t> tmp((uint8_t*)&req, (uint8_t*)&req + sizeof(GET_IMAGE_FW_VERSION_REQUEST));
	return tmp;
}

