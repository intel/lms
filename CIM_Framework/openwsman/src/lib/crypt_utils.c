/*******************************************************************************
* Copyright (C) 2004-2006 Intel Corp. All rights reserved.
*
* Redistribution and use in source and binary forms, with or without
* modification, are permitted provided that the following conditions are met:
*
*  - Redistributions of source code must retain the above copyright notice,
*    this list of conditions and the following disclaimer.
*
*  - Redistributions in binary form must reproduce the above copyright notice,
*    this list of conditions and the following disclaimer in the documentation
*    and/or other materials provided with the distribution.
*
*  - Neither the name of Intel Corp. nor the names of its
*    contributors may be used to endorse or promote products derived from this
*    software without specific prior written permission.
*
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ``AS IS''
* AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
* IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
* ARE DISCLAIMED. IN NO EVENT SHALL Intel Corp. OR THE CONTRIBUTORS
* BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
* CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
* SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
* INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
* CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
* ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
* POSSIBILITY OF SUCH DAMAGE.
*******************************************************************************/

/*++

@file: CryptUtils.cpp

--*/

#include "crypt_utils.h"
#include "string.h"

#include <stdbool.h>
#ifdef _WIN32
	#include <windows.h>
#else
	#include <stdlib.h>
	#include <string.h> 
#endif // _WIN32


static bool Crypt(int encrypt, const void *data, unsigned long *size, void **out)
{
#ifdef _WIN32
	DATA_BLOB DataIn, DataOut;
	bool res;

	if ((data == NULL) || (*size == 0))
	{
		*out = NULL;
		return true;
	}

	DataIn.pbData = (BYTE*)data;
	DataIn.cbData = *size;

	if (encrypt)
	{
		res = CryptProtectData(&DataIn, L"DONT_REMOVE", NULL, NULL, NULL, 0, &DataOut);
	}
	else
	{
		res = CryptUnprotectData(&DataIn, NULL, NULL, NULL, NULL, 0, &DataOut);
	}

	if (!res)
	{
		return false;
	}
	*out = DataOut.pbData;
	*size = DataOut.cbData;

#else
	//no encryption in linux
	*out = (char*)malloc(*size);
	if (*out == NULL) {
		return false;
	}
	memcpy(*out, data, *size);
#endif // _WIN32

	return true;
}

static bool Decrypt(const void *data, unsigned long *size, void **out)
{
	return Crypt(0, data, size, out);
}

char * DecryptString(const char * encryptedString, size_t encryptedStringLen)
{
	unsigned long stringLen = encryptedStringLen;
	char *decryptedString = NULL;

	if (Decrypt(encryptedString, &stringLen, (void**)&decryptedString) == false || decryptedString == NULL)
	{
		free(decryptedString);
		return NULL;
	}

	decryptedString[stringLen] = '\0';

	return decryptedString;
}
