//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_ConcreteComponent.h
//
//  Contents:   CIM_ConcreteComponent is a generic association used to establish 'part of' relationships between ManagedElements. It is defined as a concrete subclass of the abstract CIM_Component class, to be used in place of many specific subclasses of Component that add no semantics, that is subclasses that do not clarify the type of composition, update cardinalities, or add or remove qualifiers. Note that when you define additional semantics for Component, this class must not be subclassed. Specific semantics continue to be defined as subclasses of the abstract CIM_Component. ConcreteComponent is limited in its use as a concrete form of a general composition. 
//              
//              It was deemed more prudent to create this concrete subclass than to change Component from an abstract to a concrete class. Industry usage and impact could not be anticipated.
//
//              This file was automatically generated from CIM_ConcreteComponent.mof,  version: 2.10.0
//
//----------------------------------------------------------------------------
#ifndef CIM_CONCRETECOMPONENT_H
#define CIM_CONCRETECOMPONENT_H 1
#include "CIM_Component.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	// CIM_ConcreteComponent is a generic association used to establish 'part of' relationships between ManagedElements. It is defined as a concrete subclass of the abstract CIM_Component class, to be used in place of many specific subclasses of Component that add no semantics, that is subclasses that do not clarify the type of composition, update cardinalities, or add or remove qualifiers. Note that when you define additional semantics for Component, this class must not be subclassed. Specific semantics continue to be defined as subclasses of the abstract CIM_Component. ConcreteComponent is limited in its use as a concrete form of a general composition. 
	// 
	// It was deemed more prudent to create this concrete subclass than to change Component from an abstract to a concrete class. Industry usage and impact could not be anticipated.
	class CIMFRAMEWORK_API CIM_ConcreteComponent  : public CIM_Component
	{
	public:

		//Default constructor
		CIM_ConcreteComponent()
			: CIM_Component(NULL, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_Component::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 2);
			}
		}

		//constructor which receives WSMan client
		CIM_ConcreteComponent(ICimWsmanClient *client)
			: CIM_Component(client, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_Component::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 2);
			}
		}

		//Destructor
		virtual ~CIM_ConcreteComponent(){}

		// The "type" information for the object. Gettors only.
		virtual const string& ResourceURI() const { return CLASS_URI; }
		static const string& ClassResourceURI() { return CLASS_URI; }
		virtual const string& XmlNamespace() const { return CLASS_NS; }
		virtual const string& XmlPrefix() const { return CLASS_NS_PREFIX; }
		virtual const string& ObjectType() const { return CLASS_NAME; }
		static const string& ClassObjectType() { return CLASS_NAME; }

		// Class representing CIM_ConcreteComponent keys
		class CimKeys : public CIM_Component::CimKeys
		{
		public:
			// Required, The parent element in the association.
			const CimReference GroupComponent() const
			{
				CimReference ret;
				TypeConverter::StringToType(GetKey("GroupComponent"), ret);
				return ret;
			}

			// Required, The parent element in the association.
			void GroupComponent(const CimReference &value)
			{
				SetOrAddKey("GroupComponent", TypeConverter::TypeToString(value), true);
			}

			// Required, The child element in the association.
			const CimReference PartComponent() const
			{
				CimReference ret;
				TypeConverter::StringToType(GetKey("PartComponent"), ret);
				return ret;
			}

			// Required, The child element in the association.
			void PartComponent(const CimReference &value)
			{
				SetOrAddKey("PartComponent", TypeConverter::TypeToString(value), true);
			}

		};
		 // Function used by the factory
		static CimBase *CreateFromCimObject(const CimObject &object);

		static vector<shared_ptr<CIM_ConcreteComponent> > Enumerate(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		// Overloaded delete which supplies the internal resourceURI
		static void Delete(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		using CimBase::Delete;

	protected:
		 // Protected constructor to be used by derived classes
		CIM_ConcreteComponent(ICimWsmanClient *client, const string &class_name,
			const string &class_ns, const string &prefix, const string &uri): CIM_Component(client, class_name, class_ns, prefix, uri)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_Component::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 2);
			}
		}
		 // Protected constructor which receives CimObject
		CIM_ConcreteComponent(const CimObject &object)
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
#endif // CIM_CONCRETECOMPONENT_H
