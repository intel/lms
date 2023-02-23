/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2021-2023 Intel Corporation
 */
/*++

@file: PSRCommand.h

--*/

#ifndef __PSR_COMMAND_H__
#define __PSR_COMMAND_H__

#include "MEICommand.h"
#include "PSRErrorException.h"
#include <string>
#include <iostream>
#include <mutex>

namespace Intel
{
	namespace MEI_Client
	{
		namespace PSR_Client
		{

			enum class PSR_HECI_COMMANDS
			{
				PLATFORM_SERVICE_RECORD_GET = 10,
			};

			enum class PSR_SIGNING_MECHANISM
			{
				ECDSA384_WITH_SHA384 = 0,
			};

#pragma pack(1)
			typedef union _PSR_MSG_HEADER
			{
				uint32_t Data;
				struct
				{
					uint8_t  command;
					uint8_t  reserved;
					uint16_t length;
				} Fields;
			} PSR_MSG_HEADER;

			typedef struct
			{
				PSR_MSG_HEADER  header;
				uint32_t        status;
			} PSR_MSG_RESPONSE;
#pragma pack()

			class PSRCommand : public Intel::MEI_Client::MEICommand
			{
			public:
				PSRCommand() {}
				virtual ~PSRCommand() {}
				// To avoid multiple PSR HECI client calls
				static std::mutex& getInternalSemaphore();
			protected:
				void Transact()
				{
					std::lock_guard<std::mutex> lock(getInternalSemaphore());
					MEICommand::Transact();
				}

			private:
				virtual const GUID& getGUID();
				friend class SemaphoreInitializer;
				class SemaphoreInitializer
				{
					SemaphoreInitializer();
					static SemaphoreInitializer initializer;
				};
			};

			class PSRCommandRequest : public Intel::MEI_Client::MEICommandRequest
			{
			public:
				PSRCommandRequest(PSR_HECI_COMMANDS requestHeaderCommandNumber) : m_requestHeaderCommandNumber(requestHeaderCommandNumber) {}
				virtual ~PSRCommandRequest() {}
				virtual std::vector<uint8_t> Serialize();

			private:
				std::vector<uint8_t> serializeHeader(const PSR_MSG_HEADER& header);
				virtual uint16_t requestDataSize() = 0;
				virtual std::vector<uint8_t> SerializeData()
				{
					//default no data
					std::vector<uint8_t> tmp;
					return tmp;
				}
				// the PSR command number (in the header) of the request command
				PSR_HECI_COMMANDS m_requestHeaderCommandNumber;
			};

			template <typename T>
			class PSRCommandResponse : public Intel::MEI_Client::MEICommandResponse
			{
			public:
				PSRCommandResponse() : m_result(), m_commandNumber(PSR_HECI_COMMANDS::PLATFORM_SERVICE_RECORD_GET) {}
				PSRCommandResponse(PSRCommandResponse&& other) = default;
				PSRCommandResponse& operator = (PSRCommandResponse&& other) = default;
				PSRCommandResponse(const std::vector<uint8_t>& buffer, PSR_HECI_COMMANDS commandNumber) : m_result()
				{
					m_commandNumber = commandNumber;
					unsigned int headerAndStatSize = 0;
					verifyHeaderAndStatus(buffer, headerAndStatSize);
					verifyAndGenerateResponse(buffer.begin() + headerAndStatSize, buffer.end());
				}
				virtual ~PSRCommandResponse() {}
				T getResponse()
				{
					return m_result;
				}
			protected:
				T m_result;
				PSR_HECI_COMMANDS m_commandNumber;

			private:
				void verifyHeaderAndStatus(const std::vector<uint8_t>& buffer, unsigned int& headerAndStatSize)
				{
					if (buffer.size() < sizeof(PSR_MSG_HEADER))
					{
						throw MEIClientException("Error: response buffer too short");
					}

					PSR_MSG_HEADER* header = (PSR_MSG_HEADER*)&buffer[0];
					if (header->Fields.command != (uint8_t)getCommandNumber())
					{
						throw MEIClientException("Error: PSR Command number is incorrect");
					}
					if(header->Fields.length != buffer.size() - sizeof(PSR_MSG_HEADER))
					{
						throw MEIClientException("Error: length value is incorrect");
					}

					if (buffer.size() < sizeof(PSR_MSG_RESPONSE))
					{
						throw MEIClientException("Error: response buffer too short (no status)");
					}

					PSR_MSG_RESPONSE* response = (PSR_MSG_RESPONSE*)&buffer[0];
					if (response->status != PSR_STATUS_SUCCESS)
					{
						throw PSRErrorException(response->status);
					}

					headerAndStatSize = sizeof(PSR_MSG_RESPONSE);
				}
				void verifyAndGenerateResponse(std::vector<uint8_t>::const_iterator itr, const std::vector<uint8_t>::const_iterator end)
				{
					m_result.parse(itr, end);
				}
				PSR_HECI_COMMANDS getCommandNumber() { return m_commandNumber; }
			};
		} // namespace PSR_Client
	} // namespace MEI_Client
} // namespace Intel

#endif //__PSR_COMMAND_H__
