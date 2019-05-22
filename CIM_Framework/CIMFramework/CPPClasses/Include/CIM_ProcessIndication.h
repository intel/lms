//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_ProcessIndication.h
//
//  Contents:   An abstract superclass for specialized Indication classes, addressing specific changes and alerts published by providers and instrumentation. Subclasses include AlertIndication (with properties such as PerceivedSeverity and ProbableCause), and SNMPTrapIndication (which recasts Traps as CIM indications).
//
//              This file was automatically generated from CIM_ProcessIndication.mof,  version: 2.29.0
//
//----------------------------------------------------------------------------
#ifndef CIM_PROCESSINDICATION_H
#define CIM_PROCESSINDICATION_H 1
#include "CIM_Indication.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	// An abstract superclass for specialized Indication classes, addressing specific changes and alerts published by providers and instrumentation. Subclasses include AlertIndication (with properties such as PerceivedSeverity and ProbableCause), and SNMPTrapIndication (which recasts Traps as CIM indications).
	class CIMFRAMEWORK_API CIM_ProcessIndication  : public CIM_Indication
	{
	public:

		//Default constructor
		CIM_ProcessIndication()
			: CIM_Indication(NULL, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				_classMetaData = CIM_Indication::GetMetaData();
			}
		}

		//constructor which receives WSMan client
		CIM_ProcessIndication(ICimWsmanClient *client)
			: CIM_Indication(client, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				_classMetaData = CIM_Indication::GetMetaData();
			}
		}

		//Destructor
		virtual ~CIM_ProcessIndication(){}

		// The "type" information for the object. Gettors only.
		virtual const string& ResourceURI() const { return CLASS_URI; }
		static const string& ClassResourceURI() { return CLASS_URI; }
		virtual const string& XmlNamespace() const { return CLASS_NS; }
		virtual const string& XmlPrefix() const { return CLASS_NS_PREFIX; }
		virtual const string& ObjectType() const { return CLASS_NAME; }
		static const string& ClassObjectType() { return CLASS_NAME; }

		// Class representing CIM_ProcessIndication keys
		class CimKeys : public CIM_Indication::CimKeys
		{
		public:
		};
		 // Function used by the factory
		static CimBase *CreateFromCimObject(const CimObject &object);

		static vector<shared_ptr<CIM_ProcessIndication> > Enumerate(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		// Overloaded delete which supplies the internal resourceURI
		static void Delete(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		using CimBase::Delete;

	protected:
		 // Protected constructor to be used by derived classes
		CIM_ProcessIndication(ICimWsmanClient *client, const string &class_name,
			const string &class_ns, const string &prefix, const string &uri): CIM_Indication(client, class_name, class_ns, prefix, uri)
		{
			if(_classMetaData.size() == 0)
			{
				_classMetaData = CIM_Indication::GetMetaData();
			}
		}
		 // Protected constructor which receives CimObject
		CIM_ProcessIndication(const CimObject &object)
			: CIM_Indication(object)
		{
			if(_classMetaData.size() == 0)
			{
				_classMetaData = CIM_Indication::GetMetaData();
			}
		}
		// Called by derived classes
		void SetMetaData(vector<CimFieldAttribute>& childMetaData)
		{
			CIM_Indication::SetMetaData(childMetaData);
		}
		const vector<CimFieldAttribute> &GetMetaData() const;
	private:
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
#endif // CIM_PROCESSINDICATION_H
