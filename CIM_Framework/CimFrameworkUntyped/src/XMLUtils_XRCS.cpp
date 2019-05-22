//----------------------------------------------------------------------------
//
// Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       
//
//  Contents:   
//
//----------------------------------------------------------------------------

#include "XMLUtils.h"
//#include "RWLock.h"
#include <xercesc/util/PlatformUtils.hpp>
#include <xercesc/util/XMLString.hpp>
#include <xercesc/dom/DOM.hpp>
#include <xercesc/dom/DOMLSSerializer.hpp>
#include <xercesc/dom/DOMImplementationRegistry.hpp>
#include <xercesc/dom/DOMImplementationLS.hpp>
#include <xercesc/util/OutOfMemoryException.hpp>
#include <xercesc/framework/MemBufInputSource.hpp>
#include <xercesc/dom/DOMImplementation.hpp>
#include <xercesc/parsers/XercesDOMParser.hpp>
#include <xercesc/util/XMLUni.hpp>
#include <xercesc/framework/MemBufFormatTarget.hpp>

XERCES_CPP_NAMESPACE_USE

namespace Intel
{
namespace Manageability
{
namespace XMLUtils 
{
	bool   _CimXMLUtilsInitialized = false;
	bool   _CimXMLValidateSchema = false;
	bool   _CimXMLDisableEntities = true;
	bool   _CimValidateSchemaFromFile = false;
	string _CimXSDPath;
  //RWLock _initializationLock;
  //RWLock _xmlStringLock;
	// local utility function 
	string CIMXMLCreateErrMsg(const string& msg,
		const char* what = NULL)
	{
		string ret = msg;
		if(what)
		{
			ret.append(": \n").append(what);
		}
		return ret;
   }

	// the following utility class was copied from xerces "CreateDomDocument" sample code

	// ---------------------------------------------------------------------------
	//  This is a simple class that lets us do easy (though not terribly efficient)
	//  trancoding of char* data to XMLCh data.
	// ---------------------------------------------------------------------------
	class XStr
	{
	public :

		const XMLCh* X(const char* const toTranscode)
		{
			return setfUnicodeForm(toTranscode);
		};

		XStr(): fUnicodeForm(NULL)
		{};

		~XStr()
		{
			if (NULL != fUnicodeForm)
			{
			//	_xmlStringLock.acquire();
				XMLString::release(&fUnicodeForm);
			//	_xmlStringLock.release();
				fUnicodeForm = NULL;
			}
		}

	private :
		// -----------------------------------------------------------------------
		//  Constructors and Destructor
		// -----------------------------------------------------------------------
		XMLCh * setfUnicodeForm(const char* const toTranscode)
		{
			//_xmlStringLock.acquire();
			if (NULL != fUnicodeForm)
			{
			//	XMLString::release(&fUnicodeForm);
				fUnicodeForm = NULL;
			}
			// Call the private transcoding method
			fUnicodeForm = XMLString::transcode(toTranscode);
			//_xmlStringLock.release();
			return fUnicodeForm;
		}


		// -----------------------------------------------------------------------
		//  Private data members
		//
		//  fUnicodeForm
		//      This is the Unicode XMLCh format of the string.
		// -----------------------------------------------------------------------
		XMLCh*   fUnicodeForm;
	};

	// ---------------------------------------------------------------------------
	//  This is a simple class that lets us do easy (though not terribly efficient)
	//  trancoding of to XMLCh data to char* data.
	// ---------------------------------------------------------------------------
	class YStr
	{
	public :
		
		YStr(): fMultibyteForm(NULL)
		{};
		
		const char * Y(const XMLCh* const toTranscode)
		{
			return setfMultibyteForm(toTranscode);
		}

