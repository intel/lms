//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       IPS_ProvisioningAuditRecord.h
//
//  Contents:   The IPS_ProvisioningAuditRecord provides information related to a single Intel (R) AMT provisioning occurrence
//
//              This file was automatically generated from IPS_ProvisioningAuditRecord.mof,  version: 6.1.0
//
//----------------------------------------------------------------------------
#ifndef IPS_PROVISIONINGAUDITRECORD_H
#define IPS_PROVISIONINGAUDITRECORD_H 1
#include "CIM_LogEntry.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	// The IPS_ProvisioningAuditRecord provides information related to a single Intel (R) AMT provisioning occurrence
	class CIMFRAMEWORK_API IPS_ProvisioningAuditRecord  : public CIM_LogEntry
	{
	public:

		//Default constructor
		IPS_ProvisioningAuditRecord()
			: CIM_LogEntry(NULL, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_LogEntry::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 1);
			}
		}

		//constructor which receives WSMan client
		IPS_ProvisioningAuditRecord(ICimWsmanClient *client)
			: CIM_LogEntry(client, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_LogEntry::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 1);
			}
		}

		//Destructor
		virtual ~IPS_ProvisioningAuditRecord(){}

		// The "type" information for the object. Gettors only.
		virtual const string& ResourceURI() const { return CLASS_URI; }
		static const string& ClassResourceURI() { return CLASS_URI; }
		virtual const string& XmlNamespace() const { return CLASS_NS; }
		virtual const string& XmlPrefix() const { return CLASS_NS_PREFIX; }
		virtual const string& ObjectType() const { return CLASS_NAME; }
		static const string& ClassObjectType() { return CLASS_NAME; }

		// Class representing IPS_ProvisioningAuditRecord keys
		class CimKeys : public CIM_LogEntry::CimKeys
		{
		public:
		};
		 // Function used by the factory
		static CimBase *CreateFromCimObject(const CimObject &object);

		static vector<shared_ptr<IPS_ProvisioningAuditRecord> > Enumerate(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		// Overloaded delete which supplies the internal resourceURI
		static void Delete(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		using CimBase::Delete;

	protected:
		 // Protected constructor to be used by derived classes
		IPS_ProvisioningAuditRecord(ICimWsmanClient *client, const string &class_name,
			const string &class_ns, const string &prefix, const string &uri): CIM_LogEntry(client, class_name, class_ns, prefix, uri)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_LogEntry::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 1);
			}
		}
		 // Protected constructor which receives CimObject
		IPS_ProvisioningAuditRecord(const CimObject &object)
			: CIM_LogEntry(object)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_LogEntry::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 1);
			}
		}
		// Called by derived classes
		void SetMetaData(vector<CimFieldAttribute>& childMetaData)
		{
			CIM_LogEntry::SetMetaData(childMetaData);
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
#endif // IPS_PROVISIONINGAUDITRECORD_H
