//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_AuthorizedPrivilege.h
//
//  Contents:   Privilege is the base class for all types of activities which are granted or denied to a Role or an Identity. AuthorizedPrivilege is a subclass defining static renderings of authorization policy rules. The association of Roles and Identities to AuthorizedPrivilege is accomplished using the AuthorizedSubject relationship. The entities that are protected are defined using the AuthorizedTarget relationship. 
//              
//              Note that this class and its AuthorizedSubject/Target associations provide a short-hand, static mechanism to represent authorization policies.
//
//              This file was automatically generated from CIM_AuthorizedPrivilege.mof,  version: 2.8.0
//
//----------------------------------------------------------------------------
#ifndef CIM_AUTHORIZEDPRIVILEGE_H
#define CIM_AUTHORIZEDPRIVILEGE_H 1
#include "CIM_Privilege.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	// Privilege is the base class for all types of activities which are granted or denied to a Role or an Identity. AuthorizedPrivilege is a subclass defining static renderings of authorization policy rules. The association of Roles and Identities to AuthorizedPrivilege is accomplished using the AuthorizedSubject relationship. The entities that are protected are defined using the AuthorizedTarget relationship. 
	// 
	// Note that this class and its AuthorizedSubject/Target associations provide a short-hand, static mechanism to represent authorization policies.
	class CIMFRAMEWORK_API CIM_AuthorizedPrivilege  : public CIM_Privilege
	{
	public:

		//Default constructor
		CIM_AuthorizedPrivilege()
			: CIM_Privilege(NULL, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				_classMetaData = CIM_Privilege::GetMetaData();
			}
		}

		//constructor which receives WSMan client
		CIM_AuthorizedPrivilege(ICimWsmanClient *client)
			: CIM_Privilege(client, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				_classMetaData = CIM_Privilege::GetMetaData();
			}
		}

		//Destructor
		virtual ~CIM_AuthorizedPrivilege(){}

		// The "type" information for the object. Gettors only.
		virtual const string& ResourceURI() const { return CLASS_URI; }
		static const string& ClassResourceURI() { return CLASS_URI; }
		virtual const string& XmlNamespace() const { return CLASS_NS; }
		virtual const string& XmlPrefix() const { return CLASS_NS_PREFIX; }
		virtual const string& ObjectType() const { return CLASS_NAME; }
		static const string& ClassObjectType() { return CLASS_NAME; }

		// Class representing CIM_AuthorizedPrivilege keys
		class CimKeys : public CIM_Privilege::CimKeys
		{
		public:
		};
		 // Function used by the factory
		static CimBase *CreateFromCimObject(const CimObject &object);

		static vector<shared_ptr<CIM_AuthorizedPrivilege> > Enumerate(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		// Overloaded delete which supplies the internal resourceURI
		static void Delete(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		using CimBase::Delete;

	protected:
		 // Protected constructor to be used by derived classes
		CIM_AuthorizedPrivilege(ICimWsmanClient *client, const string &class_name,
			const string &class_ns, const string &prefix, const string &uri): CIM_Privilege(client, class_name, class_ns, prefix, uri)
		{
			if(_classMetaData.size() == 0)
			{
				_classMetaData = CIM_Privilege::GetMetaData();
			}
		}
		 // Protected constructor which receives CimObject
		CIM_AuthorizedPrivilege(const CimObject &object)
			: CIM_Privilege(object)
		{
			if(_classMetaData.size() == 0)
			{
				_classMetaData = CIM_Privilege::GetMetaData();
			}
		}
		// Called by derived classes
		void SetMetaData(vector<CimFieldAttribute>& childMetaData)
		{
			CIM_Privilege::SetMetaData(childMetaData);
		}
		const vector<CimFieldAttribute> &GetMetaData() const;
	private:
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
#endif // CIM_AUTHORIZEDPRIVILEGE_H
