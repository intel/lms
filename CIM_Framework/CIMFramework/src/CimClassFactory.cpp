//----------------------------------------------------------------------------
//
// Copyright (c) Intel Corporation, 2003 - 2009  All Rights Reserved.
//
//  File:       CimClassFactory.cpp
//
//  Contents:   Factory functions for creating typed CIM objects, implementation.
//
//----------------------------------------------------------------------------
#include "CimClassFactory.h"
#include "CimAnonymous.h"
#include "CimSerializer.h"

namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{


CimBase* CimClassFactory::CreateCimClass(const CimObject &object)
{
	CimBase *ret = NULL;
	string objectName = object.ObjectType();
	FactoryMap::const_iterator iter = _cimMap.find(objectName);
	if (iter != CimClassFactory::_cimMap.end())
	{
		ret = iter->second(object);
		return ret;
	}
	
	// In case we received an unknown object
	// return Anonymous
	CimAnonymous *stranger = new CimAnonymous(object);
	return stranger;

}
CimBase* CimClassFactory::CreateCimClass(const CimObject &object, const string &className, const string &baseClassName)
{
	CimBase *ret = NULL;
	FactoryMap::const_iterator iter;

	iter = _cimMap.find(className);
	if (iter != CimClassFactory::_cimMap.end())
	{
		ret = iter->second(object);
		return ret;
	}

	// In case we can't find the actual class, try to find the base class
	iter = _cimMap.find(baseClassName);
	if (iter != CimClassFactory::_cimMap.end())
	{
		ret = iter->second(object);
		return ret;
	}
	throw CimException("Error in framework logic - recieved unknown class to create: " + className);
}



CimClassFactory::FactoryMap CimClassFactory::_cimMap;
static CimClassFactory Factory;

};
};
};
};
