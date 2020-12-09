/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2009-2020 Intel Corporation
 */
#include "DataInterfaceBackend.h"
#include <string>


namespace Intel {
	namespace LMS {
		class AT_Device_BE : Common_BE
		{
		public:
			AT_Device_BE(bool isPfwup);

			LMS_ERROR GetAuditLogs(std::string &bstrAuditLogs);
		};
	}
}