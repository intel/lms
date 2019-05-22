//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       IPS_DALProvisioningRecord.h
//
//  Contents:   The IPS_DALProvisioningRecord provides information related to a single Intel (R) AMT provisioning occurrence that was performed using DAL.
//
//              This file was automatically generated from IPS_DALProvisioningRecord.mof,  version: 12.0.0
//
//----------------------------------------------------------------------------
#ifndef IPS_DALPROVISIONINGRECORD_H
#define IPS_DALPROVISIONINGRECORD_H 1
#include "IPS_ProvisioningAuditRecord.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	// The IPS_DALProvisioningRecord provides information related to a single Intel (R) AMT provisioning occurrence that was performed using DAL.
	class CIMFRAMEWORK_API IPS_DALProvisioningRecord  : public IPS_ProvisioningAuditRecord
	{
	public:

		//Default constructor
		IPS_DALProvisioningRecord()
			: IPS_ProvisioningAuditRecord(NULL, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				IPS_ProvisioningAuditRecord::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 1);
			}
		}

		//constructor which receives WSMan client
		IPS_DALProvisioningRecord(ICimWsmanClient *client)
			: IPS_ProvisioningAuditRecord(client, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				IPS_ProvisioningAuditRecord::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 1);
			}
		}

		//Destructor
		virtual ~IPS_DALProvisioningRecord(){}

		// The "type" information for the object. Gettors only.
		virtual const string& ResourceURI() const { return CLASS_URI; }
		static const string& ClassResourceURI() { return CLASS_URI; }
		virtual const string& XmlNamespace() const { return CLASS_NS; }
		virtual const string& XmlPrefix() const { return CLASS_NS_PREFIX; }
		virtual const string& ObjectType() const { return CLASS_NAME; }
		static const string& ClassObjectType() { return CLASS_NAME; }

		// Class representing IPS_DALProvisioningRecord keys
		class CimKeys : public IPS_ProvisioningAuditRecord::CimKeys
		{
		public:
		};

		// class fields declarations

		// Optional, The data which was saved by FW when DAL assisted provisioning occured.FW is agnostic to data encoding.
		const Base64 DALRecord() const;

		// Optional, The data which was saved by FW when DAL assisted provisioning occured.FW is agnostic to data encoding.
		void DALRecord(const Base64 &value); 

		// Is true if the field DALRecord exists in the current object, otherwise is false.
		bool DALRecordExists() const;

		// Remove DALRecord field.
		void RemoveDALRecord(); 

		 // Function used by the factory
		static CimBase *CreateFromCimObject(const CimObject &object);

		static vector<shared_ptr<IPS_DALProvisioningRecord> > Enumerate(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		// Overloaded delete which supplies the internal resourceURI
		static void Delete(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		using CimBase::Delete;

	protected:
		 // Protected constructor to be used by derived classes
		IPS_DALProvisioningRecord(ICimWsmanClient *client, const string &class_name,
			const string &class_ns, const string &prefix, const string &uri): IPS_ProvisioningAuditRecord(client, class_name, class_ns, prefix, uri)
		{
			if(_classMetaData.size() == 0)
			{
				IPS_ProvisioningAuditRecord::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 1);
			}
		}
		 // Protected constructor which receives CimObject
		IPS_DALProvisioningRecord(const CimObject &object)
			: IPS_ProvisioningAuditRecord(object)
		{
			if(_classMetaData.size() == 0)
			{
				IPS_ProvisioningAuditRecord::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 1);
			}
		}
		// Called by derived classes
		void SetMetaData(vector<CimFieldAttribute>& childMetaData)
		{
			IPS_ProvisioningAuditRecord::SetMetaData(childMetaData);
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
#endif // IPS_DALPROVISIONINGRECORD_H
