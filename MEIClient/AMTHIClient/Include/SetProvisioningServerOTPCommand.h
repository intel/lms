/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2010-2019 Intel Corporation
 */
/*++

@file: SetProvisioningServerOTPCommand.h

--*/

#ifndef __SET_PROVISIONING_SERVER_OTP_COMMAND_H__
#define __SET_PROVISIONING_SERVER_OTP_COMMAND_H__

#include "AMTHICommand.h"
#include "AmtAnsiString.h"
#include "MEIparser.h"

namespace Intel
{
	namespace MEI_Client
	{
		namespace AMTHI_Client
		{
			struct SET_PROVISIONING_SERVER_OTP_RESPONSE
			{
				void parse (std::vector<uint8_t>::const_iterator& /*itr*/, const std::vector<uint8_t>::const_iterator& /*end*/)
				{
					return;
				}
			};

			class SetProvisioningServerOTPRequest;
			class SetProvisioningServerOTPCommand : public AMTHICommand
			{
			public:

				SetProvisioningServerOTPCommand(std::string passwordOTP);
				virtual ~SetProvisioningServerOTPCommand() {}

				SET_PROVISIONING_SERVER_OTP_RESPONSE getResponse();
				
				virtual void reTransact(std::string);

				private:
				virtual void parseResponse(const std::vector<uint8_t>& buffer);

				std::shared_ptr<AMTHICommandResponse<SET_PROVISIONING_SERVER_OTP_RESPONSE>> m_response;

				static const uint32_t RESPONSE_COMMAND_NUMBER = 0x0480002A;
			};

			class SetProvisioningServerOTPRequest : public AMTHICommandRequest
			{
				static const uint32_t MIN_OTP_BUFFER_LENGTH = 8;
				static const uint32_t MAX_OTP_BUFFER_LENGTH = 32;
			public:
				SetProvisioningServerOTPRequest (const std::string otp):_otp(otp) 
				{
					if (_otp.size() > MAX_OTP_BUFFER_LENGTH || _otp.size() < MIN_OTP_BUFFER_LENGTH) 
						throw MEIClientException("Error: OTP string not in the right size.");
				}
				virtual ~SetProvisioningServerOTPRequest() {}

			private:
				AmtAnsiString _otp;

				static const uint32_t REQUEST_COMMAND_NUMBER = 0x0400002A;
				virtual unsigned int requestHeaderCommandNumber()
				{
					//this is the command number (taken from the AMTHI document)
					return REQUEST_COMMAND_NUMBER;
				}

				virtual uint32_t requestDataSize()
				{
					return _otp.bufSize();
				}
				virtual std::vector<uint8_t> SerializeData();
			};
		} // namespace AMTHI_Client
	} // namespace MEI_Client
} // namespace Intel

#endif //__SET_PROVISIONING_SERVER_OTP_COMMAND_H__