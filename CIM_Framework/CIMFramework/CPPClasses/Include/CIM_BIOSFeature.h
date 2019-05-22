//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_BIOSFeature.h
//
//  Contents:   BIOSFeature represents the capabilities of the low-level software that is used to bring up and configure a Computer System.
//
//              This file was automatically generated from CIM_BIOSFeature.mof,  version: 2.6.0
//
//----------------------------------------------------------------------------
#ifndef CIM_BIOSFEATURE_H
#define CIM_BIOSFEATURE_H 1
#include "CIM_SoftwareFeature.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	// BIOSFeature represents the capabilities of the low-level software that is used to bring up and configure a Computer System.
	class CIMFRAMEWORK_API CIM_BIOSFeature  : public CIM_SoftwareFeature
	{
	public:

		//Default constructor
		CIM_BIOSFeature()
			: CIM_SoftwareFeature(NULL, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_SoftwareFeature::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 2);
			}
		}

		//constructor which receives WSMan client
		CIM_BIOSFeature(ICimWsmanClient *client)
			: CIM_SoftwareFeature(client, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_SoftwareFeature::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 2);
			}
		}

		//Destructor
		virtual ~CIM_BIOSFeature(){}

		// The "type" information for the object. Gettors only.
		virtual const string& ResourceURI() const { return CLASS_URI; }
		static const string& ClassResourceURI() { return CLASS_URI; }
		virtual const string& XmlNamespace() const { return CLASS_NS; }
		virtual const string& XmlPrefix() const { return CLASS_NS_PREFIX; }
		virtual const string& ObjectType() const { return CLASS_NAME; }
		static const string& ClassObjectType() { return CLASS_NAME; }

		// Class representing CIM_BIOSFeature keys
		class CimKeys : public CIM_SoftwareFeature::CimKeys
		{
		public:
		};

		// class fields declarations

		// Optional, An array of integers that specify the features supported by the BIOS. For example, one can specify that PnP capabilities are provided (value=9) or that infrared devices are supported (21). Values specified in the enumeration are taken from both DMI and SMBIOS (the Type 0 structure, the BIOS Characteristics and BIOS Characteristics Extension Bytes attributes.
		const vector<unsigned short> Characteristics() const;

		// Optional, An array of integers that specify the features supported by the BIOS. For example, one can specify that PnP capabilities are provided (value=9) or that infrared devices are supported (21). Values specified in the enumeration are taken from both DMI and SMBIOS (the Type 0 structure, the BIOS Characteristics and BIOS Characteristics Extension Bytes attributes.
		void Characteristics(const vector<unsigned short> &value); 

		// Is true if the field Characteristics exists in the current object, otherwise is false.
		bool CharacteristicsExists() const;

		// Remove Characteristics field.
		void RemoveCharacteristics(); 

		// Optional, An array of free-form strings providing more detailed explanations for any of the BIOS features indicated in the Characteristics array. Note, each entry of this array is related to the entry in the Characteristics array that is located at the same index.
		const vector<string> CharacteristicDescriptions() const;

		// Optional, An array of free-form strings providing more detailed explanations for any of the BIOS features indicated in the Characteristics array. Note, each entry of this array is related to the entry in the Characteristics array that is located at the same index.
		void CharacteristicDescriptions(const vector<string> &value); 

		// Is true if the field CharacteristicDescriptions exists in the current object, otherwise is false.
		bool CharacteristicDescriptionsExists() const;

		// Remove CharacteristicDescriptions field.
		void RemoveCharacteristicDescriptions(); 

		 // Function used by the factory
		static CimBase *CreateFromCimObject(const CimObject &object);

		static vector<shared_ptr<CIM_BIOSFeature> > Enumerate(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		// Overloaded delete which supplies the internal resourceURI
		static void Delete(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		using CimBase::Delete;

	protected:
		 // Protected constructor to be used by derived classes
		CIM_BIOSFeature(ICimWsmanClient *client, const string &class_name,
			const string &class_ns, const string &prefix, const string &uri): CIM_SoftwareFeature(client, class_name, class_ns, prefix, uri)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_SoftwareFeature::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 2);
			}
		}
		 // Protected constructor which receives CimObject
		CIM_BIOSFeature(const CimObject &object)
			: CIM_SoftwareFeature(object)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_SoftwareFeature::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 2);
			}
		}
		// Called by derived classes
		void SetMetaData(vector<CimFieldAttribute>& childMetaData)
		{
			CIM_SoftwareFeature::SetMetaData(childMetaData);
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
#endif // CIM_BIOSFEATURE_H
