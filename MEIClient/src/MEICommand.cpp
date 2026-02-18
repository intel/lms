/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2010-2026 Intel Corporation
 */
/*++

@file: MEICommand.cpp

--*/

#include <chrono>
#include <thread>
#include <ace/Log_Msg.h>
#include <meteepp.h>

#include "MEICommand.h"
#include "HECI_if.h"

namespace Intel {
	namespace MEI_Client {

		void HECI_Log(bool is_error, const char* fmt, ...)
		{
			const size_t DEBUG_MSG_LEN = 1024;
			char msg[DEBUG_MSG_LEN];
			va_list varl;
			va_start(varl, fmt);
			vsnprintf(msg, DEBUG_MSG_LEN, fmt, varl);
			va_end(varl);
			ACE_DEBUG(((is_error) ? LM_ERROR : LM_TRACE, ACE_TEXT("(%t)[%D][%-11M] %I %C"), msg));
		}

		void heciConnect(intel::security::metee& heciClient, const std::string& data_path, std::stringstream &err_str)
		{
			constexpr int HECI_MAX_CONNECT_RETRY = 3;
			int retry = 0;
			while (true)
			{
				try
				{
					heciClient.connect();
					return;
				}
				catch (const intel::security::metee_exception& e)
				{
					if ((e.code().value() == TEE_BUSY || e.code().value() == TEE_UNABLE_TO_COMPLETE_OPERATION) &&
						++retry < HECI_MAX_CONNECT_RETRY)
					{
						err_str << data_path << " connect " << e.what() << " ";
						std::this_thread::sleep_for(std::chrono::milliseconds(500));
						continue;
					}
					throw;
				}
			};
		}

		intel::security::metee heciClientByGUID(const GUID& guid)
		{
#ifdef WIN32
			std::vector<struct tee_device_address> devices =
			{ { tee_device_address::TEE_DEVICE_TYPE_NONE, NULL } };
#else
			std::vector<struct tee_device_address> devices =
			{
					{ tee_device_address::TEE_DEVICE_TYPE_PATH, "/dev/mei0" },
					{ tee_device_address::TEE_DEVICE_TYPE_PATH, "/dev/mei1" },
					{ tee_device_address::TEE_DEVICE_TYPE_PATH, "/dev/mei2" },
					{ tee_device_address::TEE_DEVICE_TYPE_PATH, "/dev/mei3" },
			};
#endif // WIN32
			std::stringstream err_str;
			int err = TEE_INTERNAL_ERROR;

			for (std::vector<struct tee_device_address>::const_iterator it = devices.begin();
				it != devices.end(); it++)
			{
				try
				{
					intel::security::metee heciClient(guid, *it, TEE_LOG_LEVEL_VERBOSE, HECI_Log);
					heciConnect(heciClient, ((it->data.path) ? it->data.path : "NULL"), err_str);
					return heciClient;
				}
				catch (const intel::security::metee_exception& e)
				{
					err_str << ((it->data.path) ? it->data.path : "NULL") << " init " << e.what() << " ";
					if (e.code().value() == TEE_CLIENT_NOT_FOUND)
					{
						err = TEE_CLIENT_NOT_FOUND;
					}
					else if (e.code().value() == TEE_BUSY || e.code().value() == TEE_UNABLE_TO_COMPLETE_OPERATION)
					{
						err = TEE_BUSY;
						break;
					}
				}
			}
			if (err == TEE_CLIENT_NOT_FOUND)
				throw MEIClientExceptionNoClient(err_str.str(), TEE_CLIENT_NOT_FOUND);
			else
				throw MEIClientException(err_str.str(), err);
		}

		void GetHeciDriverVersion(std::string& ver)
		{
			try
			{
				intel::security::metee heciClient;
				ver = heciClient.driver_version();
			}
			catch (const intel::security::metee_exception &e)
			{
				throw MEIClientException(e.what(), e.code().value());
			}
		}

		void MEICommand::Transact()
		{
			try
			{
				intel::security::metee heciClient(heciClientByGUID(getGUID()));

				heciClient.write(m_request->Serialize(), 0);

				std::vector<uint8_t> readBuffer = heciClient.read(15000);
				if (readBuffer.size() == 0)
					throw MEIClientExceptionZeroBuffer("Error: Failed on ReceiveResponse");

				parseResponse(readBuffer);
			}
			catch (const intel::security::metee_exception& e)
			{
				throw MEIClientException(e.what(), e.code().value());
			}
		}

	} // MEI_Client
} // Intel


