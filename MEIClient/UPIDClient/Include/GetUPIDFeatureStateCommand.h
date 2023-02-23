/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2020-2023 Intel Corporation
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
			struct UPID_PLATFORM_ID_FEATURE_STATE_GET_Response
			{
				UPID_PLATFORM_ID_FEATURE_STATE_GET_Response() : FeatureEnabled(0) {}
				uint8_t                              FeatureEnabled;

				void parse(std::vector<uint8_t>::const_iterator& itr, const std::vector<uint8_t>::const_iterator &end)
				{
					parseData(FeatureEnabled, itr, end);
				}
			};

			class GetUPIDFeatureStateCommand : public UPIDCommand
			{
			public:

				GetUPIDFeatureStateCommand();
				virtual ~GetUPIDFeatureStateCommand() {}

				UPID_PLATFORM_ID_FEATURE_STATE_GET_Response getResponse();

			private:
				virtual void parseResponse(const std::vector<uint8_t>& buffer);

				UPIDCommandResponse<UPID_PLATFORM_ID_FEATURE_STATE_GET_Response> m_response;
			};


			class GetUPIDFeatureStateRequest : public UPIDRequest
			{
			public:
				GetUPIDFeatureStateRequest() :
					UPIDRequest(UPID_COMMAND_FEATURE_PLATFORM_ID, UPID_COMMAND_PLATFORM_ID_FEATURE_STATE_GET) {}
				virtual ~GetUPIDFeatureStateRequest() {}
			};
		} // namespace UPID_Client
	} // namespace MEI_Client
} // namespace Intel

#endif //__GET_UPID_FEATURE_STATE_COMMAND_H__