		~YStr()
		{
			if (NULL != fMultibyteForm)
			{
			//	_xmlStringLock.acquire();
				XMLString::release(&fMultibyteForm);
			//	_xmlStringLock.release();
				fMultibyteForm = NULL;
			}
		}
	private :
		// -----------------------------------------------------------------------
		//  Constructors and Destructor
		// -----------------------------------------------------------------------
		char * setfMultibyteForm(const XMLCh* const toTranscode)
		{
			// Call the private transcoding method
		//	_xmlStringLock.acquire();
			if (NULL != fMultibyteForm)
			{
		//		XMLString::release(&fMultibyteForm);
				fMultibyteForm = NULL;
			}				
			fMultibyteForm = XMLString::transcode(toTranscode);
		//	_xmlStringLock.release();
			return fMultibyteForm;
		}

		// -----------------------------------------------------------------------
		//  Private data members
		//
		//  fMultibyteForm
		//      This is the multibyteForm  format of the string.
		// -----------------------------------------------------------------------
		char*   fMultibyteForm;
	};


	class XMLElementImpl
	{
		friend class XMLDocImpl;
	private:
		DOMElement* domElement;
		DOMDocument* domDoc;
	public:
		XMLElementImpl(DOMElement* element)
		{
			domElement = element;
			try
			{
				domDoc = domElement->getOwnerDocument();
			}
			catch (XMLException& e)
			{
				throw XMLException(CIMXMLCreateErrMsg("Failed to create XMLElement", e.what()));
			}
			catch (DOMException& e)
			{
				throw XMLException(CIMXMLCreateErrMsg("Failed to create XMLElement", YStr().Y(e.getMessage())));
			}			
		}

		XMLElementImpl(const XMLElementImpl& element)
		{
			domElement = element.domElement;
			domDoc = element.domDoc;
		}

		~XMLElementImpl()
		{
			domElement = NULL;
			domDoc = NULL;
		}

		XMLElementImpl&  operator=(const XMLElementImpl &other )
		{
			if (this == &other)
				return *this;
			domElement = other.domElement;
			domDoc = other.domDoc;
			return *this;
		}


		XMLElementImpl* CreateChildNode(const string& nodeName,
			const string& ns,
			const string& prefix,
			const string* text = NULL)
		{
			try
			{
				XStr xstr1, xstr2, xstr3;
				string qn = !prefix.empty() ?
					prefix + ":" + nodeName : nodeName;
				DOMElement* elem = domDoc->createElementNS(
					!ns.empty() ? xstr1.X(ns.c_str()) : NULL,
					xstr2.X(qn.c_str()));
				domElement->appendChild(elem);
				if(text)
				{
					DOMText* val = domDoc->createTextNode(xstr3.X(text->c_str()));
					elem->appendChild(val);
				}
				return new XMLElementImpl(elem);
			}
			catch (XMLException& e)
			{
				throw XMLException(CIMXMLCreateErrMsg("Failed to create XMLElement", e.what()));
			}
			catch (DOMException& e)
			{
				throw XMLException(CIMXMLCreateErrMsg("Failed to create XMLElement", YStr().Y(e.getMessage())));
			}			
		}

		void CreateLeafNode(const string& nodeName,
			const string& ns,
			const string& prefix,
			const string& nodeValue)
		{/*
			try
			{
				string qn = !prefix.empty() ?
					prefix + ":" + nodeName : nodeName;
				DOMElement* elem = domDoc->createElementNS(
					!ns.empty() ? X(ns.c_str()) : NULL,
					X(qn.c_str()));
				domElement->appendChild(elem);
				DOMText* val = domDoc->createTextNode(X(nodeValue.c_str()));
				elem->appendChild(val);
			}
			catch (XMLException& e)
			{
				throw XMLException(CIMXMLCreateErrMsg("Failed to create XMLElement", e.what()));
			}
			catch (DOMException& e)
			{
				throw XMLException(CIMXMLCreateErrMsg("Failed to create XMLElement",Y(e.getMessage())).c_str());
			}
			*/
			CreateAttributedLeafNode(nodeName, "", "", ns, prefix, nodeValue);
		}	

