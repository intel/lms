/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2010-2019 Intel Corporation
 */
/*++

@file: GetKVMSessionStateCommand.cpp

--*/

#include "GetKVMSessionStateCommand.h"

namespace Intel {
	namespace MEI_Client {
		namespace AMTHI_Client {
			GetKVMSessionStateCommand::GetKVMSessionStateCommand()
			{
				std::shared_ptr<MEICommandRequest> tmp(new GetKVMSessionStateRequest());
				m_request = tmp;
				Transact();
			}

			GET_KVM_SESSION_STATE_RESPONSE GetKVMSessionStateCommand::getResponse()
			{
				return m_response->getResponse();
			}

			void GetKVMSessionStateCommand::parseResponse(const std::vector<uint8_t>& buffer)
			{
				std::shared_ptr<AMTHICommandResponse<GET_KVM_SESSION_STATE_RESPONSE>> tmp(
					new AMTHICommandResponse<GET_KVM_SESSION_STATE_RESPONSE>(buffer, RESPONSE_COMMAND_NUMBER));
				m_response = tmp;
			}

			std::vector<uint8_t> GetKVMSessionStateRequest::SerializeData()
			{
				uint32_t id = KVM_SESSION_ID;
				std::vector<uint8_t> output((std::uint8_t*)&id, (std::uint8_t*)&id + sizeof(uint32_t));
				return output;
			}
		} // namespace AMTHI_Client
	} // namespace MEI_Client
} // namespace Intel