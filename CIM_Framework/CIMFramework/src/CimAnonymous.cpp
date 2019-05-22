//----------------------------------------------------------------------------
//
// Copyright (c) Intel Corporation, 2003 - 2009  All Rights Reserved.
//
//  File: CimAnonymous.cpp  
//
//  Contents: Class which represent unknown recieved class form the FW, implementation. 
//
//----------------------------------------------------------------------------

#include "CimAnonymous.h"


namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	CimAnonymous::CimAnonymous(ICimWsmanClient *client, const string &objectName,
			const string &nameSpace, const string &prefix, const string &resourceURI)
			: CimBase(client, objectName, nameSpace, prefix, resourceURI)
	{
	}

	CimAnonymous::CimAnonymous(const CimObject &object)
		: CimBase(object){}

	CimAnonymous::~CimAnonymous() { }

	CimObject CimAnonymous::GetUnTyped() const
	{
		return CimBase::GetUnTyped();
	}

	string CimAnonymous::Serialize() const
	{
		return CimBase::Serialize();
	}

	void CimAnonymous::Deserialize(const string &xml)
	{
		CimBase::Deserialize(xml);
	}

};
};
};
};

