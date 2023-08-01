/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2022-2023 Intel Corporation
 */
/*++

@file: ReadFileExCommand.h

--*/

#ifndef __READ_FILE_EX_COMMAND_H__
#define __READ_FILE_EX_COMMAND_H__

#include "MEIparser.h"
#include "MCHICommand.h"

namespace Intel
{
	namespace MEI_Client
	{
		namespace MCHI_Client
		{
			enum class MCA_FILE_ID
			{
				SKU_MGR_QUALIFIED_BRAND_ENTITLEMENTS = 0x10025100,
			};

			static const uint8_t MCA_FILE_FLAGS_NVAR_HASH = 0x1;
			static const uint8_t MCA_FILE_FLAGS_GET_DEFAULT = 0x2;
			static const uint8_t MCA_FILE_FLAGS_GET_EMULATION_VALUE = 0x4;
			static const uint8_t MCA_FILE_FLAGS_GET_HW_VALUE = 0x8;
			static const uint8_t MCA_FILE_FLAGS_GET_VOLATILE = 0x10;

			struct READ_FILE_EX_RESPONSE
			{
				std::vector<uint8_t> Data;

				void parse(std::vector<uint8_t>::const_iterator& itr, const std::vector<uint8_t>::const_iterator &end)
				{
					Intel::MEI_Client::parseSimpleArray32(Data, itr, end);
				}
			};

			#pragma pack(1)
			struct READ_FILE_EX_REQUEST
			{
				uint32_t FileID;
				uint32_t Offset;
				uint32_t DataSize;
				uint8_t Flags;
			};
			#pragma pack()

			class ReadFileExRequest : public MCHICommandRequest
			{
			public:
				ReadFileExRequest(uint32_t fileID, uint32_t offset, uint32_t dataSize, uint8_t flags) :
					MCHICommandRequest(REQUEST_COMMAND_NUMBER, MCHI_GROUP_ID_MCA), request{ fileID, offset, dataSize, flags } {}
				virtual ~ReadFileExRequest() {}

			private:
				static const uint32_t REQUEST_COMMAND_NUMBER = 0xA;

				virtual uint32_t requestDataSize()
				{
					return sizeof(READ_FILE_EX_REQUEST);
				}
				virtual std::vector<uint8_t> SerializeData()
				{
					std::vector<uint8_t> output((std::uint8_t*)&request, (std::uint8_t*)&request + sizeof(request));
					return output;
				}
				READ_FILE_EX_REQUEST request;
			};

			class ReadFileExCommand : public MCHICommand
			{
			public:

				ReadFileExCommand(MCA_FILE_ID fileID, uint32_t offset, uint32_t dataSize, uint8_t flags)
				{
					m_request = std::make_shared<ReadFileExRequest>(static_cast<uint32_t>(fileID), offset, dataSize, flags);
					Transact();
				}
				virtual ~ReadFileExCommand() {}

				READ_FILE_EX_RESPONSE getResponse() { return m_response.getResponse(); }

			private:
				virtual void parseResponse(const std::vector<uint8_t>& buffer)
				{
					m_response = MCHICommandResponse<READ_FILE_EX_RESPONSE>(buffer, RESPONSE_COMMAND_NUMBER, MCHI_GROUP_ID_MCA);
				}

				MCHICommandResponse<READ_FILE_EX_RESPONSE> m_response;

				static const uint32_t RESPONSE_COMMAND_NUMBER = 0xA;
			};
		} // namespace MCHI_Client
	} // namespace MEI_Client
} // namespace Intel

#endif //__READ_FILE_EX_COMMAND_H__
