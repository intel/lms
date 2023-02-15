/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2010-2023 Intel Corporation
 */
/*++

@file: SetEnterpriseAccessCommand.h

--*/

#ifndef __SET_ENTERPRISE_ACCESS_COMMAND_H__
#define __SET_ENTERPRISE_ACCESS_COMMAND_H__

#include "AMTHICommand.h"
#include "MEIparser.h"

namespace Intel
{
	namespace MEI_Client
	{
		namespace AMTHI_Client
		{
			struct SetEnterpriseAccess_RESPONSE
			{
				void parse (std::vector<uint8_t>::const_iterator& , const std::vector<uint8_t>::const_iterator)
				{
					return;
				}
			};

			const static uint32_t HOST_IP_ADDRESS_SIZE = 16;

			class SetEnterpriseAccessCommand : public AMTHICommand
			{
			public:

				SetEnterpriseAccessCommand(uint8_t Flags, const std::vector<uint8_t> &HostIPAddress, uint8_t EnterpiseAccess);
				virtual ~SetEnterpriseAccessCommand() {}

				SetEnterpriseAccess_RESPONSE getResponse();

			private:
				virtual void parseResponse(const std::vector<uint8_t>& buffer);

				std::shared_ptr<AMTHICommandResponse<SetEnterpriseAccess_RESPONSE>> m_response;

				static const uint32_t RESPONSE_COMMAND_NUMBER = 0x0480003F;
			};

			class SetEnterpriseAccessRequest : public AMTHICommandRequest
			{
			public:
				SetEnterpriseAccessRequest(uint8_t Flags, const std::vector<uint8_t> &HostIPAddress, uint8_t EnterpiseAccess);
				SetEnterpriseAccessRequest(const SetEnterpriseAccessRequest&) = delete;
				SetEnterpriseAccessRequest& operator = (const SetEnterpriseAccessRequest&) = delete;
				virtual ~SetEnterpriseAccessRequest() {}

			private:
				static const uint32_t REQUEST_COMMAND_NUMBER = 0x0400003F;
				virtual unsigned int requestHeaderCommandNumber()
				{
					//this is the command number (taken from the AMTHI document)
					return REQUEST_COMMAND_NUMBER;
				}

				virtual uint32_t requestDataSize()
				{
					return sizeof(uint8_t) + sizeof(uint8_t) * HOST_IP_ADDRESS_SIZE + sizeof(uint8_t);
				}
				virtual std::vector<uint8_t> SerializeData();

				uint8_t _Flags;
				std::vector<uint8_t> _HostIPAddress;
				uint8_t _EnterpiseAccess;
			};
		} // namespace AMTHI_Client
	} // namespace MEI_Client
} // namespace Intel

#endif //__SET_ENTERPRISE_ACCESS_COMMAND_H__