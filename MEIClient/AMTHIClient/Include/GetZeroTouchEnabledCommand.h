/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2010-2019 Intel Corporation
 */
/*++

@file: GetZeroTouchEnabledCommand.h

--*/

#ifndef __GET_ZERO_TOUCH_ENABLED_COMMAND_H__
#define __GET_ZERO_TOUCH_ENABLED_COMMAND_H__

#include "AMTHICommand.h"
#include "MEIparser.h"

namespace Intel
{
	namespace MEI_Client
	{
		namespace AMTHI_Client
		{
			struct ZTC_ENABLED_STATUS
			{
				bool ZTCEnabled;
				void parse (std::vector<uint8_t>::const_iterator& itr, const std::vector<uint8_t>::const_iterator end)
				{
					Intel::MEI_Client::parseData (ZTCEnabled,itr,end);
				}
			};

			class GetZeroTouchEnabledRequest;
			class GetZeroTouchEnabledCommand : public AMTHICommand
			{
			public:

				GetZeroTouchEnabledCommand();
				virtual ~GetZeroTouchEnabledCommand() {}

				ZTC_ENABLED_STATUS getResponse();

			private:
				virtual void parseResponse(const std::vector<uint8_t>& buffer);

				std::shared_ptr<AMTHICommandResponse<ZTC_ENABLED_STATUS>> m_response;

				static const uint32_t RESPONSE_COMMAND_NUMBER = 0x04800030;
			};

			class GetZeroTouchEnabledRequest : public AMTHICommandRequest
			{
			public:
				GetZeroTouchEnabledRequest(){}
				virtual ~GetZeroTouchEnabledRequest() {}

			private:
				static const uint32_t REQUEST_COMMAND_NUMBER = 0x04000030;
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

#endif // __GET_ZERO_TOUCH_ENABLED_COMMAND_H__