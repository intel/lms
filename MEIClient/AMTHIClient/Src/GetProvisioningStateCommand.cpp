/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2010-2023 Intel Corporation
 */
/*++

@file: GetProvisioningStateCommand.cpp

--*/

#include "GetProvisioningStateCommand.h"

namespace Intel {
	namespace MEI_Client {
		namespace AMTHI_Client {
			GetProvisioningStateCommand::GetProvisioningStateCommand()
			{
				m_request = std::make_shared<GetProvisioningStateRequest>();
				Transact();
			}

			CFG_PROVISIONING_STATE GetProvisioningStateCommand::getResponse()
			{
				return m_response.getResponse();
			}

			void GetProvisioningStateCommand::parseResponse(const std::vector<uint8_t>& buffer)
			{
				m_response = AMTHICommandResponse<CFG_PROVISIONING_STATE>(buffer, RESPONSE_COMMAND_NUMBER);
			}
		} // namespace AMTHI_Client
	} // namespace MEI_Client
} // namespace Intel	