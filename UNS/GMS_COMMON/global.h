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

#include <ace/Log_Msg.h>

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
#define UNS_PREFIX       ACE_TEXT("(%t)[%D][%-11M] %I ")



#define UNS_TRACE(...)     \
        ACE_DEBUG(( LM_TRACE,  \
                    UNS_PREFIX __VA_ARGS__))

#define UNS_DEBUG(...)     \
        ACE_DEBUG(( LM_DEBUG,  \
                    UNS_PREFIX __VA_ARGS__))

#define UNS_WARNING(...)     \
        ACE_DEBUG(( LM_WARNING,  \
                    UNS_PREFIX __VA_ARGS__))

#define UNS_ERROR(...)     \
        ACE_DEBUG(( LM_ERROR,  \
                    UNS_PREFIX __VA_ARGS__))

#define UNS_CRITICAL(...)     \
        ACE_DEBUG(( LM_CRITICAL,  \
                    UNS_PREFIX __VA_ARGS__))


#endif		//_GMS_GLOBAL__H__
