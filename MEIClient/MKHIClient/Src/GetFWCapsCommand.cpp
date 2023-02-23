/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2010-2023 Intel Corporation
 */
/*++

@file: GetFWCapsCommand.cpp

--*/

#include "GetFWCapsCommand.h"

namespace Intel {
	namespace MEI_Client {
		namespace MKHI_Client {
			GetFWCapsCommand::GetFWCapsCommand(CapsRule rule)
			{
				m_rule = rule;
				std::shared_ptr<MEICommandRequest> tmp(new GetFWCapsRequest(rule));
				m_request = tmp;
				Transact();
			}

			MEFWCAPS_SKU_MKHI GetFWCapsCommand::getResponse()
			{
				return m_response.getResponse();
			}

			void GetFWCapsCommand::parseResponse(const std::vector<uint8_t>& buffer)
			{
				m_response = MKHIGetRuleCommandResponse<MEFWCAPS_SKU_MKHI>(buffer, RESPONSE_COMMAND_NUMBER, MKHI_FWCAPS_GROUP_ID, m_rule);
			}

			std::vector<uint8_t> GetFWCapsRequest::SerializeData()
			{
				std::vector<uint8_t> output((std::uint8_t*)&m_rule, (std::uint8_t*)&m_rule + sizeof(m_rule));
				return output;
			}
		} // namespace MKHI_Client
	} // namespace MEI_Client
} // namespace Intel