		void CreateAttributedLeafNode(const string& nodeName,
			const string& attribute,
			const string& attributeValue,
			const string& ns,
			const string& prefix,
			const string& nodeValue)
		{
			try
			{
				XStr xstr1, xstr2, xstr3;
				string qn = !prefix.empty() ?
					prefix + ":" + nodeName : nodeName;
				DOMElement* elem = domDoc->createElementNS(
					!ns.empty() ? xstr1.X(ns.c_str()) : NULL,
					xstr2.X(qn.c_str()));
				domElement->appendChild(elem);
				DOMText* val = domDoc->createTextNode(xstr3.X(nodeValue.c_str()));
				elem->appendChild(val);
				
			}
			catch (XMLException& e)
			{
				throw XMLException(CIMXMLCreateErrMsg("Failed to create XMLElement", e.what()));
			}
			catch (DOMException& e)
			{
				throw XMLException(CIMXMLCreateErrMsg("Failed to create XMLElement", YStr().Y(e.getMessage())));
			}			
		}		

		void AddText(const string& nodeValue)
		{
			try
			{
				XStr xstr;
				DOMText* val = domDoc->createTextNode(xstr.X(nodeValue.c_str()));
				domElement->appendChild(val);
			}
			catch (XMLException& e)
			{
				throw XMLException(CIMXMLCreateErrMsg("Failed to add text node", e.what()));
			}
			catch (DOMException& e)
			{
				throw XMLException(CIMXMLCreateErrMsg("Failed to add text node", YStr().Y(e.getMessage())));
			}			
		}

		bool HasNextSibling() const
		{
			try
			{
				DOMNode* tmp = domElement->getNextSibling();
				while(tmp != NULL && tmp->getNodeType() != DOMNode::ELEMENT_NODE)
				{
					tmp = tmp->getNextSibling();
				}
				return (tmp != NULL);
			}
			catch (XMLException& e)
			{
				throw XMLException(CIMXMLCreateErrMsg("Failed to retrieve sibling", e.what()));
			}
			catch (DOMException& e)
			{
				throw XMLException(CIMXMLCreateErrMsg("Failed to retrieve sibling", YStr().Y(e.getMessage())));
			}			
		}

		XMLElementImpl* GetNextSibling() const
		{
			try
			{
				DOMNode* tmp = domElement->getNextSibling();
				while(tmp != NULL && tmp->getNodeType() != DOMNode::ELEMENT_NODE)
				{
					tmp = tmp->getNextSibling();
				}
				if (tmp == NULL)
					return NULL;
				DOMElement* de = dynamic_cast<DOMElement*>(tmp);
				return (NULL == de) ? NULL: new XMLElementImpl(de);
			}
			catch (XMLException& e)
			{
				throw XMLException(CIMXMLCreateErrMsg("Failed to retrieve sibling", e.what()));
			}
			catch (DOMException& e)
			{
				throw XMLException(CIMXMLCreateErrMsg("Failed to retrieve sibling", YStr().Y(e.getMessage())));
			}			
		}

		bool HasChildren() const
		{
			try
			{
				if(!domElement->hasChildNodes())
				{
					return false;
				}

				DOMNode* child = domElement->getFirstChild(); 
				while(child && child->getNodeType() != DOMNode::ELEMENT_NODE)
				{
					child = child->getNextSibling();
				}
				return (child != NULL);
			}
			catch (XMLException& e)
			{
				throw XMLException(CIMXMLCreateErrMsg("Failed to retrieve children", e.what()));
			}
			catch (DOMException& e)
			{
				throw XMLException(CIMXMLCreateErrMsg("Failed to retrieve children", YStr().Y(e.getMessage())));
			}			
		}

		bool IsLeafNode() const
		{
			return !HasChildren();
		}

		XMLElementImpl* GetFirstChild() const
		{
			try
			{
				DOMNode* child = domElement->getFirstChild(); 
				while(child && child->getNodeType() != DOMNode::ELEMENT_NODE)
				{
					child = child->getNextSibling();
				}
				if (child == NULL)
					return NULL;
				DOMElement* de = dynamic_cast<DOMElement*>(child);
				return (NULL == de) ? NULL: new XMLElementImpl(de);
			}
			catch (XMLException& e)
			{
				throw XMLException(CIMXMLCreateErrMsg("Failed to retrieve children", e.what()));
			}
			catch (DOMException& e)
			{
				throw XMLException(CIMXMLCreateErrMsg("Failed to retrieve children", YStr().Y(e.getMessage())));
			}			
		}

