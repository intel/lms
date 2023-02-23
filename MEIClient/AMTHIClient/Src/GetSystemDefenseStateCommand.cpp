/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2010-2023 Intel Corporation
 */
/*++

@file: GetSystemDefenseStateCommand.cpp

--*/

#include "GetSystemDefenseStateCommand.h"

namespace Intel {
	namespace MEI_Client {
		namespace AMTHI_Client {
			GetSystemDefenseStateCommand::GetSystemDefenseStateCommand()
			{
				m_request = std::make_shared<GetSystemDefenseStateRequest>();
				Transact();
			}

			GET_SYSTEM_DEFENSE_STATE_RESPONSE GetSystemDefenseStateCommand::getResponse()
			{
				return m_response.getResponse();
			}

			void GetSystemDefenseStateCommand::parseResponse(const std::vector<uint8_t>& buffer)
			{
				m_response = AMTHICommandResponse<GET_SYSTEM_DEFENSE_STATE_RESPONSE>(buffer, RESPONSE_COMMAND_NUMBER);
			}

			std::vector<uint8_t> GetSystemDefenseStateRequest::SerializeData()
			{
				uint32_t id = SYSTEM_DEFENSE_ID;
				std::vector<uint8_t> output((std::uint8_t*)&id, (std::uint8_t*)&id + sizeof(uint32_t));
				return output;
			}
		} // namespace AMTHI_Client
	} // namespace MEI_Client
} // namespace Intel



	
