/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2009-2019 Intel Corporation
 */
/*++

@file: RegistryCache.h

--*/

#ifndef __REGISTRY__CACHE_H
#define __REGISTRY__CACHE_H

#include <mutex>
#include <map>
#include <string>

class RegistryCache
{
public:
	typedef std::pair<std::string, unsigned long> regCachePair_t;
	typedef std::map<LmsRegStr, regCachePair_t> regCache_t;

private:
	static regCache_t _regCache;
	static std::mutex _cacheSemaphore;

public:

	static bool GetData(void *value, unsigned long *valsz, unsigned long *type,
						const LmsRegStr &base0, const LmsRegStr &key,
						const LmsRegStr &valuename)
	{
		bool res = false;

		LmsRegStr cacheKey = key;
		cacheKey += LMS_REG_TEXT("_");
		cacheKey += valuename;
		*type=1;

		do
		{
			std::lock_guard<std::mutex> lock(_cacheSemaphore);

			if (_regCache.find(cacheKey) == _regCache.end())
			{
				res = false;
				break;
			}

			if (value == NULL)
			{
				if (valsz != NULL)
				{					
					*valsz = _regCache[cacheKey].first.length();
					*type = _regCache[cacheKey].second;



					res = true;
					break;
				}
				else
				{
					res = false;
					break;
				}
			}
			else
			if (valsz != NULL)
			{	
				if (_regCache[cacheKey].first.length() <= *valsz)
				{
					std::copy(_regCache[cacheKey].first.begin(), _regCache[cacheKey].first.end(), reinterpret_cast<char*>(value));
					*type = _regCache[cacheKey].second;
					res = true;
					break;
				}
				else
				{
					*valsz = _regCache[cacheKey].first.length();
					res = false;
					break;
				}
			}

		}while(false);

		return res;
	}
	
	static void SetData(const void *value, unsigned long valsz, unsigned long type,
						const LmsRegStr &base0, const LmsRegStr &key,
						const LmsRegStr &valuename)
	{
		LmsRegStr cacheKey = key;
		cacheKey += LMS_REG_TEXT("_");
		cacheKey += valuename;

		if (value == NULL)
		{
			return;
		}

		std::string data(reinterpret_cast<const char*>(value), valsz);
		regCachePair_t element(data, type);
		std::lock_guard<std::mutex> lock(_cacheSemaphore);
		_regCache[cacheKey] = element;
	}

	static void DeleteData(const LmsRegStr &base0, const LmsRegStr &key, const LmsRegStr &valuename)
	{
		LmsRegStr cacheKey = key;
		cacheKey += LMS_REG_TEXT("_");
		cacheKey += valuename;
		std::lock_guard<std::mutex> lock(_cacheSemaphore);
		regCache_t::iterator pos = _regCache.find(cacheKey);
		if (pos != _regCache.end())
		{
			_regCache.erase(pos);
		}
	}
};

#define DECLARE_CACHE()	RegistryCache::regCache_t RegistryCache::_regCache; \
						std::mutex RegistryCache::_cacheSemaphore; 


#endif 