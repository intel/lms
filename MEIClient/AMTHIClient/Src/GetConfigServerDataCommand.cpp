/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2010-2023 Intel Corporation
 */
/*++

@file: GetConfigServerDataCommand.cpp

--*/

#include "GetConfigServerDataCommand.h"

namespace Intel {
	namespace MEI_Client {
		namespace AMTHI_Client {
			GetConfigServerDataCommand::GetConfigServerDataCommand()
			{
				m_request = std::make_shared<GetConfigServerDataRequest>();
				Transact();
			}

			CFG_GET_CONFIG_SERVER_DATA_RESPONSE GetConfigServerDataCommand::getResponse()
			{
				return m_response.getResponse();
			}

			void GetConfigServerDataCommand::parseResponse(const std::vector<uint8_t>& buffer)
			{
				m_response = AMTHICommandResponse<CFG_GET_CONFIG_SERVER_DATA_RESPONSE>(buffer, RESPONSE_COMMAND_NUMBER);
			}
		} // namespace AMTHI_Client
	} // namespace MEI_Client
} // namespace Intel