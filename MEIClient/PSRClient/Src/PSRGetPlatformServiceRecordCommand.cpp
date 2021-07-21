/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2021 Intel Corporation
 */
/*++

@file: PSRGetPlatformServiceRecordCommand.cpp

--*/

#include "PSRGetPlatformServiceRecordCommand.h"

namespace Intel {
	namespace MEI_Client {
		namespace PSR_Client {
			PSRGetPlatformServiceRecordCommand::PSRGetPlatformServiceRecordCommand(const std::array<uint8_t, PSR_NONCE_SIZE>& _nonce)
			{
				std::shared_ptr<MEICommandRequest> tmp(new PSRGetPlatformServiceRecordRequest(_nonce));
				m_request = tmp;
				Transact();
			}

			PSR_GET_RESPONSE PSRGetPlatformServiceRecordCommand::getResponse()
			{
				return m_response->getResponse();
			}

			void PSRGetPlatformServiceRecordCommand::parseResponse(const std::vector<uint8_t>& buffer)
			{
				std::shared_ptr<PSRCommandResponse<PSR_GET_RESPONSE>> tmp(
					new PSRCommandResponse<PSR_GET_RESPONSE>(buffer, PSR_HECI_COMMANDS::PLATFORM_SERVICE_RECORD_GET));
				m_response = tmp;
			}

			PSRGetPlatformServiceRecordRawCommand::PSRGetPlatformServiceRecordRawCommand(const std::array<uint8_t, PSR_NONCE_SIZE>& _nonce)
			{
				std::shared_ptr<MEICommandRequest> tmp(new PSRGetPlatformServiceRecordRequest(_nonce));
				m_request = tmp;
				Transact();
			}

			PSR_GET_RESPONSE_RAW PSRGetPlatformServiceRecordRawCommand::getResponse()
			{
				return m_response->getResponse();
			}

			void PSRGetPlatformServiceRecordRawCommand::parseResponse(const std::vector<uint8_t>& buffer)
			{
				std::shared_ptr<PSRCommandResponse<PSR_GET_RESPONSE_RAW>> tmp(
					new PSRCommandResponse<PSR_GET_RESPONSE_RAW>(buffer, PSR_HECI_COMMANDS::PLATFORM_SERVICE_RECORD_GET));
				m_response = tmp;
			}

			std::vector<uint8_t> PSRGetPlatformServiceRecordRequest::SerializeData()
			{
				std::vector<uint8_t> output(user_nonce.begin(), user_nonce.end());

				return output;
			}
		} // namespace PSR_Client
	} // namespace MEI_Client
} // namespace Intel