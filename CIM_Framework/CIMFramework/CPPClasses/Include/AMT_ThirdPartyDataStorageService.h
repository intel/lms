//----------------------------------------------------------------------------
//
//  Copyright (c) Intel Corporation, 2003 - 2012  All Rights Reserved.
//
//  File:       AMT_ThirdPartyDataStorageService.h
//
//  Contents:   The ISV storage (ISVS) feature provides limited non-volatile storage services to third-party software applications running either on the local computer system host processor or on a remote system.
//
//              This file was automatically generated from AMT_ThirdPartyDataStorageService.mof,  version: 4.0.0
//
//----------------------------------------------------------------------------
#ifndef AMT_THIRDPARTYDATASTORAGESERVICE_H
#define AMT_THIRDPARTYDATASTORAGESERVICE_H 1
#include "CIM_Service.h"
namespace Intel
{
namespace Manageability
{
namespace Cim
{
namespace Typed 
{
	// The ISV storage (ISVS) feature provides limited non-volatile storage services to third-party software applications running either on the local computer system host processor or on a remote system.
	class CIMFRAMEWORK_API AMT_ThirdPartyDataStorageService  : public CIM_Service
	{
	public:

		//Default constructor
		AMT_ThirdPartyDataStorageService()
			: CIM_Service(NULL, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				_classMetaData = CIM_Service::GetMetaData();
			}
		}

		//constructor which receives WSMan client
		AMT_ThirdPartyDataStorageService(ICimWsmanClient *client)
			: CIM_Service(client, CLASS_NAME, CLASS_NS, CLASS_NS_PREFIX, CLASS_URI)
		{
			if(_classMetaData.size() == 0)
			{
				_classMetaData = CIM_Service::GetMetaData();
			}
		}

		//Destructor
		virtual ~AMT_ThirdPartyDataStorageService(){}

		// The "type" information for the object. Gettors only.
		virtual const string& ResourceURI() const { return CLASS_URI; }
		static const string& ClassResourceURI() { return CLASS_URI; }
		virtual const string& XmlNamespace() const { return CLASS_NS; }
		virtual const string& XmlPrefix() const { return CLASS_NS_PREFIX; }
		virtual const string& ObjectType() const { return CLASS_NAME; }
		static const string& ClassObjectType() { return CLASS_NAME; }

		// Class representing AMT_ThirdPartyDataStorageService keys
		class CimKeys : public CIM_Service::CimKeys
		{
		public:
		};
		//Output parameter for function GetMTU
		class CIMFRAMEWORK_API GetMTU_OUTPUT : public CimParam
		{
		public:
			// Class Constructor
			GetMTU_OUTPUT() : CimParam() {}

			// Class Destructor
			~GetMTU_OUTPUT(){}

			// class fields
			// The storage MTU (Maximum Transmission Unit).
			const unsigned int Mtu() const;
			bool MtuExists() const;
		private:
		};

		// Returns the MTU (Maximum Transmission Unit) of the storage.
		virtual unsigned int GetMTU(GetMTU_OUTPUT &output);

		//Input parameter for function RegisterApplication
		class CIMFRAMEWORK_API RegisterApplication_INPUT : public CimParam
		{
		public:
			// Class Constructor
			RegisterApplication_INPUT() : CimParam() {}

			// Class Destructor
			~RegisterApplication_INPUT(){}

			// Required, GUID String.
			void CallerUUID(const HexBinary &value); 

			// Required, The name of the vendor.
			void VendorName(const string &value); 

			// Required, The name of the ISV application.
			void ApplicationName(const string &value); 

			// Required, A pre-registered enterprise name.
			void EnterpriseName(const string &value); 

			const VectorFieldData GetAllFields() const;
		private:
			static const CimFieldAttribute _metadata[];
		};

		//Output parameter for function RegisterApplication
		class CIMFRAMEWORK_API RegisterApplication_OUTPUT : public CimParam
		{
		public:
			// Class Constructor
			RegisterApplication_OUTPUT() : CimParam() {}

			// Class Destructor
			~RegisterApplication_OUTPUT(){}

			// class fields
			// Hex String Session Handle
			const HexBinary SessionHandle() const;
			bool SessionHandleExists() const;
		private:
		};

		// Registers the application with Intel(R) AMT and returns a Session handle to the application. The application specifies this handle in subsequent ISV storage calls until it sends a new registration request (with identical information). Once an application has initially registered with unique registration information (Vendor Name, Application Name, Enterprise Name and UUID) from either the local or the remote interface, registration attempts with identical registration data from a different interface will be rejected.
		virtual unsigned int RegisterApplication(const RegisterApplication_INPUT &input, RegisterApplication_OUTPUT &output);

		//Input parameter for function UnregisterApplication
		class CIMFRAMEWORK_API UnregisterApplication_INPUT : public CimParam
		{
		public:
			// Class Constructor
			UnregisterApplication_INPUT() : CimParam() {}

			// Class Destructor
			~UnregisterApplication_INPUT(){}

			// Required, Hex String Session Handle
			void SessionHandle(const HexBinary &value); 

