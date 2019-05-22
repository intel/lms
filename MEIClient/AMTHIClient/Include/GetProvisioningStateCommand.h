/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2010-2019 Intel Corporation
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
				AMT_PROVISIONING_STATE ProvisioningState;
				void parse (std::vector<uint8_t>::const_iterator &itr, const std::vector<uint8_t>::const_iterator end)
				{
					Intel::MEI_Client::parseData(*this, itr, end);
				}
			};

			class GetProvisioningStateRequest;
			class GetProvisioningStateCommand : public AMTHICommand
			{
			public:

				GetProvisioningStateCommand();
				virtual ~GetProvisioningStateCommand() {}
				virtual void reTransact();
				CFG_PROVISIONING_STATE getResponse();

			private:
				virtual void parseResponse(const std::vector<uint8_t>& buffer);

				std::shared_ptr<AMTHICommandResponse<CFG_PROVISIONING_STATE>> m_response;
				static const uint32_t RESPONSE_COMMAND_NUMBER = 0x04800011;
			};

			class GetProvisioningStateRequest : public AMTHICommandRequest
			{
			public:
				GetProvisioningStateRequest(){}
				virtual ~GetProvisioningStateRequest() {}

			private:
				static const uint32_t REQUEST_COMMAND_NUMBER = 0x04000011;
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

#endif //__GET_PROVISIONING_STATE_COMMAND_H__