/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2020-2023 Intel Corporation
 */
/*++

@file: UPIDCommand.h

--*/

#ifndef __UPID_COMMAND_H__
#define __UPID_COMMAND_H__

#include "MEICommand.h"
#include "UPIDErrorException.h"
#include <mutex>

namespace Intel
{
	namespace MEI_Client
	{
		namespace UPID_Client
		{
			static const size_t UPID_LEN = 32;

			/* Taken from CSME Host Interface 1.113*/

			typedef enum
			{
				UPID_COMMAND_FEATURE_PLATFORM_ID = 0,
			}   UPID_COMMAND_FEATURE;

			typedef enum
			{
				UPID_COMMAND_PLATFORM_ID_FEATURE_SUPPORT_GET = 0,
				UPID_COMMAND_PLATFORM_ID_FEATURE_STATE_GET = 1,
				UPID_COMMAND_PLATFORM_ID_FEATURE_STATE_SET = 2,
				UPID_COMMAND_PLATFORM_ID_FEATURE_STATE_OS_CONTROL_GET = 3,
				UPID_COMMAND_PLATFORM_ID_FEATURE_STATE_OS_CONTROL_SET = 4,
				UPID_COMMAND_PLATFORM_ID_GET = 5,
				UPID_COMMAND_PLATFORM_ID_REFURBISH_COUNTER_GET = 6,
				UPID_COMMAND_OEM_PLATFORM_ID_UPDATE = 7,
			}   UPID_COMMAND;

			typedef struct
			{
				uint8_t                              Feature;
				uint8_t                              Command;
				uint16_t                             ByteCount;
			}  UPID_HECI_HEADER;


			class UPIDCommand : public Intel::MEI_Client::MEICommand
			{
			public:
				UPIDCommand() {}
				virtual ~UPIDCommand() {}
				// To avoid multiple UPID HECI client calls
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

			class UPIDRequest : public Intel::MEI_Client::MEICommandRequest
			{
			public:
				UPIDRequest(uint8_t requestHeaderFeatureID, uint8_t requestHeaderCommandID) :
					m_requestHeaderFeatureID(requestHeaderFeatureID), m_requestHeaderCommandID(requestHeaderCommandID) {}
				virtual ~UPIDRequest() {}
				virtual std::vector<uint8_t> Serialize();

			private:
				std::vector<uint8_t> serializeHeader(const UPID_HECI_HEADER& header);
				//return total length not including the message header
				virtual uint16_t requestDataSize() { return 0; };

				virtual std::vector<uint8_t> SerializeData()
				{
					//default no data
					std::vector<uint8_t> tmp;
					return tmp;
				}
				// the UPID feature\command number (in the header) of the request command
				uint8_t m_requestHeaderFeatureID;
				uint8_t m_requestHeaderCommandID;
			};

			template <typename T>
			class UPIDCommandResponse : public Intel::MEI_Client::MEICommandResponse
			{
			public:
				UPIDCommandResponse(const std::vector<uint8_t>& buffer, uint8_t featureID, uint8_t commandID)
				{
					m_featureID = featureID;
					m_commandID = commandID;
					unsigned int headerAndStatSize = 0;
					verifyHeaderAndStatus(buffer, headerAndStatSize);
					verifyAndGenerateResponse(buffer.begin() + headerAndStatSize, buffer.end());
				}
				virtual ~UPIDCommandResponse() {}
				T getResponse()
				{
					return m_result;
				}
			protected:
				T m_result;
				uint8_t m_featureID;
				uint8_t m_commandID;
			private:
				void verifyHeaderAndStatus(const std::vector<uint8_t>& buffer, unsigned int & headerAndStatSize)
				{
					if (buffer.size() < sizeof(UPID_HECI_HEADER) + sizeof(UPID_STATUS))
					{
						throw MEIClientException("Error: response buffer too short.");
					}

					UPID_HECI_HEADER *header = (UPID_HECI_HEADER *)&buffer[0];
					if (header->Feature != getFeatureID())
					{
						throw MEIClientException("Error: UPID Feature number is incorrect.");
					}
					if (header->Command != getCommandID())
					{
						throw MEIClientException("Error: UPID Command number is incorrect.");
					}
					if (header->ByteCount != (buffer.size() - sizeof(UPID_HECI_HEADER)))
					{
						throw MEIClientException("Error: UPID ByteCount is incorrect.");
					}

					UPID_STATUS *status = (UPID_STATUS*)&(buffer[sizeof(UPID_HECI_HEADER)]);
					if (*status != UPID_STATUS_SUCCESS)
					{
						throw UPIDErrorException(*status);
					}
					headerAndStatSize = sizeof(UPID_HECI_HEADER) + sizeof(UPID_STATUS);
				}
				void verifyAndGenerateResponse(std::vector<uint8_t>::const_iterator itr, const std::vector<uint8_t>::const_iterator end)
				{
					m_result.parse(itr, end);
				}
				uint8_t getFeatureID() { return m_featureID; }
				uint8_t getCommandID() { return m_commandID; }
			};

		} // namespace UPID_Client
	} // namespace MEI_Client
} // namespace Intel

#endif //__UPID_COMMAND_H__