			const VectorFieldData GetAllFields() const;
		private:
			static const CimFieldAttribute _metadata[];
		};

		// Closes the session of a registered application, but leaves the application registered, and leaves its data intact. Any block locks that the application acquired will be released. The SessionHandle is invalidated and should not be used in subsequent ISVS operations.
		virtual unsigned int UnregisterApplication(const UnregisterApplication_INPUT &input);

		//Input parameter for function GetRegisteredApplications
		class CIMFRAMEWORK_API GetRegisteredApplications_INPUT : public CimParam
		{
		public:
			// Class Constructor
			GetRegisteredApplications_INPUT() : CimParam() {}

			// Class Destructor
			~GetRegisteredApplications_INPUT(){}

			// Required, Hex String Session Handle
			void SessionHandle(const HexBinary &value); 

			const VectorFieldData GetAllFields() const;
		private:
			static const CimFieldAttribute _metadata[];
		};

		//Output parameter for function GetRegisteredApplications
		class CIMFRAMEWORK_API GetRegisteredApplications_OUTPUT : public CimParam
		{
		public:
			// Class Constructor
			GetRegisteredApplications_OUTPUT() : CimParam() {}

			// Class Destructor
			~GetRegisteredApplications_OUTPUT(){}

			// class fields
			// An array of application handles.
			const vector<unsigned int> AppHandles() const;
			bool AppHandlesExists() const;
		private:
		};

		// Returns a list of handles for ISV applications that at some point have registered with Intel(R) AMT and were not removed. Will return only those handles of applications that have the same VendorName as the current application.
		virtual unsigned int GetRegisteredApplications(const GetRegisteredApplications_INPUT &input, GetRegisteredApplications_OUTPUT &output);

		//Input parameter for function GetCurrentApplicationHandle
		class CIMFRAMEWORK_API GetCurrentApplicationHandle_INPUT : public CimParam
		{
		public:
			// Class Constructor
			GetCurrentApplicationHandle_INPUT() : CimParam() {}

			// Class Destructor
			~GetCurrentApplicationHandle_INPUT(){}

			// Required, Hex String Session Handle
			void SessionHandle(const HexBinary &value); 

			const VectorFieldData GetAllFields() const;
		private:
			static const CimFieldAttribute _metadata[];
		};

		//Output parameter for function GetCurrentApplicationHandle
		class CIMFRAMEWORK_API GetCurrentApplicationHandle_OUTPUT : public CimParam
		{
		public:
			// Class Constructor
			GetCurrentApplicationHandle_OUTPUT() : CimParam() {}

			// Class Destructor
			~GetCurrentApplicationHandle_OUTPUT(){}

			// class fields
			// The current application handle.
			const unsigned int ApplicationHandle() const;
			bool ApplicationHandleExists() const;
		private:
		};

		// Sent by a registered ISV application to retrieve its application handle.
		virtual unsigned int GetCurrentApplicationHandle(const GetCurrentApplicationHandle_INPUT &input, GetCurrentApplicationHandle_OUTPUT &output);

		//Input parameter for function GetApplicationAttributes
		class CIMFRAMEWORK_API GetApplicationAttributes_INPUT : public CimParam
		{
		public:
			// Class Constructor
			GetApplicationAttributes_INPUT() : CimParam() {}

			// Class Destructor
			~GetApplicationAttributes_INPUT(){}

			// Required, Hex String Session Handle
			void SessionHandle(const HexBinary &value); 

			// Required, The application handle whose attributes are being requested.
			void ApplicationBeingRequested(const unsigned int value); 

			const VectorFieldData GetAllFields() const;
		private:
			static const CimFieldAttribute _metadata[];
		};

		//Output parameter for function GetApplicationAttributes
		class CIMFRAMEWORK_API GetApplicationAttributes_OUTPUT : public CimParam
		{
		public:
			// Class Constructor
			GetApplicationAttributes_OUTPUT() : CimParam() {}

			// Class Destructor
			~GetApplicationAttributes_OUTPUT(){}

			// class fields
			// The name of the vendor.
			const string VendorName() const;
			bool VendorNameExists() const;
			// The name of the ISV application.
			const string ApplicationName() const;
			bool ApplicationNameExists() const;
		private:
		};

		// Sent by a registered ISV application to get a listing of attributes for applications with the same vendor name. If no applications share the same vendor name, the function will return error code 10
		virtual unsigned int GetApplicationAttributes(const GetApplicationAttributes_INPUT &input, GetApplicationAttributes_OUTPUT &output);

		//Input parameter for function RemoveApplication
		class CIMFRAMEWORK_API RemoveApplication_INPUT : public CimParam
		{
		public:
			// Class Constructor
			RemoveApplication_INPUT() : CimParam() {}

			// Class Destructor
			~RemoveApplication_INPUT(){}

			// Required, Hex String Session Handle
			void SessionHandle(const HexBinary &value); 

			const VectorFieldData GetAllFields() const;
		private:
			static const CimFieldAttribute _metadata[];
		};

