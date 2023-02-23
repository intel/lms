/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2010-2023 Intel Corporation
 */
/*++

@file: UnprovisionCommand.cpp

--*/

#include "UnprovisionCommand.h"

namespace Intel {
	namespace MEI_Client {
		namespace AMTHI_Client {
			UnprovisionCommand::UnprovisionCommand(const CFG_PROVISIONING_MODE Mode)
			{
				m_request = std::make_shared<UnprovisionRequest>(Mode);
				Transact();
			}

			void UnprovisionCommand::parseResponse(const std::vector<uint8_t>& buffer)
			{
				m_response = AMTHICommandResponse<Unprovision_RESPONSE>(buffer, RESPONSE_COMMAND_NUMBER);
			}

			std::vector<uint8_t> UnprovisionRequest::SerializeData()
			{
				std::vector<uint8_t> output((std::uint8_t*)&m_mode, (std::uint8_t*)&m_mode + sizeof(m_mode));
				return output;
			}
		} // namespace AMTHI_Client
	} // namespace MEI_Client
} // namespace Intel