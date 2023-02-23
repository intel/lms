/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2010-2023 Intel Corporation
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
				m_request = std::make_shared<SetDNSSuffixRequest>(suffix);
				Transact();
			}

			void SetDNSSuffixCommand::parseResponse(const std::vector<uint8_t>& buffer)
			{
				m_response = AMTHICommandResponse<SetDNSSuffix_RESPONSE>(buffer, RESPONSE_COMMAND_NUMBER);
			}

			std::vector<uint8_t> SetDNSSuffixRequest::SerializeData()
			{
				std::vector<uint8_t> output = m_str.serialize();
				return output;
			}
		} // namespace AMTHI_Client
	} // namespace MEI_Client
} // namespace Intel