		string GetNodeName() const
		{
			try
			{
				return string(YStr().Y(domElement->getLocalName()));
			}
			catch (XMLException& e)
			{
				throw XMLException(CIMXMLCreateErrMsg("Failed to retrieve name", e.what()));
			}
			catch (DOMException& e)
			{
				throw XMLException(CIMXMLCreateErrMsg("Failed to retrieve name", YStr().Y(e.getMessage())));
			}			
		}

		string GetNSUri() const
		{
			try
			{
				return string(YStr().Y(domElement->getNamespaceURI()));
			}
			catch (XMLException& e)
			{
				throw XMLException(CIMXMLCreateErrMsg("Failed to retrieve value", e.what()));
			}
			catch (DOMException& e)
			{
				throw XMLException(CIMXMLCreateErrMsg("Failed to retrieve value", YStr().Y(e.getMessage())));
			}			
		}

		string GetNSPrefix() const
		{
			YStr ystr;
			try
			{
				const char * res = ystr.Y(domElement->getPrefix());
				if (NULL == res)
					return string();
				return res;
			}
			catch (XMLException& e)
			{
				throw XMLException(CIMXMLCreateErrMsg("Failed to retrieve value", e.what()));
			}
			catch (DOMException& e)
			{
				throw XMLException(CIMXMLCreateErrMsg("Failed to retrieve value", ystr.Y(e.getMessage())));
			}		
		}

		string GetTextValue() const
		{
			try
			{
				return string(YStr().Y(domElement->getTextContent()));
			}
			catch (XMLException& e)
			{
				throw XMLException(CIMXMLCreateErrMsg("Failed to retrieve value", e.what()));
			}
			catch (DOMException& e)
			{
				throw XMLException(CIMXMLCreateErrMsg("Failed to retrieve value", YStr().Y(e.getMessage())));
			}			
		}

		string ToString(bool incRoot = false) const
		{
			if(!incRoot && IsLeafNode())
			{
				return GetTextValue();
			}
			string xml = "";
			DOMLSSerializer* writer = NULL;
			DOMLSOutput* theOutputDesc = NULL;
			MemBufFormatTarget* dest = NULL;
			try
			{
				XStr xstr1, xstr2;
				DOMImplementation* impl =  DOMImplementationRegistry::getDOMImplementation(xstr1.X("LS"));							
				writer = ((DOMImplementationLS*)impl)->createLSSerializer();
				if(writer)
				{
					theOutputDesc = ((DOMImplementationLS*)impl)->createLSOutput();
					dest = new MemBufFormatTarget();
					theOutputDesc->setEncoding(xstr2.X("UTF-8"));
					theOutputDesc->setByteStream(dest);
					if(incRoot)
					{
						writer->write(domElement, theOutputDesc);

						xml = (char*)(dest->getRawBuffer());
					}
					else
					{
						for(DOMNode* child = domElement->getFirstChild(); child != NULL; child = child->getNextSibling())
						{
							if(child->getNodeType() == DOMNode::ELEMENT_NODE)
							{
								writer->write(child, theOutputDesc);
							}									    
						}
						xml += (char*)(dest->getRawBuffer());
					}
				}
			}
			catch (XMLException& e)
			{
				if(writer)
				{
					writer->release();
				}
				if(dest)
				{
					delete dest;
				}
				if(theOutputDesc)
				{
					theOutputDesc->release();
				}
				throw XMLException(CIMXMLCreateErrMsg("Failed to serialize element", e.what()));
			}
			catch (DOMException& e)
			{
				if(writer)
				{
					writer->release();
				}
				if(dest)
				{
					delete dest;
				}
				if(theOutputDesc)
				{
					theOutputDesc->release();
				}
				throw XMLException(CIMXMLCreateErrMsg("Failed to serialize element", YStr().Y(e.getMessage())));
			}						

			if(writer)
			{
				writer->release();
			}
			if(dest)
			{
				delete dest;
			}
			if(theOutputDesc)
			{
				theOutputDesc->release();
			}
			return xml;
		}	

