/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2009-2019 Intel Corporation
 */
/*++

@file: RegistryStorage.h

--*/

#ifndef _REGISTRY_STORAGE_H_
#define _REGISTRY_STORAGE_H_

#include "DataStorageWrapper.h"
#include "UNSRegistry.h"
#include <unordered_map>
#include <memory>
#include <utility>
#include <vector>
#include "GMSCommonDllExport.h"

typedef std::pair<LmsRegStr /*KEY*/, LmsRegStr /*value name*/> RegEntry;
typedef std::vector<RegEntry > RegEntryMap;

typedef std::vector<LmsRegStr> MajorSubKeysList;

class GMS_COMMON_EXPORT RegistryStorage : public DataStorageWrapperImpl
{
public:
	friend DataStorageWrapper& GenerateDS(); 
	
	virtual ~RegistryStorage();
	virtual bool CleanDataStorage();
	virtual bool DeleteDataVal(DATA_NAME name);
	virtual bool GetDataValue(DATA_NAME name, std::string& value, bool withCache = true);
	virtual bool GetDataValue(DATA_NAME name, std::wstring& value, bool withCache = true);
	virtual bool GetDataValue(DATA_NAME name, unsigned long& value, bool withCache = true);
	virtual bool SetDataValue(DATA_NAME name, const std::string& value, bool withCache = true);
	virtual bool SetDataValue(DATA_NAME name, const std::wstring& value, bool withCache = true);
	virtual bool SetDataValue(DATA_NAME name, unsigned long value, bool withCache = true);
	virtual bool ValueExists(DATA_NAME name);
private:

	//used to generate the RegistryStorage instance before any thread is created (generation in the first call to GenerateDS() is not thread-safe)
	class RegistryInitializer 
	{
		RegistryInitializer();
		static RegistryInitializer  initializer;
	};

	bool RegDelnode(const LmsRegStr &lpSubKey);
	bool DeleteRegEntry(RegEntry& entry);
	bool GetRegistryData(void* value, size_t* valsz, unsigned long* type,
		const LmsRegStr &key, const LmsRegStr &valueName, bool withCache);
	bool SetRegistryData(const void* value, size_t valsz, unsigned long type,
		const LmsRegStr &key, const LmsRegStr &valueName, bool withCache);
	
	RegistryStorage(const std::shared_ptr<RegEntryMap> &regMap, const std::shared_ptr<MajorSubKeysList> &keyList);
	
	std::shared_ptr< RegEntryMap > _regMap;
	std::shared_ptr< MajorSubKeysList > _keyLists;
};


#endif //_REGISTRY_STORAGE_H_
