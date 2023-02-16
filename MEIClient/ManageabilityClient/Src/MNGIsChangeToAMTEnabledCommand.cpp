/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2010-2023 Intel Corporation
 */
/*++

@file: MNGIsChangeToAMTEnabledCommand.cpp

--*/

#include "MNGIsChangeToAMTEnabledCommand.h"

namespace Intel { namespace MEI_Client { namespace Manageability_Client {
	MNGIsChangeToAMTEnabledCommand::MNGIsChangeToAMTEnabledCommand()
	{
		std::shared_ptr<MEICommandRequest> tmp(new MNGIsChangeToAMTEnabledRequest());
		m_request = tmp;
		Transact();
	}

	IsChangedEnabledResponse MNGIsChangeToAMTEnabledCommand::getResponse()
	{
		return m_response->getResponse();
	}

	void MNGIsChangeToAMTEnabledCommand::parseResponse(const std::vector<uint8_t>& buffer)
	{
		std::shared_ptr<ManageabilityCommandResponse<IsChangedEnabledResponse>> tmp(new ManageabilityCommandResponse<IsChangedEnabledResponse>(buffer));
		m_response = tmp;
	}
} /* namespace Manageability_Client */ } /* namespace MEI_Client */ } /* namespace Intel */