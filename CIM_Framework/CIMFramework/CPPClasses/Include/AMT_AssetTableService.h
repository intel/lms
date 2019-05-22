//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       AMT_AssetTableService.h
//
//  Contents:   Represents the Asset Table Service in the Intel(R) AMT subsystem.
//
//              This file was automatically generated from AMT_AssetTableService.mof,  version: 4.0.0
//
//----------------------------------------------------------------------------
#ifndef AMT_ASSETTABLESERVICE_H
#define AMT_ASSETTABLESERVICE_H 1
#include "CIM_Service.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	// Represents the Asset Table Service in the Intel(R) AMT subsystem.
	class CIMFRAMEWORK_API AMT_AssetTableService  : public CIM_Service
	{
	public:

		//Default constructor
		AMT_AssetTableService()
			: CIM_Service(NULL, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_Service::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 1);
			}
		}

		//constructor which receives WSMan client
		AMT_AssetTableService(ICimWsmanClient *client)
			: CIM_Service(client, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_Service::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 1);
			}
		}

		//Destructor
		virtual ~AMT_AssetTableService(){}

		// The "type" information for the object. Gettors only.
		virtual const string& ResourceURI() const { return CLASS_URI; }
		static const string& ClassResourceURI() { return CLASS_URI; }
		virtual const string& XmlNamespace() const { return CLASS_NS; }
		virtual const string& XmlPrefix() const { return CLASS_NS_PREFIX; }
		virtual const string& ObjectType() const { return CLASS_NAME; }
		static const string& ClassObjectType() { return CLASS_NAME; }

		// Class representing AMT_AssetTableService keys
		class CimKeys : public CIM_Service::CimKeys
		{
		public:
		};

		// class fields declarations

		// Required, An array of asset types supported by this service. Each string is of the following format: 'TableTypeInfo:TableType' for example: 'SMbios:130'
		const vector<string> TableTypes() const;

		// Required, An array of asset types supported by this service. Each string is of the following format: 'TableTypeInfo:TableType' for example: 'SMbios:130'
		void TableTypes(const vector<string> &value); 

		// Is true if the field TableTypes exists in the current object, otherwise is false.
		bool TableTypesExists() const;

		// Remove TableTypes field.
		void RemoveTableTypes(); 

		//Input parameter for function RequestMediaDeviceTableUpdate
		class CIMFRAMEWORK_API RequestMediaDeviceTableUpdate_INPUT : public CimParam
		{
		public:
			// Class Constructor
			RequestMediaDeviceTableUpdate_INPUT() : CimParam() {}

			// Class Destructor
			~RequestMediaDeviceTableUpdate_INPUT(){}

			// Required, Ask BIOS to send Media Device table.
			void FullUpdate(const bool value); 

			// Required, Apply just for next boot or permanently.
			void Sticky(const bool value); 

			const VectorFieldData GetAllFields() const;
		private:
			static const CimFieldAttribute _metadata[];
		};

		// Sends a request to BIOS to send the Media Device table on next boot. 
		virtual unsigned int RequestMediaDeviceTableUpdate(const RequestMediaDeviceTableUpdate_INPUT &input);

		 // Function used by the factory
		static CimBase *CreateFromCimObject(const CimObject &object);

		static vector<shared_ptr<AMT_AssetTableService> > Enumerate(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		// Overloaded delete which supplies the internal resourceURI
		static void Delete(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		using CimBase::Delete;

	protected:
		 // Protected constructor to be used by derived classes
		AMT_AssetTableService(ICimWsmanClient *client, const string &class_name,
			const string &class_ns, const string &prefix, const string &uri): CIM_Service(client, class_name, class_ns, prefix, uri)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_Service::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 1);
			}
		}
		 // Protected constructor which receives CimObject
		AMT_AssetTableService(const CimObject &object)
			: CIM_Service(object)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_Service::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 1);
			}
		}
		// Called by derived classes
		void SetMetaData(vector<CimFieldAttribute>& childMetaData)
		{
			CIM_Service::SetMetaData(childMetaData);
			CimBase::SetMetaData(childMetaData, _metadata, 1);
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
#endif // AMT_ASSETTABLESERVICE_H
