//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_ElementSettingData.h
//
//  Contents:   ElementSettingData represents the association between ManagedElements and applicable setting data. This association also describes whether this is a default or current setting.
//
//              This file was automatically generated from CIM_ElementSettingData.mof,  version: 2.19.1
//
//----------------------------------------------------------------------------
#ifndef CIM_ELEMENTSETTINGDATA_H
#define CIM_ELEMENTSETTINGDATA_H 1
#include "../../include/CimBase.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	// ElementSettingData represents the association between ManagedElements and applicable setting data. This association also describes whether this is a default or current setting.
	class CIMFRAMEWORK_API CIM_ElementSettingData  : public CimBase
	{
	public:

		//Default constructor
		CIM_ElementSettingData()
			: CimBase(NULL, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CimBase::SetMetaData(_classMetaData, _metadata, 5);
			}
		}

		//constructor which receives WSMan client
		CIM_ElementSettingData(ICimWsmanClient *client)
			: CimBase(client, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CimBase::SetMetaData(_classMetaData, _metadata, 5);
			}
		}

		//Destructor
		virtual ~CIM_ElementSettingData(){}

		// The "type" information for the object. Gettors only.
		virtual const string& ResourceURI() const { return CLASS_URI; }
		static const string& ClassResourceURI() { return CLASS_URI; }
		virtual const string& XmlNamespace() const { return CLASS_NS; }
		virtual const string& XmlPrefix() const { return CLASS_NS_PREFIX; }
		virtual const string& ObjectType() const { return CLASS_NAME; }
		static const string& ClassObjectType() { return CLASS_NAME; }

		// Class representing CIM_ElementSettingData keys
		class CimKeys : public CimBase::CimKeys
		{
		public:
			// Key, Required, The managed element.
			const CimReference ManagedElement() const
			{
				CimReference ret;
				TypeConverter::StringToType(GetKey("ManagedElement"), ret);
				return ret;
			}

			// Key, Required, The managed element.
			void ManagedElement(const CimReference &value)
			{
				SetOrAddKey("ManagedElement", TypeConverter::TypeToString(value), true);
			}

			// Key, Required, The SettingData object associated with the element.
			const CimReference SettingData() const
			{
				CimReference ret;
				TypeConverter::StringToType(GetKey("SettingData"), ret);
				return ret;
			}

			// Key, Required, The SettingData object associated with the element.
			void SettingData(const CimReference &value)
			{
				SetOrAddKey("SettingData", TypeConverter::TypeToString(value), true);
			}

		};

		// class fields declarations

		// Key, Required, The managed element.
		const CimReference ManagedElement() const;

		// Key, Required, The managed element.
		void ManagedElement(const CimReference &value); 


		// Key, Required, The SettingData object associated with the element.
		const CimReference SettingData() const;

		// Key, Required, The SettingData object associated with the element.
		void SettingData(const CimReference &value); 


		// Optional, An enumerated integer indicating that the referenced setting is a default setting for the element, or that this information is unknown.
		const unsigned short IsDefault() const;

		// Optional, An enumerated integer indicating that the referenced setting is a default setting for the element, or that this information is unknown.
		void IsDefault(const unsigned short value); 

		// Is true if the field IsDefault exists in the current object, otherwise is false.
		bool IsDefaultExists() const;

		// Remove IsDefault field.
		void RemoveIsDefault(); 

		// Optional, An enumerated integer indicating that the referenced setting is currently being used in the operation of the element, or that this information is unknown.
		const unsigned short IsCurrent() const;

		// Optional, An enumerated integer indicating that the referenced setting is currently being used in the operation of the element, or that this information is unknown.
		void IsCurrent(const unsigned short value); 

		// Is true if the field IsCurrent exists in the current object, otherwise is false.
		bool IsCurrentExists() const;

		// Remove IsCurrent field.
		void RemoveIsCurrent(); 

		// Optional, An enumerated integer indicating whether or not the referenced setting is the next setting to be applied. For example, the application could take place on a re-initialization, reset, reconfiguration request. This could be a permanent setting, or a setting used only one time, as indicated by the flag. If it is a permanent setting then the setting is applied every time the managed element reinitializes, until this flag is manually reset. However, if it is single use, then the flag is automatically cleared after the settings are applied. Also note that if this flag is specified (i.e. set to value other than "Unknown"), then this takes precedence over any SettingData that may have been specified as Default. For example: If the managed element is a computer system, and the value of this flag is "Is Next", then the setting will be effective next time the system resets. And, unless this flag is changed, it will persist for subsequent system resets. However, if this flag is set to "Is Next For Single Use", then this setting will only be used once and the flag would be reset after that to "Is Not Next". So, in the above example, if the system reboots in a quick succession, the setting will not be used at the second reboot.
		const unsigned short IsNext() const;

		// Optional, An enumerated integer indicating whether or not the referenced setting is the next setting to be applied. For example, the application could take place on a re-initialization, reset, reconfiguration request. This could be a permanent setting, or a setting used only one time, as indicated by the flag. If it is a permanent setting then the setting is applied every time the managed element reinitializes, until this flag is manually reset. However, if it is single use, then the flag is automatically cleared after the settings are applied. Also note that if this flag is specified (i.e. set to value other than "Unknown"), then this takes precedence over any SettingData that may have been specified as Default. For example: If the managed element is a computer system, and the value of this flag is "Is Next", then the setting will be effective next time the system resets. And, unless this flag is changed, it will persist for subsequent system resets. However, if this flag is set to "Is Next For Single Use", then this setting will only be used once and the flag would be reset after that to "Is Not Next". So, in the above example, if the system reboots in a quick succession, the setting will not be used at the second reboot.
		void IsNext(const unsigned short value); 

		// Is true if the field IsNext exists in the current object, otherwise is false.
		bool IsNextExists() const;

		// Remove IsNext field.
		void RemoveIsNext(); 

		 // Function used by the factory
		static CimBase *CreateFromCimObject(const CimObject &object);

		static vector<shared_ptr<CIM_ElementSettingData> > Enumerate(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		// Overloaded delete which supplies the internal resourceURI
		static void Delete(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		using CimBase::Delete;

	protected:
		 // Protected constructor to be used by derived classes
		CIM_ElementSettingData(ICimWsmanClient *client, const string &class_name,
			const string &class_ns, const string &prefix, const string &uri): CimBase(client, class_name, class_ns, prefix, uri)
		{
			if(_classMetaData.size() == 0)
			{
				CimBase::SetMetaData(_classMetaData, _metadata, 5);
			}
		}
		 // Protected constructor which receives CimObject
		CIM_ElementSettingData(const CimObject &object)
			: CimBase(object)
		{
			if(_classMetaData.size() == 0)
			{
				CimBase::SetMetaData(_classMetaData, _metadata, 5);
			}
		}
		// Called by derived classes
		void SetMetaData(vector<CimFieldAttribute>& childMetaData)
		{
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
#endif // CIM_ELEMENTSETTINGDATA_H
