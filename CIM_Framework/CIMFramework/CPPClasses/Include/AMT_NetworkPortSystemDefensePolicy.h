//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       AMT_NetworkPortSystemDefensePolicy.h
//
//  Contents:   An existing association implies that a System Defense Policy may be 'Active' for the specified interface. A management console may create an instance of this class in order to to 'Enable' a policy for a given interface. Among all the associations that may exist there can be only one 'Active' policy per interface.An Active policy is chosen based on the precedence property in a policy.
//
//              This file was automatically generated from AMT_NetworkPortSystemDefensePolicy.mof,  version: 3.0.0
//
//----------------------------------------------------------------------------
#ifndef AMT_NETWORKPORTSYSTEMDEFENSEPOLICY_H
#define AMT_NETWORKPORTSYSTEMDEFENSEPOLICY_H 1
#include "AMT_InterfacePolicy.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	// An existing association implies that a System Defense Policy may be 'Active' for the specified interface. A management console may create an instance of this class in order to to 'Enable' a policy for a given interface. Among all the associations that may exist there can be only one 'Active' policy per interface.An Active policy is chosen based on the precedence property in a policy.
	class CIMFRAMEWORK_API AMT_NetworkPortSystemDefensePolicy  : public AMT_InterfacePolicy
	{
	public:

		//Default constructor
		AMT_NetworkPortSystemDefensePolicy()
			: AMT_InterfacePolicy(NULL, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				AMT_InterfacePolicy::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 1);
			}
		}

		//constructor which receives WSMan client
		AMT_NetworkPortSystemDefensePolicy(ICimWsmanClient *client)
			: AMT_InterfacePolicy(client, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				AMT_InterfacePolicy::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 1);
			}
		}

		//Destructor
		virtual ~AMT_NetworkPortSystemDefensePolicy(){}

		// The "type" information for the object. Gettors only.
		virtual const string& ResourceURI() const { return CLASS_URI; }
		static const string& ClassResourceURI() { return CLASS_URI; }
		virtual const string& XmlNamespace() const { return CLASS_NS; }
		virtual const string& XmlPrefix() const { return CLASS_NS_PREFIX; }
		virtual const string& ObjectType() const { return CLASS_NAME; }
		static const string& ClassObjectType() { return CLASS_NAME; }

		// Class representing AMT_NetworkPortSystemDefensePolicy keys
		class CimKeys : public AMT_InterfacePolicy::CimKeys
		{
		public:
		};

		// class fields declarations

		// Optional, Specifies whether the owner enabled this Policy.
		const bool Enabled() const;

		// Optional, Specifies whether the owner enabled this Policy.
		void Enabled(const bool value); 

		// Is true if the field Enabled exists in the current object, otherwise is false.
		bool EnabledExists() const;

		// Remove Enabled field.
		void RemoveEnabled(); 

		 // Function used by the factory
		static CimBase *CreateFromCimObject(const CimObject &object);

		static vector<shared_ptr<AMT_NetworkPortSystemDefensePolicy> > Enumerate(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		// Overloaded delete which supplies the internal resourceURI
		static void Delete(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		using CimBase::Delete;

	protected:
		 // Protected constructor to be used by derived classes
		AMT_NetworkPortSystemDefensePolicy(ICimWsmanClient *client, const string &class_name,
			const string &class_ns, const string &prefix, const string &uri): AMT_InterfacePolicy(client, class_name, class_ns, prefix, uri)
		{
			if(_classMetaData.size() == 0)
			{
				AMT_InterfacePolicy::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 1);
			}
		}
		 // Protected constructor which receives CimObject
		AMT_NetworkPortSystemDefensePolicy(const CimObject &object)
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
#endif // AMT_NETWORKPORTSYSTEMDEFENSEPOLICY_H
