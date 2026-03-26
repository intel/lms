/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2010-2026 Intel Corporation
 */
/*++

@file: HTMGetFLogSizeCommand.h

--*/

// HOTHAM command wrapper for retrieving firmware flog size

#ifndef __HTM_GET_FLOG_SIZE_COMMAND_H__
#define __HTM_GET_FLOG_SIZE_COMMAND_H__

#include "HOTHAMCommand.h"
#include "MEIparser.h"

namespace Intel
{
	namespace MEI_Client
	{
		namespace HOTHAM_Client
		{
			struct GET_FLOG_SIZE_RESP
			{
				uint32_t response = 0;

				void parse(std::vector<uint8_t>::const_iterator& itr, const std::vector<uint8_t>::const_iterator &end)
				{
					// Parse raw payload directly into the fixed-size response structure.
					parseData(response, itr, end);
				}
			};

			class HTMGetFLogSizeRequest : public HOTHAMCommandRequest
			{
			public:
				HTMGetFLogSizeRequest() {}
				virtual ~HTMGetFLogSizeRequest() {}

			private:
				static const uint32_t REQUEST_CODE = 0x80;
				virtual uint8_t requestHeaderReqCode()
				{
					return REQUEST_CODE;
				}

				virtual uint8_t requestHeaderMsgClass()
				{
					return HOTHAM_COMMAND_CODE;
				}
			};

			class HTMGetFLogSizeCommand : public HOTHAMCommand
			{
			public:
				// Build request and execute command transaction.
				HTMGetFLogSizeCommand()
				{
					m_request = std::make_shared<HTMGetFLogSizeRequest>();
					Transact();
				}
				virtual ~HTMGetFLogSizeCommand() {}

				GET_FLOG_SIZE_RESP getResponse() { return m_response.getResponse(); }

			private:
				virtual void parseResponse(const std::vector<uint8_t>& buffer)
				{
					m_response = HOTHAMCommandResponse<GET_FLOG_SIZE_RESP>(buffer);
				}

				HOTHAMCommandResponse<GET_FLOG_SIZE_RESP> m_response;
			};
		} // namespace HOTHAM_Client
	} // namespace MEI_Client
} // namespace Intel

#endif //__HTM_GET_FLOG_SIZE_COMMAND_H__
