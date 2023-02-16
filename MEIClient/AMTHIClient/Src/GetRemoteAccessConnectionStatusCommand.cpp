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
				std::shared_ptr<MEICommandRequest> tmp(new GetRemoteAccessConnectionStatusRequest());
				m_request = tmp;
				Transact();
			}

			REMOTE_ACCESS_STATUS GetRemoteAccessConnectionStatusCommand::getResponse()
			{
				return m_response->getResponse();
			}

			void GetRemoteAccessConnectionStatusCommand::parseResponse(const std::vector<uint8_t>& buffer)
			{
				std::shared_ptr<AMTHICommandResponse<REMOTE_ACCESS_STATUS>> tmp(new AMTHICommandResponse<REMOTE_ACCESS_STATUS>(buffer, RESPONSE_COMMAND_NUMBER));
				m_response = tmp;
			}
		} // namespace AMTHI_Client
	} // namespace MEI_Client
} // namespace Intel