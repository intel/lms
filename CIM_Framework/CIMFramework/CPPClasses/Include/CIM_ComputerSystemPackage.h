//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_ComputerSystemPackage.h
//
//  Contents:   Similar to the way that LogicalDevices are 'Realized' by PhysicalElements, ComputerSystem may be realized realized in one or more PhysicalPackages. The ComputerSystemPackage association explicitly defines this relationship.
//
//              This file was automatically generated from CIM_ComputerSystemPackage.mof,  version: 2.13.0
//
//----------------------------------------------------------------------------
#ifndef CIM_COMPUTERSYSTEMPACKAGE_H
#define CIM_COMPUTERSYSTEMPACKAGE_H 1
#include "CIM_SystemPackaging.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	// Similar to the way that LogicalDevices are 'Realized' by PhysicalElements, ComputerSystem may be realized realized in one or more PhysicalPackages. The ComputerSystemPackage association explicitly defines this relationship.
	class CIMFRAMEWORK_API CIM_ComputerSystemPackage  : public CIM_SystemPackaging
	{
	public:

		//Default constructor
		CIM_ComputerSystemPackage()
			: CIM_SystemPackaging(NULL, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_SystemPackaging::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 3);
			}
		}

		//constructor which receives WSMan client
		CIM_ComputerSystemPackage(ICimWsmanClient *client)
			: CIM_SystemPackaging(client, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_SystemPackaging::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 3);
			}
		}

		//Destructor
		virtual ~CIM_ComputerSystemPackage(){}

		// The "type" information for the object. Gettors only.
		virtual const string& ResourceURI() const { return CLASS_URI; }
		static const string& ClassResourceURI() { return CLASS_URI; }
		virtual const string& XmlNamespace() const { return CLASS_NS; }
		virtual const string& XmlPrefix() const { return CLASS_NS_PREFIX; }
		virtual const string& ObjectType() const { return CLASS_NAME; }
		static const string& ClassObjectType() { return CLASS_NAME; }

		// Class representing CIM_ComputerSystemPackage keys
		class CimKeys : public CIM_SystemPackaging::CimKeys
		{
		public:
			// Required, The PhysicalPackage(s) that realize a Unitary ComputerSystem.
			const CimReference Antecedent() const
			{
				CimReference ret;
				TypeConverter::StringToType(GetKey("Antecedent"), ret);
				return ret;
			}

			// Required, The PhysicalPackage(s) that realize a Unitary ComputerSystem.
			void Antecedent(const CimReference &value)
			{
				SetOrAddKey("Antecedent", TypeConverter::TypeToString(value), true);
			}

			// Required, The UnitaryComputerSystem.
			const CimReference Dependent() const
			{
				CimReference ret;
				TypeConverter::StringToType(GetKey("Dependent"), ret);
				return ret;
			}

			// Required, The UnitaryComputerSystem.
			void Dependent(const CimReference &value)
			{
				SetOrAddKey("Dependent", TypeConverter::TypeToString(value), true);
			}

		};

		// class fields declarations

		// Optional, A Gloabally Unique Identifier for the System's Package.
		const string PlatformGUID() const;

		// Optional, A Gloabally Unique Identifier for the System's Package.
		void PlatformGUID(const string &value); 

		// Is true if the field PlatformGUID exists in the current object, otherwise is false.
		bool PlatformGUIDExists() const;

		// Remove PlatformGUID field.
		void RemovePlatformGUID(); 

		 // Function used by the factory
		static CimBase *CreateFromCimObject(const CimObject &object);

		static vector<shared_ptr<CIM_ComputerSystemPackage> > Enumerate(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		// Overloaded delete which supplies the internal resourceURI
		static void Delete(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		using CimBase::Delete;

	protected:
		 // Protected constructor to be used by derived classes
		CIM_ComputerSystemPackage(ICimWsmanClient *client, const string &class_name,
			const string &class_ns, const string &prefix, const string &uri): CIM_SystemPackaging(client, class_name, class_ns, prefix, uri)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_SystemPackaging::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 3);
			}
		}
		 // Protected constructor which receives CimObject
		CIM_ComputerSystemPackage(const CimObject &object)
			: CIM_SystemPackaging(object)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_SystemPackaging::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 3);
			}
		}
		// Called by derived classes
		void SetMetaData(vector<CimFieldAttribute>& childMetaData)
		{
			CIM_SystemPackaging::SetMetaData(childMetaData);
			CimBase::SetMetaData(childMetaData, _metadata, 3);
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
#endif // CIM_COMPUTERSYSTEMPACKAGE_H
