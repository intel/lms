/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2022 Intel Corporation
 */
/*++

@file: MCHICommand.cpp

--*/

#include "MCHICommand.h"
#include "HECI_if.h"

namespace Intel {
	namespace MEI_Client {
		namespace MCHI_Client {
			const GUID& MCHICommand::getGUID()
			{
				return HECI_MCHI_GUID;
			}

			std::vector<uint8_t> MCHICommandRequest::Serialize()
			{
				MCHI_MSG_HEADER header;
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

			std::vector<uint8_t> MCHICommandRequest::serializeHeader(const MCHI_MSG_HEADER& header)
			{
				return Intel::MEI_Client::serializeHeader<MCHI_MSG_HEADER>(header);
			}

			std::mutex& MCHICommand::getInternalSemaphore()
			{
				static std::mutex internalSemaphore;

				return internalSemaphore;
			}

			MCHICommand::SemaphoreInitializer::SemaphoreInitializer()
			{
				MCHICommand::getInternalSemaphore();
			}

			MCHICommand::SemaphoreInitializer MCHICommand::SemaphoreInitializer::initializer;
		} // namespace MCHI_Client
	} // namespace MEI_Client
} // namespace Intel