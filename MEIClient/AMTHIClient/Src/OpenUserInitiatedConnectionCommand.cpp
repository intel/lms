/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2010-2023 Intel Corporation
 */
/*++

@file: OpenUserInitiatedConnectionCommand.cpp

--*/

#include "OpenUserInitiatedConnectionCommand.h"

namespace Intel {
	namespace MEI_Client {
		namespace AMTHI_Client {
			OpenUserInitiatedConnectionCommand::OpenUserInitiatedConnectionCommand()
			{
				m_request = std::make_shared<OpenUserInitiatedConnectionRequest>();
				Transact();
			}

			void OpenUserInitiatedConnectionCommand::parseResponse(const std::vector<uint8_t>& buffer)
			{
				m_response = AMTHICommandResponse<OpenUserInitiatedConnection_RESPONSE>(buffer, RESPONSE_COMMAND_NUMBER);
			}
		} // namespace AMTHI_Client
	} // namespace MEI_Client
} // namespace Intel