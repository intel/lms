/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2009-2019 Intel Corporation
 */
/*++

@file: Manageability_Commands_BE.cpp

--*/

#include "Manageability_Commands_BE.h"
#include "global.h"
#include "FWUGetInfoCommand.h"
#include "GetFWCapsCommand.h"
#include "GetFWVersionCommand.h"
#include "GetPlatformTypeCommand.h"
#include "GetFWUpdateStateCommand.h"
#include "GetEOPStateCommand.h"
#include "GetImageFWVersionCommand.h"
#include "SMBIOS_Reader.h"
#include <sstream>
#include <iomanip>

namespace Intel {
	namespace LMS {

#define CATCH_MEIClientException(func) \
	catch (Intel::MEI_Client::MEIClientException& e) \
	{ \
		const char* reason = e.what(); \
		UNS_DEBUG(func L" failed %C\n", reason); \
	}

#define CATCH_MKHIErrorException(func) \
	catch (Intel::MEI_Client::MKHI_Client::MKHIErrorException& e) \
	{ \
		unsigned int errNo = e.getErr(); \
		UNS_DEBUG(func L" failed ret=%d\n", errNo); \
	}

#define CATCH_FWUpdateErrorException(func) \
	catch (Intel::MEI_Client::FWUpdate_Client::FWUpdateErrorException& e) \
	{ \
		unsigned int errNo = e.getErr(); \
		UNS_DEBUG(func L" failed ret=%d\n", errNo); \
	}

#define CATCH_exception(func) \
	catch (std::exception& e) \
	{ \
		const char* reason = e.what(); \
		UNS_DEBUG(L"Exception in " func L" %C\n", reason); \
	}

		//MEBx version
		struct MEBX_BIOS_VER
		{

			uint16_t   MEBxMinor;
			uint16_t   MEBxMajor;
			uint16_t   MEBxBuildNo;
			uint16_t   MEBxHotFix;
		};


		void MenageabiltyModeLogic(Intel::MEI_Client::MKHI_Client::MKHI_PLATFORM_TYPE platform, MENAGEABILTY_MODE &pMode)
		{
			switch (platform.Fields.Brand)
			{
			case Intel::MEI_Client::MKHI_Client::NoBrand:
				pMode = NONE;
				break;
			case Intel::MEI_Client::MKHI_Client::BrandAMT:
				pMode = VPRO;
				break;
			case Intel::MEI_Client::MKHI_Client::BrandStdMng:
				pMode = STANDARD;
				break;
			case Intel::MEI_Client::MKHI_Client::BrandL3:
				pMode = L3;
				break;
			case Intel::MEI_Client::MKHI_Client::BrandSBT:
				pMode = SBT;
				break;
			default:
				pMode = NOT_KNOWN;
			}
		}

		FEATURE_STATE FeatureStateLogic(bool CapabilityBit, bool StateBit, bool AvailabilityBit)
		{
			if (CapabilityBit)
				if (StateBit)
					if (AvailabilityBit)
						return AVAILABLE;
					else
						return ENABLED;
				else
					return DISABLED;
			else
				return NOT_PRESENT;
		}


		Manageability_Commands_BE::Manageability_Commands_BE(bool isPfwUp) : Common_BE(isPfwUp)
		{
		}

