/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2009-2023 Intel Corporation
 */
#include "AT_Device_BE.h"
#include "global.h"
#include "AuditLogWSManClient.h"
#include <vector>

namespace Intel {
	namespace LMS {

		AT_Device_BE::AT_Device_BE(unsigned int port) : Common_BE(port)
		{
		}

		LMS_ERROR AT_Device_BE::GetAuditLogs(std::string &bstrAuditLogs)
		{
			if (!m_port) //This func is using WSMAN, and needs Port Forwarding to be up = LMS port is available
				return LMS_ERROR::NOT_AVAILABLE_NOW;

			try
			{
				std::string parsedRecords;
				AuditLogWSManClient client(m_port);
				std::vector<BinaryData> records;

				if (!client.GetAuditLogRecords(records))
					return LMS_ERROR::FAIL;

				UNS_DEBUG(L"get %d logs\n", records.size());
				if (client.parseLogs(parsedRecords, records))
				{
					bstrAuditLogs = parsedRecords;
					return LMS_ERROR::OK;
				}
			}
			catch (...)
			{
				UNS_DEBUG(L"Error reading from AuditLog!\n");
			}
			return LMS_ERROR::FAIL;
		}
	}
}
