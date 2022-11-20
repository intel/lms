/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2020-2022 Intel Corporation
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

			typedef struct _UPID_PLATFORM_ID_FEATURE_SUPPORT_GET_Response
			{
				uint8_t platformIdSupported;

				void parse(std::vector<uint8_t>::const_iterator& itr, const std::vector<uint8_t>::const_iterator &end)
				{
					parseData(platformIdSupported, itr, end);
				}
			} UPID_PLATFORM_ID_FEATURE_SUPPORT_GET_Response;

			class GetUPIDFeatureSupportRequest;
			class GetUPIDFeatureSupportCommand : public UPIDCommand
			{
			public:

				GetUPIDFeatureSupportCommand();
				virtual ~GetUPIDFeatureSupportCommand() {}

				UPID_PLATFORM_ID_FEATURE_SUPPORT_GET_Response getResponse();

			private:
				virtual void parseResponse(const std::vector<uint8_t>& buffer);

				std::shared_ptr<UPIDCommandResponse<UPID_PLATFORM_ID_FEATURE_SUPPORT_GET_Response>> m_response;
			};

			class GetUPIDFeatureSupportRequest : public UPIDRequest
			{
			public:
				GetUPIDFeatureSupportRequest() {}
				virtual ~GetUPIDFeatureSupportRequest() {}

			private:
				virtual uint8_t requestHeaderFeatureID()
				{
					return UPID_COMMAND_FEATURE_PLATFORM_ID;
				}
				virtual uint8_t requestHeaderCommandID()
				{
					return UPID_COMMAND_PLATFORM_ID_FEATURE_SUPPORT_GET;
				}
				virtual uint16_t requestDataSize()
				{
					return 0;
				}
				virtual std::vector<uint8_t> SerializeData();
			};
		} // namespace UPID_Client
	} // namespace MEI_Client
} // namespace Intel

#endif //__GET_UPID_FEATURE_SUPPORT_COMMAND_H__