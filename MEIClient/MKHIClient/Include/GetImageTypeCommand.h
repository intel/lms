/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2010-2023 Intel Corporation
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
			struct MKHI_IMAGE_TYPE
			{
				MKHI_IMAGE_TYPE() : ImageSignData(0) {}
				uint32_t			ImageSignData;

				void parse (std::vector<uint8_t>::const_iterator& itr, const std::vector<uint8_t>::const_iterator &end)
				{
					parseData (ImageSignData, itr, end);
				}
			};

			class GetImageTypeRequest : public MKHICommandRequest
			{
			public:
				GetImageTypeRequest() : MKHICommandRequest(REQUEST_COMMAND_NUMBER, MKHI_GEN_GROUP_ID) {}
				virtual ~GetImageTypeRequest() {}

			private:
				static const uint32_t REQUEST_COMMAND_NUMBER = 0x18;
			};

			class GetImageTypeCommand : public MKHICommand
			{
			public:

				GetImageTypeCommand()
				{
					m_request = std::make_shared<GetImageTypeRequest>();
					Transact();
				}
				virtual ~GetImageTypeCommand() {}

				MKHI_IMAGE_TYPE getResponse() { return m_response.getResponse(); }

			private:
				virtual void parseResponse(const std::vector<uint8_t>& buffer)
				{
					m_response = MKHICommandResponse<MKHI_IMAGE_TYPE>(buffer, RESPONSE_COMMAND_NUMBER, MKHI_GEN_GROUP_ID);
				}

				MKHICommandResponse<MKHI_IMAGE_TYPE> m_response;

				static const uint32_t RESPONSE_COMMAND_NUMBER = 0x18;
			};
		} // namespace MKHI_Client
	} // namespace MEI_Client
} // namespace Intel

#endif //__GET_IMAGE_TYPE_COMMAND_H__