		void GetAttributes(map<string, string>& attribs) const
		{
			YStr ystr1, ystr2;
			try
			{
				if(domElement->hasAttributes())
				{
					DOMNamedNodeMap* NodeMap = domElement->getAttributes();
					for (XMLSize_t i=0; i < NodeMap->getLength(); ++i)
					{
						attribs[ystr1.Y(NodeMap->item(i)->getNodeName())] = 
							ystr2.Y(NodeMap->item(i)->getNodeValue());
					}
				}
			}
			catch (XMLException& e)
			{
				throw XMLException(CIMXMLCreateErrMsg("Failed to retrieve attributes", e.what()));
			}
			catch (DOMException& e)
			{
				throw XMLException(CIMXMLCreateErrMsg("Failed to retrieve attributes", ystr2.Y(e.getMessage())));
			}			
		}

		string GetAttribValue(const string& name) const
		{
			YStr ystr1, ystr2;
			try
			{
				string ret = "";
				if(domElement->hasAttributes())
				{
					DOMNamedNodeMap* NodeMap = domElement->getAttributes();
					for (XMLSize_t i=0; i < NodeMap->getLength(); ++i)
					{
						if(name.compare(ystr1.Y(NodeMap->item(i)->getNodeName())) == 0)
						{
							ret = ystr2.Y(NodeMap->item(i)->getNodeValue());
							break;
						}
					}
				}
				return ret;
			}
			catch (XMLException& e)
			{
				throw XMLException(CIMXMLCreateErrMsg("Failed to retrieve attributes", e.what()));
			}
			catch (DOMException& e)
			{
				throw XMLException(CIMXMLCreateErrMsg("Failed to retrieve attributes",ystr2.Y(e.getMessage())));
			}			
		}

		void AddAttribValue(const string& name, const string& value)
		{
			try
			{
				XStr xstr;
				domElement->setAttribute(xstr.X(name.c_str()), xstr.X(value.c_str()));
			}
			catch (XMLException& e)
			{
				throw XMLException(CIMXMLCreateErrMsg("Failed to add attribute",e.what()));
			}
			catch (DOMException& e)
			{
				throw XMLException(CIMXMLCreateErrMsg("Failed to add attribute",YStr().Y(e.getMessage())));
			}			
		}

		void AddNSDefinition(const string& ns, const string* prefix = NULL)
		{
			string qn = "xmlns";
			if(prefix && !prefix->empty())
			{
				qn.append(":").append(*prefix);
			}
			try
			{
				XStr xstr1, xstr2, xstr3;
				DOMAttr* att = domDoc->createAttributeNS(xstr1.X("http://www.w3.org/2000/xmlns/"), xstr2.X(qn.c_str()));
				att->setNodeValue(xstr3.X(ns.c_str()));
				domElement->setAttributeNode(att);
			}
			catch (XMLException& e)
			{
				throw XMLException(CIMXMLCreateErrMsg("Failed to add attribute",e.what()));
			}
			catch (DOMException& e)
			{
				throw XMLException(CIMXMLCreateErrMsg("Failed to add attribute",YStr().Y(e.getMessage())));
			}			
		}
		void AppendNode(const XMLElement &innerElem)
		{
			if((NULL == domElement) || (NULL == innerElem.impl))
			{
				throw XMLException(CIMXMLCreateErrMsg("Failed to add attribute, NULL input", NULL).c_str());
			}
			try
			{
				DOMNode* appendedElem = domDoc->importNode(innerElem.impl->domElement,true);
				domElement->appendChild(appendedElem);
			}
			catch (DOMException& e)
			{
				throw XMLException(CIMXMLCreateErrMsg("Failed to add attribute",YStr().Y(e.getMessage())));
			}	
		}

	};

