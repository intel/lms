/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2020 Intel Corporation
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
				std::shared_ptr<MEICommandRequest> tmp(new GetUPIDRequest());
				m_request = tmp;
				Transact();
			}

			UPID_PLATFORM_ID_GET_Response GetUPIDCommand::getResponse()
			{
				return m_response->getResponse();
			}

			void  GetUPIDCommand::parseResponse(const std::vector<uint8_t>& buffer)
			{
				std::shared_ptr<UPIDCommandResponse<UPID_PLATFORM_ID_GET_Response>> tmp(new UPIDCommandResponse<UPID_PLATFORM_ID_GET_Response>(buffer, UPID_COMMAND_FEATURE_PLATFORM_ID, UPID_COMMAND_PLATFORM_ID_GET));
				m_response = tmp;
			}

			std::vector<uint8_t> GetUPIDRequest::SerializeData()
			{
				std::vector<uint8_t> output;
				return output;
			}
		} /* namespace HOTHAM_Client */ 
	} /* namespace MEI_Client */ 
} /* namespace Intel */