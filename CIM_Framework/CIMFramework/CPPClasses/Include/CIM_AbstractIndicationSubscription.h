//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_AbstractIndicationSubscription.h
//
//  Contents:   CIM_IndicationSubscription describes a flow of Indications. The flow is specified by the referenced Filter, and directed to the referenced destination or process in the Handler. Property values of the referenced CIM_IndicationFilter instance and CIM_ListenerDestination instance MAY significantly effect the definition of the subscription. E.g., a subscription associated with a "Transient" destination MAY be deleted when the destination terminates or is no longer available.
//
//              This file was automatically generated from CIM_AbstractIndicationSubscription.mof,  version: 2.31.0
//
//----------------------------------------------------------------------------
#ifndef CIM_ABSTRACTINDICATIONSUBSCRIPTION_H
#define CIM_ABSTRACTINDICATIONSUBSCRIPTION_H 1
#include "../../include/CimBase.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	// CIM_IndicationSubscription describes a flow of Indications. The flow is specified by the referenced Filter, and directed to the referenced destination or process in the Handler. Property values of the referenced CIM_IndicationFilter instance and CIM_ListenerDestination instance MAY significantly effect the definition of the subscription. E.g., a subscription associated with a "Transient" destination MAY be deleted when the destination terminates or is no longer available.
	class CIMFRAMEWORK_API CIM_AbstractIndicationSubscription  : public CimBase
	{
	public:

		//Default constructor
		CIM_AbstractIndicationSubscription()
			: CimBase(NULL, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CimBase::SetMetaData(_classMetaData, _metadata, 17);
			}
		}

		//constructor which receives WSMan client
		CIM_AbstractIndicationSubscription(ICimWsmanClient *client)
			: CimBase(client, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CimBase::SetMetaData(_classMetaData, _metadata, 17);
			}
		}

		//Destructor
		virtual ~CIM_AbstractIndicationSubscription(){}

		// The "type" information for the object. Gettors only.
		virtual const string& ResourceURI() const { return CLASS_URI; }
		static const string& ClassResourceURI() { return CLASS_URI; }
		virtual const string& XmlNamespace() const { return CLASS_NS; }
		virtual const string& XmlPrefix() const { return CLASS_NS_PREFIX; }
		virtual const string& ObjectType() const { return CLASS_NAME; }
		static const string& ClassObjectType() { return CLASS_NAME; }

		// Class representing CIM_AbstractIndicationSubscription keys
		class CimKeys : public CimBase::CimKeys
		{
		public:
			// Key, Required, The Filter that defines the criteria and data of the possible Indications of this subscription.
			const CimReference Filter() const
			{
				CimReference ret;
				TypeConverter::StringToType(GetKey("Filter"), ret);
				return ret;
			}

			// Key, Required, The Filter that defines the criteria and data of the possible Indications of this subscription.
			void Filter(const CimReference &value)
			{
				SetOrAddKey("Filter", TypeConverter::TypeToString(value), true);
			}

			// Key, Required, The Handler addressing delivery of the possible Indications of this subscription.
			const CimReference Handler() const
			{
				CimReference ret;
				TypeConverter::StringToType(GetKey("Handler"), ret);
				return ret;
			}

			// Key, Required, The Handler addressing delivery of the possible Indications of this subscription.
			void Handler(const CimReference &value)
			{
				SetOrAddKey("Handler", TypeConverter::TypeToString(value), true);
			}

		};

		// class fields declarations

		// Key, Required, The Filter that defines the criteria and data of the possible Indications of this subscription.
		const CimReference Filter() const;

		// Key, Required, The Filter that defines the criteria and data of the possible Indications of this subscription.
		void Filter(const CimReference &value); 


		// Key, Required, The Handler addressing delivery of the possible Indications of this subscription.
		const CimReference Handler() const;

		// Key, Required, The Handler addressing delivery of the possible Indications of this subscription.
		void Handler(const CimReference &value); 


		// Optional, Defines the desired behavior for a subscription when a fatal error occurs in one of the Indication processing subcomponents (e.g., Indication processor, Indication or instance provider, or Indication handler) and the Indication cannot be successfully sent. Specifically, a failure implies that some aspect of Indication generation, processing or dispatch is no longer functioning and Indications may be lost. If the value of OnFatalErrorPolicy is 2 ("Ignore") or not set (NULL), the subscription MUST continue to be processed in a 'best effort' mode. This mode of operation can lead to unpredictable, and potentially misleading results, because Indications may be lost. If the value is 3 ("Disable"), the subscription MUST be disabled. With this policy, no new Indications will be generated or dispatched until the subscription is explicitly enabled. This is accomplished via the property, SubscriptionState. If the value is 4 ("Remove"), the subscription MUST be deleted. Selecting this policy has the same effect as issuing a DeleteInstance operation on this subscription instance.
		const unsigned short OnFatalErrorPolicy() const;

		// Optional, Defines the desired behavior for a subscription when a fatal error occurs in one of the Indication processing subcomponents (e.g., Indication processor, Indication or instance provider, or Indication handler) and the Indication cannot be successfully sent. Specifically, a failure implies that some aspect of Indication generation, processing or dispatch is no longer functioning and Indications may be lost. If the value of OnFatalErrorPolicy is 2 ("Ignore") or not set (NULL), the subscription MUST continue to be processed in a 'best effort' mode. This mode of operation can lead to unpredictable, and potentially misleading results, because Indications may be lost. If the value is 3 ("Disable"), the subscription MUST be disabled. With this policy, no new Indications will be generated or dispatched until the subscription is explicitly enabled. This is accomplished via the property, SubscriptionState. If the value is 4 ("Remove"), the subscription MUST be deleted. Selecting this policy has the same effect as issuing a DeleteInstance operation on this subscription instance.
		void OnFatalErrorPolicy(const unsigned short value); 

		// Is true if the field OnFatalErrorPolicy exists in the current object, otherwise is false.
		bool OnFatalErrorPolicyExists() const;

		// Remove OnFatalErrorPolicy field.
		void RemoveOnFatalErrorPolicy(); 

		// Optional, A string defining "Other" values for OnFatalErrorPolicy. This value MUST be set to a non NULL value when OnFatalErrorPolicy is set to a value of 1 ("Other"). For all other values, the OtherOnFatalErrorPolicy MUST be NULL.
		const string OtherOnFatalErrorPolicy() const;

		// Optional, A string defining "Other" values for OnFatalErrorPolicy. This value MUST be set to a non NULL value when OnFatalErrorPolicy is set to a value of 1 ("Other"). For all other values, the OtherOnFatalErrorPolicy MUST be NULL.
		void OtherOnFatalErrorPolicy(const string &value); 

		// Is true if the field OtherOnFatalErrorPolicy exists in the current object, otherwise is false.
		bool OtherOnFatalErrorPolicyExists() const;

		// Remove OtherOnFatalErrorPolicy field.
		void RemoveOtherOnFatalErrorPolicy(); 

		// Optional, The FailureTriggerTimeInterval is used by the client to specify a recommended minimum delay before the OnFatalErrorPolicy is implemented.
		const Uint64 FailureTriggerTimeInterval() const;

		// Optional, The FailureTriggerTimeInterval is used by the client to specify a recommended minimum delay before the OnFatalErrorPolicy is implemented.
		void FailureTriggerTimeInterval(const Uint64 value); 

		// Is true if the field FailureTriggerTimeInterval exists in the current object, otherwise is false.
		bool FailureTriggerTimeIntervalExists() const;

		// Remove FailureTriggerTimeInterval field.
		void RemoveFailureTriggerTimeInterval(); 

		// Optional, Indicates the current processing state of the subscription.
		const unsigned short SubscriptionState() const;

		// Optional, Indicates the current processing state of the subscription.
		void SubscriptionState(const unsigned short value); 

		// Is true if the field SubscriptionState exists in the current object, otherwise is false.
		bool SubscriptionStateExists() const;

		// Remove SubscriptionState field.
		void RemoveSubscriptionState(); 

		// Optional, A string defining "Other" values for SubscriptionState. This value MUST be set to a non NULL value when SubscriptionState is set to a value of 1 ("Other"). For all other values, the OtherSubscriptionState MUST be NULL.
		const string OtherSubscriptionState() const;

		// Optional, A string defining "Other" values for SubscriptionState. This value MUST be set to a non NULL value when SubscriptionState is set to a value of 1 ("Other"). For all other values, the OtherSubscriptionState MUST be NULL.
		void OtherSubscriptionState(const string &value); 

		// Is true if the field OtherSubscriptionState exists in the current object, otherwise is false.
		bool OtherSubscriptionStateExists() const;

		// Remove OtherSubscriptionState field.
		void RemoveOtherSubscriptionState(); 

		// Optional, Date and time of the last state change. This value is based on the notion of local date and time of the Managed System Element running the Indication processing subcomponents.
		const CimDateTime TimeOfLastStateChange() const;

		// Optional, Date and time of the last state change. This value is based on the notion of local date and time of the Managed System Element running the Indication processing subcomponents.
		void TimeOfLastStateChange(const CimDateTime &value); 

		// Is true if the field TimeOfLastStateChange exists in the current object, otherwise is false.
		bool TimeOfLastStateChangeExists() const;

		// Remove TimeOfLastStateChange field.
		void RemoveTimeOfLastStateChange(); 

		// Optional, SubscriptionDuration defines the desired length of the subscription. Indications generated after the duration of the subscription has exceeded SubscriptionDuration MUST NOT be sent. The duration of a subscription MAY be changed by modifying this property. An expired subscription MAY be deleted and MUST NOT be modified. If the value of SubscriptionDuration is not set, the subscription MUST be treated as having no expiration date.
		const Uint64 SubscriptionDuration() const;

		// Optional, SubscriptionDuration defines the desired length of the subscription. Indications generated after the duration of the subscription has exceeded SubscriptionDuration MUST NOT be sent. The duration of a subscription MAY be changed by modifying this property. An expired subscription MAY be deleted and MUST NOT be modified. If the value of SubscriptionDuration is not set, the subscription MUST be treated as having no expiration date.
		void SubscriptionDuration(const Uint64 value); 

		// Is true if the field SubscriptionDuration exists in the current object, otherwise is false.
		bool SubscriptionDurationExists() const;

		// Remove SubscriptionDuration field.
		void RemoveSubscriptionDuration(); 

		// Optional, SubscriptionStartTime is the time the subscription was started. The value of this property is computed based on the notion of date and time of the ManagedSystemElement running the Indication processing subcomponents.
		const CimDateTime SubscriptionStartTime() const;

		// Optional, SubscriptionStartTime is the time the subscription was started. The value of this property is computed based on the notion of date and time of the ManagedSystemElement running the Indication processing subcomponents.
		void SubscriptionStartTime(const CimDateTime &value); 

		// Is true if the field SubscriptionStartTime exists in the current object, otherwise is false.
		bool SubscriptionStartTimeExists() const;

		// Remove SubscriptionStartTime field.
		void RemoveSubscriptionStartTime(); 

		// Optional, SubscriptionTimeRemaining is a computed value that provides a snapshot of the time remaining in the Subscription.
		const Uint64 SubscriptionTimeRemaining() const;

		// Optional, SubscriptionTimeRemaining is a computed value that provides a snapshot of the time remaining in the Subscription.
		void SubscriptionTimeRemaining(const Uint64 value); 

		// Is true if the field SubscriptionTimeRemaining exists in the current object, otherwise is false.
		bool SubscriptionTimeRemainingExists() const;

		// Remove SubscriptionTimeRemaining field.
		void RemoveSubscriptionTimeRemaining(); 

		// Optional, The RepeatNotificationPolicy property defines the desired behavior for handling Indications that report the occurrence of the same underlying event (e.g., the disk is still generating I/O errors and has not yet been repaired). The defined semantics for the RepeatNotificationCount, RepeatNotificationInterval, and RepeatNotificationGap properties depend on the value of RepeatNotificationPolicy, but values for these properties MUST be set if the property is defined for the selected policy. If the value of RepeatNotificationPolicy is 0 ("Unknown") or not set, no special processing for repeat Indications is defined by the subscription. The semantics associated with the handling of repeat Indications MAY be defined by the Indication processing subcomponents. If the value of RepeatNotificationPolicy is 2 ("None"), special processing of repeat Indications MUST NOT be performed. If the value is 3 ("Suppress") the first RepeatNotificationCount Indications, describing the same event, MUST be sent and all subsequent Indications for this event suppressed for the remainder of the time interval RepeatNotificationInterval. A new interval starts when the next Indication for this event is received. If the value of RepeatNotificationPolicy is 4 ("Delay") and an Indication is received, this Indication MUST be suppressed if, including this Indication, RepeatNoticationCount or fewer Indications for this event have been received during the prior time interval defined by RepeatNotificationInterval. If this Indication is the RepeatNotificationCount + 1 Indication, this Indication MUST be sent and all subsequent Indications for this event ignored until the RepeatNotificationGap has elapsed. A RepeatNotificationInterval MAY NOT overlap a RepeatNotificationGap time interval.
		const unsigned short RepeatNotificationPolicy() const;

		// Optional, The RepeatNotificationPolicy property defines the desired behavior for handling Indications that report the occurrence of the same underlying event (e.g., the disk is still generating I/O errors and has not yet been repaired). The defined semantics for the RepeatNotificationCount, RepeatNotificationInterval, and RepeatNotificationGap properties depend on the value of RepeatNotificationPolicy, but values for these properties MUST be set if the property is defined for the selected policy. If the value of RepeatNotificationPolicy is 0 ("Unknown") or not set, no special processing for repeat Indications is defined by the subscription. The semantics associated with the handling of repeat Indications MAY be defined by the Indication processing subcomponents. If the value of RepeatNotificationPolicy is 2 ("None"), special processing of repeat Indications MUST NOT be performed. If the value is 3 ("Suppress") the first RepeatNotificationCount Indications, describing the same event, MUST be sent and all subsequent Indications for this event suppressed for the remainder of the time interval RepeatNotificationInterval. A new interval starts when the next Indication for this event is received. If the value of RepeatNotificationPolicy is 4 ("Delay") and an Indication is received, this Indication MUST be suppressed if, including this Indication, RepeatNoticationCount or fewer Indications for this event have been received during the prior time interval defined by RepeatNotificationInterval. If this Indication is the RepeatNotificationCount + 1 Indication, this Indication MUST be sent and all subsequent Indications for this event ignored until the RepeatNotificationGap has elapsed. A RepeatNotificationInterval MAY NOT overlap a RepeatNotificationGap time interval.
		void RepeatNotificationPolicy(const unsigned short value); 

		// Is true if the field RepeatNotificationPolicy exists in the current object, otherwise is false.
		bool RepeatNotificationPolicyExists() const;

		// Remove RepeatNotificationPolicy field.
		void RemoveRepeatNotificationPolicy(); 

		// Optional, A string defining "Other" values for RepeatNotificationPolicy. This value MUST be set to a non NULL value when RepeatNotificationPolicy is set to a value of 1 ("Other"). For all other values, the OtherRepeatNotificationPolicy MUST be NULL.
		const string OtherRepeatNotificationPolicy() const;

		// Optional, A string defining "Other" values for RepeatNotificationPolicy. This value MUST be set to a non NULL value when RepeatNotificationPolicy is set to a value of 1 ("Other"). For all other values, the OtherRepeatNotificationPolicy MUST be NULL.
		void OtherRepeatNotificationPolicy(const string &value); 

		// Is true if the field OtherRepeatNotificationPolicy exists in the current object, otherwise is false.
		bool OtherRepeatNotificationPolicyExists() const;

		// Remove OtherRepeatNotificationPolicy field.
		void RemoveOtherRepeatNotificationPolicy(); 

		// Optional, Defines the time interval for the repeat notification policy calculation.
		const Uint64 RepeatNotificationInterval() const;

		// Optional, Defines the time interval for the repeat notification policy calculation.
		void RepeatNotificationInterval(const Uint64 value); 

		// Is true if the field RepeatNotificationInterval exists in the current object, otherwise is false.
		bool RepeatNotificationIntervalExists() const;

		// Remove RepeatNotificationInterval field.
		void RemoveRepeatNotificationInterval(); 

		// Optional, Defines the gap interval for the repeat notification policy calculation.
		const Uint64 RepeatNotificationGap() const;

		// Optional, Defines the gap interval for the repeat notification policy calculation.
		void RepeatNotificationGap(const Uint64 value); 

		// Is true if the field RepeatNotificationGap exists in the current object, otherwise is false.
		bool RepeatNotificationGapExists() const;

		// Remove RepeatNotificationGap field.
		void RemoveRepeatNotificationGap(); 

		// Optional, Defines the count property for the repeat notification policy calculation.
		const unsigned short RepeatNotificationCount() const;

		// Optional, Defines the count property for the repeat notification policy calculation.
		void RepeatNotificationCount(const unsigned short value); 

		// Is true if the field RepeatNotificationCount exists in the current object, otherwise is false.
		bool RepeatNotificationCountExists() const;

		// Remove RepeatNotificationCount field.
		void RemoveRepeatNotificationCount(); 

		// Optional, Subscription identification information. May be used by the client or protocol to store subscription identification information.
		const string SubscriptionInfo() const;

		// Optional, Subscription identification information. May be used by the client or protocol to store subscription identification information.
		void SubscriptionInfo(const string &value); 

		// Is true if the field SubscriptionInfo exists in the current object, otherwise is false.
		bool SubscriptionInfoExists() const;

		// Remove SubscriptionInfo field.
		void RemoveSubscriptionInfo(); 

		 // Function used by the factory
		static CimBase *CreateFromCimObject(const CimObject &object);

		static vector<shared_ptr<CIM_AbstractIndicationSubscription> > Enumerate(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		// Overloaded delete which supplies the internal resourceURI
		static void Delete(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		using CimBase::Delete;

	protected:
		 // Protected constructor to be used by derived classes
		CIM_AbstractIndicationSubscription(ICimWsmanClient *client, const string &class_name,
			const string &class_ns, const string &prefix, const string &uri): CimBase(client, class_name, class_ns, prefix, uri)
		{
			if(_classMetaData.size() == 0)
			{
				CimBase::SetMetaData(_classMetaData, _metadata, 17);
			}
		}
		 // Protected constructor which receives CimObject
		CIM_AbstractIndicationSubscription(const CimObject &object)
			: CimBase(object)
		{
			if(_classMetaData.size() == 0)
			{
				CimBase::SetMetaData(_classMetaData, _metadata, 17);
			}
		}
		// Called by derived classes
		void SetMetaData(vector<CimFieldAttribute>& childMetaData)
		{
			CimBase::SetMetaData(childMetaData, _metadata, 17);
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
#endif // CIM_ABSTRACTINDICATIONSUBSCRIPTION_H
