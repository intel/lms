//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_PhysicalElement.h
//
//  Contents:   Subclasses of CIM_PhysicalElement define any component of a System that has a distinct physical identity. Instances of this class can be defined as an object that can be seen or touched. All Processes, Files, and LogicalDevices are considered not to be Physical Elements. For example, it is not possible to touch the functionality of a 'modem.' You can touch only the card or package that implements the modem. The same card could also implement a LAN adapter. PhysicalElements are tangible ManagedSystemElements that have a physical manifestation of some sort. 
//              
//              Note that the properties of PhysicalElement describe a hardware entity. Possible replacement (FRU) information is defined by following the ElementFRU association to one or more instances of the ReplacementFRU class. This definition allows a client to determine what hardware can be replaced (FRUed) and what 'spare' parts might be required by a customer or engineer doing the replacement. If it can be instrumented or manually determined that an element actually replaced (FRUed) another, then this can be described in the model using the ElementHasBeenFRUed association.
//
//              This file was automatically generated from CIM_PhysicalElement.mof,  version: 2.10.0
//
//----------------------------------------------------------------------------
#ifndef CIM_PHYSICALELEMENT_H
#define CIM_PHYSICALELEMENT_H 1
#include "CIM_ManagedSystemElement.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	// Subclasses of CIM_PhysicalElement define any component of a System that has a distinct physical identity. Instances of this class can be defined as an object that can be seen or touched. All Processes, Files, and LogicalDevices are considered not to be Physical Elements. For example, it is not possible to touch the functionality of a 'modem.' You can touch only the card or package that implements the modem. The same card could also implement a LAN adapter. PhysicalElements are tangible ManagedSystemElements that have a physical manifestation of some sort. 
	// 
	// Note that the properties of PhysicalElement describe a hardware entity. Possible replacement (FRU) information is defined by following the ElementFRU association to one or more instances of the ReplacementFRU class. This definition allows a client to determine what hardware can be replaced (FRUed) and what 'spare' parts might be required by a customer or engineer doing the replacement. If it can be instrumented or manually determined that an element actually replaced (FRUed) another, then this can be described in the model using the ElementHasBeenFRUed association.
	class CIMFRAMEWORK_API CIM_PhysicalElement  : public CIM_ManagedSystemElement
	{
	public:

		//Default constructor
		CIM_PhysicalElement()
			: CIM_ManagedSystemElement(NULL, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_ManagedSystemElement::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 16);
			}
		}

		//constructor which receives WSMan client
		CIM_PhysicalElement(ICimWsmanClient *client)
			: CIM_ManagedSystemElement(client, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_ManagedSystemElement::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 16);
			}
		}

		//Destructor
		virtual ~CIM_PhysicalElement(){}

		// The "type" information for the object. Gettors only.
		virtual const string& ResourceURI() const { return CLASS_URI; }
		static const string& ClassResourceURI() { return CLASS_URI; }
		virtual const string& XmlNamespace() const { return CLASS_NS; }
		virtual const string& XmlPrefix() const { return CLASS_NS_PREFIX; }
		virtual const string& ObjectType() const { return CLASS_NAME; }
		static const string& ClassObjectType() { return CLASS_NAME; }

		// Class representing CIM_PhysicalElement keys
		class CimKeys : public CIM_ManagedSystemElement::CimKeys
		{
		public:
			// Key, Required, An arbitrary string that uniquely identifies the Physical Element and serves as the key of the Element. The Tag property can contain information such as asset tag or serial number data. The key for PhysicalElement is placed very high in the object hierarchy in order to independently identify the hardware or entity, regardless of physical placement in or on Cabinets, Adapters, and so on. For example, a hotswappable or removable component can be taken from its containing (scoping) Package and be temporarily unused. The object still continues to exist and can even be inserted into a different scoping container. Therefore, the key for Physical Element is an arbitrary string and is defined independently of any placement or location-oriented hierarchy.
			const string Tag() const
			{
				return GetKey("Tag");
			}

			// Key, Required, An arbitrary string that uniquely identifies the Physical Element and serves as the key of the Element. The Tag property can contain information such as asset tag or serial number data. The key for PhysicalElement is placed very high in the object hierarchy in order to independently identify the hardware or entity, regardless of physical placement in or on Cabinets, Adapters, and so on. For example, a hotswappable or removable component can be taken from its containing (scoping) Package and be temporarily unused. The object still continues to exist and can even be inserted into a different scoping container. Therefore, the key for Physical Element is an arbitrary string and is defined independently of any placement or location-oriented hierarchy.
			void Tag(const string &value)
			{
				SetOrAddKey("Tag", value);
			}

			// Key, Required, CreationClassName indicates the name of the class or the subclass used in the creation of an instance. When used with the other key properties of this class, this property allows all instances of this class and its subclasses to be uniquely identified.
			const string CreationClassName() const
			{
				return GetKey("CreationClassName");
			}

			// Key, Required, CreationClassName indicates the name of the class or the subclass used in the creation of an instance. When used with the other key properties of this class, this property allows all instances of this class and its subclasses to be uniquely identified.
			void CreationClassName(const string &value)
			{
				SetOrAddKey("CreationClassName", value);
			}

		};

		// class fields declarations

		// Key, Required, An arbitrary string that uniquely identifies the Physical Element and serves as the key of the Element. The Tag property can contain information such as asset tag or serial number data. The key for PhysicalElement is placed very high in the object hierarchy in order to independently identify the hardware or entity, regardless of physical placement in or on Cabinets, Adapters, and so on. For example, a hotswappable or removable component can be taken from its containing (scoping) Package and be temporarily unused. The object still continues to exist and can even be inserted into a different scoping container. Therefore, the key for Physical Element is an arbitrary string and is defined independently of any placement or location-oriented hierarchy.
		const string Tag() const;

		// Key, Required, An arbitrary string that uniquely identifies the Physical Element and serves as the key of the Element. The Tag property can contain information such as asset tag or serial number data. The key for PhysicalElement is placed very high in the object hierarchy in order to independently identify the hardware or entity, regardless of physical placement in or on Cabinets, Adapters, and so on. For example, a hotswappable or removable component can be taken from its containing (scoping) Package and be temporarily unused. The object still continues to exist and can even be inserted into a different scoping container. Therefore, the key for Physical Element is an arbitrary string and is defined independently of any placement or location-oriented hierarchy.
		void Tag(const string &value); 


		// Key, Required, CreationClassName indicates the name of the class or the subclass used in the creation of an instance. When used with the other key properties of this class, this property allows all instances of this class and its subclasses to be uniquely identified.
		const string CreationClassName() const;

		// Key, Required, CreationClassName indicates the name of the class or the subclass used in the creation of an instance. When used with the other key properties of this class, this property allows all instances of this class and its subclasses to be uniquely identified.
		void CreationClassName(const string &value); 


		// Optional, The name of the organization responsible for producing the PhysicalElement. This organization might be the entity from whom the Element is purchased, but this is not necessarily true. The latter information is contained in the Vendor property of CIM_Product.
		const string Manufacturer() const;

		// Optional, The name of the organization responsible for producing the PhysicalElement. This organization might be the entity from whom the Element is purchased, but this is not necessarily true. The latter information is contained in the Vendor property of CIM_Product.
		void Manufacturer(const string &value); 

		// Is true if the field Manufacturer exists in the current object, otherwise is false.
		bool ManufacturerExists() const;

		// Remove Manufacturer field.
		void RemoveManufacturer(); 

		// Optional, The name by which the PhysicalElement is generally known.
		const string Model() const;

		// Optional, The name by which the PhysicalElement is generally known.
		void Model(const string &value); 

		// Is true if the field Model exists in the current object, otherwise is false.
		bool ModelExists() const;

		// Remove Model field.
		void RemoveModel(); 

		// Optional, The stock-keeping unit number for this PhysicalElement.
		const string SKU() const;

		// Optional, The stock-keeping unit number for this PhysicalElement.
		void SKU(const string &value); 

		// Is true if the field SKU exists in the current object, otherwise is false.
		bool SKUExists() const;

		// Remove SKU field.
		void RemoveSKU(); 

		// Optional, A manufacturer-allocated number used to identify the Physical Element.
		const string SerialNumber() const;

		// Optional, A manufacturer-allocated number used to identify the Physical Element.
		void SerialNumber(const string &value); 

		// Is true if the field SerialNumber exists in the current object, otherwise is false.
		bool SerialNumberExists() const;

		// Remove SerialNumber field.
		void RemoveSerialNumber(); 

		// Optional, A string that indicates the version of the PhysicalElement.
		const string Version() const;

		// Optional, A string that indicates the version of the PhysicalElement.
		void Version(const string &value); 

		// Is true if the field Version exists in the current object, otherwise is false.
		bool VersionExists() const;

		// Remove Version field.
		void RemoveVersion(); 

		// Optional, The part number assigned by the organization that is responsible for producing or manufacturing the PhysicalElement.
		const string PartNumber() const;

		// Optional, The part number assigned by the organization that is responsible for producing or manufacturing the PhysicalElement.
		void PartNumber(const string &value); 

		// Is true if the field PartNumber exists in the current object, otherwise is false.
		bool PartNumberExists() const;

		// Remove PartNumber field.
		void RemovePartNumber(); 

		// Optional, OtherIdentifyingInfo captures data in addition to Tag information. This information could be used to identify a Physical Element. One example is bar code data associated with an Element that also has an asset tag. Note that if only bar code data is available and is unique or able to be used as an Element key, this property would be null and the bar code data would be used as the class key, in the Tag property.
		const string OtherIdentifyingInfo() const;

		// Optional, OtherIdentifyingInfo captures data in addition to Tag information. This information could be used to identify a Physical Element. One example is bar code data associated with an Element that also has an asset tag. Note that if only bar code data is available and is unique or able to be used as an Element key, this property would be null and the bar code data would be used as the class key, in the Tag property.
		void OtherIdentifyingInfo(const string &value); 

		// Is true if the field OtherIdentifyingInfo exists in the current object, otherwise is false.
		bool OtherIdentifyingInfoExists() const;

		// Remove OtherIdentifyingInfo field.
		void RemoveOtherIdentifyingInfo(); 

		// Optional, Boolean that indicates whether the PhysicalElement is powered on (TRUE) or is currently off (FALSE).
		const bool PoweredOn() const;

		// Optional, Boolean that indicates whether the PhysicalElement is powered on (TRUE) or is currently off (FALSE).
		void PoweredOn(const bool value); 

		// Is true if the field PoweredOn exists in the current object, otherwise is false.
		bool PoweredOnExists() const;

		// Remove PoweredOn field.
		void RemovePoweredOn(); 

		// Optional, The date that this PhysicalElement was manufactured.
		const CimDateTime ManufactureDate() const;

		// Optional, The date that this PhysicalElement was manufactured.
		void ManufactureDate(const CimDateTime &value); 

		// Is true if the field ManufactureDate exists in the current object, otherwise is false.
		bool ManufactureDateExists() const;

		// Remove ManufactureDate field.
		void RemoveManufactureDate(); 

		// Optional, A vendor-specific hardware type for the PhysicalElement. It describes the specific equipment type for the element, as defined by the vendor or manufacturer.
		const string VendorEquipmentType() const;

		// Optional, A vendor-specific hardware type for the PhysicalElement. It describes the specific equipment type for the element, as defined by the vendor or manufacturer.
		void VendorEquipmentType(const string &value); 

		// Is true if the field VendorEquipmentType exists in the current object, otherwise is false.
		bool VendorEquipmentTypeExists() const;

		// Remove VendorEquipmentType field.
		void RemoveVendorEquipmentType(); 

		// Optional, User-assigned and writeable asset-tracking identifier for the PhysicalElement.
		const string UserTracking() const;

		// Optional, User-assigned and writeable asset-tracking identifier for the PhysicalElement.
		void UserTracking(const string &value); 

		// Is true if the field UserTracking exists in the current object, otherwise is false.
		bool UserTrackingExists() const;

		// Remove UserTracking field.
		void RemoveUserTracking(); 

		// Optional, Boolean that indicates whether this PhysicalElement can be FRUed (TRUE) or not (FALSE).
		const bool CanBeFRUed() const;

		// Optional, Boolean that indicates whether this PhysicalElement can be FRUed (TRUE) or not (FALSE).
		void CanBeFRUed(const bool value); 

		// Is true if the field CanBeFRUed exists in the current object, otherwise is false.
		bool CanBeFRUedExists() const;

		// Remove CanBeFRUed field.
		void RemoveCanBeFRUed(); 

		 // Function used by the factory
		static CimBase *CreateFromCimObject(const CimObject &object);

		static vector<shared_ptr<CIM_PhysicalElement> > Enumerate(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		// Overloaded delete which supplies the internal resourceURI
		static void Delete(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		using CimBase::Delete;

	protected:
		 // Protected constructor to be used by derived classes
		CIM_PhysicalElement(ICimWsmanClient *client, const string &class_name,
			const string &class_ns, const string &prefix, const string &uri): CIM_ManagedSystemElement(client, class_name, class_ns, prefix, uri)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_ManagedSystemElement::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 16);
			}
		}
		 // Protected constructor which receives CimObject
		CIM_PhysicalElement(const CimObject &object)
			: CIM_ManagedSystemElement(object)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_ManagedSystemElement::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 16);
			}
		}
		// Called by derived classes
		void SetMetaData(vector<CimFieldAttribute>& childMetaData)
		{
			CIM_ManagedSystemElement::SetMetaData(childMetaData);
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
#endif // CIM_PHYSICALELEMENT_H
