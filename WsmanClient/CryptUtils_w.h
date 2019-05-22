/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2009-2018 Intel Corporation
 */
/*++

@file: CryptUtils_w.h

--*/

//----------------------------------------------------------------------------
//
//  Copyright (C) Intel Corporation, 2007.
//
//  File:       CryptUtils.cpp
//
//  Notes:      Implemintation of Crypt utils
//----------------------------------------------------------------------------

#ifndef _CRYPT_UTILS_W_H
#define _CRYPT_UTILS_W_H

#include "BaseWSManClient.h"
#include <string>

class WSMAN_DLL_API WSmanCrypt 
{
public:
	WSmanCrypt();

	static std::string EncryptString(std::string & decryptedString);
	static std::string DecryptString(const std::string & encryptedString);

private:
	static bool Encrypt(const void *data, unsigned long *size, void **out);
	static bool Decrypt(const void *data, unsigned long *size, void **out);

	static bool Crypt(bool encrypt, const void *data, unsigned long *size, void **out);

};

#endif //_CRYPT_UTILS_W_H