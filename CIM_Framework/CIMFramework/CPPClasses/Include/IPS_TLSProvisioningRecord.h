//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       IPS_TLSProvisioningRecord.h
//
//  Contents:   The IPS_TLSProvisioningRecord provides information related to a single Intel (R) AMT provisioning occurrence that was performed using a TLS provisioning method - PSK or PKI
//
//              This file was automatically generated from IPS_TLSProvisioningRecord.mof,  version: 7.0.0
//
//----------------------------------------------------------------------------
#ifndef IPS_TLSPROVISIONINGRECORD_H
#define IPS_TLSPROVISIONINGRECORD_H 1
#include "IPS_ProvisioningAuditRecord.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	// The IPS_TLSProvisioningRecord provides information related to a single Intel (R) AMT provisioning occurrence that was performed using a TLS provisioning method - PSK or PKI
	class CIMFRAMEWORK_API IPS_TLSProvisioningRecord  : public IPS_ProvisioningAuditRecord
	{
	public:

		//Default constructor
		IPS_TLSProvisioningRecord()
			: IPS_ProvisioningAuditRecord(NULL, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				IPS_ProvisioningAuditRecord::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 11);
			}
		}

		//constructor which receives WSMan client
		IPS_TLSProvisioningRecord(ICimWsmanClient *client)
			: IPS_ProvisioningAuditRecord(client, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				IPS_ProvisioningAuditRecord::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 11);
			}
		}

		//Destructor
		virtual ~IPS_TLSProvisioningRecord(){}

		// The "type" information for the object. Gettors only.
		virtual const string& ResourceURI() const { return CLASS_URI; }
		static const string& ClassResourceURI() { return CLASS_URI; }
		virtual const string& XmlNamespace() const { return CLASS_NS; }
		virtual const string& XmlPrefix() const { return CLASS_NS_PREFIX; }
		virtual const string& ObjectType() const { return CLASS_NAME; }
		static const string& ClassObjectType() { return CLASS_NAME; }

		// Class representing IPS_TLSProvisioningRecord keys
		class CimKeys : public IPS_ProvisioningAuditRecord::CimKeys
		{
		public:
		};

		// class fields declarations

		// Optional, Specifies the TLS provisioning method that was used to provision Intel(R) AMT
		const unsigned char ProvisioningTLSMode() const;

		// Optional, Specifies the TLS provisioning method that was used to provision Intel(R) AMT
		void ProvisioningTLSMode(const unsigned char &value); 

		// Is true if the field ProvisioningTLSMode exists in the current object, otherwise is false.
		bool ProvisioningTLSModeExists() const;

		// Remove ProvisioningTLSMode field.
		void RemoveProvisioningTLSMode(); 

		// Optional, True, if the DNS Suffix used to authorize the provisioning entityWas set via the MEBx, false if value was read from the DHCP Server's option 15 valueValid only if TLSProvisioningMethod="TLS-PKI"
		const bool SecureDNS() const;

		// Optional, True, if the DNS Suffix used to authorize the provisioning entityWas set via the MEBx, false if value was read from the DHCP Server's option 15 valueValid only if TLSProvisioningMethod="TLS-PKI"
		void SecureDNS(const bool value); 

		// Is true if the field SecureDNS exists in the current object, otherwise is false.
		bool SecureDNSExists() const;

		// Remove SecureDNS field.
		void RemoveSecureDNS(); 

		// Optional, True if provisioning was initiated by a host agent. Valid only if TLSProvisioningMethod="TLS-PKI"
		const bool HostInitiated() const;

		// Optional, True if provisioning was initiated by a host agent. Valid only if TLSProvisioningMethod="TLS-PKI"
		void HostInitiated(const bool value); 

		// Is true if the field HostInitiated exists in the current object, otherwise is false.
		bool HostInitiatedExists() const;

		// Remove HostInitiated field.
		void RemoveHostInitiated(); 

		// Optional, Specifies the CN value in the SSL certificate used by the provisioning server. Valid only if TLSProvisioningMethod="TLS-PKI"
		const string ProvServerFQDN() const;

		// Optional, Specifies the CN value in the SSL certificate used by the provisioning server. Valid only if TLSProvisioningMethod="TLS-PKI"
		void ProvServerFQDN(const string &value); 

		// Is true if the field ProvServerFQDN exists in the current object, otherwise is false.
		bool ProvServerFQDNExists() const;

		// Remove ProvServerFQDN field.
		void RemoveProvServerFQDN(); 

		// Optional, The hash algorithm used for SelectedHashData. Valid only if TLSProvisioningMethod="TLS-PKI"
		const unsigned char SelectedHashType() const;

		// Optional, The hash algorithm used for SelectedHashData. Valid only if TLSProvisioningMethod="TLS-PKI"
		void SelectedHashType(const unsigned char &value); 

		// Is true if the field SelectedHashType exists in the current object, otherwise is false.
		bool SelectedHashTypeExists() const;

		// Remove SelectedHashType field.
		void RemoveSelectedHashType(); 

		// Optional, Hash data - The hash of the root certificate used in the configuration process. Valid only if TLSProvisioningMethod="TLS-PKI"
		const Base64 SelectedHashData() const;

		// Optional, Hash data - The hash of the root certificate used in the configuration process. Valid only if TLSProvisioningMethod="TLS-PKI"
		void SelectedHashData(const Base64 &value); 

		// Is true if the field SelectedHashData exists in the current object, otherwise is false.
		bool SelectedHashDataExists() const;

		// Remove SelectedHashData field.
		void RemoveSelectedHashData(); 

		// Optional, Notice: the values of this array are actually base64 encoded values. A list of a maximum of three serial numbers of the issuing CA certificates. If the certificate chain has more than three certificates, this field contains the serial numbers of the last three certificates. This field has a value only if TLSProvisioningMethod="TLS-PKI"
		const HexBinary CaCertificateSerials() const;

		// Optional, Notice: the values of this array are actually base64 encoded values. A list of a maximum of three serial numbers of the issuing CA certificates. If the certificate chain has more than three certificates, this field contains the serial numbers of the last three certificates. This field has a value only if TLSProvisioningMethod="TLS-PKI"
		void CaCertificateSerials(const HexBinary &value); 

		// Is true if the field CaCertificateSerials exists in the current object, otherwise is false.
		bool CaCertificateSerialsExists() const;

		// Remove CaCertificateSerials field.
		void RemoveCaCertificateSerials(); 

		// Optional, Valid only if TLSProvisioningMethod="TLS-PKI"
		const bool AdditionalCaSerialNums() const;

		// Optional, Valid only if TLSProvisioningMethod="TLS-PKI"
		void AdditionalCaSerialNums(const bool value); 

		// Is true if the field AdditionalCaSerialNums exists in the current object, otherwise is false.
		bool AdditionalCaSerialNumsExists() const;

		// Remove AdditionalCaSerialNums field.
		void RemoveAdditionalCaSerialNums(); 

		// Optional, True if the certificate hash data was set by OEM. Valid only if TLSProvisioningMethod="TLS-PKI"
		const bool HashIsOemDefault() const;

		// Optional, True if the certificate hash data was set by OEM. Valid only if TLSProvisioningMethod="TLS-PKI"
		void HashIsOemDefault(const bool value); 

		// Is true if the field HashIsOemDefault exists in the current object, otherwise is false.
		bool HashIsOemDefaultExists() const;

		// Remove HashIsOemDefault field.
		void RemoveHashIsOemDefault(); 

		// Optional, Specifies whether the SSL cert validity period was successfully verified.The host RTC is used as the reference clock. Note that Intel(R) AMT will not cause a Provisioning operation to fail even if the certificate has expired.Valid only if TLSProvisioningMethod="TLS-PKI"
		const bool IsTimeValid() const;

		// Optional, Specifies whether the SSL cert validity period was successfully verified.The host RTC is used as the reference clock. Note that Intel(R) AMT will not cause a Provisioning operation to fail even if the certificate has expired.Valid only if TLSProvisioningMethod="TLS-PKI"
		void IsTimeValid(const bool value); 

		// Is true if the field IsTimeValid exists in the current object, otherwise is false.
		bool IsTimeValidExists() const;

		// Remove IsTimeValid field.
		void RemoveIsTimeValid(); 

		// Optional, The IP address of the Provisioning server that issued the AMT_SetupAndConfigurationService.CommitChanges() command, both IPv4 & IPv6 addresses are supported.
		const string ProvServerIP() const;

		// Optional, The IP address of the Provisioning server that issued the AMT_SetupAndConfigurationService.CommitChanges() command, both IPv4 & IPv6 addresses are supported.
		void ProvServerIP(const string &value); 

		// Is true if the field ProvServerIP exists in the current object, otherwise is false.
		bool ProvServerIPExists() const;

		// Remove ProvServerIP field.
		void RemoveProvServerIP(); 

		 // Function used by the factory
		static CimBase *CreateFromCimObject(const CimObject &object);

		static vector<shared_ptr<IPS_TLSProvisioningRecord> > Enumerate(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		// Overloaded delete which supplies the internal resourceURI
		static void Delete(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		using CimBase::Delete;

	protected:
		 // Protected constructor to be used by derived classes
		IPS_TLSProvisioningRecord(ICimWsmanClient *client, const string &class_name,
			const string &class_ns, const string &prefix, const string &uri): IPS_ProvisioningAuditRecord(client, class_name, class_ns, prefix, uri)
		{
			if(_classMetaData.size() == 0)
			{
				IPS_ProvisioningAuditRecord::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 11);
			}
		}
		 // Protected constructor which receives CimObject
		IPS_TLSProvisioningRecord(const CimObject &object)
			: IPS_ProvisioningAuditRecord(object)
		{
			if(_classMetaData.size() == 0)
			{
				IPS_ProvisioningAuditRecord::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 11);
			}
		}
		// Called by derived classes
		void SetMetaData(vector<CimFieldAttribute>& childMetaData)
		{
			IPS_ProvisioningAuditRecord::SetMetaData(childMetaData);
			CimBase::SetMetaData(childMetaData, _metadata, 11);
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
#endif // IPS_TLSPROVISIONINGRECORD_H
