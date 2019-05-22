//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_DeviceSAPImplementation.h
//
//  Contents:   An association between a ServiceAccessPoint (SAP) and how it is implemented. The cardinality of this association is many-to-many. A SAP can be provided by more than one LogicalDevice, operating in conjunction. And, any Device can provide more than one ServiceAccessPoint. When many LogicalDevices are associated with a single SAP, it is assumed that these elements operate in conjunction to provide the AccessPoint. If different implementations of a SAP exist, each of these implementations would result in individual instantiations of the ServiceAccessPoint object. These individual instantiations would then have associations to the unique implementations.
//
//              This file was automatically generated from CIM_DeviceSAPImplementation.mof,  version: 2.10.0
//
//----------------------------------------------------------------------------
#ifndef CIM_DEVICESAPIMPLEMENTATION_H
#define CIM_DEVICESAPIMPLEMENTATION_H 1
#include "CIM_Dependency.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	// An association between a ServiceAccessPoint (SAP) and how it is implemented. The cardinality of this association is many-to-many. A SAP can be provided by more than one LogicalDevice, operating in conjunction. And, any Device can provide more than one ServiceAccessPoint. When many LogicalDevices are associated with a single SAP, it is assumed that these elements operate in conjunction to provide the AccessPoint. If different implementations of a SAP exist, each of these implementations would result in individual instantiations of the ServiceAccessPoint object. These individual instantiations would then have associations to the unique implementations.
	class CIMFRAMEWORK_API CIM_DeviceSAPImplementation  : public CIM_Dependency
	{
	public:

		//Default constructor
		CIM_DeviceSAPImplementation()
			: CIM_Dependency(NULL, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_Dependency::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 2);
			}
		}

		//constructor which receives WSMan client
		CIM_DeviceSAPImplementation(ICimWsmanClient *client)
			: CIM_Dependency(client, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_Dependency::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 2);
			}
		}

		//Destructor
		virtual ~CIM_DeviceSAPImplementation(){}

		// The "type" information for the object. Gettors only.
		virtual const string& ResourceURI() const { return CLASS_URI; }
		static const string& ClassResourceURI() { return CLASS_URI; }
		virtual const string& XmlNamespace() const { return CLASS_NS; }
		virtual const string& XmlPrefix() const { return CLASS_NS_PREFIX; }
		virtual const string& ObjectType() const { return CLASS_NAME; }
		static const string& ClassObjectType() { return CLASS_NAME; }

		// Class representing CIM_DeviceSAPImplementation keys
		class CimKeys : public CIM_Dependency::CimKeys
		{
		public:
			// Required, The LogicalDevice.
			const CimReference Antecedent() const
			{
				CimReference ret;
				TypeConverter::StringToType(GetKey("Antecedent"), ret);
				return ret;
			}

			// Required, The LogicalDevice.
			void Antecedent(const CimReference &value)
			{
				SetOrAddKey("Antecedent", TypeConverter::TypeToString(value), true);
			}

			// Required, The ServiceAccessPoint implemented using the LogicalDevice.
			const CimReference Dependent() const
			{
				CimReference ret;
				TypeConverter::StringToType(GetKey("Dependent"), ret);
				return ret;
			}

			// Required, The ServiceAccessPoint implemented using the LogicalDevice.
			void Dependent(const CimReference &value)
			{
				SetOrAddKey("Dependent", TypeConverter::TypeToString(value), true);
			}

		};
		 // Function used by the factory
		static CimBase *CreateFromCimObject(const CimObject &object);

		static vector<shared_ptr<CIM_DeviceSAPImplementation> > Enumerate(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		// Overloaded delete which supplies the internal resourceURI
		static void Delete(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		using CimBase::Delete;

	protected:
		 // Protected constructor to be used by derived classes
		CIM_DeviceSAPImplementation(ICimWsmanClient *client, const string &class_name,
			const string &class_ns, const string &prefix, const string &uri): CIM_Dependency(client, class_name, class_ns, prefix, uri)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_Dependency::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 2);
			}
		}
		 // Protected constructor which receives CimObject
		CIM_DeviceSAPImplementation(const CimObject &object)
			: CIM_Dependency(object)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_Dependency::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 2);
			}
		}
		// Called by derived classes
		void SetMetaData(vector<CimFieldAttribute>& childMetaData)
		{
			CIM_Dependency::SetMetaData(childMetaData);
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
#endif // CIM_DEVICESAPIMPLEMENTATION_H
