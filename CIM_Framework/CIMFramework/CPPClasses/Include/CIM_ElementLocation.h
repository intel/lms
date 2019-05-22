//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_ElementLocation.h
//
//  Contents:   ElementLocation associates a ManagedElement with a location for positioning, inventory, maintenance and similar purposes. PhysicalElements can certainly have locations. They are explicitly defined in a subclass, PhysicalElement Location. However, other ManagedElements can also be associated with locations. For example, Organizations can be 'in' one or more locations, or Services can be restricted to a location.
//
//              This file was automatically generated from CIM_ElementLocation.mof,  version: 2.10.0
//
//----------------------------------------------------------------------------
#ifndef CIM_ELEMENTLOCATION_H
#define CIM_ELEMENTLOCATION_H 1
#include "../../include/CimBase.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	// ElementLocation associates a ManagedElement with a location for positioning, inventory, maintenance and similar purposes. PhysicalElements can certainly have locations. They are explicitly defined in a subclass, PhysicalElement Location. However, other ManagedElements can also be associated with locations. For example, Organizations can be 'in' one or more locations, or Services can be restricted to a location.
	class CIMFRAMEWORK_API CIM_ElementLocation  : public CimBase
	{
	public:

		//Default constructor
		CIM_ElementLocation()
			: CimBase(NULL, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CimBase::SetMetaData(_classMetaData, _metadata, 2);
			}
		}

		//constructor which receives WSMan client
		CIM_ElementLocation(ICimWsmanClient *client)
			: CimBase(client, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CimBase::SetMetaData(_classMetaData, _metadata, 2);
			}
		}

		//Destructor
		virtual ~CIM_ElementLocation(){}

		// The "type" information for the object. Gettors only.
		virtual const string& ResourceURI() const { return CLASS_URI; }
		static const string& ClassResourceURI() { return CLASS_URI; }
		virtual const string& XmlNamespace() const { return CLASS_NS; }
		virtual const string& XmlPrefix() const { return CLASS_NS_PREFIX; }
		virtual const string& ObjectType() const { return CLASS_NAME; }
		static const string& ClassObjectType() { return CLASS_NAME; }

		// Class representing CIM_ElementLocation keys
		class CimKeys : public CimBase::CimKeys
		{
		public:
			// Key, Required, The ManagedElement whose location is specified.
			const CimReference Element() const
			{
				CimReference ret;
				TypeConverter::StringToType(GetKey("Element"), ret);
				return ret;
			}

			// Key, Required, The ManagedElement whose location is specified.
			void Element(const CimReference &value)
			{
				SetOrAddKey("Element", TypeConverter::TypeToString(value), true);
			}

			// Key, Required, The location of the element.
			const CimReference PhysicalLocation() const
			{
				CimReference ret;
				TypeConverter::StringToType(GetKey("PhysicalLocation"), ret);
				return ret;
			}

			// Key, Required, The location of the element.
			void PhysicalLocation(const CimReference &value)
			{
				SetOrAddKey("PhysicalLocation", TypeConverter::TypeToString(value), true);
			}

		};

		// class fields declarations

		// Key, Required, The ManagedElement whose location is specified.
		const CimReference Element() const;

		// Key, Required, The ManagedElement whose location is specified.
		void Element(const CimReference &value); 


		// Key, Required, The location of the element.
		const CimReference PhysicalLocation() const;

		// Key, Required, The location of the element.
		void PhysicalLocation(const CimReference &value); 


		 // Function used by the factory
		static CimBase *CreateFromCimObject(const CimObject &object);

		static vector<shared_ptr<CIM_ElementLocation> > Enumerate(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		// Overloaded delete which supplies the internal resourceURI
		static void Delete(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		using CimBase::Delete;

	protected:
		 // Protected constructor to be used by derived classes
		CIM_ElementLocation(ICimWsmanClient *client, const string &class_name,
			const string &class_ns, const string &prefix, const string &uri): CimBase(client, class_name, class_ns, prefix, uri)
		{
			if(_classMetaData.size() == 0)
			{
				CimBase::SetMetaData(_classMetaData, _metadata, 2);
			}
		}
		 // Protected constructor which receives CimObject
		CIM_ElementLocation(const CimObject &object)
			: CimBase(object)
		{
			if(_classMetaData.size() == 0)
			{
				CimBase::SetMetaData(_classMetaData, _metadata, 2);
			}
		}
		// Called by derived classes
		void SetMetaData(vector<CimFieldAttribute>& childMetaData)
		{
			CimBase::SetMetaData(childMetaData, _metadata, 2);
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
#endif // CIM_ELEMENTLOCATION_H
