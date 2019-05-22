//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_BootConfigSetting.h
//
//  Contents:   A class derived from SettingData that provides the container to arrange all the BootSourceSetting instances in an ordered sequence. There can be one or more of the BootConfigSetting instances associated to a ComputerSystem. For example, one such BootConfigSetting could be a default boot configuration supplied by the manufacturer, a second one could be a configuration recommended by the IT Administrator. A third one could be the one actually to be used on next system boot.
//
//              This file was automatically generated from CIM_BootConfigSetting.mof,  version: 2.19.0
//
//----------------------------------------------------------------------------
#ifndef CIM_BOOTCONFIGSETTING_H
#define CIM_BOOTCONFIGSETTING_H 1
#include "CIM_SettingData.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	// A class derived from SettingData that provides the container to arrange all the BootSourceSetting instances in an ordered sequence. There can be one or more of the BootConfigSetting instances associated to a ComputerSystem. For example, one such BootConfigSetting could be a default boot configuration supplied by the manufacturer, a second one could be a configuration recommended by the IT Administrator. A third one could be the one actually to be used on next system boot.
	class CIMFRAMEWORK_API CIM_BootConfigSetting  : public CIM_SettingData
	{
	public:

		//Default constructor
		CIM_BootConfigSetting()
			: CIM_SettingData(NULL, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				_classMetaData = CIM_SettingData::GetMetaData();
			}
		}

		//constructor which receives WSMan client
		CIM_BootConfigSetting(ICimWsmanClient *client)
			: CIM_SettingData(client, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				_classMetaData = CIM_SettingData::GetMetaData();
			}
		}

		//Destructor
		virtual ~CIM_BootConfigSetting(){}

		// The "type" information for the object. Gettors only.
		virtual const string& ResourceURI() const { return CLASS_URI; }
		static const string& ClassResourceURI() { return CLASS_URI; }
		virtual const string& XmlNamespace() const { return CLASS_NS; }
		virtual const string& XmlPrefix() const { return CLASS_NS_PREFIX; }
		virtual const string& ObjectType() const { return CLASS_NAME; }
		static const string& ClassObjectType() { return CLASS_NAME; }

		// Class representing CIM_BootConfigSetting keys
		class CimKeys : public CIM_SettingData::CimKeys
		{
		public:
		};
		//Input parameter for function ChangeBootOrder
		class CIMFRAMEWORK_API ChangeBootOrder_INPUT : public CimParam
		{
		public:
			// Class Constructor
			ChangeBootOrder_INPUT() : CimParam() {}

			// Class Destructor
			~ChangeBootOrder_INPUT(){}

			// Required, An ordered array of BootSourceSettings.
			void Source(const vector<CimReference> &value); 

			const VectorFieldData GetAllFields() const;
		private:
			static const CimFieldAttribute _metadata[];
		};

		//Output parameter for function ChangeBootOrder
		class CIMFRAMEWORK_API ChangeBootOrder_OUTPUT : public CimParam
		{
		public:
			// Class Constructor
			ChangeBootOrder_OUTPUT() : CimParam() {}

			// Class Destructor
			~ChangeBootOrder_OUTPUT(){}

			// class fields
			// Reference to the job spawned if the operation continues after the method returns. (May be null if the task is completed).
			const CimReference Job() const;
			bool JobExists() const;
		private:
		};

		// This method is called to change the boot order within a boot configuration. An ordered array of BootSourceSetting instances is passed to this method. Each BootSourceSetting instance MUST already be associated with this BootConfigSetting instance via an instance of OrderedComponent. If not, the implementation MUST return a value of "Invalid Parameter" Upon execution of this method, the value of the AssignedSequence property on each instance of OrderedComponent will be updated such that the values are monotonically increasing in correlation with the position of the referenced BootSourceSetting instance in the source input parameter. That is, the first position in the array will have the lowest value for AssignedSequence. The second position will have the second lowest value, and so on. For BootSourceSetting instances which are associated with the BootConfigSetting instance via OrderedComponent and not present in the input array, the AssignedSequence property on the OrderedComponent association will be assigned a value of 0.
		virtual unsigned int ChangeBootOrder(const ChangeBootOrder_INPUT &input, ChangeBootOrder_OUTPUT &output);

		 // Function used by the factory
		static CimBase *CreateFromCimObject(const CimObject &object);

		static vector<shared_ptr<CIM_BootConfigSetting> > Enumerate(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		// Overloaded delete which supplies the internal resourceURI
		static void Delete(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		using CimBase::Delete;

	protected:
		 // Protected constructor to be used by derived classes
		CIM_BootConfigSetting(ICimWsmanClient *client, const string &class_name,
			const string &class_ns, const string &prefix, const string &uri): CIM_SettingData(client, class_name, class_ns, prefix, uri)
		{
			if(_classMetaData.size() == 0)
			{
				_classMetaData = CIM_SettingData::GetMetaData();
			}
		}
		 // Protected constructor which receives CimObject
		CIM_BootConfigSetting(const CimObject &object)
			: CIM_SettingData(object)
		{
			if(_classMetaData.size() == 0)
			{
				_classMetaData = CIM_SettingData::GetMetaData();
			}
		}
		// Called by derived classes
		void SetMetaData(vector<CimFieldAttribute>& childMetaData)
		{
			CIM_SettingData::SetMetaData(childMetaData);
		}
		const vector<CimFieldAttribute> &GetMetaData() const;
	private:
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
#endif // CIM_BOOTCONFIGSETTING_H
