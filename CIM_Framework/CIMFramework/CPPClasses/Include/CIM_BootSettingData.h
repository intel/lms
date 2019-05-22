//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_BootSettingData.h
//
//  Contents:   BootSettingData is a set of settings that apply to system boot. An example of usage of this class is to hold several BIOS, NVRAM, firmware or system settings, typically seen in the BIOS setup screens. These settings would need to be modified by the system as part of the boot process. Since, it is often not possible to intercept the boot process to apply these settings, users can set these a priori in the instance associated with the selected BootSourceSetting, thereby instructing the system to apply them during the next system reboot.
//
//              This file was automatically generated from CIM_BootSettingData.mof,  version: 2.19.0
//
//----------------------------------------------------------------------------
#ifndef CIM_BOOTSETTINGDATA_H
#define CIM_BOOTSETTINGDATA_H 1
#include "CIM_SettingData.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	// BootSettingData is a set of settings that apply to system boot. An example of usage of this class is to hold several BIOS, NVRAM, firmware or system settings, typically seen in the BIOS setup screens. These settings would need to be modified by the system as part of the boot process. Since, it is often not possible to intercept the boot process to apply these settings, users can set these a priori in the instance associated with the selected BootSourceSetting, thereby instructing the system to apply them during the next system reboot.
	class CIMFRAMEWORK_API CIM_BootSettingData  : public CIM_SettingData
	{
	public:

		//Default constructor
		CIM_BootSettingData()
			: CIM_SettingData(NULL, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_SettingData::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 1);
			}
		}

		//constructor which receives WSMan client
		CIM_BootSettingData(ICimWsmanClient *client)
			: CIM_SettingData(client, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_SettingData::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 1);
			}
		}

		//Destructor
		virtual ~CIM_BootSettingData(){}

		// The "type" information for the object. Gettors only.
		virtual const string& ResourceURI() const { return CLASS_URI; }
		static const string& ClassResourceURI() { return CLASS_URI; }
		virtual const string& XmlNamespace() const { return CLASS_NS; }
		virtual const string& XmlPrefix() const { return CLASS_NS_PREFIX; }
		virtual const string& ObjectType() const { return CLASS_NAME; }
		static const string& ClassObjectType() { return CLASS_NAME; }

		// Class representing CIM_BootSettingData keys
		class CimKeys : public CIM_SettingData::CimKeys
		{
		public:
		};

		// class fields declarations

		// Optional, OwningEntity identifies the vendor or organization that defines the contained boot settings. In order to ensure uniqueness, the value of OwningEntity MUST be constructed using the following algorithm: 
		// <OrgID>[:<LocalID>] 
		// where <OrgID> MUST include a copyrighted, trademarked or otherwise unique name that is owned by the entity creating/defining the BootSettingData, or is a registered ID that is assigned to the entity by a recognized global authority (This is similar to the <Schema Name>_<Class Name> structure of Schema class names.) In addition, <OrgID> MUST NOT contain a colon (':'). 
		// <LocalID> is optional and, when used, MUST be unique within the scope of the <OrgID>. When a <LocalID> is present, a colon MUST appear between <OrgID> and <LocalID>. For DMTF defined instances, the algorithm MUST be used with the <OrgID> set to 'CIM'.
		const string OwningEntity() const;

		// Optional, OwningEntity identifies the vendor or organization that defines the contained boot settings. In order to ensure uniqueness, the value of OwningEntity MUST be constructed using the following algorithm: 
		// <OrgID>[:<LocalID>] 
		// where <OrgID> MUST include a copyrighted, trademarked or otherwise unique name that is owned by the entity creating/defining the BootSettingData, or is a registered ID that is assigned to the entity by a recognized global authority (This is similar to the <Schema Name>_<Class Name> structure of Schema class names.) In addition, <OrgID> MUST NOT contain a colon (':'). 
		// <LocalID> is optional and, when used, MUST be unique within the scope of the <OrgID>. When a <LocalID> is present, a colon MUST appear between <OrgID> and <LocalID>. For DMTF defined instances, the algorithm MUST be used with the <OrgID> set to 'CIM'.
		void OwningEntity(const string &value); 

		// Is true if the field OwningEntity exists in the current object, otherwise is false.
		bool OwningEntityExists() const;

		// Remove OwningEntity field.
		void RemoveOwningEntity(); 

		 // Function used by the factory
		static CimBase *CreateFromCimObject(const CimObject &object);

		static vector<shared_ptr<CIM_BootSettingData> > Enumerate(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		// Overloaded delete which supplies the internal resourceURI
		static void Delete(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		using CimBase::Delete;

	protected:
		 // Protected constructor to be used by derived classes
		CIM_BootSettingData(ICimWsmanClient *client, const string &class_name,
			const string &class_ns, const string &prefix, const string &uri): CIM_SettingData(client, class_name, class_ns, prefix, uri)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_SettingData::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 1);
			}
		}
		 // Protected constructor which receives CimObject
		CIM_BootSettingData(const CimObject &object)
			: CIM_SettingData(object)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_SettingData::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 1);
			}
		}
		// Called by derived classes
		void SetMetaData(vector<CimFieldAttribute>& childMetaData)
		{
			CIM_SettingData::SetMetaData(childMetaData);
			CimBase::SetMetaData(childMetaData, _metadata, 1);
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
#endif // CIM_BOOTSETTINGDATA_H
