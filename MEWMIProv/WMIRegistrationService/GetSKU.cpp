//SPDX-License-Identifier: Apache-2.0
//
//Copyright (C) 2022 Intel Corporation
#include <vector>
#include <string>
#include <Windows.h>
#include <initguid.h>
#include <cfgmgr32.h>
#include <devpkey.h>

#include "WMIRegistrationService.h"
namespace WMIRegistrationService
{
	namespace {
		// Define GUID used to find the HECI device
		// {E2D1FF34-3458-49A9-88DA-8E6915CE9BE5}
		DEFINE_GUID(GUID_DEVINTERFACE_HECI,
			0xE2D1FF34, 0x3458, 0x49A9, 0x88, 0xDA, 0x8E, 0x69, 0x15, 0xCE, 0x9B, 0xE5);

		bool GetDevicePaths(_In_ LPCGUID InterfaceGuid, _Inout_ std::vector<std::wstring>& paths)
		{
			CONFIGRET cr = CR_SUCCESS;
			DWORD win32Err = ERROR_GEN_FAILURE;
			std::vector<wchar_t> deviceInterfaceList;
			ULONG deviceInterfaceListLength = 0;

			cr = CM_Get_Device_Interface_List_SizeW(
				&deviceInterfaceListLength,
				(LPGUID)InterfaceGuid,
				nullptr,
				CM_GET_DEVICE_INTERFACE_LIST_PRESENT);
			if (cr != CR_SUCCESS) {
				win32Err = CM_MapCrToWin32Err(cr, ERROR_GEN_FAILURE);
				DbgPrint(L"CM_Get_Device_Interface_List_SizeW falied %ul", win32Err);
				return false;
			}

			if (deviceInterfaceListLength <= 1) {
				DbgPrint(L"CM_Get_Device_Interface_List_SizeW %ul <= 1", deviceInterfaceListLength);
				return false;
			}

			deviceInterfaceList.resize(deviceInterfaceListLength);

			ZeroMemory((void*)deviceInterfaceList.data(), deviceInterfaceListLength * sizeof(wchar_t));

			cr = CM_Get_Device_Interface_ListW(
				(LPGUID)InterfaceGuid,
				nullptr,
				deviceInterfaceList.data(),
				deviceInterfaceListLength,
				CM_GET_DEVICE_INTERFACE_LIST_PRESENT);
			if (cr != CR_SUCCESS) {
				win32Err = CM_MapCrToWin32Err(cr, ERROR_GEN_FAILURE);
				DbgPrint(L"CM_Get_Device_Interface_ListW falied %ul", win32Err);
				return false;
			}

			// Search for ALL NULL-terminated strings in the array/vector
			std::vector<wchar_t>::const_iterator start = cbegin(deviceInterfaceList);
			for (auto iter = start; iter != cend(deviceInterfaceList); iter++)
			{
				// got to  NULL-terminated string end
				if (*iter == 0x00)
				{
					std::wstring path;
					path.resize(MAX_PATH);
					std::copy(start, iter++, std::begin(path));
					start = iter;
					paths.push_back(std::wstring(cbegin(path), cend(path)));
				}
			}

			return true;
		}

		bool GetSKU(int& sku)
		{
			CONFIGRET cr = CR_DEFAULT;
			DWORD win32Err = ERROR_GEN_FAILURE;

			std::vector<std::wstring> devicePaths;
			if (!GetDevicePaths(&GUID_DEVINTERFACE_HECI, devicePaths))
			{
				DbgPrint(L"GetDevicePaths falied");
				return false;
			}
			if (devicePaths.empty())
			{
				DbgPrint(L"DevicePaths is empty");
				return false;
			}

			std::vector<wchar_t> instanceIdVec(MAX_PATH);
			DEVPROPTYPE propType = 0;
			ULONG propLen = (ULONG)instanceIdVec.size();
			cr = CM_Get_Device_Interface_PropertyW(devicePaths[0].c_str(), &DEVPKEY_Device_InstanceId, &propType, (PBYTE)instanceIdVec.data(), &propLen, 0);
			if (cr != CR_SUCCESS) {
				win32Err = CM_MapCrToWin32Err(cr, ERROR_GEN_FAILURE);
				DbgPrint(L"CM_Get_Device_Interface_PropertyW falied %ul", win32Err);
				return false;
			}
			if (DEVPROP_TYPE_STRING != propType)
			{
				DbgPrint(L"DEVPKEY_Device_InstanceId is not a string");
				return false;
			}

			DEVINST devInstHandle;
			cr = CM_Locate_DevNodeW(&devInstHandle, (DEVINSTID_W)instanceIdVec.data(), 0);
			if (cr != CR_SUCCESS) {
				win32Err = CM_MapCrToWin32Err(cr, ERROR_GEN_FAILURE);
				DbgPrint(L"CM_Locate_DevNodeW falied %ul", win32Err);
				return false;
			}

			std::vector<wchar_t> FirmwareRevisionVec(MAX_PATH);
			propLen = (ULONG)FirmwareRevisionVec.size();

			cr = CM_Get_DevNode_PropertyW(devInstHandle, &DEVPKEY_Device_FirmwareRevision, &propType,
				(PBYTE)FirmwareRevisionVec.data(), &propLen, 0);
			if (cr != CR_SUCCESS) {
				win32Err = CM_MapCrToWin32Err(cr, ERROR_GEN_FAILURE);
				DbgPrint(L"CM_Get_DevNode_PropertyW falied %ul", win32Err);
				return false;
			}
			if (DEVPROP_TYPE_STRING != propType)
			{
				DbgPrint(L"DEVPKEY_Device_FirmwareRevision is not a string");
				return false;
			}

			std::wstring FirmwareRevision(cbegin(FirmwareRevisionVec), cend(FirmwareRevisionVec));

			if (FirmwareRevision.substr(0, 4) != L"SKU " || FirmwareRevision[5] != ' ')
			{
				DbgPrint(L"DEVPKEY_Device_FirmwareRevision '%s' is misformatted", FirmwareRevision.c_str());
				return false;
			}

			sku = FirmwareRevision[4] - '0';

			return true;
		}
	}

	bool IsSKUCorporate(bool &corporate_sku)
	{
		int sku = 0;

		if (!GetSKU(sku))
			return false;

		if (sku != 3)
		{
			DbgPrint(L"SKU %d is not Corporate (3)", sku);
			corporate_sku = false;
			return true;
		}
		corporate_sku = true;

		return true;
	}
};