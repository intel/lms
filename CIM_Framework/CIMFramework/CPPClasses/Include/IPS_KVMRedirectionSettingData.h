//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       IPS_KVMRedirectionSettingData.h
//
//  Contents:   The IPS_KVMRedirectionSettingData class represents configuration-related and operational parameters for the KVM redirection service in the Intel(R) AMT.
//
//              This file was automatically generated from IPS_KVMRedirectionSettingData.mof,  version: 6.0.0
//
//----------------------------------------------------------------------------
#ifndef IPS_KVMREDIRECTIONSETTINGDATA_H
#define IPS_KVMREDIRECTIONSETTINGDATA_H 1
#include "CIM_SettingData.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	// The IPS_KVMRedirectionSettingData class represents configuration-related and operational parameters for the KVM redirection service in the Intel(R) AMT.
	class CIMFRAMEWORK_API IPS_KVMRedirectionSettingData  : public CIM_SettingData
	{
	public:

		//Default constructor
		IPS_KVMRedirectionSettingData()
			: CIM_SettingData(NULL, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_SettingData::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 8);
			}
		}

		//constructor which receives WSMan client
		IPS_KVMRedirectionSettingData(ICimWsmanClient *client)
			: CIM_SettingData(client, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_SettingData::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 8);
			}
		}

		//Destructor
		virtual ~IPS_KVMRedirectionSettingData(){}

		// The "type" information for the object. Gettors only.
		virtual const string& ResourceURI() const { return CLASS_URI; }
		static const string& ClassResourceURI() { return CLASS_URI; }
		virtual const string& XmlNamespace() const { return CLASS_NS; }
		virtual const string& XmlPrefix() const { return CLASS_NS_PREFIX; }
		virtual const string& ObjectType() const { return CLASS_NAME; }
		static const string& ClassObjectType() { return CLASS_NAME; }

		// Class representing IPS_KVMRedirectionSettingData keys
		class CimKeys : public CIM_SettingData::CimKeys
		{
		public:
		};

		// class fields declarations

		// Optional, Indicates whether the KVM feature is disabled by the BIOS's MEBx settings.If the KVM feature is disabled, it cannot be enabled by any other means.
		const bool EnabledByMEBx() const;

		// Optional, Indicates whether the KVM feature is disabled by the BIOS's MEBx settings.If the KVM feature is disabled, it cannot be enabled by any other means.
		void EnabledByMEBx(const bool value); 

		// Is true if the field EnabledByMEBx exists in the current object, otherwise is false.
		bool EnabledByMEBxExists() const;

		// Remove EnabledByMEBx field.
		void RemoveEnabledByMEBx(); 

		// Optional, Indicates whether the KVM feature is working in Back-to-Back Framebuffer mode so that the next Framebuffer is sent without waiting for the request from the KVM Viewer. 
		const bool BackToBackFbMode() const;

		// Optional, Indicates whether the KVM feature is working in Back-to-Back Framebuffer mode so that the next Framebuffer is sent without waiting for the request from the KVM Viewer. 
		void BackToBackFbMode(const bool value); 

		// Is true if the field BackToBackFbMode exists in the current object, otherwise is false.
		bool BackToBackFbModeExists() const;

		// Remove BackToBackFbMode field.
		void RemoveBackToBackFbMode(); 

		// Optional, Port 5900 is used for interoperability with the RFB protocol.Ports 16994/16995 are used to transport RFB over Intel rediection protocol and includes various authentication modes which are supported by the Intel redirection protocol. This attribute states if 5900 port is open, and allowed to communicate with the service.
		const bool Is5900PortEnabled() const;

		// Optional, Port 5900 is used for interoperability with the RFB protocol.Ports 16994/16995 are used to transport RFB over Intel rediection protocol and includes various authentication modes which are supported by the Intel redirection protocol. This attribute states if 5900 port is open, and allowed to communicate with the service.
		void Is5900PortEnabled(const bool value); 

		// Is true if the field Is5900PortEnabled exists in the current object, otherwise is false.
		bool Is5900PortEnabledExists() const;

		// Remove Is5900PortEnabled field.
		void RemoveIs5900PortEnabled(); 

		// Optional, Is opt in (user consent for KVM session) enabled/disabled.
		const bool OptInPolicy() const;

		// Optional, Is opt in (user consent for KVM session) enabled/disabled.
		void OptInPolicy(const bool value); 

		// Is true if the field OptInPolicy exists in the current object, otherwise is false.
		bool OptInPolicyExists() const;

		// Remove OptInPolicy field.
		void RemoveOptInPolicy(); 

		// Optional, Defines the maximum time between session request and session establishment (when user discloses the PIN on the Sprite to the remote operator and the operator enters the PIN). When timeout expires, all displays of Sprite notifications are cancelled. Intel(R) recommends a minimum of 5 minutes (300 seconds)
		const unsigned short OptInPolicyTimeout() const;

		// Optional, Defines the maximum time between session request and session establishment (when user discloses the PIN on the Sprite to the remote operator and the operator enters the PIN). When timeout expires, all displays of Sprite notifications are cancelled. Intel(R) recommends a minimum of 5 minutes (300 seconds)
		void OptInPolicyTimeout(const unsigned short value); 

		// Is true if the field OptInPolicyTimeout exists in the current object, otherwise is false.
		bool OptInPolicyTimeoutExists() const;

		// Remove OptInPolicyTimeout field.
		void RemoveOptInPolicyTimeout(); 

		// Optional, Session timeout for TCP session close.
		const unsigned short SessionTimeout() const;

		// Optional, Session timeout for TCP session close.
		void SessionTimeout(const unsigned short value); 

		// Is true if the field SessionTimeout exists in the current object, otherwise is false.
		bool SessionTimeoutExists() const;

		// Remove SessionTimeout field.
		void RemoveSessionTimeout(); 

		// Optional, User defined password for native RFB Authentication.This is a write-only field, an empty string is returned when instance is read. When writing, an empty string or lack of field will be ignored. The password must be 8 characters long and contain at least 1 capital letter, regular letter, digit and special character. RFB password can't accept the characters: '"'   ','  ':'
		const string RFBPassword() const;

		// Optional, User defined password for native RFB Authentication.This is a write-only field, an empty string is returned when instance is read. When writing, an empty string or lack of field will be ignored. The password must be 8 characters long and contain at least 1 capital letter, regular letter, digit and special character. RFB password can't accept the characters: '"'   ','  ':'
		void RFBPassword(const string &value); 

		// Is true if the field RFBPassword exists in the current object, otherwise is false.
		bool RFBPasswordExists() const;

		// Remove RFBPassword field.
		void RemoveRFBPassword(); 

		// Optional, Default screen to use on KVM session
		const unsigned char DefaultScreen() const;

		// Optional, Default screen to use on KVM session
		void DefaultScreen(const unsigned char &value); 

		// Is true if the field DefaultScreen exists in the current object, otherwise is false.
		bool DefaultScreenExists() const;

		// Remove DefaultScreen field.
		void RemoveDefaultScreen(); 

		// This API terminates an active KVM session. it may be issues by a local tool acting on behalf of the local user which desires to terminate a remote session due to privacy concerns.
		virtual unsigned int TerminateSession();

		 // Function used by the factory
		static CimBase *CreateFromCimObject(const CimObject &object);

		static vector<shared_ptr<IPS_KVMRedirectionSettingData> > Enumerate(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		// Overloaded delete which supplies the internal resourceURI
		static void Delete(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		using CimBase::Delete;

	protected:
		 // Protected constructor to be used by derived classes
		IPS_KVMRedirectionSettingData(ICimWsmanClient *client, const string &class_name,
			const string &class_ns, const string &prefix, const string &uri): CIM_SettingData(client, class_name, class_ns, prefix, uri)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_SettingData::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 8);
			}
		}
		 // Protected constructor which receives CimObject
		IPS_KVMRedirectionSettingData(const CimObject &object)
			: CIM_SettingData(object)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_SettingData::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 8);
			}
		}
		// Called by derived classes
		void SetMetaData(vector<CimFieldAttribute>& childMetaData)
		{
			CIM_SettingData::SetMetaData(childMetaData);
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
#endif // IPS_KVMREDIRECTIONSETTINGDATA_H