		LMS_ERROR Manageability_Commands_BE::GetTheFeatureState(FEATURES feat, FEATURE_STATE &pState)
		{
			if ((feat < 0) || (feat >= FEATURES_NUM))
				return ERROR_INVALIDARG;

			try
			{
				Intel::MEI_Client::MKHI_Client::GetFWCapsCommand getCapabilitiesCommand(Intel::MEI_Client::MKHI_Client::FEATURES_CAPABLE);
				Intel::MEI_Client::MKHI_Client::GetFWCapsCommand getFeaturesStateCommand(Intel::MEI_Client::MKHI_Client::FEATURES_ENABLED);
				Intel::MEI_Client::MKHI_Client::GetFWCapsCommand getFeaturesAvailabilityCommand(Intel::MEI_Client::MKHI_Client::FEATURES_AVAILABLE);


				Intel::MEI_Client::MKHI_Client::MEFWCAPS_SKU_MKHI CapabilityData = getCapabilitiesCommand.getResponse();
				Intel::MEI_Client::MKHI_Client::MEFWCAPS_SKU_MKHI StateData = getFeaturesStateCommand.getResponse();
				auto AvailData = getFeaturesAvailabilityCommand.getResponse();

				UNS_DEBUG(L"CManageability_Commands::GetTheFeatureState Capability=0x%X State=0x%X Availability=0x%X\n", CapabilityData, StateData, AvailData);

				switch (feat)
				{
				case AMT:
					pState = FeatureStateLogic(CapabilityData.Fields.Amt, StateData.Fields.Amt, AvailData.Fields.Amt);
					break;
				case IRWT:
					pState = FeatureStateLogic(CapabilityData.Fields.Irwt, StateData.Fields.Irwt, AvailData.Fields.Irwt);
					break;
				case QST:
					pState = FeatureStateLogic(CapabilityData.Fields.Qst, StateData.Fields.Qst, AvailData.Fields.Qst);
					break;
				case TDT:
					pState = FeatureStateLogic(CapabilityData.Fields.Tdt, StateData.Fields.Tdt, AvailData.Fields.Tdt);
					break;
				case SOFTCREEK:
					pState = FeatureStateLogic(CapabilityData.Fields.SoftCreek, StateData.Fields.SoftCreek, AvailData.Fields.SoftCreek);
					break;
				case VE:
					pState = FeatureStateLogic(CapabilityData.Fields.Ve, StateData.Fields.Ve, AvailData.Fields.Ve);
					break;
					//this feature doesn't exist in the MKHI command
					/*case DT:
							pState=FeatureStateLogic(CapabilityData.Fields.Dt, StateData.Fields.Dt, AvailData.Fields.Dt);
							break;*/
				case NAND:
					pState = FeatureStateLogic(CapabilityData.Fields.Nand29, StateData.Fields.Nand29, AvailData.Fields.Nand29);
					break;
					//this feature doesn't exist in the MKHI command
					/*case MPC:
							pState=FeatureStateLogic(CapabilityData.Fields.Mpc, StateData.Fields.Mpc, AvailData.Fields.Mpc);
							break;*/
				case ICC_OVER_CLOCK_IN:
					pState = FeatureStateLogic(CapabilityData.Fields.IccOverClockin, StateData.Fields.IccOverClockin, AvailData.Fields.IccOverClockin);
					break;
				case PAV:
					pState = FeatureStateLogic(CapabilityData.Fields.Pav, StateData.Fields.Pav, AvailData.Fields.Pav);
					break;
				case SPK:
					pState = FeatureStateLogic(CapabilityData.Fields.Spk, StateData.Fields.Spk, AvailData.Fields.Spk);
					break;
				case RCA:
					pState = FeatureStateLogic(CapabilityData.Fields.Rca, StateData.Fields.Rca, AvailData.Fields.Rca);
					break;
				case RPAT:
					pState = FeatureStateLogic(CapabilityData.Fields.Rpat, StateData.Fields.Rpat, AvailData.Fields.Rpat);
					break;
				case IPV6:
					pState = FeatureStateLogic(CapabilityData.Fields.Ipv6, StateData.Fields.Ipv6, AvailData.Fields.Ipv6);
					break;
				case KVM:
					pState = FeatureStateLogic(CapabilityData.Fields.Kvm, StateData.Fields.Kvm, AvailData.Fields.Kvm);
					break;
				case OCH:
					pState = FeatureStateLogic(CapabilityData.Fields.Och, StateData.Fields.Och, AvailData.Fields.Och);
					break;
				case DAL:
					pState = FeatureStateLogic(CapabilityData.Fields.MEDAL, StateData.Fields.MEDAL, AvailData.Fields.MEDAL);
					break;
				case TLS:
					pState = FeatureStateLogic(CapabilityData.Fields.Tls, StateData.Fields.Tls, AvailData.Fields.Tls);
					break;
				case CILA:
					pState = FeatureStateLogic(CapabilityData.Fields.Cila, StateData.Fields.Cila, AvailData.Fields.Cila);
					break;
				case LAKEHOUSTON:
					pState = FeatureStateLogic(CapabilityData.Fields.LakeHouston, StateData.Fields.LakeHouston, AvailData.Fields.LakeHouston);
					break;
				default:
					return ERROR_INVALIDARG;
				}
				return ERROR_OK;
			}
			CATCH_MKHIErrorException(L"GetTheFeatureState")
			CATCH_MEIClientException(L"GetTheFeatureState")
			CATCH_exception(L"GetTheFeatureState")
			return ERROR_FAIL;
		}

