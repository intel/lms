//----------------------------------------------------------------------------
//
// Copyright (c) Intel Corporation, 2003 - 2018  All Rights Reserved.
//
//  File:       CimSerializer.cpp
//
//  Contents:   Singleton object and functions for serialization, implementation.
//
//----------------------------------------------------------------------------

#include <sstream>
#include <iomanip>
#include <locale>
#include <cctype>
#include "CimSerializer.h"
#include "XMLUtils.h"

namespace Intel 
{
namespace Manageability 
{
namespace Cim 
{
namespace Untyped 
{
	using namespace Intel::Manageability::XMLUtils;

	bool CimSerializer::initialized = false;

	void CimSerializer::CleanUpXmlLibray()
	{
		// Terminate XML library.
		TerminateXMLLibrary();
	}

	CimSerializer::CimSerializer()
	{
		// Init XML library.
		// Only do it once, on the off chance that someone does something strange like:
		// 	delete CimSerializer::GetSerializer();
		if (! initialized)
		{
			if (Intel::Manageability::XMLUtils::IsXMLLibraryInit() == false)
				InitXMLLibrary();
			atexit(CleanUpXmlLibray);
			initialized = true;
		}
	}

	CimSerializer::~CimSerializer()
	{
	}

	const CimSerializer *CimSerializer::GetSerializer()
	{
		static CimSerializer theSerializer;
		return &theSerializer;		
	}

	// Return string which represent EPR without the outer tag
	std::string CimSerializer::SerializeEPR(const CimReference &reference) const
	{
		string ret = "";
		ret += "<Address xmlns=\"http://schemas.xmlsoap.org/ws/2004/08/addressing\">"+reference.Address()+"</Address>";
		ret += "<ReferenceParameters xmlns=\"http://schemas.xmlsoap.org/ws/2004/08/addressing\">";
		ret += "<ResourceURI xmlns=\"http://schemas.dmtf.org/wbem/wsman/1/wsman.xsd\">"+reference.ResourceURI()+"</ResourceURI>";
		ret += "<SelectorSet xmlns=\"http://schemas.dmtf.org/wbem/wsman/1/wsman.xsd\">";
		WsManSelectors sel = reference.Selectors();
		WsManSelectors::const_iterator iter;
		for (iter = sel.begin(); iter != sel.end(); iter++)
		{
			string name = iter->first;
			string value = (iter->second);
			ret +="<Selector Name=\""+name+"\" xmlns=\"http://schemas.dmtf.org/wbem/wsman/1/wsman.xsd\">"+value+"</Selector>";
		}
		ret += "</SelectorSet>";
		ret += "</ReferenceParameters>";
		return ret;
	}

	// Return string which represent EPR with the outer tag
	std::string CimSerializer::SerializeFullEPR(const CimReference &reference) const
	{
		
		string ret = "<EndpointReference xmlns=\"http://schemas.xmlsoap.org/ws/2004/08/addressing\">" + SerializeEPR(reference) + "</EndpointReference>";
		return ret;
	}

	const CimReference CimSerializer::DeserializeEPR(const std::string &xml) const
	{
		CimReference ret;
		
		XMLDoc d(xml, NULL);
		XMLElement node = d.GetRootNode();
		ret.Prefix(node.GetNSPrefix());
		ret.Name(node.GetNodeName());
		ret.ResourceURI(node.GetNSUri());

		if (node.HasChildren())
		{
			XMLElement tmp = node.GetFirstChild();

			for (;;)
			{
				string name = tmp.GetNodeName();

				string value;

				if (name.compare("Address") == 0)
				{
					ret.Address(tmp.GetTextValue());
				}
				else if (name.compare("ReferenceParameters") == 0)
				{
					XMLElement tmp1 = tmp.GetFirstChild();
					name = tmp1.GetNodeName();
					ret.ResourceURI(tmp1.GetTextValue());
					tmp1 = tmp1.GetNextSibling();


					if (tmp1.HasChildren())
					{
						XMLElement selector = tmp1.GetFirstChild();
						WsManSelectors sel;
						for(;;)
						{
							map<string, string> attribs;
							selector.GetAttributes(attribs);
							pair<string, string> current;
							current.first = attribs["Name"];
							current.second = selector.GetTextValue();
							sel.insert(current);
							

							if (selector.HasNextSibling())
							{
								selector = selector.GetNextSibling();
							}
							else
							{
								ret.Selectors(sel);
								break;
							}
						}
					}
					



				}
				if (tmp.HasNextSibling())
				{
					tmp = tmp.GetNextSibling();
				}
				else
					break;
			}
		}
		return ret;
	}

