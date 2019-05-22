/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2008-2011, 2013-2019 Intel Corporation
 */
//----------------------------------------------------------------------------
//
//  File:       Common.h
//
//  Contents:   common function and data structure
//
//  Notes:      
//----------------------------------------------------------------------------
#ifndef _LMS_COMMON_H_
#define _LMS_COMMON_H_

//===================================================
//  INCLUDES
//===================================================
#ifdef WIN32
#include <windows.h>
#include <iphlpapi.h>
#else
#include <netdb.h>
#endif // WIN32

#include <string>

//===================================================
//  Structures
//===================================================
struct ADDR_Data
{
	sockaddr_storage _addr;
	
	ADDR_Data(const sockaddr_storage &addr):_addr(addr){}
	bool	is_ipv6()const {return (_addr.ss_family == AF_INET6);}
	bool	is_ipv4()const{return (_addr.ss_family == AF_INET);}
	int		length()const;
	bool	getIPString(std::string &IP); 
	int		family(){return _addr.ss_family;}
	int		sockaddrLen() const;
	bool	operator==(const ADDR_Data& addr)const ;
};

//===================================================
//  Global Functions
//===================================================
bool		CompareSuffix(const std::string &first, const std::string &second);
std::wstring	getErrMsg(unsigned long err);
std::string		addr2str(const sockaddr_storage &addr);
addrinfo	createAddrinfo(int family, int socktype, int protocol, int flags);



#endif	//_LMS_COMMON_H_
