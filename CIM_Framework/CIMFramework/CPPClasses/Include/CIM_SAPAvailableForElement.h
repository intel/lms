//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_SAPAvailableForElement.h
//
//  Contents:   CIM_SAPAvailableForElement conveys the semantics of a Service Access Point that is available for a ManagedElement. When CIM_SAPAvailableForElement is not instantiated, then the SAP is assumed to be generally available. If instantiated, the SAP is available only for the associated ManagedElements. For example, a device might provide management access through a URL. This association allows the URL to be advertised for the device.
//
//              This file was automatically generated from CIM_SAPAvailableForElement.mof,  version: 2.10.0
//
//----------------------------------------------------------------------------
#ifndef CIM_SAPAVAILABLEFORELEMENT_H
#define CIM_SAPAVAILABLEFORELEMENT_H 1
#include "../../include/CimBase.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	// CIM_SAPAvailableForElement conveys the semantics of a Service Access Point that is available for a ManagedElement. When CIM_SAPAvailableForElement is not instantiated, then the SAP is assumed to be generally available. If instantiated, the SAP is available only for the associated ManagedElements. For example, a device might provide management access through a URL. This association allows the URL to be advertised for the device.
	class CIMFRAMEWORK_API CIM_SAPAvailableForElement  : public CimBase
	{
	public:

		//Default constructor
		CIM_SAPAvailableForElement()
			: CimBase(NULL, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CimBase::SetMetaData(_classMetaData, _metadata, 2);
			}
		}

		//constructor which receives WSMan client
		CIM_SAPAvailableForElement(ICimWsmanClient *client)
			: CimBase(client, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CimBase::SetMetaData(_classMetaData, _metadata, 2);
			}
		}

		//Destructor
		virtual ~CIM_SAPAvailableForElement(){}

		// The "type" information for the object. Gettors only.
		virtual const string& ResourceURI() const { return CLASS_URI; }
		static const string& ClassResourceURI() { return CLASS_URI; }
		virtual const string& XmlNamespace() const { return CLASS_NS; }
		virtual const string& XmlPrefix() const { return CLASS_NS_PREFIX; }
		virtual const string& ObjectType() const { return CLASS_NAME; }
		static const string& ClassObjectType() { return CLASS_NAME; }

		// Class representing CIM_SAPAvailableForElement keys
		class CimKeys : public CimBase::CimKeys
		{
		public:
			// Key, Required, The Service Access Point that is available.
			const CimReference AvailableSAP() const
			{
				CimReference ret;
				TypeConverter::StringToType(GetKey("AvailableSAP"), ret);
				return ret;
			}

			// Key, Required, The Service Access Point that is available.
			void AvailableSAP(const CimReference &value)
			{
				SetOrAddKey("AvailableSAP", TypeConverter::TypeToString(value), true);
			}

			// Key, Required, The ManagedElement for which the SAP is available.
			const CimReference ManagedElement() const
			{
				CimReference ret;
				TypeConverter::StringToType(GetKey("ManagedElement"), ret);
				return ret;
			}

			// Key, Required, The ManagedElement for which the SAP is available.
			void ManagedElement(const CimReference &value)
			{
				SetOrAddKey("ManagedElement", TypeConverter::TypeToString(value), true);
			}

		};

		// class fields declarations

		// Key, Required, The Service Access Point that is available.
		const CimReference AvailableSAP() const;

		// Key, Required, The Service Access Point that is available.
		void AvailableSAP(const CimReference &value); 


		// Key, Required, The ManagedElement for which the SAP is available.
		const CimReference ManagedElement() const;

		// Key, Required, The ManagedElement for which the SAP is available.
		void ManagedElement(const CimReference &value); 


		 // Function used by the factory
		static CimBase *CreateFromCimObject(const CimObject &object);

		static vector<shared_ptr<CIM_SAPAvailableForElement> > Enumerate(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		// Overloaded delete which supplies the internal resourceURI
		static void Delete(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		using CimBase::Delete;

	protected:
		 // Protected constructor to be used by derived classes
		CIM_SAPAvailableForElement(ICimWsmanClient *client, const string &class_name,
			const string &class_ns, const string &prefix, const string &uri): CimBase(client, class_name, class_ns, prefix, uri)
		{
			if(_classMetaData.size() == 0)
			{
				CimBase::SetMetaData(_classMetaData, _metadata, 2);
			}
		}
		 // Protected constructor which receives CimObject
		CIM_SAPAvailableForElement(const CimObject &object)
			: CimBase(object)
		{
			if(_classMetaData.size() == 0)
			{
				CimBase::SetMetaData(_classMetaData, _metadata, 2);
			}
		}
		// Called by derived classes
		void SetMetaData(vector<CimFieldAttribute>& childMetaData)
		{
			CimBase::SetMetaData(childMetaData, _metadata, 2);
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
#endif // CIM_SAPAVAILABLEFORELEMENT_H
