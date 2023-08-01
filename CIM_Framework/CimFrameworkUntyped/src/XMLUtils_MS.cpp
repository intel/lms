//----------------------------------------------------------------------------
//
// Copyright (c) Intel Corporation, 2003 - 2023 All Rights Reserved.
//
//  File: XMLUtils_MS.cpp    
//
//  Contents: An implementation of the XMLUtils interface using MSXML  
//
//----------------------------------------------------------------------------

#include <msxml6.h>
#include <atlbase.h>
#include <vector>
#include <comutil.h>
#include "XMLUtils.h"
#include <MsXml2.h>

namespace Intel
{
namespace Manageability
{
namespace XMLUtils 
{
  bool   _CimXMLUtilsInitialized = false;
  
	string ConvertCComBSTRToString(CComBSTR val)
	{
		return (string)CW2A(val);
	}

	// Function to remove empty definitions of namespaces.
	string cleanXML(string val)
	{		
		string ret = val;
		string searchString( " xmlns=\"\"" ); 
		string replaceString( " " );
		string::size_type pos = 0;
		while ( (pos = ret.find(searchString, pos)) != string::npos ) 
		{
			ret.replace( pos, searchString.size(), replaceString );
			pos++;
		}
		return ret;
	}

	class XMLElementImpl
	{
		friend class XMLDocImpl;
	private:
		CComPtr<IXMLDOMNode> domNode;
		CComPtr<IXMLDOMDocument> domDoc;
		IXMLDOMNode* cloneNode(const CComPtr<IXMLDOMNode> node)
		{
			IXMLDOMNode *newNode;
			if (FAILED(node->cloneNode(true, &newNode)))
			{
				throw XMLException("node cloning failed");
			}
			return newNode;
		}
		
	public:
		XMLElementImpl(CComPtr<IXMLDOMNode> node)
		{
			domNode = node;
			if (node)
			{
				node->get_ownerDocument(&domDoc);
			}
		}

		XMLElementImpl(const XMLElementImpl& element)
		{
			domNode = element.domNode;
			domDoc = element.domDoc;
		}
		
		
		~XMLElementImpl()
		{
		}

		XMLElementImpl&  operator=(const XMLElementImpl &other )
		{
			if (this != &other)
			{
				domNode = other.domNode;
				domDoc = other.domDoc;
			}
			return *this;			
		}

		XMLElementImpl* deepClone(const XMLElementImpl &other)
		{
			CComPtr<IXMLDOMNode> newNode = CComPtr<IXMLDOMNode>(cloneNode(other.domNode));
			XMLElementImpl *ret = new XMLElementImpl(newNode);
			return ret;
		}

		XMLElementImpl* CreateChildNode(const string& nodeName,
			const string& /*ns*/,
			const string& prefix,
			const string* text = nullptr)
		{
			string qn = !prefix.empty() ?
					prefix + ":" + nodeName : nodeName;
			
			CComPtr<IXMLDOMNode> dummy = nullptr;
			CComPtr<IXMLDOMElement> elem = nullptr;
			if (FAILED(domDoc->createElement(CComBSTR(nodeName.c_str()), &elem)))
				throw XMLException("Failed to create XMLElement");
			if (FAILED(domNode->appendChild(elem, &dummy)))
				throw XMLException("Failed to create XMLElement");
			
			if(text)
			{
				CComPtr<IXMLDOMText> val = nullptr;
				if (FAILED(domDoc->createTextNode(CComBSTR(text->c_str()), &val)))
					throw XMLException("Failed to create XMLElement");
				dummy.Release();
				
				if (FAILED(elem->appendChild(val, &dummy)))
					throw XMLException("Failed to create XMLElement");
			}
			CComPtr<IXMLDOMNode> ret = nullptr;
			ret = elem;
			return new XMLElementImpl(ret);
		}

		void CreateLeafNode(const string& nodeName,
			const string& ns,
			const string& prefix,
			const string& nodeValue)
		{
			CreateAttributedLeafNode(nodeName, "", "", ns, prefix, nodeValue);
		}	

