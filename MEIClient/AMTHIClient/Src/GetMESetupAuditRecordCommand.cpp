/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2010-2023 Intel Corporation
 */
/*++

@file: GetMESetupAuditRecordCommand.cpp

--*/

#include "GetMESetupAuditRecordCommand.h"

namespace Intel {
	namespace MEI_Client {
		namespace AMTHI_Client {
			GetMESetupAuditRecordCommand::GetMESetupAuditRecordCommand()
			{
				m_request = std::make_shared<GetMESetupAuditRecordRequest>();
				Transact();
			}

			GetMESetupAuditRecord_RESPONSE GetMESetupAuditRecordCommand::getResponse()
			{
				return m_response.getResponse();
			}

			void GetMESetupAuditRecordCommand::parseResponse(const std::vector<uint8_t>& buffer)
			{
				m_response = AMTHICommandResponse<GetMESetupAuditRecord_RESPONSE>(buffer, RESPONSE_COMMAND_NUMBER);
			}
		} // namespace AMTHI_Client
	} // namespace MEI_Client
} // namespace Intel	