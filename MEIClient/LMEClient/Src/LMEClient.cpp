/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2021-2026 Intel Corporation
 */
 /*++

 @file: LMEClient.cpp

 --*/

#include "LMEClient.h"
#include "MEICommand.h"
#include <meteepp.h>
#include "HECI_if.h"

namespace Intel
{
	namespace MEI_Client
	{
		namespace LME_Client
		{
			const uint32_t HECI_IO_TIMEOUT = 5000;
			void LMEClient::Connect()
			{
				_heci.reset(new intel::security::metee(heciClientByGUID(LME_GUID)));
			}

			void LMEClient::Disconnect()
			{
				_heci.reset(nullptr);
			}

			std::vector<uint8_t> LMEClient::Read()
			{
				if (_heci == nullptr)
					throw MEIClientException("Not initialized", TEE_INTERNAL_ERROR);
				try
				{
					return _heci->read(0);
				}
				catch (const intel::security::metee_exception& e)
				{
					throw MEIClientException(e.what(), e.code().value());
				}
			}

			void LMEClient::Cancel()
			{
				if (_heci == nullptr)
					throw MEIClientException("Not initialized", TEE_INTERNAL_ERROR);
				try
				{
					_heci->cancel_io();
				}
				catch (const intel::security::metee_exception& e)
				{
					throw MEIClientException(e.what(), e.code().value());
				}
			}

			size_t LMEClient::Write(const std::vector<uint8_t> &buffer)
			{
				if (_heci == nullptr)
					throw MEIClientException("Not initialized", TEE_INTERNAL_ERROR);

				std::lock_guard<std::mutex> lock(_sendMessageLock);

				try
				{
					return _heci->write(buffer, HECI_IO_TIMEOUT);
				}
				catch (const intel::security::metee_exception& e)
				{
					throw MEIClientException(e.what(), e.code().value());
				}
			}

			size_t LMEClient::GetBufferSize() const
			{
				if (_heci == nullptr)
					throw MEIClientException("Not initialized", TEE_INTERNAL_ERROR);
				return _heci->max_msg_len();
			}

			TEE_DEVICE_HANDLE LMEClient::GetDeviceHandle() const
			{
				if (_heci == nullptr)
					throw MEIClientException("Not initialized", TEE_INTERNAL_ERROR);
				return _heci->device_handle();
			}
		} // namespace LME_Client
	} // namespace MEI_Client
} // namespace Intel
