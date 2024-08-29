/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2019-2024 Intel Corporation
 */
#include "PFWUpdateDllWrapperME18.h"
#include "fwupdatelib_ME12.h"
#include "FWUpdateCommand.h"
#include "VerifyFile.h"

#ifdef __cplusplus
extern "C"
{
#endif
#include "errorlist.h"
#ifdef __cplusplus
}
#endif


#define FWUPATITIONINSTANCES_DLL_NAME			FwuPartitionInstances
#define FWUPARTIALUPDATEFROMFILE_DLL_NAME		FwuPartialUpdateFromFile
#define FWUCHECKUPDATEPROGRESS_DLL_NAME			FwuCheckUpdateProgress

#define FWUPATITIONINSTANCES_DLL_NAME_str       FPUPUBLIC_LMS_NAME_MACRO(FWUPATITIONINSTANCES_DLL_NAME)
#define FWUPARTIALUPDATEFROMFILE_DLL_NAME_str   FPUPUBLIC_LMS_NAME_MACRO(FWUPARTIALUPDATEFROMFILE_DLL_NAME)
#define FWUCHECKUPDATEPROGRESS_DLL_NAME_str     FPUPUBLIC_LMS_NAME_MACRO(FWUCHECKUPDATEPROGRESS_DLL_NAME)

struct PFWUpdateDllWrapperME18::FUNCTIONS
{
	decltype(FWUPATITIONINSTANCES_DLL_NAME) * FwuPartitionInstancesDLL;
	decltype(FWUPARTIALUPDATEFROMFILE_DLL_NAME) * FwuPartialUpdateFromFileDLL;
	decltype(FWUCHECKUPDATEPROGRESS_DLL_NAME) * FwuCheckUpdateProgressDLL;
};


static std::wstring ME18_Dll_Name(L"FWUpdateLib_18.dll");


PFWUpdateDllWrapperME18::PFWUpdateDllWrapperME18(void)
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

	auto dllHandle = VerifyFile::SafeLoadDll(ME18_Dll_Name);
	if (dllHandle == nullptr)
	{
		throw std::exception("failed in SafeLoadDll");
	}

	decltype(FWUPATITIONINSTANCES_DLL_NAME)*FwuPartitionInstancesDLL = (decltype(FWUPATITIONINSTANCES_DLL_NAME) *)GetProcAddress(dllHandle, FWUPATITIONINSTANCES_DLL_NAME_str);
	if (FwuPartitionInstancesDLL == nullptr)
	{
		UNS_ERROR(L"Could not find %C API\n", FWUPATITIONINSTANCES_DLL_NAME_str);
		throw std::exception("Could not find FwuPartitionInstances API");
	}

	decltype(FWUPARTIALUPDATEFROMFILE_DLL_NAME) *FwuPartialUpdateFromFileDLL = (decltype(FWUPARTIALUPDATEFROMFILE_DLL_NAME) *)GetProcAddress(dllHandle, FWUPARTIALUPDATEFROMFILE_DLL_NAME_str);
	if (FwuPartialUpdateFromFileDLL == nullptr)
	{
		UNS_ERROR(L"Could not find %C API\n", FWUPARTIALUPDATEFROMFILE_DLL_NAME_str);
		throw std::exception("Could not find FwuPartialUpdateFromFile API");
	}

	decltype(FWUCHECKUPDATEPROGRESS_DLL_NAME) *FwuCheckUpdateProgressDLL = (decltype(FWUCHECKUPDATEPROGRESS_DLL_NAME) *)GetProcAddress(dllHandle, FWUCHECKUPDATEPROGRESS_DLL_NAME_str);
	if (FwuCheckUpdateProgressDLL == nullptr)
	{
		UNS_ERROR(L"Could not find %C API\n", FWUCHECKUPDATEPROGRESS_DLL_NAME_str);
		throw std::exception("Could not find FwuCheckUpdateProgress API");
	}

	functionsPtr = new FUNCTIONS{ FwuPartitionInstancesDLL, FwuPartialUpdateFromFileDLL, FwuCheckUpdateProgressDLL };

	loadDllState = LFDS_SUCCESS;
}

PFWUpdateDllWrapperME18::~PFWUpdateDllWrapperME18()
{
	delete functionsPtr;
}

/**
* @brief A callback function that reports the progress of sending the update image buffer
*        to FW (not the progress of the update itself).
*
* @param[in]  bytesSentToFw         The number of bytes of the buffer, that were already sent to FW.
* @param[in]  totalBytesToSendToFw  The total number of bytes of the buffer.
*/
static void displaySendStatus(uint32_t bytesSentToFw, uint32_t totalBytesToSendToFw)
{
	uint32_t value = bytesSentToFw * 100 / totalBytesToSendToFw;

	if (value != 100)
	{
		UNS_DEBUG(L"Sending the update image to FW for verification:  [ %u%% ]\n", value);
	}
	else
	{
		UNS_DEBUG(L"Sending the update image to FW for verification:  [ COMPLETE ]\n");
	}
}

