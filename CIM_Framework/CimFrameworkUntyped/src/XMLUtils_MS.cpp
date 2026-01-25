//----------------------------------------------------------------------------
//
// Copyright (C) 2003 Intel Corporation
//
//  File: XMLUtils_MS.cpp    
//
//  Contents: An implementation of the XMLUtils interface using MSXML  
//
//----------------------------------------------------------------------------

#include <msxml6.h>
#include <vector>
#include <comutil.h>
#include "XMLUtils.h"
#include <MsXml2.h>
#include <wrl/client.h>
#include <comdef.h>

using Microsoft::WRL::ComPtr;

namespace Intel
{
namespace Manageability
{
namespace XMLUtils 
{
  	bool   _CimXMLUtilsInitialized = false;

	string ConvertBSTRToString(_bstr_t val)
	{
		 // Get required buffer size
		int size = ::WideCharToMultiByte(CP_UTF8, 0, static_cast<const wchar_t*>(val),
										 -1, nullptr, 0, nullptr, nullptr);
		if (size <= 0)
			return "";
		std::string result(size - 1, '\0');
    	::WideCharToMultiByte(CP_UTF8, 0, static_cast<const wchar_t*>(val),
							  -1, &result[0], size, nullptr, nullptr);

    	return result;
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
		ComPtr<IXMLDOMNode> domNode;
		ComPtr<IXMLDOMDocument> domDoc;
		IXMLDOMNode* cloneNode(const ComPtr<IXMLDOMNode> node)
		{
			IXMLDOMNode *newNode;
			if (FAILED(node->cloneNode(true, &newNode)))
			{
				throw XMLException("node cloning failed");
			}
			return newNode;
		}
		
	public:
		XMLElementImpl(ComPtr<IXMLDOMNode> node)
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
			ComPtr<IXMLDOMNode> newNode = ComPtr<IXMLDOMNode>(cloneNode(other.domNode));
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
			
			ComPtr<IXMLDOMNode> dummy = nullptr;
			ComPtr<IXMLDOMElement> elem = nullptr;
			if (FAILED(domDoc->createElement(_bstr_t(nodeName.c_str()), elem.GetAddressOf())))
				throw XMLException("Failed to create XMLElement");
			if (FAILED(domNode->appendChild(elem.Get(), dummy.GetAddressOf())))
				throw XMLException("Failed to create XMLElement");
			
			if(text)
			{
				ComPtr<IXMLDOMText> val = nullptr;
				if (FAILED(domDoc->createTextNode(_bstr_t(text->c_str()), val.GetAddressOf())))
					throw XMLException("Failed to create XMLElement");
				dummy.Reset();
				
				if (FAILED(elem->appendChild(val.Get(), dummy.GetAddressOf())))
					throw XMLException("Failed to create XMLElement");
			}
			ComPtr<IXMLDOMNode> ret = nullptr;
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
			
			ComPtr<IXMLDOMNode> dummy = nullptr;
			ComPtr<IXMLDOMElement> elem = nullptr;
			ComPtr<IXMLDOMNode> node = nullptr;
			if (FAILED(domDoc->createNode(_variant_t(NODE_ELEMENT), _bstr_t(nodeName.c_str()), _bstr_t(ns.c_str()), node.GetAddressOf())))
				throw XMLException("Failed to create XMLElement");
			
			if (FAILED(node.As(&elem)))
    			throw XMLException("Failed to query IXMLDOMElement interface");

			if (! attribute.empty())
				if (FAILED(elem->setAttribute(_bstr_t(attribute.c_str()), _variant_t(attributeValue.c_str()))))
					throw XMLException("Failed to create XMLElement");

			if (FAILED(domNode->appendChild(elem.Get(), dummy.GetAddressOf())))
				throw XMLException("Failed to create XMLElement");
			
			dummy.Reset();
			
			
			ComPtr<IXMLDOMText> val = NULL;
			if (FAILED(domDoc->createTextNode(_bstr_t(nodeValue.c_str()), val.GetAddressOf())))
				throw XMLException("Failed to create XMLElement");
			if (FAILED(elem->appendChild(val.Get(), dummy.GetAddressOf())))
				throw XMLException("Failed to create XMLElement");	
		}

