/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2024 Intel Corporation
 */
 /*++

 @file: GetBootStateCommand.h

 --*/

#ifndef __GET_BOOT_STATE_COMMAND_H__
#define __GET_BOOT_STATE_COMMAND_H__

#include "MEIparser.h"
#include "MKHICommand.h"

namespace Intel
{
	namespace MEI_Client
	{
		namespace MKHI_Client
		{
			struct GET_BOOT_STATE_RESPONSE
			{
				GET_BOOT_STATE_RESPONSE() : BootState(0), Reserved(0){}
				union
				{
					uint32_t BootState;
					struct
					{
						uint32_t EOPState:1;
						uint32_t CBDState:1;
						uint32_t Reserved:30;
					} Fields;
				};
				uint32_t Reserved;

				void parse(std::vector<uint8_t>::const_iterator& itr, const std::vector<uint8_t>::const_iterator& end)
				{
					Intel::MEI_Client::parseData(BootState, itr, end);
					Intel::MEI_Client::parseData(Reserved, itr, end);
				}
			};

			class GetBootStateRequest : public MKHICommandRequest
			{
			public:
				GetBootStateRequest() : MKHICommandRequest(REQUEST_COMMAND_NUMBER, MKHI_GEN_GROUP_ID) {}
				virtual ~GetBootStateRequest() {}

			private:
				static const uint32_t REQUEST_COMMAND_NUMBER = 0xA;
			};

			class GetBootStateCommand : public MKHICommand
			{
			public:

				GetBootStateCommand()
				{
					m_request = std::make_shared<GetBootStateRequest>();
					Transact();
				}
				virtual ~GetBootStateCommand() {}

				GET_BOOT_STATE_RESPONSE getResponse() { return m_response.getResponse(); }

			private:
				virtual void parseResponse(const std::vector<uint8_t>& buffer)
				{
					m_response = MKHICommandResponse<GET_BOOT_STATE_RESPONSE>(buffer, RESPONSE_COMMAND_NUMBER, MKHI_GEN_GROUP_ID);
				}

				MKHICommandResponse<GET_BOOT_STATE_RESPONSE> m_response;

				static const uint32_t RESPONSE_COMMAND_NUMBER = 0xA;
			};

		} // namespace MKHI_Client
	} // namespace MEI_Client
} // namespace Intel

#endif //__GET_BOOT_STATE_COMMAND_H__