	string CimSerializer::SerializeDateTime(const CimDateTime &dateTime) const
	{
		ostringstream ret;
		switch (dateTime.Type()) {
		case CimDateTime::DT_ABSOLUTE:
			ret << "<Datetime xmlns=\"http://schemas.dmtf.org/wbem/wscim/1/common\">"
				<< SerializeDateTimeAbsolute(dateTime.AsAbsolute())
				<< "</Datetime>";
			break;
		case CimDateTime::DT_INTERVAL:
			ret << "<Interval xmlns=\"http://schemas.dmtf.org/wbem/wscim/1/common\">"
				<< SerializeDateTimeInterval(dateTime.AsInterval())
				<< "</Interval>";
			break;
		default:
			throw ConversionException("dateTime is of an unknown type");
		}
		return ret.str();
	}

	static int mytoupper(int c)
	{
		return toupper(c);
	}

	const CimDateTime CimSerializer::DeserializeDateTime(string xml) const
	{
		// THIS CODE IS CURRENTLY UNSAFE!
		transform(xml.begin(), xml.end(), xml.begin(), mytoupper);

		string innerValue(xml.begin() + xml.find('>') + 1, xml.begin() + xml.rfind('<'));
		string whitespace = " \t\r\n";
		innerValue.erase(0, innerValue.find_first_not_of(whitespace));
		innerValue.erase(innerValue.find_last_not_of(whitespace) + 1);

		if (xml.find("INTERVAL") != string::npos)
		{
			return CimDateTime(DeserializeDateTimeInterval(innerValue));
		}
		else if (xml.find("DATETIME") != string::npos)
		{
			return CimDateTime(DeserializeDateTimeAbsolute(innerValue));
		}
		throw ConversionException("Unknown datetime type");
	}

	string CimSerializer::SerializeDateTimeAbsolute(const CimDateTimeAbsolute &dateTime) const
	{
		ostringstream ret;
		ret.fill('0');

		ret << setw(4) << (dateTime.Year() > 0 ? dateTime.Year() : 1) << '-'
			<< setw(2) << (dateTime.Month() > 0 ? dateTime.Month() : 1) << '-'
			<< setw(2) << (dateTime.Day() > 0 ? dateTime.Day() : 1)
			<< 'T'
			<< setw(2) << (dateTime.Hour() >= 0 ? dateTime.Hour() : 0) << ':'
			<< setw(2) << (dateTime.Minute() >= 0 ? dateTime.Minute() : 0) << ':'
			<< setw(2) << (dateTime.Second() >= 0 ? dateTime.Second() : 0)
			<< 'Z';
		return ret.str();
	}

	CimDateTimeAbsolute CimSerializer::DeserializeDateTimeAbsolute(const string &str) const
	{
		istringstream input(str);
		char buffer[5];
		unsigned short year, month, day, hour, minute, second;

		input.getline(buffer, 5, '-');
		TypeConverter::StringToType(buffer, year);
		input.getline(buffer, 3, '-');
		TypeConverter::StringToType(buffer, month);
		input.getline(buffer, 3, 'T');
		TypeConverter::StringToType(buffer, day);
		input.getline(buffer, 3, ':');
		TypeConverter::StringToType(buffer, hour);
		input.getline(buffer, 3, ':');
		TypeConverter::StringToType(buffer, minute);
		input.getline(buffer, 3, 'Z');
		TypeConverter::StringToType(buffer, second);
		return CimDateTimeAbsolute(year, month, day, hour, minute, second, 0);
	}

	string CimSerializer::SerializeDateTimeInterval(const CimDateTimeInterval &dateTime) const
	{
		ostringstream ret;
		ret << 'P';
		if (dateTime.Days() > 0)
		{
			ret << dateTime.Days() << 'D';
		}
		if (dateTime.Hours() > 0 || dateTime.Minutes() > 0 || dateTime.Seconds() > 0 || dateTime.Microseconds() > 0)
		{
			ret << 'T';
			if (dateTime.Hours() > 0)
			{
				ret << dateTime.Hours() << 'H';
			}
			if (dateTime.Minutes() > 0)
			{
				ret << dateTime.Minutes() << 'M';
			}
			if (dateTime.Seconds() > 0 || dateTime.Microseconds() > 0)
			{
				if (dateTime.Seconds() > 0)
				{
					ret << dateTime.Seconds();
				}
				else
				{
					ret << '0';
				}
				if (dateTime.Microseconds() > 0)
				{
					ret.fill('0');
					ret << '.' << setw(6) << dateTime.Microseconds();
				}
				ret << 'S';
			}
		}
		return ret.str();
	}

	CimDateTimeInterval CimSerializer::DeserializeDateTimeInterval(const string &str) const
	{
		string dateString = str.substr(0, str.find('T'));
		string timeString = str.substr(str.find('T'));
		unsigned short hours = 0, minutes = 0, seconds = 0;
		unsigned long days = 0, microseconds = 0;

		DeserializeDateInterval(dateString, days);
		DeserializeTimeInterval(timeString, hours, minutes, seconds, microseconds);

		return CimDateTimeInterval(days, hours, minutes, seconds, microseconds);
	}

