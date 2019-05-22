//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_PowerSupply.h
//
//  Contents:   Capabilities and management of the PowerSupply LogicalDevice.
//
//              This file was automatically generated from CIM_PowerSupply.mof,  version: 2.10.0
//
//----------------------------------------------------------------------------
#ifndef CIM_POWERSUPPLY_H
#define CIM_POWERSUPPLY_H 1
#include "CIM_LogicalDevice.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	// Capabilities and management of the PowerSupply LogicalDevice.
	class CIMFRAMEWORK_API CIM_PowerSupply  : public CIM_LogicalDevice
	{
	public:

		//Default constructor
		CIM_PowerSupply()
			: CIM_LogicalDevice(NULL, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_LogicalDevice::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 12);
			}
		}

		//constructor which receives WSMan client
		CIM_PowerSupply(ICimWsmanClient *client)
			: CIM_LogicalDevice(client, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_LogicalDevice::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 12);
			}
		}

		//Destructor
		virtual ~CIM_PowerSupply(){}

		// The "type" information for the object. Gettors only.
		virtual const string& ResourceURI() const { return CLASS_URI; }
		static const string& ClassResourceURI() { return CLASS_URI; }
		virtual const string& XmlNamespace() const { return CLASS_NS; }
		virtual const string& XmlPrefix() const { return CLASS_NS_PREFIX; }
		virtual const string& ObjectType() const { return CLASS_NAME; }
		static const string& ClassObjectType() { return CLASS_NAME; }

		// Class representing CIM_PowerSupply keys
		class CimKeys : public CIM_LogicalDevice::CimKeys
		{
		public:
		};

		// class fields declarations

		// Optional, Boolean indicating that the PowerSupply is a switching (instead of linear) supply.
		const bool IsSwitchingSupply() const;

		// Optional, Boolean indicating that the PowerSupply is a switching (instead of linear) supply.
		void IsSwitchingSupply(const bool value); 

		// Is true if the field IsSwitchingSupply exists in the current object, otherwise is false.
		bool IsSwitchingSupplyExists() const;

		// Remove IsSwitchingSupply field.
		void RemoveIsSwitchingSupply(); 

		// Optional, The low voltage of Input Voltage Range 1 for this Power Supply, in millivolts. A value of 0 denotes 'unknown'.
		const unsigned int Range1InputVoltageLow() const;

		// Optional, The low voltage of Input Voltage Range 1 for this Power Supply, in millivolts. A value of 0 denotes 'unknown'.
		void Range1InputVoltageLow(const unsigned int value); 

		// Is true if the field Range1InputVoltageLow exists in the current object, otherwise is false.
		bool Range1InputVoltageLowExists() const;

		// Remove Range1InputVoltageLow field.
		void RemoveRange1InputVoltageLow(); 

		// Optional, The high voltage of Input Voltage Range 1 for this Power Supply, in millivolts. A value of 0 denotes 'unknown'.
		const unsigned int Range1InputVoltageHigh() const;

		// Optional, The high voltage of Input Voltage Range 1 for this Power Supply, in millivolts. A value of 0 denotes 'unknown'.
		void Range1InputVoltageHigh(const unsigned int value); 

		// Is true if the field Range1InputVoltageHigh exists in the current object, otherwise is false.
		bool Range1InputVoltageHighExists() const;

		// Remove Range1InputVoltageHigh field.
		void RemoveRange1InputVoltageHigh(); 

		// Optional, The frequency (in hertz) at the low end of the Input Frequency Range 1 of this Power Supply. A value of 0 implies DC.
		const unsigned int Range1InputFrequencyLow() const;

		// Optional, The frequency (in hertz) at the low end of the Input Frequency Range 1 of this Power Supply. A value of 0 implies DC.
		void Range1InputFrequencyLow(const unsigned int value); 

		// Is true if the field Range1InputFrequencyLow exists in the current object, otherwise is false.
		bool Range1InputFrequencyLowExists() const;

		// Remove Range1InputFrequencyLow field.
		void RemoveRange1InputFrequencyLow(); 

		// Optional, The frequency (in hertz) at the high end of the Input Frequency Range 1 of this Power Supply. A value of 0 implies DC.
		const unsigned int Range1InputFrequencyHigh() const;

		// Optional, The frequency (in hertz) at the high end of the Input Frequency Range 1 of this Power Supply. A value of 0 implies DC.
		void Range1InputFrequencyHigh(const unsigned int value); 

		// Is true if the field Range1InputFrequencyHigh exists in the current object, otherwise is false.
		bool Range1InputFrequencyHighExists() const;

		// Remove Range1InputFrequencyHigh field.
		void RemoveRange1InputFrequencyHigh(); 

		// Optional, The low voltage of Input Voltage Range 2 for this Power Supply, in millivolts. A value of 0 denotes 'unknown'.
		const unsigned int Range2InputVoltageLow() const;

		// Optional, The low voltage of Input Voltage Range 2 for this Power Supply, in millivolts. A value of 0 denotes 'unknown'.
		void Range2InputVoltageLow(const unsigned int value); 

		// Is true if the field Range2InputVoltageLow exists in the current object, otherwise is false.
		bool Range2InputVoltageLowExists() const;

		// Remove Range2InputVoltageLow field.
		void RemoveRange2InputVoltageLow(); 

		// Optional, The high voltage of Input Voltage Range 2 for this Power Supply, in millivolts. A value of 0 denotes 'unknown'.
		const unsigned int Range2InputVoltageHigh() const;

		// Optional, The high voltage of Input Voltage Range 2 for this Power Supply, in millivolts. A value of 0 denotes 'unknown'.
		void Range2InputVoltageHigh(const unsigned int value); 

		// Is true if the field Range2InputVoltageHigh exists in the current object, otherwise is false.
		bool Range2InputVoltageHighExists() const;

		// Remove Range2InputVoltageHigh field.
		void RemoveRange2InputVoltageHigh(); 

		// Optional, The frequency (in hertz) at the low end of the Input Frequency Range 2 of this Power Supply. A value of 0 implies DC.
		const unsigned int Range2InputFrequencyLow() const;

		// Optional, The frequency (in hertz) at the low end of the Input Frequency Range 2 of this Power Supply. A value of 0 implies DC.
		void Range2InputFrequencyLow(const unsigned int value); 

		// Is true if the field Range2InputFrequencyLow exists in the current object, otherwise is false.
		bool Range2InputFrequencyLowExists() const;

		// Remove Range2InputFrequencyLow field.
		void RemoveRange2InputFrequencyLow(); 

		// Optional, The frequency (in hertz) at the high end of the Input Frequency Range 2 of this Power Supply. A value of 0 implies DC.
		const unsigned int Range2InputFrequencyHigh() const;

		// Optional, The frequency (in hertz) at the high end of the Input Frequency Range 2 of this Power Supply. A value of 0 implies DC.
		void Range2InputFrequencyHigh(const unsigned int value); 

		// Is true if the field Range2InputFrequencyHigh exists in the current object, otherwise is false.
		bool Range2InputFrequencyHighExists() const;

		// Remove Range2InputFrequencyHigh field.
		void RemoveRange2InputFrequencyHigh(); 

		// Optional, ActiveInputVoltage indicates which input voltage range is currently in use. Range 1, 2, or both can be specified using the values 3, 4, or 5, respectively. If the Supply is not currently drawing power, the value 6 ("Neither") can be specified. This information is necessary in the case of a UPS, a subclass of PowerSupply.
		const unsigned short ActiveInputVoltage() const;

		// Optional, ActiveInputVoltage indicates which input voltage range is currently in use. Range 1, 2, or both can be specified using the values 3, 4, or 5, respectively. If the Supply is not currently drawing power, the value 6 ("Neither") can be specified. This information is necessary in the case of a UPS, a subclass of PowerSupply.
		void ActiveInputVoltage(const unsigned short value); 

		// Is true if the field ActiveInputVoltage exists in the current object, otherwise is false.
		bool ActiveInputVoltageExists() const;

		// Remove ActiveInputVoltage field.
		void RemoveActiveInputVoltage(); 

		// Optional, TypeOfRangeSwitching describes the kind of input voltage range switching that is implemented in this PowerSupply. For example, autoswitching can be specified (value=4).
		const unsigned short TypeOfRangeSwitching() const;

		// Optional, TypeOfRangeSwitching describes the kind of input voltage range switching that is implemented in this PowerSupply. For example, autoswitching can be specified (value=4).
		void TypeOfRangeSwitching(const unsigned short value); 

		// Is true if the field TypeOfRangeSwitching exists in the current object, otherwise is false.
		bool TypeOfRangeSwitchingExists() const;

		// Remove TypeOfRangeSwitching field.
		void RemoveTypeOfRangeSwitching(); 

		// Optional, Represents the total output power of the PowerSupply in milliWatts. 0 denotes 'unknown'.
		const unsigned int TotalOutputPower() const;

		// Optional, Represents the total output power of the PowerSupply in milliWatts. 0 denotes 'unknown'.
		void TotalOutputPower(const unsigned int value); 

		// Is true if the field TotalOutputPower exists in the current object, otherwise is false.
		bool TotalOutputPowerExists() const;

		// Remove TotalOutputPower field.
		void RemoveTotalOutputPower(); 

		 // Function used by the factory
		static CimBase *CreateFromCimObject(const CimObject &object);

		static vector<shared_ptr<CIM_PowerSupply> > Enumerate(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		// Overloaded delete which supplies the internal resourceURI
		static void Delete(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		using CimBase::Delete;

	protected:
		 // Protected constructor to be used by derived classes
		CIM_PowerSupply(ICimWsmanClient *client, const string &class_name,
			const string &class_ns, const string &prefix, const string &uri): CIM_LogicalDevice(client, class_name, class_ns, prefix, uri)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_LogicalDevice::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 12);
			}
		}
		 // Protected constructor which receives CimObject
		CIM_PowerSupply(const CimObject &object)
			: CIM_LogicalDevice(object)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_LogicalDevice::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 12);
			}
		}
		// Called by derived classes
		void SetMetaData(vector<CimFieldAttribute>& childMetaData)
		{
			CIM_LogicalDevice::SetMetaData(childMetaData);
			CimBase::SetMetaData(childMetaData, _metadata, 12);
		}
		const vector<CimFieldAttribute> &GetMetaData() const;
	private:
		static const CimFieldAttribute _metadata[];
		static const string CLASS_NAME;
		static const string CLASS_URI;
		static const string CLASS_NS;
		static const string CLASS_NS_PREFIX;
		static vector<CimFieldAttribute> _classMetaData;
	};

} // close namespace Typed
} // close namespace Cim
} // close namespace Manageability
} // close namespace Intel
#endif // CIM_POWERSUPPLY_H
