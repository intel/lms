//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       AMT_TrapTargetForService.h
//
//  Contents:   TrapTargetForService specifies the endpoint to which traps events are sent by the alerting service.
//
//              This file was automatically generated from AMT_TrapTargetForService.mof,  version: 3.0.0
//
//----------------------------------------------------------------------------
#ifndef AMT_TRAPTARGETFORSERVICE_H
#define AMT_TRAPTARGETFORSERVICE_H 1
#include "CIM_ServiceSAPDependency.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	// TrapTargetForService specifies the endpoint to which traps events are sent by the alerting service.
	class CIMFRAMEWORK_API AMT_TrapTargetForService  : public CIM_ServiceSAPDependency
	{
	public:

		//Default constructor
		AMT_TrapTargetForService()
			: CIM_ServiceSAPDependency(NULL, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_ServiceSAPDependency::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 2);
			}
		}

		//constructor which receives WSMan client
		AMT_TrapTargetForService(ICimWsmanClient *client)
			: CIM_ServiceSAPDependency(client, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_ServiceSAPDependency::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 2);
			}
		}

		//Destructor
		virtual ~AMT_TrapTargetForService(){}

		// The "type" information for the object. Gettors only.
		virtual const string& ResourceURI() const { return CLASS_URI; }
		static const string& ClassResourceURI() { return CLASS_URI; }
		virtual const string& XmlNamespace() const { return CLASS_NS; }
		virtual const string& XmlPrefix() const { return CLASS_NS_PREFIX; }
		virtual const string& ObjectType() const { return CLASS_NAME; }
		static const string& ClassObjectType() { return CLASS_NAME; }

		// Class representing AMT_TrapTargetForService keys
		class CimKeys : public CIM_ServiceSAPDependency::CimKeys
		{
		public:
			// Required, The endpoint which gets the trap.
			const CimReference Antecedent() const
			{
				CimReference ret;
				TypeConverter::StringToType(GetKey("Antecedent"), ret);
				return ret;
			}

			// Required, The endpoint which gets the trap.
			void Antecedent(const CimReference &value)
			{
				SetOrAddKey("Antecedent", TypeConverter::TypeToString(value), true);
			}

			// Required, The SNMP service that sends the notifications.
			const CimReference Dependent() const
			{
				CimReference ret;
				TypeConverter::StringToType(GetKey("Dependent"), ret);
				return ret;
			}

			// Required, The SNMP service that sends the notifications.
			void Dependent(const CimReference &value)
			{
				SetOrAddKey("Dependent", TypeConverter::TypeToString(value), true);
			}

		};
		 // Function used by the factory
		static CimBase *CreateFromCimObject(const CimObject &object);

		static vector<shared_ptr<AMT_TrapTargetForService> > Enumerate(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		// Overloaded delete which supplies the internal resourceURI
		static void Delete(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		using CimBase::Delete;

	protected:
		 // Protected constructor to be used by derived classes
		AMT_TrapTargetForService(ICimWsmanClient *client, const string &class_name,
			const string &class_ns, const string &prefix, const string &uri): CIM_ServiceSAPDependency(client, class_name, class_ns, prefix, uri)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_ServiceSAPDependency::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 2);
			}
		}
		 // Protected constructor which receives CimObject
		AMT_TrapTargetForService(const CimObject &object)
			: CIM_ServiceSAPDependency(object)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_ServiceSAPDependency::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 2);
			}
		}
		// Called by derived classes
		void SetMetaData(vector<CimFieldAttribute>& childMetaData)
		{
			CIM_ServiceSAPDependency::SetMetaData(childMetaData);
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
#endif // AMT_TRAPTARGETFORSERVICE_H
