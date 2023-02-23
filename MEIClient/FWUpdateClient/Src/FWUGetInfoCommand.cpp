/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2010-2023 Intel Corporation
 */
/*++

@file: FWUGetInfoCommand.cpp

--*/

#include "FWUGetInfoCommand.h"

namespace Intel { namespace MEI_Client { namespace FWUpdate_Client {
	FWUGetInfoCommand::FWUGetInfoCommand()
	{
		std::shared_ptr<MEICommandRequest> tmp(new FWUGetInfoRequest());
		m_request = tmp;
		Transact();
	}

	GET_INFO_RESPONSE FWUGetInfoCommand::getResponse()
	{
		return m_response.getResponse();
	}

	void FWUGetInfoCommand::parseResponse(const std::vector<uint8_t>& buffer)
	{
		m_response = FWUpdateCommandResponse<GET_INFO_RESPONSE>(buffer, RESPONSE_COMMAND_NUMBER);
	}
} /* namespace FWUpdate_Client */ } /* namespace MEI_Client */ } /* namespace Intel */