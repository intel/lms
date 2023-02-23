/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2020-2023 Intel Corporation
 */
/*++

@file: GetUPIDFeatureStateCommand.cpp

--*/

#include "GetUPIDFeatureStateCommand.h"

namespace Intel { 
	namespace MEI_Client { 
		namespace UPID_Client {
			GetUPIDFeatureStateCommand::GetUPIDFeatureStateCommand()
			{
				m_request = std::make_shared<GetUPIDFeatureStateRequest>();
				Transact();
			}

			UPID_PLATFORM_ID_FEATURE_STATE_GET_Response GetUPIDFeatureStateCommand::getResponse()
			{
				return m_response.getResponse();
			}

			void  GetUPIDFeatureStateCommand::parseResponse(const std::vector<uint8_t>& buffer)
			{
				m_response = UPIDCommandResponse<UPID_PLATFORM_ID_FEATURE_STATE_GET_Response>(buffer, UPID_COMMAND_FEATURE_PLATFORM_ID, UPID_COMMAND_PLATFORM_ID_FEATURE_STATE_GET);
			}
		} /* namespace UPID_Client */
	} /* namespace MEI_Client */ 
} /* namespace Intel */