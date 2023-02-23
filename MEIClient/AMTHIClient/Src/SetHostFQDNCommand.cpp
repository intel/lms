/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2010-2023 Intel Corporation
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
				m_request = std::make_shared<SetHostFQDNRequest>(FQDN);
				Transact();
			}

			void SetHostFQDNCommand::parseResponse(const std::vector<uint8_t>& buffer)
			{
				m_response = AMTHICommandResponse<SET_HOST_FQDN_RESPONSE>(buffer, RESPONSE_COMMAND_NUMBER);
			}

			std::vector<uint8_t> SetHostFQDNRequest::SerializeData() {
				std::vector<uint8_t> output(_FQDN.serialize());
				return output;
			}
		} // namespace AMTHI_Client
	} // namespace MEI_Client
} // namespace Intel