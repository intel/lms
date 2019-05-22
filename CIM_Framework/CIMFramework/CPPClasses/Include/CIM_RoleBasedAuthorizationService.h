//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_RoleBasedAuthorizationService.h
//
//  Contents:   The CIM_RoleBasedAuthorizationService class represents the authorization service that manages and configures roles on a managed system. The CIM_RoleBasedAuthorizationService is responsible for creating, and deleting CIM_Role instances. Privileges of the roles are represented through the instance(s) of CIM_Privilege class associated to CIM_Role instances through the CIM_MemberOfCollection association. As a result of creating, and deleting CIM_Role instances the CIM_Privilege instances can also be affected. The limiting scope of the role is determined by the CIM_RoleLimitedToTarget association.
//
//              This file was automatically generated from CIM_RoleBasedAuthorizationService.mof,  version: 2.26.0
//
//----------------------------------------------------------------------------
#ifndef CIM_ROLEBASEDAUTHORIZATIONSERVICE_H
#define CIM_ROLEBASEDAUTHORIZATIONSERVICE_H 1
#include "CIM_PrivilegeManagementService.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	// The CIM_RoleBasedAuthorizationService class represents the authorization service that manages and configures roles on a managed system. The CIM_RoleBasedAuthorizationService is responsible for creating, and deleting CIM_Role instances. Privileges of the roles are represented through the instance(s) of CIM_Privilege class associated to CIM_Role instances through the CIM_MemberOfCollection association. As a result of creating, and deleting CIM_Role instances the CIM_Privilege instances can also be affected. The limiting scope of the role is determined by the CIM_RoleLimitedToTarget association.
	class CIMFRAMEWORK_API CIM_RoleBasedAuthorizationService  : public CIM_PrivilegeManagementService
	{
	public:

		//Default constructor
		CIM_RoleBasedAuthorizationService()
			: CIM_PrivilegeManagementService(NULL, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				_classMetaData = CIM_PrivilegeManagementService::GetMetaData();
			}
		}

		//constructor which receives WSMan client
		CIM_RoleBasedAuthorizationService(ICimWsmanClient *client)
			: CIM_PrivilegeManagementService(client, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				_classMetaData = CIM_PrivilegeManagementService::GetMetaData();
			}
		}

		//Destructor
		virtual ~CIM_RoleBasedAuthorizationService(){}

		// The "type" information for the object. Gettors only.
		virtual const string& ResourceURI() const { return CLASS_URI; }
		static const string& ClassResourceURI() { return CLASS_URI; }
		virtual const string& XmlNamespace() const { return CLASS_NS; }
		virtual const string& XmlPrefix() const { return CLASS_NS_PREFIX; }
		virtual const string& ObjectType() const { return CLASS_NAME; }
		static const string& ClassObjectType() { return CLASS_NAME; }

		// Class representing CIM_RoleBasedAuthorizationService keys
		class CimKeys : public CIM_PrivilegeManagementService::CimKeys
		{
		public:
		};
		 // Function used by the factory
		static CimBase *CreateFromCimObject(const CimObject &object);

		static vector<shared_ptr<CIM_RoleBasedAuthorizationService> > Enumerate(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		// Overloaded delete which supplies the internal resourceURI
		static void Delete(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		using CimBase::Delete;

	protected:
		 // Protected constructor to be used by derived classes
		CIM_RoleBasedAuthorizationService(ICimWsmanClient *client, const string &class_name,
			const string &class_ns, const string &prefix, const string &uri): CIM_PrivilegeManagementService(client, class_name, class_ns, prefix, uri)
		{
			if(_classMetaData.size() == 0)
			{
				_classMetaData = CIM_PrivilegeManagementService::GetMetaData();
			}
		}
		 // Protected constructor which receives CimObject
		CIM_RoleBasedAuthorizationService(const CimObject &object)
			: CIM_PrivilegeManagementService(object)
		{
			if(_classMetaData.size() == 0)
			{
				_classMetaData = CIM_PrivilegeManagementService::GetMetaData();
			}
		}
		// Called by derived classes
		void SetMetaData(vector<CimFieldAttribute>& childMetaData)
		{
			CIM_PrivilegeManagementService::SetMetaData(childMetaData);
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
#endif // CIM_ROLEBASEDAUTHORIZATIONSERVICE_H
