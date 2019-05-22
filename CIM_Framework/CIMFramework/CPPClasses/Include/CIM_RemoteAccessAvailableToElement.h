//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_RemoteAccessAvailableToElement.h
//
//  Contents:   Describes an element's knowledge regarding accessing other (i.e., remote) Servers and Systems.
//
//              This file was automatically generated from CIM_RemoteAccessAvailableToElement.mof,  version: 2.19.0
//
//----------------------------------------------------------------------------
#ifndef CIM_REMOTEACCESSAVAILABLETOELEMENT_H
#define CIM_REMOTEACCESSAVAILABLETOELEMENT_H 1
#include "CIM_Dependency.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	// Describes an element's knowledge regarding accessing other (i.e., remote) Servers and Systems.
	class CIMFRAMEWORK_API CIM_RemoteAccessAvailableToElement  : public CIM_Dependency
	{
	public:

		//Default constructor
		CIM_RemoteAccessAvailableToElement()
			: CIM_Dependency(NULL, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_Dependency::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 4);
			}
		}

		//constructor which receives WSMan client
		CIM_RemoteAccessAvailableToElement(ICimWsmanClient *client)
			: CIM_Dependency(client, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_Dependency::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 4);
			}
		}

		//Destructor
		virtual ~CIM_RemoteAccessAvailableToElement(){}

		// The "type" information for the object. Gettors only.
		virtual const string& ResourceURI() const { return CLASS_URI; }
		static const string& ClassResourceURI() { return CLASS_URI; }
		virtual const string& XmlNamespace() const { return CLASS_NS; }
		virtual const string& XmlPrefix() const { return CLASS_NS_PREFIX; }
		virtual const string& ObjectType() const { return CLASS_NAME; }
		static const string& ClassObjectType() { return CLASS_NAME; }

		// Class representing CIM_RemoteAccessAvailableToElement keys
		class CimKeys : public CIM_Dependency::CimKeys
		{
		public:
			// Required, The remote server or system.
			const CimReference Antecedent() const
			{
				CimReference ret;
				TypeConverter::StringToType(GetKey("Antecedent"), ret);
				return ret;
			}

			// Required, The remote server or system.
			void Antecedent(const CimReference &value)
			{
				SetOrAddKey("Antecedent", TypeConverter::TypeToString(value), true);
			}

			// Required, The EnabledLogicalElement which has knowledge of the remote server or system.
			const CimReference Dependent() const
			{
				CimReference ret;
				TypeConverter::StringToType(GetKey("Dependent"), ret);
				return ret;
			}

			// Required, The EnabledLogicalElement which has knowledge of the remote server or system.
			void Dependent(const CimReference &value)
			{
				SetOrAddKey("Dependent", TypeConverter::TypeToString(value), true);
			}

		};

		// class fields declarations

		// Optional, Indicates that this access information is defined as a default configuration for the system.
		const bool IsDefault() const;

		// Optional, Indicates that this access information is defined as a default configuration for the system.
		void IsDefault(const bool value); 

		// Is true if the field IsDefault exists in the current object, otherwise is false.
		bool IsDefaultExists() const;

		// Remove IsDefault field.
		void RemoveIsDefault(); 

		// Optional, When an element is accessing remote services and systems, it MAY be necessary to order those accesses. This property defines that ordering - where lower numbers indicate a higher priority for access. A value of 0 (default) indicates that ordering does not apply. If multiple RemoteAccessPoint instances have the same value for OrderOfAccess, then these AccessPoints MAY be used in any sequence defined by the implementation.
		const unsigned short OrderOfAccess() const;

		// Optional, When an element is accessing remote services and systems, it MAY be necessary to order those accesses. This property defines that ordering - where lower numbers indicate a higher priority for access. A value of 0 (default) indicates that ordering does not apply. If multiple RemoteAccessPoint instances have the same value for OrderOfAccess, then these AccessPoints MAY be used in any sequence defined by the implementation.
		void OrderOfAccess(const unsigned short value); 

		// Is true if the field OrderOfAccess exists in the current object, otherwise is false.
		bool OrderOfAccessExists() const;

		// Remove OrderOfAccess field.
		void RemoveOrderOfAccess(); 

		 // Function used by the factory
		static CimBase *CreateFromCimObject(const CimObject &object);

		static vector<shared_ptr<CIM_RemoteAccessAvailableToElement> > Enumerate(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		// Overloaded delete which supplies the internal resourceURI
		static void Delete(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		using CimBase::Delete;

	protected:
		 // Protected constructor to be used by derived classes
		CIM_RemoteAccessAvailableToElement(ICimWsmanClient *client, const string &class_name,
			const string &class_ns, const string &prefix, const string &uri): CIM_Dependency(client, class_name, class_ns, prefix, uri)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_Dependency::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 4);
			}
		}
		 // Protected constructor which receives CimObject
		CIM_RemoteAccessAvailableToElement(const CimObject &object)
			: CIM_Dependency(object)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_Dependency::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 4);
			}
		}
		// Called by derived classes
		void SetMetaData(vector<CimFieldAttribute>& childMetaData)
		{
			CIM_Dependency::SetMetaData(childMetaData);
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
#endif // CIM_REMOTEACCESSAVAILABLETOELEMENT_H
