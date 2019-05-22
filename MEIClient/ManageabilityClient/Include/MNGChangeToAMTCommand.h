/*++
/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2010-2019 Intel Corporation
 */
/*++

@file: MNGChangeToAMTCommand.h

--*/

#ifndef __MNG_CHANGE_TO_AMT_COMMAND_H__
#define __MNG_CHANGE_TO_AMT_COMMAND_H__

#include "ManageabilityCommand.h"
#include "MEIparser.h"

namespace Intel
{
	namespace MEI_Client
	{
		namespace Manageability_Client
		{
			struct ChangeToAMT_RESPONSE
			{
				uint32_t Status;
				void parse (std::vector<uint8_t>::const_iterator &itr, const std::vector<uint8_t>::const_iterator end)
				{
					Intel::MEI_Client::parseData(*this, itr, end);
				}
			};

			class MNGChangeToAMTRequest;
			class MNGChangeToAMTCommand : public ManageabilityCommand
			{
			public:

				MNGChangeToAMTCommand();
				virtual ~MNGChangeToAMTCommand() {}
				virtual void reTransact();
				ChangeToAMT_RESPONSE getResponse();

			private:
				virtual void parseResponse(const std::vector<uint8_t>& buffer);

				std::shared_ptr<ManageabilityCommandResponse<ChangeToAMT_RESPONSE>> m_response;
			};

			class MNGChangeToAMTRequest : public ManageabilityCommandRequest
			{
			public:
				MNGChangeToAMTRequest(){}
				virtual ~MNGChangeToAMTRequest() {}

			private:
				static const uint8_t REQUEST_COMMAND = 0x05;
				static const uint8_t REQUEST_SUB_CMD = 0x52;
				
				virtual uint8_t requestHeaderCMD()
				{
					//this is the command number (taken from the AMTHI document)
					return REQUEST_COMMAND;
				}
				virtual uint8_t requestHeaderSubCMD()
				{
					//this is the sub command number (taken from the AMTHI document)
					return REQUEST_SUB_CMD;
				}
				virtual uint8_t requestDataSize()
				{
					return 0; 
				}

				virtual std::vector<uint8_t> SerializeData();
			};
		} // namespace Manageability_Client
	} // namespace MEI_Client
} // namespace Intel

#endif //__MNG_CHANGE_TO_AMT_COMMAND_H__