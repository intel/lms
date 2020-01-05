/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2010-2019 Intel Corporation
 */
/*++

@file: MNGChangeToAMTCommand.cpp

--*/

#include "MNGChangeToAMTCommand.h"

namespace Intel { namespace MEI_Client { namespace Manageability_Client {
	MNGChangeToAMTCommand::MNGChangeToAMTCommand()
	{
		std::shared_ptr<MEICommandRequest> tmp(new MNGChangeToAMTRequest());
		m_request = tmp;
		Transact();
	}

	ChangeToAMT_RESPONSE MNGChangeToAMTCommand::getResponse()
	{
		return m_response->getResponse();
	}

	void MNGChangeToAMTCommand::parseResponse(const std::vector<uint8_t>& buffer)
	{
		std::shared_ptr<ManageabilityCommandResponse<ChangeToAMT_RESPONSE>> tmp(new ManageabilityCommandResponse<ChangeToAMT_RESPONSE>(buffer));
		m_response = tmp;
	}

	std::vector<uint8_t> MNGChangeToAMTRequest::SerializeData()
	{
		std::vector<uint8_t> output;
		return output;
	}
} /* namespace Manageability_Client */ } /* namespace MEI_Client */ } /* namespace Intel */