//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_RecordForLog.h
//
//  Contents:   The RecordForLog class is used to instantiate records to be aggregated to a Log.
//
//              This file was automatically generated from CIM_RecordForLog.mof,  version: 2.25.0
//
//----------------------------------------------------------------------------
#ifndef CIM_RECORDFORLOG_H
#define CIM_RECORDFORLOG_H 1
#include "CIM_ManagedElement.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	// The RecordForLog class is used to instantiate records to be aggregated to a Log.
	class CIMFRAMEWORK_API CIM_RecordForLog  : public CIM_ManagedElement
	{
	public:

		//Default constructor
		CIM_RecordForLog()
			: CIM_ManagedElement(NULL, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_ManagedElement::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 4);
			}
		}

		//constructor which receives WSMan client
		CIM_RecordForLog(ICimWsmanClient *client)
			: CIM_ManagedElement(client, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_ManagedElement::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 4);
			}
		}

		//Destructor
		virtual ~CIM_RecordForLog(){}

		// The "type" information for the object. Gettors only.
		virtual const string& ResourceURI() const { return CLASS_URI; }
		static const string& ClassResourceURI() { return CLASS_URI; }
		virtual const string& XmlNamespace() const { return CLASS_NS; }
		virtual const string& XmlPrefix() const { return CLASS_NS_PREFIX; }
		virtual const string& ObjectType() const { return CLASS_NAME; }
		static const string& ClassObjectType() { return CLASS_NAME; }

		// Class representing CIM_RecordForLog keys
		class CimKeys : public CIM_ManagedElement::CimKeys
		{
		public:
		};

		// class fields declarations

		// Optional, A string describing the data structure of the information in the property, RecordData. If the RecordFormat string is <empty>, RecordData should be interpreted as a free-form string. 
		// 
		// To describe the data structure of RecordData, the RecordFormat string should be constructed as follows: 
		// - The first character is a delimiter character and is used to parse the remainder of the string into sub-strings. 
		// - Each sub-string is separated by the delimiter character and should be in the form of a CIM property declaration (i.e., datatype and property name). This set of declarations may be used to interpret the similarly delimited RecordData property. 
		// For example, using a '*' delimiter, RecordFormat = "*string ThisDay*uint32 ThisYear*datetime SomeTime" 
		// may be used to interpret: RecordData = "*This is Friday*2002*20020807141000.000000-300".
		const string RecordFormat() const;

		// Optional, A string describing the data structure of the information in the property, RecordData. If the RecordFormat string is <empty>, RecordData should be interpreted as a free-form string. 
		// 
		// To describe the data structure of RecordData, the RecordFormat string should be constructed as follows: 
		// - The first character is a delimiter character and is used to parse the remainder of the string into sub-strings. 
		// - Each sub-string is separated by the delimiter character and should be in the form of a CIM property declaration (i.e., datatype and property name). This set of declarations may be used to interpret the similarly delimited RecordData property. 
		// For example, using a '*' delimiter, RecordFormat = "*string ThisDay*uint32 ThisYear*datetime SomeTime" 
		// may be used to interpret: RecordData = "*This is Friday*2002*20020807141000.000000-300".
		void RecordFormat(const string &value); 

		// Is true if the field RecordFormat exists in the current object, otherwise is false.
		bool RecordFormatExists() const;

		// Remove RecordFormat field.
		void RemoveRecordFormat(); 

		// Optional, A string containing LogRecord data. 
		// If the corresponding RecordFormat property is <empty>, or cannot be parsed according to the recommended format, RecordData should be interpreted as a free-form string. If the RecordFormat property contains parseable format information (as recommended in the RecordFormat Description qualifier), the RecordData string SHOULD be parsed in accordance with this format. In this case, RecordData SHOULD begin with the delimiter character and this character SHOULD be used to separate substrings in the manner described. The RecordData string can then be parsed by the data consumer and appropriately typed.
		const string RecordData() const;

		// Optional, A string containing LogRecord data. 
		// If the corresponding RecordFormat property is <empty>, or cannot be parsed according to the recommended format, RecordData should be interpreted as a free-form string. If the RecordFormat property contains parseable format information (as recommended in the RecordFormat Description qualifier), the RecordData string SHOULD be parsed in accordance with this format. In this case, RecordData SHOULD begin with the delimiter character and this character SHOULD be used to separate substrings in the manner described. The RecordData string can then be parsed by the data consumer and appropriately typed.
		void RecordData(const string &value); 

		// Is true if the field RecordData exists in the current object, otherwise is false.
		bool RecordDataExists() const;

		// Remove RecordData field.
		void RemoveRecordData(); 

		// Optional, A locale indicates a particular geographical, political, or cultural region. The Locale specifies the language used in creating the RecordForLog data. If the Locale property is empty, it is assumed that the default locale is en_US (English). 
		// The locale string consists of three sub-strings, separated by underscores: 
		// - The first sub-string is the language code, as specified in ISO639. 
		// - The second sub-string is the country code, as specified in ISO3166. 
		// - The third sub-string is a variant, which is vendor specific. 
		// For example, US English appears as: "en_US_WIN", where the "WIN" variant would specify a Windows browser-specific collation (if one exists). Since the variant is not standardized, it is not commonly used and generally is limited to easily recognizable values ("WIN", "UNIX", "EURO", etc.) used in standard environments. The language and country codes are required; the variant may be empty.
		const string Locale() const;

		// Optional, A locale indicates a particular geographical, political, or cultural region. The Locale specifies the language used in creating the RecordForLog data. If the Locale property is empty, it is assumed that the default locale is en_US (English). 
		// The locale string consists of three sub-strings, separated by underscores: 
		// - The first sub-string is the language code, as specified in ISO639. 
		// - The second sub-string is the country code, as specified in ISO3166. 
		// - The third sub-string is a variant, which is vendor specific. 
		// For example, US English appears as: "en_US_WIN", where the "WIN" variant would specify a Windows browser-specific collation (if one exists). Since the variant is not standardized, it is not commonly used and generally is limited to easily recognizable values ("WIN", "UNIX", "EURO", etc.) used in standard environments. The language and country codes are required; the variant may be empty.
		void Locale(const string &value); 

		// Is true if the field Locale exists in the current object, otherwise is false.
		bool LocaleExists() const;

		// Remove Locale field.
		void RemoveLocale(); 

		// Optional, An enumerated value that describes the severity of the Indication from the notifier's point of view: 
		// 1 - Other, by CIM convention, is used to indicate that the Severity's value can be found in the OtherSeverity property. 
		// 3 - Degraded/Warning should be used when its appropriate to let the user decide if action is needed. 
		// 4 - Minor should be used to indicate action is needed, but the situation is not serious at this time. 
		// 5 - Major should be used to indicate action is needed NOW. 
		// 6 - Critical should be used to indicate action is needed NOW and the scope is broad (perhaps an imminent outage to a critical resource will result). 
		// 7 - Fatal/NonRecoverable should be used to indicate an error occurred, but it's too late to take remedial action. 
		// 2 and 0 - Information and Unknown (respectively) follow common usage. Literally, the Indication is purely informational or its severity is simply unknown.
		const unsigned short PerceivedSeverity() const;

		// Optional, An enumerated value that describes the severity of the Indication from the notifier's point of view: 
		// 1 - Other, by CIM convention, is used to indicate that the Severity's value can be found in the OtherSeverity property. 
		// 3 - Degraded/Warning should be used when its appropriate to let the user decide if action is needed. 
		// 4 - Minor should be used to indicate action is needed, but the situation is not serious at this time. 
		// 5 - Major should be used to indicate action is needed NOW. 
		// 6 - Critical should be used to indicate action is needed NOW and the scope is broad (perhaps an imminent outage to a critical resource will result). 
		// 7 - Fatal/NonRecoverable should be used to indicate an error occurred, but it's too late to take remedial action. 
		// 2 and 0 - Information and Unknown (respectively) follow common usage. Literally, the Indication is purely informational or its severity is simply unknown.
		void PerceivedSeverity(const unsigned short value); 

		// Is true if the field PerceivedSeverity exists in the current object, otherwise is false.
		bool PerceivedSeverityExists() const;

		// Remove PerceivedSeverity field.
		void RemovePerceivedSeverity(); 

		 // Function used by the factory
		static CimBase *CreateFromCimObject(const CimObject &object);

		static vector<shared_ptr<CIM_RecordForLog> > Enumerate(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		// Overloaded delete which supplies the internal resourceURI
		static void Delete(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		using CimBase::Delete;

	protected:
		 // Protected constructor to be used by derived classes
		CIM_RecordForLog(ICimWsmanClient *client, const string &class_name,
			const string &class_ns, const string &prefix, const string &uri): CIM_ManagedElement(client, class_name, class_ns, prefix, uri)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_ManagedElement::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 4);
			}
		}
		 // Protected constructor which receives CimObject
		CIM_RecordForLog(const CimObject &object)
			: CIM_ManagedElement(object)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_ManagedElement::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 4);
			}
		}
		// Called by derived classes
		void SetMetaData(vector<CimFieldAttribute>& childMetaData)
		{
			CIM_ManagedElement::SetMetaData(childMetaData);
			CimBase::SetMetaData(childMetaData, _metadata, 4);
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
#endif // CIM_RECORDFORLOG_H
