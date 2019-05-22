//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_HostedAccessPoint.h
//
//  Contents:   CIM_HostedAccessPoint is an association between a Service AccessPoint and the System on which it is provided. The cardinality of this association is one-to-many and is weak with respect to the System. Each System can host many ServiceAccessPoints. Heuristic: If the implementation of the ServiceAccessPoint is modeled, it must be implemented by a Device or SoftwareFeature that is part of the System that is hosting the ServiceAccessPoint.
//
//              This file was automatically generated from CIM_HostedAccessPoint.mof,  version: 2.10.0
//
//----------------------------------------------------------------------------
#ifndef CIM_HOSTEDACCESSPOINT_H
#define CIM_HOSTEDACCESSPOINT_H 1
#include "CIM_HostedDependency.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	// CIM_HostedAccessPoint is an association between a Service AccessPoint and the System on which it is provided. The cardinality of this association is one-to-many and is weak with respect to the System. Each System can host many ServiceAccessPoints. Heuristic: If the implementation of the ServiceAccessPoint is modeled, it must be implemented by a Device or SoftwareFeature that is part of the System that is hosting the ServiceAccessPoint.
	class CIMFRAMEWORK_API CIM_HostedAccessPoint  : public CIM_HostedDependency
	{
	public:

		//Default constructor
		CIM_HostedAccessPoint()
			: CIM_HostedDependency(NULL, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_HostedDependency::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 2);
			}
		}

		//constructor which receives WSMan client
		CIM_HostedAccessPoint(ICimWsmanClient *client)
			: CIM_HostedDependency(client, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_HostedDependency::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 2);
			}
		}

		//Destructor
		virtual ~CIM_HostedAccessPoint(){}

		// The "type" information for the object. Gettors only.
		virtual const string& ResourceURI() const { return CLASS_URI; }
		static const string& ClassResourceURI() { return CLASS_URI; }
		virtual const string& XmlNamespace() const { return CLASS_NS; }
		virtual const string& XmlPrefix() const { return CLASS_NS_PREFIX; }
		virtual const string& ObjectType() const { return CLASS_NAME; }
		static const string& ClassObjectType() { return CLASS_NAME; }

		// Class representing CIM_HostedAccessPoint keys
		class CimKeys : public CIM_HostedDependency::CimKeys
		{
		public:
			// Required, The hosting System.
			const CimReference Antecedent() const
			{
				CimReference ret;
				TypeConverter::StringToType(GetKey("Antecedent"), ret);
				return ret;
			}

			// Required, The hosting System.
			void Antecedent(const CimReference &value)
			{
				SetOrAddKey("Antecedent", TypeConverter::TypeToString(value), true);
			}

			// Required, The SAPs that are hosted on this System.
			const CimReference Dependent() const
			{
				CimReference ret;
				TypeConverter::StringToType(GetKey("Dependent"), ret);
				return ret;
			}

			// Required, The SAPs that are hosted on this System.
			void Dependent(const CimReference &value)
			{
				SetOrAddKey("Dependent", TypeConverter::TypeToString(value), true);
			}

		};
		 // Function used by the factory
		static CimBase *CreateFromCimObject(const CimObject &object);

		static vector<shared_ptr<CIM_HostedAccessPoint> > Enumerate(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		// Overloaded delete which supplies the internal resourceURI
		static void Delete(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		using CimBase::Delete;

	protected:
		 // Protected constructor to be used by derived classes
		CIM_HostedAccessPoint(ICimWsmanClient *client, const string &class_name,
			const string &class_ns, const string &prefix, const string &uri): CIM_HostedDependency(client, class_name, class_ns, prefix, uri)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_HostedDependency::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 2);
			}
		}
		 // Protected constructor which receives CimObject
		CIM_HostedAccessPoint(const CimObject &object)
			: CIM_HostedDependency(object)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_HostedDependency::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 2);
			}
		}
		// Called by derived classes
		void SetMetaData(vector<CimFieldAttribute>& childMetaData)
		{
			CIM_HostedDependency::SetMetaData(childMetaData);
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
#endif // CIM_HOSTEDACCESSPOINT_H
