/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2010-2023 Intel Corporation
 */
/*++

@file: GetTcpipParametersCommand.h

--*/

#ifndef __GET_TCPIP_PARAMETERS_COMMAND_H__
#define __GET_TCPIP_PARAMETERS_COMMAND_H__

#include "AMTHICommand.h"
#include "AmtAnsiString.h"
#include "MEIparser.h"
#include <cstring>
#include <string>

namespace Intel
{
	namespace MEI_Client
	{
		namespace AMTHI_Client
		{
			enum CFG_DHCP_MODE //uint32_t
			{
				CFG_DHCP_MODE_NONE = 0,
				CFG_DHCP_MODE_DISABLED = 1,
				CFG_DHCP_MODE_ENABLED = 2
			};
			struct TCPIP_PARAMETERS
			{
				uint32_t				DhcpMode; //Represents CFG_DHCP_MODE
				CFG_IPv4_ADDRESS	LocalAddress;			//Ignored if DhcpMode is not CFG_DHCP_MODE_DISABLED.
				CFG_IPv4_ADDRESS	SubnetMask;				//Ignored if DhcpMode is not CFG_DHCP_MODE_DISABLED.
				CFG_IPv4_ADDRESS	DefaultGatewayAddress;	//Ignored if DhcpMode is not CFG_DHCP_MODE_DISABLED.
				CFG_IPv4_ADDRESS	PrimaryDnsAddress;		//0 value indicate the entry is not set
				CFG_IPv4_ADDRESS	SecondaryDnsAddress;	//0 value indicate the entry is not set
				std::string			DomainName;				//Ignored if DhcpMode is not CFG_DHCP_MODE_DISABLED.

				void parse (std::vector<uint8_t>::const_iterator& itr, const std::vector<uint8_t>::const_iterator end)
				{
					Intel::MEI_Client::parseData (DhcpMode,itr,end);
					Intel::MEI_Client::parseData (LocalAddress,itr,end);
					Intel::MEI_Client::parseData (SubnetMask,itr,end);
					Intel::MEI_Client::parseData (DefaultGatewayAddress,itr,end);
					Intel::MEI_Client::parseData (PrimaryDnsAddress,itr,end);
					Intel::MEI_Client::parseData (SecondaryDnsAddress,itr,end);
					DomainName = AmtAnsiString(itr, end).getString();
				}
			 };

			class GetTcpipParametersCommand : public AMTHICommand
			{
			public:

				GetTcpipParametersCommand();
				virtual ~GetTcpipParametersCommand() {}

				TCPIP_PARAMETERS getResponse();

			private:
				virtual void parseResponse(const std::vector<uint8_t>& buffer);

				std::shared_ptr<AMTHICommandResponse<TCPIP_PARAMETERS>> m_response;

				static const uint32_t RESPONSE_COMMAND_NUMBER = 0x04800006;
			};

			class GetTcpipParametersRequest : public AMTHICommandRequest
			{
			public:
				GetTcpipParametersRequest() : AMTHICommandRequest(REQUEST_COMMAND_NUMBER) {}
				virtual ~GetTcpipParametersRequest() {}

			private:
				static const uint32_t REQUEST_COMMAND_NUMBER = 0x04000006;
			};
		} // namespace AMTHI_Client
	} // namespace MEI_Client
} // namespace Intel

#endif //__GET_TCPIP_PARAMETERS_COMMAND_H__