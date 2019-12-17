/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2010-2019 Intel Corporation
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
				return m_response->getResponse();
			}

			void GetDNSSuffixListCommand::parseResponse(const std::vector<uint8_t>& buffer)
			{
				std::shared_ptr<AMTHICommandResponse<GET_DNS_SUFFIX_LIST_RESPONSE> > tmp(
					new AMTHICommandResponse<GET_DNS_SUFFIX_LIST_RESPONSE>(buffer, RESPONSE_COMMAND_NUMBER));
				m_response = tmp;
			}

			std::vector<uint8_t> GetDNSSuffixListRequest::SerializeData()
			{
				std::vector<uint8_t> output;
				return output;
			}
		} // namespace AMTHI_Client
	} // namespace MEI_Client
} // namespace Intel