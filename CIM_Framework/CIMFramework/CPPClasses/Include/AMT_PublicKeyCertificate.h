//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       AMT_PublicKeyCertificate.h
//
//  Contents:   This class represents a X.509 Certificate in the Intel(R) AMT CertStore.
//
//              This file was automatically generated from AMT_PublicKeyCertificate.mof,  version: 6.0.0
//
//----------------------------------------------------------------------------
#ifndef AMT_PUBLICKEYCERTIFICATE_H
#define AMT_PUBLICKEYCERTIFICATE_H 1
#include "CIM_Credential.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	// This class represents a X.509 Certificate in the Intel(R) AMT CertStore.
	class CIMFRAMEWORK_API AMT_PublicKeyCertificate  : public CIM_Credential
	{
	public:

		//Default constructor
		AMT_PublicKeyCertificate()
			: CIM_Credential(NULL, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_Credential::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 5);
			}
		}

		//constructor which receives WSMan client
		AMT_PublicKeyCertificate(ICimWsmanClient *client)
			: CIM_Credential(client, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_Credential::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 5);
			}
		}

		//Destructor
		virtual ~AMT_PublicKeyCertificate(){}

		// The "type" information for the object. Gettors only.
		virtual const string& ResourceURI() const { return CLASS_URI; }
		static const string& ClassResourceURI() { return CLASS_URI; }
		virtual const string& XmlNamespace() const { return CLASS_NS; }
		virtual const string& XmlPrefix() const { return CLASS_NS_PREFIX; }
		virtual const string& ObjectType() const { return CLASS_NAME; }
		static const string& ClassObjectType() { return CLASS_NAME; }

		// Class representing AMT_PublicKeyCertificate keys
		class CimKeys : public CIM_Credential::CimKeys
		{
		public:
			// Key, Required, Within the scope of the instantiating Namespace, InstanceID opaquely and uniquely identifies an instance of this class.
			const string InstanceID() const
			{
				return GetKey("InstanceID");
			}

			// Key, Required, Within the scope of the instantiating Namespace, InstanceID opaquely and uniquely identifies an instance of this class.
			void InstanceID(const string &value)
			{
				SetOrAddKey("InstanceID", value);
			}

		};

		// class fields declarations

		// Optional, The X.509 Certificate blob.
		const Base64 X509Certificate() const;

		// Optional, The X.509 Certificate blob.
		void X509Certificate(const Base64 &value); 

		// Is true if the field X509Certificate exists in the current object, otherwise is false.
		bool X509CertificateExists() const;

		// Remove X509Certificate field.
		void RemoveX509Certificate(); 

		// Optional, For root certificate [that were added by AMT_PublicKeyManagementService.AddTrustedRootCertificate()]this property will be true.
		const bool TrustedRootCertficate() const;

		// Optional, For root certificate [that were added by AMT_PublicKeyManagementService.AddTrustedRootCertificate()]this property will be true.
		void TrustedRootCertficate(const bool value); 

		// Is true if the field TrustedRootCertficate exists in the current object, otherwise is false.
		bool TrustedRootCertficateExists() const;

		// Remove TrustedRootCertficate field.
		void RemoveTrustedRootCertficate(); 

		// Optional, The Issuer field of this certificate.
		const string Issuer() const;

		// Optional, The Issuer field of this certificate.
		void Issuer(const string &value); 

		// Is true if the field Issuer exists in the current object, otherwise is false.
		bool IssuerExists() const;

		// Remove Issuer field.
		void RemoveIssuer(); 

		// Optional, The Subject field of this certificate.
		const string Subject() const;

		// Optional, The Subject field of this certificate.
		void Subject(const string &value); 

		// Is true if the field Subject exists in the current object, otherwise is false.
		bool SubjectExists() const;

		// Remove Subject field.
		void RemoveSubject(); 

		 // Function used by the factory
		static CimBase *CreateFromCimObject(const CimObject &object);

		static vector<shared_ptr<AMT_PublicKeyCertificate> > Enumerate(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		// Overloaded delete which supplies the internal resourceURI
		static void Delete(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		using CimBase::Delete;

	protected:
		 // Protected constructor to be used by derived classes
		AMT_PublicKeyCertificate(ICimWsmanClient *client, const string &class_name,
			const string &class_ns, const string &prefix, const string &uri): CIM_Credential(client, class_name, class_ns, prefix, uri)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_Credential::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 5);
			}
		}
		 // Protected constructor which receives CimObject
		AMT_PublicKeyCertificate(const CimObject &object)
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
#endif // AMT_PUBLICKEYCERTIFICATE_H
