//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_MediaAccessDevice.h
//
//  Contents:   A MediaAccessDevice represents the ability to access one or more media and use this media to store and retrieve data.
//
//              This file was automatically generated from CIM_MediaAccessDevice.mof,  version: 2.6.0
//
//----------------------------------------------------------------------------
#ifndef CIM_MEDIAACCESSDEVICE_H
#define CIM_MEDIAACCESSDEVICE_H 1
#include "CIM_LogicalDevice.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	// A MediaAccessDevice represents the ability to access one or more media and use this media to store and retrieve data.
	class CIMFRAMEWORK_API CIM_MediaAccessDevice  : public CIM_LogicalDevice
	{
	public:

		//Default constructor
		CIM_MediaAccessDevice()
			: CIM_LogicalDevice(NULL, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_LogicalDevice::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 23);
			}
		}

		//constructor which receives WSMan client
		CIM_MediaAccessDevice(ICimWsmanClient *client)
			: CIM_LogicalDevice(client, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_LogicalDevice::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 23);
			}
		}

		//Destructor
		virtual ~CIM_MediaAccessDevice(){}

		// The "type" information for the object. Gettors only.
		virtual const string& ResourceURI() const { return CLASS_URI; }
		static const string& ClassResourceURI() { return CLASS_URI; }
		virtual const string& XmlNamespace() const { return CLASS_NS; }
		virtual const string& XmlPrefix() const { return CLASS_NS_PREFIX; }
		virtual const string& ObjectType() const { return CLASS_NAME; }
		static const string& ClassObjectType() { return CLASS_NAME; }

		// Class representing CIM_MediaAccessDevice keys
		class CimKeys : public CIM_LogicalDevice::CimKeys
		{
		public:
		};

		// class fields declarations

		// Optional, Capabilities of the MediaAccessDevice. For example, the Device may support "Random Access", removeable media and "Automatic Cleaning". In this case, the values 3, 7 and 9 would be written to the array. 
		// Several of the enumerated values require some explanation: 1) Value 11, Supports Dual Sided Media, distinguishes a Device that can access both sides of dual sided Media, from a Device that reads only a single side and requires the Media to be flipped; and, 2) Value 12, Predismount Eject Not Required, indicates that Media does not have to be explicitly ejected from the Device before being accessed by a PickerElement.
		const vector<unsigned short> Capabilities() const;

		// Optional, Capabilities of the MediaAccessDevice. For example, the Device may support "Random Access", removeable media and "Automatic Cleaning". In this case, the values 3, 7 and 9 would be written to the array. 
		// Several of the enumerated values require some explanation: 1) Value 11, Supports Dual Sided Media, distinguishes a Device that can access both sides of dual sided Media, from a Device that reads only a single side and requires the Media to be flipped; and, 2) Value 12, Predismount Eject Not Required, indicates that Media does not have to be explicitly ejected from the Device before being accessed by a PickerElement.
		void Capabilities(const vector<unsigned short> &value); 

		// Is true if the field Capabilities exists in the current object, otherwise is false.
		bool CapabilitiesExists() const;

		// Remove Capabilities field.
		void RemoveCapabilities(); 

		// Optional, An array of free-form strings providing more detailed explanations for any of the AccessDevice features indicated in the Capabilities array. Note, each entry of this array is related to the entry in the Capabilities array that is located at the same index.
		const vector<string> CapabilityDescriptions() const;

		// Optional, An array of free-form strings providing more detailed explanations for any of the AccessDevice features indicated in the Capabilities array. Note, each entry of this array is related to the entry in the Capabilities array that is located at the same index.
		void CapabilityDescriptions(const vector<string> &value); 

		// Is true if the field CapabilityDescriptions exists in the current object, otherwise is false.
		bool CapabilityDescriptionsExists() const;

		// Remove CapabilityDescriptions field.
		void RemoveCapabilityDescriptions(); 

		// Optional, ErrorMethodology is a free-form string describing the type(s) of error detection and correction supported by this Device.
		const string ErrorMethodology() const;

		// Optional, ErrorMethodology is a free-form string describing the type(s) of error detection and correction supported by this Device.
		void ErrorMethodology(const string &value); 

		// Is true if the field ErrorMethodology exists in the current object, otherwise is false.
		bool ErrorMethodologyExists() const;

		// Remove ErrorMethodology field.
		void RemoveErrorMethodology(); 

		// Optional, A free form string indicating the algorithm or tool used by the device to support compression. If it is not possible or not desired to describe the compression scheme (perhaps because it is not known), recommend using the following words: "Unknown" to represent that it is not known whether the device supports compression capabilities or not, "Compressed" to represent that the device supports compression capabilities but either its compression scheme is not known or not disclosed, and "Not Compressed" to represent that the devices does not support compression capabilities.
		const string CompressionMethod() const;

		// Optional, A free form string indicating the algorithm or tool used by the device to support compression. If it is not possible or not desired to describe the compression scheme (perhaps because it is not known), recommend using the following words: "Unknown" to represent that it is not known whether the device supports compression capabilities or not, "Compressed" to represent that the device supports compression capabilities but either its compression scheme is not known or not disclosed, and "Not Compressed" to represent that the devices does not support compression capabilities.
		void CompressionMethod(const string &value); 

		// Is true if the field CompressionMethod exists in the current object, otherwise is false.
		bool CompressionMethodExists() const;

		// Remove CompressionMethod field.
		void RemoveCompressionMethod(); 

		// Optional, When the MediaAccessDevice supports multiple individual Media, this property defines the maximum number which can be supported or inserted.
		const unsigned int NumberOfMediaSupported() const;

		// Optional, When the MediaAccessDevice supports multiple individual Media, this property defines the maximum number which can be supported or inserted.
		void NumberOfMediaSupported(const unsigned int value); 

		// Is true if the field NumberOfMediaSupported exists in the current object, otherwise is false.
		bool NumberOfMediaSupportedExists() const;

		// Remove NumberOfMediaSupported field.
		void RemoveNumberOfMediaSupported(); 

		// Optional, Maximum size, in KBytes, of media supported by this Device. KBytes is interpreted as the number of bytes multiplied by 1000 (NOT the number of bytes multiplied by 1024).
		const Uint64 MaxMediaSize() const;

		// Optional, Maximum size, in KBytes, of media supported by this Device. KBytes is interpreted as the number of bytes multiplied by 1000 (NOT the number of bytes multiplied by 1024).
		void MaxMediaSize(const Uint64 value); 

		// Is true if the field MaxMediaSize exists in the current object, otherwise is false.
		bool MaxMediaSizeExists() const;

		// Remove MaxMediaSize field.
		void RemoveMaxMediaSize(); 

		// Optional, Default block size, in bytes, for this Device.
		const Uint64 DefaultBlockSize() const;

		// Optional, Default block size, in bytes, for this Device.
		void DefaultBlockSize(const Uint64 value); 

		// Is true if the field DefaultBlockSize exists in the current object, otherwise is false.
		bool DefaultBlockSizeExists() const;

		// Remove DefaultBlockSize field.
		void RemoveDefaultBlockSize(); 

		// Optional, Maximum block size, in bytes, for media accessed by this Device.
		const Uint64 MaxBlockSize() const;

		// Optional, Maximum block size, in bytes, for media accessed by this Device.
		void MaxBlockSize(const Uint64 value); 

		// Is true if the field MaxBlockSize exists in the current object, otherwise is false.
		bool MaxBlockSizeExists() const;

		// Remove MaxBlockSize field.
		void RemoveMaxBlockSize(); 

		// Optional, Minimum block size, in bytes, for media accessed by this Device.
		const Uint64 MinBlockSize() const;

		// Optional, Minimum block size, in bytes, for media accessed by this Device.
		void MinBlockSize(const Uint64 value); 

		// Is true if the field MinBlockSize exists in the current object, otherwise is false.
		bool MinBlockSizeExists() const;

		// Remove MinBlockSize field.
		void RemoveMinBlockSize(); 

		// Optional, Boolean indicating that the MediaAccessDevice needs cleaning. Whether manual or automatic cleaning is possible is indicated in the Capabilities array property.
		const bool NeedsCleaning() const;

		// Optional, Boolean indicating that the MediaAccessDevice needs cleaning. Whether manual or automatic cleaning is possible is indicated in the Capabilities array property.
		void NeedsCleaning(const bool value); 

		// Is true if the field NeedsCleaning exists in the current object, otherwise is false.
		bool NeedsCleaningExists() const;

		// Remove NeedsCleaning field.
		void RemoveNeedsCleaning(); 

		// Optional, True indicates that the media is locked in the Device and can not be ejected. For non-removeable Devices, this value should be true.
		const bool MediaIsLocked() const;

		// Optional, True indicates that the media is locked in the Device and can not be ejected. For non-removeable Devices, this value should be true.
		void MediaIsLocked(const bool value); 

		// Is true if the field MediaIsLocked exists in the current object, otherwise is false.
		bool MediaIsLockedExists() const;

		// Remove MediaIsLocked field.
		void RemoveMediaIsLocked(); 

		// Optional, An enumeration indicating the operational security defined for the MediaAccessDevice. For example, information that the Device is "Read Only" (value=4) or "Boot Bypass" (value=6) can be described using this property.
		const unsigned short Security() const;

		// Optional, An enumeration indicating the operational security defined for the MediaAccessDevice. For example, information that the Device is "Read Only" (value=4) or "Boot Bypass" (value=6) can be described using this property.
		void Security(const unsigned short value); 

		// Is true if the field Security exists in the current object, otherwise is false.
		bool SecurityExists() const;

		// Remove Security field.
		void RemoveSecurity(); 

		// Optional, The date and time on which the Device was last cleaned.
		const CimDateTime LastCleaned() const;

		// Optional, The date and time on which the Device was last cleaned.
		void LastCleaned(const CimDateTime &value); 

		// Is true if the field LastCleaned exists in the current object, otherwise is false.
		bool LastCleanedExists() const;

		// Remove LastCleaned field.
		void RemoveLastCleaned(); 

		// Optional, Time in milliseconds to move from the first location on the Media to the location that is furthest with respect to time. For a DiskDrive, this represents full seek + full rotational delay. For TapeDrives, this represents a search from the beginning of the tape to the most physically distant point. (The end of a tape may be at its most physically distant point, but this is not necessarily true.)
		const Uint64 MaxAccessTime() const;

		// Optional, Time in milliseconds to move from the first location on the Media to the location that is furthest with respect to time. For a DiskDrive, this represents full seek + full rotational delay. For TapeDrives, this represents a search from the beginning of the tape to the most physically distant point. (The end of a tape may be at its most physically distant point, but this is not necessarily true.)
		void MaxAccessTime(const Uint64 value); 

		// Is true if the field MaxAccessTime exists in the current object, otherwise is false.
		bool MaxAccessTimeExists() const;

		// Remove MaxAccessTime field.
		void RemoveMaxAccessTime(); 

		// Optional, The sustained data transfer rate in KB/sec that the Device can read from and write to a Media. This is a sustained, raw data rate. Maximum rates or rates assuming compression should not be reported in this property.
		const unsigned int UncompressedDataRate() const;

		// Optional, The sustained data transfer rate in KB/sec that the Device can read from and write to a Media. This is a sustained, raw data rate. Maximum rates or rates assuming compression should not be reported in this property.
		void UncompressedDataRate(const unsigned int value); 

		// Is true if the field UncompressedDataRate exists in the current object, otherwise is false.
		bool UncompressedDataRateExists() const;

		// Remove UncompressedDataRate field.
		void RemoveUncompressedDataRate(); 

		// Optional, Time in milliseconds from 'load' to being able to read or write a Media. For example, for DiskDrives, this is the interval between a disk not spinning to the disk reporting that it is ready for read/write (ie, the disk spinning at nominal speeds). For TapeDrives, this is the time from a Media being injected to reporting that it is ready for an application. This is usually at the tape's BOT area.
		const Uint64 LoadTime() const;

		// Optional, Time in milliseconds from 'load' to being able to read or write a Media. For example, for DiskDrives, this is the interval between a disk not spinning to the disk reporting that it is ready for read/write (ie, the disk spinning at nominal speeds). For TapeDrives, this is the time from a Media being injected to reporting that it is ready for an application. This is usually at the tape's BOT area.
		void LoadTime(const Uint64 value); 

		// Is true if the field LoadTime exists in the current object, otherwise is false.
		bool LoadTimeExists() const;

		// Remove LoadTime field.
		void RemoveLoadTime(); 

		// Optional, Time in milliseconds from being able to read or write a Media to its 'unload'. For example, for DiskDrives, this is the interval between a disk spinning at nominal speeds and a disk not spinning. For TapeDrives, this is the time for a Media to go from its BOT to being fully ejected and accessible to a PickerElement or human operator.
		const Uint64 UnloadTime() const;

		// Optional, Time in milliseconds from being able to read or write a Media to its 'unload'. For example, for DiskDrives, this is the interval between a disk spinning at nominal speeds and a disk not spinning. For TapeDrives, this is the time for a Media to go from its BOT to being fully ejected and accessible to a PickerElement or human operator.
		void UnloadTime(const Uint64 value); 

		// Is true if the field UnloadTime exists in the current object, otherwise is false.
		bool UnloadTimeExists() const;

		// Remove UnloadTime field.
		void RemoveUnloadTime(); 

		// Optional, For a MediaAccessDevice that supports removable Media, the number of times that Media have been mounted for data transfer or to clean the Device. For Devices accessing nonremovable Media, such as hard disks, this property is not applicable and should be set to 0.
		const Uint64 MountCount() const;

		// Optional, For a MediaAccessDevice that supports removable Media, the number of times that Media have been mounted for data transfer or to clean the Device. For Devices accessing nonremovable Media, such as hard disks, this property is not applicable and should be set to 0.
		void MountCount(const Uint64 value); 

		// Is true if the field MountCount exists in the current object, otherwise is false.
		bool MountCountExists() const;

		// Remove MountCount field.
		void RemoveMountCount(); 

		// Optional, For a MediaAccessDevice that supports removable Media, the most recent date and time that Media was mounted on the Device. For Devices accessing nonremovable Media, such as hard disks, this property has no meaning and is not applicable.
		const CimDateTime TimeOfLastMount() const;

		// Optional, For a MediaAccessDevice that supports removable Media, the most recent date and time that Media was mounted on the Device. For Devices accessing nonremovable Media, such as hard disks, this property has no meaning and is not applicable.
		void TimeOfLastMount(const CimDateTime &value); 

		// Is true if the field TimeOfLastMount exists in the current object, otherwise is false.
		bool TimeOfLastMountExists() const;

		// Remove TimeOfLastMount field.
		void RemoveTimeOfLastMount(); 

		// Optional, For a MediaAccessDevice that supports removable Media, the total time (in seconds) that Media have been mounted for data transfer or to clean the Device. For Devices accessing nonremovable Media, such as hard disks, this property is not applicable and should be set to 0.
		const Uint64 TotalMountTime() const;

		// Optional, For a MediaAccessDevice that supports removable Media, the total time (in seconds) that Media have been mounted for data transfer or to clean the Device. For Devices accessing nonremovable Media, such as hard disks, this property is not applicable and should be set to 0.
		void TotalMountTime(const Uint64 value); 

		// Is true if the field TotalMountTime exists in the current object, otherwise is false.
		bool TotalMountTimeExists() const;

		// Remove TotalMountTime field.
		void RemoveTotalMountTime(); 

		// Optional, Defines 'Units' relative to its use in the property, MaxUnitsBeforeCleaning. This describes the criteria used to determine when the MediaAccessDevice should be cleaned.
		const string UnitsDescription() const;

		// Optional, Defines 'Units' relative to its use in the property, MaxUnitsBeforeCleaning. This describes the criteria used to determine when the MediaAccessDevice should be cleaned.
		void UnitsDescription(const string &value); 

		// Is true if the field UnitsDescription exists in the current object, otherwise is false.
		bool UnitsDescriptionExists() const;

		// Remove UnitsDescription field.
		void RemoveUnitsDescription(); 

		// Optional, An unsigned integer indicating the maximum 'units' that can be used, with respect to the AccessDevice, before the Device should be cleaned. The property, UnitsDescription, defines how 'units' should be interpreted.
		const Uint64 MaxUnitsBeforeCleaning() const;

		// Optional, An unsigned integer indicating the maximum 'units' that can be used, with respect to the AccessDevice, before the Device should be cleaned. The property, UnitsDescription, defines how 'units' should be interpreted.
		void MaxUnitsBeforeCleaning(const Uint64 value); 

		// Is true if the field MaxUnitsBeforeCleaning exists in the current object, otherwise is false.
		bool MaxUnitsBeforeCleaningExists() const;

		// Remove MaxUnitsBeforeCleaning field.
		void RemoveMaxUnitsBeforeCleaning(); 

		// Optional, An unsigned integer indicating the currently used 'units' of the AccessDevice, helpful to describe when the Device may require cleaning. The property, UnitsDescription, defines how 'units' should be interpreted.
		const Uint64 UnitsUsed() const;

		// Optional, An unsigned integer indicating the currently used 'units' of the AccessDevice, helpful to describe when the Device may require cleaning. The property, UnitsDescription, defines how 'units' should be interpreted.
		void UnitsUsed(const Uint64 value); 

		// Is true if the field UnitsUsed exists in the current object, otherwise is false.
		bool UnitsUsedExists() const;

		// Remove UnitsUsed field.
		void RemoveUnitsUsed(); 

		 // Function used by the factory
		static CimBase *CreateFromCimObject(const CimObject &object);

		static vector<shared_ptr<CIM_MediaAccessDevice> > Enumerate(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		// Overloaded delete which supplies the internal resourceURI
		static void Delete(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		using CimBase::Delete;

	protected:
		 // Protected constructor to be used by derived classes
		CIM_MediaAccessDevice(ICimWsmanClient *client, const string &class_name,
			const string &class_ns, const string &prefix, const string &uri): CIM_LogicalDevice(client, class_name, class_ns, prefix, uri)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_LogicalDevice::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 23);
			}
		}
		 // Protected constructor which receives CimObject
		CIM_MediaAccessDevice(const CimObject &object)
			: CIM_LogicalDevice(object)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_LogicalDevice::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 23);
			}
		}
		// Called by derived classes
		void SetMetaData(vector<CimFieldAttribute>& childMetaData)
		{
			CIM_LogicalDevice::SetMetaData(childMetaData);
			CimBase::SetMetaData(childMetaData, _metadata, 23);
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
#endif // CIM_MEDIAACCESSDEVICE_H
