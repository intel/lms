/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2010-2019 Intel Corporation
 */
/*++

@file: MKHICommand.cpp

--*/

#include "MKHICommand.h"
#include "HECI_if.h"
#include <vector>
using namespace Intel::MEI_Client::MKHI_Client;

const GUID&
MKHICommand::getGUID()
{
	return HECI_MKHI_GUID;
}

std::vector<uint8_t>
MKHICommandRequest::Serialize()
{
	MKHI_MSG_HEADER header;
	header.Data = 0; //initialize to 0
	//put data in correct bits

	header.Fields.Command = requestHeaderCommandNumber();
	header.Fields.GroupId = requestHeaderGroupID();
	//all other fields should and are 0
	std::vector<uint8_t> output = serializeHeader(header);
	std::vector<uint8_t> dataOutput = SerializeData();
	output.insert(output.end(), dataOutput.begin(), dataOutput.end());

	return output;
}

std::vector<uint8_t>
MKHICommandRequest::serializeHeader(const MKHI_MSG_HEADER& header)
{
	return Intel::MEI_Client::serializeHeader<MKHI_MSG_HEADER>(header);
}

std::mutex& MKHICommand::getInternalSemaphore()
{
	static std::mutex internalSemaphore;

	return internalSemaphore;
}

MKHICommand::SemaphoreInitializer::SemaphoreInitializer()
{
	MKHICommand::getInternalSemaphore();
}

MKHICommand::SemaphoreInitializer MKHICommand::SemaphoreInitializer::initializer;
