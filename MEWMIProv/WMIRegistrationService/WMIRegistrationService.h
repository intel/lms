//SPDX-License-Identifier: Apache-2.0
//
//Copyright (C) 2022 Intel Corporation

#ifndef WMIREGISTRATIONSERVICE_H
#define WMIREGISTRATIONSERVICE_H
namespace WMIRegistrationService
{
	void DbgPrint(const wchar_t* args, ...);

	bool IsSKUCorporate(bool& corporate_sku);

	enum class UNINSTALLIMSS_STATUS
	{
		FAILED,
		SUCCCEDED,
		NOT_NEEDED,
	};

	UNINSTALLIMSS_STATUS UninstallIMSS();

	bool RegistryRead(const std::wstring& name, unsigned long& value);
	bool RegistryWrite(const std::wstring& name, unsigned long value);
};
#endif // WMIREGISTRATIONSERVICE_H