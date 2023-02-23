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

			class GetCurrentPowerPolicyRequest : public AMTHICommandRequest
			{
			public:
				GetCurrentPowerPolicyRequest() : AMTHICommandRequest(REQUEST_COMMAND_NUMBER) {}
				virtual ~GetCurrentPowerPolicyRequest() {}

			private:
				static const uint32_t REQUEST_COMMAND_NUMBER = 0x04000047;
			};

			class GetCurrentPowerPolicyCommand : public AMTHICommand
			{
			public:

				GetCurrentPowerPolicyCommand()
				{
					m_request = std::make_shared<GetCurrentPowerPolicyRequest>();
					Transact();
				}
				virtual ~GetCurrentPowerPolicyCommand() {}

				std::string getResponse() { return m_response.getResponse().powerPolicy; }

			private:
				virtual void parseResponse(const std::vector<uint8_t>& buffer)
				{
					m_response = AMTHICommandResponse<GetCurrentPowerPolicy_RESPONSE>(buffer, RESPONSE_COMMAND_NUMBER);
				}

				AMTHICommandResponse<GetCurrentPowerPolicy_RESPONSE> m_response;

				static const uint32_t RESPONSE_COMMAND_NUMBER = 0x04800047;
			};
		} // namespace AMTHI_Client
	} // namespace MEI_Client
} // namespace Intel

#endif //__GET_CURRENT_POWER_POLICY_COMMAND_H__