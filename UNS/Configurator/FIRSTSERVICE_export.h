/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2009-2019 Intel Corporation
 */
// -*- C++ -*-
// $Id$
// Definition for Win32 Export directives.
// This file is generated automatically by generate_export_file.pl FirstService
// ------------------------------
#ifndef FIRSTSERVICE_EXPORT_H
#define FIRSTSERVICE_EXPORT_H

#include "ace/config-all.h"

#if defined (ACE_AS_STATIC_LIBS) && !defined (FIRSTSERVICE_HAS_DLL)
#  define FIRSTSERVICE_HAS_DLL 0
#endif /* ACE_AS_STATIC_LIBS && FIRSTSERVICE_HAS_DLL */

#if !defined (FIRSTSERVICE_HAS_DLL)
#  define FIRSTSERVICE_HAS_DLL 1
#endif /* ! FIRSTSERVICE_HAS_DLL */

#if defined (FIRSTSERVICE_HAS_DLL) && (FIRSTSERVICE_HAS_DLL == 1)
#  if defined (FIRSTSERVICE_BUILD_DLL)
#    define FIRSTSERVICE_Export ACE_Proper_Export_Flag
#    define FIRSTSERVICE_SINGLETON_DECLARATION(T) ACE_EXPORT_SINGLETON_DECLARATION (T)
#    define FIRSTSERVICE_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK) ACE_EXPORT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#  else /* FIRSTSERVICE_BUILD_DLL */
#    define FIRSTSERVICE_Export ACE_Proper_Import_Flag
#    define FIRSTSERVICE_SINGLETON_DECLARATION(T) ACE_IMPORT_SINGLETON_DECLARATION (T)
#    define FIRSTSERVICE_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK) ACE_IMPORT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#  endif /* FIRSTSERVICE_BUILD_DLL */
#else /* FIRSTSERVICE_HAS_DLL == 1 */
#  define FIRSTSERVICE_Export
#  define FIRSTSERVICE_SINGLETON_DECLARATION(T)
#  define FIRSTSERVICE_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#endif /* FIRSTSERVICE_HAS_DLL == 1 */

// Set FIRSTSERVICE_NTRACE = 0 to turn on library specific tracing even if
// tracing is turned off for ACE.
#if !defined (FIRSTSERVICE_NTRACE)
#  if (ACE_NTRACE == 1)
#    define FIRSTSERVICE_NTRACE 1
#  else /* (ACE_NTRACE == 1) */
#    define FIRSTSERVICE_NTRACE 0
#  endif /* (ACE_NTRACE == 1) */
#endif /* !FIRSTSERVICE_NTRACE */

#if (FIRSTSERVICE_NTRACE == 1)
#  define FIRSTSERVICE_TRACE(X)
#else /* (FIRSTSERVICE_NTRACE == 1) */
#  if !defined (ACE_HAS_TRACE)
#    define ACE_HAS_TRACE
#  endif /* ACE_HAS_TRACE */
#  define FIRSTSERVICE_TRACE(X) ACE_TRACE_IMPL(X)
#  include "ace/Trace.h"
#endif /* (FIRSTSERVICE_NTRACE == 1) */

#endif /* FIRSTSERVICE_EXPORT_H */

// End of auto generated file.
