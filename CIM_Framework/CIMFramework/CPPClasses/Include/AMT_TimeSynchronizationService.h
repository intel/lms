//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       AMT_TimeSynchronizationService.h
//
//  Contents:   Exposes Intel(R) AMT time synchronization services to management clients.
//
//              This file was automatically generated from AMT_TimeSynchronizationService.mof,  version: 3.0.0
//
//----------------------------------------------------------------------------
#ifndef AMT_TIMESYNCHRONIZATIONSERVICE_H
#define AMT_TIMESYNCHRONIZATIONSERVICE_H 1
#include "CIM_Service.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	// Exposes Intel(R) AMT time synchronization services to management clients.
	class CIMFRAMEWORK_API AMT_TimeSynchronizationService  : public CIM_Service
	{
	public:

		//Default constructor
		AMT_TimeSynchronizationService()
			: CIM_Service(NULL, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_Service::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 2);
			}
		}

		//constructor which receives WSMan client
		AMT_TimeSynchronizationService(ICimWsmanClient *client)
			: CIM_Service(client, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_Service::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 2);
			}
		}

		//Destructor
		virtual ~AMT_TimeSynchronizationService(){}

		// The "type" information for the object. Gettors only.
		virtual const string& ResourceURI() const { return CLASS_URI; }
		static const string& ClassResourceURI() { return CLASS_URI; }
		virtual const string& XmlNamespace() const { return CLASS_NS; }
		virtual const string& XmlPrefix() const { return CLASS_NS_PREFIX; }
		virtual const string& ObjectType() const { return CLASS_NAME; }
		static const string& ClassObjectType() { return CLASS_NAME; }

		// Class representing AMT_TimeSynchronizationService keys
		class CimKeys : public CIM_Service::CimKeys
		{
		public:
		};

		// class fields declarations

		// Optional, Determines if user with LOCAL_SYSTEM_REALM permission can set the time.The values are: DEFAULT_TRUE - Time sync is enabled by default. Was not configured to enabled or disabled by the configuration SW.CONFIGURED_TRUE - Time Sync is enabled and configured by configuration SW to TRUE. This option is required in order to differentiate between legacy configuration SW that do not support this setting and new SW that can configure it to TRUE.FALSE - Time Sync is disabled.
		const unsigned int LocalTimeSyncEnabled() const;

		// Optional, Determines if user with LOCAL_SYSTEM_REALM permission can set the time.The values are: DEFAULT_TRUE - Time sync is enabled by default. Was not configured to enabled or disabled by the configuration SW.CONFIGURED_TRUE - Time Sync is enabled and configured by configuration SW to TRUE. This option is required in order to differentiate between legacy configuration SW that do not support this setting and new SW that can configure it to TRUE.FALSE - Time Sync is disabled.
		void LocalTimeSyncEnabled(const unsigned int value); 

		// Is true if the field LocalTimeSyncEnabled exists in the current object, otherwise is false.
		bool LocalTimeSyncEnabledExists() const;

		// Remove LocalTimeSyncEnabled field.
		void RemoveLocalTimeSyncEnabled(); 

		// Optional, Determines if RTC was set to UTC by any configuration SW.
		const unsigned int TimeSource() const;

		// Optional, Determines if RTC was set to UTC by any configuration SW.
		void TimeSource(const unsigned int value); 

		// Is true if the field TimeSource exists in the current object, otherwise is false.
		bool TimeSourceExists() const;

		// Remove TimeSource field.
		void RemoveTimeSource(); 

		//Output parameter for function GetLowAccuracyTimeSynch
		class CIMFRAMEWORK_API GetLowAccuracyTimeSynch_OUTPUT : public CimParam
		{
		public:
			// Class Constructor
			GetLowAccuracyTimeSynch_OUTPUT() : CimParam() {}

			// Class Destructor
			~GetLowAccuracyTimeSynch_OUTPUT(){}

			// class fields
			// An unsigned 32-bit value representing the local time as the number of seconds from 00:00:00, January 1, 1970 UTC. This format is sufficient to maintain time stamps with one-second resolution past the year 2100. This is based on a longstanding UNIX-based standard for timekeeping, which represents time as the number of seconds from 00:00:00, January 1, 1970 UTC. Similar time formats are used in ANSI C.
			const unsigned int Ta0() const;
			bool Ta0Exists() const;
		private:
		};

		// This method is used for reading the Intel(R) AMT device's internal clock.
		virtual unsigned int GetLowAccuracyTimeSynch(GetLowAccuracyTimeSynch_OUTPUT &output);

		//Input parameter for function SetHighAccuracyTimeSynch
		class CIMFRAMEWORK_API SetHighAccuracyTimeSynch_INPUT : public CimParam
		{
		public:
			// Class Constructor
			SetHighAccuracyTimeSynch_INPUT() : CimParam() {}

			// Class Destructor
			~SetHighAccuracyTimeSynch_INPUT(){}

			// Required, The time value received from invoking GetLowAccuracyTimeSynch().
			void Ta0(const unsigned int value); 

			// Required, The remote client timestamp after getting a response from GetLowAccuracyTimeSynch(). should be greater than January 1 2004.
			void Tm1(const unsigned int value); 

			// Required, The remote client timestamp obtained immediately prior to invoking this method. should be greater than January 1 2004.
			void Tm2(const unsigned int value); 

			const VectorFieldData GetAllFields() const;
		private:
			static const CimFieldAttribute _metadata[];
		};

		// This method is used to synchronize the Intel(R) AMT device's internal clock with an external clock. Intel(R) AMT Release 2.0 constrains this value to be greater than January 1 2004.
		virtual unsigned int SetHighAccuracyTimeSynch(const SetHighAccuracyTimeSynch_INPUT &input);

		//Input parameter for function EnableLocalTimeSync
		class CIMFRAMEWORK_API EnableLocalTimeSync_INPUT : public CimParam
		{
		public:
			// Class Constructor
			EnableLocalTimeSync_INPUT() : CimParam() {}

			// Class Destructor
			~EnableLocalTimeSync_INPUT(){}

			// Required, Determines if user with LOCAL_SYSTEM_REALM permission can set the time.
			void Enable(const bool value); 

			const VectorFieldData GetAllFields() const;
		private:
			static const CimFieldAttribute _metadata[];
		};

		// This method sets the LocalTimeSyncEnabled property.
		virtual unsigned int EnableLocalTimeSync(const EnableLocalTimeSync_INPUT &input);

		 // Function used by the factory
		static CimBase *CreateFromCimObject(const CimObject &object);

		static vector<shared_ptr<AMT_TimeSynchronizationService> > Enumerate(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		// Overloaded delete which supplies the internal resourceURI
		static void Delete(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		using CimBase::Delete;

	protected:
		 // Protected constructor to be used by derived classes
		AMT_TimeSynchronizationService(ICimWsmanClient *client, const string &class_name,
			const string &class_ns, const string &prefix, const string &uri): CIM_Service(client, class_name, class_ns, prefix, uri)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_Service::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 2);
			}
		}
		 // Protected constructor which receives CimObject
		AMT_TimeSynchronizationService(const CimObject &object)
			: CIM_Service(object)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_Service::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 2);
			}
		}
		// Called by derived classes
		void SetMetaData(vector<CimFieldAttribute>& childMetaData)
		{
			CIM_Service::SetMetaData(childMetaData);
			CimBase::SetMetaData(childMetaData, _metadata, 2);
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
#endif // AMT_TIMESYNCHRONIZATIONSERVICE_H
