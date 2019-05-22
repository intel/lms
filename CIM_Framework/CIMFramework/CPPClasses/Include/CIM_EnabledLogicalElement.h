//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_EnabledLogicalElement.h
//
//  Contents:   This class extends LogicalElement to abstract the concept of an element that is enabled and disabled, such as a LogicalDevice or a ServiceAccessPoint.
//
//              This file was automatically generated from CIM_EnabledLogicalElement.mof,  version: 2.22.0
//
//----------------------------------------------------------------------------
#ifndef CIM_ENABLEDLOGICALELEMENT_H
#define CIM_ENABLEDLOGICALELEMENT_H 1
#include "CIM_LogicalElement.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	// This class extends LogicalElement to abstract the concept of an element that is enabled and disabled, such as a LogicalDevice or a ServiceAccessPoint.
	class CIMFRAMEWORK_API CIM_EnabledLogicalElement  : public CIM_LogicalElement
	{
	public:

		//Default constructor
		CIM_EnabledLogicalElement()
			: CIM_LogicalElement(NULL, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_LogicalElement::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 7);
			}
		}

		//constructor which receives WSMan client
		CIM_EnabledLogicalElement(ICimWsmanClient *client)
			: CIM_LogicalElement(client, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_LogicalElement::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 7);
			}
		}

		//Destructor
		virtual ~CIM_EnabledLogicalElement(){}

		// The "type" information for the object. Gettors only.
		virtual const string& ResourceURI() const { return CLASS_URI; }
		static const string& ClassResourceURI() { return CLASS_URI; }
		virtual const string& XmlNamespace() const { return CLASS_NS; }
		virtual const string& XmlPrefix() const { return CLASS_NS_PREFIX; }
		virtual const string& ObjectType() const { return CLASS_NAME; }
		static const string& ClassObjectType() { return CLASS_NAME; }

		// Class representing CIM_EnabledLogicalElement keys
		class CimKeys : public CIM_LogicalElement::CimKeys
		{
		public:
		};

		// class fields declarations

		// Optional, EnabledState is an integer enumeration that indicates the enabled and disabled states of an element. It can also indicate the transitions between these requested states. For example, shutting down (value=4) and starting (value=10) are transient states between enabled and disabled. The following text briefly summarizes the various enabled and disabled states: 
		// Enabled (2) indicates that the element is or could be executing commands, will process any queued commands, and queues new requests. 
		// Disabled (3) indicates that the element will not execute commands and will drop any new requests. 
		// Shutting Down (4) indicates that the element is in the process of going to a Disabled state. 
		// Not Applicable (5) indicates the element does not support being enabled or disabled. 
		// Enabled but Offline (6) indicates that the element might be completing commands, and will drop any new requests. 
		// Test (7) indicates that the element is in a test state. 
		// Deferred (8) indicates that the element might be completing commands, but will queue any new requests. 
		// Quiesce (9) indicates that the element is enabled but in a restricted mode.
		// Starting (10) indicates that the element is in the process of going to an Enabled state. New requests are queued.
		const unsigned short EnabledState() const;

		// Optional, EnabledState is an integer enumeration that indicates the enabled and disabled states of an element. It can also indicate the transitions between these requested states. For example, shutting down (value=4) and starting (value=10) are transient states between enabled and disabled. The following text briefly summarizes the various enabled and disabled states: 
		// Enabled (2) indicates that the element is or could be executing commands, will process any queued commands, and queues new requests. 
		// Disabled (3) indicates that the element will not execute commands and will drop any new requests. 
		// Shutting Down (4) indicates that the element is in the process of going to a Disabled state. 
		// Not Applicable (5) indicates the element does not support being enabled or disabled. 
		// Enabled but Offline (6) indicates that the element might be completing commands, and will drop any new requests. 
		// Test (7) indicates that the element is in a test state. 
		// Deferred (8) indicates that the element might be completing commands, but will queue any new requests. 
		// Quiesce (9) indicates that the element is enabled but in a restricted mode.
		// Starting (10) indicates that the element is in the process of going to an Enabled state. New requests are queued.
		void EnabledState(const unsigned short value); 

		// Is true if the field EnabledState exists in the current object, otherwise is false.
		bool EnabledStateExists() const;

		// Remove EnabledState field.
		void RemoveEnabledState(); 

		// Optional, A string that describes the enabled or disabled state of the element when the EnabledState property is set to 1 ("Other"). This property must be set to null when EnabledState is any value other than 1.
		const string OtherEnabledState() const;

		// Optional, A string that describes the enabled or disabled state of the element when the EnabledState property is set to 1 ("Other"). This property must be set to null when EnabledState is any value other than 1.
		void OtherEnabledState(const string &value); 

		// Is true if the field OtherEnabledState exists in the current object, otherwise is false.
		bool OtherEnabledStateExists() const;

		// Remove OtherEnabledState field.
		void RemoveOtherEnabledState(); 

		// Optional, RequestedState is an integer enumeration that indicates the last requested or desired state for the element, irrespective of the mechanism through which it was requested. The actual state of the element is represented by EnabledState. This property is provided to compare the last requested and current enabled or disabled states. Note that when EnabledState is set to 5 ("Not Applicable"), then this property has no meaning. Refer to the EnabledState property description for explanations of the values in the RequestedState enumeration. 
		// "Unknown" (0) indicates the last requested state for the element is unknown.
		// Note that the value "No Change" (5) has been deprecated in lieu of indicating the last requested state is "Unknown" (0). If the last requested or desired state is unknown, RequestedState should have the value "Unknown" (0), but may have the value "No Change" (5).Offline (6) indicates that the element has been requested to transition to the Enabled but Offline EnabledState. 
		// It should be noted that there are two new values in RequestedState that build on the statuses of EnabledState. These are "Reboot" (10) and "Reset" (11). Reboot refers to doing a "Shut Down" and then moving to an "Enabled" state. Reset indicates that the element is first "Disabled" and then "Enabled". The distinction between requesting "Shut Down" and "Disabled" should also be noted. Shut Down requests an orderly transition to the Disabled state, and might involve removing power, to completely erase any existing state. The Disabled state requests an immediate disabling of the element, such that it will not execute or accept any commands or processing requests. 
		// 
		// This property is set as the result of a method invocation (such as Start or StopService on CIM_Service), or can be overridden and defined as WRITEable in a subclass. The method approach is considered superior to a WRITEable property, because it allows an explicit invocation of the operation and the return of a result code. 
		// 
		// If knowledge of the last RequestedState is not supported for the EnabledLogicalElement, the property shall be NULL or have the value 12 "Not Applicable".
		const unsigned short RequestedState() const;

		// Optional, RequestedState is an integer enumeration that indicates the last requested or desired state for the element, irrespective of the mechanism through which it was requested. The actual state of the element is represented by EnabledState. This property is provided to compare the last requested and current enabled or disabled states. Note that when EnabledState is set to 5 ("Not Applicable"), then this property has no meaning. Refer to the EnabledState property description for explanations of the values in the RequestedState enumeration. 
		// "Unknown" (0) indicates the last requested state for the element is unknown.
		// Note that the value "No Change" (5) has been deprecated in lieu of indicating the last requested state is "Unknown" (0). If the last requested or desired state is unknown, RequestedState should have the value "Unknown" (0), but may have the value "No Change" (5).Offline (6) indicates that the element has been requested to transition to the Enabled but Offline EnabledState. 
		// It should be noted that there are two new values in RequestedState that build on the statuses of EnabledState. These are "Reboot" (10) and "Reset" (11). Reboot refers to doing a "Shut Down" and then moving to an "Enabled" state. Reset indicates that the element is first "Disabled" and then "Enabled". The distinction between requesting "Shut Down" and "Disabled" should also be noted. Shut Down requests an orderly transition to the Disabled state, and might involve removing power, to completely erase any existing state. The Disabled state requests an immediate disabling of the element, such that it will not execute or accept any commands or processing requests. 
		// 
		// This property is set as the result of a method invocation (such as Start or StopService on CIM_Service), or can be overridden and defined as WRITEable in a subclass. The method approach is considered superior to a WRITEable property, because it allows an explicit invocation of the operation and the return of a result code. 
		// 
		// If knowledge of the last RequestedState is not supported for the EnabledLogicalElement, the property shall be NULL or have the value 12 "Not Applicable".
		void RequestedState(const unsigned short value); 

		// Is true if the field RequestedState exists in the current object, otherwise is false.
		bool RequestedStateExists() const;

		// Remove RequestedState field.
		void RemoveRequestedState(); 

		// Optional, An enumerated value indicating an administrator's default or startup configuration for the Enabled State of an element. By default, the element is "Enabled" (value=2).
		const unsigned short EnabledDefault() const;

		// Optional, An enumerated value indicating an administrator's default or startup configuration for the Enabled State of an element. By default, the element is "Enabled" (value=2).
		void EnabledDefault(const unsigned short value); 

		// Is true if the field EnabledDefault exists in the current object, otherwise is false.
		bool EnabledDefaultExists() const;

		// Remove EnabledDefault field.
		void RemoveEnabledDefault(); 

		// Optional, The date or time when the EnabledState of the element last changed. If the state of the element has not changed and this property is populated, then it must be set to a 0 interval value. If a state change was requested, but rejected or not yet processed, the property must not be updated.
		const CimDateTime TimeOfLastStateChange() const;

		// Optional, The date or time when the EnabledState of the element last changed. If the state of the element has not changed and this property is populated, then it must be set to a 0 interval value. If a state change was requested, but rejected or not yet processed, the property must not be updated.
		void TimeOfLastStateChange(const CimDateTime &value); 

		// Is true if the field TimeOfLastStateChange exists in the current object, otherwise is false.
		bool TimeOfLastStateChangeExists() const;

		// Remove TimeOfLastStateChange field.
		void RemoveTimeOfLastStateChange(); 

		// Optional, AvailableRequestedStates indicates the possible values for the RequestedState parameter of the method RequestStateChange, used to initiate a state change. The values listed shall be a subset of the values contained in the RequestedStatesSupported property of the associated instance of CIM_EnabledLogicalElementCapabilities where the values selected are a function of the current state of the CIM_EnabledLogicalElement. This property may be non-null if an implementation is able to advertise the set of possible values as a function of the current state. This property shall be null if an implementation is unable to determine the set of possible values as a function of the current state.
		const vector<unsigned short> AvailableRequestedStates() const;

		// Optional, AvailableRequestedStates indicates the possible values for the RequestedState parameter of the method RequestStateChange, used to initiate a state change. The values listed shall be a subset of the values contained in the RequestedStatesSupported property of the associated instance of CIM_EnabledLogicalElementCapabilities where the values selected are a function of the current state of the CIM_EnabledLogicalElement. This property may be non-null if an implementation is able to advertise the set of possible values as a function of the current state. This property shall be null if an implementation is unable to determine the set of possible values as a function of the current state.
		void AvailableRequestedStates(const vector<unsigned short> &value); 

		// Is true if the field AvailableRequestedStates exists in the current object, otherwise is false.
		bool AvailableRequestedStatesExists() const;

		// Remove AvailableRequestedStates field.
		void RemoveAvailableRequestedStates(); 

		// Optional, TransitioningToState indicates the target state to which the instance is transitioning. 
		// A value of 5 "No Change" shall indicate that no transition is in progress.A value of 12 "Not Applicable" shall indicate the implementation does not support representing ongoing transitions. 
		// A value other than 5 or 12 shall identify the state to which the element is in the process of transitioning.
		const unsigned short TransitioningToState() const;

		// Optional, TransitioningToState indicates the target state to which the instance is transitioning. 
		// A value of 5 "No Change" shall indicate that no transition is in progress.A value of 12 "Not Applicable" shall indicate the implementation does not support representing ongoing transitions. 
		// A value other than 5 or 12 shall identify the state to which the element is in the process of transitioning.
		void TransitioningToState(const unsigned short value); 

		// Is true if the field TransitioningToState exists in the current object, otherwise is false.
		bool TransitioningToStateExists() const;

		// Remove TransitioningToState field.
		void RemoveTransitioningToState(); 

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

		static vector<shared_ptr<CIM_EnabledLogicalElement> > Enumerate(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		// Overloaded delete which supplies the internal resourceURI
		static void Delete(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		using CimBase::Delete;

	protected:
		 // Protected constructor to be used by derived classes
		CIM_EnabledLogicalElement(ICimWsmanClient *client, const string &class_name,
			const string &class_ns, const string &prefix, const string &uri): CIM_LogicalElement(client, class_name, class_ns, prefix, uri)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_LogicalElement::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 7);
			}
		}
		 // Protected constructor which receives CimObject
		CIM_EnabledLogicalElement(const CimObject &object)
			: CIM_LogicalElement(object)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_LogicalElement::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 7);
			}
		}
		// Called by derived classes
		void SetMetaData(vector<CimFieldAttribute>& childMetaData)
		{
			CIM_LogicalElement::SetMetaData(childMetaData);
			CimBase::SetMetaData(childMetaData, _metadata, 7);
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
#endif // CIM_ENABLEDLOGICALELEMENT_H
