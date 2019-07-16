/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2009-2019 Intel Corporation
 */
/*++

@file: DataStorageWrapper.h

--*/

//----------------------------------------------------------------------------
//
//  Contents:   definition to the registry wrapper
//
//----------------------------------------------------------------------------

#ifndef _DATA_STORAGE_WRAPPER_H_
#define _DATA_STORAGE_WRAPPER_H_

#include <string>
#include <memory>
#include "GMSCommonDllExport.h"

enum ValueTypes {
	VAL_NONE = 0,
	VAL_STR = 1, //REG_SZ
	VAL_BIN = 3,
	VAL_ULONG = 4 //REG_DWORD
};

enum DATA_NAME : unsigned int;

class DataStorageWrapperImpl
{
public:
	virtual bool CleanDataStorage() = 0;
	virtual bool DeleteDataVal(DATA_NAME name) = 0;
	virtual bool GetDataValue(DATA_NAME name, std::string& value, bool withCache) = 0;
	virtual bool GetDataValue(DATA_NAME name, std::wstring& value, bool withCache) = 0;
	virtual bool GetDataValue(DATA_NAME name, unsigned long& value, bool withCache) = 0;
	virtual bool SetDataValue(DATA_NAME name, const std::string& value, bool withCache) = 0;
	virtual bool SetDataValue(DATA_NAME name, const std::wstring& value, bool withCache) = 0;
	virtual bool SetDataValue(DATA_NAME name, unsigned long value, bool withCache) = 0;
	virtual bool ValueExists(DATA_NAME name) = 0;
};

class GMS_COMMON_EXPORT DataStorageWrapper
{
public:
	friend DataStorageWrapper& GenerateDS();
	virtual ~DataStorageWrapper();
	virtual bool CleanDataStorage();
	virtual bool DeleteDataVal(DATA_NAME name);
	virtual bool GetDataValue(DATA_NAME name, std::string& value, bool withCache = true);
	virtual bool GetDataValue(DATA_NAME name, std::wstring& value, bool withCache = true);
	virtual bool GetDataValue(DATA_NAME name, unsigned long& value, bool withCache = true);
	virtual bool SetDataValue(DATA_NAME name, const std::string& value, bool withCache = true);
	virtual bool SetDataValue(DATA_NAME name, const std::wstring& value, bool withCache = true);
	virtual bool SetDataValue(DATA_NAME name, unsigned long value, bool withCache);
	virtual bool ValueExists(DATA_NAME name);
private:
	DataStorageWrapper(std::shared_ptr<DataStorageWrapperImpl> impl);
	std::shared_ptr<DataStorageWrapperImpl> _impl;
};


#endif // _DATA_STORAGE_WRAPPER_H_
