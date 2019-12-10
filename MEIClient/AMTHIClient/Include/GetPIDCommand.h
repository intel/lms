/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2010-2019 Intel Corporation
 */
/*++

@file: GetPIDCommand.h

--*/

#ifndef __GET_PID_COMMAND_H__
#define __GET_PID_COMMAND_H__

#include "AMTHICommand.h"
#include "MEIparser.h"

namespace Intel
{
	namespace MEI_Client
	{
		namespace AMTHI_Client
		{
			struct GET_PID_RESPONSE 
			{
				uint8_t pid[8];

				void parse (std::vector<uint8_t>::const_iterator &itr, const std::vector<uint8_t>::const_iterator &end) 
				{
					Intel::MEI_Client::parseData(*this, itr, end);
				}
			};

			class GetPIDRequest;
			class GetPIDCommand : public AMTHICommand
			{
			public:

				GetPIDCommand();
				virtual ~GetPIDCommand() {}

				GET_PID_RESPONSE getResponse();

			private:
				virtual void parseResponse(const std::vector<uint8_t>& buffer);

				std::shared_ptr<AMTHICommandResponse<GET_PID_RESPONSE>> m_response;

				static const uint32_t RESPONSE_COMMAND_NUMBER = 0x0480003B;
			};

			class GetPIDRequest : public AMTHICommandRequest
			{
			public:
				GetPIDRequest() {}
				virtual ~GetPIDRequest() {}

			private:
				
				static const uint32_t REQUEST_COMMAND_NUMBER = 0x0400003B;
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

#endif //__GET_PID_COMMAND_H__