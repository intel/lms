/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2010-2023 Intel Corporation
 */
/*++

@file: AMTHICommand.cpp

--*/

#include "AMTHICommand.h"
#include "HECI_if.h"

namespace Intel {
	namespace MEI_Client {
		namespace AMTHI_Client {
			const GUID& AMTHICommand::getGUID()
			{
				return HECI_AMTHI_GUID;
			}

			void AMTHICommand::Transact()
			{
				std::lock_guard<std::mutex> lock(getInternalSemaphore());
				MEICommand::Transact();
			}

			std::vector<uint8_t> AMTHICommandRequest::Serialize()
			{
				AMTHI_MESSAGE_HEADER header =
				{ {AMT_MAJOR_VERSION,AMT_MINOR_VERSION}, 0, {m_requestHeaderCommandNumber}, requestDataSize() };
				std::vector<uint8_t> output = serializeHeader(header);
				std::vector<uint8_t> dataOutput = SerializeData();
				output.insert(output.end(), dataOutput.begin(), dataOutput.end());
				return output;
			}

			std::vector<uint8_t> AMTHICommandRequest::serializeHeader(const AMTHI_MESSAGE_HEADER& header)
			{
				return Intel::MEI_Client::serializeHeader<AMTHI_MESSAGE_HEADER>(header);
			}

			std::mutex& AMTHICommand::getInternalSemaphore()
			{
				static std::mutex internalSemaphore;

				return internalSemaphore;
			}

			AMTHICommand::SemaphoreInitializer::SemaphoreInitializer()
			{
				AMTHICommand::getInternalSemaphore();
			}

			AMTHICommand::SemaphoreInitializer AMTHICommand::SemaphoreInitializer::initializer;
		} // namespace AMTHI_Client
	} // namespace MEI_Client
} // namespace Intel