		void CreateAttributedLeafNode(const string& nodeName,
			const string& attribute,
			const string& attributeValue,
			const string& ns,
			const string& prefix,
			const string& nodeValue)
		{
			string qn = !prefix.empty() ?
			prefix + ":" + nodeName : nodeName;
			
			CComPtr<IXMLDOMNode> dummy = nullptr;
			CComPtr<IXMLDOMElement> elem = nullptr;
			CComPtr<IXMLDOMNode> node = nullptr;
			if (FAILED(domDoc->createNode(CComVariant(NODE_ELEMENT), CComBSTR(nodeName.c_str()), CComBSTR(ns.c_str()), &node)))
				throw XMLException("Failed to create XMLElement");
			
			elem = node;

			if (! attribute.empty())
				if (FAILED(elem->setAttribute(CComBSTR(attribute.c_str()), CComVariant(attributeValue.c_str()))))
					throw XMLException("Failed to create XMLElement");

			if (FAILED(domNode->appendChild(elem, &dummy)))
				throw XMLException("Failed to create XMLElement");
			
			dummy.Release();
			
			
			CComPtr<IXMLDOMText> val = NULL;
			if (FAILED(domDoc->createTextNode(CComBSTR(nodeValue.c_str()), &val)))
				throw XMLException("Failed to create XMLElement");
			if (FAILED(elem->appendChild(val, &dummy)))
				throw XMLException("Failed to create XMLElement");	
		}

		void AppendNode(const XMLElement &innerElem)
		{
			CComPtr<IXMLDOMNode> out = nullptr;
			if (FAILED(domNode->appendChild(innerElem.impl->domNode, &out)))
				throw XMLException("Failed to Append Node");
		}

		void AddText(const string& nodeValue)
		{

			CComPtr<IXMLDOMNode> dummy = nullptr;
			CComPtr<IXMLDOMText> val = nullptr;
			if (FAILED(domDoc->createTextNode(CComBSTR(nodeValue.c_str()), &val)))
				throw XMLException("Failed to add text node");
			if (FAILED(domNode->appendChild(val, &dummy)))
				throw XMLException("Failed to add text node");	
		}

		bool HasNextSibling() const
		{
			CComPtr<IXMLDOMNode> tmp;
			if (FAILED(domNode->get_nextSibling(&tmp)))
				throw XMLException("Failed to retrieve sibling");
			DOMNodeType type = NODE_ELEMENT;
			while(tmp != nullptr && SUCCEEDED(tmp->get_nodeType(&type)) && type != NODE_ELEMENT)
			{
				CComPtr<IXMLDOMNode> node;
				if (FAILED(tmp->get_nextSibling(&node)))
					throw XMLException("Failed to retrieve sibling");
				tmp = node;
			}
			return (tmp != nullptr);
		}

		XMLElementImpl* GetNextSibling() const
		{
			CComPtr<IXMLDOMNode> tmp;
			
			if (FAILED(domNode->get_nextSibling(&tmp)))
				throw XMLException("Failed to retrieve sibling");
			DOMNodeType type = NODE_ELEMENT;
			while(tmp != nullptr && SUCCEEDED(tmp->get_nodeType(&type)) && type != NODE_ELEMENT)
			{
				CComPtr<IXMLDOMNode> node;
				if (FAILED(tmp->get_nextSibling(&node)))
					throw XMLException("Failed to retrieve sibling");
				tmp = node;
			}
			if (tmp == nullptr)
				return nullptr;
			return new XMLElementImpl(tmp);
		}

