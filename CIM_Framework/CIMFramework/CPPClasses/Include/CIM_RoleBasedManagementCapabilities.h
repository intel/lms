//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_RoleBasedManagementCapabilities.h
//
//  Contents:   A subclass that extends the capabilities of the CIM_RoleBasedAuthorizationService.
//
//              This file was automatically generated from CIM_RoleBasedManagementCapabilities.mof,  version: 2.18.0
//
//----------------------------------------------------------------------------
#ifndef CIM_ROLEBASEDMANAGEMENTCAPABILITIES_H
#define CIM_ROLEBASEDMANAGEMENTCAPABILITIES_H 1
#include "CIM_PrivilegeManagementCapabilities.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	// A subclass that extends the capabilities of the CIM_RoleBasedAuthorizationService.
	class CIMFRAMEWORK_API CIM_RoleBasedManagementCapabilities  : public CIM_PrivilegeManagementCapabilities
	{
	public:

		//Default constructor
		CIM_RoleBasedManagementCapabilities()
			: CIM_PrivilegeManagementCapabilities(NULL, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_PrivilegeManagementCapabilities::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 1);
			}
		}

		//constructor which receives WSMan client
		CIM_RoleBasedManagementCapabilities(ICimWsmanClient *client)
			: CIM_PrivilegeManagementCapabilities(client, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_PrivilegeManagementCapabilities::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 1);
			}
		}

		//Destructor
		virtual ~CIM_RoleBasedManagementCapabilities(){}

		// The "type" information for the object. Gettors only.
		virtual const string& ResourceURI() const { return CLASS_URI; }
		static const string& ClassResourceURI() { return CLASS_URI; }
		virtual const string& XmlNamespace() const { return CLASS_NS; }
		virtual const string& XmlPrefix() const { return CLASS_NS_PREFIX; }
		virtual const string& ObjectType() const { return CLASS_NAME; }
		static const string& ClassObjectType() { return CLASS_NAME; }

		// Class representing CIM_RoleBasedManagementCapabilities keys
		class CimKeys : public CIM_PrivilegeManagementCapabilities::CimKeys
		{
		public:
		};
		 // Function used by the factory
		static CimBase *CreateFromCimObject(const CimObject &object);

		static vector<shared_ptr<CIM_RoleBasedManagementCapabilities> > Enumerate(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		// Overloaded delete which supplies the internal resourceURI
		static void Delete(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		using CimBase::Delete;

	protected:
		 // Protected constructor to be used by derived classes
		CIM_RoleBasedManagementCapabilities(ICimWsmanClient *client, const string &class_name,
			const string &class_ns, const string &prefix, const string &uri): CIM_PrivilegeManagementCapabilities(client, class_name, class_ns, prefix, uri)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_PrivilegeManagementCapabilities::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 1);
			}
		}
		 // Protected constructor which receives CimObject
		CIM_RoleBasedManagementCapabilities(const CimObject &object)
			: CIM_PrivilegeManagementCapabilities(object)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_PrivilegeManagementCapabilities::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 1);
			}
		}
		// Called by derived classes
		void SetMetaData(vector<CimFieldAttribute>& childMetaData)
		{
			CIM_PrivilegeManagementCapabilities::SetMetaData(childMetaData);
			CimBase::SetMetaData(childMetaData, _metadata, 1);
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
#endif // CIM_ROLEBASEDMANAGEMENTCAPABILITIES_H
