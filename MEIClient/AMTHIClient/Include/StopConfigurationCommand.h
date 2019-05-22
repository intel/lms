/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2010-2019 Intel Corporation
 */
/*++

@file: StopConfigurationCommand.h

--*/

#ifndef __STOP_CONFIGURATION_COMMAND_H__
#define __STOP_CONFIGURATION_COMMAND_H__

#include "AMTHICommand.h"

namespace Intel
{
	namespace MEI_Client
	{
		namespace AMTHI_Client
		{
			struct StopConfig_RESPONSE
			{
				void parse (std::vector<uint8_t>::const_iterator& , const std::vector<uint8_t>::const_iterator )
				{
					return;
				}
			};

			class StopConfigurationRequest;
			class StopConfigurationCommand : public AMTHICommand
			{
			public:

				StopConfigurationCommand();
				virtual ~StopConfigurationCommand() {}

				virtual void reTransact();

			private:
				virtual void parseResponse(const std::vector<uint8_t>& buffer);

				std::shared_ptr<AMTHICommandResponse<StopConfig_RESPONSE>> m_response;

				static const uint32_t RESPONSE_COMMAND_NUMBER = 0x0480005E;
			};

			class StopConfigurationRequest : public AMTHICommandRequest
			{
			public:
				StopConfigurationRequest() {}
				virtual ~StopConfigurationRequest() {}

			private:
				static const uint32_t REQUEST_COMMAND_NUMBER = 0x0400005E;
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

#endif //__STOP_CONFIGURATION_COMMAND_H__