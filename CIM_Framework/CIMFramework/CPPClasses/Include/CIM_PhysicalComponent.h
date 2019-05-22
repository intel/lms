//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_PhysicalComponent.h
//
//  Contents:   The PhysicalComponent class represents any low-level or basic Component within a Package. A Component object either can not or does not need to be decomposed into its constituent parts. For example, an ASIC (or Chip) can not be further decomposed. A tape for data storage (PhysicalMedia) does not need to be decomposed. Any PhysicalElement that is not a Link, Connector, or Package is a descendent (or member) of this class. For example, the UART chipset on an internal modem Card would be a subclass (if additional properties or associations are defined) or an instance of PhysicalComponent.
//
//              This file was automatically generated from CIM_PhysicalComponent.mof,  version: 2.8.0
//
//----------------------------------------------------------------------------
#ifndef CIM_PHYSICALCOMPONENT_H
#define CIM_PHYSICALCOMPONENT_H 1
#include "CIM_PhysicalElement.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	// The PhysicalComponent class represents any low-level or basic Component within a Package. A Component object either can not or does not need to be decomposed into its constituent parts. For example, an ASIC (or Chip) can not be further decomposed. A tape for data storage (PhysicalMedia) does not need to be decomposed. Any PhysicalElement that is not a Link, Connector, or Package is a descendent (or member) of this class. For example, the UART chipset on an internal modem Card would be a subclass (if additional properties or associations are defined) or an instance of PhysicalComponent.
	class CIMFRAMEWORK_API CIM_PhysicalComponent  : public CIM_PhysicalElement
	{
	public:

		//Default constructor
		CIM_PhysicalComponent()
			: CIM_PhysicalElement(NULL, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_PhysicalElement::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 4);
			}
		}

		//constructor which receives WSMan client
		CIM_PhysicalComponent(ICimWsmanClient *client)
			: CIM_PhysicalElement(client, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_PhysicalElement::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 4);
			}
		}

		//Destructor
		virtual ~CIM_PhysicalComponent(){}

		// The "type" information for the object. Gettors only.
		virtual const string& ResourceURI() const { return CLASS_URI; }
		static const string& ClassResourceURI() { return CLASS_URI; }
		virtual const string& XmlNamespace() const { return CLASS_NS; }
		virtual const string& XmlPrefix() const { return CLASS_NS_PREFIX; }
		virtual const string& ObjectType() const { return CLASS_NAME; }
		static const string& ClassObjectType() { return CLASS_NAME; }

		// Class representing CIM_PhysicalComponent keys
		class CimKeys : public CIM_PhysicalElement::CimKeys
		{
		public:
		};

		// class fields declarations

		// Optional, The RemovalCapabilites property is used to describe the conditions under which a PhysicalPackage can be removed. Since all PhysicalPackages are not removable, this property defaults to 2, 'Not Applicable'.
		const unsigned short RemovalConditions() const;

		// Optional, The RemovalCapabilites property is used to describe the conditions under which a PhysicalPackage can be removed. Since all PhysicalPackages are not removable, this property defaults to 2, 'Not Applicable'.
		void RemovalConditions(const unsigned short value); 

		// Is true if the field RemovalConditions exists in the current object, otherwise is false.
		bool RemovalConditionsExists() const;

		// Remove RemovalConditions field.
		void RemoveRemovalConditions(); 

		// Optional, The use of this property is being deprecated. Instead RemovalConditions should be used. The RemovalConditions property addresses whether a PhysicalComponent is removable with or without power being applied. 
		// 
		// A PhysicalComponent is Removable if it is designed to be taken in and out of the physical container in which it is normally found, without impairing the function of the overall packaging. A Component can still be Removable if power must be 'off' in order to perform the removal. If power can be 'on' and the Component removed, then the Element is both Removable and HotSwappable. For example, an upgradeable Processor chip is Removable.
		const bool Removable() const;

		// Optional, The use of this property is being deprecated. Instead RemovalConditions should be used. The RemovalConditions property addresses whether a PhysicalComponent is removable with or without power being applied. 
		// 
		// A PhysicalComponent is Removable if it is designed to be taken in and out of the physical container in which it is normally found, without impairing the function of the overall packaging. A Component can still be Removable if power must be 'off' in order to perform the removal. If power can be 'on' and the Component removed, then the Element is both Removable and HotSwappable. For example, an upgradeable Processor chip is Removable.
		void Removable(const bool value); 

		// Is true if the field Removable exists in the current object, otherwise is false.
		bool RemovableExists() const;

		// Remove Removable field.
		void RemoveRemovable(); 

		// Optional, The use of this property is being deprecated because it is redundant with the FRU class and its associations. A PhysicalComponent is Replaceable if it is possible to replace (FRU or upgrade) the Element with a physically different one. For example, some ComputerSystems allow the main Processor chip to be upgraded to one of a higher clock rating. In this case, the Processor is said to be Replaceable. All Removable Components are inherently Replaceable.
		const bool Replaceable() const;

		// Optional, The use of this property is being deprecated because it is redundant with the FRU class and its associations. A PhysicalComponent is Replaceable if it is possible to replace (FRU or upgrade) the Element with a physically different one. For example, some ComputerSystems allow the main Processor chip to be upgraded to one of a higher clock rating. In this case, the Processor is said to be Replaceable. All Removable Components are inherently Replaceable.
		void Replaceable(const bool value); 

		// Is true if the field Replaceable exists in the current object, otherwise is false.
		bool ReplaceableExists() const;

		// Remove Replaceable field.
		void RemoveReplaceable(); 

		// Optional, The use of this property is being deprecated. Instead RemovalConditions should be used. The RemovalConditions property addresses whether a PhysicalComponent is removable with or without power being applied. 
		// 
		// A PhysicalComponent is HotSwappable if it is possible to replace the Element with a physically different but equivalent one while the containing Package has power applied to it (ie, is 'on'). For example, a fan Component may be designed to be HotSwappable. All HotSwappable Components are inherently Removable and Replaceable.
		const bool HotSwappable() const;

		// Optional, The use of this property is being deprecated. Instead RemovalConditions should be used. The RemovalConditions property addresses whether a PhysicalComponent is removable with or without power being applied. 
		// 
		// A PhysicalComponent is HotSwappable if it is possible to replace the Element with a physically different but equivalent one while the containing Package has power applied to it (ie, is 'on'). For example, a fan Component may be designed to be HotSwappable. All HotSwappable Components are inherently Removable and Replaceable.
		void HotSwappable(const bool value); 

		// Is true if the field HotSwappable exists in the current object, otherwise is false.
		bool HotSwappableExists() const;

		// Remove HotSwappable field.
		void RemoveHotSwappable(); 

		 // Function used by the factory
		static CimBase *CreateFromCimObject(const CimObject &object);

		static vector<shared_ptr<CIM_PhysicalComponent> > Enumerate(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		// Overloaded delete which supplies the internal resourceURI
		static void Delete(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		using CimBase::Delete;

	protected:
		 // Protected constructor to be used by derived classes
		CIM_PhysicalComponent(ICimWsmanClient *client, const string &class_name,
			const string &class_ns, const string &prefix, const string &uri): CIM_PhysicalElement(client, class_name, class_ns, prefix, uri)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_PhysicalElement::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 4);
			}
		}
		 // Protected constructor which receives CimObject
		CIM_PhysicalComponent(const CimObject &object)
			: CIM_PhysicalElement(object)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_PhysicalElement::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 4);
			}
		}
		// Called by derived classes
		void SetMetaData(vector<CimFieldAttribute>& childMetaData)
		{
			CIM_PhysicalElement::SetMetaData(childMetaData);
			CimBase::SetMetaData(childMetaData, _metadata, 4);
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
#endif // CIM_PHYSICALCOMPONENT_H
