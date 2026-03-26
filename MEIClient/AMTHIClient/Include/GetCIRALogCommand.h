/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2026 Intel Corporation
 */
/*++

@file: GetCIRALogCommand.h

--*/

// AMTHI command wrapper for requesting and returning the CIRA diagnostic log stream.

#ifndef __GET_CIRA_LOG_COMMAND_H__
#define __GET_CIRA_LOG_COMMAND_H__

#include "AMTHICommand.h"
#include "MEIparser.h"
#include <string>
#include <vector>

namespace Intel
{
	namespace MEI_Client
	{
		namespace AMTHI_Client
		{
			struct GET_CIRA_LOG_RESPONSE
			{
				std::string response;

				void parse(std::vector<uint8_t>::const_iterator& itr, const std::vector<uint8_t>::const_iterator &end)
				{
					response = Intel::MEI_Client::parseHexString(itr, end);
				}
			};

			class GetCIRALogRequest : public AMTHICommandRequest
			{
			public:
				// Use protocol command code for AMTHI get-CIRA-log operation.
				GetCIRALogRequest() : AMTHICommandRequest(REQUEST_COMMAND_NUMBER) {}
				virtual ~GetCIRALogRequest() {}

			private:
				static const uint32_t REQUEST_COMMAND_NUMBER = 0x0400008E;

				virtual uint32_t requestDataSize()
				{
					return sizeof(uint8_t);
				}
				virtual std::vector<uint8_t> SerializeData()
				{
					// Create a payload with exactly 1 byte, initialized to value 0x00 (vector size=1, element value=0).
					std::vector<uint8_t> output(1, 0);
					return output;
				}
			};

			class GetCIRALogCommand : public AMTHICommand
			{
			public:

				// Build request and execute transaction immediately.
				GetCIRALogCommand()
				{
					m_request = std::make_shared<GetCIRALogRequest>();
					Transact();
				}
				virtual ~GetCIRALogCommand() {}

				GET_CIRA_LOG_RESPONSE getResponse() { return m_response.getResponse(); }

			private:
				virtual void parseResponse(const std::vector<uint8_t>& buffer)
				{
					m_response = AMTHICommandResponse<GET_CIRA_LOG_RESPONSE>(buffer, RESPONSE_COMMAND_NUMBER);
				}

				AMTHICommandResponse<GET_CIRA_LOG_RESPONSE> m_response;

				static const uint32_t RESPONSE_COMMAND_NUMBER = 0x0480008E;
			};
		} // namespace AMTHI_Client
	} // namespace MEI_Client
} // namespace Intel

#endif //__GET_CIRA_LOG_COMMAND_H__
