//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_InstalledSoftwareIdentity.h
//
//  Contents:   The InstalledSoftwareIdentity association identifies the System on which a SoftwareIdentity is installed. This class is a corollary to InstalledSoftwareElement, but deals with the asset aspects of software (as indicated by SoftwareIdentity), versus the deployment aspects (as indicated by SoftwareElement).
//
//              This file was automatically generated from CIM_InstalledSoftwareIdentity.mof,  version: 2.8.0
//
//----------------------------------------------------------------------------
#ifndef CIM_INSTALLEDSOFTWAREIDENTITY_H
#define CIM_INSTALLEDSOFTWAREIDENTITY_H 1
#include "../../include/CimBase.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	// The InstalledSoftwareIdentity association identifies the System on which a SoftwareIdentity is installed. This class is a corollary to InstalledSoftwareElement, but deals with the asset aspects of software (as indicated by SoftwareIdentity), versus the deployment aspects (as indicated by SoftwareElement).
	class CIMFRAMEWORK_API CIM_InstalledSoftwareIdentity  : public CimBase
	{
	public:

		//Default constructor
		CIM_InstalledSoftwareIdentity()
			: CimBase(NULL, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CimBase::SetMetaData(_classMetaData, _metadata, 2);
			}
		}

		//constructor which receives WSMan client
		CIM_InstalledSoftwareIdentity(ICimWsmanClient *client)
			: CimBase(client, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CimBase::SetMetaData(_classMetaData, _metadata, 2);
			}
		}

		//Destructor
		virtual ~CIM_InstalledSoftwareIdentity(){}

		// The "type" information for the object. Gettors only.
		virtual const string& ResourceURI() const { return CLASS_URI; }
		static const string& ClassResourceURI() { return CLASS_URI; }
		virtual const string& XmlNamespace() const { return CLASS_NS; }
		virtual const string& XmlPrefix() const { return CLASS_NS_PREFIX; }
		virtual const string& ObjectType() const { return CLASS_NAME; }
		static const string& ClassObjectType() { return CLASS_NAME; }

		// Class representing CIM_InstalledSoftwareIdentity keys
		class CimKeys : public CimBase::CimKeys
		{
		public:
			// Key, Required, The system on which the software is installed.
			const CimReference System() const
			{
				CimReference ret;
				TypeConverter::StringToType(GetKey("System"), ret);
				return ret;
			}

			// Key, Required, The system on which the software is installed.
			void System(const CimReference &value)
			{
				SetOrAddKey("System", TypeConverter::TypeToString(value), true);
			}

			// Key, Required, The SoftwareIdentity that is installed.
			const CimReference InstalledSoftware() const
			{
				CimReference ret;
				TypeConverter::StringToType(GetKey("InstalledSoftware"), ret);
				return ret;
			}

			// Key, Required, The SoftwareIdentity that is installed.
			void InstalledSoftware(const CimReference &value)
			{
				SetOrAddKey("InstalledSoftware", TypeConverter::TypeToString(value), true);
			}

		};

		// class fields declarations

		// Key, Required, The system on which the software is installed.
		const CimReference System() const;

		// Key, Required, The system on which the software is installed.
		void System(const CimReference &value); 


		// Key, Required, The SoftwareIdentity that is installed.
		const CimReference InstalledSoftware() const;

		// Key, Required, The SoftwareIdentity that is installed.
		void InstalledSoftware(const CimReference &value); 


		 // Function used by the factory
		static CimBase *CreateFromCimObject(const CimObject &object);

		static vector<shared_ptr<CIM_InstalledSoftwareIdentity> > Enumerate(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		// Overloaded delete which supplies the internal resourceURI
		static void Delete(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		using CimBase::Delete;

	protected:
		 // Protected constructor to be used by derived classes
		CIM_InstalledSoftwareIdentity(ICimWsmanClient *client, const string &class_name,
			const string &class_ns, const string &prefix, const string &uri): CimBase(client, class_name, class_ns, prefix, uri)
		{
			if(_classMetaData.size() == 0)
			{
				CimBase::SetMetaData(_classMetaData, _metadata, 2);
			}
		}
		 // Protected constructor which receives CimObject
		CIM_InstalledSoftwareIdentity(const CimObject &object)
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
#endif // CIM_INSTALLEDSOFTWAREIDENTITY_H
