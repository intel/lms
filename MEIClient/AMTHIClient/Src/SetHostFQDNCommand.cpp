/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2010-2019 Intel Corporation
 */
/*++

@file: SetHostFQDNCommand.cpp

--*/

#include "SetHostFQDNCommand.h"

namespace Intel {
	namespace MEI_Client {
		namespace AMTHI_Client {
			SetHostFQDNCommand::SetHostFQDNCommand(const std::string &FQDN)
			{
				std::shared_ptr<MEICommandRequest> tmp(new SetHostFQDNRequest(FQDN));
				m_request = tmp;
				Transact();
			}

			SET_HOST_FQDN_RESPONSE SetHostFQDNCommand::getResponse()
			{
				return m_response->getResponse();
			}

			void SetHostFQDNCommand::parseResponse(const std::vector<uint8_t>& buffer)
			{
				std::shared_ptr<AMTHICommandResponse<SET_HOST_FQDN_RESPONSE>> tmp(
					new AMTHICommandResponse<SET_HOST_FQDN_RESPONSE>(buffer, RESPONSE_COMMAND_NUMBER));
				m_response = tmp;
			}

			std::vector<uint8_t> SetHostFQDNRequest::SerializeData() {
				std::vector<uint8_t> output(_FQDN.serialize());
				return output;
			}
		} // namespace AMTHI_Client
	} // namespace MEI_Client
} // namespace Intel