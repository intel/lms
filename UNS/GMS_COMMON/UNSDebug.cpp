/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2009-2019 Intel Corporation
 */
/*++

@file: UNSDebug.cpp

--*/
#ifdef _ACEPRINT
#include "ace/Log_Msg.h"
#endif // _ACEPRINT
#include <cstdio>
#include <cstdlib>
#include <cstdarg>
#include "global.h"
#ifdef WIN32
#include <windows.h>
#endif // WIN32
#include "UNSDebug.h"

#ifdef __cplusplus
extern "C"
{
#endif


/*
** DbgPrint - Print Format Output to Debug Console (using Output Debug String)
**
** Parameters:
**	format - printf style format string
*/
#ifdef _DEBUGPRINT
#ifdef _ACEPRINT
const int BUF_SIZE = 2048;
void DbgPrint(const char *fmt, ...)
{
	char out[BUF_SIZE];
	va_list args;
	va_start(args, fmt);
#ifdef WIN32
	vsnprintf_s(out, BUF_SIZE, _TRUNCATE, fmt, args);
#else
	vsnprintf(out, BUF_SIZE, fmt, args);
#endif // WIN32
	UNS_DEBUG(L"UNS: %C\n", out);
	va_end(args);
}

void DbgPrintW(const wchar_t *fmt, ...)
{
	wchar_t out[BUF_SIZE];
	va_list args;
	va_start(args, fmt);
#ifdef WIN32
	vswprintf_s(out, BUF_SIZE, fmt, args);
#else
	vswprintf(out, BUF_SIZE, fmt, args);
#endif // WIN32
	UNS_DEBUG(L"UNS: %W\n", out);
	va_end(args);
}
#else
void DbgPrint(const char *format, ...)
{
    va_list args;
    int     len;
    char    *buffer;

    // retrieve the variable arguments
    va_start( args, format );

    len = _vscprintf( format, args ) // _vscprintf doesn't count
                                + 1; // terminating '\0'

    buffer = (char*)malloc( len * sizeof(char) );
	if (buffer == NULL)
	{
		return;
	}

    vsprintf_s( buffer, len * sizeof(char), format, args ); // C4996

#ifdef OUTPUT_STDOUT
	fputs(buffer, stdout;
#endif

	OutputDebugStringA(buffer);

    free( buffer );

}

void DbgPrintW(const wchar_t *format, ...)
{
	va_list args;
    int     len;
    wchar_t    *buffer;

    // retrieve the variable arguments
    va_start( args, format );

    len = _vscwprintf( format, args ) // _vscprintf doesn't count
                                + 1; // terminating '\0'

    buffer = (wchar_t*)malloc( len * sizeof(wchar_t) );
	if (buffer == NULL)
	{
		return;
	}

    vswprintf_s( buffer, len * sizeof(char), format, args ); // C4996

#ifdef OUTPUT_STDOUT
	fputs(buffer, stdout);
#endif

	OutputDebugStringW(buffer);

    free( buffer );

}
#endif // _ACEPRINT
#endif // _DEBUGPRINT
#ifdef __cplusplus
}
#endif
