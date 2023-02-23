/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2010-2023 Intel Corporation
 */
/*++

@file: GetProvisioningStateCommand.h

--*/

#ifndef __GET_PROVISIONING_STATE_COMMAND_H__
#define __GET_PROVISIONING_STATE_COMMAND_H__

#include "AMTHICommand.h"
#include "MEIparser.h"

namespace Intel
{
	namespace MEI_Client
	{
		namespace AMTHI_Client
		{
			struct CFG_PROVISIONING_STATE
			{
				CFG_PROVISIONING_STATE() : ProvisioningState(PROVISIONING_STATE_PRE) {}
				AMT_PROVISIONING_STATE ProvisioningState;
				void parse (std::vector<uint8_t>::const_iterator &itr, const std::vector<uint8_t>::const_iterator end)
				{
					Intel::MEI_Client::parseData(*this, itr, end);
				}
			};

			class GetProvisioningStateRequest : public AMTHICommandRequest
			{
			public:
				GetProvisioningStateRequest() : AMTHICommandRequest(REQUEST_COMMAND_NUMBER) {}
				virtual ~GetProvisioningStateRequest() {}

			private:
				static const uint32_t REQUEST_COMMAND_NUMBER = 0x04000011;
			};

			class GetProvisioningStateCommand : public AMTHICommand
			{
			public:

				GetProvisioningStateCommand()
				{
					m_request = std::make_shared<GetProvisioningStateRequest>();
					Transact();
				}
				virtual ~GetProvisioningStateCommand() {}

				CFG_PROVISIONING_STATE getResponse() { return m_response.getResponse(); }

			private:
				virtual void parseResponse(const std::vector<uint8_t>& buffer)
				{
					m_response = AMTHICommandResponse<CFG_PROVISIONING_STATE>(buffer, RESPONSE_COMMAND_NUMBER);
				}

				AMTHICommandResponse<CFG_PROVISIONING_STATE> m_response;
				static const uint32_t RESPONSE_COMMAND_NUMBER = 0x04800011;
			};
		} // namespace AMTHI_Client
	} // namespace MEI_Client
} // namespace Intel

#endif //__GET_PROVISIONING_STATE_COMMAND_H__