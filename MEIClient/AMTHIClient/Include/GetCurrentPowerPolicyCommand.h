/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2010-2023 Intel Corporation
 */
/*++

@file: GetCurrentPowerPolicyCommand.h

--*/

#ifndef __GET_CURRENT_POWER_POLICY_COMMAND_H__
#define __GET_CURRENT_POWER_POLICY_COMMAND_H__

#include "AMTHICommand.h"
#include "AmtAnsiString.h"

namespace Intel
{
	namespace MEI_Client
	{
		namespace AMTHI_Client
		{
			struct GetCurrentPowerPolicy_RESPONSE
			{
				std::string powerPolicy;
				void parse (std::vector<uint8_t>::const_iterator& itr, const std::vector<uint8_t>::const_iterator end)
				{
					powerPolicy = AmtAnsiString(itr, end).getString();
				}
			};

			class GetCurrentPowerPolicyCommand : public AMTHICommand
			{
			public:

				GetCurrentPowerPolicyCommand();
				virtual ~GetCurrentPowerPolicyCommand() {}

				std::string getResponse();

			private:
				virtual void parseResponse(const std::vector<uint8_t>& buffer);

				std::shared_ptr<AMTHICommandResponse<GetCurrentPowerPolicy_RESPONSE>> m_response;

				static const uint32_t RESPONSE_COMMAND_NUMBER = 0x04800047;
			};

			class GetCurrentPowerPolicyRequest : public AMTHICommandRequest
			{
			public:
				GetCurrentPowerPolicyRequest() {}
				virtual ~GetCurrentPowerPolicyRequest() {}

			private:

				static const uint32_t REQUEST_COMMAND_NUMBER = 0x04000047;
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

#endif //__GET_CURRENT_POWER_POLICY_COMMAND_H__