//----------------------------------------------------------------------------
//
//  Copyright (C) 2003 Intel Corporation
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
				CIM_Service::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 1);
			}
		}

		//constructor which receives WSMan client
		CIM_BootService(ICimWsmanClient *client)
			: CIM_Service(client, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_Service::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 1);
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
		//Input parameter for function RequestStateChange
		class CIMFRAMEWORK_API RequestStateChange_INPUT : public CimParam
		{
		public:
			// Class Constructor
			RequestStateChange_INPUT() : CimParam() {}

			// Class Destructor
			~RequestStateChange_INPUT(){}

			// Optional, The state requested for the element. This information will be placed into the RequestedState property of the instance if the return code of the RequestStateChange method is 0 ('Completed with No Error'), 3 ('Timeout'), or 4096 (0x1000) ('Job Started'). Refer to the description of the EnabledState and RequestedState properties for the detailed explanations of the RequestedState values.
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
			// DMTF Reserved: 12..32767
			// disable OCR and RPE, enable all other boot options: 32768
			// disable RPE, enable OCR and all other boot options: 32769
			// disable OCR, enable RPE and all other boot options: 32770
			// enable OCR, RPE and all other boot options: 32771
			void RequestedState(const unsigned short value); 

			// Optional, A timeout period that specifies the maximum amount of time that the client expects the transition to the new state to take. The interval format must be used to specify the TimeoutPeriod. A value of 0 or a null parameter indicates that the client has no time requirements for the transition. 
			// If this property does not contain 0 or null and the implementation does not support this parameter, a return code of 'Use Of Timeout Parameter Not Supported' must be returned.
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
			// Reference to the job (can be null if the task is completed).
			const CimReference Job() const;
			bool JobExists() const;
		private:
		};

		// Requests that the state of the element be changed to the value specified in the RequestedState parameter. When the requested state change takes place, the EnabledState and RequestedState of the element will be the same. Invoking the RequestStateChange method multiple times could result in earlier requests being overwritten or lost. 
		// If 0 is returned, then the task completed successfully and the use of ConcreteJob was not required. If 4096 (0x1000) is returned, then the task will take some time to complete, ConcreteJob will be created, and its reference returned in the output parameter Job. Any other return code indicates an error condition.
		virtual unsigned int RequestStateChange(const RequestStateChange_INPUT &input, RequestStateChange_OUTPUT &output);

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
				CIM_Service::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 1);
			}
		}
		 // Protected constructor which receives CimObject
		CIM_BootService(const CimObject &object)
			: CIM_Service(object)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_Service::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 1);
			}
		}
		// Called by derived classes
		void SetMetaData(vector<CimFieldAttribute>& childMetaData)
		{
			CIM_Service::SetMetaData(childMetaData);
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
#endif // CIM_BOOTSERVICE_H
