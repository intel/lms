/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2019 Intel Corporation
 */
#include "PFWUpdateDllWrapperME10.h"
#include "fwupdatelib_ME10.h"
#include "FWUpdateCommand.h"
#include "VerifyFile.h"

#define	GETFWUPDATEINFOSTATUS_DLL_NAME					GetFwUpdateInfoStatus
#define	GETIPUPARTITIONATTRIBUTES_DLL_NAME				GetIpuPartitionAttributes
#define FWUPDATEPARTIAL_DLL_NAME						FwUpdatePartial
#define	GETLASTUPDATERESETTYPE_DLL_NAME					GetLastUpdateResetType
#define	FWUPDATE_QUERYSTATUS_GET_RESPONSE_DLL_NAME		FWUpdate_QueryStatus_Get_Response

#define GETFWUPDATEINFOSTATUS_DLL_NAME_str				FPUPUBLIC_LMS_NAME_MACRO(GETFWUPDATEINFOSTATUS_DLL_NAME)
#define GETIPUPARTITIONATTRIBUTES_DLL_NAME_str			FPUPUBLIC_LMS_NAME_MACRO(GETIPUPARTITIONATTRIBUTES_DLL_NAME)
#define FWUPDATEPARTIAL_DLL_NAME_str					FPUPUBLIC_LMS_NAME_MACRO(FWUPDATEPARTIAL_DLL_NAME)
#define GETLASTUPDATERESETTYPE_DLL_NAME_str				FPUPUBLIC_LMS_NAME_MACRO(GETLASTUPDATERESETTYPE_DLL_NAME)
#define FWUPDATE_QUERYSTATUS_GET_RESPONSE_DLL_NAME_str	FPUPUBLIC_LMS_NAME_MACRO(FWUPDATE_QUERYSTATUS_GET_RESPONSE_DLL_NAME)

struct PFWUpdateDllWrapperME10::FUNCTIONS
{
	decltype(GETFWUPDATEINFOSTATUS_DLL_NAME) * GetFwUpdateInfoStatusDLL;
	decltype(GETIPUPARTITIONATTRIBUTES_DLL_NAME) * 	GetIpuPartitionAttributesDLL;
	decltype(FWUPDATEPARTIAL_DLL_NAME) * FwUpdatePartialDLL;
	decltype(GETLASTUPDATERESETTYPE_DLL_NAME) * GetLastUpdateResetTypeDLL;
	decltype(FWUPDATE_QUERYSTATUS_GET_RESPONSE_DLL_NAME) * FWUpdate_QueryStatus_Get_ResponseDLL;
};

typedef enum _PT_RESET_TYPE
{
	NO_RESET_REQUIRED = 0,  // No reset is required
	HOST_RESET_REQUIRED,    // Host reset is required
	ME_RESET_REQUIRED,      // ME-Reset is required
	GLOBAL_RESET_REQUIRED,  // Global reset is required (reset both host and ME). Note that HOST will probably
							// not seeing this GLOBAL_RESET_REQUIRED. If it is needed Host will receive HOST_RESET_REQUIRED
							// and ME will promote it to Pseudo Global reset on the next boot.
}PT_RESET_TYPE;


#define PROGRESS_WAIT_SEC			1

static std::wstring ME10_Dll_Name(L"FWUpdateLib_10.dll");


