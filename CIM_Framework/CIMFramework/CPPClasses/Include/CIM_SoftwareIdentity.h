//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_SoftwareIdentity.h
//
//  Contents:   SoftwareIdentity provides descriptive information about a software component for asset tracking and/or installation dependency management. When the IsEntity property has the value TRUE, the instance of SoftwareIdentity represents an individually identifiable entity similar to Physical Element. SoftwareIdentity does NOT indicate whether the software is installed, executing, etc. This extra information may be provided through specialized associations to Software Identity. For instance, both InstalledSoftwareIdentity and ElementSoftwareIdentity may be used to indicate that the software identified by this class is installed. SoftwareIdentity is used when managing the software components of a ManagedElement that is the management focus. Since software may be acquired, SoftwareIdentity can be associated with a Product using the ProductSoftwareComponent relationship. The Application Model manages the deployment and installation of software via the classes, SoftwareFeatures and SoftwareElements. SoftwareFeature and SoftwareElement are used when the software component is the management focus. The deployment/installation concepts are related to the asset/identity one. In fact, a SoftwareIdentity may correspond to a Product, or to one or more SoftwareFeatures or SoftwareElements - depending on the granularity of these classes and the deployment model. The correspondence of Software Identity to Product, SoftwareFeature or SoftwareElement is indicated using the ConcreteIdentity association. Note that there may not be sufficient detail or instrumentation to instantiate ConcreteIdentity. And, if the association is instantiated, some duplication of information may result. For example, the Vendor described in the instances of Product and SoftwareIdentity MAY be the same. However, this is not necessarily true, and it is why vendor and similar information are duplicated in this class. 
//              Note that ConcreteIdentity can also be used to describe the relationship of the software to any LogicalFiles that result from installing it. As above, there may not be sufficient detail or instrumentation to instantiate this association.
//
//              This file was automatically generated from CIM_SoftwareIdentity.mof,  version: 2.28.0
//
//----------------------------------------------------------------------------
#ifndef CIM_SOFTWAREIDENTITY_H
#define CIM_SOFTWAREIDENTITY_H 1
#include "CIM_LogicalElement.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	// SoftwareIdentity provides descriptive information about a software component for asset tracking and/or installation dependency management. When the IsEntity property has the value TRUE, the instance of SoftwareIdentity represents an individually identifiable entity similar to Physical Element. SoftwareIdentity does NOT indicate whether the software is installed, executing, etc. This extra information may be provided through specialized associations to Software Identity. For instance, both InstalledSoftwareIdentity and ElementSoftwareIdentity may be used to indicate that the software identified by this class is installed. SoftwareIdentity is used when managing the software components of a ManagedElement that is the management focus. Since software may be acquired, SoftwareIdentity can be associated with a Product using the ProductSoftwareComponent relationship. The Application Model manages the deployment and installation of software via the classes, SoftwareFeatures and SoftwareElements. SoftwareFeature and SoftwareElement are used when the software component is the management focus. The deployment/installation concepts are related to the asset/identity one. In fact, a SoftwareIdentity may correspond to a Product, or to one or more SoftwareFeatures or SoftwareElements - depending on the granularity of these classes and the deployment model. The correspondence of Software Identity to Product, SoftwareFeature or SoftwareElement is indicated using the ConcreteIdentity association. Note that there may not be sufficient detail or instrumentation to instantiate ConcreteIdentity. And, if the association is instantiated, some duplication of information may result. For example, the Vendor described in the instances of Product and SoftwareIdentity MAY be the same. However, this is not necessarily true, and it is why vendor and similar information are duplicated in this class. 
	// Note that ConcreteIdentity can also be used to describe the relationship of the software to any LogicalFiles that result from installing it. As above, there may not be sufficient detail or instrumentation to instantiate this association.
	class CIMFRAMEWORK_API CIM_SoftwareIdentity  : public CIM_LogicalElement
	{
	public:

		//Default constructor
		CIM_SoftwareIdentity()
			: CIM_LogicalElement(NULL, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_LogicalElement::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 26);
			}
		}

		//constructor which receives WSMan client
		CIM_SoftwareIdentity(ICimWsmanClient *client)
			: CIM_LogicalElement(client, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_LogicalElement::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 26);
			}
		}

		//Destructor
		virtual ~CIM_SoftwareIdentity(){}

		// The "type" information for the object. Gettors only.
		virtual const string& ResourceURI() const { return CLASS_URI; }
		static const string& ClassResourceURI() { return CLASS_URI; }
		virtual const string& XmlNamespace() const { return CLASS_NS; }
		virtual const string& XmlPrefix() const { return CLASS_NS_PREFIX; }
		virtual const string& ObjectType() const { return CLASS_NAME; }
		static const string& ClassObjectType() { return CLASS_NAME; }

		// Class representing CIM_SoftwareIdentity keys
		class CimKeys : public CIM_LogicalElement::CimKeys
		{
		public:
			// Key, Required, Within the scope of the instantiating Namespace, InstanceID opaquely and uniquely identifies an instance of this class. In order to ensure uniqueness within the NameSpace, the value of InstanceID SHOULD be constructed using the following 'preferred' algorithm: 
			// <OrgID>:<LocalID> 
			// Where <OrgID> and <LocalID> are separated by a colon ':', and where <OrgID> MUST include a copyrighted, trademarked or otherwise unique name that is owned by the business entity creating/defining the InstanceID, or is a registered ID that is assigned to the business entity by a recognized global authority (This is similar to the <Schema Name>_<Class Name> structure of Schema class names.) In addition, to ensure uniqueness <OrgID> MUST NOT contain a colon (':'). When using this algorithm, the first colon to appear in InstanceID MUST appear between <OrgID> and <LocalID>. 
			// <LocalID> is chosen by the business entity and SHOULD not be re-used to identify different underlying (real-world) elements. If the above 'preferred' algorithm is not used, the defining entity MUST assure that the resultant InstanceID is not re-used across any InstanceIDs produced by this or other providers for this instance's NameSpace. 
			// For DMTF defined instances, the 'preferred' algorithm MUST be used with the <OrgID> set to 'CIM'.
			const string InstanceID() const
			{
				return GetKey("InstanceID");
			}

			// Key, Required, Within the scope of the instantiating Namespace, InstanceID opaquely and uniquely identifies an instance of this class. In order to ensure uniqueness within the NameSpace, the value of InstanceID SHOULD be constructed using the following 'preferred' algorithm: 
			// <OrgID>:<LocalID> 
			// Where <OrgID> and <LocalID> are separated by a colon ':', and where <OrgID> MUST include a copyrighted, trademarked or otherwise unique name that is owned by the business entity creating/defining the InstanceID, or is a registered ID that is assigned to the business entity by a recognized global authority (This is similar to the <Schema Name>_<Class Name> structure of Schema class names.) In addition, to ensure uniqueness <OrgID> MUST NOT contain a colon (':'). When using this algorithm, the first colon to appear in InstanceID MUST appear between <OrgID> and <LocalID>. 
			// <LocalID> is chosen by the business entity and SHOULD not be re-used to identify different underlying (real-world) elements. If the above 'preferred' algorithm is not used, the defining entity MUST assure that the resultant InstanceID is not re-used across any InstanceIDs produced by this or other providers for this instance's NameSpace. 
			// For DMTF defined instances, the 'preferred' algorithm MUST be used with the <OrgID> set to 'CIM'.
			void InstanceID(const string &value)
			{
				SetOrAddKey("InstanceID", value);
			}

		};

		// class fields declarations

		// Optional, The major number component of the software's version information - for example, '12' from version 12.1(3)T. This property is defined as a numeric value to allow the determination of 'newer' vs. 'older' releases. A 'newer' major release is indicated by a larger numeric value.
		const unsigned short MajorVersion() const;

		// Optional, The major number component of the software's version information - for example, '12' from version 12.1(3)T. This property is defined as a numeric value to allow the determination of 'newer' vs. 'older' releases. A 'newer' major release is indicated by a larger numeric value.
		void MajorVersion(const unsigned short value); 

		// Is true if the field MajorVersion exists in the current object, otherwise is false.
		bool MajorVersionExists() const;

		// Remove MajorVersion field.
		void RemoveMajorVersion(); 

		// Optional, The minor number component of the software's version information - for example, '1' from version 12.1(3)T. This property is defined as a numeric value to allow the determination of 'newer' vs. 'older' releases. A 'newer' minor release is indicated by a larger numeric value.
		const unsigned short MinorVersion() const;

		// Optional, The minor number component of the software's version information - for example, '1' from version 12.1(3)T. This property is defined as a numeric value to allow the determination of 'newer' vs. 'older' releases. A 'newer' minor release is indicated by a larger numeric value.
		void MinorVersion(const unsigned short value); 

		// Is true if the field MinorVersion exists in the current object, otherwise is false.
		bool MinorVersionExists() const;

		// Remove MinorVersion field.
		void RemoveMinorVersion(); 

		// Optional, The revision or maintenance release component of the software's version information - for example, '3' from version 12.1(3)T. This property is defined as a numeric value to allow the determination of 'newer' vs. 'older' releases. A 'newer' revision is indicated by a larger numeric value.
		const unsigned short RevisionNumber() const;

		// Optional, The revision or maintenance release component of the software's version information - for example, '3' from version 12.1(3)T. This property is defined as a numeric value to allow the determination of 'newer' vs. 'older' releases. A 'newer' revision is indicated by a larger numeric value.
		void RevisionNumber(const unsigned short value); 

		// Is true if the field RevisionNumber exists in the current object, otherwise is false.
		bool RevisionNumberExists() const;

		// Remove RevisionNumber field.
		void RemoveRevisionNumber(); 

		// Optional, The build number of the software.
		const unsigned short BuildNumber() const;

		// Optional, The build number of the software.
		void BuildNumber(const unsigned short value); 

		// Is true if the field BuildNumber exists in the current object, otherwise is false.
		bool BuildNumberExists() const;

		// Remove BuildNumber field.
		void RemoveBuildNumber(); 

		// Optional, The build number of the software if IsLargeBuildNumber is TRUE. TheLargeBuildNumber property should be used for all future implementations.
		const Uint64 LargeBuildNumber() const;

		// Optional, The build number of the software if IsLargeBuildNumber is TRUE. TheLargeBuildNumber property should be used for all future implementations.
		void LargeBuildNumber(const Uint64 value); 

		// Is true if the field LargeBuildNumber exists in the current object, otherwise is false.
		bool LargeBuildNumberExists() const;

		// Remove LargeBuildNumber field.
		void RemoveLargeBuildNumber(); 

		// Optional, The IsLargeBuildNumber property is used to indicate if the BuildNumber of LargeBuildNumber property contains the value of the software build. A value of TRUE shall indicate that the build number is represented by the LargeBuildNumber property. A value of FALSE shall indicate that the build number is represented by the BuildNumber property.
		const bool IsLargeBuildNumber() const;

		// Optional, The IsLargeBuildNumber property is used to indicate if the BuildNumber of LargeBuildNumber property contains the value of the software build. A value of TRUE shall indicate that the build number is represented by the LargeBuildNumber property. A value of FALSE shall indicate that the build number is represented by the BuildNumber property.
		void IsLargeBuildNumber(const bool value); 

		// Is true if the field IsLargeBuildNumber exists in the current object, otherwise is false.
		bool IsLargeBuildNumberExists() const;

		// Remove IsLargeBuildNumber field.
		void RemoveIsLargeBuildNumber(); 

		// Optional, A string representing the complete software version information - for example, '12.1(3)T'. This string and the numeric major/minor/revision/build properties are complementary. Since vastly different representations and semantics exist for versions, it is not assumed that one representation is sufficient to permit a client to perform computations (i.e., the values are numeric) and a user to recognize the software's version (i.e., the values are understandable and readable). Hence, both numeric and string representations of version are provided.
		const string VersionString() const;

		// Optional, A string representing the complete software version information - for example, '12.1(3)T'. This string and the numeric major/minor/revision/build properties are complementary. Since vastly different representations and semantics exist for versions, it is not assumed that one representation is sufficient to permit a client to perform computations (i.e., the values are numeric) and a user to recognize the software's version (i.e., the values are understandable and readable). Hence, both numeric and string representations of version are provided.
		void VersionString(const string &value); 

		// Is true if the field VersionString exists in the current object, otherwise is false.
		bool VersionStringExists() const;

		// Remove VersionString field.
		void RemoveVersionString(); 

		// Optional, Specifies the target operating systems of the software. This property should be used when a target operating system is not listed in the TargetOSTypes array values.
		const vector<string> TargetOperatingSystems() const;

		// Optional, Specifies the target operating systems of the software. This property should be used when a target operating system is not listed in the TargetOSTypes array values.
		void TargetOperatingSystems(const vector<string> &value); 

		// Is true if the field TargetOperatingSystems exists in the current object, otherwise is false.
		bool TargetOperatingSystemsExists() const;

		// Remove TargetOperatingSystems field.
		void RemoveTargetOperatingSystems(); 

		// Optional, Manufacturer of this software.
		const string Manufacturer() const;

		// Optional, Manufacturer of this software.
		void Manufacturer(const string &value); 

		// Is true if the field Manufacturer exists in the current object, otherwise is false.
		bool ManufacturerExists() const;

		// Remove Manufacturer field.
		void RemoveManufacturer(); 

		// Optional, The language editions supported by the software. The language codes defined in ISO 639 should be used.
		const vector<string> Languages() const;

		// Optional, The language editions supported by the software. The language codes defined in ISO 639 should be used.
		void Languages(const vector<string> &value); 

		// Is true if the field Languages exists in the current object, otherwise is false.
		bool LanguagesExists() const;

		// Remove Languages field.
		void RemoveLanguages(); 

		// Optional, An array of enumerated integers that classify this software. For example, the software MAY be instrumentation (value=5) or firmware and diagnostic software (10 and 7). The use of value 6, Firmware/BIOS, is being deprecated. Instead, either the value 10 (Firmware) and/or 11 (BIOS/FCode) SHOULD be used. The value 13, Software Bundle, identifies a software package consisting of multiple discrete software instances that can be installed individually or together.
		// Each contained software instance is represented by an instance of SoftwareIdentity that is associated to this instance of SoftwareIdentityinstance via a Component association.
		const vector<unsigned short> Classifications() const;

		// Optional, An array of enumerated integers that classify this software. For example, the software MAY be instrumentation (value=5) or firmware and diagnostic software (10 and 7). The use of value 6, Firmware/BIOS, is being deprecated. Instead, either the value 10 (Firmware) and/or 11 (BIOS/FCode) SHOULD be used. The value 13, Software Bundle, identifies a software package consisting of multiple discrete software instances that can be installed individually or together.
		// Each contained software instance is represented by an instance of SoftwareIdentity that is associated to this instance of SoftwareIdentityinstance via a Component association.
		void Classifications(const vector<unsigned short> &value); 

		// Is true if the field Classifications exists in the current object, otherwise is false.
		bool ClassificationsExists() const;

		// Remove Classifications field.
		void RemoveClassifications(); 

		// Optional, An array of free-form strings providing more detailed explanations for any of the entries in the Classifications array. Note that each entry is related to one in the Classifications array located at the same index.
		const vector<string> ClassificationDescriptions() const;

		// Optional, An array of free-form strings providing more detailed explanations for any of the entries in the Classifications array. Note that each entry is related to one in the Classifications array located at the same index.
		void ClassificationDescriptions(const vector<string> &value); 

		// Is true if the field ClassificationDescriptions exists in the current object, otherwise is false.
		bool ClassificationDescriptionsExists() const;

		// Remove ClassificationDescriptions field.
		void RemoveClassificationDescriptions(); 

		// Optional, A manufacturer-allocated number used to identify the software.
		const string SerialNumber() const;

		// Optional, A manufacturer-allocated number used to identify the software.
		void SerialNumber(const string &value); 

		// Is true if the field SerialNumber exists in the current object, otherwise is false.
		bool SerialNumberExists() const;

		// Remove SerialNumber field.
		void RemoveSerialNumber(); 

		// Optional, An array of strings that describes the compatible installer(s). The purpose of the array elements is to establish compatibility between a SoftwareIdentity and a SoftwareInstallationService that can install the SoftwareIdentity by comparing the values of the array elements of this property to the values of SoftwareInstallationServiceCapabilities.SupportedTargetTypes[] property's array elements.
		const vector<string> TargetTypes() const;

		// Optional, An array of strings that describes the compatible installer(s). The purpose of the array elements is to establish compatibility between a SoftwareIdentity and a SoftwareInstallationService that can install the SoftwareIdentity by comparing the values of the array elements of this property to the values of SoftwareInstallationServiceCapabilities.SupportedTargetTypes[] property's array elements.
		void TargetTypes(const vector<string> &value); 

		// Is true if the field TargetTypes exists in the current object, otherwise is false.
		bool TargetTypesExists() const;

		// Remove TargetTypes field.
		void RemoveTargetTypes(); 

		// Optional, IdentityInfoValue captures additional information that MAY be used by an organization to describe or identify a software instance within the context of the organization. For example, large organizations may have several ways to address or identify a particular instance of software depending on where it is stored; a catalog, a web site, or for whom it is intended; development, customer service, etc. The indexed array property IdentityInfoValue contains 0 or more strings that contain a specific identity info string value. IdentityInfoValue is mapped and indexed to IdentityInfoType. When the IdentityInfoValue property is implemented, the IdentityInfoType property MUST be implemented and shall be formatted using the algorithm provided in the IdentityInfoType property Description.
		const vector<string> IdentityInfoValue() const;

		// Optional, IdentityInfoValue captures additional information that MAY be used by an organization to describe or identify a software instance within the context of the organization. For example, large organizations may have several ways to address or identify a particular instance of software depending on where it is stored; a catalog, a web site, or for whom it is intended; development, customer service, etc. The indexed array property IdentityInfoValue contains 0 or more strings that contain a specific identity info string value. IdentityInfoValue is mapped and indexed to IdentityInfoType. When the IdentityInfoValue property is implemented, the IdentityInfoType property MUST be implemented and shall be formatted using the algorithm provided in the IdentityInfoType property Description.
		void IdentityInfoValue(const vector<string> &value); 

		// Is true if the field IdentityInfoValue exists in the current object, otherwise is false.
		bool IdentityInfoValueExists() const;

		// Remove IdentityInfoValue field.
		void RemoveIdentityInfoValue(); 

		// Optional, An indexed array of fixed-form strings that provide the description of the type of information that is stored in the corresponding component of the IdentityInfoValue array. The elements of this property array describe the type of the value in the corresponding elements of the IndetityInfoValue array. When the IdentityInfoValue property is implemented, the IdentityInfoType property MUST be implemented. To insure uniqueness the IdentityInfoType property SHOULD be formatted using the following algorithm: < OrgID > : < LocalID > Where < OrgID > and < LocalID > are separated by a colon (:), and where < OrgID > MUST include a copyrighted, trademarked, or otherwise unique name that is owned by the business entity that is creating or defining the IdentityInfoType or that is a registered ID assigned to the business entity by a recognized global authority. (This requirement is similar to the < Schema Name > _ < Class Name > structure of Schema class names.) In addition, to ensure uniqueness, < OrgID > MUST NOT contain a colon (:). When using this algorithm, the first colon to appear in IdentityInfoType MUST appear between < OrgID > and < LocalID > . < LocalID > is chosen by the business entity and SHOULD NOT be reused to identify different underlying software elements.
		const vector<string> IdentityInfoType() const;

		// Optional, An indexed array of fixed-form strings that provide the description of the type of information that is stored in the corresponding component of the IdentityInfoValue array. The elements of this property array describe the type of the value in the corresponding elements of the IndetityInfoValue array. When the IdentityInfoValue property is implemented, the IdentityInfoType property MUST be implemented. To insure uniqueness the IdentityInfoType property SHOULD be formatted using the following algorithm: < OrgID > : < LocalID > Where < OrgID > and < LocalID > are separated by a colon (:), and where < OrgID > MUST include a copyrighted, trademarked, or otherwise unique name that is owned by the business entity that is creating or defining the IdentityInfoType or that is a registered ID assigned to the business entity by a recognized global authority. (This requirement is similar to the < Schema Name > _ < Class Name > structure of Schema class names.) In addition, to ensure uniqueness, < OrgID > MUST NOT contain a colon (:). When using this algorithm, the first colon to appear in IdentityInfoType MUST appear between < OrgID > and < LocalID > . < LocalID > is chosen by the business entity and SHOULD NOT be reused to identify different underlying software elements.
		void IdentityInfoType(const vector<string> &value); 

		// Is true if the field IdentityInfoType exists in the current object, otherwise is false.
		bool IdentityInfoTypeExists() const;

		// Remove IdentityInfoType field.
		void RemoveIdentityInfoType(); 

		// Optional, The date the software was released.
		const CimDateTime ReleaseDate() const;

		// Optional, The date the software was released.
		void ReleaseDate(const CimDateTime &value); 

		// Is true if the field ReleaseDate exists in the current object, otherwise is false.
		bool ReleaseDateExists() const;

		// Remove ReleaseDate field.
		void RemoveReleaseDate(); 

		// Optional, The IsEntity property is used to indicate whether the SoftwareIdentity corresponds to a discrete copy of the software component or is being used to convey descriptive and identifying information about software that is not present in the management domain.A value of TRUE shall indicate that the SoftwareIdentity instance corresponds to a discrete copy of the software component. A value of FALSE shall indicate that the SoftwareIdentity instance does not correspond to a discrete copy of the Software.
		const bool IsEntity() const;

		// Optional, The IsEntity property is used to indicate whether the SoftwareIdentity corresponds to a discrete copy of the software component or is being used to convey descriptive and identifying information about software that is not present in the management domain.A value of TRUE shall indicate that the SoftwareIdentity instance corresponds to a discrete copy of the software component. A value of FALSE shall indicate that the SoftwareIdentity instance does not correspond to a discrete copy of the Software.
		void IsEntity(const bool value); 

		// Is true if the field IsEntity exists in the current object, otherwise is false.
		bool IsEntityExists() const;

		// Remove IsEntity field.
		void RemoveIsEntity(); 

		// Optional, The binary format type of the installation package of the software. This property can be used to locate a SoftwareInstallationService capable of installing this software.
		const unsigned short ExtendedResourceType() const;

		// Optional, The binary format type of the installation package of the software. This property can be used to locate a SoftwareInstallationService capable of installing this software.
		void ExtendedResourceType(const unsigned short value); 

		// Is true if the field ExtendedResourceType exists in the current object, otherwise is false.
		bool ExtendedResourceTypeExists() const;

		// Remove ExtendedResourceType field.
		void RemoveExtendedResourceType(); 

		// Optional, A string describing the binary format type of the installation package of the software when the ExtendedResourceType property has a value of 1 (Other).
		const string OtherExtendedResourceTypeDescription() const;

		// Optional, A string describing the binary format type of the installation package of the software when the ExtendedResourceType property has a value of 1 (Other).
		void OtherExtendedResourceTypeDescription(const string &value); 

		// Is true if the field OtherExtendedResourceTypeDescription exists in the current object, otherwise is false.
		bool OtherExtendedResourceTypeDescriptionExists() const;

		// Remove OtherExtendedResourceTypeDescription field.
		void RemoveOtherExtendedResourceTypeDescription(); 

		// Optional, This property represents the major number component of the minimum version of the installer, represented by the ExtendedResourceType property, that is required to install this software.
		const unsigned short MinExtendedResourceTypeMajorVersion() const;

		// Optional, This property represents the major number component of the minimum version of the installer, represented by the ExtendedResourceType property, that is required to install this software.
		void MinExtendedResourceTypeMajorVersion(const unsigned short value); 

		// Is true if the field MinExtendedResourceTypeMajorVersion exists in the current object, otherwise is false.
		bool MinExtendedResourceTypeMajorVersionExists() const;

		// Remove MinExtendedResourceTypeMajorVersion field.
		void RemoveMinExtendedResourceTypeMajorVersion(); 

		// Optional, This property represents the minor number component of the minimum version of the installer, represented by theExtendedResourceType property, that is required to install this software.
		const unsigned short MinExtendedResourceTypeMinorVersion() const;

		// Optional, This property represents the minor number component of the minimum version of the installer, represented by theExtendedResourceType property, that is required to install this software.
		void MinExtendedResourceTypeMinorVersion(const unsigned short value); 

		// Is true if the field MinExtendedResourceTypeMinorVersion exists in the current object, otherwise is false.
		bool MinExtendedResourceTypeMinorVersionExists() const;

		// Remove MinExtendedResourceTypeMinorVersion field.
		void RemoveMinExtendedResourceTypeMinorVersion(); 

		// Optional, This property represents the Revision number component of the minimum version of the installer, represented by theExtendedResourceType property, that is required to install this software.
		const unsigned short MinExtendedResourceTypeRevisionNumber() const;

		// Optional, This property represents the Revision number component of the minimum version of the installer, represented by theExtendedResourceType property, that is required to install this software.
		void MinExtendedResourceTypeRevisionNumber(const unsigned short value); 

		// Is true if the field MinExtendedResourceTypeRevisionNumber exists in the current object, otherwise is false.
		bool MinExtendedResourceTypeRevisionNumberExists() const;

		// Remove MinExtendedResourceTypeRevisionNumber field.
		void RemoveMinExtendedResourceTypeRevisionNumber(); 

		// Optional, This property represents the Build number component of the minimum version of the installer, represented by theExtendedResourceType property, that is required to install this software.
		const unsigned short MinExtendedResourceTypeBuildNumber() const;

		// Optional, This property represents the Build number component of the minimum version of the installer, represented by theExtendedResourceType property, that is required to install this software.
		void MinExtendedResourceTypeBuildNumber(const unsigned short value); 

		// Is true if the field MinExtendedResourceTypeBuildNumber exists in the current object, otherwise is false.
		bool MinExtendedResourceTypeBuildNumberExists() const;

		// Remove MinExtendedResourceTypeBuildNumber field.
		void RemoveMinExtendedResourceTypeBuildNumber(); 

		// Optional, The TargetOSTypes property specifies the target operating systems supported by the software. When the target operating system of the software is not listed in the enumeration values, TargetOperatingSystems[] property should be used to specify the target operating system.
		const vector<unsigned short> TargetOSTypes() const;

		// Optional, The TargetOSTypes property specifies the target operating systems supported by the software. When the target operating system of the software is not listed in the enumeration values, TargetOperatingSystems[] property should be used to specify the target operating system.
		void TargetOSTypes(const vector<unsigned short> &value); 

		// Is true if the field TargetOSTypes exists in the current object, otherwise is false.
		bool TargetOSTypesExists() const;

		// Remove TargetOSTypes field.
		void RemoveTargetOSTypes(); 

		 // Function used by the factory
		static CimBase *CreateFromCimObject(const CimObject &object);

		static vector<shared_ptr<CIM_SoftwareIdentity> > Enumerate(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		// Overloaded delete which supplies the internal resourceURI
		static void Delete(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		using CimBase::Delete;

	protected:
		 // Protected constructor to be used by derived classes
		CIM_SoftwareIdentity(ICimWsmanClient *client, const string &class_name,
			const string &class_ns, const string &prefix, const string &uri): CIM_LogicalElement(client, class_name, class_ns, prefix, uri)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_LogicalElement::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 26);
			}
		}
		 // Protected constructor which receives CimObject
		CIM_SoftwareIdentity(const CimObject &object)
			: CIM_LogicalElement(object)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_LogicalElement::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 26);
			}
		}
		// Called by derived classes
		void SetMetaData(vector<CimFieldAttribute>& childMetaData)
		{
			CIM_LogicalElement::SetMetaData(childMetaData);
			CimBase::SetMetaData(childMetaData, _metadata, 26);
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
#endif // CIM_SOFTWAREIDENTITY_H
