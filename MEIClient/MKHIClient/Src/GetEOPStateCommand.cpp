/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2010-2019 Intel Corporation
 */
/*++

@file: GetEOPStateCommand.cpp

--*/

#include "GetEOPStateCommand.h"

namespace Intel {
	namespace MEI_Client {
		namespace MKHI_Client {
			GetEOPStateCommand::GetEOPStateCommand()
			{
				std::shared_ptr<MEICommandRequest> tmp(new GetEOPStateRequest());
				m_request = tmp;
				Transact();
			}

			GET_EOP_STATE_RESPONSE GetEOPStateCommand::getResponse()
			{
				return m_response->getResponse();
			}

			void GetEOPStateCommand::parseResponse(const std::vector<uint8_t>& buffer)
			{
				std::shared_ptr<MKHICommandResponse<GET_EOP_STATE_RESPONSE>> tmp(
					new MKHICommandResponse<GET_EOP_STATE_RESPONSE>(buffer, RESPONSE_COMMAND_NUMBER, MKHI_GEN_GROUP_ID));
				m_response = tmp;
			}

			std::vector<uint8_t> GetEOPStateRequest::SerializeData()
			{
				std::vector<uint8_t> output(0, 0);
				return output;
			}
		} // namespace MKHI_Client
	} // namespace MEI_Client
} // namespace Intel