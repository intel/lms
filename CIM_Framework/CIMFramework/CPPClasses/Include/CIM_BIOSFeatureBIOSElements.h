//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_BIOSFeatureBIOSElements.h
//
//  Contents:   A link between BIOSFeature and its aggregated BIOSElements.
//
//              This file was automatically generated from CIM_BIOSFeatureBIOSElements.mof,  version: 2.6.0
//
//----------------------------------------------------------------------------
#ifndef CIM_BIOSFEATUREBIOSELEMENTS_H
#define CIM_BIOSFEATUREBIOSELEMENTS_H 1
#include "CIM_SoftwareFeatureSoftwareElements.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	// A link between BIOSFeature and its aggregated BIOSElements.
	class CIMFRAMEWORK_API CIM_BIOSFeatureBIOSElements  : public CIM_SoftwareFeatureSoftwareElements
	{
	public:

		//Default constructor
		CIM_BIOSFeatureBIOSElements()
			: CIM_SoftwareFeatureSoftwareElements(NULL, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_SoftwareFeatureSoftwareElements::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 2);
			}
		}

		//constructor which receives WSMan client
		CIM_BIOSFeatureBIOSElements(ICimWsmanClient *client)
			: CIM_SoftwareFeatureSoftwareElements(client, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_SoftwareFeatureSoftwareElements::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 2);
			}
		}

		//Destructor
		virtual ~CIM_BIOSFeatureBIOSElements(){}

		// The "type" information for the object. Gettors only.
		virtual const string& ResourceURI() const { return CLASS_URI; }
		static const string& ClassResourceURI() { return CLASS_URI; }
		virtual const string& XmlNamespace() const { return CLASS_NS; }
		virtual const string& XmlPrefix() const { return CLASS_NS_PREFIX; }
		virtual const string& ObjectType() const { return CLASS_NAME; }
		static const string& ClassObjectType() { return CLASS_NAME; }

		// Class representing CIM_BIOSFeatureBIOSElements keys
		class CimKeys : public CIM_SoftwareFeatureSoftwareElements::CimKeys
		{
		public:
			// Required, The BIOSFeature.
			const CimReference GroupComponent() const
			{
				CimReference ret;
				TypeConverter::StringToType(GetKey("GroupComponent"), ret);
				return ret;
			}

			// Required, The BIOSFeature.
			void GroupComponent(const CimReference &value)
			{
				SetOrAddKey("GroupComponent", TypeConverter::TypeToString(value), true);
			}

			// Required, The BIOSElement that implements the capabilities described by BIOSFeature.
			const CimReference PartComponent() const
			{
				CimReference ret;
				TypeConverter::StringToType(GetKey("PartComponent"), ret);
				return ret;
			}

			// Required, The BIOSElement that implements the capabilities described by BIOSFeature.
			void PartComponent(const CimReference &value)
			{
				SetOrAddKey("PartComponent", TypeConverter::TypeToString(value), true);
			}

		};
		 // Function used by the factory
		static CimBase *CreateFromCimObject(const CimObject &object);

		static vector<shared_ptr<CIM_BIOSFeatureBIOSElements> > Enumerate(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		// Overloaded delete which supplies the internal resourceURI
		static void Delete(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		using CimBase::Delete;

	protected:
		 // Protected constructor to be used by derived classes
		CIM_BIOSFeatureBIOSElements(ICimWsmanClient *client, const string &class_name,
			const string &class_ns, const string &prefix, const string &uri): CIM_SoftwareFeatureSoftwareElements(client, class_name, class_ns, prefix, uri)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_SoftwareFeatureSoftwareElements::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 2);
			}
		}
		 // Protected constructor which receives CimObject
		CIM_BIOSFeatureBIOSElements(const CimObject &object)
			: CIM_SoftwareFeatureSoftwareElements(object)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_SoftwareFeatureSoftwareElements::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 2);
			}
		}
		// Called by derived classes
		void SetMetaData(vector<CimFieldAttribute>& childMetaData)
		{
			CIM_SoftwareFeatureSoftwareElements::SetMetaData(childMetaData);
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
#endif // CIM_BIOSFEATUREBIOSELEMENTS_H
