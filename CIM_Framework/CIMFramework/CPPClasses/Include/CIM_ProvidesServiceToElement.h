//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_ProvidesServiceToElement.h
//
//  Contents:   Note: The use of the CIM_ProvidesServiceToElement class has been deprecated. Instead, ServiceAvailableToElement conveys the semantics of use, while the subclasses of ProvidesServiceToElement (or the ConcreteDependency association) describe dependency relationships. CIM_ProvidesServiceToElement was meant to generalize the ServiceServiceDependency association. This method indicates that ManagedElements can use the functionality provided by one or more Services. An example of the association is that a Processor and an enclosure (a PhysicalElement) can use AlertOnLAN Services to signal an incomplete or erroneous boot. In reality, AlertOnLAN is simply a HostedService on a computer system that is generally available for use and is not a dependency of the processor or enclosure. To describe that the use of the service might be restricted or have limited availability or applicability, the CIM_ServiceAvailableToElement association would be instantiated.
//
//              This file was automatically generated from CIM_ProvidesServiceToElement.mof,  version: 2.10.0
//
//----------------------------------------------------------------------------
#ifndef CIM_PROVIDESSERVICETOELEMENT_H
#define CIM_PROVIDESSERVICETOELEMENT_H 1
#include "CIM_Dependency.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	// Note: The use of the CIM_ProvidesServiceToElement class has been deprecated. Instead, ServiceAvailableToElement conveys the semantics of use, while the subclasses of ProvidesServiceToElement (or the ConcreteDependency association) describe dependency relationships. CIM_ProvidesServiceToElement was meant to generalize the ServiceServiceDependency association. This method indicates that ManagedElements can use the functionality provided by one or more Services. An example of the association is that a Processor and an enclosure (a PhysicalElement) can use AlertOnLAN Services to signal an incomplete or erroneous boot. In reality, AlertOnLAN is simply a HostedService on a computer system that is generally available for use and is not a dependency of the processor or enclosure. To describe that the use of the service might be restricted or have limited availability or applicability, the CIM_ServiceAvailableToElement association would be instantiated.
	class CIMFRAMEWORK_API CIM_ProvidesServiceToElement  : public CIM_Dependency
	{
	public:

		//Default constructor
		CIM_ProvidesServiceToElement()
			: CIM_Dependency(NULL, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_Dependency::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 2);
			}
		}

		//constructor which receives WSMan client
		CIM_ProvidesServiceToElement(ICimWsmanClient *client)
			: CIM_Dependency(client, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_Dependency::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 2);
			}
		}

		//Destructor
		virtual ~CIM_ProvidesServiceToElement(){}

		// The "type" information for the object. Gettors only.
		virtual const string& ResourceURI() const { return CLASS_URI; }
		static const string& ClassResourceURI() { return CLASS_URI; }
		virtual const string& XmlNamespace() const { return CLASS_NS; }
		virtual const string& XmlPrefix() const { return CLASS_NS_PREFIX; }
		virtual const string& ObjectType() const { return CLASS_NAME; }
		static const string& ClassObjectType() { return CLASS_NAME; }

		// Class representing CIM_ProvidesServiceToElement keys
		class CimKeys : public CIM_Dependency::CimKeys
		{
		public:
			// Required, Note: The use of this element is deprecated. Deprecated description: The Service provided.
			const CimReference Antecedent() const
			{
				CimReference ret;
				TypeConverter::StringToType(GetKey("Antecedent"), ret);
				return ret;
			}

			// Required, Note: The use of this element is deprecated. Deprecated description: The Service provided.
			void Antecedent(const CimReference &value)
			{
				SetOrAddKey("Antecedent", TypeConverter::TypeToString(value), true);
			}

			// Required, Note: The use of this element is deprecated. Deprecated description: The ManagedElement that is dependent on the Service.
			const CimReference Dependent() const
			{
				CimReference ret;
				TypeConverter::StringToType(GetKey("Dependent"), ret);
				return ret;
			}

			// Required, Note: The use of this element is deprecated. Deprecated description: The ManagedElement that is dependent on the Service.
			void Dependent(const CimReference &value)
			{
				SetOrAddKey("Dependent", TypeConverter::TypeToString(value), true);
			}

		};
		 // Function used by the factory
		static CimBase *CreateFromCimObject(const CimObject &object);

		static vector<shared_ptr<CIM_ProvidesServiceToElement> > Enumerate(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		// Overloaded delete which supplies the internal resourceURI
		static void Delete(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		using CimBase::Delete;

	protected:
		 // Protected constructor to be used by derived classes
		CIM_ProvidesServiceToElement(ICimWsmanClient *client, const string &class_name,
			const string &class_ns, const string &prefix, const string &uri): CIM_Dependency(client, class_name, class_ns, prefix, uri)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_Dependency::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 2);
			}
		}
		 // Protected constructor which receives CimObject
		CIM_ProvidesServiceToElement(const CimObject &object)
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
#endif // CIM_PROVIDESSERVICETOELEMENT_H
