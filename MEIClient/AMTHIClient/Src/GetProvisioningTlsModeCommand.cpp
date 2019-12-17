/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2010-2019 Intel Corporation
 */
/*++

@file: GetProvisioningTLSModeCommand.cpp

--*/

#include "GetProvisioningTlsModeCommand.h"

namespace Intel {
	namespace MEI_Client {
		namespace AMTHI_Client {
			GetProvisioningTLSModeCommand::GetProvisioningTLSModeCommand()
			{
				std::shared_ptr<MEICommandRequest> tmp(new GetProvisioningTLSModeRequest());
				m_request = tmp;
				Transact();
			}

			PROV_TLS_MODE_RESPONSE GetProvisioningTLSModeCommand::getResponse()
			{
				return m_response->getResponse();
			}

			void GetProvisioningTLSModeCommand::parseResponse(const std::vector<uint8_t>& buffer)
			{
				std::shared_ptr<AMTHICommandResponse<PROV_TLS_MODE_RESPONSE>> tmp(new AMTHICommandResponse<PROV_TLS_MODE_RESPONSE>(buffer, RESPONSE_COMMAND_NUMBER));
				m_response = tmp;
			}

			std::vector<uint8_t> GetProvisioningTLSModeRequest::SerializeData()
			{
				std::vector<uint8_t> output;
				return output;
			}
		} // namespace AMTHI_Client
	} // namespace MEI_Client
} // namespace Intel