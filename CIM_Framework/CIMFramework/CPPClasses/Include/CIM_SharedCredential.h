//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_SharedCredential.h
//
//  Contents:   SharedCredential is a secret (such as a password or the response to a challenge question) that is shared between a principal and a particular SharedCredential security service. Secrets may be in the form of a password used for initial authentication, or as with a session key, used as part of a message to verify the originator of the message. It is important to note that SharedCredential is not just a password, but rather is the password used with a particular security service.
//
//              This file was automatically generated from CIM_SharedCredential.mof,  version: 2.27.0
//
//----------------------------------------------------------------------------
#ifndef CIM_SHAREDCREDENTIAL_H
#define CIM_SHAREDCREDENTIAL_H 1
#include "CIM_Credential.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	// SharedCredential is a secret (such as a password or the response to a challenge question) that is shared between a principal and a particular SharedCredential security service. Secrets may be in the form of a password used for initial authentication, or as with a session key, used as part of a message to verify the originator of the message. It is important to note that SharedCredential is not just a password, but rather is the password used with a particular security service.
	class CIMFRAMEWORK_API CIM_SharedCredential  : public CIM_Credential
	{
	public:

		//Default constructor
		CIM_SharedCredential()
			: CIM_Credential(NULL, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_Credential::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 5);
			}
		}

		//constructor which receives WSMan client
		CIM_SharedCredential(ICimWsmanClient *client)
			: CIM_Credential(client, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_Credential::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 5);
			}
		}

		//Destructor
		virtual ~CIM_SharedCredential(){}

		// The "type" information for the object. Gettors only.
		virtual const string& ResourceURI() const { return CLASS_URI; }
		static const string& ClassResourceURI() { return CLASS_URI; }
		virtual const string& XmlNamespace() const { return CLASS_NS; }
		virtual const string& XmlPrefix() const { return CLASS_NS_PREFIX; }
		virtual const string& ObjectType() const { return CLASS_NAME; }
		static const string& ClassObjectType() { return CLASS_NAME; }

		// Class representing CIM_SharedCredential keys
		class CimKeys : public CIM_Credential::CimKeys
		{
		public:
			// Key, Required, Within the scope of the instantiating Namespace, InstanceID opaquely and uniquely identifies an instance of this class. In order to ensure uniqueness within the NameSpace, the value of InstanceID SHOULD be constructed using the following 'preferred' algorithm: 
			// <OrgID>:<LocalID> 
			// Where <OrgID> and <LocalID> are separated by a colon ':', and where <OrgID> MUST include a copyrighted, trademarked or otherwise unique name that is owned by the business entity creating/defining the InstanceID, or is a registered ID that is assigned to the business entity by a recognized global authority. (This is similar to the <Schema Name>_<Class Name> structure of Schema class names.) In addition, to ensure uniqueness, <OrgID> MUST NOT contain a colon (':'). When using this algorithm, the first colon to appear in InstanceID MUST appear between <OrgID> and <LocalID>. 
			// <LocalID> is chosen by the organizational entity and SHOULD not be re-used to identify different underlying (real-world) elements. If the above 'preferred' algorithm is not used, the defining entity MUST assure that the resultant InstanceID is not re-used across any InstanceIDs produced by this or other providers for this instance's NameSpace. 
			// For DMTF defined instances, the 'preferred' algorithm MUST be used with the <OrgID> set to 'CIM'.
			const string InstanceID() const
			{
				return GetKey("InstanceID");
			}

			// Key, Required, Within the scope of the instantiating Namespace, InstanceID opaquely and uniquely identifies an instance of this class. In order to ensure uniqueness within the NameSpace, the value of InstanceID SHOULD be constructed using the following 'preferred' algorithm: 
			// <OrgID>:<LocalID> 
			// Where <OrgID> and <LocalID> are separated by a colon ':', and where <OrgID> MUST include a copyrighted, trademarked or otherwise unique name that is owned by the business entity creating/defining the InstanceID, or is a registered ID that is assigned to the business entity by a recognized global authority. (This is similar to the <Schema Name>_<Class Name> structure of Schema class names.) In addition, to ensure uniqueness, <OrgID> MUST NOT contain a colon (':'). When using this algorithm, the first colon to appear in InstanceID MUST appear between <OrgID> and <LocalID>. 
			// <LocalID> is chosen by the organizational entity and SHOULD not be re-used to identify different underlying (real-world) elements. If the above 'preferred' algorithm is not used, the defining entity MUST assure that the resultant InstanceID is not re-used across any InstanceIDs produced by this or other providers for this instance's NameSpace. 
			// For DMTF defined instances, the 'preferred' algorithm MUST be used with the <OrgID> set to 'CIM'.
			void InstanceID(const string &value)
			{
				SetOrAddKey("InstanceID", value);
			}

		};

		// class fields declarations

		// Optional, RemoteID is the name by which the principal is known at the remote secret key authentication service.
		const string RemoteID() const;

		// Optional, RemoteID is the name by which the principal is known at the remote secret key authentication service.
		void RemoteID(const string &value); 

		// Is true if the field RemoteID exists in the current object, otherwise is false.
		bool RemoteIDExists() const;

		// Remove RemoteID field.
		void RemoveRemoteID(); 

		// Optional, The secret known by the principal.
		const string Secret() const;

		// Optional, The secret known by the principal.
		void Secret(const string &value); 

		// Is true if the field Secret exists in the current object, otherwise is false.
		bool SecretExists() const;

		// Remove Secret field.
		void RemoveSecret(); 

		// Optional, The transformation algorithm, if any, used to protect passwords before use in the protocol. For instance, Kerberos doesn't store passwords as the shared secret, but rather, a hash of the password.
		const string Algorithm() const;

		// Optional, The transformation algorithm, if any, used to protect passwords before use in the protocol. For instance, Kerberos doesn't store passwords as the shared secret, but rather, a hash of the password.
		void Algorithm(const string &value); 

		// Is true if the field Algorithm exists in the current object, otherwise is false.
		bool AlgorithmExists() const;

		// Remove Algorithm field.
		void RemoveAlgorithm(); 

		// Optional, The protocol with which the SharedCredential is used.
		const string Protocol() const;

		// Optional, The protocol with which the SharedCredential is used.
		void Protocol(const string &value); 

		// Is true if the field Protocol exists in the current object, otherwise is false.
		bool ProtocolExists() const;

		// Remove Protocol field.
		void RemoveProtocol(); 

		 // Function used by the factory
		static CimBase *CreateFromCimObject(const CimObject &object);

		static vector<shared_ptr<CIM_SharedCredential> > Enumerate(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		// Overloaded delete which supplies the internal resourceURI
		static void Delete(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		using CimBase::Delete;

	protected:
		 // Protected constructor to be used by derived classes
		CIM_SharedCredential(ICimWsmanClient *client, const string &class_name,
			const string &class_ns, const string &prefix, const string &uri): CIM_Credential(client, class_name, class_ns, prefix, uri)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_Credential::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 5);
			}
		}
		 // Protected constructor which receives CimObject
		CIM_SharedCredential(const CimObject &object)
			: CIM_Credential(object)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_Credential::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 5);
			}
		}
		// Called by derived classes
		void SetMetaData(vector<CimFieldAttribute>& childMetaData)
		{
			CIM_Credential::SetMetaData(childMetaData);
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
#endif // CIM_SHAREDCREDENTIAL_H
