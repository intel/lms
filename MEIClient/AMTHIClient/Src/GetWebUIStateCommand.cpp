/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2010-2019 Intel Corporation
 */
/*++

@file: GetWebUIStateCommand.cpp

--*/

#include "GetWebUIStateCommand.h"

namespace Intel {
	namespace MEI_Client {
		namespace AMTHI_Client {
			GetWebUIStateCommand::GetWebUIStateCommand()
			{
				std::shared_ptr<MEICommandRequest> tmp(new GetWebUIStateRequest());
				m_request = tmp;
				Transact();
			}

			GET_WEB_UI_STATE_RESPONSE GetWebUIStateCommand::getResponse()
			{
				return m_response->getResponse();
			}

			void GetWebUIStateCommand::parseResponse(const std::vector<uint8_t>& buffer)
			{
				std::shared_ptr<AMTHICommandResponse<GET_WEB_UI_STATE_RESPONSE>> tmp(
					new AMTHICommandResponse<GET_WEB_UI_STATE_RESPONSE>(buffer, RESPONSE_COMMAND_NUMBER));
				m_response = tmp;
			}

			std::vector<uint8_t> GetWebUIStateRequest::SerializeData()
			{
				uint32_t id = WEB_UI_STATE_ID;
				std::vector<uint8_t> output((std::uint8_t*)&id, (std::uint8_t*)&id + sizeof(uint32_t));
				return output;
			}
		} // namespace AMTHI_Client
	} // namespace MEI_Client
} // namespace Intel