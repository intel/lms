/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2020-2023 Intel Corporation
 */
/*++

@file: GetUPIDFeatureOSControlCommand.cpp

--*/

#include "GetUPIDFeatureOSControlCommand.h"

namespace Intel { 
	namespace MEI_Client { 
		namespace UPID_Client {
			GetUPIDFeatureOSControlCommand::GetUPIDFeatureOSControlCommand()
			{
				m_request = std::make_shared<GetUPIDFeatureOSControlRequest>();
				Transact();
			}

			UPID_PLATFORM_ID_FEATURE_OSCONTROL_GET_Response GetUPIDFeatureOSControlCommand::getResponse()
			{
				return m_response.getResponse();
			}

			void GetUPIDFeatureOSControlCommand::parseResponse(const std::vector<uint8_t>& buffer)
			{
				m_response = UPIDCommandResponse<UPID_PLATFORM_ID_FEATURE_OSCONTROL_GET_Response>(buffer, UPID_COMMAND_FEATURE_PLATFORM_ID, UPID_COMMAND_PLATFORM_ID_FEATURE_STATE_OS_CONTROL_GET);
			}
		} /* namespace UPID_Client */
	} /* namespace MEI_Client */
} /* namespace Intel */