		LMS_ERROR Manageability_Commands_BE::GetFeaturesState(std::vector<FEATURE_STATE> &ppStates)
		{
			try
			{
				Intel::MEI_Client::MKHI_Client::GetFWCapsCommand getCapabilitiesCommand(Intel::MEI_Client::MKHI_Client::FEATURES_CAPABLE);
				Intel::MEI_Client::MKHI_Client::GetFWCapsCommand getFeaturesStateCommand(Intel::MEI_Client::MKHI_Client::FEATURES_ENABLED);
				Intel::MEI_Client::MKHI_Client::GetFWCapsCommand getFeaturesAvailabilityCommand(Intel::MEI_Client::MKHI_Client::FEATURES_AVAILABLE);

				Intel::MEI_Client::MKHI_Client::MEFWCAPS_SKU_MKHI CapabilityData = getCapabilitiesCommand.getResponse();
				Intel::MEI_Client::MKHI_Client::MEFWCAPS_SKU_MKHI StateData = getFeaturesStateCommand.getResponse();
				auto AvailData = getFeaturesAvailabilityCommand.getResponse();

				UNS_DEBUG(L"CManageability_Commands::GetTheFeatureState Capability=0x%X State=0x%X Availability=0x%X\n", CapabilityData, StateData, AvailData);

				ppStates.resize(FEATURES_NUM);

				ppStates[AMT] = FeatureStateLogic(CapabilityData.Fields.Amt, StateData.Fields.Amt, AvailData.Fields.Amt);
				ppStates[IRWT] = FeatureStateLogic(CapabilityData.Fields.Irwt, StateData.Fields.Irwt, AvailData.Fields.Irwt);
				ppStates[QST] = FeatureStateLogic(CapabilityData.Fields.Qst, StateData.Fields.Qst, AvailData.Fields.Qst);
				ppStates[TDT] = FeatureStateLogic(CapabilityData.Fields.Tdt, StateData.Fields.Tdt, AvailData.Fields.Tdt);
				ppStates[SOFTCREEK] = FeatureStateLogic(CapabilityData.Fields.SoftCreek, StateData.Fields.SoftCreek, AvailData.Fields.SoftCreek);
				ppStates[VE] = FeatureStateLogic(CapabilityData.Fields.Ve, StateData.Fields.Ve, AvailData.Fields.Ve);
				//this feature doesn't exist in the MKHI command
				//ppStates[DT]=FeatureStateLogic(CapabilityData.Fields.Dt,StateData.Fields.Dt);
				ppStates[DT] = NOT_PRESENT;

				ppStates[NAND] = FeatureStateLogic(CapabilityData.Fields.Nand29, StateData.Fields.Nand29, AvailData.Fields.Nand29);
				//this feature doesn't exist in the MKHI command
				//ppStates[MPC]=FeatureStateLogic(CapabilityData.Fields.Mpc,StateData.Fields.Mpc);
				ppStates[MPC] = NOT_PRESENT;

				ppStates[ICC_OVER_CLOCK_IN] = FeatureStateLogic(CapabilityData.Fields.IccOverClockin, StateData.Fields.IccOverClockin, AvailData.Fields.IccOverClockin);
				ppStates[PAV] = FeatureStateLogic(CapabilityData.Fields.Pav, StateData.Fields.Pav, AvailData.Fields.Pav);
				ppStates[SPK] = FeatureStateLogic(CapabilityData.Fields.Spk, StateData.Fields.Spk, AvailData.Fields.Spk);
				ppStates[RCA] = FeatureStateLogic(CapabilityData.Fields.Rca, StateData.Fields.Rca, AvailData.Fields.Rca);
				ppStates[RPAT] = FeatureStateLogic(CapabilityData.Fields.Rpat, StateData.Fields.Rpat, AvailData.Fields.Rpat);
				ppStates[IPV6] = FeatureStateLogic(CapabilityData.Fields.Ipv6, StateData.Fields.Ipv6, AvailData.Fields.Ipv6);
				ppStates[KVM] = FeatureStateLogic(CapabilityData.Fields.Kvm, StateData.Fields.Kvm, AvailData.Fields.Kvm);
				ppStates[OCH] = FeatureStateLogic(CapabilityData.Fields.Och, StateData.Fields.Och, AvailData.Fields.Och);
				ppStates[DAL] = FeatureStateLogic(CapabilityData.Fields.MEDAL, StateData.Fields.MEDAL, AvailData.Fields.MEDAL);
				ppStates[TLS] = FeatureStateLogic(CapabilityData.Fields.Tls, StateData.Fields.Tls, AvailData.Fields.Tls);
				ppStates[CILA] = FeatureStateLogic(CapabilityData.Fields.Cila, StateData.Fields.Cila, AvailData.Fields.Cila);
				ppStates[LAKEHOUSTON] = FeatureStateLogic(CapabilityData.Fields.LakeHouston, StateData.Fields.LakeHouston, AvailData.Fields.LakeHouston);

				return ERROR_OK;
			}
			CATCH_MKHIErrorException(L"GetTheFeatureState")
			CATCH_MEIClientException(L"GetTheFeatureState")
			CATCH_exception(L"GetTheFeatureState")
			return ERROR_FAIL;
		}

