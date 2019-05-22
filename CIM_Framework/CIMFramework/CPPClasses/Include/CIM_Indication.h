//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_Indication.h
//
//  Contents:   CIM_Indication is the abstract root class for all notifications about changes in schema, objects and their data, and about events detected by providers and instrumentation. Subclasses represent specific types of notifications. 
//              
//              To receive an Indication, a consumer (or subscriber) must create an instance of CIM_IndicationFilter describing the criteria of the notification, an instance of CIM_ListenerDestination describing the delivery of the notification, and an instance of CIM_IndicationSubscription associating the Filter and Handler.
//
//              This file was automatically generated from CIM_Indication.mof,  version: 2.24.0
//
//----------------------------------------------------------------------------
#ifndef CIM_INDICATION_H
#define CIM_INDICATION_H 1
#include "../../include/CimBase.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	// CIM_Indication is the abstract root class for all notifications about changes in schema, objects and their data, and about events detected by providers and instrumentation. Subclasses represent specific types of notifications. 
	// 
	// To receive an Indication, a consumer (or subscriber) must create an instance of CIM_IndicationFilter describing the criteria of the notification, an instance of CIM_ListenerDestination describing the delivery of the notification, and an instance of CIM_IndicationSubscription associating the Filter and Handler.
	class CIMFRAMEWORK_API CIM_Indication  : public CimBase
	{
	public:

		//Default constructor
		CIM_Indication()
			: CimBase(NULL, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CimBase::SetMetaData(_classMetaData, _metadata, 8);
			}
		}

		//constructor which receives WSMan client
		CIM_Indication(ICimWsmanClient *client)
			: CimBase(client, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CimBase::SetMetaData(_classMetaData, _metadata, 8);
			}
		}

		//Destructor
		virtual ~CIM_Indication(){}

		// The "type" information for the object. Gettors only.
		virtual const string& ResourceURI() const { return CLASS_URI; }
		static const string& ClassResourceURI() { return CLASS_URI; }
		virtual const string& XmlNamespace() const { return CLASS_NS; }
		virtual const string& XmlPrefix() const { return CLASS_NS_PREFIX; }
		virtual const string& ObjectType() const { return CLASS_NAME; }
		static const string& ClassObjectType() { return CLASS_NAME; }

		// Class representing CIM_Indication keys
		class CimKeys : public CimBase::CimKeys
		{
		public:
		};

		// class fields declarations

		// Optional, An identifier for the Indication. This property is similar to a key value in that it can be used for identification, when correlating Indications (see the CorrelatedIndications array). Its value SHOULD be unique as long as correlations are reported, but MAY be reused or left NULL if no future Indications will reference it in their CorrelatedIndications array.To ensure uniqueness, the value of IndicationIdentifier should be constructed using the following "preferred" algorithm: 
		// <OrgID>:<LocalID> 
		// Where <OrgID> and <LocalID> are separated by a colon (:), and where <OrgID> must include a copyrighted, trademarked, or otherwise unique name that is owned by the business entity that is creating or defining the IndicationIdentifier or that is a recognized ID that is assigned to the business entity by a recognized global authority. (This requirement is similar to the <Schema Name>_<Class Name> structure of Schema class names.) In addition, to ensure uniqueness <OrgID> must not contain a colon (:). When using this algorithm, the first colon to appear in IndicationIdentifier must appear between <OrgID> and <LocalID>. 
		// <LocalID> is chosen by the business entity and should not be re-used to identify different underlying (real-world) elements. 
		// If the above "preferred" algorithm is not used, the defining entity should assure that the resulting IndicationIdentifier is not re-used across any IndicationIdentifiers that are produced by this or other providers for the NameSpace of this instance. 
		// For DMTF-defined instances, the "preferred" algorithm should be used with the <OrgID> set to CIM.
		const string IndicationIdentifier() const;

		// Optional, An identifier for the Indication. This property is similar to a key value in that it can be used for identification, when correlating Indications (see the CorrelatedIndications array). Its value SHOULD be unique as long as correlations are reported, but MAY be reused or left NULL if no future Indications will reference it in their CorrelatedIndications array.To ensure uniqueness, the value of IndicationIdentifier should be constructed using the following "preferred" algorithm: 
		// <OrgID>:<LocalID> 
		// Where <OrgID> and <LocalID> are separated by a colon (:), and where <OrgID> must include a copyrighted, trademarked, or otherwise unique name that is owned by the business entity that is creating or defining the IndicationIdentifier or that is a recognized ID that is assigned to the business entity by a recognized global authority. (This requirement is similar to the <Schema Name>_<Class Name> structure of Schema class names.) In addition, to ensure uniqueness <OrgID> must not contain a colon (:). When using this algorithm, the first colon to appear in IndicationIdentifier must appear between <OrgID> and <LocalID>. 
		// <LocalID> is chosen by the business entity and should not be re-used to identify different underlying (real-world) elements. 
		// If the above "preferred" algorithm is not used, the defining entity should assure that the resulting IndicationIdentifier is not re-used across any IndicationIdentifiers that are produced by this or other providers for the NameSpace of this instance. 
		// For DMTF-defined instances, the "preferred" algorithm should be used with the <OrgID> set to CIM.
		void IndicationIdentifier(const string &value); 

		// Is true if the field IndicationIdentifier exists in the current object, otherwise is false.
		bool IndicationIdentifierExists() const;

		// Remove IndicationIdentifier field.
		void RemoveIndicationIdentifier(); 

		// Optional, A list of IndicationIdentifiers whose notifications are correlated with (related to) this one.
		const vector<string> CorrelatedIndications() const;

		// Optional, A list of IndicationIdentifiers whose notifications are correlated with (related to) this one.
		void CorrelatedIndications(const vector<string> &value); 

		// Is true if the field CorrelatedIndications exists in the current object, otherwise is false.
		bool CorrelatedIndicationsExists() const;

		// Remove CorrelatedIndications field.
		void RemoveCorrelatedIndications(); 

		// Optional, The time and date of creation of the Indication. The property may be set to NULL if the entity creating the Indication is not capable of determining this information. Note that IndicationTime may be the same for two Indications that are generated in rapid succession.
		const CimDateTime IndicationTime() const;

		// Optional, The time and date of creation of the Indication. The property may be set to NULL if the entity creating the Indication is not capable of determining this information. Note that IndicationTime may be the same for two Indications that are generated in rapid succession.
		void IndicationTime(const CimDateTime &value); 

		// Is true if the field IndicationTime exists in the current object, otherwise is false.
		bool IndicationTimeExists() const;

		// Remove IndicationTime field.
		void RemoveIndicationTime(); 

		// Optional, An enumerated value that describes the severity of the Indication from the notifier's point of view: 
		// 1 - Other, by CIM convention, is used to indicate that the Severity's value can be found in the OtherSeverity property. 
		// 3 - Degraded/Warning should be used when its appropriate to let the user decide if action is needed. 
		// 4 - Minor should be used to indicate action is needed, but the situation is not serious at this time. 
		// 5 - Major should be used to indicate action is needed NOW. 
		// 6 - Critical should be used to indicate action is needed NOW and the scope is broad (perhaps an imminent outage to a critical resource will result). 
		// 7 - Fatal/NonRecoverable should be used to indicate an error occurred, but it's too late to take remedial action. 
		// 2 and 0 - Information and Unknown (respectively) follow common usage. Literally, the Indication is purely informational or its severity is simply unknown.
		const unsigned short PerceivedSeverity() const;

		// Optional, An enumerated value that describes the severity of the Indication from the notifier's point of view: 
		// 1 - Other, by CIM convention, is used to indicate that the Severity's value can be found in the OtherSeverity property. 
		// 3 - Degraded/Warning should be used when its appropriate to let the user decide if action is needed. 
		// 4 - Minor should be used to indicate action is needed, but the situation is not serious at this time. 
		// 5 - Major should be used to indicate action is needed NOW. 
		// 6 - Critical should be used to indicate action is needed NOW and the scope is broad (perhaps an imminent outage to a critical resource will result). 
		// 7 - Fatal/NonRecoverable should be used to indicate an error occurred, but it's too late to take remedial action. 
		// 2 and 0 - Information and Unknown (respectively) follow common usage. Literally, the Indication is purely informational or its severity is simply unknown.
		void PerceivedSeverity(const unsigned short value); 

		// Is true if the field PerceivedSeverity exists in the current object, otherwise is false.
		bool PerceivedSeverityExists() const;

		// Remove PerceivedSeverity field.
		void RemovePerceivedSeverity(); 

		// Optional, Holds the value of the user defined severity value when 'PerceivedSeverity' is 1 ("Other").
		const string OtherSeverity() const;

		// Optional, Holds the value of the user defined severity value when 'PerceivedSeverity' is 1 ("Other").
		void OtherSeverity(const string &value); 

		// Is true if the field OtherSeverity exists in the current object, otherwise is false.
		bool OtherSeverityExists() const;

		// Remove OtherSeverity field.
		void RemoveOtherSeverity(); 

		// Optional, An identifier for the indication filter that selects this indication and causes it to be sent. This property is to be filled out by the indication sending service. The value shall be correlatable with the Name property of the instance of CIM_IndicationFilter describing the criteria of the indication. The value of the IndicationFilterName should be formatted using the following algorithm: < OrgID > : < LocalID >, where < OrgID > and < LocalID > are separated by a colon (:) and < OrgID > shall include a copyrighted, trademarked, or otherwise unique name that is owned by the business entity that is creating or defining the value or that is a registered ID assigned to the business entity by a recognized global authority. In addition, to ensure uniqueness, < OrgID > shall not contain a colon (:).When using this algorithm, the first colon to appear in the value shall appear between < OrgID > and < LocalID >. < LocalID > is chosen by the business entity and shall be used uniquely.
		const string IndicationFilterName() const;

		// Optional, An identifier for the indication filter that selects this indication and causes it to be sent. This property is to be filled out by the indication sending service. The value shall be correlatable with the Name property of the instance of CIM_IndicationFilter describing the criteria of the indication. The value of the IndicationFilterName should be formatted using the following algorithm: < OrgID > : < LocalID >, where < OrgID > and < LocalID > are separated by a colon (:) and < OrgID > shall include a copyrighted, trademarked, or otherwise unique name that is owned by the business entity that is creating or defining the value or that is a registered ID assigned to the business entity by a recognized global authority. In addition, to ensure uniqueness, < OrgID > shall not contain a colon (:).When using this algorithm, the first colon to appear in the value shall appear between < OrgID > and < LocalID >. < LocalID > is chosen by the business entity and shall be used uniquely.
		void IndicationFilterName(const string &value); 

		// Is true if the field IndicationFilterName exists in the current object, otherwise is false.
		bool IndicationFilterNameExists() const;

		// Remove IndicationFilterName field.
		void RemoveIndicationFilterName(); 

		// Optional, The sequence context portion of a sequence identifier for the indication. The sequence number portion of the sequence identifier is provided by the SequenceNumber property. The combination of both property values represents the sequence identifier for the indication.
		// The sequence identifier for the indication enables a CIM listener to identify duplicate indications when the CIM service attempts the delivery retry of indications, to reorder indications that arrive out-of-order, and to detect lost indications.
		// If a CIM service does not support sequence identifiers for indications, this property shall be NULL.
		// If a CIM service supports sequence identifiers for indications, this property shall be maintained by the CIM service for each registered listener destination, and its value shall uniquely identify the CIM service and the indication service within the CIM service such that restarts of the CIM service and deregistration of listener destinations to the CIM service cause the value to change, without reusing earlier values for a sufficiently long time.
		// When retrying the delivery of an indication, this property shall have the same value as in the original delivery.
		// To guarantee this uniqueness, the property value should be constructed using the following format (defined in ABNF): sequence-context = indication-service-name "#" cim-service-start-id "#" listener-destination-creation-time
		// Where: indication-service-name is the value of the Name property of the CIM_IndicationService instance responsible for delivering the indication. cim-service-start-id is an identifier that uniquely identifies the CIM service start, for example via a timestamp of the start time, or via a counter that increases for each start or restart. listener-destination-creation-time is a timestamp of the creation time of the CIM_ListenerDestination instance representing the listener destination.
		// Since this format is only a recommendation, CIM clients shall treat the value as an opaque identifier for the sequence context and shall not rely on this format.
		const string SequenceContext() const;

		// Optional, The sequence context portion of a sequence identifier for the indication. The sequence number portion of the sequence identifier is provided by the SequenceNumber property. The combination of both property values represents the sequence identifier for the indication.
		// The sequence identifier for the indication enables a CIM listener to identify duplicate indications when the CIM service attempts the delivery retry of indications, to reorder indications that arrive out-of-order, and to detect lost indications.
		// If a CIM service does not support sequence identifiers for indications, this property shall be NULL.
		// If a CIM service supports sequence identifiers for indications, this property shall be maintained by the CIM service for each registered listener destination, and its value shall uniquely identify the CIM service and the indication service within the CIM service such that restarts of the CIM service and deregistration of listener destinations to the CIM service cause the value to change, without reusing earlier values for a sufficiently long time.
		// When retrying the delivery of an indication, this property shall have the same value as in the original delivery.
		// To guarantee this uniqueness, the property value should be constructed using the following format (defined in ABNF): sequence-context = indication-service-name "#" cim-service-start-id "#" listener-destination-creation-time
		// Where: indication-service-name is the value of the Name property of the CIM_IndicationService instance responsible for delivering the indication. cim-service-start-id is an identifier that uniquely identifies the CIM service start, for example via a timestamp of the start time, or via a counter that increases for each start or restart. listener-destination-creation-time is a timestamp of the creation time of the CIM_ListenerDestination instance representing the listener destination.
		// Since this format is only a recommendation, CIM clients shall treat the value as an opaque identifier for the sequence context and shall not rely on this format.
		void SequenceContext(const string &value); 

		// Is true if the field SequenceContext exists in the current object, otherwise is false.
		bool SequenceContextExists() const;

		// Remove SequenceContext field.
		void RemoveSequenceContext(); 

		// Optional, The sequence number portion of a sequence identifier for the indication. The sequence context portion of the sequence identifier is provided by the SequenceContext property. The combination of both property values represents the sequence identifier for the indication.
		// The sequence identifier for the indication enables a CIM listener to identify duplicate indications when the CIM service attempts the delivery retry of indications, to reorder indications that arrive out-of-order, and to detect lost indications.
		// If a CIM service does not support sequence identifiers for indications, this property shall be NULL.
		// If a CIM service supports sequence identifiers for indications, this property shall be maintained by the CIM service for each registered listener destination, and its value shall uniquely identify the indication within the sequence context provided by SequenceContext. It shall start at 0 whenever the sequence context string changes. Otherwise, it shall be increased by 1 for every new indication to that listener destination, and it shall wrap to 0 when the value range is exceeded.
		// When retrying the delivery of an indication, this property shall have the same value as in the original delivery.
		const Int64 SequenceNumber() const;

		// Optional, The sequence number portion of a sequence identifier for the indication. The sequence context portion of the sequence identifier is provided by the SequenceContext property. The combination of both property values represents the sequence identifier for the indication.
		// The sequence identifier for the indication enables a CIM listener to identify duplicate indications when the CIM service attempts the delivery retry of indications, to reorder indications that arrive out-of-order, and to detect lost indications.
		// If a CIM service does not support sequence identifiers for indications, this property shall be NULL.
		// If a CIM service supports sequence identifiers for indications, this property shall be maintained by the CIM service for each registered listener destination, and its value shall uniquely identify the indication within the sequence context provided by SequenceContext. It shall start at 0 whenever the sequence context string changes. Otherwise, it shall be increased by 1 for every new indication to that listener destination, and it shall wrap to 0 when the value range is exceeded.
		// When retrying the delivery of an indication, this property shall have the same value as in the original delivery.
		void SequenceNumber(const Int64 value); 

		// Is true if the field SequenceNumber exists in the current object, otherwise is false.
		bool SequenceNumberExists() const;

		// Remove SequenceNumber field.
		void RemoveSequenceNumber(); 

		 // Function used by the factory
		static CimBase *CreateFromCimObject(const CimObject &object);

		static vector<shared_ptr<CIM_Indication> > Enumerate(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		// Overloaded delete which supplies the internal resourceURI
		static void Delete(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		using CimBase::Delete;

	protected:
		 // Protected constructor to be used by derived classes
		CIM_Indication(ICimWsmanClient *client, const string &class_name,
			const string &class_ns, const string &prefix, const string &uri): CimBase(client, class_name, class_ns, prefix, uri)
		{
			if(_classMetaData.size() == 0)
			{
				CimBase::SetMetaData(_classMetaData, _metadata, 8);
			}
		}
		 // Protected constructor which receives CimObject
		CIM_Indication(const CimObject &object)
			: CimBase(object)
		{
			if(_classMetaData.size() == 0)
			{
				CimBase::SetMetaData(_classMetaData, _metadata, 8);
			}
		}
		// Called by derived classes
		void SetMetaData(vector<CimFieldAttribute>& childMetaData)
		{
			CimBase::SetMetaData(childMetaData, _metadata, 8);
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
#endif // CIM_INDICATION_H
