//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       IPS_KVMRedirectionSettingData.cpp
//
//  Contents:   The IPS_KVMRedirectionSettingData class represents configuration-related and operational parameters for the KVM redirection service in the Intel(R) AMT.
//
//              This file was automatically generated from IPS_KVMRedirectionSettingData.mof,  version: 16.0.0
//
//----------------------------------------------------------------------------
#include "IPS_KVMRedirectionSettingData.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	const CimFieldAttribute IPS_KVMRedirectionSettingData::_metadata[] = {
		{"EnabledByMEBx", false, false, false },
		{"BackToBackFbMode", false, false, false },
		{"Is5900PortEnabled", false, false, false },
		{"OptInPolicy", false, false, false },
		{"OptInPolicyTimeout", false, false, false },
		{"SessionTimeout", false, false, false },
		{"RFBPassword", false, false, false },
		{"DefaultScreen", false, false, false },
		{"DoubleBufferEnabled", false, false, false },
		{"DoubleBufferActive", false, false, false },
		{"ZlibControlSupported", false, false, false },
		{"GrayscalePixelFormatSupported", false, false, false },
		{"InitialDecimationModeForLowRes", false, false, false },
	};
	// class fields
	const bool IPS_KVMRedirectionSettingData::EnabledByMEBx() const
	{
		bool ret = false;
		TypeConverter::StringToType(GetField("EnabledByMEBx"), ret);
		return ret;
	}
	void IPS_KVMRedirectionSettingData::EnabledByMEBx(const bool value)
	{
		SetOrAddField("EnabledByMEBx", TypeConverter::TypeToString(value));
	}
	bool IPS_KVMRedirectionSettingData::EnabledByMEBxExists() const
	{
		return ContainsField("EnabledByMEBx");
	}
	void IPS_KVMRedirectionSettingData::RemoveEnabledByMEBx()
	{
		RemoveField("EnabledByMEBx");
	}

	const bool IPS_KVMRedirectionSettingData::BackToBackFbMode() const
	{
		bool ret = false;
		TypeConverter::StringToType(GetField("BackToBackFbMode"), ret);
		return ret;
	}
	void IPS_KVMRedirectionSettingData::BackToBackFbMode(const bool value)
	{
		SetOrAddField("BackToBackFbMode", TypeConverter::TypeToString(value));
	}
	bool IPS_KVMRedirectionSettingData::BackToBackFbModeExists() const
	{
		return ContainsField("BackToBackFbMode");
	}
	void IPS_KVMRedirectionSettingData::RemoveBackToBackFbMode()
	{
		RemoveField("BackToBackFbMode");
	}

	const bool IPS_KVMRedirectionSettingData::Is5900PortEnabled() const
	{
		bool ret = false;
		TypeConverter::StringToType(GetField("Is5900PortEnabled"), ret);
		return ret;
	}
	void IPS_KVMRedirectionSettingData::Is5900PortEnabled(const bool value)
	{
		SetOrAddField("Is5900PortEnabled", TypeConverter::TypeToString(value));
	}
	bool IPS_KVMRedirectionSettingData::Is5900PortEnabledExists() const
	{
		return ContainsField("Is5900PortEnabled");
	}
	void IPS_KVMRedirectionSettingData::RemoveIs5900PortEnabled()
	{
		RemoveField("Is5900PortEnabled");
	}

	const bool IPS_KVMRedirectionSettingData::OptInPolicy() const
	{
		bool ret = false;
		TypeConverter::StringToType(GetField("OptInPolicy"), ret);
		return ret;
	}
	void IPS_KVMRedirectionSettingData::OptInPolicy(const bool value)
	{
		SetOrAddField("OptInPolicy", TypeConverter::TypeToString(value));
	}
	bool IPS_KVMRedirectionSettingData::OptInPolicyExists() const
	{
		return ContainsField("OptInPolicy");
	}
	void IPS_KVMRedirectionSettingData::RemoveOptInPolicy()
	{
		RemoveField("OptInPolicy");
	}

	const unsigned short IPS_KVMRedirectionSettingData::OptInPolicyTimeout() const
	{
		unsigned short ret = 0;
		TypeConverter::StringToType(GetField("OptInPolicyTimeout"), ret);
		return ret;
	}
	void IPS_KVMRedirectionSettingData::OptInPolicyTimeout(const unsigned short value)
	{
		SetOrAddField("OptInPolicyTimeout", TypeConverter::TypeToString(value));
	}
	bool IPS_KVMRedirectionSettingData::OptInPolicyTimeoutExists() const
	{
		return ContainsField("OptInPolicyTimeout");
	}
	void IPS_KVMRedirectionSettingData::RemoveOptInPolicyTimeout()
	{
		RemoveField("OptInPolicyTimeout");
	}

	const unsigned short IPS_KVMRedirectionSettingData::SessionTimeout() const
	{
		unsigned short ret = 0;
		TypeConverter::StringToType(GetField("SessionTimeout"), ret);
		return ret;
	}
	void IPS_KVMRedirectionSettingData::SessionTimeout(const unsigned short value)
	{
		SetOrAddField("SessionTimeout", TypeConverter::TypeToString(value));
	}
	bool IPS_KVMRedirectionSettingData::SessionTimeoutExists() const
	{
		return ContainsField("SessionTimeout");
	}
	void IPS_KVMRedirectionSettingData::RemoveSessionTimeout()
	{
		RemoveField("SessionTimeout");
	}

	const string IPS_KVMRedirectionSettingData::RFBPassword() const
	{
		return GetField("RFBPassword")[0];
	}
	void IPS_KVMRedirectionSettingData::RFBPassword(const string &value)
	{
		SetOrAddField("RFBPassword", value);
	}
	bool IPS_KVMRedirectionSettingData::RFBPasswordExists() const
	{
		return ContainsField("RFBPassword");
	}
	void IPS_KVMRedirectionSettingData::RemoveRFBPassword()
	{
		RemoveField("RFBPassword");
	}

	const unsigned char IPS_KVMRedirectionSettingData::DefaultScreen() const
	{
		unsigned char ret = 0;
		TypeConverter::StringToType(GetField("DefaultScreen"), ret);
		return ret;
	}
	void IPS_KVMRedirectionSettingData::DefaultScreen(const unsigned char &value)
	{
		SetOrAddField("DefaultScreen", TypeConverter::TypeToString(value));
	}
	bool IPS_KVMRedirectionSettingData::DefaultScreenExists() const
	{
		return ContainsField("DefaultScreen");
	}
	void IPS_KVMRedirectionSettingData::RemoveDefaultScreen()
	{
		RemoveField("DefaultScreen");
	}

	const bool IPS_KVMRedirectionSettingData::DoubleBufferEnabled() const
	{
		bool ret = false;
		TypeConverter::StringToType(GetField("DoubleBufferEnabled"), ret);
		return ret;
	}
	void IPS_KVMRedirectionSettingData::DoubleBufferEnabled(const bool value)
	{
		SetOrAddField("DoubleBufferEnabled", TypeConverter::TypeToString(value));
	}
	bool IPS_KVMRedirectionSettingData::DoubleBufferEnabledExists() const
	{
		return ContainsField("DoubleBufferEnabled");
	}
	void IPS_KVMRedirectionSettingData::RemoveDoubleBufferEnabled()
	{
		RemoveField("DoubleBufferEnabled");
	}

	const bool IPS_KVMRedirectionSettingData::DoubleBufferActive() const
	{
		bool ret = false;
		TypeConverter::StringToType(GetField("DoubleBufferActive"), ret);
		return ret;
	}
	void IPS_KVMRedirectionSettingData::DoubleBufferActive(const bool value)
	{
		SetOrAddField("DoubleBufferActive", TypeConverter::TypeToString(value));
	}
	bool IPS_KVMRedirectionSettingData::DoubleBufferActiveExists() const
	{
		return ContainsField("DoubleBufferActive");
	}
	void IPS_KVMRedirectionSettingData::RemoveDoubleBufferActive()
	{
		RemoveField("DoubleBufferActive");
	}

	const bool IPS_KVMRedirectionSettingData::ZlibControlSupported() const
	{
		bool ret = false;
		TypeConverter::StringToType(GetField("ZlibControlSupported"), ret);
		return ret;
	}
	void IPS_KVMRedirectionSettingData::ZlibControlSupported(const bool value)
	{
		SetOrAddField("ZlibControlSupported", TypeConverter::TypeToString(value));
	}
	bool IPS_KVMRedirectionSettingData::ZlibControlSupportedExists() const
	{
		return ContainsField("ZlibControlSupported");
	}
	void IPS_KVMRedirectionSettingData::RemoveZlibControlSupported()
	{
		RemoveField("ZlibControlSupported");
	}

	const bool IPS_KVMRedirectionSettingData::GrayscalePixelFormatSupported() const
	{
		bool ret = false;
		TypeConverter::StringToType(GetField("GrayscalePixelFormatSupported"), ret);
		return ret;
	}
	void IPS_KVMRedirectionSettingData::GrayscalePixelFormatSupported(const bool value)
	{
		SetOrAddField("GrayscalePixelFormatSupported", TypeConverter::TypeToString(value));
	}
	bool IPS_KVMRedirectionSettingData::GrayscalePixelFormatSupportedExists() const
	{
		return ContainsField("GrayscalePixelFormatSupported");
	}
	void IPS_KVMRedirectionSettingData::RemoveGrayscalePixelFormatSupported()
	{
		RemoveField("GrayscalePixelFormatSupported");
	}

	const unsigned char IPS_KVMRedirectionSettingData::InitialDecimationModeForLowRes() const
	{
		unsigned char ret = 0;
		TypeConverter::StringToType(GetField("InitialDecimationModeForLowRes"), ret);
		return ret;
	}
	void IPS_KVMRedirectionSettingData::InitialDecimationModeForLowRes(const unsigned char &value)
	{
		SetOrAddField("InitialDecimationModeForLowRes", TypeConverter::TypeToString(value));
	}
	bool IPS_KVMRedirectionSettingData::InitialDecimationModeForLowResExists() const
	{
		return ContainsField("InitialDecimationModeForLowRes");
	}
	void IPS_KVMRedirectionSettingData::RemoveInitialDecimationModeForLowRes()
	{
		RemoveField("InitialDecimationModeForLowRes");
	}

	CimBase *IPS_KVMRedirectionSettingData::CreateFromCimObject(const CimObject &object)
	{
		IPS_KVMRedirectionSettingData *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<IPS_KVMRedirectionSettingData>(object);
		}
		else
		{
			ret = new IPS_KVMRedirectionSettingData(object);
		}
		return ret;
	}

	vector<shared_ptr<IPS_KVMRedirectionSettingData> > IPS_KVMRedirectionSettingData::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<IPS_KVMRedirectionSettingData>(client, keys);
	}

	void IPS_KVMRedirectionSettingData::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &IPS_KVMRedirectionSettingData::GetMetaData() const
	{
		return _classMetaData;
	}
	unsigned int IPS_KVMRedirectionSettingData::TerminateSession()
	{
		CimEmptyParam input;
		CimEmptyParam output;
		return Invoke("TerminateSession", input, output);
	}
	const string IPS_KVMRedirectionSettingData::CLASS_NAME = "IPS_KVMRedirectionSettingData";
	const string IPS_KVMRedirectionSettingData::CLASS_URI = "http://intel.com/wbem/wscim/1/ips-schema/1/IPS_KVMRedirectionSettingData";
	const string IPS_KVMRedirectionSettingData::CLASS_NS = "http://intel.com/wbem/wscim/1/ips-schema/1/IPS_KVMRedirectionSettingData";
	const string IPS_KVMRedirectionSettingData::CLASS_NS_PREFIX = "AKV555";
	CIMFRAMEWORK_API vector <CimFieldAttribute> IPS_KVMRedirectionSettingData::_classMetaData;
}
}
}
}
