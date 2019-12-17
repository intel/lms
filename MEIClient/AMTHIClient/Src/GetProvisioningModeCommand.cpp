/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2010-2019 Intel Corporation
 */
/*++

@file: GetProvisioningModeCommand.cpp

--*/

#include "GetProvisioningModeCommand.h"

namespace Intel {
	namespace MEI_Client {
		namespace AMTHI_Client {
			GetProvisioningModeCommand::GetProvisioningModeCommand()
			{
				std::shared_ptr<MEICommandRequest> tmp(new GetProvisioningModeRequest());
				m_request = tmp;
				Transact();
			}

			PROVISIONING_MODE_SETTINGS GetProvisioningModeCommand::getResponse()
			{
				return m_response->getResponse();
			}

			void GetProvisioningModeCommand::parseResponse(const std::vector<uint8_t>& buffer)
			{
				std::shared_ptr<AMTHICommandResponse<PROVISIONING_MODE_SETTINGS>> tmp(new AMTHICommandResponse<PROVISIONING_MODE_SETTINGS>(buffer, RESPONSE_COMMAND_NUMBER));
				m_response = tmp;
			}

			std::vector<uint8_t> GetProvisioningModeRequest::SerializeData()
			{
				std::vector<uint8_t> output;
				return output;
			}
		} // namespace AMTHI_Client
	} // namespace MEI_Client
} // namespace Intel