		bool HasChildren() const
		{
			bool b = false;
			if(nullptr == domNode)
			{
				return b;
			}
			CComPtr<IXMLDOMNode> sibling = nullptr;
			CComPtr<IXMLDOMNode> nextSibling = nullptr;
			DOMNodeType type;
			VARIANT_BOOL vb;
			long len;

			if(FAILED(domNode->hasChildNodes(&vb)))
			{
				return b;
			}

			
			if(VARIANT_FALSE == vb)
			{
				return b;
			}

			
			CComPtr<IXMLDOMNodeList> children;
			if(FAILED(domNode->get_childNodes(&children)) ||
				FAILED(children->get_length(&len)))
			{
				return b;
			}

			for(long i = 0; i < len; i++)
			{
				CComPtr<IXMLDOMNode> item = nullptr;
				if(FAILED(children->get_item(i, &item)) ||
					FAILED(item->get_nodeType(&type)))
				{
					return b;
				}
				
				if(NODE_ELEMENT != type)
				{
					continue;
				}
				else
				{
					b = true;
					break;
				}
			}

			return b;
		}

		bool IsLeafNode() const
		{
			return !HasChildren();
		}

		XMLElementImpl* GetFirstChild() const
		{
			CComPtr<IXMLDOMNode> child;
			if (FAILED(domNode->get_firstChild(&child)))
				throw XMLException("Failed to retrieve child element");

			DOMNodeType type = NODE_ELEMENT;
			while(child && child->get_nodeType(&type) == 0 && type != NODE_ELEMENT)
			{
				CComPtr<IXMLDOMNode> node;
				child->get_nextSibling(&node);
				child = node;
			}
			
			return new XMLElementImpl(child);
		}

		string GetNodeName() const
		{
			CComBSTR tmp;
			if (FAILED(domNode->get_nodeName(&tmp)))
				throw XMLException("Failed to retrieve node name");

			string name = ConvertCComBSTRToString(tmp);
			const auto pos = name.find(':');
			name = (pos == string::npos) ? name : name.substr(pos + 1);
			return name;
		}

		string GetNSUri() const
		{
			CComBSTR tmp;
			if (FAILED(domNode->get_namespaceURI(&tmp)))
				throw XMLException("Failed to retrieve namespace URI");
			if(tmp)
				return ConvertCComBSTRToString(tmp);
			
			return "";
		}

		string GetNSPrefix() const
		{
			CComBSTR tmp;
			if (FAILED(domNode->get_prefix(&tmp)))
				throw XMLException("Failed to retrieve namespace prefix");
			if(tmp)
				return ConvertCComBSTRToString(tmp);
			return "";
		}

		string GetTextValue() const
		{
			CComBSTR tmp;
			if (FAILED(domNode->get_text(&tmp)))
				throw XMLException("Failed to retrieve text value");
			if (tmp)
				return ConvertCComBSTRToString(tmp);
			return "";
		}

		string ToString(bool incRoot = false) const
		{
			CComBSTR retBSTR;
			if(!incRoot && IsLeafNode())
			{
				return GetTextValue();
			}

			if(incRoot)
			{
				if (FAILED(domNode->get_xml(&retBSTR)))
					throw XMLException("Failed to serialize element");
			}
			else
			{
				CComPtr<IXMLDOMNode> child;
				CComPtr<IXMLDOMNodeList> childList;
				if (FAILED(domNode->get_childNodes(&childList)))
					throw XMLException("Failed to serialize element");

				if (FAILED(childList->nextNode(&child)))
					throw ("Failed to serialize element");
				while (child)
				{
					CComBSTR tmp;
					if (FAILED(child->get_xml(&tmp)))
						throw ("Failed to serialize element");
					retBSTR += tmp;
					child.Release();
					if (FAILED(childList->nextNode(&child)))
						throw ("Failed to serialize element");
				}
			}
			string ret = cleanXML(ConvertCComBSTRToString(retBSTR));
			return ret;
		}	

