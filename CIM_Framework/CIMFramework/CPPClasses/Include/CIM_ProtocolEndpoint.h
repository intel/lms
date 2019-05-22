//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_ProtocolEndpoint.h
//
//  Contents:   A communication point from which data can be sent or received. ProtocolEndpoints link system or computer interfaces to LogicalNetworks.
//
//              This file was automatically generated from CIM_ProtocolEndpoint.mof,  version: 2.15.0
//
//----------------------------------------------------------------------------
#ifndef CIM_PROTOCOLENDPOINT_H
#define CIM_PROTOCOLENDPOINT_H 1
#include "CIM_ServiceAccessPoint.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	// A communication point from which data can be sent or received. ProtocolEndpoints link system or computer interfaces to LogicalNetworks.
	class CIMFRAMEWORK_API CIM_ProtocolEndpoint  : public CIM_ServiceAccessPoint
	{
	public:

		//Default constructor
		CIM_ProtocolEndpoint()
			: CIM_ServiceAccessPoint(NULL, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_ServiceAccessPoint::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 9);
			}
		}

		//constructor which receives WSMan client
		CIM_ProtocolEndpoint(ICimWsmanClient *client)
			: CIM_ServiceAccessPoint(client, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_ServiceAccessPoint::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 9);
			}
		}

		//Destructor
		virtual ~CIM_ProtocolEndpoint(){}

		// The "type" information for the object. Gettors only.
		virtual const string& ResourceURI() const { return CLASS_URI; }
		static const string& ClassResourceURI() { return CLASS_URI; }
		virtual const string& XmlNamespace() const { return CLASS_NS; }
		virtual const string& XmlPrefix() const { return CLASS_NS_PREFIX; }
		virtual const string& ObjectType() const { return CLASS_NAME; }
		static const string& ClassObjectType() { return CLASS_NAME; }

		// Class representing CIM_ProtocolEndpoint keys
		class CimKeys : public CIM_ServiceAccessPoint::CimKeys
		{
		public:
			// Required, A string that identifies this ProtocolEndpoint with either a port or an interface on a device. To ensure uniqueness, the Name property should be prepended or appended with information from the Type or OtherTypeDescription properties. The method selected is described in the NameFormat property of this class.
			const string Name() const
			{
				return GetKey("Name");
			}

			// Required, A string that identifies this ProtocolEndpoint with either a port or an interface on a device. To ensure uniqueness, the Name property should be prepended or appended with information from the Type or OtherTypeDescription properties. The method selected is described in the NameFormat property of this class.
			void Name(const string &value)
			{
				SetOrAddKey("Name", value);
			}

		};

		// class fields declarations

		// Optional, NameFormat contains the naming heuristic that is selected to ensure that the value of the Name property is unique. For example, you might choose to prepend the name of the port or interface with the Type of ProtocolEndpoint (for example, IPv4) of this instance followed by an underscore.
		const string NameFormat() const;

		// Optional, NameFormat contains the naming heuristic that is selected to ensure that the value of the Name property is unique. For example, you might choose to prepend the name of the port or interface with the Type of ProtocolEndpoint (for example, IPv4) of this instance followed by an underscore.
		void NameFormat(const string &value); 

		// Is true if the field NameFormat exists in the current object, otherwise is false.
		bool NameFormatExists() const;

		// Remove NameFormat field.
		void RemoveNameFormat(); 

		// Optional, Note: This property is deprecated in lieu of the ProtocolIFType enumeration. This deprecation was done to have better alignment between the IF-MIB of the IETF and this CIM class. 
		// Deprecated description: ProtocolType is an enumeration that provides information to categorize and classify different instances of this class. For most instances, information in this enumeration and the definition of the subclass overlap. However, there are several cases where a specific subclass of ProtocolEndpoint is not required (for example, there is no Fibre Channel subclass of ProtocolEndpoint). Therefore, this property is needed to define the type of Endpoint.
		const unsigned short ProtocolType() const;

		// Optional, Note: This property is deprecated in lieu of the ProtocolIFType enumeration. This deprecation was done to have better alignment between the IF-MIB of the IETF and this CIM class. 
		// Deprecated description: ProtocolType is an enumeration that provides information to categorize and classify different instances of this class. For most instances, information in this enumeration and the definition of the subclass overlap. However, there are several cases where a specific subclass of ProtocolEndpoint is not required (for example, there is no Fibre Channel subclass of ProtocolEndpoint). Therefore, this property is needed to define the type of Endpoint.
		void ProtocolType(const unsigned short value); 

		// Is true if the field ProtocolType exists in the current object, otherwise is false.
		bool ProtocolTypeExists() const;

		// Remove ProtocolType field.
		void RemoveProtocolType(); 

		// Optional, ProtocolIFType is an enumeration that is synchronized with the IANA ifType MIB. The ifType MIB is maintained at the URL, http://www.iana.org/assignments/ianaiftype-mib. Also, additional values defined by the DMTF are included. The property is used to categorize and classify instances of the ProtocolEndpoint class. Note that if the ProtocolIFType is set to 1 (Other), then the type information should be provided in the OtherTypeDescription string property.
		const unsigned short ProtocolIFType() const;

		// Optional, ProtocolIFType is an enumeration that is synchronized with the IANA ifType MIB. The ifType MIB is maintained at the URL, http://www.iana.org/assignments/ianaiftype-mib. Also, additional values defined by the DMTF are included. The property is used to categorize and classify instances of the ProtocolEndpoint class. Note that if the ProtocolIFType is set to 1 (Other), then the type information should be provided in the OtherTypeDescription string property.
		void ProtocolIFType(const unsigned short value); 

		// Is true if the field ProtocolIFType exists in the current object, otherwise is false.
		bool ProtocolIFTypeExists() const;

		// Remove ProtocolIFType field.
		void RemoveProtocolIFType(); 

		// Optional, A string that describes the type of ProtocolEndpoint when the Type property of this class (or any of its subclasses) is set to 1 (Other). This property should be set to null when the Type property is any value other than 1.
		const string OtherTypeDescription() const;

		// Optional, A string that describes the type of ProtocolEndpoint when the Type property of this class (or any of its subclasses) is set to 1 (Other). This property should be set to null when the Type property is any value other than 1.
		void OtherTypeDescription(const string &value); 

		// Is true if the field OtherTypeDescription exists in the current object, otherwise is false.
		bool OtherTypeDescriptionExists() const;

		// Remove OtherTypeDescription field.
		void RemoveOtherTypeDescription(); 

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

		static vector<shared_ptr<CIM_ProtocolEndpoint> > Enumerate(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		// Overloaded delete which supplies the internal resourceURI
		static void Delete(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		using CimBase::Delete;

	protected:
		 // Protected constructor to be used by derived classes
		CIM_ProtocolEndpoint(ICimWsmanClient *client, const string &class_name,
			const string &class_ns, const string &prefix, const string &uri): CIM_ServiceAccessPoint(client, class_name, class_ns, prefix, uri)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_ServiceAccessPoint::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 9);
			}
		}
		 // Protected constructor which receives CimObject
		CIM_ProtocolEndpoint(const CimObject &object)
			: CIM_ServiceAccessPoint(object)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_ServiceAccessPoint::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 9);
			}
		}
		// Called by derived classes
		void SetMetaData(vector<CimFieldAttribute>& childMetaData)
		{
			CIM_ServiceAccessPoint::SetMetaData(childMetaData);
			CimBase::SetMetaData(childMetaData, _metadata, 9);
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
#endif // CIM_PROTOCOLENDPOINT_H
