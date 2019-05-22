/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2007-2019 Intel Corporation
 */
/*++

File Name:
   FWUpdateLib.h

Abstract:
   Handles full and partial firmware updates via HECI.

Author:
Inies Chemmannoor

--*/

#ifndef __FW_UPDATE_LIB_ME10_H__
#define __FW_UPDATE_LIB_ME10_H__

typedef struct __UUID
{
	unsigned long  Data1;
	unsigned short Data2;
	unsigned short Data3;
	unsigned char  Data4[8];
} _UUID;

typedef struct _FWU_INFO_FLAGS
{
	uint32_t RecoveryMode : 2;   // 0 = No recovery; 1 = Full Recovery Mode,2 = Partial Recovery Mode
	uint32_t IpuNeeded : 1;      // IPU_NEEDED bit, if set we are in IPU_NEEDED state.
	uint32_t FwInitDone : 1;     // If set indicate FW is done initialized
	uint32_t FwuInProgress : 1;  // If set FWU is in progress, this will be set for IFU update as well
	uint32_t SuInprogress : 1;   // If set IFU Safe FW update is in progress. 
	uint32_t NewFtTestS : 1;     // If set indicate that the new FT image is in Test Needed state (Stage 2 Boot)
	uint32_t SafeBootCnt : 4;    // Boot count before the operation is success
	uint32_t FsbFlag : 1;        // Force Safe Boot Flag, when this bit is set, we'll boot kernel only and go into recovery mode	

	//////////////////////////////////////////////////////
	// These fields below are important for FWU tool. 
	//////////////////////////////////////////////////////
	uint32_t LivePingNeeded : 1;     // Use for IFU only, See Below  
								 // FWU tool needs to send Live-Ping or perform querying to confirm update successful.
								 // With the current implementation when LivePingNeeded is set, 
								 // Kernel had already confirmed it. No action from the tool is needed.
	uint32_t ResumeUpdateNeeded : 1; // Use for IFU only, If set FWU tool needs to resend update image
	uint32_t RollbackNeededMode : 2; // FWU_ROLLBACK_NONE = 0, FWU_ROLLBACK_1, FWU_ROLLBACK_2 
								 // If not FWU_ROLLBACK_NONE, FWU tool needs to send restore_point image. 
	uint32_t ResetNeeded : 2;        // When this field is set to ME_RESET_REQUIRED, FW Kernel will
								 // perform ME_RESET after this message. No action from the tool is needed.
	uint32_t SuState : 4;		    // See possible values below
	uint32_t RecoveryCause : 2;      // IMAGE_CODE_INVALID = 1; IMAGE_NFT_INVALID = 2;
	uint32_t Reserve : 8;
}FWU_INFO_FLAGS;

typedef uint32_t STATUS;

typedef struct _PT_ATTRB
{
	uint32_t   PtNameId;      // HW_COMP_HDR_STRUCTID_WCOD     0x244f4357 OR 
							// HW_COMP_HDR_STRUCTID_LOCL     0x4C434F4C OR
							// HW_COMP_HDR_STRUCTID_MDMV     0x564D444D 
	uint32_t   LoadAddress;         // Load Address of the IPU
	VERSION  FwVer;         // FW version from IUP Manifest
	uint32_t   CurrentInstId; // Current Inst ID from flash, 0 indicate invalid ID 
	uint32_t   CurrentUpvVer; // Upper sig 16 bits are Major Version.
	uint32_t   ExpectedInstId;// Expected Inst ID that need to be updated to
	uint32_t   ExpectedUpvVer;// Upper sig 16 bits are Major Version.
	uint32_t   Resv[4];
}PT_ATTRB;

typedef struct _FWU_GET_IPU_PT_ATTRB_MSG_REPLY
{
	uint32_t   MessageType;      // Internal FWU tool use only
	STATUS   Status;           // Internal FWU tool use only
	VERSION  FtpFwVer;         // FW version in Fault Tolerance Partition. 
							   // This might be used for diagnostic or debug.
	uint32_t   SizeoOfPtAttrib;  // Size in bytes. Simply is the sizeof (PT_ATTRB structure)
	uint32_t   NumOfPartition;   // Number of partition actually return in this reply message
	PT_ATTRB  PtAttribute[MAXIMUM_IPU_SUPPORTED];
	uint32_t   Resv[4];
}FWU_GET_IPU_PT_ATTRB_MSG_REPLY;

//below structure is defiend by the fw team
//in fwucommon.h file
typedef struct _UPDATE_FLAGS_LIB
{
	unsigned int RestorePoint : 1;           // If set indicate restore point
	unsigned int RestartOperation : 1;       // If set indicate restart operation, like lost hard drive etc...
	unsigned int UserRollback : 1;			// indicates user has initiated a rollback
	unsigned int Reserve : 29;               //
}UPDATE_FLAGS_LIB;

//Should be used by both tool and UNS to retrieve the Updated UPV version
typedef struct _IPU_UPDATED_INFO
{
	unsigned int UpdatedUpvVer;//Version from the update image file that is for updating IPU
	unsigned int Reserved[4];
}IPU_UPDATED_INFO;

#ifdef __cplusplus
extern "C" {
#endif

#define DllExport __declspec(dllexport)

	DllExport unsigned int GetLastUpdateResetType(unsigned int *lastResetType);

	DllExport unsigned int GetIpuPartitionAttributes(FWU_GET_IPU_PT_ATTRB_MSG_REPLY *FwuGetIpuAttrbMsgInfo);

	DllExport unsigned int GetFwUpdateInfoStatus(FWU_INFO_FLAGS *StatusFlags);

	DllExport unsigned int FwUpdatePartial(wchar_t* ImageFileName, unsigned int PartitionID,
		unsigned int Flags, IPU_UPDATED_INFO *IpuUpdatedInfo,
		char* _pwd, unsigned int UpdateEnvironment, _UUID OemID,
		UPDATE_FLAGS_LIB update_flags,
		void(*func)(float, float));

	DllExport unsigned int FWUpdate_QueryStatus_Get_Response(unsigned int* UpdateStatus,
		unsigned int *TotalStages,
		unsigned int* PercentWritten,
		unsigned int* LastUpdateStatus,
		unsigned int* LastResetType);

#ifdef __cplusplus
}
#endif

#endif // __FW_UPDATE_LIB_ME10_H__
