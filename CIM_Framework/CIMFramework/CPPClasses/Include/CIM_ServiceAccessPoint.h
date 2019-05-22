//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_ServiceAccessPoint.h
//
//  Contents:   CIM_ServiceAccessPoint represents the ability to utilize or invoke a Service. Access points represent that a Service is made available for other entities to use.
//
//              This file was automatically generated from CIM_ServiceAccessPoint.mof,  version: 2.10.0
//
//----------------------------------------------------------------------------
#ifndef CIM_SERVICEACCESSPOINT_H
#define CIM_SERVICEACCESSPOINT_H 1
#include "CIM_EnabledLogicalElement.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	// CIM_ServiceAccessPoint represents the ability to utilize or invoke a Service. Access points represent that a Service is made available for other entities to use.
	class CIMFRAMEWORK_API CIM_ServiceAccessPoint  : public CIM_EnabledLogicalElement
	{
	public:

		//Default constructor
		CIM_ServiceAccessPoint()
			: CIM_EnabledLogicalElement(NULL, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_EnabledLogicalElement::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 4);
			}
		}

		//constructor which receives WSMan client
		CIM_ServiceAccessPoint(ICimWsmanClient *client)
			: CIM_EnabledLogicalElement(client, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_EnabledLogicalElement::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 4);
			}
		}

		//Destructor
		virtual ~CIM_ServiceAccessPoint(){}

		// The "type" information for the object. Gettors only.
		virtual const string& ResourceURI() const { return CLASS_URI; }
		static const string& ClassResourceURI() { return CLASS_URI; }
		virtual const string& XmlNamespace() const { return CLASS_NS; }
		virtual const string& XmlPrefix() const { return CLASS_NS_PREFIX; }
		virtual const string& ObjectType() const { return CLASS_NAME; }
		static const string& ClassObjectType() { return CLASS_NAME; }

		// Class representing CIM_ServiceAccessPoint keys
		class CimKeys : public CIM_EnabledLogicalElement::CimKeys
		{
		public:
			// Key, Required, The CreationClassName of the scoping System.
			const string SystemCreationClassName() const
			{
				return GetKey("SystemCreationClassName");
			}

			// Key, Required, The CreationClassName of the scoping System.
			void SystemCreationClassName(const string &value)
			{
				SetOrAddKey("SystemCreationClassName", value);
			}

			// Key, Required, The Name of the scoping System.
			const string SystemName() const
			{
				return GetKey("SystemName");
			}

			// Key, Required, The Name of the scoping System.
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

			// Key, Required, The Name property uniquely identifies the ServiceAccessPoint and provides an indication of the functionality that is managed. This functionality is described in more detail in the Description property of the object.
			const string Name() const
			{
				return GetKey("Name");
			}

			// Key, Required, The Name property uniquely identifies the ServiceAccessPoint and provides an indication of the functionality that is managed. This functionality is described in more detail in the Description property of the object.
			void Name(const string &value)
			{
				SetOrAddKey("Name", value);
			}

		};

		// class fields declarations

		// Key, Required, The CreationClassName of the scoping System.
		const string SystemCreationClassName() const;

		// Key, Required, The CreationClassName of the scoping System.
		void SystemCreationClassName(const string &value); 


		// Key, Required, The Name of the scoping System.
		const string SystemName() const;

		// Key, Required, The Name of the scoping System.
		void SystemName(const string &value); 


		// Key, Required, CreationClassName indicates the name of the class or the subclass used in the creation of an instance. When used with the other key properties of this class, this property allows all instances of this class and its subclasses to be uniquely identified.
		const string CreationClassName() const;

		// Key, Required, CreationClassName indicates the name of the class or the subclass used in the creation of an instance. When used with the other key properties of this class, this property allows all instances of this class and its subclasses to be uniquely identified.
		void CreationClassName(const string &value); 


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

		static vector<shared_ptr<CIM_ServiceAccessPoint> > Enumerate(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		// Overloaded delete which supplies the internal resourceURI
		static void Delete(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		using CimBase::Delete;

	protected:
		 // Protected constructor to be used by derived classes
		CIM_ServiceAccessPoint(ICimWsmanClient *client, const string &class_name,
			const string &class_ns, const string &prefix, const string &uri): CIM_EnabledLogicalElement(client, class_name, class_ns, prefix, uri)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_EnabledLogicalElement::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 4);
			}
		}
		 // Protected constructor which receives CimObject
		CIM_ServiceAccessPoint(const CimObject &object)
			: CIM_EnabledLogicalElement(object)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_EnabledLogicalElement::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 4);
			}
		}
		// Called by derived classes
		void SetMetaData(vector<CimFieldAttribute>& childMetaData)
		{
			CIM_EnabledLogicalElement::SetMetaData(childMetaData);
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
#endif // CIM_SERVICEACCESSPOINT_H
