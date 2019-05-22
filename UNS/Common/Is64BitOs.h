/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2009-2019 Intel Corporation
 */
 #ifndef _IS_64_BIT_OS_H
#define _IS_64_BIT_OS_H

#include <Windows.h>
#include <tchar.h>

bool Is64BitOS();

///TODO where to put it?
HMODULE SafeLoadDll(const TCHAR * FileName);

#endif //_IS_64_BIT_OS_H