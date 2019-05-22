//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_ElementSoftwareIdentity.h
//
//  Contents:   ElementSoftwareIdentity allows a Managed Element to report its software related asset information (firmware, drivers, configuration software, and etc.)
//
//              This file was automatically generated from CIM_ElementSoftwareIdentity.mof,  version: 2.20.0
//
//----------------------------------------------------------------------------
#ifndef CIM_ELEMENTSOFTWAREIDENTITY_H
#define CIM_ELEMENTSOFTWAREIDENTITY_H 1
#include "CIM_Dependency.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	// ElementSoftwareIdentity allows a Managed Element to report its software related asset information (firmware, drivers, configuration software, and etc.)
	class CIMFRAMEWORK_API CIM_ElementSoftwareIdentity  : public CIM_Dependency
	{
	public:

		//Default constructor
		CIM_ElementSoftwareIdentity()
			: CIM_Dependency(NULL, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_Dependency::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 5);
			}
		}

		//constructor which receives WSMan client
		CIM_ElementSoftwareIdentity(ICimWsmanClient *client)
			: CIM_Dependency(client, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_Dependency::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 5);
			}
		}

		//Destructor
		virtual ~CIM_ElementSoftwareIdentity(){}

		// The "type" information for the object. Gettors only.
		virtual const string& ResourceURI() const { return CLASS_URI; }
		static const string& ClassResourceURI() { return CLASS_URI; }
		virtual const string& XmlNamespace() const { return CLASS_NS; }
		virtual const string& XmlPrefix() const { return CLASS_NS_PREFIX; }
		virtual const string& ObjectType() const { return CLASS_NAME; }
		static const string& ClassObjectType() { return CLASS_NAME; }

		// Class representing CIM_ElementSoftwareIdentity keys
		class CimKeys : public CIM_Dependency::CimKeys
		{
		public:
			// Required, A LogicalElement's Software Asset.
			const CimReference Antecedent() const
			{
				CimReference ret;
				TypeConverter::StringToType(GetKey("Antecedent"), ret);
				return ret;
			}

			// Required, A LogicalElement's Software Asset.
			void Antecedent(const CimReference &value)
			{
				SetOrAddKey("Antecedent", TypeConverter::TypeToString(value), true);
			}

			// Required, The ManagedElement that requires or uses the software.
			const CimReference Dependent() const
			{
				CimReference ret;
				TypeConverter::StringToType(GetKey("Dependent"), ret);
				return ret;
			}

			// Required, The ManagedElement that requires or uses the software.
			void Dependent(const CimReference &value)
			{
				SetOrAddKey("Dependent", TypeConverter::TypeToString(value), true);
			}

		};

		// class fields declarations

		// Optional, Indicates the element's ability to upgrade this software asset.
		// 'Resides off element'(2), indicates the persistence of the software is outside of the element. Typically for a element this software is part of the OperatingSystem is typically upgradeable.
		// 'Owner Upgradeable' (3), indicates the persistence of the software is on the element and is upgradeable by the owner.
		// 'FactoryUpgradeable' (4),indicates the persistence of the software is on the element and is upgradeable by the manufacturer.
		// 'Not Upgradeable' (5), indicates the presistence of the software is on the element and is not upgradeable. (i.e. burned into a non replaceable ROM chip.
		const unsigned short UpgradeCondition() const;

		// Optional, Indicates the element's ability to upgrade this software asset.
		// 'Resides off element'(2), indicates the persistence of the software is outside of the element. Typically for a element this software is part of the OperatingSystem is typically upgradeable.
		// 'Owner Upgradeable' (3), indicates the persistence of the software is on the element and is upgradeable by the owner.
		// 'FactoryUpgradeable' (4),indicates the persistence of the software is on the element and is upgradeable by the manufacturer.
		// 'Not Upgradeable' (5), indicates the presistence of the software is on the element and is not upgradeable. (i.e. burned into a non replaceable ROM chip.
		void UpgradeCondition(const unsigned short value); 

		// Is true if the field UpgradeCondition exists in the current object, otherwise is false.
		bool UpgradeConditionExists() const;

		// Remove UpgradeCondition field.
		void RemoveUpgradeCondition(); 

		// Optional, Describes the upgrade condition, when UpgradeCondition is set to 1 ("Other").
		const string OtherUpgradeCondition() const;

		// Optional, Describes the upgrade condition, when UpgradeCondition is set to 1 ("Other").
		void OtherUpgradeCondition(const string &value); 

		// Is true if the field OtherUpgradeCondition exists in the current object, otherwise is false.
		bool OtherUpgradeConditionExists() const;

		// Remove OtherUpgradeCondition field.
		void RemoveOtherUpgradeCondition(); 

		// Optional, A collection of properties describing the status of the software on the managed element. Multiple properties could be set at the same time. For example a ElementSoftwareStatus could have "Installed", "Default", "Current" and "FallBack" set at the same time. 
		// "Current" indicates that the software is currently running on or for the Managed Element. 
		// "Next" indicates that the software will run after the next reset or reboot unless superseded by a software with a status of "SingleUse". 
		// "FallBack" indicates that the software will be run if the software which has a status of "Next" or "SingleUse" fails to run. 
		// "Default" indicates the default version of the software that was originally shipped by the manufacturer. 
		// "Installed" indicates that the software is persistently located and is available for use on the Managed Element. 
		// "SingleUse" indicates that the software will run only after the next reset or reboot but will not run after the subsequent reset or reboot. 
		// "Available" indicates that the software is available for installation on the Managed Element. 
		// "Supports"indicates that the software will work with or operate the Managed Element but is or will be installed on a different Managed Element.
		const vector<unsigned short> ElementSoftwareStatus() const;

		// Optional, A collection of properties describing the status of the software on the managed element. Multiple properties could be set at the same time. For example a ElementSoftwareStatus could have "Installed", "Default", "Current" and "FallBack" set at the same time. 
		// "Current" indicates that the software is currently running on or for the Managed Element. 
		// "Next" indicates that the software will run after the next reset or reboot unless superseded by a software with a status of "SingleUse". 
		// "FallBack" indicates that the software will be run if the software which has a status of "Next" or "SingleUse" fails to run. 
		// "Default" indicates the default version of the software that was originally shipped by the manufacturer. 
		// "Installed" indicates that the software is persistently located and is available for use on the Managed Element. 
		// "SingleUse" indicates that the software will run only after the next reset or reboot but will not run after the subsequent reset or reboot. 
		// "Available" indicates that the software is available for installation on the Managed Element. 
		// "Supports"indicates that the software will work with or operate the Managed Element but is or will be installed on a different Managed Element.
		void ElementSoftwareStatus(const vector<unsigned short> &value); 

		// Is true if the field ElementSoftwareStatus exists in the current object, otherwise is false.
		bool ElementSoftwareStatusExists() const;

		// Remove ElementSoftwareStatus field.
		void RemoveElementSoftwareStatus(); 

		 // Function used by the factory
		static CimBase *CreateFromCimObject(const CimObject &object);

		static vector<shared_ptr<CIM_ElementSoftwareIdentity> > Enumerate(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		// Overloaded delete which supplies the internal resourceURI
		static void Delete(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		using CimBase::Delete;

	protected:
		 // Protected constructor to be used by derived classes
		CIM_ElementSoftwareIdentity(ICimWsmanClient *client, const string &class_name,
			const string &class_ns, const string &prefix, const string &uri): CIM_Dependency(client, class_name, class_ns, prefix, uri)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_Dependency::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 5);
			}
		}
		 // Protected constructor which receives CimObject
		CIM_ElementSoftwareIdentity(const CimObject &object)
			: CIM_Dependency(object)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_Dependency::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 5);
			}
		}
		// Called by derived classes
		void SetMetaData(vector<CimFieldAttribute>& childMetaData)
		{
			CIM_Dependency::SetMetaData(childMetaData);
			CimBase::SetMetaData(childMetaData, _metadata, 5);
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
#endif // CIM_ELEMENTSOFTWAREIDENTITY_H
