//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_Processor.h
//
//  Contents:   Capabilities and management of the Processor LogicalDevice.
//
//              This file was automatically generated from CIM_Processor.mof,  version: 2.51.0
//
//----------------------------------------------------------------------------
#ifndef CIM_PROCESSOR_H
#define CIM_PROCESSOR_H 1
#include "CIM_LogicalDevice.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	// Capabilities and management of the Processor LogicalDevice.
	class CIMFRAMEWORK_API CIM_Processor  : public CIM_LogicalDevice
	{
	public:

		//Default constructor
		CIM_Processor()
			: CIM_LogicalDevice(NULL, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_LogicalDevice::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 16);
			}
		}

		//constructor which receives WSMan client
		CIM_Processor(ICimWsmanClient *client)
			: CIM_LogicalDevice(client, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_LogicalDevice::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 16);
			}
		}

		//Destructor
		virtual ~CIM_Processor(){}

		// The "type" information for the object. Gettors only.
		virtual const string& ResourceURI() const { return CLASS_URI; }
		static const string& ClassResourceURI() { return CLASS_URI; }
		virtual const string& XmlNamespace() const { return CLASS_NS; }
		virtual const string& XmlPrefix() const { return CLASS_NS_PREFIX; }
		virtual const string& ObjectType() const { return CLASS_NAME; }
		static const string& ClassObjectType() { return CLASS_NAME; }

		// Class representing CIM_Processor keys
		class CimKeys : public CIM_LogicalDevice::CimKeys
		{
		public:
		};

		// class fields declarations

		// Optional, A free-form string that describes the role of the Processor, for example, "Central Processor" or "Math Processor".
		const string Role() const;

		// Optional, A free-form string that describes the role of the Processor, for example, "Central Processor" or "Math Processor".
		void Role(const string &value); 

		// Is true if the field Role exists in the current object, otherwise is false.
		bool RoleExists() const;

		// Remove Role field.
		void RemoveRole(); 

		// Optional, The Processor family type. For example, values include "Pentium(R) processor with MMX(TM) technology" (value=14) and "68040" (value=96).
		const unsigned short Family() const;

		// Optional, The Processor family type. For example, values include "Pentium(R) processor with MMX(TM) technology" (value=14) and "68040" (value=96).
		void Family(const unsigned short value); 

		// Is true if the field Family exists in the current object, otherwise is false.
		bool FamilyExists() const;

		// Remove Family field.
		void RemoveFamily(); 

		// Optional, A string that describes the Processor Family type. It is used when the Family property is set to 1 ("Other"). This string should be set to NULL when the Family property is any value other than 1.
		const string OtherFamilyDescription() const;

		// Optional, A string that describes the Processor Family type. It is used when the Family property is set to 1 ("Other"). This string should be set to NULL when the Family property is any value other than 1.
		void OtherFamilyDescription(const string &value); 

		// Is true if the field OtherFamilyDescription exists in the current object, otherwise is false.
		bool OtherFamilyDescriptionExists() const;

		// Remove OtherFamilyDescription field.
		void RemoveOtherFamilyDescription(); 

		// Optional, CPU socket information that includes data on how this Processor can be upgraded (if upgrades are supported). This property is an integer enumeration.
		const unsigned short UpgradeMethod() const;

		// Optional, CPU socket information that includes data on how this Processor can be upgraded (if upgrades are supported). This property is an integer enumeration.
		void UpgradeMethod(const unsigned short value); 

		// Is true if the field UpgradeMethod exists in the current object, otherwise is false.
		bool UpgradeMethodExists() const;

		// Remove UpgradeMethod field.
		void RemoveUpgradeMethod(); 

		// Optional, The maximum speed (in MHz) of this Processor.
		const unsigned int MaxClockSpeed() const;

		// Optional, The maximum speed (in MHz) of this Processor.
		void MaxClockSpeed(const unsigned int value); 

		// Is true if the field MaxClockSpeed exists in the current object, otherwise is false.
		bool MaxClockSpeedExists() const;

		// Remove MaxClockSpeed field.
		void RemoveMaxClockSpeed(); 

		// Optional, The current speed (in MHz) of this Processor.
		const unsigned int CurrentClockSpeed() const;

		// Optional, The current speed (in MHz) of this Processor.
		void CurrentClockSpeed(const unsigned int value); 

		// Is true if the field CurrentClockSpeed exists in the current object, otherwise is false.
		bool CurrentClockSpeedExists() const;

		// Remove CurrentClockSpeed field.
		void RemoveCurrentClockSpeed(); 

		// Optional, Processor data width in bits.
		const unsigned short DataWidth() const;

		// Optional, Processor data width in bits.
		void DataWidth(const unsigned short value); 

		// Is true if the field DataWidth exists in the current object, otherwise is false.
		bool DataWidthExists() const;

		// Remove DataWidth field.
		void RemoveDataWidth(); 

		// Optional, Processor address width in bits.
		const unsigned short AddressWidth() const;

		// Optional, Processor address width in bits.
		void AddressWidth(const unsigned short value); 

		// Is true if the field AddressWidth exists in the current object, otherwise is false.
		bool AddressWidthExists() const;

		// Remove AddressWidth field.
		void RemoveAddressWidth(); 

		// Optional, Loading of this Processor, averaged over the last minute, in Percent.
		const unsigned short LoadPercentage() const;

		// Optional, Loading of this Processor, averaged over the last minute, in Percent.
		void LoadPercentage(const unsigned short value); 

		// Is true if the field LoadPercentage exists in the current object, otherwise is false.
		bool LoadPercentageExists() const;

		// Remove LoadPercentage field.
		void RemoveLoadPercentage(); 

		// Optional, Stepping is a free-form string that indicates the revision level of the Processor within the Processor.Family.
		const string Stepping() const;

		// Optional, Stepping is a free-form string that indicates the revision level of the Processor within the Processor.Family.
		void Stepping(const string &value); 

		// Is true if the field Stepping exists in the current object, otherwise is false.
		bool SteppingExists() const;

		// Remove Stepping field.
		void RemoveStepping(); 

		// Optional, A globally unique identifier for the Processor. This identifier can be unique only within a Processor Family.
		const string UniqueID() const;

		// Optional, A globally unique identifier for the Processor. This identifier can be unique only within a Processor Family.
		void UniqueID(const string &value); 

		// Is true if the field UniqueID exists in the current object, otherwise is false.
		bool UniqueIDExists() const;

		// Remove UniqueID field.
		void RemoveUniqueID(); 

		// Optional, The CPUStatus property that indicates the current status of the Processor. For example, the Processor might be disabled by the user (value=2), or disabled due to a POST error (value=3). Information in this property can be obtained from SMBIOS, the Type 4 structure, and the Status attribute.
		const unsigned short CPUStatus() const;

		// Optional, The CPUStatus property that indicates the current status of the Processor. For example, the Processor might be disabled by the user (value=2), or disabled due to a POST error (value=3). Information in this property can be obtained from SMBIOS, the Type 4 structure, and the Status attribute.
		void CPUStatus(const unsigned short value); 

		// Is true if the field CPUStatus exists in the current object, otherwise is false.
		bool CPUStatusExists() const;

		// Remove CPUStatus field.
		void RemoveCPUStatus(); 

		// Optional, The speed (in MHz) of the external bus interface (also known as the front side bus).
		const unsigned int ExternalBusClockSpeed() const;

		// Optional, The speed (in MHz) of the external bus interface (also known as the front side bus).
		void ExternalBusClockSpeed(const unsigned int value); 

		// Is true if the field ExternalBusClockSpeed exists in the current object, otherwise is false.
		bool ExternalBusClockSpeedExists() const;

		// Remove ExternalBusClockSpeed field.
		void RemoveExternalBusClockSpeed(); 

		// Optional, Array of enumerated values that describes the characteristics of the processor. The characteristics include certain features of the processor such as 64 bit support for data width of the processor. Note that if this property does not contain the value corresponding to a feature of the processor, than the feature either is not that some of the features of the processor may exist but may not be enabled. To find the the currently enabled features the processor, reffer to the EnabledProcessorCharacteristics property. Values specified in the enumeration may be obtained from SMBIOS v2.5 Type 4 offset 26h (Processor Characteristics Word). 32-bit Capable - describes whether the processor has the capability for 32 bits data width. 64-bit Capable - describes whether the processor has the capability for 64 bits data width. Enhanced Virtualization - describes whether the processor has the capability for executing enhanced virtualization instructions. Hardware Thread - indicates that the processor is capable of the hardware threading. NX-bit - describes whether the processor has capability to utilize non-execute bit and can differentiate the memory marked strictly for storage. Power/Performance Control - describes whether the processor has capability for load based power savings. Core Frequency Boosting - describes whether the processor has a capability for one processor core to increase its frequency whenever the other core has gone into an idle state.
		const vector<unsigned short> Characteristics() const;

		// Optional, Array of enumerated values that describes the characteristics of the processor. The characteristics include certain features of the processor such as 64 bit support for data width of the processor. Note that if this property does not contain the value corresponding to a feature of the processor, than the feature either is not that some of the features of the processor may exist but may not be enabled. To find the the currently enabled features the processor, reffer to the EnabledProcessorCharacteristics property. Values specified in the enumeration may be obtained from SMBIOS v2.5 Type 4 offset 26h (Processor Characteristics Word). 32-bit Capable - describes whether the processor has the capability for 32 bits data width. 64-bit Capable - describes whether the processor has the capability for 64 bits data width. Enhanced Virtualization - describes whether the processor has the capability for executing enhanced virtualization instructions. Hardware Thread - indicates that the processor is capable of the hardware threading. NX-bit - describes whether the processor has capability to utilize non-execute bit and can differentiate the memory marked strictly for storage. Power/Performance Control - describes whether the processor has capability for load based power savings. Core Frequency Boosting - describes whether the processor has a capability for one processor core to increase its frequency whenever the other core has gone into an idle state.
		void Characteristics(const vector<unsigned short> &value); 

		// Is true if the field Characteristics exists in the current object, otherwise is false.
		bool CharacteristicsExists() const;

		// Remove Characteristics field.
		void RemoveCharacteristics(); 

		// Optional, This property indicates the enabled states of the corresponding processor characteristics. The property array is indexed with ProcessorCharacteristics property array of the associated CIM_ProcessorCapabilities instance through the CIM_ElementCapabilities association. Each of the values in the ProcessorCharacteristics array property shall have its enabled state indicated in the corresponding element of this property array. For example; if the ProcessorCharacteristics array has value - NX-bit - for the first element of the array, then the first element of this property will contain the value for the enabled state of the NX-bit feature of the processor: whether the processor currently differentiates the dedicated storage memory based on the non-execute bit. Unknown - the processor feature is in unknown state. Enabled - the processor feature is enabled and could be used. Disabled - the processor feature is disabled and cannot be used. Not Applicable - the processor feature does not have state context.
		const vector<unsigned short> EnabledProcessorCharacteristics() const;

		// Optional, This property indicates the enabled states of the corresponding processor characteristics. The property array is indexed with ProcessorCharacteristics property array of the associated CIM_ProcessorCapabilities instance through the CIM_ElementCapabilities association. Each of the values in the ProcessorCharacteristics array property shall have its enabled state indicated in the corresponding element of this property array. For example; if the ProcessorCharacteristics array has value - NX-bit - for the first element of the array, then the first element of this property will contain the value for the enabled state of the NX-bit feature of the processor: whether the processor currently differentiates the dedicated storage memory based on the non-execute bit. Unknown - the processor feature is in unknown state. Enabled - the processor feature is enabled and could be used. Disabled - the processor feature is disabled and cannot be used. Not Applicable - the processor feature does not have state context.
		void EnabledProcessorCharacteristics(const vector<unsigned short> &value); 

		// Is true if the field EnabledProcessorCharacteristics exists in the current object, otherwise is false.
		bool EnabledProcessorCharacteristicsExists() const;

		// Remove EnabledProcessorCharacteristics field.
		void RemoveEnabledProcessorCharacteristics(); 

		// Optional, Number of processor cores enabled for processor.
		const unsigned short NumberOfEnabledCores() const;

		// Optional, Number of processor cores enabled for processor.
		void NumberOfEnabledCores(const unsigned short value); 

		// Is true if the field NumberOfEnabledCores exists in the current object, otherwise is false.
		bool NumberOfEnabledCoresExists() const;

		// Remove NumberOfEnabledCores field.
		void RemoveNumberOfEnabledCores(); 

		 // Function used by the factory
		static CimBase *CreateFromCimObject(const CimObject &object);

		static vector<shared_ptr<CIM_Processor> > Enumerate(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		// Overloaded delete which supplies the internal resourceURI
		static void Delete(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		using CimBase::Delete;

	protected:
		 // Protected constructor to be used by derived classes
		CIM_Processor(ICimWsmanClient *client, const string &class_name,
			const string &class_ns, const string &prefix, const string &uri): CIM_LogicalDevice(client, class_name, class_ns, prefix, uri)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_LogicalDevice::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 16);
			}
		}
		 // Protected constructor which receives CimObject
		CIM_Processor(const CimObject &object)
			: CIM_LogicalDevice(object)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_LogicalDevice::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 16);
			}
		}
		// Called by derived classes
		void SetMetaData(vector<CimFieldAttribute>& childMetaData)
		{
			CIM_LogicalDevice::SetMetaData(childMetaData);
			CimBase::SetMetaData(childMetaData, _metadata, 16);
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
#endif // CIM_PROCESSOR_H
