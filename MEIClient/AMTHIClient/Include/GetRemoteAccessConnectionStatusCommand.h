/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2010-2023 Intel Corporation
 */
/*++

@file: GetRemoteAccessConnectionStatusCommand.h

--*/

#ifndef __GET_REMOTE_ACCESS_CONNECTION_STATUS_COMMAND_H__
#define __GET_REMOTE_ACCESS_CONNECTION_STATUS_COMMAND_H__

#include "AMTHICommand.h"
#include "MEIparser.h"
#include "AmtAnsiString.h"

namespace Intel
{
	namespace MEI_Client
	{
		namespace AMTHI_Client
		{
			typedef enum
			{
				AMT_NETWORK_CONNECTION_DIRECT=0,
				AMT_NETWORK_CONNECTION_VPN,
				AMT_NETWORK_CONNECTION_OUTSIDE_ENTERPRISE,
				AMT_NETWORK_CONNECTION_UNKNOWN
			} AMT_NETWORK_CONNECTION_STATUS;

			typedef enum
			{
				REMOTE_ACCESS_CONNECTION_STATUS_NOT_CONNECTED=0,
				REMOTE_ACCESS_CONNECTION_STATUS_CONNECTING,
				REMOTE_ACCESS_CONNECTION_STATUS_CONNECTED
			} REMOTE_ACCESS_CONNECTION_STATUS;

			typedef enum
			{
				REMOTE_ACCESS_CONNECTION_TRIGGER_USER_INITIATED=0,
				REMOTE_ACCESS_CONNECTION_TRIGGER_ALERT,
				REMOTE_ACCESS_CONNECTION_TRIGGER_PROVISIONING,
				REMOTE_ACCESS_CONNECTION_TRIGGER_PERIODIC,
			} REMOTE_ACCESS_CONNECTION_TRIGGER;

			//Response struct:
			struct REMOTE_ACCESS_STATUS
			{
				REMOTE_ACCESS_STATUS() : AmtNetworkConnectionStatus(AMT_NETWORK_CONNECTION_DIRECT),
					RemoteAccessConnectionStatus(REMOTE_ACCESS_CONNECTION_STATUS_NOT_CONNECTED),
					RemoteAccessConnectionTrigger(REMOTE_ACCESS_CONNECTION_TRIGGER_USER_INITIATED) {}
				AMT_NETWORK_CONNECTION_STATUS AmtNetworkConnectionStatus;
				REMOTE_ACCESS_CONNECTION_STATUS RemoteAccessConnectionStatus;
				REMOTE_ACCESS_CONNECTION_TRIGGER RemoteAccessConnectionTrigger;
				std::string MpsHostname; 

				void parse (std::vector<uint8_t>::const_iterator &itr, const std::vector<uint8_t>::const_iterator &end) 
				{
					
					Intel::MEI_Client::parseData(AmtNetworkConnectionStatus, itr, end);
					Intel::MEI_Client::parseData(RemoteAccessConnectionStatus, itr, end);
					Intel::MEI_Client::parseData(RemoteAccessConnectionTrigger, itr, end);
					MpsHostname = AmtAnsiString(itr, end).getString();
				}
			};

			class GetRemoteAccessConnectionStatusRequest : public AMTHICommandRequest
			{
			public:
				GetRemoteAccessConnectionStatusRequest() : AMTHICommandRequest(REQUEST_COMMAND_NUMBER) {}
				virtual ~GetRemoteAccessConnectionStatusRequest() {}

			private:
				static const uint32_t REQUEST_COMMAND_NUMBER = 0x04000046;
			};

			class GetRemoteAccessConnectionStatusCommand : public AMTHICommand
			{
			public:

				GetRemoteAccessConnectionStatusCommand()
				{
					m_request = std::make_shared<GetRemoteAccessConnectionStatusRequest>();
					Transact();
				}
				virtual ~GetRemoteAccessConnectionStatusCommand() {}

				REMOTE_ACCESS_STATUS getResponse() { return m_response.getResponse(); }

			private:
				virtual void parseResponse(const std::vector<uint8_t>& buffer)
				{
					m_response = AMTHICommandResponse<REMOTE_ACCESS_STATUS>(buffer, RESPONSE_COMMAND_NUMBER);
				}

				AMTHICommandResponse<REMOTE_ACCESS_STATUS> m_response;

				static const uint32_t RESPONSE_COMMAND_NUMBER = 0x04800046;
			};
		} // namespace AMTHI_Client
	} // namespace MEI_Client
} // namespace Intel

#endif //__GET_REMOTE_ACCESS_CONNECTION_STATUS_COMMAND_H__