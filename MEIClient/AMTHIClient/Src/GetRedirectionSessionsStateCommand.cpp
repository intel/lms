/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2010-2019 Intel Corporation
 */
/*++

@file: GetRedirectionSessionsStateCommand.cpp

--*/

#include "GetRedirectionSessionsStateCommand.h"

namespace Intel {
	namespace MEI_Client {
		namespace AMTHI_Client {
			GetRedirectionSessionsStateCommand::GetRedirectionSessionsStateCommand()
			{
				std::shared_ptr<MEICommandRequest> tmp(new GetRedirectionSessionsStateRequest());
				m_request = tmp;
				Transact();
			}

			GET_REDIRECTION_SESSIONS_STATE_RESPONSE GetRedirectionSessionsStateCommand::getResponse()
			{
				return m_response->getResponse();
			}

			void GetRedirectionSessionsStateCommand::parseResponse(const std::vector<uint8_t>& buffer)
			{
				std::shared_ptr<AMTHICommandResponse<GET_REDIRECTION_SESSIONS_STATE_RESPONSE>> tmp(
					new AMTHICommandResponse<GET_REDIRECTION_SESSIONS_STATE_RESPONSE>(buffer, RESPONSE_COMMAND_NUMBER));
				m_response = tmp;
			}

			std::vector<uint8_t> GetRedirectionSessionsStateRequest::SerializeData()
			{
				uint32_t id = REDIRECTION_ID;
				std::vector<uint8_t> output((std::uint8_t*)&id, (std::uint8_t*)&id + sizeof(uint32_t));
				return output;
			}
		} // namespace AMTHI_Client
	} // namespace MEI_Client
} // namespace Intel