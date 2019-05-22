//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       AMT_AuditPolicyRule.h
//
//  Contents:   Represents event policies.
//
//              This file was automatically generated from AMT_AuditPolicyRule.mof,  version: 7.0.0
//
//----------------------------------------------------------------------------
#ifndef AMT_AUDITPOLICYRULE_H
#define AMT_AUDITPOLICYRULE_H 1
#include "CIM_PolicyRule.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	// Represents event policies.
	class CIMFRAMEWORK_API AMT_AuditPolicyRule  : public CIM_PolicyRule
	{
	public:

		//Default constructor
		AMT_AuditPolicyRule()
			: CIM_PolicyRule(NULL, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_PolicyRule::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 2);
			}
		}

		//constructor which receives WSMan client
		AMT_AuditPolicyRule(ICimWsmanClient *client)
			: CIM_PolicyRule(client, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_PolicyRule::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 2);
			}
		}

		//Destructor
		virtual ~AMT_AuditPolicyRule(){}

		// The "type" information for the object. Gettors only.
		virtual const string& ResourceURI() const { return CLASS_URI; }
		static const string& ClassResourceURI() { return CLASS_URI; }
		virtual const string& XmlNamespace() const { return CLASS_NS; }
		virtual const string& XmlPrefix() const { return CLASS_NS_PREFIX; }
		virtual const string& ObjectType() const { return CLASS_NAME; }
		static const string& ClassObjectType() { return CLASS_NAME; }

		// Class representing AMT_AuditPolicyRule keys
		class CimKeys : public CIM_PolicyRule::CimKeys
		{
		public:
		};

		// class fields declarations

		// Required, List of application events the policy rule applies to.
		const vector<unsigned int> AuditApplicationEventID() const;

		// Required, List of application events the policy rule applies to.
		void AuditApplicationEventID(const vector<unsigned int> &value); 

		// Is true if the field AuditApplicationEventID exists in the current object, otherwise is false.
		bool AuditApplicationEventIDExists() const;

		// Remove AuditApplicationEventID field.
		void RemoveAuditApplicationEventID(); 

		// Required, For each audited event, a flag indicating the type of policy. For example: indicating if the policy is defined as critical.
		const vector<unsigned int> PolicyType() const;

		// Required, For each audited event, a flag indicating the type of policy. For example: indicating if the policy is defined as critical.
		void PolicyType(const vector<unsigned int> &value); 

		// Is true if the field PolicyType exists in the current object, otherwise is false.
		bool PolicyTypeExists() const;

		// Remove PolicyType field.
		void RemovePolicyType(); 

		//Input parameter for function SetAuditPolicy
		class CIMFRAMEWORK_API SetAuditPolicy_INPUT : public CimParam
		{
		public:
			// Class Constructor
			SetAuditPolicy_INPUT() : CimParam() {}

			// Class Destructor
			~SetAuditPolicy_INPUT(){}

			// Required, This flag indicates whether the requested operation is enable or disable.
			void Enable(const bool value); 

			// Required, The application ID of the event.
			void AuditedAppID(const unsigned short value); 

			// Required, The ID of the event.
			void EventID(const unsigned short value); 

			// Optional, A flag indicating the type of policy. For example: indicating if the policy is defined as critical. When the audit log is locked or full, all critical events will not be executed, and will return a failure status code. This flag is not required for a disable request.
			// Legal values:
			// NONE: 0
			// CRITICAL: 1
			// RESERVED: 2..65535
			void PolicyType(const unsigned int value); 

			const VectorFieldData GetAllFields() const;
		private:
			static const CimFieldAttribute _metadata[];
		};

		// This routine is used to enable or disable auditing of a single event. Certain events are predefined as always logged. They are included in the audit log policy whether they were requested explicitly or not. Attempting to remove such events from audit log policy will return an error. Certain events are predefined as never critical. Attempting to include such events in a policy and marking them as critical will return an error.
		virtual unsigned int SetAuditPolicy(const SetAuditPolicy_INPUT &input);

		//Input parameter for function SetAuditPolicyBulk
		class CIMFRAMEWORK_API SetAuditPolicyBulk_INPUT : public CimParam
		{
		public:
			// Class Constructor
			SetAuditPolicyBulk_INPUT() : CimParam() {}

			// Class Destructor
			~SetAuditPolicyBulk_INPUT(){}

			// Required, Array of flags, each one indicates whether to enable or disable the corresponding policy event.
			void Enable(const vector<bool> &value); 

			// Required, Array of application IDs of the policy events.
			void AuditedAppID(const vector<unsigned short> &value); 

			// Required, Array of event IDs of the policy events.
			void EventID(const vector<unsigned short> &value); 

			// Required, Array of flags, each one indicates the type of the corresponding policy event. For example: indicating if the policy is defined as critical. When the audit log is locked or full, all critical events will not be executed, and will return a failure status code.
			// Legal values:
			// NONE: 0
			// CRITICAL: 1
			// RESERVED: 2..65535
			void PolicyType(const vector<unsigned int> &value); 

			const VectorFieldData GetAllFields() const;
		private:
			static const CimFieldAttribute _metadata[];
		};

		// This method enables or disables auditing of multiple events.
		// Certain events are predefined as always logged. They are included in the audit log policy whether they were requested explicitly or not. Attempting to remove such events from the audit log policy will return an error.
		// Certain events are predefined as never critical. Attempting to include such events in a policy and marking them as critical will return an error.
		// If a policy event is configured more than once, the last configuration will be applied.
		// If there is an error, the current audit log policy configuration will not be changed.
		// If the request size is too large to be processed, divide the request into multiple smaller requests.As a rule of thumb, it is recommended not to add more than 6k of data to the request.
		virtual unsigned int SetAuditPolicyBulk(const SetAuditPolicyBulk_INPUT &input);

		 // Function used by the factory
		static CimBase *CreateFromCimObject(const CimObject &object);

		static vector<shared_ptr<AMT_AuditPolicyRule> > Enumerate(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		// Overloaded delete which supplies the internal resourceURI
		static void Delete(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		using CimBase::Delete;

	protected:
		 // Protected constructor to be used by derived classes
		AMT_AuditPolicyRule(ICimWsmanClient *client, const string &class_name,
			const string &class_ns, const string &prefix, const string &uri): CIM_PolicyRule(client, class_name, class_ns, prefix, uri)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_PolicyRule::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 2);
			}
		}
		 // Protected constructor which receives CimObject
		AMT_AuditPolicyRule(const CimObject &object)
			: CIM_PolicyRule(object)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_PolicyRule::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 2);
			}
		}
		// Called by derived classes
		void SetMetaData(vector<CimFieldAttribute>& childMetaData)
		{
			CIM_PolicyRule::SetMetaData(childMetaData);
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
#endif // AMT_AUDITPOLICYRULE_H
