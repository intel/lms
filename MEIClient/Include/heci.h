/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2009-2024 Intel Corporation
 */
/*++

@file: heci.h

--*/

#ifndef __HECI_H__
#define __HECI_H__
#include <string>
#include <memory>
#include <metee.h>

namespace Intel {
	namespace MEI_Client {
		class HECI {

		public:
			HECI(const GUID &guid, bool verbose = false);
			~HECI();
			HECI(const HECI&) = delete;
			HECI& operator = (const HECI&) = delete;

			void Init();
			void Deinit();
			size_t ReceiveHeciMessage(unsigned char *buffer, size_t len, unsigned long timeout);
			size_t SendHeciMessage(const unsigned char *buffer, size_t len, unsigned long timeout);
			size_t GetBufferSize() const { return _bufSize; }
			void* GetHandle();
			void GetHeciDriverVersion(std::string& ver);
		protected:
			const GUID &_guid;
			bool _initialized;
			bool _verbose;
			size_t _bufSize;

			std::unique_ptr<_TEEHANDLE> _handle;
		};
	};
};
#endif // __HECI_H__
