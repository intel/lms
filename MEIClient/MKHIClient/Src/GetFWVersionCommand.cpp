/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2010-2023 Intel Corporation
 */
/*++

@file: GetFWVersionCommand.cpp

--*/

#include "GetFWVersionCommand.h"

namespace Intel {
	namespace MEI_Client {
		namespace MKHI_Client {
			GetFWVersionCommand::GetFWVersionCommand()
			{
				m_request = std::make_shared<GetFWVersionRequest>();
				Transact();
			}

			GET_FW_VER_RESPONSE GetFWVersionCommand::getResponse()
			{
				return m_response.getResponse();
			}

			void GetFWVersionCommand::parseResponse(const std::vector<uint8_t>& buffer)
			{
				m_response = MKHICommandResponse<GET_FW_VER_RESPONSE>(buffer, RESPONSE_COMMAND_NUMBER, MKHI_GEN_GROUP_ID);
			}
		} // namespace MKHI_Client
	} // namespace MEI_Client
} // namespace Intel