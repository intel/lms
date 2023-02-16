/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2010-2023 Intel Corporation
 */

/*++

@file: EnumerateHashHandlesCommand.h

--*/

#ifndef __ENUMERATE_HASH_HANDLES_COMMAND_H__
#define __ENUMERATE_HASH_HANDLES_COMMAND_H__

#include "AMTHICommand.h"
#include "MEIparser.h"

namespace Intel
{
	namespace MEI_Client
	{
		namespace AMTHI_Client
		{
			struct ENUMERATE_HASH_HANDLES_RESPONSE
			{
				std::vector<uint32_t> HashHandles;

				void parse (std::vector<uint8_t>::const_iterator& itr, const std::vector<uint8_t>::const_iterator end)
				{
					Intel::MEI_Client::parseSimpleArray32(HashHandles, itr, end);
				}
			};

			class EnumerateHashHandlesCommand : public AMTHICommand
			{
			public:

				EnumerateHashHandlesCommand ();
				virtual ~EnumerateHashHandlesCommand () {}

				ENUMERATE_HASH_HANDLES_RESPONSE getResponse() ;

			private:
				virtual void parseResponse(const std::vector<uint8_t>& buffer);

				std::shared_ptr<AMTHICommandResponse<ENUMERATE_HASH_HANDLES_RESPONSE> > m_response;

				static const uint32_t RESPONSE_COMMAND_NUMBER = 0x0480002C;

			};

			class EnumerateHashHandlesRequest : public AMTHICommandRequest
			{
			public:
				EnumerateHashHandlesRequest () : AMTHICommandRequest(REQUEST_COMMAND_NUMBER) {}
				virtual ~EnumerateHashHandlesRequest() {}

			private:
				static const uint32_t REQUEST_COMMAND_NUMBER = 0x0400002C;
			};
		} // namespace AMTHI_Client
	} // namespace MEI_Client
} // namespace Intel

#endif //__ENUMERATE_HASH_HANDLES_COMMAND_H__