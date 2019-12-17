/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2010-2019 Intel Corporation
 */
/*++

@file: GetZeroTouchEnabledCommand.cpp

--*/

#include "GetZeroTouchEnabledCommand.h"

namespace Intel {
	namespace MEI_Client {
		namespace AMTHI_Client {
			GetZeroTouchEnabledCommand::GetZeroTouchEnabledCommand()
			{
				std::shared_ptr<MEICommandRequest> tmp(new GetZeroTouchEnabledRequest());
				m_request = tmp;
				Transact();
			}

			ZTC_ENABLED_STATUS GetZeroTouchEnabledCommand::getResponse()
			{
				return m_response->getResponse();
			}

			void GetZeroTouchEnabledCommand::parseResponse(const std::vector<uint8_t>& buffer)
			{
				std::shared_ptr<AMTHICommandResponse<ZTC_ENABLED_STATUS>> tmp(new AMTHICommandResponse<ZTC_ENABLED_STATUS>(buffer, RESPONSE_COMMAND_NUMBER));
				m_response = tmp;
			}

			std::vector<uint8_t> GetZeroTouchEnabledRequest::SerializeData()
			{
				std::vector<uint8_t> output;
				return output;
			}
		} // namespace AMTHI_Client
	} // namespace MEI_Client
} // namespace Intel