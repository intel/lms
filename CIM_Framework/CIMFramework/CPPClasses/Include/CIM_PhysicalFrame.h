//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_PhysicalFrame.h
//
//  Contents:   PhysicalFrame is a superclass of Rack, Chassis and other frame enclosures, as they are defined in extension classes. Properties like visible or audible alarm, and data related to security breaches are in this superclass.
//
//              This file was automatically generated from CIM_PhysicalFrame.mof,  version: 2.7.0
//
//----------------------------------------------------------------------------
#ifndef CIM_PHYSICALFRAME_H
#define CIM_PHYSICALFRAME_H 1
#include "CIM_PhysicalPackage.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	// PhysicalFrame is a superclass of Rack, Chassis and other frame enclosures, as they are defined in extension classes. Properties like visible or audible alarm, and data related to security breaches are in this superclass.
	class CIMFRAMEWORK_API CIM_PhysicalFrame  : public CIM_PhysicalPackage
	{
	public:

		//Default constructor
		CIM_PhysicalFrame()
			: CIM_PhysicalPackage(NULL, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_PhysicalPackage::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 9);
			}
		}

		//constructor which receives WSMan client
		CIM_PhysicalFrame(ICimWsmanClient *client)
			: CIM_PhysicalPackage(client, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_PhysicalPackage::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 9);
			}
		}

		//Destructor
		virtual ~CIM_PhysicalFrame(){}

		// The "type" information for the object. Gettors only.
		virtual const string& ResourceURI() const { return CLASS_URI; }
		static const string& ClassResourceURI() { return CLASS_URI; }
		virtual const string& XmlNamespace() const { return CLASS_NS; }
		virtual const string& XmlPrefix() const { return CLASS_NS_PREFIX; }
		virtual const string& ObjectType() const { return CLASS_NAME; }
		static const string& ClassObjectType() { return CLASS_NAME; }

		// Class representing CIM_PhysicalFrame keys
		class CimKeys : public CIM_PhysicalPackage::CimKeys
		{
		public:
		};

		// class fields declarations

		// Optional, CableManagementStrategy is a free-form string that contains information on how the various cables are connected and bundled for the Frame. With many networking, storage-related and power cables, cable management can be a complex and challenging endeavor. This string property contains information to aid in assembly and service of the Frame.
		const string CableManagementStrategy() const;

		// Optional, CableManagementStrategy is a free-form string that contains information on how the various cables are connected and bundled for the Frame. With many networking, storage-related and power cables, cable management can be a complex and challenging endeavor. This string property contains information to aid in assembly and service of the Frame.
		void CableManagementStrategy(const string &value); 

		// Is true if the field CableManagementStrategy exists in the current object, otherwise is false.
		bool CableManagementStrategyExists() const;

		// Remove CableManagementStrategy field.
		void RemoveCableManagementStrategy(); 

		// Optional, ServicePhilosophy is an enumerated, integer-valued array that indicates whether the Frame is serviced from the top (value=2), front (3), back (4) or side (5), whether it has sliding trays (6) or removable sides (7), and/or whether the Frame is moveable (8), for example, having rollers.
		const vector<unsigned short> ServicePhilosophy() const;

		// Optional, ServicePhilosophy is an enumerated, integer-valued array that indicates whether the Frame is serviced from the top (value=2), front (3), back (4) or side (5), whether it has sliding trays (6) or removable sides (7), and/or whether the Frame is moveable (8), for example, having rollers.
		void ServicePhilosophy(const vector<unsigned short> &value); 

		// Is true if the field ServicePhilosophy exists in the current object, otherwise is false.
		bool ServicePhilosophyExists() const;

		// Remove ServicePhilosophy field.
		void RemoveServicePhilosophy(); 

		// Optional, An array of free-form strings providing more detailed explanations for any of the entries in the Service Philosophy array. Note, each entry of this array is related to the entry in ServicePhilosophy that is located at the same index.
		const vector<string> ServiceDescriptions() const;

		// Optional, An array of free-form strings providing more detailed explanations for any of the entries in the Service Philosophy array. Note, each entry of this array is related to the entry in ServicePhilosophy that is located at the same index.
		void ServiceDescriptions(const vector<string> &value); 

		// Is true if the field ServiceDescriptions exists in the current object, otherwise is false.
		bool ServiceDescriptionsExists() const;

		// Remove ServiceDescriptions field.
		void RemoveServiceDescriptions(); 

		// Optional, Boolean indicating whether the Frame is protected with a lock.
		const bool LockPresent() const;

		// Optional, Boolean indicating whether the Frame is protected with a lock.
		void LockPresent(const bool value); 

		// Is true if the field LockPresent exists in the current object, otherwise is false.
		bool LockPresentExists() const;

		// Remove LockPresent field.
		void RemoveLockPresent(); 

		// Optional, Boolean indicating whether the Frame is equipped with an audible alarm.
		const bool AudibleAlarm() const;

		// Optional, Boolean indicating whether the Frame is equipped with an audible alarm.
		void AudibleAlarm(const bool value); 

		// Is true if the field AudibleAlarm exists in the current object, otherwise is false.
		bool AudibleAlarmExists() const;

		// Remove AudibleAlarm field.
		void RemoveAudibleAlarm(); 

		// Optional, Boolean indicating that the equipment includes a visible alarm.
		const bool VisibleAlarm() const;

		// Optional, Boolean indicating that the equipment includes a visible alarm.
		void VisibleAlarm(const bool value); 

		// Is true if the field VisibleAlarm exists in the current object, otherwise is false.
		bool VisibleAlarmExists() const;

		// Remove VisibleAlarm field.
		void RemoveVisibleAlarm(); 

		// Optional, SecurityBreach is an enumerated, integer-valued property indicating whether a physical breach of the Frame was attempted but unsuccessful (value=4) or attempted and successful (5). Also, the values, "Unknown", "Other" or "No Breach", can be specified.
		const unsigned short SecurityBreach() const;

		// Optional, SecurityBreach is an enumerated, integer-valued property indicating whether a physical breach of the Frame was attempted but unsuccessful (value=4) or attempted and successful (5). Also, the values, "Unknown", "Other" or "No Breach", can be specified.
		void SecurityBreach(const unsigned short value); 

		// Is true if the field SecurityBreach exists in the current object, otherwise is false.
		bool SecurityBreachExists() const;

		// Remove SecurityBreach field.
		void RemoveSecurityBreach(); 

		// Optional, BreachDescription is a free-form string providing more information if the SecurityBreach property indicates that a breach or some other security-related event occurred.
		const string BreachDescription() const;

		// Optional, BreachDescription is a free-form string providing more information if the SecurityBreach property indicates that a breach or some other security-related event occurred.
		void BreachDescription(const string &value); 

		// Is true if the field BreachDescription exists in the current object, otherwise is false.
		bool BreachDescriptionExists() const;

		// Remove BreachDescription field.
		void RemoveBreachDescription(); 

		// Optional, Boolean indicating that the Frame is currently locked.
		const bool IsLocked() const;

		// Optional, Boolean indicating that the Frame is currently locked.
		void IsLocked(const bool value); 

		// Is true if the field IsLocked exists in the current object, otherwise is false.
		bool IsLockedExists() const;

		// Remove IsLocked field.
		void RemoveIsLocked(); 

		//Input parameter for function IsCompatible
		class CIMFRAMEWORK_API IsCompatible_INPUT : public CimParam
		{
		public:
			// Class Constructor
			IsCompatible_INPUT() : CimParam() {}

			// Class Destructor
			~IsCompatible_INPUT(){}

			// Optional, The element to check for compatibility with this one.
			void ElementToCheck(const CimReference &value); 

			const VectorFieldData GetAllFields() const;
		private:
			static const CimFieldAttribute _metadata[];
		};

		// This method is being deprecated. A PhysicalPackage cannot determine if it is compatible with another object. The IsCompatible method verifies whether the referenced PhysicalElement may be contained by or inserted into the PhysicalPackage. The return value should be 0 if the request was successfully executed, 1 if the request is not supported and some other value if an error occurred. In a subclass, the set of possible return codes could be specified, using a ValueMap qualifier on the method. The strings to which the ValueMap contents are 'translated' may also be specified in the subclass as a Values array qualifier.
		virtual unsigned int IsCompatible(const IsCompatible_INPUT &input);

		 // Function used by the factory
		static CimBase *CreateFromCimObject(const CimObject &object);

		static vector<shared_ptr<CIM_PhysicalFrame> > Enumerate(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		// Overloaded delete which supplies the internal resourceURI
		static void Delete(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		using CimBase::Delete;

	protected:
		 // Protected constructor to be used by derived classes
		CIM_PhysicalFrame(ICimWsmanClient *client, const string &class_name,
			const string &class_ns, const string &prefix, const string &uri): CIM_PhysicalPackage(client, class_name, class_ns, prefix, uri)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_PhysicalPackage::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 9);
			}
		}
		 // Protected constructor which receives CimObject
		CIM_PhysicalFrame(const CimObject &object)
			: CIM_PhysicalPackage(object)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_PhysicalPackage::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 9);
			}
		}
		// Called by derived classes
		void SetMetaData(vector<CimFieldAttribute>& childMetaData)
		{
			CIM_PhysicalPackage::SetMetaData(childMetaData);
			CimBase::SetMetaData(childMetaData, _metadata, 9);
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
#endif // CIM_PHYSICALFRAME_H
