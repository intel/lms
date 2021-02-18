/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2010-2021 Intel Corporation
 */
/*++

@file: GetImageTypeCommand.h

--*/

#ifndef __GET_IMAGE_TYPE_COMMAND_H__
#define __GET_IMAGE_TYPE_COMMAND_H__

#include "MEIparser.h"
#include "MKHICommand.h"


namespace Intel
{
	namespace MEI_Client
	{
		namespace MKHI_Client
		{
			typedef struct MKHI_IMAGE_TYPE_t
			{
				MKHI_MSG_HEADER		Header;
				uint32_t			ImageSignData;

				void parse (std::vector<uint8_t>::const_iterator& itr, const std::vector<uint8_t>::const_iterator &end)
				{
					parseData (ImageSignData, itr, end);
				}
			} MKHI_IMAGE_TYPE;

			class GetImageTypeRequest;
			class GetImageTypeCommand : public MKHICommand
			{
			public:

				GetImageTypeCommand();
				virtual ~GetImageTypeCommand() {}

				MKHI_IMAGE_TYPE getResponse();

			private:
				virtual void parseResponse(const std::vector<uint8_t>& buffer);

				std::shared_ptr<MKHICommandResponse<MKHI_IMAGE_TYPE>> m_response;

				static const uint32_t RESPONSE_COMMAND_NUMBER = 0x18;
			};

			class GetImageTypeRequest : public MKHICommandRequest
			{
			public:
				GetImageTypeRequest() {}
				virtual ~GetImageTypeRequest() {}

			private:
				static const uint32_t REQUEST_COMMAND_NUMBER = 0x18;
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

#endif //__GET_IMAGE_TYPE_COMMAND_H__
