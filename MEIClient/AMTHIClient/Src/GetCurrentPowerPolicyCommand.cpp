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
				std::shared_ptr<MEICommandRequest> tmp(new GetCurrentPowerPolicyRequest());
				m_request = tmp;
				Transact();
			}

			std::string GetCurrentPowerPolicyCommand::getResponse()
			{
				return m_response->getResponse().powerPolicy;
			}

			void GetCurrentPowerPolicyCommand::parseResponse(const std::vector<uint8_t>& buffer)
			{
				std::shared_ptr<AMTHICommandResponse<GetCurrentPowerPolicy_RESPONSE>> tmp(new AMTHICommandResponse<GetCurrentPowerPolicy_RESPONSE>(buffer, RESPONSE_COMMAND_NUMBER));
				m_response = tmp;
			}
		} // namespace AMTHI_Client
	} // namespace MEI_Client
} // namespace Intel