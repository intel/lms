/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2010-2019 Intel Corporation
 */
/*++

@file: SetDNSSuffixCommand.cpp

--*/

#include "SetDNSSuffixCommand.h"

namespace Intel {
	namespace MEI_Client {
		namespace AMTHI_Client {
			SetDNSSuffixCommand::SetDNSSuffixCommand(const std::string &suffix)
			{
				std::shared_ptr<MEICommandRequest> tmp(new SetDNSSuffixRequest(suffix));
				m_request = tmp;
				Transact();
			}

			void SetDNSSuffixCommand::parseResponse(const std::vector<uint8_t>& buffer)
			{
				std::shared_ptr<AMTHICommandResponse<SetDNSSuffix_RESPONSE>> tmp(new AMTHICommandResponse<SetDNSSuffix_RESPONSE>(buffer, RESPONSE_COMMAND_NUMBER));
				m_response = tmp;
			}

			std::vector<uint8_t> SetDNSSuffixRequest::SerializeData()
			{
				std::vector<uint8_t> output = m_str.serialize();
				return output;
			}
		} // namespace AMTHI_Client
	} // namespace MEI_Client
} // namespace Intel