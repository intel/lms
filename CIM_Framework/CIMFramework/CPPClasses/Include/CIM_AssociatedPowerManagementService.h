//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_AssociatedPowerManagementService.h
//
//  Contents:   The association between a Managed System Element and its power management service.
//
//              This file was automatically generated from CIM_AssociatedPowerManagementService.mof,  version: 2.24.1
//
//----------------------------------------------------------------------------
#ifndef CIM_ASSOCIATEDPOWERMANAGEMENTSERVICE_H
#define CIM_ASSOCIATEDPOWERMANAGEMENTSERVICE_H 1
#include "CIM_ServiceAvailableToElement.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	// The association between a Managed System Element and its power management service.
	class CIMFRAMEWORK_API CIM_AssociatedPowerManagementService  : public CIM_ServiceAvailableToElement
	{
	public:

		//Default constructor
		CIM_AssociatedPowerManagementService()
			: CIM_ServiceAvailableToElement(NULL, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_ServiceAvailableToElement::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 8);
			}
		}

		//constructor which receives WSMan client
		CIM_AssociatedPowerManagementService(ICimWsmanClient *client)
			: CIM_ServiceAvailableToElement(client, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_ServiceAvailableToElement::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 8);
			}
		}

		//Destructor
		virtual ~CIM_AssociatedPowerManagementService(){}

		// The "type" information for the object. Gettors only.
		virtual const string& ResourceURI() const { return CLASS_URI; }
		static const string& ClassResourceURI() { return CLASS_URI; }
		virtual const string& XmlNamespace() const { return CLASS_NS; }
		virtual const string& XmlPrefix() const { return CLASS_NS_PREFIX; }
		virtual const string& ObjectType() const { return CLASS_NAME; }
		static const string& ClassObjectType() { return CLASS_NAME; }

		// Class representing CIM_AssociatedPowerManagementService keys
		class CimKeys : public CIM_ServiceAvailableToElement::CimKeys
		{
		public:
			// Required, The Service that is available.
			const CimReference ServiceProvided() const
			{
				CimReference ret;
				TypeConverter::StringToType(GetKey("ServiceProvided"), ret);
				return ret;
			}

			// Required, The Service that is available.
			void ServiceProvided(const CimReference &value)
			{
				SetOrAddKey("ServiceProvided", TypeConverter::TypeToString(value), true);
			}

		};

		// class fields declarations

		// Optional, The current power state of the associated Managed System Element.
		const unsigned short PowerState() const;

		// Optional, The current power state of the associated Managed System Element.
		void PowerState(const unsigned short value); 

		// Is true if the field PowerState exists in the current object, otherwise is false.
		bool PowerStateExists() const;

		// Remove PowerState field.
		void RemovePowerState(); 

		// Optional, A string describing the additional power management state of the element, used when the PowerState is set to the value 1, "Other".
		const string OtherPowerState() const;

		// Optional, A string describing the additional power management state of the element, used when the PowerState is set to the value 1, "Other".
		void OtherPowerState(const string &value); 

		// Is true if the field OtherPowerState exists in the current object, otherwise is false.
		bool OtherPowerStateExists() const;

		// Remove OtherPowerState field.
		void RemoveOtherPowerState(); 

		// Optional, The desired or the last requested power state of the associated Managed System Element, irrespective of the mechanism through which the request was made. If the requested power state is unknown, then the property shall have the value of 0 ("Unknown"). If the property has no meaning or is not supported, then the property shall have value 12("Not Applicable").
		const unsigned short RequestedPowerState() const;

		// Optional, The desired or the last requested power state of the associated Managed System Element, irrespective of the mechanism through which the request was made. If the requested power state is unknown, then the property shall have the value of 0 ("Unknown"). If the property has no meaning or is not supported, then the property shall have value 12("Not Applicable").
		void RequestedPowerState(const unsigned short value); 

		// Is true if the field RequestedPowerState exists in the current object, otherwise is false.
		bool RequestedPowerStateExists() const;

		// Remove RequestedPowerState field.
		void RemoveRequestedPowerState(); 

		// Optional, A string describing the additional power management state of the element, used when the RequestedPowerState is set to the value 1, "Other".
		const string OtherRequestedPowerState() const;

		// Optional, A string describing the additional power management state of the element, used when the RequestedPowerState is set to the value 1, "Other".
		void OtherRequestedPowerState(const string &value); 

		// Is true if the field OtherRequestedPowerState exists in the current object, otherwise is false.
		bool OtherRequestedPowerStateExists() const;

		// Remove OtherRequestedPowerState field.
		void RemoveOtherRequestedPowerState(); 

		// Optional, The time when the element will be powered on again, used when the RequestedPowerState has the value 2, "On", 5, "Power Cycle (Off - Soft)" or 6, "Power Cycle (Off - Hard)".
		const CimDateTime PowerOnTime() const;

		// Optional, The time when the element will be powered on again, used when the RequestedPowerState has the value 2, "On", 5, "Power Cycle (Off - Soft)" or 6, "Power Cycle (Off - Hard)".
		void PowerOnTime(const CimDateTime &value); 

		// Is true if the field PowerOnTime exists in the current object, otherwise is false.
		bool PowerOnTimeExists() const;

		// Remove PowerOnTime field.
		void RemovePowerOnTime(); 

		// Optional, AvailableRequestedPowerStates indicates the possible values for the PowerState parameter of the method RequestPowerStateChange, used to initiate a power state change.The values listed shall be a subset of the values contained in the RequestedPowerStatesSupported property of the CIM_PowerManagementCapabilities where the values selected are a function of the current power state of the system. This property shall be non-null if an implementation supports the advertisement of the set of possible values as a function of the current state. This property shall be null if an implementation does not support the advertisement of the set of possible values as a function of the current state. 
		// The current values in the enumeration are: 
		// 2=On, corresponding to ACPI state G0 or S0 or D0. 
		// 3=Sleep - Light, corresponding to ACPI state G1, S1/S2, or D1. 
		// 4=Sleep - Deep, corresponding to ACPI state G1, S3, or D2.
		// 5=Power Cycle (Off - Soft), corresponding to ACPI state G2, S5, or D3, but where the managed element is set to return to power state "On" at a pre-determined time. 
		// 6=Off - Hard, corresponding to ACPI state G3, S5, or D3. 
		// 7=Hibernate (Off - Soft), corresponding to ACPI state S4, where the state of the managed element is preserved and will be recovered upon powering on. 
		// 8=Off - Soft, corresponding to ACPI state G2, S5, or D3. 9= Power Cycle (Off-Hard), corresponds to the managed element reaching the ACPI state G3 followed by ACPI state S0. 
		// 10=Master Bus Reset, corresponds to the system reaching ACPI state S5 followed by ACPI state S0. This is used to represent system master bus reset. 11=Diagnostic Interrupt (NMI), corresponding to the system reaching ACPI state S5 followed by ACPI state S0. This is used to represent system non-maskable interrupt. 12=Off - Soft Graceful, equivalent to Off Soft but preceded by a request to the managed element to perform an orderly shutdown. 
		// 13=Off - Hard Graceful, equivalent to Off Hard but preceded by a request to the managed element to perform an orderly shutdown. 
		// 14=Master Bus Rest Graceful, equivalent to Master Bus Reset but preceded by a request to the managed element to perform an orderly shutdown. 
		// 15=Power Cycle (Off - Soft Graceful), equivalent to Power Cycle (Off - Soft) but preceded by a request to the managed element to perform an orderly shutdown. 
		// 16=Power Cycle (Off - Hard Graceful), equivalent to Power Cycle (Off - Hard) but preceded by a request to the managed element to perform an orderly shutdown. 
		// ..=DMTF Reserved. 
		// 0x7FFF..0xFFFF = Vendor Specific.
		const vector<unsigned short> AvailableRequestedPowerStates() const;

		// Optional, AvailableRequestedPowerStates indicates the possible values for the PowerState parameter of the method RequestPowerStateChange, used to initiate a power state change.The values listed shall be a subset of the values contained in the RequestedPowerStatesSupported property of the CIM_PowerManagementCapabilities where the values selected are a function of the current power state of the system. This property shall be non-null if an implementation supports the advertisement of the set of possible values as a function of the current state. This property shall be null if an implementation does not support the advertisement of the set of possible values as a function of the current state. 
		// The current values in the enumeration are: 
		// 2=On, corresponding to ACPI state G0 or S0 or D0. 
		// 3=Sleep - Light, corresponding to ACPI state G1, S1/S2, or D1. 
		// 4=Sleep - Deep, corresponding to ACPI state G1, S3, or D2.
		// 5=Power Cycle (Off - Soft), corresponding to ACPI state G2, S5, or D3, but where the managed element is set to return to power state "On" at a pre-determined time. 
		// 6=Off - Hard, corresponding to ACPI state G3, S5, or D3. 
		// 7=Hibernate (Off - Soft), corresponding to ACPI state S4, where the state of the managed element is preserved and will be recovered upon powering on. 
		// 8=Off - Soft, corresponding to ACPI state G2, S5, or D3. 9= Power Cycle (Off-Hard), corresponds to the managed element reaching the ACPI state G3 followed by ACPI state S0. 
		// 10=Master Bus Reset, corresponds to the system reaching ACPI state S5 followed by ACPI state S0. This is used to represent system master bus reset. 11=Diagnostic Interrupt (NMI), corresponding to the system reaching ACPI state S5 followed by ACPI state S0. This is used to represent system non-maskable interrupt. 12=Off - Soft Graceful, equivalent to Off Soft but preceded by a request to the managed element to perform an orderly shutdown. 
		// 13=Off - Hard Graceful, equivalent to Off Hard but preceded by a request to the managed element to perform an orderly shutdown. 
		// 14=Master Bus Rest Graceful, equivalent to Master Bus Reset but preceded by a request to the managed element to perform an orderly shutdown. 
		// 15=Power Cycle (Off - Soft Graceful), equivalent to Power Cycle (Off - Soft) but preceded by a request to the managed element to perform an orderly shutdown. 
		// 16=Power Cycle (Off - Hard Graceful), equivalent to Power Cycle (Off - Hard) but preceded by a request to the managed element to perform an orderly shutdown. 
		// ..=DMTF Reserved. 
		// 0x7FFF..0xFFFF = Vendor Specific.
		void AvailableRequestedPowerStates(const vector<unsigned short> &value); 

		// Is true if the field AvailableRequestedPowerStates exists in the current object, otherwise is false.
		bool AvailableRequestedPowerStatesExists() const;

		// Remove AvailableRequestedPowerStates field.
		void RemoveAvailableRequestedPowerStates(); 

		// Optional, TransitioningToPowerState indicates the target power state to which the system is transitioning. 
		// A value of 19 "No Change" shall indicate that no transition is in progress. A value of 18 "Not Applicable" shall indicate the implementation does not support representing ongoing transitions. 
		// A value other than 18 or 19 shall identify the power state to which the element is in the process of transitioning.
		const unsigned short TransitioningToPowerState() const;

		// Optional, TransitioningToPowerState indicates the target power state to which the system is transitioning. 
		// A value of 19 "No Change" shall indicate that no transition is in progress. A value of 18 "Not Applicable" shall indicate the implementation does not support representing ongoing transitions. 
		// A value other than 18 or 19 shall identify the power state to which the element is in the process of transitioning.
		void TransitioningToPowerState(const unsigned short value); 

		// Is true if the field TransitioningToPowerState exists in the current object, otherwise is false.
		bool TransitioningToPowerStateExists() const;

		// Remove TransitioningToPowerState field.
		void RemoveTransitioningToPowerState(); 

		 // Function used by the factory
		static CimBase *CreateFromCimObject(const CimObject &object);

		static vector<shared_ptr<CIM_AssociatedPowerManagementService> > Enumerate(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		// Overloaded delete which supplies the internal resourceURI
		static void Delete(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		using CimBase::Delete;

	protected:
		 // Protected constructor to be used by derived classes
		CIM_AssociatedPowerManagementService(ICimWsmanClient *client, const string &class_name,
			const string &class_ns, const string &prefix, const string &uri): CIM_ServiceAvailableToElement(client, class_name, class_ns, prefix, uri)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_ServiceAvailableToElement::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 8);
			}
		}
		 // Protected constructor which receives CimObject
		CIM_AssociatedPowerManagementService(const CimObject &object)
			: CIM_ServiceAvailableToElement(object)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_ServiceAvailableToElement::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 8);
			}
		}
		// Called by derived classes
		void SetMetaData(vector<CimFieldAttribute>& childMetaData)
		{
			CIM_ServiceAvailableToElement::SetMetaData(childMetaData);
			CimBase::SetMetaData(childMetaData, _metadata, 8);
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
#endif // CIM_ASSOCIATEDPOWERMANAGEMENTSERVICE_H
