/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2009-2023 Intel Corporation
 */
#include "DataInterfaceBackend.h"
#include <string>

namespace Intel {
	namespace LMS {
		class UNSAlert_BE : Common_BE
		{
		public:
			UNSAlert_BE(unsigned int port);

			LMS_ERROR GetIMSSEventHistory(std::wstring &bstrEventHistory);
		};
	}
}