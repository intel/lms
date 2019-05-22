/*++
/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2010-2019 Intel Corporation
 */
/*++

@file: GetFWVersionCommand.h

--*/

#ifndef __GET_FW_VERSION_COMMAND_H__
#define __GET_FW_VERSION_COMMAND_H__

#include "MEIparser.h"
#include "MKHICommand.h"


namespace Intel
{
	namespace MEI_Client
	{
		namespace MKHI_Client
		{
			struct GET_FW_VER_RESPONSE
			{
				uint16_t  FTMinor;		    // Same as firmware fields 
				uint16_t  FTMajor;		    // same as firmware fields
				uint16_t  FTBuildNo;	    // same as firmware fields
				uint16_t  FTHotFix;		// same as firmware fields
				uint16_t  NFTMinor;		    // Same as firmware fields 
				uint16_t  NFTMajor;		    // same as firmware fields
				uint16_t  NFTBuildNo;	    // same as firmware fields
				uint16_t  NFTHotFix;		// same as firmware fields

				void parse (std::vector<uint8_t>::const_iterator& itr, const std::vector<uint8_t>::const_iterator &end)
				{
					parseData (FTMinor, itr, end);
					parseData (FTMajor, itr, end);
					parseData (FTBuildNo, itr, end);
					parseData (FTHotFix, itr, end);
					parseData (NFTMinor, itr, end);
					parseData (NFTMajor, itr, end);
					parseData (NFTBuildNo, itr, end);
					parseData (NFTHotFix, itr, end);
				}
			};

			class GetFWVersionRequest;
			class GetFWVersionCommand : public MKHICommand
			{
			public:
				GetFWVersionCommand();
				virtual ~GetFWVersionCommand() {}
				virtual void reTransact();
				GET_FW_VER_RESPONSE getResponse();

			private:
				virtual void parseResponse(const std::vector<uint8_t>& buffer);

				std::shared_ptr<MKHICommandResponse<GET_FW_VER_RESPONSE>> m_response;
				
				static const uint32_t RESPONSE_COMMAND_NUMBER = 0x02;
			};

			class GetFWVersionRequest : public MKHICommandRequest
			{
			public:
				GetFWVersionRequest() {}
				virtual ~GetFWVersionRequest() {}

			private:
				static const uint32_t REQUEST_COMMAND_NUMBER = 0x02;
				virtual unsigned int requestHeaderCommandNumber()
				{
					//this is the command number (taken from the MKHI document)
					return REQUEST_COMMAND_NUMBER;
				}

				virtual uint32_t requestDataSize()
				{
					return 0;
				}
				virtual unsigned int requestHeaderGroupID() 
				{
					//this is the command group (taken from the MKHI document)
					return MKHI_GEN_GROUP_ID;
				}
				virtual std::vector<uint8_t> SerializeData();
			};
		} // namespace MKHI_Client
	} // namespace MEI_Client
} // namespace Intel

#endif //__GET_FW_VERSION_COMMAND_H__