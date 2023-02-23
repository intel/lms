/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2010-2023 Intel Corporation
 */
/*++

@file: CloseUserInitiatedConnectionCommand.cpp

--*/

#include "CloseUserInitiatedConnectionCommand.h"

namespace Intel {
	namespace MEI_Client {
		namespace AMTHI_Client {
			CloseUserInitiatedConnectionCommand::CloseUserInitiatedConnectionCommand()
			{
				m_request = std::make_shared< CloseUserInitiatedConnectionRequest>();
				Transact();
			}

			void CloseUserInitiatedConnectionCommand::parseResponse(const std::vector<uint8_t>& buffer)
			{
				m_response = AMTHICommandResponse<CloseUserInitiatedConnection_RESPONSE>(buffer, RESPONSE_COMMAND_NUMBER);
			}
		} // namespace AMTHI_Client
	} // namespace MEI_Client
} // namespace Intel	