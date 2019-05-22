//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       AMT_AgentPresenceWatchdog.h
//
//  Contents:   Represents the monitoring state associated with a single agent.
//
//              This file was automatically generated from AMT_AgentPresenceWatchdog.mof,  version: 6.0.0
//
//----------------------------------------------------------------------------
#ifndef AMT_AGENTPRESENCEWATCHDOG_H
#define AMT_AGENTPRESENCEWATCHDOG_H 1
#include "CIM_Watchdog.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	// Represents the monitoring state associated with a single agent.
	class CIMFRAMEWORK_API AMT_AgentPresenceWatchdog  : public CIM_Watchdog
	{
	public:

		//Default constructor
		AMT_AgentPresenceWatchdog()
			: CIM_Watchdog(NULL, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_Watchdog::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 5);
			}
		}

		//constructor which receives WSMan client
		AMT_AgentPresenceWatchdog(ICimWsmanClient *client)
			: CIM_Watchdog(client, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_Watchdog::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 5);
			}
		}

		//Destructor
		virtual ~AMT_AgentPresenceWatchdog(){}

		// The "type" information for the object. Gettors only.
		virtual const string& ResourceURI() const { return CLASS_URI; }
		static const string& ClassResourceURI() { return CLASS_URI; }
		virtual const string& XmlNamespace() const { return CLASS_NS; }
		virtual const string& XmlPrefix() const { return CLASS_NS_PREFIX; }
		virtual const string& ObjectType() const { return CLASS_NAME; }
		static const string& ClassObjectType() { return CLASS_NAME; }

		// Class representing AMT_AgentPresenceWatchdog keys
		class CimKeys : public CIM_Watchdog::CimKeys
		{
		public:
			// Key, Required, A GUID which is the AgentID for the monitored application encoded as Base64.
			const string DeviceID() const
			{
				return GetKey("DeviceID");
			}

			// Key, Required, A GUID which is the AgentID for the monitored application encoded as Base64.
			void DeviceID(const string &value)
			{
				SetOrAddKey("DeviceID", value);
			}

		};

		// class fields declarations

		// Optional, Describes the current state of the monitored application. The possible states are: 1 - NotStarted, 2 - Stopped, 4 - Running, 8 - Expired, 16 - Suspended.
		const unsigned short CurrentState() const;

		// Optional, Describes the current state of the monitored application. The possible states are: 1 - NotStarted, 2 - Stopped, 4 - Running, 8 - Expired, 16 - Suspended.
		void CurrentState(const unsigned short value); 

		// Is true if the field CurrentState exists in the current object, otherwise is false.
		bool CurrentStateExists() const;

		// Remove CurrentState field.
		void RemoveCurrentState(); 

		// Required, A seconds timer value which specifies the maximum time allowed for an application to start up and start sending application heartbeat calls (i.e., the time after system restart or after adding a new agent watchdog).
		const unsigned short StartupInterval() const;

		// Required, A seconds timer value which specifies the maximum time allowed for an application to start up and start sending application heartbeat calls (i.e., the time after system restart or after adding a new agent watchdog).
		void StartupInterval(const unsigned short value); 

		// Is true if the field StartupInterval exists in the current object, otherwise is false.
		bool StartupIntervalExists() const;

		// Remove StartupInterval field.
		void RemoveStartupInterval(); 

		//Output parameter for function RegisterAgent
		class CIMFRAMEWORK_API RegisterAgent_OUTPUT : public CimParam
		{
		public:
			// Class Constructor
			RegisterAgent_OUTPUT() : CimParam() {}

			// Class Destructor
			~RegisterAgent_OUTPUT(){}

			// class fields
			// A random sequence number returned by the Intel(R) AMT device. This number should be incremented by one in subsequent calls (when provided). After the counter reaches its highest possible value, it is rolled to zero. The sequence number is used to enforce detection of crashed applications which may have lost their handles. The sequence number is not intended to provide any form of security for this flow.
			const unsigned int SessionSequenceNumber() const;
			bool SessionSequenceNumberExists() const;
			// A seconds timer value which specifies the maximum time allowed between application heartbeat calls.
			const unsigned short TimeoutInterval() const;
			bool TimeoutIntervalExists() const;
		private:
		};

		// This method is issued by applications that wish to start reporting their running state.
		virtual unsigned int RegisterAgent(RegisterAgent_OUTPUT &output);

		//Input parameter for function AssertPresence
		class CIMFRAMEWORK_API AssertPresence_INPUT : public CimParam
		{
		public:
			// Class Constructor
			AssertPresence_INPUT() : CimParam() {}

			// Class Destructor
			~AssertPresence_INPUT(){}

			// Required, A random sequence number returned by the Intel(R) AMT device when the agent last called RegisterAgent. This number should be incremented by one.
			void SequenceNumber(const unsigned int value); 

			const VectorFieldData GetAllFields() const;
		private:
			static const CimFieldAttribute _metadata[];
		};

		// This method is issued periodically by applications to report their running state.
		virtual unsigned int AssertPresence(const AssertPresence_INPUT &input);

		//Input parameter for function AssertShutdown
		class CIMFRAMEWORK_API AssertShutdown_INPUT : public CimParam
		{
		public:
			// Class Constructor
			AssertShutdown_INPUT() : CimParam() {}

			// Class Destructor
			~AssertShutdown_INPUT(){}

			// Required, A random sequence number returned by the Intel(R) AMT device on the former RegisterAgent call. If a call is made with a bad sequence number, it will be ignored so that an invalid agent trying to 'scan' for the current sequence number receives a minimum amount of information. After this call succeeds (in such a way that the command is not ignored), the SequenceNumber is no longer valid and subsequent calls cannot be issued until re-registering. This number should be incremented by one.
			void SequenceNumber(const unsigned int value); 

			const VectorFieldData GetAllFields() const;
		private:
			static const CimFieldAttribute _metadata[];
		};

		// This method is issued by applications to report their termination state.
		virtual unsigned int AssertShutdown(const AssertShutdown_INPUT &input);

		//Input parameter for function AddAction
		class CIMFRAMEWORK_API AddAction_INPUT : public CimParam
		{
		public:
			// Class Constructor
			AddAction_INPUT() : CimParam() {}

			// Class Destructor
			~AddAction_INPUT(){}

			// Required, The last state of the application watchdog. This state may be set to a value containing a logical OR of watchdog states. The possible states are: 1 - NotStarted, 2 - Stopped, 4 - Running, 8 - Expired, 16 - Suspended.
			void OldState(const unsigned short value); 

			// Required, The current state of the application watchdog. This state may be set to a value containing a logical OR of watchdog states. The possible states are: 1 - NotStarted, 2 - Stopped, 4 - Running, 8 - Expired, 16 - Suspended.
			void NewState(const unsigned short value); 

			// Required, Specifies whether an Event should be created in the Event Manager when the application watchdog transitions from OldState to NewState.
			void EventOnTransition(const bool value); 

			// Optional, A System Defense Action which may be applied, when the application watchdog transitions from OldState to NewState. If the caller did not create any policy through AMT_AgentPresenceInterfacePolicy (or ConsoleWatchdogSetCbPolicy() PTNI operation), no policy will be activated, however if the caller created an AMT_AgentPresenceInterfacePolicy to specify a policy at later time, the policy may be activated immediatly according to the logical state which is currently maintained by the Agent Presence feature. This action is optional.
			// Legal values:
			// ActivatePolicy: 0
			// DeactivatePolicy: 1
			void ActionSd(const unsigned short value); 

			// Optional, When this field is TRUE it enables two actions: 1. Information about this agent is included in an Intel(R) AMT EAC posture. This happens if at least one transition is defined as TRUE for this agent. Posture information includes current state and state counters showing how many times each state was entered. 2. When this specific state transition occurs, an avent is generated to indicate that Intel(R) AMT posture has changed.
			void ActionEac(const bool value); 

			const VectorFieldData GetAllFields() const;
		private:
			static const CimFieldAttribute _metadata[];
		};

		// This method adds an action to the application watchdog.
		virtual unsigned int AddAction(const AddAction_INPUT &input);

		// This method removes all actions associated with the watchdog.
		virtual unsigned int DeleteAllActions();

		 // Function used by the factory
		static CimBase *CreateFromCimObject(const CimObject &object);

		static vector<shared_ptr<AMT_AgentPresenceWatchdog> > Enumerate(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		// Overloaded delete which supplies the internal resourceURI
		static void Delete(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		using CimBase::Delete;

	protected:
		 // Protected constructor to be used by derived classes
		AMT_AgentPresenceWatchdog(ICimWsmanClient *client, const string &class_name,
			const string &class_ns, const string &prefix, const string &uri): CIM_Watchdog(client, class_name, class_ns, prefix, uri)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_Watchdog::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 5);
			}
		}
		 // Protected constructor which receives CimObject
		AMT_AgentPresenceWatchdog(const CimObject &object)
			: CIM_Watchdog(object)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_Watchdog::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 5);
			}
		}
		// Called by derived classes
		void SetMetaData(vector<CimFieldAttribute>& childMetaData)
		{
			CIM_Watchdog::SetMetaData(childMetaData);
			CimBase::SetMetaData(childMetaData, _metadata, 5);
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
#endif // AMT_AGENTPRESENCEWATCHDOG_H
