/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2010-2023 Intel Corporation
 */
/*++

@file: GetFWUpdateStateCommand.cpp

--*/

#include "GetFWUpdateStateCommand.h"

namespace Intel {
	namespace MEI_Client {
		namespace MKHI_Client {
			GetFWUpdateStateCommand::GetFWUpdateStateCommand()
			{
				std::shared_ptr<MEICommandRequest> tmp(new GetFWUpdateStateRequest());
				m_request = tmp;
				Transact();
			}

			FW_UPDATE_STATE GetFWUpdateStateCommand::getResponse()
			{
				return m_response.getResponse();
			}

			void GetFWUpdateStateCommand::parseResponse(const std::vector<uint8_t>& buffer)
			{
				m_response = MKHIGetRuleCommandResponse<FW_UPDATE_STATE>(buffer, RESPONSE_COMMAND_NUMBER, MKHI_FWCAPS_GROUP_ID, MEFWCAPS_ME_FW_UPDATE_RULE_ID);
			}

			std::vector<uint8_t> GetFWUpdateStateRequest::SerializeData()
			{
				RULE_ID rule;
				rule.Data = MEFWCAPS_ME_FW_UPDATE_RULE_ID;
				std::vector<uint8_t> output((std::uint8_t*)&rule, (std::uint8_t*)&rule + sizeof(rule));

				return output;
			}
		} // namespace MKHI_Client
	} // namespace MEI_Client
} // namespace Intel