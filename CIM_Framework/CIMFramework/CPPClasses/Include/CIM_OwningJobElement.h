//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_OwningJobElement.h
//
//  Contents:   OwningJobElement represents an association between a Job and the ManagedElement responsible for the creation of the Job. This association may not be possible, given that the execution of jobs can move between systems and that the lifecycle of the creating entity may not persist for the total duration of the job. However, this can be very useful information when available. This association defines a more specific 'owner' than is provided by the CIM_Job.Owner string.
//
//              This file was automatically generated from CIM_OwningJobElement.mof,  version: 2.7.0
//
//----------------------------------------------------------------------------
#ifndef CIM_OWNINGJOBELEMENT_H
#define CIM_OWNINGJOBELEMENT_H 1
#include "../../include/CimBase.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	// OwningJobElement represents an association between a Job and the ManagedElement responsible for the creation of the Job. This association may not be possible, given that the execution of jobs can move between systems and that the lifecycle of the creating entity may not persist for the total duration of the job. However, this can be very useful information when available. This association defines a more specific 'owner' than is provided by the CIM_Job.Owner string.
	class CIMFRAMEWORK_API CIM_OwningJobElement  : public CimBase
	{
	public:

		//Default constructor
		CIM_OwningJobElement()
			: CimBase(NULL, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CimBase::SetMetaData(_classMetaData, _metadata, 2);
			}
		}

		//constructor which receives WSMan client
		CIM_OwningJobElement(ICimWsmanClient *client)
			: CimBase(client, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CimBase::SetMetaData(_classMetaData, _metadata, 2);
			}
		}

		//Destructor
		virtual ~CIM_OwningJobElement(){}

		// The "type" information for the object. Gettors only.
		virtual const string& ResourceURI() const { return CLASS_URI; }
		static const string& ClassResourceURI() { return CLASS_URI; }
		virtual const string& XmlNamespace() const { return CLASS_NS; }
		virtual const string& XmlPrefix() const { return CLASS_NS_PREFIX; }
		virtual const string& ObjectType() const { return CLASS_NAME; }
		static const string& ClassObjectType() { return CLASS_NAME; }

		// Class representing CIM_OwningJobElement keys
		class CimKeys : public CimBase::CimKeys
		{
		public:
			// Key, Required, The ManagedElement responsible for the creation of the Job.
			const CimReference OwningElement() const
			{
				CimReference ret;
				TypeConverter::StringToType(GetKey("OwningElement"), ret);
				return ret;
			}

			// Key, Required, The ManagedElement responsible for the creation of the Job.
			void OwningElement(const CimReference &value)
			{
				SetOrAddKey("OwningElement", TypeConverter::TypeToString(value), true);
			}

			// Key, Required, The Job created by the ManagedElement.
			const CimReference OwnedElement() const
			{
				CimReference ret;
				TypeConverter::StringToType(GetKey("OwnedElement"), ret);
				return ret;
			}

			// Key, Required, The Job created by the ManagedElement.
			void OwnedElement(const CimReference &value)
			{
				SetOrAddKey("OwnedElement", TypeConverter::TypeToString(value), true);
			}

		};

		// class fields declarations

		// Key, Required, The ManagedElement responsible for the creation of the Job.
		const CimReference OwningElement() const;

		// Key, Required, The ManagedElement responsible for the creation of the Job.
		void OwningElement(const CimReference &value); 


		// Key, Required, The Job created by the ManagedElement.
		const CimReference OwnedElement() const;

		// Key, Required, The Job created by the ManagedElement.
		void OwnedElement(const CimReference &value); 


		 // Function used by the factory
		static CimBase *CreateFromCimObject(const CimObject &object);

		static vector<shared_ptr<CIM_OwningJobElement> > Enumerate(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		// Overloaded delete which supplies the internal resourceURI
		static void Delete(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		using CimBase::Delete;

	protected:
		 // Protected constructor to be used by derived classes
		CIM_OwningJobElement(ICimWsmanClient *client, const string &class_name,
			const string &class_ns, const string &prefix, const string &uri): CimBase(client, class_name, class_ns, prefix, uri)
		{
			if(_classMetaData.size() == 0)
			{
				CimBase::SetMetaData(_classMetaData, _metadata, 2);
			}
		}
		 // Protected constructor which receives CimObject
		CIM_OwningJobElement(const CimObject &object)
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
#endif // CIM_OWNINGJOBELEMENT_H