	void CimSerializer::DeserializeDateInterval(const string& dateString, unsigned long& days) const
	{
		unsigned short years = 0, months = 0;
		days = 0;

		string::const_iterator begin = dateString.begin() + dateString.find('P') + 1;

		GetValueIfExists(begin, dateString.end(), 'Y', years);
		GetValueIfExists(begin, dateString.end(), 'M', months);
		GetValueIfExists(begin, dateString.end(), 'D', days);

		// Convert number of years, months, and days to number of days
		days += (years * 365) + (months * 30);
	}

	void CimSerializer::DeserializeTimeInterval(const string& timeString, unsigned short& hours, unsigned short& minutes, unsigned short& seconds, unsigned long& microseconds) const
	{
		hours = minutes = seconds = 0, microseconds = 0;

		string::const_iterator begin = timeString.begin() + timeString.find('T') + 1;

		GetValueIfExists(begin, timeString.end(), 'H', hours);
		GetValueIfExists(begin, timeString.end(), 'M', minutes);
		if (timeString.find('.') != string::npos)
		{
			GetValueIfExists(begin, timeString.end(), '.', seconds);
			ostringstream microseconds_stream;
			microseconds_stream.fill('0');
			microseconds_stream << setiosflags(ios::left) << setw(6)
								<< string(begin, find(begin, timeString.end(), 'S'))
								<< resetiosflags(ios::left);
			TypeConverter::StringToType(microseconds_stream.str(), microseconds);
		}
		else
		{
			GetValueIfExists(begin, timeString.end(), 'S', seconds);
		}
	}

	string CimSerializer::Serialize(const string &objectName, const string &nameSpace,
		const string &/*uri*/, const string &prefix, const VectorFieldData &vfd, bool includeRoot, bool delegateNs) const
	{
	#if 0
		string ret = "";

		// opening tag
		ret += "<" + objectName;
		if (! nameSpace.empty() && !delegateNs)
		{
			ret += " xmlns";
			if (! prefix.empty())
				ret += ":" + prefix;
			ret += "=\"" + nameSpace + "\"";
		}
		ret += ">";

		VectorFieldData::const_iterator iter;
		for (iter = vfd.begin(); iter != vfd.end(); iter++)
		{
			vector<string>::const_iterator vals;
			for (vals = iter->second.begin(); vals != iter->second.end(); vals++)
			{
				string value = *vals;
				if (value[0] == '<') //icko
				{
					ret += value;
				}
				else
				{
					ret += "<" + iter->first;
					if (delegateNs)
					{
						ret += " xmlns";
						if (! prefix.empty())
							ret += ":" + prefix;
						ret += "=\"" + nameSpace + "\"";
					}
					ret += ">";
					ret += value;
					ret += "</" + iter->first + ">";
				}
			}
		}
		
		
		// closing tag
		ret += "</" + objectName + ">";
		return ret;
		
		
	#endif
	#if 1
		XMLDoc doc(objectName.c_str(),
			delegateNs ? NULL : nameSpace.c_str(),
			prefix.empty() ? NULL : prefix.c_str() );
		XMLElement root = doc.GetRootNode();
		
		// Loop over the elements in the vfd and add them to the XML document.
		VectorFieldData::const_iterator iter;
		for (iter = vfd.begin(); iter != vfd.end(); iter++)
		{
			vector<string>::const_iterator vals;
			string elemName = iter->name;
			for (vals = iter->value.begin(); vals != iter->value.end(); vals++)
			{
				string xml = *vals;
				// Change the value to a valid XML ()
				xml = "<"+elemName+" xmlns=\""+nameSpace+"\">" + xml + "</"+elemName+">";
				XMLDoc innerDoc(xml, NULL);
				XMLElement innerElem = innerDoc.GetRootNode();
				try {
					root.AppendNode(innerElem);
				}
				catch (const XMLException& e)
				{
					throw ConversionException(xml + " " + e.what());
				}
			}
		}

		if (includeRoot)
		{
			return doc.ToString();
		}
		else
		{
			return root.ToString(includeRoot);
		}
	#endif

	}

