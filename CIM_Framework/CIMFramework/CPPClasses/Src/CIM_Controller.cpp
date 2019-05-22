//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_Controller.cpp
//
//  Contents:   Controller is a superclass for grouping the miscellaneous control-related Devices that provide a classic bus master interface. Examples of Controllers are USBControllers, SerialControllers, and so on. The Controller class is an abstraction for Devices with a single protocol stack, which exist to control communications (data, control, and reset) to downstream devices. Note that a new abstract class (ProtocolController) has been created to model more complex interface controllers such as SCSI.
//
//              This file was automatically generated from CIM_Controller.mof,  version: 2.10.0
//
//----------------------------------------------------------------------------
#include "CIM_Controller.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	const CimFieldAttribute CIM_Controller::_metadata[] = {
		{"TimeOfLastReset", false, false, false },
		{"ProtocolSupported", false, false, false },
		{"MaxNumberControlled", false, false, false },
		{"ProtocolDescription", false, false, false },
	};
	// class fields
	const CimDateTime CIM_Controller::TimeOfLastReset() const
	{
		CimDateTime ret;
		TypeConverter::StringToType(GetField("TimeOfLastReset"), ret);
		return ret;
	}
	void CIM_Controller::TimeOfLastReset(const CimDateTime &value)
	{
		SetOrAddField("TimeOfLastReset", TypeConverter::TypeToString(value));
	}
	bool CIM_Controller::TimeOfLastResetExists() const
	{
		return ContainsField("TimeOfLastReset");
	}
	void CIM_Controller::RemoveTimeOfLastReset()
	{
		RemoveField("TimeOfLastReset");
	}

	const unsigned short CIM_Controller::ProtocolSupported() const
	{
		unsigned short ret = 0;
		TypeConverter::StringToType(GetField("ProtocolSupported"), ret);
		return ret;
	}
	void CIM_Controller::ProtocolSupported(const unsigned short value)
	{
		SetOrAddField("ProtocolSupported", TypeConverter::TypeToString(value));
	}
	bool CIM_Controller::ProtocolSupportedExists() const
	{
		return ContainsField("ProtocolSupported");
	}
	void CIM_Controller::RemoveProtocolSupported()
	{
		RemoveField("ProtocolSupported");
	}

	const unsigned int CIM_Controller::MaxNumberControlled() const
	{
		unsigned int ret = 0;
		TypeConverter::StringToType(GetField("MaxNumberControlled"), ret);
		return ret;
	}
	void CIM_Controller::MaxNumberControlled(const unsigned int value)
	{
		SetOrAddField("MaxNumberControlled", TypeConverter::TypeToString(value));
	}
	bool CIM_Controller::MaxNumberControlledExists() const
	{
		return ContainsField("MaxNumberControlled");
	}
	void CIM_Controller::RemoveMaxNumberControlled()
	{
		RemoveField("MaxNumberControlled");
	}

	const string CIM_Controller::ProtocolDescription() const
	{
		return GetField("ProtocolDescription")[0];
	}
	void CIM_Controller::ProtocolDescription(const string &value)
	{
		SetOrAddField("ProtocolDescription", value);
	}
	bool CIM_Controller::ProtocolDescriptionExists() const
	{
		return ContainsField("ProtocolDescription");
	}
	void CIM_Controller::RemoveProtocolDescription()
	{
		RemoveField("ProtocolDescription");
	}

	CimBase *CIM_Controller::CreateFromCimObject(const CimObject &object)
	{
		CIM_Controller *ret = NULL;
		if(object.ObjectType() != CLASS_NAME)
		{
			ret = new CimExtended<CIM_Controller>(object);
		}
		else
		{
			ret = new CIM_Controller(object);
		}
		return ret;
	}

	vector<shared_ptr<CIM_Controller> > CIM_Controller::Enumerate(ICimWsmanClient *client, const CimKeys &keys) 
	{
		return CimBase::Enumerate<CIM_Controller>(client, keys);
	}

	void CIM_Controller::Delete(ICimWsmanClient *client, const CimKeys &keys) 
	{
		CimBase::Delete(client, CLASS_URI, keys);
	}

	const vector<CimFieldAttribute> &CIM_Controller::GetMetaData() const
	{
		return _classMetaData;
	}
	unsigned int CIM_Controller::RestoreProperties()
	{
		CimEmptyParam input;
		CimEmptyParam output;
		return Invoke("RestoreProperties", input, output);
	}
	unsigned int CIM_Controller::SaveProperties()
	{
		CimEmptyParam input;
		CimEmptyParam output;
		return Invoke("SaveProperties", input, output);
	}
	const CimFieldAttribute CIM_Controller::QuiesceDevice_INPUT::_metadata[] = {
		{"Quiesce", false, false },
	};
	void CIM_Controller::QuiesceDevice_INPUT::Quiesce(const bool value)
	{
		SetOrAddField("Quiesce", TypeConverter::TypeToString(value));
	}
	const VectorFieldData CIM_Controller::QuiesceDevice_INPUT::GetAllFields() const
	{
		VectorFieldData ret;
		ret = sortData(_metadata, 1);
		return ret;
	}
	unsigned int CIM_Controller::QuiesceDevice(const QuiesceDevice_INPUT &input)
	{
		CimEmptyParam output;
		return Invoke("QuiesceDevice", input, output);
	}
	const CimFieldAttribute CIM_Controller::OnlineDevice_INPUT::_metadata[] = {
		{"Online", false, false },
	};
	void CIM_Controller::OnlineDevice_INPUT::Online(const bool value)
	{
		SetOrAddField("Online", TypeConverter::TypeToString(value));
	}
	const VectorFieldData CIM_Controller::OnlineDevice_INPUT::GetAllFields() const
	{
		VectorFieldData ret;
		ret = sortData(_metadata, 1);
		return ret;
	}
	unsigned int CIM_Controller::OnlineDevice(const OnlineDevice_INPUT &input)
	{
		CimEmptyParam output;
		return Invoke("OnlineDevice", input, output);
	}
	const CimFieldAttribute CIM_Controller::EnableDevice_INPUT::_metadata[] = {
		{"Enabled", false, false },
	};
	void CIM_Controller::EnableDevice_INPUT::Enabled(const bool value)
	{
		SetOrAddField("Enabled", TypeConverter::TypeToString(value));
	}
	const VectorFieldData CIM_Controller::EnableDevice_INPUT::GetAllFields() const
	{
		VectorFieldData ret;
		ret = sortData(_metadata, 1);
		return ret;
	}
	unsigned int CIM_Controller::EnableDevice(const EnableDevice_INPUT &input)
	{
		CimEmptyParam output;
		return Invoke("EnableDevice", input, output);
	}
	unsigned int CIM_Controller::Reset()
	{
		CimEmptyParam input;
		CimEmptyParam output;
		return Invoke("Reset", input, output);
	}
	const CimFieldAttribute CIM_Controller::SetPowerState_INPUT::_metadata[] = {
		{"PowerState", false, false },
		{"Time", false, false },
	};
	void CIM_Controller::SetPowerState_INPUT::PowerState(const unsigned short value)
	{
		SetOrAddField("PowerState", TypeConverter::TypeToString(value));
	}
	void CIM_Controller::SetPowerState_INPUT::Time(const CimDateTime &value)
	{
		SetOrAddField("Time", TypeConverter::TypeToString(value));
	}
	const VectorFieldData CIM_Controller::SetPowerState_INPUT::GetAllFields() const
	{
		VectorFieldData ret;
		ret = sortData(_metadata, 2);
		return ret;
	}
	unsigned int CIM_Controller::SetPowerState(const SetPowerState_INPUT &input)
	{
		CimEmptyParam output;
		return Invoke("SetPowerState", input, output);
	}
	const CimFieldAttribute CIM_Controller::RequestStateChange_INPUT::_metadata[] = {
		{"RequestedState", false, false },
		{"TimeoutPeriod", false, false },
	};
	void CIM_Controller::RequestStateChange_INPUT::RequestedState(const unsigned short value)
	{
		SetOrAddField("RequestedState", TypeConverter::TypeToString(value));
	}
	void CIM_Controller::RequestStateChange_INPUT::TimeoutPeriod(const CimDateTime &value)
	{
		SetOrAddField("TimeoutPeriod", TypeConverter::TypeToString(value));
	}
	const VectorFieldData CIM_Controller::RequestStateChange_INPUT::GetAllFields() const
	{
		VectorFieldData ret;
		ret = sortData(_metadata, 2);
		return ret;
	}
	const CimReference CIM_Controller::RequestStateChange_OUTPUT::Job() const
	{
		CimReference ret;
		TypeConverter::StringToType(GetField("Job"), ret);
		return ret;
	}
	bool CIM_Controller::RequestStateChange_OUTPUT::JobExists() const
	{
		return ContainsField("Job");
	}
	unsigned int CIM_Controller::RequestStateChange(const RequestStateChange_INPUT &input, RequestStateChange_OUTPUT &output)
	{
		return Invoke("RequestStateChange", input, output);
	}
	const string CIM_Controller::CLASS_NAME = "CIM_Controller";
	const string CIM_Controller::CLASS_URI = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_Controller";
	const string CIM_Controller::CLASS_NS = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_Controller";
	const string CIM_Controller::CLASS_NS_PREFIX = "ACo172";
	CIMFRAMEWORK_API vector <CimFieldAttribute> CIM_Controller::_classMetaData;
}
}
}
}