		void GetAttributes(map<string, string>& attribs) const
		{
			CComBSTR tmpName;
			CComVariant tmpValue;
			CComPtr<IXMLDOMNamedNodeMap> attributeMap = NULL;
			if (FAILED(domNode->get_attributes(&attributeMap)))
				throw XMLException("Failed to retrieve attributes");
			long len = 0;
			if (FAILED(attributeMap->get_length(&len)))
				throw XMLException("Failed to retrieve attributes");

			for (long i=0; i < len; ++i)
			{
				CComPtr<IXMLDOMNode> listItem = NULL;
				if (FAILED(attributeMap->get_item(i, &listItem)))
					throw XMLException("Failed to retrieve attributes");
				if (FAILED(listItem->get_nodeName(&tmpName)))
					throw XMLException("Failed to retrieve attributes");
				if (FAILED(listItem->get_nodeValue(&tmpValue)))
					throw XMLException("Failed to retrieve attributes");

				attribs[ConvertCComBSTRToString(tmpName)] = ConvertCComBSTRToString(tmpValue.bstrVal);
			}	
		}

		string GetAttribValue(const string& name) const
		{
			string ret = "";
			CComBSTR tmpName;
			CComVariant tmpValue;
			CComPtr<IXMLDOMNamedNodeMap> attributeMap = NULL;
			if (FAILED(domNode->get_attributes(&attributeMap)))
				throw XMLException("Failed to retrieve attributes");

			long len = 0;
			if (FAILED(attributeMap->get_length(&len)))
				throw XMLException("Failed to retrieve attributes");
			for (long i=0; i < len; ++i)
			{
				CComPtr<IXMLDOMNode> listItem = NULL;
				if (FAILED(attributeMap->get_item(i, &listItem)))
					throw XMLException("Failed to retrieve attributes");
				if (FAILED(listItem->get_nodeName(&tmpName)))
					throw XMLException("Failed to retrieve attributes");
				if (FAILED(listItem->get_nodeValue(&tmpValue)))
					throw XMLException("Failed to retrieve attributes");
				if(name.compare(ConvertCComBSTRToString(tmpName)) == 0)
				{
					ret = ConvertCComBSTRToString(tmpValue.bstrVal);
					break;
				}
				
			}
			
			return ret;
		}

		void AddAttribValue(const string& name, const string& value)
		{
			CComPtr<IXMLDOMElement> elem;
			elem = domNode;
			if (FAILED(elem->setAttribute(CComBSTR(name.c_str()), CComVariant(value.c_str()))))
				throw XMLException("Failed to add Add attribute value");
		}

		void AddNSDefinition(const string& ns, const string* prefix = nullptr)
		{
			string qn = "xmlns";
			if(prefix && !prefix->empty())
			{
				qn.append(":").append(*prefix);
			}

			CComPtr<IXMLDOMAttribute> att;
			CComPtr<IXMLDOMAttribute> dummy;
			if (FAILED(domDoc->createAttribute(CComBSTR(qn.c_str()), &att)))
				throw XMLException("Failed to add namespace definition");
			if (FAILED(att->put_value(CComVariant(ns.c_str()))))
				throw XMLException("Failed to add namespace definition");
			CComPtr<IXMLDOMElement> elem;
			elem = domNode;
			if (FAILED(elem->setAttributeNode(att, &dummy)))
				throw XMLException("Failed to add namespace definition");
		}
		

	};

	class XMLDocImpl
	{
	private:
		CComPtr<IXMLDOMElement> rootNode;
		CComPtr<IXMLDOMDocument> doc;
	public:		
		XMLDocImpl(const string& xml, const char*  /*xsdFile = NULL*/):doc(NULL), rootNode(NULL)//doc(NULL), parser(NULL)
		{
			VARIANT_BOOL status;

			HRESULT res = CoCreateInstance(__uuidof(DOMDocument60), NULL,
				CLSCTX_INPROC_SERVER, __uuidof(IXMLDOMDocument), (void**)&doc) ||
				FAILED(doc->put_async(VARIANT_FALSE)) ||
				FAILED(doc->put_validateOnParse(VARIANT_FALSE)) ||
				FAILED(doc->put_resolveExternals(VARIANT_FALSE));


			if (res != S_OK)
				throw XMLException("Failed to create XML document");
			try
			{
				const auto ret = doc->loadXML(CComBSTR(xml.c_str()), &status);
				if (ret != S_OK)
					throw XMLException("Failed to create XML document");
			}
			catch (CAtlException)
			{
				throw XMLException("Failed to create XML document, AtlException");
			}
			if (status == VARIANT_TRUE)
				if (doc->get_documentElement(&rootNode) != S_OK)
					throw XMLException("Failed to create XML document");
		}

