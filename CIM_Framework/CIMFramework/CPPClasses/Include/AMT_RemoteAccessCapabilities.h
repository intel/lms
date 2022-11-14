//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       AMT_RemoteAccessCapabilities.h
//
//  Contents:   Represents the Remote Access feature capabilities.
//
//              This file was automatically generated from AMT_RemoteAccessCapabilities.mof,  version: 4.0.0
//
//----------------------------------------------------------------------------
#ifndef AMT_REMOTEACCESSCAPABILITIES_H
#define AMT_REMOTEACCESSCAPABILITIES_H 1
#include "CIM_Capabilities.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	// Represents the Remote Access feature capabilities.
	class CIMFRAMEWORK_API AMT_RemoteAccessCapabilities  : public CIM_Capabilities
	{
	public:

		//Default constructor
		AMT_RemoteAccessCapabilities()
			: CIM_Capabilities(NULL, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_Capabilities::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 4);
			}
		}

		//constructor which receives WSMan client
		AMT_RemoteAccessCapabilities(ICimWsmanClient *client)
			: CIM_Capabilities(client, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_Capabilities::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 4);
			}
		}

		//Destructor
		virtual ~AMT_RemoteAccessCapabilities(){}

		// The "type" information for the object. Gettors only.
		virtual const string& ResourceURI() const { return CLASS_URI; }
		static const string& ClassResourceURI() { return CLASS_URI; }
		virtual const string& XmlNamespace() const { return CLASS_NS; }
		virtual const string& XmlPrefix() const { return CLASS_NS_PREFIX; }
		virtual const string& ObjectType() const { return CLASS_NAME; }
		static const string& ClassObjectType() { return CLASS_NAME; }

		// Class representing AMT_RemoteAccessCapabilities keys
		class CimKeys : public CIM_Capabilities::CimKeys
		{
		public:
		};

		// class fields declarations

		// Optional, The maximum number of MpServers that can be configured on the Intel(R) AMT device for remote access.
		const unsigned int MaxTotalMpServers() const;

		// Optional, The maximum number of MpServers that can be configured on the Intel(R) AMT device for remote access.
		void MaxTotalMpServers(const unsigned int value); 

		// Is true if the field MaxTotalMpServers exists in the current object, otherwise is false.
		bool MaxTotalMpServersExists() const;

		// Remove MaxTotalMpServers field.
		void RemoveMaxTotalMpServers(); 

		// Optional, The maximum number of remote access policies that can be defined (altogether) on the Intel(R) AMT device.
		const unsigned int MaxTotalPolicies() const;

		// Optional, The maximum number of remote access policies that can be defined (altogether) on the Intel(R) AMT device.
		void MaxTotalPolicies(const unsigned int value); 

		// Is true if the field MaxTotalPolicies exists in the current object, otherwise is false.
		bool MaxTotalPoliciesExists() const;

		// Remove MaxTotalPolicies field.
		void RemoveMaxTotalPolicies(); 

		// Optional, The maximum number of MpServers that can be associated with a remote access policy for Intel(R) AMT device.
		const unsigned int MaxMpsPerPolicy() const;

		// Optional, The maximum number of MpServers that can be associated with a remote access policy for Intel(R) AMT device.
		void MaxMpsPerPolicy(const unsigned int value); 

		// Is true if the field MaxMpsPerPolicy exists in the current object, otherwise is false.
		bool MaxMpsPerPolicyExists() const;

		// Remove MaxMpsPerPolicy field.
		void RemoveMaxMpsPerPolicy(); 

		// Optional, The maximum number of Proxy Entry Points that can be configured on the Intel(R) AMT device for remote access.
		const unsigned int MaxTotalProxyEntryPoints() const;

		// Optional, The maximum number of Proxy Entry Points that can be configured on the Intel(R) AMT device for remote access.
		void MaxTotalProxyEntryPoints(const unsigned int value); 

		// Is true if the field MaxTotalProxyEntryPoints exists in the current object, otherwise is false.
		bool MaxTotalProxyEntryPointsExists() const;

		// Remove MaxTotalProxyEntryPoints field.
		void RemoveMaxTotalProxyEntryPoints(); 

		 // Function used by the factory
		static CimBase *CreateFromCimObject(const CimObject &object);

		static vector<shared_ptr<AMT_RemoteAccessCapabilities> > Enumerate(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		// Overloaded delete which supplies the internal resourceURI
		static void Delete(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		using CimBase::Delete;

	protected:
		 // Protected constructor to be used by derived classes
		AMT_RemoteAccessCapabilities(ICimWsmanClient *client, const string &class_name,
			const string &class_ns, const string &prefix, const string &uri): CIM_Capabilities(client, class_name, class_ns, prefix, uri)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_Capabilities::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 4);
			}
		}
		 // Protected constructor which receives CimObject
		AMT_RemoteAccessCapabilities(const CimObject &object)
			: CIM_Capabilities(object)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_Capabilities::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 4);
			}
		}
		// Called by derived classes
		void SetMetaData(vector<CimFieldAttribute>& childMetaData)
		{
			CIM_Capabilities::SetMetaData(childMetaData);
			CimBase::SetMetaData(childMetaData, _metadata, 4);
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
#endif // AMT_REMOTEACCESSCAPABILITIES_H
