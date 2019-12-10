/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2010-2019 Intel Corporation
 */
/*++

@file: CloseUserInitiatedConnectionCommand.h

--*/

#ifndef __CLOSE_USER_INITIATED_CONNECTION_COMMAND_H__
#define __CLOSE_USER_INITIATED_CONNECTION_COMMAND_H__

#include "AMTHICommand.h"

namespace Intel
{
	namespace MEI_Client
	{
		namespace AMTHI_Client
		{
			struct CloseUserInitiatedConnection_RESPONSE
			{
				void parse (std::vector<uint8_t>::const_iterator& , const std::vector<uint8_t>::const_iterator)
				{
					return;
				}
			};

			class CloseUserInitiatedConnectionRequest;
			class CloseUserInitiatedConnectionCommand : public AMTHICommand
			{
			public:

				CloseUserInitiatedConnectionCommand();
				virtual ~CloseUserInitiatedConnectionCommand() {}

			private:
				virtual void parseResponse(const std::vector<uint8_t>& buffer);

				std::shared_ptr<AMTHICommandResponse<CloseUserInitiatedConnection_RESPONSE>> m_response;

				static const uint32_t RESPONSE_COMMAND_NUMBER = 0x04800045;
			};

			class CloseUserInitiatedConnectionRequest : public AMTHICommandRequest
			{
			public:
				CloseUserInitiatedConnectionRequest() {}
				virtual ~CloseUserInitiatedConnectionRequest() {}

			private:
				
				static const uint32_t REQUEST_COMMAND_NUMBER = 0x04000045;
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

#endif //__CLOSE_USER_INITIATED_CONNECTION_COMMAND_H__