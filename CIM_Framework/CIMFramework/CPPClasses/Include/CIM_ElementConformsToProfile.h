//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_ElementConformsToProfile.h
//
//  Contents:   The CIM_ElementConformsToProfile association defines the RegisteredProfiles to which the referenced ManagedElement is conformant. Note: This association may apply to any Managed Element. Typical usage will apply it to a higher level instance, such as a System, NameSpace, or Service. When applied to a higher level instance, all constituent parts MUST behave appropriately in support of the ManagedElement's conformance to the named RegisteredProfile.
//
//              This file was automatically generated from CIM_ElementConformsToProfile.mof,  version: 2.8.0
//
//----------------------------------------------------------------------------
#ifndef CIM_ELEMENTCONFORMSTOPROFILE_H
#define CIM_ELEMENTCONFORMSTOPROFILE_H 1
#include "../../include/CimBase.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	// The CIM_ElementConformsToProfile association defines the RegisteredProfiles to which the referenced ManagedElement is conformant. Note: This association may apply to any Managed Element. Typical usage will apply it to a higher level instance, such as a System, NameSpace, or Service. When applied to a higher level instance, all constituent parts MUST behave appropriately in support of the ManagedElement's conformance to the named RegisteredProfile.
	class CIMFRAMEWORK_API CIM_ElementConformsToProfile  : public CimBase
	{
	public:

		//Default constructor
		CIM_ElementConformsToProfile()
			: CimBase(NULL, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CimBase::SetMetaData(_classMetaData, _metadata, 2);
			}
		}

		//constructor which receives WSMan client
		CIM_ElementConformsToProfile(ICimWsmanClient *client)
			: CimBase(client, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CimBase::SetMetaData(_classMetaData, _metadata, 2);
			}
		}

		//Destructor
		virtual ~CIM_ElementConformsToProfile(){}

		// The "type" information for the object. Gettors only.
		virtual const string& ResourceURI() const { return CLASS_URI; }
		static const string& ClassResourceURI() { return CLASS_URI; }
		virtual const string& XmlNamespace() const { return CLASS_NS; }
		virtual const string& XmlPrefix() const { return CLASS_NS_PREFIX; }
		virtual const string& ObjectType() const { return CLASS_NAME; }
		static const string& ClassObjectType() { return CLASS_NAME; }

		// Class representing CIM_ElementConformsToProfile keys
		class CimKeys : public CimBase::CimKeys
		{
		public:
			// Key, Required, The RegisteredProfile to which the ManagedElement conforms.
			const CimReference ConformantStandard() const
			{
				CimReference ret;
				TypeConverter::StringToType(GetKey("ConformantStandard"), ret);
				return ret;
			}

			// Key, Required, The RegisteredProfile to which the ManagedElement conforms.
			void ConformantStandard(const CimReference &value)
			{
				SetOrAddKey("ConformantStandard", TypeConverter::TypeToString(value), true);
			}

			// Key, Required, The ManagedElement that conforms to the RegisteredProfile.
			const CimReference ManagedElement() const
			{
				CimReference ret;
				TypeConverter::StringToType(GetKey("ManagedElement"), ret);
				return ret;
			}

			// Key, Required, The ManagedElement that conforms to the RegisteredProfile.
			void ManagedElement(const CimReference &value)
			{
				SetOrAddKey("ManagedElement", TypeConverter::TypeToString(value), true);
			}

		};

		// class fields declarations

		// Key, Required, The RegisteredProfile to which the ManagedElement conforms.
		const CimReference ConformantStandard() const;

		// Key, Required, The RegisteredProfile to which the ManagedElement conforms.
		void ConformantStandard(const CimReference &value); 


		// Key, Required, The ManagedElement that conforms to the RegisteredProfile.
		const CimReference ManagedElement() const;

		// Key, Required, The ManagedElement that conforms to the RegisteredProfile.
		void ManagedElement(const CimReference &value); 


		 // Function used by the factory
		static CimBase *CreateFromCimObject(const CimObject &object);

		static vector<shared_ptr<CIM_ElementConformsToProfile> > Enumerate(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		// Overloaded delete which supplies the internal resourceURI
		static void Delete(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		using CimBase::Delete;

	protected:
		 // Protected constructor to be used by derived classes
		CIM_ElementConformsToProfile(ICimWsmanClient *client, const string &class_name,
			const string &class_ns, const string &prefix, const string &uri): CimBase(client, class_name, class_ns, prefix, uri)
		{
			if(_classMetaData.size() == 0)
			{
				CimBase::SetMetaData(_classMetaData, _metadata, 2);
			}
		}
		 // Protected constructor which receives CimObject
		CIM_ElementConformsToProfile(const CimObject &object)
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
#endif // CIM_ELEMENTCONFORMSTOPROFILE_H
