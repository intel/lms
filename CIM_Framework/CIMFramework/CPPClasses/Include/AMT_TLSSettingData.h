//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       AMT_TLSSettingData.h
//
//  Contents:   The AMT_TLSSettingData class represents configuration-related and operational parameters for the TLS service in the Intel(R) AMT.
//
//              This file was automatically generated from AMT_TLSSettingData.mof,  version: 3.0.0
//
//----------------------------------------------------------------------------
#ifndef AMT_TLSSETTINGDATA_H
#define AMT_TLSSETTINGDATA_H 1
#include "CIM_SettingData.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	// The AMT_TLSSettingData class represents configuration-related and operational parameters for the TLS service in the Intel(R) AMT.
	class CIMFRAMEWORK_API AMT_TLSSettingData  : public CIM_SettingData
	{
	public:

		//Default constructor
		AMT_TLSSettingData()
			: CIM_SettingData(NULL, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_SettingData::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 7);
			}
		}

		//constructor which receives WSMan client
		AMT_TLSSettingData(ICimWsmanClient *client)
			: CIM_SettingData(client, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_SettingData::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 7);
			}
		}

		//Destructor
		virtual ~AMT_TLSSettingData(){}

		// The "type" information for the object. Gettors only.
		virtual const string& ResourceURI() const { return CLASS_URI; }
		static const string& ClassResourceURI() { return CLASS_URI; }
		virtual const string& XmlNamespace() const { return CLASS_NS; }
		virtual const string& XmlPrefix() const { return CLASS_NS_PREFIX; }
		virtual const string& ObjectType() const { return CLASS_NAME; }
		static const string& ClassObjectType() { return CLASS_NAME; }

		// Class representing AMT_TLSSettingData keys
		class CimKeys : public CIM_SettingData::CimKeys
		{
		public:
		};

		// class fields declarations

		// Optional, Adminstrator-settable property that determines whether or not mutual authentication is used at the TLS layer is used on the associated service access point. If False, then only the server authenticates itself at the TLS layer.
		const bool MutualAuthentication() const;

		// Optional, Adminstrator-settable property that determines whether or not mutual authentication is used at the TLS layer is used on the associated service access point. If False, then only the server authenticates itself at the TLS layer.
		void MutualAuthentication(const bool value); 

		// Is true if the field MutualAuthentication exists in the current object, otherwise is false.
		bool MutualAuthenticationExists() const;

		// Remove MutualAuthentication field.
		void RemoveMutualAuthentication(); 

		// Required, Administrator-settable property that determines whether or not TLS is used on the associated service access point.
		const bool Enabled() const;

		// Required, Administrator-settable property that determines whether or not TLS is used on the associated service access point.
		void Enabled(const bool value); 

		// Is true if the field Enabled exists in the current object, otherwise is false.
		bool EnabledExists() const;

		// Remove Enabled field.
		void RemoveEnabled(); 

		// Optional, An array of strings, used to validate the CN subfield of the subject field in X.509 certificates presented to Intel(R) AMT in the TLS handshake. This value must comply with the requirements of RFC 1035.
		const vector<string> TrustedCN() const;

		// Optional, An array of strings, used to validate the CN subfield of the subject field in X.509 certificates presented to Intel(R) AMT in the TLS handshake. This value must comply with the requirements of RFC 1035.
		void TrustedCN(const vector<string> &value); 

		// Is true if the field TrustedCN exists in the current object, otherwise is false.
		bool TrustedCNExists() const;

		// Remove TrustedCN field.
		void RemoveTrustedCN(); 

		// Optional, The Issuer Name field in the X.509 certificate.
		const string X509IssuerName() const;

		// Optional, The Issuer Name field in the X.509 certificate.
		void X509IssuerName(const string &value); 

		// Is true if the field X509IssuerName exists in the current object, otherwise is false.
		bool X509IssuerNameExists() const;

		// Remove X509IssuerName field.
		void RemoveX509IssuerName(); 

		// Optional, The Serial Numebr field in the X.509 certificate.
		const Base64 X509SerialNumber() const;

		// Optional, The Serial Numebr field in the X.509 certificate.
		void X509SerialNumber(const Base64 &value); 

		// Is true if the field X509SerialNumber exists in the current object, otherwise is false.
		bool X509SerialNumberExists() const;

		// Remove X509SerialNumber field.
		void RemoveX509SerialNumber(); 

		// Optional, This setting defines once TLS is enabled and configured whether non-secure EOI/WSMAN connections are still accepted by FW on ports 16992 and 623. If AcceptNonSecureConnections is set to TRUE then non-secure connections are still accepted. If set to FALSE then non-secure connections are rejected. This setting may be set per interface for the local and network interfaces.
		const bool AcceptNonSecureConnections() const;

		// Optional, This setting defines once TLS is enabled and configured whether non-secure EOI/WSMAN connections are still accepted by FW on ports 16992 and 623. If AcceptNonSecureConnections is set to TRUE then non-secure connections are still accepted. If set to FALSE then non-secure connections are rejected. This setting may be set per interface for the local and network interfaces.
		void AcceptNonSecureConnections(const bool value); 

		// Is true if the field AcceptNonSecureConnections exists in the current object, otherwise is false.
		bool AcceptNonSecureConnectionsExists() const;

		// Remove AcceptNonSecureConnections field.
		void RemoveAcceptNonSecureConnections(); 

		// Optional, This setting define whether a non secure - aka direct tcpis supported or not - not supported from RPL on.This setting is read only.
		const bool NonSecureConnectionsSupported() const;

		// Optional, This setting define whether a non secure - aka direct tcpis supported or not - not supported from RPL on.This setting is read only.
		void NonSecureConnectionsSupported(const bool value); 

		// Is true if the field NonSecureConnectionsSupported exists in the current object, otherwise is false.
		bool NonSecureConnectionsSupportedExists() const;

		// Remove NonSecureConnectionsSupported field.
		void RemoveNonSecureConnectionsSupported(); 

		 // Function used by the factory
		static CimBase *CreateFromCimObject(const CimObject &object);

		static vector<shared_ptr<AMT_TLSSettingData> > Enumerate(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		// Overloaded delete which supplies the internal resourceURI
		static void Delete(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		using CimBase::Delete;

	protected:
		 // Protected constructor to be used by derived classes
		AMT_TLSSettingData(ICimWsmanClient *client, const string &class_name,
			const string &class_ns, const string &prefix, const string &uri): CIM_SettingData(client, class_name, class_ns, prefix, uri)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_SettingData::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 7);
			}
		}
		 // Protected constructor which receives CimObject
		AMT_TLSSettingData(const CimObject &object)
			: CIM_SettingData(object)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_SettingData::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 7);
			}
		}
		// Called by derived classes
		void SetMetaData(vector<CimFieldAttribute>& childMetaData)
		{
			CIM_SettingData::SetMetaData(childMetaData);
			CimBase::SetMetaData(childMetaData, _metadata, 7);
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
#endif // AMT_TLSSETTINGDATA_H
