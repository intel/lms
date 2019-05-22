//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       AMT_AssetTable.h
//
//  Contents:   Represents an Asset Table
//
//              This file was automatically generated from AMT_AssetTable.mof,  version: 6.0.0
//
//----------------------------------------------------------------------------
#ifndef AMT_ASSETTABLE_H
#define AMT_ASSETTABLE_H 1
#include "CIM_ManagedElement.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	// Represents an Asset Table
	class CIMFRAMEWORK_API AMT_AssetTable  : public CIM_ManagedElement
	{
	public:

		//Default constructor
		AMT_AssetTable()
			: CIM_ManagedElement(NULL, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_ManagedElement::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 4);
			}
		}

		//constructor which receives WSMan client
		AMT_AssetTable(ICimWsmanClient *client)
			: CIM_ManagedElement(client, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_ManagedElement::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 4);
			}
		}

		//Destructor
		virtual ~AMT_AssetTable(){}

		// The "type" information for the object. Gettors only.
		virtual const string& ResourceURI() const { return CLASS_URI; }
		static const string& ClassResourceURI() { return CLASS_URI; }
		virtual const string& XmlNamespace() const { return CLASS_NS; }
		virtual const string& XmlPrefix() const { return CLASS_NS_PREFIX; }
		virtual const string& ObjectType() const { return CLASS_NAME; }
		static const string& ClassObjectType() { return CLASS_NAME; }

		// Class representing AMT_AssetTable keys
		class CimKeys : public CIM_ManagedElement::CimKeys
		{
		public:
			// Key, Required, The table type.
			const unsigned int TableType() const
			{
				unsigned int ret;
				TypeConverter::StringToType(GetKey("TableType"), ret);
				return ret;
			}

			// Key, Required, The table type.
			void TableType(const unsigned int value)
			{
				SetOrAddKey("TableType", TypeConverter::TypeToString(value));
			}

			// Key, Required, An instance number uniquely identifying a table of certain type.
			const string InstanceID() const
			{
				return GetKey("InstanceID");
			}

			// Key, Required, An instance number uniquely identifying a table of certain type.
			void InstanceID(const string &value)
			{
				SetOrAddKey("InstanceID", value);
			}

		};

		// class fields declarations

		// Key, Required, The table type.
		const unsigned int TableType() const;

		// Key, Required, The table type.
		void TableType(const unsigned int value); 


		// Optional, Further information on the table type (such as is this a SMbios, FRU or Media Device table.)
		const string TableTypeInfo() const;

		// Optional, Further information on the table type (such as is this a SMbios, FRU or Media Device table.)
		void TableTypeInfo(const string &value); 

		// Is true if the field TableTypeInfo exists in the current object, otherwise is false.
		bool TableTypeInfoExists() const;

		// Remove TableTypeInfo field.
		void RemoveTableTypeInfo(); 

		// Required, The table data in binary.
		const Base64 TableData() const;

		// Required, The table data in binary.
		void TableData(const Base64 &value); 

		// Is true if the field TableData exists in the current object, otherwise is false.
		bool TableDataExists() const;

		// Remove TableData field.
		void RemoveTableData(); 

		 // Function used by the factory
		static CimBase *CreateFromCimObject(const CimObject &object);

		static vector<shared_ptr<AMT_AssetTable> > Enumerate(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		// Overloaded delete which supplies the internal resourceURI
		static void Delete(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		using CimBase::Delete;

	protected:
		 // Protected constructor to be used by derived classes
		AMT_AssetTable(ICimWsmanClient *client, const string &class_name,
			const string &class_ns, const string &prefix, const string &uri): CIM_ManagedElement(client, class_name, class_ns, prefix, uri)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_ManagedElement::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 4);
			}
		}
		 // Protected constructor which receives CimObject
		AMT_AssetTable(const CimObject &object)
			: CIM_ManagedElement(object)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_ManagedElement::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 4);
			}
		}
		// Called by derived classes
		void SetMetaData(vector<CimFieldAttribute>& childMetaData)
		{
			CIM_ManagedElement::SetMetaData(childMetaData);
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
#endif // AMT_ASSETTABLE_H
