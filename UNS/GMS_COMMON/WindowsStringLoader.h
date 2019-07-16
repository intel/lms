/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2009-2019 Intel Corporation
 */
/*++

@file: WindowsStringLoader.h

--*/

//-------------------------------------------------------------------------------------------
//
//  Contents:   definition to the string loader for Windows(R)  - used to load strings of correct language
//              from embedded rc file in Windows
//
//--------------------------------------------------------------------------------------------
#ifndef _WIN_STRING_LOADER_H_
#define _WIN_STRING_LOADER_H_

#include "StringManager.h"
#include "GMSCommonDllExport.h"

//StringLoader for windows
class GMS_COMMON_EXPORT WindowsStringLoader : public StringLoader
{
public:
	//load the strings with IDs from given vector into the map,throws exception on failure
	void loadStrings(std::vector<unsigned int>& ids,std::map<unsigned int,STRING_TYPE>& stringMap);
	virtual ~WindowsStringLoader() {}
private:
	//load string from embedded rc file, according to OS language, returns empty string on failure
	STRING_TYPE loadString(unsigned int id);
};

#endif //_WIN_STRING_LOADER_H_
