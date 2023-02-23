/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2010-2023 Intel Corporation
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

			class GetDNSSuffixCommand : public AMTHICommand
			{
			public:

				GetDNSSuffixCommand();
				virtual ~GetDNSSuffixCommand() {}

				std::string getResponse();

			private:
				virtual void parseResponse(const std::vector<uint8_t>& buffer);

				AMTHICommandResponse<GetDNSSuffix_RESPONSE> m_response;

				static const uint32_t RESPONSE_COMMAND_NUMBER = 0x04800036;
			};

			class GetDNSSuffixRequest : public AMTHICommandRequest
			{
			public:
				GetDNSSuffixRequest() : AMTHICommandRequest(REQUEST_COMMAND_NUMBER) {}
				virtual ~GetDNSSuffixRequest() {}

			private:
				static const uint32_t REQUEST_COMMAND_NUMBER = 0x04000036;
			};
		} // namespace AMTHI_Client
	} // namespace MEI_Client
} // namespace Intel

#endif //__GET_DNS_SUFFIX_COMMAND_H__