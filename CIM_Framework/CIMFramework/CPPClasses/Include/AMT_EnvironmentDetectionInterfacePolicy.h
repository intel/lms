//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       AMT_EnvironmentDetectionInterfacePolicy.h
//
//  Contents:   An existing association implies that a System Defense Policy has been configured to be activated for each interface that identifies it is external to the organization network.
//
//              This file was automatically generated from AMT_EnvironmentDetectionInterfacePolicy.mof,  version: 3.0.0
//
//----------------------------------------------------------------------------
#ifndef AMT_ENVIRONMENTDETECTIONINTERFACEPOLICY_H
#define AMT_ENVIRONMENTDETECTIONINTERFACEPOLICY_H 1
#include "AMT_InterfacePolicy.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	// An existing association implies that a System Defense Policy has been configured to be activated for each interface that identifies it is external to the organization network.
	class CIMFRAMEWORK_API AMT_EnvironmentDetectionInterfacePolicy  : public AMT_InterfacePolicy
	{
	public:

		//Default constructor
		AMT_EnvironmentDetectionInterfacePolicy()
			: AMT_InterfacePolicy(NULL, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				AMT_InterfacePolicy::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 1);
			}
		}

		//constructor which receives WSMan client
		AMT_EnvironmentDetectionInterfacePolicy(ICimWsmanClient *client)
			: AMT_InterfacePolicy(client, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				AMT_InterfacePolicy::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 1);
			}
		}

		//Destructor
		virtual ~AMT_EnvironmentDetectionInterfacePolicy(){}

		// The "type" information for the object. Gettors only.
		virtual const string& ResourceURI() const { return CLASS_URI; }
		static const string& ClassResourceURI() { return CLASS_URI; }
		virtual const string& XmlNamespace() const { return CLASS_NS; }
		virtual const string& XmlPrefix() const { return CLASS_NS_PREFIX; }
		virtual const string& ObjectType() const { return CLASS_NAME; }
		static const string& ClassObjectType() { return CLASS_NAME; }

		// Class representing AMT_EnvironmentDetectionInterfacePolicy keys
		class CimKeys : public AMT_InterfacePolicy::CimKeys
		{
		public:
		};

		// class fields declarations

		// Optional, Specifies whether this policy was enabled on the interface.
		const bool Enabled() const;

		// Optional, Specifies whether this policy was enabled on the interface.
		void Enabled(const bool value); 

		// Is true if the field Enabled exists in the current object, otherwise is false.
		bool EnabledExists() const;

		// Remove Enabled field.
		void RemoveEnabled(); 

		 // Function used by the factory
		static CimBase *CreateFromCimObject(const CimObject &object);

		static vector<shared_ptr<AMT_EnvironmentDetectionInterfacePolicy> > Enumerate(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		// Overloaded delete which supplies the internal resourceURI
		static void Delete(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		using CimBase::Delete;

	protected:
		 // Protected constructor to be used by derived classes
		AMT_EnvironmentDetectionInterfacePolicy(ICimWsmanClient *client, const string &class_name,
			const string &class_ns, const string &prefix, const string &uri): AMT_InterfacePolicy(client, class_name, class_ns, prefix, uri)
		{
			if(_classMetaData.size() == 0)
			{
				AMT_InterfacePolicy::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 1);
			}
		}
		 // Protected constructor which receives CimObject
		AMT_EnvironmentDetectionInterfacePolicy(const CimObject &object)
			: AMT_InterfacePolicy(object)
		{
			if(_classMetaData.size() == 0)
			{
				AMT_InterfacePolicy::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 1);
			}
		}
		// Called by derived classes
		void SetMetaData(vector<CimFieldAttribute>& childMetaData)
		{
			AMT_InterfacePolicy::SetMetaData(childMetaData);
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
#endif // AMT_ENVIRONMENTDETECTIONINTERFACEPOLICY_H
