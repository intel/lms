//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       AMT_SystemDefensePolicy.h
//
//  Contents:   Describes a System Defense Policy
//
//              This file was automatically generated from AMT_SystemDefensePolicy.mof,  version: 6.0.0
//
//----------------------------------------------------------------------------
#ifndef AMT_SYSTEMDEFENSEPOLICY_H
#define AMT_SYSTEMDEFENSEPOLICY_H 1
#include "CIM_ManagedElement.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	// Describes a System Defense Policy
	class CIMFRAMEWORK_API AMT_SystemDefensePolicy  : public CIM_ManagedElement
	{
	public:

		//Default constructor
		AMT_SystemDefensePolicy()
			: CIM_ManagedElement(NULL, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_ManagedElement::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 11);
			}
		}

		//constructor which receives WSMan client
		AMT_SystemDefensePolicy(ICimWsmanClient *client)
			: CIM_ManagedElement(client, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_ManagedElement::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 11);
			}
		}

		//Destructor
		virtual ~AMT_SystemDefensePolicy(){}

		// The "type" information for the object. Gettors only.
		virtual const string& ResourceURI() const { return CLASS_URI; }
		static const string& ClassResourceURI() { return CLASS_URI; }
		virtual const string& XmlNamespace() const { return CLASS_NS; }
		virtual const string& XmlPrefix() const { return CLASS_NS_PREFIX; }
		virtual const string& ObjectType() const { return CLASS_NAME; }
		static const string& ClassObjectType() { return CLASS_NAME; }

		// Class representing AMT_SystemDefensePolicy keys
		class CimKeys : public CIM_ManagedElement::CimKeys
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

		// Optional, Policy name.
		const string PolicyName() const;

		// Optional, Policy name.
		void PolicyName(const string &value); 

		// Is true if the field PolicyName exists in the current object, otherwise is false.
		bool PolicyNameExists() const;

		// Remove PolicyName field.
		void RemovePolicyName(); 

		// Required, In case multiple policies are being activated simultaneously, the policy with the highest precedence value takes effect. (Policies with the same precedence are chosen arbitrarily).
		const unsigned int PolicyPrecedence() const;

		// Required, In case multiple policies are being activated simultaneously, the policy with the highest precedence value takes effect. (Policies with the same precedence are chosen arbitrarily).
		void PolicyPrecedence(const unsigned int value); 

		// Is true if the field PolicyPrecedence exists in the current object, otherwise is false.
		bool PolicyPrecedenceExists() const;

		// Remove PolicyPrecedence field.
		void RemovePolicyPrecedence(); 

		// Optional, Anti Spoofing has the highest priority for blocking. Any packet that does NOT pass AS filter will not be transmitted even if it passes other filters. Any packet that does pass the AS filter is subject to the rest of the CB filters before it is transmitted.
		const unsigned int AntiSpoofingSupport() const;

		// Optional, Anti Spoofing has the highest priority for blocking. Any packet that does NOT pass AS filter will not be transmitted even if it passes other filters. Any packet that does pass the AS filter is subject to the rest of the CB filters before it is transmitted.
		void AntiSpoofingSupport(const unsigned int value); 

		// Is true if the field AntiSpoofingSupport exists in the current object, otherwise is false.
		bool AntiSpoofingSupportExists() const;

		// Remove AntiSpoofingSupport field.
		void RemoveAntiSpoofingSupport(); 

		// Optional, A list of Filter Creation Handles to be included in the Policy.
		const vector<unsigned int> FilterCreationHandles() const;

		// Optional, A list of Filter Creation Handles to be included in the Policy.
		void FilterCreationHandles(const vector<unsigned int> &value); 

		// Is true if the field FilterCreationHandles exists in the current object, otherwise is false.
		bool FilterCreationHandlesExists() const;

		// Remove FilterCreationHandles field.
		void RemoveFilterCreationHandles(); 

		// Required, Specifies whether the TX packet should be dropped on filter match.
		const bool TxDefaultDrop() const;

		// Required, Specifies whether the TX packet should be dropped on filter match.
		void TxDefaultDrop(const bool value); 

		// Is true if the field TxDefaultDrop exists in the current object, otherwise is false.
		bool TxDefaultDropExists() const;

		// Remove TxDefaultDrop field.
		void RemoveTxDefaultDrop(); 

		// Required, Specifies whether an Event should be created in the Event Manager when this filter is matched. (The event will be generated once and will be allowed again only after statistics are read).
		const bool TxDefaultMatchEvent() const;

		// Required, Specifies whether an Event should be created in the Event Manager when this filter is matched. (The event will be generated once and will be allowed again only after statistics are read).
		void TxDefaultMatchEvent(const bool value); 

		// Is true if the field TxDefaultMatchEvent exists in the current object, otherwise is false.
		bool TxDefaultMatchEventExists() const;

		// Remove TxDefaultMatchEvent field.
		void RemoveTxDefaultMatchEvent(); 

		// Required, Specifies whether to count filter matches. (Specifying TRUE in this action will consume one extra counter from the counter resources of the Policy).
		const bool TxDefaultCount() const;

		// Required, Specifies whether to count filter matches. (Specifying TRUE in this action will consume one extra counter from the counter resources of the Policy).
		void TxDefaultCount(const bool value); 

		// Is true if the field TxDefaultCount exists in the current object, otherwise is false.
		bool TxDefaultCountExists() const;

		// Remove TxDefaultCount field.
		void RemoveTxDefaultCount(); 

		// Required, Specifies whether the RX packet should be dropped on filter match.
		const bool RxDefaultDrop() const;

		// Required, Specifies whether the RX packet should be dropped on filter match.
		void RxDefaultDrop(const bool value); 

		// Is true if the field RxDefaultDrop exists in the current object, otherwise is false.
		bool RxDefaultDropExists() const;

		// Remove RxDefaultDrop field.
		void RemoveRxDefaultDrop(); 

		// Required, Specifies whether an Event should be created in the Event Manager when this filter is matched. (The event will be generated once and will be allowed again only after statistics are read).
		const bool RxDefaultMatchEvent() const;

		// Required, Specifies whether an Event should be created in the Event Manager when this filter is matched. (The event will be generated once and will be allowed again only after statistics are read).
		void RxDefaultMatchEvent(const bool value); 

		// Is true if the field RxDefaultMatchEvent exists in the current object, otherwise is false.
		bool RxDefaultMatchEventExists() const;

		// Remove RxDefaultMatchEvent field.
		void RemoveRxDefaultMatchEvent(); 

		// Required, Specifies whether to count filter matches. (Specifying TRUE in this action will consume one extra counter from the counter resources of the Policy).
		const bool RxDefaultCount() const;

		// Required, Specifies whether to count filter matches. (Specifying TRUE in this action will consume one extra counter from the counter resources of the Policy).
		void RxDefaultCount(const bool value); 

		// Is true if the field RxDefaultCount exists in the current object, otherwise is false.
		bool RxDefaultCountExists() const;

		// Remove RxDefaultCount field.
		void RemoveRxDefaultCount(); 

		//Output parameter for function GetTimeout
		class CIMFRAMEWORK_API GetTimeout_OUTPUT : public CimParam
		{
		public:
			// Class Constructor
			GetTimeout_OUTPUT() : CimParam() {}

			// Class Destructor
			~GetTimeout_OUTPUT(){}

			// class fields
			// The timeout of the policy (timeout is measured in minutes, and 0 means no timeout).
			const unsigned int Timeout() const;
			bool TimeoutExists() const;
		private:
		};

		// Get the timeout parameter.
		virtual unsigned int GetTimeout(GetTimeout_OUTPUT &output);

		//Input parameter for function SetTimeout
		class CIMFRAMEWORK_API SetTimeout_INPUT : public CimParam
		{
		public:
			// Class Constructor
			SetTimeout_INPUT() : CimParam() {}

			// Class Destructor
			~SetTimeout_INPUT(){}

			// Required, The timeout for the policy (measured in minutes, and 0 means no timeout).
			// Legal values:
			// Infinite: 0
			// Minutes for timeout: 1..65535
			// Reserved: 65536..
			void Timeout(const unsigned int value); 

			const VectorFieldData GetAllFields() const;
		private:
			static const CimFieldAttribute _metadata[];
		};

		// Set the timeout parameter.
		virtual unsigned int SetTimeout(const SetTimeout_INPUT &input);

		//Input parameter for function UpdateStatistics
		class CIMFRAMEWORK_API UpdateStatistics_INPUT : public CimParam
		{
		public:
			// Class Constructor
			UpdateStatistics_INPUT() : CimParam() {}

			// Class Destructor
			~UpdateStatistics_INPUT(){}

			// Required, EPR to the CIM_EthernetPort object representing the interface for which to update statistics
			void NetworkInterface(const CimReference &value); 

			// Required, Causes statistics to be resetted
			void ResetOnRead(const bool value); 

			const VectorFieldData GetAllFields() const;
		private:
			static const CimFieldAttribute _metadata[];
		};

		// Updates the statistics objects with new data.
		virtual unsigned int UpdateStatistics(const UpdateStatistics_INPUT &input);

		 // Function used by the factory
		static CimBase *CreateFromCimObject(const CimObject &object);

		static vector<shared_ptr<AMT_SystemDefensePolicy> > Enumerate(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		// Overloaded delete which supplies the internal resourceURI
		static void Delete(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		using CimBase::Delete;

	protected:
		 // Protected constructor to be used by derived classes
		AMT_SystemDefensePolicy(ICimWsmanClient *client, const string &class_name,
			const string &class_ns, const string &prefix, const string &uri): CIM_ManagedElement(client, class_name, class_ns, prefix, uri)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_ManagedElement::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 11);
			}
		}
		 // Protected constructor which receives CimObject
		AMT_SystemDefensePolicy(const CimObject &object)
			: CIM_ManagedElement(object)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_ManagedElement::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 11);
			}
		}
		// Called by derived classes
		void SetMetaData(vector<CimFieldAttribute>& childMetaData)
		{
			CIM_ManagedElement::SetMetaData(childMetaData);
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
#endif // AMT_SYSTEMDEFENSEPOLICY_H