	std::string CimSerializer::SerializeAttributed(const string &rootTag,
			const string &innerTag, 
			const string &attribute, //attribute name
			const string &nameSpace,
			const string &/*uri*/, 
			const string &prefix,
			const VectorFieldData &vfd, // inner value of the node 
			bool includeRoot) const
	{
		XMLDoc doc(rootTag.c_str(),
			nameSpace.empty() ? NULL : nameSpace.c_str(),
			prefix.empty() ? NULL : prefix.c_str() );
		XMLElement root = doc.GetRootNode();

		vector<string> attributes;
		vector<string> values;
		VectorFieldData::const_iterator iter;

		for (iter = vfd.begin(); iter != vfd.end(); iter++)
		{
			vector<string>::const_iterator vals;
			
			string attributeName = attribute;
			string attributeValue = iter->name;
			for (vals = iter->value.begin(); vals != iter->value.end(); vals++)
			{
				string xml = *vals;
				
				// Change the value to a valid XML ()
				xml = "<"+innerTag+" xmlns=\""+nameSpace+"\"  >" + xml + "</"+innerTag+">";//"+attributeName+"=\""+attributeValue+"\"
				XMLDoc innerDoc(xml, NULL);
				XMLElement innerElem = innerDoc.GetRootNode();
				innerElem.AddAttribValue(attributeName, attributeValue);
				try {
					root.AppendNode(innerElem);
				}
				catch (const XMLException& e)
				{
					throw ConversionException(xml + " " + e.what());
				}
			
			}
		}


		if (includeRoot)
		{
			return doc.ToString();
		}
		else
		{
			return root.ToString(includeRoot);
		}
	}

	const VectorFieldData CimSerializer::Deserialize(const std::string &xml, string &objectName, string &prefix, string &resourceURI) const
	{
		VectorFieldData ret;

		XMLDoc d(xml, NULL);
		XMLElement node = d.GetRootNode();
		prefix = node.GetNSPrefix();
		objectName = node.GetNodeName();
		resourceURI = node.GetNSUri();
		if (node.HasChildren())
		{
			XMLElement tmp = node.GetFirstChild();

			for (;;)
			{
				string name = tmp.GetNodeName();
				string value;

				// Insert the value without the outer tag (which is saved as the name)
				value = tmp.ToString(false);
					


				// Because we can have multiple instances of tag and value in a
				// document, we want to keep all the values together with their
				// tag, so we have to loop over the existing vector string pair to
				// see if we have found this tag already.  This isn't pretty but
				// it's necessary; we DO NOT use a map since we require the ordering
				// in the metadata in CimData to give us serialization order.
				VectorFieldData::iterator iter;
				bool found = false;
				for (iter = ret.begin(); iter != ret.end(); iter++)
				{
					if (iter->name == name)
					{
						iter->value.push_back(value);
						found = true;
						break;
					}
				}

				if (! found)
				{
					FieldData newval;
					newval.name = name;
					newval.value.push_back(value);
					ret.push_back(newval);
				}

				// Move on to next element in the XML document (loop control).
				if (tmp.HasNextSibling())
				{
					tmp = tmp.GetNextSibling();
				}
				else
					break;
			}		
		}
		return ret;
	}

	const VectorFieldData CimSerializer::Deserialize(const std::string &xml) const
	{
		string objectName, prefix, resourceURI; // not used
		return Deserialize(xml, objectName, prefix, resourceURI);
	}

	void CimSerializer::DeserializeItem(const std::string &itemXml, std::string &firstXml, std::string &secondXml) const
	{
		XMLDoc d(itemXml, NULL);
		XMLElement node = d.GetRootNode();
		XMLElement tmp = node.GetFirstChild();
		firstXml = tmp.ToString(true);
		
		tmp = tmp.GetNextSibling();
		secondXml = tmp.ToString(true);	
	}
	const VectorFieldData CimSerializer::DeserializeAttributed(const std::string &xml, const string &attribute) const
	{
		VectorFieldData ret;

		XMLDoc d(xml, NULL);
		XMLElement node = d.GetRootNode();

		if (node.HasChildren())
		{
			XMLElement tmp = node.GetFirstChild();

			map <string, string> attributes;
			for (;;)
			{
				tmp.GetAttributes(attributes);
				string name = attributes.find(attribute)->second;
				string value = tmp.ToString(false);//tmp.GetTextValue();

				string objectName, nameSpace, prefix, resourceURI;

				// Because we can have multiple instances of tag and value in a
				// document, we want to keep all the values together with their
				// tag, so we have to loop over the existing vector string pair to
				// see if we have found this tag already.  This ain't pretty but
				// it's necessary; we DO NOT use a map since we require the ordering
				// in the metadata in CimData to give us serialization order.
				VectorFieldData::iterator iter;
				bool found = false;
				for (iter = ret.begin(); iter != ret.end(); iter++)
				{
					if (iter->name == name)
					{
						iter->value.push_back(value);
						found = true;
						break;
					}
				}

				if (! found)
				{
					FieldData newval;
					newval.name = name;
					newval.value.push_back(value);
					ret.push_back(newval);
				}

				// Move on to next element in the XML document (loop control).
				if (tmp.HasNextSibling())
				{
					tmp = tmp.GetNextSibling();
				}
				else
					break;
			}		
		}
		return ret;
	}

} //namespace Untyped
} //namespace Cim 
} //namespace Manageability 
} //namespace Intel
