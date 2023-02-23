/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2010-2023 Intel Corporation
 */
/*++

@file: GetRemoteAccessConnectionStatusCommand.cpp

--*/

#include "GetRemoteAccessConnectionStatusCommand.h"

namespace Intel {
	namespace MEI_Client {
		namespace AMTHI_Client {
			GetRemoteAccessConnectionStatusCommand::GetRemoteAccessConnectionStatusCommand()
			{
				m_request = std::make_shared<GetRemoteAccessConnectionStatusRequest>();
				Transact();
			}

			REMOTE_ACCESS_STATUS GetRemoteAccessConnectionStatusCommand::getResponse()
			{
				return m_response.getResponse();
			}

			void GetRemoteAccessConnectionStatusCommand::parseResponse(const std::vector<uint8_t>& buffer)
			{
				m_response = AMTHICommandResponse<REMOTE_ACCESS_STATUS>(buffer, RESPONSE_COMMAND_NUMBER);
			}
		} // namespace AMTHI_Client
	} // namespace MEI_Client
} // namespace Intel