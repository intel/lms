/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2009-2022 Intel Corporation
 */
/*++

@file: RegistryStorage.cpp

--*/

#include "RegistryStorage.h"
#include "RegistryCache.h"
#include <climits>
#include <memory>

#ifndef REG_SZ
const unsigned long REG_SZ = 1ul;
#endif // REG_SZ
#ifndef REG_DWORD
const unsigned long REG_DWORD = 4ul;
#endif // REG_DWORD

DECLARE_CACHE()

#define CHECK_NAME_VALID(name) \
	do { \
	if (_regMap->size() < ((size_t) name)) \
		return false; \
	} while(0);

RegistryStorage::RegistryStorage(const std::shared_ptr<RegEntryMap> &regMap, const std::shared_ptr<MajorSubKeysList> &keyList):_regMap(regMap), _keyLists(keyList)
{
	/*_regMap.insert(key, RegEntry);
	 ..
	 ..
	*/
}

RegistryStorage::~RegistryStorage()
{
}

bool 
RegistryStorage::CleanDataStorage()
{
	bool success = true;
	for (MajorSubKeysList::iterator itr = _keyLists->begin(); itr != _keyLists->end(); ++itr)
	{
		
		if (!RegDelnode(*itr))
			success = false;
	}
	return success;
}

bool 
RegistryStorage::DeleteDataVal(DATA_NAME name)
{
	CHECK_NAME_VALID(name)
	RegEntry element = _regMap->at(name);
	return DeleteRegEntry(element);
	
}

bool 
RegistryStorage::GetDataValue(DATA_NAME name, std::string& value, bool withCache)
{
	CHECK_NAME_VALID(name)
	unsigned long requestedType = REG_SZ;


	RegEntry entry = _regMap->at(name);
	
	const LmsRegStr &key = entry.first;
	const LmsRegStr &value_name = entry.second;
	size_t valsz = 0;
	unsigned long type;
			
	if (GetRegistryData(NULL, &valsz, &type, key, value_name, withCache) == true)
	{
		if (type != requestedType)
		{
			//type not fit user requested type
			return false;
		}
		std::unique_ptr<char[]> newVal(new char[valsz + 1]);
		if (GetRegistryData(newVal.get(), &valsz, &type, key, value_name, withCache) !=true)
		{
			return false;
		}
		if (valsz == ULONG_MAX) //too long string, will not be able to create a NULL terminated string.
		{
			return false;
		}
		newVal[valsz] = 0;
		value = newVal.get();
		return true;
	}		
    return false;
}

bool 
RegistryStorage::ValueExists(DATA_NAME name)
{
	CHECK_NAME_VALID(name)
	RegEntry entry = _regMap->at(name);
	
	const LmsRegStr &key = entry.first;
	const LmsRegStr &value_name = entry.second;
	size_t valsz = 0;
	unsigned long type;
	if (GetRegistryData(NULL, &valsz, &type, key, value_name, false) == true)
	{
		return true;
	}
	return false;
}

bool 
RegistryStorage::GetDataValue(DATA_NAME name, std::wstring& value, bool withCache)
{
	CHECK_NAME_VALID(name)
	unsigned long requestedType = REG_SZ;
	RegEntry entry = _regMap->at(name);
	const LmsRegStr &key = entry.first;
	const LmsRegStr &value_name = entry.second;
	size_t valsz = 0;
	unsigned long type;
	if (GetRegistryData(NULL, &valsz, &type, key, value_name, withCache) == true)
	{
		if (type != requestedType)
		{
			return false;
		}
		size_t wsize = valsz / sizeof(wchar_t);
		std::unique_ptr<wchar_t[]> newVal(new wchar_t[wsize + 1]);
		if(GetRegistryData(newVal.get(), &valsz, &type, key, value_name, withCache)!=true)
		{
			return false;
		}
		newVal[wsize] = 0;
		value = newVal.get();
		return true;
	}
    return false;
}

bool 
RegistryStorage::GetDataValue(DATA_NAME name, unsigned long& value, bool withCache)
{
	CHECK_NAME_VALID(name)
	unsigned long requestedType = REG_DWORD;
	RegEntry entry = _regMap->at(name);
	
	const LmsRegStr &key = entry.first;
	const LmsRegStr &value_name = entry.second;
	size_t valsz = sizeof(value);
	unsigned long type;
	
	if (GetRegistryData(&value, &valsz, &type, key, value_name, withCache) == true)
	{
		if (type != requestedType)
		{
			//type not fit user requested type
			return false;
		}
		return true;
	}		
		
    return false;
}

bool 
RegistryStorage::SetDataValue(DATA_NAME name, const std::string& value, bool withCache)
{
	CHECK_NAME_VALID(name)
	RegEntry entry = _regMap->at(name);
	unsigned long type = REG_SZ;
	
	const LmsRegStr &key = entry.first;
	const LmsRegStr &value_name = entry.second;
	
	return SetRegistryData(value.c_str(), value.size()+1, type, key, value_name, withCache);
}

bool 
RegistryStorage::SetDataValue(DATA_NAME name, const std::wstring& value, bool withCache)
{
	CHECK_NAME_VALID(name)
	RegEntry entry = _regMap->at(name);
	unsigned long type = REG_SZ;
	const LmsRegStr &key = entry.first;
	const LmsRegStr &value_name = entry.second;
	
	return SetRegistryData(value.c_str(), (value.size()+1)*sizeof(wchar_t), type, key, value_name, withCache);
}

bool 
RegistryStorage::SetDataValue(DATA_NAME name, unsigned long value, bool withCache)
{
	CHECK_NAME_VALID(name)
	RegEntry entry = _regMap->at(name);
	unsigned long type = REG_DWORD;
	
	const LmsRegStr &key = entry.first;
	const LmsRegStr &value_name = entry.second;
	
	return SetRegistryData(&value, sizeof(unsigned long), type, key, value_name, withCache);
}