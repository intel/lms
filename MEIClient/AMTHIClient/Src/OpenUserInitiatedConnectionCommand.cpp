/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2010-2019 Intel Corporation
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
				std::shared_ptr<MEICommandRequest> tmp(new OpenUserInitiatedConnectionRequest());
				m_request = tmp;
				Transact();
			}

			void OpenUserInitiatedConnectionCommand::parseResponse(const std::vector<uint8_t>& buffer)
			{
				std::shared_ptr<AMTHICommandResponse<OpenUserInitiatedConnection_RESPONSE>> tmp(new AMTHICommandResponse<OpenUserInitiatedConnection_RESPONSE>(buffer, RESPONSE_COMMAND_NUMBER));
				m_response = tmp;
			}

			std::vector<uint8_t> OpenUserInitiatedConnectionRequest::SerializeData()
			{
				std::vector<uint8_t> output;
				return output;
			}
		} // namespace AMTHI_Client
	} // namespace MEI_Client
} // namespace Intel