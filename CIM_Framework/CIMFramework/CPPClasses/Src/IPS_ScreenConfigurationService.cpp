//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       IPS_ScreenConfigurationService.cpp
//
//  Contents:   Configures the screen blanking settings in the Intel(R) AMT subsystem.
//
//              This file was automatically generated from IPS_ScreenConfigurationService.mof,  version: 10.0.0
//
//----------------------------------------------------------------------------
#include "IPS_ScreenConfigurationService.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	const CimFieldAttribute IPS_ScreenConfigurationService::_metadata[] = {
		{"CurrentState", false, false, false },
		{"EnabledState", false, false, false },
		{"RemainingConsecutiveRebootsNum", false, false, false },
	};
	// class fields
	const unsigned short IPS_ScreenConfigurationService::CurrentState() const
	{
		unsigned short ret = 0;
		TypeConverter::StringToType(GetField("CurrentState"), ret);
		return ret;
	}
	void IPS_ScreenConfigurationService::CurrentState(const unsigned short value)
	{
		SetOrAddField("CurrentState", TypeConverter::TypeToString(value));
	}
	bool IPS_ScreenConfigurationService::CurrentStateExists() const
	{
		return ContainsField("CurrentState");
	}
	void IPS_ScreenConfigurationService::RemoveCurrentState()
	{
		RemoveField("CurrentState");
	}

	const unsigned short IPS_ScreenConfigurationService::EnabledState() const
	{
		unsigned short ret = 0;
		TypeConverter::StringToType(GetField("EnabledState"), ret);
		return ret;
	}
	void IPS_ScreenConfigurationService::EnabledState(const unsigned short value)
	{
		SetOrAddField("EnabledState", TypeConverter::TypeToString(value));
	}
	bool IPS_ScreenConfigurationService::EnabledStateExists() const
	{
		return ContainsField("EnabledState");
	}
	void IPS_ScreenConfigurationService::RemoveEnabledState()
	{
		RemoveField("EnabledState");
	}

	const unsigned short IPS_ScreenConfigurationService::RemainingConsecutiveRebootsNum() const
	{
		unsigned short ret = 0;
		TypeConverter::StringToType(GetField("RemainingConsecutiveRebootsNum"), ret);
		return ret;
	}
	void IPS_ScreenConfigurationService::RemainingConsecutiveRebootsNum(const unsigned short value)
	{
		SetOrAddField("RemainingConsecutiveRebootsNum", TypeConverter::TypeToString(value));
	}
	bool IPS_ScreenConfigurationService::RemainingConsecutiveRebootsNumExists() const
	{
		return ContainsField("RemainingConsecutiveRebootsNum");
	}
	void IPS_ScreenConfigurationService::RemoveRemainingConsecutiveRebootsNum()
	{
		RemoveField("RemainingConsecutiveRebootsNum");
	}

	CimBase *IPS_ScreenConfigurationService::CreateFromCimObject(const CimObject &object)
	{
		IPS_ScreenConfigurationService *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<IPS_ScreenConfigurationService>(object);
		}
		else
		{
			ret = new IPS_ScreenConfigurationService(object);
		}
		return ret;
	}

	vector<shared_ptr<IPS_ScreenConfigurationService> > IPS_ScreenConfigurationService::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<IPS_ScreenConfigurationService>(client, keys);
	}

	void IPS_ScreenConfigurationService::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &IPS_ScreenConfigurationService::GetMetaData() const
	{
		return _classMetaData;
	}
	const CimFieldAttribute IPS_ScreenConfigurationService::RequestStateChange_INPUT::_metadata[] = {
		{"RequestedState", false, false },
		{"TimeoutPeriod", false, false },
	};
	void IPS_ScreenConfigurationService::RequestStateChange_INPUT::RequestedState(const unsigned short value)
	{
		SetOrAddField("RequestedState", TypeConverter::TypeToString(value));
	}
	void IPS_ScreenConfigurationService::RequestStateChange_INPUT::TimeoutPeriod(const CimDateTime &value)
	{
		SetOrAddField("TimeoutPeriod", TypeConverter::TypeToString(value));
	}
	const VectorFieldData IPS_ScreenConfigurationService::RequestStateChange_INPUT::GetAllFields() const
	{
		VectorFieldData ret;
		ret = sortData(_metadata, 2);
		return ret;
	}
	const CimReference IPS_ScreenConfigurationService::RequestStateChange_OUTPUT::Job() const
	{
		CimReference ret;
		TypeConverter::StringToType(GetField("Job"), ret);
		return ret;
	}
	bool IPS_ScreenConfigurationService::RequestStateChange_OUTPUT::JobExists() const
	{
		return ContainsField("Job");
	}
	unsigned int IPS_ScreenConfigurationService::RequestStateChange(const RequestStateChange_INPUT &input, RequestStateChange_OUTPUT &output)
	{
		return Invoke("RequestStateChange", input, output);
	}
	const CimFieldAttribute IPS_ScreenConfigurationService::SetSessionState_INPUT::_metadata[] = {
		{"SessionState", false, false },
		{"ConsecutiveRebootsNum", false, false },
	};
	void IPS_ScreenConfigurationService::SetSessionState_INPUT::SessionState(const unsigned char &value)
	{
		SetOrAddField("SessionState", TypeConverter::TypeToString(value));
	}
	void IPS_ScreenConfigurationService::SetSessionState_INPUT::ConsecutiveRebootsNum(const unsigned char &value)
	{
		SetOrAddField("ConsecutiveRebootsNum", TypeConverter::TypeToString(value));
	}
	const VectorFieldData IPS_ScreenConfigurationService::SetSessionState_INPUT::GetAllFields() const
	{
		VectorFieldData ret;
		ret = sortData(_metadata, 2);
		return ret;
	}
	unsigned int IPS_ScreenConfigurationService::SetSessionState(const SetSessionState_INPUT &input)
	{
		CimEmptyParam output;
		return Invoke("SetSessionState", input, output);
	}
	const string IPS_ScreenConfigurationService::CLASS_NAME = "IPS_ScreenConfigurationService";
	const string IPS_ScreenConfigurationService::CLASS_URI = "http://intel.com/wbem/wscim/1/ips-schema/1/IPS_ScreenConfigurationService";
	const string IPS_ScreenConfigurationService::CLASS_NS = "http://intel.com/wbem/wscim/1/ips-schema/1/IPS_ScreenConfigurationService";
	const string IPS_ScreenConfigurationService::CLASS_NS_PREFIX = "ASc606";
	CIMFRAMEWORK_API vector <CimFieldAttribute> IPS_ScreenConfigurationService::_classMetaData;
}
}
}
}
