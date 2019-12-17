/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2010-2019 Intel Corporation
 */
/*++

@file: GetEACStateCommand.cpp

--*/

#include "GetEACStateCommand.h"

namespace Intel {
	namespace MEI_Client {
		namespace AMTHI_Client {
			GetEACStateCommand::GetEACStateCommand()
			{
				std::shared_ptr<MEICommandRequest> tmp(new GetEACStateRequest());
				m_request = tmp;
				Transact();
			}

			GET_EAC_STATE_RESPONSE GetEACStateCommand::getResponse()
			{
				return m_response->getResponse();
			}

			void GetEACStateCommand::parseResponse(const std::vector<uint8_t>& buffer)
			{
				std::shared_ptr<AMTHICommandResponse<GET_EAC_STATE_RESPONSE>> tmp(
					new AMTHICommandResponse<GET_EAC_STATE_RESPONSE>(buffer, RESPONSE_COMMAND_NUMBER));
				m_response = tmp;
			}

			std::vector<uint8_t> GetEACStateRequest::SerializeData()
			{
				uint32_t id = EAC_ID;
				std::vector<uint8_t> output((std::uint8_t*)&id, (std::uint8_t*)&id + sizeof(uint32_t));
				return output;
			}
		} // namespace AMTHI_Client
	} // namespace MEI_Client
} // namespace Intel