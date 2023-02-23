/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2020-2023 Intel Corporation
 */
/*++

@file: GetUPIDFeatureSupportCommand.cpp

--*/

#include "GetUPIDFeatureSupportCommand.h"

namespace Intel {
	namespace MEI_Client {
		namespace UPID_Client {
			GetUPIDFeatureSupportCommand::GetUPIDFeatureSupportCommand()
			{
				m_request = std::make_shared<GetUPIDFeatureSupportRequest>();
				Transact();
			}

			UPID_PLATFORM_ID_FEATURE_SUPPORT_GET_Response GetUPIDFeatureSupportCommand::getResponse()
			{
				return m_response.getResponse();
			}

			void GetUPIDFeatureSupportCommand::parseResponse(const std::vector<uint8_t>& buffer)
			{
				m_response = UPIDCommandResponse<UPID_PLATFORM_ID_FEATURE_SUPPORT_GET_Response>(buffer, UPID_COMMAND_FEATURE_PLATFORM_ID, UPID_COMMAND_PLATFORM_ID_FEATURE_SUPPORT_GET);
			}
		} /* namespace UPID_Client */
	} /* namespace MEI_Client */
} /* namespace Intel */