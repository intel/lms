/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2020 Intel Corporation
 */
 /*++

 @file: WsmanClientLog.h

 --*/

#ifndef _WSMAN_CLIENT_LOG_H
#define _WSMAN_CLIENT_LOG_H

#include <ace/Log_Msg.h>

#define WSMAN_PREFIX ACE_TEXT("(%t)[%D][%-11M] %I ")

#define WSMAN_TRACE(...)     \
        ACE_DEBUG(( LM_TRACE,  \
                    WSMAN_PREFIX __VA_ARGS__))

#define WSMAN_DEBUG(...)     \
        ACE_DEBUG(( LM_DEBUG,  \
                    WSMAN_PREFIX __VA_ARGS__))

#define WSMAN_WARNING(...)     \
        ACE_DEBUG(( LM_WARNING,  \
                    WSMAN_PREFIX __VA_ARGS__))

#define WSMAN_ERROR(...)     \
        ACE_DEBUG(( LM_ERROR,  \
                    WSMAN_PREFIX __VA_ARGS__))

#define WSMAN_CRITICAL(...)     \
        ACE_DEBUG(( LM_CRITICAL,  \
                    WSMAN_PREFIX __VA_ARGS__))

#endif // _WSMAN_CLIENT_LOG_H