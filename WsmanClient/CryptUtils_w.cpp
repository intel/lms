/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2009-2019 Intel Corporation
 */
/*++

@file: CryptUtils_w.cpp

--*/

//----------------------------------------------------------------------------
//
//  Copyright (C) Intel Corporation, 2007.
//
//  File:       CryptUtils_w.cpp
//
//  Notes:      Implemintation of Crypt utils
//----------------------------------------------------------------------------
#include "CryptUtils_w.h"
#ifdef _WIN32
	#include <objbase.h>
	#include <process.h>
	#include <wincrypt.h>
#else
	#include <algorithm>
#endif // _WIN32

WSmanCrypt::WSmanCrypt()
{

}


bool WSmanCrypt::Crypt(bool encrypt, const void *data, unsigned long *size, void **out)
{
#ifdef _WIN32
	DATA_BLOB DataIn, DataOut;
	BOOL res;

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
	// buffers of same size
	std::copy_n(reinterpret_cast<const char*>(data), *size, reinterpret_cast<char*>(*out));
#endif // _WIN32

	return true;
}

bool WSmanCrypt::Decrypt(const void *data, unsigned long *size, void **out)
{
	return Crypt(false, data, size, out);
}

bool WSmanCrypt::Encrypt(const void *data, unsigned long *size, void **out)
{
	return Crypt(true, data, size, out);
}

std::string  WSmanCrypt::EncryptString(std::string &decryptedString)
{
	unsigned char *encryptedString = NULL;
	unsigned long stringLen;
	std::string encryptedStringAsString = "";

	stringLen = (unsigned long)decryptedString.size();

	if (Encrypt(decryptedString.c_str(), &stringLen, (void**)&encryptedString) == false || encryptedString == NULL)
	{
		if (encryptedString != NULL)
		{
			free(encryptedString);
		}
		std::fill(decryptedString.begin(), decryptedString.end(), 0);
		return encryptedStringAsString;
	}

	std::fill(decryptedString.begin(), decryptedString.end(), 0);

	encryptedStringAsString = std::string((char*)encryptedString, stringLen);

	if (encryptedString != NULL)
	{
		free(encryptedString);
	}

	return encryptedStringAsString;
}

std::string WSmanCrypt::DecryptString(const std::string &encryptedString)
{
	unsigned long stringLen = 0;
	unsigned char *decryptedString = NULL;
	std::string decryptedStringAsString = "";

	stringLen = (unsigned long)encryptedString.size();

	if (Decrypt(encryptedString.c_str(), &stringLen, (void**)&decryptedString) == false || decryptedString == NULL)
	{
		if (decryptedString != NULL)
		{
			free(decryptedString);
		}
		return decryptedStringAsString;
	}

	decryptedStringAsString = std::string((char*)decryptedString, stringLen);

	if (decryptedString != NULL)
	{
		free(decryptedString);
	}

	return decryptedStringAsString;
}
