/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2010-2023 Intel Corporation
 */
/*++

@file: GetDNSSuffixCommand.cpp

--*/

#include "GetDNSSuffixCommand.h"

namespace Intel {
	namespace MEI_Client {
		namespace AMTHI_Client {
			GetDNSSuffixCommand::GetDNSSuffixCommand()
			{
				std::shared_ptr<MEICommandRequest> tmp(new GetDNSSuffixRequest());
				m_request = tmp;
				Transact();
			}

			std::string GetDNSSuffixCommand::getResponse()
			{
				return m_response.getResponse().DNSSuffix;
			}

			void GetDNSSuffixCommand::parseResponse(const std::vector<uint8_t>& buffer)
			{
				m_response = AMTHICommandResponse<GetDNSSuffix_RESPONSE>(buffer, RESPONSE_COMMAND_NUMBER);
			}
		} // namespace AMTHI_Client
	} // namespace MEI_Client
} // namespace Intel