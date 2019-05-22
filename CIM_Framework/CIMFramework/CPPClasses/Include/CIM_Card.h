//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_Card.h
//
//  Contents:   The Card class represents a type of physical container that can be plugged into another Card or HostingBoard, or is itself a HostingBoard/Motherboard in a Chassis. The CIM_Card class includes any package capable of carrying signals and providing a mounting point for PhysicalComponents, such as Chips, or other PhysicalPackages, such as other Cards.
//
//              This file was automatically generated from CIM_Card.mof,  version: 2.8.0
//
//----------------------------------------------------------------------------
#ifndef CIM_CARD_H
#define CIM_CARD_H 1
#include "CIM_PhysicalPackage.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	// The Card class represents a type of physical container that can be plugged into another Card or HostingBoard, or is itself a HostingBoard/Motherboard in a Chassis. The CIM_Card class includes any package capable of carrying signals and providing a mounting point for PhysicalComponents, such as Chips, or other PhysicalPackages, such as other Cards.
	class CIMFRAMEWORK_API CIM_Card  : public CIM_PhysicalPackage
	{
	public:

		//Default constructor
		CIM_Card()
			: CIM_PhysicalPackage(NULL, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_PhysicalPackage::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 6);
			}
		}

		//constructor which receives WSMan client
		CIM_Card(ICimWsmanClient *client)
			: CIM_PhysicalPackage(client, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_PhysicalPackage::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 6);
			}
		}

		//Destructor
		virtual ~CIM_Card(){}

		// The "type" information for the object. Gettors only.
		virtual const string& ResourceURI() const { return CLASS_URI; }
		static const string& ClassResourceURI() { return CLASS_URI; }
		virtual const string& XmlNamespace() const { return CLASS_NS; }
		virtual const string& XmlPrefix() const { return CLASS_NS_PREFIX; }
		virtual const string& ObjectType() const { return CLASS_NAME; }
		static const string& ClassObjectType() { return CLASS_NAME; }

		// Class representing CIM_Card keys
		class CimKeys : public CIM_PhysicalPackage::CimKeys
		{
		public:
		};

		// class fields declarations

		// Optional, Boolean indicating that this Card is a Motherboard or, more generically, a baseboard in a Chassis.
		const bool HostingBoard() const;

		// Optional, Boolean indicating that this Card is a Motherboard or, more generically, a baseboard in a Chassis.
		void HostingBoard(const bool value); 

		// Is true if the field HostingBoard exists in the current object, otherwise is false.
		bool HostingBoardExists() const;

		// Remove HostingBoard field.
		void RemoveHostingBoard(); 

		// Optional, SlotLayout is a free-form string that describes the slot positioning, typical usage, restrictions, individual slot spacings or any other pertinent information for the slots on a Card.
		const string SlotLayout() const;

		// Optional, SlotLayout is a free-form string that describes the slot positioning, typical usage, restrictions, individual slot spacings or any other pertinent information for the slots on a Card.
		void SlotLayout(const string &value); 

		// Is true if the field SlotLayout exists in the current object, otherwise is false.
		bool SlotLayoutExists() const;

		// Remove SlotLayout field.
		void RemoveSlotLayout(); 

		// Optional, Boolean indicating that at least one daughterboard or auxiliary Card is required in order to function properly.
		const bool RequiresDaughterBoard() const;

		// Optional, Boolean indicating that at least one daughterboard or auxiliary Card is required in order to function properly.
		void RequiresDaughterBoard(const bool value); 

		// Is true if the field RequiresDaughterBoard exists in the current object, otherwise is false.
		bool RequiresDaughterBoardExists() const;

		// Remove RequiresDaughterBoard field.
		void RemoveRequiresDaughterBoard(); 

		// Optional, Boolean indicating that this Card is physically unique from other Cards of the same type and therefore requires a special Slot. For example, a double-wide Card requires two Slots. Another example is where a certain Card may be used for the same general function as other Cards but requires a special Slot (e.g., extra long), whereas the other Cards can be placed in any available Slot. If set to TRUE, then the corresponding property, RequirementsDescription, should specify the nature of the uniqueness or purpose of the Card.
		const bool SpecialRequirements() const;

		// Optional, Boolean indicating that this Card is physically unique from other Cards of the same type and therefore requires a special Slot. For example, a double-wide Card requires two Slots. Another example is where a certain Card may be used for the same general function as other Cards but requires a special Slot (e.g., extra long), whereas the other Cards can be placed in any available Slot. If set to TRUE, then the corresponding property, RequirementsDescription, should specify the nature of the uniqueness or purpose of the Card.
		void SpecialRequirements(const bool value); 

		// Is true if the field SpecialRequirements exists in the current object, otherwise is false.
		bool SpecialRequirementsExists() const;

		// Remove SpecialRequirements field.
		void RemoveSpecialRequirements(); 

		// Optional, A free-form string describing the way(s) in which this Card is physically unique from other Cards. This property only has meaning when the corresponding boolean property, SpecialRequirements, is set to TRUE.
		const string RequirementsDescription() const;

		// Optional, A free-form string describing the way(s) in which this Card is physically unique from other Cards. This property only has meaning when the corresponding boolean property, SpecialRequirements, is set to TRUE.
		void RequirementsDescription(const string &value); 

		// Is true if the field RequirementsDescription exists in the current object, otherwise is false.
		bool RequirementsDescriptionExists() const;

		// Remove RequirementsDescription field.
		void RemoveRequirementsDescription(); 

		// Optional, Operating voltages required by the Card.
		const vector<short> OperatingVoltages() const;

		// Optional, Operating voltages required by the Card.
		void OperatingVoltages(const vector<short> &value); 

		// Is true if the field OperatingVoltages exists in the current object, otherwise is false.
		bool OperatingVoltagesExists() const;

		// Remove OperatingVoltages field.
		void RemoveOperatingVoltages(); 

		 // Function used by the factory
		static CimBase *CreateFromCimObject(const CimObject &object);

		static vector<shared_ptr<CIM_Card> > Enumerate(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		// Overloaded delete which supplies the internal resourceURI
		static void Delete(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		using CimBase::Delete;

	protected:
		 // Protected constructor to be used by derived classes
		CIM_Card(ICimWsmanClient *client, const string &class_name,
			const string &class_ns, const string &prefix, const string &uri): CIM_PhysicalPackage(client, class_name, class_ns, prefix, uri)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_PhysicalPackage::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 6);
			}
		}
		 // Protected constructor which receives CimObject
		CIM_Card(const CimObject &object)
			: CIM_PhysicalPackage(object)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_PhysicalPackage::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 6);
			}
		}
		// Called by derived classes
		void SetMetaData(vector<CimFieldAttribute>& childMetaData)
		{
			CIM_PhysicalPackage::SetMetaData(childMetaData);
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
#endif // CIM_CARD_H