		// Un-registers an application and releases all allocated Intel(R) AMT storage resources associated with this ISV application. If the application owns any storage blocks, they are released, along with any associated permissions group resources. If the application is in the Partner Allocation Control List (PACL), the PACL entry is not removed. The application is removed from all permissions groups associated with storage blocks that are owned by other applications. The SessionHandle input is invalidated and should not be used in subsequent ISVS operations.
		virtual unsigned int RemoveApplication(const RemoveApplication_INPUT &input);

		//Input parameter for function GetBytesAvailable
		class CIMFRAMEWORK_API GetBytesAvailable_INPUT : public CimParam
		{
		public:
			// Class Constructor
			GetBytesAvailable_INPUT() : CimParam() {}

			// Class Destructor
			~GetBytesAvailable_INPUT(){}

			// Required, Hex String Session Handle
			void SessionHandle(const HexBinary &value); 

			const VectorFieldData GetAllFields() const;
		private:
			static const CimFieldAttribute _metadata[];
		};

		//Output parameter for function GetBytesAvailable
		class CIMFRAMEWORK_API GetBytesAvailable_OUTPUT : public CimParam
		{
		public:
			// Class Constructor
			GetBytesAvailable_OUTPUT() : CimParam() {}

			// Class Destructor
			~GetBytesAvailable_OUTPUT(){}

			// class fields
			// The number of bytes available for the application, identified by SessionHandle, to allocate.
			const unsigned int BytesAvailable() const;
			bool BytesAvailableExists() const;
		private:
		};

		// Sent by a registered ISV application to determine the number of bytes currently available for it to allocate.
		virtual unsigned int GetBytesAvailable(const GetBytesAvailable_INPUT &input, GetBytesAvailable_OUTPUT &output);

		//Input parameter for function AllocateBlock
		class CIMFRAMEWORK_API AllocateBlock_INPUT : public CimParam
		{
		public:
			// Class Constructor
			AllocateBlock_INPUT() : CimParam() {}

			// Class Destructor
			~AllocateBlock_INPUT(){}

			// Required, Hex String Session Handle
			void SessionHandle(const HexBinary &value); 

			// Required, The number of bytes requested by the sender must be a multiple of the Storage MTU.
			void BytesRequested(const unsigned int value); 

			// Required, The value should be TRUE if the block should be hidden from other applications, FALSE otherwise.
			void BlockHidden(const bool value); 

			// Optional, The block name.
			void BlockName(const string &value); 

			const VectorFieldData GetAllFields() const;
		private:
			static const CimFieldAttribute _metadata[];
		};

		//Output parameter for function AllocateBlock
		class CIMFRAMEWORK_API AllocateBlock_OUTPUT : public CimParam
		{
		public:
			// Class Constructor
			AllocateBlock_OUTPUT() : CimParam() {}

			// Class Destructor
			~AllocateBlock_OUTPUT(){}

			// class fields
			// The block handle that can be used to reference the block in subsequent operations.
			const unsigned int BlockHandle() const;
			bool BlockHandleExists() const;
		private:
		};

		// Sent by a registered ISV application to allocate a portion of the Intel(R) AMT non-volatile storage area, sets the block visibility and defines the block name. Once the block is allocated the application becomes the owner of the block.
		virtual unsigned int AllocateBlock(const AllocateBlock_INPUT &input, AllocateBlock_OUTPUT &output);

		//Input parameter for function DeallocateBlock
		class CIMFRAMEWORK_API DeallocateBlock_INPUT : public CimParam
		{
		public:
			// Class Constructor
			DeallocateBlock_INPUT() : CimParam() {}

			// Class Destructor
			~DeallocateBlock_INPUT(){}

			// Required, Hex String Session Handle
			void SessionHandle(const HexBinary &value); 

			// Required, Identifies the block to be de-allocated.
			void BlockHandle(const unsigned int value); 

			const VectorFieldData GetAllFields() const;
		private:
			static const CimFieldAttribute _metadata[];
		};

		// Enables an application that owns an allocated block to return it back to the system.
		virtual unsigned int DeallocateBlock(const DeallocateBlock_INPUT &input);

		//Input parameter for function RemovePermissionsGroup
		class CIMFRAMEWORK_API RemovePermissionsGroup_INPUT : public CimParam
		{
		public:
			// Class Constructor
			RemovePermissionsGroup_INPUT() : CimParam() {}

			// Class Destructor
			~RemovePermissionsGroup_INPUT(){}

			// Required, Hex String Session Handle
			void SessionHandle(const HexBinary &value); 

			// Required, Identifies the storage block that owns the group specified by GroupHandle.
			void BlockHandle(const unsigned int value); 

			// Required, Identifies the permissions group being removed.
			void GroupHandle(const unsigned int value); 

			const VectorFieldData GetAllFields() const;
		private:
			static const CimFieldAttribute _metadata[];
		};

		// Sent by a registered ISV application to remove a permissions group from a storage block. The sending application must be the owner of the block.
		virtual unsigned int RemovePermissionsGroup(const RemovePermissionsGroup_INPUT &input);

