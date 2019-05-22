//----------------------------------------------------------------------------
//
// Copyright (c) Intel Corporation, 2003 - 2009  All Rights Reserved.
//
//  File:       CimSerializer.h
//
//  Contents:   Singleton object and functions for serialization, declarations.
//
//----------------------------------------------------------------------------

#ifndef CIMSERIALIZER_H
#define CIMSERIALIZER_H 1

#include <string>
#include <algorithm>

#include "CimUtils.h"
#include "CimReference.h"
#include "CimDateTime.h"


namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Untyped 
{

	//using namespace Intel::WSManagement;;
	using Intel::Manageability::Exceptions::ConversionException;
	using Intel::Manageability::Cim::Utils::TypeConverter;
	using Intel::Manageability::Cim::Utils::VectorFieldData;
	using Intel::Manageability::Cim::Utils::FieldData;
	//using Intel::Manageability::Cim::CimReference;

	// Singleton class!
	class CIMUNTYPEDFRAMEWORK_API CimSerializer {
	public:
		// Singleton access function.
		static const CimSerializer *GetSerializer();

		// Serialize data in VectorFieldData into xml string.
		std::string Serialize(const string &objectName, const string &nameSpace,
			const string &uri, const string &prefix, const VectorFieldData &v,
			bool includeRoot = true, bool delegateNs = false) const;

		std::string SerializeFullEPR(const CimReference &reference) const;
		std::string SerializeEPR(const CimReference &reference) const;
		const CimReference DeserializeEPR(const std::string &xml) const;

		string SerializeDateTime(const CimDateTime &dateTime) const;
		const CimDateTime DeserializeDateTime(string xml) const;

		// Serialize data in VectorFieldData into xml string.
		// Here, the VectorFieldData contains the attribute value to
		// use in the tag, for example:
		// <innertag attribute="first-val">second-value</inntertag>.
		std::string SerializeAttributed(const string &rootTag,
			const string &innerTag, const string &attribute,
			const string &nameSpace,
			const string &uri, const string &prefix,
			const VectorFieldData &v, bool includeRoot = true) const;

		// Deserialize xml, return VectorFieldData and set objectName and prefix.
		// Only late binding objects should use this one since they need
		// all the information from the XML returned by the AMT firmware.
		const VectorFieldData Deserialize(const std::string &xml, string &objectName,
				string &prefix, string &resourceURI) const;

		// Deserialize xml, return VectorFieldData
		// This one is used by CimBase and descendants since they
		// know the namespace info etc.
		const VectorFieldData Deserialize(const std::string &xml) const;

		// Deserialize data, where the attribute values are the names and the
		// xml element values are the values. For example,
		// <foo Name="answer">42</foo> puts answer/name into vfd.
		const VectorFieldData DeserializeAttributed(const std::string &xml,
				const string &attribute) const;

		void DeserializeItem(const std::string &itemXml, std::string &firstXml, std::string &secondXml) const;
	private:
		// Constructor.
		CimSerializer();

		// Destructor.
		~CimSerializer();

		// Called once at program exit, see the code.
		static void CleanUpXmlLibray();

		// Helpers
		string SerializeDateTimeAbsolute(const CimDateTimeAbsolute &dateTime) const;
		CimDateTimeAbsolute DeserializeDateTimeAbsolute(const string &dateTime) const;

		string SerializeDateTimeInterval(const CimDateTimeInterval &dateTime) const;
		CimDateTimeInterval DeserializeDateTimeInterval(const string &interval) const;

		void DeserializeDateInterval(const string& dateString, unsigned long& days) const;
		void DeserializeTimeInterval(const string& timeString, unsigned short& hours, unsigned short& minutes, unsigned short& seconds, unsigned long& microseconds) const;

		template<typename T>
		void GetValueIfExists(string::const_iterator& begin, const string::const_iterator& end, char separator, T& value) const
		{
			string::const_iterator found = find(begin, end, separator);
			if (found != end)
			{
				TypeConverter::StringToType(string(begin, found), value);
				begin = found + 1;
			}
		}

		// Singleton stuff.
		static bool initialized;
	};

};
};
};
};

#endif // CIMSERIALIZER_H
