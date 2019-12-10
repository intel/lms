/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2010-2019 Intel Corporation
 */
/*++

@file: GetDNSSuffixCommand.h

--*/

#ifndef __GET_DNS_SUFFIX_COMMAND_H__
#define __GET_DNS_SUFFIX_COMMAND_H__

#include "AMTHICommand.h"
#include "AmtAnsiString.h"

namespace Intel
{
	namespace MEI_Client
	{
		namespace AMTHI_Client
		{
			struct GetDNSSuffix_RESPONSE
			{
				std::string DNSSuffix;
				void parse (std::vector<uint8_t>::const_iterator& itr, const std::vector<uint8_t>::const_iterator end)
				{
					DNSSuffix = AmtAnsiString(itr, end).getString();
				}
			};

			class GetDNSSuffixRequest;
			class GetDNSSuffixCommand : public AMTHICommand
			{
			public:

				GetDNSSuffixCommand();
				virtual ~GetDNSSuffixCommand() {}

				std::string getResponse();

			private:
				virtual void parseResponse(const std::vector<uint8_t>& buffer);

				std::shared_ptr<AMTHICommandResponse<GetDNSSuffix_RESPONSE>> m_response;

				static const uint32_t RESPONSE_COMMAND_NUMBER = 0x04800036;
			};

			class GetDNSSuffixRequest : public AMTHICommandRequest
			{
			public:
				GetDNSSuffixRequest() {}
				virtual ~GetDNSSuffixRequest() {}

			private:
				static const uint32_t REQUEST_COMMAND_NUMBER = 0x04000036;
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

#endif //__GET_DNS_SUFFIX_COMMAND_H__