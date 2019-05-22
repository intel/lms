/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2009-2019 Intel Corporation
 */
/*++

@file: AdapterListInfo.h

--*/

#ifndef _ADAPTER_LIST_INFO_H_
#define _ADAPTER_LIST_INFO_H_

#include <mutex>
#include <map>
#include <string>
#include <ace/Thread.h>

class AddressLess {
public:
	bool operator()(const sockaddr_storage& _Left, const sockaddr_storage& _Right) const {

		int diff = _Left.ss_family - _Right.ss_family;
		if (diff == 0) {

			if (_Left.ss_family == AF_INET) {
				diff = ((sockaddr_in *)&_Left)->sin_addr.s_addr -
					((sockaddr_in *)&_Right)->sin_addr.s_addr;
			}
			else if (_Left.ss_family == AF_INET6) {

				sockaddr_in6 * a = (sockaddr_in6 *)&_Left;
				sockaddr_in6 * b = (sockaddr_in6 *)&_Right;

				diff = a->sin6_scope_id - b->sin6_scope_id;
				int i = 0;
				while ((diff == 0) && (i <= 14)) {
					diff = a->sin6_addr.s6_addr[i] - b->sin6_addr.s6_addr[i];
					++i;
				}
			}
			else {
				return true;
			}
		}
		return diff < 0;
		//return (memcmp(&_Left, &_Right, sizeof(_Left)) < 0);
	}
};

typedef std::map<sockaddr_storage, std::string, AddressLess> SuffixMap;
typedef void (*AdapterCallback) (void *, SuffixMap &localDNSSuffixes);

class AdapterListInfo {
public:
	static bool Init(AdapterCallback cb, void *param);
	static void Deinit();
	static int UpdateAdapterListInfo();
	static std::string GetDNSSuffixFromLocalIP(const sockaddr_storage &ip);
	static const SuffixMap GetLocalDNSSuffixList()
	{ 
		std::lock_guard<std::mutex> l(_localDNSLock);
		return _copyOfLocalDNSSuffixes;
	}
	static bool PerformUpdate(void *params);

private:
	static std::mutex _localDNSLock;
	static SuffixMap _localDNSSuffixes;
	static SuffixMap _copyOfLocalDNSSuffixes;
	static ACE_thread_t _thread;
	static AdapterCallback _cb;
	static std::mutex _initLock;
};

#endif