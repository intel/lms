//----------------------------------------------------------------------------
//
// Copyright (c) Intel Corporation, 2009  All Rights Reserved.
//
//  File:       CimTypedDllExport.h
//
//  Contents:   File which define declspec for cross-platform portability.
//
//----------------------------------------------------------------------------

#ifndef CIMDLLEXPORT_H
#define CIMDLLEXPORT_H 1

#pragma warning(disable: 4275)
#pragma warning(disable: 4251)

#if (defined (_WIN32) || defined (_WIN64)) && defined (CIMFRAMEWORK_DLL)
	#ifdef CIMFRAMEWORK_EXPORTS
		#define CIMFRAMEWORK_API __declspec(dllexport)
	#else
		#define CIMFRAMEWORK_API __declspec(dllimport)
	#endif
#else
	#define CIMFRAMEWORK_API
#endif

#endif // CIMDLLEXPORT_H