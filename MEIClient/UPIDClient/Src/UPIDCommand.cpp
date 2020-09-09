/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2020 Intel Corporation
 */
/*++

@file: UPIDCommand.cpp

--*/

#include "UPIDCommand.h"
#include "HECI_if.h"

namespace Intel {
	namespace MEI_Client {
		namespace UPID_Client {
	
			const GUID& UPIDCommand::getGUID()
			{
				return HECI_UPID_GUID;
			}

			std::vector<uint8_t> UPIDRequest::Serialize()
			{
				UPID_HECI_HEADER header = { requestHeaderFeatureID(), requestHeaderCommandID(), requestDataSize() };
				std::vector<uint8_t> output = serializeHeader(header);
				std::vector<uint8_t> dataOutput = SerializeData();
				output.insert(output.end(), dataOutput.begin(), dataOutput.end());
				return output;
			}

			std::vector<uint8_t> UPIDRequest::serializeHeader(const UPID_HECI_HEADER& header)
			{
				return Intel::MEI_Client::serializeHeader<UPID_HECI_HEADER>(header);
			}

			std::mutex& UPIDCommand::getInternalSemaphore()
			{
				static std::mutex internalSemaphore;

				return internalSemaphore;
			}

			UPIDCommand::SemaphoreInitializer::SemaphoreInitializer()
			{
				UPIDCommand::getInternalSemaphore();
			}

			UPIDCommand::SemaphoreInitializer UPIDCommand::SemaphoreInitializer::initializer;
		} /* namespace UPID_Client */ 
	} /* namespace MEI_Client */
} /* namespace Intel */