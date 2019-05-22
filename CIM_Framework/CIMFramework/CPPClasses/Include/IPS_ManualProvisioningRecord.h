//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       IPS_ManualProvisioningRecord.h
//
//  Contents:   The IPS_ManualProvisioningRecord provides information related to a single Intel(R) AMT provisioning occurrence that was performed using a manual provisioning operation.
//
//              This file was automatically generated from IPS_ManualProvisioningRecord.mof,  version: 6.1.0
//
//----------------------------------------------------------------------------
#ifndef IPS_MANUALPROVISIONINGRECORD_H
#define IPS_MANUALPROVISIONINGRECORD_H 1
#include "IPS_ProvisioningAuditRecord.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	// The IPS_ManualProvisioningRecord provides information related to a single Intel(R) AMT provisioning occurrence that was performed using a manual provisioning operation.
	class CIMFRAMEWORK_API IPS_ManualProvisioningRecord  : public IPS_ProvisioningAuditRecord
	{
	public:

		//Default constructor
		IPS_ManualProvisioningRecord()
			: IPS_ProvisioningAuditRecord(NULL, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				_classMetaData = IPS_ProvisioningAuditRecord::GetMetaData();
			}
		}

		//constructor which receives WSMan client
		IPS_ManualProvisioningRecord(ICimWsmanClient *client)
			: IPS_ProvisioningAuditRecord(client, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				_classMetaData = IPS_ProvisioningAuditRecord::GetMetaData();
			}
		}

		//Destructor
		virtual ~IPS_ManualProvisioningRecord(){}

		// The "type" information for the object. Gettors only.
		virtual const string& ResourceURI() const { return CLASS_URI; }
		static const string& ClassResourceURI() { return CLASS_URI; }
		virtual const string& XmlNamespace() const { return CLASS_NS; }
		virtual const string& XmlPrefix() const { return CLASS_NS_PREFIX; }
		virtual const string& ObjectType() const { return CLASS_NAME; }
		static const string& ClassObjectType() { return CLASS_NAME; }

		// Class representing IPS_ManualProvisioningRecord keys
		class CimKeys : public IPS_ProvisioningAuditRecord::CimKeys
		{
		public:
		};
		 // Function used by the factory
		static CimBase *CreateFromCimObject(const CimObject &object);

		static vector<shared_ptr<IPS_ManualProvisioningRecord> > Enumerate(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		// Overloaded delete which supplies the internal resourceURI
		static void Delete(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		using CimBase::Delete;

	protected:
		 // Protected constructor to be used by derived classes
		IPS_ManualProvisioningRecord(ICimWsmanClient *client, const string &class_name,
			const string &class_ns, const string &prefix, const string &uri): IPS_ProvisioningAuditRecord(client, class_name, class_ns, prefix, uri)
		{
			if(_classMetaData.size() == 0)
			{
				_classMetaData = IPS_ProvisioningAuditRecord::GetMetaData();
			}
		}
		 // Protected constructor which receives CimObject
		IPS_ManualProvisioningRecord(const CimObject &object)
			: IPS_ProvisioningAuditRecord(object)
		{
			if(_classMetaData.size() == 0)
			{
				_classMetaData = IPS_ProvisioningAuditRecord::GetMetaData();
			}
		}
		// Called by derived classes
		void SetMetaData(vector<CimFieldAttribute>& childMetaData)
		{
			IPS_ProvisioningAuditRecord::SetMetaData(childMetaData);
		}
		const vector<CimFieldAttribute> &GetMetaData() const;
	private:
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
#endif // IPS_MANUALPROVISIONINGRECORD_H
