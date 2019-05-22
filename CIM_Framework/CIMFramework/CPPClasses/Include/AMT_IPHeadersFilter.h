//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       AMT_IPHeadersFilter.h
//
//  Contents:   IPHeadersFilter contains the most commonly required properties for performing filtering on IP, TCP or UDP headers. Properties not present in an instance of the IPHeadersFilter are treated as 'all values'.
//
//              This file was automatically generated from AMT_IPHeadersFilter.mof,  version: 6.0.0
//
//----------------------------------------------------------------------------
#ifndef AMT_IPHEADERSFILTER_H
#define AMT_IPHEADERSFILTER_H 1
#include "AMT_ComplexFilterEntryBase.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	// IPHeadersFilter contains the most commonly required properties for performing filtering on IP, TCP or UDP headers. Properties not present in an instance of the IPHeadersFilter are treated as 'all values'.
	class CIMFRAMEWORK_API AMT_IPHeadersFilter  : public AMT_ComplexFilterEntryBase
	{
	public:

		//Default constructor
		AMT_IPHeadersFilter()
			: AMT_ComplexFilterEntryBase(NULL, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				AMT_ComplexFilterEntryBase::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 20);
			}
		}

		//constructor which receives WSMan client
		AMT_IPHeadersFilter(ICimWsmanClient *client)
			: AMT_ComplexFilterEntryBase(client, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				AMT_ComplexFilterEntryBase::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 20);
			}
		}

		//Destructor
		virtual ~AMT_IPHeadersFilter(){}

		// The "type" information for the object. Gettors only.
		virtual const string& ResourceURI() const { return CLASS_URI; }
		static const string& ClassResourceURI() { return CLASS_URI; }
		virtual const string& XmlNamespace() const { return CLASS_NS; }
		virtual const string& XmlPrefix() const { return CLASS_NS_PREFIX; }
		virtual const string& ObjectType() const { return CLASS_NAME; }
		static const string& ClassObjectType() { return CLASS_NAME; }

		// Class representing AMT_IPHeadersFilter keys
		class CimKeys : public AMT_ComplexFilterEntryBase::CimKeys
		{
		public:
		};

		// class fields declarations

		// Optional, HdrIPVersion identifies the version of the IP addresses for IP header filters. It is also used to determine the sizes of the OctetStrings in the six properties HdrSrcAddress, HdrSrcAddressEndOfRange, HdrSrcMask, HdrDestAddress, HdrDestAddressEndOfRange and HdrDestMask, as follows: 
		// ipv4(4): OctetString(SIZE (4)) 
		// ipv6(6): OctetString(SIZE (16|20)), 
		// depending on whether a scope identifier is present. 
		// 
		// If a value for this property is not provided, then the filter does not consider IP version in selecting matching packets, i.e., IP version matches for all values. In this case, the HdrSrcAddress, HdrSrcAddressEndOfRange, HdrSrcMask, HdrDestAddress, HdrDestAddressEndOfRange and HdrDestMask must also be not present.
		const unsigned char HdrIPVersion() const;

		// Optional, HdrIPVersion identifies the version of the IP addresses for IP header filters. It is also used to determine the sizes of the OctetStrings in the six properties HdrSrcAddress, HdrSrcAddressEndOfRange, HdrSrcMask, HdrDestAddress, HdrDestAddressEndOfRange and HdrDestMask, as follows: 
		// ipv4(4): OctetString(SIZE (4)) 
		// ipv6(6): OctetString(SIZE (16|20)), 
		// depending on whether a scope identifier is present. 
		// 
		// If a value for this property is not provided, then the filter does not consider IP version in selecting matching packets, i.e., IP version matches for all values. In this case, the HdrSrcAddress, HdrSrcAddressEndOfRange, HdrSrcMask, HdrDestAddress, HdrDestAddressEndOfRange and HdrDestMask must also be not present.
		void HdrIPVersion(const unsigned char &value); 

		// Is true if the field HdrIPVersion exists in the current object, otherwise is false.
		bool HdrIPVersionExists() const;

		// Remove HdrIPVersion field.
		void RemoveHdrIPVersion(); 

		// Optional, HdrSrcAddress is an OctetString, of a size determined by the value of the HdrIPVersion property, representing a source IP address. When there is no HdrSrcAddressEndOfRange value, this value is compared to the source address in the IP header, subject to the mask represented in the HdrSrcMask property. (Note that the mask is ANDed with the address.) When there is a HdrSrcAddressEndOfRange value, this value is the start of the specified range (i.e., the HdrSrcAddress is lower than the HdrSrcAddressEndOfRange) that is compared to the source address in the IP header and matches on any value in the range. 
		// 
		// If a value for this property is not provided, then the filter does not consider HdrSrcAddress in selecting matching packets, i.e., HdrSrcAddress matches for all values.
		const HexBinary HdrSrcAddress() const;

		// Optional, HdrSrcAddress is an OctetString, of a size determined by the value of the HdrIPVersion property, representing a source IP address. When there is no HdrSrcAddressEndOfRange value, this value is compared to the source address in the IP header, subject to the mask represented in the HdrSrcMask property. (Note that the mask is ANDed with the address.) When there is a HdrSrcAddressEndOfRange value, this value is the start of the specified range (i.e., the HdrSrcAddress is lower than the HdrSrcAddressEndOfRange) that is compared to the source address in the IP header and matches on any value in the range. 
		// 
		// If a value for this property is not provided, then the filter does not consider HdrSrcAddress in selecting matching packets, i.e., HdrSrcAddress matches for all values.
		void HdrSrcAddress(const HexBinary &value); 

		// Is true if the field HdrSrcAddress exists in the current object, otherwise is false.
		bool HdrSrcAddressExists() const;

		// Remove HdrSrcAddress field.
		void RemoveHdrSrcAddress(); 

		// Optional, HdrSrcAddressEndOfRange is an OctetString, of a size determined by the value of the HdrIPVersion property, representing the end of a range of source IP addresses (inclusive), where the start of the range is the HdrSrcAddress property value. 
		// 
		// If a value for HdrSrcAddress is not provided, then this property also MUST NOT be provided. If a value for this property is provided, then HdrSrcMask MUST NOT be provided.
		const HexBinary HdrSrcAddressEndOfRange() const;

		// Optional, HdrSrcAddressEndOfRange is an OctetString, of a size determined by the value of the HdrIPVersion property, representing the end of a range of source IP addresses (inclusive), where the start of the range is the HdrSrcAddress property value. 
		// 
		// If a value for HdrSrcAddress is not provided, then this property also MUST NOT be provided. If a value for this property is provided, then HdrSrcMask MUST NOT be provided.
		void HdrSrcAddressEndOfRange(const HexBinary &value); 

		// Is true if the field HdrSrcAddressEndOfRange exists in the current object, otherwise is false.
		bool HdrSrcAddressEndOfRangeExists() const;

		// Remove HdrSrcAddressEndOfRange field.
		void RemoveHdrSrcAddressEndOfRange(); 

		// Optional, HdrSrcMask is an OctetString, of a size determined by the value of the HdrIPVersion property, representing a mask to be used in comparing the source address in the IP header with the value represented in the HdrSrcAddress property. 
		// 
		// If a value for this property is not provided, then the filter does not consider HdrSrcMask in selecting matching packets, i.e., the value of the HdrSrcAddress or the source address range must match the source address in the packet exactly. If a value for this property is provided, then HdrSrcAddressEndOfRange MUST NOT be provided.
		const HexBinary HdrSrcMask() const;

		// Optional, HdrSrcMask is an OctetString, of a size determined by the value of the HdrIPVersion property, representing a mask to be used in comparing the source address in the IP header with the value represented in the HdrSrcAddress property. 
		// 
		// If a value for this property is not provided, then the filter does not consider HdrSrcMask in selecting matching packets, i.e., the value of the HdrSrcAddress or the source address range must match the source address in the packet exactly. If a value for this property is provided, then HdrSrcAddressEndOfRange MUST NOT be provided.
		void HdrSrcMask(const HexBinary &value); 

		// Is true if the field HdrSrcMask exists in the current object, otherwise is false.
		bool HdrSrcMaskExists() const;

		// Remove HdrSrcMask field.
		void RemoveHdrSrcMask(); 

		// Optional, HdrDestAddress is an OctetString, of a size determined by the value of the HdrIPVersion property, representing a destination IP address. When there is no HdrDestAddressEndOfRange value, this value is compared to the destination address in the IP header, subject to the mask represented in the HdrDestMask property. (Note that the mask is ANDed with the address.) When there is a HdrDestAddressEndOfRange value, this value is the start of the specified range (i.e., the HdrDestAddress is lower than the HdrDestAddressEndOfRange) that is compared to the source address in the IP header and matches on any value in the range. 
		// 
		// If a value for this property is not provided, then the filter does not consider HdrDestAddress in selecting matching packets, i.e., HdrDestAddress matches for all values.
		const HexBinary HdrDestAddress() const;

		// Optional, HdrDestAddress is an OctetString, of a size determined by the value of the HdrIPVersion property, representing a destination IP address. When there is no HdrDestAddressEndOfRange value, this value is compared to the destination address in the IP header, subject to the mask represented in the HdrDestMask property. (Note that the mask is ANDed with the address.) When there is a HdrDestAddressEndOfRange value, this value is the start of the specified range (i.e., the HdrDestAddress is lower than the HdrDestAddressEndOfRange) that is compared to the source address in the IP header and matches on any value in the range. 
		// 
		// If a value for this property is not provided, then the filter does not consider HdrDestAddress in selecting matching packets, i.e., HdrDestAddress matches for all values.
		void HdrDestAddress(const HexBinary &value); 

		// Is true if the field HdrDestAddress exists in the current object, otherwise is false.
		bool HdrDestAddressExists() const;

		// Remove HdrDestAddress field.
		void RemoveHdrDestAddress(); 

		// Optional, HdrDestAddressEndOfRange is an OctetString, of a size determined by the value of the HdrIPVersion property, representing the end of a range of destination IP addresses (inclusive), where the start of the range is the HdrDestAddress property value. 
		// 
		// If a value for HdrDestAddress is not provided, then this property also MUST NOT be provided. If a value for this property is provided, then HdrDestMask MUST NOT be provided.
		const HexBinary HdrDestAddressEndOfRange() const;

		// Optional, HdrDestAddressEndOfRange is an OctetString, of a size determined by the value of the HdrIPVersion property, representing the end of a range of destination IP addresses (inclusive), where the start of the range is the HdrDestAddress property value. 
		// 
		// If a value for HdrDestAddress is not provided, then this property also MUST NOT be provided. If a value for this property is provided, then HdrDestMask MUST NOT be provided.
		void HdrDestAddressEndOfRange(const HexBinary &value); 

		// Is true if the field HdrDestAddressEndOfRange exists in the current object, otherwise is false.
		bool HdrDestAddressEndOfRangeExists() const;

		// Remove HdrDestAddressEndOfRange field.
		void RemoveHdrDestAddressEndOfRange(); 

		// Optional, HdrDestMask is an OctetString, of a size determined by the value of the HdrIPVersion property, representing a mask to be used in comparing the destination address in the IP header with the value represented in the HdrDestAddress property. 
		// 
		// If a value for this property is not provided, then the filter does not consider HdrDestMask in selecting matching packets, i.e., the value of the HdrDestAddress or the destination address range must match the destination address in the packet exactly. If a value for this property is provided, then HdrDestAddressEndOfRange MUST NOT be provided.
		const HexBinary HdrDestMask() const;

		// Optional, HdrDestMask is an OctetString, of a size determined by the value of the HdrIPVersion property, representing a mask to be used in comparing the destination address in the IP header with the value represented in the HdrDestAddress property. 
		// 
		// If a value for this property is not provided, then the filter does not consider HdrDestMask in selecting matching packets, i.e., the value of the HdrDestAddress or the destination address range must match the destination address in the packet exactly. If a value for this property is provided, then HdrDestAddressEndOfRange MUST NOT be provided.
		void HdrDestMask(const HexBinary &value); 

		// Is true if the field HdrDestMask exists in the current object, otherwise is false.
		bool HdrDestMaskExists() const;

		// Remove HdrDestMask field.
		void RemoveHdrDestMask(); 

		// Optional, HdrProtocolID is an 8-bit unsigned integer, representing an IP protocol type. This value is compared to the Protocol field in the IP header. 
		// 
		// If a value for this property is not provided, then the filter does not consider HdrProtocolID in selecting matching packets, i.e., HdrProtocolID matches for all values.
		const unsigned char HdrProtocolID() const;

		// Optional, HdrProtocolID is an 8-bit unsigned integer, representing an IP protocol type. This value is compared to the Protocol field in the IP header. 
		// 
		// If a value for this property is not provided, then the filter does not consider HdrProtocolID in selecting matching packets, i.e., HdrProtocolID matches for all values.
		void HdrProtocolID(const unsigned char &value); 

		// Is true if the field HdrProtocolID exists in the current object, otherwise is false.
		bool HdrProtocolIDExists() const;

		// Remove HdrProtocolID field.
		void RemoveHdrProtocolID(); 

		// Optional, HdrSrcPortStart represents the lower end of a range of UDP or TCP source ports. The upper end of the range is represented by the HdrSrcPortEnd property. The value of HdrSrcPortStart MUST be no greater than the value of HdrSrcPortEnd. A single port is indicated by equal values for HdrSrcPortStart and HdrSrcPortEnd. 
		// 
		// A source port filter is evaluated by testing whether the source port identified in the IP header falls within the range of values between HdrSrcPortStart and HdrSrcPortEnd, INCLUDING these two end points. 
		// 
		// If a value for this property is not provided, then the filter does not consider HdrSrcPortStart in selecting matching packets, i.e., there is no lower bound in matching source port values.
		const unsigned short HdrSrcPortStart() const;

		// Optional, HdrSrcPortStart represents the lower end of a range of UDP or TCP source ports. The upper end of the range is represented by the HdrSrcPortEnd property. The value of HdrSrcPortStart MUST be no greater than the value of HdrSrcPortEnd. A single port is indicated by equal values for HdrSrcPortStart and HdrSrcPortEnd. 
		// 
		// A source port filter is evaluated by testing whether the source port identified in the IP header falls within the range of values between HdrSrcPortStart and HdrSrcPortEnd, INCLUDING these two end points. 
		// 
		// If a value for this property is not provided, then the filter does not consider HdrSrcPortStart in selecting matching packets, i.e., there is no lower bound in matching source port values.
		void HdrSrcPortStart(const unsigned short value); 

		// Is true if the field HdrSrcPortStart exists in the current object, otherwise is false.
		bool HdrSrcPortStartExists() const;

		// Remove HdrSrcPortStart field.
		void RemoveHdrSrcPortStart(); 

		// Optional, HdrSrcPortEnd represents the upper end of a range of UDP or TCP source ports. The lower end of the range is represented by the HdrSrcPortStart property. The value of HdrSrcPortEnd MUST be no less than the value of HdrSrcPortStart. A single port is indicated by equal values for HdrSrcPortStart and HdrSrcPortEnd. 
		// 
		// A source port filter is evaluated by testing whether the source port identified in the IP header falls within the range of values between HdrSrcPortStart and HdrSrcPortEnd, INCLUDING these two end points. 
		// 
		// If a value for this property is not provided, then the filter does not consider HdrSrcPortEnd in selecting matching packets, i.e., there is no upper bound in matching source port values.
		const unsigned short HdrSrcPortEnd() const;

		// Optional, HdrSrcPortEnd represents the upper end of a range of UDP or TCP source ports. The lower end of the range is represented by the HdrSrcPortStart property. The value of HdrSrcPortEnd MUST be no less than the value of HdrSrcPortStart. A single port is indicated by equal values for HdrSrcPortStart and HdrSrcPortEnd. 
		// 
		// A source port filter is evaluated by testing whether the source port identified in the IP header falls within the range of values between HdrSrcPortStart and HdrSrcPortEnd, INCLUDING these two end points. 
		// 
		// If a value for this property is not provided, then the filter does not consider HdrSrcPortEnd in selecting matching packets, i.e., there is no upper bound in matching source port values.
		void HdrSrcPortEnd(const unsigned short value); 

		// Is true if the field HdrSrcPortEnd exists in the current object, otherwise is false.
		bool HdrSrcPortEndExists() const;

		// Remove HdrSrcPortEnd field.
		void RemoveHdrSrcPortEnd(); 

		// Optional, HdrDestPortStart represents the lower end of a range of UDP or TCP destination ports. The upper end of the range is represented by the HdrDestPortEnd property. The value of HdrDestPortStart MUST be no greater than the value of HdrDestPortEnd. A single port is indicated by equal values for HdrDestPortStart and HdrDestPortEnd. 
		// 
		// A destination port filter is evaluated by testing whether the destination port identified in the IP header falls within the range of values between HdrDestPortStart and HdrDestPortEnd, INCLUDING these two end points. 
		// 
		// If a value for this property is not provided, then the filter does not consider HdrDestPortStart in selecting matching packets, i.e., there is no lower bound in matching destination port values.
		const unsigned short HdrDestPortStart() const;

		// Optional, HdrDestPortStart represents the lower end of a range of UDP or TCP destination ports. The upper end of the range is represented by the HdrDestPortEnd property. The value of HdrDestPortStart MUST be no greater than the value of HdrDestPortEnd. A single port is indicated by equal values for HdrDestPortStart and HdrDestPortEnd. 
		// 
		// A destination port filter is evaluated by testing whether the destination port identified in the IP header falls within the range of values between HdrDestPortStart and HdrDestPortEnd, INCLUDING these two end points. 
		// 
		// If a value for this property is not provided, then the filter does not consider HdrDestPortStart in selecting matching packets, i.e., there is no lower bound in matching destination port values.
		void HdrDestPortStart(const unsigned short value); 

		// Is true if the field HdrDestPortStart exists in the current object, otherwise is false.
		bool HdrDestPortStartExists() const;

		// Remove HdrDestPortStart field.
		void RemoveHdrDestPortStart(); 

		// Optional, HdrDestPortEnd represents the upper end of a range of UDP or TCP destination ports. The lower end of the range is represented by the HdrDestPortStart property. The value of HdrDestPortEnd MUST be no less than the value of HdrDestPortStart. A single port is indicated by equal values for HdrDestPortStart and HdrDestPortEnd. 
		// 
		// A destination port filter is evaluated by testing whether the destination port identified in the IP header falls within the range of values between HdrDestPortStart and HdrDestPortEnd, INCLUDING these two end points. 
		// 
		// If a value for this property is not provided, then the filter does not consider HdrDestPortEnd in selecting matching packets, i.e., there is no upper bound in matching destination port values.
		const unsigned short HdrDestPortEnd() const;

		// Optional, HdrDestPortEnd represents the upper end of a range of UDP or TCP destination ports. The lower end of the range is represented by the HdrDestPortStart property. The value of HdrDestPortEnd MUST be no less than the value of HdrDestPortStart. A single port is indicated by equal values for HdrDestPortStart and HdrDestPortEnd. 
		// 
		// A destination port filter is evaluated by testing whether the destination port identified in the IP header falls within the range of values between HdrDestPortStart and HdrDestPortEnd, INCLUDING these two end points. 
		// 
		// If a value for this property is not provided, then the filter does not consider HdrDestPortEnd in selecting matching packets, i.e., there is no upper bound in matching destination port values.
		void HdrDestPortEnd(const unsigned short value); 

		// Is true if the field HdrDestPortEnd exists in the current object, otherwise is false.
		bool HdrDestPortEndExists() const;

		// Remove HdrDestPortEnd field.
		void RemoveHdrDestPortEnd(); 

		// Optional, HdrDSCP is defined as a set of discrete DiffServ code points, with no inherent structure. There is no semantically significant relationship between different HdrDSCPs. Consequently, there is no provision for specifying a range of HdrDSCPs. 
		// 
		// Since, in IPv4, the HdrDSCP field may contain bits to be interpreted as the TOS IP Precedence, this property is also used to filter on IP Precedence. Similarly, the IPv6 Traffic Class field is also filtered using the value(s) in this property. 
		// 
		// HdrDSCP is defined as an array, to provide the ability to specify several discrete DSCPs in a single instance of IPHeadersFilter, that would be OR'ed together to define the filter criteria. 
		// 
		// If a value for this property is not provided, then the filter does not consider HdrDSCP in selecting matching packets, i.e., HdrDSCP matches for all values.
		const vector<unsigned char> HdrDSCP() const;

		// Optional, HdrDSCP is defined as a set of discrete DiffServ code points, with no inherent structure. There is no semantically significant relationship between different HdrDSCPs. Consequently, there is no provision for specifying a range of HdrDSCPs. 
		// 
		// Since, in IPv4, the HdrDSCP field may contain bits to be interpreted as the TOS IP Precedence, this property is also used to filter on IP Precedence. Similarly, the IPv6 Traffic Class field is also filtered using the value(s) in this property. 
		// 
		// HdrDSCP is defined as an array, to provide the ability to specify several discrete DSCPs in a single instance of IPHeadersFilter, that would be OR'ed together to define the filter criteria. 
		// 
		// If a value for this property is not provided, then the filter does not consider HdrDSCP in selecting matching packets, i.e., HdrDSCP matches for all values.
		void HdrDSCP(const vector<unsigned char> &value); 

		// Is true if the field HdrDSCP exists in the current object, otherwise is false.
		bool HdrDSCPExists() const;

		// Remove HdrDSCP field.
		void RemoveHdrDSCP(); 

		// Optional, The 20-bit Flow Label field in the IPv6 header may be used by a source to label sequences of packets for which it requests special handling by the IPv6 devices, such as non-default quality of service or 'real-time' service. In the filter, this 20-bit string is encoded in a 24-bit octetstring by right-adjusting the value and padding on the left with b'0000'. 
		// 
		// If a value for this property is not provided, then the filter does not consider HdrFlowLabel in selecting matching packets, i.e., HdrFlowLabel matches for all values.
		const HexBinary HdrFlowLabel() const;

		// Optional, The 20-bit Flow Label field in the IPv6 header may be used by a source to label sequences of packets for which it requests special handling by the IPv6 devices, such as non-default quality of service or 'real-time' service. In the filter, this 20-bit string is encoded in a 24-bit octetstring by right-adjusting the value and padding on the left with b'0000'. 
		// 
		// If a value for this property is not provided, then the filter does not consider HdrFlowLabel in selecting matching packets, i.e., HdrFlowLabel matches for all values.
		void HdrFlowLabel(const HexBinary &value); 

		// Is true if the field HdrFlowLabel exists in the current object, otherwise is false.
		bool HdrFlowLabelExists() const;

		// Remove HdrFlowLabel field.
		void RemoveHdrFlowLabel(); 

		// Optional, A set of flags whose effective value in the TCP header of each packet must be ON for filter to take effect
		const vector<unsigned short> TCPFlagsOn() const;

		// Optional, A set of flags whose effective value in the TCP header of each packet must be ON for filter to take effect
		void TCPFlagsOn(const vector<unsigned short> &value); 

		// Is true if the field TCPFlagsOn exists in the current object, otherwise is false.
		bool TCPFlagsOnExists() const;

		// Remove TCPFlagsOn field.
		void RemoveTCPFlagsOn(); 

		// Optional, A set of flags whose effective value in the TCP header of each packet must be OFF for filter to take effect
		const vector<unsigned short> TCPFlagsOff() const;

		// Optional, A set of flags whose effective value in the TCP header of each packet must be OFF for filter to take effect
		void TCPFlagsOff(const vector<unsigned short> &value); 

		// Is true if the field TCPFlagsOff exists in the current object, otherwise is false.
		bool TCPFlagsOffExists() const;

		// Remove TCPFlagsOff field.
		void RemoveTCPFlagsOff(); 

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

		static vector<shared_ptr<AMT_IPHeadersFilter> > Enumerate(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		// Overloaded delete which supplies the internal resourceURI
		static void Delete(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		using CimBase::Delete;

	protected:
		 // Protected constructor to be used by derived classes
		AMT_IPHeadersFilter(ICimWsmanClient *client, const string &class_name,
			const string &class_ns, const string &prefix, const string &uri): AMT_ComplexFilterEntryBase(client, class_name, class_ns, prefix, uri)
		{
			if(_classMetaData.size() == 0)
			{
				AMT_ComplexFilterEntryBase::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 20);
			}
		}
		 // Protected constructor which receives CimObject
		AMT_IPHeadersFilter(const CimObject &object)
			: AMT_ComplexFilterEntryBase(object)
		{
			if(_classMetaData.size() == 0)
			{
				AMT_ComplexFilterEntryBase::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 20);
			}
		}
		// Called by derived classes
		void SetMetaData(vector<CimFieldAttribute>& childMetaData)
		{
			AMT_ComplexFilterEntryBase::SetMetaData(childMetaData);
			CimBase::SetMetaData(childMetaData, _metadata, 20);
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
#endif // AMT_IPHEADERSFILTER_H
