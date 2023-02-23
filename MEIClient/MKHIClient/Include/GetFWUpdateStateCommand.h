/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2010-2023 Intel Corporation
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
				FW_UPDATE_STATE() : Data(0) {}
				uint32_t    Data;

				void parse (std::vector<uint8_t>::const_iterator &itr, const std::vector<uint8_t>::const_iterator end)
				{
					Intel::MEI_Client::parseData(*this, itr, end);
				}
			};

			class GetFWUpdateStateRequest : public MKHICommandRequest
			{
			public:
				GetFWUpdateStateRequest() : MKHICommandRequest(REQUEST_COMMAND_NUMBER, MKHI_FWCAPS_GROUP_ID) {}
				virtual ~GetFWUpdateStateRequest() {}

			private:
				static const uint32_t REQUEST_COMMAND_NUMBER = 0x02;

				virtual uint32_t requestDataSize()
				{
					return sizeof(RULE_ID);
				}
				virtual std::vector<uint8_t> SerializeData()
				{
					RULE_ID rule;
					rule.Data = MEFWCAPS_ME_FW_UPDATE_RULE_ID;
					return std::vector<uint8_t>((std::uint8_t*)&rule, (std::uint8_t*)&rule + sizeof(rule));
				}
			};

			class GetFWUpdateStateCommand : public MKHICommand
			{
			public:

				GetFWUpdateStateCommand()
				{
					m_request = std::make_shared<GetFWUpdateStateRequest>();
					Transact();
				}
				virtual ~GetFWUpdateStateCommand() {}

				FW_UPDATE_STATE getResponse() { return m_response.getResponse(); }

			private:
				virtual void parseResponse(const std::vector<uint8_t>& buffer)
				{
					m_response = MKHIGetRuleCommandResponse<FW_UPDATE_STATE>(buffer, RESPONSE_COMMAND_NUMBER, MKHI_FWCAPS_GROUP_ID, MEFWCAPS_ME_FW_UPDATE_RULE_ID);
				}

				MKHIGetRuleCommandResponse<FW_UPDATE_STATE> m_response;

				static const uint32_t RESPONSE_COMMAND_NUMBER = 0x02;

			};
		} // namespace MKHI_Client
	} // namespace MEI_Client
} // namespace Intel

#endif //__GET_FW_UPDATE_STATE_COMMAND_H__
