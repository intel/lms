/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2010-2019 Intel Corporation
 */
/*++

@file: GetUserInitiatedEnabledInterfacesCommand.h

--*/

#ifndef __GET_USER_INITIATED_ENABLED_INTERFACES_COMMAND_H__
#define __GET_USER_INITIATED_ENABLED_INTERFACES_COMMAND_H__

#include "AMTHICommand.h"
#include "MEIparser.h"

namespace Intel
{
	namespace MEI_Client
	{
		namespace AMTHI_Client
		{
			typedef struct _EnabledInterfacesFields
			{
				uint32_t          Bios   :1;
				uint32_t          OS_Agent :1;
				uint32_t          reserved: 30;
			} EnabledInterfacesFields;
			struct GET_USER_INITIATED_ENABLED_INTERFACES_RESPONSE
			{
				EnabledInterfacesFields EnabledInterfaces;
				void parse (std::vector<uint8_t>::const_iterator& itr, const std::vector<uint8_t>::const_iterator end)
				{
					Intel::MEI_Client::parseData(EnabledInterfaces, itr, end);
				}
			};

			class GetUserInitiatedEnabledInterfacesRequest;
			class GetUserInitiatedEnabledInterfacesCommand : public AMTHICommand
			{
			public:

				GetUserInitiatedEnabledInterfacesCommand();
				virtual ~GetUserInitiatedEnabledInterfacesCommand() {}

				virtual void reTransact();
				GET_USER_INITIATED_ENABLED_INTERFACES_RESPONSE getResponse();

			private:
				virtual void parseResponse(const std::vector<uint8_t>& buffer);

				std::shared_ptr<AMTHICommandResponse<GET_USER_INITIATED_ENABLED_INTERFACES_RESPONSE>> m_response;

				static const uint32_t RESPONSE_COMMAND_NUMBER = 0x0480004D;
			};

			class GetUserInitiatedEnabledInterfacesRequest : public AMTHICommandRequest
			{
			public:
				GetUserInitiatedEnabledInterfacesRequest() {}
				virtual ~GetUserInitiatedEnabledInterfacesRequest() {}

			private:
				static const uint32_t REQUEST_COMMAND_NUMBER = 0x0400004D;
				virtual unsigned int requestHeaderCommandNumber()
				{
					//this is the command number (taken from the AMTHI document)
					return REQUEST_COMMAND_NUMBER;
				}

				virtual uint32_t requestDataSize()
				{
					return 0;
				}
				virtual std::vector<uint8_t> SerializeData();
			};
		} // namespace AMTHI_Client
	} // namespace MEI_Client
} // namespace Intel

#endif //__GET_USER_INITIATED_ENABLED_INTERFACES_COMMAND_H__