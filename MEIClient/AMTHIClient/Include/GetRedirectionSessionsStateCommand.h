/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2010-2023 Intel Corporation
 */
/*++

@file: GetRedirectionSessionsStateCommand.h

--*/

#ifndef __GET_REDIRECTION_SESSIONS_STATE_COMMAND_H__
#define __GET_REDIRECTION_SESSIONS_STATE_COMMAND_H__

#include "AMTHICommand.h"
#include "MEIparser.h"

namespace Intel
{
	namespace MEI_Client
	{
		namespace AMTHI_Client
		{
			struct GET_REDIRECTION_SESSIONS_STATE_RESPONSE
			{
				GET_REDIRECTION_SESSIONS_STATE_RESPONSE() : RequestId(0), IderOpen(AMT_FALSE), SolOpen(AMT_FALSE), Reserved(AMT_FALSE) {}
				uint32_t RequestId;
				AMT_BOOLEAN IderOpen;
				AMT_BOOLEAN SolOpen;
				AMT_BOOLEAN Reserved;

				void parse (std::vector<uint8_t>::const_iterator &itr, const std::vector<uint8_t>::const_iterator &end)
				{
					Intel::MEI_Client::parseData(RequestId, itr, end);
					Intel::MEI_Client::parseData(IderOpen, itr, end);
					Intel::MEI_Client::parseData(SolOpen, itr, end); 
					Intel::MEI_Client::parseData(Reserved, itr, end);
				}
			};

			class GetRedirectionSessionsStateCommand : public AMTHICommand
			{
			public:

				GetRedirectionSessionsStateCommand();
				virtual ~GetRedirectionSessionsStateCommand() {}

				GET_REDIRECTION_SESSIONS_STATE_RESPONSE getResponse();

			private:
				virtual void parseResponse(const std::vector<uint8_t>& buffer);

				AMTHICommandResponse<GET_REDIRECTION_SESSIONS_STATE_RESPONSE> m_response;

				static const uint32_t RESPONSE_COMMAND_NUMBER = 0x04800049;
			};

			class GetRedirectionSessionsStateRequest : public AMTHICommandRequest
			{
			public:
				GetRedirectionSessionsStateRequest() : AMTHICommandRequest(REQUEST_COMMAND_NUMBER) {}
				virtual ~GetRedirectionSessionsStateRequest() {}

			private:
				static const uint32_t REDIRECTION_ID = 0;
				static const uint32_t REQUEST_COMMAND_NUMBER = 0x04000049;

				virtual uint32_t requestDataSize()
				{
					return sizeof(uint32_t);
				}
				virtual std::vector<uint8_t> SerializeData();
			};
		} // namespace AMTHI_Client
	} // namespace MEI_Client
} // namespace Intel

#endif //__GET_REDIRECTION_SESSIONS_STATE_COMMAND_H__