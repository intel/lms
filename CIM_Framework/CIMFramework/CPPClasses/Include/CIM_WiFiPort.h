//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_WiFiPort.h
//
//  Contents:   WiFiPort is the logical representation of wireless local area network communications hardware that conforms to the IEEE 802.11 series of specifications. It embodies properties at the lowest layers of a network stack, such as the antennas used for transmission and reception, the address permanently embedded into the hardware, and the operational bandwidth of the device.
//
//              This file was automatically generated from CIM_WiFiPort.mof,  version: 2.22.0
//
//----------------------------------------------------------------------------
#ifndef CIM_WIFIPORT_H
#define CIM_WIFIPORT_H 1
#include "CIM_NetworkPort.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	// WiFiPort is the logical representation of wireless local area network communications hardware that conforms to the IEEE 802.11 series of specifications. It embodies properties at the lowest layers of a network stack, such as the antennas used for transmission and reception, the address permanently embedded into the hardware, and the operational bandwidth of the device.
	class CIMFRAMEWORK_API CIM_WiFiPort  : public CIM_NetworkPort
	{
	public:

		//Default constructor
		CIM_WiFiPort()
			: CIM_NetworkPort(NULL, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_NetworkPort::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 5);
			}
		}

		//constructor which receives WSMan client
		CIM_WiFiPort(ICimWsmanClient *client)
			: CIM_NetworkPort(client, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_NetworkPort::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 5);
			}
		}

		//Destructor
		virtual ~CIM_WiFiPort(){}

		// The "type" information for the object. Gettors only.
		virtual const string& ResourceURI() const { return CLASS_URI; }
		static const string& ClassResourceURI() { return CLASS_URI; }
		virtual const string& XmlNamespace() const { return CLASS_NS; }
		virtual const string& XmlPrefix() const { return CLASS_NS_PREFIX; }
		virtual const string& ObjectType() const { return CLASS_NAME; }
		static const string& ClassObjectType() { return CLASS_NAME; }

		// Class representing CIM_WiFiPort keys
		class CimKeys : public CIM_NetworkPort::CimKeys
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

		static vector<shared_ptr<CIM_WiFiPort> > Enumerate(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		// Overloaded delete which supplies the internal resourceURI
		static void Delete(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		using CimBase::Delete;

	protected:
		 // Protected constructor to be used by derived classes
		CIM_WiFiPort(ICimWsmanClient *client, const string &class_name,
			const string &class_ns, const string &prefix, const string &uri): CIM_NetworkPort(client, class_name, class_ns, prefix, uri)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_NetworkPort::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 5);
			}
		}
		 // Protected constructor which receives CimObject
		CIM_WiFiPort(const CimObject &object)
			: CIM_NetworkPort(object)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_NetworkPort::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 5);
			}
		}
		// Called by derived classes
		void SetMetaData(vector<CimFieldAttribute>& childMetaData)
		{
			CIM_NetworkPort::SetMetaData(childMetaData);
			CimBase::SetMetaData(childMetaData, _metadata, 5);
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
#endif // CIM_WIFIPORT_H
