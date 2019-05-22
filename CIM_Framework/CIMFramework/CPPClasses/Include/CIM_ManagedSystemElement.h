//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_ManagedSystemElement.h
//
//  Contents:   CIM_ManagedSystemElement is the base class for the System Element hierarchy. Any distinguishable component of a System is a candidate for inclusion in this class. Examples of system components include: 
//              - software components such as application servers, databases, and applications 
//              - operating system components such as files, processes, and threads 
//              - device components such as disk drives, controllers, processors, and printers 
//              - physical components such as chips and cards.
//
//              This file was automatically generated from CIM_ManagedSystemElement.mof,  version: 2.28.0
//
//----------------------------------------------------------------------------
#ifndef CIM_MANAGEDSYSTEMELEMENT_H
#define CIM_MANAGEDSYSTEMELEMENT_H 1
#include "CIM_ManagedElement.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	// CIM_ManagedSystemElement is the base class for the System Element hierarchy. Any distinguishable component of a System is a candidate for inclusion in this class. Examples of system components include: 
	// - software components such as application servers, databases, and applications 
	// - operating system components such as files, processes, and threads 
	// - device components such as disk drives, controllers, processors, and printers 
	// - physical components such as chips and cards.
	class CIMFRAMEWORK_API CIM_ManagedSystemElement  : public CIM_ManagedElement
	{
	public:

		//Default constructor
		CIM_ManagedSystemElement()
			: CIM_ManagedElement(NULL, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_ManagedElement::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 10);
			}
		}

		//constructor which receives WSMan client
		CIM_ManagedSystemElement(ICimWsmanClient *client)
			: CIM_ManagedElement(client, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_ManagedElement::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 10);
			}
		}

		//Destructor
		virtual ~CIM_ManagedSystemElement(){}

		// The "type" information for the object. Gettors only.
		virtual const string& ResourceURI() const { return CLASS_URI; }
		static const string& ClassResourceURI() { return CLASS_URI; }
		virtual const string& XmlNamespace() const { return CLASS_NS; }
		virtual const string& XmlPrefix() const { return CLASS_NS_PREFIX; }
		virtual const string& ObjectType() const { return CLASS_NAME; }
		static const string& ClassObjectType() { return CLASS_NAME; }

		// Class representing CIM_ManagedSystemElement keys
		class CimKeys : public CIM_ManagedElement::CimKeys
		{
		public:
		};

		// class fields declarations

		// Optional, A datetime value that indicates when the object was installed. Lack of a value does not indicate that the object is not installed.
		const CimDateTime InstallDate() const;

		// Optional, A datetime value that indicates when the object was installed. Lack of a value does not indicate that the object is not installed.
		void InstallDate(const CimDateTime &value); 

		// Is true if the field InstallDate exists in the current object, otherwise is false.
		bool InstallDateExists() const;

		// Remove InstallDate field.
		void RemoveInstallDate(); 

		// Optional, The Name property defines the label by which the object is known. When subclassed, the Name property can be overridden to be a Key property.
		const string Name() const;

		// Optional, The Name property defines the label by which the object is known. When subclassed, the Name property can be overridden to be a Key property.
		void Name(const string &value); 

		// Is true if the field Name exists in the current object, otherwise is false.
		bool NameExists() const;

		// Remove Name field.
		void RemoveName(); 

		// Optional, Indicates the current statuses of the element. Various operational statuses are defined. Many of the enumeration's values are self-explanatory. However, a few are not and are described here in more detail. 
		// "Stressed" indicates that the element is functioning, but needs attention. Examples of "Stressed" states are overload, overheated, and so on. 
		// "Predictive Failure" indicates that an element is functioning nominally but predicting a failure in the near future. 
		// "In Service" describes an element being configured, maintained, cleaned, or otherwise administered. 
		// "No Contact" indicates that the monitoring system has knowledge of this element, but has never been able to establish communications with it. 
		// "Lost Communication" indicates that the ManagedSystem Element is known to exist and has been contacted successfully in the past, but is currently unreachable. 
		// "Stopped" and "Aborted" are similar, although the former implies a clean and orderly stop, while the latter implies an abrupt stop where the state and configuration of the element might need to be updated. 
		// "Dormant" indicates that the element is inactive or quiesced. 
		// "Supporting Entity in Error" indicates that this element might be "OK" but that another element, on which it is dependent, is in error. An example is a network service or endpoint that cannot function due to lower-layer networking problems. 
		// "Completed" indicates that the element has completed its operation. This value should be combined with either OK, Error, or Degraded so that a client can tell if the complete operation Completed with OK (passed), Completed with Error (failed), or Completed with Degraded (the operation finished, but it did not complete OK or did not report an error). 
		// "Power Mode" indicates that the element has additional power model information contained in the Associated PowerManagementService association. 
		// "Relocating" indicates the element is being relocated.
		// OperationalStatus replaces the Status property on ManagedSystemElement to provide a consistent approach to enumerations, to address implementation needs for an array property, and to provide a migration path from today's environment to the future. This change was not made earlier because it required the deprecated qualifier. Due to the widespread use of the existing Status property in management applications, it is strongly recommended that providers or instrumentation provide both the Status and OperationalStatus properties. Further, the first value of OperationalStatus should contain the primary status for the element. When instrumented, Status (because it is single-valued) should also provide the primary status of the element.
		const vector<unsigned short> OperationalStatus() const;

		// Optional, Indicates the current statuses of the element. Various operational statuses are defined. Many of the enumeration's values are self-explanatory. However, a few are not and are described here in more detail. 
		// "Stressed" indicates that the element is functioning, but needs attention. Examples of "Stressed" states are overload, overheated, and so on. 
		// "Predictive Failure" indicates that an element is functioning nominally but predicting a failure in the near future. 
		// "In Service" describes an element being configured, maintained, cleaned, or otherwise administered. 
		// "No Contact" indicates that the monitoring system has knowledge of this element, but has never been able to establish communications with it. 
		// "Lost Communication" indicates that the ManagedSystem Element is known to exist and has been contacted successfully in the past, but is currently unreachable. 
		// "Stopped" and "Aborted" are similar, although the former implies a clean and orderly stop, while the latter implies an abrupt stop where the state and configuration of the element might need to be updated. 
		// "Dormant" indicates that the element is inactive or quiesced. 
		// "Supporting Entity in Error" indicates that this element might be "OK" but that another element, on which it is dependent, is in error. An example is a network service or endpoint that cannot function due to lower-layer networking problems. 
		// "Completed" indicates that the element has completed its operation. This value should be combined with either OK, Error, or Degraded so that a client can tell if the complete operation Completed with OK (passed), Completed with Error (failed), or Completed with Degraded (the operation finished, but it did not complete OK or did not report an error). 
		// "Power Mode" indicates that the element has additional power model information contained in the Associated PowerManagementService association. 
		// "Relocating" indicates the element is being relocated.
		// OperationalStatus replaces the Status property on ManagedSystemElement to provide a consistent approach to enumerations, to address implementation needs for an array property, and to provide a migration path from today's environment to the future. This change was not made earlier because it required the deprecated qualifier. Due to the widespread use of the existing Status property in management applications, it is strongly recommended that providers or instrumentation provide both the Status and OperationalStatus properties. Further, the first value of OperationalStatus should contain the primary status for the element. When instrumented, Status (because it is single-valued) should also provide the primary status of the element.
		void OperationalStatus(const vector<unsigned short> &value); 

		// Is true if the field OperationalStatus exists in the current object, otherwise is false.
		bool OperationalStatusExists() const;

		// Remove OperationalStatus field.
		void RemoveOperationalStatus(); 

		// Optional, Strings describing the various OperationalStatus array values. For example, if "Stopping" is the value assigned to OperationalStatus, then this property may contain an explanation as to why an object is being stopped. Note that entries in this array are correlated with those at the same array index in OperationalStatus.
		const vector<string> StatusDescriptions() const;

		// Optional, Strings describing the various OperationalStatus array values. For example, if "Stopping" is the value assigned to OperationalStatus, then this property may contain an explanation as to why an object is being stopped. Note that entries in this array are correlated with those at the same array index in OperationalStatus.
		void StatusDescriptions(const vector<string> &value); 

		// Is true if the field StatusDescriptions exists in the current object, otherwise is false.
		bool StatusDescriptionsExists() const;

		// Remove StatusDescriptions field.
		void RemoveStatusDescriptions(); 

		// Optional, A string indicating the current status of the object. Various operational and non-operational statuses are defined. This property is deprecated in lieu of OperationalStatus, which includes the same semantics in its enumeration. This change is made for 3 reasons: 
		// 1) Status is more correctly defined as an array. This definition overcomes the limitation of describing status using a single value, when it is really a multi-valued property (for example, an element might be OK AND Stopped. 
		// 2) A MaxLen of 10 is too restrictive and leads to unclear enumerated values. 
		// 3) The change to a uint16 data type was discussed when CIM V2.0 was defined. However, existing V1.0 implementations used the string property and did not want to modify their code. Therefore, Status was grandfathered into the Schema. Use of the deprecated qualifier allows the maintenance of the existing property, but also permits an improved definition using OperationalStatus.
		const string Status() const;

		// Optional, A string indicating the current status of the object. Various operational and non-operational statuses are defined. This property is deprecated in lieu of OperationalStatus, which includes the same semantics in its enumeration. This change is made for 3 reasons: 
		// 1) Status is more correctly defined as an array. This definition overcomes the limitation of describing status using a single value, when it is really a multi-valued property (for example, an element might be OK AND Stopped. 
		// 2) A MaxLen of 10 is too restrictive and leads to unclear enumerated values. 
		// 3) The change to a uint16 data type was discussed when CIM V2.0 was defined. However, existing V1.0 implementations used the string property and did not want to modify their code. Therefore, Status was grandfathered into the Schema. Use of the deprecated qualifier allows the maintenance of the existing property, but also permits an improved definition using OperationalStatus.
		void Status(const string &value); 

		// Is true if the field Status exists in the current object, otherwise is false.
		bool StatusExists() const;

		// Remove Status field.
		void RemoveStatus(); 

		// Optional, Indicates the current health of the element. This attribute expresses the health of this element but not necessarily that of its subcomponents. The possible values are 0 to 30, where 5 means the element is entirely healthy and 30 means the element is completely non-functional. The following continuum is defined: 
		// "Non-recoverable Error" (30) - The element has completely failed, and recovery is not possible. All functionality provided by this element has been lost. 
		// "Critical Failure" (25) - The element is non-functional and recovery might not be possible. 
		// "Major Failure" (20) - The element is failing. It is possible that some or all of the functionality of this component is degraded or not working. 
		// "Minor Failure" (15) - All functionality is available but some might be degraded. 
		// "Degraded/Warning" (10) - The element is in working order and all functionality is provided. However, the element is not working to the best of its abilities. For example, the element might not be operating at optimal performance or it might be reporting recoverable errors. 
		// "OK" (5) - The element is fully functional and is operating within normal operational parameters and without error. 
		// "Unknown" (0) - The implementation cannot report on HealthState at this time. 
		// DMTF has reserved the unused portion of the continuum for additional HealthStates in the future.
		const unsigned short HealthState() const;

		// Optional, Indicates the current health of the element. This attribute expresses the health of this element but not necessarily that of its subcomponents. The possible values are 0 to 30, where 5 means the element is entirely healthy and 30 means the element is completely non-functional. The following continuum is defined: 
		// "Non-recoverable Error" (30) - The element has completely failed, and recovery is not possible. All functionality provided by this element has been lost. 
		// "Critical Failure" (25) - The element is non-functional and recovery might not be possible. 
		// "Major Failure" (20) - The element is failing. It is possible that some or all of the functionality of this component is degraded or not working. 
		// "Minor Failure" (15) - All functionality is available but some might be degraded. 
		// "Degraded/Warning" (10) - The element is in working order and all functionality is provided. However, the element is not working to the best of its abilities. For example, the element might not be operating at optimal performance or it might be reporting recoverable errors. 
		// "OK" (5) - The element is fully functional and is operating within normal operational parameters and without error. 
		// "Unknown" (0) - The implementation cannot report on HealthState at this time. 
		// DMTF has reserved the unused portion of the continuum for additional HealthStates in the future.
		void HealthState(const unsigned short value); 

		// Is true if the field HealthState exists in the current object, otherwise is false.
		bool HealthStateExists() const;

		// Remove HealthState field.
		void RemoveHealthState(); 

		// Optional, CommunicationStatus indicates the ability of the instrumentation to communicate with the underlying ManagedElement. CommunicationStatus consists of one of the following values: Unknown, None, Communication OK, Lost Communication, or No Contact. 
		// A Null return indicates the implementation (provider) does not implement this property. 
		// "Unknown" indicates the implementation is in general capable of returning this property, but is unable to do so at this time. 
		// "Not Available" indicates that the implementation (provider) is capable of returning a value for this property, but not ever for this particular piece of hardware/software or the property is intentionally not used because it adds no meaningful information (as in the case of a property that is intended to add additional info to another property). 
		// "Communication OK " indicates communication is established with the element, but does not convey any quality of service. 
		// "No Contact" indicates that the monitoring system has knowledge of this element, but has never been able to establish communications with it. 
		// "Lost Communication" indicates that the Managed Element is known to exist and has been contacted successfully in the past, but is currently unreachable.
		const unsigned short CommunicationStatus() const;

		// Optional, CommunicationStatus indicates the ability of the instrumentation to communicate with the underlying ManagedElement. CommunicationStatus consists of one of the following values: Unknown, None, Communication OK, Lost Communication, or No Contact. 
		// A Null return indicates the implementation (provider) does not implement this property. 
		// "Unknown" indicates the implementation is in general capable of returning this property, but is unable to do so at this time. 
		// "Not Available" indicates that the implementation (provider) is capable of returning a value for this property, but not ever for this particular piece of hardware/software or the property is intentionally not used because it adds no meaningful information (as in the case of a property that is intended to add additional info to another property). 
		// "Communication OK " indicates communication is established with the element, but does not convey any quality of service. 
		// "No Contact" indicates that the monitoring system has knowledge of this element, but has never been able to establish communications with it. 
		// "Lost Communication" indicates that the Managed Element is known to exist and has been contacted successfully in the past, but is currently unreachable.
		void CommunicationStatus(const unsigned short value); 

		// Is true if the field CommunicationStatus exists in the current object, otherwise is false.
		bool CommunicationStatusExists() const;

		// Remove CommunicationStatus field.
		void RemoveCommunicationStatus(); 

		// Optional, DetailedStatus compliments PrimaryStatus with additional status detail. It consists of one of the following values: Not Available, No Additional Information, Stressed, Predictive Failure, Error, Non-Recoverable Error, SupportingEntityInError. Detailed status is used to expand upon the PrimaryStatus of the element. 
		// A Null return indicates the implementation (provider) does not implement this property. 
		// "Not Available" indicates that the implementation (provider) is capable of returning a value for this property, but not ever for this particular piece of hardware/software or the property is intentionally not used because it adds no meaningful information (as in the case of a property that is intended to add additional info to another property). 
		// "No Additional Information" indicates that the element is functioning normally as indicated by PrimaryStatus = "OK". 
		// "Stressed" indicates that the element is functioning, but needs attention. Examples of "Stressed" states are overload, overheated, and so on. 
		// "Predictive Failure" indicates that an element is functioning normally but a failure is predicted in the near future. 
		// "Non-Recoverable Error " indicates that this element is in an error condition that requires human intervention. 
		// "Supporting Entity in Error" indicates that this element might be "OK" but that another element, on which it is dependent, is in error. An example is a network service or endpoint that cannot function due to lower-layer networking problems.
		const unsigned short DetailedStatus() const;

		// Optional, DetailedStatus compliments PrimaryStatus with additional status detail. It consists of one of the following values: Not Available, No Additional Information, Stressed, Predictive Failure, Error, Non-Recoverable Error, SupportingEntityInError. Detailed status is used to expand upon the PrimaryStatus of the element. 
		// A Null return indicates the implementation (provider) does not implement this property. 
		// "Not Available" indicates that the implementation (provider) is capable of returning a value for this property, but not ever for this particular piece of hardware/software or the property is intentionally not used because it adds no meaningful information (as in the case of a property that is intended to add additional info to another property). 
		// "No Additional Information" indicates that the element is functioning normally as indicated by PrimaryStatus = "OK". 
		// "Stressed" indicates that the element is functioning, but needs attention. Examples of "Stressed" states are overload, overheated, and so on. 
		// "Predictive Failure" indicates that an element is functioning normally but a failure is predicted in the near future. 
		// "Non-Recoverable Error " indicates that this element is in an error condition that requires human intervention. 
		// "Supporting Entity in Error" indicates that this element might be "OK" but that another element, on which it is dependent, is in error. An example is a network service or endpoint that cannot function due to lower-layer networking problems.
		void DetailedStatus(const unsigned short value); 

		// Is true if the field DetailedStatus exists in the current object, otherwise is false.
		bool DetailedStatusExists() const;

		// Remove DetailedStatus field.
		void RemoveDetailedStatus(); 

		// Optional, OperatingStatus provides a current status value for the operational condition of the element and can be used for providing more detail with respect to the value of EnabledState. It can also provide the transitional states when an element is transitioning from one state to another, such as when an element is transitioning between EnabledState and RequestedState, as well as other transitional conditions.
		// OperatingStatus consists of one of the following values: Unknown, Not Available, In Service, Starting, Stopping, Stopped, Aborted, Dormant, Completed, Migrating, Emmigrating, Immigrating, Snapshotting. Shutting Down, In Test 
		// A Null return indicates the implementation (provider) does not implement this property. 
		// "Unknown" indicates the implementation is in general capable of returning this property, but is unable to do so at this time. 
		// "None" indicates that the implementation (provider) is capable of returning a value for this property, but not ever for this particular piece of hardware/software or the property is intentionally not used because it adds no meaningful information (as in the case of a property that is intended to add additional info to another property). 
		// "Servicing" describes an element being configured, maintained, cleaned, or otherwise administered. 
		// "Starting" describes an element being initialized. 
		// "Stopping" describes an element being brought to an orderly stop. 
		// "Stopped" and "Aborted" are similar, although the former implies a clean and orderly stop, while the latter implies an abrupt stop where the state and configuration of the element might need to be updated. 
		// "Dormant" indicates that the element is inactive or quiesced. 
		// "Completed" indicates that the element has completed its operation. This value should be combined with either OK, Error, or Degraded in the PrimaryStatus so that a client can tell if the complete operation Completed with OK (passed), Completed with Error (failed), or Completed with Degraded (the operation finished, but it did not complete OK or did not report an error). 
		// "Migrating" element is being moved between host elements. 
		// "Immigrating" element is being moved to new host element. 
		// "Emigrating" element is being moved away from host element. 
		// "Shutting Down" describes an element being brought to an abrupt stop. 
		// "In Test" element is performing test functions. 
		// "Transitioning" describes an element that is between states, that is, it is not fully available in either its previous state or its next state. This value should be used if other values indicating a transition to a specific state are not applicable.
		// "In Service" describes an element that is in service and operational.
		const unsigned short OperatingStatus() const;

		// Optional, OperatingStatus provides a current status value for the operational condition of the element and can be used for providing more detail with respect to the value of EnabledState. It can also provide the transitional states when an element is transitioning from one state to another, such as when an element is transitioning between EnabledState and RequestedState, as well as other transitional conditions.
		// OperatingStatus consists of one of the following values: Unknown, Not Available, In Service, Starting, Stopping, Stopped, Aborted, Dormant, Completed, Migrating, Emmigrating, Immigrating, Snapshotting. Shutting Down, In Test 
		// A Null return indicates the implementation (provider) does not implement this property. 
		// "Unknown" indicates the implementation is in general capable of returning this property, but is unable to do so at this time. 
		// "None" indicates that the implementation (provider) is capable of returning a value for this property, but not ever for this particular piece of hardware/software or the property is intentionally not used because it adds no meaningful information (as in the case of a property that is intended to add additional info to another property). 
		// "Servicing" describes an element being configured, maintained, cleaned, or otherwise administered. 
		// "Starting" describes an element being initialized. 
		// "Stopping" describes an element being brought to an orderly stop. 
		// "Stopped" and "Aborted" are similar, although the former implies a clean and orderly stop, while the latter implies an abrupt stop where the state and configuration of the element might need to be updated. 
		// "Dormant" indicates that the element is inactive or quiesced. 
		// "Completed" indicates that the element has completed its operation. This value should be combined with either OK, Error, or Degraded in the PrimaryStatus so that a client can tell if the complete operation Completed with OK (passed), Completed with Error (failed), or Completed with Degraded (the operation finished, but it did not complete OK or did not report an error). 
		// "Migrating" element is being moved between host elements. 
		// "Immigrating" element is being moved to new host element. 
		// "Emigrating" element is being moved away from host element. 
		// "Shutting Down" describes an element being brought to an abrupt stop. 
		// "In Test" element is performing test functions. 
		// "Transitioning" describes an element that is between states, that is, it is not fully available in either its previous state or its next state. This value should be used if other values indicating a transition to a specific state are not applicable.
		// "In Service" describes an element that is in service and operational.
		void OperatingStatus(const unsigned short value); 

		// Is true if the field OperatingStatus exists in the current object, otherwise is false.
		bool OperatingStatusExists() const;

		// Remove OperatingStatus field.
		void RemoveOperatingStatus(); 

		// Optional, PrimaryStatus provides a high level status value, intended to align with Red-Yellow-Green type representation of status. It should be used in conjunction with DetailedStatus to provide high level and detailed health status of the ManagedElement and its subcomponents. 
		// PrimaryStatus consists of one of the following values: Unknown, OK, Degraded or Error. "Unknown" indicates the implementation is in general capable of returning this property, but is unable to do so at this time. 
		// "OK" indicates the ManagedElement is functioning normally. 
		// "Degraded" indicates the ManagedElement is functioning below normal. 
		// "Error" indicates the ManagedElement is in an Error condition.
		const unsigned short PrimaryStatus() const;

		// Optional, PrimaryStatus provides a high level status value, intended to align with Red-Yellow-Green type representation of status. It should be used in conjunction with DetailedStatus to provide high level and detailed health status of the ManagedElement and its subcomponents. 
		// PrimaryStatus consists of one of the following values: Unknown, OK, Degraded or Error. "Unknown" indicates the implementation is in general capable of returning this property, but is unable to do so at this time. 
		// "OK" indicates the ManagedElement is functioning normally. 
		// "Degraded" indicates the ManagedElement is functioning below normal. 
		// "Error" indicates the ManagedElement is in an Error condition.
		void PrimaryStatus(const unsigned short value); 

		// Is true if the field PrimaryStatus exists in the current object, otherwise is false.
		bool PrimaryStatusExists() const;

		// Remove PrimaryStatus field.
		void RemovePrimaryStatus(); 

		 // Function used by the factory
		static CimBase *CreateFromCimObject(const CimObject &object);

		static vector<shared_ptr<CIM_ManagedSystemElement> > Enumerate(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		// Overloaded delete which supplies the internal resourceURI
		static void Delete(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		using CimBase::Delete;

	protected:
		 // Protected constructor to be used by derived classes
		CIM_ManagedSystemElement(ICimWsmanClient *client, const string &class_name,
			const string &class_ns, const string &prefix, const string &uri): CIM_ManagedElement(client, class_name, class_ns, prefix, uri)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_ManagedElement::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 10);
			}
		}
		 // Protected constructor which receives CimObject
		CIM_ManagedSystemElement(const CimObject &object)
			: CIM_ManagedElement(object)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_ManagedElement::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 10);
			}
		}
		// Called by derived classes
		void SetMetaData(vector<CimFieldAttribute>& childMetaData)
		{
			CIM_ManagedElement::SetMetaData(childMetaData);
			CimBase::SetMetaData(childMetaData, _metadata, 10);
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
#endif // CIM_MANAGEDSYSTEMELEMENT_H
