//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_Service.h
//
//  Contents:   A Service is a LogicalElement that represents the availability of functionality that can be managed. This functionality may be provided by a seperately modeled entity such as a LogicalDevice or a SoftwareFeature, or both. The modeled Service typically provides only functionality required for management of itself or the elements it affects.
//
//              This file was automatically generated from CIM_Service.mof,  version: 2.14.0
//
//----------------------------------------------------------------------------
#ifndef CIM_SERVICE_H
#define CIM_SERVICE_H 1
#include "CIM_EnabledLogicalElement.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	// A Service is a LogicalElement that represents the availability of functionality that can be managed. This functionality may be provided by a seperately modeled entity such as a LogicalDevice or a SoftwareFeature, or both. The modeled Service typically provides only functionality required for management of itself or the elements it affects.
	class CIMFRAMEWORK_API CIM_Service  : public CIM_EnabledLogicalElement
	{
	public:

		//Default constructor
		CIM_Service()
			: CIM_EnabledLogicalElement(NULL, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_EnabledLogicalElement::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 8);
			}
		}

		//constructor which receives WSMan client
		CIM_Service(ICimWsmanClient *client)
			: CIM_EnabledLogicalElement(client, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_EnabledLogicalElement::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 8);
			}
		}

		//Destructor
		virtual ~CIM_Service(){}

		// The "type" information for the object. Gettors only.
		virtual const string& ResourceURI() const { return CLASS_URI; }
		static const string& ClassResourceURI() { return CLASS_URI; }
		virtual const string& XmlNamespace() const { return CLASS_NS; }
		virtual const string& XmlPrefix() const { return CLASS_NS_PREFIX; }
		virtual const string& ObjectType() const { return CLASS_NAME; }
		static const string& ClassObjectType() { return CLASS_NAME; }

		// Class representing CIM_Service keys
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

			// Key, Required, CreationClassName indicates the name of the class or the subclass that is used in the creation of an instance. When used with the other key properties of this class, this property allows all instances of this class and its subclasses to be uniquely identified.
			const string CreationClassName() const
			{
				return GetKey("CreationClassName");
			}

			// Key, Required, CreationClassName indicates the name of the class or the subclass that is used in the creation of an instance. When used with the other key properties of this class, this property allows all instances of this class and its subclasses to be uniquely identified.
			void CreationClassName(const string &value)
			{
				SetOrAddKey("CreationClassName", value);
			}

			// Key, Required, The Name property uniquely identifies the Service and provides an indication of the functionality that is managed. This functionality is described in more detail in the Description property of the object.
			const string Name() const
			{
				return GetKey("Name");
			}

			// Key, Required, The Name property uniquely identifies the Service and provides an indication of the functionality that is managed. This functionality is described in more detail in the Description property of the object.
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


		// Key, Required, CreationClassName indicates the name of the class or the subclass that is used in the creation of an instance. When used with the other key properties of this class, this property allows all instances of this class and its subclasses to be uniquely identified.
		const string CreationClassName() const;

		// Key, Required, CreationClassName indicates the name of the class or the subclass that is used in the creation of an instance. When used with the other key properties of this class, this property allows all instances of this class and its subclasses to be uniquely identified.
		void CreationClassName(const string &value); 


		// Optional, The name of the primary owner for the service, if one is defined. The primary owner is the initial support contact for the Service.
		const string PrimaryOwnerName() const;

		// Optional, The name of the primary owner for the service, if one is defined. The primary owner is the initial support contact for the Service.
		void PrimaryOwnerName(const string &value); 

		// Is true if the field PrimaryOwnerName exists in the current object, otherwise is false.
		bool PrimaryOwnerNameExists() const;

		// Remove PrimaryOwnerName field.
		void RemovePrimaryOwnerName(); 

		// Optional, A string that provides information on how the primary owner of the Service can be reached (for example, phone number, e-mail address, and so on).
		const string PrimaryOwnerContact() const;

		// Optional, A string that provides information on how the primary owner of the Service can be reached (for example, phone number, e-mail address, and so on).
		void PrimaryOwnerContact(const string &value); 

		// Is true if the field PrimaryOwnerContact exists in the current object, otherwise is false.
		bool PrimaryOwnerContactExists() const;

		// Remove PrimaryOwnerContact field.
		void RemovePrimaryOwnerContact(); 

		// Optional, Note: The use of this element is deprecated in lieu of the EnabledDefault property that is inherited from EnabledLogicalElement. The EnabledLogicalElement addresses the same semantics. The change to a uint16 data type was discussed when CIM V2.0 was defined. However, existing V1.0 implementations used the string property. To remain compatible with those implementations, StartMode was grandfathered into the schema. Use of the deprecated qualifier allows the maintenance of the existing property but also permits an improved, clarified definition using EnabledDefault. 
		// Deprecated description: StartMode is a string value that indicates whether the Service is automatically started by a System, an Operating System, and so on, or is started only upon request.
		const string StartMode() const;

		// Optional, Note: The use of this element is deprecated in lieu of the EnabledDefault property that is inherited from EnabledLogicalElement. The EnabledLogicalElement addresses the same semantics. The change to a uint16 data type was discussed when CIM V2.0 was defined. However, existing V1.0 implementations used the string property. To remain compatible with those implementations, StartMode was grandfathered into the schema. Use of the deprecated qualifier allows the maintenance of the existing property but also permits an improved, clarified definition using EnabledDefault. 
		// Deprecated description: StartMode is a string value that indicates whether the Service is automatically started by a System, an Operating System, and so on, or is started only upon request.
		void StartMode(const string &value); 

		// Is true if the field StartMode exists in the current object, otherwise is false.
		bool StartModeExists() const;

		// Remove StartMode field.
		void RemoveStartMode(); 

		// Optional, Started is a Boolean that indicates whether the Service has been started (TRUE), or stopped (FALSE).
		const bool Started() const;

		// Optional, Started is a Boolean that indicates whether the Service has been started (TRUE), or stopped (FALSE).
		void Started(const bool value); 

		// Is true if the field Started exists in the current object, otherwise is false.
		bool StartedExists() const;

		// Remove Started field.
		void RemoveStarted(); 

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

		// The StartService method places the Service in the started state. Note that the function of this method overlaps with the RequestedState property. RequestedState was added to the model to maintain a record (such as a persisted value) of the last state request. Invoking the StartService method should set the RequestedState property appropriately. The method returns an integer value of 0 if the Service was successfully started, 1 if the request is not supported, and any other number to indicate an error. In a subclass, the set of possible return codes could be specified using a ValueMap qualifier on the method. The strings to which the ValueMap contents are translated can also be specified in the subclass as a Values array qualifier. 
		// 
		// Note: The semantics of this method overlap with the RequestStateChange method that is inherited from EnabledLogicalElement. This method is maintained because it has been widely implemented, and its simple "start" semantics are convenient to use.
		virtual unsigned int StartService();

		// The StopService method places the Service in the stopped state. Note that the function of this method overlaps with the RequestedState property. RequestedState was added to the model to maintain a record (such as a persisted value) of the last state request. Invoking the StopService method should set the RequestedState property appropriately. The method returns an integer value of 0 if the Service was successfully stopped, 1 if the request is not supported, and any other number to indicate an error. In a subclass, the set of possible return codes could be specified using a ValueMap qualifier on the method. The strings to which the ValueMap contents are translated can also be specified in the subclass as a Values array qualifier. 
		// 
		// Note: The semantics of this method overlap with the RequestStateChange method that is inherited from EnabledLogicalElement. This method is maintained because it has been widely implemented, and its simple "stop" semantics are convenient to use.
		virtual unsigned int StopService();

		 // Function used by the factory
		static CimBase *CreateFromCimObject(const CimObject &object);

		static vector<shared_ptr<CIM_Service> > Enumerate(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		// Overloaded delete which supplies the internal resourceURI
		static void Delete(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		using CimBase::Delete;

	protected:
		 // Protected constructor to be used by derived classes
		CIM_Service(ICimWsmanClient *client, const string &class_name,
			const string &class_ns, const string &prefix, const string &uri): CIM_EnabledLogicalElement(client, class_name, class_ns, prefix, uri)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_EnabledLogicalElement::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 8);
			}
		}
		 // Protected constructor which receives CimObject
		CIM_Service(const CimObject &object)
			: CIM_EnabledLogicalElement(object)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_EnabledLogicalElement::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 8);
			}
		}
		// Called by derived classes
		void SetMetaData(vector<CimFieldAttribute>& childMetaData)
		{
			CIM_EnabledLogicalElement::SetMetaData(childMetaData);
			CimBase::SetMetaData(childMetaData, _metadata, 8);
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
#endif // CIM_SERVICE_H
