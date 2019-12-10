/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2010-2019 Intel Corporation
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

			class OpenUserInitiatedConnectionRequest;
			class OpenUserInitiatedConnectionCommand : public AMTHICommand
			{
			public:

				OpenUserInitiatedConnectionCommand();
				virtual ~OpenUserInitiatedConnectionCommand() {}

			private:
				virtual void parseResponse(const std::vector<uint8_t>& buffer);

				std::shared_ptr<AMTHICommandResponse<OpenUserInitiatedConnection_RESPONSE>> m_response;

				static const uint32_t RESPONSE_COMMAND_NUMBER = 0x04800044;

			};

			class OpenUserInitiatedConnectionRequest : public AMTHICommandRequest
			{
			public:
				OpenUserInitiatedConnectionRequest() {}
				virtual ~OpenUserInitiatedConnectionRequest() {}

			private:
				
				static const uint32_t REQUEST_COMMAND_NUMBER = 0x04000044;
				virtual unsigned int requestHeaderCommandNumber()
				{
					//this is the command number (taken from the AMTHI document)
					return REQUEST_COMMAND_NUMBER;
				}

				virtual uint32_t requestDataSize()
				{
					return 0;
				}
				virtual std::vector<uint8_t> SerializeData();
			};
		} // namespace AMTHI_Client
	} // namespace MEI_Client
} // namespace Intel

#endif //__OPEN_USER_INITIATED_CONNECTION_COMMAND_H__