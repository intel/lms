//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       IPS_HostBootReason.h
//
//  Contents:   The IPS_HostBootReason class returns the details of the last host boot.
//
//              This file was automatically generated from IPS_HostBootReason.mof,  version: 8.0.0
//
//----------------------------------------------------------------------------
#ifndef IPS_HOSTBOOTREASON_H
#define IPS_HOSTBOOTREASON_H 1
#include "CIM_ManagedElement.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	// The IPS_HostBootReason class returns the details of the last host boot.
	class CIMFRAMEWORK_API IPS_HostBootReason  : public CIM_ManagedElement
	{
	public:

		//Default constructor
		IPS_HostBootReason()
			: CIM_ManagedElement(NULL, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_ManagedElement::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 4);
			}
		}

		//constructor which receives WSMan client
		IPS_HostBootReason(ICimWsmanClient *client)
			: CIM_ManagedElement(client, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_ManagedElement::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 4);
			}
		}

		//Destructor
		virtual ~IPS_HostBootReason(){}

		// The "type" information for the object. Gettors only.
		virtual const string& ResourceURI() const { return CLASS_URI; }
		static const string& ClassResourceURI() { return CLASS_URI; }
		virtual const string& XmlNamespace() const { return CLASS_NS; }
		virtual const string& XmlPrefix() const { return CLASS_NS_PREFIX; }
		virtual const string& ObjectType() const { return CLASS_NAME; }
		static const string& ClassObjectType() { return CLASS_NAME; }

		// Class representing IPS_HostBootReason keys
		class CimKeys : public CIM_ManagedElement::CimKeys
		{
		public:
			// Key, Required, 
			const string InstanceID() const
			{
				return GetKey("InstanceID");
			}

			// Key, Required, 
			void InstanceID(const string &value)
			{
				SetOrAddKey("InstanceID", value);
			}

		};

		// class fields declarations

		// Required, The reason for the last host boot.'Other' stands for a boot that did not originate in AMT, e.g. OS-initiated reset.'Remote Control' stands for a boot that originated in AMT remote control operation.'Alarm' stands for a boot that originated in an Alarm Clock operation.
		const unsigned int Reason() const;

		// Required, The reason for the last host boot.'Other' stands for a boot that did not originate in AMT, e.g. OS-initiated reset.'Remote Control' stands for a boot that originated in AMT remote control operation.'Alarm' stands for a boot that originated in an Alarm Clock operation.
		void Reason(const unsigned int value); 

		// Is true if the field Reason exists in the current object, otherwise is false.
		bool ReasonExists() const;

		// Remove Reason field.
		void RemoveReason(); 

		// Optional, Details of the last host boot reason.If reason is 'Remote Control', this field will contain a string representing the remote control operation performed ("Reset",  "Power Up" or "Power Cycle"). If reason is 'Alarm', this field will contain the ElementName of the IPS_AlarmClockOccurence instance that invoked the alarm.
		const string ReasonDetails() const;

		// Optional, Details of the last host boot reason.If reason is 'Remote Control', this field will contain a string representing the remote control operation performed ("Reset",  "Power Up" or "Power Cycle"). If reason is 'Alarm', this field will contain the ElementName of the IPS_AlarmClockOccurence instance that invoked the alarm.
		void ReasonDetails(const string &value); 

		// Is true if the field ReasonDetails exists in the current object, otherwise is false.
		bool ReasonDetailsExists() const;

		// Remove ReasonDetails field.
		void RemoveReasonDetails(); 

		// Required, The host S-state prior to the last boot.
		const unsigned int PreviousSxState() const;

		// Required, The host S-state prior to the last boot.
		void PreviousSxState(const unsigned int value); 

		// Is true if the field PreviousSxState exists in the current object, otherwise is false.
		bool PreviousSxStateExists() const;

		// Remove PreviousSxState field.
		void RemovePreviousSxState(); 

		 // Function used by the factory
		static CimBase *CreateFromCimObject(const CimObject &object);

		static vector<shared_ptr<IPS_HostBootReason> > Enumerate(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		// Overloaded delete which supplies the internal resourceURI
		static void Delete(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		using CimBase::Delete;

	protected:
		 // Protected constructor to be used by derived classes
		IPS_HostBootReason(ICimWsmanClient *client, const string &class_name,
			const string &class_ns, const string &prefix, const string &uri): CIM_ManagedElement(client, class_name, class_ns, prefix, uri)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_ManagedElement::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 4);
			}
		}
		 // Protected constructor which receives CimObject
		IPS_HostBootReason(const CimObject &object)
			: CIM_ManagedElement(object)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_ManagedElement::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 4);
			}
		}
		// Called by derived classes
		void SetMetaData(vector<CimFieldAttribute>& childMetaData)
		{
			CIM_ManagedElement::SetMetaData(childMetaData);
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
#endif // IPS_HOSTBOOTREASON_H
