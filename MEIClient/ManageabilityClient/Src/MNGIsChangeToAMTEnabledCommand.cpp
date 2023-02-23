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
		m_request = std::make_shared<MNGIsChangeToAMTEnabledRequest>();
		Transact();
	}

	IsChangedEnabledResponse MNGIsChangeToAMTEnabledCommand::getResponse()
	{
		return m_response.getResponse();
	}

	void MNGIsChangeToAMTEnabledCommand::parseResponse(const std::vector<uint8_t>& buffer)
	{
		m_response = ManageabilityCommandResponse<IsChangedEnabledResponse>(buffer);
	}
} /* namespace Manageability_Client */ } /* namespace MEI_Client */ } /* namespace Intel */