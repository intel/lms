/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2020-2023 Intel Corporation
 */
/*++

@file: SetUPIDFeatureStateCommand.h

--*/

#ifndef __SET_UPID_FEATURE_STATE_COMMAND_H__
#define __SET_UPID_FEATURE_STATE_COMMAND_H__

#include "UPIDCommand.h"
#include "MEIparser.h"

namespace Intel
{
	namespace MEI_Client
	{
		namespace UPID_Client
		{
			struct UPID_PLATFORM_ID_FEATURE_STATE_SET_Response
			{
				void parse(std::vector<uint8_t>::const_iterator&, const std::vector<uint8_t>::const_iterator&)
				{
					return;
				}
			};

			typedef struct
			{
				uint8_t         featureState;
			}  UPID_PLATFORM_ID_FEATURE_STATE_SET_Request;

			class SetUPIDFeatureStateRequest : public UPIDRequest
			{
			public:
				SetUPIDFeatureStateRequest(bool featureState) :
					UPIDRequest(UPID_COMMAND_FEATURE_PLATFORM_ID, UPID_COMMAND_PLATFORM_ID_FEATURE_STATE_SET), _featureState(featureState) {}
				virtual ~SetUPIDFeatureStateRequest() {}

			private:
				virtual uint16_t requestDataSize()
				{
					return sizeof(UPID_PLATFORM_ID_FEATURE_STATE_SET_Request);
				}
				virtual std::vector<uint8_t> SerializeData()
				{
					return std::vector<uint8_t>((std::uint8_t*)&_featureState, (std::uint8_t*)&_featureState + sizeof(_featureState));
				}
				bool _featureState;
			};

			class SetUPIDFeatureStateCommand : public UPIDCommand
			{
			public:

				SetUPIDFeatureStateCommand(bool featureState)
				{
					m_request = std::make_shared<SetUPIDFeatureStateRequest>(featureState);
					Transact();
				}
				virtual ~SetUPIDFeatureStateCommand() {}

				UPID_PLATFORM_ID_FEATURE_STATE_SET_Response getResponse() { return m_response.getResponse(); }

			private:
				virtual void parseResponse(const std::vector<uint8_t>& buffer)
				{
					m_response = UPIDCommandResponse<UPID_PLATFORM_ID_FEATURE_STATE_SET_Response>(buffer, UPID_COMMAND_FEATURE_PLATFORM_ID, UPID_COMMAND_PLATFORM_ID_FEATURE_STATE_SET);
				}

				UPIDCommandResponse<UPID_PLATFORM_ID_FEATURE_STATE_SET_Response> m_response;
			};
		} // namespace UPID_Client
	} // namespace MEI_Client
} // namespace Intel

#endif //__SET_UPID_FEATURE_STATE_COMMAND_H__