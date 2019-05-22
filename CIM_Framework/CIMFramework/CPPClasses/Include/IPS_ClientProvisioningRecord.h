//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       IPS_ClientProvisioningRecord.h
//
//  Contents:   The IPS_ClientProvisioningRecord provides information related to a single Intel (R) AMT provisioning occurrence that was performed using a host based provisioning operation in client control mode.
//
//              This file was automatically generated from IPS_ClientProvisioningRecord.mof,  version: 7.0.0
//
//----------------------------------------------------------------------------
#ifndef IPS_CLIENTPROVISIONINGRECORD_H
#define IPS_CLIENTPROVISIONINGRECORD_H 1
#include "IPS_ProvisioningAuditRecord.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	// The IPS_ClientProvisioningRecord provides information related to a single Intel (R) AMT provisioning occurrence that was performed using a host based provisioning operation in client control mode.
	class CIMFRAMEWORK_API IPS_ClientProvisioningRecord  : public IPS_ProvisioningAuditRecord
	{
	public:

		//Default constructor
		IPS_ClientProvisioningRecord()
			: IPS_ProvisioningAuditRecord(NULL, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				IPS_ProvisioningAuditRecord::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 2);
			}
		}

		//constructor which receives WSMan client
		IPS_ClientProvisioningRecord(ICimWsmanClient *client)
			: IPS_ProvisioningAuditRecord(client, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				IPS_ProvisioningAuditRecord::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 2);
			}
		}

		//Destructor
		virtual ~IPS_ClientProvisioningRecord(){}

		// The "type" information for the object. Gettors only.
		virtual const string& ResourceURI() const { return CLASS_URI; }
		static const string& ClassResourceURI() { return CLASS_URI; }
		virtual const string& XmlNamespace() const { return CLASS_NS; }
		virtual const string& XmlPrefix() const { return CLASS_NS_PREFIX; }
		virtual const string& ObjectType() const { return CLASS_NAME; }
		static const string& ClassObjectType() { return CLASS_NAME; }

		// Class representing IPS_ClientProvisioningRecord keys
		class CimKeys : public IPS_ProvisioningAuditRecord::CimKeys
		{
		public:
		};

		// class fields declarations

		// Optional, The Hashing Algorithm used to generate the ProvCertificateHash field
		const unsigned char HashAlgorithm() const;

		// Optional, The Hashing Algorithm used to generate the ProvCertificateHash field
		void HashAlgorithm(const unsigned char &value); 

		// Is true if the field HashAlgorithm exists in the current object, otherwise is false.
		bool HashAlgorithmExists() const;

		// Remove HashAlgorithm field.
		void RemoveHashAlgorithm(); 

		// Optional, A Hash value of the certificate that was used to digitally sign the provisioning operationA Value of NULL indicates the caller did not sign the provisioning operation.
		const Base64 ProvCertificateHash() const;

		// Optional, A Hash value of the certificate that was used to digitally sign the provisioning operationA Value of NULL indicates the caller did not sign the provisioning operation.
		void ProvCertificateHash(const Base64 &value); 

		// Is true if the field ProvCertificateHash exists in the current object, otherwise is false.
		bool ProvCertificateHashExists() const;

		// Remove ProvCertificateHash field.
		void RemoveProvCertificateHash(); 

		 // Function used by the factory
		static CimBase *CreateFromCimObject(const CimObject &object);

		static vector<shared_ptr<IPS_ClientProvisioningRecord> > Enumerate(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		// Overloaded delete which supplies the internal resourceURI
		static void Delete(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		using CimBase::Delete;

	protected:
		 // Protected constructor to be used by derived classes
		IPS_ClientProvisioningRecord(ICimWsmanClient *client, const string &class_name,
			const string &class_ns, const string &prefix, const string &uri): IPS_ProvisioningAuditRecord(client, class_name, class_ns, prefix, uri)
		{
			if(_classMetaData.size() == 0)
			{
				IPS_ProvisioningAuditRecord::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 2);
			}
		}
		 // Protected constructor which receives CimObject
		IPS_ClientProvisioningRecord(const CimObject &object)
			: IPS_ProvisioningAuditRecord(object)
		{
			if(_classMetaData.size() == 0)
			{
				IPS_ProvisioningAuditRecord::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 2);
			}
		}
		// Called by derived classes
		void SetMetaData(vector<CimFieldAttribute>& childMetaData)
		{
			IPS_ProvisioningAuditRecord::SetMetaData(childMetaData);
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
#endif // IPS_CLIENTPROVISIONINGRECORD_H
