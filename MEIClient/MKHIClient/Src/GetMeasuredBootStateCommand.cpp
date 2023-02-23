/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2020-2023 Intel Corporation
 */
/*++

@file: GetMeasuredBootStateCommand.cpp

--*/

#include "GetMeasuredBootStateCommand.h"

namespace Intel { namespace MEI_Client { namespace MKHI_Client {

	GetMeasuredBootStateCommand::GetMeasuredBootStateCommand()
	{
		std::shared_ptr<MEICommandRequest> tmp(new GetMeasuredBootStateRequest());
		m_request = tmp;
		Transact();
	}

	MKHI_MEASURED_BOOT_STATE GetMeasuredBootStateCommand::getResponse()
	{
		return m_response.getResponse();
	}

	void  GetMeasuredBootStateCommand::parseResponse(const std::vector<uint8_t>& buffer)
	{
		m_response = MKHICommandResponse<MKHI_MEASURED_BOOT_STATE>(buffer, RESPONSE_COMMAND_NUMBER, MKHI_GEN_GROUP_ID);
	}
} /* namespace MKHI_Client */ } /* namespace MEI_Client */ } /* namespace Intel */