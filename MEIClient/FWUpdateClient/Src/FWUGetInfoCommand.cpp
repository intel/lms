/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2010-2019 Intel Corporation
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
		return m_response->getResponse();
	}

	void FWUGetInfoCommand::parseResponse(const std::vector<uint8_t>& buffer)
	{
		std::shared_ptr<FWUpdateCommandResponse<GET_INFO_RESPONSE>> tmp(new FWUpdateCommandResponse<GET_INFO_RESPONSE>(buffer, RESPONSE_COMMAND_NUMBER));
		m_response = tmp;
	}

	std::vector<uint8_t> FWUGetInfoRequest::SerializeData()
	{
		std::vector<uint8_t> output;
		return output;
	}
} /* namespace FWUpdate_Client */ } /* namespace MEI_Client */ } /* namespace Intel */