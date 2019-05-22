//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_SettingsDefineState.h
//
//  Contents:   SettingsDefineState is used to associate an instance of SettingData with an instance of ManagedElement. This association indicates that the SettingData instance provides additional information about the Current State of the associated ManagedElement. State is broadly defined to include the configuration, status, capabilities, and other information of an instance. 
//              Use of the same instance of SettingData to represent more than one of Current State (SettingsDefineState) and Desired State (ElementSettingData) and Possible State (SettingsDefineCapabilities) for a ManagedElement is not recommended.
//
//              This file was automatically generated from CIM_SettingsDefineState.mof,  version: 2.22.0
//
//----------------------------------------------------------------------------
#ifndef CIM_SETTINGSDEFINESTATE_H
#define CIM_SETTINGSDEFINESTATE_H 1
#include "../../include/CimBase.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	// SettingsDefineState is used to associate an instance of SettingData with an instance of ManagedElement. This association indicates that the SettingData instance provides additional information about the Current State of the associated ManagedElement. State is broadly defined to include the configuration, status, capabilities, and other information of an instance. 
	// Use of the same instance of SettingData to represent more than one of Current State (SettingsDefineState) and Desired State (ElementSettingData) and Possible State (SettingsDefineCapabilities) for a ManagedElement is not recommended.
	class CIMFRAMEWORK_API CIM_SettingsDefineState  : public CimBase
	{
	public:

		//Default constructor
		CIM_SettingsDefineState()
			: CimBase(NULL, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CimBase::SetMetaData(_classMetaData, _metadata, 2);
			}
		}

		//constructor which receives WSMan client
		CIM_SettingsDefineState(ICimWsmanClient *client)
			: CimBase(client, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CimBase::SetMetaData(_classMetaData, _metadata, 2);
			}
		}

		//Destructor
		virtual ~CIM_SettingsDefineState(){}

		// The "type" information for the object. Gettors only.
		virtual const string& ResourceURI() const { return CLASS_URI; }
		static const string& ClassResourceURI() { return CLASS_URI; }
		virtual const string& XmlNamespace() const { return CLASS_NS; }
		virtual const string& XmlPrefix() const { return CLASS_NS_PREFIX; }
		virtual const string& ObjectType() const { return CLASS_NAME; }
		static const string& ClassObjectType() { return CLASS_NAME; }

		// Class representing CIM_SettingsDefineState keys
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

			// Key, Required, The SettingData object that provides additional information about the current state and configuration of the ManagedElement.
			const CimReference SettingData() const
			{
				CimReference ret;
				TypeConverter::StringToType(GetKey("SettingData"), ret);
				return ret;
			}

			// Key, Required, The SettingData object that provides additional information about the current state and configuration of the ManagedElement.
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


		// Key, Required, The SettingData object that provides additional information about the current state and configuration of the ManagedElement.
		const CimReference SettingData() const;

		// Key, Required, The SettingData object that provides additional information about the current state and configuration of the ManagedElement.
		void SettingData(const CimReference &value); 


		 // Function used by the factory
		static CimBase *CreateFromCimObject(const CimObject &object);

		static vector<shared_ptr<CIM_SettingsDefineState> > Enumerate(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		// Overloaded delete which supplies the internal resourceURI
		static void Delete(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		using CimBase::Delete;

	protected:
		 // Protected constructor to be used by derived classes
		CIM_SettingsDefineState(ICimWsmanClient *client, const string &class_name,
			const string &class_ns, const string &prefix, const string &uri): CimBase(client, class_name, class_ns, prefix, uri)
		{
			if(_classMetaData.size() == 0)
			{
				CimBase::SetMetaData(_classMetaData, _metadata, 2);
			}
		}
		 // Protected constructor which receives CimObject
		CIM_SettingsDefineState(const CimObject &object)
			: CimBase(object)
		{
			if(_classMetaData.size() == 0)
			{
				CimBase::SetMetaData(_classMetaData, _metadata, 2);
			}
		}
		// Called by derived classes
		void SetMetaData(vector<CimFieldAttribute>& childMetaData)
		{
			CimBase::SetMetaData(childMetaData, _metadata, 2);
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
#endif // CIM_SETTINGSDEFINESTATE_H
