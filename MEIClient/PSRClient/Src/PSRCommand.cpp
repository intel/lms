/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2021-2023 Intel Corporation
 */
/*++

@file: PSRCommand.cpp

--*/

#include "PSRCommand.h"
#include "HECI_if.h"

namespace Intel {
	namespace MEI_Client {
		namespace PSR_Client {
			const GUID& PSRCommand::getGUID()
			{
				return HECI_PSR_GUID;
			}

			std::vector<uint8_t> PSRCommandRequest::Serialize()
			{
				PSR_MSG_HEADER header;
				header.Data = 0; //initialize to 0
				//put data in correct bits

				header.Fields.command = static_cast<uint8_t>(m_requestHeaderCommandNumber);
				header.Fields.length = requestDataSize();
				//all other fields should and are 0
				std::vector<uint8_t> output = serializeHeader(header);
				std::vector<uint8_t> dataOutput = SerializeData();
				output.insert(output.end(), dataOutput.begin(), dataOutput.end());

				return output;
			}

			std::vector<uint8_t> PSRCommandRequest::serializeHeader(const PSR_MSG_HEADER& header)
			{
				return Intel::MEI_Client::serializeHeader<PSR_MSG_HEADER>(header);
			}

			std::mutex& PSRCommand::getInternalSemaphore()
			{
				static std::mutex internalSemaphore;

				return internalSemaphore;
			}

			PSRCommand::SemaphoreInitializer::SemaphoreInitializer()
			{
				PSRCommand::getInternalSemaphore();
			}

			PSRCommand::SemaphoreInitializer PSRCommand::SemaphoreInitializer::initializer;
		} // namespace PSR_Client
	} // namespace MEI_Client
} // namespace Intel