		XMLDocImpl(const char* rootName,
			const char* uri,
			const char*  /*prefix*/):doc(nullptr), rootNode(nullptr)//doc(NULL), parser(NULL)
		{
			if (CoCreateInstance(__uuidof(DOMDocument60), nullptr,
			CLSCTX_INPROC_SERVER, __uuidof(IXMLDOMDocument), (void**)&doc) ||
			FAILED(doc->put_async(VARIANT_FALSE)) ||
			FAILED(doc->put_validateOnParse(VARIANT_FALSE)) ||
			FAILED(doc->put_resolveExternals(VARIANT_FALSE)) )
				throw XMLException("Failed to create XML document");

			if (FAILED(doc->createNode(CComVariant(NODE_ELEMENT), CComBSTR(rootName), CComBSTR(uri), (IXMLDOMNode **)&rootNode)))
				throw XMLException("Failed to create XML document");
			if (FAILED(doc->putref_documentElement(rootNode)))
				throw XMLException("Failed to create XML document");

			CComBSTR docstr;
			if (FAILED(doc->get_xml(&docstr)))
				throw XMLException("Failed to create XML document");
	
		}		

		~XMLDocImpl()
		{
			doc.Release();
		}

		void LoadXml(const char* xmlString)
		{
			VARIANT_BOOL status;
			if (doc->loadXML(CComBSTR(xmlString), &status) != S_OK)
				throw XMLException("Failed to Load XML");
		}

		XMLElement GetRootNode()
		{
			CComPtr<IXMLDOMElement> DOMElement = nullptr;
			if (FAILED(doc->get_documentElement(&DOMElement)))
				throw XMLException("Failed to retrieve root element");
			return XMLElement(new XMLElementImpl((CComPtr<IXMLDOMNode>)DOMElement));			
		}

		string GetElementByTagName(const string &name)
		{
			CComPtr<IXMLDOMNodeList> resultList = nullptr;
			
			if (FAILED(doc->getElementsByTagName(CComBSTR(name.c_str()), &resultList)))
				return "";
			long length = 0;
			if (resultList == nullptr || FAILED(resultList->get_length(&length)))
				throw XMLException("Failed to retrieve element");
			if (length == 0)
				return "";
			CComPtr<IXMLDOMNode> listItem = nullptr;
			if (FAILED(resultList->get_item(0, &listItem)))
				throw XMLException("Failed to retrieve element");
			CComVariant value;
			if (FAILED(listItem->get_nodeValue(&value)))
				throw XMLException("Failed to retrieve element");
			return ConvertCComBSTRToString(value.bstrVal);		
		}

		string ToString(bool /*incVersionStr = false*/)
		{
			
			CComBSTR retBSTR;
			if (FAILED(doc->get_xml(&retBSTR)))
				throw XMLException("Failed to serialize XML document");
			string ret = cleanXML(ConvertCComBSTRToString(retBSTR));
			
			return ret;
		}
	};


	void InitXMLLibrary(const bool /*enableSchemaValidation*/,
											  const bool /*validateFromFile*/,
											  const string& /*xsdPath*/)
	{
		if(_CimXMLUtilsInitialized)
		{
			throw XMLException("An attempt was made to initialize the XML library, after it was already initialized..");
		}
		const auto res = CoInitializeEx(nullptr, COINIT_MULTITHREADED);
		if(0 > res)
		{
			throw XMLException("Unable to initialize XML library");
		}
		_CimXMLUtilsInitialized = true;
	}

	bool IsXMLLibraryInit()
		{
			return _CimXMLUtilsInitialized;
		}
	void TerminateXMLLibrary()
	{
		if (_CimXMLUtilsInitialized) {
			CoUninitialize();
			_CimXMLUtilsInitialized = false;
		}
	}

