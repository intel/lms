/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2006-2011, 2013-2019 Intel Corporation
 */
//----------------------------------------------------------------------------
//
//  File:       global.h
//
//  Contents:   Global declarations and definitions.
//
//  Notes:      
//----------------------------------------------------------------------------
#ifndef _GMS_GLOBAL__H__
#define _GMS_GLOBAL__H__

//===================================================
//  INCLUDES
//===================================================
#define _WIN32_WINNT _WIN32_WINNT_VISTA 

#include "ace/config.h"
#include "servicesNames.h"

//===================================================
//  DEFINES 
//===================================================

#define GMS_ACE_SECOND 1
#define GMS_ACE_MINUTE (60 * GMS_ACE_SECOND)

#ifndef WIN32
typedef void* HDEVNOTIFY;
typedef void* HANDLE;
typedef int SOCKET;
#define _strnicmp strncasecmp
static inline int GetLastError() {return errno;}
static inline int WSAGetLastError() {return errno;}
#endif // !WIN32

//===================================================
//  GLOBAL MACROS
//===================================================

//log:
#define DEBUG_PREFIX       ACE_TEXT ("(%t)[%D] [%M] %I ")
#define INFO_PREFIX        ACE_TEXT ("(%t)[%D] [%M] %I ")
#define NOTICE_PREFIX      ACE_TEXT ("[%D] %M%I ")
#define WARNING_PREFIX     ACE_TEXT ("[%D] %M%I ")
#define ERROR_PREFIX       ACE_TEXT ("[%D] %M%I %p %I")
#define CRITICAL_PREFIX    ACE_TEXT ("[%D] %M %p")
#define ALERT_PREFIX       ACE_TEXT ("[%D] %M %p")
#define EMERGENCY_PREFIX   ACE_TEXT ("[%D] %M %p")

#define UNS_DEBUG(FMT, ...)     \
        ACE_DEBUG(( LM_DEBUG,  \
                    DEBUG_PREFIX FMT  \
					__VA_ARGS__))


#define LMS_DEBUG_VAR(FMT, ...)     \
	ACE_DEBUG(( LM_DEBUG,  \
	DEBUG_PREFIX L"LMS: " FMT  \
	L"\n", __VA_ARGS__))

#define LMS_DEBUG_SIMPLE(FMT)     \
	ACE_DEBUG(( LM_DEBUG,  \
	DEBUG_PREFIX L"LMS: " FMT L"\n"))


#define UNS_INFO(FMT, ...)     \
        ACE_DEBUG(( LM_INFO,  \
                    INFO_PREFIX FMT \
                    __VA_ARGS__))
#define UNS_NOTICE(FMT, ...)     \
        ACE_DEBUG(( LM_NOTICE,  \
                    NOTICE_PREFIX FMT \
                    __VA_ARGS__))
#define UNS_WARNING(FMT, ...)     \
        ACE_DEBUG(( LM_WARNING,  \
                    WARNING_PREFIX FMT \
                    __VA_ARGS__))
#define UNS_ERROR(FMT, ...)     \
        ACE_DEBUG(( LM_ERROR,  \
                    ERROR_PREFIX FMT \
                    __VA_ARGS__))
#define UNS_CRITICAL(FMT, ...)     \
        ACE_DEBUG(( LM_CRITICAL,  \
                    CRITICAL_PREFIX FMT \
                    __VA_ARGS__))
#define UNS_ALERT(FMT, ...)     \
        ACE_DEBUG(( LM_ALERT,  \
                    ALERT_PREFIX FMT \
                    __VA_ARGS__))
#define UNS_EMERGENCY(FMT, ...)     \
        ACE_DEBUG(( LM_EMERGENCY,  \
                    EMERGENCY_PREFIX FMT \
                    __VA_ARGS__))

#endif		//_GMS_GLOBAL__H__
