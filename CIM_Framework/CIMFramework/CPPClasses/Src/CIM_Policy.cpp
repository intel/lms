//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_Policy.cpp
//
//  Contents:   An abstract class defining the common properties of the policy managed elements derived from CIM_Policy. The subclasses are used to create rules and groups of rules that work together to form a coherent set of policies within an administrative domain or set of domains.
//
//              This file was automatically generated from CIM_Policy.mof,  version: 2.6.0
//
//----------------------------------------------------------------------------
#include "CIM_Policy.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	const CimFieldAttribute CIM_Policy::_metadata[] = {
		{"CommonName", false, false, false },
		{"PolicyKeywords", false, false, false },
	};
	// class fields
	const string CIM_Policy::CommonName() const
	{
		return GetField("CommonName")[0];
	}
	void CIM_Policy::CommonName(const string &value)
	{
		SetOrAddField("CommonName", value);
	}
	bool CIM_Policy::CommonNameExists() const
	{
		return ContainsField("CommonName");
	}
	void CIM_Policy::RemoveCommonName()
	{
		RemoveField("CommonName");
	}

	const vector<string> CIM_Policy::PolicyKeywords() const
	{
		vector<string> ret;
		TypeConverter::StringToType(GetField("PolicyKeywords"), ret);
		return ret;
	}
	void CIM_Policy::PolicyKeywords(const vector<string> &value)
	{
		SetOrAddField("PolicyKeywords", TypeConverter::TypeToString(value));
	}
	bool CIM_Policy::PolicyKeywordsExists() const
	{
		return ContainsField("PolicyKeywords");
	}
	void CIM_Policy::RemovePolicyKeywords()
	{
		RemoveField("PolicyKeywords");
	}

	CimBase *CIM_Policy::CreateFromCimObject(const CimObject &object)
	{
		CIM_Policy *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<CIM_Policy>(object);
		}
		else
		{
			ret = new CIM_Policy(object);
		}
		return ret;
	}

	vector<shared_ptr<CIM_Policy> > CIM_Policy::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<CIM_Policy>(client, keys);
	}

	void CIM_Policy::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &CIM_Policy::GetMetaData() const
	{
		return _classMetaData;
	}
	const string CIM_Policy::CLASS_NAME = "CIM_Policy";
	const string CIM_Policy::CLASS_URI = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_Policy";
	const string CIM_Policy::CLASS_NS = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_Policy";
	const string CIM_Policy::CLASS_NS_PREFIX = "APo38";
	CIMFRAMEWORK_API vector <CimFieldAttribute> CIM_Policy::_classMetaData;
}
}
}
}
