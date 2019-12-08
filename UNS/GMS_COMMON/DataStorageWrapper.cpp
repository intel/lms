/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2009-2019 Intel Corporation
 */
/*++

@file: DataStorageWrapper.cpp

--*/

#include "DataStorageWrapper.h"

DataStorageWrapper::DataStorageWrapper(const std::shared_ptr<DataStorageWrapperImpl> &impl) : _impl(impl) {}

DataStorageWrapper::~DataStorageWrapper() {}



bool
DataStorageWrapper::CleanDataStorage()
{
	return _impl->CleanDataStorage();
}

bool 
DataStorageWrapper::DeleteDataVal(DATA_NAME name)
{
	return _impl->DeleteDataVal(name);
}

bool
DataStorageWrapper::GetDataValue(DATA_NAME name, std::string& value, bool withCache)
{
	return _impl->GetDataValue(name, value, withCache);
}

bool
DataStorageWrapper::GetDataValue(DATA_NAME name, std::wstring& value, bool withCache)
{
	return _impl->GetDataValue(name, value, withCache);
}

bool
DataStorageWrapper::GetDataValue(DATA_NAME name, unsigned long& value, bool withCache)
{
	return _impl->GetDataValue(name, value, withCache);
}

bool 
DataStorageWrapper::SetDataValue(DATA_NAME name, unsigned long value, bool withCache)
{
	return _impl->SetDataValue(name, value, withCache);
}

bool
DataStorageWrapper::SetDataValue(DATA_NAME name, const std::string& value, bool withCache)
{
	return _impl->SetDataValue(name, value, withCache);
}

bool
DataStorageWrapper::SetDataValue(DATA_NAME name, const std::wstring& value, bool withCache)
{
	return _impl->SetDataValue(name, value, withCache);
}

bool 
DataStorageWrapper::ValueExists(DATA_NAME name)
{
	return _impl->ValueExists(name);
}
