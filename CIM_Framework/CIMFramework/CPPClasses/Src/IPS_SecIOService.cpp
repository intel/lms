//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       IPS_SecIOService.cpp
//
//  Contents:   Represents the Secured IO service
//
//              This file was automatically generated from IPS_SecIOService.mof,  version: 8.0.0
//
//----------------------------------------------------------------------------
#include "IPS_SecIOService.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	const CimFieldAttribute IPS_SecIOService::_metadata[] = {
		{"language", false, false, false },
		{"RequestedLanguage", false, false, false },
		{"zoom", false, false, false },
		{"DefaultScreen", false, false, false },
		{"NumberOfScreens", false, false, false },
	};
	// class fields
	const unsigned short IPS_SecIOService::language() const
	{
		unsigned short ret = 0;
		TypeConverter::StringToType(GetField("language"), ret);
		return ret;
	}
	void IPS_SecIOService::language(const unsigned short value)
	{
		SetOrAddField("language", TypeConverter::TypeToString(value));
	}
	bool IPS_SecIOService::languageExists() const
	{
		return ContainsField("language");
	}
	void IPS_SecIOService::Removelanguage()
	{
		RemoveField("language");
	}

	const unsigned short IPS_SecIOService::RequestedLanguage() const
	{
		unsigned short ret = 0;
		TypeConverter::StringToType(GetField("RequestedLanguage"), ret);
		return ret;
	}
	void IPS_SecIOService::RequestedLanguage(const unsigned short value)
	{
		SetOrAddField("RequestedLanguage", TypeConverter::TypeToString(value));
	}
	bool IPS_SecIOService::RequestedLanguageExists() const
	{
		return ContainsField("RequestedLanguage");
	}
	void IPS_SecIOService::RemoveRequestedLanguage()
	{
		RemoveField("RequestedLanguage");
	}

	const unsigned short IPS_SecIOService::zoom() const
	{
		unsigned short ret = 0;
		TypeConverter::StringToType(GetField("zoom"), ret);
		return ret;
	}
	void IPS_SecIOService::zoom(const unsigned short value)
	{
		SetOrAddField("zoom", TypeConverter::TypeToString(value));
	}
	bool IPS_SecIOService::zoomExists() const
	{
		return ContainsField("zoom");
	}
	void IPS_SecIOService::Removezoom()
	{
		RemoveField("zoom");
	}

	const unsigned char IPS_SecIOService::DefaultScreen() const
	{
		unsigned char ret = 0;
		TypeConverter::StringToType(GetField("DefaultScreen"), ret);
		return ret;
	}
	void IPS_SecIOService::DefaultScreen(const unsigned char &value)
	{
		SetOrAddField("DefaultScreen", TypeConverter::TypeToString(value));
	}
	bool IPS_SecIOService::DefaultScreenExists() const
	{
		return ContainsField("DefaultScreen");
	}
	void IPS_SecIOService::RemoveDefaultScreen()
	{
		RemoveField("DefaultScreen");
	}

	const unsigned char IPS_SecIOService::NumberOfScreens() const
	{
		unsigned char ret = 0;
		TypeConverter::StringToType(GetField("NumberOfScreens"), ret);
		return ret;
	}
	void IPS_SecIOService::NumberOfScreens(const unsigned char &value)
	{
		SetOrAddField("NumberOfScreens", TypeConverter::TypeToString(value));
	}
	bool IPS_SecIOService::NumberOfScreensExists() const
	{
		return ContainsField("NumberOfScreens");
	}
	void IPS_SecIOService::RemoveNumberOfScreens()
	{
		RemoveField("NumberOfScreens");
	}

	CimBase *IPS_SecIOService::CreateFromCimObject(const CimObject &object)
	{
		IPS_SecIOService *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<IPS_SecIOService>(object);
		}
		else
		{
			ret = new IPS_SecIOService(object);
		}
		return ret;
	}

	vector<shared_ptr<IPS_SecIOService> > IPS_SecIOService::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<IPS_SecIOService>(client, keys);
	}

	void IPS_SecIOService::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &IPS_SecIOService::GetMetaData() const
	{
		return _classMetaData;
	}
	const CimFieldAttribute IPS_SecIOService::RequestStateChange_INPUT::_metadata[] = {
		{"RequestedState", false, false },
		{"TimeoutPeriod", false, false },
	};
	void IPS_SecIOService::RequestStateChange_INPUT::RequestedState(const unsigned short value)
	{
		SetOrAddField("RequestedState", TypeConverter::TypeToString(value));
	}
	void IPS_SecIOService::RequestStateChange_INPUT::TimeoutPeriod(const CimDateTime &value)
	{
		SetOrAddField("TimeoutPeriod", TypeConverter::TypeToString(value));
	}
	const VectorFieldData IPS_SecIOService::RequestStateChange_INPUT::GetAllFields() const
	{
		VectorFieldData ret;
		ret = sortData(_metadata, 2);
		return ret;
	}
	const CimReference IPS_SecIOService::RequestStateChange_OUTPUT::Job() const
	{
		CimReference ret;
		TypeConverter::StringToType(GetField("Job"), ret);
		return ret;
	}
	bool IPS_SecIOService::RequestStateChange_OUTPUT::JobExists() const
	{
		return ContainsField("Job");
	}
	unsigned int IPS_SecIOService::RequestStateChange(const RequestStateChange_INPUT &input, RequestStateChange_OUTPUT &output)
	{
		return Invoke("RequestStateChange", input, output);
	}
	const string IPS_SecIOService::CLASS_NAME = "IPS_SecIOService";
	const string IPS_SecIOService::CLASS_URI = "http://intel.com/wbem/wscim/1/ips-schema/1/IPS_SecIOService";
	const string IPS_SecIOService::CLASS_NS = "http://intel.com/wbem/wscim/1/ips-schema/1/IPS_SecIOService";
	const string IPS_SecIOService::CLASS_NS_PREFIX = "ASe441";
	CIMFRAMEWORK_API vector <CimFieldAttribute> IPS_SecIOService::_classMetaData;
}
}
}
}
