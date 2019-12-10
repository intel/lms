/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2010-2019 Intel Corporation
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
				uint32_t Resrved :29;
			};

			struct REDIRECTION_STATE
			{
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

			class GetRedirectionStateRequest;
			class GetRedirectionStateCommand : public AMTHICommand
			{
			public:
				GetRedirectionStateCommand();
				virtual ~GetRedirectionStateCommand() {}

				REDIRECTION_STATE getResponse();

			private:
				virtual void parseResponse(const std::vector<uint8_t>& buffer);

				std::shared_ptr<AMTHICommandResponse<REDIRECTION_STATE>> m_response;
				static const uint32_t RESPONSE_COMMAND_NUMBER = 0x04800058;

			};

			class GetRedirectionStateRequest : public AMTHICommandRequest
			{
			public:
				GetRedirectionStateRequest() {}
				virtual ~GetRedirectionStateRequest() {}

			private:
				static const uint32_t REQUEST_COMMAND_NUMBER = 0x04000058;
				virtual unsigned int requestHeaderCommandNumber()
				{
					//this is the command number (taken from the AMTHI document)
					return REQUEST_COMMAND_NUMBER;
				}

				virtual uint32_t requestDataSize()
				{
					return 0;
				}
			};
		} // namespace AMTHI_Client
	} // namespace MEI_Client
} // namespace Intel

#endif //__GET_REDIRECTION_STATE_COMMAND_H__