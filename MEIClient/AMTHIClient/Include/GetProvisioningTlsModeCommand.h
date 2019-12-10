/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2010-2019 Intel Corporation
 */
/*++

@file: GetProvisioningTlsModeCommand.h

--*/

#ifndef __GET_PROVISIONING_TLS_MODE_H__
#define __GET_PROVISIONING_TLS_MODE_H__


#include "AMTHICommand.h"
#include "MEIparser.h"

namespace Intel
{
	namespace MEI_Client
	{
		namespace AMTHI_Client
		{
			enum ProvTLSMode_t
			{
				PROV_UNKNOWN = 0,
				PSK = 1,
				PKI = 2
			};

			struct PROV_TLS_MODE_RESPONSE
			{
				ProvTLSMode_t ProvTLSMode;
				void parse (std::vector<uint8_t>::const_iterator& itr, const std::vector<uint8_t>::const_iterator end)
				{
					
					Intel::MEI_Client::parseData (*this,itr,end);
				}
			} ;

			class GetProvisioningTLSModeRequest;
			class GetProvisioningTLSModeCommand : public AMTHICommand
			{
			public:

				GetProvisioningTLSModeCommand();
				virtual ~GetProvisioningTLSModeCommand() {}

				PROV_TLS_MODE_RESPONSE getResponse();

			private:
				virtual void parseResponse(const std::vector<uint8_t>& buffer);

				std::shared_ptr<AMTHICommandResponse<PROV_TLS_MODE_RESPONSE>> m_response;
				static const uint32_t RESPONSE_COMMAND_NUMBER = 0x0480002B;
			};

			class GetProvisioningTLSModeRequest : public AMTHICommandRequest
			{
			public:
				GetProvisioningTLSModeRequest(){}
				virtual ~GetProvisioningTLSModeRequest() {}

			private:
				static const uint32_t REQUEST_COMMAND_NUMBER = 0x0400002B;
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

#endif //__GET_PROVISIONING_TLS_MODE_H__