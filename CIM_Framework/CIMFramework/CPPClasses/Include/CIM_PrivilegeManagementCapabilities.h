//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_PrivilegeManagementCapabilities.h
//
//  Contents:   A subclass of Capabilities that defines the capabilities of the Privilege Management Service.
//
//              This file was automatically generated from CIM_PrivilegeManagementCapabilities.mof,  version: 2.18.0
//
//----------------------------------------------------------------------------
#ifndef CIM_PRIVILEGEMANAGEMENTCAPABILITIES_H
#define CIM_PRIVILEGEMANAGEMENTCAPABILITIES_H 1
#include "CIM_Capabilities.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	// A subclass of Capabilities that defines the capabilities of the Privilege Management Service.
	class CIMFRAMEWORK_API CIM_PrivilegeManagementCapabilities  : public CIM_Capabilities
	{
	public:

		//Default constructor
		CIM_PrivilegeManagementCapabilities()
			: CIM_Capabilities(NULL, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_Capabilities::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 5);
			}
		}

		//constructor which receives WSMan client
		CIM_PrivilegeManagementCapabilities(ICimWsmanClient *client)
			: CIM_Capabilities(client, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_Capabilities::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 5);
			}
		}

		//Destructor
		virtual ~CIM_PrivilegeManagementCapabilities(){}

		// The "type" information for the object. Gettors only.
		virtual const string& ResourceURI() const { return CLASS_URI; }
		static const string& ClassResourceURI() { return CLASS_URI; }
		virtual const string& XmlNamespace() const { return CLASS_NS; }
		virtual const string& XmlPrefix() const { return CLASS_NS_PREFIX; }
		virtual const string& ObjectType() const { return CLASS_NAME; }
		static const string& ClassObjectType() { return CLASS_NAME; }

		// Class representing CIM_PrivilegeManagementCapabilities keys
		class CimKeys : public CIM_Capabilities::CimKeys
		{
		public:
		};

		// class fields declarations

		// Optional, Set to TRUE if this PrivilegeManagementService supports association of multiple subjects or targets to a particular Privilege. If False, the AssignAccess method supports at most one entry each in the Subjects and Targets parameters.
		const bool SharedPrivilegeSupported() const;

		// Optional, Set to TRUE if this PrivilegeManagementService supports association of multiple subjects or targets to a particular Privilege. If False, the AssignAccess method supports at most one entry each in the Subjects and Targets parameters.
		void SharedPrivilegeSupported(const bool value); 

		// Is true if the field SharedPrivilegeSupported exists in the current object, otherwise is false.
		bool SharedPrivilegeSupportedExists() const;

		// Remove SharedPrivilegeSupported field.
		void RemoveSharedPrivilegeSupported(); 

		// Optional, A super set of activities that could be granted or denied to a role or an identity by the associated privileges. The Activities property of the instances of CIM_Privilege that are associated to the role or the identity MUST contain only the values enumerated in the ActivitiesSupported array property. The supported activities apply to all entities specified in the ActivityQualifiersSupported array. Refer to the CIM_Privilege.Activities property for the detailed description of values.
		const vector<unsigned short> ActivitiesSupported() const;

		// Optional, A super set of activities that could be granted or denied to a role or an identity by the associated privileges. The Activities property of the instances of CIM_Privilege that are associated to the role or the identity MUST contain only the values enumerated in the ActivitiesSupported array property. The supported activities apply to all entities specified in the ActivityQualifiersSupported array. Refer to the CIM_Privilege.Activities property for the detailed description of values.
		void ActivitiesSupported(const vector<unsigned short> &value); 

		// Is true if the field ActivitiesSupported exists in the current object, otherwise is false.
		bool ActivitiesSupportedExists() const;

		// Remove ActivitiesSupported field.
		void RemoveActivitiesSupported(); 

		// Optional, The ActivityQualifiersSupported property is an array of string values used to further qualify and specify the supported activities of privileges. The ActivityQualifiers property of the instances of CIM_Privilege that are associated to the role or the identity MUST contain only the values enumerated in the ActivityQualifiersSupported array property. Details on the semantics of the individual entries in ActivityQualifiersSupported are provided by corresponding entries in the QualifierFormatsSupported array. Refer to the CIM_Privilege.ActivityQualifiers property for the detailed description of values.
		const vector<string> ActivityQualifiersSupported() const;

		// Optional, The ActivityQualifiersSupported property is an array of string values used to further qualify and specify the supported activities of privileges. The ActivityQualifiers property of the instances of CIM_Privilege that are associated to the role or the identity MUST contain only the values enumerated in the ActivityQualifiersSupported array property. Details on the semantics of the individual entries in ActivityQualifiersSupported are provided by corresponding entries in the QualifierFormatsSupported array. Refer to the CIM_Privilege.ActivityQualifiers property for the detailed description of values.
		void ActivityQualifiersSupported(const vector<string> &value); 

		// Is true if the field ActivityQualifiersSupported exists in the current object, otherwise is false.
		bool ActivityQualifiersSupportedExists() const;

		// Remove ActivityQualifiersSupported field.
		void RemoveActivityQualifiersSupported(); 

		// Optional, Defines the semantics of corresponding entries in the ActivityQualifierSupported array. The QualifierSupported property of the instances of CIM_Privilege that are associated to the role or the identity MUST contain only the values enumerated in the QualifierSupported array property. Refer to the CIM_Privilege.QualifierSupported property for the detailed description of values.
		const vector<unsigned short> QualifierFormatsSupported() const;

		// Optional, Defines the semantics of corresponding entries in the ActivityQualifierSupported array. The QualifierSupported property of the instances of CIM_Privilege that are associated to the role or the identity MUST contain only the values enumerated in the QualifierSupported array property. Refer to the CIM_Privilege.QualifierSupported property for the detailed description of values.
		void QualifierFormatsSupported(const vector<unsigned short> &value); 

		// Is true if the field QualifierFormatsSupported exists in the current object, otherwise is false.
		bool QualifierFormatsSupportedExists() const;

		// Remove QualifierFormatsSupported field.
		void RemoveQualifierFormatsSupported(); 

		// Optional, Each enumeration corresponds to support for the like-named method of the PrivilegeManagementService.
		const vector<unsigned short> SupportedMethods() const;

		// Optional, Each enumeration corresponds to support for the like-named method of the PrivilegeManagementService.
		void SupportedMethods(const vector<unsigned short> &value); 

		// Is true if the field SupportedMethods exists in the current object, otherwise is false.
		bool SupportedMethodsExists() const;

		// Remove SupportedMethods field.
		void RemoveSupportedMethods(); 

		 // Function used by the factory
		static CimBase *CreateFromCimObject(const CimObject &object);

		static vector<shared_ptr<CIM_PrivilegeManagementCapabilities> > Enumerate(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		// Overloaded delete which supplies the internal resourceURI
		static void Delete(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		using CimBase::Delete;

	protected:
		 // Protected constructor to be used by derived classes
		CIM_PrivilegeManagementCapabilities(ICimWsmanClient *client, const string &class_name,
			const string &class_ns, const string &prefix, const string &uri): CIM_Capabilities(client, class_name, class_ns, prefix, uri)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_Capabilities::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 5);
			}
		}
		 // Protected constructor which receives CimObject
		CIM_PrivilegeManagementCapabilities(const CimObject &object)
			: CIM_Capabilities(object)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_Capabilities::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 5);
			}
		}
		// Called by derived classes
		void SetMetaData(vector<CimFieldAttribute>& childMetaData)
		{
			CIM_Capabilities::SetMetaData(childMetaData);
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
#endif // CIM_PRIVILEGEMANAGEMENTCAPABILITIES_H
