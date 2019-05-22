//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_RegisteredProfile.h
//
//  Contents:   A RegisteredProfile describes a set of CIM Schema classes with required properties and/or methods, necessary to manage a real-world entity or to support a usage scenario, in an interoperable fashion. RegisteredProfiles can be defined by the DMTF or other standards organizations. Note that this class should not be confused with CIM_Profile, which collects SettingData instances, to be applied as a 'configuration profile' for an element. 
//              A RegisteredProfile is a named 'standard' for CIM-based management of a particular System, subsystem, Service or other entity, for a specified set of uses. It is a complete, standalone definition, as opposed to the subclass RegisteredSubProfile, which requires a scoping profile for context. 
//              The uses for a RegisteredProfile or SubProfile MUST be specified in the document that defines the profile. Examples of Profiles are to manage various aspects of an Operating System, Storage Array, or Database. The name of the profile is defined and scoped by its authoring organization.
//
//              This file was automatically generated from CIM_RegisteredProfile.mof,  version: 2.27.0
//
//----------------------------------------------------------------------------
#ifndef CIM_REGISTEREDPROFILE_H
#define CIM_REGISTEREDPROFILE_H 1
#include "CIM_ManagedElement.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	// A RegisteredProfile describes a set of CIM Schema classes with required properties and/or methods, necessary to manage a real-world entity or to support a usage scenario, in an interoperable fashion. RegisteredProfiles can be defined by the DMTF or other standards organizations. Note that this class should not be confused with CIM_Profile, which collects SettingData instances, to be applied as a 'configuration profile' for an element. 
	// A RegisteredProfile is a named 'standard' for CIM-based management of a particular System, subsystem, Service or other entity, for a specified set of uses. It is a complete, standalone definition, as opposed to the subclass RegisteredSubProfile, which requires a scoping profile for context. 
	// The uses for a RegisteredProfile or SubProfile MUST be specified in the document that defines the profile. Examples of Profiles are to manage various aspects of an Operating System, Storage Array, or Database. The name of the profile is defined and scoped by its authoring organization.
	class CIMFRAMEWORK_API CIM_RegisteredProfile  : public CIM_ManagedElement
	{
	public:

		//Default constructor
		CIM_RegisteredProfile()
			: CIM_ManagedElement(NULL, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_ManagedElement::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 8);
			}
		}

		//constructor which receives WSMan client
		CIM_RegisteredProfile(ICimWsmanClient *client)
			: CIM_ManagedElement(client, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_ManagedElement::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 8);
			}
		}

		//Destructor
		virtual ~CIM_RegisteredProfile(){}

		// The "type" information for the object. Gettors only.
		virtual const string& ResourceURI() const { return CLASS_URI; }
		static const string& ClassResourceURI() { return CLASS_URI; }
		virtual const string& XmlNamespace() const { return CLASS_NS; }
		virtual const string& XmlPrefix() const { return CLASS_NS_PREFIX; }
		virtual const string& ObjectType() const { return CLASS_NAME; }
		static const string& ClassObjectType() { return CLASS_NAME; }

		// Class representing CIM_RegisteredProfile keys
		class CimKeys : public CIM_ManagedElement::CimKeys
		{
		public:
			// Key, Required, Within the scope of the instantiating Namespace, InstanceID opaquely and uniquely identifies an instance of this class. In order to ensure uniqueness within the NameSpace, the value of InstanceID SHOULD be constructed using the following 'preferred' algorithm: 
			// <OrgID>:<LocalID> 
			// Where <OrgID> and <LocalID> are separated by a colon ':', and where <OrgID> MUST include a copyrighted, trademarked or otherwise unique name that is owned by the business entity creating/defining the InstanceID, or is a registered ID that is assigned to the business entity by a recognized global authority. (This is similar to the <Schema Name>_<Class Name> structure of Schema class names.) In addition, to ensure uniqueness, <OrgID> MUST NOT contain a colon (':'). When using this algorithm, the first colon to appear in InstanceID MUST appear between <OrgID> and <LocalID>. 
			// <LocalID> is chosen by the organizational entity and SHOULD not be re-used to identify different underlying (real-world) elements. If the above 'preferred' algorithm is not used, the defining entity MUST assure that the resultant InstanceID is not re-used across any InstanceIDs produced by this or other providers for this instance's NameSpace. 
			// For DMTF defined instances, the 'preferred' algorithm MUST be used with the <OrgID> set to 'CIM'.
			const string InstanceID() const
			{
				return GetKey("InstanceID");
			}

			// Key, Required, Within the scope of the instantiating Namespace, InstanceID opaquely and uniquely identifies an instance of this class. In order to ensure uniqueness within the NameSpace, the value of InstanceID SHOULD be constructed using the following 'preferred' algorithm: 
			// <OrgID>:<LocalID> 
			// Where <OrgID> and <LocalID> are separated by a colon ':', and where <OrgID> MUST include a copyrighted, trademarked or otherwise unique name that is owned by the business entity creating/defining the InstanceID, or is a registered ID that is assigned to the business entity by a recognized global authority. (This is similar to the <Schema Name>_<Class Name> structure of Schema class names.) In addition, to ensure uniqueness, <OrgID> MUST NOT contain a colon (':'). When using this algorithm, the first colon to appear in InstanceID MUST appear between <OrgID> and <LocalID>. 
			// <LocalID> is chosen by the organizational entity and SHOULD not be re-used to identify different underlying (real-world) elements. If the above 'preferred' algorithm is not used, the defining entity MUST assure that the resultant InstanceID is not re-used across any InstanceIDs produced by this or other providers for this instance's NameSpace. 
			// For DMTF defined instances, the 'preferred' algorithm MUST be used with the <OrgID> set to 'CIM'.
			void InstanceID(const string &value)
			{
				SetOrAddKey("InstanceID", value);
			}

		};

		// class fields declarations

		// Required, The organization that defines this profile.
		const unsigned short RegisteredOrganization() const;

		// Required, The organization that defines this profile.
		void RegisteredOrganization(const unsigned short value); 

		// Is true if the field RegisteredOrganization exists in the current object, otherwise is false.
		bool RegisteredOrganizationExists() const;

		// Remove RegisteredOrganization field.
		void RemoveRegisteredOrganization(); 

		// Optional, A free-form string providing a description of the organization when 1, "Other", is specified for the RegisteredOrganization.
		const string OtherRegisteredOrganization() const;

		// Optional, A free-form string providing a description of the organization when 1, "Other", is specified for the RegisteredOrganization.
		void OtherRegisteredOrganization(const string &value); 

		// Is true if the field OtherRegisteredOrganization exists in the current object, otherwise is false.
		bool OtherRegisteredOrganizationExists() const;

		// Remove OtherRegisteredOrganization field.
		void RemoveOtherRegisteredOrganization(); 

		// Required, The name of this registered profile. Since multiple versions can exist for the same RegisteredName, the combination of RegisteredName, RegisteredOrganization, and RegisteredVersion MUST uniquely identify the registered profile within the scope of the organization.
		const string RegisteredName() const;

		// Required, The name of this registered profile. Since multiple versions can exist for the same RegisteredName, the combination of RegisteredName, RegisteredOrganization, and RegisteredVersion MUST uniquely identify the registered profile within the scope of the organization.
		void RegisteredName(const string &value); 

		// Is true if the field RegisteredName exists in the current object, otherwise is false.
		bool RegisteredNameExists() const;

		// Remove RegisteredName field.
		void RemoveRegisteredName(); 

		// Required, The version of this profile. The string representing the version MUST be in the form: 
		// M + "." + N + "." + U 
		// Where: 
		// M - The major version (in numeric form) describing the profile's creation or last modification. 
		// N - The minor version (in numeric form) describing the profile's creation or last modification. 
		// U - The update (e.g. errata, patch, ..., in numeric form) describing the profile's creation or last modification.
		const string RegisteredVersion() const;

		// Required, The version of this profile. The string representing the version MUST be in the form: 
		// M + "." + N + "." + U 
		// Where: 
		// M - The major version (in numeric form) describing the profile's creation or last modification. 
		// N - The minor version (in numeric form) describing the profile's creation or last modification. 
		// U - The update (e.g. errata, patch, ..., in numeric form) describing the profile's creation or last modification.
		void RegisteredVersion(const string &value); 

		// Is true if the field RegisteredVersion exists in the current object, otherwise is false.
		bool RegisteredVersionExists() const;

		// Remove RegisteredVersion field.
		void RemoveRegisteredVersion(); 

		// Required, This property signifies the advertisement for the profile information. It is used by the advertising services of the WBEM infrastructure to determine what should be advertised, via what mechanisms. The property is an array so that the profile MAY be advertised using several mechanisms. Note: If this property is null/uninitialized, this is equivalent to specifying the value 2, "Not Advertised".
		const vector<unsigned short> AdvertiseTypes() const;

		// Required, This property signifies the advertisement for the profile information. It is used by the advertising services of the WBEM infrastructure to determine what should be advertised, via what mechanisms. The property is an array so that the profile MAY be advertised using several mechanisms. Note: If this property is null/uninitialized, this is equivalent to specifying the value 2, "Not Advertised".
		void AdvertiseTypes(const vector<unsigned short> &value); 

		// Is true if the field AdvertiseTypes exists in the current object, otherwise is false.
		bool AdvertiseTypesExists() const;

		// Remove AdvertiseTypes field.
		void RemoveAdvertiseTypes(); 

		// Optional, A free-form string providing additional information related to the AdvertiseType. A description MUST be provided when the AdvertiseType is 1, "Other". An entry in this array corresponds to the entry in the AdvertiseTypes array at the same index. It is not expected that additional descriptions are needed if the Type is set to "Not Advertised" or "SLP". However, as the SLP template expands, or as other advertisement mechanisms are defined, support for additional descriptions may be needed. This array is defined to support this.
		const vector<string> AdvertiseTypeDescriptions() const;

		// Optional, A free-form string providing additional information related to the AdvertiseType. A description MUST be provided when the AdvertiseType is 1, "Other". An entry in this array corresponds to the entry in the AdvertiseTypes array at the same index. It is not expected that additional descriptions are needed if the Type is set to "Not Advertised" or "SLP". However, as the SLP template expands, or as other advertisement mechanisms are defined, support for additional descriptions may be needed. This array is defined to support this.
		void AdvertiseTypeDescriptions(const vector<string> &value); 

		// Is true if the field AdvertiseTypeDescriptions exists in the current object, otherwise is false.
		bool AdvertiseTypeDescriptionsExists() const;

		// Remove AdvertiseTypeDescriptions field.
		void RemoveAdvertiseTypeDescriptions(); 

		// Optional, Profiles may gather a set of provisions together that are implemented, (or not implemented), as a whole by a conformant implementation. Such sets are known as profile features.
		// If a profile does not define features, then this property shall be null. 
		// If not null, an implementation shall put the profile defined feature name of each implemented feature in a separate entry of this array.
		const vector<string> ImplementedFeatures() const;

		// Optional, Profiles may gather a set of provisions together that are implemented, (or not implemented), as a whole by a conformant implementation. Such sets are known as profile features.
		// If a profile does not define features, then this property shall be null. 
		// If not null, an implementation shall put the profile defined feature name of each implemented feature in a separate entry of this array.
		void ImplementedFeatures(const vector<string> &value); 

		// Is true if the field ImplementedFeatures exists in the current object, otherwise is false.
		bool ImplementedFeaturesExists() const;

		// Remove ImplementedFeatures field.
		void RemoveImplementedFeatures(); 

		 // Function used by the factory
		static CimBase *CreateFromCimObject(const CimObject &object);

		static vector<shared_ptr<CIM_RegisteredProfile> > Enumerate(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		// Overloaded delete which supplies the internal resourceURI
		static void Delete(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		using CimBase::Delete;

	protected:
		 // Protected constructor to be used by derived classes
		CIM_RegisteredProfile(ICimWsmanClient *client, const string &class_name,
			const string &class_ns, const string &prefix, const string &uri): CIM_ManagedElement(client, class_name, class_ns, prefix, uri)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_ManagedElement::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 8);
			}
		}
		 // Protected constructor which receives CimObject
		CIM_RegisteredProfile(const CimObject &object)
			: CIM_ManagedElement(object)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_ManagedElement::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 8);
			}
		}
		// Called by derived classes
		void SetMetaData(vector<CimFieldAttribute>& childMetaData)
		{
			CIM_ManagedElement::SetMetaData(childMetaData);
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
#endif // CIM_REGISTEREDPROFILE_H