		//Input parameter for function GetPermissionsGroupMembers
		class CIMFRAMEWORK_API GetPermissionsGroupMembers_INPUT : public CimParam
		{
		public:
			// Class Constructor
			GetPermissionsGroupMembers_INPUT() : CimParam() {}

			// Class Destructor
			~GetPermissionsGroupMembers_INPUT(){}

			// Required, Hex String Session Handle
			void SessionHandle(const HexBinary &value); 

			// Required, Identifies the storage block that owns the group specified by GroupHandle.
			void BlockHandle(const unsigned int value); 

			// Required, Identifies the permissions group.
			void GroupHandle(const unsigned int value); 

			const VectorFieldData GetAllFields() const;
		private:
			static const CimFieldAttribute _metadata[];
		};

		//Output parameter for function GetPermissionsGroupMembers
		class CIMFRAMEWORK_API GetPermissionsGroupMembers_OUTPUT : public CimParam
		{
		public:
			// Class Constructor
			GetPermissionsGroupMembers_OUTPUT() : CimParam() {}

			// Class Destructor
			~GetPermissionsGroupMembers_OUTPUT(){}

			// class fields
			// An array of member handles.
			const vector<unsigned int> MemberHandles() const;
			bool MemberHandlesExists() const;
		private:
		};

		// Sent by any registered ISV application to get the list of handles of ISV applications which are members of a storage block permissions group. The members of a permissions group are registered ISV applications or generic application filters. Members of groups associated with hidden blocks will not be returned unless the originator of the call is the block owner.
		virtual unsigned int GetPermissionsGroupMembers(const GetPermissionsGroupMembers_INPUT &input, GetPermissionsGroupMembers_OUTPUT &output);

		//Input parameter for function GetAllocatedBlocks
		class CIMFRAMEWORK_API GetAllocatedBlocks_INPUT : public CimParam
		{
		public:
			// Class Constructor
			GetAllocatedBlocks_INPUT() : CimParam() {}

			// Class Destructor
			~GetAllocatedBlocks_INPUT(){}

			// Required, Hex String Session Handle
			void SessionHandle(const HexBinary &value); 

			// Required, The handle of the application whose block list is being retrieved.
			void BlockOwnerApplication(const unsigned int value); 

			const VectorFieldData GetAllFields() const;
		private:
			static const CimFieldAttribute _metadata[];
		};

		//Output parameter for function GetAllocatedBlocks
		class CIMFRAMEWORK_API GetAllocatedBlocks_OUTPUT : public CimParam
		{
		public:
			// Class Constructor
			GetAllocatedBlocks_OUTPUT() : CimParam() {}

			// Class Destructor
			~GetAllocatedBlocks_OUTPUT(){}

			// class fields
			// An array of block handles.
			const vector<unsigned int> BlockHandles() const;
			bool BlockHandlesExists() const;
		private:
		};

		// Enables an application to get a listing of block handles for those blocks allocated by a given application. Blocks allocated with "Hidden" visibility attribute will not be returned by this command unless the command is issued by the block owner, even if the requesting application has been granted I/O access on them by the owner through a permissions group.
		virtual unsigned int GetAllocatedBlocks(const GetAllocatedBlocks_INPUT &input, GetAllocatedBlocks_OUTPUT &output);

		//Input parameter for function RemovePermissionsGroupMembers
		class CIMFRAMEWORK_API RemovePermissionsGroupMembers_INPUT : public CimParam
		{
		public:
			// Class Constructor
			RemovePermissionsGroupMembers_INPUT() : CimParam() {}

			// Class Destructor
			~RemovePermissionsGroupMembers_INPUT(){}

			// Required, Hex String Session Handle
			void SessionHandle(const HexBinary &value); 

			// Required, Identifies the storage block that owns the group specified by GroupHandle.
			void BlockHandle(const unsigned int value); 

			// Required, Identifies the permissions group being modified.
			void GroupHandle(const unsigned int value); 

			// Required, An array of application handles or generic application filters.
			void MemberHandles(const vector<unsigned int> &value); 

			const VectorFieldData GetAllFields() const;
		private:
			static const CimFieldAttribute _metadata[];
		};

		// Sent by a registered ISV application to remove member applications or generic application filters from a permissions group associated with a single block of ISV storage. The sending application must be the owner of the block.
		virtual unsigned int RemovePermissionsGroupMembers(const RemovePermissionsGroupMembers_INPUT &input);

		//Input parameter for function GetBlockAttributes
		class CIMFRAMEWORK_API GetBlockAttributes_INPUT : public CimParam
		{
		public:
			// Class Constructor
			GetBlockAttributes_INPUT() : CimParam() {}

			// Class Destructor
			~GetBlockAttributes_INPUT(){}

			// Required, Hex String Session Handle
			void SessionHandle(const HexBinary &value); 

			// Required, Identifies the block whose attributes are being requested.
			void BlockHandle(const unsigned int value); 

			const VectorFieldData GetAllFields() const;
		private:
			static const CimFieldAttribute _metadata[];
		};

		//Output parameter for function GetBlockAttributes
		class CIMFRAMEWORK_API GetBlockAttributes_OUTPUT : public CimParam
		{
		public:
			// Class Constructor
			GetBlockAttributes_OUTPUT() : CimParam() {}