		CUSTOMER_TYPE GetPlatformTypeExt(const Intel::MEI_Client::MKHI_Client::MKHI_PLATFORM_TYPE *Platform)
		{
			bool isME11 = true;

			try
			{
				Intel::MEI_Client::MKHI_Client::GetFWVersionCommand getFWVersionCommand;
				Intel::MEI_Client::MKHI_Client::GET_FW_VER_RESPONSE res = getFWVersionCommand.getResponse();
				if (res.FTMajor < 11)
				{
					isME11 = false;
				}
			}
			CATCH_exception(L"getFWVersionCommand")

			if (isME11)
			{
				if (Platform->Fields.ImageType == Intel::MEI_Client::MKHI_Client::MPT_IMAGE_TYPE_FULL_SKU)
				{
					return CORPORATE;
				}
				if (Platform->Fields.ImageType == Intel::MEI_Client::MKHI_Client::MPT_IMAGE_TYPE_SMALL_SKU)
				{
					return CONSUMER;
				}
			}
			else
			{
				Intel::MEI_Client::MKHI_Client::MKHI_PLATFORM_TYPE_ME10 * Platform10 = (Intel::MEI_Client::MKHI_Client::MKHI_PLATFORM_TYPE_ME10 *)Platform;
				if (Platform10->Fields.Corporate)
				{
					return CORPORATE;
				}
				if (Platform10->Fields.Consumer)
				{
					return CONSUMER;
				}
			}
			return WRONG_CUSTOMER_TYPE;
		}

		LMS_ERROR Manageability_Commands_BE::GetCustomerType(CUSTOMER_TYPE &pType)
		{
			try
			{
				Intel::MEI_Client::MKHI_Client::GetPlatformTypeCommand getPlatformTypeCommand;
				Intel::MEI_Client::MKHI_Client::MKHI_PLATFORM_TYPE Platform = getPlatformTypeCommand.getResponse();
				UNS_DEBUG(L"CManageability_Commands::GetCustomerType: Platform=0x%X \n", Platform.Data);

				pType = GetPlatformTypeExt(&Platform);
				if (pType == WRONG_CUSTOMER_TYPE)
					return ERROR_UNEXPECTED;
				return ERROR_OK;
			}
			CATCH_MKHIErrorException(L"GetPlatformTypeExt")
			CATCH_MEIClientException(L"GetPlatformTypeExt")
			CATCH_exception(L"GetPlatformTypeExt")
			return ERROR_FAIL;
		}

