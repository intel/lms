//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       AMT_AgentPresenceCapabilities.h
//
//  Contents:   Represents the Agent Presence feature capabilities.
//
//              This file was automatically generated from AMT_AgentPresenceCapabilities.mof,  version: 4.0.0
//
//----------------------------------------------------------------------------
#ifndef AMT_AGENTPRESENCECAPABILITIES_H
#define AMT_AGENTPRESENCECAPABILITIES_H 1
#include "CIM_Capabilities.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	// Represents the Agent Presence feature capabilities.
	class CIMFRAMEWORK_API AMT_AgentPresenceCapabilities  : public CIM_Capabilities
	{
	public:

		//Default constructor
		AMT_AgentPresenceCapabilities()
			: CIM_Capabilities(NULL, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_Capabilities::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 4);
			}
		}

		//constructor which receives WSMan client
		AMT_AgentPresenceCapabilities(ICimWsmanClient *client)
			: CIM_Capabilities(client, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_Capabilities::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 4);
			}
		}

		//Destructor
		virtual ~AMT_AgentPresenceCapabilities(){}

		// The "type" information for the object. Gettors only.
		virtual const string& ResourceURI() const { return CLASS_URI; }
		static const string& ClassResourceURI() { return CLASS_URI; }
		virtual const string& XmlNamespace() const { return CLASS_NS; }
		virtual const string& XmlPrefix() const { return CLASS_NS_PREFIX; }
		virtual const string& ObjectType() const { return CLASS_NAME; }
		static const string& ClassObjectType() { return CLASS_NAME; }

		// Class representing AMT_AgentPresenceCapabilities keys
		class CimKeys : public CIM_Capabilities::CimKeys
		{
		public:
		};

		// class fields declarations

		// Optional, The maximum number of agents that can be registered on the Intel(R) AMT device.
		const unsigned int MaxTotalAgents() const;

		// Optional, The maximum number of agents that can be registered on the Intel(R) AMT device.
		void MaxTotalAgents(const unsigned int value); 

		// Is true if the field MaxTotalAgents exists in the current object, otherwise is false.
		bool MaxTotalAgentsExists() const;

		// Remove MaxTotalAgents field.
		void RemoveMaxTotalAgents(); 

		// Optional, The maximum number of actions that can be defined (altogether) on the Intel(R) AMT device.
		const unsigned int MaxTotalActions() const;

		// Optional, The maximum number of actions that can be defined (altogether) on the Intel(R) AMT device.
		void MaxTotalActions(const unsigned int value); 

		// Is true if the field MaxTotalActions exists in the current object, otherwise is false.
		bool MaxTotalActionsExists() const;

		// Remove MaxTotalActions field.
		void RemoveMaxTotalActions(); 

		// Optional, The minimum number of actions that is guaranteed for every Agent on the Intel(R) AMT device.
		const unsigned int MinGuaranteedActionListSize() const;

		// Optional, The minimum number of actions that is guaranteed for every Agent on the Intel(R) AMT device.
		void MinGuaranteedActionListSize(const unsigned int value); 

		// Is true if the field MinGuaranteedActionListSize exists in the current object, otherwise is false.
		bool MinGuaranteedActionListSizeExists() const;

		// Remove MinGuaranteedActionListSize field.
		void RemoveMinGuaranteedActionListSize(); 

		// Optional, The maximum number of agents that registered on the Intel AMT device and configured with EAC action.
		const unsigned int MaxEacAgents() const;

		// Optional, The maximum number of agents that registered on the Intel AMT device and configured with EAC action.
		void MaxEacAgents(const unsigned int value); 

		// Is true if the field MaxEacAgents exists in the current object, otherwise is false.
		bool MaxEacAgentsExists() const;

		// Remove MaxEacAgents field.
		void RemoveMaxEacAgents(); 

		 // Function used by the factory
		static CimBase *CreateFromCimObject(const CimObject &object);

		static vector<shared_ptr<AMT_AgentPresenceCapabilities> > Enumerate(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		// Overloaded delete which supplies the internal resourceURI
		static void Delete(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		using CimBase::Delete;

	protected:
		 // Protected constructor to be used by derived classes
		AMT_AgentPresenceCapabilities(ICimWsmanClient *client, const string &class_name,
			const string &class_ns, const string &prefix, const string &uri): CIM_Capabilities(client, class_name, class_ns, prefix, uri)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_Capabilities::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 4);
			}
		}
		 // Protected constructor which receives CimObject
		AMT_AgentPresenceCapabilities(const CimObject &object)
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
#endif // AMT_AGENTPRESENCECAPABILITIES_H
