//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       AMT_StateTransitionCondition.h
//
//  Contents:   Represents an application watchdog state transition that can trigger an action.
//
//              This file was automatically generated from AMT_StateTransitionCondition.mof,  version: 3.0.0
//
//----------------------------------------------------------------------------
#ifndef AMT_STATETRANSITIONCONDITION_H
#define AMT_STATETRANSITIONCONDITION_H 1
#include "CIM_PolicyCondition.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	// Represents an application watchdog state transition that can trigger an action.
	class CIMFRAMEWORK_API AMT_StateTransitionCondition  : public CIM_PolicyCondition
	{
	public:

		//Default constructor
		AMT_StateTransitionCondition()
			: CIM_PolicyCondition(NULL, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_PolicyCondition::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 3);
			}
		}

		//constructor which receives WSMan client
		AMT_StateTransitionCondition(ICimWsmanClient *client)
			: CIM_PolicyCondition(client, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_PolicyCondition::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 3);
			}
		}

		//Destructor
		virtual ~AMT_StateTransitionCondition(){}

		// The "type" information for the object. Gettors only.
		virtual const string& ResourceURI() const { return CLASS_URI; }
		static const string& ClassResourceURI() { return CLASS_URI; }
		virtual const string& XmlNamespace() const { return CLASS_NS; }
		virtual const string& XmlPrefix() const { return CLASS_NS_PREFIX; }
		virtual const string& ObjectType() const { return CLASS_NAME; }
		static const string& ClassObjectType() { return CLASS_NAME; }

		// Class representing AMT_StateTransitionCondition keys
		class CimKeys : public CIM_PolicyCondition::CimKeys
		{
		public:
		};

		// class fields declarations

		// Optional, The state exited by the transition. This state may be set to a value containing a logical OR of watchdog states. The possible states are: 1 - NotStarted, 2 - Stopped, 4 - Running, 8 - Expired, 16 - Suspended.
		const unsigned short OldState() const;

		// Optional, The state exited by the transition. This state may be set to a value containing a logical OR of watchdog states. The possible states are: 1 - NotStarted, 2 - Stopped, 4 - Running, 8 - Expired, 16 - Suspended.
		void OldState(const unsigned short value); 

		// Is true if the field OldState exists in the current object, otherwise is false.
		bool OldStateExists() const;

		// Remove OldState field.
		void RemoveOldState(); 

		// Optional, The state entered by the transition. This state may be set to a value containing a logical OR of watchdog states. The possible states are: 1 - NotStarted, 2 - Stopped, 4 - Running, 8 - Expired, 16 - Suspended.
		const unsigned short NewState() const;

		// Optional, The state entered by the transition. This state may be set to a value containing a logical OR of watchdog states. The possible states are: 1 - NotStarted, 2 - Stopped, 4 - Running, 8 - Expired, 16 - Suspended.
		void NewState(const unsigned short value); 

		// Is true if the field NewState exists in the current object, otherwise is false.
		bool NewStateExists() const;

		// Remove NewState field.
		void RemoveNewState(); 

		// Optional, A string that identifies the set of state values that can be assigned to OldState and NewState.
		const string StateSpace() const;

		// Optional, A string that identifies the set of state values that can be assigned to OldState and NewState.
		void StateSpace(const string &value); 

		// Is true if the field StateSpace exists in the current object, otherwise is false.
		bool StateSpaceExists() const;

		// Remove StateSpace field.
		void RemoveStateSpace(); 

		 // Function used by the factory
		static CimBase *CreateFromCimObject(const CimObject &object);

		static vector<shared_ptr<AMT_StateTransitionCondition> > Enumerate(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		// Overloaded delete which supplies the internal resourceURI
		static void Delete(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		using CimBase::Delete;

	protected:
		 // Protected constructor to be used by derived classes
		AMT_StateTransitionCondition(ICimWsmanClient *client, const string &class_name,
			const string &class_ns, const string &prefix, const string &uri): CIM_PolicyCondition(client, class_name, class_ns, prefix, uri)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_PolicyCondition::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 3);
			}
		}
		 // Protected constructor which receives CimObject
		AMT_StateTransitionCondition(const CimObject &object)
			: CIM_PolicyCondition(object)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_PolicyCondition::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 3);
			}
		}
		// Called by derived classes
		void SetMetaData(vector<CimFieldAttribute>& childMetaData)
		{
			CIM_PolicyCondition::SetMetaData(childMetaData);
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
#endif // AMT_STATETRANSITIONCONDITION_H
