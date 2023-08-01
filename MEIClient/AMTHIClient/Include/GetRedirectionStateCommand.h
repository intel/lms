/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2010-2023 Intel Corporation
 */
/*++

@file: GetRedirectionStateCommand.h

--*/

#ifndef __GET_REDIRECTION_STATE_COMMAND_H__
#define __GET_REDIRECTION_STATE_COMMAND_H__

#include "AMTHICommand.h"
#include "MEIparser.h"

namespace Intel
{
	namespace MEI_Client
	{
		namespace AMTHI_Client
		{
			struct REDIRECTION_FEATURES
			{
				uint32_t SOLEnabled :1;
				uint32_t IDEREnabled :1;
				uint32_t KVMEnabled :1;
				uint32_t Reserved :29;
			};

			struct REDIRECTION_STATE
			{
				REDIRECTION_STATE() : SOLEnabled(false), IDEREnabled(false), KVMEnabled(false) {}
				bool SOLEnabled;
				bool IDEREnabled;
				bool KVMEnabled;

				void parse (std::vector<uint8_t>::const_iterator& itr, const std::vector<uint8_t>::const_iterator end)
				{
					REDIRECTION_FEATURES RedirectionFeaturesState;
					Intel::MEI_Client::parseData (RedirectionFeaturesState,itr,end);
					SOLEnabled = RedirectionFeaturesState.SOLEnabled;
					IDEREnabled = RedirectionFeaturesState.IDEREnabled;
					KVMEnabled = RedirectionFeaturesState.KVMEnabled;
				}
			};

			class GetRedirectionStateRequest : public AMTHICommandRequest
			{
			public:
				GetRedirectionStateRequest() : AMTHICommandRequest(REQUEST_COMMAND_NUMBER) {}
				virtual ~GetRedirectionStateRequest() {}

			private:
				static const uint32_t REQUEST_COMMAND_NUMBER = 0x04000058;
			};

			class GetRedirectionStateCommand : public AMTHICommand
			{
			public:
				GetRedirectionStateCommand()
				{
					m_request = std::make_shared<GetRedirectionStateRequest>();
					Transact();
				}
				virtual ~GetRedirectionStateCommand() {}

				REDIRECTION_STATE getResponse() { return m_response.getResponse(); }

			private:
				virtual void parseResponse(const std::vector<uint8_t>& buffer)
				{
					m_response = AMTHICommandResponse<REDIRECTION_STATE>(buffer, RESPONSE_COMMAND_NUMBER);
				}

				AMTHICommandResponse<REDIRECTION_STATE> m_response;
				static const uint32_t RESPONSE_COMMAND_NUMBER = 0x04800058;

			};
		} // namespace AMTHI_Client
	} // namespace MEI_Client
} // namespace Intel

#endif //__GET_REDIRECTION_STATE_COMMAND_H__
