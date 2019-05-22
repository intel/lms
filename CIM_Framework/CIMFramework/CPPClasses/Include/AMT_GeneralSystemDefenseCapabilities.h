//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       AMT_GeneralSystemDefenseCapabilities.h
//
//  Contents:   Describes the system capabilities of the System Defense feature. These capabilities are independent of all network interfaces.
//
//              This file was automatically generated from AMT_GeneralSystemDefenseCapabilities.mof,  version: 6.0.0
//
//----------------------------------------------------------------------------
#ifndef AMT_GENERALSYSTEMDEFENSECAPABILITIES_H
#define AMT_GENERALSYSTEMDEFENSECAPABILITIES_H 1
#include "CIM_Capabilities.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	// Describes the system capabilities of the System Defense feature. These capabilities are independent of all network interfaces.
	class CIMFRAMEWORK_API AMT_GeneralSystemDefenseCapabilities  : public CIM_Capabilities
	{
	public:

		//Default constructor
		AMT_GeneralSystemDefenseCapabilities()
			: CIM_Capabilities(NULL, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_Capabilities::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 3);
			}
		}

		//constructor which receives WSMan client
		AMT_GeneralSystemDefenseCapabilities(ICimWsmanClient *client)
			: CIM_Capabilities(client, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_Capabilities::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 3);
			}
		}

		//Destructor
		virtual ~AMT_GeneralSystemDefenseCapabilities(){}

		// The "type" information for the object. Gettors only.
		virtual const string& ResourceURI() const { return CLASS_URI; }
		static const string& ClassResourceURI() { return CLASS_URI; }
		virtual const string& XmlNamespace() const { return CLASS_NS; }
		virtual const string& XmlPrefix() const { return CLASS_NS_PREFIX; }
		virtual const string& ObjectType() const { return CLASS_NAME; }
		static const string& ClassObjectType() { return CLASS_NAME; }

		// Class representing AMT_GeneralSystemDefenseCapabilities keys
		class CimKeys : public CIM_Capabilities::CimKeys
		{
		public:
			// Key, Required, Opaquely and uniquely identifies an instance of this class.
			const string InstanceID() const
			{
				return GetKey("InstanceID");
			}

			// Key, Required, Opaquely and uniquely identifies an instance of this class.
			void InstanceID(const string &value)
			{
				SetOrAddKey("InstanceID", value);
			}

		};

		// class fields declarations

		// Optional, Specifies the maximum number of supported policies allocated by the Intel(R) AMT device.
		const unsigned int GlobalMaxSupportedPolicies() const;

		// Optional, Specifies the maximum number of supported policies allocated by the Intel(R) AMT device.
		void GlobalMaxSupportedPolicies(const unsigned int value); 

		// Is true if the field GlobalMaxSupportedPolicies exists in the current object, otherwise is false.
		bool GlobalMaxSupportedPoliciesExists() const;

		// Remove GlobalMaxSupportedPolicies field.
		void RemoveGlobalMaxSupportedPolicies(); 

		// Optional, Specifies the maximum number of supported filters allocated by the Intel(R) AMT device.
		const unsigned int GlobalMaxSupportedFilters() const;

		// Optional, Specifies the maximum number of supported filters allocated by the Intel(R) AMT device.
		void GlobalMaxSupportedFilters(const unsigned int value); 

		// Is true if the field GlobalMaxSupportedFilters exists in the current object, otherwise is false.
		bool GlobalMaxSupportedFiltersExists() const;

		// Remove GlobalMaxSupportedFilters field.
		void RemoveGlobalMaxSupportedFilters(); 

		 // Function used by the factory
		static CimBase *CreateFromCimObject(const CimObject &object);

		static vector<shared_ptr<AMT_GeneralSystemDefenseCapabilities> > Enumerate(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		// Overloaded delete which supplies the internal resourceURI
		static void Delete(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		using CimBase::Delete;

	protected:
		 // Protected constructor to be used by derived classes
		AMT_GeneralSystemDefenseCapabilities(ICimWsmanClient *client, const string &class_name,
			const string &class_ns, const string &prefix, const string &uri): CIM_Capabilities(client, class_name, class_ns, prefix, uri)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_Capabilities::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 3);
			}
		}
		 // Protected constructor which receives CimObject
		AMT_GeneralSystemDefenseCapabilities(const CimObject &object)
			: CIM_Capabilities(object)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_Capabilities::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 3);
			}
		}
		// Called by derived classes
		void SetMetaData(vector<CimFieldAttribute>& childMetaData)
		{
			CIM_Capabilities::SetMetaData(childMetaData);
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
#endif // AMT_GENERALSYSTEMDEFENSECAPABILITIES_H
