//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       IPS_ScreenSettingData.cpp
//
//  Contents:   The IPS_ScreenSettingData class represents Extended Displays Configuration settings for KVM redirection service in the Intel(R) AMT.
//
//              This file was automatically generated from IPS_ScreenSettingData.mof,  version: 8.0.0
//
//----------------------------------------------------------------------------
#include "IPS_ScreenSettingData.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	const CimFieldAttribute IPS_ScreenSettingData::_metadata[] = {
		{"PrimaryIndex", false, false, false },
		{"SecondaryIndex", false, false, false },
		{"TertiaryIndex", false, false, false },
		{"QuadraryIndex", false, false, false },
		{"IsActive", false, false, false },
		{"UpperLeftX", false, false, false },
		{"UpperLeftY", false, false, false },
		{"ResolutionX", false, false, false },
		{"ResolutionY", false, false, false },
	};
	// class fields
	const unsigned char IPS_ScreenSettingData::PrimaryIndex() const
	{
		unsigned char ret = 0;
		TypeConverter::StringToType(GetField("PrimaryIndex"), ret);
		return ret;
	}
	void IPS_ScreenSettingData::PrimaryIndex(const unsigned char &value)
	{
		SetOrAddField("PrimaryIndex", TypeConverter::TypeToString(value));
	}
	bool IPS_ScreenSettingData::PrimaryIndexExists() const
	{
		return ContainsField("PrimaryIndex");
	}
	void IPS_ScreenSettingData::RemovePrimaryIndex()
	{
		RemoveField("PrimaryIndex");
	}

	const unsigned char IPS_ScreenSettingData::SecondaryIndex() const
	{
		unsigned char ret = 0;
		TypeConverter::StringToType(GetField("SecondaryIndex"), ret);
		return ret;
	}
	void IPS_ScreenSettingData::SecondaryIndex(const unsigned char &value)
	{
		SetOrAddField("SecondaryIndex", TypeConverter::TypeToString(value));
	}
	bool IPS_ScreenSettingData::SecondaryIndexExists() const
	{
		return ContainsField("SecondaryIndex");
	}
	void IPS_ScreenSettingData::RemoveSecondaryIndex()
	{
		RemoveField("SecondaryIndex");
	}

	const unsigned char IPS_ScreenSettingData::TertiaryIndex() const
	{
		unsigned char ret = 0;
		TypeConverter::StringToType(GetField("TertiaryIndex"), ret);
		return ret;
	}
	void IPS_ScreenSettingData::TertiaryIndex(const unsigned char &value)
	{
		SetOrAddField("TertiaryIndex", TypeConverter::TypeToString(value));
	}
	bool IPS_ScreenSettingData::TertiaryIndexExists() const
	{
		return ContainsField("TertiaryIndex");
	}
	void IPS_ScreenSettingData::RemoveTertiaryIndex()
	{
		RemoveField("TertiaryIndex");
	}

	const unsigned char IPS_ScreenSettingData::QuadraryIndex() const
	{
		unsigned char ret = 0;
		TypeConverter::StringToType(GetField("QuadraryIndex"), ret);
		return ret;
	}
	void IPS_ScreenSettingData::QuadraryIndex(const unsigned char &value)
	{
		SetOrAddField("QuadraryIndex", TypeConverter::TypeToString(value));
	}
	bool IPS_ScreenSettingData::QuadraryIndexExists() const
	{
		return ContainsField("QuadraryIndex");
	}
	void IPS_ScreenSettingData::RemoveQuadraryIndex()
	{
		RemoveField("QuadraryIndex");
	}

	const vector<bool> IPS_ScreenSettingData::IsActive() const
	{
		vector<bool> ret;
		TypeConverter::StringToType(GetField("IsActive"), ret);
		return ret;
	}
	void IPS_ScreenSettingData::IsActive(const vector<bool> &value)
	{
		SetOrAddField("IsActive", TypeConverter::TypeToString(value));
	}
	bool IPS_ScreenSettingData::IsActiveExists() const
	{
		return ContainsField("IsActive");
	}
	void IPS_ScreenSettingData::RemoveIsActive()
	{
		RemoveField("IsActive");
	}

	const vector<int> IPS_ScreenSettingData::UpperLeftX() const
	{
		vector<int> ret;
		TypeConverter::StringToType(GetField("UpperLeftX"), ret);
		return ret;
	}
	void IPS_ScreenSettingData::UpperLeftX(const vector<int> &value)
	{
		SetOrAddField("UpperLeftX", TypeConverter::TypeToString(value));
	}
	bool IPS_ScreenSettingData::UpperLeftXExists() const
	{
		return ContainsField("UpperLeftX");
	}
	void IPS_ScreenSettingData::RemoveUpperLeftX()
	{
		RemoveField("UpperLeftX");
	}

	const vector<int> IPS_ScreenSettingData::UpperLeftY() const
	{
		vector<int> ret;
		TypeConverter::StringToType(GetField("UpperLeftY"), ret);
		return ret;
	}
	void IPS_ScreenSettingData::UpperLeftY(const vector<int> &value)
	{
		SetOrAddField("UpperLeftY", TypeConverter::TypeToString(value));
	}
	bool IPS_ScreenSettingData::UpperLeftYExists() const
	{
		return ContainsField("UpperLeftY");
	}
	void IPS_ScreenSettingData::RemoveUpperLeftY()
	{
		RemoveField("UpperLeftY");
	}

	const vector<unsigned int> IPS_ScreenSettingData::ResolutionX() const
	{
		vector<unsigned int> ret;
		TypeConverter::StringToType(GetField("ResolutionX"), ret);
		return ret;
	}
	void IPS_ScreenSettingData::ResolutionX(const vector<unsigned int> &value)
	{
		SetOrAddField("ResolutionX", TypeConverter::TypeToString(value));
	}
	bool IPS_ScreenSettingData::ResolutionXExists() const
	{
		return ContainsField("ResolutionX");
	}
	void IPS_ScreenSettingData::RemoveResolutionX()
	{
		RemoveField("ResolutionX");
	}

	const vector<unsigned int> IPS_ScreenSettingData::ResolutionY() const
	{
		vector<unsigned int> ret;
		TypeConverter::StringToType(GetField("ResolutionY"), ret);
		return ret;
	}
	void IPS_ScreenSettingData::ResolutionY(const vector<unsigned int> &value)
	{
		SetOrAddField("ResolutionY", TypeConverter::TypeToString(value));
	}
	bool IPS_ScreenSettingData::ResolutionYExists() const
	{
		return ContainsField("ResolutionY");
	}
	void IPS_ScreenSettingData::RemoveResolutionY()
	{
		RemoveField("ResolutionY");
	}

	CimBase *IPS_ScreenSettingData::CreateFromCimObject(const CimObject &object)
	{
		IPS_ScreenSettingData *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<IPS_ScreenSettingData>(object);
		}
		else
		{
			ret = new IPS_ScreenSettingData(object);
		}
		return ret;
	}

	vector<shared_ptr<IPS_ScreenSettingData> > IPS_ScreenSettingData::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<IPS_ScreenSettingData>(client, keys);
	}

	void IPS_ScreenSettingData::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &IPS_ScreenSettingData::GetMetaData() const
	{
		return _classMetaData;
	}
	unsigned int IPS_ScreenSettingData::ResetToDefault()
	{
		CimEmptyParam input;
		CimEmptyParam output;
		return Invoke("ResetToDefault", input, output);
	}
	const string IPS_ScreenSettingData::CLASS_NAME = "IPS_ScreenSettingData";
	const string IPS_ScreenSettingData::CLASS_URI = "http://intel.com/wbem/wscim/1/ips-schema/1/IPS_ScreenSettingData";
	const string IPS_ScreenSettingData::CLASS_NS = "http://intel.com/wbem/wscim/1/ips-schema/1/IPS_ScreenSettingData";
	const string IPS_ScreenSettingData::CLASS_NS_PREFIX = "ASc29";
	CIMFRAMEWORK_API vector <CimFieldAttribute> IPS_ScreenSettingData::_classMetaData;
}
}
}
}
