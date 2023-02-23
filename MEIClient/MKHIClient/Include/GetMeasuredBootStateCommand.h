/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2020-2023 Intel Corporation
 */
/*++

@file: GetMeasuredBootStateCommand.h

--*/

#ifndef __GET_MEASURED_BOOT_STATE_COMMAND_H__
#define __GET_MEASURED_BOOT_STATE_COMMAND_H__

#include "MEIparser.h"
#include "MKHICommand.h"


namespace Intel
{
	namespace MEI_Client
	{
		namespace MKHI_Client
		{
			struct MKHI_MEASURED_BOOT_STATE
			{
				MKHI_MEASURED_BOOT_STATE() : State(0) {}
				uint8_t				State;

				void parse(std::vector<uint8_t>::const_iterator& itr, const std::vector<uint8_t>::const_iterator &end)
				{
					parseData (State, itr, end);
				}
			};

			class GetMeasuredBootStateRequest : public MKHICommandRequest
			{
			public:
				GetMeasuredBootStateRequest() : MKHICommandRequest(REQUEST_COMMAND_NUMBER, MKHI_GEN_GROUP_ID) {}
				virtual ~GetMeasuredBootStateRequest() {}

			private:
				static const uint32_t REQUEST_COMMAND_NUMBER = 0x23;
			};

			class GetMeasuredBootStateCommand : public MKHICommand
			{
			public:

				GetMeasuredBootStateCommand()
				{
					m_request = std::make_shared<GetMeasuredBootStateRequest>();
					Transact();
				}
				virtual ~GetMeasuredBootStateCommand() {}

				MKHI_MEASURED_BOOT_STATE getResponse() { return m_response.getResponse(); }

			private:
				virtual void parseResponse(const std::vector<uint8_t>& buffer)
				{
					m_response = MKHICommandResponse<MKHI_MEASURED_BOOT_STATE>(buffer, RESPONSE_COMMAND_NUMBER, MKHI_GEN_GROUP_ID);
				}

				MKHICommandResponse<MKHI_MEASURED_BOOT_STATE> m_response;

				static const uint32_t RESPONSE_COMMAND_NUMBER = 0x23;
			};
		} // namespace MKHI_Client
	} // namespace MEI_Client
} // namespace Intel

#endif //__GET_MEASURED_BOOT_STATE_COMMAND_H__
