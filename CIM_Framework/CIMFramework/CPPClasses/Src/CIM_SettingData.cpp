//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_SettingData.cpp
//
//  Contents:   CIM_SettingData is used to represent configuration and and operational parameters for CIM_ManagedElement instances. There are a number of different uses of CIM_SettingData supported in the model today. Additional uses may be defined in the future.
//              Instances of CIM_SettingData may represent Aspects of a CIM_ManagedElement instance. This is modeled using the CIM_SettingsDefineState association. CIM_SettingData may be used to define capabilities when associated to an instance of CIM_Capabilities through the CIM_SettingsDefineCapabilities association. 
//              Instances of CIM_SettingData may represent different types of configurations for a CIM_ManagedElement, including persistent configurations, in progress configuration changes, or requested configurations. The CIM_ElementSettingData association is used to model the relationship between a CIM_SettingData instance and the CIM_ManagedElement for which it is a configuration. 
//              When an instance of CIM_SettingData represents a configuration, the current operational values for the parameters of the element are reflected by properties in the Element itself or by properties in its associations. These properties do not have to be the same values that are present in the SettingData object. For example, a modem might have a SettingData baud rate of 56Kb/sec but be operating at 19.2Kb/sec. 
//              Note: The CIM_SettingData class is very similar to CIM_Setting, yet both classes are present in the model because many implementations have successfully used CIM_Setting. However, issues have arisen that could not be resolved without defining a new class. Therefore, until a new major release occurs, both classes will exist in the model. Refer to the Core White Paper for additional information. SettingData instances can be aggregated together into higher- level SettingData objects using ConcreteComponent associations.
//
//              This file was automatically generated from CIM_SettingData.mof,  version: 2.19.0
//
//----------------------------------------------------------------------------
#include "CIM_SettingData.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	const CimFieldAttribute CIM_SettingData::_metadata[] = {
		{"InstanceID", true, false, false },
		{"ElementName", false, true, false },
	};
	// class fields
	CimBase *CIM_SettingData::CreateFromCimObject(const CimObject &object)
	{
		CIM_SettingData *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<CIM_SettingData>(object);
		}
		else
		{
			ret = new CIM_SettingData(object);
		}
		return ret;
	}

	vector<shared_ptr<CIM_SettingData> > CIM_SettingData::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<CIM_SettingData>(client, keys);
	}

	void CIM_SettingData::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &CIM_SettingData::GetMetaData() const
	{
		return _classMetaData;
	}
	const string CIM_SettingData::CLASS_NAME = "CIM_SettingData";
	const string CIM_SettingData::CLASS_URI = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_SettingData";
	const string CIM_SettingData::CLASS_NS = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_SettingData";
	const string CIM_SettingData::CLASS_NS_PREFIX = "ASe54";
	CIMFRAMEWORK_API vector <CimFieldAttribute> CIM_SettingData::_classMetaData;
}
}
}
}
