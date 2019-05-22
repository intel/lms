//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_ServiceAffectsElement.h
//
//  Contents:   ServiceAffectsElement represents an association between a Service and the ManagedElements that might be affected by its execution. Instantiating this association indicates that running the service may change, manage, provide functionality for,or pose some burden on the ManagedElement. This burden might affect performance, throughput, availability, and so on.
//
//              This file was automatically generated from CIM_ServiceAffectsElement.mof,  version: 2.14.0
//
//----------------------------------------------------------------------------
#ifndef CIM_SERVICEAFFECTSELEMENT_H
#define CIM_SERVICEAFFECTSELEMENT_H 1
#include "../../include/CimBase.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	// ServiceAffectsElement represents an association between a Service and the ManagedElements that might be affected by its execution. Instantiating this association indicates that running the service may change, manage, provide functionality for,or pose some burden on the ManagedElement. This burden might affect performance, throughput, availability, and so on.
	class CIMFRAMEWORK_API CIM_ServiceAffectsElement  : public CimBase
	{
	public:

		//Default constructor
		CIM_ServiceAffectsElement()
			: CimBase(NULL, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CimBase::SetMetaData(_classMetaData, _metadata, 4);
			}
		}

		//constructor which receives WSMan client
		CIM_ServiceAffectsElement(ICimWsmanClient *client)
			: CimBase(client, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CimBase::SetMetaData(_classMetaData, _metadata, 4);
			}
		}

		//Destructor
		virtual ~CIM_ServiceAffectsElement(){}

		// The "type" information for the object. Gettors only.
		virtual const string& ResourceURI() const { return CLASS_URI; }
		static const string& ClassResourceURI() { return CLASS_URI; }
		virtual const string& XmlNamespace() const { return CLASS_NS; }
		virtual const string& XmlPrefix() const { return CLASS_NS_PREFIX; }
		virtual const string& ObjectType() const { return CLASS_NAME; }
		static const string& ClassObjectType() { return CLASS_NAME; }

		// Class representing CIM_ServiceAffectsElement keys
		class CimKeys : public CimBase::CimKeys
		{
		public:
			// Key, Required, The Managed Element that is affected by the Service.
			const CimReference AffectedElement() const
			{
				CimReference ret;
				TypeConverter::StringToType(GetKey("AffectedElement"), ret);
				return ret;
			}

			// Key, Required, The Managed Element that is affected by the Service.
			void AffectedElement(const CimReference &value)
			{
				SetOrAddKey("AffectedElement", TypeConverter::TypeToString(value), true);
			}

			// Key, Required, The Service that is affecting the ManagedElement.
			const CimReference AffectingElement() const
			{
				CimReference ret;
				TypeConverter::StringToType(GetKey("AffectingElement"), ret);
				return ret;
			}

			// Key, Required, The Service that is affecting the ManagedElement.
			void AffectingElement(const CimReference &value)
			{
				SetOrAddKey("AffectingElement", TypeConverter::TypeToString(value), true);
			}

		};

		// class fields declarations

		// Key, Required, The Managed Element that is affected by the Service.
		const CimReference AffectedElement() const;

		// Key, Required, The Managed Element that is affected by the Service.
		void AffectedElement(const CimReference &value); 


		// Key, Required, The Service that is affecting the ManagedElement.
		const CimReference AffectingElement() const;

		// Key, Required, The Service that is affecting the ManagedElement.
		void AffectingElement(const CimReference &value); 


		// Optional, An enumeration that describes the effect on the ManagedElement. This array corresponds to the OtherElementEffectsDescriptions array, where the latter provides details that are related to the high-level effects enumerated by this property. Additional detail is required if the ElementEffects array contains the value 1 (Other). The values are defined as follows: 
		// - Exclusive Use (2): No other Service may have this association to the element. 
		// - Performance Impact (3): Deprecated in favor of "Consumes", "Enhances Performance", or "Degrades Performance". Execution of the Service may enhance or degrade the performance of the element. This may be as a side-effect of execution or as an intended consequence of methods provided by the Service. 
		// - Element Integrity (4): Deprecated in favor of "Consumes", "Enhances Integrity", or "Degrades Integrity". Execution of the Service may enhance or degrade the integrity of the element. This may be as a side-effect of execution or as an intended consequence of methods provided by the Service. 
		// - Manages (5): The Service manages the element. 
		// - Consumes (6): Execution of the Service consumes some or all of the associated element as a consequence of running the Service. For example, the Service may consume CPU cycles, which may affect performance, or Storage which may affect both performance and integrity. (For instance, the lack of free storage can degrade integrity by reducing the ability to save state. ) "Consumes" may be used alone or in conjunction with other values, in particular, "Degrades Performance" and "Degrades Integrity". 
		// "Manages" and not "Consumes" should be used to reflect allocation services that may be provided by a Service. 
		// - Enhances Integrity (7): The Service may enhance integrity of the associated element. 
		// - Degrades Integrity (8): The Service may degrade integrity of the associated element. 
		// - Enhances Performance (9): The Service may enhance performance of the associated element. 
		// - Degrades Performance (10): The Service may degrade performance of the associated element.
		const vector<unsigned short> ElementEffects() const;

		// Optional, An enumeration that describes the effect on the ManagedElement. This array corresponds to the OtherElementEffectsDescriptions array, where the latter provides details that are related to the high-level effects enumerated by this property. Additional detail is required if the ElementEffects array contains the value 1 (Other). The values are defined as follows: 
		// - Exclusive Use (2): No other Service may have this association to the element. 
		// - Performance Impact (3): Deprecated in favor of "Consumes", "Enhances Performance", or "Degrades Performance". Execution of the Service may enhance or degrade the performance of the element. This may be as a side-effect of execution or as an intended consequence of methods provided by the Service. 
		// - Element Integrity (4): Deprecated in favor of "Consumes", "Enhances Integrity", or "Degrades Integrity". Execution of the Service may enhance or degrade the integrity of the element. This may be as a side-effect of execution or as an intended consequence of methods provided by the Service. 
		// - Manages (5): The Service manages the element. 
		// - Consumes (6): Execution of the Service consumes some or all of the associated element as a consequence of running the Service. For example, the Service may consume CPU cycles, which may affect performance, or Storage which may affect both performance and integrity. (For instance, the lack of free storage can degrade integrity by reducing the ability to save state. ) "Consumes" may be used alone or in conjunction with other values, in particular, "Degrades Performance" and "Degrades Integrity". 
		// "Manages" and not "Consumes" should be used to reflect allocation services that may be provided by a Service. 
		// - Enhances Integrity (7): The Service may enhance integrity of the associated element. 
		// - Degrades Integrity (8): The Service may degrade integrity of the associated element. 
		// - Enhances Performance (9): The Service may enhance performance of the associated element. 
		// - Degrades Performance (10): The Service may degrade performance of the associated element.
		void ElementEffects(const vector<unsigned short> &value); 

		// Is true if the field ElementEffects exists in the current object, otherwise is false.
		bool ElementEffectsExists() const;

		// Remove ElementEffects field.
		void RemoveElementEffects(); 

		// Optional, Provides details for the effect at the corresponding array position in ElementEffects. This information is required if ElementEffects contains the value 1 (Other).
		const vector<string> OtherElementEffectsDescriptions() const;

		// Optional, Provides details for the effect at the corresponding array position in ElementEffects. This information is required if ElementEffects contains the value 1 (Other).
		void OtherElementEffectsDescriptions(const vector<string> &value); 

		// Is true if the field OtherElementEffectsDescriptions exists in the current object, otherwise is false.
		bool OtherElementEffectsDescriptionsExists() const;

		// Remove OtherElementEffectsDescriptions field.
		void RemoveOtherElementEffectsDescriptions(); 

		 // Function used by the factory
		static CimBase *CreateFromCimObject(const CimObject &object);

		static vector<shared_ptr<CIM_ServiceAffectsElement> > Enumerate(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		// Overloaded delete which supplies the internal resourceURI
		static void Delete(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		using CimBase::Delete;

	protected:
		 // Protected constructor to be used by derived classes
		CIM_ServiceAffectsElement(ICimWsmanClient *client, const string &class_name,
			const string &class_ns, const string &prefix, const string &uri): CimBase(client, class_name, class_ns, prefix, uri)
		{
			if(_classMetaData.size() == 0)
			{
				CimBase::SetMetaData(_classMetaData, _metadata, 4);
			}
		}
		 // Protected constructor which receives CimObject
		CIM_ServiceAffectsElement(const CimObject &object)
			: CimBase(object)
		{
			if(_classMetaData.size() == 0)
			{
				CimBase::SetMetaData(_classMetaData, _metadata, 4);
			}
		}
		// Called by derived classes
		void SetMetaData(vector<CimFieldAttribute>& childMetaData)
		{
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
#endif // CIM_SERVICEAFFECTSELEMENT_H
