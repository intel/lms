/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2010-2019 Intel Corporation
 */
/*++

@file: FWUpdateCommand.cpp

--*/

#include "FWUpdateCommand.h"
#include "HECI_if.h"

namespace Intel { namespace MEI_Client { namespace FWUpdate_Client {
	const GUID&	FWUpdateCommand::getGUID()
	{
		return FW_UPDATE_GUID;
	}

	std::vector<uint8_t> FWUpdateCommandRequest::Serialize()
	{
		FWUpdate_MESSAGE_HEADER header = { requestHeaderMessageID() };
		std::vector<uint8_t> output = serializeHeader(header);
		std::vector<uint8_t> dataOutput = SerializeData();

		output.insert(output.end(), dataOutput.begin(), dataOutput.end());
		return output;
	}

	std::vector<uint8_t> FWUpdateCommandRequest::serializeHeader(const FWUpdate_MESSAGE_HEADER& header)
	{
		return Intel::MEI_Client::serializeHeader<FWUpdate_MESSAGE_HEADER>(header);
	}

	std::mutex& FWUpdateCommand::getInternalSemaphore()
	{
		static std::mutex internalSemaphore;

		return internalSemaphore;
	}

	FWUpdateCommand::SemaphoreInitializer::SemaphoreInitializer()
	{
		FWUpdateCommand::getInternalSemaphore();
	}

	FWUpdateCommand::SemaphoreInitializer FWUpdateCommand::SemaphoreInitializer::initializer;
} /* namespace FWUpdate_Client */ } /* namespace MEI_Client */ } /* namespace Intel */