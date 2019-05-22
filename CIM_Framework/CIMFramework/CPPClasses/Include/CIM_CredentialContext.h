//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_CredentialContext.h
//
//  Contents:   This relationship defines a context (e.g., a System or Service) of a Credential. One example is a shared secret/ password which is defined within the context of an application (or Service). Generally, there is one scoping element for a Credential, however the multiplicities of the association allow a Credential to be scoped by more than one element. If this association is not instantiated for a Credential, that Credential is assumed to be scoped to the Namespace.
//              This association may also be used to indicate that a Credential is valid in some other environment. For instance associating the Credential to a RemoteServiceAccessPoint would indicate that the Credential is used to access the remote service.
//
//              This file was automatically generated from CIM_CredentialContext.mof,  version: 2.27.0
//
//----------------------------------------------------------------------------
#ifndef CIM_CREDENTIALCONTEXT_H
#define CIM_CREDENTIALCONTEXT_H 1
#include "../../include/CimBase.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	// This relationship defines a context (e.g., a System or Service) of a Credential. One example is a shared secret/ password which is defined within the context of an application (or Service). Generally, there is one scoping element for a Credential, however the multiplicities of the association allow a Credential to be scoped by more than one element. If this association is not instantiated for a Credential, that Credential is assumed to be scoped to the Namespace.
	// This association may also be used to indicate that a Credential is valid in some other environment. For instance associating the Credential to a RemoteServiceAccessPoint would indicate that the Credential is used to access the remote service.
	class CIMFRAMEWORK_API CIM_CredentialContext  : public CimBase
	{
	public:

		//Default constructor
		CIM_CredentialContext()
			: CimBase(NULL, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CimBase::SetMetaData(_classMetaData, _metadata, 3);
			}
		}

		//constructor which receives WSMan client
		CIM_CredentialContext(ICimWsmanClient *client)
			: CimBase(client, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CimBase::SetMetaData(_classMetaData, _metadata, 3);
			}
		}

		//Destructor
		virtual ~CIM_CredentialContext(){}

		// The "type" information for the object. Gettors only.
		virtual const string& ResourceURI() const { return CLASS_URI; }
		static const string& ClassResourceURI() { return CLASS_URI; }
		virtual const string& XmlNamespace() const { return CLASS_NS; }
		virtual const string& XmlPrefix() const { return CLASS_NS_PREFIX; }
		virtual const string& ObjectType() const { return CLASS_NAME; }
		static const string& ClassObjectType() { return CLASS_NAME; }

		// Class representing CIM_CredentialContext keys
		class CimKeys : public CimBase::CimKeys
		{
		public:
			// Key, Required, A Credential whose context is defined.
			const CimReference ElementInContext() const
			{
				CimReference ret;
				TypeConverter::StringToType(GetKey("ElementInContext"), ret);
				return ret;
			}

			// Key, Required, A Credential whose context is defined.
			void ElementInContext(const CimReference &value)
			{
				SetOrAddKey("ElementInContext", TypeConverter::TypeToString(value), true);
			}

			// Key, Required, The ManagedElement that provides context or scope for the Credential.
			const CimReference ElementProvidingContext() const
			{
				CimReference ret;
				TypeConverter::StringToType(GetKey("ElementProvidingContext"), ret);
				return ret;
			}

			// Key, Required, The ManagedElement that provides context or scope for the Credential.
			void ElementProvidingContext(const CimReference &value)
			{
				SetOrAddKey("ElementProvidingContext", TypeConverter::TypeToString(value), true);
			}

		};

		// class fields declarations

		// Key, Required, A Credential whose context is defined.
		const CimReference ElementInContext() const;

		// Key, Required, A Credential whose context is defined.
		void ElementInContext(const CimReference &value); 


		// Key, Required, The ManagedElement that provides context or scope for the Credential.
		const CimReference ElementProvidingContext() const;

		// Key, Required, The ManagedElement that provides context or scope for the Credential.
		void ElementProvidingContext(const CimReference &value); 


		// Optional, The usage of the certificate by the managed element that the certificate is for or is scoped to. Owned - Credential represents the CredentialContexts identity. This means that the managed element will present this credential to another party for authentication, authorization, or both. Trusted - The ManagedElement trusts the credential. This means that the credential is trusted for one or more of the security operations such as authentication, third-party authentication, and authorization. Trusted for Authentication - The ManagedElement trusts the identity represented by the credential only for authentication purposes. Trusted for Authorization - The ManagedElement trusts the identity represented by the credential only for authorization purposes. Trusted for Authentication/Authorization - The ManagedElement trusts the identity represented by the credential both for authentication and authorization purposes. Trusted for Third-Party Authentication/Authorization - The credential is being trusted for approving a third-party credential to the ManagedElement.
		const unsigned short Usage() const;

		// Optional, The usage of the certificate by the managed element that the certificate is for or is scoped to. Owned - Credential represents the CredentialContexts identity. This means that the managed element will present this credential to another party for authentication, authorization, or both. Trusted - The ManagedElement trusts the credential. This means that the credential is trusted for one or more of the security operations such as authentication, third-party authentication, and authorization. Trusted for Authentication - The ManagedElement trusts the identity represented by the credential only for authentication purposes. Trusted for Authorization - The ManagedElement trusts the identity represented by the credential only for authorization purposes. Trusted for Authentication/Authorization - The ManagedElement trusts the identity represented by the credential both for authentication and authorization purposes. Trusted for Third-Party Authentication/Authorization - The credential is being trusted for approving a third-party credential to the ManagedElement.
		void Usage(const unsigned short value); 

		// Is true if the field Usage exists in the current object, otherwise is false.
		bool UsageExists() const;

		// Remove Usage field.
		void RemoveUsage(); 

		 // Function used by the factory
		static CimBase *CreateFromCimObject(const CimObject &object);

		static vector<shared_ptr<CIM_CredentialContext> > Enumerate(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		// Overloaded delete which supplies the internal resourceURI
		static void Delete(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		using CimBase::Delete;

	protected:
		 // Protected constructor to be used by derived classes
		CIM_CredentialContext(ICimWsmanClient *client, const string &class_name,
			const string &class_ns, const string &prefix, const string &uri): CimBase(client, class_name, class_ns, prefix, uri)
		{
			if(_classMetaData.size() == 0)
			{
				CimBase::SetMetaData(_classMetaData, _metadata, 3);
			}
		}
		 // Protected constructor which receives CimObject
		CIM_CredentialContext(const CimObject &object)
			: CimBase(object)
		{
			if(_classMetaData.size() == 0)
			{
				CimBase::SetMetaData(_classMetaData, _metadata, 3);
			}
		}
		// Called by derived classes
		void SetMetaData(vector<CimFieldAttribute>& childMetaData)
		{
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
#endif // CIM_CREDENTIALCONTEXT_H
