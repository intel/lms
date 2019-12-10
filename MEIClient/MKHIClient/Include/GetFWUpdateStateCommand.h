/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2010-2019 Intel Corporation
 */
/*++

@file: GetFWUpdateStateCommand.h

--*/

#ifndef __GET_FW_UPDATE_STATE_COMMAND_H__
#define __GET_FW_UPDATE_STATE_COMMAND_H__

#include "MEIparser.h"
#include "MKHICommand.h"

namespace Intel
{
	namespace MEI_Client
	{
		namespace MKHI_Client
		{
			typedef enum
			{
				FW_UPDATE_DISABLED = 0,
				FW_UPDATE_ENABLED = 1,
				FW_UPDATE_PASSWORD_PROTECTED = 2,
			} ME_FW_UPDATE_STATE;

			union FW_UPDATE_STATE
			{
				uint32_t    Data;

				void parse (std::vector<uint8_t>::const_iterator &itr, const std::vector<uint8_t>::const_iterator end)
				{
					Intel::MEI_Client::parseData(*this, itr, end);
				}
			};

			class GetFWUpdateStateRequest;
			class GetFWUpdateStateCommand : public MKHICommand
			{
			public:

				GetFWUpdateStateCommand();
				virtual ~GetFWUpdateStateCommand() {}

				FW_UPDATE_STATE getResponse();

			private:
				virtual void parseResponse(const std::vector<uint8_t>& buffer);

				std::shared_ptr<MKHIGetRuleCommandResponse<FW_UPDATE_STATE>> m_response;

				static const uint32_t RESPONSE_COMMAND_NUMBER = 0x02;

			};

			class GetFWUpdateStateRequest : public MKHICommandRequest
			{
			public:
				GetFWUpdateStateRequest() {}
				virtual ~GetFWUpdateStateRequest() {}

			private:
				static const uint32_t REQUEST_COMMAND_NUMBER = 0x02;
				virtual unsigned int requestHeaderCommandNumber()
				{
					//this is the command number (taken from the MKHI document)
					return REQUEST_COMMAND_NUMBER;
				}

				virtual uint32_t requestDataSize()
				{
					return sizeof(RULE_ID);
				}
				virtual unsigned int requestHeaderGroupID()
				{
					//this is the command group (taken from the MKHI document)
					return MKHI_FWCAPS_GROUP_ID;
				}

				virtual std::vector<uint8_t> SerializeData();
			};
		} // namespace MKHI_Client
	} // namespace MEI_Client
} // namespace Intel

#endif //__GET_FW_UPDATE_STATE_COMMAND_H__
