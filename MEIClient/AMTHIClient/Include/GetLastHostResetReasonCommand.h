/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2010-2023 Intel Corporation
 */
/*++

@file: GetLastHostResetReasonCommand.h

--*/

#ifndef __GET_LAST_HOST_RESET_REASON_COMMAND_H__
#define __GET_LAST_HOST_RESET_REASON_COMMAND_H__

#include "AMTHICommand.h"
#include "MEIparser.h"

namespace Intel
{
	namespace MEI_Client
	{
		namespace AMTHI_Client
		{
			struct LAST_HOST_RESET_REASON_RESPONSE
			{
				LAST_HOST_RESET_REASON_RESPONSE() : Reason(0), RemoteControlTimeStamp(0) {}
				uint32_t Reason;
				uint32_t RemoteControlTimeStamp;
				
				void parse (std::vector<uint8_t>::const_iterator& itr, const std::vector<uint8_t>::const_iterator end)
				{
					Intel::MEI_Client::parseData(*this,itr,end);
				}
			};

			class GetLastHostResetReasonCommand : public AMTHICommand
			{
			public:

				GetLastHostResetReasonCommand();
				virtual ~GetLastHostResetReasonCommand() {}

				LAST_HOST_RESET_REASON_RESPONSE getResponse();

			private:
				virtual void parseResponse(const std::vector<uint8_t>& buffer);

				AMTHICommandResponse<LAST_HOST_RESET_REASON_RESPONSE> m_response;

				static const uint32_t RESPONSE_COMMAND_NUMBER = 0x0480004A;
			};

			class GetLastHostResetReasonRequest : public AMTHICommandRequest
			{
			public:
				GetLastHostResetReasonRequest() : AMTHICommandRequest(REQUEST_COMMAND_NUMBER) {}
				virtual ~GetLastHostResetReasonRequest() {}

			private:
				static const uint32_t REQUEST_COMMAND_NUMBER = 0x0400004A;
			};
		} // namespace AMTHI_Client
	} // namespace MEI_Client
} // namespace Intel

#endif //__GET_LAST_HOST_RESET_REASON_COMMAND_H__