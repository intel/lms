/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2010-2019 Intel Corporation
 */
/*++

@file: GetRedirectionStateCommand.cpp

--*/

#include "GetRedirectionStateCommand.h"

namespace Intel {
	namespace MEI_Client {
		namespace AMTHI_Client {
			GetRedirectionStateCommand::GetRedirectionStateCommand()
			{
				std::shared_ptr<MEICommandRequest> tmp(new GetRedirectionStateRequest());
				m_request = tmp;
				Transact();
			}

			REDIRECTION_STATE GetRedirectionStateCommand::getResponse()
			{
				return m_response->getResponse();
			}

			void GetRedirectionStateCommand::parseResponse(const std::vector<uint8_t>& buffer)
			{
				std::shared_ptr<AMTHICommandResponse<REDIRECTION_STATE>> tmp(new AMTHICommandResponse<REDIRECTION_STATE>(buffer, RESPONSE_COMMAND_NUMBER));
				m_response = tmp;
			}
		} // namespace AMTHI_Client
	} // namespace MEI_Client
} // namespace Intel