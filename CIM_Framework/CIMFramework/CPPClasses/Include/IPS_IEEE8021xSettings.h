//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       IPS_IEEE8021xSettings.h
//
//  Contents:   
//
//              This file was automatically generated from IPS_IEEE8021xSettings.mof,  version: 8.0.0
//
//----------------------------------------------------------------------------
#ifndef IPS_IEEE8021XSETTINGS_H
#define IPS_IEEE8021XSETTINGS_H 1
#include "CIM_IEEE8021xSettings.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	// 
	class CIMFRAMEWORK_API IPS_IEEE8021xSettings  : public CIM_IEEE8021xSettings
	{
	public:

		//Default constructor
		IPS_IEEE8021xSettings()
			: CIM_IEEE8021xSettings(NULL, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_IEEE8021xSettings::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 3);
			}
		}

		//constructor which receives WSMan client
		IPS_IEEE8021xSettings(ICimWsmanClient *client)
			: CIM_IEEE8021xSettings(client, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_IEEE8021xSettings::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 3);
			}
		}

		//Destructor
		virtual ~IPS_IEEE8021xSettings(){}

		// The "type" information for the object. Gettors only.
		virtual const string& ResourceURI() const { return CLASS_URI; }
		static const string& ClassResourceURI() { return CLASS_URI; }
		virtual const string& XmlNamespace() const { return CLASS_NS; }
		virtual const string& XmlPrefix() const { return CLASS_NS_PREFIX; }
		virtual const string& ObjectType() const { return CLASS_NAME; }
		static const string& ClassObjectType() { return CLASS_NAME; }

		// Class representing IPS_IEEE8021xSettings keys
		class CimKeys : public CIM_IEEE8021xSettings::CimKeys
		{
		public:
		};

		// class fields declarations

		// Optional, Timeout in seconds, in which the Intel(R) AMT will hold an authenticated 802.1X session. During the defined period, Intel(R) AMT manages the 802.1X negotiation while a PXE boot takes place. After the timeout, control of the negotiation passes to the host. 
		// The maximum value is 86400 seconds (one day).
		// A value of 0 disables the feature. 
		// If this optional value is omitted, Intel(R) AMT sets a default value of 120 seconds.
		const unsigned int PxeTimeout() const;

		// Optional, Timeout in seconds, in which the Intel(R) AMT will hold an authenticated 802.1X session. During the defined period, Intel(R) AMT manages the 802.1X negotiation while a PXE boot takes place. After the timeout, control of the negotiation passes to the host. 
		// The maximum value is 86400 seconds (one day).
		// A value of 0 disables the feature. 
		// If this optional value is omitted, Intel(R) AMT sets a default value of 120 seconds.
		void PxeTimeout(const unsigned int value); 

		// Is true if the field PxeTimeout exists in the current object, otherwise is false.
		bool PxeTimeoutExists() const;

		// Remove PxeTimeout field.
		void RemovePxeTimeout(); 

		// Optional, Indicates the activity setting of the 802.1X module in S0 state. The default value for this property is 'true'.
		const bool AvailableInS0() const;

		// Optional, Indicates the activity setting of the 802.1X module in S0 state. The default value for this property is 'true'.
		void AvailableInS0(const bool value); 

		// Is true if the field AvailableInS0 exists in the current object, otherwise is false.
		bool AvailableInS0Exists() const;

		// Remove AvailableInS0 field.
		void RemoveAvailableInS0(); 

		// Required, Indicates whether the 802.1x profile is enabled.
		const unsigned int Enabled() const;

		// Required, Indicates whether the 802.1x profile is enabled.
		void Enabled(const unsigned int value); 

		// Is true if the field Enabled exists in the current object, otherwise is false.
		bool EnabledExists() const;

		// Remove Enabled field.
		void RemoveEnabled(); 

		//Input parameter for function SetCertificates
		class CIMFRAMEWORK_API SetCertificates_INPUT : public CimParam
		{
		public:
			// Class Constructor
			SetCertificates_INPUT() : CimParam() {}

			// Class Destructor
			~SetCertificates_INPUT(){}

			// Optional, The trusted root CA that should be used while verifying the server certificate.
			void ServerCertificateIssuer(const CimReference &value); 

			// Optional, The client certificate that should be used by the profile.
			void ClientCertificate(const CimReference &value); 

			const VectorFieldData GetAllFields() const;
		private:
			static const CimFieldAttribute _metadata[];
		};

		// Set the certificates associated with the 8021X profile.
		virtual unsigned int SetCertificates(const SetCertificates_INPUT &input);

		 // Function used by the factory
		static CimBase *CreateFromCimObject(const CimObject &object);

		static vector<shared_ptr<IPS_IEEE8021xSettings> > Enumerate(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		// Overloaded delete which supplies the internal resourceURI
		static void Delete(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		using CimBase::Delete;

	protected:
		 // Protected constructor to be used by derived classes
		IPS_IEEE8021xSettings(ICimWsmanClient *client, const string &class_name,
			const string &class_ns, const string &prefix, const string &uri): CIM_IEEE8021xSettings(client, class_name, class_ns, prefix, uri)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_IEEE8021xSettings::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 3);
			}
		}
		 // Protected constructor which receives CimObject
		IPS_IEEE8021xSettings(const CimObject &object)
			: CIM_IEEE8021xSettings(object)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_IEEE8021xSettings::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 3);
			}
		}
		// Called by derived classes
		void SetMetaData(vector<CimFieldAttribute>& childMetaData)
		{
			CIM_IEEE8021xSettings::SetMetaData(childMetaData);
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
#endif // IPS_IEEE8021XSETTINGS_H
