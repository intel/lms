//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_RoleLimitedToTarget.h
//
//  Contents:   The Role object class is used to represent a position or set of responsibilities within an organization, organizational unit or other scope. When explicitly restricting the target elements that may be accessed from this Role, this association MUST be used.
//
//              This file was automatically generated from CIM_RoleLimitedToTarget.mof,  version: 2.20.0
//
//----------------------------------------------------------------------------
#ifndef CIM_ROLELIMITEDTOTARGET_H
#define CIM_ROLELIMITEDTOTARGET_H 1
#include "../../include/CimBase.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	// The Role object class is used to represent a position or set of responsibilities within an organization, organizational unit or other scope. When explicitly restricting the target elements that may be accessed from this Role, this association MUST be used.
	class CIMFRAMEWORK_API CIM_RoleLimitedToTarget  : public CimBase
	{
	public:

		//Default constructor
		CIM_RoleLimitedToTarget()
			: CimBase(NULL, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CimBase::SetMetaData(_classMetaData, _metadata, 2);
			}
		}

		//constructor which receives WSMan client
		CIM_RoleLimitedToTarget(ICimWsmanClient *client)
			: CimBase(client, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CimBase::SetMetaData(_classMetaData, _metadata, 2);
			}
		}

		//Destructor
		virtual ~CIM_RoleLimitedToTarget(){}

		// The "type" information for the object. Gettors only.
		virtual const string& ResourceURI() const { return CLASS_URI; }
		static const string& ClassResourceURI() { return CLASS_URI; }
		virtual const string& XmlNamespace() const { return CLASS_NS; }
		virtual const string& XmlPrefix() const { return CLASS_NS_PREFIX; }
		virtual const string& ObjectType() const { return CLASS_NAME; }
		static const string& ClassObjectType() { return CLASS_NAME; }

		// Class representing CIM_RoleLimitedToTarget keys
		class CimKeys : public CimBase::CimKeys
		{
		public:
			// Key, Required, The Role whose target set is explicitly defined.
			const CimReference DefiningRole() const
			{
				CimReference ret;
				TypeConverter::StringToType(GetKey("DefiningRole"), ret);
				return ret;
			}

			// Key, Required, The Role whose target set is explicitly defined.
			void DefiningRole(const CimReference &value)
			{
				SetOrAddKey("DefiningRole", TypeConverter::TypeToString(value), true);
			}

			// Key, Required, Reference to the target set that can be accessed from the Role.
			const CimReference TargetElement() const
			{
				CimReference ret;
				TypeConverter::StringToType(GetKey("TargetElement"), ret);
				return ret;
			}

			// Key, Required, Reference to the target set that can be accessed from the Role.
			void TargetElement(const CimReference &value)
			{
				SetOrAddKey("TargetElement", TypeConverter::TypeToString(value), true);
			}

		};

		// class fields declarations

		// Key, Required, The Role whose target set is explicitly defined.
		const CimReference DefiningRole() const;

		// Key, Required, The Role whose target set is explicitly defined.
		void DefiningRole(const CimReference &value); 


		// Key, Required, Reference to the target set that can be accessed from the Role.
		const CimReference TargetElement() const;

		// Key, Required, Reference to the target set that can be accessed from the Role.
		void TargetElement(const CimReference &value); 


		 // Function used by the factory
		static CimBase *CreateFromCimObject(const CimObject &object);

		static vector<shared_ptr<CIM_RoleLimitedToTarget> > Enumerate(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		// Overloaded delete which supplies the internal resourceURI
		static void Delete(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		using CimBase::Delete;

	protected:
		 // Protected constructor to be used by derived classes
		CIM_RoleLimitedToTarget(ICimWsmanClient *client, const string &class_name,
			const string &class_ns, const string &prefix, const string &uri): CimBase(client, class_name, class_ns, prefix, uri)
		{
			if(_classMetaData.size() == 0)
			{
				CimBase::SetMetaData(_classMetaData, _metadata, 2);
			}
		}
		 // Protected constructor which receives CimObject
		CIM_RoleLimitedToTarget(const CimObject &object)
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
#endif // CIM_ROLELIMITEDTOTARGET_H
