/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2010-2019 Intel Corporation
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
				std::shared_ptr<MEICommandRequest> tmp(new GetTcpipParametersRequest());
				m_request = tmp;
				Transact();
			}

			TCPIP_PARAMETERS GetTcpipParametersCommand::getResponse()
			{
				return m_response->getResponse();
			}

			void GetTcpipParametersCommand::parseResponse(const std::vector<uint8_t>& buffer)
			{
				std::shared_ptr<AMTHICommandResponse<TCPIP_PARAMETERS>> tmp(new AMTHICommandResponse<TCPIP_PARAMETERS>(buffer, RESPONSE_COMMAND_NUMBER));
				m_response = tmp;
			}
		} // namespace AMTHI_Client
	} // namespace MEI_Client
} // namespace Intel