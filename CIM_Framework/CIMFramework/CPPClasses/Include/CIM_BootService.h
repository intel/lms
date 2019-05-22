//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_BootService.h
//
//  Contents:   A class derived from Service that provides the controls to manage the boot configuration of a managed computer system or device. This includes changing the order of the boot devices and affecting settings on managed elements during the boot process. This service can also affect the load of a specific operating system on the computer system through a BootSourceSetting that points to a specific operating system image.
//
//              This file was automatically generated from CIM_BootService.mof,  version: 2.19.0
//
//----------------------------------------------------------------------------
#ifndef CIM_BOOTSERVICE_H
#define CIM_BOOTSERVICE_H 1
#include "CIM_Service.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	// A class derived from Service that provides the controls to manage the boot configuration of a managed computer system or device. This includes changing the order of the boot devices and affecting settings on managed elements during the boot process. This service can also affect the load of a specific operating system on the computer system through a BootSourceSetting that points to a specific operating system image.
	class CIMFRAMEWORK_API CIM_BootService  : public CIM_Service
	{
	public:

		//Default constructor
		CIM_BootService()
			: CIM_Service(NULL, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				_classMetaData = CIM_Service::GetMetaData();
			}
		}

		//constructor which receives WSMan client
		CIM_BootService(ICimWsmanClient *client)
			: CIM_Service(client, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				_classMetaData = CIM_Service::GetMetaData();
			}
		}

		//Destructor
		virtual ~CIM_BootService(){}

		// The "type" information for the object. Gettors only.
		virtual const string& ResourceURI() const { return CLASS_URI; }
		static const string& ClassResourceURI() { return CLASS_URI; }
		virtual const string& XmlNamespace() const { return CLASS_NS; }
		virtual const string& XmlPrefix() const { return CLASS_NS_PREFIX; }
		virtual const string& ObjectType() const { return CLASS_NAME; }
		static const string& ClassObjectType() { return CLASS_NAME; }

		// Class representing CIM_BootService keys
		class CimKeys : public CIM_Service::CimKeys
		{
		public:
		};
		//Input parameter for function SetBootConfigRole
		class CIMFRAMEWORK_API SetBootConfigRole_INPUT : public CimParam
		{
		public:
			// Class Constructor
			SetBootConfigRole_INPUT() : CimParam() {}

			// Class Destructor
			~SetBootConfigRole_INPUT(){}

			// Required, An existing BootConfigSetting instance whose role will be updated.
			void BootConfigSetting(const CimReference &value); 

			// Required, The desired Role of the BootConfigSetting. 
			// "IsNext" updates the ElementSettingData.IsNext property and indicates that the specified BootConfigSetting is to be used in the future when any of its related ComputerSystems are enabled.
			// "IsNextSingleUse" updates the ElementSettingData.IsNext property. It is similar to IsNext, except the change applies only to the next time a related ComputerSystem is enabled.
			// "IsDefault" updates the ElementSettingData.IsDefault property to indicate that the BootConfigSetting is identified as the default boot configuration for any of its related ComputerSystems
			// Legal values:
			// IsNext: 0
			// IsNextSingleUse: 1
			// IsDefault: 2
			// DMTF Reserved: 3..32767
			// Vendor Specified: 32768..65535
			void Role(const unsigned short value); 

			const VectorFieldData GetAllFields() const;
		private:
			static const CimFieldAttribute _metadata[];
		};

		//Output parameter for function SetBootConfigRole
		class CIMFRAMEWORK_API SetBootConfigRole_OUTPUT : public CimParam
		{
		public:
			// Class Constructor
			SetBootConfigRole_OUTPUT() : CimParam() {}

			// Class Destructor
			~SetBootConfigRole_OUTPUT(){}

			// class fields
			// Reference to the job spawned if the operation continues after the method returns. (May be null if the task is completed).
			const CimReference Job() const;
			bool JobExists() const;
		private:
		};

		// This method is called to set the role of the BootConfigSetting that is directly or indirectly associated to one or more ComputerSystems. The method applies the new role equally to all related ComputerSystems. If a BootConfigSetting can be related to more than one ComputerSystem, but role modification applies to just one of them, the SetBootConfigUsage method shall be used instead.
		// The method shall update the IsNext or IsDefault property of every ElementSettingData that directly or indirectly associates BootConfigSetting to a ComputerSystem. The method may also update the IsNext or IsDefault property of other ElementSettingDatas that reference the same ComputerSystems to satisfy cardinality constraints.
		virtual unsigned int SetBootConfigRole(const SetBootConfigRole_INPUT &input, SetBootConfigRole_OUTPUT &output);

		 // Function used by the factory
		static CimBase *CreateFromCimObject(const CimObject &object);

		static vector<shared_ptr<CIM_BootService> > Enumerate(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		// Overloaded delete which supplies the internal resourceURI
		static void Delete(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		using CimBase::Delete;

	protected:
		 // Protected constructor to be used by derived classes
		CIM_BootService(ICimWsmanClient *client, const string &class_name,
			const string &class_ns, const string &prefix, const string &uri): CIM_Service(client, class_name, class_ns, prefix, uri)
		{
			if(_classMetaData.size() == 0)
			{
				_classMetaData = CIM_Service::GetMetaData();
			}
		}
		 // Protected constructor which receives CimObject
		CIM_BootService(const CimObject &object)
			: CIM_Service(object)
		{
			if(_classMetaData.size() == 0)
			{
				_classMetaData = CIM_Service::GetMetaData();
			}
		}
		// Called by derived classes
		void SetMetaData(vector<CimFieldAttribute>& childMetaData)
		{
			CIM_Service::SetMetaData(childMetaData);
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
#endif // CIM_BOOTSERVICE_H
