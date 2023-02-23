/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2010-2023 Intel Corporation
 */
/*++

@file: GetLanInterfaceSettingsCommand.h

--*/

#ifndef __GET_LAN_INTERFACE_SETTIGNS_COMMAND_H__
#define __GET_LAN_INTERFACE_SETTIGNS_COMMAND_H__

#include "AMTHICommand.h"
#include "MEIparser.h"

namespace Intel
{
	namespace MEI_Client
	{
		namespace AMTHI_Client
		{
			struct LAN_SETTINGS
			{
				LAN_SETTINGS() : Enabled(AMT_FALSE), Ipv4Address(0), DhcpEnabled(AMT_FALSE), DhcpIpMode(0),
					LinkStatus(0), MacAddress { 0 } {}
				AMT_BOOLEAN Enabled;
				CFG_IPv4_ADDRESS Ipv4Address;
				AMT_BOOLEAN DhcpEnabled;
				uint8_t DhcpIpMode;
				uint8_t LinkStatus;
				uint8_t MacAddress[6];
				void parse (std::vector<uint8_t>::const_iterator &itr, const std::vector<uint8_t>::const_iterator end)
				{
					Intel::MEI_Client::parseData(*this, itr, end);
				}
			};

			class GetLanInterfaceSettingRequest : public AMTHICommandRequest
			{
			public:
				GetLanInterfaceSettingRequest(const uint32_t interfaceSettings) :
					AMTHICommandRequest(REQUEST_COMMAND_NUMBER), m_interfaceSettings(interfaceSettings) {} //INTERFACE_SETTINGS
				virtual ~GetLanInterfaceSettingRequest() {}

			private:
				uint32_t m_interfaceSettings;	//INTERFACE_SETTINGS
				static const uint32_t REQUEST_COMMAND_NUMBER = 0x04000048;

				virtual uint32_t requestDataSize()
				{
					return sizeof(uint32_t);
				}
				virtual std::vector<uint8_t> SerializeData()
				{
					std::vector<uint8_t> output((std::uint8_t*)&m_interfaceSettings, (std::uint8_t*)&m_interfaceSettings + sizeof(uint32_t));
					return output;
				}
			};

			class GetLanInterfaceSettingsCommand : public AMTHICommand
			{
			public:

				GetLanInterfaceSettingsCommand(uint32_t interfaceSettings) //INTERFACE_SETTINGS
				{
					m_request = std::make_shared<GetLanInterfaceSettingRequest>(interfaceSettings);
					Transact();
				}
				virtual ~GetLanInterfaceSettingsCommand() {}

				LAN_SETTINGS getResponse() { return m_response.getResponse(); }

			private:
				virtual void parseResponse(const std::vector<uint8_t>& buffer)
				{
					m_response = AMTHICommandResponse<LAN_SETTINGS>(buffer, RESPONSE_COMMAND_NUMBER);
				}

				AMTHICommandResponse<LAN_SETTINGS> m_response;

				static const uint32_t RESPONSE_COMMAND_NUMBER = 0x04800048;
			};
		} // namespace AMTHI_Client
	} // namespace MEI_Client
} // namespace Intel

#endif //__GET_LAN_INTERFACE_SETTIGNS_COMMAND_H__