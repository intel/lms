//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_PhysicalPackage.h
//
//  Contents:   The PhysicalPackage class represents PhysicalElements that contain or host other components. Examples are a Rack enclosure or an adapter Card.
//
//              This file was automatically generated from CIM_PhysicalPackage.mof,  version: 2.18.0
//
//----------------------------------------------------------------------------
#ifndef CIM_PHYSICALPACKAGE_H
#define CIM_PHYSICALPACKAGE_H 1
#include "CIM_PhysicalElement.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	// The PhysicalPackage class represents PhysicalElements that contain or host other components. Examples are a Rack enclosure or an adapter Card.
	class CIMFRAMEWORK_API CIM_PhysicalPackage  : public CIM_PhysicalElement
	{
	public:

		//Default constructor
		CIM_PhysicalPackage()
			: CIM_PhysicalElement(NULL, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_PhysicalElement::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 11);
			}
		}

		//constructor which receives WSMan client
		CIM_PhysicalPackage(ICimWsmanClient *client)
			: CIM_PhysicalElement(client, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_PhysicalElement::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 11);
			}
		}

		//Destructor
		virtual ~CIM_PhysicalPackage(){}

		// The "type" information for the object. Gettors only.
		virtual const string& ResourceURI() const { return CLASS_URI; }
		static const string& ClassResourceURI() { return CLASS_URI; }
		virtual const string& XmlNamespace() const { return CLASS_NS; }
		virtual const string& XmlPrefix() const { return CLASS_NS_PREFIX; }
		virtual const string& ObjectType() const { return CLASS_NAME; }
		static const string& ClassObjectType() { return CLASS_NAME; }

		// Class representing CIM_PhysicalPackage keys
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

		// Optional, The use of this property is being deprecated. Instead RemovalConditions should be used. The RemovalConditions property addresses whether a PhysicalPackage is removable with or without power being applied. 
		// A PhysicalPackage is Removable if it is designed to be taken in and out of the physical container in which it is normally found, without impairing the function of the overall packaging. A Package can still be Removable if power must be 'off' in order to perform the removal. If power can be 'on' and the Package removed, then the Element is both Removable and HotSwappable. For example, an extra battery in a laptop is Removable, as is a disk drive Package inserted using SCA connectors. However, the latter is also HotSwappable. A laptop's display is not Removable, nor is a non-redundant power supply. Removing these components would impact the function of the overall packaging or is impossible due to the tight integration of the Package.
		const bool Removable() const;

		// Optional, The use of this property is being deprecated. Instead RemovalConditions should be used. The RemovalConditions property addresses whether a PhysicalPackage is removable with or without power being applied. 
		// A PhysicalPackage is Removable if it is designed to be taken in and out of the physical container in which it is normally found, without impairing the function of the overall packaging. A Package can still be Removable if power must be 'off' in order to perform the removal. If power can be 'on' and the Package removed, then the Element is both Removable and HotSwappable. For example, an extra battery in a laptop is Removable, as is a disk drive Package inserted using SCA connectors. However, the latter is also HotSwappable. A laptop's display is not Removable, nor is a non-redundant power supply. Removing these components would impact the function of the overall packaging or is impossible due to the tight integration of the Package.
		void Removable(const bool value); 

		// Is true if the field Removable exists in the current object, otherwise is false.
		bool RemovableExists() const;

		// Remove Removable field.
		void RemoveRemovable(); 

		// Optional, The use of this property is being deprecated because it is redundant with the FRU class and its associations. A PhysicalPackage is Replaceable if it is possible to replace (FRU or upgrade) the Element with a physically different one. For example, some ComputerSystems allow the main Processor chip to be upgraded to one of a higher clock rating. In this case, the Processor is said to be Replaceable. Another example is a power supply Package mounted on sliding rails. All Removable packages are inherently Replaceable.
		const bool Replaceable() const;

		// Optional, The use of this property is being deprecated because it is redundant with the FRU class and its associations. A PhysicalPackage is Replaceable if it is possible to replace (FRU or upgrade) the Element with a physically different one. For example, some ComputerSystems allow the main Processor chip to be upgraded to one of a higher clock rating. In this case, the Processor is said to be Replaceable. Another example is a power supply Package mounted on sliding rails. All Removable packages are inherently Replaceable.
		void Replaceable(const bool value); 

		// Is true if the field Replaceable exists in the current object, otherwise is false.
		bool ReplaceableExists() const;

		// Remove Replaceable field.
		void RemoveReplaceable(); 

		// Optional, The use of this property is being deprecated. Instead RemovalConditions should be used. The RemovalConditions property addresses whether a PhysicalPackage is removable with or without power being applied. 
		// 
		// A PhysicalPackage is HotSwappable if it is possible to replace the Element with a physically different but equivalent one while the containing Package has power applied to it (ie, is 'on'). For example, a disk drive Package inserted using SCA connectors is both Removable and HotSwappable. All HotSwappable packages are inherently Removable and Replaceable.
		const bool HotSwappable() const;

		// Optional, The use of this property is being deprecated. Instead RemovalConditions should be used. The RemovalConditions property addresses whether a PhysicalPackage is removable with or without power being applied. 
		// 
		// A PhysicalPackage is HotSwappable if it is possible to replace the Element with a physically different but equivalent one while the containing Package has power applied to it (ie, is 'on'). For example, a disk drive Package inserted using SCA connectors is both Removable and HotSwappable. All HotSwappable packages are inherently Removable and Replaceable.
		void HotSwappable(const bool value); 

		// Is true if the field HotSwappable exists in the current object, otherwise is false.
		bool HotSwappableExists() const;

		// Remove HotSwappable field.
		void RemoveHotSwappable(); 

		// Optional, The height of the PhysicalPackage in inches.
		const double Height() const;

		// Optional, The height of the PhysicalPackage in inches.
		void Height(const double value); 

		// Is true if the field Height exists in the current object, otherwise is false.
		bool HeightExists() const;

		// Remove Height field.
		void RemoveHeight(); 

		// Optional, The depth of the PhysicalPackage in inches.
		const double Depth() const;

		// Optional, The depth of the PhysicalPackage in inches.
		void Depth(const double value); 

		// Is true if the field Depth exists in the current object, otherwise is false.
		bool DepthExists() const;

		// Remove Depth field.
		void RemoveDepth(); 

		// Optional, The width of the PhysicalPackage in inches.
		const double Width() const;

		// Optional, The width of the PhysicalPackage in inches.
		void Width(const double value); 

		// Is true if the field Width exists in the current object, otherwise is false.
		bool WidthExists() const;

		// Remove Width field.
		void RemoveWidth(); 

		// Optional, The weight of the PhysicalPackage in pounds.
		const double Weight() const;

		// Optional, The weight of the PhysicalPackage in pounds.
		void Weight(const double value); 

		// Is true if the field Weight exists in the current object, otherwise is false.
		bool WeightExists() const;

		// Remove Weight field.
		void RemoveWeight(); 

		// Optional, Enumeration defining the type of the PhysicalPackage. Note that this enumeration expands on the list in the Entity MIB (the attribute, entPhysicalClass). The numeric values are consistent with CIM's enum numbering guidelines, but are slightly different than the MIB's values.
		// Unknown - indicates that the package type is not known.
		// Other - The package type does not correspond to an existing enumerated value. The value is specified using the OtherPackageType property.
		// The values "Rack" through "Port/Connector" are defined per the Entity-MIB (where the semantics of rack are equivalent to the MIB's 'stack' value). The other values (for battery, processor, memory, power source/generator and storage media package) are self-explanatory.
		// A value of "Blade" should be used when the PhysicalPackage contains the operational hardware aspects of a ComputerSystem, without the supporting mechanicals such as power and cooling. For example, a Blade Server includes processor(s) and memory, and relies on the containing chassis to supply power and cooling. In many respects, a Blade can be considered a "Module/Card". However, it is tracked differently by inventory systems and differs in terms of service philosophy. For example, a Blade is intended to be hot-plugged into a hosting enclosure without requiring additional cabling, and does not require a cover to be removed from the enclosure for installation. Similarly, a "Blade Expansion" has characteristics of a "Blade" and a "Module/Card". However, it is distinct from both due to inventory tracking and service philosophy, and because of its hardware dependence on a Blade. A Blade Expansion must be attached to a Blade prior to inserting the resultant assembly into an enclosure.
		const unsigned short PackageType() const;

		// Optional, Enumeration defining the type of the PhysicalPackage. Note that this enumeration expands on the list in the Entity MIB (the attribute, entPhysicalClass). The numeric values are consistent with CIM's enum numbering guidelines, but are slightly different than the MIB's values.
		// Unknown - indicates that the package type is not known.
		// Other - The package type does not correspond to an existing enumerated value. The value is specified using the OtherPackageType property.
		// The values "Rack" through "Port/Connector" are defined per the Entity-MIB (where the semantics of rack are equivalent to the MIB's 'stack' value). The other values (for battery, processor, memory, power source/generator and storage media package) are self-explanatory.
		// A value of "Blade" should be used when the PhysicalPackage contains the operational hardware aspects of a ComputerSystem, without the supporting mechanicals such as power and cooling. For example, a Blade Server includes processor(s) and memory, and relies on the containing chassis to supply power and cooling. In many respects, a Blade can be considered a "Module/Card". However, it is tracked differently by inventory systems and differs in terms of service philosophy. For example, a Blade is intended to be hot-plugged into a hosting enclosure without requiring additional cabling, and does not require a cover to be removed from the enclosure for installation. Similarly, a "Blade Expansion" has characteristics of a "Blade" and a "Module/Card". However, it is distinct from both due to inventory tracking and service philosophy, and because of its hardware dependence on a Blade. A Blade Expansion must be attached to a Blade prior to inserting the resultant assembly into an enclosure.
		void PackageType(const unsigned short value); 

		// Is true if the field PackageType exists in the current object, otherwise is false.
		bool PackageTypeExists() const;

		// Remove PackageType field.
		void RemovePackageType(); 

		// Optional, A string describing the package when the instance's PackageType property is 1 ("Other").
		const string OtherPackageType() const;

		// Optional, A string describing the package when the instance's PackageType property is 1 ("Other").
		void OtherPackageType(const string &value); 

		// Is true if the field OtherPackageType exists in the current object, otherwise is false.
		bool OtherPackageTypeExists() const;

		// Remove OtherPackageType field.
		void RemoveOtherPackageType(); 

		// Optional, An array of strings that identify the component that is compatible with, and can be inserted in a slot that reports this string as one of the array element in the VendorCompatibilityStrings This allows system administrators to determine whether it is appropriateto insert a package into a slot 
		// In order to ensure uniqueness within the NameSpace, each value defined by the vendor for use in the VendorCompatibilityStrings property SHOULD be constructed using the following 'preferred' algorithm: 
		// <OrgID>:<LocalID> 
		// Where <OrgID> and <LocalID> are separated by a colon ':', and where <OrgID> MUST include a copyrighted, trademarked or otherwise unique name that is owned by the business entity creating/defining the InstanceID, or is a registered ID that is assigned to the business entity by a recognized global authority (This is similar to the <Schema Name>_<Class Name> structure of Schema class names.) In addition, to ensure uniqueness <OrgID> MUST NOT contain a colon (':'). When using this algorithm, the first colon to appear in InstanceID MUST appear between <OrgID> and <LocalID>. 
		// <LocalID> is chosen by the business entity and SHOULD not be re-used to identify different underlying (real-world) elements.
		const vector<string> VendorCompatibilityStrings() const;

		// Optional, An array of strings that identify the component that is compatible with, and can be inserted in a slot that reports this string as one of the array element in the VendorCompatibilityStrings This allows system administrators to determine whether it is appropriateto insert a package into a slot 
		// In order to ensure uniqueness within the NameSpace, each value defined by the vendor for use in the VendorCompatibilityStrings property SHOULD be constructed using the following 'preferred' algorithm: 
		// <OrgID>:<LocalID> 
		// Where <OrgID> and <LocalID> are separated by a colon ':', and where <OrgID> MUST include a copyrighted, trademarked or otherwise unique name that is owned by the business entity creating/defining the InstanceID, or is a registered ID that is assigned to the business entity by a recognized global authority (This is similar to the <Schema Name>_<Class Name> structure of Schema class names.) In addition, to ensure uniqueness <OrgID> MUST NOT contain a colon (':'). When using this algorithm, the first colon to appear in InstanceID MUST appear between <OrgID> and <LocalID>. 
		// <LocalID> is chosen by the business entity and SHOULD not be re-used to identify different underlying (real-world) elements.
		void VendorCompatibilityStrings(const vector<string> &value); 

		// Is true if the field VendorCompatibilityStrings exists in the current object, otherwise is false.
		bool VendorCompatibilityStringsExists() const;

		// Remove VendorCompatibilityStrings field.
		void RemoveVendorCompatibilityStrings(); 

		 // Function used by the factory
		static CimBase *CreateFromCimObject(const CimObject &object);

		static vector<shared_ptr<CIM_PhysicalPackage> > Enumerate(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		// Overloaded delete which supplies the internal resourceURI
		static void Delete(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		using CimBase::Delete;

	protected:
		 // Protected constructor to be used by derived classes
		CIM_PhysicalPackage(ICimWsmanClient *client, const string &class_name,
			const string &class_ns, const string &prefix, const string &uri): CIM_PhysicalElement(client, class_name, class_ns, prefix, uri)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_PhysicalElement::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 11);
			}
		}
		 // Protected constructor which receives CimObject
		CIM_PhysicalPackage(const CimObject &object)
			: CIM_PhysicalElement(object)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_PhysicalElement::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 11);
			}
		}
		// Called by derived classes
		void SetMetaData(vector<CimFieldAttribute>& childMetaData)
		{
			CIM_PhysicalElement::SetMetaData(childMetaData);
			CimBase::SetMetaData(childMetaData, _metadata, 11);
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
#endif // CIM_PHYSICALPACKAGE_H