	class XMLDocImpl
	{
	private:
		DOMDocument* doc;
		XercesDOMParser *parser;
		bool parsed;
	public:		
		XMLDocImpl(const string& xml, const char* xsdFile = NULL):doc(NULL), parser(NULL)
		{
			try
			{
				parsed = true;
				MemBufInputSource source((const XMLByte*const) xml.c_str(),
					xml.length(),"ID");
				parser = new XercesDOMParser;
				parser->setDoNamespaces(true);
				if (_CimXMLDisableEntities)
				{
					parser->setDisableDefaultEntityResolution(true);
					parser->setEntityResolver(NULL);
					parser->setSkipDTDValidation(true);
				}
				if(_CimXMLValidateSchema)
				{
					parser->setDoSchema(true);
				}
				if(_CimValidateSchemaFromFile && xsdFile)
				{
					string fullPath = _CimXSDPath + xsdFile;
					parser->setExternalNoNamespaceSchemaLocation(fullPath.c_str());
				}
				parser->parse(source);
				doc = parser->getDocument();
			}
			catch (XMLException& e)
			{
				if(parser) delete parser;
				throw XMLException(CIMXMLCreateErrMsg("Failed to create xml document",e.what()));
			}
			catch (DOMException& e)
			{
				if(parser) delete parser;
				throw XMLException(CIMXMLCreateErrMsg("Failed to create xml document",YStr().Y(e.getMessage())));
			}			
		}

		XMLDocImpl(const char* rootName,
			const char* uri,
			const char* prefix):doc(NULL), parser(NULL)
		{
			parsed = false;
			try
			{
				XStr xstr1, xstr2, xstr3;
				const char* ln = (rootName && strcmp(rootName, "") != 0) ? rootName : "root";
				string qn = prefix && strcmp(prefix, "") != 0 ? string(prefix).append(":").append(ln) : string(ln);
				DOMImplementation* impl =  DOMImplementationRegistry::getDOMImplementation(xstr1.X("LS"));
				doc = impl->createDocument(uri && strcmp(uri, "") ? xstr2.X(uri) : NULL,	xstr3.X(qn.c_str()), 0);				
			}

			catch (XMLException& e)
			{
				throw XMLException(CIMXMLCreateErrMsg("Failed to create xml document",e.what()));
			}
			catch (DOMException& e)
			{
				throw XMLException(CIMXMLCreateErrMsg("Failed to create xml document",YStr().Y(e.getMessage())));
			}			
		}

		~XMLDocImpl()
		{
			if(parsed && parser)
			{
				delete parser;
				parser = NULL;
			}
			else if(doc)
			{
				doc->release();
				doc = NULL;
			}
		}

		XMLElement GetRootNode()
		{
			try
			{
				DOMElement* rootElem = doc->getDocumentElement();
				return XMLElement(new XMLElementImpl(rootElem));
			}
			catch (XMLException& e)
			{
				throw XMLException(CIMXMLCreateErrMsg("Failed to retrieve root element",e.what()));
			}
			catch (DOMException& e)
			{
				throw XMLException(CIMXMLCreateErrMsg("Failed to retrieve root element",YStr().Y(e.getMessage())));
			}					
		}

		string GetElementByTagName(const string &name)
		{
			XStr xstr1;
			DOMNodeList *list = doc->getElementsByTagName(xstr1.X(name.c_str()));
			if (list == NULL)
				return string();
			int a = list->getLength();
			if (a <= 0)
				return string();
			DOMNode *item = list->item(0);
			if (item == NULL)
				return string();
			return string(YStr().Y((item->getNodeValue())));
		}

