//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       AMT_RemoteAccessPolicyAppliesToMPS.h
//
//  Contents:   This class associates a Management Presence Server with a Remote Access Policy rule. When a Policy Rule is triggered, the Intel(R) AMT subsystem will attempt to connect to the MpServers associated with the triggered policy in the order by which the associations were created. This order is indicated in the OrderOfAccess field where lower numbers indicate a higher priority.
//
//              This file was automatically generated from AMT_RemoteAccessPolicyAppliesToMPS.mof,  version: 6.0.0
//
//----------------------------------------------------------------------------
#ifndef AMT_REMOTEACCESSPOLICYAPPLIESTOMPS_H
#define AMT_REMOTEACCESSPOLICYAPPLIESTOMPS_H 1
#include "CIM_PolicySetAppliesToElement.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	// This class associates a Management Presence Server with a Remote Access Policy rule. When a Policy Rule is triggered, the Intel(R) AMT subsystem will attempt to connect to the MpServers associated with the triggered policy in the order by which the associations were created. This order is indicated in the OrderOfAccess field where lower numbers indicate a higher priority.
	class CIMFRAMEWORK_API AMT_RemoteAccessPolicyAppliesToMPS  : public CIM_PolicySetAppliesToElement
	{
	public:

		//Default constructor
		AMT_RemoteAccessPolicyAppliesToMPS()
			: CIM_PolicySetAppliesToElement(NULL, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_PolicySetAppliesToElement::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 4);
			}
		}

		//constructor which receives WSMan client
		AMT_RemoteAccessPolicyAppliesToMPS(ICimWsmanClient *client)
			: CIM_PolicySetAppliesToElement(client, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_PolicySetAppliesToElement::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 4);
			}
		}

		//Destructor
		virtual ~AMT_RemoteAccessPolicyAppliesToMPS(){}

		// The "type" information for the object. Gettors only.
		virtual const string& ResourceURI() const { return CLASS_URI; }
		static const string& ClassResourceURI() { return CLASS_URI; }
		virtual const string& XmlNamespace() const { return CLASS_NS; }
		virtual const string& XmlPrefix() const { return CLASS_NS_PREFIX; }
		virtual const string& ObjectType() const { return CLASS_NAME; }
		static const string& ClassObjectType() { return CLASS_NAME; }

		// Class representing AMT_RemoteAccessPolicyAppliesToMPS keys
		class CimKeys : public CIM_PolicySetAppliesToElement::CimKeys
		{
		public:
			// Key, Required, The Remote Access policy rule that is currently applied to the MpServer.
			const CimReference PolicySet() const
			{
				CimReference ret;
				TypeConverter::StringToType(GetKey("PolicySet"), ret);
				return ret;
			}

			// Key, Required, The Remote Access policy rule that is currently applied to the MpServer.
			void PolicySet(const CimReference &value)
			{
				SetOrAddKey("PolicySet", TypeConverter::TypeToString(value), true);
			}

			// Key, Required, The MpServer to which the policy applies.
			const CimReference ManagedElement() const
			{
				CimReference ret;
				TypeConverter::StringToType(GetKey("ManagedElement"), ret);
				return ret;
			}

			// Key, Required, The MpServer to which the policy applies.
			void ManagedElement(const CimReference &value)
			{
				SetOrAddKey("ManagedElement", TypeConverter::TypeToString(value), true);
			}

		};

		// class fields declarations

		// Optional, This field indicates in what order will the Intel(R) AMT subsystem attempt to connect to the referenced MpServer when the referenced Remote Access policy is triggered.
		const unsigned short OrderOfAccess() const;

		// Optional, This field indicates in what order will the Intel(R) AMT subsystem attempt to connect to the referenced MpServer when the referenced Remote Access policy is triggered.
		void OrderOfAccess(const unsigned short value); 

		// Is true if the field OrderOfAccess exists in the current object, otherwise is false.
		bool OrderOfAccessExists() const;

		// Remove OrderOfAccess field.
		void RemoveOrderOfAccess(); 

		// Optional, This field indicates if the MpServer is to be used inside or outside of the organization, or both. Default is outside (0).
		const unsigned short MpsType() const;

		// Optional, This field indicates if the MpServer is to be used inside or outside of the organization, or both. Default is outside (0).
		void MpsType(const unsigned short value); 

		// Is true if the field MpsType exists in the current object, otherwise is false.
		bool MpsTypeExists() const;

		// Remove MpsType field.
		void RemoveMpsType(); 

		 // Function used by the factory
		static CimBase *CreateFromCimObject(const CimObject &object);

		static vector<shared_ptr<AMT_RemoteAccessPolicyAppliesToMPS> > Enumerate(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		// Overloaded delete which supplies the internal resourceURI
		static void Delete(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		using CimBase::Delete;

	protected:
		 // Protected constructor to be used by derived classes
		AMT_RemoteAccessPolicyAppliesToMPS(ICimWsmanClient *client, const string &class_name,
			const string &class_ns, const string &prefix, const string &uri): CIM_PolicySetAppliesToElement(client, class_name, class_ns, prefix, uri)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_PolicySetAppliesToElement::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 4);
			}
		}
		 // Protected constructor which receives CimObject
		AMT_RemoteAccessPolicyAppliesToMPS(const CimObject &object)
			: CIM_PolicySetAppliesToElement(object)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_PolicySetAppliesToElement::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 4);
			}
		}
		// Called by derived classes
		void SetMetaData(vector<CimFieldAttribute>& childMetaData)
		{
			CIM_PolicySetAppliesToElement::SetMetaData(childMetaData);
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
#endif // AMT_REMOTEACCESSPOLICYAPPLIESTOMPS_H
