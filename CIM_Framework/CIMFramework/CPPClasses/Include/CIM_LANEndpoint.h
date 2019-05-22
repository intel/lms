//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_LANEndpoint.h
//
//  Contents:   A communication endpoint which, when its associated interface device is connected to a LAN, may send and receive data frames. LANEndpoints include Ethernet, Token Ring and FDDI interfaces.
//
//              This file was automatically generated from CIM_LANEndpoint.mof,  version: 2.7.0
//
//----------------------------------------------------------------------------
#ifndef CIM_LANENDPOINT_H
#define CIM_LANENDPOINT_H 1
#include "CIM_ProtocolEndpoint.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	// A communication endpoint which, when its associated interface device is connected to a LAN, may send and receive data frames. LANEndpoints include Ethernet, Token Ring and FDDI interfaces.
	class CIMFRAMEWORK_API CIM_LANEndpoint  : public CIM_ProtocolEndpoint
	{
	public:

		//Default constructor
		CIM_LANEndpoint()
			: CIM_ProtocolEndpoint(NULL, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_ProtocolEndpoint::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 7);
			}
		}

		//constructor which receives WSMan client
		CIM_LANEndpoint(ICimWsmanClient *client)
			: CIM_ProtocolEndpoint(client, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_ProtocolEndpoint::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 7);
			}
		}

		//Destructor
		virtual ~CIM_LANEndpoint(){}

		// The "type" information for the object. Gettors only.
		virtual const string& ResourceURI() const { return CLASS_URI; }
		static const string& ClassResourceURI() { return CLASS_URI; }
		virtual const string& XmlNamespace() const { return CLASS_NS; }
		virtual const string& XmlPrefix() const { return CLASS_NS_PREFIX; }
		virtual const string& ObjectType() const { return CLASS_NAME; }
		static const string& ClassObjectType() { return CLASS_NAME; }

		// Class representing CIM_LANEndpoint keys
		class CimKeys : public CIM_ProtocolEndpoint::CimKeys
		{
		public:
		};

		// class fields declarations

		// Optional, A label or identifier for the LAN Segment to which the Endpoint is connected. If the Endpoint is not currently active/connected or this information is not known, then LANID is NULL.
		const string LANID() const;

		// Optional, A label or identifier for the LAN Segment to which the Endpoint is connected. If the Endpoint is not currently active/connected or this information is not known, then LANID is NULL.
		void LANID(const string &value); 

		// Is true if the field LANID exists in the current object, otherwise is false.
		bool LANIDExists() const;

		// Remove LANID field.
		void RemoveLANID(); 

		// Optional, An indication of the kind of technology used on the LAN. This property is deprecated in lieu of ProtocolType, which is an enumeration inherited from ProtocolEndpoint and which includes the Values specified here.
		const unsigned short LANType() const;

		// Optional, An indication of the kind of technology used on the LAN. This property is deprecated in lieu of ProtocolType, which is an enumeration inherited from ProtocolEndpoint and which includes the Values specified here.
		void LANType(const unsigned short value); 

		// Is true if the field LANType exists in the current object, otherwise is false.
		bool LANTypeExists() const;

		// Remove LANType field.
		void RemoveLANType(); 

		// Optional, A free-form string that describes the type of technology used on the LAN when the value of the LANType property is equal to 1 (i.e., "Other"). This property is deprecated since its purpose overlaps with OtherTypeDescription, which which is inherited from ProtocolEndpoint.
		const string OtherLANType() const;

		// Optional, A free-form string that describes the type of technology used on the LAN when the value of the LANType property is equal to 1 (i.e., "Other"). This property is deprecated since its purpose overlaps with OtherTypeDescription, which which is inherited from ProtocolEndpoint.
		void OtherLANType(const string &value); 

		// Is true if the field OtherLANType exists in the current object, otherwise is false.
		bool OtherLANTypeExists() const;

		// Remove OtherLANType field.
		void RemoveOtherLANType(); 

		// Optional, The principal unicast address used in communication with the LANEndpoint. The MAC address is formatted as twelve hexadecimal digits (e.g., "010203040506"), with each pair representing one of the six octets of the MAC address in "canonical" bit order according to RFC 2469.
		const string MACAddress() const;

		// Optional, The principal unicast address used in communication with the LANEndpoint. The MAC address is formatted as twelve hexadecimal digits (e.g., "010203040506"), with each pair representing one of the six octets of the MAC address in "canonical" bit order according to RFC 2469.
		void MACAddress(const string &value); 

		// Is true if the field MACAddress exists in the current object, otherwise is false.
		bool MACAddressExists() const;

		// Remove MACAddress field.
		void RemoveMACAddress(); 

		// Optional, Other unicast addresses that may be used to communicate with the LANEndpoint.
		const vector<string> AliasAddresses() const;

		// Optional, Other unicast addresses that may be used to communicate with the LANEndpoint.
		void AliasAddresses(const vector<string> &value); 

		// Is true if the field AliasAddresses exists in the current object, otherwise is false.
		bool AliasAddressesExists() const;

		// Remove AliasAddresses field.
		void RemoveAliasAddresses(); 

		// Optional, Multicast addresses to which the LANEndpoint listens.
		const vector<string> GroupAddresses() const;

		// Optional, Multicast addresses to which the LANEndpoint listens.
		void GroupAddresses(const vector<string> &value); 

		// Is true if the field GroupAddresses exists in the current object, otherwise is false.
		bool GroupAddressesExists() const;

		// Remove GroupAddresses field.
		void RemoveGroupAddresses(); 

		// Optional, The largest information field that may be sent or received by the LANEndpoint.
		const unsigned int MaxDataSize() const;

		// Optional, The largest information field that may be sent or received by the LANEndpoint.
		void MaxDataSize(const unsigned int value); 

		// Is true if the field MaxDataSize exists in the current object, otherwise is false.
		bool MaxDataSizeExists() const;

		// Remove MaxDataSize field.
		void RemoveMaxDataSize(); 

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

		static vector<shared_ptr<CIM_LANEndpoint> > Enumerate(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		// Overloaded delete which supplies the internal resourceURI
		static void Delete(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		using CimBase::Delete;

	protected:
		 // Protected constructor to be used by derived classes
		CIM_LANEndpoint(ICimWsmanClient *client, const string &class_name,
			const string &class_ns, const string &prefix, const string &uri): CIM_ProtocolEndpoint(client, class_name, class_ns, prefix, uri)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_ProtocolEndpoint::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 7);
			}
		}
		 // Protected constructor which receives CimObject
		CIM_LANEndpoint(const CimObject &object)
			: CIM_ProtocolEndpoint(object)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_ProtocolEndpoint::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 7);
			}
		}
		// Called by derived classes
		void SetMetaData(vector<CimFieldAttribute>& childMetaData)
		{
			CIM_ProtocolEndpoint::SetMetaData(childMetaData);
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
#endif // CIM_LANENDPOINT_H
