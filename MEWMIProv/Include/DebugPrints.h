/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2019 Intel Corporation
 */
 //----------------------------------------------------------------------------
 //
 //  File:       DebugPrints.h
 //
 //  Contents:   Debug messages printing
 //
 //  Notes:
 //----------------------------------------------------------------------------
#ifndef _DEBUG_PRINTS__H__
#define _DEBUG_PRINTS__H__

#include <ace/Log_Msg.h>

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


#endif		//_DEBUG_PRINTS__H__
