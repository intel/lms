//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       IPS_HostIPSettings.h
//
//  Contents:   The IPS_HostIpSettings class represents the IP settings of the host computer.It will use to synchronize IP between host and ME if needed.
//
//              This file was automatically generated from IPS_HostIPSettings.mof,  version: 7.0.0
//
//----------------------------------------------------------------------------
#ifndef IPS_HOSTIPSETTINGS_H
#define IPS_HOSTIPSETTINGS_H 1
#include "CIM_SettingData.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	// The IPS_HostIpSettings class represents the IP settings of the host computer.It will use to synchronize IP between host and ME if needed.
	class CIMFRAMEWORK_API IPS_HostIPSettings  : public CIM_SettingData
	{
	public:

		//Default constructor
		IPS_HostIPSettings()
			: CIM_SettingData(NULL, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_SettingData::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 6);
			}
		}

		//constructor which receives WSMan client
		IPS_HostIPSettings(ICimWsmanClient *client)
			: CIM_SettingData(client, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_SettingData::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 6);
			}
		}

		//Destructor
		virtual ~IPS_HostIPSettings(){}

		// The "type" information for the object. Gettors only.
		virtual const string& ResourceURI() const { return CLASS_URI; }
		static const string& ClassResourceURI() { return CLASS_URI; }
		virtual const string& XmlNamespace() const { return CLASS_NS; }
		virtual const string& XmlPrefix() const { return CLASS_NS_PREFIX; }
		virtual const string& ObjectType() const { return CLASS_NAME; }
		static const string& ClassObjectType() { return CLASS_NAME; }

		// Class representing IPS_HostIPSettings keys
		class CimKeys : public CIM_SettingData::CimKeys
		{
		public:
		};

		// class fields declarations

		// Optional, Indicates whether DHCP is in use.
		const bool DHCPEnabled() const;

		// Optional, Indicates whether DHCP is in use.
		void DHCPEnabled(const bool value); 

		// Is true if the field DHCPEnabled exists in the current object, otherwise is false.
		bool DHCPEnabledExists() const;

		// Remove DHCPEnabled field.
		void RemoveDHCPEnabled(); 

		// Optional, String representation of IP address. Represents static IP of host.
		const string IpAddress() const;

		// Optional, String representation of IP address. Represents static IP of host.
		void IpAddress(const string &value); 

		// Is true if the field IpAddress exists in the current object, otherwise is false.
		bool IpAddressExists() const;

		// Remove IpAddress field.
		void RemoveIpAddress(); 

		// Optional, Subnet mask in a string format.For example: 255.255.0.0.Represents mask of host IP.
		const string SubnetMask() const;

		// Optional, Subnet mask in a string format.For example: 255.255.0.0.Represents mask of host IP.
		void SubnetMask(const string &value); 

		// Is true if the field SubnetMask exists in the current object, otherwise is false.
		bool SubnetMaskExists() const;

		// Remove SubnetMask field.
		void RemoveSubnetMask(); 

		// Optional, Default Gateway in a string format. For example: 10.12.232.1Represents Default Gateway of host IP.
		const string DefaultGateway() const;

		// Optional, Default Gateway in a string format. For example: 10.12.232.1Represents Default Gateway of host IP.
		void DefaultGateway(const string &value); 

		// Is true if the field DefaultGateway exists in the current object, otherwise is false.
		bool DefaultGatewayExists() const;

		// Remove DefaultGateway field.
		void RemoveDefaultGateway(); 

		// Optional, Primary DNS in a string format. For example: 10.12.232.1.Represents Primary DNS of host IP.
		const string PrimaryDNS() const;

		// Optional, Primary DNS in a string format. For example: 10.12.232.1.Represents Primary DNS of host IP.
		void PrimaryDNS(const string &value); 

		// Is true if the field PrimaryDNS exists in the current object, otherwise is false.
		bool PrimaryDNSExists() const;

		// Remove PrimaryDNS field.
		void RemovePrimaryDNS(); 

		// Optional, Secondary DNS in a string format. For example: 10.12.232.1.Represents Secondary DNS of host IP.
		const string SecondaryDNS() const;

		// Optional, Secondary DNS in a string format. For example: 10.12.232.1.Represents Secondary DNS of host IP.
		void SecondaryDNS(const string &value); 

		// Is true if the field SecondaryDNS exists in the current object, otherwise is false.
		bool SecondaryDNSExists() const;

		// Remove SecondaryDNS field.
		void RemoveSecondaryDNS(); 

		 // Function used by the factory
		static CimBase *CreateFromCimObject(const CimObject &object);

		static vector<shared_ptr<IPS_HostIPSettings> > Enumerate(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		// Overloaded delete which supplies the internal resourceURI
		static void Delete(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		using CimBase::Delete;

	protected:
		 // Protected constructor to be used by derived classes
		IPS_HostIPSettings(ICimWsmanClient *client, const string &class_name,
			const string &class_ns, const string &prefix, const string &uri): CIM_SettingData(client, class_name, class_ns, prefix, uri)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_SettingData::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 6);
			}
		}
		 // Protected constructor which receives CimObject
		IPS_HostIPSettings(const CimObject &object)
			: CIM_SettingData(object)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_SettingData::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 6);
			}
		}
		// Called by derived classes
		void SetMetaData(vector<CimFieldAttribute>& childMetaData)
		{
			CIM_SettingData::SetMetaData(childMetaData);
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
#endif // IPS_HOSTIPSETTINGS_H
