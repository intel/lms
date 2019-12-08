/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2010-2019 Intel Corporation
 */
/*++

@file: SetCertificateHashStateCommand.h

--*/

#ifndef __ADD_PROXY_TABLE_ENTRY_COMMAND_H__
#define __ADD_PROXY_TABLE_ENTRY_COMMAND_H__


#include "AMTHICommand.h"
#include "MEIparser.h"
#include "AmtAnsiString.h"
#include <algorithm>
#include <iterator>
#include <climits>

namespace Intel
{
	namespace MEI_Client
	{
		namespace AMTHI_Client
		{
			static const size_t MAC_ADDRESS_SIZE = 6;

			//CFG_AddProxyTableEntry_Response
			struct ADD_PROXY_TABLE_ENTRY_RESPONSE 
			{
				void parse (std::vector<uint8_t>::const_iterator& /*itr*/, const std::vector<uint8_t>::const_iterator& /*end*/)
				{
					return;
				}
			};

			class AddProxyTableEntryRequest;
			
			class AddProxyTableEntryCommand : public AMTHICommand
			{
			public:

				AddProxyTableEntryCommand(uint16_t proxyPort, uint8_t gatewayMAC[MAC_ADDRESS_SIZE],
					const std::string &proxyFQDN, const std::string &networkDnsSuffix);
				virtual ~AddProxyTableEntryCommand() {}
				virtual void reTransact(uint16_t proxyPort, uint8_t gatewayMAC[MAC_ADDRESS_SIZE],
					const std::string &proxyFQDN, const std::string &networkDnsSuffix);

			private:
				virtual void parseResponse(const std::vector<uint8_t>& buffer);

				std::shared_ptr<AMTHICommandResponse<ADD_PROXY_TABLE_ENTRY_RESPONSE> > m_response;

				static const uint32_t RESPONSE_COMMAND_NUMBER = 0x0480007C ;
			};

			//CFG_AddProxyTableEntry_Request
			class AddProxyTableEntryRequest: public AMTHICommandRequest
			{
			public:
				AddProxyTableEntryRequest(	uint16_t proxyPort, 
											uint8_t gatewayMAC[MAC_ADDRESS_SIZE],
											const std::string &proxyFQDN, 
											const std::string &networkDnsSuffix) :
					_proxyPort(proxyPort), 
					_proxyFQDN(proxyFQDN), 
					_networkDnsSuffix(networkDnsSuffix) 
				{
					std::copy_n(&gatewayMAC[0], MAC_ADDRESS_SIZE, std::back_inserter(_gatewayMAC));
				}
				virtual ~AddProxyTableEntryRequest() {}

			private:
				static const uint32_t REQUEST_COMMAND_NUMBER = 0x0400007C;
				virtual unsigned int requestHeaderCommandNumber()
				{
					//this is the command number (taken from the AMTHI document)
					return REQUEST_COMMAND_NUMBER;
				}

				virtual uint32_t requestDataSize()
				{
					if (_proxyFQDN.bufSize() + _networkDnsSuffix.bufSize() < _proxyFQDN.bufSize()) //unsigned int overflow
						return UINT_MAX;
					unsigned int uint16AndMac = sizeof(uint16_t) + MAC_ADDRESS_SIZE;
					unsigned int buffers = _proxyFQDN.bufSize() + _networkDnsSuffix.bufSize();
					if (uint16AndMac + buffers < uint16AndMac) //unsigned int overflow
						return UINT_MAX;

					return sizeof(uint16_t) + MAC_ADDRESS_SIZE + _proxyFQDN.bufSize() + _networkDnsSuffix.bufSize();
				}
				virtual std::vector<uint8_t> SerializeData();

				uint16_t _proxyPort;
				std::vector<uint8_t> _gatewayMAC;
				AmtAnsiString _proxyFQDN;
				AmtAnsiString _networkDnsSuffix;
			};
		} // namespace AMTHI_Client
	} // namespace MEI_Client
} // namespace Intel

#endif //__ADD_PROXY_TABLE_ENTRY_COMMAND_H__