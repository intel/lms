//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_ElementStatisticalData.h
//
//  Contents:   CIM_ElementStatisticalData is an association that relates a ManagedElement to its StatisticalData. Note that the cardinality of the ManagedElement reference is Min(1), Max(1). This cardinality mandates the instantiation of the ElementStatisticalData association for the referenced instance of CIM_StatisticalData. ElementStatisticalData describes the existence requirements and context for the CIM_StatisticalData, relative to a specific ManagedElement.
//
//              This file was automatically generated from CIM_ElementStatisticalData.mof,  version: 2.7.0
//
//----------------------------------------------------------------------------
#ifndef CIM_ELEMENTSTATISTICALDATA_H
#define CIM_ELEMENTSTATISTICALDATA_H 1
#include "../../include/CimBase.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	// CIM_ElementStatisticalData is an association that relates a ManagedElement to its StatisticalData. Note that the cardinality of the ManagedElement reference is Min(1), Max(1). This cardinality mandates the instantiation of the ElementStatisticalData association for the referenced instance of CIM_StatisticalData. ElementStatisticalData describes the existence requirements and context for the CIM_StatisticalData, relative to a specific ManagedElement.
	class CIMFRAMEWORK_API CIM_ElementStatisticalData  : public CimBase
	{
	public:

		//Default constructor
		CIM_ElementStatisticalData()
			: CimBase(NULL, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CimBase::SetMetaData(_classMetaData, _metadata, 2);
			}
		}

		//constructor which receives WSMan client
		CIM_ElementStatisticalData(ICimWsmanClient *client)
			: CimBase(client, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CimBase::SetMetaData(_classMetaData, _metadata, 2);
			}
		}

		//Destructor
		virtual ~CIM_ElementStatisticalData(){}

		// The "type" information for the object. Gettors only.
		virtual const string& ResourceURI() const { return CLASS_URI; }
		static const string& ClassResourceURI() { return CLASS_URI; }
		virtual const string& XmlNamespace() const { return CLASS_NS; }
		virtual const string& XmlPrefix() const { return CLASS_NS_PREFIX; }
		virtual const string& ObjectType() const { return CLASS_NAME; }
		static const string& ClassObjectType() { return CLASS_NAME; }

		// Class representing CIM_ElementStatisticalData keys
		class CimKeys : public CimBase::CimKeys
		{
		public:
			// Key, Required, The ManagedElement for which statistical or metric data is defined.
			const CimReference ManagedElement() const
			{
				CimReference ret;
				TypeConverter::StringToType(GetKey("ManagedElement"), ret);
				return ret;
			}

			// Key, Required, The ManagedElement for which statistical or metric data is defined.
			void ManagedElement(const CimReference &value)
			{
				SetOrAddKey("ManagedElement", TypeConverter::TypeToString(value), true);
			}

			// Key, Required, The statistic information/object.
			const CimReference Stats() const
			{
				CimReference ret;
				TypeConverter::StringToType(GetKey("Stats"), ret);
				return ret;
			}

			// Key, Required, The statistic information/object.
			void Stats(const CimReference &value)
			{
				SetOrAddKey("Stats", TypeConverter::TypeToString(value), true);
			}

		};

		// class fields declarations

		// Key, Required, The ManagedElement for which statistical or metric data is defined.
		const CimReference ManagedElement() const;

		// Key, Required, The ManagedElement for which statistical or metric data is defined.
		void ManagedElement(const CimReference &value); 


		// Key, Required, The statistic information/object.
		const CimReference Stats() const;

		// Key, Required, The statistic information/object.
		void Stats(const CimReference &value); 


		 // Function used by the factory
		static CimBase *CreateFromCimObject(const CimObject &object);

		static vector<shared_ptr<CIM_ElementStatisticalData> > Enumerate(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		// Overloaded delete which supplies the internal resourceURI
		static void Delete(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		using CimBase::Delete;

	protected:
		 // Protected constructor to be used by derived classes
		CIM_ElementStatisticalData(ICimWsmanClient *client, const string &class_name,
			const string &class_ns, const string &prefix, const string &uri): CimBase(client, class_name, class_ns, prefix, uri)
		{
			if(_classMetaData.size() == 0)
			{
				CimBase::SetMetaData(_classMetaData, _metadata, 2);
			}
		}
		 // Protected constructor which receives CimObject
		CIM_ElementStatisticalData(const CimObject &object)
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
#endif // CIM_ELEMENTSTATISTICALDATA_H