			// Class Destructor
			~GetBlockAttributes_OUTPUT(){}

			// class fields
			// The size of the block in bytes.
			const unsigned int BlockSize() const;
			bool BlockSizeExists() const;
			// TRUE if block is hidden from other applications, FALSE otherwise.
			const bool BlockHidden() const;
			bool BlockHiddenExists() const;
			// An optional name for the block, set by the owner.
			const string BlockName() const;
			bool BlockNameExists() const;
		private:
		};

		// Enables an application to get a listing of attributes for a single allocated block. Blocks allocated with the "Hidden" visibility attribute will not appear in this command unless the command is issued by the block owner.
		virtual unsigned int GetBlockAttributes(const GetBlockAttributes_INPUT &input, GetBlockAttributes_OUTPUT &output);

		//Input parameter for function AddPermissionsGroupMembers
		class CIMFRAMEWORK_API AddPermissionsGroupMembers_INPUT : public CimParam
		{
		public:
			// Class Constructor
			AddPermissionsGroupMembers_INPUT() : CimParam() {}

			// Class Destructor
			~AddPermissionsGroupMembers_INPUT(){}

			// Required, Hex String Session Handle
			void SessionHandle(const HexBinary &value); 

			// Required, Identifies the storage block that owns the group specified by GroupHandle.
			void BlockHandle(const unsigned int value); 

			// Required, Identifies the permissions group being modified.
			void GroupHandle(const unsigned int value); 

			// Required, An array of application handles or generic application filters.
			void MemberHandles(const vector<unsigned int> &value); 

			const VectorFieldData GetAllFields() const;
		private:
			static const CimFieldAttribute _metadata[];
		};

		// Sent by a registered ISV application to add member applications or generic application filters to a permissions group associated with a single block of ISV storage. The sending application must be the owner of the block.
		virtual unsigned int AddPermissionsGroupMembers(const AddPermissionsGroupMembers_INPUT &input);

		//Input parameter for function UnlockBlock
		class CIMFRAMEWORK_API UnlockBlock_INPUT : public CimParam
		{
		public:
			// Class Constructor
			UnlockBlock_INPUT() : CimParam() {}

			// Class Destructor
			~UnlockBlock_INPUT(){}

			// Required, Hex String Session Handle
			void SessionHandle(const HexBinary &value); 

			// Required, Identifies the allocated block of ISV storage being unlocked.
			void BlockHandle(const unsigned int value); 

			const VectorFieldData GetAllFields() const;
		private:
			static const CimFieldAttribute _metadata[];
		};

		// Enables an application to remove a lock from a block of non-volatile memory so that other applications may access the allocated block for read or write operations. The sending application must have at least read permissions for the block. An application can not unlock a block which was locked by another application.
		virtual unsigned int UnlockBlock(const UnlockBlock_INPUT &input);

		//Input parameter for function SetPermissionsGroupName
		class CIMFRAMEWORK_API SetPermissionsGroupName_INPUT : public CimParam
		{
		public:
			// Class Constructor
			SetPermissionsGroupName_INPUT() : CimParam() {}

			// Class Destructor
			~SetPermissionsGroupName_INPUT(){}

			// Required, Hex String Session Handle
			void SessionHandle(const HexBinary &value); 

			// Required, Identifies the storage block that owns the group specified by GroupHandle.
			void BlockHandle(const unsigned int value); 

			// Required, Identifies the permissions group whose name is being modified.
			void GroupHandle(const unsigned int value); 

			// Required, The name assigned to the permissions group.
			void GroupName(const string &value); 

			const VectorFieldData GetAllFields() const;
		private:
			static const CimFieldAttribute _metadata[];
		};

		// Sent by a registered ISV application to set the name of a storage block permissions group. The sending application must be the owner of the block.
		virtual unsigned int SetPermissionsGroupName(const SetPermissionsGroupName_INPUT &input);

		//Output parameter for function GetTimeoutValues
		class CIMFRAMEWORK_API GetTimeoutValues_OUTPUT : public CimParam
		{
		public:
			// Class Constructor
			GetTimeoutValues_OUTPUT() : CimParam() {}

			// Class Destructor
			~GetTimeoutValues_OUTPUT(){}

			// class fields
			// Time, in seconds, after which an idle registered application is automatically un-registered by the Intel(R) AMT device. The actions which are performed after the timeout has elapsed are similar to the actions which are performed by the UnregisterApplication method.
			const unsigned int RegistrationTimeout() const;
			bool RegistrationTimeoutExists() const;
			// Time, in seconds, after which an idle locked block is automatically unlocked by the Intel(R) AMT device to avoid deadlocks. The following operations reset the expiration timer of the block they operate on: ReadBlock, WriteBlock, LockBlock..
			const unsigned int LockTimeout() const;
			bool LockTimeoutExists() const;
		private:
		};

		// Sent by an ISV application to get the timeout values used by the Intel(R) AMT device for idle registered applications and idle locked blocks.
		virtual unsigned int GetTimeoutValues(GetTimeoutValues_OUTPUT &output);