		string ToString(bool incVersionStr = false)
		{
			string xml;
			DOMLSSerializer* writer = NULL;
			DOMLSOutput* theOutputDesc = NULL;
			MemBufFormatTarget* dest = NULL;
			try
			{
				XStr xstr1, xstr2;
				DOMImplementation* impl =  DOMImplementationRegistry::getDOMImplementation(xstr1.X("LS"));							
				writer = ((DOMImplementationLS*)impl)->createLSSerializer();
				if(writer)
				{
					theOutputDesc = ((DOMImplementationLS*)impl)->createLSOutput();
					dest = new MemBufFormatTarget();
					theOutputDesc->setEncoding(xstr2.X("UTF-8"));
					theOutputDesc->setByteStream(dest);
					if(!incVersionStr)
					{
						DOMConfiguration* dc = writer->getDomConfig();
						dc->setParameter(XMLUni::fgDOMXMLDeclaration, false);
					}
					writer->write(doc, theOutputDesc);
					xml = (char*)(dest->getRawBuffer());
				}
			}
			catch (XMLException& e)
			{
				if(writer)
				{
					writer->release();
				}
				if(dest)
				{
					delete dest;
				}
				if(theOutputDesc)
				{
					theOutputDesc->release();
				}
				throw XMLException(CIMXMLCreateErrMsg("Failed to serialize XML document",e.what()));
			}
			catch (DOMException& e)
			{
				if(writer)
				{
					writer->release();
				}
				if(dest)
				{
					delete dest;
				}
				if(theOutputDesc)
				{
					theOutputDesc->release();
				}
				throw XMLException(CIMXMLCreateErrMsg("Failed to serialize XML document",YStr().Y(e.getMessage())));
			}						
			if(writer)
			{
				writer->release();
			}
			if(dest)
			{
				delete dest;
			}
			if(theOutputDesc)
			{
				theOutputDesc->release();
			}
			return xml;
		}
	private:
		XMLDocImpl(const XMLDocImpl& other){}
		XMLDocImpl operator=(const XMLDocImpl& other);
	};


	void InitXMLLibrary(const bool enableSchemaValidation,
											  const bool validateFromFile,
											  const string& xsdPath)
	{
		if(_CimXMLUtilsInitialized)
		{
			throw XMLException("An attempt was made to initialize the XML library, after it was already initialized..");
		}
		//_initializationLock.acquire();
		if (!_CimXMLUtilsInitialized) {
			XMLPlatformUtils::Initialize();
			_CimXMLUtilsInitialized = true;
		}
		if(enableSchemaValidation)
		{
			_CimXMLValidateSchema = true;
		}
		else
		{
			_CimXMLValidateSchema = false;
		}

		if(validateFromFile)
		{
			_CimValidateSchemaFromFile = true;
			_CimXSDPath = xsdPath;
		}
		else
		{
			_CimValidateSchemaFromFile = false;
		}
		//_initializationLock.release();
	}

	void TerminateXMLLibrary()
	{
		//_initializationLock.acquire();
		if (_CimXMLUtilsInitialized) {
			XMLPlatformUtils::Terminate();
			_CimXMLUtilsInitialized = false;
		}
		//_initializationLock.release();
	}

	bool IsXMLLibraryInit()
	{
		return _CimXMLUtilsInitialized;
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
		if (this == &other)
			return *this;
		if(impl)
		{
			delete impl;
			impl = new XMLElementImpl(*(other.impl));
		}
		return *this;
	}

	XMLElement::~XMLElement()
	{
		delete impl;
		impl = NULL;
	}

	
	/*XMLElement XMLElement::CreateChildNode(const string& nodeName,
																 const string& ns,
																 const string& prefix,
																 const string* text)
	{
		return XMLElement(impl->CreateChildNode(nodeName, ns, prefix, text));
	}*/

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

/*
	void XMLElement::AddText(const string& nodeValue)
	{
		impl->AddText(nodeValue);
	}
*/

	bool XMLElement::HasNextSibling() const
	{
		return impl->HasNextSibling();
	}

	XMLElement XMLElement::GetNextSibling() const
	{
		return XMLElement(impl->GetNextSibling());
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
		return XMLElement(impl->GetFirstChild());
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
		if(!_CimXMLUtilsInitialized)
		{
			throw XMLException("XML library was not initialized.");
		}
		impl = new XMLDocImpl(xml, xsdFile);
	}

	XMLDoc::XMLDoc(const char* rootName,
										 const char* uri,
										 const char* prefix)
	{
		if(!_CimXMLUtilsInitialized)
		{
			throw XMLException("XML library was not initialized.");
		}
		impl = new XMLDocImpl(rootName, uri, prefix);
	}

	XMLDoc::~XMLDoc()
	{
		if(impl)
		{
			delete impl;
			impl = NULL;
		}
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

