/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2010-2019 Intel Corporation
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
				return m_response->getResponse();
			}

			void GetUserInitiatedEnabledInterfacesCommand::parseResponse(const std::vector<uint8_t>& buffer)
			{
				std::shared_ptr<AMTHICommandResponse<GET_USER_INITIATED_ENABLED_INTERFACES_RESPONSE>> tmp(
					new AMTHICommandResponse<GET_USER_INITIATED_ENABLED_INTERFACES_RESPONSE>(buffer, RESPONSE_COMMAND_NUMBER));
				m_response = tmp;
			}

			std::vector<uint8_t> GetUserInitiatedEnabledInterfacesRequest::SerializeData()
			{
				std::vector<uint8_t> output;
				return output;
			}
		} // namespace AMTHI_Client
	} // namespace MEI_Client
} // namespace Intel