//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_ListenerDestinationWSManagement.h
//
//  Contents:   CIM_ListenerDestinationWSManagement describes the destination for CIM indications to be delivered via WS-Management.
//
//              This file was automatically generated from CIM_ListenerDestinationWSManagement.mof,  version: 2.22.0
//
//----------------------------------------------------------------------------
#ifndef CIM_LISTENERDESTINATIONWSMANAGEMENT_H
#define CIM_LISTENERDESTINATIONWSMANAGEMENT_H 1
#include "CIM_ListenerDestination.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	// CIM_ListenerDestinationWSManagement describes the destination for CIM indications to be delivered via WS-Management.
	class CIMFRAMEWORK_API CIM_ListenerDestinationWSManagement  : public CIM_ListenerDestination
	{
	public:

		//Default constructor
		CIM_ListenerDestinationWSManagement()
			: CIM_ListenerDestination(NULL, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_ListenerDestination::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 10);
			}
		}

		//constructor which receives WSMan client
		CIM_ListenerDestinationWSManagement(ICimWsmanClient *client)
			: CIM_ListenerDestination(client, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_ListenerDestination::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 10);
			}
		}

		//Destructor
		virtual ~CIM_ListenerDestinationWSManagement(){}

		// The "type" information for the object. Gettors only.
		virtual const string& ResourceURI() const { return CLASS_URI; }
		static const string& ClassResourceURI() { return CLASS_URI; }
		virtual const string& XmlNamespace() const { return CLASS_NS; }
		virtual const string& XmlPrefix() const { return CLASS_NS_PREFIX; }
		virtual const string& ObjectType() const { return CLASS_NAME; }
		static const string& ClassObjectType() { return CLASS_NAME; }

		// Class representing CIM_ListenerDestinationWSManagement keys
		class CimKeys : public CIM_ListenerDestination::CimKeys
		{
		public:
		};

		// class fields declarations

		// Optional, Separate To address for notice of abnormal subscription termination.
		const string DestinationEndTo() const;

		// Optional, Separate To address for notice of abnormal subscription termination.
		void DestinationEndTo(const string &value); 

		// Is true if the field DestinationEndTo exists in the current object, otherwise is false.
		bool DestinationEndToExists() const;

		// Remove DestinationEndTo field.
		void RemoveDestinationEndTo(); 

		// Optional, If the events contain localized content, the service should accept a subscription with this Locale block acting as a hint. The language of the event message is encoded in an xml:lang attribute using RFC 3066 language codes. The service should attempt to localize any descriptive content to the specified language when delivering such events.
		const string Locale() const;

		// Optional, If the events contain localized content, the service should accept a subscription with this Locale block acting as a hint. The language of the event message is encoded in an xml:lang attribute using RFC 3066 language codes. The service should attempt to localize any descriptive content to the specified language when delivering such events.
		void Locale(const string &value); 

		// Is true if the field Locale exists in the current object, otherwise is false.
		bool LocaleExists() const;

		// Remove Locale field.
		void RemoveLocale(); 

		// Optional, This block acts as a hint to indicate how the delivered events should be encoded. The two standard tokens defined for this purpose are "UTF-8" or "UTF-16", although other encoding formats may be specified if necessary.
		const string ContentEncoding() const;

		// Optional, This block acts as a hint to indicate how the delivered events should be encoded. The two standard tokens defined for this purpose are "UTF-8" or "UTF-16", although other encoding formats may be specified if necessary.
		void ContentEncoding(const string &value); 

		// Is true if the field ContentEncoding exists in the current object, otherwise is false.
		bool ContentEncodingExists() const;

		// Remove ContentEncoding field.
		void RemoveContentEncoding(); 

		// Optional, Method by which the service is to deliver events to the client. Values are as follows. Push (2): the event is sent to the destination address; depending on the protocol, delivery may not be guaranteed. PushWithAck (3): the service sends the event and waits for a specific acknowledgment message from the subscriber. Events (4): the service collects events into batches and sends the batches to the subscriber. Pull (5): the service collects the events into batches and the subscriber pulls each batch from the service using wxf:Pull.
		const unsigned short DeliveryMode() const;

		// Optional, Method by which the service is to deliver events to the client. Values are as follows. Push (2): the event is sent to the destination address; depending on the protocol, delivery may not be guaranteed. PushWithAck (3): the service sends the event and waits for a specific acknowledgment message from the subscriber. Events (4): the service collects events into batches and sends the batches to the subscriber. Pull (5): the service collects the events into batches and the subscriber pulls each batch from the service using wxf:Pull.
		void DeliveryMode(const unsigned short value); 

		// Is true if the field DeliveryMode exists in the current object, otherwise is false.
		bool DeliveryModeExists() const;

		// Remove DeliveryMode field.
		void RemoveDeliveryMode(); 

		// Optional, Specifies how often heartbeat events are added to the event stream at the specified interval.
		const Uint64 Heartbeat() const;

		// Optional, Specifies how often heartbeat events are added to the event stream at the specified interval.
		void Heartbeat(const Uint64 value); 

		// Is true if the field Heartbeat exists in the current object, otherwise is false.
		bool HeartbeatExists() const;

		// Remove Heartbeat field.
		void RemoveHeartbeat(); 

		// Optional, A property element that instructs the service to send a bookmark with each event. Bookmarks apply to all delivery modes. The bookmark is a token which represents an abstract pointer in the event stream, but whether it points to the last delivered event or the last event plus one (the upcoming event) makes no difference since the token is supplied to the same implementation during a subsequent wse:Subscribe operation. The service may thus attach any service-specific meaning and structure to the bookmark with no change to the client.
		const bool SendBookmark() const;

		// Optional, A property element that instructs the service to send a bookmark with each event. Bookmarks apply to all delivery modes. The bookmark is a token which represents an abstract pointer in the event stream, but whether it points to the last delivered event or the last event plus one (the upcoming event) makes no difference since the token is supplied to the same implementation during a subsequent wse:Subscribe operation. The service may thus attach any service-specific meaning and structure to the bookmark with no change to the client.
		void SendBookmark(const bool value); 

		// Is true if the field SendBookmark exists in the current object, otherwise is false.
		bool SendBookmarkExists() const;

		// Remove SendBookmark field.
		void RemoveSendBookmark(); 

		// Optional, This element may contain a duration that indicates the maximum amount of time the service should allow to elapse while batching EVENT bodies. That is, this time may not be exceeded between the encoding of the first event in the batch and the dispatching of the batch for delivery.
		const Uint64 MaxTime() const;

		// Optional, This element may contain a duration that indicates the maximum amount of time the service should allow to elapse while batching EVENT bodies. That is, this time may not be exceeded between the encoding of the first event in the batch and the dispatching of the batch for delivery.
		void MaxTime(const Uint64 value); 

		// Is true if the field MaxTime exists in the current object, otherwise is false.
		bool MaxTimeExists() const;

		// Remove MaxTime field.
		void RemoveMaxTime(); 

		// Optional, A URI identifying the WS-Management security profile to be used by the service (acting as publisher) when authenticating to the event sink (consumer) at event delivery time.
		const string DeliveryAuth() const;

		// Optional, A URI identifying the WS-Management security profile to be used by the service (acting as publisher) when authenticating to the event sink (consumer) at event delivery time.
		void DeliveryAuth(const string &value); 

		// Is true if the field DeliveryAuth exists in the current object, otherwise is false.
		bool DeliveryAuthExists() const;

		// Remove DeliveryAuth field.
		void RemoveDeliveryAuth(); 

		// Optional, Specifies the treatment of Indication subclasses, whether subclasses are to be included and with what set of properties. Valid values are: None, IncludeSubclassProperties, and ExcludeSubclassProperties. Using None, only instances of the parent class are included in the output (event stream). For other modes, subclass instances are included with the sets of properties stated.
		const unsigned short PolyMorphismMode() const;

		// Optional, Specifies the treatment of Indication subclasses, whether subclasses are to be included and with what set of properties. Valid values are: None, IncludeSubclassProperties, and ExcludeSubclassProperties. Using None, only instances of the parent class are included in the output (event stream). For other modes, subclass instances are included with the sets of properties stated.
		void PolyMorphismMode(const unsigned short value); 

		// Is true if the field PolyMorphismMode exists in the current object, otherwise is false.
		bool PolyMorphismModeExists() const;

		// Remove PolyMorphismMode field.
		void RemovePolyMorphismMode(); 

		 // Function used by the factory
		static CimBase *CreateFromCimObject(const CimObject &object);

		static vector<shared_ptr<CIM_ListenerDestinationWSManagement> > Enumerate(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		// Overloaded delete which supplies the internal resourceURI
		static void Delete(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		using CimBase::Delete;

	protected:
		 // Protected constructor to be used by derived classes
		CIM_ListenerDestinationWSManagement(ICimWsmanClient *client, const string &class_name,
			const string &class_ns, const string &prefix, const string &uri): CIM_ListenerDestination(client, class_name, class_ns, prefix, uri)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_ListenerDestination::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 10);
			}
		}
		 // Protected constructor which receives CimObject
		CIM_ListenerDestinationWSManagement(const CimObject &object)
			: CIM_ListenerDestination(object)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_ListenerDestination::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 10);
			}
		}
		// Called by derived classes
		void SetMetaData(vector<CimFieldAttribute>& childMetaData)
		{
			CIM_ListenerDestination::SetMetaData(childMetaData);
			CimBase::SetMetaData(childMetaData, _metadata, 10);
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
#endif // CIM_LISTENERDESTINATIONWSMANAGEMENT_H
