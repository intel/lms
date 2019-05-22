//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_Role.h
//
//  Contents:   The Role object class is used to represent a position or set of responsibilities within an organization, organizational unit or other scope, and MAY be filled by a person or persons (or non-human entities represented by ManagedSystemElement subclasses) - i.e., the 'role occupants'. The latter MAY be explicitly associated to a Role, by associating Identities using MemberOfCollection. The 'position or set of responsibilities' of a Role are represented as a set of rights defined by instances of the Privilege class, and are also associated to the Role via MemberOfCollection. If Identities are not explicitly associated, instances of AuthorizationRule MUST be associated with a Role using AuthorizationRuleAppliesToRole. The rule defines how subject entities are authorized for a Role and to which target entities the Role applies. 
//              
//              The Role class is defined so as to incorporate commonly-used LDAP attributes to permit implementations to easily derive this information from LDAP-accessible directories. This class's properties are a subset of a related class, OtherRoleInformation, which defines all the group properties and uses arrays for directory compatibility.
//
//              This file was automatically generated from CIM_Role.mof,  version: 2.18.0
//
//----------------------------------------------------------------------------
#ifndef CIM_ROLE_H
#define CIM_ROLE_H 1
#include "CIM_Collection.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	// The Role object class is used to represent a position or set of responsibilities within an organization, organizational unit or other scope, and MAY be filled by a person or persons (or non-human entities represented by ManagedSystemElement subclasses) - i.e., the 'role occupants'. The latter MAY be explicitly associated to a Role, by associating Identities using MemberOfCollection. The 'position or set of responsibilities' of a Role are represented as a set of rights defined by instances of the Privilege class, and are also associated to the Role via MemberOfCollection. If Identities are not explicitly associated, instances of AuthorizationRule MUST be associated with a Role using AuthorizationRuleAppliesToRole. The rule defines how subject entities are authorized for a Role and to which target entities the Role applies. 
	// 
	// The Role class is defined so as to incorporate commonly-used LDAP attributes to permit implementations to easily derive this information from LDAP-accessible directories. This class's properties are a subset of a related class, OtherRoleInformation, which defines all the group properties and uses arrays for directory compatibility.
	class CIMFRAMEWORK_API CIM_Role  : public CIM_Collection
	{
	public:

		//Default constructor
		CIM_Role()
			: CIM_Collection(NULL, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_Collection::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 5);
			}
		}

		//constructor which receives WSMan client
		CIM_Role(ICimWsmanClient *client)
			: CIM_Collection(client, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_Collection::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 5);
			}
		}

		//Destructor
		virtual ~CIM_Role(){}

		// The "type" information for the object. Gettors only.
		virtual const string& ResourceURI() const { return CLASS_URI; }
		static const string& ClassResourceURI() { return CLASS_URI; }
		virtual const string& XmlNamespace() const { return CLASS_NS; }
		virtual const string& XmlPrefix() const { return CLASS_NS_PREFIX; }
		virtual const string& ObjectType() const { return CLASS_NAME; }
		static const string& ClassObjectType() { return CLASS_NAME; }

		// Class representing CIM_Role keys
		class CimKeys : public CIM_Collection::CimKeys
		{
		public:
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

			// Key, Required, The Name property defines the label by which the object is known. In the case of an LDAP-derived instance, the Name property value may be set to the distinguished name of the LDAP-accessed object instance.
			const string Name() const
			{
				return GetKey("Name");
			}

			// Key, Required, The Name property defines the label by which the object is known. In the case of an LDAP-derived instance, the Name property value may be set to the distinguished name of the LDAP-accessed object instance.
			void Name(const string &value)
			{
				SetOrAddKey("Name", value);
			}

		};

		// class fields declarations

		// Key, Required, CreationClassName indicates the name of the class or the subclass used in the creation of an instance. When used with the other key properties of this class, this property allows all instances of this class and its subclasses to be uniquely identified.
		const string CreationClassName() const;

		// Key, Required, CreationClassName indicates the name of the class or the subclass used in the creation of an instance. When used with the other key properties of this class, this property allows all instances of this class and its subclasses to be uniquely identified.
		void CreationClassName(const string &value); 


		// Key, Required, The Name property defines the label by which the object is known. In the case of an LDAP-derived instance, the Name property value may be set to the distinguished name of the LDAP-accessed object instance.
		const string Name() const;

		// Key, Required, The Name property defines the label by which the object is known. In the case of an LDAP-derived instance, the Name property value may be set to the distinguished name of the LDAP-accessed object instance.
		void Name(const string &value); 


		// Optional, This property may be used to describe the kind of business activity performed by the members (role occupants) in the position or set of responsibilities represented by the Role.
		const string BusinessCategory() const;

		// Optional, This property may be used to describe the kind of business activity performed by the members (role occupants) in the position or set of responsibilities represented by the Role.
		void BusinessCategory(const string &value); 

		// Is true if the field BusinessCategory exists in the current object, otherwise is false.
		bool BusinessCategoryExists() const;

		// Remove BusinessCategory field.
		void RemoveBusinessCategory(); 

		// Required, A Common Name is a (possibly ambiguous) name by which the role is commonly known in some limited scope (such as an organization) and conforms to the naming conventions of the country or culture with which it is associated.
		const string CommonName() const;

		// Required, A Common Name is a (possibly ambiguous) name by which the role is commonly known in some limited scope (such as an organization) and conforms to the naming conventions of the country or culture with which it is associated.
		void CommonName(const string &value); 

		// Is true if the field CommonName exists in the current object, otherwise is false.
		bool CommonNameExists() const;

		// Remove CommonName field.
		void RemoveCommonName(); 

		// Optional, RoleCharacteristics provides descriptive information about the intended usage of the Role.
		// When the value 2 "Static" is specified, no modification to the role shall be allowed. Any requests by client to change the privileges or the scope of the role by modifying the associated instances of CIM_Privilege or referencing associations shall fail.
		// When the value 2 "Static" is not specified, the instance of CIM_Role may be modified by a client. The modification may include changing the scope of the role or rights granted. When the value 3 "Opaque" is specified, the rights granted by the CIM_Role instance shall not be explicitly modeled through aggregation of instances of CIM_Privilege.
		// When the value 3 "Opaque" is not specified, the rights granted by the instance of CIM_Role shall be explicitly modeled through aggregation of instances of CIM_Privilege.
		const vector<unsigned short> RoleCharacteristics() const;

		// Optional, RoleCharacteristics provides descriptive information about the intended usage of the Role.
		// When the value 2 "Static" is specified, no modification to the role shall be allowed. Any requests by client to change the privileges or the scope of the role by modifying the associated instances of CIM_Privilege or referencing associations shall fail.
		// When the value 2 "Static" is not specified, the instance of CIM_Role may be modified by a client. The modification may include changing the scope of the role or rights granted. When the value 3 "Opaque" is specified, the rights granted by the CIM_Role instance shall not be explicitly modeled through aggregation of instances of CIM_Privilege.
		// When the value 3 "Opaque" is not specified, the rights granted by the instance of CIM_Role shall be explicitly modeled through aggregation of instances of CIM_Privilege.
		void RoleCharacteristics(const vector<unsigned short> &value); 

		// Is true if the field RoleCharacteristics exists in the current object, otherwise is false.
		bool RoleCharacteristicsExists() const;

		// Remove RoleCharacteristics field.
		void RemoveRoleCharacteristics(); 

		 // Function used by the factory
		static CimBase *CreateFromCimObject(const CimObject &object);

		static vector<shared_ptr<CIM_Role> > Enumerate(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		// Overloaded delete which supplies the internal resourceURI
		static void Delete(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		using CimBase::Delete;

	protected:
		 // Protected constructor to be used by derived classes
		CIM_Role(ICimWsmanClient *client, const string &class_name,
			const string &class_ns, const string &prefix, const string &uri): CIM_Collection(client, class_name, class_ns, prefix, uri)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_Collection::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 5);
			}
		}
		 // Protected constructor which receives CimObject
		CIM_Role(const CimObject &object)
			: CIM_Collection(object)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_Collection::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 5);
			}
		}
		// Called by derived classes
		void SetMetaData(vector<CimFieldAttribute>& childMetaData)
		{
			CIM_Collection::SetMetaData(childMetaData);
			CimBase::SetMetaData(childMetaData, _metadata, 5);
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
#endif // CIM_ROLE_H
