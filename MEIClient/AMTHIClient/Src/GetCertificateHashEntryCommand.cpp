/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2010-2023 Intel Corporation
 */
/*++

@file: GetCertificateHashEntryCommand.cpp

--*/

#include "GetCertificateHashEntryCommand.h"

namespace Intel {
	namespace MEI_Client {
		namespace AMTHI_Client {
			GetCertificateHashEntryCommand::GetCertificateHashEntryCommand(uint32_t hashHandle)
			{
				std::shared_ptr<MEICommandRequest> tmp(new GetCertificateHashEntryRequest(hashHandle));
				m_request = tmp;
				Transact();
			}

			GET_CERTIFICATE_HASH_ENTRY_RESPONSE GetCertificateHashEntryCommand::getResponse()
			{
				return m_response.getResponse();
			}

			void GetCertificateHashEntryCommand::parseResponse(const std::vector<uint8_t>& buffer)
			{
				m_response = AMTHICommandResponse<GET_CERTIFICATE_HASH_ENTRY_RESPONSE>(buffer, RESPONSE_COMMAND_NUMBER);
			}

			std::vector<uint8_t> GetCertificateHashEntryRequest::SerializeData()
			{
				std::vector<uint8_t> output((std::uint8_t*)&_hashHandle, (std::uint8_t*)&_hashHandle + sizeof(uint32_t));
				return output;
			}
		} // namespace AMTHI_Client
	} // namespace MEI_Client
} // namespace Intel
