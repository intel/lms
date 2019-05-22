/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2009-2019 Intel Corporation
 */
/*++

@file: WindowsStringLoader.cpp

--*/

//-------------------------------------------------------------------------------------------
//
//  Copyright (C) Intel Corporation, 2012.
//
//  File:       WindowsStringLoader.cpp
//
//  Contents:   defenition to the string loader for Windows(R)  - used to load strings of correct language
//              from embedded rc file in Windows 
//
//--------------------------------------------------------------------------------------------

#include <map>
#include <windows.h>
#include "WindowsStringLoader.h"
#include "UNSDebug.h"

//load string from embedded rc file, according to OS language, returns empty string on failure
STRING_TYPE WindowsStringLoader::loadString(unsigned int id)
{
	CHAR_TYPE char_arr[MAX_STRING_LEN];
	ZeroMemory(&char_arr[0],sizeof(char_arr));
	if (LoadString(GetModuleHandle(NULL),id,&char_arr[0],MAX_STRING_LEN)<=0)
	{
		DbgPrintW(L"WindowsStringLoader::loadString - LoadString failed with error %lu",L"\n",GetLastError());
		return EMPTY_STR;
	}

	return STRING_TYPE(char_arr);
}

//load the strings with IDs from given vector into the map,throws exception on failure
void WindowsStringLoader::loadStrings(std::vector<unsigned int>& ids,std::map<unsigned int,STRING_TYPE>& stringMap)
{
	std::vector<unsigned int>::iterator itr;
	STRING_TYPE str;

	for (itr=ids.begin(); itr<ids.end(); ++itr)
	{
		str = loadString(*itr);
		if (!str.empty())
		{
			stringMap.insert(std::pair<unsigned int,STRING_TYPE>(*itr,str));
		}
	}
}
