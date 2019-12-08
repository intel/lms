/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2010-2019 Intel Corporation
 */
/*++

@file: SetHostFQDNCommand.h

--*/

#ifndef __SET_HOST_FQDN_COMMAND_H__
#define __SET_HOST_FQDN_COMMAND_H__

#include "AMTHICommand.h"
#include "MEIparser.h"
#include "AmtAnsiString.h"

namespace Intel
{
	namespace MEI_Client
	{
		namespace AMTHI_Client
		{
			struct SET_HOST_FQDN_RESPONSE 
			{
				void parse(std::vector<uint8_t>::const_iterator& /*itr*/, const std::vector<uint8_t>::const_iterator& /*end*/)
				{
					return ;
				}
			};

			class SetHostFQDNRequest;
			class SetHostFQDNCommand : public AMTHICommand
			{
			public:
				SetHostFQDNCommand(const std::string &FQDN);
				virtual ~SetHostFQDNCommand() {}
				virtual void reTransact(const std::string &FQDN);
				SET_HOST_FQDN_RESPONSE getResponse();

			private:
				virtual void parseResponse(const std::vector<uint8_t>& buffer);

				std::shared_ptr<AMTHICommandResponse<SET_HOST_FQDN_RESPONSE>> m_response;

				static const uint32_t RESPONSE_COMMAND_NUMBER = 0x0480005B;
			};

			class SetHostFQDNRequest : public AMTHICommandRequest
			{
			public:
				SetHostFQDNRequest(const std::string &FQDN) : _FQDN (FQDN){}
				virtual ~SetHostFQDNRequest() {}

			private:
				static const uint32_t REQUEST_COMMAND_NUMBER = 0x0400005B;
				virtual unsigned int requestHeaderCommandNumber()
				{
					//this is the command number (taken from the AMTHI document)
					return REQUEST_COMMAND_NUMBER;
				}

				virtual uint32_t requestDataSize()
				{
					return _FQDN.bufSize();
				}
				virtual std::vector<uint8_t> SerializeData();

				AmtAnsiString _FQDN;
			};
		} // namespace AMTHI_Client
	} // namespace MEI_Client
} // namespace Intel

#endif //__SET_HOST_FQDN_COMMAND_H__