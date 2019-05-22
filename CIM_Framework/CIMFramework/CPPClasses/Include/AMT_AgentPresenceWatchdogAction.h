//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       AMT_AgentPresenceWatchdogAction.h
//
//  Contents:   Represents an action which is triggered on an application watchdog state transition.
//
//              This file was automatically generated from AMT_AgentPresenceWatchdogAction.mof,  version: 4.0.0
//
//----------------------------------------------------------------------------
#ifndef AMT_AGENTPRESENCEWATCHDOGACTION_H
#define AMT_AGENTPRESENCEWATCHDOGACTION_H 1
#include "CIM_PolicyAction.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	// Represents an action which is triggered on an application watchdog state transition.
	class CIMFRAMEWORK_API AMT_AgentPresenceWatchdogAction  : public CIM_PolicyAction
	{
	public:

		//Default constructor
		AMT_AgentPresenceWatchdogAction()
			: CIM_PolicyAction(NULL, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_PolicyAction::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 2);
			}
		}

		//constructor which receives WSMan client
		AMT_AgentPresenceWatchdogAction(ICimWsmanClient *client)
			: CIM_PolicyAction(client, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_PolicyAction::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 2);
			}
		}

		//Destructor
		virtual ~AMT_AgentPresenceWatchdogAction(){}

		// The "type" information for the object. Gettors only.
		virtual const string& ResourceURI() const { return CLASS_URI; }
		static const string& ClassResourceURI() { return CLASS_URI; }
		virtual const string& XmlNamespace() const { return CLASS_NS; }
		virtual const string& XmlPrefix() const { return CLASS_NS_PREFIX; }
		virtual const string& ObjectType() const { return CLASS_NAME; }
		static const string& ClassObjectType() { return CLASS_NAME; }

		// Class representing AMT_AgentPresenceWatchdogAction keys
		class CimKeys : public CIM_PolicyAction::CimKeys
		{
		public:
		};

		// class fields declarations

		// Optional, Specifies whether an Event should be created in the Event Manager on the application watchdog transition.
		const bool EventOnTransition() const;

		// Optional, Specifies whether an Event should be created in the Event Manager on the application watchdog transition.
		void EventOnTransition(const bool value); 

		// Is true if the field EventOnTransition exists in the current object, otherwise is false.
		bool EventOnTransitionExists() const;

		// Remove EventOnTransition field.
		void RemoveEventOnTransition(); 

		// Optional, A System Defense Action which may be applied, on the application watchdog transition. Note that all Agent Presence instances share the same list of policies, which can be activated.
		const unsigned short ActionSd() const;

		// Optional, A System Defense Action which may be applied, on the application watchdog transition. Note that all Agent Presence instances share the same list of policies, which can be activated.
		void ActionSd(const unsigned short value); 

		// Is true if the field ActionSd exists in the current object, otherwise is false.
		bool ActionSdExists() const;

		// Remove ActionSd field.
		void RemoveActionSd(); 

		//Output parameter for function GetActionEac
		class CIMFRAMEWORK_API GetActionEac_OUTPUT : public CimParam
		{
		public:
			// Class Constructor
			GetActionEac_OUTPUT() : CimParam() {}

			// Class Destructor
			~GetActionEac_OUTPUT(){}

			// class fields
			// A boolean flag indicating whether this action is defined as an EAC action.
			const bool ActionEac() const;
			bool ActionEacExists() const;
		private:
		};

		// This method allows to determine if this action is defined as an EAC action. If this method returns TRUE: 1. Information about this agent is included in an Intel(R) AMT EAC posture. This happens if at least one transition is defined as TRUE for this agent. Posture information includes current state and state counters showing how many times each state was entered. 2. When this specific state transition occurs, an avent is generated to indicate that Intel(R) AMT posture has changed.
		virtual unsigned int GetActionEac(GetActionEac_OUTPUT &output);

		 // Function used by the factory
		static CimBase *CreateFromCimObject(const CimObject &object);

		static vector<shared_ptr<AMT_AgentPresenceWatchdogAction> > Enumerate(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		// Overloaded delete which supplies the internal resourceURI
		static void Delete(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		using CimBase::Delete;

	protected:
		 // Protected constructor to be used by derived classes
		AMT_AgentPresenceWatchdogAction(ICimWsmanClient *client, const string &class_name,
			const string &class_ns, const string &prefix, const string &uri): CIM_PolicyAction(client, class_name, class_ns, prefix, uri)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_PolicyAction::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 2);
			}
		}
		 // Protected constructor which receives CimObject
		AMT_AgentPresenceWatchdogAction(const CimObject &object)
			: CIM_PolicyAction(object)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_PolicyAction::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 2);
			}
		}
		// Called by derived classes
		void SetMetaData(vector<CimFieldAttribute>& childMetaData)
		{
			CIM_PolicyAction::SetMetaData(childMetaData);
			CimBase::SetMetaData(childMetaData, _metadata, 2);
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
#endif // AMT_AGENTPRESENCEWATCHDOGACTION_H
