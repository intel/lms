/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2010-2023 Intel Corporation
 */
/*++

@file: HTMGetFLogCommand.h

--*/

#ifndef __HTM_GET_FLOG_COMMAND_H__
#define __HTM_GET_FLOG_COMMAND_H__

#include "HOTHAMCommand.h"
#include "MEIparser.h"

namespace Intel
{
	namespace MEI_Client
	{
		namespace HOTHAM_Client
		{
			typedef struct _HTM_CMD_FLOG_RESP
			{
				uint32_t response;
			} HTM_CMD_FLOG_RESP;

			struct GET_FLOG_RESP
			{
				GET_FLOG_RESP() : response({ 0 }) {}
				HTM_CMD_FLOG_RESP response;

				void parse (std::vector<uint8_t>::const_iterator& itr, const std::vector<uint8_t>::const_iterator &end)
				{
					Intel::MEI_Client::parseData(response, itr, end);
				}
			};

			class HTMGetFatalErrorsRequest : public HOTHAMCommandRequest
			{
			public:
				HTMGetFatalErrorsRequest() {}
				virtual ~HTMGetFatalErrorsRequest() {}

			private:
				static const uint32_t REQUEST_CODE = 0x80; //#define PCH_DFX_FLOG_GET_SIZE 0x80
				virtual uint8_t requestHeaderReqCode()
				{
					return REQUEST_CODE;
				}

				virtual uint8_t requestHeaderMsgClass()
				{
					return HOTHAM_COMMAND_CODE;
				}
			};

			class HTMGetFatalErrorsCommand : public HOTHAMCommand
			{
			public:
				HTMGetFatalErrorsCommand()
				{
					m_request = std::make_shared<HTMGetFatalErrorsRequest>();
					Transact();
				}
				virtual ~HTMGetFatalErrorsCommand() {}

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