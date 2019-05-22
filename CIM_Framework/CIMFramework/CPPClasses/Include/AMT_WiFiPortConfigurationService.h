//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       AMT_WiFiPortConfigurationService.h
//
//  Contents:   AMT_WiFiPortConfigurationService provides management of the Wi-Fi network interfaces associated with a Wi-Fi network port.
//
//              This file was automatically generated from AMT_WiFiPortConfigurationService.mof,  version: 4.0.0
//
//----------------------------------------------------------------------------
#ifndef AMT_WIFIPORTCONFIGURATIONSERVICE_H
#define AMT_WIFIPORTCONFIGURATIONSERVICE_H 1
#include "CIM_WiFiEndpointSettings.h"
#include "CIM_IEEE8021xSettings.h"
#include "CIM_WiFiEndpointSettings.h"
#include "CIM_IEEE8021xSettings.h"
#include "CIM_NetworkPortConfigurationService.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	// AMT_WiFiPortConfigurationService provides management of the Wi-Fi network interfaces associated with a Wi-Fi network port.
	class CIMFRAMEWORK_API AMT_WiFiPortConfigurationService  : public CIM_NetworkPortConfigurationService
	{
	public:

		//Default constructor
		AMT_WiFiPortConfigurationService()
			: CIM_NetworkPortConfigurationService(NULL, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_NetworkPortConfigurationService::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 3);
			}
		}

		//constructor which receives WSMan client
		AMT_WiFiPortConfigurationService(ICimWsmanClient *client)
			: CIM_NetworkPortConfigurationService(client, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_NetworkPortConfigurationService::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 3);
			}
		}

		//Destructor
		virtual ~AMT_WiFiPortConfigurationService(){}

		// The "type" information for the object. Gettors only.
		virtual const string& ResourceURI() const { return CLASS_URI; }
		static const string& ClassResourceURI() { return CLASS_URI; }
		virtual const string& XmlNamespace() const { return CLASS_NS; }
		virtual const string& XmlPrefix() const { return CLASS_NS_PREFIX; }
		virtual const string& ObjectType() const { return CLASS_NAME; }
		static const string& ClassObjectType() { return CLASS_NAME; }

		// Class representing AMT_WiFiPortConfigurationService keys
		class CimKeys : public CIM_NetworkPortConfigurationService::CimKeys
		{
		public:
		};

		// class fields declarations

		// Optional, Administrator's policy regarding enablement of local profile synchronization.Remote profile synchronization is always enabled.
		const unsigned int localProfileSynchronizationEnabled() const;

		// Optional, Administrator's policy regarding enablement of local profile synchronization.Remote profile synchronization is always enabled.
		void localProfileSynchronizationEnabled(const unsigned int value); 

		// Is true if the field localProfileSynchronizationEnabled exists in the current object, otherwise is false.
		bool localProfileSynchronizationEnabledExists() const;

		// Remove localProfileSynchronizationEnabled field.
		void RemovelocalProfileSynchronizationEnabled(); 

		// Optional, The SSID of the Wireless network that was last connected in ME Control state
		const string LastConnectedSsidUnderMeControl() const;

		// Optional, The SSID of the Wireless network that was last connected in ME Control state
		void LastConnectedSsidUnderMeControl(const string &value); 

		// Is true if the field LastConnectedSsidUnderMeControl exists in the current object, otherwise is false.
		bool LastConnectedSsidUnderMeControlExists() const;

		// Remove LastConnectedSsidUnderMeControl field.
		void RemoveLastConnectedSsidUnderMeControl(); 

		// Optional, Setting Policy regarding no HOST CSME software.
		const unsigned int NoHostCsmeSoftwarePolicy() const;

		// Optional, Setting Policy regarding no HOST CSME software.
		void NoHostCsmeSoftwarePolicy(const unsigned int value); 

		// Is true if the field NoHostCsmeSoftwarePolicy exists in the current object, otherwise is false.
		bool NoHostCsmeSoftwarePolicyExists() const;

		// Remove NoHostCsmeSoftwarePolicy field.
		void RemoveNoHostCsmeSoftwarePolicy(); 

		//Input parameter for function AddWiFiSettings
		class CIMFRAMEWORK_API AddWiFiSettings_INPUT : public CimParam
		{
		public:
			// Class Constructor
			AddWiFiSettings_INPUT() : CimParam() {}

			// Class Destructor
			~AddWiFiSettings_INPUT(){}

			// Required, The endpoint to associate the new settings with
			void WiFiEndpoint(const CimReference &value); 

			// Required, a string encoded embedded instance of CIM_WiFiEndpointSettings. In a case of ambiguity (e.g. 2 contradictory properties were supplied), a valid profile will be created according to an internal precedence.
			void WiFiEndpointSettingsInput(const CIM_WiFiEndpointSettings &value); 

			// Optional, a string encoded embedded instance of CIM_IEEE8021xSettings. In a case of ambiguity (e.g. 2 contradictory properties were supplied), a valid profile will be created according to an internal precedence.
			void IEEE8021xSettingsInput(const CIM_IEEE8021xSettings &value); 

			// Optional, a Reference to an AMT_PublicKeyCertificate, which represents the client certificate
			void ClientCredential(const CimReference &value); 

			// Optional, a Reference to an AMT_PublicKeyCertificate, which represents the CA certificate
			void CACredential(const CimReference &value); 

			const VectorFieldData GetAllFields() const;
		private:
			static const CimFieldAttribute _metadata[];
		};

		//Output parameter for function AddWiFiSettings
		class CIMFRAMEWORK_API AddWiFiSettings_OUTPUT : public CimParam
		{
		public:
			// Class Constructor
			AddWiFiSettings_OUTPUT() : CimParam() {}

			// Class Destructor
			~AddWiFiSettings_OUTPUT(){}

			// class fields
			// A reference to a new CIM_WiFiEndpointSettings instance that shall be created by the method using the property values in WiFiEndpointSettingsInput.
			const CimReference WiFiEndpointSettings() const;
			bool WiFiEndpointSettingsExists() const;
			// A reference to a new CIM_IEEE8021xSettings instance that shall be created by the method using the property values in IEEE8021xSettingsInput
			const CimReference IEEE8021xSettings() const;
			bool IEEE8021xSettingsExists() const;
		private:
		};

		// Atomically creates an instance of CIM_WifiEndpointSettings from the embedded instance parameter and optionally an instance of CIM_IEEE8021xSettings from the embedded instance parameter (if provided), associates the CIM_WiFiEndpointSettings instance with the referenced instance of CIM_WiFiEndpoint using an instance of CIM_ElementSettingData optionally associates the newly created or referenced by parameter instance of CIM_IEEE8021xSettings with the instance of CIM_WiFiEndpointSettings using an instance of CIM_ConcreteComponent and optionally associates the referenced instance of AMT_PublicKeyCertificate (if provided) with the instance of CIM_IEEE8021xSettings (if provided) using an instance of CIM_CredentialContext.
		virtual unsigned int AddWiFiSettings(const AddWiFiSettings_INPUT &input, AddWiFiSettings_OUTPUT &output);

		//Input parameter for function UpdateWiFiSettings
		class CIMFRAMEWORK_API UpdateWiFiSettings_INPUT : public CimParam
		{
		public:
			// Class Constructor
			UpdateWiFiSettings_INPUT() : CimParam() {}

			// Class Destructor
			~UpdateWiFiSettings_INPUT(){}

			// Required, The endpoint settings to update
			void WiFiEndpointSettings(const CimReference &value); 

			// Required, a string encoded embedded instance of update parameters of CIM_WiFiEndpointSettings. Properties that aren't being changed should also be supplied. In a case of ambiguity (e.g. 2 contradictory properties were supplied), a valid profile will be created according to an internal precedence.
			void WiFiEndpointSettingsInput(const CIM_WiFiEndpointSettings &value); 

			// Optional, a string encoded embedded instance of update parameters of CIM_IEEE8021xSettings. Properties that aren't being changed should also be supplied. In a case of ambiguity (e.g. 2 contradictory properties were supplied), a valid profile will be created according to an internal precedence.
			void IEEE8021xSettingsInput(const CIM_IEEE8021xSettings &value); 

			// Optional, a Reference to an AMT_PublicKeyCertificate, which represents the client certificate
			void ClientCredential(const CimReference &value); 

			// Optional, a Reference to an AMT_PublicKeyCertificate, which represents the CA certificate
			void CACredential(const CimReference &value); 

			const VectorFieldData GetAllFields() const;
		private:
			static const CimFieldAttribute _metadata[];
		};

		//Output parameter for function UpdateWiFiSettings
		class CIMFRAMEWORK_API UpdateWiFiSettings_OUTPUT : public CimParam
		{
		public:
			// Class Constructor
			UpdateWiFiSettings_OUTPUT() : CimParam() {}

			// Class Destructor
			~UpdateWiFiSettings_OUTPUT(){}

			// class fields
			// A reference to the CIM_IEEE8021xSettings instance that shall be updated (or created) by the method using the property values in IEEE8021xSettingsInput
			const CimReference IEEE8021xSettings() const;
			bool IEEE8021xSettingsExists() const;
		private:
		};

		// Atomically updates the referenced instance of CIM_WifiEndpointSettings from the embedded instance of CIM_WiFiEndPointSettings and updates the referenced instance of CIM_IEEE8021xSettings from the embedded instance of CIM_IEEE8021xSettings.
		virtual unsigned int UpdateWiFiSettings(const UpdateWiFiSettings_INPUT &input, UpdateWiFiSettings_OUTPUT &output);

		// Deletes all the instances of CIM_WiFiEndpointSettings and CIM_IEEE8021xSettings that were created by AddWiFiSettings requests. Also deletes all the associations that reference the instances of CIM_WiFiEndpointSettings and CIM_IEEE8021xSettings that were deleted.
		virtual unsigned int DeleteAllITProfiles();

		// Deletes all the instances of CIM_WiFiEndpointSettings and CIM_IEEE8021xSettings that were created by local user applications. Also deletes all the associations that reference the instances of CIM_WiFiEndpointSettings and CIM_IEEE8021xSettings that were deleted.
		virtual unsigned int DeleteAllUserProfiles();

		//Input parameter for function SetApplicationRequestedRfKill
		class CIMFRAMEWORK_API SetApplicationRequestedRfKill_INPUT : public CimParam
		{
		public:
			// Class Constructor
			SetApplicationRequestedRfKill_INPUT() : CimParam() {}

			// Class Destructor
			~SetApplicationRequestedRfKill_INPUT(){}

			// Required, Indicates the adapter switching state
			void ApplicationRequestedRfKill(const bool value); 

			const VectorFieldData GetAllFields() const;
		private:
			static const CimFieldAttribute _metadata[];
		};

		// Notifies Intel(R) AMT WLAN that SW RF Kill is due to Host Adapter Switching
		virtual unsigned int SetApplicationRequestedRfKill(const SetApplicationRequestedRfKill_INPUT &input);

		 // Function used by the factory
		static CimBase *CreateFromCimObject(const CimObject &object);

		static vector<shared_ptr<AMT_WiFiPortConfigurationService> > Enumerate(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		// Overloaded delete which supplies the internal resourceURI
		static void Delete(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		using CimBase::Delete;

	protected:
		 // Protected constructor to be used by derived classes
		AMT_WiFiPortConfigurationService(ICimWsmanClient *client, const string &class_name,
			const string &class_ns, const string &prefix, const string &uri): CIM_NetworkPortConfigurationService(client, class_name, class_ns, prefix, uri)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_NetworkPortConfigurationService::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 3);
			}
		}
		 // Protected constructor which receives CimObject
		AMT_WiFiPortConfigurationService(const CimObject &object)
			: CIM_NetworkPortConfigurationService(object)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_NetworkPortConfigurationService::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 3);
			}
		}
		// Called by derived classes
		void SetMetaData(vector<CimFieldAttribute>& childMetaData)
		{
			CIM_NetworkPortConfigurationService::SetMetaData(childMetaData);
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
#endif // AMT_WIFIPORTCONFIGURATIONSERVICE_H
