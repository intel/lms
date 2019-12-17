/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2010-2019 Intel Corporation
 */
/*++

@file: GetLanInterfaceSettingsCommand.cpp

--*/

#include "GetLanInterfaceSettingsCommand.h"

namespace Intel {
	namespace MEI_Client {
		namespace AMTHI_Client {
			GetLanInterfaceSettingsCommand::GetLanInterfaceSettingsCommand(uint32_t interfaceSettings)	//INTERFACE_SETTINGS
			{
				std::shared_ptr<MEICommandRequest> tmp(new GetLanInterfaceSettingRequest(interfaceSettings));
				m_request = tmp;
				Transact();
			}

			LAN_SETTINGS GetLanInterfaceSettingsCommand::getResponse()
			{
				return m_response->getResponse();
			}

			void GetLanInterfaceSettingsCommand::parseResponse(const std::vector<uint8_t>& buffer)
			{
				std::shared_ptr<AMTHICommandResponse<LAN_SETTINGS>> tmp(new AMTHICommandResponse<LAN_SETTINGS>(buffer, RESPONSE_COMMAND_NUMBER));
				m_response = tmp;
			}

			std::vector<uint8_t> GetLanInterfaceSettingRequest::SerializeData()
			{
				std::vector<uint8_t> output((std::uint8_t*)&m_interfaceSettings, (std::uint8_t*)&m_interfaceSettings + sizeof(uint32_t));
				return output;
			}
		} // namespace AMTHI_Client
	} // namespace MEI_Client
} // namespace Intel