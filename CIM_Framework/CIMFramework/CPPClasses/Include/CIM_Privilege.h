//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_Privilege.h
//
//  Contents:   Privilege is the base class for all types of activities which are granted or denied by a Role or an Identity. Whether an individual Privilege is granted or denied is defined using the PrivilegeGranted boolean. Any Privileges not specifically granted are assumed to be denied. An explicit deny (Privilege Granted = FALSE) takes precedence over any granted Privileges. 
//              
//              The association of subjects (Roles and Identities) to Privileges is accomplished using policy or explicitly via the associations on a subclass. The entities that are protected (targets) can be similarly defined. 
//              
//              Note that Privileges may be inherited through hierarchical Roles, or may overlap. For example, a Privilege denying any instance Writes in a particular CIM Server Namespace would overlap with a Privilege defining specific access rights at an instance level within that Namespace. In this example, the AuthorizedSubjects are either Identities or Roles, and the AuthorizedTargets are a Namespace in the former case, and a particular instance in the latter.
//
//              This file was automatically generated from CIM_Privilege.mof,  version: 2.20.0
//
//----------------------------------------------------------------------------
#ifndef CIM_PRIVILEGE_H
#define CIM_PRIVILEGE_H 1
#include "CIM_ManagedElement.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	// Privilege is the base class for all types of activities which are granted or denied by a Role or an Identity. Whether an individual Privilege is granted or denied is defined using the PrivilegeGranted boolean. Any Privileges not specifically granted are assumed to be denied. An explicit deny (Privilege Granted = FALSE) takes precedence over any granted Privileges. 
	// 
	// The association of subjects (Roles and Identities) to Privileges is accomplished using policy or explicitly via the associations on a subclass. The entities that are protected (targets) can be similarly defined. 
	// 
	// Note that Privileges may be inherited through hierarchical Roles, or may overlap. For example, a Privilege denying any instance Writes in a particular CIM Server Namespace would overlap with a Privilege defining specific access rights at an instance level within that Namespace. In this example, the AuthorizedSubjects are either Identities or Roles, and the AuthorizedTargets are a Namespace in the former case, and a particular instance in the latter.
	class CIMFRAMEWORK_API CIM_Privilege  : public CIM_ManagedElement
	{
	public:

		//Default constructor
		CIM_Privilege()
			: CIM_ManagedElement(NULL, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_ManagedElement::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 6);
			}
		}

		//constructor which receives WSMan client
		CIM_Privilege(ICimWsmanClient *client)
			: CIM_ManagedElement(client, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_ManagedElement::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 6);
			}
		}

		//Destructor
		virtual ~CIM_Privilege(){}

		// The "type" information for the object. Gettors only.
		virtual const string& ResourceURI() const { return CLASS_URI; }
		static const string& ClassResourceURI() { return CLASS_URI; }
		virtual const string& XmlNamespace() const { return CLASS_NS; }
		virtual const string& XmlPrefix() const { return CLASS_NS_PREFIX; }
		virtual const string& ObjectType() const { return CLASS_NAME; }
		static const string& ClassObjectType() { return CLASS_NAME; }

		// Class representing CIM_Privilege keys
		class CimKeys : public CIM_ManagedElement::CimKeys
		{
		public:
			// Key, Required, Within the scope of the instantiating Namespace, InstanceID opaquely and uniquely identifies an instance of this class. In order to ensure uniqueness within the NameSpace, the value of InstanceID SHOULD be constructed using the following 'preferred' algorithm: 
			// <OrgID>:<LocalID> 
			// Where <OrgID> and <LocalID> are separated by a colon ':', and where <OrgID> MUST include a copyrighted, trademarked or otherwise unique name that is owned by the business entity creating/defining the InstanceID, or is a registered ID that is assigned to the business entity by a recognized global authority. (This is similar to the <Schema Name>_<Class Name> structure of Schema class names.) In addition, to ensure uniqueness <OrgID> MUST NOT contain a colon (':'). When using this algorithm, the first colon to appear in InstanceID MUST appear between <OrgID> and <LocalID>. 
			// <LocalID> is chosen by the business entity and SHOULD not be re-used to identify different underlying (real-world) elements. If the above 'preferred' algorithm is not used, the defining entity MUST assure that the resultant InstanceID is not re-used across any InstanceIDs produced by this or other providers for this instance's NameSpace. For DMTF defined instances, the 'preferred' algorithm MUST be used with the <OrgID> set to 'CIM'.
			const string InstanceID() const
			{
				return GetKey("InstanceID");
			}

			// Key, Required, Within the scope of the instantiating Namespace, InstanceID opaquely and uniquely identifies an instance of this class. In order to ensure uniqueness within the NameSpace, the value of InstanceID SHOULD be constructed using the following 'preferred' algorithm: 
			// <OrgID>:<LocalID> 
			// Where <OrgID> and <LocalID> are separated by a colon ':', and where <OrgID> MUST include a copyrighted, trademarked or otherwise unique name that is owned by the business entity creating/defining the InstanceID, or is a registered ID that is assigned to the business entity by a recognized global authority. (This is similar to the <Schema Name>_<Class Name> structure of Schema class names.) In addition, to ensure uniqueness <OrgID> MUST NOT contain a colon (':'). When using this algorithm, the first colon to appear in InstanceID MUST appear between <OrgID> and <LocalID>. 
			// <LocalID> is chosen by the business entity and SHOULD not be re-used to identify different underlying (real-world) elements. If the above 'preferred' algorithm is not used, the defining entity MUST assure that the resultant InstanceID is not re-used across any InstanceIDs produced by this or other providers for this instance's NameSpace. For DMTF defined instances, the 'preferred' algorithm MUST be used with the <OrgID> set to 'CIM'.
			void InstanceID(const string &value)
			{
				SetOrAddKey("InstanceID", value);
			}

		};

		// class fields declarations

		// Optional, Boolean indicating whether the Privilege is granted (TRUE) or denied (FALSE). The default is to grant permission.
		const bool PrivilegeGranted() const;

		// Optional, Boolean indicating whether the Privilege is granted (TRUE) or denied (FALSE). The default is to grant permission.
		void PrivilegeGranted(const bool value); 

		// Is true if the field PrivilegeGranted exists in the current object, otherwise is false.
		bool PrivilegeGrantedExists() const;

		// Remove PrivilegeGranted field.
		void RemovePrivilegeGranted(); 

		// Optional, An enumeration indicating the activities that are granted or denied. These activities apply to all entities specified in the ActivityQualifiers array. The values in the enumeration are straightforward except for one, 4="Detect". This value indicates that the existence or presence of an entity may be determined, but not necessarily specific data (which requires the Read privilege to be true). This activity is exemplified by 'hidden files'- if you list the contents of a directory, you will not see hidden files. However, if you know a specific file name, or know how to expose hidden files, then they can be 'detected'. Another example is the ability to define search privileges in directory implementations.
		const vector<unsigned short> Activities() const;

		// Optional, An enumeration indicating the activities that are granted or denied. These activities apply to all entities specified in the ActivityQualifiers array. The values in the enumeration are straightforward except for one, 4="Detect". This value indicates that the existence or presence of an entity may be determined, but not necessarily specific data (which requires the Read privilege to be true). This activity is exemplified by 'hidden files'- if you list the contents of a directory, you will not see hidden files. However, if you know a specific file name, or know how to expose hidden files, then they can be 'detected'. Another example is the ability to define search privileges in directory implementations.
		void Activities(const vector<unsigned short> &value); 

		// Is true if the field Activities exists in the current object, otherwise is false.
		bool ActivitiesExists() const;

		// Remove Activities field.
		void RemoveActivities(); 

		// Optional, The ActivityQualifiers property is an array of string values used to further qualify and specify the privileges granted or denied. For example, it is used to specify a set of files for which 'Read'/'Write' access is permitted or denied. Or, it defines a class' methods that may be 'Executed'. Details on the semantics of the individual entries in ActivityQualifiers are provided by corresponding entries in the QualifierFormats array.
		const vector<string> ActivityQualifiers() const;

		// Optional, The ActivityQualifiers property is an array of string values used to further qualify and specify the privileges granted or denied. For example, it is used to specify a set of files for which 'Read'/'Write' access is permitted or denied. Or, it defines a class' methods that may be 'Executed'. Details on the semantics of the individual entries in ActivityQualifiers are provided by corresponding entries in the QualifierFormats array.
		void ActivityQualifiers(const vector<string> &value); 

		// Is true if the field ActivityQualifiers exists in the current object, otherwise is false.
		bool ActivityQualifiersExists() const;

		// Remove ActivityQualifiers field.
		void RemoveActivityQualifiers(); 

		// Optional, Defines the semantics of corresponding entries in the ActivityQualifiers array. An example of each of these 'formats' and their use follows: 
		// - 2=Class Name. Example: If the authorization target is a CIM Service or a Namespace, then the ActivityQualifiers entries can define a list of classes that the authorized subject is able to create or delete. 
		// - 3=<Class.>Property. Example: If the authorization target is a CIM Service, Namespace or Collection of instances, then the ActivityQualifiers entries can define the class properties that may or may not be accessed. In this case, the class names are specified with the property names to avoid ambiguity - since a CIM Service, Namespace or Collection could manage multiple classes. On the other hand, if the authorization target is an individual instance, then there is no possible ambiguity and the class name may be omitted. To specify ALL properties, the wildcard string "*" should be used. 
		// - 4=<Class.>Method. This example is very similar to the Property one, above. And, as above, the string "*" may be specified to select ALL methods. 
		// - 5=Object Reference. Example: If the authorization target is a CIM Service or Namespace, then the ActivityQualifiers entries can define a list of object references (as strings) that the authorized subject can access. 
		// - 6=Namespace. Example: If the authorization target is a CIM Service, then the ActivityQualifiers entries can define a list of Namespaces that the authorized subject is able to access. 
		// - 7=URL. Example: An authorization target may not be defined, but a Privilege could be used to deny access to specific URLs by individual Identities or for specific Roles, such as the 'under 17' Role. 
		// - 8=Directory/File Name. Example: If the authorization target is a FileSystem, then the ActivityQualifiers entries can define a list of directories and files whose access is protected. 
		// - 9=Command Line Instruction. Example: If the authorization target is a ComputerSystem or Service, then the ActivityQualifiers entries can define a list of command line instructions that may or may not be 'Executed' by the authorized subjects. 
		// - 10=SCSI Command, using a format of 'CDB=xx[,Page=pp]'. For example, the ability to select the VPD page of the Inquiry command is encoded as 'CDB=12,Page=83' in the corresponding ActivityQualifiers entry. A '*' may be used to indicate all CDBs or Page numbers. 
		// - 11=Packets. Example: The transmission of packets is permitted or denied by the Privilege for the target (a ComputerSystem, ProtocolEndpoint, Pipe, or other ManagedSystemElement).
		const vector<unsigned short> QualifierFormats() const;

		// Optional, Defines the semantics of corresponding entries in the ActivityQualifiers array. An example of each of these 'formats' and their use follows: 
		// - 2=Class Name. Example: If the authorization target is a CIM Service or a Namespace, then the ActivityQualifiers entries can define a list of classes that the authorized subject is able to create or delete. 
		// - 3=<Class.>Property. Example: If the authorization target is a CIM Service, Namespace or Collection of instances, then the ActivityQualifiers entries can define the class properties that may or may not be accessed. In this case, the class names are specified with the property names to avoid ambiguity - since a CIM Service, Namespace or Collection could manage multiple classes. On the other hand, if the authorization target is an individual instance, then there is no possible ambiguity and the class name may be omitted. To specify ALL properties, the wildcard string "*" should be used. 
		// - 4=<Class.>Method. This example is very similar to the Property one, above. And, as above, the string "*" may be specified to select ALL methods. 
		// - 5=Object Reference. Example: If the authorization target is a CIM Service or Namespace, then the ActivityQualifiers entries can define a list of object references (as strings) that the authorized subject can access. 
		// - 6=Namespace. Example: If the authorization target is a CIM Service, then the ActivityQualifiers entries can define a list of Namespaces that the authorized subject is able to access. 
		// - 7=URL. Example: An authorization target may not be defined, but a Privilege could be used to deny access to specific URLs by individual Identities or for specific Roles, such as the 'under 17' Role. 
		// - 8=Directory/File Name. Example: If the authorization target is a FileSystem, then the ActivityQualifiers entries can define a list of directories and files whose access is protected. 
		// - 9=Command Line Instruction. Example: If the authorization target is a ComputerSystem or Service, then the ActivityQualifiers entries can define a list of command line instructions that may or may not be 'Executed' by the authorized subjects. 
		// - 10=SCSI Command, using a format of 'CDB=xx[,Page=pp]'. For example, the ability to select the VPD page of the Inquiry command is encoded as 'CDB=12,Page=83' in the corresponding ActivityQualifiers entry. A '*' may be used to indicate all CDBs or Page numbers. 
		// - 11=Packets. Example: The transmission of packets is permitted or denied by the Privilege for the target (a ComputerSystem, ProtocolEndpoint, Pipe, or other ManagedSystemElement).
		void QualifierFormats(const vector<unsigned short> &value); 

		// Is true if the field QualifierFormats exists in the current object, otherwise is false.
		bool QualifierFormatsExists() const;

		// Remove QualifierFormats field.
		void RemoveQualifierFormats(); 

		// Optional, The RepresentsAuthorizationRights flag indicates whether the rights defined by this instance should be interpreted as rights of Subjects to access Targets or as rights of Subjects to change those rights on/for Targets.
		const bool RepresentsAuthorizationRights() const;

		// Optional, The RepresentsAuthorizationRights flag indicates whether the rights defined by this instance should be interpreted as rights of Subjects to access Targets or as rights of Subjects to change those rights on/for Targets.
		void RepresentsAuthorizationRights(const bool value); 

		// Is true if the field RepresentsAuthorizationRights exists in the current object, otherwise is false.
		bool RepresentsAuthorizationRightsExists() const;

		// Remove RepresentsAuthorizationRights field.
		void RemoveRepresentsAuthorizationRights(); 

		 // Function used by the factory
		static CimBase *CreateFromCimObject(const CimObject &object);

		static vector<shared_ptr<CIM_Privilege> > Enumerate(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		// Overloaded delete which supplies the internal resourceURI
		static void Delete(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		using CimBase::Delete;

	protected:
		 // Protected constructor to be used by derived classes
		CIM_Privilege(ICimWsmanClient *client, const string &class_name,
			const string &class_ns, const string &prefix, const string &uri): CIM_ManagedElement(client, class_name, class_ns, prefix, uri)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_ManagedElement::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 6);
			}
		}
		 // Protected constructor which receives CimObject
		CIM_Privilege(const CimObject &object)
			: CIM_ManagedElement(object)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_ManagedElement::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 6);
			}
		}
		// Called by derived classes
		void SetMetaData(vector<CimFieldAttribute>& childMetaData)
		{
			CIM_ManagedElement::SetMetaData(childMetaData);
			CimBase::SetMetaData(childMetaData, _metadata, 6);
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
#endif // CIM_PRIVILEGE_H
