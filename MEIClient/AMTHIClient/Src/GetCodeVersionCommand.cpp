/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2010-2019 Intel Corporation
 */
/*++

@file: GetCodeVersionCommand.cpp

--*/

#include "GetCodeVersionCommand.h"

namespace Intel {
	namespace MEI_Client {
		namespace AMTHI_Client {
			GetCodeVersionCommand::GetCodeVersionCommand()
			{
				std::shared_ptr<MEICommandRequest> tmp(new GetCodeVersionRequest());
				m_request = tmp;
				Transact();
			}

			CODE_VERSIONS GetCodeVersionCommand::getResponse()
			{
				return m_response->getResponse();
			}

			void GetCodeVersionCommand::parseResponse(const std::vector<uint8_t>& buffer)
			{
				std::shared_ptr<AMTHICommandResponse<CODE_VERSIONS>> tmp(new AMTHICommandResponse<CODE_VERSIONS>(buffer, RESPONSE_COMMAND_NUMBER));
				m_response = tmp;
			}
		} // namespace AMTHI_Client
	} // namespace MEI_Client
} // namespace Intel