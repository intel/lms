/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2010-2023 Intel Corporation
 */
/*++

@file: GetUUIDCommand.h

--*/

#ifndef __GET_UUID_COMMAND_H__
#define __GET_UUID_COMMAND_H__

#include "AMTHICommand.h"
#include "MEIparser.h"

namespace Intel
{
	namespace MEI_Client
	{
		namespace AMTHI_Client
		{
			struct GET_UUID_RESPONSE
			{
				GET_UUID_RESPONSE() : UUID { 0 } {}
				uint8_t UUID[16];

				void parse (std::vector<uint8_t>::const_iterator &itr, const std::vector<uint8_t>::const_iterator &end)
				{
					parseData(*this, itr, end);
				}
			} ;

			class GetUUIDRequest : public AMTHICommandRequest
			{
			public:
				GetUUIDRequest() : AMTHICommandRequest(REQUEST_COMMAND_NUMBER) {}
				virtual ~GetUUIDRequest() {}

			private:
				static const uint32_t REQUEST_COMMAND_NUMBER = 0x0400005C;
			};

			class GetUUIDCommand : public AMTHICommand
			{
			public:
				GetUUIDCommand()
				{
					m_request = std::make_shared<GetUUIDRequest>();
					Transact();
				}
				virtual ~GetUUIDCommand() {}

				GET_UUID_RESPONSE getResponse() { return m_response.getResponse(); }

			private:
				virtual void parseResponse(const std::vector<uint8_t>& buffer)
				{
					m_response = AMTHICommandResponse<GET_UUID_RESPONSE>(buffer, RESPONSE_COMMAND_NUMBER);
				}

				AMTHICommandResponse<GET_UUID_RESPONSE> m_response;

				static const uint32_t RESPONSE_COMMAND_NUMBER = 0x0480005C;
			};
		} // namespace AMTHI_Client
	} // namespace MEI_Client
} // namespace Intel

#endif //__GET_UUID_COMMAND_H__