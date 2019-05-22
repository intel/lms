//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_Job.h
//
//  Contents:   A Job is a LogicalElement that represents an executing unit of work, such as a script or a print job. A Job is distinct from a Process in that a Job can be scheduled or queued, and its execution is not limited to a single system.
//
//              This file was automatically generated from CIM_Job.mof,  version: 2.10.0
//
//----------------------------------------------------------------------------
#ifndef CIM_JOB_H
#define CIM_JOB_H 1
#include "CIM_LogicalElement.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	// A Job is a LogicalElement that represents an executing unit of work, such as a script or a print job. A Job is distinct from a Process in that a Job can be scheduled or queued, and its execution is not limited to a single system.
	class CIMFRAMEWORK_API CIM_Job  : public CIM_LogicalElement
	{
	public:

		//Default constructor
		CIM_Job()
			: CIM_LogicalElement(NULL, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_LogicalElement::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 21);
			}
		}

		//constructor which receives WSMan client
		CIM_Job(ICimWsmanClient *client)
			: CIM_LogicalElement(client, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_LogicalElement::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 21);
			}
		}

		//Destructor
		virtual ~CIM_Job(){}

		// The "type" information for the object. Gettors only.
		virtual const string& ResourceURI() const { return CLASS_URI; }
		static const string& ClassResourceURI() { return CLASS_URI; }
		virtual const string& XmlNamespace() const { return CLASS_NS; }
		virtual const string& XmlPrefix() const { return CLASS_NS_PREFIX; }
		virtual const string& ObjectType() const { return CLASS_NAME; }
		static const string& ClassObjectType() { return CLASS_NAME; }

		// Class representing CIM_Job keys
		class CimKeys : public CIM_LogicalElement::CimKeys
		{
		public:
		};

		// class fields declarations

		// Optional, A free-form string that represents the status of the job. The primary status is reflected in the inherited OperationalStatus property. JobStatus provides additional, implementation-specific details.
		const string JobStatus() const;

		// Optional, A free-form string that represents the status of the job. The primary status is reflected in the inherited OperationalStatus property. JobStatus provides additional, implementation-specific details.
		void JobStatus(const string &value); 

		// Is true if the field JobStatus exists in the current object, otherwise is false.
		bool JobStatusExists() const;

		// Remove JobStatus field.
		void RemoveJobStatus(); 

		// Optional, The time that the Job was submitted to execute. A value of all zeroes indicates that the owning element is not capable of reporting a date and time. Therefore, the ScheduledStartTime and StartTime are reported as intervals relative to the time their values are requested.
		const CimDateTime TimeSubmitted() const;

		// Optional, The time that the Job was submitted to execute. A value of all zeroes indicates that the owning element is not capable of reporting a date and time. Therefore, the ScheduledStartTime and StartTime are reported as intervals relative to the time their values are requested.
		void TimeSubmitted(const CimDateTime &value); 

		// Is true if the field TimeSubmitted exists in the current object, otherwise is false.
		bool TimeSubmittedExists() const;

		// Remove TimeSubmitted field.
		void RemoveTimeSubmitted(); 

		// Optional, The time that the current Job is scheduled to start. This time can be represented by the actual date and time, or an interval relative to the time that this property is requested. A value of all zeroes indicates that the Job is already executing. The property is deprecated in lieu of the more expressive scheduling properties, RunMonth, RunDay, RunDayOfWeek, and RunStartInterval.
		const CimDateTime ScheduledStartTime() const;

		// Optional, The time that the current Job is scheduled to start. This time can be represented by the actual date and time, or an interval relative to the time that this property is requested. A value of all zeroes indicates that the Job is already executing. The property is deprecated in lieu of the more expressive scheduling properties, RunMonth, RunDay, RunDayOfWeek, and RunStartInterval.
		void ScheduledStartTime(const CimDateTime &value); 

		// Is true if the field ScheduledStartTime exists in the current object, otherwise is false.
		bool ScheduledStartTimeExists() const;

		// Remove ScheduledStartTime field.
		void RemoveScheduledStartTime(); 

		// Optional, The time that the Job was actually started. This time can be represented by an actual date and time, or by an interval relative to the time that this property is requested. Note that this property is also present in the JobProcessingStatistics class. This class is necessary to capture the processing information for recurring Jobs, because only the 'last' run time can be stored in this single-valued property.
		const CimDateTime StartTime() const;

		// Optional, The time that the Job was actually started. This time can be represented by an actual date and time, or by an interval relative to the time that this property is requested. Note that this property is also present in the JobProcessingStatistics class. This class is necessary to capture the processing information for recurring Jobs, because only the 'last' run time can be stored in this single-valued property.
		void StartTime(const CimDateTime &value); 

		// Is true if the field StartTime exists in the current object, otherwise is false.
		bool StartTimeExists() const;

		// Remove StartTime field.
		void RemoveStartTime(); 

		// Optional, The time interval that the Job has been executing or the total execution time if the Job is complete. Note that this property is also present in the JobProcessingStatistics class. This class is necessary to capture the processing information for recurring Jobs, because only the 'last' run time can be stored in this single-valued property.
		const CimDateTime ElapsedTime() const;

		// Optional, The time interval that the Job has been executing or the total execution time if the Job is complete. Note that this property is also present in the JobProcessingStatistics class. This class is necessary to capture the processing information for recurring Jobs, because only the 'last' run time can be stored in this single-valued property.
		void ElapsedTime(const CimDateTime &value); 

		// Is true if the field ElapsedTime exists in the current object, otherwise is false.
		bool ElapsedTimeExists() const;

		// Remove ElapsedTime field.
		void RemoveElapsedTime(); 

		// Optional, The number of times that the Job should be run. A value of 1 indicates that the Job is not recurring, while any non-zero value indicates a limit to the number of times that the Job will recur. Zero indicates that there is no limit to the number of times that the Job can be processed, but that it is terminated either after the UntilTime or by manual intervention. By default, a Job is processed once.
		const unsigned int JobRunTimes() const;

		// Optional, The number of times that the Job should be run. A value of 1 indicates that the Job is not recurring, while any non-zero value indicates a limit to the number of times that the Job will recur. Zero indicates that there is no limit to the number of times that the Job can be processed, but that it is terminated either after the UntilTime or by manual intervention. By default, a Job is processed once.
		void JobRunTimes(const unsigned int value); 

		// Is true if the field JobRunTimes exists in the current object, otherwise is false.
		bool JobRunTimesExists() const;

		// Remove JobRunTimes field.
		void RemoveJobRunTimes(); 

		// Optional, The month during which the Job should be processed. Specify 0 for January, 1 for February, and so on.
		const unsigned char RunMonth() const;

		// Optional, The month during which the Job should be processed. Specify 0 for January, 1 for February, and so on.
		void RunMonth(const unsigned char &value); 

		// Is true if the field RunMonth exists in the current object, otherwise is false.
		bool RunMonthExists() const;

		// Remove RunMonth field.
		void RemoveRunMonth(); 

		// Optional, The day in the month on which the Job should be processed. There are two different interpretations for this property, depending on the value of DayOfWeek. In one case, RunDay defines the day-in-month on which the Job is processed. This interpretation is used when the DayOfWeek is 0. A positive or negative integer indicates whether the RunDay should be calculated from the beginning or end of the month. For example, 5 indicates the fifth day in the RunMonth and -1 indicates the last day in the RunMonth. 
		// 
		// When RunDayOfWeek is not 0, RunDay is the day-in-month on which the Job is processed, defined in conjunction with RunDayOfWeek. For example, if RunDay is 15 and RunDayOfWeek is Saturday, then the Job is processed on the first Saturday on or after the 15th day in the RunMonth (for example, the third Saturday in the month). If RunDay is 20 and RunDayOfWeek is -Saturday, then this indicates the first Saturday on or before the 20th day in the RunMonth. If RunDay is -1 and RunDayOfWeek is -Sunday, then this indicates the last Sunday in the RunMonth.
		const char RunDay() const;

		// Optional, The day in the month on which the Job should be processed. There are two different interpretations for this property, depending on the value of DayOfWeek. In one case, RunDay defines the day-in-month on which the Job is processed. This interpretation is used when the DayOfWeek is 0. A positive or negative integer indicates whether the RunDay should be calculated from the beginning or end of the month. For example, 5 indicates the fifth day in the RunMonth and -1 indicates the last day in the RunMonth. 
		// 
		// When RunDayOfWeek is not 0, RunDay is the day-in-month on which the Job is processed, defined in conjunction with RunDayOfWeek. For example, if RunDay is 15 and RunDayOfWeek is Saturday, then the Job is processed on the first Saturday on or after the 15th day in the RunMonth (for example, the third Saturday in the month). If RunDay is 20 and RunDayOfWeek is -Saturday, then this indicates the first Saturday on or before the 20th day in the RunMonth. If RunDay is -1 and RunDayOfWeek is -Sunday, then this indicates the last Sunday in the RunMonth.
		void RunDay(const char &value); 

		// Is true if the field RunDay exists in the current object, otherwise is false.
		bool RunDayExists() const;

		// Remove RunDay field.
		void RemoveRunDay(); 

		// Optional, A positive or negative integer used in conjunction with RunDay to indicate the day of the week on which the Job is processed. RunDayOfWeek is set to 0 to indicate an exact day of the month, such as March 1. A positive integer (representing Sunday, Monday, ..., Saturday) means that the day of week is found on or after the specified RunDay. A negative integer (representing -Sunday, -Monday, ..., -Saturday) means that the day of week is found on or BEFORE the RunDay.
		const char RunDayOfWeek() const;

		// Optional, A positive or negative integer used in conjunction with RunDay to indicate the day of the week on which the Job is processed. RunDayOfWeek is set to 0 to indicate an exact day of the month, such as March 1. A positive integer (representing Sunday, Monday, ..., Saturday) means that the day of week is found on or after the specified RunDay. A negative integer (representing -Sunday, -Monday, ..., -Saturday) means that the day of week is found on or BEFORE the RunDay.
		void RunDayOfWeek(const char &value); 

		// Is true if the field RunDayOfWeek exists in the current object, otherwise is false.
		bool RunDayOfWeekExists() const;

		// Remove RunDayOfWeek field.
		void RemoveRunDayOfWeek(); 

		// Optional, The time interval after midnight when the Job should be processed. For example, 
		// 00000000020000.000000:000 
		// indicates that the Job should be run on or after two o'clock, local time or UTC time (distinguished using the LocalOrUtcTime property.
		const CimDateTime RunStartInterval() const;

		// Optional, The time interval after midnight when the Job should be processed. For example, 
		// 00000000020000.000000:000 
		// indicates that the Job should be run on or after two o'clock, local time or UTC time (distinguished using the LocalOrUtcTime property.
		void RunStartInterval(const CimDateTime &value); 

		// Is true if the field RunStartInterval exists in the current object, otherwise is false.
		bool RunStartIntervalExists() const;

		// Remove RunStartInterval field.
		void RemoveRunStartInterval(); 

		// Optional, This property indicates whether the times represented in the RunStartInterval and UntilTime properties represent local times or UTC times. Time values are synchronized worldwide by using the enumeration value 2, "UTC Time".
		const unsigned short LocalOrUtcTime() const;

		// Optional, This property indicates whether the times represented in the RunStartInterval and UntilTime properties represent local times or UTC times. Time values are synchronized worldwide by using the enumeration value 2, "UTC Time".
		void LocalOrUtcTime(const unsigned short value); 

		// Is true if the field LocalOrUtcTime exists in the current object, otherwise is false.
		bool LocalOrUtcTimeExists() const;

		// Remove LocalOrUtcTime field.
		void RemoveLocalOrUtcTime(); 

		// Optional, The time after which the Job is invalid or should be stopped. This time can be represented by an actual date and time, or by an interval relative to the time that this property is requested. A value of all nines indicates that the Job can run indefinitely.
		const CimDateTime UntilTime() const;

		// Optional, The time after which the Job is invalid or should be stopped. This time can be represented by an actual date and time, or by an interval relative to the time that this property is requested. A value of all nines indicates that the Job can run indefinitely.
		void UntilTime(const CimDateTime &value); 

		// Is true if the field UntilTime exists in the current object, otherwise is false.
		bool UntilTimeExists() const;

		// Remove UntilTime field.
		void RemoveUntilTime(); 

		// Optional, The User who is to be notified upon the Job completion or failure.
		const string Notify() const;

		// Optional, The User who is to be notified upon the Job completion or failure.
		void Notify(const string &value); 

		// Is true if the field Notify exists in the current object, otherwise is false.
		bool NotifyExists() const;

		// Remove Notify field.
		void RemoveNotify(); 

		// Optional, The User that submitted the Job, or the Service or method name that caused the job to be created.
		const string Owner() const;

		// Optional, The User that submitted the Job, or the Service or method name that caused the job to be created.
		void Owner(const string &value); 

		// Is true if the field Owner exists in the current object, otherwise is false.
		bool OwnerExists() const;

		// Remove Owner field.
		void RemoveOwner(); 

		// Optional, Indicates the urgency or importance of execution of the Job. The lower the number, the higher the priority. Note that this property is also present in the JobProcessingStatistics class. This class is necessary to capture the setting information that would influence the results of a job.
		const unsigned int Priority() const;

		// Optional, Indicates the urgency or importance of execution of the Job. The lower the number, the higher the priority. Note that this property is also present in the JobProcessingStatistics class. This class is necessary to capture the setting information that would influence the results of a job.
		void Priority(const unsigned int value); 

		// Is true if the field Priority exists in the current object, otherwise is false.
		bool PriorityExists() const;

		// Remove Priority field.
		void RemovePriority(); 

		// Optional, The percentage of the job that has completed at the time that this value is requested. Note that this property is also present in the JobProcessingStatistics class. This class is necessary to capture the processing information for recurring Jobs, because only the 'last' run data can be stored in this single-valued property. 
		// Note that the value 101 is undefined and will be not be allowed in the next major revision of the specification.
		const unsigned short PercentComplete() const;

		// Optional, The percentage of the job that has completed at the time that this value is requested. Note that this property is also present in the JobProcessingStatistics class. This class is necessary to capture the processing information for recurring Jobs, because only the 'last' run data can be stored in this single-valued property. 
		// Note that the value 101 is undefined and will be not be allowed in the next major revision of the specification.
		void PercentComplete(const unsigned short value); 

		// Is true if the field PercentComplete exists in the current object, otherwise is false.
		bool PercentCompleteExists() const;

		// Remove PercentComplete field.
		void RemovePercentComplete(); 

		// Optional, Indicates whether or not the job should be automatically deleted upon completion. Note that the 'completion' of a recurring job is defined by its JobRunTimes or UntilTime properties, or when the Job is terminated by manual intervention. If this property is set to false and the job completes, then the extrinsic method DeleteInstance must be used to delete the job instead of updating this property.
		const bool DeleteOnCompletion() const;

		// Optional, Indicates whether or not the job should be automatically deleted upon completion. Note that the 'completion' of a recurring job is defined by its JobRunTimes or UntilTime properties, or when the Job is terminated by manual intervention. If this property is set to false and the job completes, then the extrinsic method DeleteInstance must be used to delete the job instead of updating this property.
		void DeleteOnCompletion(const bool value); 

		// Is true if the field DeleteOnCompletion exists in the current object, otherwise is false.
		bool DeleteOnCompletionExists() const;

		// Remove DeleteOnCompletion field.
		void RemoveDeleteOnCompletion(); 

		// Optional, A vendor-specific error code. The value must be set to zero if the Job completed without error. Note that this property is also present in the JobProcessingStatistics class. This class is necessary to capture the processing information for recurring Jobs, because only the 'last' run error can be stored in this single-valued property.
		const unsigned short ErrorCode() const;

		// Optional, A vendor-specific error code. The value must be set to zero if the Job completed without error. Note that this property is also present in the JobProcessingStatistics class. This class is necessary to capture the processing information for recurring Jobs, because only the 'last' run error can be stored in this single-valued property.
		void ErrorCode(const unsigned short value); 

		// Is true if the field ErrorCode exists in the current object, otherwise is false.
		bool ErrorCodeExists() const;

		// Remove ErrorCode field.
		void RemoveErrorCode(); 

		// Optional, A free-form string that contains the vendor error description. Note that this property is also present in the JobProcessingStatistics class. This class is necessary to capture the processing information for recurring Jobs, because only the 'last' run error can be stored in this single-valued property.
		const string ErrorDescription() const;

		// Optional, A free-form string that contains the vendor error description. Note that this property is also present in the JobProcessingStatistics class. This class is necessary to capture the processing information for recurring Jobs, because only the 'last' run error can be stored in this single-valued property.
		void ErrorDescription(const string &value); 

		// Is true if the field ErrorDescription exists in the current object, otherwise is false.
		bool ErrorDescriptionExists() const;

		// Remove ErrorDescription field.
		void RemoveErrorDescription(); 

		// Optional, Describes the recovery action to be taken for an unsuccessfully run Job. The possible values are: 
		// 0 = "Unknown", meaning it is unknown as to what recovery action to take 
		// 1 = "Other", indicating that the recovery action will be specified in the OtherRecoveryAction property 
		// 2 = "Do Not Continue", meaning stop the execution of the job and appropriately update its status 
		// 3 = "Continue With Next Job", meaning continue with the next job in the queue 
		// 4 = "Re-run Job", indicating that the job should be re-run 
		// 5 = "Run Recovery Job", meaning run the Job associated using the RecoveryJob relationship. Note that the recovery Job must already be in the queue from which it will run.
		const unsigned short RecoveryAction() const;

		// Optional, Describes the recovery action to be taken for an unsuccessfully run Job. The possible values are: 
		// 0 = "Unknown", meaning it is unknown as to what recovery action to take 
		// 1 = "Other", indicating that the recovery action will be specified in the OtherRecoveryAction property 
		// 2 = "Do Not Continue", meaning stop the execution of the job and appropriately update its status 
		// 3 = "Continue With Next Job", meaning continue with the next job in the queue 
		// 4 = "Re-run Job", indicating that the job should be re-run 
		// 5 = "Run Recovery Job", meaning run the Job associated using the RecoveryJob relationship. Note that the recovery Job must already be in the queue from which it will run.
		void RecoveryAction(const unsigned short value); 

		// Is true if the field RecoveryAction exists in the current object, otherwise is false.
		bool RecoveryActionExists() const;

		// Remove RecoveryAction field.
		void RemoveRecoveryAction(); 

		// Optional, A string describing the recovery action when the RecoveryAction property of the instance is 1 ("Other").
		const string OtherRecoveryAction() const;

		// Optional, A string describing the recovery action when the RecoveryAction property of the instance is 1 ("Other").
		void OtherRecoveryAction(const string &value); 

		// Is true if the field OtherRecoveryAction exists in the current object, otherwise is false.
		bool OtherRecoveryActionExists() const;

		// Remove OtherRecoveryAction field.
		void RemoveOtherRecoveryAction(); 

		//Input parameter for function KillJob
		class CIMFRAMEWORK_API KillJob_INPUT : public CimParam
		{
		public:
			// Class Constructor
			KillJob_INPUT() : CimParam() {}

			// Class Destructor
			~KillJob_INPUT(){}

			// Optional, Indicates whether or not the Job should be automatically deleted upon termination. This parameter takes precedence over the property, DeleteOnCompletion.
			void DeleteOnKill(const bool value); 

			const VectorFieldData GetAllFields() const;
		private:
			static const CimFieldAttribute _metadata[];
		};

		// KillJob is being deprecated because there is no distinction made between an orderly shutdown and an immediate kill. CIM_ConcreteJob.RequestStateChange() provides 'Terminate' and 'Kill' options to allow this distinction. 
		// A method to kill this job and any underlying processes, and to remove any 'dangling' associations.
		virtual unsigned int KillJob(const KillJob_INPUT &input);

		 // Function used by the factory
		static CimBase *CreateFromCimObject(const CimObject &object);

		static vector<shared_ptr<CIM_Job> > Enumerate(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		// Overloaded delete which supplies the internal resourceURI
		static void Delete(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		using CimBase::Delete;

	protected:
		 // Protected constructor to be used by derived classes
		CIM_Job(ICimWsmanClient *client, const string &class_name,
			const string &class_ns, const string &prefix, const string &uri): CIM_LogicalElement(client, class_name, class_ns, prefix, uri)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_LogicalElement::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 21);
			}
		}
		 // Protected constructor which receives CimObject
		CIM_Job(const CimObject &object)
			: CIM_LogicalElement(object)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_LogicalElement::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 21);
			}
		}
		// Called by derived classes
		void SetMetaData(vector<CimFieldAttribute>& childMetaData)
		{
			CIM_LogicalElement::SetMetaData(childMetaData);
			CimBase::SetMetaData(childMetaData, _metadata, 21);
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
#endif // CIM_JOB_H
