/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2010-2023 Intel Corporation
 */
/*++

@file: GetFQDNCommand.cpp

--*/

#include "GetFQDNCommand.h"

namespace Intel {
	namespace MEI_Client {
		namespace AMTHI_Client {
			GetFQDNCommand::GetFQDNCommand()
			{
				std::shared_ptr<MEICommandRequest> tmp(new GetFQDNRequest());
				m_request = tmp;
				Transact();
			}

			GET_FQDN_RESPONSE GetFQDNCommand::getResponse()
			{
				return m_response.getResponse();
			}

			void GetFQDNCommand::parseResponse(const std::vector<uint8_t>& buffer)
			{
				m_response = AMTHICommandResponse<GET_FQDN_RESPONSE>(buffer, RESPONSE_COMMAND_NUMBER);
			}
		} // namespace AMTHI_Client
	} // namespace MEI_Client
} // namespace Intel