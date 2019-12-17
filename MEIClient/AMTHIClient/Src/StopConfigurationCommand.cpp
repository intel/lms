/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2010-2019 Intel Corporation
 */
/*++

@file: StopConfigurationCommand.cpp

--*/

#include "StopConfigurationCommand.h"

namespace Intel {
	namespace MEI_Client {
		namespace AMTHI_Client {
			StopConfigurationCommand::StopConfigurationCommand()
			{
				std::shared_ptr<MEICommandRequest> tmp(new StopConfigurationRequest());
				m_request = tmp;
				Transact();
			}

			void StopConfigurationCommand::parseResponse(const std::vector<uint8_t>& buffer)
			{
				std::shared_ptr<AMTHICommandResponse<StopConfig_RESPONSE>> tmp(new AMTHICommandResponse<StopConfig_RESPONSE>(buffer, RESPONSE_COMMAND_NUMBER));
				m_response = tmp;
			}
		} // namespace AMTHI_Client
	} // namespace MEI_Client
} // namespace Intel