//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_ServiceServiceDependency.h
//
//  Contents:   CIM_ServiceServiceDependency is an association between a Service and another Service, which indicates that the latter cooperates with the former, is required to be present, required to have completed, or must be absent for the former Service to provide its functionality. For example, Boot Services might be dependent upon underlying system initialization Services. In the case of the initialization Services, the Boot Service might be dependent on the completion of the init Services. 
//              When examining the ServiceServiceDependency class definition, note that its superclass ProvidesServiceToElement is deprecated. Unfortunately, ProvidesServiceToElement cannot be removed from the object hierarchy without a major Schema release. When or if a major release occurs, the ProvidesServiceToElement superclass will be removed, and ServiceServiceDependency will subclass from CIM_Dependency directly.
//
//              This file was automatically generated from CIM_ServiceServiceDependency.mof,  version: 2.16.0
//
//----------------------------------------------------------------------------
#ifndef CIM_SERVICESERVICEDEPENDENCY_H
#define CIM_SERVICESERVICEDEPENDENCY_H 1
#include "CIM_ProvidesServiceToElement.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	// CIM_ServiceServiceDependency is an association between a Service and another Service, which indicates that the latter cooperates with the former, is required to be present, required to have completed, or must be absent for the former Service to provide its functionality. For example, Boot Services might be dependent upon underlying system initialization Services. In the case of the initialization Services, the Boot Service might be dependent on the completion of the init Services. 
	// When examining the ServiceServiceDependency class definition, note that its superclass ProvidesServiceToElement is deprecated. Unfortunately, ProvidesServiceToElement cannot be removed from the object hierarchy without a major Schema release. When or if a major release occurs, the ProvidesServiceToElement superclass will be removed, and ServiceServiceDependency will subclass from CIM_Dependency directly.
	class CIMFRAMEWORK_API CIM_ServiceServiceDependency  : public CIM_ProvidesServiceToElement
	{
	public:

		//Default constructor
		CIM_ServiceServiceDependency()
			: CIM_ProvidesServiceToElement(NULL, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_ProvidesServiceToElement::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 4);
			}
		}

		//constructor which receives WSMan client
		CIM_ServiceServiceDependency(ICimWsmanClient *client)
			: CIM_ProvidesServiceToElement(client, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_ProvidesServiceToElement::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 4);
			}
		}

		//Destructor
		virtual ~CIM_ServiceServiceDependency(){}

		// The "type" information for the object. Gettors only.
		virtual const string& ResourceURI() const { return CLASS_URI; }
		static const string& ClassResourceURI() { return CLASS_URI; }
		virtual const string& XmlNamespace() const { return CLASS_NS; }
		virtual const string& XmlPrefix() const { return CLASS_NS_PREFIX; }
		virtual const string& ObjectType() const { return CLASS_NAME; }
		static const string& ClassObjectType() { return CLASS_NAME; }

		// Class representing CIM_ServiceServiceDependency keys
		class CimKeys : public CIM_ProvidesServiceToElement::CimKeys
		{
		public:
			// Required, The required Service.
			const CimReference Antecedent() const
			{
				CimReference ret;
				TypeConverter::StringToType(GetKey("Antecedent"), ret);
				return ret;
			}

			// Required, The required Service.
			void Antecedent(const CimReference &value)
			{
				SetOrAddKey("Antecedent", TypeConverter::TypeToString(value), true);
			}

			// Required, The Service that is dependent on an underlying Service.
			const CimReference Dependent() const
			{
				CimReference ret;
				TypeConverter::StringToType(GetKey("Dependent"), ret);
				return ret;
			}

			// Required, The Service that is dependent on an underlying Service.
			void Dependent(const CimReference &value)
			{
				SetOrAddKey("Dependent", TypeConverter::TypeToString(value), true);
			}

		};

		// class fields declarations

		// Optional, The nature of the Service-to-Service dependency. 2 - Antecedent Service shall have completed before Dependent service's functionality is available.
		// 3 - Antecedent Service shall have started before Dependent service's functionality is available.
		// 4 - Antecedent Service shall not be started in order for Dependent service's functionality to be available.
		// 5 - The two Services cooperate and augment each other's function. There is no requirement implied by this value regarding the execution of the Antecedent service in order for the Dependent service to operate.
		const unsigned short TypeOfDependency() const;

		// Optional, The nature of the Service-to-Service dependency. 2 - Antecedent Service shall have completed before Dependent service's functionality is available.
		// 3 - Antecedent Service shall have started before Dependent service's functionality is available.
		// 4 - Antecedent Service shall not be started in order for Dependent service's functionality to be available.
		// 5 - The two Services cooperate and augment each other's function. There is no requirement implied by this value regarding the execution of the Antecedent service in order for the Dependent service to operate.
		void TypeOfDependency(const unsigned short value); 

		// Is true if the field TypeOfDependency exists in the current object, otherwise is false.
		bool TypeOfDependencyExists() const;

		// Remove TypeOfDependency field.
		void RemoveTypeOfDependency(); 

		// Optional, This property describes that the Antecedent Service must be restarted after the Dependent operation is complete.
		const bool RestartService() const;

		// Optional, This property describes that the Antecedent Service must be restarted after the Dependent operation is complete.
		void RestartService(const bool value); 

		// Is true if the field RestartService exists in the current object, otherwise is false.
		bool RestartServiceExists() const;

		// Remove RestartService field.
		void RemoveRestartService(); 

		 // Function used by the factory
		static CimBase *CreateFromCimObject(const CimObject &object);

		static vector<shared_ptr<CIM_ServiceServiceDependency> > Enumerate(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		// Overloaded delete which supplies the internal resourceURI
		static void Delete(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		using CimBase::Delete;

	protected:
		 // Protected constructor to be used by derived classes
		CIM_ServiceServiceDependency(ICimWsmanClient *client, const string &class_name,
			const string &class_ns, const string &prefix, const string &uri): CIM_ProvidesServiceToElement(client, class_name, class_ns, prefix, uri)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_ProvidesServiceToElement::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 4);
			}
		}
		 // Protected constructor which receives CimObject
		CIM_ServiceServiceDependency(const CimObject &object)
			: CIM_ProvidesServiceToElement(object)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_ProvidesServiceToElement::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 4);
			}
		}
		// Called by derived classes
		void SetMetaData(vector<CimFieldAttribute>& childMetaData)
		{
			CIM_ProvidesServiceToElement::SetMetaData(childMetaData);
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
#endif // CIM_SERVICESERVICEDEPENDENCY_H
