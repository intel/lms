/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2010-2019 Intel Corporation
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
				return m_response->getResponse().DNSSuffix;
			}

			void GetDNSSuffixCommand::parseResponse(const std::vector<uint8_t>& buffer)
			{
				std::shared_ptr<AMTHICommandResponse<GetDNSSuffix_RESPONSE>> tmp(new AMTHICommandResponse<GetDNSSuffix_RESPONSE>(buffer, RESPONSE_COMMAND_NUMBER));
				m_response = tmp;
			}

			std::vector<uint8_t> GetDNSSuffixRequest::SerializeData()
			{
				std::vector<uint8_t> output;
				return output;
			}
		} // namespace AMTHI_Client
	} // namespace MEI_Client
} // namespace Intel