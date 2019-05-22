//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       IPS_ScreenConfigurationService.h
//
//  Contents:   Configures the screen blanking settings in the Intel(R) AMT subsystem.
//
//              This file was automatically generated from IPS_ScreenConfigurationService.mof,  version: 10.0.0
//
//----------------------------------------------------------------------------
#ifndef IPS_SCREENCONFIGURATIONSERVICE_H
#define IPS_SCREENCONFIGURATIONSERVICE_H 1
#include "CIM_Service.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	// Configures the screen blanking settings in the Intel(R) AMT subsystem.
	class CIMFRAMEWORK_API IPS_ScreenConfigurationService  : public CIM_Service
	{
	public:

		//Default constructor
		IPS_ScreenConfigurationService()
			: CIM_Service(NULL, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_Service::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 3);
			}
		}

		//constructor which receives WSMan client
		IPS_ScreenConfigurationService(ICimWsmanClient *client)
			: CIM_Service(client, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_Service::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 3);
			}
		}

		//Destructor
		virtual ~IPS_ScreenConfigurationService(){}

		// The "type" information for the object. Gettors only.
		virtual const string& ResourceURI() const { return CLASS_URI; }
		static const string& ClassResourceURI() { return CLASS_URI; }
		virtual const string& XmlNamespace() const { return CLASS_NS; }
		virtual const string& XmlPrefix() const { return CLASS_NS_PREFIX; }
		virtual const string& ObjectType() const { return CLASS_NAME; }
		static const string& ClassObjectType() { return CLASS_NAME; }

		// Class representing IPS_ScreenConfigurationService keys
		class CimKeys : public CIM_Service::CimKeys
		{
		public:
		};

		// class fields declarations

		// Optional, Indicates if currently screen blanking session is open. This property is read only.
		const unsigned short CurrentState() const;

		// Optional, Indicates if currently screen blanking session is open. This property is read only.
		void CurrentState(const unsigned short value); 

		// Is true if the field CurrentState exists in the current object, otherwise is false.
		bool CurrentStateExists() const;

		// Remove CurrentState field.
		void RemoveCurrentState(); 

		// Optional, Indicates if currently screen blanking is enabled, i.e. screen blanking session can be opened.
		const unsigned short EnabledState() const;

		// Optional, Indicates if currently screen blanking is enabled, i.e. screen blanking session can be opened.
		void EnabledState(const unsigned short value); 

		// Is true if the field EnabledState exists in the current object, otherwise is false.
		bool EnabledStateExists() const;

		// Remove EnabledState field.
		void RemoveEnabledState(); 

		// Optional, number of remaining conscutive reboots that will end the screen blanking session. If the value is 0 AMT will not blank the screen after a reboot.Only a warm reset should be counted as a reboot. Global reset or a power cycle reset will not survive the screen blanking session.This property is read only.
		const unsigned short RemainingConsecutiveRebootsNum() const;

		// Optional, number of remaining conscutive reboots that will end the screen blanking session. If the value is 0 AMT will not blank the screen after a reboot.Only a warm reset should be counted as a reboot. Global reset or a power cycle reset will not survive the screen blanking session.This property is read only.
		void RemainingConsecutiveRebootsNum(const unsigned short value); 

		// Is true if the field RemainingConsecutiveRebootsNum exists in the current object, otherwise is false.
		bool RemainingConsecutiveRebootsNumExists() const;

		// Remove RemainingConsecutiveRebootsNum field.
		void RemoveRemainingConsecutiveRebootsNum(); 

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

		//Input parameter for function SetSessionState
		class CIMFRAMEWORK_API SetSessionState_INPUT : public CimParam
		{
		public:
			// Class Constructor
			SetSessionState_INPUT() : CimParam() {}

			// Class Destructor
			~SetSessionState_INPUT(){}

			// Optional, Open if required to open session blanking session, Otherwise, (close session) the parameter is Close.
			// Legal values:
			// Close: 0
			// Open: 1
			// Reserved: 2..
			void SessionState(const unsigned char &value); 

			// Optional, If SessionState is Open, reflects number of reboots session should survive.
			// Legal values:
			// Number of screen blanking reboots: 0..3
			// Reserved: 4..
			void ConsecutiveRebootsNum(const unsigned char &value); 

			const VectorFieldData GetAllFields() const;
		private:
			static const CimFieldAttribute _metadata[];
		};

		// AMT will start a screen blanking session and require the GFX to blank all the screens connected to the iGFX simultaneously.
		virtual unsigned int SetSessionState(const SetSessionState_INPUT &input);

		 // Function used by the factory
		static CimBase *CreateFromCimObject(const CimObject &object);

		static vector<shared_ptr<IPS_ScreenConfigurationService> > Enumerate(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		// Overloaded delete which supplies the internal resourceURI
		static void Delete(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		using CimBase::Delete;

	protected:
		 // Protected constructor to be used by derived classes
		IPS_ScreenConfigurationService(ICimWsmanClient *client, const string &class_name,
			const string &class_ns, const string &prefix, const string &uri): CIM_Service(client, class_name, class_ns, prefix, uri)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_Service::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 3);
			}
		}
		 // Protected constructor which receives CimObject
		IPS_ScreenConfigurationService(const CimObject &object)
			: CIM_Service(object)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_Service::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 3);
			}
		}
		// Called by derived classes
		void SetMetaData(vector<CimFieldAttribute>& childMetaData)
		{
			CIM_Service::SetMetaData(childMetaData);
			CimBase::SetMetaData(childMetaData, _metadata, 3);
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
#endif // IPS_SCREENCONFIGURATIONSERVICE_H
