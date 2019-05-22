//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_IndicationService.h
//
//  Contents:   An IndicationService is a Service of the CIM Object Manager that is responsible for delivering indications to Indication Handlers.
//
//              This file was automatically generated from CIM_IndicationService.mof,  version: 2.20.0
//
//----------------------------------------------------------------------------
#ifndef CIM_INDICATIONSERVICE_H
#define CIM_INDICATIONSERVICE_H 1
#include "CIM_Service.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	// An IndicationService is a Service of the CIM Object Manager that is responsible for delivering indications to Indication Handlers.
	class CIMFRAMEWORK_API CIM_IndicationService  : public CIM_Service
	{
	public:

		//Default constructor
		CIM_IndicationService()
			: CIM_Service(NULL, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_Service::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 5);
			}
		}

		//constructor which receives WSMan client
		CIM_IndicationService(ICimWsmanClient *client)
			: CIM_Service(client, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_Service::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 5);
			}
		}

		//Destructor
		virtual ~CIM_IndicationService(){}

		// The "type" information for the object. Gettors only.
		virtual const string& ResourceURI() const { return CLASS_URI; }
		static const string& ClassResourceURI() { return CLASS_URI; }
		virtual const string& XmlNamespace() const { return CLASS_NS; }
		virtual const string& XmlPrefix() const { return CLASS_NS_PREFIX; }
		virtual const string& ObjectType() const { return CLASS_NAME; }
		static const string& ClassObjectType() { return CLASS_NAME; }

		// Class representing CIM_IndicationService keys
		class CimKeys : public CIM_Service::CimKeys
		{
		public:
		};

		// class fields declarations

		// Optional, The FilterCreationEnabled property controls whether or not clients can create indication filters. If this value is set to false, only the indication filters that exist can be subscribed to. If this value is true clients may attempt to create filters. Note that implementations may preset this setting and not allow this value to be modified.
		const bool FilterCreationEnabled() const;

		// Optional, The FilterCreationEnabled property controls whether or not clients can create indication filters. If this value is set to false, only the indication filters that exist can be subscribed to. If this value is true clients may attempt to create filters. Note that implementations may preset this setting and not allow this value to be modified.
		void FilterCreationEnabled(const bool value); 

		// Is true if the field FilterCreationEnabled exists in the current object, otherwise is false.
		bool FilterCreationEnabledExists() const;

		// Remove FilterCreationEnabled field.
		void RemoveFilterCreationEnabled(); 

		// Optional, Defines the number of retries that the indication service will try to deliver an indication to a particular listener destination. This does not effect the original delivery attempt, thus if set to 0, it will only try to deliver the indication once. Note that implementations may preset this setting and not allow this value to be modified.
		const unsigned short DeliveryRetryAttempts() const;

		// Optional, Defines the number of retries that the indication service will try to deliver an indication to a particular listener destination. This does not effect the original delivery attempt, thus if set to 0, it will only try to deliver the indication once. Note that implementations may preset this setting and not allow this value to be modified.
		void DeliveryRetryAttempts(const unsigned short value); 

		// Is true if the field DeliveryRetryAttempts exists in the current object, otherwise is false.
		bool DeliveryRetryAttemptsExists() const;

		// Remove DeliveryRetryAttempts field.
		void RemoveDeliveryRetryAttempts(); 

		// Optional, Defines the minimal time interval in seconds for the indication service to use before delivering an indication to a particular listener destination that previously failed. The implementation may take longer due to QoS or other processing. Note that implementations may preset this setting and not allow this value to be modified.
		const unsigned int DeliveryRetryInterval() const;

		// Optional, Defines the minimal time interval in seconds for the indication service to use before delivering an indication to a particular listener destination that previously failed. The implementation may take longer due to QoS or other processing. Note that implementations may preset this setting and not allow this value to be modified.
		void DeliveryRetryInterval(const unsigned int value); 

		// Is true if the field DeliveryRetryInterval exists in the current object, otherwise is false.
		bool DeliveryRetryIntervalExists() const;

		// Remove DeliveryRetryInterval field.
		void RemoveDeliveryRetryInterval(); 

		// Optional, Defines the removal action for subscriptions that have two failed indication deliveries without any successful indication deliveries in between and the time between the failed deliveries exceeded the timeout defined in the SubscriptionRemovalTimeInterval property. "Remove" defines the subscription is to be removed.
		// "Disable" indicates that subscription removal process isnot being enforced. 
		// "Ignore" indicates that the removal action is temporarily not enforced. implementations may preset this setting and not allow this value to be modified.
		const unsigned short SubscriptionRemovalAction() const;

		// Optional, Defines the removal action for subscriptions that have two failed indication deliveries without any successful indication deliveries in between and the time between the failed deliveries exceeded the timeout defined in the SubscriptionRemovalTimeInterval property. "Remove" defines the subscription is to be removed.
		// "Disable" indicates that subscription removal process isnot being enforced. 
		// "Ignore" indicates that the removal action is temporarily not enforced. implementations may preset this setting and not allow this value to be modified.
		void SubscriptionRemovalAction(const unsigned short value); 

		// Is true if the field SubscriptionRemovalAction exists in the current object, otherwise is false.
		bool SubscriptionRemovalActionExists() const;

		// Remove SubscriptionRemovalAction field.
		void RemoveSubscriptionRemovalAction(); 

		// Optional, Minimum time between two failed indication deliveries without any successful indication deliveries in between before the SubscriptionRemovalPolicy goes into effect.
		const unsigned int SubscriptionRemovalTimeInterval() const;

		// Optional, Minimum time between two failed indication deliveries without any successful indication deliveries in between before the SubscriptionRemovalPolicy goes into effect.
		void SubscriptionRemovalTimeInterval(const unsigned int value); 

		// Is true if the field SubscriptionRemovalTimeInterval exists in the current object, otherwise is false.
		bool SubscriptionRemovalTimeIntervalExists() const;

		// Remove SubscriptionRemovalTimeInterval field.
		void RemoveSubscriptionRemovalTimeInterval(); 

		 // Function used by the factory
		static CimBase *CreateFromCimObject(const CimObject &object);

		static vector<shared_ptr<CIM_IndicationService> > Enumerate(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		// Overloaded delete which supplies the internal resourceURI
		static void Delete(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		using CimBase::Delete;

	protected:
		 // Protected constructor to be used by derived classes
		CIM_IndicationService(ICimWsmanClient *client, const string &class_name,
			const string &class_ns, const string &prefix, const string &uri): CIM_Service(client, class_name, class_ns, prefix, uri)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_Service::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 5);
			}
		}
		 // Protected constructor which receives CimObject
		CIM_IndicationService(const CimObject &object)
			: CIM_Service(object)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_Service::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 5);
			}
		}
		// Called by derived classes
		void SetMetaData(vector<CimFieldAttribute>& childMetaData)
		{
			CIM_Service::SetMetaData(childMetaData);
			CimBase::SetMetaData(childMetaData, _metadata, 5);
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
#endif // CIM_INDICATIONSERVICE_H
