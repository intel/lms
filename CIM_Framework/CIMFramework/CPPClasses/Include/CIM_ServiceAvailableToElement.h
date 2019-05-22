//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_ServiceAvailableToElement.h
//
//  Contents:   CIM_ServiceAvailableToElement conveys the semantics of a Service that is available for the use of a ManagedElement. An example of an available Service is that a Processor and an enclosure (a PhysicalElement) can use AlertOnLAN Services to signal an incomplete or erroneous boot. In reality, AlertOnLAN is simply a HostedService on a computer system that is generally available for use and is not a dependency of the processor or enclosure. To describe that the use of this service might be restricted or have limited availability or applicability, the CIM_ServiceAvailableToElement association would be instantiated between the Service and specific CIM_Processors and CIM_Chassis.
//
//              This file was automatically generated from CIM_ServiceAvailableToElement.mof,  version: 2.10.0
//
//----------------------------------------------------------------------------
#ifndef CIM_SERVICEAVAILABLETOELEMENT_H
#define CIM_SERVICEAVAILABLETOELEMENT_H 1
#include "../../include/CimBase.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	// CIM_ServiceAvailableToElement conveys the semantics of a Service that is available for the use of a ManagedElement. An example of an available Service is that a Processor and an enclosure (a PhysicalElement) can use AlertOnLAN Services to signal an incomplete or erroneous boot. In reality, AlertOnLAN is simply a HostedService on a computer system that is generally available for use and is not a dependency of the processor or enclosure. To describe that the use of this service might be restricted or have limited availability or applicability, the CIM_ServiceAvailableToElement association would be instantiated between the Service and specific CIM_Processors and CIM_Chassis.
	class CIMFRAMEWORK_API CIM_ServiceAvailableToElement  : public CimBase
	{
	public:

		//Default constructor
		CIM_ServiceAvailableToElement()
			: CimBase(NULL, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CimBase::SetMetaData(_classMetaData, _metadata, 2);
			}
		}

		//constructor which receives WSMan client
		CIM_ServiceAvailableToElement(ICimWsmanClient *client)
			: CimBase(client, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CimBase::SetMetaData(_classMetaData, _metadata, 2);
			}
		}

		//Destructor
		virtual ~CIM_ServiceAvailableToElement(){}

		// The "type" information for the object. Gettors only.
		virtual const string& ResourceURI() const { return CLASS_URI; }
		static const string& ClassResourceURI() { return CLASS_URI; }
		virtual const string& XmlNamespace() const { return CLASS_NS; }
		virtual const string& XmlPrefix() const { return CLASS_NS_PREFIX; }
		virtual const string& ObjectType() const { return CLASS_NAME; }
		static const string& ClassObjectType() { return CLASS_NAME; }

		// Class representing CIM_ServiceAvailableToElement keys
		class CimKeys : public CimBase::CimKeys
		{
		public:
			// Key, Required, The Service that is available.
			const CimReference ServiceProvided() const
			{
				CimReference ret;
				TypeConverter::StringToType(GetKey("ServiceProvided"), ret);
				return ret;
			}

			// Key, Required, The Service that is available.
			void ServiceProvided(const CimReference &value)
			{
				SetOrAddKey("ServiceProvided", TypeConverter::TypeToString(value), true);
			}

			// Key, Required, The ManagedElement that can use the Service.
			const CimReference UserOfService() const
			{
				CimReference ret;
				TypeConverter::StringToType(GetKey("UserOfService"), ret);
				return ret;
			}

			// Key, Required, The ManagedElement that can use the Service.
			void UserOfService(const CimReference &value)
			{
				SetOrAddKey("UserOfService", TypeConverter::TypeToString(value), true);
			}

		};

		// class fields declarations

		// Key, Required, The Service that is available.
		const CimReference ServiceProvided() const;

		// Key, Required, The Service that is available.
		void ServiceProvided(const CimReference &value); 


		// Key, Required, The ManagedElement that can use the Service.
		const CimReference UserOfService() const;

		// Key, Required, The ManagedElement that can use the Service.
		void UserOfService(const CimReference &value); 


		 // Function used by the factory
		static CimBase *CreateFromCimObject(const CimObject &object);

		static vector<shared_ptr<CIM_ServiceAvailableToElement> > Enumerate(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		// Overloaded delete which supplies the internal resourceURI
		static void Delete(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		using CimBase::Delete;

	protected:
		 // Protected constructor to be used by derived classes
		CIM_ServiceAvailableToElement(ICimWsmanClient *client, const string &class_name,
			const string &class_ns, const string &prefix, const string &uri): CimBase(client, class_name, class_ns, prefix, uri)
		{
			if(_classMetaData.size() == 0)
			{
				CimBase::SetMetaData(_classMetaData, _metadata, 2);
			}
		}
		 // Protected constructor which receives CimObject
		CIM_ServiceAvailableToElement(const CimObject &object)
			: CimBase(object)
		{
			if(_classMetaData.size() == 0)
			{
				CimBase::SetMetaData(_classMetaData, _metadata, 2);
			}
		}
		// Called by derived classes
		void SetMetaData(vector<CimFieldAttribute>& childMetaData)
		{
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
#endif // CIM_SERVICEAVAILABLETOELEMENT_H
