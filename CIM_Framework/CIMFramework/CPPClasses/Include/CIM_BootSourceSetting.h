//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_BootSourceSetting.h
//
//  Contents:   A class derived from SettingData that provides the information necessary to describe a boot source. This may be optionally associated to a bootable logical device, such as a hard disk partition, or a network device. The information from this class instance is used by the boot manager, such as BIOS/EFI or OS Loader to initiate the boot process, when this instance appears in a BootConfigSetting collection.
//
//              This file was automatically generated from CIM_BootSourceSetting.mof,  version: 2.19.0
//
//----------------------------------------------------------------------------
#ifndef CIM_BOOTSOURCESETTING_H
#define CIM_BOOTSOURCESETTING_H 1
#include "CIM_SettingData.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	// A class derived from SettingData that provides the information necessary to describe a boot source. This may be optionally associated to a bootable logical device, such as a hard disk partition, or a network device. The information from this class instance is used by the boot manager, such as BIOS/EFI or OS Loader to initiate the boot process, when this instance appears in a BootConfigSetting collection.
	class CIMFRAMEWORK_API CIM_BootSourceSetting  : public CIM_SettingData
	{
	public:

		//Default constructor
		CIM_BootSourceSetting()
			: CIM_SettingData(NULL, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_SettingData::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 4);
			}
		}

		//constructor which receives WSMan client
		CIM_BootSourceSetting(ICimWsmanClient *client)
			: CIM_SettingData(client, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_SettingData::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 4);
			}
		}

		//Destructor
		virtual ~CIM_BootSourceSetting(){}

		// The "type" information for the object. Gettors only.
		virtual const string& ResourceURI() const { return CLASS_URI; }
		static const string& ClassResourceURI() { return CLASS_URI; }
		virtual const string& XmlNamespace() const { return CLASS_NS; }
		virtual const string& XmlPrefix() const { return CLASS_NS_PREFIX; }
		virtual const string& ObjectType() const { return CLASS_NAME; }
		static const string& ClassObjectType() { return CLASS_NAME; }

		// Class representing CIM_BootSourceSetting keys
		class CimKeys : public CIM_SettingData::CimKeys
		{
		public:
		};

		// class fields declarations

		// Optional, A string identifying the boot source. It is typically used by the instrumentation to pass to the boot manager as a selection string. This could be a string identifying the bootable device, such as "CDROM 1", or could be an implementation specific address of a bootable partition, such as the following. "fd(64)unix root=hd(40) swap=hd(41)", or "multi(0)disk(0)rdisk(0)partition(1)\WINDOWS="Microsoft Windows XP Professional"".
		const string BootString() const;

		// Optional, A string identifying the boot source. It is typically used by the instrumentation to pass to the boot manager as a selection string. This could be a string identifying the bootable device, such as "CDROM 1", or could be an implementation specific address of a bootable partition, such as the following. "fd(64)unix root=hd(40) swap=hd(41)", or "multi(0)disk(0)rdisk(0)partition(1)\WINDOWS="Microsoft Windows XP Professional"".
		void BootString(const string &value); 

		// Is true if the field BootString exists in the current object, otherwise is false.
		bool BootStringExists() const;

		// Remove BootString field.
		void RemoveBootString(); 

		// Optional, A string identifying the boot source which corresponds to the string used by the BIOS to uniquely name the boot source. For example, in systems which implement the BIOS Boot Specification, the string could correspond to the descString string for entries in the IPL Table or BCV Table.
		const string BIOSBootString() const;

		// Optional, A string identifying the boot source which corresponds to the string used by the BIOS to uniquely name the boot source. For example, in systems which implement the BIOS Boot Specification, the string could correspond to the descString string for entries in the IPL Table or BCV Table.
		void BIOSBootString(const string &value); 

		// Is true if the field BIOSBootString exists in the current object, otherwise is false.
		bool BIOSBootStringExists() const;

		// Remove BIOSBootString field.
		void RemoveBIOSBootString(); 

		// Optional, A string identifying the boot source using the format "<OrgID>:<identifier>:<index>", in which neither <OrgID>, <identifier> or <index> contains a colon (":"). The value of <OrgID> is a copyrighted, trademarked or otherwise unique name that is owned by the entity defining the <identifier>, or is a registered ID that is assigned to the entity by a recognized global authority. For DMTF defined identifiers, the <OrgID> is set to 'CIM'. The <identifiers> are "Floppy", "Hard-Disk", "CD/DVD", "Network", "PCMCIA", "USB". The value of <index> shall be a non-zero integer.
		const string StructuredBootString() const;

		// Optional, A string identifying the boot source using the format "<OrgID>:<identifier>:<index>", in which neither <OrgID>, <identifier> or <index> contains a colon (":"). The value of <OrgID> is a copyrighted, trademarked or otherwise unique name that is owned by the entity defining the <identifier>, or is a registered ID that is assigned to the entity by a recognized global authority. For DMTF defined identifiers, the <OrgID> is set to 'CIM'. The <identifiers> are "Floppy", "Hard-Disk", "CD/DVD", "Network", "PCMCIA", "USB". The value of <index> shall be a non-zero integer.
		void StructuredBootString(const string &value); 

		// Is true if the field StructuredBootString exists in the current object, otherwise is false.
		bool StructuredBootStringExists() const;

		// Remove StructuredBootString field.
		void RemoveStructuredBootString(); 

		// Optional, An enumeration indicating the behavior when the attempt to boot using the boot source fails (no media, timeout). The current values in the enumeration are: 
		// 0 = Unknown 
		// 1 = Is Supported 
		// 2 = Is Not Supported. 
		// A value of 1 (Is Supported) indicates that next boot source the boot order is used. A value of 2 (Is Not Supported) indicates that the boot order is terminated and no other boot sources associated to the same CIM_BootConfigSetting are used). The default is 1 (Is Supported)
		const unsigned short FailThroughSupported() const;

		// Optional, An enumeration indicating the behavior when the attempt to boot using the boot source fails (no media, timeout). The current values in the enumeration are: 
		// 0 = Unknown 
		// 1 = Is Supported 
		// 2 = Is Not Supported. 
		// A value of 1 (Is Supported) indicates that next boot source the boot order is used. A value of 2 (Is Not Supported) indicates that the boot order is terminated and no other boot sources associated to the same CIM_BootConfigSetting are used). The default is 1 (Is Supported)
		void FailThroughSupported(const unsigned short value); 

		// Is true if the field FailThroughSupported exists in the current object, otherwise is false.
		bool FailThroughSupportedExists() const;

		// Remove FailThroughSupported field.
		void RemoveFailThroughSupported(); 

		 // Function used by the factory
		static CimBase *CreateFromCimObject(const CimObject &object);

		static vector<shared_ptr<CIM_BootSourceSetting> > Enumerate(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		// Overloaded delete which supplies the internal resourceURI
		static void Delete(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		using CimBase::Delete;

	protected:
		 // Protected constructor to be used by derived classes
		CIM_BootSourceSetting(ICimWsmanClient *client, const string &class_name,
			const string &class_ns, const string &prefix, const string &uri): CIM_SettingData(client, class_name, class_ns, prefix, uri)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_SettingData::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 4);
			}
		}
		 // Protected constructor which receives CimObject
		CIM_BootSourceSetting(const CimObject &object)
			: CIM_SettingData(object)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_SettingData::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 4);
			}
		}
		// Called by derived classes
		void SetMetaData(vector<CimFieldAttribute>& childMetaData)
		{
			CIM_SettingData::SetMetaData(childMetaData);
			CimBase::SetMetaData(childMetaData, _metadata, 4);
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
#endif // CIM_BOOTSOURCESETTING_H
