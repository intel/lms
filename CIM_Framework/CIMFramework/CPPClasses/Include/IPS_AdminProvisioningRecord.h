//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       IPS_AdminProvisioningRecord.h
//
//  Contents:   The IPS_AdminProvisioningRecord provides information related to a single Intel (R) AMT provisioning occurrence that was performed using a Admin  control mode
//
//              This file was automatically generated from IPS_AdminProvisioningRecord.mof,  version: 7.0.0
//
//----------------------------------------------------------------------------
#ifndef IPS_ADMINPROVISIONINGRECORD_H
#define IPS_ADMINPROVISIONINGRECORD_H 1
#include "IPS_ProvisioningAuditRecord.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	// The IPS_AdminProvisioningRecord provides information related to a single Intel (R) AMT provisioning occurrence that was performed using a Admin  control mode
	class CIMFRAMEWORK_API IPS_AdminProvisioningRecord  : public IPS_ProvisioningAuditRecord
	{
	public:

		//Default constructor
		IPS_AdminProvisioningRecord()
			: IPS_ProvisioningAuditRecord(NULL, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				IPS_ProvisioningAuditRecord::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 8);
			}
		}

		//constructor which receives WSMan client
		IPS_AdminProvisioningRecord(ICimWsmanClient *client)
			: IPS_ProvisioningAuditRecord(client, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				IPS_ProvisioningAuditRecord::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 8);
			}
		}

		//Destructor
		virtual ~IPS_AdminProvisioningRecord(){}

		// The "type" information for the object. Gettors only.
		virtual const string& ResourceURI() const { return CLASS_URI; }
		static const string& ClassResourceURI() { return CLASS_URI; }
		virtual const string& XmlNamespace() const { return CLASS_NS; }
		virtual const string& XmlPrefix() const { return CLASS_NS_PREFIX; }
		virtual const string& ObjectType() const { return CLASS_NAME; }
		static const string& ClassObjectType() { return CLASS_NAME; }

		// Class representing IPS_AdminProvisioningRecord keys
		class CimKeys : public IPS_ProvisioningAuditRecord::CimKeys
		{
		public:
		};

		// class fields declarations

		// Optional, True, if the DNS Suffix used to authorize the provisioning entityWas set via the MEBx, false if value was read from the DHCP Server's option 15 value.
		const bool SecureDNS() const;

		// Optional, True, if the DNS Suffix used to authorize the provisioning entityWas set via the MEBx, false if value was read from the DHCP Server's option 15 value.
		void SecureDNS(const bool value); 

		// Is true if the field SecureDNS exists in the current object, otherwise is false.
		bool SecureDNSExists() const;

		// Remove SecureDNS field.
		void RemoveSecureDNS(); 

		// Optional, Specifies the CN value in the SSL certificate used for provisioning. 
		const string CertificateCN() const;

		// Optional, Specifies the CN value in the SSL certificate used for provisioning. 
		void CertificateCN(const string &value); 

		// Is true if the field CertificateCN exists in the current object, otherwise is false.
		bool CertificateCNExists() const;

		// Remove CertificateCN field.
		void RemoveCertificateCN(); 

		// Optional, The hash algorithm used for SelectedHashData. 
		const unsigned char SelectedHashType() const;

		// Optional, The hash algorithm used for SelectedHashData. 
		void SelectedHashType(const unsigned char &value); 

		// Is true if the field SelectedHashType exists in the current object, otherwise is false.
		bool SelectedHashTypeExists() const;

		// Remove SelectedHashType field.
		void RemoveSelectedHashType(); 

		// Optional, Hash data - The hash of the root certificate used in the configuration process.
		const Base64 SelectedHashData() const;

		// Optional, Hash data - The hash of the root certificate used in the configuration process.
		void SelectedHashData(const Base64 &value); 

		// Is true if the field SelectedHashData exists in the current object, otherwise is false.
		bool SelectedHashDataExists() const;

		// Remove SelectedHashData field.
		void RemoveSelectedHashData(); 

		// Optional, Notice: the values of this array are actually base64 encoded values. A list of a maximum of three serial numbers of the issuing CA certificates, starting with the leaf certificate. If the certificate chain has more than three certificates, this field contains the serial numbers of the last three certificates.
		const HexBinary CaCertificateSerials() const;

		// Optional, Notice: the values of this array are actually base64 encoded values. A list of a maximum of three serial numbers of the issuing CA certificates, starting with the leaf certificate. If the certificate chain has more than three certificates, this field contains the serial numbers of the last three certificates.
		void CaCertificateSerials(const HexBinary &value); 

		// Is true if the field CaCertificateSerials exists in the current object, otherwise is false.
		bool CaCertificateSerialsExists() const;

		// Remove CaCertificateSerials field.
		void RemoveCaCertificateSerials(); 

		// Optional, If additional CA serial numbers exist
		const bool AdditionalCaSerialNums() const;

		// Optional, If additional CA serial numbers exist
		void AdditionalCaSerialNums(const bool value); 

		// Is true if the field AdditionalCaSerialNums exists in the current object, otherwise is false.
		bool AdditionalCaSerialNumsExists() const;

		// Remove AdditionalCaSerialNums field.
		void RemoveAdditionalCaSerialNums(); 

		// Optional, True if the certificate hash data was set by OEM. 
		const bool HashIsOemDefault() const;

		// Optional, True if the certificate hash data was set by OEM. 
		void HashIsOemDefault(const bool value); 

		// Is true if the field HashIsOemDefault exists in the current object, otherwise is false.
		bool HashIsOemDefaultExists() const;

		// Remove HashIsOemDefault field.
		void RemoveHashIsOemDefault(); 

		// Optional, Whether EHBC provisioning was performed or not. 
		const unsigned char EHBCState() const;

		// Optional, Whether EHBC provisioning was performed or not. 
		void EHBCState(const unsigned char &value); 

		// Is true if the field EHBCState exists in the current object, otherwise is false.
		bool EHBCStateExists() const;

		// Remove EHBCState field.
		void RemoveEHBCState(); 

		 // Function used by the factory
		static CimBase *CreateFromCimObject(const CimObject &object);

		static vector<shared_ptr<IPS_AdminProvisioningRecord> > Enumerate(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		// Overloaded delete which supplies the internal resourceURI
		static void Delete(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		using CimBase::Delete;

	protected:
		 // Protected constructor to be used by derived classes
		IPS_AdminProvisioningRecord(ICimWsmanClient *client, const string &class_name,
			const string &class_ns, const string &prefix, const string &uri): IPS_ProvisioningAuditRecord(client, class_name, class_ns, prefix, uri)
		{
			if(_classMetaData.size() == 0)
			{
				IPS_ProvisioningAuditRecord::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 8);
			}
		}
		 // Protected constructor which receives CimObject
		IPS_AdminProvisioningRecord(const CimObject &object)
			: IPS_ProvisioningAuditRecord(object)
		{
			if(_classMetaData.size() == 0)
			{
				IPS_ProvisioningAuditRecord::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 8);
			}
		}
		// Called by derived classes
		void SetMetaData(vector<CimFieldAttribute>& childMetaData)
		{
			IPS_ProvisioningAuditRecord::SetMetaData(childMetaData);
			CimBase::SetMetaData(childMetaData, _metadata, 8);
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
#endif // IPS_ADMINPROVISIONINGRECORD_H
