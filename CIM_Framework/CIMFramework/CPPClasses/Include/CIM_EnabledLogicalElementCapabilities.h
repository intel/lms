//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_EnabledLogicalElementCapabilities.h
//
//  Contents:   EnabledLogicalElementCapabilities describes the capabilities supported for changing the state of the associated EnabledLogicalElement.
//
//              This file was automatically generated from CIM_EnabledLogicalElementCapabilities.mof,  version: 2.22.0
//
//----------------------------------------------------------------------------
#ifndef CIM_ENABLEDLOGICALELEMENTCAPABILITIES_H
#define CIM_ENABLEDLOGICALELEMENTCAPABILITIES_H 1
#include "CIM_Capabilities.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	// EnabledLogicalElementCapabilities describes the capabilities supported for changing the state of the associated EnabledLogicalElement.
	class CIMFRAMEWORK_API CIM_EnabledLogicalElementCapabilities  : public CIM_Capabilities
	{
	public:

		//Default constructor
		CIM_EnabledLogicalElementCapabilities()
			: CIM_Capabilities(NULL, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_Capabilities::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 4);
			}
		}

		//constructor which receives WSMan client
		CIM_EnabledLogicalElementCapabilities(ICimWsmanClient *client)
			: CIM_Capabilities(client, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_Capabilities::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 4);
			}
		}

		//Destructor
		virtual ~CIM_EnabledLogicalElementCapabilities(){}

		// The "type" information for the object. Gettors only.
		virtual const string& ResourceURI() const { return CLASS_URI; }
		static const string& ClassResourceURI() { return CLASS_URI; }
		virtual const string& XmlNamespace() const { return CLASS_NS; }
		virtual const string& XmlPrefix() const { return CLASS_NS_PREFIX; }
		virtual const string& ObjectType() const { return CLASS_NAME; }
		static const string& ClassObjectType() { return CLASS_NAME; }

		// Class representing CIM_EnabledLogicalElementCapabilities keys
		class CimKeys : public CIM_Capabilities::CimKeys
		{
		public:
		};

		// class fields declarations

		// Optional, Boolean indicating whether the ElementName can be modified.
		const bool ElementNameEditSupported() const;

		// Optional, Boolean indicating whether the ElementName can be modified.
		void ElementNameEditSupported(const bool value); 

		// Is true if the field ElementNameEditSupported exists in the current object, otherwise is false.
		bool ElementNameEditSupportedExists() const;

		// Remove ElementNameEditSupported field.
		void RemoveElementNameEditSupported(); 

		// Optional, Maximum supported ElementName length.
		const unsigned short MaxElementNameLen() const;

		// Optional, Maximum supported ElementName length.
		void MaxElementNameLen(const unsigned short value); 

		// Is true if the field MaxElementNameLen exists in the current object, otherwise is false.
		bool MaxElementNameLenExists() const;

		// Remove MaxElementNameLen field.
		void RemoveMaxElementNameLen(); 

		// Optional, RequestedStatesSupported indicates the possible states that can be requested when using the method RequestStateChange on the EnabledLogicalElement.
		const vector<unsigned short> RequestedStatesSupported() const;

		// Optional, RequestedStatesSupported indicates the possible states that can be requested when using the method RequestStateChange on the EnabledLogicalElement.
		void RequestedStatesSupported(const vector<unsigned short> &value); 

		// Is true if the field RequestedStatesSupported exists in the current object, otherwise is false.
		bool RequestedStatesSupportedExists() const;

		// Remove RequestedStatesSupported field.
		void RemoveRequestedStatesSupported(); 

		// Optional, This string expresses the restrictions on ElementName.The mask is expressed as a regular expression.See DMTF standard ABNF with the Management Profile Specification Usage Guide, appendix C for the regular expression syntax permitted. 
		// Since the ElementNameMask can describe the maximum length of the ElementName,any length defined in the regexp is in addition to the restriction defined in MaxElementNameLen (causing the smaller value to be the maximum length) The ElementName value satisfies the restriction, if and only if it matches the regular expression
		const string ElementNameMask() const;

		// Optional, This string expresses the restrictions on ElementName.The mask is expressed as a regular expression.See DMTF standard ABNF with the Management Profile Specification Usage Guide, appendix C for the regular expression syntax permitted. 
		// Since the ElementNameMask can describe the maximum length of the ElementName,any length defined in the regexp is in addition to the restriction defined in MaxElementNameLen (causing the smaller value to be the maximum length) The ElementName value satisfies the restriction, if and only if it matches the regular expression
		void ElementNameMask(const string &value); 

		// Is true if the field ElementNameMask exists in the current object, otherwise is false.
		bool ElementNameMaskExists() const;

		// Remove ElementNameMask field.
		void RemoveElementNameMask(); 

		 // Function used by the factory
		static CimBase *CreateFromCimObject(const CimObject &object);

		static vector<shared_ptr<CIM_EnabledLogicalElementCapabilities> > Enumerate(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		// Overloaded delete which supplies the internal resourceURI
		static void Delete(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		using CimBase::Delete;

	protected:
		 // Protected constructor to be used by derived classes
		CIM_EnabledLogicalElementCapabilities(ICimWsmanClient *client, const string &class_name,
			const string &class_ns, const string &prefix, const string &uri): CIM_Capabilities(client, class_name, class_ns, prefix, uri)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_Capabilities::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 4);
			}
		}
		 // Protected constructor which receives CimObject
		CIM_EnabledLogicalElementCapabilities(const CimObject &object)
			: CIM_Capabilities(object)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_Capabilities::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 4);
			}
		}
		// Called by derived classes
		void SetMetaData(vector<CimFieldAttribute>& childMetaData)
		{
			CIM_Capabilities::SetMetaData(childMetaData);
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
#endif // CIM_ENABLEDLOGICALELEMENTCAPABILITIES_H
