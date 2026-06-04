/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2026 Intel Corporation
 */
/*++

@file: GetRTCValueCommand.h

--*/

// MKHI command wrapper for reading firmware-reported RTC timestamp value.

#ifndef __GET_RTC_VALUE_COMMAND_H__
#define __GET_RTC_VALUE_COMMAND_H__

#include "MEIparser.h"
#include "MKHICommand.h"

namespace Intel
{
	namespace MEI_Client
	{
		namespace MKHI_Client
		{
			struct RTC_VALUE_RESPONSE
			{
				RTC_VALUE_RESPONSE() : RTCValue(0) {}
				uint32_t RTCValue;		// Real-time clock value (timestamp)

				void parse(std::vector<uint8_t>::const_iterator& itr, const std::vector<uint8_t>::const_iterator &end)
				{
					parseData(RTCValue, itr, end);
				}
			};

			class GetRTCValueRequest : public MKHICommandRequest
			{
			public:
				// Initialize MKHI group and command identifiers for RTC value query.
				GetRTCValueRequest() : MKHICommandRequest(REQUEST_COMMAND_NUMBER, MKHI_GEN_GROUP_ID) {}
				virtual ~GetRTCValueRequest() {}

			private:
				static const uint8_t REQUEST_COMMAND_NUMBER = 0x1b;
			};

			class GetRTCValueCommand : public MKHICommand
			{
			public:
				// Build request and run transaction on construction.
				GetRTCValueCommand()
				{
					m_request = std::make_shared<GetRTCValueRequest>();
					Transact();
				}
				virtual ~GetRTCValueCommand() {}

				RTC_VALUE_RESPONSE getResponse() { return m_response.getResponse(); }

			private:
				virtual void parseResponse(const std::vector<uint8_t>& buffer)
				{
					m_response = MKHICommandResponse<RTC_VALUE_RESPONSE>(buffer, RESPONSE_COMMAND_NUMBER, MKHI_GEN_GROUP_ID);
				}

				MKHICommandResponse<RTC_VALUE_RESPONSE> m_response;

				static const uint8_t RESPONSE_COMMAND_NUMBER = 0x1b;
			};
		} // namespace MKHI_Client
	} // namespace MEI_Client
} // namespace Intel

#endif //__GET_RTC_VALUE_COMMAND_H__
