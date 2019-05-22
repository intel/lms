//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_Watchdog.h
//
//  Contents:   CIM_Watchdog is a timer that is implemented in the system hardware. It allows the hardware to monitor the state of the Operating System, BIOS, or a software component that is installed on the System. If the monitored component fails to re-arm the timer before its expiration, the hardware assumes that the System is in a critical state, and could reset the ComputerSystem. This feature can also be used as an application watchdog timer for a mission-critical application. In this case, the application would assume responsibility for re-arming the timer before expiration.
//
//              This file was automatically generated from CIM_Watchdog.mof,  version: 2.10.0
//
//----------------------------------------------------------------------------
#ifndef CIM_WATCHDOG_H
#define CIM_WATCHDOG_H 1
#include "CIM_LogicalDevice.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	// CIM_Watchdog is a timer that is implemented in the system hardware. It allows the hardware to monitor the state of the Operating System, BIOS, or a software component that is installed on the System. If the monitored component fails to re-arm the timer before its expiration, the hardware assumes that the System is in a critical state, and could reset the ComputerSystem. This feature can also be used as an application watchdog timer for a mission-critical application. In this case, the application would assume responsibility for re-arming the timer before expiration.
	class CIMFRAMEWORK_API CIM_Watchdog  : public CIM_LogicalDevice
	{
	public:

		//Default constructor
		CIM_Watchdog()
			: CIM_LogicalDevice(NULL, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_LogicalDevice::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 7);
			}
		}

		//constructor which receives WSMan client
		CIM_Watchdog(ICimWsmanClient *client)
			: CIM_LogicalDevice(client, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_LogicalDevice::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 7);
			}
		}

		//Destructor
		virtual ~CIM_Watchdog(){}

		// The "type" information for the object. Gettors only.
		virtual const string& ResourceURI() const { return CLASS_URI; }
		static const string& ClassResourceURI() { return CLASS_URI; }
		virtual const string& XmlNamespace() const { return CLASS_NS; }
		virtual const string& XmlPrefix() const { return CLASS_NS_PREFIX; }
		virtual const string& ObjectType() const { return CLASS_NAME; }
		static const string& ClassObjectType() { return CLASS_NAME; }

		// Class representing CIM_Watchdog keys
		class CimKeys : public CIM_LogicalDevice::CimKeys
		{
		public:
		};

		// class fields declarations

		// Optional, The entity that is currently being monitored by the WatchDog. This property is used to identify the module that is responsible for re-arming, or whose information is used to re-arm, the watchdog at periodic intervals.
		const unsigned short MonitoredEntity() const;

		// Optional, The entity that is currently being monitored by the WatchDog. This property is used to identify the module that is responsible for re-arming, or whose information is used to re-arm, the watchdog at periodic intervals.
		void MonitoredEntity(const unsigned short value); 

		// Is true if the field MonitoredEntity exists in the current object, otherwise is false.
		bool MonitoredEntityExists() const;

		// Remove MonitoredEntity field.
		void RemoveMonitoredEntity(); 

		// Optional, A string that describes more textual information about the monitored entity.
		const string MonitoredEntityDescription() const;

		// Optional, A string that describes more textual information about the monitored entity.
		void MonitoredEntityDescription(const string &value); 

		// Is true if the field MonitoredEntityDescription exists in the current object, otherwise is false.
		bool MonitoredEntityDescriptionExists() const;

		// Remove MonitoredEntityDescription field.
		void RemoveMonitoredEntityDescription(); 

		// Optional, The timeout interval that is used by the watchdog, in MicroSeconds.
		const unsigned int TimeoutInterval() const;

		// Optional, The timeout interval that is used by the watchdog, in MicroSeconds.
		void TimeoutInterval(const unsigned int value); 

		// Is true if the field TimeoutInterval exists in the current object, otherwise is false.
		bool TimeoutIntervalExists() const;

		// Remove TimeoutInterval field.
		void RemoveTimeoutInterval(); 

		// Optional, Resolution of the timer. For example, if this value is 100, then the timer can expire anytime between (TimeoutInterval- 100) microseconds or (TimeoutInterval+100) microseconds.
		const unsigned int TimerResolution() const;

		// Optional, Resolution of the timer. For example, if this value is 100, then the timer can expire anytime between (TimeoutInterval- 100) microseconds or (TimeoutInterval+100) microseconds.
		void TimerResolution(const unsigned int value); 

		// Is true if the field TimerResolution exists in the current object, otherwise is false.
		bool TimerResolutionExists() const;

		// Remove TimerResolution field.
		void RemoveTimerResolution(); 

		// Optional, The time of the last timer expiry.
		const CimDateTime TimeOfLastExpiration() const;

		// Optional, The time of the last timer expiry.
		void TimeOfLastExpiration(const CimDateTime &value); 

		// Is true if the field TimeOfLastExpiration exists in the current object, otherwise is false.
		bool TimeOfLastExpirationExists() const;

		// Remove TimeOfLastExpiration field.
		void RemoveTimeOfLastExpiration(); 

		// Optional, Monitored entity at the time of last timer expiry.
		const unsigned short MonitoredEntityOnLastExpiration() const;

		// Optional, Monitored entity at the time of last timer expiry.
		void MonitoredEntityOnLastExpiration(const unsigned short value); 

		// Is true if the field MonitoredEntityOnLastExpiration exists in the current object, otherwise is false.
		bool MonitoredEntityOnLastExpirationExists() const;

		// Remove MonitoredEntityOnLastExpiration field.
		void RemoveMonitoredEntityOnLastExpiration(); 

		// Optional, The action that should happen upon the expiry of the watchdog.
		const unsigned short ActionOnExpiration() const;

		// Optional, The action that should happen upon the expiry of the watchdog.
		void ActionOnExpiration(const unsigned short value); 

		// Is true if the field ActionOnExpiration exists in the current object, otherwise is false.
		bool ActionOnExpirationExists() const;

		// Remove ActionOnExpiration field.
		void RemoveActionOnExpiration(); 

		 // Function used by the factory
		static CimBase *CreateFromCimObject(const CimObject &object);

		static vector<shared_ptr<CIM_Watchdog> > Enumerate(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		// Overloaded delete which supplies the internal resourceURI
		static void Delete(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		using CimBase::Delete;

	protected:
		 // Protected constructor to be used by derived classes
		CIM_Watchdog(ICimWsmanClient *client, const string &class_name,
			const string &class_ns, const string &prefix, const string &uri): CIM_LogicalDevice(client, class_name, class_ns, prefix, uri)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_LogicalDevice::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 7);
			}
		}
		 // Protected constructor which receives CimObject
		CIM_Watchdog(const CimObject &object)
			: CIM_LogicalDevice(object)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_LogicalDevice::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 7);
			}
		}
		// Called by derived classes
		void SetMetaData(vector<CimFieldAttribute>& childMetaData)
		{
			CIM_LogicalDevice::SetMetaData(childMetaData);
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
#endif // CIM_WATCHDOG_H
