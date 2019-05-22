//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       AMT_ProvisioningCertificateHash.h
//
//  Contents:   A class derived from Credential that describes provisioning certificate hash entry.
//
//              This file was automatically generated from AMT_ProvisioningCertificateHash.mof,  version: 6.0.0
//
//----------------------------------------------------------------------------
#ifndef AMT_PROVISIONINGCERTIFICATEHASH_H
#define AMT_PROVISIONINGCERTIFICATEHASH_H 1
#include "CIM_Credential.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	// A class derived from Credential that describes provisioning certificate hash entry.
	class CIMFRAMEWORK_API AMT_ProvisioningCertificateHash  : public CIM_Credential
	{
	public:

		//Default constructor
		AMT_ProvisioningCertificateHash()
			: CIM_Credential(NULL, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_Credential::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 6);
			}
		}

		//constructor which receives WSMan client
		AMT_ProvisioningCertificateHash(ICimWsmanClient *client)
			: CIM_Credential(client, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_Credential::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 6);
			}
		}

		//Destructor
		virtual ~AMT_ProvisioningCertificateHash(){}

		// The "type" information for the object. Gettors only.
		virtual const string& ResourceURI() const { return CLASS_URI; }
		static const string& ClassResourceURI() { return CLASS_URI; }
		virtual const string& XmlNamespace() const { return CLASS_NS; }
		virtual const string& XmlPrefix() const { return CLASS_NS_PREFIX; }
		virtual const string& ObjectType() const { return CLASS_NAME; }
		static const string& ClassObjectType() { return CLASS_NAME; }

		// Class representing AMT_ProvisioningCertificateHash keys
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

		// Optional, Indicates whether this entry is a factory default. This property is read-only.
		const bool IsDefault() const;

		// Optional, Indicates whether this entry is a factory default. This property is read-only.
		void IsDefault(const bool value); 

		// Is true if the field IsDefault exists in the current object, otherwise is false.
		bool IsDefaultExists() const;

		// Remove IsDefault field.
		void RemoveIsDefault(); 

		// Optional, The hash type.
		const unsigned char HashType() const;

		// Optional, The hash type.
		void HashType(const unsigned char &value); 

		// Is true if the field HashType exists in the current object, otherwise is false.
		bool HashTypeExists() const;

		// Remove HashType field.
		void RemoveHashType(); 

		// Optional, Hash value (length depending on hash type). This property is read-only.
		const Base64 HashData() const;

		// Optional, Hash value (length depending on hash type). This property is read-only.
		void HashData(const Base64 &value); 

		// Is true if the field HashData exists in the current object, otherwise is false.
		bool HashDataExists() const;

		// Remove HashData field.
		void RemoveHashData(); 

		// Optional, Indicates whether this certificate hash is in use
		const bool Enabled() const;

		// Optional, Indicates whether this certificate hash is in use
		void Enabled(const bool value); 

		// Is true if the field Enabled exists in the current object, otherwise is false.
		bool EnabledExists() const;

		// Remove Enabled field.
		void RemoveEnabled(); 

		 // Function used by the factory
		static CimBase *CreateFromCimObject(const CimObject &object);

		static vector<shared_ptr<AMT_ProvisioningCertificateHash> > Enumerate(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		// Overloaded delete which supplies the internal resourceURI
		static void Delete(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		using CimBase::Delete;

	protected:
		 // Protected constructor to be used by derived classes
		AMT_ProvisioningCertificateHash(ICimWsmanClient *client, const string &class_name,
			const string &class_ns, const string &prefix, const string &uri): CIM_Credential(client, class_name, class_ns, prefix, uri)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_Credential::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 6);
			}
		}
		 // Protected constructor which receives CimObject
		AMT_ProvisioningCertificateHash(const CimObject &object)
			: CIM_Credential(object)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_Credential::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 6);
			}
		}
		// Called by derived classes
		void SetMetaData(vector<CimFieldAttribute>& childMetaData)
		{
			CIM_Credential::SetMetaData(childMetaData);
			CimBase::SetMetaData(childMetaData, _metadata, 6);
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
#endif // AMT_PROVISIONINGCERTIFICATEHASH_H
