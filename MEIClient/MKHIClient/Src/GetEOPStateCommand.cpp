/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2010-2023 Intel Corporation
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
				m_request = std::make_shared<GetEOPStateRequest>();
				Transact();
			}

			GET_EOP_STATE_RESPONSE GetEOPStateCommand::getResponse()
			{
				return m_response.getResponse();
			}

			void GetEOPStateCommand::parseResponse(const std::vector<uint8_t>& buffer)
			{
				m_response = MKHICommandResponse<GET_EOP_STATE_RESPONSE>(buffer, RESPONSE_COMMAND_NUMBER, MKHI_GEN_GROUP_ID);
			}
		} // namespace MKHI_Client
	} // namespace MEI_Client
} // namespace Intel