		void AppendNode(const XMLElement &innerElem)
		{
			ComPtr<IXMLDOMNode> out = nullptr;
			if (FAILED(domNode->appendChild(innerElem.impl->domNode.Get(), out.GetAddressOf())))
				throw XMLException("Failed to Append Node");
		}

		void AddText(const string& nodeValue)
		{

			ComPtr<IXMLDOMNode> dummy = nullptr;
			ComPtr<IXMLDOMText> val = nullptr;
			if (FAILED(domDoc->createTextNode(_bstr_t(nodeValue.c_str()), val.GetAddressOf())))
				throw XMLException("Failed to add text node");
			if (FAILED(domNode->appendChild(val.Get(), dummy.GetAddressOf())))
				throw XMLException("Failed to add text node");	
		}

		bool HasNextSibling() const
		{
			ComPtr<IXMLDOMNode> tmp;
			if (FAILED(domNode->get_nextSibling(tmp.GetAddressOf())))
				throw XMLException("Failed to retrieve sibling");
			DOMNodeType type = NODE_ELEMENT;
			while(tmp != nullptr && SUCCEEDED(tmp->get_nodeType(&type)) && type != NODE_ELEMENT)
			{
				ComPtr<IXMLDOMNode> node;
				if (FAILED(tmp->get_nextSibling(node.GetAddressOf())))
					throw XMLException("Failed to retrieve sibling");
				tmp = node;
			}
			return (tmp != nullptr);
		}

		XMLElementImpl* GetNextSibling() const
		{
			ComPtr<IXMLDOMNode> tmp;
			
			if (FAILED(domNode->get_nextSibling(tmp.GetAddressOf())))
				throw XMLException("Failed to retrieve sibling");
			DOMNodeType type = NODE_ELEMENT;
			while(tmp != nullptr && SUCCEEDED(tmp->get_nodeType(&type)) && type != NODE_ELEMENT)
			{
				ComPtr<IXMLDOMNode> node;
				if (FAILED(tmp->get_nextSibling(node.GetAddressOf())))
					throw XMLException("Failed to retrieve sibling");
				tmp = node;
			}
			if (tmp == nullptr)
				return nullptr;
			return new XMLElementImpl(tmp.Get());
		}