		//Input parameter for function ReadBlock
		class CIMFRAMEWORK_API ReadBlock_INPUT : public CimParam
		{
		public:
			// Class Constructor
			ReadBlock_INPUT() : CimParam() {}

			// Class Destructor
			~ReadBlock_INPUT(){}

			// Required, Hex String Session Handle
			void SessionHandle(const HexBinary &value); 

			// Required, Identifies the block from which data will be retrieved.
			void BlockHandle(const unsigned int value); 

			// Required, The byte offset - relative to the first byte of the block - from which the first byte of Data is to be retrieved.
			void ByteOffset(const unsigned int value); 

			// Required, The number of bytes to read.
			void ByteCount(const unsigned int value); 

			const VectorFieldData GetAllFields() const;
		private:
			static const CimFieldAttribute _metadata[];
		};

		//Output parameter for function ReadBlock
		class CIMFRAMEWORK_API ReadBlock_OUTPUT : public CimParam
		{
		public:
			// Class Constructor
			ReadBlock_OUTPUT() : CimParam() {}

			// Class Destructor
			~ReadBlock_OUTPUT(){}

			// class fields
			// Binary Data
			const Base64 Data() const;
			bool DataExists() const;
		private:
		};

		// Sent by a registered ISV application to retrieve data previously stored in a block of local nonvolatile memory. The data is transparent to Intel(R) AMT and is treated as an unformatted sequence of bytes. The requesting application must have read permissions for the block.
		virtual unsigned int ReadBlock(const ReadBlock_INPUT &input, ReadBlock_OUTPUT &output);

		//Input parameter for function WriteBlock
		class CIMFRAMEWORK_API WriteBlock_INPUT : public CimParam
		{
		public:
			// Class Constructor
			WriteBlock_INPUT() : CimParam() {}

			// Class Destructor
			~WriteBlock_INPUT(){}

			// Required, Hex String Session Handle
			void SessionHandle(const HexBinary &value); 

			// Required, Identifies the block in which Data will be stored.
			void BlockHandle(const unsigned int value); 

			// Required, The byte offset - relative to the first byte of the block - at which the first byte of Data is to be stored.
			void ByteOffset(const unsigned int value); 

			// Required, Binary Data
			void Data(const Base64 &value); 

			const VectorFieldData GetAllFields() const;
		private:
			static const CimFieldAttribute _metadata[];
		};

		//Output parameter for function WriteBlock
		class CIMFRAMEWORK_API WriteBlock_OUTPUT : public CimParam
		{
		public:
			// Class Constructor
			WriteBlock_OUTPUT() : CimParam() {}

			// Class Destructor
			~WriteBlock_OUTPUT(){}

			// class fields
			// The number of bytes, from Data that were actually stored by this operation. Note: This value is valid on any return status, it may indicate that partial data was modified although return value is not PT_STATUS_SUCCESS.
			const unsigned int BytesWritten() const;
			bool BytesWrittenExists() const;
		private:
		};

		// Enables an application with proper permissions to write data to an allocated block. The data is transparent to Intel(R) AMT and is stored without modification.
		virtual unsigned int WriteBlock(const WriteBlock_INPUT &input, WriteBlock_OUTPUT &output);

		//Input parameter for function SetPermissionsGroupPermissions
		class CIMFRAMEWORK_API SetPermissionsGroupPermissions_INPUT : public CimParam
		{
		public:
			// Class Constructor
			SetPermissionsGroupPermissions_INPUT() : CimParam() {}

			// Class Destructor
			~SetPermissionsGroupPermissions_INPUT(){}

			// Required, Hex String Session Handle
			void SessionHandle(const HexBinary &value); 

			// Required, Identifies the storage block that owns the group specified by GroupHandle.
			void BlockHandle(const unsigned int value); 

			// Required, Identifies the permissions group whose permissions are being modified.
			void GroupHandle(const unsigned int value); 

			// Required, The permission flag settings to be applied. A value of 1 indicates read permissions, a value of 2 indicates read-write permissions.
			void Permissions(const unsigned int value); 

			const VectorFieldData GetAllFields() const;
		private:
			static const CimFieldAttribute _metadata[];
		};

		// Sent by a registered ISV application to set the permission flags for a storage block permissions group. The sending application must be the owner of the block.
		virtual unsigned int SetPermissionsGroupPermissions(const SetPermissionsGroupPermissions_INPUT &input);

		//Input parameter for function SetBlockVisibility
		class CIMFRAMEWORK_API SetBlockVisibility_INPUT : public CimParam
		{
		public:
			// Class Constructor
			SetBlockVisibility_INPUT() : CimParam() {}

			// Class Destructor
			~SetBlockVisibility_INPUT(){}

			// Required, Hex String Session Handle
			void SessionHandle(const HexBinary &value); 

			// Required, Identifies the block being modified.
			void BlockHandle(const unsigned int value); 

			// Required, If TRUE, block will be hidden from other applications; if FALSE, block will be visible to other applications.
			void BlockHidden(const bool value); 

