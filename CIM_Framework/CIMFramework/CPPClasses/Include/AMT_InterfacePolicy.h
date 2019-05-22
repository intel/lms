//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       AMT_InterfacePolicy.h
//
//  Contents:   Associates a System Defense Policy to a Network Interface. An existing association implies that a System Defense Policy may be activated on the specified interface. Among all the associations that may exist there can be only one active policy per interface. An Active policy is chosen based on the precedence property in a policy.
//
//              This file was automatically generated from AMT_InterfacePolicy.mof,  version: 6.0.0
//
//----------------------------------------------------------------------------
#ifndef AMT_INTERFACEPOLICY_H
#define AMT_INTERFACEPOLICY_H 1
#include "CIM_Dependency.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	// Associates a System Defense Policy to a Network Interface. An existing association implies that a System Defense Policy may be activated on the specified interface. Among all the associations that may exist there can be only one active policy per interface. An Active policy is chosen based on the precedence property in a policy.
	class CIMFRAMEWORK_API AMT_InterfacePolicy  : public CIM_Dependency
	{
	public:

		//Default constructor
		AMT_InterfacePolicy()
			: CIM_Dependency(NULL, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_Dependency::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 3);
			}
		}

		//constructor which receives WSMan client
		AMT_InterfacePolicy(ICimWsmanClient *client)
			: CIM_Dependency(client, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_Dependency::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 3);
			}
		}

		//Destructor
		virtual ~AMT_InterfacePolicy(){}

		// The "type" information for the object. Gettors only.
		virtual const string& ResourceURI() const { return CLASS_URI; }
		static const string& ClassResourceURI() { return CLASS_URI; }
		virtual const string& XmlNamespace() const { return CLASS_NS; }
		virtual const string& XmlPrefix() const { return CLASS_NS_PREFIX; }
		virtual const string& ObjectType() const { return CLASS_NAME; }
		static const string& ClassObjectType() { return CLASS_NAME; }

		// Class representing AMT_InterfacePolicy keys
		class CimKeys : public CIM_Dependency::CimKeys
		{
		public:
			// Key, Required, References a CIM_EthernetPort object representing the interface.
			const CimReference Antecedent() const
			{
				CimReference ret;
				TypeConverter::StringToType(GetKey("Antecedent"), ret);
				return ret;
			}

			// Key, Required, References a CIM_EthernetPort object representing the interface.
			void Antecedent(const CimReference &value)
			{
				SetOrAddKey("Antecedent", TypeConverter::TypeToString(value), true);
			}

			// Key, Required, References an AMT_SystemDefensePolicy object.
			const CimReference Dependent() const
			{
				CimReference ret;
				TypeConverter::StringToType(GetKey("Dependent"), ret);
				return ret;
			}

			// Key, Required, References an AMT_SystemDefensePolicy object.
			void Dependent(const CimReference &value)
			{
				SetOrAddKey("Dependent", TypeConverter::TypeToString(value), true);
			}

		};

		// class fields declarations

		// Optional, Specifies whether this Policy is Active on the network interface.
		const bool Active() const;

		// Optional, Specifies whether this Policy is Active on the network interface.
		void Active(const bool value); 

		// Is true if the field Active exists in the current object, otherwise is false.
		bool ActiveExists() const;

		// Remove Active field.
		void RemoveActive(); 

		 // Function used by the factory
		static CimBase *CreateFromCimObject(const CimObject &object);

		static vector<shared_ptr<AMT_InterfacePolicy> > Enumerate(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		// Overloaded delete which supplies the internal resourceURI
		static void Delete(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		using CimBase::Delete;

	protected:
		 // Protected constructor to be used by derived classes
		AMT_InterfacePolicy(ICimWsmanClient *client, const string &class_name,
			const string &class_ns, const string &prefix, const string &uri): CIM_Dependency(client, class_name, class_ns, prefix, uri)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_Dependency::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 3);
			}
		}
		 // Protected constructor which receives CimObject
		AMT_InterfacePolicy(const CimObject &object)
			: CIM_Dependency(object)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_Dependency::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 3);
			}
		}
		// Called by derived classes
		void SetMetaData(vector<CimFieldAttribute>& childMetaData)
		{
			CIM_Dependency::SetMetaData(childMetaData);
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
#endif // AMT_INTERFACEPOLICY_H
