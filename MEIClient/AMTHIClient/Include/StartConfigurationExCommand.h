/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2010-2019 Intel Corporation
 */
/*++

@file: StartConfigurationExCommand.h

--*/

#ifndef __START_CONFIGURATION_EX_COMMAND_H__
#define __START_CONFIGURATION_EX_COMMAND_H__

#include "AMTHICommand.h"

namespace Intel
{
	namespace MEI_Client
	{
		namespace AMTHI_Client
		{
			struct START_CONFIGURATION_EX_RESPONSE
			{
				void parse (std::vector<uint8_t>::const_iterator& /*itr*/, const std::vector<uint8_t>::const_iterator& /*end*/)
				{
					return;
				}
			};

			class StartConfigurationExRequest;
			class StartConfigurationExCommand : public AMTHICommand
			{
			public:

				StartConfigurationExCommand(bool IPv6Enable);
				virtual ~StartConfigurationExCommand() {}
				virtual void reTransact(bool IPv6Enable);
				START_CONFIGURATION_EX_RESPONSE getResponse();

			private:
				virtual void parseResponse(const std::vector<uint8_t>& buffer);

				std::shared_ptr<AMTHICommandResponse<START_CONFIGURATION_EX_RESPONSE>> m_response;

				static const uint32_t RESPONSE_COMMAND_NUMBER = 0x04800062;
			};

			class StartConfigurationExRequest : public AMTHICommandRequest
			{
			public:
				StartConfigurationExRequest(bool IPv6Enable) : _IPv6Enable(IPv6Enable ? AMT_TRUE : AMT_FALSE){}
				virtual ~StartConfigurationExRequest() {}

			private:
				static const uint32_t REQUEST_COMMAND_NUMBER = 0x04000062;
				virtual unsigned int requestHeaderCommandNumber()
				{
					//this is the command number (taken from the AMTHI document)
					return REQUEST_COMMAND_NUMBER;
				}

				virtual uint32_t requestDataSize()
				{
					return sizeof(AMT_BOOLEAN);
				}
				virtual std::vector<uint8_t> SerializeData();
				AMT_BOOLEAN _IPv6Enable;
			};
		} // namespace AMTHI_Client
	} // namespace MEI_Client
} // namespace Intel

#endif //__START_CONFIGURATION_EX_COMMAND_H__