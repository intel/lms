//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       AMT_SNMPEventSubscriber.h
//
//  Contents:   Represents a SNMP-events subscriber in the Intel(R) AMT system.
//
//              This file was automatically generated from AMT_SNMPEventSubscriber.mof,  version: 6.0.0
//
//----------------------------------------------------------------------------
#ifndef AMT_SNMPEVENTSUBSCRIBER_H
#define AMT_SNMPEVENTSUBSCRIBER_H 1
#include "AMT_EventSubscriber.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	// Represents a SNMP-events subscriber in the Intel(R) AMT system.
	class CIMFRAMEWORK_API AMT_SNMPEventSubscriber  : public AMT_EventSubscriber
	{
	public:

		//Default constructor
		AMT_SNMPEventSubscriber()
			: AMT_EventSubscriber(NULL, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				AMT_EventSubscriber::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 3);
			}
		}

		//constructor which receives WSMan client
		AMT_SNMPEventSubscriber(ICimWsmanClient *client)
			: AMT_EventSubscriber(client, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				AMT_EventSubscriber::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 3);
			}
		}

		//Destructor
		virtual ~AMT_SNMPEventSubscriber(){}

		// The "type" information for the object. Gettors only.
		virtual const string& ResourceURI() const { return CLASS_URI; }
		static const string& ClassResourceURI() { return CLASS_URI; }
		virtual const string& XmlNamespace() const { return CLASS_NS; }
		virtual const string& XmlPrefix() const { return CLASS_NS_PREFIX; }
		virtual const string& ObjectType() const { return CLASS_NAME; }
		static const string& ClassObjectType() { return CLASS_NAME; }

		// Class representing AMT_SNMPEventSubscriber keys
		class CimKeys : public AMT_EventSubscriber::CimKeys
		{
		public:
		};

		// class fields declarations

		// Required, Associates a Subscription to its filter.
		const unsigned char PolicyID() const;

		// Required, Associates a Subscription to its filter.
		void PolicyID(const unsigned char &value); 

		// Is true if the field PolicyID exists in the current object, otherwise is false.
		bool PolicyIDExists() const;

		// Remove PolicyID field.
		void RemovePolicyID(); 

		// Optional, A community string to send with the trap operation.
		const string CommunityString() const;

		// Optional, A community string to send with the trap operation.
		void CommunityString(const string &value); 

		// Is true if the field CommunityString exists in the current object, otherwise is false.
		bool CommunityStringExists() const;

		// Remove CommunityString field.
		void RemoveCommunityString(); 

		 // Function used by the factory
		static CimBase *CreateFromCimObject(const CimObject &object);

		static vector<shared_ptr<AMT_SNMPEventSubscriber> > Enumerate(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		// Overloaded delete which supplies the internal resourceURI
		static void Delete(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		using CimBase::Delete;

	protected:
		 // Protected constructor to be used by derived classes
		AMT_SNMPEventSubscriber(ICimWsmanClient *client, const string &class_name,
			const string &class_ns, const string &prefix, const string &uri): AMT_EventSubscriber(client, class_name, class_ns, prefix, uri)
		{
			if(_classMetaData.size() == 0)
			{
				AMT_EventSubscriber::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 3);
			}
		}
		 // Protected constructor which receives CimObject
		AMT_SNMPEventSubscriber(const CimObject &object)
			: AMT_EventSubscriber(object)
		{
			if(_classMetaData.size() == 0)
			{
				AMT_EventSubscriber::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 3);
			}
		}
		// Called by derived classes
		void SetMetaData(vector<CimFieldAttribute>& childMetaData)
		{
			AMT_EventSubscriber::SetMetaData(childMetaData);
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
#endif // AMT_SNMPEVENTSUBSCRIBER_H
