/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2010-2023 Intel Corporation
 */
/*++

@file: GetWebUIStateCommand.h

--*/

#ifndef __GET_WEB_UI_STATE_COMMAND_H__
#define __GET_WEB_UI_STATE_COMMAND_H__

#include "AMTHICommand.h"
#include "MEIparser.h"

namespace Intel
{
	namespace MEI_Client
	{
		namespace AMTHI_Client
		{
			struct GET_WEB_UI_STATE_RESPONSE
			{
				GET_WEB_UI_STATE_RESPONSE() : RequestId(0), WebUiEnabled(AMT_FALSE) {}
				uint32_t RequestId;
				AMT_BOOLEAN WebUiEnabled;
			
				void parse (std::vector<uint8_t>::const_iterator &itr, const std::vector<uint8_t>::const_iterator &end)
				{
					parseData(RequestId, itr, end);
					parseData(WebUiEnabled, itr, end); 
				}
			};

			class GetWebUIStateRequest : public AMTHICommandRequest
			{
			public:
				GetWebUIStateRequest() : AMTHICommandRequest(REQUEST_COMMAND_NUMBER) {}
				virtual ~GetWebUIStateRequest() {}

			private:
				static const uint32_t WEB_UI_STATE_ID = 2;
				static const uint32_t REQUEST_COMMAND_NUMBER = 0x04000049;

				virtual uint32_t requestDataSize()
				{
					return sizeof(uint32_t);
				}
				virtual std::vector<uint8_t> SerializeData()
				{
					uint32_t id = WEB_UI_STATE_ID;
					std::vector<uint8_t> output((std::uint8_t*)&id, (std::uint8_t*)&id + sizeof(uint32_t));
					return output;
				}
			};

			class GetWebUIStateCommand : public AMTHICommand
			{
			public:

				GetWebUIStateCommand()
				{
					m_request = std::make_shared<GetWebUIStateRequest>();
					Transact();
				}
				virtual ~GetWebUIStateCommand() {}

				GET_WEB_UI_STATE_RESPONSE getResponse() { return m_response.getResponse(); }

			private:
				virtual void parseResponse(const std::vector<uint8_t>& buffer)
				{
					m_response = AMTHICommandResponse<GET_WEB_UI_STATE_RESPONSE>(buffer, RESPONSE_COMMAND_NUMBER);
				}

				AMTHICommandResponse<GET_WEB_UI_STATE_RESPONSE> m_response;

				static const uint32_t RESPONSE_COMMAND_NUMBER = 0x04800049;
			};
		} // namespace AMTHI_Client
	} // namespace MEI_Client
} // namespace Intel

#endif //__GET_WEB_UI_STATE_COMMAND_H__