uint32_t PFWUpdateDllWrapperME18::waitForFwInitDone() // this is a W/A for ME10 and ME11
{
	return SUCCESS;
}

uint32_t PFWUpdateDllWrapperME18::isPfwuRequired(bool& isLoclPfuRequired, bool& isWcodPfurequired, uint32_t& requiredLanguage)
{
	uint32_t status = INTERNAL_ERROR;
	uint32_t currentInstanceId = 0;
	uint32_t expectedInstanceId = 0;

	try
	{
		std::lock_guard<std::mutex> lock(Intel::MEI_Client::FWUpdate_Client::FWUpdateCommand::getInternalSemaphore());

		status = functionsPtr->FwuPartitionInstancesDLL(FPT_PARTITION_NAME_LOCL, &currentInstanceId, &expectedInstanceId);
		if (status != SUCCESS)
		{
			goto End;
		}
		UNS_DEBUG(L"isPfwuRequired LOCL: currentInstanceId=%u, expectedInstanceId=%u\n", currentInstanceId, expectedInstanceId);
		if (currentInstanceId == 0 ||
            currentInstanceId != expectedInstanceId)
		{
			isLoclPfuRequired = true;
			requiredLanguage = expectedInstanceId - 1;
		}

		isWcodPfurequired = false;
	}
	catch (...)
	{
		status = INTERNAL_ERROR;
		UNS_ERROR(L"FwuPartitionInstances thrown error\n");
	}

End:
	printPfwuReturnCode(status);
	return status;
}

uint32_t PFWUpdateDllWrapperME18::performPFWU(uint32_t partialID, const std::wstring& imagePath)
{
	uint32_t status = INTERNAL_ERROR;
	BOOL inProgress = FALSE;
	uint32_t currentPercent = 0;
	uint32_t previousPercent = 0;
	uint32_t fwUpdateStatus = 0;
	uint32_t neededResetType = MFT_PART_INFO_EXT_UPDATE_ACTION_NONE;
	uint32_t timer = 0;
	std::vector<char> imagePathChar(imagePath.length() + 1);
	size_t charsConverted;
	wcstombs_s(&charsConverted, imagePathChar.data(), imagePath.length() + 1, imagePath.c_str(), imagePath.length());

	if (imagePath.c_str() == NULL)
	{
		return status;
	}

	try
	{
		std::lock_guard<std::mutex> lock(Intel::MEI_Client::FWUpdate_Client::FWUpdateCommand::getInternalSemaphore());

		status = functionsPtr->FwuPartialUpdateFromFileDLL(imagePathChar.data(), partialID , &displaySendStatus);
		if (status != SUCCESS)
		{
			goto End;
		}
		
		UNS_DEBUG(L"Image was sent to FW Update client\n");
		
		// poll the FW Update progress until finished
		do
		{
			status = functionsPtr->FwuCheckUpdateProgressDLL(&inProgress,
				&currentPercent,
				&fwUpdateStatus,
				&neededResetType);
			if (status != SUCCESS) // update failed
			{
				break;
			}

			if (!inProgress) // update finished successfully
			{
				// print 100% for output consistency
				UNS_DEBUG(L"FW Update:  [ 100%% ]\n");
				break;
			}

			// update progress
			UNS_DEBUG(L"FW Update:  [ %3u%% ]\n", currentPercent);

			Sleep(250); // wait 250 milliseconds before polling again
			if (timer >= 30000) // if 30 seconds passed
			{
				if (currentPercent == previousPercent) // if percent didn't change in 30 seconds
				{
					status = FWU_UPDATE_TIMEOUT;
					break;
				}

				// percent changed
				previousPercent = currentPercent;
				timer = 0;
			}
			else
			{
				timer += 250;
			}
		} while (TRUE);

		if (status != SUCCESS)
		{
			goto End;
		}

		switch (neededResetType)
		{
		case MFT_PART_INFO_EXT_UPDATE_ACTION_NONE:
		case MFT_PART_INFO_EXT_UPDATE_ACTION_CSE_RESET:
			UNS_DEBUG(L"FW Update completed successfully. No reboot is required\n");
			break;
		case MFT_PART_INFO_EXT_UPDATE_ACTION_HOST_RESET:
			UNS_DEBUG(L"Partial FW Update completed successfully and a reboot will run the new FW. (Host Reset)\n");
			break;
		case MFT_PART_INFO_EXT_UPDATE_ACTION_GLOBAL_RESET:
			UNS_DEBUG(L"Partial FW Update completed successfully and a reboot will run the new FW. (Global Reset)\n");
			break;
		default:
			UNS_DEBUG(L"Partial FW Update completed successfully and a reboot will run the new FW.\n");
			break;
		}
	
	}
	catch (...)
	{
		status = INTERNAL_ERROR;
		UNS_ERROR(L"performPFWU thrown error\n");
	}

End:
	printPfwuReturnCode(status);
	return status;
}

void PFWUpdateDllWrapperME18::printPfwuReturnCode(const uint32_t status)
{
	UNS_DEBUG("PFWUpdate Return Code %u: %C\n", status, GetErrorString(status));
}
