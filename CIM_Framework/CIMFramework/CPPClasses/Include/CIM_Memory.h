//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       CIM_Memory.h
//
//  Contents:   Capabilities and management of Memory-related LogicalDevices.
//
//              This file was automatically generated from CIM_Memory.mof,  version: 2.8.0
//
//----------------------------------------------------------------------------
#ifndef CIM_MEMORY_H
#define CIM_MEMORY_H 1
#include "CIM_StorageExtent.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	// Capabilities and management of Memory-related LogicalDevices.
	class CIMFRAMEWORK_API CIM_Memory  : public CIM_StorageExtent
	{
	public:

		//Default constructor
		CIM_Memory()
			: CIM_StorageExtent(NULL, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_StorageExtent::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 16);
			}
		}

		//constructor which receives WSMan client
		CIM_Memory(ICimWsmanClient *client)
			: CIM_StorageExtent(client, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_StorageExtent::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 16);
			}
		}

		//Destructor
		virtual ~CIM_Memory(){}

		// The "type" information for the object. Gettors only.
		virtual const string& ResourceURI() const { return CLASS_URI; }
		static const string& ClassResourceURI() { return CLASS_URI; }
		virtual const string& XmlNamespace() const { return CLASS_NS; }
		virtual const string& XmlPrefix() const { return CLASS_NS_PREFIX; }
		virtual const string& ObjectType() const { return CLASS_NAME; }
		static const string& ClassObjectType() { return CLASS_NAME; }

		// Class representing CIM_Memory keys
		class CimKeys : public CIM_StorageExtent::CimKeys
		{
		public:
		};

		// class fields declarations

		// Optional, Volatile is a property that indicates whether this memory is volatile or not.
		const bool Volatile() const;

		// Optional, Volatile is a property that indicates whether this memory is volatile or not.
		void Volatile(const bool value); 

		// Is true if the field Volatile exists in the current object, otherwise is false.
		bool VolatileExists() const;

		// Remove Volatile field.
		void RemoveVolatile(); 

		// Optional, The beginning address, referenced by an application or operating system and mapped by a memory controller, for this Memory object. The starting address is specified in KBytes.
		const Uint64 StartingAddress() const;

		// Optional, The beginning address, referenced by an application or operating system and mapped by a memory controller, for this Memory object. The starting address is specified in KBytes.
		void StartingAddress(const Uint64 value); 

		// Is true if the field StartingAddress exists in the current object, otherwise is false.
		bool StartingAddressExists() const;

		// Remove StartingAddress field.
		void RemoveStartingAddress(); 

		// Optional, The ending address, referenced by an application or operating system and mapped by a memory controller, for this Memory object. The ending address is specified in KBytes.
		const Uint64 EndingAddress() const;

		// Optional, The ending address, referenced by an application or operating system and mapped by a memory controller, for this Memory object. The ending address is specified in KBytes.
		void EndingAddress(const Uint64 value); 

		// Is true if the field EndingAddress exists in the current object, otherwise is false.
		bool EndingAddressExists() const;

		// Remove EndingAddress field.
		void RemoveEndingAddress(); 

		// Optional, An integer enumeration describing the type of error that occurred most recently. For example, single (value=6) or double bit errors (7) can be specified using this property. The values, 12-14, are undefined in the CIM Schema since in DMI, they mix the semantics of the type of error and whether it was correctable or not. The latter is indicated in the property, CorrectableError.
		const unsigned short ErrorInfo() const;

		// Optional, An integer enumeration describing the type of error that occurred most recently. For example, single (value=6) or double bit errors (7) can be specified using this property. The values, 12-14, are undefined in the CIM Schema since in DMI, they mix the semantics of the type of error and whether it was correctable or not. The latter is indicated in the property, CorrectableError.
		void ErrorInfo(const unsigned short value); 

		// Is true if the field ErrorInfo exists in the current object, otherwise is false.
		bool ErrorInfoExists() const;

		// Remove ErrorInfo field.
		void RemoveErrorInfo(); 

		// Optional, Free form string providing more information if the Error Type property is set to 1, "Other". If not set to 1, this string has no meaning.
		const string OtherErrorDescription() const;

		// Optional, Free form string providing more information if the Error Type property is set to 1, "Other". If not set to 1, this string has no meaning.
		void OtherErrorDescription(const string &value); 

		// Is true if the field OtherErrorDescription exists in the current object, otherwise is false.
		bool OtherErrorDescriptionExists() const;

		// Remove OtherErrorDescription field.
		void RemoveOtherErrorDescription(); 

		// Optional, Boolean indicating that the most recent error was correctable. If the ErrorInfo property is equal to 3, "OK", then this property has no meaning.
		const bool CorrectableError() const;

		// Optional, Boolean indicating that the most recent error was correctable. If the ErrorInfo property is equal to 3, "OK", then this property has no meaning.
		void CorrectableError(const bool value); 

		// Is true if the field CorrectableError exists in the current object, otherwise is false.
		bool CorrectableErrorExists() const;

		// Remove CorrectableError field.
		void RemoveCorrectableError(); 

		// Optional, The time that the last memory error occurred. The type of error is described by the ErrorInfo property. If the Error Info property is equal to 3, "OK", then this property has no meaning.
		const CimDateTime ErrorTime() const;

		// Optional, The time that the last memory error occurred. The type of error is described by the ErrorInfo property. If the Error Info property is equal to 3, "OK", then this property has no meaning.
		void ErrorTime(const CimDateTime &value); 

		// Is true if the field ErrorTime exists in the current object, otherwise is false.
		bool ErrorTimeExists() const;

		// Remove ErrorTime field.
		void RemoveErrorTime(); 

		// Optional, An integer enumeration indicating the memory access operation that caused the last error. The type of error is described by the ErrorInfo property. If the ErrorInfo property is equal to 3, "OK", then this property has no meaning.
		const unsigned short ErrorAccess() const;

		// Optional, An integer enumeration indicating the memory access operation that caused the last error. The type of error is described by the ErrorInfo property. If the ErrorInfo property is equal to 3, "OK", then this property has no meaning.
		void ErrorAccess(const unsigned short value); 

		// Is true if the field ErrorAccess exists in the current object, otherwise is false.
		bool ErrorAccessExists() const;

		// Remove ErrorAccess field.
		void RemoveErrorAccess(); 

		// Optional, The size of the data transfer in bits that caused the last error. 0 indicates no error. If the ErrorInfo property is equal to 3, "OK", then this property should be set to 0.
		const unsigned int ErrorTransferSize() const;

		// Optional, The size of the data transfer in bits that caused the last error. 0 indicates no error. If the ErrorInfo property is equal to 3, "OK", then this property should be set to 0.
		void ErrorTransferSize(const unsigned int value); 

		// Is true if the field ErrorTransferSize exists in the current object, otherwise is false.
		bool ErrorTransferSizeExists() const;

		// Remove ErrorTransferSize field.
		void RemoveErrorTransferSize(); 

		// Optional, Data captured during the last erroneous mebmory access. The data occupies the first n octets of the array necessary to hold the number of bits specified by the ErrorTransferSize property. If ErrorTransferSize is 0, then this property has no meaning.
		const Base64 ErrorData() const;

		// Optional, Data captured during the last erroneous mebmory access. The data occupies the first n octets of the array necessary to hold the number of bits specified by the ErrorTransferSize property. If ErrorTransferSize is 0, then this property has no meaning.
		void ErrorData(const Base64 &value); 

		// Is true if the field ErrorData exists in the current object, otherwise is false.
		bool ErrorDataExists() const;

		// Remove ErrorData field.
		void RemoveErrorData(); 

		// Optional, The ordering for data stored in the ErrorData property. "Least Significant Byte First" (value=1) or "Most Significant Byte First" (2) can be specified. If ErrorTransferSize is 0, then this property has no meaning.
		const unsigned short ErrorDataOrder() const;

		// Optional, The ordering for data stored in the ErrorData property. "Least Significant Byte First" (value=1) or "Most Significant Byte First" (2) can be specified. If ErrorTransferSize is 0, then this property has no meaning.
		void ErrorDataOrder(const unsigned short value); 

		// Is true if the field ErrorDataOrder exists in the current object, otherwise is false.
		bool ErrorDataOrderExists() const;

		// Remove ErrorDataOrder field.
		void RemoveErrorDataOrder(); 

		// Optional, Specifies the address of the last memory error. The type of error is described by the ErrorInfo property. If the ErrorInfo property is equal to 3, "OK", then this property has no meaning.
		const Uint64 ErrorAddress() const;

		// Optional, Specifies the address of the last memory error. The type of error is described by the ErrorInfo property. If the ErrorInfo property is equal to 3, "OK", then this property has no meaning.
		void ErrorAddress(const Uint64 value); 

		// Is true if the field ErrorAddress exists in the current object, otherwise is false.
		bool ErrorAddressExists() const;

		// Remove ErrorAddress field.
		void RemoveErrorAddress(); 

		// Optional, Boolean indicating whether the address information in the property, ErrorAddress, is a system-level address (TRUE) or a physical address (FALSE). If the ErrorInfo property is equal to 3, "OK", then this property has no meaning.
		const bool SystemLevelAddress() const;

		// Optional, Boolean indicating whether the address information in the property, ErrorAddress, is a system-level address (TRUE) or a physical address (FALSE). If the ErrorInfo property is equal to 3, "OK", then this property has no meaning.
		void SystemLevelAddress(const bool value); 

		// Is true if the field SystemLevelAddress exists in the current object, otherwise is false.
		bool SystemLevelAddressExists() const;

		// Remove SystemLevelAddress field.
		void RemoveSystemLevelAddress(); 

		// Optional, Specifies the range, in bytes, to which the last error can be resolved. For example, if error addresses are resolved to bit 11 (ie, on a typical page basis), then errors can be resolved to 4K boundaries and this property is set to 4000. If the ErrorInfo property is equal to 3, "OK", then this property has no meaning.
		const Uint64 ErrorResolution() const;

		// Optional, Specifies the range, in bytes, to which the last error can be resolved. For example, if error addresses are resolved to bit 11 (ie, on a typical page basis), then errors can be resolved to 4K boundaries and this property is set to 4000. If the ErrorInfo property is equal to 3, "OK", then this property has no meaning.
		void ErrorResolution(const Uint64 value); 

		// Is true if the field ErrorResolution exists in the current object, otherwise is false.
		bool ErrorResolutionExists() const;

		// Remove ErrorResolution field.
		void RemoveErrorResolution(); 

		// Optional, An array of octets holding additional error information. An example is ECC Syndrome or the return of the check bits if a CRC-based ErrorMethodology is used. In the latter case, if a single bit error is recognized and the CRC algorithm is known, it is possible to determine the exact bit that failed. This type of data (ECC Syndrome, Check Bit or Parity Bit data, or other vendor supplied information) is included in this field. If the ErrorInfo property is equal to 3, "OK", then AdditionalErrorData has no meaning.
		const Base64 AdditionalErrorData() const;

		// Optional, An array of octets holding additional error information. An example is ECC Syndrome or the return of the check bits if a CRC-based ErrorMethodology is used. In the latter case, if a single bit error is recognized and the CRC algorithm is known, it is possible to determine the exact bit that failed. This type of data (ECC Syndrome, Check Bit or Parity Bit data, or other vendor supplied information) is included in this field. If the ErrorInfo property is equal to 3, "OK", then AdditionalErrorData has no meaning.
		void AdditionalErrorData(const Base64 &value); 

		// Is true if the field AdditionalErrorData exists in the current object, otherwise is false.
		bool AdditionalErrorDataExists() const;

		// Remove AdditionalErrorData field.
		void RemoveAdditionalErrorData(); 

		 // Function used by the factory
		static CimBase *CreateFromCimObject(const CimObject &object);

		static vector<shared_ptr<CIM_Memory> > Enumerate(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		// Overloaded delete which supplies the internal resourceURI
		static void Delete(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		using CimBase::Delete;

	protected:
		 // Protected constructor to be used by derived classes
		CIM_Memory(ICimWsmanClient *client, const string &class_name,
			const string &class_ns, const string &prefix, const string &uri): CIM_StorageExtent(client, class_name, class_ns, prefix, uri)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_StorageExtent::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 16);
			}
		}
		 // Protected constructor which receives CimObject
		CIM_Memory(const CimObject &object)
			: CIM_StorageExtent(object)
		{
			if(_classMetaData.size() == 0)
			{
				CIM_StorageExtent::SetMetaData(_classMetaData);
				CimBase::SetMetaData(_classMetaData, _metadata, 16);
			}
		}
		// Called by derived classes
		void SetMetaData(vector<CimFieldAttribute>& childMetaData)
		{
			CIM_StorageExtent::SetMetaData(childMetaData);
			CimBase::SetMetaData(childMetaData, _metadata, 16);
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
#endif // CIM_MEMORY_H
