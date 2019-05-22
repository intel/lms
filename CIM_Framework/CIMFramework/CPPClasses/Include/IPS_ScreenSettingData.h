//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       IPS_ScreenSettingData.h
//
//  Contents:   The IPS_ScreenSettingData class represents Extended Displays Configuration settings for KVM redirection service in the Intel(R) AMT.
//
//              This file was automatically generated from IPS_ScreenSettingData.mof,  version: 8.0.0
//
//----------------------------------------------------------------------------
#ifndef IPS_SCREENSETTINGDATA_H
#define IPS_SCREENSETTINGDATA_H 1
#include "CIM_SettingData.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	// The IPS_ScreenSettingData class represents Extended Displays Configuration settings for KVM redirection service in the Intel(R) AMT.
	class CIMFRAMEWORK_API IPS_ScreenSettingData  : public CIM_SettingData
	{
	public:

		//Default constructor
		IPS_ScreenSettingData()
			: CIM_SettingData(NULL, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_SettingData::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 9);
			}
		}

		//constructor which receives WSMan client
		IPS_ScreenSettingData(ICimWsmanClient *client)
			: CIM_SettingData(client, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_SettingData::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 9);
			}
		}

		//Destructor
		virtual ~IPS_ScreenSettingData(){}

		// The "type" information for the object. Gettors only.
		virtual const string& ResourceURI() const { return CLASS_URI; }
		static const string& ClassResourceURI() { return CLASS_URI; }
		virtual const string& XmlNamespace() const { return CLASS_NS; }
		virtual const string& XmlPrefix() const { return CLASS_NS_PREFIX; }
		virtual const string& ObjectType() const { return CLASS_NAME; }
		static const string& ClassObjectType() { return CLASS_NAME; }

		// Class representing IPS_ScreenSettingData keys
		class CimKeys : public CIM_SettingData::CimKeys
		{
		public:
		};

		// class fields declarations

		// Optional, The display with the start button. When working in extended display mode, this display have (0,0) coordinates as left-upper corner
		const unsigned char PrimaryIndex() const;

		// Optional, The display with the start button. When working in extended display mode, this display have (0,0) coordinates as left-upper corner
		void PrimaryIndex(const unsigned char &value); 

		// Is true if the field PrimaryIndex exists in the current object, otherwise is false.
		bool PrimaryIndexExists() const;

		// Remove PrimaryIndex field.
		void RemovePrimaryIndex(); 

		// Optional, The secondary display according to GFX driver 
		const unsigned char SecondaryIndex() const;

		// Optional, The secondary display according to GFX driver 
		void SecondaryIndex(const unsigned char &value); 

		// Is true if the field SecondaryIndex exists in the current object, otherwise is false.
		bool SecondaryIndexExists() const;

		// Remove SecondaryIndex field.
		void RemoveSecondaryIndex(); 

		// Optional, The tertiary display according to GFX driver 
		const unsigned char TertiaryIndex() const;

		// Optional, The tertiary display according to GFX driver 
		void TertiaryIndex(const unsigned char &value); 

		// Is true if the field TertiaryIndex exists in the current object, otherwise is false.
		bool TertiaryIndexExists() const;

		// Remove TertiaryIndex field.
		void RemoveTertiaryIndex(); 

		// Optional, The quadrary display according to GFX driver 
		const unsigned char QuadraryIndex() const;

		// Optional, The quadrary display according to GFX driver 
		void QuadraryIndex(const unsigned char &value); 

		// Is true if the field QuadraryIndex exists in the current object, otherwise is false.
		bool QuadraryIndexExists() const;

		// Remove QuadraryIndex field.
		void RemoveQuadraryIndex(); 

		// Optional, Represent if screen[i] is present
		const vector<bool> IsActive() const;

		// Optional, Represent if screen[i] is present
		void IsActive(const vector<bool> &value); 

		// Is true if the field IsActive exists in the current object, otherwise is false.
		bool IsActiveExists() const;

		// Remove IsActive field.
		void RemoveIsActive(); 

		// Optional, Upper left X coordinate of screen[i]. Shall be set to 0 for primary display.Can be negative
		const vector<int> UpperLeftX() const;

		// Optional, Upper left X coordinate of screen[i]. Shall be set to 0 for primary display.Can be negative
		void UpperLeftX(const vector<int> &value); 

		// Is true if the field UpperLeftX exists in the current object, otherwise is false.
		bool UpperLeftXExists() const;

		// Remove UpperLeftX field.
		void RemoveUpperLeftX(); 

		// Optional, Upper left Y coordinate of screen[i]. Shall be set to 0 for primary display.Can be negative
		const vector<int> UpperLeftY() const;

		// Optional, Upper left Y coordinate of screen[i]. Shall be set to 0 for primary display.Can be negative
		void UpperLeftY(const vector<int> &value); 

		// Is true if the field UpperLeftY exists in the current object, otherwise is false.
		bool UpperLeftYExists() const;

		// Remove UpperLeftY field.
		void RemoveUpperLeftY(); 

		// Optional, X resolution of screen[i]
		const vector<unsigned int> ResolutionX() const;

		// Optional, X resolution of screen[i]
		void ResolutionX(const vector<unsigned int> &value); 

		// Is true if the field ResolutionX exists in the current object, otherwise is false.
		bool ResolutionXExists() const;

		// Remove ResolutionX field.
		void RemoveResolutionX(); 

		// Optional, Y resolution of screen[i]
		const vector<unsigned int> ResolutionY() const;

		// Optional, Y resolution of screen[i]
		void ResolutionY(const vector<unsigned int> &value); 

		// Is true if the field ResolutionY exists in the current object, otherwise is false.
		bool ResolutionYExists() const;

		// Remove ResolutionY field.
		void RemoveResolutionY(); 

		// This API resets the extended display configuration settings
		virtual unsigned int ResetToDefault();

		 // Function used by the factory
		static CimBase *CreateFromCimObject(const CimObject &object);

		static vector<shared_ptr<IPS_ScreenSettingData> > Enumerate(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		// Overloaded delete which supplies the internal resourceURI
		static void Delete(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		using CimBase::Delete;

	protected:
		 // Protected constructor to be used by derived classes
		IPS_ScreenSettingData(ICimWsmanClient *client, const string &class_name,
			const string &class_ns, const string &prefix, const string &uri): CIM_SettingData(client, class_name, class_ns, prefix, uri)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_SettingData::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 9);
			}
		}
		 // Protected constructor which receives CimObject
		IPS_ScreenSettingData(const CimObject &object)
			: CIM_SettingData(object)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_SettingData::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 9);
			}
		}
		// Called by derived classes
		void SetMetaData(vector<CimFieldAttribute>& childMetaData)
		{
			CIM_SettingData::SetMetaData(childMetaData);
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
#endif // IPS_SCREENSETTINGDATA_H
