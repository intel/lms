//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_NetworkPort.h
//
//  Contents:   NetworkPort is the logical representation of network communications hardware such as a physical connector and the setup or operation of the network chips, at the lowest layers of a network stack.
//
//              This file was automatically generated from CIM_NetworkPort.mof,  version: 2.10.0
//
//----------------------------------------------------------------------------
#ifndef CIM_NETWORKPORT_H
#define CIM_NETWORKPORT_H 1
#include "CIM_LogicalPort.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	// NetworkPort is the logical representation of network communications hardware such as a physical connector and the setup or operation of the network chips, at the lowest layers of a network stack.
	class CIMFRAMEWORK_API CIM_NetworkPort  : public CIM_LogicalPort
	{
	public:

		//Default constructor
		CIM_NetworkPort()
			: CIM_LogicalPort(NULL, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_LogicalPort::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 11);
			}
		}

		//constructor which receives WSMan client
		CIM_NetworkPort(ICimWsmanClient *client)
			: CIM_LogicalPort(client, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_LogicalPort::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 11);
			}
		}

		//Destructor
		virtual ~CIM_NetworkPort(){}

		// The "type" information for the object. Gettors only.
		virtual const string& ResourceURI() const { return CLASS_URI; }
		static const string& ClassResourceURI() { return CLASS_URI; }
		virtual const string& XmlNamespace() const { return CLASS_NS; }
		virtual const string& XmlPrefix() const { return CLASS_NS_PREFIX; }
		virtual const string& ObjectType() const { return CLASS_NAME; }
		static const string& ClassObjectType() { return CLASS_NAME; }

		// Class representing CIM_NetworkPort keys
		class CimKeys : public CIM_LogicalPort::CimKeys
		{
		public:
		};

		// class fields declarations

		// Optional, Note: The use of this property is deprecated in lieu of CIM_LogicalPort.PortType. 
		// Deprecated description: The type of module, when PortType is set to 1 ("Other".)
		const string OtherNetworkPortType() const;

		// Optional, Note: The use of this property is deprecated in lieu of CIM_LogicalPort.PortType. 
		// Deprecated description: The type of module, when PortType is set to 1 ("Other".)
		void OtherNetworkPortType(const string &value); 

		// Is true if the field OtherNetworkPortType exists in the current object, otherwise is false.
		bool OtherNetworkPortTypeExists() const;

		// Remove OtherNetworkPortType field.
		void RemoveOtherNetworkPortType(); 

		// Optional, NetworkPorts are often numbered relative to either a logical module or a network element.
		const unsigned short PortNumber() const;

		// Optional, NetworkPorts are often numbered relative to either a logical module or a network element.
		void PortNumber(const unsigned short value); 

		// Is true if the field PortNumber exists in the current object, otherwise is false.
		bool PortNumberExists() const;

		// Remove PortNumber field.
		void RemovePortNumber(); 

		// Optional, An enumeration of the types of links. When set to 1 ("Other"), the related property OtherLinkTechnology contains a string description of the type of link.
		const unsigned short LinkTechnology() const;

		// Optional, An enumeration of the types of links. When set to 1 ("Other"), the related property OtherLinkTechnology contains a string description of the type of link.
		void LinkTechnology(const unsigned short value); 

		// Is true if the field LinkTechnology exists in the current object, otherwise is false.
		bool LinkTechnologyExists() const;

		// Remove LinkTechnology field.
		void RemoveLinkTechnology(); 

		// Optional, A string value that describes LinkTechnology when it is set to 1, "Other".
		const string OtherLinkTechnology() const;

		// Optional, A string value that describes LinkTechnology when it is set to 1, "Other".
		void OtherLinkTechnology(const string &value); 

		// Is true if the field OtherLinkTechnology exists in the current object, otherwise is false.
		bool OtherLinkTechnologyExists() const;

		// Remove OtherLinkTechnology field.
		void RemoveOtherLinkTechnology(); 

		// Optional, PermanentAddress defines the network address that is hardcoded into a port. This 'hardcoded' address can be changed using a firmware upgrade or a software configuration. When this change is made, the field should be updated at the same time. PermanentAddress should be left blank if no 'hardcoded' address exists for the NetworkAdapter.
		const string PermanentAddress() const;

		// Optional, PermanentAddress defines the network address that is hardcoded into a port. This 'hardcoded' address can be changed using a firmware upgrade or a software configuration. When this change is made, the field should be updated at the same time. PermanentAddress should be left blank if no 'hardcoded' address exists for the NetworkAdapter.
		void PermanentAddress(const string &value); 

		// Is true if the field PermanentAddress exists in the current object, otherwise is false.
		bool PermanentAddressExists() const;

		// Remove PermanentAddress field.
		void RemovePermanentAddress(); 

		// Optional, An array of strings that indicates the network addresses for the port.
		const vector<string> NetworkAddresses() const;

		// Optional, An array of strings that indicates the network addresses for the port.
		void NetworkAddresses(const vector<string> &value); 

		// Is true if the field NetworkAddresses exists in the current object, otherwise is false.
		bool NetworkAddressesExists() const;

		// Remove NetworkAddresses field.
		void RemoveNetworkAddresses(); 

		// Optional, Boolean that indicates that the port is operating in full duplex mode.
		const bool FullDuplex() const;

		// Optional, Boolean that indicates that the port is operating in full duplex mode.
		void FullDuplex(const bool value); 

		// Is true if the field FullDuplex exists in the current object, otherwise is false.
		bool FullDuplexExists() const;

		// Remove FullDuplex field.
		void RemoveFullDuplex(); 

		// Optional, A Boolean that indicates whether the NetworkPort is capable of automatically determining the speed or other communications characteristics of the attached network media.
		const bool AutoSense() const;

		// Optional, A Boolean that indicates whether the NetworkPort is capable of automatically determining the speed or other communications characteristics of the attached network media.
		void AutoSense(const bool value); 

		// Is true if the field AutoSense exists in the current object, otherwise is false.
		bool AutoSenseExists() const;

		// Remove AutoSense field.
		void RemoveAutoSense(); 

		// Optional, The maximum transmission unit (MTU) that can be supported.
		const Uint64 SupportedMaximumTransmissionUnit() const;

		// Optional, The maximum transmission unit (MTU) that can be supported.
		void SupportedMaximumTransmissionUnit(const Uint64 value); 

		// Is true if the field SupportedMaximumTransmissionUnit exists in the current object, otherwise is false.
		bool SupportedMaximumTransmissionUnitExists() const;

		// Remove SupportedMaximumTransmissionUnit field.
		void RemoveSupportedMaximumTransmissionUnit(); 

		// Optional, The active or negotiated maximum transmission unit (MTU) that can be supported.
		const Uint64 ActiveMaximumTransmissionUnit() const;

		// Optional, The active or negotiated maximum transmission unit (MTU) that can be supported.
		void ActiveMaximumTransmissionUnit(const Uint64 value); 

		// Is true if the field ActiveMaximumTransmissionUnit exists in the current object, otherwise is false.
		bool ActiveMaximumTransmissionUnitExists() const;

		// Remove ActiveMaximumTransmissionUnit field.
		void RemoveActiveMaximumTransmissionUnit(); 

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

		static vector<shared_ptr<CIM_NetworkPort> > Enumerate(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		// Overloaded delete which supplies the internal resourceURI
		static void Delete(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		using CimBase::Delete;

	protected:
		 // Protected constructor to be used by derived classes
		CIM_NetworkPort(ICimWsmanClient *client, const string &class_name,
			const string &class_ns, const string &prefix, const string &uri): CIM_LogicalPort(client, class_name, class_ns, prefix, uri)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_LogicalPort::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 11);
			}
		}
		 // Protected constructor which receives CimObject
		CIM_NetworkPort(const CimObject &object)
			: CIM_LogicalPort(object)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_LogicalPort::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 11);
			}
		}
		// Called by derived classes
		void SetMetaData(vector<CimFieldAttribute>& childMetaData)
		{
			CIM_LogicalPort::SetMetaData(childMetaData);
			CimBase::SetMetaData(childMetaData, _metadata, 11);
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
#endif // CIM_NETWORKPORT_H