			const VectorFieldData GetAllFields() const;
		private:
			static const CimFieldAttribute _metadata[];
		};

		// Enables an application that owns an allocated memory block to set the block visibility attribute. When a memory block is hidden it will not be listed when other applications call GetAllocatedBlocks with the handle of the block owner. Other applications which attempt to perform operations on a hidden block will recieve the error PT_STATUS_BLOCK_DOES_NOT_EXIST. Applications which are members of a permissions-group associated with a "hidden block" are still granted the access permission for the block (e.g. read the data in the block). In addition to setting the block visibility, the owner must not assign I/O access permissions to other applications if it wishes to completely deny access to the block's data and attributes.
		virtual unsigned int SetBlockVisibility(const SetBlockVisibility_INPUT &input);

		//Input parameter for function GetPermissionsGroupAttributes
		class CIMFRAMEWORK_API GetPermissionsGroupAttributes_INPUT : public CimParam
		{
		public:
			// Class Constructor
			GetPermissionsGroupAttributes_INPUT() : CimParam() {}

			// Class Destructor
			~GetPermissionsGroupAttributes_INPUT(){}

			// Required, Hex String Session Handle
			void SessionHandle(const HexBinary &value); 

			// Required, Identifies the storage block that owns the group specified by GroupHandle.
			void BlockHandle(const unsigned int value); 

			// Required, Identifies the permissions group whose attributes are being requested.
			void GroupHandle(const unsigned int value); 

			const VectorFieldData GetAllFields() const;
		private:
			static const CimFieldAttribute _metadata[];
		};

		//Output parameter for function GetPermissionsGroupAttributes
		class CIMFRAMEWORK_API GetPermissionsGroupAttributes_OUTPUT : public CimParam
		{
		public:
			// Class Constructor
			GetPermissionsGroupAttributes_OUTPUT() : CimParam() {}

			// Class Destructor
			~GetPermissionsGroupAttributes_OUTPUT(){}

			// class fields
			// Name of the permissions group.
			const string Name() const;
			bool NameExists() const;
			// The permission flags for this group. A value of 1 indicates read permissions, a value of 2 indicates read-write permissions.
			const unsigned int Permissions() const;
			bool PermissionsExists() const;
		private:
		};

		// Sent by a registered ISV application to get the attributes for a single permissions group. Only the block owner may request this operation for a group that is associated with a hidden block. Any registered application may request this operation for a group that is associated with a visible block.
		virtual unsigned int GetPermissionsGroupAttributes(const GetPermissionsGroupAttributes_INPUT &input, GetPermissionsGroupAttributes_OUTPUT &output);

		//Input parameter for function GetPermissionsGroups
		class CIMFRAMEWORK_API GetPermissionsGroups_INPUT : public CimParam
		{
		public:
			// Class Constructor
			GetPermissionsGroups_INPUT() : CimParam() {}

			// Class Destructor
			~GetPermissionsGroups_INPUT(){}

			// Required, Hex String Session Handle
			void SessionHandle(const HexBinary &value); 

			// Required, Identifies the storage block whose permissions groups are being requested.
			void BlockHandle(const unsigned int value); 

			const VectorFieldData GetAllFields() const;
		private:
			static const CimFieldAttribute _metadata[];
		};

		//Output parameter for function GetPermissionsGroups
		class CIMFRAMEWORK_API GetPermissionsGroups_OUTPUT : public CimParam
		{
		public:
			// Class Constructor
			GetPermissionsGroups_OUTPUT() : CimParam() {}

			// Class Destructor
			~GetPermissionsGroups_OUTPUT(){}

			// class fields
			// An array of group handles.
			const vector<unsigned int> GroupHandles() const;
			bool GroupHandlesExists() const;
		private:
		};

		// Sent by a registered ISV application to get a list of handles of the permissions groups currently defined for a block of ISV storage. Only the block owner may request this operation for a hidden block. Any registered application may request this operation for a visible block.
		virtual unsigned int GetPermissionsGroups(const GetPermissionsGroups_INPUT &input, GetPermissionsGroups_OUTPUT &output);

		//Input parameter for function SetBlockName
		class CIMFRAMEWORK_API SetBlockName_INPUT : public CimParam
		{
		public:
			// Class Constructor
			SetBlockName_INPUT() : CimParam() {}

			// Class Destructor
			~SetBlockName_INPUT(){}

			// Required, Hex String Session Handle
			void SessionHandle(const HexBinary &value); 

			// Required, Identifies the allocated block of ISV storage being named.
			void BlockHandle(const unsigned int value); 

			// Required, The name being assigned to the storage block.
			void BlockName(const string &value); 

			const VectorFieldData GetAllFields() const;
		private:
			static const CimFieldAttribute _metadata[];
		};

		// Enables an application that owns an allocated block to modify the block's name.
		virtual unsigned int SetBlockName(const SetBlockName_INPUT &input);

		//Input parameter for function AddPermissionsGroup
		class CIMFRAMEWORK_API AddPermissionsGroup_INPUT : public CimParam
		{
		public:
			// Class Constructor
			AddPermissionsGroup_INPUT() : CimParam() {}

