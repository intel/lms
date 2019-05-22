/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2013-2015 Intel Corporation
 */
#ifndef __STRING_MANIPULATOR_H
#define __STRING_MANIPULATOR_H

#include <string>
#include <algorithm>

inline std::wstring ToWStr(const std::string& s)
{
	std::wstring str2(s.length(), L' '); // Make room for characters

	// Copy string to wstring.
	std::copy(s.begin(), s.end(), str2.begin());
	return str2;
}

#endif //__STRING_MANIPULATOR_H