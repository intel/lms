//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_PhysicalConnector.h
//
//  Contents:   The PhysicalConnector class represents any PhysicalElement that is used to connect to other Elements. Any object that can be used to connect and transmit signals or power between two or more PhysicalElements is a descendant (or member) of this class. For example, Slots and D-shell connectors are types of PhysicalConnectors.
//
//              This file was automatically generated from CIM_PhysicalConnector.mof,  version: 2.19.0
//
//----------------------------------------------------------------------------
#ifndef CIM_PHYSICALCONNECTOR_H
#define CIM_PHYSICALCONNECTOR_H 1
#include "CIM_PhysicalElement.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	// The PhysicalConnector class represents any PhysicalElement that is used to connect to other Elements. Any object that can be used to connect and transmit signals or power between two or more PhysicalElements is a descendant (or member) of this class. For example, Slots and D-shell connectors are types of PhysicalConnectors.
	class CIMFRAMEWORK_API CIM_PhysicalConnector  : public CIM_PhysicalElement
	{
	public:

		//Default constructor
		CIM_PhysicalConnector()
			: CIM_PhysicalElement(NULL, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_PhysicalElement::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 9);
			}
		}

		//constructor which receives WSMan client
		CIM_PhysicalConnector(ICimWsmanClient *client)
			: CIM_PhysicalElement(client, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_PhysicalElement::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 9);
			}
		}

		//Destructor
		virtual ~CIM_PhysicalConnector(){}

		// The "type" information for the object. Gettors only.
		virtual const string& ResourceURI() const { return CLASS_URI; }
		static const string& ClassResourceURI() { return CLASS_URI; }
		virtual const string& XmlNamespace() const { return CLASS_NS; }
		virtual const string& XmlPrefix() const { return CLASS_NS_PREFIX; }
		virtual const string& ObjectType() const { return CLASS_NAME; }
		static const string& ClassObjectType() { return CLASS_NAME; }

		// Class representing CIM_PhysicalConnector keys
		class CimKeys : public CIM_PhysicalElement::CimKeys
		{
		public:
		};

		// class fields declarations

		// Optional, A free-form string describing the pin configuration and/or signal usage of a PhysicalConnector.
		const string ConnectorPinout() const;

		// Optional, A free-form string describing the pin configuration and/or signal usage of a PhysicalConnector.
		void ConnectorPinout(const string &value); 

		// Is true if the field ConnectorPinout exists in the current object, otherwise is false.
		bool ConnectorPinoutExists() const;

		// Remove ConnectorPinout field.
		void RemoveConnectorPinout(); 

		// Optional, An array of integers defining the type of PhysicalConnector. An array is specified to allow the description of 'combinations' of Connector information. For example, one array entry could specify RS-232 (value=25), another DB-25 (value=23) and a third entry define the Connector as "Male" (value=2). 
		// This single property is being deprecated in lieu of using separate properties to describe the various aspects of the connector. The separation allows for a more generic means of describing the connectors. Obsolete connectors were intentionally removed from the new list.
		const vector<unsigned short> ConnectorType() const;

		// Optional, An array of integers defining the type of PhysicalConnector. An array is specified to allow the description of 'combinations' of Connector information. For example, one array entry could specify RS-232 (value=25), another DB-25 (value=23) and a third entry define the Connector as "Male" (value=2). 
		// This single property is being deprecated in lieu of using separate properties to describe the various aspects of the connector. The separation allows for a more generic means of describing the connectors. Obsolete connectors were intentionally removed from the new list.
		void ConnectorType(const vector<unsigned short> &value); 

		// Is true if the field ConnectorType exists in the current object, otherwise is false.
		bool ConnectorTypeExists() const;

		// Remove ConnectorType field.
		void RemoveConnectorType(); 

		// Optional, A string describing the Connector - used when the ConnectorType property is set to 1 ("Other"). OtherType Description should be set to NULL when ConnectorType is any value other than 1. 
		// The use of this property is deprecated in lieu of Connector Description.
		const string OtherTypeDescription() const;

		// Optional, A string describing the Connector - used when the ConnectorType property is set to 1 ("Other"). OtherType Description should be set to NULL when ConnectorType is any value other than 1. 
		// The use of this property is deprecated in lieu of Connector Description.
		void OtherTypeDescription(const string &value); 

		// Is true if the field OtherTypeDescription exists in the current object, otherwise is false.
		bool OtherTypeDescriptionExists() const;

		// Remove OtherTypeDescription field.
		void RemoveOtherTypeDescription(); 

		// Optional, Describes the gender of the connector.
		const unsigned short ConnectorGender() const;

		// Optional, Describes the gender of the connector.
		void ConnectorGender(const unsigned short value); 

		// Is true if the field ConnectorGender exists in the current object, otherwise is false.
		bool ConnectorGenderExists() const;

		// Remove ConnectorGender field.
		void RemoveConnectorGender(); 

		// Optional, Describes the electrical characteristic for this connector.
		const vector<unsigned short> ConnectorElectricalCharacteristics() const;

		// Optional, Describes the electrical characteristic for this connector.
		void ConnectorElectricalCharacteristics(const vector<unsigned short> &value); 

		// Is true if the field ConnectorElectricalCharacteristics exists in the current object, otherwise is false.
		bool ConnectorElectricalCharacteristicsExists() const;

		// Remove ConnectorElectricalCharacteristics field.
		void RemoveConnectorElectricalCharacteristics(); 

		// Optional, A string describing the connector's electrical characteristics - used when the ConnectorElectricalCharacteristics property contains an entry of 1 (Other). OtherElectricalCharacteristics should be set to NULL when ConnectorElectricalCharacteristics does not contain an value of 1.
		const vector<string> OtherElectricalCharacteristics() const;

		// Optional, A string describing the connector's electrical characteristics - used when the ConnectorElectricalCharacteristics property contains an entry of 1 (Other). OtherElectricalCharacteristics should be set to NULL when ConnectorElectricalCharacteristics does not contain an value of 1.
		void OtherElectricalCharacteristics(const vector<string> &value); 

		// Is true if the field OtherElectricalCharacteristics exists in the current object, otherwise is false.
		bool OtherElectricalCharacteristicsExists() const;

		// Remove OtherElectricalCharacteristics field.
		void RemoveOtherElectricalCharacteristics(); 

		// Optional, Describes the number of physical pins (male/female) that are present on this connector.
		const unsigned int NumPhysicalPins() const;

		// Optional, Describes the number of physical pins (male/female) that are present on this connector.
		void NumPhysicalPins(const unsigned int value); 

		// Is true if the field NumPhysicalPins exists in the current object, otherwise is false.
		bool NumPhysicalPinsExists() const;

		// Remove NumPhysicalPins field.
		void RemoveNumPhysicalPins(); 

		// Optional, Describes the type of packaging normally associated with this type of connector.16 (PCI) - describes the generic PCI connector layout. 17 (PCI-X) - describes the PCI Extended connector layout. 18 (PCI-E) - describes the PCI Express connector layout, where the actual layout as far as the length is concerned is unknown. 19 - 25 (PCI-E xN) - describes the PCI Express connector layout, where N is the lane count that appropriately descirbes the length of the PCI-E connector.
		const unsigned short ConnectorLayout() const;

		// Optional, Describes the type of packaging normally associated with this type of connector.16 (PCI) - describes the generic PCI connector layout. 17 (PCI-X) - describes the PCI Extended connector layout. 18 (PCI-E) - describes the PCI Express connector layout, where the actual layout as far as the length is concerned is unknown. 19 - 25 (PCI-E xN) - describes the PCI Express connector layout, where N is the lane count that appropriately descirbes the length of the PCI-E connector.
		void ConnectorLayout(const unsigned short value); 

		// Is true if the field ConnectorLayout exists in the current object, otherwise is false.
		bool ConnectorLayoutExists() const;

		// Remove ConnectorLayout field.
		void RemoveConnectorLayout(); 

		// Optional, A string describing the Connector - used when the ConnectorLayout property is set to 1 ("Other"). Connector Description should be set to NULL when ConnectorLayout is any value other than 1.
		const string ConnectorDescription() const;

		// Optional, A string describing the Connector - used when the ConnectorLayout property is set to 1 ("Other"). Connector Description should be set to NULL when ConnectorLayout is any value other than 1.
		void ConnectorDescription(const string &value); 

		// Is true if the field ConnectorDescription exists in the current object, otherwise is false.
		bool ConnectorDescriptionExists() const;

		// Remove ConnectorDescription field.
		void RemoveConnectorDescription(); 

		 // Function used by the factory
		static CimBase *CreateFromCimObject(const CimObject &object);

		static vector<shared_ptr<CIM_PhysicalConnector> > Enumerate(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		// Overloaded delete which supplies the internal resourceURI
		static void Delete(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		using CimBase::Delete;

	protected:
		 // Protected constructor to be used by derived classes
		CIM_PhysicalConnector(ICimWsmanClient *client, const string &class_name,
			const string &class_ns, const string &prefix, const string &uri): CIM_PhysicalElement(client, class_name, class_ns, prefix, uri)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_PhysicalElement::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 9);
			}
		}
		 // Protected constructor which receives CimObject
		CIM_PhysicalConnector(const CimObject &object)
			: CIM_PhysicalElement(object)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_PhysicalElement::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 9);
			}
		}
		// Called by derived classes
		void SetMetaData(vector<CimFieldAttribute>& childMetaData)
		{
			CIM_PhysicalElement::SetMetaData(childMetaData);
			CimBase::SetMetaData(childMetaData, _metadata, 9);
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
#endif // CIM_PHYSICALCONNECTOR_H
