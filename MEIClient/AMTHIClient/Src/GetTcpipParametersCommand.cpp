/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2010-2023 Intel Corporation
 */
/*++

@file: GetTcpipParametersCommand.cpp

--*/

#include "GetTcpipParametersCommand.h"

namespace Intel {
	namespace MEI_Client {
		namespace AMTHI_Client {
			GetTcpipParametersCommand::GetTcpipParametersCommand()
			{
				m_request = std::make_shared<GetTcpipParametersRequest>();
				Transact();
			}

			TCPIP_PARAMETERS GetTcpipParametersCommand::getResponse()
			{
				return m_response.getResponse();
			}

			void GetTcpipParametersCommand::parseResponse(const std::vector<uint8_t>& buffer)
			{
				m_response = AMTHICommandResponse<TCPIP_PARAMETERS>(buffer, RESPONSE_COMMAND_NUMBER);
			}
		} // namespace AMTHI_Client
	} // namespace MEI_Client
} // namespace Intel