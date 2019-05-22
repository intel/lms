/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2009-2017 Intel Corporation
 */
#include "DataInterfaceBackend.h"
#include <string>

namespace Intel {
	namespace LMS {
		class UNSAlert_BE : Common_BE
		{
		public:
			UNSAlert_BE(bool isPfwup);

			LMS_ERROR GetIMSSEventHistory(std::wstring &bstrEventHistory);
		};
	}
}