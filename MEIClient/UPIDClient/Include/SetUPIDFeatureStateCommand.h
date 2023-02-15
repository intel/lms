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
			typedef struct _UPID_PLATFORM_ID_FEATURE_STATE_SET_Response
			{
				void parse(std::vector<uint8_t>::const_iterator&, const std::vector<uint8_t>::const_iterator&)
				{
					return;
				}
			}  UPID_PLATFORM_ID_FEATURE_STATE_SET_Response;


			typedef struct
			{
				uint8_t         featureState;
			}  UPID_PLATFORM_ID_FEATURE_STATE_SET_Request;

			class SetUPIDFeatureStateCommand : public UPIDCommand
			{
			public:

				SetUPIDFeatureStateCommand(bool fetaureState);
				virtual ~SetUPIDFeatureStateCommand() {}

				UPID_PLATFORM_ID_FEATURE_STATE_SET_Response getResponse();

			private:
				virtual void parseResponse(const std::vector<uint8_t>& buffer);

				std::shared_ptr<UPIDCommandResponse<UPID_PLATFORM_ID_FEATURE_STATE_SET_Response>> m_response;
			};


			class SetUPIDFeatureStateRequest : public UPIDRequest
			{
			public:
				SetUPIDFeatureStateRequest(bool featureState) : _featureState(featureState) {}
				virtual ~SetUPIDFeatureStateRequest() {}

			private:
				virtual uint8_t requestHeaderFeatureID()
				{
					return UPID_COMMAND_FEATURE_PLATFORM_ID;
				}
				virtual uint8_t requestHeaderCommandID()
				{
					return UPID_COMMAND_PLATFORM_ID_FEATURE_STATE_SET;
				}
				virtual uint16_t requestDataSize()
				{
					return sizeof(UPID_PLATFORM_ID_FEATURE_STATE_SET_Request);
				}
				virtual std::vector<uint8_t> SerializeData();
				bool _featureState;

			};
		} // namespace UPID_Client
	} // namespace MEI_Client
} // namespace Intel

#endif //__SET_UPID_FEATURE_STATE_COMMAND_H__