//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_AssociatedPrivilege.h
//
//  Contents:   CIM_AssociatedPrivilege is an association that models the privileges that a Subject element has to access or authorize other elements to access a Target element.
//
//              This file was automatically generated from CIM_AssociatedPrivilege.mof,  version: 2.22.0
//
//----------------------------------------------------------------------------
#ifndef CIM_ASSOCIATEDPRIVILEGE_H
#define CIM_ASSOCIATEDPRIVILEGE_H 1
#include "../../include/CimBase.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	// CIM_AssociatedPrivilege is an association that models the privileges that a Subject element has to access or authorize other elements to access a Target element.
	class CIMFRAMEWORK_API CIM_AssociatedPrivilege  : public CimBase
	{
	public:

		//Default constructor
		CIM_AssociatedPrivilege()
			: CimBase(NULL, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CimBase::SetMetaData(_classMetaData, _metadata, 8);
			}
		}

		//constructor which receives WSMan client
		CIM_AssociatedPrivilege(ICimWsmanClient *client)
			: CimBase(client, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CimBase::SetMetaData(_classMetaData, _metadata, 8);
			}
		}

		//Destructor
		virtual ~CIM_AssociatedPrivilege(){}

		// The "type" information for the object. Gettors only.
		virtual const string& ResourceURI() const { return CLASS_URI; }
		static const string& ClassResourceURI() { return CLASS_URI; }
		virtual const string& XmlNamespace() const { return CLASS_NS; }
		virtual const string& XmlPrefix() const { return CLASS_NS_PREFIX; }
		virtual const string& ObjectType() const { return CLASS_NAME; }
		static const string& ClassObjectType() { return CLASS_NAME; }

		// Class representing CIM_AssociatedPrivilege keys
		class CimKeys : public CimBase::CimKeys
		{
		public:
			// Key, Required, The Subject for which privileges are granted or denied.
			const CimReference Subject() const
			{
				CimReference ret;
				TypeConverter::StringToType(GetKey("Subject"), ret);
				return ret;
			}

			// Key, Required, The Subject for which privileges are granted or denied.
			void Subject(const CimReference &value)
			{
				SetOrAddKey("Subject", TypeConverter::TypeToString(value), true);
			}

			// Key, Required, The target element to which the privileges apply.
			const CimReference Target() const
			{
				CimReference ret;
				TypeConverter::StringToType(GetKey("Target"), ret);
				return ret;
			}

			// Key, Required, The target element to which the privileges apply.
			void Target(const CimReference &value)
			{
				SetOrAddKey("Target", TypeConverter::TypeToString(value), true);
			}

			// Key, Required, UseKey is used to distinguish instances in case multiple instances of this association exist between the same Subject and Target. This may arise, for example, if separate instances are created for each management domain, or if the Subject has access and authorization rights to the Target.
			// Within the scope of the instantiating Namespace, UseKey opaquely and uniquely identifies an instance of this class. In order to ensure uniqueness within the NameSpace, the value of UseKey should be constructed using the following 'preferred' algorithm: 
			// <OrgID>:<LocalID> 
			// Where <OrgID> and <LocalID> are separated by a colon ':', and where <OrgID> shall include a copyrighted, trademarked or otherwise unique name that is owned by the business entity creating/defining the UseKey, or is a registered ID that is assigned to the business entity by a recognized global authority. (This is similar to the <Schema Name>_<Class Name> structure of Schema class names.) In addition, to ensure uniqueness <OrgID> shall not contain a colon (':'). When using this algorithm, the first colon to appear in UseKey shall appear between <OrgID> and <LocalID>. 
			// <LocalID> is chosen by the business entity and should not be re-used to identify different underlying (real-world) elements. If the above 'preferred' algorithm is not used, the defining entity shall assure that the resultant UseKey is not re-used across any UseKeys produced by this or other providers for this instance's NameSpace. 
			// For DMTF defined instances, the 'preferred' algorithm shall be used with the <OrgID> set to 'CIM'.
			const string UseKey() const
			{
				return GetKey("UseKey");
			}

			// Key, Required, UseKey is used to distinguish instances in case multiple instances of this association exist between the same Subject and Target. This may arise, for example, if separate instances are created for each management domain, or if the Subject has access and authorization rights to the Target.
			// Within the scope of the instantiating Namespace, UseKey opaquely and uniquely identifies an instance of this class. In order to ensure uniqueness within the NameSpace, the value of UseKey should be constructed using the following 'preferred' algorithm: 
			// <OrgID>:<LocalID> 
			// Where <OrgID> and <LocalID> are separated by a colon ':', and where <OrgID> shall include a copyrighted, trademarked or otherwise unique name that is owned by the business entity creating/defining the UseKey, or is a registered ID that is assigned to the business entity by a recognized global authority. (This is similar to the <Schema Name>_<Class Name> structure of Schema class names.) In addition, to ensure uniqueness <OrgID> shall not contain a colon (':'). When using this algorithm, the first colon to appear in UseKey shall appear between <OrgID> and <LocalID>. 
			// <LocalID> is chosen by the business entity and should not be re-used to identify different underlying (real-world) elements. If the above 'preferred' algorithm is not used, the defining entity shall assure that the resultant UseKey is not re-used across any UseKeys produced by this or other providers for this instance's NameSpace. 
			// For DMTF defined instances, the 'preferred' algorithm shall be used with the <OrgID> set to 'CIM'.
			void UseKey(const string &value)
			{
				SetOrAddKey("UseKey", value);
			}

		};

		// class fields declarations

		// Key, Required, The Subject for which privileges are granted or denied.
		const CimReference Subject() const;

		// Key, Required, The Subject for which privileges are granted or denied.
		void Subject(const CimReference &value); 


		// Key, Required, The target element to which the privileges apply.
		const CimReference Target() const;

		// Key, Required, The target element to which the privileges apply.
		void Target(const CimReference &value); 


		// Key, Required, UseKey is used to distinguish instances in case multiple instances of this association exist between the same Subject and Target. This may arise, for example, if separate instances are created for each management domain, or if the Subject has access and authorization rights to the Target.
		// Within the scope of the instantiating Namespace, UseKey opaquely and uniquely identifies an instance of this class. In order to ensure uniqueness within the NameSpace, the value of UseKey should be constructed using the following 'preferred' algorithm: 
		// <OrgID>:<LocalID> 
		// Where <OrgID> and <LocalID> are separated by a colon ':', and where <OrgID> shall include a copyrighted, trademarked or otherwise unique name that is owned by the business entity creating/defining the UseKey, or is a registered ID that is assigned to the business entity by a recognized global authority. (This is similar to the <Schema Name>_<Class Name> structure of Schema class names.) In addition, to ensure uniqueness <OrgID> shall not contain a colon (':'). When using this algorithm, the first colon to appear in UseKey shall appear between <OrgID> and <LocalID>. 
		// <LocalID> is chosen by the business entity and should not be re-used to identify different underlying (real-world) elements. If the above 'preferred' algorithm is not used, the defining entity shall assure that the resultant UseKey is not re-used across any UseKeys produced by this or other providers for this instance's NameSpace. 
		// For DMTF defined instances, the 'preferred' algorithm shall be used with the <OrgID> set to 'CIM'.
		const string UseKey() const;

		// Key, Required, UseKey is used to distinguish instances in case multiple instances of this association exist between the same Subject and Target. This may arise, for example, if separate instances are created for each management domain, or if the Subject has access and authorization rights to the Target.
		// Within the scope of the instantiating Namespace, UseKey opaquely and uniquely identifies an instance of this class. In order to ensure uniqueness within the NameSpace, the value of UseKey should be constructed using the following 'preferred' algorithm: 
		// <OrgID>:<LocalID> 
		// Where <OrgID> and <LocalID> are separated by a colon ':', and where <OrgID> shall include a copyrighted, trademarked or otherwise unique name that is owned by the business entity creating/defining the UseKey, or is a registered ID that is assigned to the business entity by a recognized global authority. (This is similar to the <Schema Name>_<Class Name> structure of Schema class names.) In addition, to ensure uniqueness <OrgID> shall not contain a colon (':'). When using this algorithm, the first colon to appear in UseKey shall appear between <OrgID> and <LocalID>. 
		// <LocalID> is chosen by the business entity and should not be re-used to identify different underlying (real-world) elements. If the above 'preferred' algorithm is not used, the defining entity shall assure that the resultant UseKey is not re-used across any UseKeys produced by this or other providers for this instance's NameSpace. 
		// For DMTF defined instances, the 'preferred' algorithm shall be used with the <OrgID> set to 'CIM'.
		void UseKey(const string &value); 


		// Optional, Boolean indicating whether the Privilege is granted (TRUE) or denied (FALSE). The default is to grant permission.
		const bool PrivilegeGranted() const;

		// Optional, Boolean indicating whether the Privilege is granted (TRUE) or denied (FALSE). The default is to grant permission.
		void PrivilegeGranted(const bool value); 

		// Is true if the field PrivilegeGranted exists in the current object, otherwise is false.
		bool PrivilegeGrantedExists() const;

		// Remove PrivilegeGranted field.
		void RemovePrivilegeGranted(); 

		// Optional, An enumeration indicating the activities that are granted or denied. These activities apply to all entities specified in the ActivityQualifiers array.
		// "Other" (1): indicates an activity that is not specified in this enumeration.
		// "Create" (2), "Delete" (3), "Detect" (4), "Read" (5), "Write" (6), "Execute" (7): each of these values indicates that the Subject is permitted to use an operation supported by the Target. They are all straightforward except for one, 4="Detect". This value indicates that the existence or presence of an entity may be determined, but not necessarily specific data (which requires the Read privilege to be true). This activity is exemplified by 'hidden files'- if you list the contents of a directory, you will not see hidden files. However, if you know a specific file name, or know how to expose hidden files, then they can be 'detected'. Another example is the ability to define search privileges in directory implementations.
		// "Deny Create" (8), "Deny Delete" (9), "Deny Detect" (10), "Deny Read" (11), "Deny Write" (12), "Deny Execute" (13): each of these values indicates that the Subject is expressly denied permission to use an operation supported by the Target.
		// Authorize to Grant/Deny Authorization (14): this value indicates that the Subject is permitted to add any of the following values to - or remove any of the following values from - the Activities array property in any other instance of CIM_AssociatedPrivilege that references the same Target: "Authorize to Create" (15), "Authorize to Delete" (16), "Authorize to Detect" (17), "Authorize to Read" (18), "Authorize to Write" (19), "Authorize to Execute" (20), "Authorize to Deny Create" (21), "Authorize to Deny Delete" (22), "Authorize to Deny Detect" (23), "Authorize to Deny Read" (24), "Authorize to Deny Write" (25), and "Authorize to Deny Execute" (26).
		// "Authorize to Create" (15), "Authorize to Delete" (16), "Authorize to Detect" (17), "Authorize to Read" (18), "Authorize to Write" (19), "Authorize to Execute" (20), "Authorize to Deny Create" (21), "Authorize to Deny Delete" (22), "Authorize to Deny Detect" (23), "Authorize to Deny Read" (24), "Authorize to Deny Write" (25), and "Authorize to Deny Execute" (26): each of these values indicates that the Subject is permitted to add value named in the string to - or remove the value from - the Activities array property in any other instance of CIM_AssociatedPrivilege that references the same Target. For example, "Authorize to Read" indicates that the Subject is permitted to add or remove the value "Read", and "Authorize to Deny Read" indicates that the Subject is permitted to add or remove the value "Deny Read".
		const vector<unsigned short> Activities() const;

		// Optional, An enumeration indicating the activities that are granted or denied. These activities apply to all entities specified in the ActivityQualifiers array.
		// "Other" (1): indicates an activity that is not specified in this enumeration.
		// "Create" (2), "Delete" (3), "Detect" (4), "Read" (5), "Write" (6), "Execute" (7): each of these values indicates that the Subject is permitted to use an operation supported by the Target. They are all straightforward except for one, 4="Detect". This value indicates that the existence or presence of an entity may be determined, but not necessarily specific data (which requires the Read privilege to be true). This activity is exemplified by 'hidden files'- if you list the contents of a directory, you will not see hidden files. However, if you know a specific file name, or know how to expose hidden files, then they can be 'detected'. Another example is the ability to define search privileges in directory implementations.
		// "Deny Create" (8), "Deny Delete" (9), "Deny Detect" (10), "Deny Read" (11), "Deny Write" (12), "Deny Execute" (13): each of these values indicates that the Subject is expressly denied permission to use an operation supported by the Target.
		// Authorize to Grant/Deny Authorization (14): this value indicates that the Subject is permitted to add any of the following values to - or remove any of the following values from - the Activities array property in any other instance of CIM_AssociatedPrivilege that references the same Target: "Authorize to Create" (15), "Authorize to Delete" (16), "Authorize to Detect" (17), "Authorize to Read" (18), "Authorize to Write" (19), "Authorize to Execute" (20), "Authorize to Deny Create" (21), "Authorize to Deny Delete" (22), "Authorize to Deny Detect" (23), "Authorize to Deny Read" (24), "Authorize to Deny Write" (25), and "Authorize to Deny Execute" (26).
		// "Authorize to Create" (15), "Authorize to Delete" (16), "Authorize to Detect" (17), "Authorize to Read" (18), "Authorize to Write" (19), "Authorize to Execute" (20), "Authorize to Deny Create" (21), "Authorize to Deny Delete" (22), "Authorize to Deny Detect" (23), "Authorize to Deny Read" (24), "Authorize to Deny Write" (25), and "Authorize to Deny Execute" (26): each of these values indicates that the Subject is permitted to add value named in the string to - or remove the value from - the Activities array property in any other instance of CIM_AssociatedPrivilege that references the same Target. For example, "Authorize to Read" indicates that the Subject is permitted to add or remove the value "Read", and "Authorize to Deny Read" indicates that the Subject is permitted to add or remove the value "Deny Read".
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
		// - 12=Specification-defined. The semantics are defined in a a specification produced by the DMTF or other organization. The value of the corresponding ActivityQualifiers entry names the specification and the organization that produced it, and includes a label that unambiguously references the semantic definition within the specification. The value of of the corresponding ActivityQualifiers entry should be constructed using the following "preferred" algorithm: 
		// <OrgID>:<SpecID>:<Label>, where <OrgID>, <SpecID>, and <Label> are separated by a colon (:), and where <OrgID> shall include a copyrighted, trademarked, or otherwise unique name that is owned by the business entity that is creating or defining the InstanceID or that is a registered ID assigned to the business entity by a recognized global authority. (This requirement is similar to the <Schema Name>_<Class Name> structure of Schema class names.) In addition, to ensure uniqueness both <OrgID> and <SpecID> shall not contain a colon (':'). When using this algorithm, the first colon to appear in the corresponding ActivityQualifiers entry shall appear between <OrgID> and <SpecID> and the second colon to appear in the corresponding ActivityQualifiers entry shall appear between <SpecID> and <Label>. 
		// <Label> is chosen by the business entity and should not be reused to identify different underlying semantics. If the above "preferred" algorithm is not used, the defining entity must assure that the resulting value is not reused to refer to a different specification or different semantics within defined within the same specification.
		// For DMTF-defined instances, the "preferred" algorithm shall be used with the <OrgID> set to "DMTF", and the <SpecID> set to "DSPx", where x is the number of a DSP published by the DMTF.
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
		// - 12=Specification-defined. The semantics are defined in a a specification produced by the DMTF or other organization. The value of the corresponding ActivityQualifiers entry names the specification and the organization that produced it, and includes a label that unambiguously references the semantic definition within the specification. The value of of the corresponding ActivityQualifiers entry should be constructed using the following "preferred" algorithm: 
		// <OrgID>:<SpecID>:<Label>, where <OrgID>, <SpecID>, and <Label> are separated by a colon (:), and where <OrgID> shall include a copyrighted, trademarked, or otherwise unique name that is owned by the business entity that is creating or defining the InstanceID or that is a registered ID assigned to the business entity by a recognized global authority. (This requirement is similar to the <Schema Name>_<Class Name> structure of Schema class names.) In addition, to ensure uniqueness both <OrgID> and <SpecID> shall not contain a colon (':'). When using this algorithm, the first colon to appear in the corresponding ActivityQualifiers entry shall appear between <OrgID> and <SpecID> and the second colon to appear in the corresponding ActivityQualifiers entry shall appear between <SpecID> and <Label>. 
		// <Label> is chosen by the business entity and should not be reused to identify different underlying semantics. If the above "preferred" algorithm is not used, the defining entity must assure that the resulting value is not reused to refer to a different specification or different semantics within defined within the same specification.
		// For DMTF-defined instances, the "preferred" algorithm shall be used with the <OrgID> set to "DMTF", and the <SpecID> set to "DSPx", where x is the number of a DSP published by the DMTF.
		void QualifierFormats(const vector<unsigned short> &value); 

		// Is true if the field QualifierFormats exists in the current object, otherwise is false.
		bool QualifierFormatsExists() const;

		// Remove QualifierFormats field.
		void RemoveQualifierFormats(); 

		// Optional, The RepresentsAuthorizationRights flag indicates whether the rights defined by this instance shall be interpreted as rights of Subjects to access Targets or as rights of Subjects to change those rights on/for Targets.
		const bool RepresentsAuthorizationRights() const;

		// Optional, The RepresentsAuthorizationRights flag indicates whether the rights defined by this instance shall be interpreted as rights of Subjects to access Targets or as rights of Subjects to change those rights on/for Targets.
		void RepresentsAuthorizationRights(const bool value); 

		// Is true if the field RepresentsAuthorizationRights exists in the current object, otherwise is false.
		bool RepresentsAuthorizationRightsExists() const;

		// Remove RepresentsAuthorizationRights field.
		void RemoveRepresentsAuthorizationRights(); 

		 // Function used by the factory
		static CimBase *CreateFromCimObject(const CimObject &object);

		static vector<shared_ptr<CIM_AssociatedPrivilege> > Enumerate(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		// Overloaded delete which supplies the internal resourceURI
		static void Delete(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		using CimBase::Delete;

	protected:
		 // Protected constructor to be used by derived classes
		CIM_AssociatedPrivilege(ICimWsmanClient *client, const string &class_name,
			const string &class_ns, const string &prefix, const string &uri): CimBase(client, class_name, class_ns, prefix, uri)
		{
			if(_classMetaData.size() == 0)
			{
				CimBase::SetMetaData(_classMetaData, _metadata, 8);
			}
		}
		 // Protected constructor which receives CimObject
		CIM_AssociatedPrivilege(const CimObject &object)
			: CimBase(object)
		{
			if(_classMetaData.size() == 0)
			{
				CimBase::SetMetaData(_classMetaData, _metadata, 8);
			}
		}
		// Called by derived classes
		void SetMetaData(vector<CimFieldAttribute>& childMetaData)
		{
			CimBase::SetMetaData(childMetaData, _metadata, 8);
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
#endif // CIM_ASSOCIATEDPRIVILEGE_H
