/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2010-2023 Intel Corporation
 */
/*++

@file: SetDNSSuffixCommand.h

--*/

#ifndef __SET_DNS_SUFFIX_COMMAND_H__
#define __SET_DNS_SUFFIX_COMMAND_H__

#include "AMTHICommand.h"
#include "AmtAnsiString.h"

namespace Intel
{
	namespace MEI_Client
	{
		namespace AMTHI_Client
		{
			struct SetDNSSuffix_RESPONSE
			{
				void parse (std::vector<uint8_t>::const_iterator& , const std::vector<uint8_t>::const_iterator )
				{
					return;
				}
			};

			class SetDNSSuffixRequest : public AMTHICommandRequest
			{
			public:
				SetDNSSuffixRequest(const std::string& suffix) :
					AMTHICommandRequest(REQUEST_COMMAND_NUMBER), m_str(suffix, false) {} //should check if the null terminated is needed or not
				virtual ~SetDNSSuffixRequest() {}

			private:
				static const uint32_t REQUEST_COMMAND_NUMBER = 0x0400002F;

				virtual uint32_t requestDataSize()
				{
					return m_str.bufSize();
				}
				virtual std::vector<uint8_t> SerializeData()
				{
					std::vector<uint8_t> output = m_str.serialize();
					return output;
				}

				AmtAnsiString m_str;
			};

			class SetDNSSuffixCommand : public AMTHICommand
			{
			public:

				SetDNSSuffixCommand(const std::string &suffix)
				{
					m_request = std::make_shared<SetDNSSuffixRequest>(suffix);
					Transact();
				}
				virtual ~SetDNSSuffixCommand() {}

			private:
				virtual void parseResponse(const std::vector<uint8_t>& buffer)
				{
					m_response = AMTHICommandResponse<SetDNSSuffix_RESPONSE>(buffer, RESPONSE_COMMAND_NUMBER);
				}
				AMTHICommandResponse<SetDNSSuffix_RESPONSE> m_response;

				static const uint32_t RESPONSE_COMMAND_NUMBER = 0x0480002F;
			};
		} // namespace AMTHI_Client
	} // namespace MEI_Client
} // namespace Intel

#endif //__SET_DNS_SUFFIX_COMMAND_H__