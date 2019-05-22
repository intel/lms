//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       AMT_HeuristicPacketFilterSettings.h
//
//  Contents:   Represents the system settings for the Heuristics System Defense feature
//
//              This file was automatically generated from AMT_HeuristicPacketFilterSettings.mof,  version: 3.0.0
//
//----------------------------------------------------------------------------
#ifndef AMT_HEURISTICPACKETFILTERSETTINGS_H
#define AMT_HEURISTICPACKETFILTERSETTINGS_H 1
#include "CIM_SettingData.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	// Represents the system settings for the Heuristics System Defense feature
	class CIMFRAMEWORK_API AMT_HeuristicPacketFilterSettings  : public CIM_SettingData
	{
	public:

		//Default constructor
		AMT_HeuristicPacketFilterSettings()
			: CIM_SettingData(NULL, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_SettingData::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 8);
			}
		}

		//constructor which receives WSMan client
		AMT_HeuristicPacketFilterSettings(ICimWsmanClient *client)
			: CIM_SettingData(client, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_SettingData::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 8);
			}
		}

		//Destructor
		virtual ~AMT_HeuristicPacketFilterSettings(){}

		// The "type" information for the object. Gettors only.
		virtual const string& ResourceURI() const { return CLASS_URI; }
		static const string& ClassResourceURI() { return CLASS_URI; }
		virtual const string& XmlNamespace() const { return CLASS_NS; }
		virtual const string& XmlPrefix() const { return CLASS_NS_PREFIX; }
		virtual const string& ObjectType() const { return CLASS_NAME; }
		static const string& ClassObjectType() { return CLASS_NAME; }

		// Class representing AMT_HeuristicPacketFilterSettings keys
		class CimKeys : public CIM_SettingData::CimKeys
		{
		public:
		};

		// class fields declarations

		// Required, Indicates whether or not Heuristics Packet Filter has been enabled.
		const bool Enabled() const;

		// Required, Indicates whether or not Heuristics Packet Filter has been enabled.
		void Enabled(const bool value); 

		// Is true if the field Enabled exists in the current object, otherwise is false.
		bool EnabledExists() const;

		// Remove Enabled field.
		void RemoveEnabled(); 

		// Optional, Specifies how many "fast connections" are permitted per unit of time. Once the count reaches this value, the actions specified in this object are taken. FastConnectionRateClearTime is used to reset the count
		const unsigned int FastConnectionRateThreshold() const;

		// Optional, Specifies how many "fast connections" are permitted per unit of time. Once the count reaches this value, the actions specified in this object are taken. FastConnectionRateClearTime is used to reset the count
		void FastConnectionRateThreshold(const unsigned int value); 

		// Is true if the field FastConnectionRateThreshold exists in the current object, otherwise is false.
		bool FastConnectionRateThresholdExists() const;

		// Remove FastConnectionRateThreshold field.
		void RemoveFastConnectionRateThreshold(); 

		// Optional, If the clear time elapses without any further connections, the counter is cleared and count begins from zero. Clear time is in units of milliseconds, and the permitted range is between 10 milliseconds to 1000 milliseconds.
		const unsigned int FastConnectionRateClearTime() const;

		// Optional, If the clear time elapses without any further connections, the counter is cleared and count begins from zero. Clear time is in units of milliseconds, and the permitted range is between 10 milliseconds to 1000 milliseconds.
		void FastConnectionRateClearTime(const unsigned int value); 

		// Is true if the field FastConnectionRateClearTime exists in the current object, otherwise is false.
		bool FastConnectionRateClearTimeExists() const;

		// Remove FastConnectionRateClearTime field.
		void RemoveFastConnectionRateClearTime(); 

		// Optional, Specifies how many "slow connections" are permitted per unit of time. Once the count reaches this value, the actions specified in this object are taken. SlowConnectionRateClearTime is used to reset the count.
		const unsigned int SlowConnectionRateThreshold() const;

		// Optional, Specifies how many "slow connections" are permitted per unit of time. Once the count reaches this value, the actions specified in this object are taken. SlowConnectionRateClearTime is used to reset the count.
		void SlowConnectionRateThreshold(const unsigned int value); 

		// Is true if the field SlowConnectionRateThreshold exists in the current object, otherwise is false.
		bool SlowConnectionRateThresholdExists() const;

		// Remove SlowConnectionRateThreshold field.
		void RemoveSlowConnectionRateThreshold(); 

		// Optional, If the clear time elapses without any further connections, the counter is cleared and count begins from zero. Clear time is in units of seconds, and the permitted range is between one second to 50 seconds. This time is represented in milliseconds (1000-50000).
		const unsigned int SlowConnectionRateClearTime() const;

		// Optional, If the clear time elapses without any further connections, the counter is cleared and count begins from zero. Clear time is in units of seconds, and the permitted range is between one second to 50 seconds. This time is represented in milliseconds (1000-50000).
		void SlowConnectionRateClearTime(const unsigned int value); 

		// Is true if the field SlowConnectionRateClearTime exists in the current object, otherwise is false.
		bool SlowConnectionRateClearTimeExists() const;

		// Remove SlowConnectionRateClearTime field.
		void RemoveSlowConnectionRateClearTime(); 

		// Optional, Specifies whether all transmit traffic should be blocked if one of the conditions applies.
		const bool BlockAll() const;

		// Optional, Specifies whether all transmit traffic should be blocked if one of the conditions applies.
		void BlockAll(const bool value); 

		// Is true if the field BlockAll exists in the current object, otherwise is false.
		bool BlockAllExists() const;

		// Remove BlockAll field.
		void RemoveBlockAll(); 

		// Optional, Specifies whether the offensive TX port should be blocked if one of the conditions applies.
		const bool BlockOffensivePort() const;

		// Optional, Specifies whether the offensive TX port should be blocked if one of the conditions applies.
		void BlockOffensivePort(const bool value); 

		// Is true if the field BlockOffensivePort exists in the current object, otherwise is false.
		bool BlockOffensivePortExists() const;

		// Remove BlockOffensivePort field.
		void RemoveBlockOffensivePort(); 

		// Required, A Timer value (in seconds) which defines the number of seconds the Intel(R) AMT device will stay in "Encounter" mode (activating configured actions). At the expiration of the timer value, the Intel(R) AMT device will transition to "running" mode sending a "system clean" alert. 0 has a special meaning - "Move to Encounter mode without time out (permanent encounter)".
		const unsigned short EncounterTimeout() const;

		// Required, A Timer value (in seconds) which defines the number of seconds the Intel(R) AMT device will stay in "Encounter" mode (activating configured actions). At the expiration of the timer value, the Intel(R) AMT device will transition to "running" mode sending a "system clean" alert. 0 has a special meaning - "Move to Encounter mode without time out (permanent encounter)".
		void EncounterTimeout(const unsigned short value); 

		// Is true if the field EncounterTimeout exists in the current object, otherwise is false.
		bool EncounterTimeoutExists() const;

		// Remove EncounterTimeout field.
		void RemoveEncounterTimeout(); 

		 // Function used by the factory
		static CimBase *CreateFromCimObject(const CimObject &object);

		static vector<shared_ptr<AMT_HeuristicPacketFilterSettings> > Enumerate(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		// Overloaded delete which supplies the internal resourceURI
		static void Delete(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		using CimBase::Delete;

	protected:
		 // Protected constructor to be used by derived classes
		AMT_HeuristicPacketFilterSettings(ICimWsmanClient *client, const string &class_name,
			const string &class_ns, const string &prefix, const string &uri): CIM_SettingData(client, class_name, class_ns, prefix, uri)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_SettingData::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 8);
			}
		}
		 // Protected constructor which receives CimObject
		AMT_HeuristicPacketFilterSettings(const CimObject &object)
			: CIM_SettingData(object)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_SettingData::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 8);
			}
		}
		// Called by derived classes
		void SetMetaData(vector<CimFieldAttribute>& childMetaData)
		{
			CIM_SettingData::SetMetaData(childMetaData);
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
#endif // AMT_HEURISTICPACKETFILTERSETTINGS_H
