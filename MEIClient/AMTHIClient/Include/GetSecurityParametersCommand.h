/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2010-2023 Intel Corporation
 */
/*++

@file: GetSecurityParametersCommand.h

--*/


#ifndef __GET_SECURITY_PARAMETERS_COMMAND_H__
#define __GET_SECURITY_PARAMETERS_COMMAND_H__

#include "AMTHICommand.h"
#include "MEIparser.h"

namespace Intel
{
	namespace MEI_Client
	{
		namespace AMTHI_Client
		{
			struct SECURITY_PARAMETERS
			{
				bool					EnterpriseMode;
				bool					TLSEnabled;
				bool					HWCryptoEnabled;
				AMT_PROVISIONING_STATE	ProvisioningState;
				bool					NetworkInterfaceEnabled;
				bool					SOLEnabled;
				bool					IDEREnabled;
				bool					FWUpdateEnabled;
				bool					LinkIsUp;
				bool					KvmEnabled;
				//vector<bool>			Reserved; //size  = 7

				void parse (std::vector<uint8_t>::const_iterator& itr, const std::vector<uint8_t>::const_iterator end)
				{
					struct {
						uint32_t tmp[17];
					} tmp;
					Intel::MEI_Client::parseData(tmp, itr, end);
					EnterpriseMode = (tmp.tmp[0] == AMT_TRUE);
					TLSEnabled = (tmp.tmp[1] == AMT_TRUE);
					HWCryptoEnabled = (tmp.tmp[2] == AMT_TRUE);
					ProvisioningState = (AMT_PROVISIONING_STATE)tmp.tmp[3];
					NetworkInterfaceEnabled = (tmp.tmp[4] == AMT_TRUE);
					SOLEnabled = (tmp.tmp[5] == AMT_TRUE);
					IDEREnabled = (tmp.tmp[6] == AMT_TRUE);
					FWUpdateEnabled = (tmp.tmp[7] == AMT_TRUE);
					LinkIsUp = (tmp.tmp[8] == AMT_TRUE);
					KvmEnabled = (tmp.tmp[9] == AMT_TRUE);
				}
			};

			class GetSecurityParametersCommand : public AMTHICommand
			{
			public:

				GetSecurityParametersCommand();
				virtual ~GetSecurityParametersCommand() {}

				SECURITY_PARAMETERS getResponse();

			private:
				virtual void parseResponse(const std::vector<uint8_t>& buffer);

				std::shared_ptr<AMTHICommandResponse<SECURITY_PARAMETERS>> m_response;
				static const uint32_t RESPONSE_COMMAND_NUMBER = 0x0480001B;
			};

			class GetSecurityParametersRequest : public AMTHICommandRequest
			{
			public:
				GetSecurityParametersRequest() {}
				virtual ~GetSecurityParametersRequest() {}

			private:
				static const uint32_t REQUEST_COMMAND_NUMBER = 0x0400001B;
				virtual unsigned int requestHeaderCommandNumber()
				{
					//this is the command number (taken from the AMTHI document)
					return REQUEST_COMMAND_NUMBER;
				}

				virtual uint32_t requestDataSize()
				{
					return 0;
				}
			};
		} // namespace AMTHI_Client
	} // namespace MEI_Client
} // namespace Intel

#endif //__GET_SECURITY_PARAMETERS_COMMAND_H__