/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2010-2023 Intel Corporation
 */
/*++

@file: GetUserInitiatedEnabledInterfacesCommand.cpp

--*/

#include "GetUserInitiatedEnabledInterfacesCommand.h"

namespace Intel {
	namespace MEI_Client {
		namespace AMTHI_Client {
			GetUserInitiatedEnabledInterfacesCommand::GetUserInitiatedEnabledInterfacesCommand()
			{
				std::shared_ptr<MEICommandRequest> tmp(new GetUserInitiatedEnabledInterfacesRequest());
				m_request = tmp;
				Transact();
			}

			GET_USER_INITIATED_ENABLED_INTERFACES_RESPONSE GetUserInitiatedEnabledInterfacesCommand::getResponse()
			{
				return m_response.getResponse();
			}

			void GetUserInitiatedEnabledInterfacesCommand::parseResponse(const std::vector<uint8_t>& buffer)
			{
				m_response = AMTHICommandResponse<GET_USER_INITIATED_ENABLED_INTERFACES_RESPONSE>(buffer, RESPONSE_COMMAND_NUMBER);
			}
		} // namespace AMTHI_Client
	} // namespace MEI_Client
} // namespace Intel