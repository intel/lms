//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_PCIController.h
//
//  Contents:   PCIController is a superclass for the PCIBridge and PCIDevice classes. These classes model adapters and bridges on a PCI bus. The properties in PCIController and its subclasses are defined in the various PCI Specifications that are published by the PCI SIG.
//
//              This file was automatically generated from CIM_PCIController.mof,  version: 2.28.0
//
//----------------------------------------------------------------------------
#ifndef CIM_PCICONTROLLER_H
#define CIM_PCICONTROLLER_H 1
#include "CIM_Controller.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	// PCIController is a superclass for the PCIBridge and PCIDevice classes. These classes model adapters and bridges on a PCI bus. The properties in PCIController and its subclasses are defined in the various PCI Specifications that are published by the PCI SIG.
	class CIMFRAMEWORK_API CIM_PCIController  : public CIM_Controller
	{
	public:

		//Default constructor
		CIM_PCIController()
			: CIM_Controller(NULL, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_Controller::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 10);
			}
		}

		//constructor which receives WSMan client
		CIM_PCIController(ICimWsmanClient *client)
			: CIM_Controller(client, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_Controller::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 10);
			}
		}

		//Destructor
		virtual ~CIM_PCIController(){}

		// The "type" information for the object. Gettors only.
		virtual const string& ResourceURI() const { return CLASS_URI; }
		static const string& ClassResourceURI() { return CLASS_URI; }
		virtual const string& XmlNamespace() const { return CLASS_NS; }
		virtual const string& XmlPrefix() const { return CLASS_NS_PREFIX; }
		virtual const string& ObjectType() const { return CLASS_NAME; }
		static const string& ClassObjectType() { return CLASS_NAME; }

		// Class representing CIM_PCIController keys
		class CimKeys : public CIM_Controller::CimKeys
		{
		public:
		};

		// class fields declarations

		// Optional, Current contents of the register that provides basic control over the ability of the device to respond to or perform PCI accesses.
		const unsigned short CommandRegister() const;

		// Optional, Current contents of the register that provides basic control over the ability of the device to respond to or perform PCI accesses.
		void CommandRegister(const unsigned short value); 

		// Is true if the field CommandRegister exists in the current object, otherwise is false.
		bool CommandRegisterExists() const;

		// Remove CommandRegister field.
		void RemoveCommandRegister(); 

		// Optional, An array of integers that indicates controller capabilities. Information such as "Supports 66MHz" (value=2) is specified in this property. The data in the Capabilities array is gathered from the PCI Status Register and the PCI Capabilities List as defined in the PCI Specification.
		const vector<unsigned short> Capabilities() const;

		// Optional, An array of integers that indicates controller capabilities. Information such as "Supports 66MHz" (value=2) is specified in this property. The data in the Capabilities array is gathered from the PCI Status Register and the PCI Capabilities List as defined in the PCI Specification.
		void Capabilities(const vector<unsigned short> &value); 

		// Is true if the field Capabilities exists in the current object, otherwise is false.
		bool CapabilitiesExists() const;

		// Remove Capabilities field.
		void RemoveCapabilities(); 

		// Optional, An array of free-form strings that provides more detailed explanations for any of the PCIController features that are indicated in the Capabilities array. Note, each entry of this array is related to the entry in the Capabilities array that is located at the same index.
		const vector<string> CapabilityDescriptions() const;

		// Optional, An array of free-form strings that provides more detailed explanations for any of the PCIController features that are indicated in the Capabilities array. Note, each entry of this array is related to the entry in the Capabilities array that is located at the same index.
		void CapabilityDescriptions(const vector<string> &value); 

		// Is true if the field CapabilityDescriptions exists in the current object, otherwise is false.
		bool CapabilityDescriptionsExists() const;

		// Remove CapabilityDescriptions field.
		void RemoveCapabilityDescriptions(); 

		// Optional, The slowest device-select timing for a target device.
		const unsigned short DeviceSelectTiming() const;

		// Optional, The slowest device-select timing for a target device.
		void DeviceSelectTiming(const unsigned short value); 

		// Is true if the field DeviceSelectTiming exists in the current object, otherwise is false.
		bool DeviceSelectTimingExists() const;

		// Remove DeviceSelectTiming field.
		void RemoveDeviceSelectTiming(); 

		// Optional, Register of 8 bits that identifies the basic function of the PCI device. This property is only the upper byte (offset 0Bh) of the 3-byte ClassCode field. Note that the ValueMap array of the property specifies the decimal representation of this information.
		const unsigned char ClassCode() const;

		// Optional, Register of 8 bits that identifies the basic function of the PCI device. This property is only the upper byte (offset 0Bh) of the 3-byte ClassCode field. Note that the ValueMap array of the property specifies the decimal representation of this information.
		void ClassCode(const unsigned char &value); 

		// Is true if the field ClassCode exists in the current object, otherwise is false.
		bool ClassCodeExists() const;

		// Remove ClassCode field.
		void RemoveClassCode(); 

		// Optional, Specifies the system cache line size in doubleword increments (for example, a 486-based system would store the value 04h, indicating a cache line size of four doublewords.
		const unsigned char CacheLineSize() const;

		// Optional, Specifies the system cache line size in doubleword increments (for example, a 486-based system would store the value 04h, indicating a cache line size of four doublewords.
		void CacheLineSize(const unsigned char &value); 

		// Is true if the field CacheLineSize exists in the current object, otherwise is false.
		bool CacheLineSizeExists() const;

		// Remove CacheLineSize field.
		void RemoveCacheLineSize(); 

		// Optional, Defines the minimum amount of time, in PCI clock cycles, that the bus master can retain ownership of the bus.
		const unsigned char LatencyTimer() const;

		// Optional, Defines the minimum amount of time, in PCI clock cycles, that the bus master can retain ownership of the bus.
		void LatencyTimer(const unsigned char &value); 

		// Is true if the field LatencyTimer exists in the current object, otherwise is false.
		bool LatencyTimerExists() const;

		// Remove LatencyTimer field.
		void RemoveLatencyTimer(); 

		// Optional, Defines the PCI interrupt request pin (INTA# to INTD#) to which a PCI functional device is connected.
		const unsigned short InterruptPin() const;

		// Optional, Defines the PCI interrupt request pin (INTA# to INTD#) to which a PCI functional device is connected.
		void InterruptPin(const unsigned short value); 

		// Is true if the field InterruptPin exists in the current object, otherwise is false.
		bool InterruptPinExists() const;

		// Remove InterruptPin field.
		void RemoveInterruptPin(); 

		// Optional, Doubleword Expansion ROM-base memory address.
		const unsigned int ExpansionROMBaseAddress() const;

		// Optional, Doubleword Expansion ROM-base memory address.
		void ExpansionROMBaseAddress(const unsigned int value); 

		// Is true if the field ExpansionROMBaseAddress exists in the current object, otherwise is false.
		bool ExpansionROMBaseAddressExists() const;

		// Remove ExpansionROMBaseAddress field.
		void RemoveExpansionROMBaseAddress(); 

		// Optional, Reports if the PCI device can perform the self-test function. Returns bit 7 of the BIST register as a Boolean.
		const bool SelfTestEnabled() const;

		// Optional, Reports if the PCI device can perform the self-test function. Returns bit 7 of the BIST register as a Boolean.
		void SelfTestEnabled(const bool value); 

		// Is true if the field SelfTestEnabled exists in the current object, otherwise is false.
		bool SelfTestEnabledExists() const;

		// Remove SelfTestEnabled field.
		void RemoveSelfTestEnabled(); 

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

		// Method to invoke PCI device self-test. This method sets bit 6 of the BIST register. The return result is the lower 4 bits of the BIST register where 0 indicates success and non-zero is a device-dependent failure. Support for this method is optional in the PCI Specification.
		virtual unsigned int BISTExecution();

		 // Function used by the factory
		static CimBase *CreateFromCimObject(const CimObject &object);

		static vector<shared_ptr<CIM_PCIController> > Enumerate(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		// Overloaded delete which supplies the internal resourceURI
		static void Delete(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		using CimBase::Delete;

	protected:
		 // Protected constructor to be used by derived classes
		CIM_PCIController(ICimWsmanClient *client, const string &class_name,
			const string &class_ns, const string &prefix, const string &uri): CIM_Controller(client, class_name, class_ns, prefix, uri)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_Controller::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 10);
			}
		}
		 // Protected constructor which receives CimObject
		CIM_PCIController(const CimObject &object)
			: CIM_Controller(object)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_Controller::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 10);
			}
		}
		// Called by derived classes
		void SetMetaData(vector<CimFieldAttribute>& childMetaData)
		{
			CIM_Controller::SetMetaData(childMetaData);
			CimBase::SetMetaData(childMetaData, _metadata, 10);
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
#endif // CIM_PCICONTROLLER_H
