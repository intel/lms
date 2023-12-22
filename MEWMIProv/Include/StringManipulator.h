/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2013-2023 Intel Corporation
 */
#ifndef __STRING_MANIPULATOR_H
#define __STRING_MANIPULATOR_H

#include <string>
#include <vector>
#include <algorithm>

inline std::wstring ToWStr(const std::string& s)
{
	std::wstring str2(s.length(), L' '); // Make room for characters

	// Copy string to wstring.
	std::copy(s.begin(), s.end(), str2.begin());
	return str2;
}

inline std::wstring UTF8ToWStr(const std::string& s)
{
	const char* p = s.c_str();
	std::setlocale(LC_ALL, "en_US.utf8");
	std::mbstate_t state = std::mbstate_t();
	std::size_t len = 1 + std::mbsrtowcs(nullptr, &p, 0, &state);
	std::wstring wstr(len, '\0');
	std::mbsrtowcs(&wstr[0], &p, wstr.size(), &state);
	return wstr;
}

#endif //__STRING_MANIPULATOR_H