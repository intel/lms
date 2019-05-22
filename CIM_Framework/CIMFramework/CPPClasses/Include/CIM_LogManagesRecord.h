//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_LogManagesRecord.h
//
//  Contents:   LogManagesRecord describes the aggregation or location of Records managed by a Log.
//
//              This file was automatically generated from CIM_LogManagesRecord.mof,  version: 2.9.0
//
//----------------------------------------------------------------------------
#ifndef CIM_LOGMANAGESRECORD_H
#define CIM_LOGMANAGESRECORD_H 1
#include "../../include/CimBase.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	// LogManagesRecord describes the aggregation or location of Records managed by a Log.
	class CIMFRAMEWORK_API CIM_LogManagesRecord  : public CimBase
	{
	public:

		//Default constructor
		CIM_LogManagesRecord()
			: CimBase(NULL, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CimBase::SetMetaData(_classMetaData, _metadata, 2);
			}
		}

		//constructor which receives WSMan client
		CIM_LogManagesRecord(ICimWsmanClient *client)
			: CimBase(client, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CimBase::SetMetaData(_classMetaData, _metadata, 2);
			}
		}

		//Destructor
		virtual ~CIM_LogManagesRecord(){}

		// The "type" information for the object. Gettors only.
		virtual const string& ResourceURI() const { return CLASS_URI; }
		static const string& ClassResourceURI() { return CLASS_URI; }
		virtual const string& XmlNamespace() const { return CLASS_NS; }
		virtual const string& XmlPrefix() const { return CLASS_NS_PREFIX; }
		virtual const string& ObjectType() const { return CLASS_NAME; }
		static const string& ClassObjectType() { return CLASS_NAME; }

		// Class representing CIM_LogManagesRecord keys
		class CimKeys : public CimBase::CimKeys
		{
		public:
			// Key, Required, The Log.
			const CimReference Log() const
			{
				CimReference ret;
				TypeConverter::StringToType(GetKey("Log"), ret);
				return ret;
			}

			// Key, Required, The Log.
			void Log(const CimReference &value)
			{
				SetOrAddKey("Log", TypeConverter::TypeToString(value), true);
			}

			// Key, Required, The record managed by the Log.
			const CimReference Record() const
			{
				CimReference ret;
				TypeConverter::StringToType(GetKey("Record"), ret);
				return ret;
			}

			// Key, Required, The record managed by the Log.
			void Record(const CimReference &value)
			{
				SetOrAddKey("Record", TypeConverter::TypeToString(value), true);
			}

		};

		// class fields declarations

		// Key, Required, The Log.
		const CimReference Log() const;

		// Key, Required, The Log.
		void Log(const CimReference &value); 


		// Key, Required, The record managed by the Log.
		const CimReference Record() const;

		// Key, Required, The record managed by the Log.
		void Record(const CimReference &value); 


		 // Function used by the factory
		static CimBase *CreateFromCimObject(const CimObject &object);

		static vector<shared_ptr<CIM_LogManagesRecord> > Enumerate(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		// Overloaded delete which supplies the internal resourceURI
		static void Delete(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		using CimBase::Delete;

	protected:
		 // Protected constructor to be used by derived classes
		CIM_LogManagesRecord(ICimWsmanClient *client, const string &class_name,
			const string &class_ns, const string &prefix, const string &uri): CimBase(client, class_name, class_ns, prefix, uri)
		{
			if(_classMetaData.size() == 0)
			{
				CimBase::SetMetaData(_classMetaData, _metadata, 2);
			}
		}
		 // Protected constructor which receives CimObject
		CIM_LogManagesRecord(const CimObject &object)
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
#endif // CIM_LOGMANAGESRECORD_H
