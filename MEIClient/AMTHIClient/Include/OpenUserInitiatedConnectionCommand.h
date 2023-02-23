/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2010-2023 Intel Corporation
 */
/*++

@file: OpenUserInitiatedConnectionCommand.h

--*/

#ifndef __OPEN_USER_INITIATED_CONNECTION_COMMAND_H__
#define __OPEN_USER_INITIATED_CONNECTION_COMMAND_H__

#include "AMTHICommand.h"

namespace Intel
{
	namespace MEI_Client
	{
		namespace AMTHI_Client
		{
			struct OpenUserInitiatedConnection_RESPONSE
			{
				void parse (std::vector<uint8_t>::const_iterator& , const std::vector<uint8_t>::const_iterator )
				{
					return;
				}
			};

			class OpenUserInitiatedConnectionRequest : public AMTHICommandRequest
			{
			public:
				OpenUserInitiatedConnectionRequest() : AMTHICommandRequest(REQUEST_COMMAND_NUMBER) {}
				virtual ~OpenUserInitiatedConnectionRequest() {}

			private:
				static const uint32_t REQUEST_COMMAND_NUMBER = 0x04000044;
			};

			class OpenUserInitiatedConnectionCommand : public AMTHICommand
			{
			public:

				OpenUserInitiatedConnectionCommand()
				{
					m_request = std::make_shared<OpenUserInitiatedConnectionRequest>();
					Transact();
				}
				virtual ~OpenUserInitiatedConnectionCommand() {}

			private:
				virtual void parseResponse(const std::vector<uint8_t>& buffer)
				{
					m_response = AMTHICommandResponse<OpenUserInitiatedConnection_RESPONSE>(buffer, RESPONSE_COMMAND_NUMBER);
				}

				AMTHICommandResponse<OpenUserInitiatedConnection_RESPONSE> m_response;

				static const uint32_t RESPONSE_COMMAND_NUMBER = 0x04800044;

			};
		} // namespace AMTHI_Client
	} // namespace MEI_Client
} // namespace Intel

#endif //__OPEN_USER_INITIATED_CONNECTION_COMMAND_H__