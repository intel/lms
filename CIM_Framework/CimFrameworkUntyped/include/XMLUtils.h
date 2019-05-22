//----------------------------------------------------------------------------
//
// Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       
//
//  Contents:   
//
//----------------------------------------------------------------------------

// defines an XML utility interface

#ifndef __CIMXMLUTILS_H
#define __CIMXMLUTILS_H

#include <string>
#include <map>
#include <vector>
#include <stdexcept>

#include "CimUtils.h"



namespace Intel
{
namespace Manageability
{
namespace XMLUtils 
{
	using namespace std;
	using namespace Intel::Manageability::Cim::Utils;

	// function declarations
	// this function should be called once at the beginning of the program
	// enableSchemaValidation will enable schema validation. To enable
	// validation from xsd file, set validateFromFile. To set the path where
	// search for xsd files that are provided (in the XMLDoc constructor)
	// set xsdPath.
	// (The xsd file name will be appended to the provided xsdPath, as is.)
	// *** Schema Validation has not been implemented
	void InitXMLLibrary(const bool enableSchemaValidation = false,
		const bool validateFromFile = false, const string& xsdPath = "");

	// return if the lib was initiated
	bool IsXMLLibraryInit();

	// this function should be called once at the end of the program
	void TerminateXMLLibrary();
	
	// Exception class, encapsulates exceptions thrown by the XML lib
	// used to implement the XML utility interface
	class XMLException : public runtime_error
	{
	public:
		XMLException()
			: runtime_error("XMLException: Unknown XML Exception")
		{ }
		XMLException(const XMLException &Other)
			: runtime_error(Other)
		{ }
		XMLException(const string &message)
			: runtime_error("XMLException: " + message)
		{ }
		virtual ~XMLException() throw() {}

		XMLException &operator=(const XMLException &other) = delete;
	};	

	// forward class declaration
	class XMLElementImpl;

	// XMLElement represents an XML element node
	class XMLElement
	{
		friend class XMLDocImpl;
		friend class XMLElementImpl;
	private:
		XMLElementImpl* impl;
		XMLElement(XMLElementImpl* i);

	public:
		XMLElement(const XMLElement& other);

		~XMLElement();

		XMLElement& operator=(const XMLElement &other );

		
		void CreateLeafNode(const string& nodeName,
			const string& ns,
			const string& prefix,
			const string& nodeValue);

		void CreateAttributedLeafNode(const string& nodeName,
			const string& attribute,
			const string& attributeValue,
			const string& ns,
			const string& prefix,
			const string& nodeValue);


		bool HasNextSibling() const;

		XMLElement GetNextSibling() const;

		bool HasChildren() const;

		bool IsLeafNode() const;

		XMLElement GetFirstChild() const;

		string GetNodeName() const;

		string GetTextValue() const;

		string ToString(bool incRoot = false) const;

		string GetNSUri() const;

		string GetNSPrefix() const;

		void GetAttributes(map<string, string>& attribs) const;

		void AppendNode(const XMLElement &innerElem);

		

		template <class T>
		void AppendLeaf(const string& name,			
			const T& t,
			const string& ns = "",
			const string& prefix = "")
		{
			/*string xml = TypeConverter::TypeToString(t);
			if (xml[0] == '<') // uck, yack, ptooey, blech, ...
			{
				XMLDoc innerDoc(xml, NULL);
				XMLElement tmp;
				XMLElement innerElem = innerDoc.GetRootNode();
				string val = innerElem.ToString(true);
				while (innerElem.HasChildren())
				{
					tmp = innerElem.GetFirstChild();

				}
				string innerval = innerElem.ToString(false);
				root.AppendNode(innerElem.GetFirstChild());
			}*/
			CreateLeafNode(name, ns, prefix,
				TypeConverter::TypeToString(t));
		}

		template <class T>
		void AppendLeafArray(const string& name,			
			const vector<T>& vec,
			const string& ns = "",
			const string& prefix = "")
		{
			for(unsigned int i = 0 ; i < vec.size(); i++)
			{
				AppendLeaf(name, vec[i], ns, prefix);
			}			
		}

		template <class T>
		void AppendAttributedLeaf(const string& name,
			const string& attribute,
			const string& attributeValue,
			const T& t,
			const string& ns = "",
			const string& prefix = "")
		{
			CreateAttributedLeafNode(name, attribute, attributeValue, ns, prefix,
				TypeConverter::TypeToString(t));
		}

		template <class T>
		void AppendAttributedLeafArray(const string& name,	
			const string& attribute,
			const vector<string> &attributes,
			const vector<T>& vec,
			const string& ns = "",
			const string& prefix = "")
		{
			for(unsigned int i = 0 ; i < vec.size(); i++)
			{
				AppendAttributedLeaf(name, attribute, attributes[i], vec[i], ns, prefix);
			}			
		}


		
		void AddNSDefinition(const string& ns, const string* prefix = NULL);

		void AddAttribValue(const string& name, const string& value);

		string GetAttribValue(const string& name) const;

		/*
		void AddText(const string& nodeValue);
		
		XMLElement CreateChildNode(const string& nodeName,
			const string& ns,
			const string& prefix,
			const string* text = NULL);

		

		

		
		
		*/

		/*template <class T>
		void AppendNodeArray(const string& name,			
			const vector<T>& vec,
			const string& ns = "",
			const string& prefix = "")
		{
			for(unsigned int i = 0 ; i < vec.size(); i++)
			{
				AppendNode(name, vec[i], ns, prefix);
			}			
		}*/

		/*template <class T>
		void SetValue(T& t) const
		{
			TypeConverter::
				StringToType(GetTextValue(),t);
		}*/

		/*template <class T>
		void AddValue(vector<T>& vec) const
		{
			T t;
			TypeConverter::
				StringToType(GetTextValue(),t);
			vec.push_back(t);			
		}*/

		/*template <class T>
		void SetComplexType(T& t) const
		{
			t.Deserialize(*this);
		}*/

		/*template <class T>
		void AddComplexType(vector<T>& vec) const
		{
			T t;
			t.Deserialize(*this);
			vec.push_back(t);			
		}*/

	};

	class XMLDocImpl;

	// XML Doc represents an XML document
	class XMLDoc
	{
	private:
		XMLDocImpl* impl;

		XMLDoc(const XMLDoc& xml);

		XMLDoc& operator=(const XMLDoc &other );

	public:
		// parse an XML doc, perform schema validation using xsdFile, if provided
		XMLDoc(const string& xml, const char* xsdFile = NULL);		

		// create an xml doc with the given root element
		XMLDoc(const char* rootName = "root",
			const char* uri = NULL,
			const char* prefix = NULL);

		~XMLDoc();

		void LoadXml(const char* xmlString);

		XMLElement GetRootNode();

		string GetElementByTagName(const string &name);

		string ToString(bool incVersionStr = false);
	};

}
}
}
#endif
