/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2020-2023 Intel Corporation
 */
/*++

@file: SetUPIDFeatureStateCommand.cpp

--*/

#include "SetUPIDFeatureStateCommand.h"

namespace Intel {
	namespace MEI_Client {
		namespace UPID_Client {
			SetUPIDFeatureStateCommand::SetUPIDFeatureStateCommand(bool featureState)
			{
				m_request = std::make_shared<SetUPIDFeatureStateRequest>(featureState);
				Transact();
			}

			UPID_PLATFORM_ID_FEATURE_STATE_SET_Response SetUPIDFeatureStateCommand::getResponse()
			{
				return m_response.getResponse();
			}

			void  SetUPIDFeatureStateCommand::parseResponse(const std::vector<uint8_t>& buffer)
			{
				m_response = UPIDCommandResponse<UPID_PLATFORM_ID_FEATURE_STATE_SET_Response>(buffer, UPID_COMMAND_FEATURE_PLATFORM_ID, UPID_COMMAND_PLATFORM_ID_FEATURE_STATE_SET);
			}

			std::vector<uint8_t> SetUPIDFeatureStateRequest::SerializeData()
			{
				std::vector<uint8_t> output((std::uint8_t*)&_featureState, (std::uint8_t*)&_featureState + sizeof(_featureState));
				return output;
			}
		} /* namespace HOTHAM_Client */ 
	} /* namespace MEI_Client */ 
} /* namespace Intel */