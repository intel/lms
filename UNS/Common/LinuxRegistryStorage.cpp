/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2009-2019 Intel Corporation
 */
/*++

@file: LinuxRegistryStorage.cpp

--*/

#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>

#include <fstream>

#include "RegistryStorage.h"
#include "RegistryCache.h"
#include "UNSRegistry.h"

bool DeleteRegistryKey(const std::string &key)
{
	std::string path(GetLmsRegPosition() + key);

	if (unlink(path.c_str()) == -1)
		return false;
	return true;
}

bool DeleteRegistryVal(const std::string &key, const std::string &valuename)
{
	std::string path(GetLmsRegPosition() + key + "/" + valuename);

	if (unlink(path.c_str()) == -1)
		return false;
	return true;
}

#define MAX_DATA 8192

static bool GetRegistryData(void *value, unsigned long *valsz, unsigned long *type,
			    const std::string &key, const std::string &valuename)
{
	std::string path(GetLmsRegPosition() + key + "/" + valuename);
	char tmpval[MAX_DATA];

	std::ifstream file(path);
	if (!file.is_open())
		return false;

	file >> *type;
	if (!file.good())
		return false;

	file.read(tmpval, MAX_DATA);
	if (!file.eof())
		return false;

	if (!value) {
		*valsz = file.gcount();
		return true;
	}

	//file.gcount is limited by MAX_DATA, so unsigned cast is safe
	if (*valsz < (unsigned long)file.gcount()) {
		*valsz = file.gcount();
		return false;
	}

	std::copy(tmpval, tmpval + file.gcount(), reinterpret_cast<char*>(value));
	return true;
}

static bool SetRegistryData(const void* value, unsigned long valsz, unsigned long type,
			    const std::string &key, const std::string &valuename)
{
	std::string path(GetLmsRegPosition());
	const mode_t mode = S_IRWXU | S_IRGRP | S_IXGRP | S_IROTH | S_IXOTH;

	//create path
	if (mkdir(path.c_str(), mode) == -1) {
		if (errno != EEXIST)
			return false;
	}

	path += key;

	//create path
	if (mkdir(path.c_str(), mode) == -1) {
		if (errno != EEXIST)
			return false;
	}

	path += "/" + valuename;

	std::ofstream file(path);
	if (!file.is_open())
		return false;

	file << type;
	if (!file.good())
		return false;

	file.write((const char*)value, valsz);
	if (!file.good())
		return false;

	return true;
}

bool RegistryStorage::RegDelnode(const LmsRegStr &lpSubKey)
{
	return DeleteRegistryKey(lpSubKey);
}

bool
RegistryStorage::DeleteRegEntry(RegEntry& entry)
{
	const LmsRegStr &key = entry.first;
	const LmsRegStr &valueName = entry.second;
	LmsRegStr dummy(LMS_REG_TEXT(""));

	RegistryCache::DeleteData(dummy, key, valueName);

	return DeleteRegistryVal(key, valueName);
}

bool
RegistryStorage::GetRegistryData(void* value, unsigned long* valsz, unsigned long* type,
	const LmsRegStr &key, const LmsRegStr &valueName, bool withCache)
{
	if (!valsz)
		return false;

	LmsRegStr dummy(LMS_REG_TEXT(""));
	bool retval;

	if (withCache)
	{
		if (RegistryCache::GetData(value, valsz, type, dummy, key, valueName) == true)
		{
			return true;
		}
	}

	retval = ::GetRegistryData(value, valsz, type, key, valueName);

	if (withCache && retval == true && value != NULL)
	{
		RegistryCache::SetData(value, *valsz, *type, dummy, key, valueName);
	}
	return retval;
}

bool
RegistryStorage::SetRegistryData(const void* value, unsigned long valsz, unsigned long type,
	const LmsRegStr &key, const LmsRegStr &valueName, bool withCache)
{
	if (!value || (value && (valsz == 0)))
		return false;

	const LmsRegStr dummy(LMS_REG_TEXT(""));
	bool retval;
	retval = ::SetRegistryData(value, valsz, type, key, valueName);

	if (withCache && retval == true)
	{
		RegistryCache::SetData(value, valsz, type, dummy, key, valueName);
	}

	return retval;
}