		bool HasChildren() const
		{
			bool b = false;
			if(nullptr == domNode)
			{
				return b;
			}
			ComPtr<IXMLDOMNode> sibling = nullptr;
			ComPtr<IXMLDOMNode> nextSibling = nullptr;
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

			
			ComPtr<IXMLDOMNodeList> children;
			if(FAILED(domNode->get_childNodes(children.GetAddressOf())) ||
				FAILED(children->get_length(&len)))
			{
				return b;
			}

			for(long i = 0; i < len; i++)
			{
				ComPtr<IXMLDOMNode> item = nullptr;
				if(FAILED(children->get_item(i, item.GetAddressOf())) ||
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
			ComPtr<IXMLDOMNode> child;
			if (FAILED(domNode->get_firstChild(child.GetAddressOf())))
				throw XMLException("Failed to retrieve child element");

			DOMNodeType type = NODE_ELEMENT;
			while(child && child->get_nodeType(&type) == 0 && type != NODE_ELEMENT)
			{
				ComPtr<IXMLDOMNode> node;
				child->get_nextSibling(node.GetAddressOf());
				child = node;
			}
			
			return new XMLElementImpl(child.Get());
		}

		string GetNodeName() const
		{
			_bstr_t tmp;
			if (FAILED(domNode->get_nodeName(tmp.GetAddress())))
				throw XMLException("Failed to retrieve node name");

			string name = ConvertBSTRToString(tmp);
			const auto pos = name.find(':');
			name = (pos == string::npos) ? name : name.substr(pos + 1);
			return name;
		}

		string GetNSUri() const
		{
			_bstr_t tmp;
			string name = "";
			if (FAILED(domNode->get_namespaceURI(tmp.GetAddress())))
				throw XMLException("Failed to retrieve namespace URI");
			if(tmp.GetBSTR())
			{
				name = ConvertBSTRToString(tmp);
			}
			return name;
		}

		string GetNSPrefix() const
		{
			_bstr_t tmp;
			string name = "";
			if (FAILED(domNode->get_prefix(tmp.GetAddress())))
				throw XMLException("Failed to retrieve namespace prefix");
			if(tmp.GetBSTR())
			{
				name = ConvertBSTRToString(tmp);
			}
			return name;
		}

		string GetTextValue() const
		{
			_bstr_t tmp;
			string name = "";
			if (FAILED(domNode->get_text(tmp.GetAddress())))
				throw XMLException("Failed to retrieve text value");
			if (tmp.GetBSTR())
			{
				name = ConvertBSTRToString(tmp);
			}
			return name;
		}

		string ToString(bool incRoot = false) const
		{
			_bstr_t retBSTR;
			if(!incRoot && IsLeafNode())
			{
				return GetTextValue();
			}

			if(incRoot)
			{
				if (FAILED(domNode->get_xml(retBSTR.GetAddress())))
					throw XMLException("Failed to serialize element");
			}
			else
			{
				ComPtr<IXMLDOMNode> child;
				ComPtr<IXMLDOMNodeList> childList;
				if (FAILED(domNode->get_childNodes(&childList)))
					throw XMLException("Failed to serialize element");

				if (FAILED(childList->nextNode(&child)))
					throw ("Failed to serialize element");
				while (child)
				{
					_bstr_t tmp;
					if (FAILED(child->get_xml(tmp.GetAddress())))
						throw ("Failed to serialize element");
					retBSTR += tmp;
					child.Reset();
					if (FAILED(childList->nextNode(&child)))
						throw ("Failed to serialize element");
				}
			}
			string ret = cleanXML(ConvertBSTRToString(retBSTR));
			return ret;
		}	

		void GetAttributes(std::map<string, string>& attribs) const
		{
			_variant_t tmpValue;
			ComPtr<IXMLDOMNamedNodeMap> attributeMap = NULL;
			if (FAILED(domNode->get_attributes(&attributeMap)))
				throw XMLException("Failed to retrieve attributes");
			long len = 0;
			if (FAILED(attributeMap->get_length(&len)))
				throw XMLException("Failed to retrieve attributes");

			for (long i=0; i < len; ++i)
			{
				_bstr_t tmpName;

				ComPtr<IXMLDOMNode> listItem = NULL;
				if (FAILED(attributeMap->get_item(i, &listItem)))
					throw XMLException("Failed to retrieve attributes");
				if (FAILED(listItem->get_nodeName(tmpName.GetAddress())))
					throw XMLException("Failed to retrieve attributes");
				if (FAILED(listItem->get_nodeValue(&tmpValue)))
					throw XMLException("Failed to retrieve attributes");

				attribs[ConvertBSTRToString(tmpName)] = ConvertBSTRToString(tmpValue.bstrVal);
			}	
		}

		string GetAttribValue(const string& name) const
		{
			string ret = "";
			_bstr_t tmpName;
			_variant_t tmpValue;
			ComPtr<IXMLDOMNamedNodeMap> attributeMap = NULL;
			if (FAILED(domNode->get_attributes(attributeMap.GetAddressOf())))
				throw XMLException("Failed to retrieve attributes");

			long len = 0;
			if (FAILED(attributeMap->get_length(&len)))
				throw XMLException("Failed to retrieve attributes");
			for (long i=0; i < len; ++i)
			{
				ComPtr<IXMLDOMNode> listItem = NULL;
				if (FAILED(attributeMap->get_item(i, listItem.GetAddressOf())))
					throw XMLException("Failed to retrieve attributes");
				if (FAILED(listItem->get_nodeName(tmpName.GetAddress())))
					throw XMLException("Failed to retrieve attributes");
				if (FAILED(listItem->get_nodeValue(&tmpValue)))
					throw XMLException("Failed to retrieve attributes");
				if(name.compare(ConvertBSTRToString(tmpName)) == 0)
				{
					ret = ConvertBSTRToString(tmpValue.bstrVal);
					break;
				}
				
			}
			
			return ret;
		}

		void AddAttribValue(const string& name, const string& value)
		{
			ComPtr<IXMLDOMElement> elem;
			if (FAILED(domNode.As(&elem)))
    			throw XMLException("Failed to query IXMLDOMElement interface");
			if (FAILED(elem->setAttribute(_bstr_t(name.c_str()), _variant_t(value.c_str()))))
				throw XMLException("Failed to add Add attribute value");
		}

		void AddNSDefinition(const string& ns, const string* prefix = nullptr)
		{
			string qn = "xmlns";
			if(prefix && !prefix->empty())
			{
				qn.append(":").append(*prefix);
			}

			ComPtr<IXMLDOMAttribute> att;
			ComPtr<IXMLDOMAttribute> dummy;
			if (FAILED(domDoc->createAttribute(_bstr_t(qn.c_str()), att.GetAddressOf())))
				throw XMLException("Failed to add namespace definition");
			if (FAILED(att->put_value(_variant_t(ns.c_str()))))
				throw XMLException("Failed to add namespace definition");
			ComPtr<IXMLDOMElement> elem;
			if (FAILED(domNode.As(&elem)))
    			throw XMLException("Failed to query IXMLDOMElement interface");
			if (FAILED(elem->setAttributeNode(att.Get(), dummy.GetAddressOf())))
				throw XMLException("Failed to add namespace definition");
		}
		

	};

	class XMLDocImpl
	{
	private:
		ComPtr<IXMLDOMElement> rootNode;
		ComPtr<IXMLDOMDocument> doc;
	public:		
		XMLDocImpl(const string& xml, const char*  /*xsdFile = NULL*/):doc(NULL), rootNode(NULL)//doc(NULL), parser(NULL)
		{
			VARIANT_BOOL status;

			HRESULT res = CoCreateInstance(__uuidof(DOMDocument60), NULL,
				CLSCTX_INPROC_SERVER, __uuidof(IXMLDOMDocument), (void**)doc.GetAddressOf()) ||
				FAILED(doc->put_async(VARIANT_FALSE)) ||
				FAILED(doc->put_validateOnParse(VARIANT_FALSE)) ||
				FAILED(doc->put_resolveExternals(VARIANT_FALSE));


			if (res != S_OK)
				throw XMLException("Failed to create XML document");
			const auto ret = doc->loadXML(_bstr_t(xml.c_str()), &status);
			if (ret != S_OK)
				throw XMLException("Failed to create XML document");
				
			if (status == VARIANT_TRUE)
				if (doc->get_documentElement(rootNode.GetAddressOf()) != S_OK)
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

			if (FAILED(doc->createNode(_variant_t(NODE_ELEMENT), _bstr_t(rootName), _bstr_t(uri), (IXMLDOMNode **)rootNode.GetAddressOf())))
				throw XMLException("Failed to create XML document");
			if (FAILED(doc->putref_documentElement(rootNode.Get())))
				throw XMLException("Failed to create XML document");

			_bstr_t docstr;
			if (FAILED(doc->get_xml(docstr.GetAddress())))
				throw XMLException("Failed to create XML document");
	
		}		

		~XMLDocImpl()
		{
			doc.Reset();
		}

		void LoadXml(const char* xmlString)
		{
			VARIANT_BOOL status;
			if (doc->loadXML(_bstr_t(xmlString), &status) != S_OK)
				throw XMLException("Failed to Load XML");
		}

		XMLElement GetRootNode()
		{
			ComPtr<IXMLDOMElement> DOMElement = nullptr;
			if (FAILED(doc->get_documentElement(&DOMElement)))
				throw XMLException("Failed to retrieve root element");
			return XMLElement(new XMLElementImpl((ComPtr<IXMLDOMNode>)DOMElement));
		}

		string GetElementByTagName(const string &name)
		{
			ComPtr<IXMLDOMNodeList> resultList = nullptr;
			
			if (FAILED(doc->getElementsByTagName(_bstr_t(name.c_str()), &resultList)))
				return "";
			long length = 0;
			if (resultList == nullptr || FAILED(resultList->get_length(&length)))
				throw XMLException("Failed to retrieve element");
			if (length == 0)
				return "";
			ComPtr<IXMLDOMNode> listItem = nullptr;
			if (FAILED(resultList->get_item(0, &listItem)))
				throw XMLException("Failed to retrieve element");
			_variant_t value;
			if (FAILED(listItem->get_nodeValue(&value)))
				throw XMLException("Failed to retrieve element");
			return ConvertBSTRToString(value.bstrVal);		
		}

		string ToString(bool /*incVersionStr = false*/)
		{
			
			_bstr_t retBSTR;
			if (FAILED(doc->get_xml(retBSTR.GetAddress())))
				throw XMLException("Failed to serialize XML document");
			string ret = cleanXML(ConvertBSTRToString(retBSTR));
			
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

	void XMLElement::GetAttributes(std::map<string, string>& attribs) const
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
