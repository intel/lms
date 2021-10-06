/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2021-2026 Intel Corporation
 */
 /*++

 @file: LMEClient.h

 --*/

#ifndef __LME_CLIENT_H__
#define __LME_CLIENT_H__

#include <vector>
#include <memory>
#include <mutex>
#include <meteepp.h>
#include "MEIClientException.h"

namespace Intel
{
	namespace MEI_Client
	{
		namespace LME_Client
		{

			class LMEClient {
			public:
				LMEClient() : _heci(nullptr) {}

				void Connect();
				void Disconnect();
				void Cancel();
				std::vector<uint8_t> Read();
				size_t Write(const std::vector<uint8_t> &buffer);
				size_t GetBufferSize() const;
				TEE_DEVICE_HANDLE GetDeviceHandle() const;
			private:
				std::unique_ptr<intel::security::metee> _heci;
				std::mutex _sendMessageLock;
			};
		} // namespace LME_Client
	} // namespace MEI_Client
} // namespace Intel

#endif //__LME_CLIENT_H__
