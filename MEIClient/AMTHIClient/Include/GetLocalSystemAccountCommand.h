/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2010-2019 Intel Corporation
 */
/*++

@file: GetLocalSystemAccountCommand.h

--*/

#ifndef __GET_LOCAL_SYSTEM_ACCOUNT_COMMAND_H__
#define __GET_LOCAL_SYSTEM_ACCOUNT_COMMAND_H__

#include "AMTHICommand.h"
#include "MEIparser.h"
#include <cstring>
#include <vector>
#include <string>
#include <cstring>

namespace Intel
{
	namespace MEI_Client
	{
		namespace AMTHI_Client
		{
			static const size_t CFG_MAX_ACL_USER_LENGTH = 33;
			static const size_t CFG_MAX_ACL_PWD_LENGTH = 33;

			struct GET_LOCAL_SYSTEM_ACCOUNT_RESPONSE
			{
				std::string UserName;
				std::string Password;

				void parse (std::vector<uint8_t>::const_iterator& itr, const std::vector<uint8_t>::const_iterator end)
				{
					char userNameC[CFG_MAX_ACL_USER_LENGTH] = { 0 }; //NULL terminated
					Intel::MEI_Client::parseData(userNameC, itr, end);
					userNameC[CFG_MAX_ACL_USER_LENGTH - 1] = '\0';
					UserName = userNameC;

					char passwordC[CFG_MAX_ACL_PWD_LENGTH] = { 0 };
					Intel::MEI_Client::parseData(passwordC, itr, end);
					passwordC[CFG_MAX_ACL_PWD_LENGTH - 1] = '\0';
					Password = passwordC;
				}
			};

			class GetLocalSystemAccountRequest;
			class GetLocalSystemAccountCommand : public AMTHICommand
			{
			public:

				GetLocalSystemAccountCommand();
				virtual ~GetLocalSystemAccountCommand() {}

				GET_LOCAL_SYSTEM_ACCOUNT_RESPONSE getResponse();

			private:
				virtual void parseResponse(const std::vector<uint8_t>& buffer);

				std::shared_ptr<AMTHICommandResponse<GET_LOCAL_SYSTEM_ACCOUNT_RESPONSE>> m_response;

				static const uint32_t RESPONSE_COMMAND_NUMBER = 0x04800067;
			};

			class GetLocalSystemAccountRequest : public AMTHICommandRequest
			{
			public:
				GetLocalSystemAccountRequest() {}
				virtual ~GetLocalSystemAccountRequest() {}

			private:
				static const uint32_t REQUEST_COMMAND_NUMBER = 0x04000067;
				virtual unsigned int requestHeaderCommandNumber()
				{
					//this is the command number (taken from the AMTHI document)
					return REQUEST_COMMAND_NUMBER;
				}

				virtual uint32_t requestDataSize()
				{
					return sizeof(uint8_t)*40; //"Reserved"
				}
				virtual std::vector<uint8_t> SerializeData();
			};
		} // namespace AMTHI_Client
	} // namespace MEI_Client
} // namespace Intel

#endif //__GET_LOCAL_SYSTEM_ACCOUNT_COMMAND_H__