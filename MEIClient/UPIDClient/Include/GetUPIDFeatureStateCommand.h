/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2020 Intel Corporation
 */
/*++

@file: GetUPIDFeatureStateCommand.h

--*/

#ifndef __GET_UPID_FEATURE_STATE_COMMAND_H__
#define __GET_UPID_FEATURE_STATE_COMMAND_H__

#include "UPIDCommand.h"
#include "MEIparser.h"


namespace Intel
{
	namespace MEI_Client
	{
		namespace UPID_Client
		{
			typedef struct _UPID_PLATFORM_ID_FEATURE_STATE_GET_Response
			{
				uint8_t                              FeatureEnabled;

				void parse(std::vector<uint8_t>::const_iterator& itr, const std::vector<uint8_t>::const_iterator &end)
				{
					parseData(FeatureEnabled, itr, end);
				}
			}  UPID_PLATFORM_ID_FEATURE_STATE_GET_Response;


			class GetUPIDFeatureStateRequest;
			class GetUPIDFeatureStateCommand : public UPIDCommand
			{
			public:

				GetUPIDFeatureStateCommand();
				virtual ~GetUPIDFeatureStateCommand() {}

				UPID_PLATFORM_ID_FEATURE_STATE_GET_Response getResponse();

			private:
				virtual void parseResponse(const std::vector<uint8_t>& buffer);

				std::shared_ptr<UPIDCommandResponse<UPID_PLATFORM_ID_FEATURE_STATE_GET_Response>> m_response;
			};


			class GetUPIDFeatureStateRequest : public UPIDRequest
			{
			public:
				GetUPIDFeatureStateRequest() {}
				virtual ~GetUPIDFeatureStateRequest() {}

			private:
				virtual uint8_t requestHeaderFeatureID()
				{
					return UPID_COMMAND_FEATURE_PLATFORM_ID;
				}
				virtual uint8_t requestHeaderCommandID()
				{
					return UPID_COMMAND_PLATFORM_ID_FEATURE_STATE_GET;
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

#endif //__GET_UPID_FEATURE_STATE_COMMAND_H__