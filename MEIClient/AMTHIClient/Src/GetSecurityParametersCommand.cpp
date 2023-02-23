/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2010-2023 Intel Corporation
 */
/*++

@file: GetSecurityParametersCommand.cpp

--*/

#include "GetSecurityParametersCommand.h"

namespace Intel {
	namespace MEI_Client {
		namespace AMTHI_Client {
			GetSecurityParametersCommand::GetSecurityParametersCommand()
			{
				std::shared_ptr<MEICommandRequest> tmp(new GetSecurityParametersRequest());
				m_request = tmp;
				Transact();
			}

			SECURITY_PARAMETERS GetSecurityParametersCommand::getResponse()
			{
				return m_response.getResponse();
			}

			void GetSecurityParametersCommand::parseResponse(const std::vector<uint8_t>& buffer)
			{
				m_response = AMTHICommandResponse<SECURITY_PARAMETERS>(buffer, RESPONSE_COMMAND_NUMBER);
			}
		} // namespace AMTHI_Client
	} // namespace MEI_Client
} // namespace Intel