PFWUpdateDllWrapperME10::PFWUpdateDllWrapperME10(void)
{
	enum LoadFwDllState { LFDS_INITIAL, LFDS_FAILURE, LFDS_SUCCESS };

	static enum LoadFwDllState loadDllState = LFDS_INITIAL;

	if (loadDllState != LFDS_INITIAL)
	{
		if (loadDllState != LFDS_SUCCESS)
		{
			throw std::exception("Dll state: " + loadDllState);
		}
	}
	loadDllState = LFDS_FAILURE;

	auto dllHandle = VerifyFile::SafeLoadDll(ME10_Dll_Name);
	if (dllHandle == nullptr)
	{
		throw std::exception("failed in SafeLoadDll");
	}

	decltype(GETFWUPDATEINFOSTATUS_DLL_NAME)*GetFwUpdateInfoStatusDLL = (decltype(GETFWUPDATEINFOSTATUS_DLL_NAME) *)GetProcAddress(dllHandle, GETFWUPDATEINFOSTATUS_DLL_NAME_str);
	if (GetFwUpdateInfoStatusDLL == nullptr)
	{
		UNS_ERROR(L"Could not find %C API\n", GETFWUPDATEINFOSTATUS_DLL_NAME_str);
		throw std::exception("Could not find GetFwUpdateInfoStatus API");
	}

	decltype(GETIPUPARTITIONATTRIBUTES_DLL_NAME)*GetIpuPartitionAttributesDLL = (decltype(GETIPUPARTITIONATTRIBUTES_DLL_NAME) *)GetProcAddress(dllHandle, GETIPUPARTITIONATTRIBUTES_DLL_NAME_str);
	if (GetIpuPartitionAttributesDLL == nullptr)
	{
		UNS_ERROR(L"Could not find %C API\n", GETIPUPARTITIONATTRIBUTES_DLL_NAME_str);
		throw std::exception("Could not find GetIpuPartitionAttributes API");
	}

	decltype(FWUPDATEPARTIAL_DLL_NAME) *FwUpdatePartialDLL = (decltype(FWUPDATEPARTIAL_DLL_NAME) *)GetProcAddress(dllHandle, FWUPDATEPARTIAL_DLL_NAME_str);
	if (FwUpdatePartialDLL == nullptr)
	{
		UNS_ERROR(L"Could not find %C API\n", FWUPDATEPARTIAL_DLL_NAME_str);
		throw std::exception("Could not find FwUpdatePartial API");
	}

	decltype(GETLASTUPDATERESETTYPE_DLL_NAME)*GetLastUpdateResetTypeDLL = (decltype(GETLASTUPDATERESETTYPE_DLL_NAME) *)GetProcAddress(dllHandle, GETLASTUPDATERESETTYPE_DLL_NAME_str);
	if (GetLastUpdateResetTypeDLL == nullptr)
	{
		UNS_ERROR(L"Could not find %C API\n", GETLASTUPDATERESETTYPE_DLL_NAME_str);
		throw std::exception("Could not find GetLastUpdateResetType API");
	}

	decltype(FWUPDATE_QUERYSTATUS_GET_RESPONSE_DLL_NAME) *FWUpdate_QueryStatus_Get_ResponseDLL = (decltype(FWUPDATE_QUERYSTATUS_GET_RESPONSE_DLL_NAME) *)GetProcAddress(dllHandle, FWUPDATE_QUERYSTATUS_GET_RESPONSE_DLL_NAME_str);
	if (FWUpdate_QueryStatus_Get_ResponseDLL == nullptr)
	{
		UNS_ERROR(L"Could not find %C API\n", FWUPDATE_QUERYSTATUS_GET_RESPONSE_DLL_NAME_str);
		throw std::exception("Could not find FWUpdate_QueryStatus_Get_Response API");
	}

	functionsPtr = new FUNCTIONS{ GetFwUpdateInfoStatusDLL, GetIpuPartitionAttributesDLL, FwUpdatePartialDLL, GetLastUpdateResetTypeDLL, FWUpdate_QueryStatus_Get_ResponseDLL };

	loadDllState = LFDS_SUCCESS;
}

PFWUpdateDllWrapperME10::~PFWUpdateDllWrapperME10()
{
	delete functionsPtr;
}

