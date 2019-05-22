//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_SystemDevice.h
//
//  Contents:   LogicalDevices can be aggregated by a System. This relationship is made explicit by the SystemDevice association.
//
//              This file was automatically generated from CIM_SystemDevice.mof,  version: 2.10.0
//
//----------------------------------------------------------------------------
#ifndef CIM_SYSTEMDEVICE_H
#define CIM_SYSTEMDEVICE_H 1
#include "CIM_SystemComponent.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	// LogicalDevices can be aggregated by a System. This relationship is made explicit by the SystemDevice association.
	class CIMFRAMEWORK_API CIM_SystemDevice  : public CIM_SystemComponent
	{
	public:

		//Default constructor
		CIM_SystemDevice()
			: CIM_SystemComponent(NULL, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_SystemComponent::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 2);
			}
		}

		//constructor which receives WSMan client
		CIM_SystemDevice(ICimWsmanClient *client)
			: CIM_SystemComponent(client, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_SystemComponent::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 2);
			}
		}

		//Destructor
		virtual ~CIM_SystemDevice(){}

		// The "type" information for the object. Gettors only.
		virtual const string& ResourceURI() const { return CLASS_URI; }
		static const string& ClassResourceURI() { return CLASS_URI; }
		virtual const string& XmlNamespace() const { return CLASS_NS; }
		virtual const string& XmlPrefix() const { return CLASS_NS_PREFIX; }
		virtual const string& ObjectType() const { return CLASS_NAME; }
		static const string& ClassObjectType() { return CLASS_NAME; }

		// Class representing CIM_SystemDevice keys
		class CimKeys : public CIM_SystemComponent::CimKeys
		{
		public:
			// Required, The parent system in the Association.
			const CimReference GroupComponent() const
			{
				CimReference ret;
				TypeConverter::StringToType(GetKey("GroupComponent"), ret);
				return ret;
			}

			// Required, The parent system in the Association.
			void GroupComponent(const CimReference &value)
			{
				SetOrAddKey("GroupComponent", TypeConverter::TypeToString(value), true);
			}

			// Required, The LogicalDevice that is a component of a System.
			const CimReference PartComponent() const
			{
				CimReference ret;
				TypeConverter::StringToType(GetKey("PartComponent"), ret);
				return ret;
			}

			// Required, The LogicalDevice that is a component of a System.
			void PartComponent(const CimReference &value)
			{
				SetOrAddKey("PartComponent", TypeConverter::TypeToString(value), true);
			}

		};
		 // Function used by the factory
		static CimBase *CreateFromCimObject(const CimObject &object);

		static vector<shared_ptr<CIM_SystemDevice> > Enumerate(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		// Overloaded delete which supplies the internal resourceURI
		static void Delete(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		using CimBase::Delete;

	protected:
		 // Protected constructor to be used by derived classes
		CIM_SystemDevice(ICimWsmanClient *client, const string &class_name,
			const string &class_ns, const string &prefix, const string &uri): CIM_SystemComponent(client, class_name, class_ns, prefix, uri)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_SystemComponent::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 2);
			}
		}
		 // Protected constructor which receives CimObject
		CIM_SystemDevice(const CimObject &object)
			: CIM_SystemComponent(object)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_SystemComponent::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 2);
			}
		}
		// Called by derived classes
		void SetMetaData(vector<CimFieldAttribute>& childMetaData)
		{
			CIM_SystemComponent::SetMetaData(childMetaData);
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
#endif // CIM_SYSTEMDEVICE_H
