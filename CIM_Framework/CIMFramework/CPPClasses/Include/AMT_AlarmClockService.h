//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       AMT_AlarmClockService.h
//
//  Contents:   AMT Alarm Clock Service derived from Service and provides the ability to set an alarm time to turn the host computer system on. Setting an alarm time is done by calling "AddAlarm" method."NextAMTAlarmTime" and "AMTAlarmClockInterval" properties are deprecated and "AddAlarm" should be used instead.
//
//              This file was automatically generated from AMT_AlarmClockService.mof,  version: 8.0.0
//
//----------------------------------------------------------------------------
#ifndef AMT_ALARMCLOCKSERVICE_H
#define AMT_ALARMCLOCKSERVICE_H 1
#include "IPS_AlarmClockOccurrence.h"
#include "CIM_Service.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	// AMT Alarm Clock Service derived from Service and provides the ability to set an alarm time to turn the host computer system on. Setting an alarm time is done by calling "AddAlarm" method."NextAMTAlarmTime" and "AMTAlarmClockInterval" properties are deprecated and "AddAlarm" should be used instead. 
	class CIMFRAMEWORK_API AMT_AlarmClockService  : public CIM_Service
	{
	public:

		//Default constructor
		AMT_AlarmClockService()
			: CIM_Service(NULL, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_Service::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 2);
			}
		}

		//constructor which receives WSMan client
		AMT_AlarmClockService(ICimWsmanClient *client)
			: CIM_Service(client, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_Service::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 2);
			}
		}

		//Destructor
		virtual ~AMT_AlarmClockService(){}

		// The "type" information for the object. Gettors only.
		virtual const string& ResourceURI() const { return CLASS_URI; }
		static const string& ClassResourceURI() { return CLASS_URI; }
		virtual const string& XmlNamespace() const { return CLASS_NS; }
		virtual const string& XmlPrefix() const { return CLASS_NS_PREFIX; }
		virtual const string& ObjectType() const { return CLASS_NAME; }
		static const string& ClassObjectType() { return CLASS_NAME; }

		// Class representing AMT_AlarmClockService keys
		class CimKeys : public CIM_Service::CimKeys
		{
		public:
		};

		// class fields declarations

		// Optional, Specifies the next AMT alarm time. "NextAMTAlarmTime" must be in Datetime format.This property is deprecated, you should use the AddAlarm() method instead.
		const CimDateTime NextAMTAlarmTime() const;

		// Optional, Specifies the next AMT alarm time. "NextAMTAlarmTime" must be in Datetime format.This property is deprecated, you should use the AddAlarm() method instead.
		void NextAMTAlarmTime(const CimDateTime &value); 

		// Is true if the field NextAMTAlarmTime exists in the current object, otherwise is false.
		bool NextAMTAlarmTimeExists() const;

		// Remove NextAMTAlarmTime field.
		void RemoveNextAMTAlarmTime(); 

		// Optional, Specifies the alarm time interval. "AMTAlarmClockInterval" must be in Interval format.This property is deprecated, you should use the AddAlarm() method instead.
		const CimDateTime AMTAlarmClockInterval() const;

		// Optional, Specifies the alarm time interval. "AMTAlarmClockInterval" must be in Interval format.This property is deprecated, you should use the AddAlarm() method instead.
		void AMTAlarmClockInterval(const CimDateTime &value); 

		// Is true if the field AMTAlarmClockInterval exists in the current object, otherwise is false.
		bool AMTAlarmClockIntervalExists() const;

		// Remove AMTAlarmClockInterval field.
		void RemoveAMTAlarmClockInterval(); 

		//Input parameter for function AddAlarm
		class CIMFRAMEWORK_API AddAlarm_INPUT : public CimParam
		{
		public:
			// Class Constructor
			AddAlarm_INPUT() : CimParam() {}

			// Class Destructor
			~AddAlarm_INPUT(){}

			// Required, A template for creating a new alarm of type IPS_AlarmClockOccurrence.
			void AlarmTemplate(const IPS_AlarmClockOccurrence &value); 

			const VectorFieldData GetAllFields() const;
		private:
			static const CimFieldAttribute _metadata[];
		};

		//Output parameter for function AddAlarm
		class CIMFRAMEWORK_API AddAlarm_OUTPUT : public CimParam
		{
		public:
			// Class Constructor
			AddAlarm_OUTPUT() : CimParam() {}

			// Class Destructor
			~AddAlarm_OUTPUT(){}

			// class fields
			// A reference to the created instance of IPS_AlarmClockOccurrence.
			const CimReference AlarmClock() const;
			bool AlarmClockExists() const;
		private:
		};

		// This method creates an alarm that would wake the system at a given time.The method receives as input an embedded instance of type IPS_AlarmClockOccurrence, with the following fields set: StartTime, Interval, InstanceID, DeleteOnCompletion. Upon success, the method creates an instance of IPS_AlarmClockOccurrence which is associated with AlarmClockService.The method would fail if 5 instances or more of IPS_AlarmClockOccurrence already exist in the system.
		virtual unsigned int AddAlarm(const AddAlarm_INPUT &input, AddAlarm_OUTPUT &output);

		 // Function used by the factory
		static CimBase *CreateFromCimObject(const CimObject &object);

		static vector<shared_ptr<AMT_AlarmClockService> > Enumerate(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		// Overloaded delete which supplies the internal resourceURI
		static void Delete(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		using CimBase::Delete;

	protected:
		 // Protected constructor to be used by derived classes
		AMT_AlarmClockService(ICimWsmanClient *client, const string &class_name,
			const string &class_ns, const string &prefix, const string &uri): CIM_Service(client, class_name, class_ns, prefix, uri)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_Service::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 2);
			}
		}
		 // Protected constructor which receives CimObject
		AMT_AlarmClockService(const CimObject &object)
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
#endif // AMT_ALARMCLOCKSERVICE_H
