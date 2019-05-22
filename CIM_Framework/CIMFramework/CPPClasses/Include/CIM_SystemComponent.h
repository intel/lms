//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_SystemComponent.h
//
//  Contents:   CIM_SystemComponent is a specialization of the CIM_Component association that establishes 'part of' relationships between a System and any ManagedSystemElements of which it is composed. 
//              Use this association with caution when using it instead of a subclass such as SystemDevice or a peer association such as HostedService. This class is very broadly defined, which can lead to erroneous use. For example, Access Points that are dependent on (and hosted on) a System are NOT Components of the System. The System is not made up of any AccessPoint 'parts', which is why a Dependency association, HostedAccessPoint, was defined. Similarly, a PhysicalPackage is not a 'part' of a System, because the physical element exists independently of any internal components, software, and so on. In fact, again, a Dependency relationship is true where a ComputerSystem is Dependent on its packaging, as described by the ComputerSystemPackage association.
//
//              This file was automatically generated from CIM_SystemComponent.mof,  version: 2.10.0
//
//----------------------------------------------------------------------------
#ifndef CIM_SYSTEMCOMPONENT_H
#define CIM_SYSTEMCOMPONENT_H 1
#include "CIM_Component.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	// CIM_SystemComponent is a specialization of the CIM_Component association that establishes 'part of' relationships between a System and any ManagedSystemElements of which it is composed. 
	// Use this association with caution when using it instead of a subclass such as SystemDevice or a peer association such as HostedService. This class is very broadly defined, which can lead to erroneous use. For example, Access Points that are dependent on (and hosted on) a System are NOT Components of the System. The System is not made up of any AccessPoint 'parts', which is why a Dependency association, HostedAccessPoint, was defined. Similarly, a PhysicalPackage is not a 'part' of a System, because the physical element exists independently of any internal components, software, and so on. In fact, again, a Dependency relationship is true where a ComputerSystem is Dependent on its packaging, as described by the ComputerSystemPackage association.
	class CIMFRAMEWORK_API CIM_SystemComponent  : public CIM_Component
	{
	public:

		//Default constructor
		CIM_SystemComponent()
			: CIM_Component(NULL, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_Component::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 2);
			}
		}

		//constructor which receives WSMan client
		CIM_SystemComponent(ICimWsmanClient *client)
			: CIM_Component(client, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_Component::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 2);
			}
		}

		//Destructor
		virtual ~CIM_SystemComponent(){}

		// The "type" information for the object. Gettors only.
		virtual const string& ResourceURI() const { return CLASS_URI; }
		static const string& ClassResourceURI() { return CLASS_URI; }
		virtual const string& XmlNamespace() const { return CLASS_NS; }
		virtual const string& XmlPrefix() const { return CLASS_NS_PREFIX; }
		virtual const string& ObjectType() const { return CLASS_NAME; }
		static const string& ClassObjectType() { return CLASS_NAME; }

		// Class representing CIM_SystemComponent keys
		class CimKeys : public CIM_Component::CimKeys
		{
		public:
			// Required, The parent System in the Association.
			const CimReference GroupComponent() const
			{
				CimReference ret;
				TypeConverter::StringToType(GetKey("GroupComponent"), ret);
				return ret;
			}

			// Required, The parent System in the Association.
			void GroupComponent(const CimReference &value)
			{
				SetOrAddKey("GroupComponent", TypeConverter::TypeToString(value), true);
			}

			// Required, The child element that is a component of a System.
			const CimReference PartComponent() const
			{
				CimReference ret;
				TypeConverter::StringToType(GetKey("PartComponent"), ret);
				return ret;
			}

			// Required, The child element that is a component of a System.
			void PartComponent(const CimReference &value)
			{
				SetOrAddKey("PartComponent", TypeConverter::TypeToString(value), true);
			}

		};
		 // Function used by the factory
		static CimBase *CreateFromCimObject(const CimObject &object);

		static vector<shared_ptr<CIM_SystemComponent> > Enumerate(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		// Overloaded delete which supplies the internal resourceURI
		static void Delete(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		using CimBase::Delete;

	protected:
		 // Protected constructor to be used by derived classes
		CIM_SystemComponent(ICimWsmanClient *client, const string &class_name,
			const string &class_ns, const string &prefix, const string &uri): CIM_Component(client, class_name, class_ns, prefix, uri)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_Component::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 2);
			}
		}
		 // Protected constructor which receives CimObject
		CIM_SystemComponent(const CimObject &object)
			: CIM_Component(object)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_Component::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 2);
			}
		}
		// Called by derived classes
		void SetMetaData(vector<CimFieldAttribute>& childMetaData)
		{
			CIM_Component::SetMetaData(childMetaData);
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
#endif // CIM_SYSTEMCOMPONENT_H
