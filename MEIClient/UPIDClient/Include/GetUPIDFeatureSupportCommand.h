/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2020-2023 Intel Corporation
 */
/*++

@file: GetUPIDFeatureSupportCommand.h

--*/

#ifndef __GET_UPID_FEATURE_SUPPORT_COMMAND_H__
#define __GET_UPID_FEATURE_SUPPORT_COMMAND_H__

#include "UPIDCommand.h"
#include "MEIparser.h"

namespace Intel
{
	namespace MEI_Client
	{
		namespace UPID_Client
		{
			static const uint8_t UPID_PLATFORM_ID_UPID_IS_SUPPORTED = 0x1;
			static const uint8_t UPID_PLATFORM_ID_ATTESTATION_IS_SUPPORTED = 0x2;

			struct UPID_PLATFORM_ID_FEATURE_SUPPORT_GET_Response
			{
				UPID_PLATFORM_ID_FEATURE_SUPPORT_GET_Response() : platformIdSupported(0) {}
				uint8_t platformIdSupported;

				void parse(std::vector<uint8_t>::const_iterator& itr, const std::vector<uint8_t>::const_iterator &end)
				{
					parseData(platformIdSupported, itr, end);
				}
			};

			class GetUPIDFeatureSupportRequest : public UPIDRequest
			{
			public:
				GetUPIDFeatureSupportRequest() :
					UPIDRequest(UPID_COMMAND_FEATURE_PLATFORM_ID, UPID_COMMAND_PLATFORM_ID_FEATURE_SUPPORT_GET) {}
				virtual ~GetUPIDFeatureSupportRequest() {}
			};

			class GetUPIDFeatureSupportCommand : public UPIDCommand
			{
			public:

				GetUPIDFeatureSupportCommand()
				{
					m_request = std::make_shared<GetUPIDFeatureSupportRequest>();
					Transact();
				}
				virtual ~GetUPIDFeatureSupportCommand() {}

				UPID_PLATFORM_ID_FEATURE_SUPPORT_GET_Response getResponse() { return m_response.getResponse(); }

			private:
				virtual void parseResponse(const std::vector<uint8_t>& buffer)
				{
					m_response = UPIDCommandResponse<UPID_PLATFORM_ID_FEATURE_SUPPORT_GET_Response>(buffer, UPID_COMMAND_FEATURE_PLATFORM_ID, UPID_COMMAND_PLATFORM_ID_FEATURE_SUPPORT_GET);
				}

				UPIDCommandResponse<UPID_PLATFORM_ID_FEATURE_SUPPORT_GET_Response> m_response;
			};
		} // namespace UPID_Client
	} // namespace MEI_Client
} // namespace Intel

#endif //__GET_UPID_FEATURE_SUPPORT_COMMAND_H__