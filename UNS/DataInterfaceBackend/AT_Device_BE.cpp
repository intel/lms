/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2009-2022 Intel Corporation
 */
#include "AT_Device_BE.h"
#include "global.h"
#include "AuditLogWSManClient.h"
#include <vector>

namespace Intel {
	namespace LMS {

		AT_Device_BE::AT_Device_BE(bool isPfwUp) :Common_BE(isPfwUp)
		{
		}

		LMS_ERROR AT_Device_BE::GetAuditLogs(std::string &bstrAuditLogs)
		{
			if (!m_isPfwUp) //This func is using WSMAN, and needs Port Forwarding to be up = LMS port is available
				return LMS_ERROR::NOT_AVAILABLE_NOW;

			std::string parsedRecords;
			AuditLogWSManClient client;
			std::vector<BinaryData> records;
			std::vector<Intel::Manageability::Cim::Typed::Base64> base64Records;

			try
			{
				if (!client.readLogsFromFW(base64Records))
					return LMS_ERROR::FAIL;

				UNS_DEBUG(L"get %d logs\n", base64Records.size());
				for (unsigned int i = 0; i < base64Records.size(); i++)
				{
					const unsigned char *data= base64Records.at(i).Data();
					unsigned int length = base64Records.at(i).Length();

					records.push_back(BinaryData(data, data + length));
				}
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
