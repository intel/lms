/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2010-2019 Intel Corporation
 */
/*++

@file: GetPlatformTypeCommand.cpp

--*/

#include "GetPlatformTypeCommand.h"

namespace Intel {
	namespace MEI_Client {
		namespace MKHI_Client {
			GetPlatformTypeCommand::GetPlatformTypeCommand()
			{
				std::shared_ptr<MEICommandRequest> tmp(new GetPlatformTypeRequest());
				m_request = tmp;
				Transact();
			}

			MKHI_PLATFORM_TYPE GetPlatformTypeCommand::getResponse()
			{
				return m_response->getResponse();
			}

			void GetPlatformTypeCommand::parseResponse(const std::vector<uint8_t>& buffer)
			{
				std::shared_ptr<MKHIGetRuleCommandResponse<MKHI_PLATFORM_TYPE>> tmp(
					new MKHIGetRuleCommandResponse<MKHI_PLATFORM_TYPE>(buffer, RESPONSE_COMMAND_NUMBER, MKHI_FWCAPS_GROUP_ID, MEFWCAPS_PCV_OEM_PLAT_TYPE_CFG_RULE_ID));
				m_response = tmp;
			}

			std::vector<uint8_t> GetPlatformTypeRequest::SerializeData()
			{
				RULE_ID rule;
				rule.Data = MEFWCAPS_PCV_OEM_PLAT_TYPE_CFG_RULE_ID;
				std::vector<uint8_t> output((std::uint8_t*)&rule, (std::uint8_t*)&rule + sizeof(rule));

				return output;
			}
		} // namespace MKHI_Client
	} // namespace MEI_Client
} // namespace Intel