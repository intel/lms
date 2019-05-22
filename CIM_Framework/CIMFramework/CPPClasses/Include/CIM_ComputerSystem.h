//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_ComputerSystem.h
//
//  Contents:   A class derived from System that is a special collection of ManagedSystemElements. This collection is related to the providing of compute capabilities and MAY serve as an aggregation point to associate one or more of the following elements: FileSystem, OperatingSystem, Processor and Memory (Volatile and/or NonVolatile Storage).
//
//              This file was automatically generated from CIM_ComputerSystem.mof,  version: 2.28.0
//
//----------------------------------------------------------------------------
#ifndef CIM_COMPUTERSYSTEM_H
#define CIM_COMPUTERSYSTEM_H 1
#include "CIM_System.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	// A class derived from System that is a special collection of ManagedSystemElements. This collection is related to the providing of compute capabilities and MAY serve as an aggregation point to associate one or more of the following elements: FileSystem, OperatingSystem, Processor and Memory (Volatile and/or NonVolatile Storage).
	class CIMFRAMEWORK_API CIM_ComputerSystem  : public CIM_System
	{
	public:

		//Default constructor
		CIM_ComputerSystem()
			: CIM_System(NULL, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_System::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 5);
			}
		}

		//constructor which receives WSMan client
		CIM_ComputerSystem(ICimWsmanClient *client)
			: CIM_System(client, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_System::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 5);
			}
		}

		//Destructor
		virtual ~CIM_ComputerSystem(){}

		// The "type" information for the object. Gettors only.
		virtual const string& ResourceURI() const { return CLASS_URI; }
		static const string& ClassResourceURI() { return CLASS_URI; }
		virtual const string& XmlNamespace() const { return CLASS_NS; }
		virtual const string& XmlPrefix() const { return CLASS_NS_PREFIX; }
		virtual const string& ObjectType() const { return CLASS_NAME; }
		static const string& ClassObjectType() { return CLASS_NAME; }

		// Class representing CIM_ComputerSystem keys
		class CimKeys : public CIM_System::CimKeys
		{
		public:
		};

		// class fields declarations

		// Optional, Enumeration indicating the purpose(s) to which the ComputerSystem is dedicated, if any, and what functionality is provided. For example, one could specify that the System is dedicated to "Print" (value=11) or acts as a "Hub" (value=8). 
		// Also, one could indicate that this is a general purpose system by indicating 'Not Dedicated' (value=0) but that it also hosts 'Print' (value=11) or mobile phone 'Mobile User Device' (value=17) services. 
		// A clarification is needed with respect to the value 17 ("Mobile User Device"). An example of a dedicated user device is a mobile phone or a barcode scanner in a store that communicates via radio frequency. These systems are quite limited in functionality and programmability, and are not considered 'general purpose' computing platforms. Alternately, an example of a mobile system that is 'general purpose' (i.e., is NOT dedicated) is a hand-held computer. Although limited in its programmability, new software can be downloaded and its functionality expanded by the user. 
		// A value of "Management" indicates this instance is dedicated to hosting system management software.
		// A value of "Management Controller" indicates this instance represents specialized hardware dedicated to systems management (i.e., a Baseboard Management Controller (BMC) or service processor).
		// The management scope of a "Management Controller" is typically a single managed system in which it is contained.
		// A value of "Chassis Manager" indicates this instance represents a system dedicated to management of a blade chassis and its contained devices. This value would be used to represent a Shelf Controller. A "Chassis Manager" is an aggregation point for management and may rely on subordinate management controllers for the management of constituent parts. A value of "Host-based RAID Controller" indicates this instance represents a RAID storage controller contained within a host computer. A value of "Storage Device Enclosure" indicates this instance represents an enclosure that contains storage devices. A "Virtual Tape Library" is the emulation of a tape library by a Virtual Library System. A "Virtual Library System" uses disk storage to emulate tape libraries.A "FC Switch" indicates this instance is dedicated to switching layer 2 fibre channel frames. An "Ethernet Switch" indicates this instance is dedicated to switching layer 2 ethernet frames.
		const vector<unsigned short> Dedicated() const;

		// Optional, Enumeration indicating the purpose(s) to which the ComputerSystem is dedicated, if any, and what functionality is provided. For example, one could specify that the System is dedicated to "Print" (value=11) or acts as a "Hub" (value=8). 
		// Also, one could indicate that this is a general purpose system by indicating 'Not Dedicated' (value=0) but that it also hosts 'Print' (value=11) or mobile phone 'Mobile User Device' (value=17) services. 
		// A clarification is needed with respect to the value 17 ("Mobile User Device"). An example of a dedicated user device is a mobile phone or a barcode scanner in a store that communicates via radio frequency. These systems are quite limited in functionality and programmability, and are not considered 'general purpose' computing platforms. Alternately, an example of a mobile system that is 'general purpose' (i.e., is NOT dedicated) is a hand-held computer. Although limited in its programmability, new software can be downloaded and its functionality expanded by the user. 
		// A value of "Management" indicates this instance is dedicated to hosting system management software.
		// A value of "Management Controller" indicates this instance represents specialized hardware dedicated to systems management (i.e., a Baseboard Management Controller (BMC) or service processor).
		// The management scope of a "Management Controller" is typically a single managed system in which it is contained.
		// A value of "Chassis Manager" indicates this instance represents a system dedicated to management of a blade chassis and its contained devices. This value would be used to represent a Shelf Controller. A "Chassis Manager" is an aggregation point for management and may rely on subordinate management controllers for the management of constituent parts. A value of "Host-based RAID Controller" indicates this instance represents a RAID storage controller contained within a host computer. A value of "Storage Device Enclosure" indicates this instance represents an enclosure that contains storage devices. A "Virtual Tape Library" is the emulation of a tape library by a Virtual Library System. A "Virtual Library System" uses disk storage to emulate tape libraries.A "FC Switch" indicates this instance is dedicated to switching layer 2 fibre channel frames. An "Ethernet Switch" indicates this instance is dedicated to switching layer 2 ethernet frames.
		void Dedicated(const vector<unsigned short> &value); 

		// Is true if the field Dedicated exists in the current object, otherwise is false.
		bool DedicatedExists() const;

		// Remove Dedicated field.
		void RemoveDedicated(); 

		// Optional, A string describing how or why the system is dedicated when the Dedicated array includes the value 2, "Other".
		const vector<string> OtherDedicatedDescriptions() const;

		// Optional, A string describing how or why the system is dedicated when the Dedicated array includes the value 2, "Other".
		void OtherDedicatedDescriptions(const vector<string> &value); 

		// Is true if the field OtherDedicatedDescriptions exists in the current object, otherwise is false.
		bool OtherDedicatedDescriptionsExists() const;

		// Remove OtherDedicatedDescriptions field.
		void RemoveOtherDedicatedDescriptions(); 

		// Optional, If enabled (value = 4), the ComputerSystem can be reset via hardware (e.g. the power and reset buttons). If disabled (value = 3), hardware reset is not allowed. In addition to Enabled and Disabled, other Values for the property are also defined - "Not Implemented" (5), "Other" (1) and "Unknown" (2).
		const unsigned short ResetCapability() const;

		// Optional, If enabled (value = 4), the ComputerSystem can be reset via hardware (e.g. the power and reset buttons). If disabled (value = 3), hardware reset is not allowed. In addition to Enabled and Disabled, other Values for the property are also defined - "Not Implemented" (5), "Other" (1) and "Unknown" (2).
		void ResetCapability(const unsigned short value); 

		// Is true if the field ResetCapability exists in the current object, otherwise is false.
		bool ResetCapabilityExists() const;

		// Remove ResetCapability field.
		void RemoveResetCapability(); 

		// Optional, An enumerated array describing the power management capabilities of the ComputerSystem. The use of this property has been deprecated. Instead, the Power Capabilites property in an associated PowerManagement Capabilities class should be used.
		const vector<unsigned short> PowerManagementCapabilities() const;

		// Optional, An enumerated array describing the power management capabilities of the ComputerSystem. The use of this property has been deprecated. Instead, the Power Capabilites property in an associated PowerManagement Capabilities class should be used.
		void PowerManagementCapabilities(const vector<unsigned short> &value); 

		// Is true if the field PowerManagementCapabilities exists in the current object, otherwise is false.
		bool PowerManagementCapabilitiesExists() const;

		// Remove PowerManagementCapabilities field.
		void RemovePowerManagementCapabilities(); 

		 // Function used by the factory
		static CimBase *CreateFromCimObject(const CimObject &object);

		static vector<shared_ptr<CIM_ComputerSystem> > Enumerate(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		// Overloaded delete which supplies the internal resourceURI
		static void Delete(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		using CimBase::Delete;

	protected:
		 // Protected constructor to be used by derived classes
		CIM_ComputerSystem(ICimWsmanClient *client, const string &class_name,
			const string &class_ns, const string &prefix, const string &uri): CIM_System(client, class_name, class_ns, prefix, uri)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_System::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 5);
			}
		}
		 // Protected constructor which receives CimObject
		CIM_ComputerSystem(const CimObject &object)
			: CIM_System(object)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_System::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 5);
			}
		}
		// Called by derived classes
		void SetMetaData(vector<CimFieldAttribute>& childMetaData)
		{
			CIM_System::SetMetaData(childMetaData);
			CimBase::SetMetaData(childMetaData, _metadata, 5);
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
#endif // CIM_COMPUTERSYSTEM_H
