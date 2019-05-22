//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_Location.h
//
//  Contents:   The Location class specifies the position and address of a PhysicalElement.
//
//              This file was automatically generated from CIM_Location.mof,  version: 2.10.0
//
//----------------------------------------------------------------------------
#ifndef CIM_LOCATION_H
#define CIM_LOCATION_H 1
#include "CIM_ManagedElement.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	// The Location class specifies the position and address of a PhysicalElement.
	class CIMFRAMEWORK_API CIM_Location  : public CIM_ManagedElement
	{
	public:

		//Default constructor
		CIM_Location()
			: CIM_ManagedElement(NULL, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_ManagedElement::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 3);
			}
		}

		//constructor which receives WSMan client
		CIM_Location(ICimWsmanClient *client)
			: CIM_ManagedElement(client, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_ManagedElement::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 3);
			}
		}

		//Destructor
		virtual ~CIM_Location(){}

		// The "type" information for the object. Gettors only.
		virtual const string& ResourceURI() const { return CLASS_URI; }
		static const string& ClassResourceURI() { return CLASS_URI; }
		virtual const string& XmlNamespace() const { return CLASS_NS; }
		virtual const string& XmlPrefix() const { return CLASS_NS_PREFIX; }
		virtual const string& ObjectType() const { return CLASS_NAME; }
		static const string& ClassObjectType() { return CLASS_NAME; }

		// Class representing CIM_Location keys
		class CimKeys : public CIM_ManagedElement::CimKeys
		{
		public:
			// Key, Required, Name is a free-form string defining a label for the Location. It is a part of the key for the object.
			const string Name() const
			{
				return GetKey("Name");
			}

			// Key, Required, Name is a free-form string defining a label for the Location. It is a part of the key for the object.
			void Name(const string &value)
			{
				SetOrAddKey("Name", value);
			}

			// Key, Required, Position is a free-form string that indicates the placement of a PhysicalElement. It can specify slot information on a HostingBoard, mounting site in a Cabinet, or latitude and longitude information, for example, from a GPS. It is part of the key of the Location object.
			const string PhysicalPosition() const
			{
				return GetKey("PhysicalPosition");
			}

			// Key, Required, Position is a free-form string that indicates the placement of a PhysicalElement. It can specify slot information on a HostingBoard, mounting site in a Cabinet, or latitude and longitude information, for example, from a GPS. It is part of the key of the Location object.
			void PhysicalPosition(const string &value)
			{
				SetOrAddKey("PhysicalPosition", value);
			}

		};

		// class fields declarations

		// Key, Required, Name is a free-form string defining a label for the Location. It is a part of the key for the object.
		const string Name() const;

		// Key, Required, Name is a free-form string defining a label for the Location. It is a part of the key for the object.
		void Name(const string &value); 


		// Key, Required, Position is a free-form string that indicates the placement of a PhysicalElement. It can specify slot information on a HostingBoard, mounting site in a Cabinet, or latitude and longitude information, for example, from a GPS. It is part of the key of the Location object.
		const string PhysicalPosition() const;

		// Key, Required, Position is a free-form string that indicates the placement of a PhysicalElement. It can specify slot information on a HostingBoard, mounting site in a Cabinet, or latitude and longitude information, for example, from a GPS. It is part of the key of the Location object.
		void PhysicalPosition(const string &value); 


		// Optional, Address is a free-form string indicating a street, building, or other type of address for the location of the PhysicalElement.
		const string Address() const;

		// Optional, Address is a free-form string indicating a street, building, or other type of address for the location of the PhysicalElement.
		void Address(const string &value); 

		// Is true if the field Address exists in the current object, otherwise is false.
		bool AddressExists() const;

		// Remove Address field.
		void RemoveAddress(); 

		 // Function used by the factory
		static CimBase *CreateFromCimObject(const CimObject &object);

		static vector<shared_ptr<CIM_Location> > Enumerate(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		// Overloaded delete which supplies the internal resourceURI
		static void Delete(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		using CimBase::Delete;

	protected:
		 // Protected constructor to be used by derived classes
		CIM_Location(ICimWsmanClient *client, const string &class_name,
			const string &class_ns, const string &prefix, const string &uri): CIM_ManagedElement(client, class_name, class_ns, prefix, uri)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_ManagedElement::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 3);
			}
		}
		 // Protected constructor which receives CimObject
		CIM_Location(const CimObject &object)
			: CIM_ManagedElement(object)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_ManagedElement::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 3);
			}
		}
		// Called by derived classes
		void SetMetaData(vector<CimFieldAttribute>& childMetaData)
		{
			CIM_ManagedElement::SetMetaData(childMetaData);
			CimBase::SetMetaData(childMetaData, _metadata, 3);
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
#endif // CIM_LOCATION_H
