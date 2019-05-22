/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2010-2015 Intel Corporation
 */
/*++

@file: SetProvisioningServerOTPCommand.cpp

--*/

#include "SetProvisioningServerOTPCommand.h"

using namespace std;

using namespace Intel::MEI_Client::AMTHI_Client;


SetProvisioningServerOTPCommand::SetProvisioningServerOTPCommand(std::string passwordOTP)
{
	shared_ptr<MEICommandRequest> tmp(new SetProvisioningServerOTPRequest(passwordOTP));
	m_request = tmp;
	Transact();
}

void
SetProvisioningServerOTPCommand::reTransact(std::string passwordOTP)
{
	shared_ptr<MEICommandRequest> tmp(new SetProvisioningServerOTPRequest(passwordOTP));
	m_request = tmp;
	Transact();
}

SET_PROVISIONING_SERVER_OTP_RESPONSE 
SetProvisioningServerOTPCommand::getResponse ()
{
	return m_response->getResponse();
}

void
SetProvisioningServerOTPCommand::parseResponse(const vector<uint8_t>& buffer)
{
	shared_ptr<AMTHICommandResponse<SET_PROVISIONING_SERVER_OTP_RESPONSE>> tmp(
		new AMTHICommandResponse<SET_PROVISIONING_SERVER_OTP_RESPONSE>(buffer, RESPONSE_COMMAND_NUMBER));
	m_response = tmp;
}

std::vector<uint8_t> 
SetProvisioningServerOTPRequest::SerializeData() {
	std::vector<uint8_t> output(_otp.serialize());
	return output;
}
