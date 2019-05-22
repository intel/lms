//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       AMT_HeuristicPacketFilterStatistics.h
//
//  Contents:   Represents the state of the Heuristics System Defense feature
//
//              This file was automatically generated from AMT_HeuristicPacketFilterStatistics.mof,  version: 3.0.0
//
//----------------------------------------------------------------------------
#ifndef AMT_HEURISTICPACKETFILTERSTATISTICS_H
#define AMT_HEURISTICPACKETFILTERSTATISTICS_H 1
#include "CIM_StatisticalData.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	// Represents the state of the Heuristics System Defense feature
	class CIMFRAMEWORK_API AMT_HeuristicPacketFilterStatistics  : public CIM_StatisticalData
	{
	public:

		//Default constructor
		AMT_HeuristicPacketFilterStatistics()
			: CIM_StatisticalData(NULL, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_StatisticalData::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 7);
			}
		}

		//constructor which receives WSMan client
		AMT_HeuristicPacketFilterStatistics(ICimWsmanClient *client)
			: CIM_StatisticalData(client, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_StatisticalData::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 7);
			}
		}

		//Destructor
		virtual ~AMT_HeuristicPacketFilterStatistics(){}

		// The "type" information for the object. Gettors only.
		virtual const string& ResourceURI() const { return CLASS_URI; }
		static const string& ClassResourceURI() { return CLASS_URI; }
		virtual const string& XmlNamespace() const { return CLASS_NS; }
		virtual const string& XmlPrefix() const { return CLASS_NS_PREFIX; }
		virtual const string& ObjectType() const { return CLASS_NAME; }
		static const string& ClassObjectType() { return CLASS_NAME; }

		// Class representing AMT_HeuristicPacketFilterStatistics keys
		class CimKeys : public CIM_StatisticalData::CimKeys
		{
		public:
		};

		// class fields declarations

		// Optional, The state of the Heuristics Packet Filter.
		const unsigned short State() const;

		// Optional, The state of the Heuristics Packet Filter.
		void State(const unsigned short value); 

		// Is true if the field State exists in the current object, otherwise is false.
		bool StateExists() const;

		// Remove State field.
		void RemoveState(); 

		// Optional, Indicates whether all transmit traffic has been blocked due to one of the conditions being met.
		const bool BlockedAll() const;

		// Optional, Indicates whether all transmit traffic has been blocked due to one of the conditions being met.
		void BlockedAll(const bool value); 

		// Is true if the field BlockedAll exists in the current object, otherwise is false.
		bool BlockedAllExists() const;

		// Remove BlockedAll field.
		void RemoveBlockedAll(); 

		// Optional, A time stamp of last transition to the current state. This property is Null when the current state is Running.
		const CimDateTime TimeStamp() const;

		// Optional, A time stamp of last transition to the current state. This property is Null when the current state is Running.
		void TimeStamp(const CimDateTime &value); 

		// Is true if the field TimeStamp exists in the current object, otherwise is false.
		bool TimeStampExists() const;

		// Remove TimeStamp field.
		void RemoveTimeStamp(); 

		// Optional, Contains the reason that caused the last transition from Running state. This property is Null when the current state is Running.
		const unsigned short TriggerReason() const;

		// Optional, Contains the reason that caused the last transition from Running state. This property is Null when the current state is Running.
		void TriggerReason(const unsigned short value); 

		// Is true if the field TriggerReason exists in the current object, otherwise is false.
		bool TriggerReasonExists() const;

		// Remove TriggerReason field.
		void RemoveTriggerReason(); 

		// Optional, Identifies the offensive TX port blocked due to one of the conditions being met. A 16-bit port number.
		const unsigned short BlockedOffensivePort() const;

		// Optional, Identifies the offensive TX port blocked due to one of the conditions being met. A 16-bit port number.
		void BlockedOffensivePort(const unsigned short value); 

		// Is true if the field BlockedOffensivePort exists in the current object, otherwise is false.
		bool BlockedOffensivePortExists() const;

		// Remove BlockedOffensivePort field.
		void RemoveBlockedOffensivePort(); 

		// Optional, Indicates the protocol type at the offensive TX port blocked.
		const unsigned short BlockedOffensivePortProtocol() const;

		// Optional, Indicates the protocol type at the offensive TX port blocked.
		void BlockedOffensivePortProtocol(const unsigned short value); 

		// Is true if the field BlockedOffensivePortProtocol exists in the current object, otherwise is false.
		bool BlockedOffensivePortProtocolExists() const;

		// Remove BlockedOffensivePortProtocol field.
		void RemoveBlockedOffensivePortProtocol(); 

		// Optional, Indicates whether the associated System Defense policy was applied due to one of the conditions being met.
		const bool EnabledPolicy() const;

		// Optional, Indicates whether the associated System Defense policy was applied due to one of the conditions being met.
		void EnabledPolicy(const bool value); 

		// Is true if the field EnabledPolicy exists in the current object, otherwise is false.
		bool EnabledPolicyExists() const;

		// Remove EnabledPolicy field.
		void RemoveEnabledPolicy(); 

		//Input parameter for function ResetSelectedStats
		class CIMFRAMEWORK_API ResetSelectedStats_INPUT : public CimParam
		{
		public:
			// Class Constructor
			ResetSelectedStats_INPUT() : CimParam() {}

			// Class Destructor
			~ResetSelectedStats_INPUT(){}

			// Required, Array of strings indicating which statistics to reset.
			void SelectedStatistics(const vector<string> &value); 

			const VectorFieldData GetAllFields() const;
		private:
			static const CimFieldAttribute _metadata[];
		};

		// Method to reset one or more of the instance's statistics. The method takes one parameter as input - an array of strings indicating which statistics to reset. If all the statistics in the instance should be reset, the first element of the array MUST be set to "All" or "ALL". If one or more individual statistics should be reset, the corresponding property names are entered into the elements of the array. 
		// The method returns 0 if successful, 1 if not supported, and any other value if an error occurred. A method is specified so that the StatisticalInformation's provider/ instrumentation, which calculates the statistics, can reset its internal processing, counters, etc. 
		// In a subclass, the set of possible return codes could be specified, using a ValueMap qualifier on the method. The strings to which the ValueMap contents are 'translated' may also be specified in the subclass as a Values array qualifier.
		virtual unsigned int ResetSelectedStats(const ResetSelectedStats_INPUT &input);

		 // Function used by the factory
		static CimBase *CreateFromCimObject(const CimObject &object);

		static vector<shared_ptr<AMT_HeuristicPacketFilterStatistics> > Enumerate(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		// Overloaded delete which supplies the internal resourceURI
		static void Delete(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		using CimBase::Delete;

	protected:
		 // Protected constructor to be used by derived classes
		AMT_HeuristicPacketFilterStatistics(ICimWsmanClient *client, const string &class_name,
			const string &class_ns, const string &prefix, const string &uri): CIM_StatisticalData(client, class_name, class_ns, prefix, uri)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_StatisticalData::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 7);
			}
		}
		 // Protected constructor which receives CimObject
		AMT_HeuristicPacketFilterStatistics(const CimObject &object)
			: CIM_StatisticalData(object)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_StatisticalData::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 7);
			}
		}
		// Called by derived classes
		void SetMetaData(vector<CimFieldAttribute>& childMetaData)
		{
			CIM_StatisticalData::SetMetaData(childMetaData);
			CimBase::SetMetaData(childMetaData, _metadata, 7);
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
#endif // AMT_HEURISTICPACKETFILTERSTATISTICS_H