uint32_t PFWUpdateDllWrapperME10::waitForFwInitDone() //this is W/A for ME10 and ME11
{
	uint32_t retCode = 8707;
	bool fwInitDone = false;

	retCode = isFwInitDone(&fwInitDone);
	if (retCode != 0)
	{
		return retCode;
	}

	uint32_t loopCount = 0;
	while (!fwInitDone)
	{
		retCode = isFwInitDone(&fwInitDone);
		if (retCode != 0)
		{
			return retCode;
		}
		Sleep(1000 * INIT_WAIT_SEC);

		//Timeout After 5sec, if don't get FWInit Done
		if (!fwInitDone && loopCount > 5)
		{
			UNS_ERROR(L"Wait for FwInitDone got Timeout, partialFWUpdate failed\n");
			return 8707;
		}

		++loopCount;
	}

	return 0;
}
uint32_t PFWUpdateDllWrapperME10::isFwInitDone(bool* isFwInitDone)
{
	unsigned int retcode = 8707;
	FWU_INFO_FLAGS flags;
	memset(&flags, 0, sizeof(flags));

	try
	{
		std::lock_guard<std::mutex> lock(Intel::MEI_Client::FWUpdate_Client::FWUpdateCommand::getInternalSemaphore());
		retcode = functionsPtr->GetFwUpdateInfoStatusDLL(&flags);
		if (retcode == 0)
		{
			*isFwInitDone = flags.FwInitDone;
			UNS_DEBUG(L"isFwInitDone=%d\n", *isFwInitDone);
		}
	}
	catch (...)
	{
		retcode = 8707;
		UNS_ERROR(L"GetFwUpdateInfoStatus threw error\n");
	}

	printPfwuReturnCode(retcode);
	return retcode;
}

uint32_t PFWUpdateDllWrapperME10::isPfwuRequired(bool& isLoclPfuRequired, bool& isWcodPfurequired, uint32_t& requiredLanguage)
{
	unsigned int retcode = 8707;
	FWU_GET_IPU_PT_ATTRB_MSG_REPLY info;
	memset(&info, 0, sizeof(info));

	try
	{
		std::lock_guard<std::mutex> lock(Intel::MEI_Client::FWUpdate_Client::FWUpdateCommand::getInternalSemaphore());
		retcode = functionsPtr->GetIpuPartitionAttributesDLL(&info);
		if (retcode != 0)
		{
			UNS_ERROR(L"GetIpuPartitionAttributesDLL failed, retcode=0x%X\n", retcode);
			return retcode;
		}

		for (uint16_t i = 0; (i < info.NumOfPartition) && (i < MAXIMUM_IPU_SUPPORTED); i++)
		{
			UNS_DEBUG(L"Check partition [%u] - %X, CurrentInstId %u, ExpectedInstId %u, CurrentUpvVer %u, ExpectedUpvVer %u!\n", i, info.PtAttribute[i].PtNameId,
				info.PtAttribute[i].CurrentInstId, info.PtAttribute[i].ExpectedInstId,
				info.PtAttribute[i].CurrentUpvVer, info.PtAttribute[i].ExpectedUpvVer);

			if (info.PtAttribute[i].PtNameId == WOCD_ID)
			{
				if ((info.PtAttribute[i].CurrentInstId == 0) ||
					(info.PtAttribute[i].CurrentInstId != info.PtAttribute[i].ExpectedInstId) ||
					/* update only if major version (upper 16 bit) is different, not if only minor version is different */
					(info.PtAttribute[i].CurrentUpvVer & 0xFFFF0000) != (info.PtAttribute[i].ExpectedUpvVer & 0xFFFF0000))
				{
					isWcodPfurequired = true;
				}
			}
			else if (info.PtAttribute[i].PtNameId == LOCL_ID)
			{
				if ((info.PtAttribute[i].CurrentInstId == 0) ||
					(info.PtAttribute[i].CurrentInstId != info.PtAttribute[i].ExpectedInstId) ||
					(info.PtAttribute[i].CurrentUpvVer != info.PtAttribute[i].ExpectedUpvVer))
				{
					isLoclPfuRequired = true;
					requiredLanguage = info.PtAttribute[i].ExpectedInstId - 1;
				}
			}
			else
			{
				UNS_ERROR(L"Found mismatch on an unknown partition #%u 0x%X\n", i, info.PtAttribute[i].PtNameId);
			}
		}
	}
	catch (...)
	{
		retcode = 8707;
		UNS_ERROR(L"GetIpuPartitionAttributes threw error\n");
	}

	printPfwuReturnCode(retcode);
	return retcode;
}

