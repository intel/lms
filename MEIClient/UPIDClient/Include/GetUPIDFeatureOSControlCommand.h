/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2020-2023 Intel Corporation
 */
/*++

@file: GetUPIDFeatureOSControl.h

--*/

#ifndef __GET_UPID_FEATURE_OSCONTROL_COMMAND_H__
#define __GET_UPID_FEATURE_OSCONTROL_COMMAND_H__

#include "UPIDCommand.h"
#include "MEIparser.h"

namespace Intel
{
	namespace MEI_Client
	{
		namespace UPID_Client
		{
			struct UPID_PLATFORM_ID_FEATURE_OSCONTROL_GET_Response
			{
				UPID_PLATFORM_ID_FEATURE_OSCONTROL_GET_Response() : OsControlEnabled(0) {}
				uint8_t OsControlEnabled;

				void parse(std::vector<uint8_t>::const_iterator& itr, const std::vector<uint8_t>::const_iterator &end)
				{
					parseData(OsControlEnabled, itr, end);
				}
			};

			class GetUPIDFeatureOSControlRequest : public UPIDRequest
			{
			public:
				GetUPIDFeatureOSControlRequest() :
					UPIDRequest(UPID_COMMAND_FEATURE_PLATFORM_ID, UPID_COMMAND_PLATFORM_ID_FEATURE_STATE_OS_CONTROL_GET) {}
				virtual ~GetUPIDFeatureOSControlRequest() {}
			};

			class GetUPIDFeatureOSControlCommand : public UPIDCommand
			{
			public:

				GetUPIDFeatureOSControlCommand()
				{
					m_request = std::make_shared<GetUPIDFeatureOSControlRequest>();
					Transact();
				}
				virtual ~GetUPIDFeatureOSControlCommand() {}

				UPID_PLATFORM_ID_FEATURE_OSCONTROL_GET_Response getResponse() { return m_response.getResponse(); }

			private:
				virtual void parseResponse(const std::vector<uint8_t>& buffer)
				{
					m_response = UPIDCommandResponse<UPID_PLATFORM_ID_FEATURE_OSCONTROL_GET_Response>(buffer, UPID_COMMAND_FEATURE_PLATFORM_ID, UPID_COMMAND_PLATFORM_ID_FEATURE_STATE_OS_CONTROL_GET);
				}

				UPIDCommandResponse<UPID_PLATFORM_ID_FEATURE_OSCONTROL_GET_Response> m_response;
			};
		} // namespace UPID_Client
	} // namespace MEI_Client
} // namespace Intel

#endif //__GET_UPID_FEATURE_OSCONTROL_COMMAND_H__