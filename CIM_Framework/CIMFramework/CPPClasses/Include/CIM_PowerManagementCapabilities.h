//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_PowerManagementCapabilities.h
//
//  Contents:   A class derived from Capabilities that describes the power management aspects of an element (typically a system or device). The element's power management capabilities are decoupled from a PowerManagementService, since a single service could apply to multiple elements, each with specific capabilities.
//
//              This file was automatically generated from CIM_PowerManagementCapabilities.mof,  version: 2.23.0
//
//----------------------------------------------------------------------------
#ifndef CIM_POWERMANAGEMENTCAPABILITIES_H
#define CIM_POWERMANAGEMENTCAPABILITIES_H 1
#include "CIM_Capabilities.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	// A class derived from Capabilities that describes the power management aspects of an element (typically a system or device). The element's power management capabilities are decoupled from a PowerManagementService, since a single service could apply to multiple elements, each with specific capabilities.
	class CIMFRAMEWORK_API CIM_PowerManagementCapabilities  : public CIM_Capabilities
	{
	public:

		//Default constructor
		CIM_PowerManagementCapabilities()
			: CIM_Capabilities(NULL, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_Capabilities::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 6);
			}
		}

		//constructor which receives WSMan client
		CIM_PowerManagementCapabilities(ICimWsmanClient *client)
			: CIM_Capabilities(client, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_Capabilities::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 6);
			}
		}

		//Destructor
		virtual ~CIM_PowerManagementCapabilities(){}

		// The "type" information for the object. Gettors only.
		virtual const string& ResourceURI() const { return CLASS_URI; }
		static const string& ClassResourceURI() { return CLASS_URI; }
		virtual const string& XmlNamespace() const { return CLASS_NS; }
		virtual const string& XmlPrefix() const { return CLASS_NS_PREFIX; }
		virtual const string& ObjectType() const { return CLASS_NAME; }
		static const string& ClassObjectType() { return CLASS_NAME; }

		// Class representing CIM_PowerManagementCapabilities keys
		class CimKeys : public CIM_Capabilities::CimKeys
		{
		public:
		};

		// class fields declarations

		// Optional, An enumeration indicating the specific power-related capabilities of a managed element. Since this is an array, multiple values may be specified. The current values in the enumeration are: 
		// 0 = Unknown 
		// 1 = Other 
		// 2 = Power Saving Modes Entered Automatically, describing that a managed element can change its power state based on usage or other criteria 
		// 3 = Power State Settable, indicating that the SetPowerState method is supported 
		// 4 = Power Cycling Supported, indicating that the SetPowerState method can be invoked with the PowerState input variable set to 'Power Cycle' 
		// 5 = Timed Power On Supported, indicating that the SetPowerState method can be invoked with the PowerState input variable set to 'Power Cycle' and the Time parameter set to a specific date and time, or interval, for power-on.
		const vector<unsigned short> PowerCapabilities() const;

		// Optional, An enumeration indicating the specific power-related capabilities of a managed element. Since this is an array, multiple values may be specified. The current values in the enumeration are: 
		// 0 = Unknown 
		// 1 = Other 
		// 2 = Power Saving Modes Entered Automatically, describing that a managed element can change its power state based on usage or other criteria 
		// 3 = Power State Settable, indicating that the SetPowerState method is supported 
		// 4 = Power Cycling Supported, indicating that the SetPowerState method can be invoked with the PowerState input variable set to 'Power Cycle' 
		// 5 = Timed Power On Supported, indicating that the SetPowerState method can be invoked with the PowerState input variable set to 'Power Cycle' and the Time parameter set to a specific date and time, or interval, for power-on.
		void PowerCapabilities(const vector<unsigned short> &value); 

		// Is true if the field PowerCapabilities exists in the current object, otherwise is false.
		bool PowerCapabilitiesExists() const;

		// Remove PowerCapabilities field.
		void RemovePowerCapabilities(); 

		// Optional, An array of strings describing an element's additional power management capabilities, used when the PowerCapabilities array includes the value 1, "Other".
		const vector<string> OtherPowerCapabilitiesDescriptions() const;

		// Optional, An array of strings describing an element's additional power management capabilities, used when the PowerCapabilities array includes the value 1, "Other".
		void OtherPowerCapabilitiesDescriptions(const vector<string> &value); 

		// Is true if the field OtherPowerCapabilitiesDescriptions exists in the current object, otherwise is false.
		bool OtherPowerCapabilitiesDescriptionsExists() const;

		// Remove OtherPowerCapabilitiesDescriptions field.
		void RemoveOtherPowerCapabilitiesDescriptions(); 

		// Optional, An enumeration that indicates the power states supported by a managed element. Because this is an array, multiple values can be specified. The current values in the enumeration are: 
		// 2=On, corresponding to ACPI state G0 or S0 or D0. 
		// 3=Sleep - Light, corresponding to ACPI state G1, S1/S2, or D1. 
		// 4=Sleep - Deep, corresponding to ACPI state G1, S3, or D2.
		// 5=Power Cycle (Off - Soft), corresponding to ACPI state G2, S5, or D3, but where the managed element is set to return to power state "On" at a pre-determined time. 
		// 6=Off - Hard, corresponding to ACPI state G3, S5, or D3. 
		// 7=Hibernate (Off - Soft), corresponding to ACPI state S4, where the state of the managed element is preserved and will be recovered upon powering on. 
		// 8=Off - Soft, corresponding to ACPI state G2, S5, or D3. 9= Power Cycle (Off-Hard), corresponds to the managed element reaching the ACPI state G3 followed by ACPI state S0. 
		// 10=Master Bus Reset, corresponds to the system reaching ACPI state S5 followed by ACPI state S0. This is used to represent system master bus reset. 11=Diagnostic Interrupt (NMI), corresponding to the system reaching ACPI state S5 followed by ACPI state S0. This is used to represent system non-maskable interrupt. 12=Off - Soft Graceful, equivalent to Off Soft but preceded by a request to the managed element to perform an orderlyshutdown. 
		// 13=Off - Hard Graceful, equivalent to Off Hard but preceded by a request to the managed element to perform an orderly shutdown. 
		// 14=Master Bus Rest Graceful, equivalent to Master Bus Reset but preceded by a request to the managed element to perform an orderly shutdown. 
		// 15=Power Cycle (Off - Soft Graceful), equivalent to Power Cycle (Off - Soft) but preceded by a request to the managed element to perform an orderly shutdown. 
		// 16=Power Cycle (Off - Hard Graceful), equivalent to Power Cycle (Off - Hard) but preceded by a request to the managed element to perform an orderly shutdown. 
		// ..=DMTF Reserved. 
		// 0x7FFF..0xFFFF = Vendor Specific.
		const vector<unsigned short> PowerStatesSupported() const;

		// Optional, An enumeration that indicates the power states supported by a managed element. Because this is an array, multiple values can be specified. The current values in the enumeration are: 
		// 2=On, corresponding to ACPI state G0 or S0 or D0. 
		// 3=Sleep - Light, corresponding to ACPI state G1, S1/S2, or D1. 
		// 4=Sleep - Deep, corresponding to ACPI state G1, S3, or D2.
		// 5=Power Cycle (Off - Soft), corresponding to ACPI state G2, S5, or D3, but where the managed element is set to return to power state "On" at a pre-determined time. 
		// 6=Off - Hard, corresponding to ACPI state G3, S5, or D3. 
		// 7=Hibernate (Off - Soft), corresponding to ACPI state S4, where the state of the managed element is preserved and will be recovered upon powering on. 
		// 8=Off - Soft, corresponding to ACPI state G2, S5, or D3. 9= Power Cycle (Off-Hard), corresponds to the managed element reaching the ACPI state G3 followed by ACPI state S0. 
		// 10=Master Bus Reset, corresponds to the system reaching ACPI state S5 followed by ACPI state S0. This is used to represent system master bus reset. 11=Diagnostic Interrupt (NMI), corresponding to the system reaching ACPI state S5 followed by ACPI state S0. This is used to represent system non-maskable interrupt. 12=Off - Soft Graceful, equivalent to Off Soft but preceded by a request to the managed element to perform an orderlyshutdown. 
		// 13=Off - Hard Graceful, equivalent to Off Hard but preceded by a request to the managed element to perform an orderly shutdown. 
		// 14=Master Bus Rest Graceful, equivalent to Master Bus Reset but preceded by a request to the managed element to perform an orderly shutdown. 
		// 15=Power Cycle (Off - Soft Graceful), equivalent to Power Cycle (Off - Soft) but preceded by a request to the managed element to perform an orderly shutdown. 
		// 16=Power Cycle (Off - Hard Graceful), equivalent to Power Cycle (Off - Hard) but preceded by a request to the managed element to perform an orderly shutdown. 
		// ..=DMTF Reserved. 
		// 0x7FFF..0xFFFF = Vendor Specific.
		void PowerStatesSupported(const vector<unsigned short> &value); 

		// Is true if the field PowerStatesSupported exists in the current object, otherwise is false.
		bool PowerStatesSupportedExists() const;

		// Remove PowerStatesSupported field.
		void RemovePowerStatesSupported(); 

		// Optional, An enumeration indicating the specific power-related capabilities of a managed element. Since this is an array, multiple values may be specified. The current values in the enumeration are: 
		// 0 = Unknown 
		// 1 = Other 
		// 2 = Power Saving Modes Entered Automatically, describing that a managed element can change its power state based on usage or other criteria 
		// 3 = Power State Settable, indicating that the RequestPowerStateChange method is supported 
		// 4 = Power Cycling Supported, indicating that the RequestPowerStateChange method can be invoked with the PowerState input variable set to 'Power Cycle (Off Soft)' 
		// 5 = Timed Power On Supported, indicating that the RequestPowerStateChange method can be invoked with the PowerState input variable set to 'Power On' and the Time parameter set to a specific date and time, or interval, for power-on.8 = Graceful Shutdown Supported, indicating that the managed element can be sent a hardware signal requesting an orderly shutdown prior to the requested power state change.
		const vector<unsigned short> PowerChangeCapabilities() const;

		// Optional, An enumeration indicating the specific power-related capabilities of a managed element. Since this is an array, multiple values may be specified. The current values in the enumeration are: 
		// 0 = Unknown 
		// 1 = Other 
		// 2 = Power Saving Modes Entered Automatically, describing that a managed element can change its power state based on usage or other criteria 
		// 3 = Power State Settable, indicating that the RequestPowerStateChange method is supported 
		// 4 = Power Cycling Supported, indicating that the RequestPowerStateChange method can be invoked with the PowerState input variable set to 'Power Cycle (Off Soft)' 
		// 5 = Timed Power On Supported, indicating that the RequestPowerStateChange method can be invoked with the PowerState input variable set to 'Power On' and the Time parameter set to a specific date and time, or interval, for power-on.8 = Graceful Shutdown Supported, indicating that the managed element can be sent a hardware signal requesting an orderly shutdown prior to the requested power state change.
		void PowerChangeCapabilities(const vector<unsigned short> &value); 

		// Is true if the field PowerChangeCapabilities exists in the current object, otherwise is false.
		bool PowerChangeCapabilitiesExists() const;

		// Remove PowerChangeCapabilities field.
		void RemovePowerChangeCapabilities(); 

		// Optional, A string describing the additional power management capabilities of the element, used when the PowerChangeCapabilities is set to the value 1, "Other".
		const string OtherPowerChangeCapabilities() const;

		// Optional, A string describing the additional power management capabilities of the element, used when the PowerChangeCapabilities is set to the value 1, "Other".
		void OtherPowerChangeCapabilities(const string &value); 

		// Is true if the field OtherPowerChangeCapabilities exists in the current object, otherwise is false.
		bool OtherPowerChangeCapabilitiesExists() const;

		// Remove OtherPowerChangeCapabilities field.
		void RemoveOtherPowerChangeCapabilities(); 

		// Optional, An enumeration that indicates the requested power states supported by the power management service. Because this is an array, multiple values can be specified. The current values in the enumeration are: 
		// 2=On, corresponding to ACPI state G0 or S0 or D0. 
		// 3=Sleep - Light, corresponding to ACPI state G1, S1/S2, or D1. 
		// 4=Sleep - Deep, corresponding to ACPI state G1, S3, or D2.
		// 5=Power Cycle (Off - Soft), corresponding to ACPI state G2, S5, or D3, but where the managed element is set to return to power state "On" at a pre-determined time. 
		// 6=Off - Hard, corresponding to ACPI state G3, S5, or D3. 
		// 7=Hibernate (Off - Soft), corresponding to ACPI state S4, where the state of the managed element is preserved and will be recovered upon powering on. 
		// 8=Off - Soft, corresponding to ACPI state G2, S5, or D3. 9= Power Cycle (Off-Hard), corresponds to the managed element reaching the ACPI state G3 followed by ACPI state S0. 
		// 10=Master Bus Reset, corresponds to the system reaching ACPI state S5 followed by ACPI state S0. This is used to represent system master bus reset. 11=Diagnostic Interrupt (NMI), corresponding to the system reaching ACPI state S5 followed by ACPI state S0. This is used to represent system non-maskable interrupt. 12=Off - Soft Graceful, equivalent to Off Soft but preceded by a request to the managed element to perform an orderlyshutdown. 
		// 13=Off - Hard Graceful, equivalent to Off Hard but preceded by a request to the managed element to perform an orderly shutdown. 
		// 14=Master Bus Rest Graceful, equivalent to Master Bus Reset but preceded by a request to the managed element to perform an orderly shutdown. 
		// 15=Power Cycle (Off - Soft Graceful), equivalent to Power Cycle (Off - Soft) but preceded by a request to the managed element to perform an orderly shutdown. 
		// 16=Power Cycle (Off - Hard Graceful), equivalent to Power Cycle (Off - Hard) but preceded by a request to the managed element to perform an orderly shutdown. 
		// 17=Diagnostic Interrupt (INIT), equivalent to Diagnostic Interrupt (NMI) but performed by an INIT switch instead because the NMI signal is masked. 
		// ..=DMTF Reserved. 
		// 0x7FFF..0xFFFF = Vendor Specific.
		const vector<unsigned short> RequestedPowerStatesSupported() const;

		// Optional, An enumeration that indicates the requested power states supported by the power management service. Because this is an array, multiple values can be specified. The current values in the enumeration are: 
		// 2=On, corresponding to ACPI state G0 or S0 or D0. 
		// 3=Sleep - Light, corresponding to ACPI state G1, S1/S2, or D1. 
		// 4=Sleep - Deep, corresponding to ACPI state G1, S3, or D2.
		// 5=Power Cycle (Off - Soft), corresponding to ACPI state G2, S5, or D3, but where the managed element is set to return to power state "On" at a pre-determined time. 
		// 6=Off - Hard, corresponding to ACPI state G3, S5, or D3. 
		// 7=Hibernate (Off - Soft), corresponding to ACPI state S4, where the state of the managed element is preserved and will be recovered upon powering on. 
		// 8=Off - Soft, corresponding to ACPI state G2, S5, or D3. 9= Power Cycle (Off-Hard), corresponds to the managed element reaching the ACPI state G3 followed by ACPI state S0. 
		// 10=Master Bus Reset, corresponds to the system reaching ACPI state S5 followed by ACPI state S0. This is used to represent system master bus reset. 11=Diagnostic Interrupt (NMI), corresponding to the system reaching ACPI state S5 followed by ACPI state S0. This is used to represent system non-maskable interrupt. 12=Off - Soft Graceful, equivalent to Off Soft but preceded by a request to the managed element to perform an orderlyshutdown. 
		// 13=Off - Hard Graceful, equivalent to Off Hard but preceded by a request to the managed element to perform an orderly shutdown. 
		// 14=Master Bus Rest Graceful, equivalent to Master Bus Reset but preceded by a request to the managed element to perform an orderly shutdown. 
		// 15=Power Cycle (Off - Soft Graceful), equivalent to Power Cycle (Off - Soft) but preceded by a request to the managed element to perform an orderly shutdown. 
		// 16=Power Cycle (Off - Hard Graceful), equivalent to Power Cycle (Off - Hard) but preceded by a request to the managed element to perform an orderly shutdown. 
		// 17=Diagnostic Interrupt (INIT), equivalent to Diagnostic Interrupt (NMI) but performed by an INIT switch instead because the NMI signal is masked. 
		// ..=DMTF Reserved. 
		// 0x7FFF..0xFFFF = Vendor Specific.
		void RequestedPowerStatesSupported(const vector<unsigned short> &value); 

		// Is true if the field RequestedPowerStatesSupported exists in the current object, otherwise is false.
		bool RequestedPowerStatesSupportedExists() const;

		// Remove RequestedPowerStatesSupported field.
		void RemoveRequestedPowerStatesSupported(); 

		 // Function used by the factory
		static CimBase *CreateFromCimObject(const CimObject &object);

		static vector<shared_ptr<CIM_PowerManagementCapabilities> > Enumerate(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		// Overloaded delete which supplies the internal resourceURI
		static void Delete(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		using CimBase::Delete;

	protected:
		 // Protected constructor to be used by derived classes
		CIM_PowerManagementCapabilities(ICimWsmanClient *client, const string &class_name,
			const string &class_ns, const string &prefix, const string &uri): CIM_Capabilities(client, class_name, class_ns, prefix, uri)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_Capabilities::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 6);
			}
		}
		 // Protected constructor which receives CimObject
		CIM_PowerManagementCapabilities(const CimObject &object)
			: CIM_Capabilities(object)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_Capabilities::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 6);
			}
		}
		// Called by derived classes
		void SetMetaData(vector<CimFieldAttribute>& childMetaData)
		{
			CIM_Capabilities::SetMetaData(childMetaData);
			CimBase::SetMetaData(childMetaData, _metadata, 6);
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
#endif // CIM_POWERMANAGEMENTCAPABILITIES_H
