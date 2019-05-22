/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2010-2019 Intel Corporation
 */
/*++

@file: GetDNSSuffixListCommand.h

--*/

#ifndef __GET_DNS_SUFFIX_LIST_COMMAND_H__
#define __GET_DNS_SUFFIX_LIST_COMMAND_H__

#include "AMTHICommand.h"
#include "MEIparser.h"

namespace Intel
{
	namespace MEI_Client
	{
		namespace AMTHI_Client
		{
			struct GET_DNS_SUFFIX_LIST_RESPONSE
			{
				std::vector<uint8_t> HashHandles;

				void parse (std::vector<uint8_t>::const_iterator& itr, const std::vector<uint8_t>::const_iterator end)
				{
					Intel::MEI_Client::parseSimpleArray16(HashHandles, itr, end);
				}
			};

			class GetDNSSuffixListRequest;
			class GetDNSSuffixListCommand : public AMTHICommand
			{
			public:

				GetDNSSuffixListCommand ();
				virtual ~GetDNSSuffixListCommand () {}

				GET_DNS_SUFFIX_LIST_RESPONSE getResponse() ;

				virtual void reTransact();

			private:
				virtual void parseResponse(const std::vector<uint8_t>& buffer);

				std::shared_ptr<AMTHICommandResponse<GET_DNS_SUFFIX_LIST_RESPONSE> > m_response;

				static const uint32_t RESPONSE_COMMAND_NUMBER = 0x0480003E;

			};

			class GetDNSSuffixListRequest : public AMTHICommandRequest
			{
			public:
				GetDNSSuffixListRequest (){}
				virtual ~GetDNSSuffixListRequest() {}

			private:

				static const uint32_t REQUEST_COMMAND_NUMBER = 0x0400003E;
				virtual unsigned int requestHeaderCommandNumber()
				{
					//this is the command number (taken from the AMTHI document)
					return REQUEST_COMMAND_NUMBER;
				}

				virtual uint32_t requestDataSize()
				{
					return 0;
				}
				virtual std::vector<uint8_t> SerializeData();
			};
		} // namespace AMTHI_Client
	} // namespace MEI_Client
} // namespace Intel

#endif //__GET_DNS_SUFFIX_LIST_COMMAND_H__