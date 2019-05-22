//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_Battery.h
//
//  Contents:   Capabilities and management of the Battery. This class applies to both batteries in Laptop Systems and other internal or external batteries, such as an uninterruptible power supply (UPS).
//
//              This file was automatically generated from CIM_Battery.mof,  version: 2.26.0
//
//----------------------------------------------------------------------------
#ifndef CIM_BATTERY_H
#define CIM_BATTERY_H 1
#include "CIM_LogicalDevice.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	// Capabilities and management of the Battery. This class applies to both batteries in Laptop Systems and other internal or external batteries, such as an uninterruptible power supply (UPS).
	class CIMFRAMEWORK_API CIM_Battery  : public CIM_LogicalDevice
	{
	public:

		//Default constructor
		CIM_Battery()
			: CIM_LogicalDevice(NULL, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_LogicalDevice::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 19);
			}
		}

		//constructor which receives WSMan client
		CIM_Battery(ICimWsmanClient *client)
			: CIM_LogicalDevice(client, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_LogicalDevice::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 19);
			}
		}

		//Destructor
		virtual ~CIM_Battery(){}

		// The "type" information for the object. Gettors only.
		virtual const string& ResourceURI() const { return CLASS_URI; }
		static const string& ClassResourceURI() { return CLASS_URI; }
		virtual const string& XmlNamespace() const { return CLASS_NS; }
		virtual const string& XmlPrefix() const { return CLASS_NS_PREFIX; }
		virtual const string& ObjectType() const { return CLASS_NAME; }
		static const string& ClassObjectType() { return CLASS_NAME; }

		// Class representing CIM_Battery keys
		class CimKeys : public CIM_LogicalDevice::CimKeys
		{
		public:
		};

		// class fields declarations

		// Optional, Description of the charge status of the Battery. Values such as "Fully Charged" (value=3) or "Partially Charged" (value=11) can be specified. The value, 10, is not valid in the CIM Schema because in DMI it represents that no battery is installed. In this case, this object should not be instantiated. The valuemaps: 6(Charging), 7(Charging and High), 8(Charging and Low), and 9(Charing and Critical) has been deprecated in lieu of the ChargingStatus property. 10(Undefined) has been deprecated in lieu of 2(Unknown).
		const unsigned short BatteryStatus() const;

		// Optional, Description of the charge status of the Battery. Values such as "Fully Charged" (value=3) or "Partially Charged" (value=11) can be specified. The value, 10, is not valid in the CIM Schema because in DMI it represents that no battery is installed. In this case, this object should not be instantiated. The valuemaps: 6(Charging), 7(Charging and High), 8(Charging and Low), and 9(Charing and Critical) has been deprecated in lieu of the ChargingStatus property. 10(Undefined) has been deprecated in lieu of 2(Unknown).
		void BatteryStatus(const unsigned short value); 

		// Is true if the field BatteryStatus exists in the current object, otherwise is false.
		bool BatteryStatusExists() const;

		// Remove BatteryStatus field.
		void RemoveBatteryStatus(); 

		// Optional, TimeOnBattery indicates the elapsed time in seconds since the ComputerSystem, UPS, or so on, last switched to battery power, or the time since the System or UPS was last restarted, whichever is less. Zero is returned if the Battery is 'on line'.
		const unsigned int TimeOnBattery() const;

		// Optional, TimeOnBattery indicates the elapsed time in seconds since the ComputerSystem, UPS, or so on, last switched to battery power, or the time since the System or UPS was last restarted, whichever is less. Zero is returned if the Battery is 'on line'.
		void TimeOnBattery(const unsigned int value); 

		// Is true if the field TimeOnBattery exists in the current object, otherwise is false.
		bool TimeOnBatteryExists() const;

		// Remove TimeOnBattery field.
		void RemoveTimeOnBattery(); 

		// Optional, EstimatedRunTime is an estimate in minutes of the time that battery charge depletion will occur under the present load conditions if the utility power is off, or is lost and remains off, or a Laptop is disconnected from a power source.
		const unsigned int EstimatedRunTime() const;

		// Optional, EstimatedRunTime is an estimate in minutes of the time that battery charge depletion will occur under the present load conditions if the utility power is off, or is lost and remains off, or a Laptop is disconnected from a power source.
		void EstimatedRunTime(const unsigned int value); 

		// Is true if the field EstimatedRunTime exists in the current object, otherwise is false.
		bool EstimatedRunTimeExists() const;

		// Remove EstimatedRunTime field.
		void RemoveEstimatedRunTime(); 

		// Optional, An estimate of the percentage of full charge remaining.
		const unsigned short EstimatedChargeRemaining() const;

		// Optional, An estimate of the percentage of full charge remaining.
		void EstimatedChargeRemaining(const unsigned short value); 

		// Is true if the field EstimatedChargeRemaining exists in the current object, otherwise is false.
		bool EstimatedChargeRemainingExists() const;

		// Remove EstimatedChargeRemaining field.
		void RemoveEstimatedChargeRemaining(); 

		// Optional, An enumeration that describes the chemistry of the Battery.
		const unsigned short Chemistry() const;

		// Optional, An enumeration that describes the chemistry of the Battery.
		void Chemistry(const unsigned short value); 

		// Is true if the field Chemistry exists in the current object, otherwise is false.
		bool ChemistryExists() const;

		// Remove Chemistry field.
		void RemoveChemistry(); 

		// Optional, The design capacity of the battery in mWatt-hours. If this property is not supported, enter 0.
		const unsigned int DesignCapacity() const;

		// Optional, The design capacity of the battery in mWatt-hours. If this property is not supported, enter 0.
		void DesignCapacity(const unsigned int value); 

		// Is true if the field DesignCapacity exists in the current object, otherwise is false.
		bool DesignCapacityExists() const;

		// Remove DesignCapacity field.
		void RemoveDesignCapacity(); 

		// Optional, The full charge capacity of the battery in mWatt-hours. Comparison of this value to the Battery DesignCapacity determines when the Battery requires replacement. The end of life of a Battery is typically when the FullCharge Capacity falls below 80% of the DesignCapacity. If this property is not supported, enter 0.
		const unsigned int FullChargeCapacity() const;

		// Optional, The full charge capacity of the battery in mWatt-hours. Comparison of this value to the Battery DesignCapacity determines when the Battery requires replacement. The end of life of a Battery is typically when the FullCharge Capacity falls below 80% of the DesignCapacity. If this property is not supported, enter 0.
		void FullChargeCapacity(const unsigned int value); 

		// Is true if the field FullChargeCapacity exists in the current object, otherwise is false.
		bool FullChargeCapacityExists() const;

		// Remove FullChargeCapacity field.
		void RemoveFullChargeCapacity(); 

		// Optional, The design voltage of the battery in mVolts. If this attribute is not supported, enter 0.
		const Uint64 DesignVoltage() const;

		// Optional, The design voltage of the battery in mVolts. If this attribute is not supported, enter 0.
		void DesignVoltage(const Uint64 value); 

		// Is true if the field DesignVoltage exists in the current object, otherwise is false.
		bool DesignVoltageExists() const;

		// Remove DesignVoltage field.
		void RemoveDesignVoltage(); 

		// Optional, The Smart Battery Data Specification version number that is supported by this Battery. If the Battery does not support this function, the value should be left blank.
		const string SmartBatteryVersion() const;

		// Optional, The Smart Battery Data Specification version number that is supported by this Battery. If the Battery does not support this function, the value should be left blank.
		void SmartBatteryVersion(const string &value); 

		// Is true if the field SmartBatteryVersion exists in the current object, otherwise is false.
		bool SmartBatteryVersionExists() const;

		// Remove SmartBatteryVersion field.
		void RemoveSmartBatteryVersion(); 

		// Optional, The remaining time in minutes to charge the battery fully at the current charging rate and usage.
		const unsigned int TimeToFullCharge() const;

		// Optional, The remaining time in minutes to charge the battery fully at the current charging rate and usage.
		void TimeToFullCharge(const unsigned int value); 

		// Is true if the field TimeToFullCharge exists in the current object, otherwise is false.
		bool TimeToFullChargeExists() const;

		// Remove TimeToFullCharge field.
		void RemoveTimeToFullCharge(); 

		// Optional, Indicates the expected lifetime of the Battery in minutes, assuming that the Battery is fully charged. This property represents the total expected life of the Battery, not its current remaining life, which is indicated by the EstimatedRunTime property.
		const unsigned int ExpectedLife() const;

		// Optional, Indicates the expected lifetime of the Battery in minutes, assuming that the Battery is fully charged. This property represents the total expected life of the Battery, not its current remaining life, which is indicated by the EstimatedRunTime property.
		void ExpectedLife(const unsigned int value); 

		// Is true if the field ExpectedLife exists in the current object, otherwise is false.
		bool ExpectedLifeExists() const;

		// Remove ExpectedLife field.
		void RemoveExpectedLife(); 

		// Optional, MaxRechargeTime indicates the maximum time, in minutes, to fully charge the Battery. This property represents the time to recharge a fully depleted Battery, not the current remaining charging time, which is indicated in the TimeToFullCharge property.
		const unsigned int MaxRechargeTime() const;

		// Optional, MaxRechargeTime indicates the maximum time, in minutes, to fully charge the Battery. This property represents the time to recharge a fully depleted Battery, not the current remaining charging time, which is indicated in the TimeToFullCharge property.
		void MaxRechargeTime(const unsigned int value); 

		// Is true if the field MaxRechargeTime exists in the current object, otherwise is false.
		bool MaxRechargeTimeExists() const;

		// Remove MaxRechargeTime field.
		void RemoveMaxRechargeTime(); 

		// Optional, The number of times the Battery has been recharged.
		const unsigned int RechargeCount() const;

		// Optional, The number of times the Battery has been recharged.
		void RechargeCount(const unsigned int value); 

		// Is true if the field RechargeCount exists in the current object, otherwise is false.
		bool RechargeCountExists() const;

		// Remove RechargeCount field.
		void RemoveRechargeCount(); 

		// Optional, The maximum number of times the Battery can be recharged.
		const unsigned int MaxRechargeCount() const;

		// Optional, The maximum number of times the Battery can be recharged.
		void MaxRechargeCount(const unsigned int value); 

		// Is true if the field MaxRechargeCount exists in the current object, otherwise is false.
		bool MaxRechargeCountExists() const;

		// Remove MaxRechargeCount field.
		void RemoveMaxRechargeCount(); 

		// Optional, The Battery's remaining charge capacity in mWatt-hours.
		const unsigned int RemainingCapacity() const;

		// Optional, The Battery's remaining charge capacity in mWatt-hours.
		void RemainingCapacity(const unsigned int value); 

		// Is true if the field RemainingCapacity exists in the current object, otherwise is false.
		bool RemainingCapacityExists() const;

		// Remove RemainingCapacity field.
		void RemoveRemainingCapacity(); 

		// Optional, The maximum error (as a percentage) in the mWatt-hour data reported by RemainingCapacity property.
		const unsigned char RemainingCapacityMaxError() const;

		// Optional, The maximum error (as a percentage) in the mWatt-hour data reported by RemainingCapacity property.
		void RemainingCapacityMaxError(const unsigned char &value); 

		// Is true if the field RemainingCapacityMaxError exists in the current object, otherwise is false.
		bool RemainingCapacityMaxErrorExists() const;

		// Remove RemainingCapacityMaxError field.
		void RemoveRemainingCapacityMaxError(); 

		// Optional, The description of the battery chemistry when the Chemistry property has value 1 (Other). The property shall be implemented if the Chemistry property has value 1(Other).
		const string OtherChemistryDescription() const;

		// Optional, The description of the battery chemistry when the Chemistry property has value 1 (Other). The property shall be implemented if the Chemistry property has value 1(Other).
		void OtherChemistryDescription(const string &value); 

		// Is true if the field OtherChemistryDescription exists in the current object, otherwise is false.
		bool OtherChemistryDescriptionExists() const;

		// Remove OtherChemistryDescription field.
		void RemoveOtherChemistryDescription(); 

		// Optional, ChargingStatus indicates whether the battery is charging. Charging - the battery is charging. Discharging - the battery is discharging. Idle - the batter is neither charging nor discharging.
		const unsigned short ChargingStatus() const;

		// Optional, ChargingStatus indicates whether the battery is charging. Charging - the battery is charging. Discharging - the battery is discharging. Idle - the batter is neither charging nor discharging.
		void ChargingStatus(const unsigned short value); 

		// Is true if the field ChargingStatus exists in the current object, otherwise is false.
		bool ChargingStatusExists() const;

		// Remove ChargingStatus field.
		void RemoveChargingStatus(); 

		// Optional, An estimate of the percentage of the overall battery health. It indicates how much the battery has deteriorated over time. It can take values 0 to 100; 255 if it is unknown.
		const unsigned char HealthPercent() const;

		// Optional, An estimate of the percentage of the overall battery health. It indicates how much the battery has deteriorated over time. It can take values 0 to 100; 255 if it is unknown.
		void HealthPercent(const unsigned char &value); 

		// Is true if the field HealthPercent exists in the current object, otherwise is false.
		bool HealthPercentExists() const;

		// Remove HealthPercent field.
		void RemoveHealthPercent(); 

		 // Function used by the factory
		static CimBase *CreateFromCimObject(const CimObject &object);

		static vector<shared_ptr<CIM_Battery> > Enumerate(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		// Overloaded delete which supplies the internal resourceURI
		static void Delete(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		using CimBase::Delete;

	protected:
		 // Protected constructor to be used by derived classes
		CIM_Battery(ICimWsmanClient *client, const string &class_name,
			const string &class_ns, const string &prefix, const string &uri): CIM_LogicalDevice(client, class_name, class_ns, prefix, uri)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_LogicalDevice::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 19);
			}
		}
		 // Protected constructor which receives CimObject
		CIM_Battery(const CimObject &object)
			: CIM_LogicalDevice(object)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_LogicalDevice::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 19);
			}
		}
		// Called by derived classes
		void SetMetaData(vector<CimFieldAttribute>& childMetaData)
		{
			CIM_LogicalDevice::SetMetaData(childMetaData);
			CimBase::SetMetaData(childMetaData, _metadata, 19);
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
#endif // CIM_BATTERY_H
