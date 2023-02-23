/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2020-2023 Intel Corporation
 */
/*++

@file: GetUPIDCommand.cpp

--*/

#include "GetUPIDCommand.h"

namespace Intel {
	namespace MEI_Client {
		namespace UPID_Client {
			GetUPIDCommand::GetUPIDCommand()
			{
				m_request = std::make_shared<GetUPIDRequest>();
				Transact();
			}

			UPID_PLATFORM_ID_GET_Response GetUPIDCommand::getResponse()
			{
				return m_response.getResponse();
			}

			void  GetUPIDCommand::parseResponse(const std::vector<uint8_t>& buffer)
			{
				m_response = UPIDCommandResponse<UPID_PLATFORM_ID_GET_Response>(buffer, UPID_COMMAND_FEATURE_PLATFORM_ID, UPID_COMMAND_PLATFORM_ID_GET);
			}
		} /* namespace UPID_Client */
	} /* namespace MEI_Client */
} /* namespace Intel */