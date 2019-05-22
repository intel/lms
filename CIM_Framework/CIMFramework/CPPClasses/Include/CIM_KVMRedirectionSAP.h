//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_KVMRedirectionSAP.h
//
//  Contents:   A class derived from Service Access Point, that describes an access point to start the KVM redirection. One access point represents access to a single KVM redirection stream.
//
//              This file was automatically generated from CIM_KVMRedirectionSAP.mof,  version: 2.22.0
//
//----------------------------------------------------------------------------
#ifndef CIM_KVMREDIRECTIONSAP_H
#define CIM_KVMREDIRECTIONSAP_H 1
#include "CIM_ServiceAccessPoint.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	// A class derived from Service Access Point, that describes an access point to start the KVM redirection. One access point represents access to a single KVM redirection stream.
	class CIMFRAMEWORK_API CIM_KVMRedirectionSAP  : public CIM_ServiceAccessPoint
	{
	public:

		//Default constructor
		CIM_KVMRedirectionSAP()
			: CIM_ServiceAccessPoint(NULL, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_ServiceAccessPoint::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 2);
			}
		}

		//constructor which receives WSMan client
		CIM_KVMRedirectionSAP(ICimWsmanClient *client)
			: CIM_ServiceAccessPoint(client, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_ServiceAccessPoint::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 2);
			}
		}

		//Destructor
		virtual ~CIM_KVMRedirectionSAP(){}

		// The "type" information for the object. Gettors only.
		virtual const string& ResourceURI() const { return CLASS_URI; }
		static const string& ClassResourceURI() { return CLASS_URI; }
		virtual const string& XmlNamespace() const { return CLASS_NS; }
		virtual const string& XmlPrefix() const { return CLASS_NS_PREFIX; }
		virtual const string& ObjectType() const { return CLASS_NAME; }
		static const string& ClassObjectType() { return CLASS_NAME; }

		// Class representing CIM_KVMRedirectionSAP keys
		class CimKeys : public CIM_ServiceAccessPoint::CimKeys
		{
		public:
		};

		// class fields declarations

		// Optional, An enumeration specifying the type of the KVM stream supported on this SAP. In some cases this may be a raw video steam, with the characters having no special meaning. However, in other cases it may support a protocol where some messages have a predefined structure. 
		// 0 "Unknown" shall indicate the protocol is unknown. 
		// 1 "Other" shall indicate the protocol is specified in OtherKVMProtocol. 
		// 2 "Raw" shall indicate the protocol is a raw and uncompressed data stream. 3 "RDP" shall indicate the protocol is the Remote Desktop Protocol. 
		// 4 "VNC" shall indicate the protocol is the VNC Protocol.
		const unsigned short KVMProtocol() const;

		// Optional, An enumeration specifying the type of the KVM stream supported on this SAP. In some cases this may be a raw video steam, with the characters having no special meaning. However, in other cases it may support a protocol where some messages have a predefined structure. 
		// 0 "Unknown" shall indicate the protocol is unknown. 
		// 1 "Other" shall indicate the protocol is specified in OtherKVMProtocol. 
		// 2 "Raw" shall indicate the protocol is a raw and uncompressed data stream. 3 "RDP" shall indicate the protocol is the Remote Desktop Protocol. 
		// 4 "VNC" shall indicate the protocol is the VNC Protocol.
		void KVMProtocol(const unsigned short value); 

		// Is true if the field KVMProtocol exists in the current object, otherwise is false.
		bool KVMProtocolExists() const;

		// Remove KVMProtocol field.
		void RemoveKVMProtocol(); 

		// Optional, A string describing the KVMProtocol when the value of the KVMProtocol property is set to 1 = "Other".
		const string OtherKVMProtocol() const;

		// Optional, A string describing the KVMProtocol when the value of the KVMProtocol property is set to 1 = "Other".
		void OtherKVMProtocol(const string &value); 

		// Is true if the field OtherKVMProtocol exists in the current object, otherwise is false.
		bool OtherKVMProtocolExists() const;

		// Remove OtherKVMProtocol field.
		void RemoveOtherKVMProtocol(); 

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

		static vector<shared_ptr<CIM_KVMRedirectionSAP> > Enumerate(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		// Overloaded delete which supplies the internal resourceURI
		static void Delete(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		using CimBase::Delete;

	protected:
		 // Protected constructor to be used by derived classes
		CIM_KVMRedirectionSAP(ICimWsmanClient *client, const string &class_name,
			const string &class_ns, const string &prefix, const string &uri): CIM_ServiceAccessPoint(client, class_name, class_ns, prefix, uri)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_ServiceAccessPoint::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 2);
			}
		}
		 // Protected constructor which receives CimObject
		CIM_KVMRedirectionSAP(const CimObject &object)
			: CIM_ServiceAccessPoint(object)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_ServiceAccessPoint::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 2);
			}
		}
		// Called by derived classes
		void SetMetaData(vector<CimFieldAttribute>& childMetaData)
		{
			CIM_ServiceAccessPoint::SetMetaData(childMetaData);
			CimBase::SetMetaData(childMetaData, _metadata, 2);
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
#endif // CIM_KVMREDIRECTIONSAP_H