			// Class Destructor
			~AddPermissionsGroup_INPUT(){}

			// Required, Hex String Session Handle
			void SessionHandle(const HexBinary &value); 

			// Required, Identifies the storage block which the permissions group will be associated to.
			void BlockHandle(const unsigned int value); 

			// Required, The permission flags for this group, which only apply to this storage block.
			void GroupPermissions(const unsigned int value); 

			// Optional, An optional name that the sender can assign to this group.
			void GroupName(const string &value); 

			const VectorFieldData GetAllFields() const;
		private:
			static const CimFieldAttribute _metadata[];
		};

		//Output parameter for function AddPermissionsGroup
		class CIMFRAMEWORK_API AddPermissionsGroup_OUTPUT : public CimParam
		{
		public:
			// Class Constructor
			AddPermissionsGroup_OUTPUT() : CimParam() {}

			// Class Destructor
			~AddPermissionsGroup_OUTPUT(){}

			// class fields
			// A group handle generated by Intel(R) AMT - used to reference the group in other Intel(R) AMT non-volatile storage operations.
			const unsigned int GroupHandle() const;
			bool GroupHandleExists() const;
		private:
		};

		// Sent by a registered ISV application to associate a permissions group with a block of ISV storage, set its initial permissions value, and define its name. Each permissions group has its own set of permissions. Each member of a permission group is an application with a unique Application Handle. A permissions group can be used to establish different storage roles for different applications from the same ISV. Each permissions group is associated with exactly one block. The sending application must be the owner of the block.
		virtual unsigned int AddPermissionsGroup(const AddPermissionsGroup_INPUT &input, AddPermissionsGroup_OUTPUT &output);

		//Input parameter for function LockBlock
		class CIMFRAMEWORK_API LockBlock_INPUT : public CimParam
		{
		public:
			// Class Constructor
			LockBlock_INPUT() : CimParam() {}

			// Class Destructor
			~LockBlock_INPUT(){}

			// Required, Hex String Session Handle
			void SessionHandle(const HexBinary &value); 

			// Required, Identifies the allocated block of ISV storage being locked.
			void BlockHandle(const unsigned int value); 

			const VectorFieldData GetAllFields() const;
		private:
			static const CimFieldAttribute _metadata[];
		};

		// Sent by a registered ISV application to lock a block of non-volatile memory, thereby preventing other applications from reading or writing the block's data. If the request succeeds, the requesting application will own the block's lock until it explicitly releases it with an UnlockBlock request, or until an inactivity timer expires, whichever occurs first. Also, if the application session terminates, the lock is also removed. The lock does not prevent the block from being de-allocated. If the owner of a block de-allocates it while another application holds the lock, the lock is destroyed with the block. An application can not lock a block while it is already locked by another application. The sending application must have at least read permission for the block. As a lock operation following a lock operation performed on the same block, executed by the same application would succeed, this operation can not be used to synchronize operation between multiple application threads.
		virtual unsigned int LockBlock(const LockBlock_INPUT &input);

		//Output parameter for function GetWriteEraseLimit
		class CIMFRAMEWORK_API GetWriteEraseLimit_OUTPUT : public CimParam
		{
		public:
			// Class Constructor
			GetWriteEraseLimit_OUTPUT() : CimParam() {}

			// Class Destructor
			~GetWriteEraseLimit_OUTPUT(){}

			// class fields
			// This value indicates the number of write operations that are guaranteed to succeed before the Flash wear-out protection mechanism will disable subsequent write operations.
			const unsigned int WriteEraseLimit() const;
			bool WriteEraseLimitExists() const;
		private:
		};

		// Returns the number of currently available write operations.
		virtual unsigned int GetWriteEraseLimit(GetWriteEraseLimit_OUTPUT &output);

		 // Function used by the factory
		static CimBase *CreateFromCimObject(const CimObject &object);

		static vector<shared_ptr<AMT_ThirdPartyDataStorageService> > Enumerate(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		// Overloaded delete which supplies the internal resourceURI
		static void Delete(ICimWsmanClient *client, const CimKeys &keys = CimKeys()) ;

		using CimBase::Delete;

	protected:
		 // Protected constructor to be used by derived classes
		AMT_ThirdPartyDataStorageService(ICimWsmanClient *client, const string &class_name,
			const string &class_ns, const string &prefix, const string &uri): CIM_Service(client, class_name, class_ns, prefix, uri)
		{
			if(_classMetaData.size() == 0)
			{
				_classMetaData = CIM_Service::GetMetaData();
			}
		}
		 // Protected constructor which receives CimObject
		AMT_ThirdPartyDataStorageService(const CimObject &object)
			: CIM_Service(object)
		{
			if(_classMetaData.size() == 0)
			{
				_classMetaData = CIM_Service::GetMetaData();
			}
		}
		// Called by derived classes
		void SetMetaData(vector<CimFieldAttribute>& childMetaData)
		{
			CIM_Service::SetMetaData(childMetaData);
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
#endif // AMT_THIRDPARTYDATASTORAGESERVICE_H
