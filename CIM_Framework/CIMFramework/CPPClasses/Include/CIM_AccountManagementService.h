//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_AccountManagementService.h
//
//  Contents:   CIM_AccountManagementService creates, manages, and if necessary destroys Accounts on behalf of other SecuritySerices.
//
//              This file was automatically generated from CIM_AccountManagementService.mof,  version: 2.19.0
//
//----------------------------------------------------------------------------
#ifndef CIM_ACCOUNTMANAGEMENTSERVICE_H
#define CIM_ACCOUNTMANAGEMENTSERVICE_H 1
#include "CIM_Account.h"
#include "CIM_SecurityService.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	// CIM_AccountManagementService creates, manages, and if necessary destroys Accounts on behalf of other SecuritySerices.
	class CIMFRAMEWORK_API CIM_AccountManagementService  : public CIM_SecurityService
	{
	public:

		//Default constructor
		CIM_AccountManagementService()
			: CIM_SecurityService(NULL, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				_classMetaData = CIM_SecurityService::GetMetaData();
			}
		}

		//constructor which receives WSMan client
		CIM_AccountManagementService(ICimWsmanClient *client)
			: CIM_SecurityService(client, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				_classMetaData = CIM_SecurityService::GetMetaData();
			}
		}

		//Destructor
		virtual ~CIM_AccountManagementService(){}

		// The "type" information for the object. Gettors only.
		virtual const string& ResourceURI() const { return CLASS_URI; }
		static const string& ClassResourceURI() { return CLASS_URI; }
		virtual const string& XmlNamespace() const { return CLASS_NS; }
		virtual const string& XmlPrefix() const { return CLASS_NS_PREFIX; }
		virtual const string& ObjectType() const { return CLASS_NAME; }
		static const string& ClassObjectType() { return CLASS_NAME; }

		// Class representing CIM_AccountManagementService keys
		class CimKeys : public CIM_SecurityService::CimKeys
		{
		public:
		};
		//Input parameter for function CreateAccount
		class CIMFRAMEWORK_API CreateAccount_INPUT : public CimParam
		{
		public:
			// Class Constructor
			CreateAccount_INPUT() : CimParam() {}

			// Class Destructor
			~CreateAccount_INPUT(){}

			// Required, The scoping ComputerSystem in which to create the Account.
			void System(const CimReference &value); 

			// Required, AccountTemplate is a template for the desired Account to be created.
			void AccountTemplate(const CIM_Account &value); 

			const VectorFieldData GetAllFields() const;
		private:
			static const CimFieldAttribute _metadata[];
		};

		//Output parameter for function CreateAccount
		class CIMFRAMEWORK_API CreateAccount_OUTPUT : public CimParam
		{
		public:
			// Class Constructor
			CreateAccount_OUTPUT() : CimParam() {}

			// Class Destructor
			~CreateAccount_OUTPUT(){}

			// class fields
			// Reference to the instance of CIM_Account created when the method returns a value of 0.
			const CimReference Account() const;
			bool AccountExists() const;
			// Reference to the instances of CIM_Identity created when the method returns a value of 0. NULL if no such instances are created.
			const vector<CimReference> Identities() const;
			bool IdentitiesExists() const;
		private:
		};

		// CreateAccount creates an Account on the specified ComputerSystem. Upon successful completion of the method, there shall be a newly created instance of CIM_Account associated through the CIM_AccountOnSystem association with the instance of ComputerSystem identified by the System parameter such that each property of the CIM_Account instance has the value of the corresponding property of the template instance specified by the AccountTemplate parameter and the CIM_Account instance is associated with this instance of CIM_AccountManagementService through the CIM_ServiceAffectsElement association.
		// Instances of CIM_Identity may be created by the method and associated with the instance of CIM_Account through CIM_AssignedIdentity. If one or more instances of CIM_Identity are created, a reference to each shall be returned in the Identities parameter, otherwise the Identities parameter shall be NULL upon method completion.
		virtual unsigned int CreateAccount(const CreateAccount_INPUT &input, CreateAccount_OUTPUT &output);

		 // Function used by the factory
		static CimBase *CreateFromCimObject(const CimObject &object);

		static vector<shared_ptr<CIM_AccountManagementService> > Enumerate(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		// Overloaded delete which supplies the internal resourceURI
		static void Delete(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		using CimBase::Delete;

	protected:
		 // Protected constructor to be used by derived classes
		CIM_AccountManagementService(ICimWsmanClient *client, const string &class_name,
			const string &class_ns, const string &prefix, const string &uri): CIM_SecurityService(client, class_name, class_ns, prefix, uri)
		{
			if(_classMetaData.size() == 0)
			{
				_classMetaData = CIM_SecurityService::GetMetaData();
			}
		}
		 // Protected constructor which receives CimObject
		CIM_AccountManagementService(const CimObject &object)
			: CIM_SecurityService(object)
		{
			if(_classMetaData.size() == 0)
			{
				_classMetaData = CIM_SecurityService::GetMetaData();
			}
		}
		// Called by derived classes
		void SetMetaData(vector<CimFieldAttribute>& childMetaData)
		{
			CIM_SecurityService::SetMetaData(childMetaData);
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
#endif // CIM_ACCOUNTMANAGEMENTSERVICE_H
