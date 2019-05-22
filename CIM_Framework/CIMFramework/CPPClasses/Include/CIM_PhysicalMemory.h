//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_PhysicalMemory.h
//
//  Contents:   PhysicalMemory is a subclass of CIM_Chip, representing low level memory devices - SIMMS, DIMMs, raw memory chips, etc.
//
//              This file was automatically generated from CIM_PhysicalMemory.mof,  version: 2.33.0
//
//----------------------------------------------------------------------------
#ifndef CIM_PHYSICALMEMORY_H
#define CIM_PHYSICALMEMORY_H 1
#include "CIM_Chip.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	// PhysicalMemory is a subclass of CIM_Chip, representing low level memory devices - SIMMS, DIMMs, raw memory chips, etc.
	class CIMFRAMEWORK_API CIM_PhysicalMemory  : public CIM_Chip
	{
	public:

		//Default constructor
		CIM_PhysicalMemory()
			: CIM_Chip(NULL, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_Chip::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 12);
			}
		}

		//constructor which receives WSMan client
		CIM_PhysicalMemory(ICimWsmanClient *client)
			: CIM_Chip(client, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_Chip::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 12);
			}
		}

		//Destructor
		virtual ~CIM_PhysicalMemory(){}

		// The "type" information for the object. Gettors only.
		virtual const string& ResourceURI() const { return CLASS_URI; }
		static const string& ClassResourceURI() { return CLASS_URI; }
		virtual const string& XmlNamespace() const { return CLASS_NS; }
		virtual const string& XmlPrefix() const { return CLASS_NS_PREFIX; }
		virtual const string& ObjectType() const { return CLASS_NAME; }
		static const string& ClassObjectType() { return CLASS_NAME; }

		// Class representing CIM_PhysicalMemory keys
		class CimKeys : public CIM_Chip::CimKeys
		{
		public:
		};

		// class fields declarations

		// Optional, The type of PhysicalMemory. Synchronous DRAM is also known as SDRAM Cache DRAM is also known as CDRAM CDRAM is also known as Cache DRAM SDRAM is also known as Synchronous DRAM BRAM is also known as Block RAM
		const unsigned short MemoryType() const;

		// Optional, The type of PhysicalMemory. Synchronous DRAM is also known as SDRAM Cache DRAM is also known as CDRAM CDRAM is also known as Cache DRAM SDRAM is also known as Synchronous DRAM BRAM is also known as Block RAM
		void MemoryType(const unsigned short value); 

		// Is true if the field MemoryType exists in the current object, otherwise is false.
		bool MemoryTypeExists() const;

		// Remove MemoryType field.
		void RemoveMemoryType(); 

		// Optional, Total width, in bits, of the PhysicalMemory, including check or error correction bits. If there are no error correction bits, the value in this property should match that specified for DataWidth.
		const unsigned short TotalWidth() const;

		// Optional, Total width, in bits, of the PhysicalMemory, including check or error correction bits. If there are no error correction bits, the value in this property should match that specified for DataWidth.
		void TotalWidth(const unsigned short value); 

		// Is true if the field TotalWidth exists in the current object, otherwise is false.
		bool TotalWidthExists() const;

		// Remove TotalWidth field.
		void RemoveTotalWidth(); 

		// Optional, Data width of the PhysicalMemory, in bits. A data width of 0 and a TotalWidth of 8 would indicate that the Memory is solely used to provide error correction bits.
		const unsigned short DataWidth() const;

		// Optional, Data width of the PhysicalMemory, in bits. A data width of 0 and a TotalWidth of 8 would indicate that the Memory is solely used to provide error correction bits.
		void DataWidth(const unsigned short value); 

		// Is true if the field DataWidth exists in the current object, otherwise is false.
		bool DataWidthExists() const;

		// Remove DataWidth field.
		void RemoveDataWidth(); 

		// Optional, The speed of the PhysicalMemory, in nanoseconds.
		const unsigned int Speed() const;

		// Optional, The speed of the PhysicalMemory, in nanoseconds.
		void Speed(const unsigned int value); 

		// Is true if the field Speed exists in the current object, otherwise is false.
		bool SpeedExists() const;

		// Remove Speed field.
		void RemoveSpeed(); 

		// Optional, The total capacity of this PhysicalMemory, in bytes.
		const Uint64 Capacity() const;

		// Optional, The total capacity of this PhysicalMemory, in bytes.
		void Capacity(const Uint64 value); 

		// Is true if the field Capacity exists in the current object, otherwise is false.
		bool CapacityExists() const;

		// Remove Capacity field.
		void RemoveCapacity(); 

		// Optional, A string identifying the physically labeled bank where the Memory is located - for example, 'Bank 0' or 'Bank A'.
		const string BankLabel() const;

		// Optional, A string identifying the physically labeled bank where the Memory is located - for example, 'Bank 0' or 'Bank A'.
		void BankLabel(const string &value); 

		// Is true if the field BankLabel exists in the current object, otherwise is false.
		bool BankLabelExists() const;

		// Remove BankLabel field.
		void RemoveBankLabel(); 

		// Optional, Specifies the position of the PhysicalMemory in a 'row'. For example, if it takes two 8-bit memory devices to form a 16- bit row, then a value of '2'means that this Memory is the second device. 0 is an invalid value for this property.
		const unsigned int PositionInRow() const;

		// Optional, Specifies the position of the PhysicalMemory in a 'row'. For example, if it takes two 8-bit memory devices to form a 16- bit row, then a value of '2'means that this Memory is the second device. 0 is an invalid value for this property.
		void PositionInRow(const unsigned int value); 

		// Is true if the field PositionInRow exists in the current object, otherwise is false.
		bool PositionInRowExists() const;

		// Remove PositionInRow field.
		void RemovePositionInRow(); 

		// Optional, The position of this PhysicalMemory in an interleave. 0 indicates non-interleaved. 1 indicates the first position, 2 the second position and so on. For example, in a 2:1 interleave, a value of '1' would indicate that the Memory is in the 'even' position.
		const unsigned int InterleavePosition() const;

		// Optional, The position of this PhysicalMemory in an interleave. 0 indicates non-interleaved. 1 indicates the first position, 2 the second position and so on. For example, in a 2:1 interleave, a value of '1' would indicate that the Memory is in the 'even' position.
		void InterleavePosition(const unsigned int value); 

		// Is true if the field InterleavePosition exists in the current object, otherwise is false.
		bool InterleavePositionExists() const;

		// Remove InterleavePosition field.
		void RemoveInterleavePosition(); 

		// Optional, The configured clock speed (in MHz) of PhysicalMemory.
		const unsigned int ConfiguredMemoryClockSpeed() const;

		// Optional, The configured clock speed (in MHz) of PhysicalMemory.
		void ConfiguredMemoryClockSpeed(const unsigned int value); 

		// Is true if the field ConfiguredMemoryClockSpeed exists in the current object, otherwise is false.
		bool ConfiguredMemoryClockSpeedExists() const;

		// Remove ConfiguredMemoryClockSpeed field.
		void RemoveConfiguredMemoryClockSpeed(); 

		// Optional, The IsSpeedInMHz property is used to indicate if the Speed property or the MaxMemorySpeed contains the value of the memory speed. A value of TRUE shall indicate that the speed is represented by the MaxMemorySpeed property. A value of FALSE shall indicate that the speed is represented by the Speed property.
		const bool IsSpeedInMhz() const;

		// Optional, The IsSpeedInMHz property is used to indicate if the Speed property or the MaxMemorySpeed contains the value of the memory speed. A value of TRUE shall indicate that the speed is represented by the MaxMemorySpeed property. A value of FALSE shall indicate that the speed is represented by the Speed property.
		void IsSpeedInMhz(const bool value); 

		// Is true if the field IsSpeedInMhz exists in the current object, otherwise is false.
		bool IsSpeedInMhzExists() const;

		// Remove IsSpeedInMhz field.
		void RemoveIsSpeedInMhz(); 

		// Optional, The maximum speed (in MHz) of PhysicalMemory.
		const unsigned int MaxMemorySpeed() const;

		// Optional, The maximum speed (in MHz) of PhysicalMemory.
		void MaxMemorySpeed(const unsigned int value); 

		// Is true if the field MaxMemorySpeed exists in the current object, otherwise is false.
		bool MaxMemorySpeedExists() const;

		// Remove MaxMemorySpeed field.
		void RemoveMaxMemorySpeed(); 

		 // Function used by the factory
		static CimBase *CreateFromCimObject(const CimObject &object);

		static vector<shared_ptr<CIM_PhysicalMemory> > Enumerate(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		// Overloaded delete which supplies the internal resourceURI
		static void Delete(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		using CimBase::Delete;

	protected:
		 // Protected constructor to be used by derived classes
		CIM_PhysicalMemory(ICimWsmanClient *client, const string &class_name,
			const string &class_ns, const string &prefix, const string &uri): CIM_Chip(client, class_name, class_ns, prefix, uri)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_Chip::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 12);
			}
		}
		 // Protected constructor which receives CimObject
		CIM_PhysicalMemory(const CimObject &object)
			: CIM_Chip(object)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_Chip::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 12);
			}
		}
		// Called by derived classes
		void SetMetaData(vector<CimFieldAttribute>& childMetaData)
		{
			CIM_Chip::SetMetaData(childMetaData);
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
#endif // CIM_PHYSICALMEMORY_H
