//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       AMT_HeuristicPacketFilterInterfacePolicy.h
//
//  Contents:   An existing association implies that a System Defense Policy may be 'Active' for the specified interface. A management console may create an instance of this class in order to set a Heuristic Packet Filter configuration, that will cause the policy to move to the 'Enabled' System Defense policy state in case of a threshold breach.As per the rules for System Defense policies, an Enabled policy will become Active if it has the highest priority of all policies enabled for the particular network interface.
//
//              This file was automatically generated from AMT_HeuristicPacketFilterInterfacePolicy.mof,  version: 6.0.0
//
//----------------------------------------------------------------------------
#ifndef AMT_HEURISTICPACKETFILTERINTERFACEPOLICY_H
#define AMT_HEURISTICPACKETFILTERINTERFACEPOLICY_H 1
#include "AMT_InterfacePolicy.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	// An existing association implies that a System Defense Policy may be 'Active' for the specified interface. A management console may create an instance of this class in order to set a Heuristic Packet Filter configuration, that will cause the policy to move to the 'Enabled' System Defense policy state in case of a threshold breach.As per the rules for System Defense policies, an Enabled policy will become Active if it has the highest priority of all policies enabled for the particular network interface.
	class CIMFRAMEWORK_API AMT_HeuristicPacketFilterInterfacePolicy  : public AMT_InterfacePolicy
	{
	public:

		//Default constructor
		AMT_HeuristicPacketFilterInterfacePolicy()
			: AMT_InterfacePolicy(NULL, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				AMT_InterfacePolicy::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 3);
			}
		}

		//constructor which receives WSMan client
		AMT_HeuristicPacketFilterInterfacePolicy(ICimWsmanClient *client)
			: AMT_InterfacePolicy(client, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				AMT_InterfacePolicy::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 3);
			}
		}

		//Destructor
		virtual ~AMT_HeuristicPacketFilterInterfacePolicy(){}

		// The "type" information for the object. Gettors only.
		virtual const string& ResourceURI() const { return CLASS_URI; }
		static const string& ClassResourceURI() { return CLASS_URI; }
		virtual const string& XmlNamespace() const { return CLASS_NS; }
		virtual const string& XmlPrefix() const { return CLASS_NS_PREFIX; }
		virtual const string& ObjectType() const { return CLASS_NAME; }
		static const string& ClassObjectType() { return CLASS_NAME; }

		// Class representing AMT_HeuristicPacketFilterInterfacePolicy keys
		class CimKeys : public AMT_InterfacePolicy::CimKeys
		{
		public:
			// Key, Required, References an AMT_SystemDefensePolicy object.
			const CimReference Dependent() const
			{
				CimReference ret;
				TypeConverter::StringToType(GetKey("Dependent"), ret);
				return ret;
			}

			// Key, Required, References an AMT_SystemDefensePolicy object.
			void Dependent(const CimReference &value)
			{
				SetOrAddKey("Dependent", TypeConverter::TypeToString(value), true);
			}

			// Key, Required, References a CIM_EthernetPort object representing the interface.
			const CimReference Antecedent() const
			{
				CimReference ret;
				TypeConverter::StringToType(GetKey("Antecedent"), ret);
				return ret;
			}

			// Key, Required, References a CIM_EthernetPort object representing the interface.
			void Antecedent(const CimReference &value)
			{
				SetOrAddKey("Antecedent", TypeConverter::TypeToString(value), true);
			}

		};

		// class fields declarations

		// Optional, Specifies whether Heuristic Packet Filter Configured this Policy.
		const bool Enabled() const;

		// Optional, Specifies whether Heuristic Packet Filter Configured this Policy.
		void Enabled(const bool value); 

		// Is true if the field Enabled exists in the current object, otherwise is false.
		bool EnabledExists() const;

		// Remove Enabled field.
		void RemoveEnabled(); 

		 // Function used by the factory
		static CimBase *CreateFromCimObject(const CimObject &object);

		static vector<shared_ptr<AMT_HeuristicPacketFilterInterfacePolicy> > Enumerate(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		// Overloaded delete which supplies the internal resourceURI
		static void Delete(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		using CimBase::Delete;

	protected:
		 // Protected constructor to be used by derived classes
		AMT_HeuristicPacketFilterInterfacePolicy(ICimWsmanClient *client, const string &class_name,
			const string &class_ns, const string &prefix, const string &uri): AMT_InterfacePolicy(client, class_name, class_ns, prefix, uri)
		{
			if(_classMetaData.size() == 0)
			{
				AMT_InterfacePolicy::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 3);
			}
		}
		 // Protected constructor which receives CimObject
		AMT_HeuristicPacketFilterInterfacePolicy(const CimObject &object)
			: AMT_InterfacePolicy(object)
		{
			if(_classMetaData.size() == 0)
			{
				AMT_InterfacePolicy::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 3);
			}
		}
		// Called by derived classes
		void SetMetaData(vector<CimFieldAttribute>& childMetaData)
		{
			AMT_InterfacePolicy::SetMetaData(childMetaData);
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
#endif // AMT_HEURISTICPACKETFILTERINTERFACEPOLICY_H
