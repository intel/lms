/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2010-2023 Intel Corporation
 */
/*++

@file: GetCurrentPowerPolicyCommand.cpp

--*/

#include "GetCurrentPowerPolicyCommand.h"

namespace Intel {
	namespace MEI_Client {
		namespace AMTHI_Client {
			GetCurrentPowerPolicyCommand::GetCurrentPowerPolicyCommand()
			{
				m_request = std::make_shared<GetCurrentPowerPolicyRequest>();
				Transact();
			}

			std::string GetCurrentPowerPolicyCommand::getResponse()
			{
				return m_response.getResponse().powerPolicy;
			}

			void GetCurrentPowerPolicyCommand::parseResponse(const std::vector<uint8_t>& buffer)
			{
				m_response = AMTHICommandResponse<GetCurrentPowerPolicy_RESPONSE>(buffer, RESPONSE_COMMAND_NUMBER);
			}
		} // namespace AMTHI_Client
	} // namespace MEI_Client
} // namespace Intel