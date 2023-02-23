/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2022-2023 Intel Corporation
 */
/*++

@file: ReadFileExCommand.cpp

--*/

#include "ReadFileExCommand.h"

namespace Intel {
	namespace MEI_Client {
		namespace MCHI_Client {
			ReadFileExCommand::ReadFileExCommand(MCA_FILE_ID fileID, uint32_t offset, uint32_t dataSize, uint8_t flags)
			{
				std::shared_ptr<MEICommandRequest> tmp(new ReadFileExRequest(static_cast<uint32_t>(fileID), offset, dataSize, flags));
				m_request = tmp;
				Transact();
			}

			READ_FILE_EX_RESPONSE ReadFileExCommand::getResponse()
			{
				return m_response.getResponse();
			}

			void  ReadFileExCommand::parseResponse(const std::vector<uint8_t>& buffer)
			{
				m_response = MCHICommandResponse<READ_FILE_EX_RESPONSE>(buffer, RESPONSE_COMMAND_NUMBER, MCHI_GROUP_ID_MCA);
			}

			std::vector<uint8_t> ReadFileExRequest::SerializeData()
			{
				std::vector<uint8_t> output((std::uint8_t*)&request, (std::uint8_t*)&request + sizeof(request));
				return output;
			}
		} /* namespace MCHI_Client */
	} /* namespace MEI_Client */
} /* namespace Intel */