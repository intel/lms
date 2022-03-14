//SPDX-License-Identifier: Apache-2.0
//
//Copyright (C) 2022 Intel Corporation
#include <winrt/Windows.ApplicationModel.h>
#include <winrt/Windows.Management.Deployment.h>
#include <winrt/Windows.Foundation.Collections.h>
#include "WMIRegistrationService.h"

namespace WMIRegistrationService
{
	namespace
	{
		winrt::hstring IsIMSSInstalled()
		{
			auto packages = winrt::Windows::Management::Deployment::PackageManager{}.FindPackages();
			for (auto const& package : packages)
			{
				if (package.Id().Name() == L"AppUp.IntelManagementandSecurityStatus")
				{
					return package.Id().FullName();
				}
			}

			DbgPrint(L"IMSS is not installed");
			return winrt::hstring();
		}

		UNINSTALLIMSS_STATUS UninstallByName(winrt::hstring name)
		{
			DbgPrint(L"IMSS UninstallByName %s", name.c_str());
			auto deploymentOperation{ winrt::Windows::Management::Deployment::PackageManager{}.RemovePackageAsync(name,
				winrt::Windows::Management::Deployment::RemovalOptions::RemoveForAllUsers) };
			deploymentOperation.get();

			// Check the status of the operation
			if (deploymentOperation.Status() == winrt::Windows::Foundation::AsyncStatus::Error)
			{
				auto deploymentResult{ deploymentOperation.GetResults() };
				DbgPrint(L"Failed to uninstall IMSS (%d) %s.", deploymentOperation.ErrorCode(), deploymentResult.ErrorText().c_str());
				return UNINSTALLIMSS_STATUS::FAILED;
			}
			else if (deploymentOperation.Status() == winrt::Windows::Foundation::AsyncStatus::Canceled)
			{
				DbgPrint(L"Failed to uninstall IMSS - cancelled.");
				return UNINSTALLIMSS_STATUS::FAILED;
			}
			else if (deploymentOperation.Status() == winrt::Windows::Foundation::AsyncStatus::Completed)
			{
				return UNINSTALLIMSS_STATUS::SUCCCEDED;
			}
			DbgPrint(L"Failed to uninstall IMSS - unknown.");
			return UNINSTALLIMSS_STATUS::FAILED;
		}
	}

	UNINSTALLIMSS_STATUS UninstallIMSS()
	{
		winrt::init_apartment();

		auto fullName = IsIMSSInstalled();
		if (fullName == winrt::hstring())
		{
			DbgPrint(L"IMSS not installed - ignoring.");
			return UNINSTALLIMSS_STATUS::NOT_NEEDED;
		}

		return UninstallByName(fullName);
	}
};