		LMS_ERROR Manageability_Commands_BE::GetPlatformType(PLATFORM_TYPE &pType)
		{
			try
			{
				Intel::MEI_Client::MKHI_Client::GetPlatformTypeCommand getPlatformTypeCommand;
				Intel::MEI_Client::MKHI_Client::MKHI_PLATFORM_TYPE Platform = getPlatformTypeCommand.getResponse();

				UNS_DEBUG(L"CManageability_Commands::GetPlatformType: Platform=0x%X \n", Platform.Data);
				if (Platform.Fields.Desktop)
					pType = DESKTOP;
				else
					if (Platform.Fields.Mobile)
						pType = MOBILE;
					else
						if (Platform.Fields.Server)
							pType = SERVER;
						else
							if (Platform.Fields.WorkStn)
								pType = WORKSTATION;
							else
								return ERROR_UNEXPECTED;
				return ERROR_OK;
			}
			CATCH_MKHIErrorException(L"GetPlatformTypeCommand")
			CATCH_MEIClientException(L"GetPlatformTypeCommand")
			CATCH_exception(L"GetPlatformTypeCommand")
			return ERROR_FAIL;
		}

		LMS_ERROR Manageability_Commands_BE::GetMenageabiltyMode(MENAGEABILTY_MODE &pMode)
		{
			try
			{
				Intel::MEI_Client::MKHI_Client::GetPlatformTypeCommand getPlatformTypeCommand;
				Intel::MEI_Client::MKHI_Client::MKHI_PLATFORM_TYPE Platform = getPlatformTypeCommand.getResponse();

				MenageabiltyModeLogic(Platform, pMode);
				UNS_DEBUG(L"CManageability_Commands::GetMenageabiltyMode platform=0x%X MenageabilityMode=%d\n", Platform, pMode);
				return ERROR_OK;
			}
			CATCH_MKHIErrorException(L"GetPlatformTypeCommand")
			CATCH_MEIClientException(L"GetPlatformTypeCommand")
			CATCH_exception(L"GetPlatformTypeCommand")
			return ERROR_FAIL;
		}

		LMS_ERROR Manageability_Commands_BE::GetFWInfo(std::string &pMEBxVersion, unsigned long &pBiosBootState, bool &pCryptoFuseEnable, bool &pLocalFWupdateEnable)
		{
			MEBX_BIOS_VER version;

			//use SMBIOS to get MEBx version
			SMBIOS_Reader sm_reader;
			if (sm_reader.CheckForSmbiosFlags() == 0)
			{
				version.MEBxMajor = sm_reader.pCapabilities.MEBx_Major;
				version.MEBxMinor = sm_reader.pCapabilities.MEBx_Minor;
				version.MEBxHotFix = sm_reader.pCapabilities.MEBx_Hotfix;
				version.MEBxBuildNo = sm_reader.pCapabilities.MEBx_Build;
			}
			else
			{
				return ERROR_FAIL;
			}

			std::stringstream ss;
			ss << version.MEBxMajor << "." << version.MEBxMinor << "." << version.MEBxHotFix << ".";
			ss << std::setfill('0') << std::setw(4) << version.MEBxBuildNo;
			pMEBxVersion = ss.str();

			bool isME12andUp = true;
			try
			{
				Intel::MEI_Client::MKHI_Client::GetFWVersionCommand getFWVersionCommand;
				Intel::MEI_Client::MKHI_Client::GET_FW_VER_RESPONSE res = getFWVersionCommand.getResponse();
				if (res.FTMajor < 12)
				{
					isME12andUp = false;
				}
			}
			CATCH_MKHIErrorException(L"GetFWVersionCommand")
			CATCH_MEIClientException(L"GetFWVersionCommand")
			CATCH_exception(L"GetFWVersionCommand")

			if (isME12andUp)
			{
				try
				{
					Intel::MEI_Client::MKHI_Client::GetEOPStateCommand getEOPStateCommand;
					Intel::MEI_Client::MKHI_Client::GET_EOP_STATE_RESPONSE res = getEOPStateCommand.getResponse();

					//For compatibility with pre 12 API output
					if (res.Fields.EopState == 0)
					{
						pBiosBootState = 2;
					}
					else
					{
						pBiosBootState = 0;
					}
				}
				CATCH_MKHIErrorException(L"GetEOPStateCommand")
				CATCH_MEIClientException(L"GetEOPStateCommand")
				CATCH_exception(L"GetEOPStateCommand")
			}
			else
			{
				try
				{
					Intel::MEI_Client::FWUpdate_Client::FWUGetInfoCommand getInfoCommand;
					Intel::MEI_Client::FWUpdate_Client::GET_INFO_RESPONSE info = getInfoCommand.getResponse();

					pBiosBootState = info.BiosBootState;
				}
				CATCH_FWUpdateErrorException(L"FWUGetInfoCommand")
				CATCH_MEIClientException(L"FWUGetInfoCommand")
				CATCH_exception(L"FWUGetInfoCommand")
			}

			try
			{
				Intel::MEI_Client::MKHI_Client::GetFWCapsCommand getCapabilitiesCommand(Intel::MEI_Client::MKHI_Client::FEATURES_CAPABLE);
				Intel::MEI_Client::MKHI_Client::MEFWCAPS_SKU_MKHI CapabilityData = getCapabilitiesCommand.getResponse();
				//TODO : that's the way we do it in MEProv, why don't we check if enabled?
				// in addition, we can get it using  GetAMTStateCommand
				pCryptoFuseEnable = CapabilityData.Fields.Tls;
			}
			CATCH_MKHIErrorException(L"GetFWCapsCommand")
			CATCH_MEIClientException(L"GetFWCapsCommand")
			CATCH_exception(L"GetFWCapsCommand")

			pLocalFWupdateEnable = false;
			try
			{
				Intel::MEI_Client::MKHI_Client::GetFWUpdateStateCommand getFWUpdateStateCommand;
				Intel::MEI_Client::MKHI_Client::FW_UPDATE_STATE verinfo = getFWUpdateStateCommand.getResponse();
				pLocalFWupdateEnable = (verinfo.Data == Intel::MEI_Client::MKHI_Client::FW_UPDATE_ENABLED) ||
									   (verinfo.Data == Intel::MEI_Client::MKHI_Client::FW_UPDATE_PASSWORD_PROTECTED);
			}
			CATCH_MKHIErrorException(L"GetFWUpdateStateCommand")
			CATCH_MEIClientException(L"GetFWUpdateStateCommand")
			CATCH_exception(L"GetFWUpdateStateCommand")
			UNS_DEBUG(L"CManageability_Commands::GetFWInfo: MEBxVersion=%s BiosBootState=%d CryptoFuseEnable=%d LocalFWupdateEnable=%d\n",
				pMEBxVersion.c_str(), pBiosBootState, pCryptoFuseEnable, pLocalFWupdateEnable);
			return ERROR_OK;
		}

#define FPT_PARTITION_NAME_PMCP 0x50434D50 /**< "PMCP" Partition Name*/

