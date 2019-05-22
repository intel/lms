//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       AMT_RemoteAccessPolicyRule.h
//
//  Contents:   Represents a Remote Access policy. The policy defines a condition that will trigger the establishment of a tunnel between the Intel(R) AMT subsystem and a remote MpServer. The policy also defines parameters for the connection such as TunnelLifeTime in seconds.
//
//              This file was automatically generated from AMT_RemoteAccessPolicyRule.mof,  version: 4.0.0
//
//----------------------------------------------------------------------------
#ifndef AMT_REMOTEACCESSPOLICYRULE_H
#define AMT_REMOTEACCESSPOLICYRULE_H 1
#include "CIM_PolicyRule.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	// Represents a Remote Access policy. The policy defines a condition that will trigger the establishment of a tunnel between the Intel(R) AMT subsystem and a remote MpServer. The policy also defines parameters for the connection such as TunnelLifeTime in seconds.
	class CIMFRAMEWORK_API AMT_RemoteAccessPolicyRule  : public CIM_PolicyRule
	{
	public:

		//Default constructor
		AMT_RemoteAccessPolicyRule()
			: CIM_PolicyRule(NULL, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_PolicyRule::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 3);
			}
		}

		//constructor which receives WSMan client
		AMT_RemoteAccessPolicyRule(ICimWsmanClient *client)
			: CIM_PolicyRule(client, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_PolicyRule::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 3);
			}
		}

		//Destructor
		virtual ~AMT_RemoteAccessPolicyRule(){}

		// The "type" information for the object. Gettors only.
		virtual const string& ResourceURI() const { return CLASS_URI; }
		static const string& ClassResourceURI() { return CLASS_URI; }
		virtual const string& XmlNamespace() const { return CLASS_NS; }
		virtual const string& XmlPrefix() const { return CLASS_NS_PREFIX; }
		virtual const string& ObjectType() const { return CLASS_NAME; }
		static const string& ClassObjectType() { return CLASS_NAME; }

		// Class representing AMT_RemoteAccessPolicyRule keys
		class CimKeys : public CIM_PolicyRule::CimKeys
		{
		public:
		};

		// class fields declarations

		// Required, The event that will trigger the establishment of the remote connection to the MpServer.
		const unsigned short Trigger() const;

		// Required, The event that will trigger the establishment of the remote connection to the MpServer.
		void Trigger(const unsigned short value); 

		// Is true if the field Trigger exists in the current object, otherwise is false.
		bool TriggerExists() const;

		// Remove Trigger field.
		void RemoveTrigger(); 

		// Required, Defines the tunnel lifetime in seconds, 0 means no lifetime- the tunnel should stay open until it is closed by CloseRemoteAccessConnection or when a different policy with higher priority needs to be processed.
		const unsigned int TunnelLifeTime() const;

		// Required, Defines the tunnel lifetime in seconds, 0 means no lifetime- the tunnel should stay open until it is closed by CloseRemoteAccessConnection or when a different policy with higher priority needs to be processed.
		void TunnelLifeTime(const unsigned int value); 

		// Is true if the field TunnelLifeTime exists in the current object, otherwise is false.
		bool TunnelLifeTimeExists() const;

		// Remove TunnelLifeTime field.
		void RemoveTunnelLifeTime(); 

		// Optional, Data associated with the policy, up to 32 bytes. The data should be in a network order. The extended data for a policy with a periodic trigger contains first a periodic type and after that the data for that type. For periodic type 0 [Interval - The CIRA connection will be established every fixed number of seconds] - the data should include a uint32 value that indicates the time period in seconds between tunnel establishments. For periodic type 1 [Daily - The CIRA connection will be established every day in a specific pre-defined time (hour and minutes)] - the data should include two uint32 values which define the wanted hour of the day and minutes of that hour. For the other triggers extended data is not defined and not needed. The length and data should be zero.
		const Base64 ExtendedData() const;

		// Optional, Data associated with the policy, up to 32 bytes. The data should be in a network order. The extended data for a policy with a periodic trigger contains first a periodic type and after that the data for that type. For periodic type 0 [Interval - The CIRA connection will be established every fixed number of seconds] - the data should include a uint32 value that indicates the time period in seconds between tunnel establishments. For periodic type 1 [Daily - The CIRA connection will be established every day in a specific pre-defined time (hour and minutes)] - the data should include two uint32 values which define the wanted hour of the day and minutes of that hour. For the other triggers extended data is not defined and not needed. The length and data should be zero.
		void ExtendedData(const Base64 &value); 

		// Is true if the field ExtendedData exists in the current object, otherwise is false.
		bool ExtendedDataExists() const;

		// Remove ExtendedData field.
		void RemoveExtendedData(); 

		 // Function used by the factory
		static CimBase *CreateFromCimObject(const CimObject &object);

		static vector<shared_ptr<AMT_RemoteAccessPolicyRule> > Enumerate(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		// Overloaded delete which supplies the internal resourceURI
		static void Delete(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		using CimBase::Delete;

	protected:
		 // Protected constructor to be used by derived classes
		AMT_RemoteAccessPolicyRule(ICimWsmanClient *client, const string &class_name,
			const string &class_ns, const string &prefix, const string &uri): CIM_PolicyRule(client, class_name, class_ns, prefix, uri)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_PolicyRule::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 3);
			}
		}
		 // Protected constructor which receives CimObject
		AMT_RemoteAccessPolicyRule(const CimObject &object)
			: CIM_PolicyRule(object)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_PolicyRule::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 3);
			}
		}
		// Called by derived classes
		void SetMetaData(vector<CimFieldAttribute>& childMetaData)
		{
			CIM_PolicyRule::SetMetaData(childMetaData);
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
#endif // AMT_REMOTEACCESSPOLICYRULE_H
