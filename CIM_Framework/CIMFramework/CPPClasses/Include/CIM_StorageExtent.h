//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_StorageExtent.h
//
//  Contents:   StorageExtent describes the capabilities and management of the various media that exist to store data and allow data retrieval. This superclass could be used to represent the various components of RAID (Hardware or Software) or as a raw logical extent on top of physical media.
//
//              This file was automatically generated from CIM_StorageExtent.mof,  version: 2.29.0
//
//----------------------------------------------------------------------------
#ifndef CIM_STORAGEEXTENT_H
#define CIM_STORAGEEXTENT_H 1
#include "CIM_LogicalDevice.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	// StorageExtent describes the capabilities and management of the various media that exist to store data and allow data retrieval. This superclass could be used to represent the various components of RAID (Hardware or Software) or as a raw logical extent on top of physical media.
	class CIMFRAMEWORK_API CIM_StorageExtent  : public CIM_LogicalDevice
	{
	public:

		//Default constructor
		CIM_StorageExtent()
			: CIM_LogicalDevice(NULL, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_LogicalDevice::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 20);
			}
		}

		//constructor which receives WSMan client
		CIM_StorageExtent(ICimWsmanClient *client)
			: CIM_LogicalDevice(client, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_LogicalDevice::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 20);
			}
		}

		//Destructor
		virtual ~CIM_StorageExtent(){}

		// The "type" information for the object. Gettors only.
		virtual const string& ResourceURI() const { return CLASS_URI; }
		static const string& ClassResourceURI() { return CLASS_URI; }
		virtual const string& XmlNamespace() const { return CLASS_NS; }
		virtual const string& XmlPrefix() const { return CLASS_NS_PREFIX; }
		virtual const string& ObjectType() const { return CLASS_NAME; }
		static const string& ClassObjectType() { return CLASS_NAME; }

		// Class representing CIM_StorageExtent keys
		class CimKeys : public CIM_LogicalDevice::CimKeys
		{
		public:
		};

		// class fields declarations

		// Optional, Type of data organization used.
		const unsigned short DataOrganization() const;

		// Optional, Type of data organization used.
		void DataOrganization(const unsigned short value); 

		// Is true if the field DataOrganization exists in the current object, otherwise is false.
		bool DataOrganizationExists() const;

		// Remove DataOrganization field.
		void RemoveDataOrganization(); 

		// Optional, A free form string describing the media and/or its use.
		const string Purpose() const;

		// Optional, A free form string describing the media and/or its use.
		void Purpose(const string &value); 

		// Is true if the field Purpose exists in the current object, otherwise is false.
		bool PurposeExists() const;

		// Remove Purpose field.
		void RemovePurpose(); 

		// Optional, Access describes whether the media is readable (value=1), writeable (value=2), or both (value=3). "Unknown" (0) and "Write Once" (4) can also be defined.
		const unsigned short Access() const;

		// Optional, Access describes whether the media is readable (value=1), writeable (value=2), or both (value=3). "Unknown" (0) and "Write Once" (4) can also be defined.
		void Access(const unsigned short value); 

		// Is true if the field Access exists in the current object, otherwise is false.
		bool AccessExists() const;

		// Remove Access field.
		void RemoveAccess(); 

		// Optional, ErrorMethodology is a free-form string describing the type of error detection and correction supported by this StorageExtent.
		const string ErrorMethodology() const;

		// Optional, ErrorMethodology is a free-form string describing the type of error detection and correction supported by this StorageExtent.
		void ErrorMethodology(const string &value); 

		// Is true if the field ErrorMethodology exists in the current object, otherwise is false.
		bool ErrorMethodologyExists() const;

		// Remove ErrorMethodology field.
		void RemoveErrorMethodology(); 

		// Optional, Size in bytes of the blocks which form this StorageExtent. If variable block size, then the maximum block size in bytes should be specified. If the block size is unknown or if a block concept is not valid (for example, for AggregateExtents, Memory or LogicalDisks), enter a 1.
		const Uint64 BlockSize() const;

		// Optional, Size in bytes of the blocks which form this StorageExtent. If variable block size, then the maximum block size in bytes should be specified. If the block size is unknown or if a block concept is not valid (for example, for AggregateExtents, Memory or LogicalDisks), enter a 1.
		void BlockSize(const Uint64 value); 

		// Is true if the field BlockSize exists in the current object, otherwise is false.
		bool BlockSizeExists() const;

		// Remove BlockSize field.
		void RemoveBlockSize(); 

		// Optional, Total number of logically contiguous blocks, of size Block Size, which form this Extent. The total size of the Extent can be calculated by multiplying BlockSize by NumberOfBlocks. If the BlockSize is 1, this property is the total size of the Extent.
		const Uint64 NumberOfBlocks() const;

		// Optional, Total number of logically contiguous blocks, of size Block Size, which form this Extent. The total size of the Extent can be calculated by multiplying BlockSize by NumberOfBlocks. If the BlockSize is 1, this property is the total size of the Extent.
		void NumberOfBlocks(const Uint64 value); 

		// Is true if the field NumberOfBlocks exists in the current object, otherwise is false.
		bool NumberOfBlocksExists() const;

		// Remove NumberOfBlocks field.
		void RemoveNumberOfBlocks(); 

		// Optional, The maximum number of blocks, of size BlockSize, which are available for consumption when layering StorageExtents using the BasedOn association. This property only has meaning when this StorageExtent is an Antecedent reference in a BasedOn relationship. For example, a StorageExtent could be composed of 120 blocks. However, the Extent itself may use 20 blocks for redundancy data. If another StorageExtent is BasedOn this Extent, only 100 blocks would be available to it. This information ('100 blocks is available for consumption') is indicated in the ConsumableBlocks property.
		const Uint64 ConsumableBlocks() const;

		// Optional, The maximum number of blocks, of size BlockSize, which are available for consumption when layering StorageExtents using the BasedOn association. This property only has meaning when this StorageExtent is an Antecedent reference in a BasedOn relationship. For example, a StorageExtent could be composed of 120 blocks. However, the Extent itself may use 20 blocks for redundancy data. If another StorageExtent is BasedOn this Extent, only 100 blocks would be available to it. This information ('100 blocks is available for consumption') is indicated in the ConsumableBlocks property.
		void ConsumableBlocks(const Uint64 value); 

		// Is true if the field ConsumableBlocks exists in the current object, otherwise is false.
		bool ConsumableBlocksExists() const;

		// Remove ConsumableBlocks field.
		void RemoveConsumableBlocks(); 

		// Optional, True indicates that the underlying StorageExtent(s) participate in a StorageRedundancyGroup.
		const bool IsBasedOnUnderlyingRedundancy() const;

		// Optional, True indicates that the underlying StorageExtent(s) participate in a StorageRedundancyGroup.
		void IsBasedOnUnderlyingRedundancy(const bool value); 

		// Is true if the field IsBasedOnUnderlyingRedundancy exists in the current object, otherwise is false.
		bool IsBasedOnUnderlyingRedundancyExists() const;

		// Remove IsBasedOnUnderlyingRedundancy field.
		void RemoveIsBasedOnUnderlyingRedundancy(); 

		// Optional, Boolean set to TRUE if the Storage is sequentially accessed by a MediaAccessDevice. A TapePartition is an example of a sequentially accessed StorageExtent. StorageVolumes, Disk Partitions and LogicalDisks represent randomly accessed Extents.
		const bool SequentialAccess() const;

		// Optional, Boolean set to TRUE if the Storage is sequentially accessed by a MediaAccessDevice. A TapePartition is an example of a sequentially accessed StorageExtent. StorageVolumes, Disk Partitions and LogicalDisks represent randomly accessed Extents.
		void SequentialAccess(const bool value); 

		// Is true if the field SequentialAccess exists in the current object, otherwise is false.
		bool SequentialAccessExists() const;

		// Remove SequentialAccess field.
		void RemoveSequentialAccess(); 

		// Optional, StorageExtents have additional status information beyond that captured in the OperationalStatus and other properties, inherited from ManagedSystemElement. This additional information (for example, "Protection Disabled", value=9) is captured in the ExtentStatus property. 
		// 'In-Band Access Granted' says that access to data on an extent is granted to some consumer and is only valid when 'Exported' is also set. It is set as a side effect of PrivilegeManagementService.ChangeAccess or equivalent interfaces. 
		// 'Imported' indicates that the extent is used in the current system, but known to be managed by some other system. For example, a server imports volumes from a disk array. 
		// 'Exported' indicates the extent is meant to be used by some comsumer. A disk array's logical units are exported. 
		// Intermediate composite extents may be neither imported nor exported.
		// 'Relocating' indicates the extent is being relocated.
		const vector<unsigned short> ExtentStatus() const;

		// Optional, StorageExtents have additional status information beyond that captured in the OperationalStatus and other properties, inherited from ManagedSystemElement. This additional information (for example, "Protection Disabled", value=9) is captured in the ExtentStatus property. 
		// 'In-Band Access Granted' says that access to data on an extent is granted to some consumer and is only valid when 'Exported' is also set. It is set as a side effect of PrivilegeManagementService.ChangeAccess or equivalent interfaces. 
		// 'Imported' indicates that the extent is used in the current system, but known to be managed by some other system. For example, a server imports volumes from a disk array. 
		// 'Exported' indicates the extent is meant to be used by some comsumer. A disk array's logical units are exported. 
		// Intermediate composite extents may be neither imported nor exported.
		// 'Relocating' indicates the extent is being relocated.
		void ExtentStatus(const vector<unsigned short> &value); 

		// Is true if the field ExtentStatus exists in the current object, otherwise is false.
		bool ExtentStatusExists() const;

		// Remove ExtentStatus field.
		void RemoveExtentStatus(); 

		// Optional, Indicates whether or not there exists no single point of failure.
		const bool NoSinglePointOfFailure() const;

		// Optional, Indicates whether or not there exists no single point of failure.
		void NoSinglePointOfFailure(const bool value); 

		// Is true if the field NoSinglePointOfFailure exists in the current object, otherwise is false.
		bool NoSinglePointOfFailureExists() const;

		// Remove NoSinglePointOfFailure field.
		void RemoveNoSinglePointOfFailure(); 

		// Optional, Number of complete copies of data currently maintained.
		const unsigned short DataRedundancy() const;

		// Optional, Number of complete copies of data currently maintained.
		void DataRedundancy(const unsigned short value); 

		// Is true if the field DataRedundancy exists in the current object, otherwise is false.
		bool DataRedundancyExists() const;

		// Remove DataRedundancy field.
		void RemoveDataRedundancy(); 

		// Optional, How many physical packages can currently fail without data loss. For example, in the storage domain, this might be disk spindles.
		const unsigned short PackageRedundancy() const;

		// Optional, How many physical packages can currently fail without data loss. For example, in the storage domain, this might be disk spindles.
		void PackageRedundancy(const unsigned short value); 

		// Is true if the field PackageRedundancy exists in the current object, otherwise is false.
		bool PackageRedundancyExists() const;

		// Remove PackageRedundancy field.
		void RemovePackageRedundancy(); 

		// Optional, Current value for Delta reservation. This is a percentage that specifies the amount of space that should be reserved in a replica for caching changes.
		const unsigned char DeltaReservation() const;

		// Optional, Current value for Delta reservation. This is a percentage that specifies the amount of space that should be reserved in a replica for caching changes.
		void DeltaReservation(const unsigned char &value); 

		// Is true if the field DeltaReservation exists in the current object, otherwise is false.
		bool DeltaReservationExists() const;

		// Remove DeltaReservation field.
		void RemoveDeltaReservation(); 

		// Optional, If true, "Primordial" indicates that the containing System does not have the ability to create or delete this operational element. This is important because StorageExtents are assembled into higher-level abstractions using the BasedOn association. Although the higher-level abstractions can be created and deleted, the most basic, (i.e. primordial), hardware-based storage entities cannot. They are physically realized as part of the System, or are actually managed by some other System and imported as if they were physically realized. In other words, a Primordial StorageExtent exists in, but is not created by its System and conversely a non-Primordial StorageExtent is created in the context of its System. For StorageVolumes, this property will generally be false. One use of this property is to enable algorithms that aggregate StorageExtent.ConsumableSpace across all, StorageExtents but that also want to distinquish the space that underlies Primordial StoragePools. Since implementations are not required to surface all Component StorageExtents of a StoragePool, this information is not accessible in any other way.
		const bool Primordial() const;

		// Optional, If true, "Primordial" indicates that the containing System does not have the ability to create or delete this operational element. This is important because StorageExtents are assembled into higher-level abstractions using the BasedOn association. Although the higher-level abstractions can be created and deleted, the most basic, (i.e. primordial), hardware-based storage entities cannot. They are physically realized as part of the System, or are actually managed by some other System and imported as if they were physically realized. In other words, a Primordial StorageExtent exists in, but is not created by its System and conversely a non-Primordial StorageExtent is created in the context of its System. For StorageVolumes, this property will generally be false. One use of this property is to enable algorithms that aggregate StorageExtent.ConsumableSpace across all, StorageExtents but that also want to distinquish the space that underlies Primordial StoragePools. Since implementations are not required to surface all Component StorageExtents of a StoragePool, this information is not accessible in any other way.
		void Primordial(const bool value); 

		// Is true if the field Primordial exists in the current object, otherwise is false.
		bool PrimordialExists() const;

		// Remove Primordial field.
		void RemovePrimordial(); 

		// Optional, The list here applies to all StorageExtent subclasses. Please look at the Description in each subclass for guidelines on the approriate values for that subclass. Note that any of these formats could apply to a CompositeExtent. 
		// 
		// Note - this property originally touched on two concepts that are now separated into this property and NameNamespace. Values 2,3,4,5,6, and 8 are retained for backwards compatibility but are deprecated in lieu of the corresponding values in CIM_StorageExtent.NameNamespace. 
		// 
		// For example, the preferred source for SCSI virtual (RAID) disk names is from Inquiry VPD page 83 response, type 3 identifiers. These will have NameFormat set to 'NAA' and NameNamespace to 'VPD83Type3'. 
		// 
		// Format of the Name property. Values for extents representing SCSI volumes are (per SCSI SPC-3): 
		// 2 = VPD Page 83, NAA IEEE Registered Extended (VPD83NAA6) 
		// (DEPRECATED) 
		// 3 = VPD Page 83, NAA IEEE Registered (VPD83NAA5) 
		// (DEPRECATED) 
		// 4 = VPD Page 83, (VPD83Type2) (DEPRECATED) 
		// 5 = VPD Page 83, 
		// T10 Vendor Identification (VPD83Type1) (DEPRECATED) 
		// 6 = VPD Page 83, Vendor Specific (VPD83Type0) (DEPRECATED) 
		// 7 = Serial Number/Vendor/Model (SNVM) SNVM is 3 strings representing the vendor name, product name within the vendor namespace, and the serial number within the model namespace. Strings are delimited with a '+'. Spaces may be included and are significant. The serial number is the text representation of the serial number in hexadecimal upper case. This represents the vendor and model ID from SCSI Inquiry data; the vendor field MUST be 8 characters wide and the product field MUST be 16 characters wide. For example, 
		// 'ACME____+SUPER DISK______+124437458' (_ is a space character) 
		// 8 = Node WWN (for single LUN/controller) (NodeWWN) 
		// (DEPRECATED) 
		// 9 = NAA as a generic format. See 
		// http://standards.ieee.org/regauth/oui/tutorials/fibrecomp_id.html. Formatted as 16 or 32 unseparated uppercase hex characters (2 per binary byte). For example '21000020372D3C73' 
		// 10 = EUI as a generic format (EUI64) See 
		// http://standards.ieee.org/regauth/oui/tutorials/EUI64.html. 
		// Formatted as 16 unseparated uppercase hex characters (2 per binary byte) 
		// 11 = T10 vendor identifier format as returned by SCSI Inquiry VPD page 83, identifier type 1. See T10 SPC-3 specification. This is the 8-byte ASCII vendor ID from the T10 registry followed by a vendor specific ASCII identifier; spaces are permitted. For non SCSI volumes, 'SNVM' may be the most appropriate choice. 12 = OS Device Name (for LogicalDisks). See LogicalDisk Name description for details.
		const unsigned short NameFormat() const;

		// Optional, The list here applies to all StorageExtent subclasses. Please look at the Description in each subclass for guidelines on the approriate values for that subclass. Note that any of these formats could apply to a CompositeExtent. 
		// 
		// Note - this property originally touched on two concepts that are now separated into this property and NameNamespace. Values 2,3,4,5,6, and 8 are retained for backwards compatibility but are deprecated in lieu of the corresponding values in CIM_StorageExtent.NameNamespace. 
		// 
		// For example, the preferred source for SCSI virtual (RAID) disk names is from Inquiry VPD page 83 response, type 3 identifiers. These will have NameFormat set to 'NAA' and NameNamespace to 'VPD83Type3'. 
		// 
		// Format of the Name property. Values for extents representing SCSI volumes are (per SCSI SPC-3): 
		// 2 = VPD Page 83, NAA IEEE Registered Extended (VPD83NAA6) 
		// (DEPRECATED) 
		// 3 = VPD Page 83, NAA IEEE Registered (VPD83NAA5) 
		// (DEPRECATED) 
		// 4 = VPD Page 83, (VPD83Type2) (DEPRECATED) 
		// 5 = VPD Page 83, 
		// T10 Vendor Identification (VPD83Type1) (DEPRECATED) 
		// 6 = VPD Page 83, Vendor Specific (VPD83Type0) (DEPRECATED) 
		// 7 = Serial Number/Vendor/Model (SNVM) SNVM is 3 strings representing the vendor name, product name within the vendor namespace, and the serial number within the model namespace. Strings are delimited with a '+'. Spaces may be included and are significant. The serial number is the text representation of the serial number in hexadecimal upper case. This represents the vendor and model ID from SCSI Inquiry data; the vendor field MUST be 8 characters wide and the product field MUST be 16 characters wide. For example, 
		// 'ACME____+SUPER DISK______+124437458' (_ is a space character) 
		// 8 = Node WWN (for single LUN/controller) (NodeWWN) 
		// (DEPRECATED) 
		// 9 = NAA as a generic format. See 
		// http://standards.ieee.org/regauth/oui/tutorials/fibrecomp_id.html. Formatted as 16 or 32 unseparated uppercase hex characters (2 per binary byte). For example '21000020372D3C73' 
		// 10 = EUI as a generic format (EUI64) See 
		// http://standards.ieee.org/regauth/oui/tutorials/EUI64.html. 
		// Formatted as 16 unseparated uppercase hex characters (2 per binary byte) 
		// 11 = T10 vendor identifier format as returned by SCSI Inquiry VPD page 83, identifier type 1. See T10 SPC-3 specification. This is the 8-byte ASCII vendor ID from the T10 registry followed by a vendor specific ASCII identifier; spaces are permitted. For non SCSI volumes, 'SNVM' may be the most appropriate choice. 12 = OS Device Name (for LogicalDisks). See LogicalDisk Name description for details.
		void NameFormat(const unsigned short value); 

		// Is true if the field NameFormat exists in the current object, otherwise is false.
		bool NameFormatExists() const;

		// Remove NameFormat field.
		void RemoveNameFormat(); 

		// Optional, The preferred source SCSI for volume names is SCSI VPD Page 83 responses. Page 83 returns a list of identifiers for various device elements. The metadata for each identifier includes an Association field, identifiers with association of 0 apply to volumes. Page 83 supports several namespaces specified in the Type field in the identifier metadata. See SCSI SPC-3 specification. 
		// 2 = VPD Page 83, Type 3 NAA (NameFormat SHOULD be NAA) 
		// 3 = VPD Page 83, Type 2 EUI64 (NameFormat EUI) 
		// 4 = VPD Page 83, Type 1 T10 Vendor Identification 
		// (NameFormat T10) 
		// Less preferred volume namespaces from other interfaces: 
		// 5 = VPD page 80, Serial number (NameFormat SHOULD be Other) 
		// 6 = FC NodeWWN (NameFormat SHOULD be NAA or EUI) 
		// 7 = Serial Number/Vendor/Model (NameFormat SHOULD be SNVM) 
		// The preferred namespace for LogigicalDisk names is platform specific device namespace; see LogigicalDIsk Description. 
		// 8 = OS Device Namespace.
		const unsigned short NameNamespace() const;

		// Optional, The preferred source SCSI for volume names is SCSI VPD Page 83 responses. Page 83 returns a list of identifiers for various device elements. The metadata for each identifier includes an Association field, identifiers with association of 0 apply to volumes. Page 83 supports several namespaces specified in the Type field in the identifier metadata. See SCSI SPC-3 specification. 
		// 2 = VPD Page 83, Type 3 NAA (NameFormat SHOULD be NAA) 
		// 3 = VPD Page 83, Type 2 EUI64 (NameFormat EUI) 
		// 4 = VPD Page 83, Type 1 T10 Vendor Identification 
		// (NameFormat T10) 
		// Less preferred volume namespaces from other interfaces: 
		// 5 = VPD page 80, Serial number (NameFormat SHOULD be Other) 
		// 6 = FC NodeWWN (NameFormat SHOULD be NAA or EUI) 
		// 7 = Serial Number/Vendor/Model (NameFormat SHOULD be SNVM) 
		// The preferred namespace for LogigicalDisk names is platform specific device namespace; see LogigicalDIsk Description. 
		// 8 = OS Device Namespace.
		void NameNamespace(const unsigned short value); 

		// Is true if the field NameNamespace exists in the current object, otherwise is false.
		bool NameNamespaceExists() const;

		// Remove NameNamespace field.
		void RemoveNameNamespace(); 

		// Optional, A string describing the namespace of the Name property when NameNamespace includes the value 1, "Other".
		const string OtherNameNamespace() const;

		// Optional, A string describing the namespace of the Name property when NameNamespace includes the value 1, "Other".
		void OtherNameNamespace(const string &value); 

		// Is true if the field OtherNameNamespace exists in the current object, otherwise is false.
		bool OtherNameNamespaceExists() const;

		// Remove OtherNameNamespace field.
		void RemoveOtherNameNamespace(); 

		// Optional, A string describing the format of the Name property when NameFormat includes the value 1, "Other".
		const string OtherNameFormat() const;

		// Optional, A string describing the format of the Name property when NameFormat includes the value 1, "Other".
		void OtherNameFormat(const string &value); 

		// Is true if the field OtherNameFormat exists in the current object, otherwise is false.
		bool OtherNameFormatExists() const;

		// Remove OtherNameFormat field.
		void RemoveOtherNameFormat(); 

		// Requests that the Device re-establish its configuration, setup and/or state information from a backing store. The intent is to capture this information at an earlier time (via the SaveProperties method), and use it to return a Device to this earlier "condition". This method may not be supported by all Devices. The method should return 0 if successful, 1 if the request is not supported, and some other value if any other error occurred. In a subclass, the set of possible return codes could be specified, using a ValueMap qualifier on the method. The strings to which the ValueMap contents are 'translated' may also be specified in the subclass as a Values array qualifier.
		virtual unsigned int RestoreProperties();

		// Requests that the Device capture its current configuration, setup and/or state information in a backing store. The goal would be to use this information at a later time (via the RestoreProperties method), to return a Device to its present "condition". This method may not be supported by all Devices. The method should return 0 if successful, 1 if the request is not supported, and some other value if any other error occurred. In a subclass, the set of possible return codes could be specified, using a ValueMap qualifier on the method. The strings to which the ValueMap contents are 'translated' may also be specified in the subclass as a Values array qualifier.
		virtual unsigned int SaveProperties();

		//Input parameter for function QuiesceDevice
		class CIMFRAMEWORK_API QuiesceDevice_INPUT : public CimParam
		{
		public:
			// Class Constructor
			QuiesceDevice_INPUT() : CimParam() {}

			// Class Destructor
			~QuiesceDevice_INPUT(){}

			// Optional, If set to TRUE then cleanly cease all activity, if FALSE resume activity.
			void Quiesce(const bool value); 

			const VectorFieldData GetAllFields() const;
		private:
			static const CimFieldAttribute _metadata[];
		};

		// The QuiesceDevice method has been deprecated in lieu of the more general RequestStateChange method that directly overlaps with the functionality provided by this method. 
		// Requests that the LogicalDevice cleanly cease all current activity ("Quiesce" input parameter = TRUE) or resume activity (= FALSE). For this method to quiesce a Device, that Device should have an Availability (or Additional Availability) of "Running/Full Power" (value=3) and an EnabledStatus/StatusInfo of "Enabled". For example, if quiesced, a Device may then be offlined for diagnostics, or disabled for power off and hot swap. For the method to "unquiesce" a Device, that Device should have an Availability (or AdditionalAvailability) of "Quiesced" (value=21) and an EnabledStatus/StatusInfo of "Enabled". In this case, the Device would be returned to an "Enabled" and "Running/Full Power" status. 
		// The method's return code should indicate the success or failure of the quiesce. It should return 0 if successful, 1 if the request is not supported at all, 2 if the request is not supported due to the current state of the Device, and some other value if any other error occurred. In a subclass, the set of possible return codes could be specified, using a ValueMap qualifier on the method. The strings to which the ValueMap contents are 'translated' may also be specified in the subclass as a Values array qualifier.
		virtual unsigned int QuiesceDevice(const QuiesceDevice_INPUT &input);

		//Input parameter for function OnlineDevice
		class CIMFRAMEWORK_API OnlineDevice_INPUT : public CimParam
		{
		public:
			// Class Constructor
			OnlineDevice_INPUT() : CimParam() {}

			// Class Destructor
			~OnlineDevice_INPUT(){}

			// Optional, If TRUE, take the device online, if FALSE, take the device OFFLINE.
			void Online(const bool value); 

			const VectorFieldData GetAllFields() const;
		private:
			static const CimFieldAttribute _metadata[];
		};

		// The OnlineDevice method has been deprecated in lieu of the more general RequestStateChange method that directly overlaps with the functionality provided by this method. 
		// Requests that the LogicalDevice be brought online ("Online" input parameter = TRUE) or taken offline (= FALSE). "Online" indicates that the Device is ready to accept requests, and is operational and fully functioning. In this case, the Device's Availability property would be set to a value of 3 ("Running/Full Power"). "Offline" indicates that a Device is powered up and operational, but not processing functional requests. In an offline state, a Device may be capable of running diagnostics or generating operational alerts. For example, when the "Offline" button is pushed on a Printer, the Device is no longer available to process print jobs, but could be available for diagnostics or maintenance. 
		// If this method is successful, the Device's Availability and AdditionalAvailability properties should reflect the updated status. If a failure occurs trying to bring the Device online or offline, it should remain in its current state. IE, the request, if unsuccessful, should not leave the Device in an indeterminate state. When bringing a Device back "Online", from an "Offline" mode, the Device should be restored to its last "Online" state, if at all possible. Only a Device that has an EnabledState/StatusInfo of "Enabled" and has been configured can be brought online or taken offline. 
		// OnlineDevice should return 0 if successful, 1 if the request is not supported at all, 2 if the request is not supported due to the current state of the Device, and some other value if any other error occurred. In a subclass, the set of possible return codes could be specified, using a ValueMap qualifier on the method. The strings to which the ValueMap contents are 'translated' may also be specified in the subclass as a Values array qualifier. 
		// Note that this method's function overlaps with the RequestedState property. RequestedState was added to the model to maintain a record (i.e., a persisted value) of the last state request. Invoking the OnlineDevice method should set the RequestedState property appropriately.
		virtual unsigned int OnlineDevice(const OnlineDevice_INPUT &input);

		//Input parameter for function EnableDevice
		class CIMFRAMEWORK_API EnableDevice_INPUT : public CimParam
		{
		public:
			// Class Constructor
			EnableDevice_INPUT() : CimParam() {}

			// Class Destructor
			~EnableDevice_INPUT(){}

			// Optional, If TRUE enable the device, if FALSE disable the device.
			void Enabled(const bool value); 

			const VectorFieldData GetAllFields() const;
		private:
			static const CimFieldAttribute _metadata[];
		};

		// The EnableDevice method has been deprecated in lieu of the more general RequestStateChange method that directly overlaps with the functionality provided by this method. 
		// Requests that the LogicalDevice be enabled ("Enabled" input parameter = TRUE) or disabled (= FALSE). If successful, the Device's StatusInfo/EnabledState properties should reflect the desired state (enabled/disabled). Note that this method's function overlaps with the RequestedState property. RequestedState was added to the model to maintain a record (i.e., a persisted value) of the last state request. Invoking the EnableDevice method should set the RequestedState property appropriately. 
		// The return code should be 0 if the request was successfully executed, 1 if the request is not supported and some other value if an error occurred. In a subclass, the set of possible return codes could be specified, using a ValueMap qualifier on the method. The strings to which the ValueMap contents are 'translated' may also be specified in the subclass as a Values array qualifier.
		virtual unsigned int EnableDevice(const EnableDevice_INPUT &input);

		// Requests a reset of the LogicalDevice. The return value should be 0 if the request was successfully executed, 1 if the request is not supported and some other value if an error occurred. In a subclass, the set of possible return codes could be specified, using a ValueMap qualifier on the method. The strings to which the ValueMap contents are 'translated' may also be specified in the subclass as a Values array qualifier.
		virtual unsigned int Reset();

		//Input parameter for function SetPowerState
		class CIMFRAMEWORK_API SetPowerState_INPUT : public CimParam
		{
		public:
			// Class Constructor
			SetPowerState_INPUT() : CimParam() {}

			// Class Destructor
			~SetPowerState_INPUT(){}

			// Optional, The power state to set.
			// Legal values:
			// Full Power: 1
			// Power Save - Low Power Mode: 2
			// Power Save - Standby: 3
			// Power Save - Other: 4
			// Power Cycle: 5
			// Power Off: 6
			void PowerState(const unsigned short value); 

			// Optional, Time indicates when the power state should be set, either as a regular date-time value or as an interval value (where the interval begins when the method invocation is received.
			void Time(const CimDateTime &value); 

			const VectorFieldData GetAllFields() const;
		private:
			static const CimFieldAttribute _metadata[];
		};

		// Sets the power state of the Device. The use of this method has been deprecated. Instead, use the SetPowerState method in the associated PowerManagementService class.
		virtual unsigned int SetPowerState(const SetPowerState_INPUT &input);

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

		 // Function used by the factory
		static CimBase *CreateFromCimObject(const CimObject &object);

		static vector<shared_ptr<CIM_StorageExtent> > Enumerate(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		// Overloaded delete which supplies the internal resourceURI
		static void Delete(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		using CimBase::Delete;

	protected:
		 // Protected constructor to be used by derived classes
		CIM_StorageExtent(ICimWsmanClient *client, const string &class_name,
			const string &class_ns, const string &prefix, const string &uri): CIM_LogicalDevice(client, class_name, class_ns, prefix, uri)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_LogicalDevice::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 20);
			}
		}
		 // Protected constructor which receives CimObject
		CIM_StorageExtent(const CimObject &object)
			: CIM_LogicalDevice(object)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_LogicalDevice::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 20);
			}
		}
		// Called by derived classes
		void SetMetaData(vector<CimFieldAttribute>& childMetaData)
		{
			CIM_LogicalDevice::SetMetaData(childMetaData);
			CimBase::SetMetaData(childMetaData, _metadata, 20);
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
#endif // CIM_STORAGEEXTENT_H
