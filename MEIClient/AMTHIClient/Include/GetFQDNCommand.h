/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2010-2023 Intel Corporation
 */
/*++

@file: GetFQDNCommand.h

--*/

#ifndef __GET_FQDN_COMMAND_H__
#define __GET_FQDN_COMMAND_H__

#include "AMTHICommand.h"
#include "MEIparser.h"
#include "AmtAnsiString.h"
#include <string>
#include <vector>

namespace Intel
{
	namespace MEI_Client
	{
		namespace AMTHI_Client
		{
			struct GET_FQDN_RESPONSE
			{
				GET_FQDN_RESPONSE() : SharedFQDN(false), DDNSUpdateEnabled(false), DDNSPeriodicUpdateInterval(0),
					DDNSTTL(0), HostNameLength(0) {}
				bool        SharedFQDN;
				bool        DDNSUpdateEnabled;
				uint32_t    DDNSPeriodicUpdateInterval;
				uint32_t    DDNSTTL;
				uint32_t    HostNameLength;
				std::string FQDN;

				void parse (std::vector<uint8_t>::const_iterator& itr, const std::vector<uint8_t>::const_iterator end)
				{
					AMT_BOOLEAN b;
					Intel::MEI_Client::parseData(b,itr,end);
					SharedFQDN = (b==AMT_TRUE); //we want "bool" not AMT_BOOLEAN
					Intel::MEI_Client::parseData(b,itr,end);
					DDNSUpdateEnabled = (b==AMT_TRUE);
					Intel::MEI_Client::parseData(DDNSPeriodicUpdateInterval, itr,end);
					Intel::MEI_Client::parseData(DDNSTTL, itr,end);
					Intel::MEI_Client::parseData(HostNameLength, itr,end);

					FQDN = AmtAnsiString(itr,end).getString();
				}
			};

			class GetFQDNCommand : public AMTHICommand
			{
			public:

				GetFQDNCommand();
				virtual ~GetFQDNCommand() {}

				GET_FQDN_RESPONSE getResponse();

			private:
				virtual void parseResponse(const std::vector<uint8_t>& buffer);

				AMTHICommandResponse<GET_FQDN_RESPONSE> m_response;

				static const uint32_t RESPONSE_COMMAND_NUMBER = 0x04800056;
			};

			class GetFQDNRequest : public AMTHICommandRequest
			{
			public:
				GetFQDNRequest() : AMTHICommandRequest(REQUEST_COMMAND_NUMBER) {}
				virtual ~GetFQDNRequest() {}

			private:
				static const uint32_t REQUEST_COMMAND_NUMBER = 0x04000056;
			};
		} // namespace AMTHI_Client
	} // namespace MEI_Client
} // namespace Intel

#endif //__GET_FQDN_COMMAND_H__