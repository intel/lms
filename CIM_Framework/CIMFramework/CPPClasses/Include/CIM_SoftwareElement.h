//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_SoftwareElement.h
//
//  Contents:   The CIM_SoftwareElement class is used to decompose a CIM_SoftwareFeature object into a set of individually manageable or deployable parts, for a particular platform. A SoftwareElement's platform is uniquely identified by its underlying hardware architecture and operating system (for example Sun Solaris on Sun Sparc or Windows NT on Intel platforms). As such, to understand the details of how the functionality of a particular SoftwareFeature is provided on a particular platform, the CIM_SoftwareElement objects referenced by CIM_SoftwareFeatureSoftwareElements associations are organized in disjoint sets based on the TargetOperatingSystem property. A CIM_SoftwareElement object captures the management details of a part or component in one of four states characterized by the SoftwareElementState property.
//
//              This file was automatically generated from CIM_SoftwareElement.mof,  version: 2.23.0
//
//----------------------------------------------------------------------------
#ifndef CIM_SOFTWAREELEMENT_H
#define CIM_SOFTWAREELEMENT_H 1
#include "CIM_LogicalElement.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	// The CIM_SoftwareElement class is used to decompose a CIM_SoftwareFeature object into a set of individually manageable or deployable parts, for a particular platform. A SoftwareElement's platform is uniquely identified by its underlying hardware architecture and operating system (for example Sun Solaris on Sun Sparc or Windows NT on Intel platforms). As such, to understand the details of how the functionality of a particular SoftwareFeature is provided on a particular platform, the CIM_SoftwareElement objects referenced by CIM_SoftwareFeatureSoftwareElements associations are organized in disjoint sets based on the TargetOperatingSystem property. A CIM_SoftwareElement object captures the management details of a part or component in one of four states characterized by the SoftwareElementState property.
	class CIMFRAMEWORK_API CIM_SoftwareElement  : public CIM_LogicalElement
	{
	public:

		//Default constructor
		CIM_SoftwareElement()
			: CIM_LogicalElement(NULL, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_LogicalElement::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 12);
			}
		}

		//constructor which receives WSMan client
		CIM_SoftwareElement(ICimWsmanClient *client)
			: CIM_LogicalElement(client, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_LogicalElement::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 12);
			}
		}

		//Destructor
		virtual ~CIM_SoftwareElement(){}

		// The "type" information for the object. Gettors only.
		virtual const string& ResourceURI() const { return CLASS_URI; }
		static const string& ClassResourceURI() { return CLASS_URI; }
		virtual const string& XmlNamespace() const { return CLASS_NS; }
		virtual const string& XmlPrefix() const { return CLASS_NS_PREFIX; }
		virtual const string& ObjectType() const { return CLASS_NAME; }
		static const string& ClassObjectType() { return CLASS_NAME; }

		// Class representing CIM_SoftwareElement keys
		class CimKeys : public CIM_LogicalElement::CimKeys
		{
		public:
			// Key, Required, The name used to identify this SoftwareElement.
			const string Name() const
			{
				return GetKey("Name");
			}

			// Key, Required, The name used to identify this SoftwareElement.
			void Name(const string &value)
			{
				SetOrAddKey("Name", value);
			}

			// Key, Required, Software Version should be in the form <Major>.<Minor>.<Revision> or <Major>.<Minor><letter><revision>.
			const string Version() const
			{
				return GetKey("Version");
			}

			// Key, Required, Software Version should be in the form <Major>.<Minor>.<Revision> or <Major>.<Minor><letter><revision>.
			void Version(const string &value)
			{
				SetOrAddKey("Version", value);
			}

			// Key, Required, The SoftwareElementState is defined in this model to identify various states of a SoftwareElement's life cycle. 
			// - A SoftwareElement in the deployable state describes the details necessary to successfully distribute it and the details (Checks and Actions) required to move it to the installable state (i.e, the next state). 
			// - A SoftwareElement in the installable state describes the details necessary to successfully install it and the details (Checks and Actions) required to create an element in the executable state (i.e., the next state). 
			// - A SoftwareElement in the executable state describes the details necessary to successfully start it and the details (Checks and Actions) required to move it to the running state (i.e., the next state). 
			// - A SoftwareElement in the running state describes the details necessary to manage the started element.
			const unsigned short SoftwareElementState() const
			{
				unsigned short ret;
				TypeConverter::StringToType(GetKey("SoftwareElementState"), ret);
				return ret;
			}

			// Key, Required, The SoftwareElementState is defined in this model to identify various states of a SoftwareElement's life cycle. 
			// - A SoftwareElement in the deployable state describes the details necessary to successfully distribute it and the details (Checks and Actions) required to move it to the installable state (i.e, the next state). 
			// - A SoftwareElement in the installable state describes the details necessary to successfully install it and the details (Checks and Actions) required to create an element in the executable state (i.e., the next state). 
			// - A SoftwareElement in the executable state describes the details necessary to successfully start it and the details (Checks and Actions) required to move it to the running state (i.e., the next state). 
			// - A SoftwareElement in the running state describes the details necessary to manage the started element.
			void SoftwareElementState(const unsigned short value)
			{
				SetOrAddKey("SoftwareElementState", TypeConverter::TypeToString(value));
			}

			// Key, Required, This is an identifier for the SoftwareElement and is designed to be used in conjunction with other keys to create a unique representation of the element.
			const string SoftwareElementID() const
			{
				return GetKey("SoftwareElementID");
			}

			// Key, Required, This is an identifier for the SoftwareElement and is designed to be used in conjunction with other keys to create a unique representation of the element.
			void SoftwareElementID(const string &value)
			{
				SetOrAddKey("SoftwareElementID", value);
			}

			// Key, Required, The TargetOperatingSystem property specifies the element's operating system environment. The value of this property does not ensure that it is binary executable. Two other pieces of information are needed. First, the version of the OS needs to be specified using the class, CIM_OSVersion Check. The second piece of information is the architecture that the OS runs on. This information is verified using CIM_ArchitectureCheck. The combination of these constructs clearly identifies the level of OS required for a particular SoftwareElement.
			const unsigned short TargetOperatingSystem() const
			{
				unsigned short ret;
				TypeConverter::StringToType(GetKey("TargetOperatingSystem"), ret);
				return ret;
			}

			// Key, Required, The TargetOperatingSystem property specifies the element's operating system environment. The value of this property does not ensure that it is binary executable. Two other pieces of information are needed. First, the version of the OS needs to be specified using the class, CIM_OSVersion Check. The second piece of information is the architecture that the OS runs on. This information is verified using CIM_ArchitectureCheck. The combination of these constructs clearly identifies the level of OS required for a particular SoftwareElement.
			void TargetOperatingSystem(const unsigned short value)
			{
				SetOrAddKey("TargetOperatingSystem", TypeConverter::TypeToString(value));
			}

		};

		// class fields declarations

		// Key, Required, Software Version should be in the form <Major>.<Minor>.<Revision> or <Major>.<Minor><letter><revision>.
		const string Version() const;

		// Key, Required, Software Version should be in the form <Major>.<Minor>.<Revision> or <Major>.<Minor><letter><revision>.
		void Version(const string &value); 


		// Key, Required, The SoftwareElementState is defined in this model to identify various states of a SoftwareElement's life cycle. 
		// - A SoftwareElement in the deployable state describes the details necessary to successfully distribute it and the details (Checks and Actions) required to move it to the installable state (i.e, the next state). 
		// - A SoftwareElement in the installable state describes the details necessary to successfully install it and the details (Checks and Actions) required to create an element in the executable state (i.e., the next state). 
		// - A SoftwareElement in the executable state describes the details necessary to successfully start it and the details (Checks and Actions) required to move it to the running state (i.e., the next state). 
		// - A SoftwareElement in the running state describes the details necessary to manage the started element.
		const unsigned short SoftwareElementState() const;

		// Key, Required, The SoftwareElementState is defined in this model to identify various states of a SoftwareElement's life cycle. 
		// - A SoftwareElement in the deployable state describes the details necessary to successfully distribute it and the details (Checks and Actions) required to move it to the installable state (i.e, the next state). 
		// - A SoftwareElement in the installable state describes the details necessary to successfully install it and the details (Checks and Actions) required to create an element in the executable state (i.e., the next state). 
		// - A SoftwareElement in the executable state describes the details necessary to successfully start it and the details (Checks and Actions) required to move it to the running state (i.e., the next state). 
		// - A SoftwareElement in the running state describes the details necessary to manage the started element.
		void SoftwareElementState(const unsigned short value); 


		// Key, Required, This is an identifier for the SoftwareElement and is designed to be used in conjunction with other keys to create a unique representation of the element.
		const string SoftwareElementID() const;

		// Key, Required, This is an identifier for the SoftwareElement and is designed to be used in conjunction with other keys to create a unique representation of the element.
		void SoftwareElementID(const string &value); 


		// Key, Required, The TargetOperatingSystem property specifies the element's operating system environment. The value of this property does not ensure that it is binary executable. Two other pieces of information are needed. First, the version of the OS needs to be specified using the class, CIM_OSVersion Check. The second piece of information is the architecture that the OS runs on. This information is verified using CIM_ArchitectureCheck. The combination of these constructs clearly identifies the level of OS required for a particular SoftwareElement.
		const unsigned short TargetOperatingSystem() const;

		// Key, Required, The TargetOperatingSystem property specifies the element's operating system environment. The value of this property does not ensure that it is binary executable. Two other pieces of information are needed. First, the version of the OS needs to be specified using the class, CIM_OSVersion Check. The second piece of information is the architecture that the OS runs on. This information is verified using CIM_ArchitectureCheck. The combination of these constructs clearly identifies the level of OS required for a particular SoftwareElement.
		void TargetOperatingSystem(const unsigned short value); 


		// Optional, The OtherTargetOS property records the manufacturer and operating system type for a SoftwareElement when the TargetOperatingSystem property has a value of 1 ("Other"). For all other values of TargetOperatingSystem, the OtherTargetOS property is NULL.
		const string OtherTargetOS() const;

		// Optional, The OtherTargetOS property records the manufacturer and operating system type for a SoftwareElement when the TargetOperatingSystem property has a value of 1 ("Other"). For all other values of TargetOperatingSystem, the OtherTargetOS property is NULL.
		void OtherTargetOS(const string &value); 

		// Is true if the field OtherTargetOS exists in the current object, otherwise is false.
		bool OtherTargetOSExists() const;

		// Remove OtherTargetOS field.
		void RemoveOtherTargetOS(); 

		// Optional, Manufacturer of this SoftwareElement.
		const string Manufacturer() const;

		// Optional, Manufacturer of this SoftwareElement.
		void Manufacturer(const string &value); 

		// Is true if the field Manufacturer exists in the current object, otherwise is false.
		bool ManufacturerExists() const;

		// Remove Manufacturer field.
		void RemoveManufacturer(); 

		// Optional, The internal identifier for this compilation of SoftwareElement.
		const string BuildNumber() const;

		// Optional, The internal identifier for this compilation of SoftwareElement.
		void BuildNumber(const string &value); 

		// Is true if the field BuildNumber exists in the current object, otherwise is false.
		bool BuildNumberExists() const;

		// Remove BuildNumber field.
		void RemoveBuildNumber(); 

		// Optional, The assigned serial number of this SoftwareElement.
		const string SerialNumber() const;

		// Optional, The assigned serial number of this SoftwareElement.
		void SerialNumber(const string &value); 

		// Is true if the field SerialNumber exists in the current object, otherwise is false.
		bool SerialNumberExists() const;

		// Remove SerialNumber field.
		void RemoveSerialNumber(); 

		// Optional, The code set used by this SoftwareElement. It defines the bit patterns that a system uses to identify characters. ISO defines various code sets such as UTF-8 and ISO8859-1.
		const string CodeSet() const;

		// Optional, The code set used by this SoftwareElement. It defines the bit patterns that a system uses to identify characters. ISO defines various code sets such as UTF-8 and ISO8859-1.
		void CodeSet(const string &value); 

		// Is true if the field CodeSet exists in the current object, otherwise is false.
		bool CodeSetExists() const;

		// Remove CodeSet field.
		void RemoveCodeSet(); 

		// Optional, The manufacturer's identifier for this SoftwareElement. Often this will be a stock keeping unit (SKU) or a part number.
		const string IdentificationCode() const;

		// Optional, The manufacturer's identifier for this SoftwareElement. Often this will be a stock keeping unit (SKU) or a part number.
		void IdentificationCode(const string &value); 

		// Is true if the field IdentificationCode exists in the current object, otherwise is false.
		bool IdentificationCodeExists() const;

		// Remove IdentificationCode field.
		void RemoveIdentificationCode(); 

		// Optional, The value of this property identifies the language edition of this SoftwareElement. The language codes defined in ISO 639 should be used. Where the element represents a multi-lingual or international version, the string "Multilingual" should be used.
		const string LanguageEdition() const;

		// Optional, The value of this property identifies the language edition of this SoftwareElement. The language codes defined in ISO 639 should be used. Where the element represents a multi-lingual or international version, the string "Multilingual" should be used.
		void LanguageEdition(const string &value); 

		// Is true if the field LanguageEdition exists in the current object, otherwise is false.
		bool LanguageEditionExists() const;

		// Remove LanguageEdition field.
		void RemoveLanguageEdition(); 

		 // Function used by the factory
		static CimBase *CreateFromCimObject(const CimObject &object);

		static vector<shared_ptr<CIM_SoftwareElement> > Enumerate(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		// Overloaded delete which supplies the internal resourceURI
		static void Delete(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		using CimBase::Delete;

	protected:
		 // Protected constructor to be used by derived classes
		CIM_SoftwareElement(ICimWsmanClient *client, const string &class_name,
			const string &class_ns, const string &prefix, const string &uri): CIM_LogicalElement(client, class_name, class_ns, prefix, uri)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_LogicalElement::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 12);
			}
		}
		 // Protected constructor which receives CimObject
		CIM_SoftwareElement(const CimObject &object)
			: CIM_LogicalElement(object)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_LogicalElement::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 12);
			}
		}
		// Called by derived classes
		void SetMetaData(vector<CimFieldAttribute>& childMetaData)
		{
			CIM_LogicalElement::SetMetaData(childMetaData);
			CimBase::SetMetaData(childMetaData, _metadata, 12);
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
#endif // CIM_SOFTWAREELEMENT_H
