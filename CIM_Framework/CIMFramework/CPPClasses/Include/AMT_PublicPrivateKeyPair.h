//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       AMT_PublicPrivateKeyPair.h
//
//  Contents:   This class represents a public-private key in the Intel(R) AMT CertStore.
//
//              This file was automatically generated from AMT_PublicPrivateKeyPair.mof,  version: 6.0.0
//
//----------------------------------------------------------------------------
#ifndef AMT_PUBLICPRIVATEKEYPAIR_H
#define AMT_PUBLICPRIVATEKEYPAIR_H 1
#include "CIM_Credential.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	// This class represents a public-private key in the Intel(R) AMT CertStore.
	class CIMFRAMEWORK_API AMT_PublicPrivateKeyPair  : public CIM_Credential
	{
	public:

		//Default constructor
		AMT_PublicPrivateKeyPair()
			: CIM_Credential(NULL, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_Credential::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 2);
			}
		}

		//constructor which receives WSMan client
		AMT_PublicPrivateKeyPair(ICimWsmanClient *client)
			: CIM_Credential(client, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_Credential::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 2);
			}
		}

		//Destructor
		virtual ~AMT_PublicPrivateKeyPair(){}

		// The "type" information for the object. Gettors only.
		virtual const string& ResourceURI() const { return CLASS_URI; }
		static const string& ClassResourceURI() { return CLASS_URI; }
		virtual const string& XmlNamespace() const { return CLASS_NS; }
		virtual const string& XmlPrefix() const { return CLASS_NS_PREFIX; }
		virtual const string& ObjectType() const { return CLASS_NAME; }
		static const string& ClassObjectType() { return CLASS_NAME; }

		// Class representing AMT_PublicPrivateKeyPair keys
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

		// Optional, RSA Key encoded as DES PKCS#1. The Exponent (E) is 65537 (0x010001).When this structure is used as an output parameter (GET or PULL method),only the public section of the key is exported.
		const Base64 DERKey() const;

		// Optional, RSA Key encoded as DES PKCS#1. The Exponent (E) is 65537 (0x010001).When this structure is used as an output parameter (GET or PULL method),only the public section of the key is exported.
		void DERKey(const Base64 &value); 

		// Is true if the field DERKey exists in the current object, otherwise is false.
		bool DERKeyExists() const;

		// Remove DERKey field.
		void RemoveDERKey(); 

		 // Function used by the factory
		static CimBase *CreateFromCimObject(const CimObject &object);

		static vector<shared_ptr<AMT_PublicPrivateKeyPair> > Enumerate(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		// Overloaded delete which supplies the internal resourceURI
		static void Delete(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		using CimBase::Delete;

	protected:
		 // Protected constructor to be used by derived classes
		AMT_PublicPrivateKeyPair(ICimWsmanClient *client, const string &class_name,
			const string &class_ns, const string &prefix, const string &uri): CIM_Credential(client, class_name, class_ns, prefix, uri)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_Credential::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 2);
			}
		}
		 // Protected constructor which receives CimObject
		AMT_PublicPrivateKeyPair(const CimObject &object)
			: CIM_Credential(object)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_Credential::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 2);
			}
		}
		// Called by derived classes
		void SetMetaData(vector<CimFieldAttribute>& childMetaData)
		{
			CIM_Credential::SetMetaData(childMetaData);
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
#endif // AMT_PUBLICPRIVATEKEYPAIR_H
