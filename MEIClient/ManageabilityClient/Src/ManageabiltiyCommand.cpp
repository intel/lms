/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2010-2019 Intel Corporation
 */
/*++

@file: ManageabilityCommand.cpp

--*/

#include "ManageabilityCommand.h"
#include "HECI_if.h"

namespace Intel { namespace MEI_Client { namespace Manageability_Client {
	const uint8_t MNG_HEADER_VERSION = 0x10;

	const GUID& ManageabilityCommand::getGUID()
	{
		return HECI_WATCHDOG_GUID;
	}

	std::mutex& ManageabilityCommand::getInternalSemaphore()
	{
		static std::mutex internalSemaphore;

		return internalSemaphore;
	}

	ManageabilityCommand::SemaphoreInitializer::SemaphoreInitializer()
	{
		ManageabilityCommand::getInternalSemaphore();
	}

	ManageabilityCommand::SemaphoreInitializer ManageabilityCommand::SemaphoreInitializer::initializer;

	std::vector<uint8_t> ManageabilityCommandRequest::Serialize()
	{
		uint8_t bytesCount = (uint8_t)(sizeof(uint8_t) * 2) + requestDataSize();
		Manageability_MESSAGE_HEADER header =
		{ requestHeaderCMD(), bytesCount,requestHeaderSubCMD(), MNG_HEADER_VERSION };
		std::vector<uint8_t> output = serializeHeader(header);
		std::vector<uint8_t> dataOutput = SerializeData();

		output.insert(output.end(), dataOutput.begin(), dataOutput.end());
		return output;
	}

	std::vector<uint8_t> ManageabilityCommandRequest::serializeHeader(const Manageability_MESSAGE_HEADER& header)
	{
		return Intel::MEI_Client::serializeHeader<Manageability_MESSAGE_HEADER>(header);
	}
} /* namespace Manageability_Client */ } /* namespace MEI_Client */ } /* namespace Intel */