/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2010-2019 Intel Corporation
 */
/*++

@file: GetProvisioningStateCommand.cpp

--*/

#include "GetProvisioningStateCommand.h"
#include "StatusCodeDefinitions.h"
#include <string.h>

using namespace std;

using namespace Intel::MEI_Client::AMTHI_Client;

GetProvisioningStateCommand::GetProvisioningStateCommand()
{
	shared_ptr<MEICommandRequest> tmp(new GetProvisioningStateRequest());
	m_request = tmp;
	Transact();
}

CFG_PROVISIONING_STATE GetProvisioningStateCommand::getResponse()
{
	return m_response->getResponse();
}

void
GetProvisioningStateCommand::parseResponse(const vector<uint8_t>& buffer)
{
	shared_ptr<AMTHICommandResponse<CFG_PROVISIONING_STATE>> tmp(new AMTHICommandResponse<CFG_PROVISIONING_STATE>(buffer, RESPONSE_COMMAND_NUMBER));
	m_response = tmp;
}

std::vector<uint8_t> 
GetProvisioningStateRequest::SerializeData()
{
	vector<uint8_t> output;
	return output;
}

//GetProvisioningStateResponse::GetProvisioningStateResponse(const vector<uint8_t>& buffer)
//{
//	
//	unsigned int headerAndStatSize =0;
//	verifyHeaderAndStatus(&buffer[0],  headerAndStatSize);
//	verifyAndGenerateResponse(&buffer[headerAndStatSize], 
//		bufferSize - headerAndStatSize );  
//}
//
//void
//GetProvisioningStateResponse::verifyAndGenerateResponse(const uint8_t* const buffer)
//{
//	if (bufferSize != sizeof(PROVISIONING_STATE))
//	{
//		throw MEIClientException("Error: data buffer not in the right size");
//	}
//	memcpy(&m_provisioningState, buffer, sizeof(PROVISIONING_STATE));
//}
//
//
//
//
//
//
//
//	

	