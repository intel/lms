//----------------------------------------------------------------------------
//
// Copyright (c) Intel Corporation, 2009  All Rights Reserved.
//
//  File:       CimUntypedDllExport.h
//
//  Contents:   File which define declspec for cross-platform portability.
//
//----------------------------------------------------------------------------
#ifndef CIMUNTYPEDDLLEXPORT_H
#define CIMUNTYPEDDLLEXPORT_H 1

#pragma warning(disable: 4275)
#pragma warning(disable: 4251)

#if (defined (_WIN32) || defined (_WIN64)) && defined (CIMUNTYPEDFRAMEWORK_DLL)
	#ifdef CIMUNTYPEDFRAMEWORK_EXPORTS
		#define CIMUNTYPEDFRAMEWORK_API __declspec(dllexport)
	#else
		#define CIMUNTYPEDFRAMEWORK_API __declspec(dllimport)
	#endif
#else
	#define CIMUNTYPEDFRAMEWORK_API
#endif

#endif // CIMUNTYPEDDLLEXPORT_H
