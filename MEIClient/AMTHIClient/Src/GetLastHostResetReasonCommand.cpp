/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2010-2023 Intel Corporation
 */
/*++

@file: GetLastHostResetReasonCommand.cpp

--*/

#include "GetLastHostResetReasonCommand.h"

namespace Intel {
	namespace MEI_Client {
		namespace AMTHI_Client {
			GetLastHostResetReasonCommand::GetLastHostResetReasonCommand()
			{
				std::shared_ptr<MEICommandRequest> tmp(new GetLastHostResetReasonRequest());
				m_request = tmp;
				Transact();
			}

			LAST_HOST_RESET_REASON_RESPONSE GetLastHostResetReasonCommand::getResponse()
			{
				return m_response->getResponse();
			}

			void GetLastHostResetReasonCommand::parseResponse(const std::vector<uint8_t>& buffer)
			{
				std::shared_ptr<AMTHICommandResponse<LAST_HOST_RESET_REASON_RESPONSE>> tmp(new AMTHICommandResponse<LAST_HOST_RESET_REASON_RESPONSE>(buffer, RESPONSE_COMMAND_NUMBER));
				m_response = tmp;
			}
		} // namespace AMTHI_Client
	} // namespace MEI_Client
} // namespace Intel