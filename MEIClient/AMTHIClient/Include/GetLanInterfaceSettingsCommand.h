/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2010-2019 Intel Corporation
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
			typedef uint32_t CFG_IPv4_ADDRESS;

			struct LAN_SETTINGS
			{
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

			class GetLanInterfaceSettingRequest;
			//class GetLanInterfaceSettingResponse;
			class GetLanInterfaceSettingsCommand : public AMTHICommand
			{
			public:

				GetLanInterfaceSettingsCommand(uint32_t interfaceSettings);	//INTERFACE_SETTINGS
				virtual ~GetLanInterfaceSettingsCommand() {}

				LAN_SETTINGS getResponse();

			private:
				virtual void parseResponse(const std::vector<uint8_t>& buffer);

				std::shared_ptr<AMTHICommandResponse<LAN_SETTINGS>> m_response;

				static const uint32_t RESPONSE_COMMAND_NUMBER = 0x04800048;
			};

			class GetLanInterfaceSettingRequest : public AMTHICommandRequest
			{
			public:
				GetLanInterfaceSettingRequest(const uint32_t interfaceSettings):m_interfaceSettings(interfaceSettings) {}	//INTERFACE_SETTINGS
				virtual ~GetLanInterfaceSettingRequest() {}

			private:
				uint32_t m_interfaceSettings;	//INTERFACE_SETTINGS
				static const uint32_t REQUEST_COMMAND_NUMBER = 0x04000048;
				virtual unsigned int requestHeaderCommandNumber()
				{
					//this is the command number (taken from the AMTHI document)
					return REQUEST_COMMAND_NUMBER;
				}

				virtual uint32_t requestDataSize()
				{
					return sizeof(uint32_t);
				}
				virtual std::vector<uint8_t> SerializeData();
			};
		} // namespace AMTHI_Client
	} // namespace MEI_Client
} // namespace Intel

#endif //__GET_LAN_INTERFACE_SETTIGNS_COMMAND_H__