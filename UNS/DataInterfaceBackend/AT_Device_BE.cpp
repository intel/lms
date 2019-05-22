/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2009-2019 Intel Corporation
 */
#include "AT_Device_BE.h"
#include "UNSDebug.h"
#include "SMBIOS_Reader.h"
#include "AuditLogWSManClient.h"
#include <vector>

namespace Intel {
	namespace LMS {

		AT_Device_BE::AT_Device_BE(bool isPfwUp) :Common_BE(isPfwUp)
		{
		}

		LMS_ERROR AT_Device_BE::GetATDeviceInfo(short &pState)
		{
			uint32_t res;
			SMBIOS_Reader sm_reader;
			res = sm_reader.CheckForSmbiosFlags();

			if (res == SMBIOS_FOUNDED)
			{
				pState = sm_reader.pCapabilities.AT_Enrolled + 1;
				return ERROR_OK;
			}
			else
			{
				if (res == SMBIOS_NOT_FOUNDED)
				{
					pState = 0; // Disable
				}
				else
				{	/*
					///////////////////////////////
					SMBIOS_FAILURE				2
					ERROR_COCREATEINSTANCE		3
					ERROR_COINITIALIZE			4
					ERROR_SMBIOS_ENUMERATION	5
					ERROR_WMI_CONNECT			6
					ERROR_WMI_SET_PROXY			7
					///////////////////////////////		*/
					DbgPrintW(L"GetATInfo failed res=%d\n", res);
				}
			}
			return ERROR_FAIL;
		}

		LMS_ERROR AT_Device_BE::GetAuditLogs(std::string &bstrAuditLogs)
		{
			if (!m_isPfwUp) //This func is using WSMAN, and needs Port Forwarding to be up = LMS port is available
				return ERROR_NOT_AVAILABLE_NOW;

			std::string parsedRecords;
			AuditLogWSManClient client;
			std::vector<BinaryData> records;
			std::vector<Intel::Manageability::Cim::Typed::Base64> base64Records;

			try
			{
				if (!client.readLogsFromFW(base64Records))
					return ERROR_FAIL;
				DbgPrintW(L"get %d logs\n", base64Records.size());
				const unsigned char* tmpData;
				unsigned int tmpLength;
				for (unsigned int i = 0; i < base64Records.size(); i++)
				{
					tmpData = base64Records.at(i).Data();
					tmpLength = base64Records.at(i).Length();
					records.push_back(BinaryData(tmpData, tmpData + tmpLength));
				}
				if (client.parseLogs(parsedRecords, records))
				{
					bstrAuditLogs = parsedRecords;
					return ERROR_OK;
				}
			}
			catch (...)
			{
				DbgPrintW(L"Error reading from AuditLog!");
			}
			return ERROR_FAIL;
		}


	}
}