	XMLElement::XMLElement(XMLElementImpl* i)
	{
		impl = i;
	}

	XMLElement::XMLElement(const XMLElement& other)
	{
		impl = new XMLElementImpl(*(other.impl));
	}

	XMLElement& XMLElement::operator=(const XMLElement &other)
	{
		if(this != &other)
		{
			delete impl;
			impl = new XMLElementImpl(*(other.impl));
		}
		return *this;
	}

	XMLElement::~XMLElement()
	{
		delete impl;
		impl = nullptr;
	}

	void XMLElement::CreateLeafNode(const string& nodeName,
														   const string& ns,
														   const string& prefix,
														   const string& nodeValue)
	{
		impl->CreateLeafNode(nodeName, ns, prefix, nodeValue);
	}

	void XMLElement::CreateAttributedLeafNode(const string& nodeName,
														   const string& attribute,
														   const string& attributeValue,
														   const string& ns,
														   const string& prefix,
														   const string& nodeValue)
	{
		impl->CreateAttributedLeafNode(nodeName, attribute, attributeValue, ns, prefix, nodeValue);
	}

	bool XMLElement::HasNextSibling() const
	{
		return impl->HasNextSibling();
	}

	XMLElement XMLElement::GetNextSibling() const
	{
		XMLElementImpl* sibling = impl->GetNextSibling();
		if (sibling == nullptr)
			throw XMLException("Failed to retrieve sibling");
		return XMLElement(sibling);
	}

	bool XMLElement::HasChildren() const
	{
		return impl->HasChildren();
	}

	bool XMLElement::IsLeafNode() const
	{
		return impl->IsLeafNode();
	}

	XMLElement XMLElement::GetFirstChild() const
	{
		XMLElementImpl* child = impl->GetFirstChild();
		if (child == nullptr)
			throw XMLException("Failed to retrieve child element");
		return XMLElement(child);
	}

	string XMLElement::GetNodeName() const
	{
		return impl->GetNodeName();
	}

	string XMLElement::GetTextValue() const
	{
		return impl->GetTextValue();
	}



	string XMLElement::ToString(bool incRoot) const
	{
		return impl->ToString(incRoot);
	}

	string XMLElement::GetNSUri() const
	{
		return impl->GetNSUri();
	}

	string XMLElement::GetNSPrefix() const
	{
		return impl->GetNSPrefix();
	}

	void XMLElement::GetAttributes(map<string, string>& attribs) const
	{
		impl->GetAttributes(attribs);
	}

	void XMLElement::AppendNode(const XMLElement &innerElem)
	{
		impl->AppendNode(innerElem);
	}



	string XMLElement::GetAttribValue(const string& name) const
	{
		return impl->GetAttribValue(name);
	}

	void XMLElement::AddAttribValue(const string& name, const string& value)
	{
		impl->AddAttribValue(name, value);
	}

	void XMLElement::AddNSDefinition(const string& ns, const string* prefix)
	{
		impl->AddNSDefinition(ns, prefix);
	}

	// XMLDoc function implementations
	XMLDoc::XMLDoc(const string& xml, const char* xsdFile)
	{
		impl = new XMLDocImpl(xml, xsdFile);
	}

	XMLDoc::XMLDoc(const char* rootName,
										 const char* uri,
										 const char* prefix)
	{
		impl = new XMLDocImpl(rootName, uri, prefix);
	}

	XMLDoc::~XMLDoc()
	{
		delete impl;
	}

	void XMLDoc::LoadXml(const char* xmlString)
	{
		impl->LoadXml(xmlString);
	}

	XMLElement XMLDoc::GetRootNode()
	{
		return impl->GetRootNode();
	}

	string XMLDoc::GetElementByTagName(const string &name)
	{
		return impl->GetElementByTagName(name);
	}

	string XMLDoc::ToString(bool incVersionStr)
	{
		return impl->ToString(incVersionStr);
	}

};
}
}
