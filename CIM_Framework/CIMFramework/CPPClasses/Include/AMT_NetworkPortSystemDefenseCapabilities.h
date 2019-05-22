//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       AMT_NetworkPortSystemDefenseCapabilities.h
//
//  Contents:   Describes the System Defense capabilities of a single network port.
//
//              This file was automatically generated from AMT_NetworkPortSystemDefenseCapabilities.mof,  version: 6.0.0
//
//----------------------------------------------------------------------------
#ifndef AMT_NETWORKPORTSYSTEMDEFENSECAPABILITIES_H
#define AMT_NETWORKPORTSYSTEMDEFENSECAPABILITIES_H 1
#include "CIM_Capabilities.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	// Describes the System Defense capabilities of a single network port.
	class CIMFRAMEWORK_API AMT_NetworkPortSystemDefenseCapabilities  : public CIM_Capabilities
	{
	public:

		//Default constructor
		AMT_NetworkPortSystemDefenseCapabilities()
			: CIM_Capabilities(NULL, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_Capabilities::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 12);
			}
		}

		//constructor which receives WSMan client
		AMT_NetworkPortSystemDefenseCapabilities(ICimWsmanClient *client)
			: CIM_Capabilities(client, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_Capabilities::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 12);
			}
		}

		//Destructor
		virtual ~AMT_NetworkPortSystemDefenseCapabilities(){}

		// The "type" information for the object. Gettors only.
		virtual const string& ResourceURI() const { return CLASS_URI; }
		static const string& ClassResourceURI() { return CLASS_URI; }
		virtual const string& XmlNamespace() const { return CLASS_NS; }
		virtual const string& XmlPrefix() const { return CLASS_NS_PREFIX; }
		virtual const string& ObjectType() const { return CLASS_NAME; }
		static const string& ClassObjectType() { return CLASS_NAME; }

		// Class representing AMT_NetworkPortSystemDefenseCapabilities keys
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

		// Optional, Maximum number of active IPv4 Transmit filters (note: this number includes default filters).
		const unsigned short IPv4_MaxTxFilters() const;

		// Optional, Maximum number of active IPv4 Transmit filters (note: this number includes default filters).
		void IPv4_MaxTxFilters(const unsigned short value); 

		// Is true if the field IPv4_MaxTxFilters exists in the current object, otherwise is false.
		bool IPv4_MaxTxFiltersExists() const;

		// Remove IPv4_MaxTxFilters field.
		void RemoveIPv4_MaxTxFilters(); 

		// Optional, Maximum number of active IPv4 Transmit counters
		const unsigned short IPv4_MaxTxCounters() const;

		// Optional, Maximum number of active IPv4 Transmit counters
		void IPv4_MaxTxCounters(const unsigned short value); 

		// Is true if the field IPv4_MaxTxCounters exists in the current object, otherwise is false.
		bool IPv4_MaxTxCountersExists() const;

		// Remove IPv4_MaxTxCounters field.
		void RemoveIPv4_MaxTxCounters(); 

		// Optional, Maximum number of active IPv4 Receive filters (note: this number includes default filters).
		const unsigned short IPv4_MaxRxFilters() const;

		// Optional, Maximum number of active IPv4 Receive filters (note: this number includes default filters).
		void IPv4_MaxRxFilters(const unsigned short value); 

		// Is true if the field IPv4_MaxRxFilters exists in the current object, otherwise is false.
		bool IPv4_MaxRxFiltersExists() const;

		// Remove IPv4_MaxRxFilters field.
		void RemoveIPv4_MaxRxFilters(); 

		// Optional, Maximum number of active IPv4 Receive counters.
		const unsigned short IPv4_MaxRxCounters() const;

		// Optional, Maximum number of active IPv4 Receive counters.
		void IPv4_MaxRxCounters(const unsigned short value); 

		// Is true if the field IPv4_MaxRxCounters exists in the current object, otherwise is false.
		bool IPv4_MaxRxCountersExists() const;

		// Remove IPv4_MaxRxCounters field.
		void RemoveIPv4_MaxRxCounters(); 

		// Optional, Indicates whether the device supports Anti Spoofing filter for IPv4.
		const bool IPv4_AntiSpoofingCapable() const;

		// Optional, Indicates whether the device supports Anti Spoofing filter for IPv4.
		void IPv4_AntiSpoofingCapable(const bool value); 

		// Is true if the field IPv4_AntiSpoofingCapable exists in the current object, otherwise is false.
		bool IPv4_AntiSpoofingCapableExists() const;

		// Remove IPv4_AntiSpoofingCapable field.
		void RemoveIPv4_AntiSpoofingCapable(); 

		// Optional, Maximum number of active IPv6 Transmit filters.
		const unsigned short IPv6_MaxTxFilters() const;

		// Optional, Maximum number of active IPv6 Transmit filters.
		void IPv6_MaxTxFilters(const unsigned short value); 

		// Is true if the field IPv6_MaxTxFilters exists in the current object, otherwise is false.
		bool IPv6_MaxTxFiltersExists() const;

		// Remove IPv6_MaxTxFilters field.
		void RemoveIPv6_MaxTxFilters(); 

		// Optional, Maximum number of active IPv6 Transmit counters.
		const unsigned short IPv6_MaxTxCounters() const;

		// Optional, Maximum number of active IPv6 Transmit counters.
		void IPv6_MaxTxCounters(const unsigned short value); 

		// Is true if the field IPv6_MaxTxCounters exists in the current object, otherwise is false.
		bool IPv6_MaxTxCountersExists() const;

		// Remove IPv6_MaxTxCounters field.
		void RemoveIPv6_MaxTxCounters(); 

		// Optional, Maximum number of active IPv6 Receive filters.
		const unsigned short IPv6_MaxRxFilters() const;

		// Optional, Maximum number of active IPv6 Receive filters.
		void IPv6_MaxRxFilters(const unsigned short value); 

		// Is true if the field IPv6_MaxRxFilters exists in the current object, otherwise is false.
		bool IPv6_MaxRxFiltersExists() const;

		// Remove IPv6_MaxRxFilters field.
		void RemoveIPv6_MaxRxFilters(); 

		// Optional, Maximum number of active IPv6 receive counters.
		const unsigned short IPv6_MaxRxCounters() const;

		// Optional, Maximum number of active IPv6 receive counters.
		void IPv6_MaxRxCounters(const unsigned short value); 

		// Is true if the field IPv6_MaxRxCounters exists in the current object, otherwise is false.
		bool IPv6_MaxRxCountersExists() const;

		// Remove IPv6_MaxRxCounters field.
		void RemoveIPv6_MaxRxCounters(); 

		// Optional, Indicates whether the device supports Anti Spoofing filter for IPv6.
		const bool IPv6_AntiSpoofingCapable() const;

		// Optional, Indicates whether the device supports Anti Spoofing filter for IPv6.
		void IPv6_AntiSpoofingCapable(const bool value); 

		// Is true if the field IPv6_AntiSpoofingCapable exists in the current object, otherwise is false.
		bool IPv6_AntiSpoofingCapableExists() const;

		// Remove IPv6_AntiSpoofingCapable field.
		void RemoveIPv6_AntiSpoofingCapable(); 

		// Optional, Indicates how many IPv4 filters (or counters) are approximately occupied by an IPv6 filter (or counter, respectively).
		const unsigned short IPv6_to_IPv4_Ratio() const;

		// Optional, Indicates how many IPv4 filters (or counters) are approximately occupied by an IPv6 filter (or counter, respectively).
		void IPv6_to_IPv4_Ratio(const unsigned short value); 

		// Is true if the field IPv6_to_IPv4_Ratio exists in the current object, otherwise is false.
		bool IPv6_to_IPv4_RatioExists() const;

		// Remove IPv6_to_IPv4_Ratio field.
		void RemoveIPv6_to_IPv4_Ratio(); 

		 // Function used by the factory
		static CimBase *CreateFromCimObject(const CimObject &object);

		static vector<shared_ptr<AMT_NetworkPortSystemDefenseCapabilities> > Enumerate(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		// Overloaded delete which supplies the internal resourceURI
		static void Delete(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		using CimBase::Delete;

	protected:
		 // Protected constructor to be used by derived classes
		AMT_NetworkPortSystemDefenseCapabilities(ICimWsmanClient *client, const string &class_name,
			const string &class_ns, const string &prefix, const string &uri): CIM_Capabilities(client, class_name, class_ns, prefix, uri)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_Capabilities::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 12);
			}
		}
		 // Protected constructor which receives CimObject
		AMT_NetworkPortSystemDefenseCapabilities(const CimObject &object)
			: CIM_Capabilities(object)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_Capabilities::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 12);
			}
		}
		// Called by derived classes
		void SetMetaData(vector<CimFieldAttribute>& childMetaData)
		{
			CIM_Capabilities::SetMetaData(childMetaData);
			CimBase::SetMetaData(childMetaData, _metadata, 12);
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
#endif // AMT_NETWORKPORTSYSTEMDEFENSECAPABILITIES_H