uint32_t PFWUpdateDllWrapperME10::performPFWU(uint32_t partialID, const std::wstring& imagePath)
{
	// Lock the FWUpdate client in order to assure that it is used just once each time
	std::lock_guard<std::mutex> lock(Intel::MEI_Client::FWUpdate_Client::FWUpdateCommand::getInternalSemaphore());

	unsigned int retcode = 8707;
	UNS_DEBUG(L"performPFWU: ImageFileName %s, PartitionID %u\n", imagePath, partialID);

	try
	{
		char* _pwd = NULL;
		unsigned int UpdateEnvironment = FWU_ENV_MANUFACTURING;
		_UUID OemID = { 0,0,0,0 };
		UPDATE_FLAGS_LIB update_flags = { 0,0,0 };
		IPU_UPDATED_INFO IpuUpdatedInfo;
		retcode = functionsPtr->FwUpdatePartialDLL(const_cast<wchar_t*>(imagePath.c_str()), partialID, 0, &IpuUpdatedInfo, _pwd, UpdateEnvironment, OemID, update_flags, NULL);
		if (retcode == 8707)
		{ //check if boot is needed
			if (functionsPtr->GetLastUpdateResetTypeDLL(&retcode) != 0)
				retcode = 8707;
			else
			{
				if (retcode == HOST_RESET_REQUIRED || retcode == GLOBAL_RESET_REQUIRED)
				{
					UNS_DEBUG(L"HOST_RESET_REQUIRED || GLOBAL_RESET_REQUIRED %u\n", retcode);
					retcode = 8703;
				}
			}
		}
	}
	catch (...)
	{
		retcode = 8707;
		UNS_ERROR(L"FwUpdatePartial threw error\n");
	}
	printPfwuReturnCode(retcode);
	if (retcode != 0)
	{
		UNS_ERROR(L"FwUpdatePartial - failed\n");
		return retcode;
	}


	bool done = false;
	uint32_t currentStage = 0, totalStage = 0, progress = 0, lastUpdateStatus = 0, lastResetType = 0;
	uint32_t currentStageNew = 0, totalStageNew = 0, progressNew = 0, lastUpdateStatusNew = 0, lastResetTypeNew = 0;
	int errCounter = 0;
	while (!done)
	{
		UNS_DEBUG(L"Progress...\n");
		try
		{
			retcode = functionsPtr->FWUpdate_QueryStatus_Get_ResponseDLL(&currentStageNew, &totalStageNew, &progressNew, &lastUpdateStatusNew, &lastResetTypeNew);
		}
		catch (...)
		{
			retcode = 8707;
			UNS_ERROR(L"FWUpdate_QueryStatus_Get_Response threw error\n");
		}
		printPfwuReturnCode(retcode);
		UNS_DEBUG(L"currentStageNew %u, totalStageNew %u, progressNew %u, lastUpdateStatusNew %u, lastResetTypeNew %u, done %d\n", currentStageNew, totalStageNew, progressNew, lastUpdateStatusNew, lastResetTypeNew, done);
		if (retcode != 0)
		{
			if (errCounter >= PFWU_RETRIES_LOOP)
			{
				UNS_ERROR(L"getFWUpdateStatus error\n");
				return retcode;
			}
			UNS_DEBUG(L"getFWUpdateStatus intermediate error : %u - sleeping, error #%d\n", retcode, errCounter);
			Sleep(100 * PROGRESS_WAIT_SEC);
			errCounter++;
		}
		if (progress < progressNew)
		{
			progress = progressNew;
			currentStage = currentStageNew;
			totalStage = totalStageNew;
			lastUpdateStatus = lastUpdateStatusNew;
			lastResetType = lastResetTypeNew;
			errCounter = 0;
		}
		if ((progress >= 100) || (progress > progressNew))
		{
			done = true;
		}
		else
		{
			Sleep(100 * PROGRESS_WAIT_SEC);
		}
	}
	return 0;
}

