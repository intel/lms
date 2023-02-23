/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2010-2023 Intel Corporation
 */
/*++

@file: GetDNSSuffixListCommand.cpp

--*/

#include "GetDNSSuffixListCommand.h"

namespace Intel {
	namespace MEI_Client {
		namespace AMTHI_Client {
			GetDNSSuffixListCommand::GetDNSSuffixListCommand()
			{
				std::shared_ptr<MEICommandRequest> tmp(new GetDNSSuffixListRequest());
				m_request = tmp;
				Transact();
			}

			GET_DNS_SUFFIX_LIST_RESPONSE GetDNSSuffixListCommand::getResponse()
			{
				return m_response.getResponse();
			}

			void GetDNSSuffixListCommand::parseResponse(const std::vector<uint8_t>& buffer)
			{
				m_response = AMTHICommandResponse<GET_DNS_SUFFIX_LIST_RESPONSE>(buffer, RESPONSE_COMMAND_NUMBER);
			}
		} // namespace AMTHI_Client
	} // namespace MEI_Client
} // namespace Intel