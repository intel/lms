/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2009-2019 Intel Corporation
 */
// -*- C++ -*-
// $Id$
// Definition for Win32 Export directives.
// This file is generated automatically by generate_export_file.pl LastService
// ------------------------------
#ifndef LASTSERVICE_EXPORT_H
#define LASTSERVICE_EXPORT_H

#include "ace/config-all.h"

#if defined (ACE_AS_STATIC_LIBS) && !defined (LASTSERVICE_HAS_DLL)
#  define LASTSERVICE_HAS_DLL 0
#endif /* ACE_AS_STATIC_LIBS && LASTSERVICE_HAS_DLL */

#if !defined (LASTSERVICE_HAS_DLL)
#  define LASTSERVICE_HAS_DLL 1
#endif /* ! LASTSERVICE_HAS_DLL */

#if defined (LASTSERVICE_HAS_DLL) && (LASTSERVICE_HAS_DLL == 1)
#  if defined (LASTSERVICE_BUILD_DLL)
#    define LASTSERVICE_Export ACE_Proper_Export_Flag
#    define LASTSERVICE_SINGLETON_DECLARATION(T) ACE_EXPORT_SINGLETON_DECLARATION (T)
#    define LASTSERVICE_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK) ACE_EXPORT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#  else /* LASTSERVICE_BUILD_DLL */
#    define LASTSERVICE_Export ACE_Proper_Import_Flag
#    define LASTSERVICE_SINGLETON_DECLARATION(T) ACE_IMPORT_SINGLETON_DECLARATION (T)
#    define LASTSERVICE_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK) ACE_IMPORT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#  endif /* LASTSERVICE_BUILD_DLL */
#else /* LASTSERVICE_HAS_DLL == 1 */
#  define LASTSERVICE_Export
#  define LASTSERVICE_SINGLETON_DECLARATION(T)
#  define LASTSERVICE_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#endif /* LASTSERVICE_HAS_DLL == 1 */

// Set LASTSERVICE_NTRACE = 0 to turn on library specific tracing even if
// tracing is turned off for ACE.
#if !defined (LASTSERVICE_NTRACE)
#  if (ACE_NTRACE == 1)
#    define LASTSERVICE_NTRACE 1
#  else /* (ACE_NTRACE == 1) */
#    define LASTSERVICE_NTRACE 0
#  endif /* (ACE_NTRACE == 1) */
#endif /* !LASTSERVICE_NTRACE */

#if (LASTSERVICE_NTRACE == 1)
#  define LASTSERVICE_TRACE(X)
#else /* (LASTSERVICE_NTRACE == 1) */
#  if !defined (ACE_HAS_TRACE)
#    define ACE_HAS_TRACE
#  endif /* ACE_HAS_TRACE */
#  define LASTSERVICE_TRACE(X) ACE_TRACE_IMPL(X)
#  include "ace/Trace.h"
#endif /* (LASTSERVICE_NTRACE == 1) */

#endif /* LASTSERVICE_EXPORT_H */

// End of auto generated file.
