/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2010-2023 Intel Corporation
 */
/*++

@file: GetSystemDefenseStateCommand.h

--*/

#ifndef __GET_SYSTEM_DEFENSE_STATE_COMMAND_H__
#define __GET_SYSTEM_DEFENSE_STATE_COMMAND_H__

#include "AMTHICommand.h"
#include "MEIparser.h"

namespace Intel
{
	namespace MEI_Client
	{
		namespace AMTHI_Client
		{
			typedef struct GET_SYSTEM_DEFENSE_STATE_RESPONSE_t
			{
				uint32_t RequestId;
				AMT_BOOLEAN SystemDefenseActivated;

				void parse (std::vector<uint8_t>::const_iterator &itr, const std::vector<uint8_t>::const_iterator &end)
				{
					parseData(RequestId, itr, end);
					parseData(SystemDefenseActivated, itr, end); 
				}
			} GET_SYSTEM_DEFENSE_STATE_RESPONSE;

			class GetSystemDefenseStateCommand : public AMTHICommand
			{
			public:

				GetSystemDefenseStateCommand();
				virtual ~GetSystemDefenseStateCommand() {}

				GET_SYSTEM_DEFENSE_STATE_RESPONSE getResponse();

			private:
				virtual void parseResponse(const std::vector<uint8_t>& buffer);

				std::shared_ptr<AMTHICommandResponse<GET_SYSTEM_DEFENSE_STATE_RESPONSE>> m_response;

				static const uint32_t RESPONSE_COMMAND_NUMBER = 0x04800049;
			};

			class GetSystemDefenseStateRequest : public AMTHICommandRequest
			{
			public:
				GetSystemDefenseStateRequest() {}
				virtual ~GetSystemDefenseStateRequest() {}

			private:
				static const uint32_t SYSTEM_DEFENSE_ID = 1;
				static const uint32_t REQUEST_COMMAND_NUMBER = 0x04000049;
				virtual unsigned int requestHeaderCommandNumber()
				{
					//this is the command number (taken from the AMTHI document)
					return REQUEST_COMMAND_NUMBER;
				}

				virtual uint32_t requestDataSize()
				{
					return sizeof(uint32_t);
				}
				virtual std::vector<uint8_t> SerializeData();
			};
		} // namespace AMTHI_Client
	} // namespace MEI_Client
} // namespace Intel

#endif //__GET_SYSTEM_DEFENSE_STATE_COMMAND_H__