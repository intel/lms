//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       IPS_OptInService.cpp
//
//  Contents:   Describes the user consent service. This service manages user opt-in options and sends a user consent code for KVM, redirection, and set boot options.
//
//              This file was automatically generated from IPS_OptInService.mof,  version: 7.0.0
//
//----------------------------------------------------------------------------
#include "IPS_OptInService.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	const CimFieldAttribute IPS_OptInService::_metadata[] = {
		{"OptInCodeTimeout", false, false, false },
		{"OptInRequired", false, false, false },
		{"OptInState", false, false, false },
		{"CanModifyOptInPolicy", false, false, false },
		{"OptInDisplayTimeout", false, false, false },
	};
	// class fields
	const unsigned int IPS_OptInService::OptInCodeTimeout() const
	{
		unsigned int ret = 0;
		TypeConverter::StringToType(GetField("OptInCodeTimeout"), ret);
		return ret;
	}
	void IPS_OptInService::OptInCodeTimeout(const unsigned int value)
	{
		SetOrAddField("OptInCodeTimeout", TypeConverter::TypeToString(value));
	}
	bool IPS_OptInService::OptInCodeTimeoutExists() const
	{
		return ContainsField("OptInCodeTimeout");
	}
	void IPS_OptInService::RemoveOptInCodeTimeout()
	{
		RemoveField("OptInCodeTimeout");
	}

	const unsigned int IPS_OptInService::OptInRequired() const
	{
		unsigned int ret = 0;
		TypeConverter::StringToType(GetField("OptInRequired"), ret);
		return ret;
	}
	void IPS_OptInService::OptInRequired(const unsigned int value)
	{
		SetOrAddField("OptInRequired", TypeConverter::TypeToString(value));
	}
	bool IPS_OptInService::OptInRequiredExists() const
	{
		return ContainsField("OptInRequired");
	}
	void IPS_OptInService::RemoveOptInRequired()
	{
		RemoveField("OptInRequired");
	}

	const unsigned char IPS_OptInService::OptInState() const
	{
		unsigned char ret = 0;
		TypeConverter::StringToType(GetField("OptInState"), ret);
		return ret;
	}
	void IPS_OptInService::OptInState(const unsigned char &value)
	{
		SetOrAddField("OptInState", TypeConverter::TypeToString(value));
	}
	bool IPS_OptInService::OptInStateExists() const
	{
		return ContainsField("OptInState");
	}
	void IPS_OptInService::RemoveOptInState()
	{
		RemoveField("OptInState");
	}

	const unsigned char IPS_OptInService::CanModifyOptInPolicy() const
	{
		unsigned char ret = 0;
		TypeConverter::StringToType(GetField("CanModifyOptInPolicy"), ret);
		return ret;
	}
	void IPS_OptInService::CanModifyOptInPolicy(const unsigned char &value)
	{
		SetOrAddField("CanModifyOptInPolicy", TypeConverter::TypeToString(value));
	}
	bool IPS_OptInService::CanModifyOptInPolicyExists() const
	{
		return ContainsField("CanModifyOptInPolicy");
	}
	void IPS_OptInService::RemoveCanModifyOptInPolicy()
	{
		RemoveField("CanModifyOptInPolicy");
	}

	const unsigned short IPS_OptInService::OptInDisplayTimeout() const
	{
		unsigned short ret = 0;
		TypeConverter::StringToType(GetField("OptInDisplayTimeout"), ret);
		return ret;
	}
	void IPS_OptInService::OptInDisplayTimeout(const unsigned short value)
	{
		SetOrAddField("OptInDisplayTimeout", TypeConverter::TypeToString(value));
	}
	bool IPS_OptInService::OptInDisplayTimeoutExists() const
	{
		return ContainsField("OptInDisplayTimeout");
	}
	void IPS_OptInService::RemoveOptInDisplayTimeout()
	{
		RemoveField("OptInDisplayTimeout");
	}

	CimBase *IPS_OptInService::CreateFromCimObject(const CimObject &object)
	{
		IPS_OptInService *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<IPS_OptInService>(object);
		}
		else
		{
			ret = new IPS_OptInService(object);
		}
		return ret;
	}

	vector<shared_ptr<IPS_OptInService> > IPS_OptInService::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<IPS_OptInService>(client, keys);
	}

	void IPS_OptInService::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &IPS_OptInService::GetMetaData() const
	{
		return _classMetaData;
	}
	unsigned int IPS_OptInService::StartOptIn()
	{
		CimEmptyParam input;
		CimEmptyParam output;
		return Invoke("StartOptIn", input, output);
	}
	unsigned int IPS_OptInService::CancelOptIn()
	{
		CimEmptyParam input;
		CimEmptyParam output;
		return Invoke("CancelOptIn", input, output);
	}
	const CimFieldAttribute IPS_OptInService::SendOptInCode_INPUT::_metadata[] = {
		{"OptInCode", false, false },
	};
	void IPS_OptInService::SendOptInCode_INPUT::OptInCode(const unsigned int value)
	{
		SetOrAddField("OptInCode", TypeConverter::TypeToString(value));
	}
	const VectorFieldData IPS_OptInService::SendOptInCode_INPUT::GetAllFields() const
	{
		VectorFieldData ret;
		ret = sortData(_metadata, 1);
		return ret;
	}
	unsigned int IPS_OptInService::SendOptInCode(const SendOptInCode_INPUT &input)
	{
		CimEmptyParam output;
		return Invoke("SendOptInCode", input, output);
	}
	const string IPS_OptInService::CLASS_NAME = "IPS_OptInService";
	const string IPS_OptInService::CLASS_URI = "http://intel.com/wbem/wscim/1/ips-schema/1/IPS_OptInService";
	const string IPS_OptInService::CLASS_NS = "http://intel.com/wbem/wscim/1/ips-schema/1/IPS_OptInService";
	const string IPS_OptInService::CLASS_NS_PREFIX = "AOp344";
	CIMFRAMEWORK_API vector <CimFieldAttribute> IPS_OptInService::_classMetaData;
}
}
}
}
