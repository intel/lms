/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2019 Intel Corporation
 */
/*++

File Name:
    fwpdatelib.h

Abstract:
    Handles full and partial firmware updates via HECI.

--*/

#ifndef __FW_UPDATE_LIB_ME12_H__
#define __FW_UPDATE_LIB_ME12_H__

#ifdef __cplusplus
    extern "C" {
#endif

#ifdef _FWUPDATE_DLL
#define DllExport __declspec(dllexport)
#else
#define DllExport
#endif

#define FPT_PARTITION_NAME_FTPR         0x52505446
#define FPT_PARTITION_NAME_RBEP         0x50454252
#define FPT_PARTITION_NAME_NFTP         0x5054464E
#define FPT_PARTITION_NAME_PMCP         0x50434D50
#define FPT_PARTITION_NAME_PCHC         0x43484350
#define FPT_PARTITION_NAME_OEMP         0x504D454F
#define FPT_PARTITION_NAME_ISHC         0x43485349
#define FPT_PARTITION_NAME_IUNP         0x504E5549
#define FPT_PARTITION_NAME_LOCL         0x4C434F4C
#define FPT_PARTITION_NAME_WCOD         0x444f4357
#define FPT_PARTITION_NAME_IOMP         0x504D4F49
#define FPT_PARTITION_NAME_NPHY         0x5948504E
#define FPT_PARTITION_NAME_TBTP         0x50544254
#define FPT_PARTITION_NAME_DPHY         0x59485044
#define FPT_PARTITION_NAME_ISIF         0x46495349
#define FPT_PARTITION_NAME_ISIC         0x43495349

#define MFT_PART_INFO_EXT_UPDATE_ACTION_NONE         0
#define MFT_PART_INFO_EXT_UPDATE_ACTION_HOST_RESET   1
#define MFT_PART_INFO_EXT_UPDATE_ACTION_CSE_RESET    2
#define MFT_PART_INFO_EXT_UPDATE_ACTION_GLOBAL_RESET 3

#define FW_UPDATE_DISABLED 0
#define FW_UPDATE_ENABLED 1

#define FWU_FW_TYPE_INVALID 0
#define FWU_FW_TYPE_RESERVED 1
#define FWU_FW_TYPE_SLIM 2
#define FWU_FW_TYPE_CONSUMER 3
#define FWU_FW_TYPE_CORPORATE 4

#define FWU_PCH_SKU_INVALID 0
#define FWU_PCH_SKU_H 1
#define FWU_PCH_SKU_LP 2

#define FWU_POWER_SOURCE_UNKNOWN 0 
#define FWU_POWER_SOURCE_AC 1
#define FWU_POWER_SOURCE_DC 2


typedef struct __UUID
{
   UINT32 Data1;
   UINT16 Data2;
   UINT16 Data3;
   UINT8  Data4[8];
} _UUID;

/**
* @brief Starting a Full FW Update from a buffer.
*
* @param[in]  buffer        Buffer of Update Image read from Update Image file.
* @param[in]  bufferLength  Length of the buffer in bytes.
* @param[in]  oemId         OEM ID to compare with OEM ID in FW (if exist). Can be NULL.
* @param[in]  func          A callback function that reports the progress of sending the buffer
*                           to FW (not the progress of the update itself). Can be NULL.
*                           void* func(UINT32 bytesSentToFw, UINT32 totalBytesToSendToFw);
*
* @return SUCCESS  If Update started successfully. Error code otherwise.
*/
DllExport
UINT32 FwuFullUpdateFromBuffer(IN  UINT8 *buffer,
                               IN  UINT32 bufferLength,
                               IN  _UUID *oemId,
                               IN  void(*func)(UINT32, UINT32));

/**
* @brief Starting a Partial FW Update from a buffer.
*
* @param[in]  buffer        Buffer of Update Image read from Update Image file.
* @param[in]  bufferLength  Length of the buffer in bytes.
* @param[in]  partitionId   ID of partition to update. Only partitions that are allowed to be partially updated.
* @param[in]  func          A callback function that reports the progress of sending the buffer
*                           to FW (not the progress of the update itself). Can be NULL.
*                           void* func(UINT32 bytesSentToFw, UINT32 totalBytesToSendToFw);
*
* @return SUCCESS  If Update started successfully. Error code otherwise.
*/
DllExport
UINT32 FwuPartialUpdateFromBuffer(IN  UINT8 *buffer,
                                  IN  UINT32 bufferLength,
                                  IN  UINT32 partitionId,
                                  IN  void(*func)(UINT32, UINT32));

/**
* @brief Check for Update progress.
*        If in progress, return the current percent.
*        If finished, return the status of the update, and the needed reset type after the update.
*        This function should be called only after starting the update by calling FwuUpdateFull/Partial...
*
* @param[out] inProgress       True if Update is still in progress. False if Update finished. Caller allocated.
* @param[out] currentPercent   Current percent of the update, if Update is in progress. Caller allocated.
* @param[out] fwUpdateStatus   FW error code status of the update, if it finished (success or error code). Caller allocated.
* @param[out] neededResetType  Needed reset type after the update, if it finished. Caller allocated.
*                              MFT_PART_INFO_EXT_UPDATE_ACTION_NONE         0
*                              MFT_PART_INFO_EXT_UPDATE_ACTION_HOST_RESET   1
*                              MFT_PART_INFO_EXT_UPDATE_ACTION_CSE_RESET    2
*                              MFT_PART_INFO_EXT_UPDATE_ACTION_GLOBAL_RESET 3
*
* @return SUCCESS  If Update is still in progress, or finished successfully. Error code otherwise.
*/
DllExport
UINT32 FwuCheckUpdateProgress(OUT BOOL *inProgress,
                              OUT UINT32 *currentPercent,
                              OUT UINT32 *fwUpdateStatus,
                              OUT UINT32 *neededResetType);

/**
* @brief Get FW Update enabling state: enabled, disabled.
*
* @param[out] enabledState  FW Update enabling state: enabled, disabled. Caller allocated.
*                           FW_UPDATE_DISABLED = 0.
*                           FW_UPDATE_ENABLED = 1.
*
* @return SUCCESS  If succeeded. Error code otherwise.
*/
DllExport
UINT32 FwuEnabledState(OUT UINT16 *enabledState);

/**
* @brief Get OEM ID from flash.
*
* @param[out] oemId  OEM ID from flash. Caller allocated.
*
* @return SUCCESS  If succeeded. Error code otherwise.
*/
DllExport
UINT32 FwuOemId(OUT _UUID *oemId);

/**
* @brief Get FW Type.
*
* @param[out] fwType  FW Type. Caller allocated.
*                     FWU_FW_TYPE_INVALID 0
*                     FWU_FW_TYPE_RESERVED 1
*                     FWU_FW_TYPE_SLIM 2
*                     FWU_FW_TYPE_CONSUMER 3
*                     FWU_FW_TYPE_CORPORATE 4
*
* @return SUCCESS  If succeeded. Error code otherwise.
*/
DllExport
UINT32 FwuFwType(OUT UINT32 *fwType);

/**
* @brief Get PCH SKU.
*
* @param[out] pchSku  PCH SKU. Caller allocated.
*                     FWU_PCH_SKU_INVALID 0
*                     FWU_PCH_SKU_H 1
*                     FWU_PCH_SKU_LP 2
*
* @return SUCCESS  If succeeded. Error code otherwise.
*/
DllExport
UINT32 FwuPchSku(OUT UINT32 *pchSku);

/**
* @brief Get version of a specific partition, from the flash image.
*
* @param[in]  partitionId  ID of partition. If the FW version of CSE is needed,
*                          use FTPR partition ID: FPT_PARTITION_NAME_FTPR.
* @param[out] major        Major number of version. Caller allocated.
* @param[out] minor        Minor number of version. Caller allocated.
* @param[out] hotfix       Hotfix number of version. Caller allocated.
* @param[out] build        Build number of version. Caller allocated.
*
* @return SUCCESS  If succeeded. Error code otherwise.
*/
DllExport
UINT32 FwuPartitionVersionFromFlash(IN  UINT32 partitionId,
                                    OUT UINT16 *major,
                                    OUT UINT16 *minor,
                                    OUT UINT16 *hotfix,
                                    OUT UINT16 *build);

/**
* @brief Get version of a specific partition, from the Update Image buffer.
*
* @param[in]  buffer        Buffer of Update Image read from Update Image file.
* @param[in]  bufferLength  Length of the buffer in bytes.
* @param[in]  partitionId   ID of partition. If the FW version of CSE is needed,
*                           use FTPR partition ID: FPT_PARTITION_NAME_FTPR.
* @param[out] major         Major number of version. Caller allocated.
* @param[out] minor         Minor number of version. Caller allocated.
* @param[out] hotfix        Hotfix number of version. Caller allocated.
* @param[out] build         Build number of version. Caller allocated.
*
* @return SUCCESS  If succeeded. Error code otherwise.
*/
DllExport
UINT32 FwuPartitionVersionFromBuffer(IN  UINT8 *buffer,
                                     IN  UINT32 bufferLength,
                                     IN  UINT32 partitionId,
                                     OUT UINT16 *major,
                                     OUT UINT16 *minor,
                                     OUT UINT16 *hotfix,
                                     OUT UINT16 *build);

/**
* @brief Get vendor ID of a specific partition, from the flash image.
*
* @param[in]  partitionId  ID of partition.
* @param[out] vendorId     Vendor ID of partition. Caller allocated.
*
* @return SUCCESS  If succeeded. Error code otherwise.
*/
DllExport
UINT32 FwuPartitionVendorIdFromFlash(IN  UINT32 partitionId,
                                     OUT UINT32 *vendorId);

/**
* @brief Starting a Full FW Update from a file.
*
* @param[in]  fileName      File name of Update Image.
* @param[in]  oemId         OEM ID to compare with OEM ID in FW (if exist). Can be NULL.
* @param[in]  func          A callback function that reports the progress of sending the buffer
*                           to FW (not the progress of the update itself). Can be NULL.
*                           void* func(UINT32 bytesSentToFw, UINT32 totalBytesToSendToFw);
*
* @return SUCCESS  If Update started successfully. Error code otherwise.
**/
DllExport
UINT32 FwuFullUpdateFromFile(IN  const char *fileName,
                             IN  _UUID *oemId,
                             IN  void(*func)(UINT32, UINT32));

/**
* @brief Starting a Partial FW Update from a file.
*
* @param[in]  fileName      File name of Update Image.
* @param[in]  partitionId   ID of partition to update. Only partitions that are allowed to be partially updated.
* @param[in]  func          A callback function that reports the progress of sending the buffer
*                           to FW (not the progress of the update itself). Can be NULL.
*                           void* func(UINT32 bytesSentToFw, UINT32 totalBytesToSendToFw);
*
* @return SUCCESS  If Update started successfully. Error code otherwise.
*/
DllExport
UINT32 FwuPartialUpdateFromFile(IN  const char *fileName,
                                IN  UINT32 partitionId,
                                IN  void(*func)(UINT32, UINT32));

/**
* @brief Get version of a specific partition, from the Update Image file.
*
* @param[in]  fileName      File name of Update Image.
* @param[in]  partitionId   ID of partition. If the FW version of CSE is needed,
*                           use FTPR partition ID: FPT_PARTITION_NAME_FTPR.
* @param[out] major         Major number of version. Caller allocated.
* @param[out] minor         Minor number of version. Caller allocated.
* @param[out] hotfix        Hotfix number of version. Caller allocated.
* @param[out] build         Build number of version. Caller allocated.
*
* @return SUCCESS  If succeeded. Error code otherwise.
*/
DllExport
UINT32 FwuPartitionVersionFromFile(IN  const char *fileName,
                                   IN  UINT32 partitionId,
                                   OUT UINT16 *major,
                                   OUT UINT16 *minor,
                                   OUT UINT16 *hotfix,
                                   OUT UINT16 *build);

/**
* @brief Get the current instance ID and the expected instance ID of an IUP partition in the FW.
*
* @param[in]  partitionId         ID of an IUP partition.
* @param[out] currentInstanceId   Current instance ID. Caller allocated.
* @param[out] expectedInstanceId  Expected instance ID. Caller allocated.
*
* @return SUCCESS  If succeeded. Error code otherwise.
*/
DllExport
UINT32 FwuPartitionInstances(IN  UINT32 partitionId,
                             OUT UINT32 *currentInstanceId,
                             OUT UINT32 *expectedInstanceId);

/**
* @brief Starting a Partial FW Update to a specific instance ID, from a buffer.
*
* @param[in]  buffer        Buffer of Update Image read from Update Image file.
* @param[in]  bufferLength  Length of the buffer in bytes.
* @param[in]  partitionId   ID of partition to update. Only partitions that are allowed to be partially updated.
* @param[in]  instanceId    Instance ID of partition to update to.
* @param[in]  func          A callback function that reports the progress of sending the buffer
*                           to FW (not the progress of the update itself). Can be NULL.
*                           void* func(UINT32 bytesSentToFw, UINT32 totalBytesToSendToFw);
*
* @return SUCCESS  If Update started successfully. Error code otherwise.
*/
DllExport
UINT32 FwuPartialUpdateWithInstanceIdFromBuffer(IN  UINT8 *buffer,
                                                IN  UINT32 bufferLength,
                                                IN  UINT32 partitionId,
                                                IN  UINT32 instanceId,
                                                IN  void(*func)(UINT32, UINT32));

/**
* @brief Starting a Partial FW Update to a specific instance ID, from a file.
*
* @param[in]  fileName      File name of Update Image.
* @param[in]  partitionId   ID of partition to update. Only partitions that are allowed to be partially updated.
* @param[in]  instanceId    Instance ID of partition to update to.
* @param[in]  func          A callback function that reports the progress of sending the buffer
*                           to FW (not the progress of the update itself). Can be NULL.
*                           void* func(UINT32 bytesSentToFw, UINT32 totalBytesToSendToFw);
*
* @return SUCCESS  If Update started successfully. Error code otherwise.
*/
DllExport
UINT32 FwuPartialUpdateWithInstanceIdFromFile(IN  const char *fileName,
                                              IN  UINT32 partitionId,
                                              IN  UINT32 instanceId,
                                              IN  void(*func)(UINT32, UINT32));

/**
* @brief Get the the current image from the flash - Restore Point Image, and save it to buffer.
*
* @param[out] buffer        Buffer of the saved Restore Point Image.
*                           Allocated by the function, only in case of SUCCESS. NULL otherwise.
*                           Caller should free the buffer
*                           using free() in WIN, FreePool() in EFI.
* @param[out] bufferLength  Length of the buffer in bytes.
*
* @return SUCCESS  If succeeded. Error code otherwise.
*/
DllExport
UINT32 FwuSaveRestorePointToBuffer(OUT UINT8 **buffer,
                                   OUT UINT32 *bufferLength);

/**
* @brief Get the the current image from the flash - Restore Point Image, and save it to file.
*
* @param[in]  fileName  File name to save Restore Point Image into.
*
* @return SUCCESS  If succeeded. Error code otherwise.
*/
DllExport
UINT32 FwuSaveRestorePointToFile(IN  const char *fileName);

/**
* @brief Check if the power source is AC or DC.
*
* @param[out] powerSource  Power Source. Caller allocated.
*                          FWU_POWER_SOURCE_UNKNOWN = 0.
*                          FWU_POWER_SOURCE_AC  = 1.
*                          FWU_POWER_SOURCE_DC  = 2.
*
* @return SUCCESS  If succeeded. Error code otherwise.
*/
DllExport
UINT32 FwuPowerSource(OUT UINT32 *powerSource);

#ifdef __cplusplus
    }
#endif
#endif //__FW_UPDATE_LIB_ME12_H__
