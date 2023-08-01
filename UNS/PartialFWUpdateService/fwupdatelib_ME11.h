/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2007-2022 Intel Corporation
 */
/*++

File Name:
   FWUpdateLib.h

Abstract:
   Handles full and partial firmware updates via HECI.

Author:
Inies Chemmannoor

--*/

#ifndef __FW_UPDATE_LIB_ME11_H__
#define __FW_UPDATE_LIB_ME11_H__

typedef struct __UUID
{
	unsigned int   Data1;
	unsigned short Data2;
	unsigned short Data3;
	unsigned char  Data4[8];
} _UUID;

/** @brief Defines a generic version structure used in the software build process. This structure will be used to
*   represent versions of ROM, FW and Recovery modules.
*/
typedef struct _VERSION
{
	uint16_t      Major;
	uint16_t      Minor;
	uint16_t      Hotfix;
	uint16_t      Build;
}VERSION;

const size_t MAXIMUM_IPU_SUPPORTED = 4;

typedef struct _FWU_INFO_FLAGS
{
	unsigned int RecoveryMode : 2;   // 0 = No recovery; 1 = Full Recovery Mode,2 = Partial Recovery Mode
	unsigned int IpuNeeded : 1;      // IPU_NEEDED bit, if set we are in IPU_NEEDED state.
	unsigned int FwInitDone : 1;     // If set indicate FW is done initialized
	unsigned int FwuInProgress : 1;  // If set FWU is in progress, this will be set for IFU update as well
	unsigned int SuInprogress : 1;   // If set IFU Safe FW update is in progress. 
	unsigned int NewFtTestS : 1;     // If set indicate that the new FT image is in Test Needed state (Stage 2 Boot)
	unsigned int SafeBootCnt : 4;    // Boot count before the operation is success
	unsigned int FsbFlag : 1;        // Force Safe Boot Flag, when this bit is set, we'll boot kernel only and go into recovery mode	

	//////////////////////////////////////////////////////
	// These fields below are important for FWU tool. 
	//////////////////////////////////////////////////////
	unsigned int LivePingNeeded : 1;     // Use for IFU only, See Below  
								 // FWU tool needs to send Live-Ping or perform querying to confirm update successful.
								 // With the current implementation when LivePingNeeded is set, 
								 // Kernel had already confirmed it. No action from the tool is needed.
	unsigned int ResumeUpdateNeeded : 1; // Use for IFU only, If set FWU tool needs to resend update image
	unsigned int RollbackNeededMode : 2; // FWU_ROLLBACK_NONE = 0, FWU_ROLLBACK_1, FWU_ROLLBACK_2 
								 // If not FWU_ROLLBACK_NONE, FWU tool needs to send restore_point image. 
	unsigned int ResetNeeded : 2;        // When this field is set to ME_RESET_REQUIRED, FW Kernel will
								 // perform ME_RESET after this message. No action from the tool is needed.
	unsigned int SuState : 4;		    // See possible values below
	unsigned int RecoveryCause : 2;      // IMAGE_CODE_INVALID = 1; IMAGE_NFT_INVALID = 2;
	unsigned int Reserve : 8;
}FWU_INFO_FLAGS;

typedef unsigned int STATUS;

typedef struct _PT_ATTRB
{
	unsigned int   PtNameId;      // HW_COMP_HDR_STRUCTID_WCOD     0x244f4357 OR 
							// HW_COMP_HDR_STRUCTID_LOCL     0x4C434F4C OR
							// HW_COMP_HDR_STRUCTID_MDMV     0x564D444D 
	unsigned int   LoadAddress;         // Load Address of the IPU
	VERSION  FwVer;         // FW version from IUP Manifest
	unsigned int   CurrentInstId; // Current Inst ID from flash, 0 indicate invalid ID 
	unsigned int   CurrentUpvVer; // Upper sig 16 bits are Major Version.
	unsigned int   ExpectedInstId;// Expected Inst ID that need to be updated to
	unsigned int   ExpectedUpvVer;// Upper sig 16 bits are Major Version.
	unsigned int   Resv[4];
}PT_ATTRB;

typedef struct _FWU_GET_IPU_PT_ATTRB_MSG_REPLY
{
	unsigned int   MessageType;      // Internal FWU tool use only
	STATUS   Status;           // Internal FWU tool use only
	VERSION  FtpFwVer;         // FW version in Fault Tolerance Partition. 
							   // This might be used for diagnostic or debug.
	unsigned int   SizeoOfPtAttrib;  // Size in bytes. Simply is the sizeof (PT_ATTRB structure)
	unsigned int   NumOfPartition;   // Number of partition actually return in this reply message
	PT_ATTRB  PtAttribute[MAXIMUM_IPU_SUPPORTED];
	unsigned int   Resv[4];
} FWU_GET_IPU_PT_ATTRB_MSG_REPLY;

typedef struct _UPDATE_FLAGS_LIB
{
   uint32_t RestorePoint      :1;       // If set indicate restore point
   uint32_t RestartOperation  :1;       // If set indicate restart operation, like lost hard drive etc...
   uint32_t UserRollback      :1;       // indicates user has initiated a rollback
   uint32_t Reserve           :29;      //
} UPDATE_FLAGS_LIB;

// Should be used by both tool and UNS to retrieve the Updated UPV version
typedef struct _IPU_UPDATED_INFO
{
    uint32_t UpdatedUpvVer; //Version from the update image file that is for updating IPU
	uint32_t Reserved[4];
} IPU_UPDATED_INFO;

#ifdef __cplusplus
    extern "C" {
#endif

#define DllExport __declspec(dllexport)

DllExport uint32_t GetLastUpdateResetType(uint32_t *lastResetType);

DllExport uint32_t GetIpuPartitionAttributes(
    FWU_GET_IPU_PT_ATTRB_MSG_REPLY *FwuGetIpuAttrbMsgInfo);

DllExport uint32_t GetFwUpdateInfoStatus(
    FWU_INFO_FLAGS *StatusFlags);

DllExport uint32_t FwUpdatePartial(
    wchar_t*             ImageFileName, 
	uint32_t      PartitionID,
	uint32_t      Flags,
    IPU_UPDATED_INFO* IpuUpdatedInfo,
    char*             _pwd,
	uint32_t      UpdateEnvironment,
    _UUID             OemID,
    UPDATE_FLAGS_LIB  update_flags,
    void(*func)(float, float));

DllExport uint32_t FWUpdate_QueryStatus_Get_Response(
	uint32_t* UpdateStatus,
	uint32_t *TotalStages,
	uint32_t* PercentWritten,
	uint32_t* LastUpdateStatus,
	uint32_t* LastResetType);

#ifdef __cplusplus
    }
#endif

#endif //__FW_UPDATE_LIB_ME10_H__
