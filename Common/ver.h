/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2005-2022 Intel Corporation
 */
/**                                                                            
********************************************************************************
**
**    @file ver.h
**
**    @brief Contains definitions of the MAJOR, MINOR, & HOTFIX versions used
**           throughout the code.
**
**    @author Christopher Spiegel and John Traver
**
********************************************************************************
*/   

/* Sentry Header
 *****************/
#ifndef _VER_H_
#define _VER_H_

/* Include Files
 *****************/
#include "version.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Global Declarations
 **************************/

/* Flags set based on build type */
#if DBG
/** Define "DBG" string that is attached to version string when DBG build */
#define VER_DEBUG_TAG   " (DBG)"
#else
/** Define string that is attached to version string when release build */
#define VER_DEBUG_TAG   
#endif

/** Combined file version information  */
#define _MAKE_VER_STRING(maj, min, submin, bld)    #maj "." #min "." #submin "." #bld
#define MAKE_VER_STRING(maj, min, submin, bld)    _MAKE_VER_STRING(maj, min, submin, bld)

#define VER_PRODUCTVERSION          MAJOR_VERSION,MINOR_VERSION,QUICK_FIX_NUMBER,VER_BUILD
#define VER_PRODUCTVERSION_STR      MAKE_VER_STRING(MAJOR_VERSION, MINOR_VERSION, QUICK_FIX_NUMBER, VER_BUILD) VER_DEBUG_TAG

#ifdef __cplusplus
}
#endif

#endif // _VER_H_

