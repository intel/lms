/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2010-2026 Intel Corporation
 */
/*++

@file: HTMGetFLogCommand.h

--*/

// HOTHAM command wrapper for retrieving firmware flog data

#ifndef __HTM_GET_FLOG_COMMAND_H__
#define __HTM_GET_FLOG_COMMAND_H__

#include "HOTHAMCommand.h"
#include "MEIparser.h"
#include <string>
#include <vector>

namespace Intel
{
	namespace MEI_Client
	{
		namespace HOTHAM_Client
		{
			struct GET_FLOG_RESP
			{
				std::string response;

				void parse (std::vector<uint8_t>::const_iterator& itr, const std::vector<uint8_t>::const_iterator &end)
				{
					response = parseHexString(itr, end);
				}
			};

			class HTMGetFLogRequest : public HOTHAMCommandRequest
			{
			public:
				HTMGetFLogRequest() {}
				virtual ~HTMGetFLogRequest() {}

			private:
				static const uint32_t REQUEST_CODE = 0x81;
				virtual uint8_t requestHeaderReqCode()
				{
					return REQUEST_CODE;
				}

				virtual uint8_t requestHeaderMsgClass()
				{
					return HOTHAM_COMMAND_CODE;
				}
			};

			class HTMGetFLogCommand : public HOTHAMCommand
			{
			public:
				HTMGetFLogCommand()
				{
					m_request = std::make_shared<HTMGetFLogRequest>();
					Transact();
				}
				virtual ~HTMGetFLogCommand() {}

				GET_FLOG_RESP getResponse() { return m_response.getResponse(); }

			private:
				virtual void parseResponse(const std::vector<uint8_t>& buffer)
				{
					m_response = HOTHAMCommandResponse<GET_FLOG_RESP>(buffer);
				}

				HOTHAMCommandResponse<GET_FLOG_RESP> m_response;
			};
		} // namespace HOTHAM_Client
	} // namespace MEI_Client
} // namespace Intel

#endif //__HTM_GET_FLOG_COMMAND_H__
