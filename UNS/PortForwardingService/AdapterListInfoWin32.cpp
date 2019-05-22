/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2009-2019 Intel Corporation
 */
/*++

@file: AdapterListInfoWin32.cpp

--*/

#include "AdapterListInfo.h"
#include "global.h"

#include <windows.h>
#include <iphlpapi.h>

std::mutex AdapterListInfo::_localDNSLock;
std::mutex AdapterListInfo::_initLock;
SuffixMap AdapterListInfo::_localDNSSuffixes;
SuffixMap AdapterListInfo::_copyOfLocalDNSSuffixes;
ACE_thread_t AdapterListInfo::_thread = 0;
AdapterCallback AdapterListInfo::_cb = NULL;
HANDLE m_handle = 0;

VOID NETIOAPI_API_ ipChangeCallback(PVOID *context, PMIB_IPINTERFACE_ROW row, MIB_NOTIFICATION_TYPE notType)
{
	AdapterListInfo::PerformUpdate(context);
}

bool AdapterListInfo::Init(AdapterCallback cb, void *params)
{
	std::lock_guard<std::mutex> l(_initLock);
	bool res = false;

	_cb = cb;

	if (!PerformUpdate(params)) {
		res = false;
		goto out;
	}

	res = (NotifyIpInterfaceChange(AF_UNSPEC, (PIPINTERFACE_CHANGE_CALLBACK)ipChangeCallback, params, FALSE, &m_handle) == NO_ERROR);

out:
	return res;
}

void AdapterListInfo::Deinit()
{
	std::lock_guard<std::mutex> l(_initLock);

	if (m_handle) {
		CancelMibChangeNotify2(m_handle);
		m_handle = 0;
	}
}

int AdapterListInfo::UpdateAdapterListInfo()
{
	int result = -1;

	std::unique_ptr<unsigned char[]>buffer;
	ULONG bufLen = 15360; /* 15K recommended starting value by the doc */
	ULONG ret = 0;
	unsigned int retry = 0;
	const unsigned int MAX_TRIES = 3;

	do {
		buffer.reset(new unsigned char[bufLen]);
		ret = GetAdaptersAddresses(AF_UNSPEC, 0, NULL,
					   (PIP_ADAPTER_ADDRESSES)buffer.get(), &bufLen);
	} while (ret == ERROR_BUFFER_OVERFLOW && retry++ < MAX_TRIES);

	if (ret != NO_ERROR) {
		result = -1;
		goto out;
	}

	// If successful, retrieve DNS suffixes from each adapter
	{
		std::lock_guard<std::mutex> lock(_localDNSLock);
		_localDNSSuffixes.clear();

		PIP_ADAPTER_ADDRESSES Adapter = (PIP_ADAPTER_ADDRESSES)buffer.get();
		while (Adapter) {
			char addressStr[2 * MAX_HOSTNAME_LEN];
			DWORD len = 2 * MAX_HOSTNAME_LEN;
			std::string localDnsSuffixStr = "";

			if (Adapter->DnsSuffix != NULL)
			{
				size_t length = wcslen(Adapter->DnsSuffix);
				if (length != 0)
				{
					++length;
					size_t retCnt;
					std::unique_ptr<char[]> localDnsSuffix(new char[length]);
					if (!wcstombs_s(&retCnt, localDnsSuffix.get(), length, Adapter->DnsSuffix, length)) {

						LMS_DEBUG_VAR(L"Local DNS suffix: %C", localDnsSuffix.get());
						localDnsSuffixStr = localDnsSuffix.get();
					}
				}
			}

			if (Adapter->OperStatus == IfOperStatusUp) {
				PIP_ADAPTER_UNICAST_ADDRESS uniAddr = Adapter->FirstUnicastAddress;
				while (uniAddr) {
					if (0 == WSAAddressToStringA(uniAddr->Address.lpSockaddr,
						uniAddr->Address.iSockaddrLength,
						NULL,
						addressStr, &len)) {
						LMS_DEBUG_VAR(L"\tIP Address %C", addressStr);
					}

					sockaddr_storage addr;
					memset(&addr, 0, sizeof(addr));
					memcpy_s(&addr, sizeof(addr), uniAddr->Address.lpSockaddr, uniAddr->Address.iSockaddrLength);

					_localDNSSuffixes[addr] = localDnsSuffixStr;

					uniAddr = uniAddr->Next;
				}
			}
			Adapter = Adapter->Next;
		}
		_copyOfLocalDNSSuffixes = _localDNSSuffixes;
	}
	result = 0;

out:
	if (result) {
		LMS_DEBUG_SIMPLE(L"Error in getting local DNS suffixes...");
	}

	return result;
}

std::string AdapterListInfo::GetDNSSuffixFromLocalIP(const sockaddr_storage &ip)
{
	std::string dns;
	std::lock_guard<std::mutex> lock(_localDNSLock);

	SuffixMap::iterator it = _localDNSSuffixes.find(ip);
	if (it != _localDNSSuffixes.end()) {
		dns = it->second;
	}
	else {
		dns = "";
	}

	return dns;
}

bool AdapterListInfo::PerformUpdate(void *params)
{
	LMS_DEBUG_SIMPLE(L"---> Check for update in Adapter ...");
	if (UpdateAdapterListInfo() != 0)
		return false;
	if (_cb != NULL) {
		SuffixMap suffixes(GetLocalDNSSuffixList());//to copy it under lock
		_cb(params, suffixes);
	}
	return true;
}
