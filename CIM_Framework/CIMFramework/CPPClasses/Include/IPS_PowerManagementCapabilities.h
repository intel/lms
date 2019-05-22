//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       IPS_PowerManagementCapabilities.h
//
//  Contents:   A class derived from CIM_PowerManagementCapabilitieslities that adds OS power saving aspects of an element (AKA connected standby).
//
//              This file was automatically generated from IPS_PowerManagementCapabilities.mof,  version: 2.23.0
//
//----------------------------------------------------------------------------
#ifndef IPS_POWERMANAGEMENTCAPABILITIES_H
#define IPS_POWERMANAGEMENTCAPABILITIES_H 1
#include "CIM_PowerManagementCapabilities.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	// A class derived from CIM_PowerManagementCapabilitieslities that adds OS power saving aspects of an element (AKA connected standby). 
	class CIMFRAMEWORK_API IPS_PowerManagementCapabilities  : public CIM_PowerManagementCapabilities
	{
	public:

		//Default constructor
		IPS_PowerManagementCapabilities()
			: CIM_PowerManagementCapabilities(NULL, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_PowerManagementCapabilities::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 2);
			}
		}

		//constructor which receives WSMan client
		IPS_PowerManagementCapabilities(ICimWsmanClient *client)
			: CIM_PowerManagementCapabilities(client, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_PowerManagementCapabilities::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 2);
			}
		}

		//Destructor
		virtual ~IPS_PowerManagementCapabilities(){}

		// The "type" information for the object. Gettors only.
		virtual const string& ResourceURI() const { return CLASS_URI; }
		static const string& ClassResourceURI() { return CLASS_URI; }
		virtual const string& XmlNamespace() const { return CLASS_NS; }
		virtual const string& XmlPrefix() const { return CLASS_NS_PREFIX; }
		virtual const string& ObjectType() const { return CLASS_NAME; }
		static const string& ClassObjectType() { return CLASS_NAME; }

		// Class representing IPS_PowerManagementCapabilities keys
		class CimKeys : public CIM_PowerManagementCapabilities::CimKeys
		{
		public:
		};

		// class fields declarations

		// Optional, A value that indicates whether OS power savingstate is supported by a managed element. 
		const unsigned short OSPowerSavingStateSupported() const;

		// Optional, A value that indicates whether OS power savingstate is supported by a managed element. 
		void OSPowerSavingStateSupported(const unsigned short value); 

		// Is true if the field OSPowerSavingStateSupported exists in the current object, otherwise is false.
		bool OSPowerSavingStateSupportedExists() const;

		// Remove OSPowerSavingStateSupported field.
		void RemoveOSPowerSavingStateSupported(); 

		// Optional, An enumeration indicating the specific power-saving-related capabilities of a managed element.
		const unsigned short OSPowerSavingStateChangeSupported() const;

		// Optional, An enumeration indicating the specific power-saving-related capabilities of a managed element.
		void OSPowerSavingStateChangeSupported(const unsigned short value); 

		// Is true if the field OSPowerSavingStateChangeSupported exists in the current object, otherwise is false.
		bool OSPowerSavingStateChangeSupportedExists() const;

		// Remove OSPowerSavingStateChangeSupported field.
		void RemoveOSPowerSavingStateChangeSupported(); 

		 // Function used by the factory
		static CimBase *CreateFromCimObject(const CimObject &object);

		static vector<shared_ptr<IPS_PowerManagementCapabilities> > Enumerate(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		// Overloaded delete which supplies the internal resourceURI
		static void Delete(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		using CimBase::Delete;

	protected:
		 // Protected constructor to be used by derived classes
		IPS_PowerManagementCapabilities(ICimWsmanClient *client, const string &class_name,
			const string &class_ns, const string &prefix, const string &uri): CIM_PowerManagementCapabilities(client, class_name, class_ns, prefix, uri)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_PowerManagementCapabilities::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 2);
			}
		}
		 // Protected constructor which receives CimObject
		IPS_PowerManagementCapabilities(const CimObject &object)
			: CIM_PowerManagementCapabilities(object)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_PowerManagementCapabilities::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 2);
			}
		}
		// Called by derived classes
		void SetMetaData(vector<CimFieldAttribute>& childMetaData)
		{
			CIM_PowerManagementCapabilities::SetMetaData(childMetaData);
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
#endif // IPS_POWERMANAGEMENTCAPABILITIES_H
