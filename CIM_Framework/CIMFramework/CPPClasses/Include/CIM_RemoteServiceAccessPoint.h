//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_RemoteServiceAccessPoint.h
//
//  Contents:   RemoteServiceAccessPoint describes access or addressing information or a combination of this information for a remote connection that is known to a local network element. This information is scoped or contained by the local network element, because this is the context in which the connection is remote. 
//              The relevance of the remote access point and information on its use are described by subclassing RemoteServiceAccessPoint or by associating to it.
//
//              This file was automatically generated from CIM_RemoteServiceAccessPoint.mof,  version: 2.27.0
//
//----------------------------------------------------------------------------
#ifndef CIM_REMOTESERVICEACCESSPOINT_H
#define CIM_REMOTESERVICEACCESSPOINT_H 1
#include "CIM_ServiceAccessPoint.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	// RemoteServiceAccessPoint describes access or addressing information or a combination of this information for a remote connection that is known to a local network element. This information is scoped or contained by the local network element, because this is the context in which the connection is remote. 
	// The relevance of the remote access point and information on its use are described by subclassing RemoteServiceAccessPoint or by associating to it.
	class CIMFRAMEWORK_API CIM_RemoteServiceAccessPoint  : public CIM_ServiceAccessPoint
	{
	public:

		//Default constructor
		CIM_RemoteServiceAccessPoint()
			: CIM_ServiceAccessPoint(NULL, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_ServiceAccessPoint::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 5);
			}
		}

		//constructor which receives WSMan client
		CIM_RemoteServiceAccessPoint(ICimWsmanClient *client)
			: CIM_ServiceAccessPoint(client, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_ServiceAccessPoint::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 5);
			}
		}

		//Destructor
		virtual ~CIM_RemoteServiceAccessPoint(){}

		// The "type" information for the object. Gettors only.
		virtual const string& ResourceURI() const { return CLASS_URI; }
		static const string& ClassResourceURI() { return CLASS_URI; }
		virtual const string& XmlNamespace() const { return CLASS_NS; }
		virtual const string& XmlPrefix() const { return CLASS_NS_PREFIX; }
		virtual const string& ObjectType() const { return CLASS_NAME; }
		static const string& ClassObjectType() { return CLASS_NAME; }

		// Class representing CIM_RemoteServiceAccessPoint keys
		class CimKeys : public CIM_ServiceAccessPoint::CimKeys
		{
		public:
		};

		// class fields declarations

		// Optional, Access or addressing information or a combination of this information for a remote connection. This information can be a host name, network address, or similar information.
		const string AccessInfo() const;

		// Optional, Access or addressing information or a combination of this information for a remote connection. This information can be a host name, network address, or similar information.
		void AccessInfo(const string &value); 

		// Is true if the field AccessInfo exists in the current object, otherwise is false.
		bool AccessInfoExists() const;

		// Remove AccessInfo field.
		void RemoveAccessInfo(); 

		// Optional, An enumerated integer that describes the format and interpretation of the AccessInfo property.
		// 206'Parameterized URL'- a URL containing ${parameterName} strings. Those strings are intended to be replaced in their entirety by the value of the named parameter. The interpretation of such parameters is not defined by this subclass. 
		// As an example use: If a parameter named 'CompanyURL' has a value of 'www.DMTF.org' and the value of AccessInfo was 'http:\${CompanyURL}', then the resultant URL is intended to be 'http:\www.dmtf.org'.
		const unsigned short InfoFormat() const;

		// Optional, An enumerated integer that describes the format and interpretation of the AccessInfo property.
		// 206'Parameterized URL'- a URL containing ${parameterName} strings. Those strings are intended to be replaced in their entirety by the value of the named parameter. The interpretation of such parameters is not defined by this subclass. 
		// As an example use: If a parameter named 'CompanyURL' has a value of 'www.DMTF.org' and the value of AccessInfo was 'http:\${CompanyURL}', then the resultant URL is intended to be 'http:\www.dmtf.org'.
		void InfoFormat(const unsigned short value); 

		// Is true if the field InfoFormat exists in the current object, otherwise is false.
		bool InfoFormatExists() const;

		// Remove InfoFormat field.
		void RemoveInfoFormat(); 

		// Optional, Describes the format when the property InfoFormat is set to 1 (Other).
		const string OtherInfoFormatDescription() const;

		// Optional, Describes the format when the property InfoFormat is set to 1 (Other).
		void OtherInfoFormatDescription(const string &value); 

		// Is true if the field OtherInfoFormatDescription exists in the current object, otherwise is false.
		bool OtherInfoFormatDescriptionExists() const;

		// Remove OtherInfoFormatDescription field.
		void RemoveOtherInfoFormatDescription(); 

		// Optional, The AccessContext property identifies the role this RemoteServiceAccessPoint is playing in the hosting system.
		const unsigned short AccessContext() const;

		// Optional, The AccessContext property identifies the role this RemoteServiceAccessPoint is playing in the hosting system.
		void AccessContext(const unsigned short value); 

		// Is true if the field AccessContext exists in the current object, otherwise is false.
		bool AccessContextExists() const;

		// Remove AccessContext field.
		void RemoveAccessContext(); 

		// Optional, When the AccessContext property contains a value of 1, "Other" then this is a free form string providing more information about the role of RemoteServiceAccessPoint in the hosting system.
		const string OtherAccessContext() const;

		// Optional, When the AccessContext property contains a value of 1, "Other" then this is a free form string providing more information about the role of RemoteServiceAccessPoint in the hosting system.
		void OtherAccessContext(const string &value); 

		// Is true if the field OtherAccessContext exists in the current object, otherwise is false.
		bool OtherAccessContextExists() const;

		// Remove OtherAccessContext field.
		void RemoveOtherAccessContext(); 

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

		static vector<shared_ptr<CIM_RemoteServiceAccessPoint> > Enumerate(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		// Overloaded delete which supplies the internal resourceURI
		static void Delete(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		using CimBase::Delete;

	protected:
		 // Protected constructor to be used by derived classes
		CIM_RemoteServiceAccessPoint(ICimWsmanClient *client, const string &class_name,
			const string &class_ns, const string &prefix, const string &uri): CIM_ServiceAccessPoint(client, class_name, class_ns, prefix, uri)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_ServiceAccessPoint::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 5);
			}
		}
		 // Protected constructor which receives CimObject
		CIM_RemoteServiceAccessPoint(const CimObject &object)
			: CIM_ServiceAccessPoint(object)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_ServiceAccessPoint::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 5);
			}
		}
		// Called by derived classes
		void SetMetaData(vector<CimFieldAttribute>& childMetaData)
		{
			CIM_ServiceAccessPoint::SetMetaData(childMetaData);
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
#endif // CIM_REMOTESERVICEACCESSPOINT_H
