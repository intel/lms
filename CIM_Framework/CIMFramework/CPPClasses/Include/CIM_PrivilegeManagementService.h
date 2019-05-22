//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_PrivilegeManagementService.h
//
//  Contents:   The PrivilegeManagementService is responsible for creating, deleting, and associating AuthorizedPrivilege instances. References to 'subject' and 'target' define the entities that are associated with an AuthorizedPrivilege instance via the relationships, AuthorizedSubject and AuthorizedTarget, respectively. When created, an AuthorizedPrivilege instance is related to this (PrivilegeManagement)Service via the association, ConcreteDependency.
//
//              This file was automatically generated from CIM_PrivilegeManagementService.mof,  version: 2.20.0
//
//----------------------------------------------------------------------------
#ifndef CIM_PRIVILEGEMANAGEMENTSERVICE_H
#define CIM_PRIVILEGEMANAGEMENTSERVICE_H 1
#include "CIM_AuthorizationService.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	// The PrivilegeManagementService is responsible for creating, deleting, and associating AuthorizedPrivilege instances. References to 'subject' and 'target' define the entities that are associated with an AuthorizedPrivilege instance via the relationships, AuthorizedSubject and AuthorizedTarget, respectively. When created, an AuthorizedPrivilege instance is related to this (PrivilegeManagement)Service via the association, ConcreteDependency.
	class CIMFRAMEWORK_API CIM_PrivilegeManagementService  : public CIM_AuthorizationService
	{
	public:

		//Default constructor
		CIM_PrivilegeManagementService()
			: CIM_AuthorizationService(NULL, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				_classMetaData = CIM_AuthorizationService::GetMetaData();
			}
		}

		//constructor which receives WSMan client
		CIM_PrivilegeManagementService(ICimWsmanClient *client)
			: CIM_AuthorizationService(client, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				_classMetaData = CIM_AuthorizationService::GetMetaData();
			}
		}

		//Destructor
		virtual ~CIM_PrivilegeManagementService(){}

		// The "type" information for the object. Gettors only.
		virtual const string& ResourceURI() const { return CLASS_URI; }
		static const string& ClassResourceURI() { return CLASS_URI; }
		virtual const string& XmlNamespace() const { return CLASS_NS; }
		virtual const string& XmlPrefix() const { return CLASS_NS_PREFIX; }
		virtual const string& ObjectType() const { return CLASS_NAME; }
		static const string& ClassObjectType() { return CLASS_NAME; }

		// Class representing CIM_PrivilegeManagementService keys
		class CimKeys : public CIM_AuthorizationService::CimKeys
		{
		public:
		};
		// The StopService method places the Service in the stopped state. Note that the function of this method overlaps with the RequestedState property. RequestedState was added to the model to maintain a record (such as a persisted value) of the last state request. Invoking the StopService method should set the RequestedState property appropriately. The method returns an integer value of 0 if the Service was successfully stopped, 1 if the request is not supported, and any other number to indicate an error. In a subclass, the set of possible return codes could be specified using a ValueMap qualifier on the method. The strings to which the ValueMap contents are translated can also be specified in the subclass as a Values array qualifier. 
		// 
		// Note: The semantics of this method overlap with the RequestStateChange method that is inherited from EnabledLogicalElement. This method is maintained because it has been widely implemented, and its simple "stop" semantics are convenient to use.
		virtual unsigned int StopService();

		// The StartService method places the Service in the started state. Note that the function of this method overlaps with the RequestedState property. RequestedState was added to the model to maintain a record (such as a persisted value) of the last state request. Invoking the StartService method should set the RequestedState property appropriately. The method returns an integer value of 0 if the Service was successfully started, 1 if the request is not supported, and any other number to indicate an error. In a subclass, the set of possible return codes could be specified using a ValueMap qualifier on the method. The strings to which the ValueMap contents are translated can also be specified in the subclass as a Values array qualifier. 
		// 
		// Note: The semantics of this method overlap with the RequestStateChange method that is inherited from EnabledLogicalElement. This method is maintained because it has been widely implemented, and its simple "start" semantics are convenient to use.
		virtual unsigned int StartService();

		//Input parameter for function RequestStateChange
		class CIMFRAMEWORK_API RequestStateChange_INPUT : public CimParam
		{
		public:
			// Class Constructor
			RequestStateChange_INPUT() : CimParam() {}

			// Class Destructor
			~RequestStateChange_INPUT(){}

			// Optional, The state requested for the element. This information will be placed into the RequestedState property of the instance if the return code of the RequestStateChange method is 0 ('Completed with No Error'), or 4096 (0x1000) ('Job Started'). Refer to the description of the EnabledState and RequestedState properties for the detailed explanations of the RequestedState values.
			// Legal values:
			// Enabled: 2
			// Disabled: 3
			// Shut Down: 4
			// Offline: 6
			// Test: 7
			// Defer: 8
			// Quiesce: 9
			// Reboot: 10
			// Reset: 11
			// DMTF Reserved: ..
			// Vendor Reserved: 32768..65535
			void RequestedState(const unsigned short value); 

			// Optional, A timeout period that specifies the maximum amount of time that the client expects the transition to the new state to take. The interval format must be used to specify the TimeoutPeriod. A value of 0 or a null parameter indicates that the client has no time requirements for the transition. 
			// If this property does not contain 0 or null and the implementation does not support this parameter, a return code of 'Use Of Timeout Parameter Not Supported' shall be returned.
			void TimeoutPeriod(const CimDateTime &value); 

			const VectorFieldData GetAllFields() const;
		private:
			static const CimFieldAttribute _metadata[];
		};

		//Output parameter for function RequestStateChange
		class CIMFRAMEWORK_API RequestStateChange_OUTPUT : public CimParam
		{
		public:
			// Class Constructor
			RequestStateChange_OUTPUT() : CimParam() {}

			// Class Destructor
			~RequestStateChange_OUTPUT(){}

			// class fields
			// May contain a reference to the ConcreteJob created to track the state transition initiated by the method invocation.
			const CimReference Job() const;
			bool JobExists() const;
		private:
		};

		// Requests that the state of the element be changed to the value specified in the RequestedState parameter. When the requested state change takes place, the EnabledState and RequestedState of the element will be the same. Invoking the RequestStateChange method multiple times could result in earlier requests being overwritten or lost. 
		// A return code of 0 shall indicate the state change was successfully initiated. 
		// A return code of 3 shall indicate that the state transition cannot complete within the interval specified by the TimeoutPeriod parameter. 
		// A return code of 4096 (0x1000) shall indicate the state change was successfully initiated, a ConcreteJob has been created, and its reference returned in the output parameter Job. Any other return code indicates an error condition.
		virtual unsigned int RequestStateChange(const RequestStateChange_INPUT &input, RequestStateChange_OUTPUT &output);

		//Input parameter for function AssignAccess
		class CIMFRAMEWORK_API AssignAccess_INPUT : public CimParam
		{
		public:
			// Class Constructor
			AssignAccess_INPUT() : CimParam() {}

			// Class Destructor
			~AssignAccess_INPUT(){}

			// Required, The Subject parameter is a reference to a ManagedElement instance. This parameter MUST be supplied.
			void Subject(const CimReference &value); 

			// Optional, MUST be NULL unless Privilege is NULL on input. The PrivilegeGranted flag indicates whether the rights defined by the parameters in this call should be granted or denied to the named Subject/Target pair.
			void PrivilegeGranted(const bool value); 

			// Required, MUST be NULL unless the Privilege is NULL on input. This parameter specifies the activities to be granted or denied.
			// Legal values:
			// Other: 1
			// Create: 2
			// Delete: 3
			// Detect: 4
			// Read: 5
			// Write: 6
			// Execute: 7
			// DMTF Reserved: ..
			// Vendor Reserved: 16000..65535
			void Activities(const vector<unsigned short> &value); 

			// Required, MUST be NULL unless Privilege is NULL on input. This parameter defines the activity qualifiers for the Activities to be granted or denied.
			void ActivityQualifiers(const vector<string> &value); 

			// Required, MUST be NULL unless Privilege is NULL on input. This parameter defines the qualifier formats for the corresponding ActivityQualifiers.
			// Legal values:
			// Class Name: 2
			// <Class.>Property: 3
			// <Class.>Method: 4
			// Object Reference: 5
			// Namespace: 6
			// URL: 7
			// Directory/File Name: 8
			// Command Line Instruction: 9
			// DMTF Reserved: 10..15999
			// Vendor Reserved: 16000..65535
			void QualifierFormats(const vector<unsigned short> &value); 

			// Required, The Target parameter is a reference to an instance of ManagedElement. This parameter MUST be supplied.
			void Target(const CimReference &value); 

			// Optional, On input, this reference MUST be either NULL or refer to an instance of AuthorizedPrivilege that is used as a template. The rights granted by corresponding entries in the Activities, ActivityQualifiers and QualifierFormats array properties are applied incrementally and do not affect unnamed rights. If the property, PrivilegeGranted, is false, then the named rights are removed. If PrivilegeGranted is True, then the named rights are added. (Note that the RemoveAccess method SHOULD be used to completely remove all privileges between a subject and a target. On output, this property references an AuthorizedPrivilege instance that represents the resulting rights between the named Subject and the named Target. AuthorizedPrivilege instances used as a templates in this property SHOULD have a HostedDependency association to the PriviligeManagementService and SHOULD NOT have any AuthorizedTarget or AuthorizedSubject associations to it.
			void Privilege(const CimReference &value); 

			const VectorFieldData GetAllFields() const;
		private:
			static const CimFieldAttribute _metadata[];
		};

		//Output parameter for function AssignAccess
		class CIMFRAMEWORK_API AssignAccess_OUTPUT : public CimParam
		{
		public:
			// Class Constructor
			AssignAccess_OUTPUT() : CimParam() {}

			// Class Destructor
			~AssignAccess_OUTPUT(){}

			// class fields
			// On input, this reference MUST be either NULL or refer to an instance of AuthorizedPrivilege that is used as a template. The rights granted by corresponding entries in the Activities, ActivityQualifiers and QualifierFormats array properties are applied incrementally and do not affect unnamed rights. If the property, PrivilegeGranted, is false, then the named rights are removed. If PrivilegeGranted is True, then the named rights are added. (Note that the RemoveAccess method SHOULD be used to completely remove all privileges between a subject and a target. On output, this property references an AuthorizedPrivilege instance that represents the resulting rights between the named Subject and the named Target. AuthorizedPrivilege instances used as a templates in this property SHOULD have a HostedDependency association to the PriviligeManagementService and SHOULD NOT have any AuthorizedTarget or AuthorizedSubject associations to it.
			const CimReference Privilege() const;
			bool PrivilegeExists() const;
		private:
		};

		// When this method is called, a provider updates the specified Subject's rights to the Target according to the parameters of this call. The rights are modeled via an AuthorizedPrivilege instance. If an AuthorizedPrivilege instance is created as a result of this call, it MUST be linked to the Subject and Target via the AuthorizedSubject and AuthorizedTarget associations, respectively. When created, the AuthorizedPrivilege instance is associated to this PrivilegeManagementService via ConcreteDependency. If the execution of this call results in no rights between the Subject and Target, then they MUST NOT be linked to a particular AuthorizedPrivilege instance via AuthorizedSubject and AuthorizedTarget respectively. 
		// 
		// Note that regardless of whether specified via parameter, or template, the Activities, ActivityQualifiers and QualifierFormats, are mutually indexed. Also note that Subject and Target references MUST be supplied. 
		// 
		// The successful completion of the method SHALL create any necessary AuthorizedSubject, AuthorizedTarget, AuthorizedPrivilege, HostedDependency, and ConcreteDependency instances.
		virtual unsigned int AssignAccess(const AssignAccess_INPUT &input, AssignAccess_OUTPUT &output);

		//Input parameter for function RemoveAccess
		class CIMFRAMEWORK_API RemoveAccess_INPUT : public CimParam
		{
		public:
			// Class Constructor
			RemoveAccess_INPUT() : CimParam() {}

			// Class Destructor
			~RemoveAccess_INPUT(){}

			// Optional, The Subject parameter is a reference to a ManagedElement instance (associated via AuthorizedSubject) for which privileges are to be revoked.
			void Subject(const CimReference &value); 

			// Optional, A reference to the AuthorizedPrivilege to be revoked.
			void Privilege(const CimReference &value); 

			// Optional, The Target parameter is a reference to a ManagedElement (associated via AuthorizedTarget) which will no longer be protected via the AuthorizedPrivilege.
			void Target(const CimReference &value); 

			const VectorFieldData GetAllFields() const;
		private:
			static const CimFieldAttribute _metadata[];
		};

		// This method revokes a specific AuthorizedPrivilege or all privileges for a particular target, subject, or subject/target pair. If an AuthorizedPrivilege instance is left with no AuthorizedTarget associations, it SHOULD be deleted. The successful completion of the method SHALL remove the directly or indirectly requested AuthorizedSubject, AuthorizedTarget and AuthorizedPrivilege instances.
		virtual unsigned int RemoveAccess(const RemoveAccess_INPUT &input);

		//Input parameter for function ShowAccess
		class CIMFRAMEWORK_API ShowAccess_INPUT : public CimParam
		{
		public:
			// Class Constructor
			ShowAccess_INPUT() : CimParam() {}

			// Class Destructor
			~ShowAccess_INPUT(){}

			// Optional, The Subject parameter references an instance of ManagedElement. The result of this operation is that the cumulative rights of the Subject to access or define authorization rights for the Target will be reported. If no Subject is specified, then a Target MUST be supplied and ALL Subjects that have rights to access or define authorizations for the Target will be reported. (It should be noted that the information reported MUST be filtered by the rights of the requestor to view that data.) If the Subject element is a Collection, then the operation will specifically report the Privileges for all elements associated to the Collection via MemberOfCollection. These elements will be reported individually in the returned OutSubjects array.
			void Subject(const CimReference &value); 

			// Optional, The Target parameter references an instance of ManagedElement. The result of this operation is that the cumulative rights of the Subject to access or define authorization rights for the Target will be reported. If no Target is specified, then a Subject MUST be supplied and ALL Targets for which that the Subject has rights to access or define authorization will be reported. (It should be noted that the information reported MUST be filtered by the rights of the requestor to view that data.) If the Target element is a Collection, then the operation will be applied to all elements associated to the Collection via MemberOfCollection. These elements will be reported individually in the returned OutTargets array.
			void Target(const CimReference &value); 

			const VectorFieldData GetAllFields() const;
		private:
			static const CimFieldAttribute _metadata[];
		};

		//Output parameter for function ShowAccess
		class CIMFRAMEWORK_API ShowAccess_OUTPUT : public CimParam
		{
		public:
			// Class Constructor
			ShowAccess_OUTPUT() : CimParam() {}

			// Class Destructor
			~ShowAccess_OUTPUT(){}

			// class fields
			// The array of Subject REFs corresponding to the individual Privileges and OutTargets arrays. The resulting OutSubjects, Privileges and OutTargets arrays define the cumulative rights granted between the Subject/Target at the corresponding index (filtered to return the information that the requestor is authorized to view).
			const vector<CimReference> OutSubjects() const;
			bool OutSubjectsExists() const;
			// The array of Target REFs corresponding to the individual Privileges and OutSubjects arrays. The resulting OutSubjects, Privileges and OutTargets arrays define the cumulative rights granted between the Subject/Target at the corresponding index (filtered to return the information that the requestor is authorized to view).
			const vector<CimReference> OutTargets() const;
			bool OutTargetsExists() const;
			// The returned Privilege objects represent the cumulative rights granted between the OutSubjects and OutTargets at the same array index (filtered to return the information that the requestor is authorized to view). If a specific array entry is NULL, then there exist NO rights that the requestor is authorized to view between the Subject/Target pair.
			const vector<string> Privileges() const;
			bool PrivilegesExists() const;
		private:
		};

		// ShowAccess reports the Privileges (i.e., rights) granted to a particular Subject and/or Target pair. Either a Subject, a Target or both MUST be specified. In the case where only one is specified, the method will return all rights to all Targets for the specified Subject, or all rights for all subjects which apply to the specified Target. 
		// 
		// ShowAccess returns the cumulative rights granted between the OutSubjects and OutTargets at the same array index (filtered to return the information that the requestor is authorized to view). If a specific array entry is NULL, then there exist NO rights that the requestor is authorized to view between the Subject/Target pair. 
		// 
		// Note that the Privileges returned by this method MAY NOT correspond to what is actually instantiated in the model, and MAY be optimized for ease of reporting. Hence, the data is passed 'by value', as embedded objects. Also, note that multiple Privileges MAY be defined for a given Subject/Target pair. 
		// 
		// Other mechanisms MAY also be used to retrieve this information. CIM Operations' EnumerateInstances MAY be used to return all Privileges currently instantiated within a namespace. Also, if the AuthorizedPrivilege subclass is instantiated, the CIM Operation Associators MAY be used to navigate from the Privilege to AuthorizedSubjects and AuthorizedTargets. These CIM Operations will not generally provide the functionality or optimizations available with ShowAccess.
		virtual unsigned int ShowAccess(const ShowAccess_INPUT &input, ShowAccess_OUTPUT &output);

		 // Function used by the factory
		static CimBase *CreateFromCimObject(const CimObject &object);

		static vector<shared_ptr<CIM_PrivilegeManagementService> > Enumerate(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		// Overloaded delete which supplies the internal resourceURI
		static void Delete(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		using CimBase::Delete;

	protected:
		 // Protected constructor to be used by derived classes
		CIM_PrivilegeManagementService(ICimWsmanClient *client, const string &class_name,
			const string &class_ns, const string &prefix, const string &uri): CIM_AuthorizationService(client, class_name, class_ns, prefix, uri)
		{
			if(_classMetaData.size() == 0)
			{
				_classMetaData = CIM_AuthorizationService::GetMetaData();
			}
		}
		 // Protected constructor which receives CimObject
		CIM_PrivilegeManagementService(const CimObject &object)
			: CIM_AuthorizationService(object)
		{
			if(_classMetaData.size() == 0)
			{
				_classMetaData = CIM_AuthorizationService::GetMetaData();
			}
		}
		// Called by derived classes
		void SetMetaData(vector<CimFieldAttribute>& childMetaData)
		{
			CIM_AuthorizationService::SetMetaData(childMetaData);
		}
		const vector<CimFieldAttribute> &GetMetaData() const;
	private:
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
#endif // CIM_PRIVILEGEMANAGEMENTSERVICE_H
