//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       AMT_Hdr8021Filter.h
//
//  Contents:   8021Filter allows 802.1.source and destination MAC addresses, as well as the 802.1 protocol ID, priority, and VLAN identifier fields, to be expressed in a single object to classify and identify traffic.
//
//              This file was automatically generated from AMT_Hdr8021Filter.mof,  version: 3.0.0
//
//----------------------------------------------------------------------------
#ifndef AMT_HDR8021FILTER_H
#define AMT_HDR8021FILTER_H 1
#include "AMT_ComplexFilterEntryBase.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	// 8021Filter allows 802.1.source and destination MAC addresses, as well as the 802.1 protocol ID, priority, and VLAN identifier fields, to be expressed in a single object to classify and identify traffic.
	class CIMFRAMEWORK_API AMT_Hdr8021Filter  : public AMT_ComplexFilterEntryBase
	{
	public:

		//Default constructor
		AMT_Hdr8021Filter()
			: AMT_ComplexFilterEntryBase(NULL, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				AMT_ComplexFilterEntryBase::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 11);
			}
		}

		//constructor which receives WSMan client
		AMT_Hdr8021Filter(ICimWsmanClient *client)
			: AMT_ComplexFilterEntryBase(client, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				AMT_ComplexFilterEntryBase::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 11);
			}
		}

		//Destructor
		virtual ~AMT_Hdr8021Filter(){}

		// The "type" information for the object. Gettors only.
		virtual const string& ResourceURI() const { return CLASS_URI; }
		static const string& ClassResourceURI() { return CLASS_URI; }
		virtual const string& XmlNamespace() const { return CLASS_NS; }
		virtual const string& XmlPrefix() const { return CLASS_NS_PREFIX; }
		virtual const string& ObjectType() const { return CLASS_NAME; }
		static const string& ClassObjectType() { return CLASS_NAME; }

		// Class representing AMT_Hdr8021Filter keys
		class CimKeys : public AMT_ComplexFilterEntryBase::CimKeys
		{
		public:
		};

		// class fields declarations

		// Optional, This property is an OctetString of size 6, representing a 48-bit source MAC address in canonical format. This value is compared to the SourceAddress field in the MAC header, subject to the mask represented in the 8021HdrSrcMACMask property. If a value for this property is not provided, then the filter does not consider 8021HdrSrcMACAddr in selecting matching packets, i.e., 8021HdrSrcMACAddr matches for all values.
		const Base64 HdrSrcMACAddr8021() const;

		// Optional, This property is an OctetString of size 6, representing a 48-bit source MAC address in canonical format. This value is compared to the SourceAddress field in the MAC header, subject to the mask represented in the 8021HdrSrcMACMask property. If a value for this property is not provided, then the filter does not consider 8021HdrSrcMACAddr in selecting matching packets, i.e., 8021HdrSrcMACAddr matches for all values.
		void HdrSrcMACAddr8021(const Base64 &value); 

		// Is true if the field HdrSrcMACAddr8021 exists in the current object, otherwise is false.
		bool HdrSrcMACAddr8021Exists() const;

		// Remove HdrSrcMACAddr8021 field.
		void RemoveHdrSrcMACAddr8021(); 

		// Optional, This property is an OctetString of size 6, representing a 48-bit mask to be used in comparing the SourceAddress field in the MAC header with the value represented in the 8021HdrSrcMACAddr property. If a value for this property is not provided, then the filter does not consider 8021HdrSrcMACMask in selecting matching packets, i.e., the value of 8021HdrSrcMACAddr must match the source MAC address in the packet exactly.
		const Base64 HdrSrcMACMask8021() const;

		// Optional, This property is an OctetString of size 6, representing a 48-bit mask to be used in comparing the SourceAddress field in the MAC header with the value represented in the 8021HdrSrcMACAddr property. If a value for this property is not provided, then the filter does not consider 8021HdrSrcMACMask in selecting matching packets, i.e., the value of 8021HdrSrcMACAddr must match the source MAC address in the packet exactly.
		void HdrSrcMACMask8021(const Base64 &value); 

		// Is true if the field HdrSrcMACMask8021 exists in the current object, otherwise is false.
		bool HdrSrcMACMask8021Exists() const;

		// Remove HdrSrcMACMask8021 field.
		void RemoveHdrSrcMACMask8021(); 

		// Optional, This property is an OctetString of size 6, representing a 48-bit destination MAC address in canonical format. This value is compared to the DestinationAddress field in the MAC header, subject to the mask represented in the 8021HdrDestMACMask property. If a value for this property is not provided, then the filter does not consider 8021HdrDestMACAddr in selecting matching packets, i.e., 8021HdrDestMACAddr matches for all values.
		const Base64 HdrDestMACAddr8021() const;

		// Optional, This property is an OctetString of size 6, representing a 48-bit destination MAC address in canonical format. This value is compared to the DestinationAddress field in the MAC header, subject to the mask represented in the 8021HdrDestMACMask property. If a value for this property is not provided, then the filter does not consider 8021HdrDestMACAddr in selecting matching packets, i.e., 8021HdrDestMACAddr matches for all values.
		void HdrDestMACAddr8021(const Base64 &value); 

		// Is true if the field HdrDestMACAddr8021 exists in the current object, otherwise is false.
		bool HdrDestMACAddr8021Exists() const;

		// Remove HdrDestMACAddr8021 field.
		void RemoveHdrDestMACAddr8021(); 

		// Optional, This property is an OctetString of size 6, representing a 48-bit mask to be used in comparing the DestinationAddress field in the MAC header with the value represented in the 8021HdrDestMACAddr property. If a value for this property is not provided, then the filter does not consider 8021HdrDestMACMask in selecting matching packets, i.e., the value of 8021HdrDestMACAddr must match the destination MAC address in the packet exactly.
		const Base64 HdrDestMACMask8021() const;

		// Optional, This property is an OctetString of size 6, representing a 48-bit mask to be used in comparing the DestinationAddress field in the MAC header with the value represented in the 8021HdrDestMACAddr property. If a value for this property is not provided, then the filter does not consider 8021HdrDestMACMask in selecting matching packets, i.e., the value of 8021HdrDestMACAddr must match the destination MAC address in the packet exactly.
		void HdrDestMACMask8021(const Base64 &value); 

		// Is true if the field HdrDestMACMask8021 exists in the current object, otherwise is false.
		bool HdrDestMACMask8021Exists() const;

		// Remove HdrDestMACMask8021 field.
		void RemoveHdrDestMACMask8021(); 

		// Required, This property is a 16-bit unsigned integer, representing an Ethernet protocol type. This value is compared to the Ethernet Type field in the 802.3 MAC header.
		const unsigned short HdrProtocolID8021() const;

		// Required, This property is a 16-bit unsigned integer, representing an Ethernet protocol type. This value is compared to the Ethernet Type field in the 802.3 MAC header.
		void HdrProtocolID8021(const unsigned short value); 

		// Is true if the field HdrProtocolID8021 exists in the current object, otherwise is false.
		bool HdrProtocolID8021Exists() const;

		// Remove HdrProtocolID8021 field.
		void RemoveHdrProtocolID8021(); 

		// Optional, This property is an 8-bit unsigned integer, representing an 802.1Q priority. This value is compared to the Priority field in the 802.1Q header. Since the 802.1Q Priority field consists of 3 bits, the values for this property are limited to the range 0..7. If a value for this property is not provided, then the filter does not consider 8021HdrPriorityValue in selecting matching packets, i.e., 8021HdrPriorityValue matches for all values.
		const unsigned char HdrPriorityValue8021() const;

		// Optional, This property is an 8-bit unsigned integer, representing an 802.1Q priority. This value is compared to the Priority field in the 802.1Q header. Since the 802.1Q Priority field consists of 3 bits, the values for this property are limited to the range 0..7. If a value for this property is not provided, then the filter does not consider 8021HdrPriorityValue in selecting matching packets, i.e., 8021HdrPriorityValue matches for all values.
		void HdrPriorityValue8021(const unsigned char &value); 

		// Is true if the field HdrPriorityValue8021 exists in the current object, otherwise is false.
		bool HdrPriorityValue8021Exists() const;

		// Remove HdrPriorityValue8021 field.
		void RemoveHdrPriorityValue8021(); 

		// Optional, This property is an 32-bit unsigned integer, representing an 802.1Q VLAN Identifier. This value is compared to the VLAN ID field in the 802.1Q header. Since the 802.1Q VLAN ID field consists of 12 bits, the values for this property are limited to the range 0..4095. If a value for this property is not provided, then the filter does not consider 8021HdrVLANID in selecting matching packets, i.e., 8021HdrVLANID matches for all values.
		const unsigned int HdrVLANID8021() const;

		// Optional, This property is an 32-bit unsigned integer, representing an 802.1Q VLAN Identifier. This value is compared to the VLAN ID field in the 802.1Q header. Since the 802.1Q VLAN ID field consists of 12 bits, the values for this property are limited to the range 0..4095. If a value for this property is not provided, then the filter does not consider 8021HdrVLANID in selecting matching packets, i.e., 8021HdrVLANID matches for all values.
		void HdrVLANID8021(const unsigned int value); 

		// Is true if the field HdrVLANID8021 exists in the current object, otherwise is false.
		bool HdrVLANID8021Exists() const;

		// Remove HdrVLANID8021 field.
		void RemoveHdrVLANID8021(); 

		// Required, Specifies the type of behavior exhibited by the filter.
		const unsigned short FilterProfile() const;

		// Required, Specifies the type of behavior exhibited by the filter.
		void FilterProfile(const unsigned short value); 

		// Is true if the field FilterProfile exists in the current object, otherwise is false.
		bool FilterProfileExists() const;

		// Remove FilterProfile field.
		void RemoveFilterProfile(); 

		// Required, Specifies the traffic direction (transmit or receive) that the filter governs.
		const unsigned short FilterDirection() const;

		// Required, Specifies the traffic direction (transmit or receive) that the filter governs.
		void FilterDirection(const unsigned short value); 

		// Is true if the field FilterDirection exists in the current object, otherwise is false.
		bool FilterDirectionExists() const;

		// Remove FilterDirection field.
		void RemoveFilterDirection(); 

		// Required, Specifies whether an Event should be created in the Event Manager when this filter is matched.
		const bool ActionEventOnMatch() const;

		// Required, Specifies whether an Event should be created in the Event Manager when this filter is matched.
		void ActionEventOnMatch(const bool value); 

		// Is true if the field ActionEventOnMatch exists in the current object, otherwise is false.
		bool ActionEventOnMatchExists() const;

		// Remove ActionEventOnMatch field.
		void RemoveActionEventOnMatch(); 

		// Optional, An extra data parameter which is used depending on the FilterProfile: It is left blank for Drop/Pass/Statistics filters, but is required for Rate Limit filters. It indicates the maximum number of events per second (should be greater than 0). Rate limits are not exact. Typically several more packets than the number in the rate limit will be allowed to pass before traffic is blocked. If the boundary is critical, set the maximum number of events to a lower value
		const unsigned int FilterProfileData() const;

		// Optional, An extra data parameter which is used depending on the FilterProfile: It is left blank for Drop/Pass/Statistics filters, but is required for Rate Limit filters. It indicates the maximum number of events per second (should be greater than 0). Rate limits are not exact. Typically several more packets than the number in the rate limit will be allowed to pass before traffic is blocked. If the boundary is critical, set the maximum number of events to a lower value
		void FilterProfileData(const unsigned int value); 

		// Is true if the field FilterProfileData exists in the current object, otherwise is false.
		bool FilterProfileDataExists() const;

		// Remove FilterProfileData field.
		void RemoveFilterProfileData(); 

		 // Function used by the factory
		static CimBase *CreateFromCimObject(const CimObject &object);

		static vector<shared_ptr<AMT_Hdr8021Filter> > Enumerate(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		// Overloaded delete which supplies the internal resourceURI
		static void Delete(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		using CimBase::Delete;

	protected:
		 // Protected constructor to be used by derived classes
		AMT_Hdr8021Filter(ICimWsmanClient *client, const string &class_name,
			const string &class_ns, const string &prefix, const string &uri): AMT_ComplexFilterEntryBase(client, class_name, class_ns, prefix, uri)
		{
			if(_classMetaData.size() == 0)
			{
				AMT_ComplexFilterEntryBase::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 11);
			}
		}
		 // Protected constructor which receives CimObject
		AMT_Hdr8021Filter(const CimObject &object)
			: AMT_ComplexFilterEntryBase(object)
		{
			if(_classMetaData.size() == 0)
			{
				AMT_ComplexFilterEntryBase::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 11);
			}
		}
		// Called by derived classes
		void SetMetaData(vector<CimFieldAttribute>& childMetaData)
		{
			AMT_ComplexFilterEntryBase::SetMetaData(childMetaData);
			CimBase::SetMetaData(childMetaData, _metadata, 11);
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
#endif // AMT_HDR8021FILTER_H
