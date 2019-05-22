//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_AlertIndication.h
//
//  Contents:   A concrete superclass for CIM Alert notifications. An AlertIndication is a specialized type of CIM_Indication that contains information about the severity, cause, recommended actions and other data of a real world event. This event and its data may or may not be modeled in the CIM class hierarchy.
//
//              This file was automatically generated from CIM_AlertIndication.mof,  version: 2.27.0
//
//----------------------------------------------------------------------------
#ifndef CIM_ALERTINDICATION_H
#define CIM_ALERTINDICATION_H 1
#include "CIM_ProcessIndication.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	// A concrete superclass for CIM Alert notifications. An AlertIndication is a specialized type of CIM_Indication that contains information about the severity, cause, recommended actions and other data of a real world event. This event and its data may or may not be modeled in the CIM class hierarchy.
	class CIMFRAMEWORK_API CIM_AlertIndication  : public CIM_ProcessIndication
	{
	public:

		//Default constructor
		CIM_AlertIndication()
			: CIM_ProcessIndication(NULL, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_ProcessIndication::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 20);
			}
		}

		//constructor which receives WSMan client
		CIM_AlertIndication(ICimWsmanClient *client)
			: CIM_ProcessIndication(client, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_ProcessIndication::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 20);
			}
		}

		//Destructor
		virtual ~CIM_AlertIndication(){}

		// The "type" information for the object. Gettors only.
		virtual const string& ResourceURI() const { return CLASS_URI; }
		static const string& ClassResourceURI() { return CLASS_URI; }
		virtual const string& XmlNamespace() const { return CLASS_NS; }
		virtual const string& XmlPrefix() const { return CLASS_NS_PREFIX; }
		virtual const string& ObjectType() const { return CLASS_NAME; }
		static const string& ClassObjectType() { return CLASS_NAME; }

		// Class representing CIM_AlertIndication keys
		class CimKeys : public CIM_ProcessIndication::CimKeys
		{
		public:
		};

		// class fields declarations

		// Optional, A short description of the Indication.
		const string Description() const;

		// Optional, A short description of the Indication.
		void Description(const string &value); 

		// Is true if the field Description exists in the current object, otherwise is false.
		bool DescriptionExists() const;

		// Remove Description field.
		void RemoveDescription(); 

		// Optional, The identifying information of the entity (ie, the instance) for which this Indication is generated. The property contains the path of an instance, encoded as a string parameter - if the instance is modeled in the CIM Schema. If not a CIM instance, the property contains some identifying string that names the entity for which the Alert is generated. The path or identifying string is formatted per the AlertingElementFormat property.
		const string AlertingManagedElement() const;

		// Optional, The identifying information of the entity (ie, the instance) for which this Indication is generated. The property contains the path of an instance, encoded as a string parameter - if the instance is modeled in the CIM Schema. If not a CIM instance, the property contains some identifying string that names the entity for which the Alert is generated. The path or identifying string is formatted per the AlertingElementFormat property.
		void AlertingManagedElement(const string &value); 

		// Is true if the field AlertingManagedElement exists in the current object, otherwise is false.
		bool AlertingManagedElementExists() const;

		// Remove AlertingManagedElement field.
		void RemoveAlertingManagedElement(); 

		// Optional, The format of the AlertingManagedElement property is interpretable based upon the value of this property. Values are defined as: 
		// 0 - Unknown. The format is unknown or not meaningfully interpretable by a CIM client application. 
		// 1 - Other. The format is defined by the value of the OtherAlertingElementFormat property. 
		// 2 - CIMObjectPath. The format is a CIMObjectPath, with format <NamespacePath>:<ClassName>.<Prop1>="<Value1>", <Prop2>="<Value2>", . . . specifying an instance in the CIM Schema.
		const unsigned short AlertingElementFormat() const;

		// Optional, The format of the AlertingManagedElement property is interpretable based upon the value of this property. Values are defined as: 
		// 0 - Unknown. The format is unknown or not meaningfully interpretable by a CIM client application. 
		// 1 - Other. The format is defined by the value of the OtherAlertingElementFormat property. 
		// 2 - CIMObjectPath. The format is a CIMObjectPath, with format <NamespacePath>:<ClassName>.<Prop1>="<Value1>", <Prop2>="<Value2>", . . . specifying an instance in the CIM Schema.
		void AlertingElementFormat(const unsigned short value); 

		// Is true if the field AlertingElementFormat exists in the current object, otherwise is false.
		bool AlertingElementFormatExists() const;

		// Remove AlertingElementFormat field.
		void RemoveAlertingElementFormat(); 

		// Optional, A string defining "Other" values for AlertingElementFormat. This value MUST be set to a non NULL value when AlertingElementFormat is set to a value of 1 ("Other"). For all other values of AlertingElementFormat, the value of this string must be set to NULL.
		const string OtherAlertingElementFormat() const;

		// Optional, A string defining "Other" values for AlertingElementFormat. This value MUST be set to a non NULL value when AlertingElementFormat is set to a value of 1 ("Other"). For all other values of AlertingElementFormat, the value of this string must be set to NULL.
		void OtherAlertingElementFormat(const string &value); 

		// Is true if the field OtherAlertingElementFormat exists in the current object, otherwise is false.
		bool OtherAlertingElementFormatExists() const;

		// Remove OtherAlertingElementFormat field.
		void RemoveOtherAlertingElementFormat(); 

		// Required, Primary classification of the Indication. The following values are defined: 
		// 1 - Other. The Indication's OtherAlertType property conveys its classification. Use of "Other" in an enumeration is a standard CIM convention. It means that the current Indication does not fit into the categories described by this enumeration. 
		// 2 - Communications Alert. An Indication of this type is principally associated with the procedures and/or processes required to convey information from one point to another. 
		// 3 - Quality of Service Alert. An Indication of this type is principally associated with a degradation or errors in the performance or function of an entity. 
		// 4 - Processing Error. An Indication of this type is principally associated with a software or processing fault. 
		// 5 - Device Alert. An Indication of this type is principally associated with an equipment or hardware fault. 
		// 6 - Environmental Alert. An Indication of this type is principally associated with a condition relating to an enclosure in which the hardware resides, or other environmental considerations. 
		// 7 - Model Change. The Indication addresses changes in the Information Model. For example, it may embed a Lifecycle Indication to convey the specific model change being alerted. 
		// 8 - Security Alert. An Indication of this type is associated with security violations, detection of viruses, and similar issues.
		const unsigned short AlertType() const;

		// Required, Primary classification of the Indication. The following values are defined: 
		// 1 - Other. The Indication's OtherAlertType property conveys its classification. Use of "Other" in an enumeration is a standard CIM convention. It means that the current Indication does not fit into the categories described by this enumeration. 
		// 2 - Communications Alert. An Indication of this type is principally associated with the procedures and/or processes required to convey information from one point to another. 
		// 3 - Quality of Service Alert. An Indication of this type is principally associated with a degradation or errors in the performance or function of an entity. 
		// 4 - Processing Error. An Indication of this type is principally associated with a software or processing fault. 
		// 5 - Device Alert. An Indication of this type is principally associated with an equipment or hardware fault. 
		// 6 - Environmental Alert. An Indication of this type is principally associated with a condition relating to an enclosure in which the hardware resides, or other environmental considerations. 
		// 7 - Model Change. The Indication addresses changes in the Information Model. For example, it may embed a Lifecycle Indication to convey the specific model change being alerted. 
		// 8 - Security Alert. An Indication of this type is associated with security violations, detection of viruses, and similar issues.
		void AlertType(const unsigned short value); 

		// Is true if the field AlertType exists in the current object, otherwise is false.
		bool AlertTypeExists() const;

		// Remove AlertType field.
		void RemoveAlertType(); 

		// Optional, A string describing the Alert type - used when the AlertType property is set to 1, "Other State Change".
		const string OtherAlertType() const;

		// Optional, A string describing the Alert type - used when the AlertType property is set to 1, "Other State Change".
		void OtherAlertType(const string &value); 

		// Is true if the field OtherAlertType exists in the current object, otherwise is false.
		bool OtherAlertTypeExists() const;

		// Remove OtherAlertType field.
		void RemoveOtherAlertType(); 

		// Required, An enumerated value that describes the probable cause of the situation which resulted in the AlertIndication.
		const unsigned short ProbableCause() const;

		// Required, An enumerated value that describes the probable cause of the situation which resulted in the AlertIndication.
		void ProbableCause(const unsigned short value); 

		// Is true if the field ProbableCause exists in the current object, otherwise is false.
		bool ProbableCauseExists() const;

		// Remove ProbableCause field.
		void RemoveProbableCause(); 

		// Optional, Provides additional information related to the ProbableCause.
		const string ProbableCauseDescription() const;

		// Optional, Provides additional information related to the ProbableCause.
		void ProbableCauseDescription(const string &value); 

		// Is true if the field ProbableCauseDescription exists in the current object, otherwise is false.
		bool ProbableCauseDescriptionExists() const;

		// Remove ProbableCauseDescription field.
		void RemoveProbableCauseDescription(); 

		// Optional, Provides information on trending - trending up, down or no change.
		const unsigned short Trending() const;

		// Optional, Provides information on trending - trending up, down or no change.
		void Trending(const unsigned short value); 

		// Is true if the field Trending exists in the current object, otherwise is false.
		bool TrendingExists() const;

		// Remove Trending field.
		void RemoveTrending(); 

		// Optional, Free form descriptions of the recommended actions to take to resolve the cause of the notification.
		const vector<string> RecommendedActions() const;

		// Optional, Free form descriptions of the recommended actions to take to resolve the cause of the notification.
		void RecommendedActions(const vector<string> &value); 

		// Is true if the field RecommendedActions exists in the current object, otherwise is false.
		bool RecommendedActionsExists() const;

		// Remove RecommendedActions field.
		void RemoveRecommendedActions(); 

		// Optional, An instrumentation or provider specific value that describes the underlying "real-world" event represented by the Indication. Two Indications with the same, non NULL EventID value are considered, by the creating entity, to represent the same event. The comparison of two EventID values is only defined for Alert Indications with identical, non NULL values of SystemCreateClassName, SystemName and ProviderName.
		const string EventID() const;

		// Optional, An instrumentation or provider specific value that describes the underlying "real-world" event represented by the Indication. Two Indications with the same, non NULL EventID value are considered, by the creating entity, to represent the same event. The comparison of two EventID values is only defined for Alert Indications with identical, non NULL values of SystemCreateClassName, SystemName and ProviderName.
		void EventID(const string &value); 

		// Is true if the field EventID exists in the current object, otherwise is false.
		bool EventIDExists() const;

		// Remove EventID field.
		void RemoveEventID(); 

		// Optional, The time and date the underlying event was first detected. If specified, this property MUST be set to NULL if the creating entity is not capable of providing this information. This value is based on the notion of local date and time of the Managed System Element generating the Indication.
		const CimDateTime EventTime() const;

		// Optional, The time and date the underlying event was first detected. If specified, this property MUST be set to NULL if the creating entity is not capable of providing this information. This value is based on the notion of local date and time of the Managed System Element generating the Indication.
		void EventTime(const CimDateTime &value); 

		// Is true if the field EventTime exists in the current object, otherwise is false.
		bool EventTimeExists() const;

		// Remove EventTime field.
		void RemoveEventTime(); 

		// Optional, The scoping System's CreationClassName for the Provider generating this Indication.
		const string SystemCreationClassName() const;

		// Optional, The scoping System's CreationClassName for the Provider generating this Indication.
		void SystemCreationClassName(const string &value); 

		// Is true if the field SystemCreationClassName exists in the current object, otherwise is false.
		bool SystemCreationClassNameExists() const;

		// Remove SystemCreationClassName field.
		void RemoveSystemCreationClassName(); 

		// Optional, The scoping System's Name for the Provider generating this Indication.
		const string SystemName() const;

		// Optional, The scoping System's Name for the Provider generating this Indication.
		void SystemName(const string &value); 

		// Is true if the field SystemName exists in the current object, otherwise is false.
		bool SystemNameExists() const;

		// Remove SystemName field.
		void RemoveSystemName(); 

		// Optional, The name of the Provider generating this Indication.
		const string ProviderName() const;

		// Optional, The name of the Provider generating this Indication.
		void ProviderName(const string &value); 

		// Is true if the field ProviderName exists in the current object, otherwise is false.
		bool ProviderNameExists() const;

		// Remove ProviderName field.
		void RemoveProviderName(); 

		// Optional, The formatted message. This message is constructed by combining some or all of the dynamic elements specified in the MessageArguments property with the static elements uniquely identified by the MessageID in a message registry or other catalog associated with the OwningEntity.
		const string Message() const;

		// Optional, The formatted message. This message is constructed by combining some or all of the dynamic elements specified in the MessageArguments property with the static elements uniquely identified by the MessageID in a message registry or other catalog associated with the OwningEntity.
		void Message(const string &value); 

		// Is true if the field Message exists in the current object, otherwise is false.
		bool MessageExists() const;

		// Remove Message field.
		void RemoveMessage(); 

		// Optional, An array containing the dynamic content of the message.
		const vector<string> MessageArguments() const;

		// Optional, An array containing the dynamic content of the message.
		void MessageArguments(const vector<string> &value); 

		// Is true if the field MessageArguments exists in the current object, otherwise is false.
		bool MessageArgumentsExists() const;

		// Remove MessageArguments field.
		void RemoveMessageArguments(); 

		// Optional, A string that uniquely identifies, within the scope of the OwningEntity, the format of the Message.
		const string MessageID() const;

		// Optional, A string that uniquely identifies, within the scope of the OwningEntity, the format of the Message.
		void MessageID(const string &value); 

		// Is true if the field MessageID exists in the current object, otherwise is false.
		bool MessageIDExists() const;

		// Remove MessageID field.
		void RemoveMessageID(); 

		// Optional, A string that uniquely identifies the entity that owns the definition of the format of the Message described in this instance. OwningEntity MUST include a copyrighted, trademarked or otherwise unique name that is owned by the business entity or standards body defining the format.
		const string OwningEntity() const;

		// Optional, A string that uniquely identifies the entity that owns the definition of the format of the Message described in this instance. OwningEntity MUST include a copyrighted, trademarked or otherwise unique name that is owned by the business entity or standards body defining the format.
		void OwningEntity(const string &value); 

		// Is true if the field OwningEntity exists in the current object, otherwise is false.
		bool OwningEntityExists() const;

		// Remove OwningEntity field.
		void RemoveOwningEntity(); 

		 // Function used by the factory
		static CimBase *CreateFromCimObject(const CimObject &object);

		static vector<shared_ptr<CIM_AlertIndication> > Enumerate(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		// Overloaded delete which supplies the internal resourceURI
		static void Delete(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		using CimBase::Delete;

	protected:
		 // Protected constructor to be used by derived classes
		CIM_AlertIndication(ICimWsmanClient *client, const string &class_name,
			const string &class_ns, const string &prefix, const string &uri): CIM_ProcessIndication(client, class_name, class_ns, prefix, uri)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_ProcessIndication::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 20);
			}
		}
		 // Protected constructor which receives CimObject
		CIM_AlertIndication(const CimObject &object)
			: CIM_ProcessIndication(object)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_ProcessIndication::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 20);
			}
		}
		// Called by derived classes
		void SetMetaData(vector<CimFieldAttribute>& childMetaData)
		{
			CIM_ProcessIndication::SetMetaData(childMetaData);
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
#endif // CIM_ALERTINDICATION_H
