/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2010-2023 Intel Corporation
 */
/*++

@file: GetIPv6LanInterfaceStatusCommand.h

--*/

#ifndef __GET_IPv6_LAN_INTERFACE_STATUS_COMMAND_H__
#define __GET_IPv6_LAN_INTERFACE_STATUS_COMMAND_H__


#include <cstring>
#include <string>
#include <vector>
#include "MEIparser.h"
#include "AMTHICommand.h"

namespace Intel
{
	namespace MEI_Client
	{
		namespace AMTHI_Client
		{
			enum CFG_IPv6_ADDR_TYPE		//uint32_t
			{
				CFG_Ipv6_ADDR_TYPE_LINK_LOCAL		= 0,
				CFG_Ipv6_ADDR_TYPE_ROUTER_CONF		= 1,
				CFG_Ipv6_ADDR_TYPE_DHCPv6			= 2,
				CFG_Ipv6_ADDR_TYPE_MANUAL			= 3,
				CFG_Ipv6_ADDR_TYPE_UNKNOWN			= 4
			};

			enum CFG_IPv6_ADDR_STATE	//uint32_t
			{
				CFG_Ipv6_ADDR_STATE_TENTATIVE		= 0,
				CFG_Ipv6_ADDR_STATE_PREFERRED		= 1,
				CFG_Ipv6_ADDR_STATE_DEPRECATED		= 2,
				CFG_Ipv6_ADDR_STATE_VALID			= 3,
				CFG_Ipv6_ADDR_STATE_INVALID		= 4,
				CFG_Ipv6_ADDR_STATE_COLLISION		= 5,
				CFG_Ipv6_ADDR_STATE_UNKNOWN		= 6
			};

			struct CFG_IPv6_ADDR_INFO
			{
				CFG_IPv6_ADDR_INFO() : Type(0), State(0) {}
				std::string Address;
				uint32_t Type;	//CFG_IPv6_ADDR_TYPE
				uint32_t State; //CFG_IPv6_ADDR_STATE
				
				void parse (std::vector<uint8_t>::const_iterator& itr, const std::vector<uint8_t>::const_iterator end)
				{
					CFG_IP_ADDR itmp;
					parseData(itmp,itr,end);
					Address = itmp.toString();
					parseData(Type,itr,end);
					parseData(State,itr,end);
				}
			};

			struct GET_IPv6_LAN_INTERFACE_STATUS_RESPONSE
			{
				std::string				    IPv6DefaultRouter;
				std::string				    PrimaryDNS;
				std::string				    SecondaryDNS;
				std::vector<CFG_IPv6_ADDR_INFO>  IPv6Addresses;

				void parse (std::vector<uint8_t>::const_iterator& itr, const std::vector<uint8_t>::const_iterator end)
				{
					CFG_IP_ADDR itmp;
					parseData(itmp,itr,end);
					IPv6DefaultRouter = itmp.toString();

					parseData(itmp,itr,end);
					PrimaryDNS = itmp.toString();

					parseData(itmp,itr,end);
					SecondaryDNS = itmp.toString();

					parseComplexArray(IPv6Addresses,itr,end);
				}
			};

			class GetIPv6LanInterfaceStatusCommand : public AMTHICommand
			{
			public:

				GetIPv6LanInterfaceStatusCommand(uint32_t interfaceIndex);	//INTERFACE_SETTINGS
				virtual ~GetIPv6LanInterfaceStatusCommand() {}

				GET_IPv6_LAN_INTERFACE_STATUS_RESPONSE getResponse();

			private:
				virtual void parseResponse(const std::vector<uint8_t>& buffer);

				AMTHICommandResponse<GET_IPv6_LAN_INTERFACE_STATUS_RESPONSE> m_response;
				
				static const uint32_t RESPONSE_COMMAND_NUMBER = 0x04800052;
			};

			class GetIPv6LanInterfaceStatusRequest : public AMTHICommandRequest
			{
			public:
				GetIPv6LanInterfaceStatusRequest(const uint32_t interfaceIndex):
					m_interfaceIndex(interfaceIndex), AMTHICommandRequest(REQUEST_COMMAND_NUMBER) {} //INTERFACE_SETTINGS
				virtual ~GetIPv6LanInterfaceStatusRequest() {}

			private:
				uint32_t m_interfaceIndex;	//INTERFACE_SETTINGS
				static const uint32_t REQUEST_COMMAND_NUMBER = 0x04000052;

				virtual uint32_t requestDataSize()
				{
					return sizeof(uint32_t);
				}
				virtual std::vector<uint8_t> SerializeData();
			};
		} // namespace AMTHI_Client
	} // namespace MEI_Client
} // namespace Intel

#endif //__GET_IPv6_LAN_INTERFACE_STATUS_COMMAND_H__