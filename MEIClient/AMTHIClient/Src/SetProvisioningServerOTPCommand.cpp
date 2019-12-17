/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2010-2019 Intel Corporation
 */
/*++

@file: SetProvisioningServerOTPCommand.cpp

--*/

#include "SetProvisioningServerOTPCommand.h"

namespace Intel {
	namespace MEI_Client {
		namespace AMTHI_Client {
			SetProvisioningServerOTPCommand::SetProvisioningServerOTPCommand(const std::string &passwordOTP)
			{
				std::shared_ptr<MEICommandRequest> tmp(new SetProvisioningServerOTPRequest(passwordOTP));
				m_request = tmp;
				Transact();
			}

			SET_PROVISIONING_SERVER_OTP_RESPONSE SetProvisioningServerOTPCommand::getResponse()
			{
				return m_response->getResponse();
			}

			void SetProvisioningServerOTPCommand::parseResponse(const std::vector<uint8_t>& buffer)
			{
				std::shared_ptr<AMTHICommandResponse<SET_PROVISIONING_SERVER_OTP_RESPONSE>> tmp(
					new AMTHICommandResponse<SET_PROVISIONING_SERVER_OTP_RESPONSE>(buffer, RESPONSE_COMMAND_NUMBER));
				m_response = tmp;
			}

			std::vector<uint8_t> SetProvisioningServerOTPRequest::SerializeData() {
				std::vector<uint8_t> output(_otp.serialize());
				return output;
			}
		} // namespace AMTHI_Client
	} // namespace MEI_Client
} // namespace Intel