		LMS_ERROR Manageability_Commands_BE::GetPMCVersion(std::string &pFwVer)
		{
			bool isME12andUp = true;
			try
			{
				Intel::MEI_Client::MKHI_Client::GetFWVersionCommand getFWVersionCommand;
				Intel::MEI_Client::MKHI_Client::GET_FW_VER_RESPONSE res = getFWVersionCommand.getResponse();
				if (res.FTMajor < 12)
				{
					isME12andUp = false;
				}
			}
			CATCH_MKHIErrorException(L"GetFWVersionCommand")
			CATCH_MEIClientException(L"GetFWVersionCommand")
			CATCH_exception(L"GetFWVersionCommand")

			if (isME12andUp)
			{
				try
				{
					Intel::MEI_Client::MKHI_Client::GetImageFWVersionCommand getImageFWVersionCommand(FPT_PARTITION_NAME_PMCP);
					Intel::MEI_Client::MKHI_Client::GET_IMAGE_FW_VERSION_RESPONSE res = getImageFWVersionCommand.getResponse();

					if (res.NumOfModules != 1)
					{
						UNS_DEBUG(L"GetFWVersionCommand returned wrong number of modules %d\n", res.NumOfModules);
						return ERROR_FAIL;
					}

					std::stringstream ss;
					ss << res.ManifestData[0].Version.Major << ".";
					ss << res.ManifestData[0].Version.Minor << ".";
					ss << res.ManifestData[0].Version.Hotfix << ".";
					ss << std::setfill('0') << std::setw(4) << res.ManifestData[0].Version.Build;
					pFwVer = ss.str();

					return ERROR_OK;
				}
				CATCH_MKHIErrorException(L"GetImageFWVersionCommand")
				CATCH_MEIClientException(L"GetImageFWVersionCommand")
				CATCH_exception(L"GetImageFWVersionCommand")
				return ERROR_FAIL;
			}
			else
			{
				// No PMCP partition in FW < 12
				pFwVer = "";
				return ERROR_OK;
			}
		}
	}
}