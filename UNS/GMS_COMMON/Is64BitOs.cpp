/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2009-2019 Intel Corporation
 */
 #ifdef _WIN32
#include "Is64BitOs.h"
#include <windows.h>

bool Is64BitOS()
{
	static BOOL bChecked = FALSE;
	static BOOL bIs64BitOS = FALSE;

	if (!bChecked)
	{
		bChecked = TRUE;

		if (!IsWow64Process(GetCurrentProcess(), &bIs64BitOS))
		{
			/*IsWow64Process failed - assuming 32 bit os.*/
			return false;
		}
	}

	return bIs64BitOS ? true : false;
}
#endif
