/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2010-2019 Intel Corporation
 */
/*++

@file: GetProvisioningMode.h

--*/

#ifndef __GET_PROVISIONING_MODE_H__
#define __GET_PROVISIONING_MODE_H__

#include "AMTHICommand.h"
#include "MEIparser.h"

namespace Intel
{
	namespace MEI_Client
	{
		namespace AMTHI_Client
		{
			struct PROVISIONING_MODE_SETTINGS
			{
				uint32_t ProvisioningMode; //CFG_PROVISIONING_MODE 
				bool LegacyMode;

				void parse (std::vector<uint8_t>::const_iterator& itr, const std::vector<uint8_t>::const_iterator end)
				{
					Intel::MEI_Client::parseData(ProvisioningMode, itr, end);
					Intel::MEI_Client::parseData(LegacyMode, itr, end);
				}
			};

			class GetProvisioningModeRequest;
			class GetProvisioningModeCommand : public AMTHICommand
			{
			public:

				GetProvisioningModeCommand();
				virtual ~GetProvisioningModeCommand() {}

				PROVISIONING_MODE_SETTINGS getResponse();

			private:
				virtual void parseResponse(const std::vector<uint8_t>& buffer);

				std::shared_ptr<AMTHICommandResponse<PROVISIONING_MODE_SETTINGS>> m_response;

				static const uint32_t RESPONSE_COMMAND_NUMBER = 0x04800008;
			};

			class GetProvisioningModeRequest : public AMTHICommandRequest
			{
			public:
				GetProvisioningModeRequest() {}
				virtual ~GetProvisioningModeRequest() {}

			private:
				static const uint32_t REQUEST_COMMAND_NUMBER = 0x04000008;
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

#endif //__GET_PROVISIONING_MODE_H__