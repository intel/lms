/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2010-2023 Intel Corporation
 */
/*++

@file: GetIPv6LanInterfaceStatusCommand.cpp

--*/

#include "GetIPv6LanInterfaceStatusCommand.h"

namespace Intel {
	namespace MEI_Client {
		namespace AMTHI_Client {
			GetIPv6LanInterfaceStatusCommand::GetIPv6LanInterfaceStatusCommand(uint32_t interfaceIndex)	//INTERFACE_SETTINGS
			{
				std::shared_ptr<MEICommandRequest> tmp(new GetIPv6LanInterfaceStatusRequest(interfaceIndex));
				m_request = tmp;
				Transact();
			}

			GET_IPv6_LAN_INTERFACE_STATUS_RESPONSE GetIPv6LanInterfaceStatusCommand::getResponse()
			{
				return m_response.getResponse();
			}

			void GetIPv6LanInterfaceStatusCommand::parseResponse(const std::vector<uint8_t>& buffer)
			{
				m_response = AMTHICommandResponse<GET_IPv6_LAN_INTERFACE_STATUS_RESPONSE>(buffer, RESPONSE_COMMAND_NUMBER);
			}

			std::vector<uint8_t> GetIPv6LanInterfaceStatusRequest::SerializeData()
			{
				std::vector<uint8_t> output((std::uint8_t*)&m_interfaceIndex, (std::uint8_t*)&m_interfaceIndex + sizeof(uint32_t));
				return output;
			}
		} // namespace AMTHI_Client
	} // namespace MEI_Client
} // namespace Intel