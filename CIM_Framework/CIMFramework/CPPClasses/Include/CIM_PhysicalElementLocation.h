//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_PhysicalElementLocation.h
//
//  Contents:   PhysicalElementLocation associates a PhysicalElement with a Location object for inventory or replacement purposes.
//
//              This file was automatically generated from CIM_PhysicalElementLocation.mof,  version: 2.10.0
//
//----------------------------------------------------------------------------
#ifndef CIM_PHYSICALELEMENTLOCATION_H
#define CIM_PHYSICALELEMENTLOCATION_H 1
#include "CIM_ElementLocation.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	// PhysicalElementLocation associates a PhysicalElement with a Location object for inventory or replacement purposes.
	class CIMFRAMEWORK_API CIM_PhysicalElementLocation  : public CIM_ElementLocation
	{
	public:

		//Default constructor
		CIM_PhysicalElementLocation()
			: CIM_ElementLocation(NULL, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_ElementLocation::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 2);
			}
		}

		//constructor which receives WSMan client
		CIM_PhysicalElementLocation(ICimWsmanClient *client)
			: CIM_ElementLocation(client, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_ElementLocation::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 2);
			}
		}

		//Destructor
		virtual ~CIM_PhysicalElementLocation(){}

		// The "type" information for the object. Gettors only.
		virtual const string& ResourceURI() const { return CLASS_URI; }
		static const string& ClassResourceURI() { return CLASS_URI; }
		virtual const string& XmlNamespace() const { return CLASS_NS; }
		virtual const string& XmlPrefix() const { return CLASS_NS_PREFIX; }
		virtual const string& ObjectType() const { return CLASS_NAME; }
		static const string& ClassObjectType() { return CLASS_NAME; }

		// Class representing CIM_PhysicalElementLocation keys
		class CimKeys : public CIM_ElementLocation::CimKeys
		{
		public:
			// Required, The PhysicalElement whose location is specified.
			const CimReference Element() const
			{
				CimReference ret;
				TypeConverter::StringToType(GetKey("Element"), ret);
				return ret;
			}

			// Required, The PhysicalElement whose location is specified.
			void Element(const CimReference &value)
			{
				SetOrAddKey("Element", TypeConverter::TypeToString(value), true);
			}

			// Required, The location of the PhysicalElement.
			const CimReference PhysicalLocation() const
			{
				CimReference ret;
				TypeConverter::StringToType(GetKey("PhysicalLocation"), ret);
				return ret;
			}

			// Required, The location of the PhysicalElement.
			void PhysicalLocation(const CimReference &value)
			{
				SetOrAddKey("PhysicalLocation", TypeConverter::TypeToString(value), true);
			}

		};
		 // Function used by the factory
		static CimBase *CreateFromCimObject(const CimObject &object);

		static vector<shared_ptr<CIM_PhysicalElementLocation> > Enumerate(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		// Overloaded delete which supplies the internal resourceURI
		static void Delete(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		using CimBase::Delete;

	protected:
		 // Protected constructor to be used by derived classes
		CIM_PhysicalElementLocation(ICimWsmanClient *client, const string &class_name,
			const string &class_ns, const string &prefix, const string &uri): CIM_ElementLocation(client, class_name, class_ns, prefix, uri)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_ElementLocation::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 2);
			}
		}
		 // Protected constructor which receives CimObject
		CIM_PhysicalElementLocation(const CimObject &object)
			: CIM_ElementLocation(object)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_ElementLocation::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 2);
			}
		}
		// Called by derived classes
		void SetMetaData(vector<CimFieldAttribute>& childMetaData)
		{
			CIM_ElementLocation::SetMetaData(childMetaData);
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
#endif // CIM_PHYSICALELEMENTLOCATION_H
