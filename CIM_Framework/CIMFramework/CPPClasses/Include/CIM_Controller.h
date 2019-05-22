//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_Controller.h
//
//  Contents:   Controller is a superclass for grouping the miscellaneous control-related Devices that provide a classic bus master interface. Examples of Controllers are USBControllers, SerialControllers, and so on. The Controller class is an abstraction for Devices with a single protocol stack, which exist to control communications (data, control, and reset) to downstream devices. Note that a new abstract class (ProtocolController) has been created to model more complex interface controllers such as SCSI.
//
//              This file was automatically generated from CIM_Controller.mof,  version: 2.10.0
//
//----------------------------------------------------------------------------
#ifndef CIM_CONTROLLER_H
#define CIM_CONTROLLER_H 1
#include "CIM_LogicalDevice.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	// Controller is a superclass for grouping the miscellaneous control-related Devices that provide a classic bus master interface. Examples of Controllers are USBControllers, SerialControllers, and so on. The Controller class is an abstraction for Devices with a single protocol stack, which exist to control communications (data, control, and reset) to downstream devices. Note that a new abstract class (ProtocolController) has been created to model more complex interface controllers such as SCSI.
	class CIMFRAMEWORK_API CIM_Controller  : public CIM_LogicalDevice
	{
	public:

		//Default constructor
		CIM_Controller()
			: CIM_LogicalDevice(NULL, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_LogicalDevice::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 4);
			}
		}

		//constructor which receives WSMan client
		CIM_Controller(ICimWsmanClient *client)
			: CIM_LogicalDevice(client, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_LogicalDevice::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 4);
			}
		}

		//Destructor
		virtual ~CIM_Controller(){}

		// The "type" information for the object. Gettors only.
		virtual const string& ResourceURI() const { return CLASS_URI; }
		static const string& ClassResourceURI() { return CLASS_URI; }
		virtual const string& XmlNamespace() const { return CLASS_NS; }
		virtual const string& XmlPrefix() const { return CLASS_NS_PREFIX; }
		virtual const string& ObjectType() const { return CLASS_NAME; }
		static const string& ClassObjectType() { return CLASS_NAME; }

		// Class representing CIM_Controller keys
		class CimKeys : public CIM_LogicalDevice::CimKeys
		{
		public:
		};

		// class fields declarations

		// Optional, Time of last reset of the Controller.
		const CimDateTime TimeOfLastReset() const;

		// Optional, Time of last reset of the Controller.
		void TimeOfLastReset(const CimDateTime &value); 

		// Is true if the field TimeOfLastReset exists in the current object, otherwise is false.
		bool TimeOfLastResetExists() const;

		// Remove TimeOfLastReset field.
		void RemoveTimeOfLastReset(); 

		// Optional, The protocol used by the Controller to access controlled Devices.
		const unsigned short ProtocolSupported() const;

		// Optional, The protocol used by the Controller to access controlled Devices.
		void ProtocolSupported(const unsigned short value); 

		// Is true if the field ProtocolSupported exists in the current object, otherwise is false.
		bool ProtocolSupportedExists() const;

		// Remove ProtocolSupported field.
		void RemoveProtocolSupported(); 

		// Optional, Maximum number of directly addressable entities that are supported by this Controller. A value of 0 should be used if the number is unknown or unlimited.
		const unsigned int MaxNumberControlled() const;

		// Optional, Maximum number of directly addressable entities that are supported by this Controller. A value of 0 should be used if the number is unknown or unlimited.
		void MaxNumberControlled(const unsigned int value); 

		// Is true if the field MaxNumberControlled exists in the current object, otherwise is false.
		bool MaxNumberControlledExists() const;

		// Remove MaxNumberControlled field.
		void RemoveMaxNumberControlled(); 

		// Optional, A free-form string that provides more information that is related to the ProtocolSupported by the Controller.
		const string ProtocolDescription() const;

		// Optional, A free-form string that provides more information that is related to the ProtocolSupported by the Controller.
		void ProtocolDescription(const string &value); 

		// Is true if the field ProtocolDescription exists in the current object, otherwise is false.
		bool ProtocolDescriptionExists() const;

		// Remove ProtocolDescription field.
		void RemoveProtocolDescription(); 

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

		static vector<shared_ptr<CIM_Controller> > Enumerate(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		// Overloaded delete which supplies the internal resourceURI
		static void Delete(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		using CimBase::Delete;

	protected:
		 // Protected constructor to be used by derived classes
		CIM_Controller(ICimWsmanClient *client, const string &class_name,
			const string &class_ns, const string &prefix, const string &uri): CIM_LogicalDevice(client, class_name, class_ns, prefix, uri)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_LogicalDevice::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 4);
			}
		}
		 // Protected constructor which receives CimObject
		CIM_Controller(const CimObject &object)
			: CIM_LogicalDevice(object)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_LogicalDevice::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 4);
			}
		}
		// Called by derived classes
		void SetMetaData(vector<CimFieldAttribute>& childMetaData)
		{
			CIM_LogicalDevice::SetMetaData(childMetaData);
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
#endif // CIM_CONTROLLER_H
