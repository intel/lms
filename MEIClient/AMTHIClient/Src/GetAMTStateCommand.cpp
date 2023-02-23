/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2010-2023 Intel Corporation
 */
/*++

@file: GetAMTStateCommand.cpp

--*/

#include "GetAMTStateCommand.h"

namespace Intel {
	namespace MEI_Client {
		namespace AMTHI_Client {
			GetAMTStateCommand::GetAMTStateCommand(AMT_UUID StateVariableIdentifier)
			{
				std::shared_ptr<MEICommandRequest> tmp(new GetAMTStateRequest(StateVariableIdentifier));
				m_request = tmp;
				Transact();
			}

			AMT_STATE_RESPONSE GetAMTStateCommand::getResponse()
			{
				return m_response.getResponse();
			}

			void GetAMTStateCommand::parseResponse(const std::vector<uint8_t>& buffer)
			{
				m_response = AMTHICommandResponse<AMT_STATE_RESPONSE>(buffer, RESPONSE_COMMAND_NUMBER);
			}

			std::vector<uint8_t> GetAMTStateRequest::SerializeData()
			{
				std::vector<uint8_t> output(m_stateVariableIdentifier.amt_uuid, m_stateVariableIdentifier.amt_uuid + sizeof(AMT_UUID));
				return output;
			}
		} // namespace AMTHI_Client
	} // namespace MEI_Client
} // namespace Intel