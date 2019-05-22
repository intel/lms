//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_BIOSElement.h
//
//  Contents:   BIOSElement represents the low-level software that is loaded into non-volatile storage and used to bring up and configure a ComputerSystem.
//
//              This file was automatically generated from CIM_BIOSElement.mof,  version: 2.17.0
//
//----------------------------------------------------------------------------
#ifndef CIM_BIOSELEMENT_H
#define CIM_BIOSELEMENT_H 1
#include "CIM_SoftwareElement.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	// BIOSElement represents the low-level software that is loaded into non-volatile storage and used to bring up and configure a ComputerSystem.
	class CIMFRAMEWORK_API CIM_BIOSElement  : public CIM_SoftwareElement
	{
	public:

		//Default constructor
		CIM_BIOSElement()
			: CIM_SoftwareElement(NULL, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_SoftwareElement::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 10);
			}
		}

		//constructor which receives WSMan client
		CIM_BIOSElement(ICimWsmanClient *client)
			: CIM_SoftwareElement(client, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_SoftwareElement::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 10);
			}
		}

		//Destructor
		virtual ~CIM_BIOSElement(){}

		// The "type" information for the object. Gettors only.
		virtual const string& ResourceURI() const { return CLASS_URI; }
		static const string& ClassResourceURI() { return CLASS_URI; }
		virtual const string& XmlNamespace() const { return CLASS_NS; }
		virtual const string& XmlPrefix() const { return CLASS_NS_PREFIX; }
		virtual const string& ObjectType() const { return CLASS_NAME; }
		static const string& ClassObjectType() { return CLASS_NAME; }

		// Class representing CIM_BIOSElement keys
		class CimKeys : public CIM_SoftwareElement::CimKeys
		{
		public:
			// Required, 
			const string Version() const
			{
				return GetKey("Version");
			}

			// Required, 
			void Version(const string &value)
			{
				SetOrAddKey("Version", value);
			}

		};

		// class fields declarations

		// Optional, If true, this is the primary BIOS of the ComputerSystem.
		const bool PrimaryBIOS() const;

		// Optional, If true, this is the primary BIOS of the ComputerSystem.
		void PrimaryBIOS(const bool value); 

		// Is true if the field PrimaryBIOS exists in the current object, otherwise is false.
		bool PrimaryBIOSExists() const;

		// Remove PrimaryBIOS field.
		void RemovePrimaryBIOS(); 

		// Optional, A list of installable languages for the BIOS. This information can be obtained from SMBIOS, from the string list that follows the Type 13 structure. An ISO 639 Language Name should be used to specify the BIOS' installable languages. The ISO 3166 Territory Name and the encoding method may also be specified, following the Language Name.
		const vector<string> ListOfLanguages() const;

		// Optional, A list of installable languages for the BIOS. This information can be obtained from SMBIOS, from the string list that follows the Type 13 structure. An ISO 639 Language Name should be used to specify the BIOS' installable languages. The ISO 3166 Territory Name and the encoding method may also be specified, following the Language Name.
		void ListOfLanguages(const vector<string> &value); 

		// Is true if the field ListOfLanguages exists in the current object, otherwise is false.
		bool ListOfLanguagesExists() const;

		// Remove ListOfLanguages field.
		void RemoveListOfLanguages(); 

		// Optional, The currently selected language for the BIOS. This information can be obtained from SMBIOS, using the Current Language attribute of the Type 13 structure, to index into the string list following the structure. The property is formatted using the ISO 639 Language Name, and may be followed by the ISO 3166 Territory Name and the encoding method.
		const string CurrentLanguage() const;

		// Optional, The currently selected language for the BIOS. This information can be obtained from SMBIOS, using the Current Language attribute of the Type 13 structure, to index into the string list following the structure. The property is formatted using the ISO 639 Language Name, and may be followed by the ISO 3166 Territory Name and the encoding method.
		void CurrentLanguage(const string &value); 

		// Is true if the field CurrentLanguage exists in the current object, otherwise is false.
		bool CurrentLanguageExists() const;

		// Remove CurrentLanguage field.
		void RemoveCurrentLanguage(); 

		// Optional, The starting address of the memory which this BIOS occupies.
		const Uint64 LoadedStartingAddress() const;

		// Optional, The starting address of the memory which this BIOS occupies.
		void LoadedStartingAddress(const Uint64 value); 

		// Is true if the field LoadedStartingAddress exists in the current object, otherwise is false.
		bool LoadedStartingAddressExists() const;

		// Remove LoadedStartingAddress field.
		void RemoveLoadedStartingAddress(); 

		// Optional, The ending address of the memory which this BIOS occupies.
		const Uint64 LoadedEndingAddress() const;

		// Optional, The ending address of the memory which this BIOS occupies.
		void LoadedEndingAddress(const Uint64 value); 

		// Is true if the field LoadedEndingAddress exists in the current object, otherwise is false.
		bool LoadedEndingAddressExists() const;

		// Remove LoadedEndingAddress field.
		void RemoveLoadedEndingAddress(); 

		// Optional, A free form string describing the BIOS flash/load utility that is required to update the BIOSElement. Version and other information may be indicated in this property.
		const string LoadUtilityInformation() const;

		// Optional, A free form string describing the BIOS flash/load utility that is required to update the BIOSElement. Version and other information may be indicated in this property.
		void LoadUtilityInformation(const string &value); 

		// Is true if the field LoadUtilityInformation exists in the current object, otherwise is false.
		bool LoadUtilityInformationExists() const;

		// Remove LoadUtilityInformation field.
		void RemoveLoadUtilityInformation(); 

		// Optional, Date that this BIOS was released.
		const CimDateTime ReleaseDate() const;

		// Optional, Date that this BIOS was released.
		void ReleaseDate(const CimDateTime &value); 

		// Is true if the field ReleaseDate exists in the current object, otherwise is false.
		bool ReleaseDateExists() const;

		// Remove ReleaseDate field.
		void RemoveReleaseDate(); 

		// Optional, A string representing the publication location of the BIOS Attribute registry or registries the implementation complies to.
		const vector<string> RegistryURIs() const;

		// Optional, A string representing the publication location of the BIOS Attribute registry or registries the implementation complies to.
		void RegistryURIs(const vector<string> &value); 

		// Is true if the field RegistryURIs exists in the current object, otherwise is false.
		bool RegistryURIsExists() const;

		// Remove RegistryURIs field.
		void RemoveRegistryURIs(); 

		 // Function used by the factory
		static CimBase *CreateFromCimObject(const CimObject &object);

		static vector<shared_ptr<CIM_BIOSElement> > Enumerate(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		// Overloaded delete which supplies the internal resourceURI
		static void Delete(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		using CimBase::Delete;

	protected:
		 // Protected constructor to be used by derived classes
		CIM_BIOSElement(ICimWsmanClient *client, const string &class_name,
			const string &class_ns, const string &prefix, const string &uri): CIM_SoftwareElement(client, class_name, class_ns, prefix, uri)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_SoftwareElement::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 10);
			}
		}
		 // Protected constructor which receives CimObject
		CIM_BIOSElement(const CimObject &object)
			: CIM_SoftwareElement(object)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_SoftwareElement::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 10);
			}
		}
		// Called by derived classes
		void SetMetaData(vector<CimFieldAttribute>& childMetaData)
		{
			CIM_SoftwareElement::SetMetaData(childMetaData);
			CimBase::SetMetaData(childMetaData, _metadata, 10);
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
#endif // CIM_BIOSELEMENT_H
