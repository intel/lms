/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2009-2019 Intel Corporation
 */
/*++

@file: Common.cpp

--*/
#include "global.h"

#include "Common.h"
#include "Tools.h"
#include <string>

int ADDR_Data::length() const
{
	bool ipv6 = is_ipv6();
	if (ipv6) {
		return sizeof(in6_addr);
	}
	else if (is_ipv4()){
		return sizeof(in_addr);
	}
	else
	{
		return -1;
	}
	
}

int ADDR_Data::sockaddrLen() const
{
	bool ipv6 = is_ipv6();
	if (ipv6) {
		return sizeof(sockaddr_in6);
	}
	else if (is_ipv4()){
		return sizeof(sockaddr_in);
	}
	else
	{
		return -1;
	}
}

#ifdef WIN32
bool ADDR_Data::getIPString(std::string &IP)
{
	int len = length();

	if (len != -1)
	{
		char addressStr[2 * MAX_HOSTNAME_LEN];
		DWORD addressStrlen = 2 * MAX_HOSTNAME_LEN;

		if(0 == WSAAddressToStringA((LPSOCKADDR)&_addr, sizeof(_addr), NULL, addressStr, &addressStrlen)) 
		{
			//UNS_DEBUG("\tIP Address %s\n", IP.c_str());
			IP = addressStr;
			return true;
		}
	}
	else
	{
		UNS_ERROR(L"ADDR_Data::getANSI - illegal address \n");
		return false;
	}
	return false;
}
#else // WIN32
bool ADDR_Data::getIPString(std::string &IP)
{
	int len = length();

	if (len == -1)
	{
		UNS_ERROR(L"ADDR_Data::getIPString - illegal len\n");
		return false;
	}

	char addressStr[NI_MAXHOST];
	if (getnameinfo((struct sockaddr *)&_addr, sizeof(_addr),
			addressStr, sizeof(addressStr), NULL, 0, NI_NUMERICHOST))
		return false;

	IP = addressStr;
	return true;
}
#endif // WIN32

bool ADDR_Data::operator==(const ADDR_Data& addr) const
{
	return  (length() != -1) && ((_addr.ss_family == addr._addr.ss_family) &&
			(memcmp(&_addr,&addr._addr, length()) ==0));
}

std::string addr2str(const sockaddr_storage& addr)
{
	ADDR_Data tmp_addr(addr);
	std::string ip;
	tmp_addr.getIPString(ip);
	return ip;
}
bool CompareSuffix(const std::string &first, const std::string &second)
{
	if (first.size() > second.size()) {

		return false;
	}

	if ((first.size() < second.size()) && 
		(second[second.size() - first.size() - 1] != '.')) {

		return false;
	}

	std::string myTail = second.substr(second.size() - first.size());

	return (myTail == first); 
}

std::wstring getErrMsg(unsigned long err)
{
#ifdef WIN32
	wchar_t buffer[1024];
	FormatMessage(FORMAT_MESSAGE_FROM_SYSTEM,
		NULL,
		err,
		0,
		buffer,
		sizeof(buffer) - 1,
		0);
	return std::wstring(buffer);
#else
	char cbuf[1024];
	char *pbuf;
	pbuf = strerror_r(err, cbuf, sizeof(cbuf) - 1);
	return StringToWString(std::string(pbuf));
#endif  // WIN32
}

addrinfo createAddrinfo(int family, int socktype, int protocol, int flags)
{
	addrinfo res;
	memset(&res, 0, sizeof(res));
	res.ai_family	= family;
	res.ai_socktype = socktype;
	res.ai_protocol = protocol;
	res.ai_flags	= flags;

	return res;
}
