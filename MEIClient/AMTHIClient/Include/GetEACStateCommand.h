/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2010-2023 Intel Corporation
 */
/*++

@file: GetEACStateCommand.h

--*/

#ifndef __GET_EAC_STATE_COMMAND_H__
#define __GET_EAC_STATE_COMMAND_H__

#include "AMTHICommand.h"
#include "MEIparser.h"

namespace Intel
{
	namespace MEI_Client
	{
		namespace AMTHI_Client
		{
			struct GET_EAC_STATE_RESPONSE
			{
				GET_EAC_STATE_RESPONSE() : RequestId(0), EacEnabled(AMT_FALSE) {}
				uint32_t RequestId;
				AMT_BOOLEAN EacEnabled;

				void parse (std::vector<uint8_t>::const_iterator &itr, const std::vector<uint8_t>::const_iterator &end)
				{
					Intel::MEI_Client::parseData(RequestId, itr, end);
					Intel::MEI_Client::parseData(EacEnabled, itr, end);
				}
			};

			class GetEACStateCommand : public AMTHICommand
			{
			public:

				GetEACStateCommand();
				virtual ~GetEACStateCommand() {}

				GET_EAC_STATE_RESPONSE getResponse();

			private:
				virtual void parseResponse(const std::vector<uint8_t>& buffer);

				AMTHICommandResponse<GET_EAC_STATE_RESPONSE> m_response;

				static const uint32_t RESPONSE_COMMAND_NUMBER = 0x04800049;
			};

			class GetEACStateRequest : public AMTHICommandRequest
			{
			public:
				GetEACStateRequest() : AMTHICommandRequest(REQUEST_COMMAND_NUMBER) {}
				virtual ~GetEACStateRequest() {}

			private:
				static const uint32_t EAC_ID  = 3;
				static const uint32_t REQUEST_COMMAND_NUMBER = 0x04000049;

				virtual uint32_t requestDataSize()
				{
					return sizeof(uint32_t);
				}
				virtual std::vector<uint8_t> SerializeData();
			};
		} // namespace AMTHI_Client
	} // namespace MEI_Client
} // namespace Intel

#endif //__GET_EAC_STATE_COMMAND_H__