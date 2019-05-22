//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_RedirectionService.h
//
//  Contents:   RedirectionService provides the capability to manage redirection services. Examples of this include any video stream directed to a Network Port (by the operating system) on a Computer System redirected out to a remote administrator's console. Similarly this can include input redirected into the same Network Port. Other examples include the redirection of IO from a logical element to a remote or local destination. Each redirection stream is accessible via a SAP. This service can support multiple redirection types via multiple associated SAPs.
//
//              This file was automatically generated from CIM_RedirectionService.mof,  version: 2.17.0
//
//----------------------------------------------------------------------------
#ifndef CIM_REDIRECTIONSERVICE_H
#define CIM_REDIRECTIONSERVICE_H 1
#include "CIM_Service.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	// RedirectionService provides the capability to manage redirection services. Examples of this include any video stream directed to a Network Port (by the operating system) on a Computer System redirected out to a remote administrator's console. Similarly this can include input redirected into the same Network Port. Other examples include the redirection of IO from a logical element to a remote or local destination. Each redirection stream is accessible via a SAP. This service can support multiple redirection types via multiple associated SAPs.
	class CIMFRAMEWORK_API CIM_RedirectionService  : public CIM_Service
	{
	public:

		//Default constructor
		CIM_RedirectionService()
			: CIM_Service(NULL, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_Service::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 4);
			}
		}

		//constructor which receives WSMan client
		CIM_RedirectionService(ICimWsmanClient *client)
			: CIM_Service(client, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_Service::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 4);
			}
		}

		//Destructor
		virtual ~CIM_RedirectionService(){}

		// The "type" information for the object. Gettors only.
		virtual const string& ResourceURI() const { return CLASS_URI; }
		static const string& ClassResourceURI() { return CLASS_URI; }
		virtual const string& XmlNamespace() const { return CLASS_NS; }
		virtual const string& XmlPrefix() const { return CLASS_NS_PREFIX; }
		virtual const string& ObjectType() const { return CLASS_NAME; }
		static const string& ClassObjectType() { return CLASS_NAME; }

		// Class representing CIM_RedirectionService keys
		class CimKeys : public CIM_Service::CimKeys
		{
		public:
		};

		// class fields declarations

		// Optional, An enumerated array indicating the type(s) of Redirection supported by this Service. This value is set to the type of redirection service that this service represents. A value set to 2 = "Text" shall indicate a Text Console Redirection service. A value set to 3 = "KVM" shall indicate a Keyboard, Mouse and Video Console Redirection service. A value set to 4 = "USB" shall indicate a USB Redirection service. A value set to 5 = "media" shall indicate a traditional Media Redirection service.
		const vector<unsigned short> RedirectionServiceType() const;

		// Optional, An enumerated array indicating the type(s) of Redirection supported by this Service. This value is set to the type of redirection service that this service represents. A value set to 2 = "Text" shall indicate a Text Console Redirection service. A value set to 3 = "KVM" shall indicate a Keyboard, Mouse and Video Console Redirection service. A value set to 4 = "USB" shall indicate a USB Redirection service. A value set to 5 = "media" shall indicate a traditional Media Redirection service.
		void RedirectionServiceType(const vector<unsigned short> &value); 

		// Is true if the field RedirectionServiceType exists in the current object, otherwise is false.
		bool RedirectionServiceTypeExists() const;

		// Remove RedirectionServiceType field.
		void RemoveRedirectionServiceType(); 

		// Optional, A string describing the Redirection Service when the value of the RedirectionServiceType property is set to 1 = "Other".
		const string OtherRedirectionServiceType() const;

		// Optional, A string describing the Redirection Service when the value of the RedirectionServiceType property is set to 1 = "Other".
		void OtherRedirectionServiceType(const string &value); 

		// Is true if the field OtherRedirectionServiceType exists in the current object, otherwise is false.
		bool OtherRedirectionServiceTypeExists() const;

		// Remove OtherRedirectionServiceType field.
		void RemoveOtherRedirectionServiceType(); 

		// Optional, Maximum number of concurrently enabled redirection SAPs. The Service may have multiple (more than this number) SAPs associated with it. However, the number of Active SAPs (EnabledState=Enabled) associated with this Service instance cannot exceed this number. This limitation could come from hardware limitations (e.g. one COM port can only redirect the text to one console), or from any other software resource limitations.
		const unsigned short MaxCurrentEnabledSAPs() const;

		// Optional, Maximum number of concurrently enabled redirection SAPs. The Service may have multiple (more than this number) SAPs associated with it. However, the number of Active SAPs (EnabledState=Enabled) associated with this Service instance cannot exceed this number. This limitation could come from hardware limitations (e.g. one COM port can only redirect the text to one console), or from any other software resource limitations.
		void MaxCurrentEnabledSAPs(const unsigned short value); 

		// Is true if the field MaxCurrentEnabledSAPs exists in the current object, otherwise is false.
		bool MaxCurrentEnabledSAPsExists() const;

		// Remove MaxCurrentEnabledSAPs field.
		void RemoveMaxCurrentEnabledSAPs(); 

		// Optional, An enumeration specifying the impact of enabling the redirection of the text console flow on the original destination of the flow. The original destination is modeled as a concrete subclass of LogicalDevice and associated to this service using a ServiceAffectsElement association). If this value is Exclusive, it shall mean that when the element flow is actively being redirected, then the element being redirected cannot be accessed at the original destination. If this value is Shared, it shall mean that when the element flow is actively being redirected, then the element being redirected can still be accessed at the original destination.
		const unsigned short SharingMode() const;

		// Optional, An enumeration specifying the impact of enabling the redirection of the text console flow on the original destination of the flow. The original destination is modeled as a concrete subclass of LogicalDevice and associated to this service using a ServiceAffectsElement association). If this value is Exclusive, it shall mean that when the element flow is actively being redirected, then the element being redirected cannot be accessed at the original destination. If this value is Shared, it shall mean that when the element flow is actively being redirected, then the element being redirected can still be accessed at the original destination.
		void SharingMode(const unsigned short value); 

		// Is true if the field SharingMode exists in the current object, otherwise is false.
		bool SharingModeExists() const;

		// Remove SharingMode field.
		void RemoveSharingMode(); 

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

		static vector<shared_ptr<CIM_RedirectionService> > Enumerate(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		// Overloaded delete which supplies the internal resourceURI
		static void Delete(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		using CimBase::Delete;

	protected:
		 // Protected constructor to be used by derived classes
		CIM_RedirectionService(ICimWsmanClient *client, const string &class_name,
			const string &class_ns, const string &prefix, const string &uri): CIM_Service(client, class_name, class_ns, prefix, uri)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_Service::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 4);
			}
		}
		 // Protected constructor which receives CimObject
		CIM_RedirectionService(const CimObject &object)
			: CIM_Service(object)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_Service::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 4);
			}
		}
		// Called by derived classes
		void SetMetaData(vector<CimFieldAttribute>& childMetaData)
		{
			CIM_Service::SetMetaData(childMetaData);
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
#endif // CIM_REDIRECTIONSERVICE_H
