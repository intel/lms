/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2010-2019 Intel Corporation
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
				return m_response->getResponse();
			}

			void GetFQDNCommand::parseResponse(const std::vector<uint8_t>& buffer)
			{
				std::shared_ptr<AMTHICommandResponse<GET_FQDN_RESPONSE>> tmp(new AMTHICommandResponse<GET_FQDN_RESPONSE>(buffer, RESPONSE_COMMAND_NUMBER));
				m_response = tmp;
			}
		} // namespace AMTHI_Client
	} // namespace MEI_Client
} // namespace Intel