//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       IPS_WatchDogAction.h
//
//  Contents:   The IPS_WatchDogAction class configures the action of watch dog expiration.
//
//              This file was automatically generated from IPS_WatchDogAction.mof,  version: 11.0.0
//
//----------------------------------------------------------------------------
#ifndef IPS_WATCHDOGACTION_H
#define IPS_WATCHDOGACTION_H 1
#include "CIM_ManagedElement.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	// The IPS_WatchDogAction class configures the action of watch dog expiration.
	class CIMFRAMEWORK_API IPS_WatchDogAction  : public CIM_ManagedElement
	{
	public:

		//Default constructor
		IPS_WatchDogAction()
			: CIM_ManagedElement(NULL, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_ManagedElement::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 5);
			}
		}

		//constructor which receives WSMan client
		IPS_WatchDogAction(ICimWsmanClient *client)
			: CIM_ManagedElement(client, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_ManagedElement::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 5);
			}
		}

		//Destructor
		virtual ~IPS_WatchDogAction(){}

		// The "type" information for the object. Gettors only.
		virtual const string& ResourceURI() const { return CLASS_URI; }
		static const string& ClassResourceURI() { return CLASS_URI; }
		virtual const string& XmlNamespace() const { return CLASS_NS; }
		virtual const string& XmlPrefix() const { return CLASS_NS_PREFIX; }
		virtual const string& ObjectType() const { return CLASS_NAME; }
		static const string& ClassObjectType() { return CLASS_NAME; }

		// Class representing IPS_WatchDogAction keys
		class CimKeys : public CIM_ManagedElement::CimKeys
		{
		public:
			// Key, Required, 
			const string InstanceID() const
			{
				return GetKey("InstanceID");
			}

			// Key, Required, 
			void InstanceID(const string &value)
			{
				SetOrAddKey("InstanceID", value);
			}

		};

		// class fields declarations

		// Required, The action to invoke upon OS Watch dog expiration.'None' stands for no action. 'Reboot' stands for reset of the machine
		const unsigned int HeciWatchDogExpirationAction() const;

		// Required, The action to invoke upon OS Watch dog expiration.'None' stands for no action. 'Reboot' stands for reset of the machine
		void HeciWatchDogExpirationAction(const unsigned int value); 

		// Is true if the field HeciWatchDogExpirationAction exists in the current object, otherwise is false.
		bool HeciWatchDogExpirationActionExists() const;

		// Remove HeciWatchDogExpirationAction field.
		void RemoveHeciWatchDogExpirationAction(); 

		// Required, The action to invoke upon AP Watch dog expiration.'None' stands for no action. 'Reboot' stands for reset of the machine
		const unsigned int AgentPresenceWatchDogExpirationAction() const;

		// Required, The action to invoke upon AP Watch dog expiration.'None' stands for no action. 'Reboot' stands for reset of the machine
		void AgentPresenceWatchDogExpirationAction(const unsigned int value); 

		// Is true if the field AgentPresenceWatchDogExpirationAction exists in the current object, otherwise is false.
		bool AgentPresenceWatchDogExpirationActionExists() const;

		// Remove AgentPresenceWatchDogExpirationAction field.
		void RemoveAgentPresenceWatchDogExpirationAction(); 

		// Optional, How long to wait (in seconds) before applying HeciWatchDogExpirationAction or AgentPresenceWatchDogExpirationAction
		const unsigned int Timeout() const;

		// Optional, How long to wait (in seconds) before applying HeciWatchDogExpirationAction or AgentPresenceWatchDogExpirationAction
		void Timeout(const unsigned int value); 

		// Is true if the field Timeout exists in the current object, otherwise is false.
		bool TimeoutExists() const;

		// Remove Timeout field.
		void RemoveTimeout(); 

		// Optional, Allows the manageability to perform reset again
		const bool ReArmReset() const;

		// Optional, Allows the manageability to perform reset again
		void ReArmReset(const bool value); 

		// Is true if the field ReArmReset exists in the current object, otherwise is false.
		bool ReArmResetExists() const;

		// Remove ReArmReset field.
		void RemoveReArmReset(); 

		//Input parameter for function ApplyActionOnWatchDog
		class CIMFRAMEWORK_API ApplyActionOnWatchDog_INPUT : public CimParam
		{
		public:
			// Class Constructor
			ApplyActionOnWatchDog_INPUT() : CimParam() {}

			// Class Destructor
			~ApplyActionOnWatchDog_INPUT(){}

			// Required, The instance of the AMT_AgentPresenceWatchdog to apply action on.
			void AgentPresenceWatchDog(const CimReference &value); 

			// Required, Determine if action should be applied or not on AMT_AgentPresenceWatchdog instance
			void ActionEnable(const bool value); 

			const VectorFieldData GetAllFields() const;
		private:
			static const CimFieldAttribute _metadata[];
		};

		// Apply AgentPresenceWatchDogExpirationAction on instance of AMT_AgentPresenceWatchdog.Creates association of CIM_ElementSettingData between IPS_WatchDogAction and the specified instance.
		virtual unsigned int ApplyActionOnWatchDog(const ApplyActionOnWatchDog_INPUT &input);

		// Cancel Reboot operation following WD expiration.
		virtual unsigned int CancelRebootAction();

		 // Function used by the factory
		static CimBase *CreateFromCimObject(const CimObject &object);

		static vector<shared_ptr<IPS_WatchDogAction> > Enumerate(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		// Overloaded delete which supplies the internal resourceURI
		static void Delete(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		using CimBase::Delete;

	protected:
		 // Protected constructor to be used by derived classes
		IPS_WatchDogAction(ICimWsmanClient *client, const string &class_name,
			const string &class_ns, const string &prefix, const string &uri): CIM_ManagedElement(client, class_name, class_ns, prefix, uri)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_ManagedElement::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 5);
			}
		}
		 // Protected constructor which receives CimObject
		IPS_WatchDogAction(const CimObject &object)
			: CIM_ManagedElement(object)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_ManagedElement::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 5);
			}
		}
		// Called by derived classes
		void SetMetaData(vector<CimFieldAttribute>& childMetaData)
		{
			CIM_ManagedElement::SetMetaData(childMetaData);
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
#endif // IPS_WATCHDOGACTION_H
