/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2010-2019 Intel Corporation
 */
/*++

@file: UnprovisionCommand.h

--*/

#ifndef __UNPROVISION_COMMAND_H__
#define __UNPROVISION_COMMAND_H__

#include "AMTHICommand.h"
#include "MEIparser.h"


namespace Intel
{
	namespace MEI_Client
	{
		namespace AMTHI_Client
		{
			struct Unprovision_RESPONSE
			{
				void parse (std::vector<uint8_t>::const_iterator& , const std::vector<uint8_t>::const_iterator)
				{
					return;
				}
			};

			class UnprovisionRequest;
			class UnprovisionCommand : public AMTHICommand
			{
			public:

				UnprovisionCommand(const CFG_PROVISIONING_MODE Mode);
				virtual ~UnprovisionCommand() {}

			private:
				virtual void parseResponse(const std::vector<uint8_t>& buffer);

				std::shared_ptr<AMTHICommandResponse<Unprovision_RESPONSE>> m_response;

				static const uint32_t RESPONSE_COMMAND_NUMBER = 0x04800010;
			};

			class UnprovisionRequest : public AMTHICommandRequest
			{
			public:
				UnprovisionRequest(const CFG_PROVISIONING_MODE Mode):m_mode(Mode) {}
				virtual ~UnprovisionRequest() {}		

			private:
				CFG_PROVISIONING_MODE m_mode;
				static const uint32_t REQUEST_COMMAND_NUMBER = 0x04000010;
				virtual unsigned int requestHeaderCommandNumber()
				{
					//this is the command number (taken from the AMTHI document)
					return REQUEST_COMMAND_NUMBER;
				}

				virtual uint32_t requestDataSize()
				{
					return sizeof(uint32_t);
				}
				virtual std::vector<uint8_t> SerializeData();
			};
		} // namespace AMTHI_Client
	} // namespace MEI_Client
} // namespace Intel

#endif //#define __UNPROVISION_COMMAND_H__