//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_LogicalDevice.h
//
//  Contents:   An abstraction or emulation of a hardware entity, that may or may not be Realized in physical hardware. Any characteristics of a LogicalDevice that are used to manage its operation or configuration are contained in, or associated with, the LogicalDevice object. Examples of the operational properties of a Printer would be paper sizes supported, or detected errors. Examples of the configuration properties of a Sensor Device would be threshold settings. Various configurations could exist for a LogicalDevice. These configurations could be contained in Setting objects and associated with the LogicalDevice.
//
//              This file was automatically generated from CIM_LogicalDevice.mof,  version: 2.8.0
//
//----------------------------------------------------------------------------
#ifndef CIM_LOGICALDEVICE_H
#define CIM_LOGICALDEVICE_H 1
#include "CIM_EnabledLogicalElement.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	// An abstraction or emulation of a hardware entity, that may or may not be Realized in physical hardware. Any characteristics of a LogicalDevice that are used to manage its operation or configuration are contained in, or associated with, the LogicalDevice object. Examples of the operational properties of a Printer would be paper sizes supported, or detected errors. Examples of the configuration properties of a Sensor Device would be threshold settings. Various configurations could exist for a LogicalDevice. These configurations could be contained in Setting objects and associated with the LogicalDevice.
	class CIMFRAMEWORK_API CIM_LogicalDevice  : public CIM_EnabledLogicalElement
	{
	public:

		//Default constructor
		CIM_LogicalDevice()
			: CIM_EnabledLogicalElement(NULL, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_EnabledLogicalElement::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 17);
			}
		}

		//constructor which receives WSMan client
		CIM_LogicalDevice(ICimWsmanClient *client)
			: CIM_EnabledLogicalElement(client, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_EnabledLogicalElement::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 17);
			}
		}

		//Destructor
		virtual ~CIM_LogicalDevice(){}

		// The "type" information for the object. Gettors only.
		virtual const string& ResourceURI() const { return CLASS_URI; }
		static const string& ClassResourceURI() { return CLASS_URI; }
		virtual const string& XmlNamespace() const { return CLASS_NS; }
		virtual const string& XmlPrefix() const { return CLASS_NS_PREFIX; }
		virtual const string& ObjectType() const { return CLASS_NAME; }
		static const string& ClassObjectType() { return CLASS_NAME; }

		// Class representing CIM_LogicalDevice keys
		class CimKeys : public CIM_EnabledLogicalElement::CimKeys
		{
		public:
			// Key, Required, The scoping System's CreationClassName.
			const string SystemCreationClassName() const
			{
				return GetKey("SystemCreationClassName");
			}

			// Key, Required, The scoping System's CreationClassName.
			void SystemCreationClassName(const string &value)
			{
				SetOrAddKey("SystemCreationClassName", value);
			}

			// Key, Required, The scoping System's Name.
			const string SystemName() const
			{
				return GetKey("SystemName");
			}

			// Key, Required, The scoping System's Name.
			void SystemName(const string &value)
			{
				SetOrAddKey("SystemName", value);
			}

			// Key, Required, CreationClassName indicates the name of the class or the subclass used in the creation of an instance. When used with the other key properties of this class, this property allows all instances of this class and its subclasses to be uniquely identified.
			const string CreationClassName() const
			{
				return GetKey("CreationClassName");
			}

			// Key, Required, CreationClassName indicates the name of the class or the subclass used in the creation of an instance. When used with the other key properties of this class, this property allows all instances of this class and its subclasses to be uniquely identified.
			void CreationClassName(const string &value)
			{
				SetOrAddKey("CreationClassName", value);
			}

			// Key, Required, An address or other identifying information to uniquely name the LogicalDevice.
			const string DeviceID() const
			{
				return GetKey("DeviceID");
			}

			// Key, Required, An address or other identifying information to uniquely name the LogicalDevice.
			void DeviceID(const string &value)
			{
				SetOrAddKey("DeviceID", value);
			}

		};

		// class fields declarations

		// Key, Required, The scoping System's CreationClassName.
		const string SystemCreationClassName() const;

		// Key, Required, The scoping System's CreationClassName.
		void SystemCreationClassName(const string &value); 


		// Key, Required, The scoping System's Name.
		const string SystemName() const;

		// Key, Required, The scoping System's Name.
		void SystemName(const string &value); 


		// Key, Required, CreationClassName indicates the name of the class or the subclass used in the creation of an instance. When used with the other key properties of this class, this property allows all instances of this class and its subclasses to be uniquely identified.
		const string CreationClassName() const;

		// Key, Required, CreationClassName indicates the name of the class or the subclass used in the creation of an instance. When used with the other key properties of this class, this property allows all instances of this class and its subclasses to be uniquely identified.
		void CreationClassName(const string &value); 


		// Key, Required, An address or other identifying information to uniquely name the LogicalDevice.
		const string DeviceID() const;

		// Key, Required, An address or other identifying information to uniquely name the LogicalDevice.
		void DeviceID(const string &value); 


		// Optional, Boolean indicating that the Device can be power managed. The use of this property has been deprecated. Instead, the existence of an associated PowerManagementCapabilities class (associated using the ElementCapabilities relationhip) indicates that power management is supported.
		const bool PowerManagementSupported() const;

		// Optional, Boolean indicating that the Device can be power managed. The use of this property has been deprecated. Instead, the existence of an associated PowerManagementCapabilities class (associated using the ElementCapabilities relationhip) indicates that power management is supported.
		void PowerManagementSupported(const bool value); 

		// Is true if the field PowerManagementSupported exists in the current object, otherwise is false.
		bool PowerManagementSupportedExists() const;

		// Remove PowerManagementSupported field.
		void RemovePowerManagementSupported(); 

		// Optional, An enumerated array describing the power management capabilities of the Device. The use of this property has been deprecated. Instead, the PowerCapabilites property in an associated PowerManagementCapabilities class should be used.
		const vector<unsigned short> PowerManagementCapabilities() const;

		// Optional, An enumerated array describing the power management capabilities of the Device. The use of this property has been deprecated. Instead, the PowerCapabilites property in an associated PowerManagementCapabilities class should be used.
		void PowerManagementCapabilities(const vector<unsigned short> &value); 

		// Is true if the field PowerManagementCapabilities exists in the current object, otherwise is false.
		bool PowerManagementCapabilitiesExists() const;

		// Remove PowerManagementCapabilities field.
		void RemovePowerManagementCapabilities(); 

		// Optional, The primary availability and status of the Device. (Additional status information can be specified using the Additional Availability array property.) For example, the Availability property indicates that the Device is running and has full power (value=3), or is in a warning (4), test (5), degraded (10) or power save state (values 13-15 and 17). Regarding the Power Save states, these are defined as follows: Value 13 ("Power Save - Unknown") indicates that the Device is known to be in a power save mode, but its exact status in this mode is unknown; 14 ("Power Save - Low Power Mode") indicates that the Device is in a power save state but still functioning, and may exhibit degraded performance; 15 ("Power Save - Standby") describes that the Device is not functioning but could be brought to full power 'quickly'; and value 17 ("Power Save - Warning") indicates that the Device is in a warning state, though also in a power save mode.
		const unsigned short Availability() const;

		// Optional, The primary availability and status of the Device. (Additional status information can be specified using the Additional Availability array property.) For example, the Availability property indicates that the Device is running and has full power (value=3), or is in a warning (4), test (5), degraded (10) or power save state (values 13-15 and 17). Regarding the Power Save states, these are defined as follows: Value 13 ("Power Save - Unknown") indicates that the Device is known to be in a power save mode, but its exact status in this mode is unknown; 14 ("Power Save - Low Power Mode") indicates that the Device is in a power save state but still functioning, and may exhibit degraded performance; 15 ("Power Save - Standby") describes that the Device is not functioning but could be brought to full power 'quickly'; and value 17 ("Power Save - Warning") indicates that the Device is in a warning state, though also in a power save mode.
		void Availability(const unsigned short value); 

		// Is true if the field Availability exists in the current object, otherwise is false.
		bool AvailabilityExists() const;

		// Remove Availability field.
		void RemoveAvailability(); 

		// Optional, The StatusInfo property indicates whether the Logical Device is in an enabled (value = 3), disabled (value = 4) or some other (1) or unknown (2) state. If this property does not apply to the LogicalDevice, the value, 5 ("Not Applicable"), should be used. StatusInfo has been deprecated in lieu of a more clearly named property with additional enumerated values (EnabledState), that is inherited from ManagedSystemElement. 
		// If a Device is ("Enabled")(value=3), it has been powered up, and is configured and operational. The Device may or may not be functionally active, depending on whether its Availability (or AdditionalAvailability) indicate that it is ("Running/Full Power")(value=3) or ("Off line") (value=8). In an enabled but offline mode, a Device may be performing out-of-band requests, such as running Diagnostics. If ("Disabled") StatusInfo value=4), a Device can only be "enabled" or powered off. In a personal computer environment, ("Disabled") means that the Device's driver is not available in the stack. In other environments, a Device can be disabled by removing its configuration file. A disabled device is physically present in a System and consuming resources, but can not be communicated with until a load of a driver, a load of a configuration file or some other "enabling" activity has occurred.
		const unsigned short StatusInfo() const;

		// Optional, The StatusInfo property indicates whether the Logical Device is in an enabled (value = 3), disabled (value = 4) or some other (1) or unknown (2) state. If this property does not apply to the LogicalDevice, the value, 5 ("Not Applicable"), should be used. StatusInfo has been deprecated in lieu of a more clearly named property with additional enumerated values (EnabledState), that is inherited from ManagedSystemElement. 
		// If a Device is ("Enabled")(value=3), it has been powered up, and is configured and operational. The Device may or may not be functionally active, depending on whether its Availability (or AdditionalAvailability) indicate that it is ("Running/Full Power")(value=3) or ("Off line") (value=8). In an enabled but offline mode, a Device may be performing out-of-band requests, such as running Diagnostics. If ("Disabled") StatusInfo value=4), a Device can only be "enabled" or powered off. In a personal computer environment, ("Disabled") means that the Device's driver is not available in the stack. In other environments, a Device can be disabled by removing its configuration file. A disabled device is physically present in a System and consuming resources, but can not be communicated with until a load of a driver, a load of a configuration file or some other "enabling" activity has occurred.
		void StatusInfo(const unsigned short value); 

		// Is true if the field StatusInfo exists in the current object, otherwise is false.
		bool StatusInfoExists() const;

		// Remove StatusInfo field.
		void RemoveStatusInfo(); 

		// Optional, LastErrorCode captures the last error code reported by the LogicalDevice.
		const unsigned int LastErrorCode() const;

		// Optional, LastErrorCode captures the last error code reported by the LogicalDevice.
		void LastErrorCode(const unsigned int value); 

		// Is true if the field LastErrorCode exists in the current object, otherwise is false.
		bool LastErrorCodeExists() const;

		// Remove LastErrorCode field.
		void RemoveLastErrorCode(); 

		// Optional, ErrorDescription is a free-form string supplying more information about the error recorded in LastErrorCode, and information on any corrective actions that may be taken.
		const string ErrorDescription() const;

		// Optional, ErrorDescription is a free-form string supplying more information about the error recorded in LastErrorCode, and information on any corrective actions that may be taken.
		void ErrorDescription(const string &value); 

		// Is true if the field ErrorDescription exists in the current object, otherwise is false.
		bool ErrorDescriptionExists() const;

		// Remove ErrorDescription field.
		void RemoveErrorDescription(); 

		// Optional, ErrorCleared is a boolean property indicating that the error reported in LastErrorCode is now cleared.
		const bool ErrorCleared() const;

		// Optional, ErrorCleared is a boolean property indicating that the error reported in LastErrorCode is now cleared.
		void ErrorCleared(const bool value); 

		// Is true if the field ErrorCleared exists in the current object, otherwise is false.
		bool ErrorClearedExists() const;

		// Remove ErrorCleared field.
		void RemoveErrorCleared(); 

		// Optional, OtherIdentifyingInfo captures additional data, beyond DeviceID information, that could be used to identify a LogicalDevice. One example would be to hold the Operating System's user friendly name for the Device in this property.
		const vector<string> OtherIdentifyingInfo() const;

		// Optional, OtherIdentifyingInfo captures additional data, beyond DeviceID information, that could be used to identify a LogicalDevice. One example would be to hold the Operating System's user friendly name for the Device in this property.
		void OtherIdentifyingInfo(const vector<string> &value); 

		// Is true if the field OtherIdentifyingInfo exists in the current object, otherwise is false.
		bool OtherIdentifyingInfoExists() const;

		// Remove OtherIdentifyingInfo field.
		void RemoveOtherIdentifyingInfo(); 

		// Optional, The number of consecutive hours that this Device has been powered, since its last power cycle.
		const Uint64 PowerOnHours() const;

		// Optional, The number of consecutive hours that this Device has been powered, since its last power cycle.
		void PowerOnHours(const Uint64 value); 

		// Is true if the field PowerOnHours exists in the current object, otherwise is false.
		bool PowerOnHoursExists() const;

		// Remove PowerOnHours field.
		void RemovePowerOnHours(); 

		// Optional, The total number of hours that this Device has been powered.
		const Uint64 TotalPowerOnHours() const;

		// Optional, The total number of hours that this Device has been powered.
		void TotalPowerOnHours(const Uint64 value); 

		// Is true if the field TotalPowerOnHours exists in the current object, otherwise is false.
		bool TotalPowerOnHoursExists() const;

		// Remove TotalPowerOnHours field.
		void RemoveTotalPowerOnHours(); 

		// Optional, An array of free-form strings providing explanations and details behind the entries in the OtherIdentifyingInfo array. Note, each entry of this array is related to the entry in OtherIdentifyingInfo that is located at the same index.
		const vector<string> IdentifyingDescriptions() const;

		// Optional, An array of free-form strings providing explanations and details behind the entries in the OtherIdentifyingInfo array. Note, each entry of this array is related to the entry in OtherIdentifyingInfo that is located at the same index.
		void IdentifyingDescriptions(const vector<string> &value); 

		// Is true if the field IdentifyingDescriptions exists in the current object, otherwise is false.
		bool IdentifyingDescriptionsExists() const;

		// Remove IdentifyingDescriptions field.
		void RemoveIdentifyingDescriptions(); 

		// Optional, Additional availability and status of the Device, beyond that specified in the Availability property. The Availability property denotes the primary status and availability of the Device. In some cases, this will not be sufficient to denote the complete status of the Device. In those cases, the AdditionalAvailability property can be used to provide further information. For example, a Device's primary Availability may be "Off line" (value=8), but it may also be in a low power state (AdditonalAvailability value=14), or the Device could be running Diagnostics (AdditionalAvailability value=5, "In Test").
		const vector<unsigned short> AdditionalAvailability() const;

		// Optional, Additional availability and status of the Device, beyond that specified in the Availability property. The Availability property denotes the primary status and availability of the Device. In some cases, this will not be sufficient to denote the complete status of the Device. In those cases, the AdditionalAvailability property can be used to provide further information. For example, a Device's primary Availability may be "Off line" (value=8), but it may also be in a low power state (AdditonalAvailability value=14), or the Device could be running Diagnostics (AdditionalAvailability value=5, "In Test").
		void AdditionalAvailability(const vector<unsigned short> &value); 

		// Is true if the field AdditionalAvailability exists in the current object, otherwise is false.
		bool AdditionalAvailabilityExists() const;

		// Remove AdditionalAvailability field.
		void RemoveAdditionalAvailability(); 

		// Optional, The MaxQuiesceTime property has been deprecated. When evaluating the use of Quiesce, it was determine that this single property is not adequate for describing when a device will automatically exit a quiescent state. In fact, the most likely scenario for a device to exit a quiescent state was determined to be based on the number of outstanding requests queued rather than on a maximum time. This will be re-evaluated and repositioned later. 
		// Maximum time in milliseconds, that a Device can run in a "Quiesced" state. A Device's state is defined in its Availability and AdditionalAvailability properties, where "Quiesced" is conveyed by the value 21. What occurs at the end of the time limit is device-specific. The Device may unquiesce, may offline or take other action. A value of 0 indicates that a Device can remain quiesced indefinitely.
		const Uint64 MaxQuiesceTime() const;

		// Optional, The MaxQuiesceTime property has been deprecated. When evaluating the use of Quiesce, it was determine that this single property is not adequate for describing when a device will automatically exit a quiescent state. In fact, the most likely scenario for a device to exit a quiescent state was determined to be based on the number of outstanding requests queued rather than on a maximum time. This will be re-evaluated and repositioned later. 
		// Maximum time in milliseconds, that a Device can run in a "Quiesced" state. A Device's state is defined in its Availability and AdditionalAvailability properties, where "Quiesced" is conveyed by the value 21. What occurs at the end of the time limit is device-specific. The Device may unquiesce, may offline or take other action. A value of 0 indicates that a Device can remain quiesced indefinitely.
		void MaxQuiesceTime(const Uint64 value); 

		// Is true if the field MaxQuiesceTime exists in the current object, otherwise is false.
		bool MaxQuiesceTimeExists() const;

		// Remove MaxQuiesceTime field.
		void RemoveMaxQuiesceTime(); 

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

		// Requests a reset of the LogicalDevice. The return value should be 0 if the request was successfully executed, 1 if the request is not supported and some other value if an error occurred. In a subclass, the set of possible return codes could be specified, using a ValueMap qualifier on the method. The strings to which the ValueMap contents are 'translated' may also be specified in the subclass as a Values array qualifier.
		virtual unsigned int Reset();

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

		// Requests that the Device capture its current configuration, setup and/or state information in a backing store. The goal would be to use this information at a later time (via the RestoreProperties method), to return a Device to its present "condition". This method may not be supported by all Devices. The method should return 0 if successful, 1 if the request is not supported, and some other value if any other error occurred. In a subclass, the set of possible return codes could be specified, using a ValueMap qualifier on the method. The strings to which the ValueMap contents are 'translated' may also be specified in the subclass as a Values array qualifier.
		virtual unsigned int SaveProperties();

		// Requests that the Device re-establish its configuration, setup and/or state information from a backing store. The intent is to capture this information at an earlier time (via the SaveProperties method), and use it to return a Device to this earlier "condition". This method may not be supported by all Devices. The method should return 0 if successful, 1 if the request is not supported, and some other value if any other error occurred. In a subclass, the set of possible return codes could be specified, using a ValueMap qualifier on the method. The strings to which the ValueMap contents are 'translated' may also be specified in the subclass as a Values array qualifier.
		virtual unsigned int RestoreProperties();

		 // Function used by the factory
		static CimBase *CreateFromCimObject(const CimObject &object);

		static vector<shared_ptr<CIM_LogicalDevice> > Enumerate(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		// Overloaded delete which supplies the internal resourceURI
		static void Delete(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		using CimBase::Delete;

	protected:
		 // Protected constructor to be used by derived classes
		CIM_LogicalDevice(ICimWsmanClient *client, const string &class_name,
			const string &class_ns, const string &prefix, const string &uri): CIM_EnabledLogicalElement(client, class_name, class_ns, prefix, uri)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_EnabledLogicalElement::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 17);
			}
		}
		 // Protected constructor which receives CimObject
		CIM_LogicalDevice(const CimObject &object)
			: CIM_EnabledLogicalElement(object)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_EnabledLogicalElement::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 17);
			}
		}
		// Called by derived classes
		void SetMetaData(vector<CimFieldAttribute>& childMetaData)
		{
			CIM_EnabledLogicalElement::SetMetaData(childMetaData);
			CimBase::SetMetaData(childMetaData, _metadata, 17);
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
#endif // CIM_LOGICALDEVICE_H
