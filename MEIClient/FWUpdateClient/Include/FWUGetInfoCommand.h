/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2010-2019 Intel Corporation
 */
/*++

@file: FWUGetInfoCommand.h

--*/

#ifndef __FWU_GET_INFO_COMMAND_H__
#define __FWU_GET_INFO_COMMAND_H__

#include "FWUpdateCommand.h"
#include "MEIparser.h"

namespace Intel
{
	namespace MEI_Client
	{
		namespace FWUpdate_Client
		{
			struct GET_INFO_RESPONSE
			{
				FWU_VERSION       MEBxVersion;
				unsigned int      FlashOverridePolicy;
				unsigned int      MangeabilityMode;
				unsigned int      BiosBootState;
				struct {
				 unsigned int    CryptoFuse   :1;
				 unsigned int    FlashProtection:1;
				 unsigned int    FwOverrideQualifier:2;
				 unsigned int    MeResetReason:2; 
				 unsigned int    FwOverrideCounter:8;
				 unsigned int    reserved:18;
				} Fields;
				uint8_t             BiosVersion[20];


				void parse (std::vector<uint8_t>::const_iterator &itr, const std::vector<uint8_t>::const_iterator end)
				{
					Intel::MEI_Client::parseData(*this, itr, end);
				}
			};

			class FWUGetInfoRequest;
			class FWUGetInfoCommand : public FWUpdateCommand
			{
			public:

				FWUGetInfoCommand();
				virtual ~FWUGetInfoCommand() {}
				virtual void reTransact();
				GET_INFO_RESPONSE getResponse();

			private:
				virtual void parseResponse(const std::vector<uint8_t>& buffer);

				std::shared_ptr<FWUpdateCommandResponse<GET_INFO_RESPONSE>> m_response;
				static const uint32_t RESPONSE_COMMAND_NUMBER = 0x09;
			};

			class FWUGetInfoRequest : public FWUpdateCommandRequest
			{
			public:
				FWUGetInfoRequest(){}
				virtual ~FWUGetInfoRequest() {}

			private:
				static const uint32_t REQUEST_COMMAND_NUMBER = 0x08;
				virtual unsigned int requestHeaderMessageID()
				{
					//this is the command number (taken from the AMTHI document)
					return REQUEST_COMMAND_NUMBER;
				}

				virtual std::vector<uint8_t> SerializeData();
			};
		} // namespace FWUpadate_Client
	} // namespace MEI_Client
} // namespace Intel

#endif //__FWU_GET_INFO_COMMAND_H__