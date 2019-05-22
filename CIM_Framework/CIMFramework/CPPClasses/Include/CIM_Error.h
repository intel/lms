//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_Error.h
//
//  Contents:   CIM_Error is a specialized class that contains information about the severity, cause, recommended actions and other data related to the failure of a CIM Operation. Instances of this type MAY be included as part of the response to a CIM Operation.
//
//              This file was automatically generated from CIM_Error.mof,  version: 2.22.1
//
//----------------------------------------------------------------------------
#ifndef CIM_ERROR_H
#define CIM_ERROR_H 1
#include "../../include/CimBase.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	// CIM_Error is a specialized class that contains information about the severity, cause, recommended actions and other data related to the failure of a CIM Operation. Instances of this type MAY be included as part of the response to a CIM Operation.
	class CIMFRAMEWORK_API CIM_Error  : public CimBase
	{
	public:

		//Default constructor
		CIM_Error()
			: CimBase(NULL, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CimBase::SetMetaData(_classMetaData, _metadata, 15);
			}
		}

		//constructor which receives WSMan client
		CIM_Error(ICimWsmanClient *client)
			: CimBase(client, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CimBase::SetMetaData(_classMetaData, _metadata, 15);
			}
		}

		//Destructor
		virtual ~CIM_Error(){}

		// The "type" information for the object. Gettors only.
		virtual const string& ResourceURI() const { return CLASS_URI; }
		static const string& ClassResourceURI() { return CLASS_URI; }
		virtual const string& XmlNamespace() const { return CLASS_NS; }
		virtual const string& XmlPrefix() const { return CLASS_NS_PREFIX; }
		virtual const string& ObjectType() const { return CLASS_NAME; }
		static const string& ClassObjectType() { return CLASS_NAME; }

		// Class representing CIM_Error keys
		class CimKeys : public CimBase::CimKeys
		{
		public:
		};

		// class fields declarations

		// Optional, Primary classification of the error. The following values are defined: 
		// 2 - Communications Error. Errors of this type are principally associated with the procedures and/or processes required to convey information from one point to another. 
		// 3 - Quality of Service Error. Errors of this type are principally associated with failures that result in reduced functionality or performance. 
		// 4 - Software Error. Error of this type are principally associated with a software or processing fault. 
		// 5 - Hardware Error. Errors of this type are principally associated with an equipment or hardware failure. 
		// 6 - Environmental Error. Errors of this type are principally associated with a failure condition relating the to facility, or other environmental considerations. 
		// 7 - Security Error. Errors of this type are associated with security violations, detection of viruses, and similar issues. 
		// 8 - Oversubscription Error. Errors of this type are principally associated with the failure to allocate sufficient resources to complete the operation. 
		// 9 - Unavailable Resource Error. Errors of this type are principally associated with the failure to access a required resource. 
		// 10 -Unsupported Operation Error. Errors of this type are principally associated with requests that are not supported.
		const unsigned short ErrorType() const;

		// Optional, Primary classification of the error. The following values are defined: 
		// 2 - Communications Error. Errors of this type are principally associated with the procedures and/or processes required to convey information from one point to another. 
		// 3 - Quality of Service Error. Errors of this type are principally associated with failures that result in reduced functionality or performance. 
		// 4 - Software Error. Error of this type are principally associated with a software or processing fault. 
		// 5 - Hardware Error. Errors of this type are principally associated with an equipment or hardware failure. 
		// 6 - Environmental Error. Errors of this type are principally associated with a failure condition relating the to facility, or other environmental considerations. 
		// 7 - Security Error. Errors of this type are associated with security violations, detection of viruses, and similar issues. 
		// 8 - Oversubscription Error. Errors of this type are principally associated with the failure to allocate sufficient resources to complete the operation. 
		// 9 - Unavailable Resource Error. Errors of this type are principally associated with the failure to access a required resource. 
		// 10 -Unsupported Operation Error. Errors of this type are principally associated with requests that are not supported.
		void ErrorType(const unsigned short value); 

		// Is true if the field ErrorType exists in the current object, otherwise is false.
		bool ErrorTypeExists() const;

		// Remove ErrorType field.
		void RemoveErrorType(); 

		// Optional, A free-form string describing the ErrorType when 1, "Other", is specified as the ErrorType.
		const string OtherErrorType() const;

		// Optional, A free-form string describing the ErrorType when 1, "Other", is specified as the ErrorType.
		void OtherErrorType(const string &value); 

		// Is true if the field OtherErrorType exists in the current object, otherwise is false.
		bool OtherErrorTypeExists() const;

		// Remove OtherErrorType field.
		void RemoveOtherErrorType(); 

		// Optional, A string that uniquely identifies the entity that owns the definition of the format of the Message described in this instance. OwningEntity MUST include a copyrighted, trademarked or otherwise unique name that is owned by the business entity or standards body defining the format.
		const string OwningEntity() const;

		// Optional, A string that uniquely identifies the entity that owns the definition of the format of the Message described in this instance. OwningEntity MUST include a copyrighted, trademarked or otherwise unique name that is owned by the business entity or standards body defining the format.
		void OwningEntity(const string &value); 

		// Is true if the field OwningEntity exists in the current object, otherwise is false.
		bool OwningEntityExists() const;

		// Remove OwningEntity field.
		void RemoveOwningEntity(); 

		// Required, An opaque string that uniquely identifies, within the scope of the OwningEntity, the format of the Message.
		const string MessageID() const;

		// Required, An opaque string that uniquely identifies, within the scope of the OwningEntity, the format of the Message.
		void MessageID(const string &value); 

		// Is true if the field MessageID exists in the current object, otherwise is false.
		bool MessageIDExists() const;

		// Remove MessageID field.
		void RemoveMessageID(); 

		// Optional, The formatted message. This message is constructed by combining some or all of the dynamic elements specified in the MessageArguments property with the static elements uniquely identified by the MessageID in a message registry or other catalog associated with the OwningEntity.
		const string Message() const;

		// Optional, The formatted message. This message is constructed by combining some or all of the dynamic elements specified in the MessageArguments property with the static elements uniquely identified by the MessageID in a message registry or other catalog associated with the OwningEntity.
		void Message(const string &value); 

		// Is true if the field Message exists in the current object, otherwise is false.
		bool MessageExists() const;

		// Remove Message field.
		void RemoveMessage(); 

		// Optional, An array containing the dynamic content of the message.
		const vector<string> MessageArguments() const;

		// Optional, An array containing the dynamic content of the message.
		void MessageArguments(const vector<string> &value); 

		// Is true if the field MessageArguments exists in the current object, otherwise is false.
		bool MessageArgumentsExists() const;

		// Remove MessageArguments field.
		void RemoveMessageArguments(); 

		// Optional, An enumerated value that describes the severity of the Indication from the notifier's point of view: 
		// 0 - the Perceived Severity of the indication is unknown or indeterminate. 
		// 1 - Other, by CIM convention, is used to indicate that the Severity's value can be found in the OtherSeverity property. 
		// 2 - Information should be used when providing an informative response. 
		// 3 - Degraded/Warning should be used when its appropriate to let the user decide if action is needed. 
		// 4 - Minor should be used to indicate action is needed, but the situation is not serious at this time. 
		// 5 - Major should be used to indicate action is needed NOW. 
		// 6 - Critical should be used to indicate action is needed NOW and the scope is broad (perhaps an imminent outage to a critical resource will result). 
		// 7 - Fatal/NonRecoverable should be used to indicate an error occurred, but it's too late to take remedial action. 
		// 2 and 0 - Information and Unknown (respectively) follow common usage. Literally, the Error is purely informational or its severity is simply unknown.
		const unsigned short PerceivedSeverity() const;

		// Optional, An enumerated value that describes the severity of the Indication from the notifier's point of view: 
		// 0 - the Perceived Severity of the indication is unknown or indeterminate. 
		// 1 - Other, by CIM convention, is used to indicate that the Severity's value can be found in the OtherSeverity property. 
		// 2 - Information should be used when providing an informative response. 
		// 3 - Degraded/Warning should be used when its appropriate to let the user decide if action is needed. 
		// 4 - Minor should be used to indicate action is needed, but the situation is not serious at this time. 
		// 5 - Major should be used to indicate action is needed NOW. 
		// 6 - Critical should be used to indicate action is needed NOW and the scope is broad (perhaps an imminent outage to a critical resource will result). 
		// 7 - Fatal/NonRecoverable should be used to indicate an error occurred, but it's too late to take remedial action. 
		// 2 and 0 - Information and Unknown (respectively) follow common usage. Literally, the Error is purely informational or its severity is simply unknown.
		void PerceivedSeverity(const unsigned short value); 

		// Is true if the field PerceivedSeverity exists in the current object, otherwise is false.
		bool PerceivedSeverityExists() const;

		// Remove PerceivedSeverity field.
		void RemovePerceivedSeverity(); 

		// Optional, An enumerated value that describes the probable cause of the error.
		const unsigned short ProbableCause() const;

		// Optional, An enumerated value that describes the probable cause of the error.
		void ProbableCause(const unsigned short value); 

		// Is true if the field ProbableCause exists in the current object, otherwise is false.
		bool ProbableCauseExists() const;

		// Remove ProbableCause field.
		void RemoveProbableCause(); 

		// Optional, A free-form string describing the probable cause of the error.
		const string ProbableCauseDescription() const;

		// Optional, A free-form string describing the probable cause of the error.
		void ProbableCauseDescription(const string &value); 

		// Is true if the field ProbableCauseDescription exists in the current object, otherwise is false.
		bool ProbableCauseDescriptionExists() const;

		// Remove ProbableCauseDescription field.
		void RemoveProbableCauseDescription(); 

		// Optional, A free-form string describing recommended actions to take to resolve the error.
		const vector<string> RecommendedActions() const;

		// Optional, A free-form string describing recommended actions to take to resolve the error.
		void RecommendedActions(const vector<string> &value); 

		// Is true if the field RecommendedActions exists in the current object, otherwise is false.
		bool RecommendedActionsExists() const;

		// Remove RecommendedActions field.
		void RemoveRecommendedActions(); 

		// Optional, The identifying information of the entity (i.e., the instance) generating the error. If this entity is modeled in the CIM Schema, this property contains the path of the instance encoded as a string parameter. If not modeled, the property contains some identifying string that names the entity that generated the error. The path or identifying string is formatted per the ErrorSourceFormat property.
		const string ErrorSource() const;

		// Optional, The identifying information of the entity (i.e., the instance) generating the error. If this entity is modeled in the CIM Schema, this property contains the path of the instance encoded as a string parameter. If not modeled, the property contains some identifying string that names the entity that generated the error. The path or identifying string is formatted per the ErrorSourceFormat property.
		void ErrorSource(const string &value); 

		// Is true if the field ErrorSource exists in the current object, otherwise is false.
		bool ErrorSourceExists() const;

		// Remove ErrorSource field.
		void RemoveErrorSource(); 

		// Optional, The format of the ErrorSource property is interpretable based on the value of this property. Values are defined as: 
		// 0 - Unknown. The format is unknown or not meaningfully interpretable by a CIM client application. 
		// 1 - Other. The format is defined by the value of the OtherErrorSourceFormat property.2 - CIMObjectPath. A CIM Object Path as defined in the CIM Infrastructure specification. Note: CIM 2.5 and earlier used the term object names.
		const unsigned short ErrorSourceFormat() const;

		// Optional, The format of the ErrorSource property is interpretable based on the value of this property. Values are defined as: 
		// 0 - Unknown. The format is unknown or not meaningfully interpretable by a CIM client application. 
		// 1 - Other. The format is defined by the value of the OtherErrorSourceFormat property.2 - CIMObjectPath. A CIM Object Path as defined in the CIM Infrastructure specification. Note: CIM 2.5 and earlier used the term object names.
		void ErrorSourceFormat(const unsigned short value); 

		// Is true if the field ErrorSourceFormat exists in the current object, otherwise is false.
		bool ErrorSourceFormatExists() const;

		// Remove ErrorSourceFormat field.
		void RemoveErrorSourceFormat(); 

		// Optional, A string defining "Other" values for ErrorSourceFormat. This value MUST be set to a non NULL value when ErrorSourceFormat is set to a value of 1 ("Other"). For all other values of ErrorSourceFormat, the value of this string must be set to NULL.
		const string OtherErrorSourceFormat() const;

		// Optional, A string defining "Other" values for ErrorSourceFormat. This value MUST be set to a non NULL value when ErrorSourceFormat is set to a value of 1 ("Other"). For all other values of ErrorSourceFormat, the value of this string must be set to NULL.
		void OtherErrorSourceFormat(const string &value); 

		// Is true if the field OtherErrorSourceFormat exists in the current object, otherwise is false.
		bool OtherErrorSourceFormatExists() const;

		// Remove OtherErrorSourceFormat field.
		void RemoveOtherErrorSourceFormat(); 

		// Optional, The CIM status code that characterizes this instance. 
		// This property defines the status codes that MAY be return by a conforming CIM Server or Listener. Note that not all status codes are valid for each operation. The specification for each operation SHOULD define the status codes that may be returned by that operation. 
		// The following values for CIM status code are defined: 
		// 1 - CIM_ERR_FAILED. A general error occurred that is not covered by a more specific error code. 
		// 2 - CIM_ERR_ACCESS_DENIED. Access to a CIM resource was not available to the client. 
		// 3 - CIM_ERR_INVALID_NAMESPACE. The target namespace does not exist. 
		// 4 - CIM_ERR_INVALID_PARAMETER. One or more parameter values passed to the method were invalid. 
		// 5 - CIM_ERR_INVALID_CLASS. The specified Class does not exist. 
		// 6 - CIM_ERR_NOT_FOUND. The requested object could not be found. 
		// 7 - CIM_ERR_NOT_SUPPORTED. The requested operation is not supported. 
		// 8 - CIM_ERR_CLASS_HAS_CHILDREN. Operation cannot be carried out on this class since it has instances. 
		// 9 - CIM_ERR_CLASS_HAS_INSTANCES. Operation cannot be carried out on this class since it has instances. 
		// 10 - CIM_ERR_INVALID_SUPERCLASS. Operation cannot be carried out since the specified superclass does not exist. 
		// 11 - CIM_ERR_ALREADY_EXISTS. Operation cannot be carried out because an object already exists. 
		// 12 - CIM_ERR_NO_SUCH_PROPERTY. The specified Property does not exist. 
		// 13 - CIM_ERR_TYPE_MISMATCH. The value supplied is incompatible with the type. 
		// 14 - CIM_ERR_QUERY_LANGUAGE_NOT_SUPPORTED. The query language is not recognized or supported. 
		// 15 - CIM_ERR_INVALID_QUERY. The query is not valid for the specified query language. 
		// 16 - CIM_ERR_METHOD_NOT_AVAILABLE. The extrinsic Method could not be executed. 
		// 17 - CIM_ERR_METHOD_NOT_FOUND. The specified extrinsic Method does not exist. 
		// 18 - CIM_ERR_UNEXPECTED_RESPONSE. The returned response to the asynchronous operation was not expected. 
		// 19 - CIM_ERR_INVALID_RESPONSE_DESTINATION. The specified destination for the asynchronous response is not valid. 
		// 20 - CIM_ERR_NAMESPACE_NOT_EMPTY. The specified Namespace is not empty.
		// 21 - CIM_ERR_INVALID_ENUMERATION_CONTEXT. The enumeration context supplied is not valid.
		// 22 - CIM_ERR_INVALID_OPERATION_TIMEOUT. The specified Namespace is not empty.
		// 23 - CIM_ERR_PULL_HAS_BEEN_ABANDONED. The specified Namespace is not empty.
		// 24 - CIM_ERR_PULL_CANNOT_BE_ABANDONED. The attempt to abandon a pull operation has failed.
		// 25 - CIM_ERR_FILTERED_ENUMERATION_NOT_SUPPORTED. Filtered Enumeratrions are not supported.
		// 26 - CIM_ERR_CONTINUATION_ON_ERROR_NOT_SUPPORTED. Continue on error is not supported.
		// 27 - CIM_ERR_SERVER_LIMITS_EXCEEDED. The WBEM Server limits have been exceeded (e.g. memory, connections, ...).
		// 28 - CIM_ERR_SERVER_IS_SHUTTING_DOWN. The WBEM Server is shutting down.
		// 29 - CIM_ERR_QUERY_FEATURE_NOT_SUPPORTED. The specified Query Feature is not supported.
		const unsigned int CIMStatusCode() const;

		// Optional, The CIM status code that characterizes this instance. 
		// This property defines the status codes that MAY be return by a conforming CIM Server or Listener. Note that not all status codes are valid for each operation. The specification for each operation SHOULD define the status codes that may be returned by that operation. 
		// The following values for CIM status code are defined: 
		// 1 - CIM_ERR_FAILED. A general error occurred that is not covered by a more specific error code. 
		// 2 - CIM_ERR_ACCESS_DENIED. Access to a CIM resource was not available to the client. 
		// 3 - CIM_ERR_INVALID_NAMESPACE. The target namespace does not exist. 
		// 4 - CIM_ERR_INVALID_PARAMETER. One or more parameter values passed to the method were invalid. 
		// 5 - CIM_ERR_INVALID_CLASS. The specified Class does not exist. 
		// 6 - CIM_ERR_NOT_FOUND. The requested object could not be found. 
		// 7 - CIM_ERR_NOT_SUPPORTED. The requested operation is not supported. 
		// 8 - CIM_ERR_CLASS_HAS_CHILDREN. Operation cannot be carried out on this class since it has instances. 
		// 9 - CIM_ERR_CLASS_HAS_INSTANCES. Operation cannot be carried out on this class since it has instances. 
		// 10 - CIM_ERR_INVALID_SUPERCLASS. Operation cannot be carried out since the specified superclass does not exist. 
		// 11 - CIM_ERR_ALREADY_EXISTS. Operation cannot be carried out because an object already exists. 
		// 12 - CIM_ERR_NO_SUCH_PROPERTY. The specified Property does not exist. 
		// 13 - CIM_ERR_TYPE_MISMATCH. The value supplied is incompatible with the type. 
		// 14 - CIM_ERR_QUERY_LANGUAGE_NOT_SUPPORTED. The query language is not recognized or supported. 
		// 15 - CIM_ERR_INVALID_QUERY. The query is not valid for the specified query language. 
		// 16 - CIM_ERR_METHOD_NOT_AVAILABLE. The extrinsic Method could not be executed. 
		// 17 - CIM_ERR_METHOD_NOT_FOUND. The specified extrinsic Method does not exist. 
		// 18 - CIM_ERR_UNEXPECTED_RESPONSE. The returned response to the asynchronous operation was not expected. 
		// 19 - CIM_ERR_INVALID_RESPONSE_DESTINATION. The specified destination for the asynchronous response is not valid. 
		// 20 - CIM_ERR_NAMESPACE_NOT_EMPTY. The specified Namespace is not empty.
		// 21 - CIM_ERR_INVALID_ENUMERATION_CONTEXT. The enumeration context supplied is not valid.
		// 22 - CIM_ERR_INVALID_OPERATION_TIMEOUT. The specified Namespace is not empty.
		// 23 - CIM_ERR_PULL_HAS_BEEN_ABANDONED. The specified Namespace is not empty.
		// 24 - CIM_ERR_PULL_CANNOT_BE_ABANDONED. The attempt to abandon a pull operation has failed.
		// 25 - CIM_ERR_FILTERED_ENUMERATION_NOT_SUPPORTED. Filtered Enumeratrions are not supported.
		// 26 - CIM_ERR_CONTINUATION_ON_ERROR_NOT_SUPPORTED. Continue on error is not supported.
		// 27 - CIM_ERR_SERVER_LIMITS_EXCEEDED. The WBEM Server limits have been exceeded (e.g. memory, connections, ...).
		// 28 - CIM_ERR_SERVER_IS_SHUTTING_DOWN. The WBEM Server is shutting down.
		// 29 - CIM_ERR_QUERY_FEATURE_NOT_SUPPORTED. The specified Query Feature is not supported.
		void CIMStatusCode(const unsigned int value); 

		// Is true if the field CIMStatusCode exists in the current object, otherwise is false.
		bool CIMStatusCodeExists() const;

		// Remove CIMStatusCode field.
		void RemoveCIMStatusCode(); 

		// Optional, A free-form string containing a human-readable description of CIMStatusCode. This description MAY extend, but MUST be consistent with, the definition of CIMStatusCode.
		const string CIMStatusCodeDescription() const;

		// Optional, A free-form string containing a human-readable description of CIMStatusCode. This description MAY extend, but MUST be consistent with, the definition of CIMStatusCode.
		void CIMStatusCodeDescription(const string &value); 

		// Is true if the field CIMStatusCodeDescription exists in the current object, otherwise is false.
		bool CIMStatusCodeDescriptionExists() const;

		// Remove CIMStatusCodeDescription field.
		void RemoveCIMStatusCodeDescription(); 

		 // Function used by the factory
		static CimBase *CreateFromCimObject(const CimObject &object);

		static vector<shared_ptr<CIM_Error> > Enumerate(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		// Overloaded delete which supplies the internal resourceURI
		static void Delete(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		using CimBase::Delete;

	protected:
		 // Protected constructor to be used by derived classes
		CIM_Error(ICimWsmanClient *client, const string &class_name,
			const string &class_ns, const string &prefix, const string &uri): CimBase(client, class_name, class_ns, prefix, uri)
		{
			if(_classMetaData.size() == 0)
			{
				CimBase::SetMetaData(_classMetaData, _metadata, 15);
			}
		}
		 // Protected constructor which receives CimObject
		CIM_Error(const CimObject &object)
			: CimBase(object)
		{
			if(_classMetaData.size() == 0)
			{
				CimBase::SetMetaData(_classMetaData, _metadata, 15);
			}
		}
		// Called by derived classes
		void SetMetaData(vector<CimFieldAttribute>& childMetaData)
		{
			CimBase::SetMetaData(childMetaData, _metadata, 15);
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
#endif // CIM_ERROR_H
