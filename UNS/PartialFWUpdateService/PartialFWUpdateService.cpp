/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2010-2024 Intel Corporation
 */
#include "PartialFWUpdateService.h"

#include <ace/OS_NS_stdio.h>
#include <ace/OS_NS_string.h>
#include <ace/OS_NS_dirent.h>
#include <ace/Dirent_Selector.h>
#include <ace/Containers_T.h>
#include "EventManagment.h"
#include "Tools.h"

#include "UNSEventsDefinition.h"
#include "DataStorageGenerator.h"
#include "SIOWSManClient.h"

#include "PFWUpdateDllWrapperFactory.h"

#include "MKHIErrorException.h"
#include "GetFWVersionCommand.h"
#include "GetPlatformTypeCommand.h"
#include "GetImageTypeCommand.h"
#include "FWUpdateCommand.h"

#include <iostream>
#include <memory>
#include <set>

const ACE_TString PARTIAL_FW_UPDATE_BEGIN_MESSAGE_INIT(ACE_TEXT("Partial FW update begin - "));
#define PARTIAL_FW_UPDATE_END_INIT				L"Partial FW update "
const ACE_TString MISSING_IMAGE_FILE_MSG(ACE_TEXT("Partial FW update failed due missing image file"));

class PartialFWUpdateEventsFilter: public EventsFilter
{
public:
	PartialFWUpdateEventsFilter(unsigned int maxEventID = MAX_EVENT_NUM);
	~PartialFWUpdateEventsFilter();
	virtual bool toSubscribe(const GMS_AlertIndication *alert) const;
	bool addEvent(unsigned int eventID);
	static bool defaultInitialization(std::shared_ptr<PartialFWUpdateEventsFilter> & filter);
private:
	ACE_Array<unsigned int> eventsIDList_;
	unsigned int arrayMaxElement_;
};


PartialFWUpdateEventsFilter::PartialFWUpdateEventsFilter(unsigned int maxEventID):eventsIDList_(maxEventID+1, 0, NULL), arrayMaxElement_(maxEventID)
{}

PartialFWUpdateEventsFilter::~PartialFWUpdateEventsFilter() {}

bool PartialFWUpdateEventsFilter::addEvent(unsigned int eventID)
{
	if (eventID > arrayMaxElement_)
		return false;
	eventsIDList_[eventID] = 1;
	return true;
}

bool PartialFWUpdateEventsFilter::toSubscribe(const GMS_AlertIndication *alert) const
{
	if (alert->id <= arrayMaxElement_)
	{
		if (eventsIDList_[alert->id] == 1)
		{
			return true;
		}
	}
	return false;
}

bool PartialFWUpdateEventsFilter::defaultInitialization(std::shared_ptr<PartialFWUpdateEventsFilter> & filter)
{
	if (
		filter->addEvent(EVENT_PORT_FORWARDING_SERVICE_AVAILABLE)
		) //if
		return true;
	UNS_ERROR(L"filter initialization failed\n");
	return false;
}

PartialFWUpdateService::PartialFWUpdateService() :
	filter_(std::make_shared<PartialFWUpdateEventsFilter>()), m_PfuRequiredButNoPfw(false),
	langID(PRIMARYLANGID(GetSystemDefaultLCID())), mode(LANGUAGE_FLOW_MODE::INITIAL), schedPFUAfterResume_(false)
{
	PartialFWUpdateEventsFilter::defaultInitialization(filter_);

}

std::shared_ptr<EventsFilter> PartialFWUpdateService::getFilter()
{
	return filter_;
}

int PartialFWUpdateService::init(int argc, ACE_TCHAR *argv[])
{
	int retVal = EventHandler::init(argc, argv);
	if (retVal != 0)
	{
		UNS_ERROR(L"EventHandler::init failed. retVal: %d\n", retVal);
		return retVal;
	}

	startSubService();

	//send message to the service to start it self after init - we want to start after the handlers have started
	startPFWUpMessage();
	initTimestamp = ACE_OS::gettimeofday();
	return 0;
}

const ACE_TString PartialFWUpdateService::name()
{
	return GMS_PARTIALFWUPDATESERVICE;
}


int PartialFWUpdateService::resume()
{
	GmsSubService::resume();
	UNS_DEBUG(L"PartialFWUpdateService::resume(). Service resumed, PFWUp flow will be scheduled after PFWS is up, to see if HW changed during hiberboot.\n");
	schedPFUAfterResume_ = true;
	return 0;
}

//Starting PFWUp flow by sending a message to self (in order to verify the order of actions).
void PartialFWUpdateService::startPFWUpMessage()
{
	MessageBlockPtr mbPtr(new ACE_Message_Block(), deleteMessageBlockPtr);
	mbPtr->data_block(new StartPFWUP());
	mbPtr->msg_type(MB_PFWU_START_EVENT);
	mbPtr->msg_priority(3);//higher than normal messages
	this->putq(mbPtr->duplicate());
}

LMS_SUBSERVICE_DEFINE (PARTIALFWUPDATESERVICE, PartialFWUpdateService)

/* Business logic */
int PartialFWUpdateService::handle_event (MessageBlockPtr mbPtr )
{
	int type=mbPtr->msg_type();
	GMS_AlertIndication * pGMS_AlertIndication = nullptr;
	StartPFWUP * pStartPFWUP = nullptr;
	FuncEntryExit<decltype(type)> fee(this, L"handle_event", type);
	switch (type)
	{
	case MB_PFWU_EVENT:
		UNS_DEBUG(L"PartialFWUpdateService: MB_PFWU_EVENT\n");
		if (!getAllowFlashUpdate())
		{
			UNS_DEBUG(L"Feature disabled in registry\n");
			publishPartialFWUpgrade_failed(PARTIAL_FWU_MODULE::LANGUAGE, L"- feature disabled in registry", 8719);
			return 1;
		}

		pStartPFWUP = dynamic_cast<StartPFWUP*>(mbPtr->data_block());
		if (pStartPFWUP != nullptr)
		{
			return partialFWUpdate(pStartPFWUP->value, LANGUAGE_FLOW_MODE::MANUAL, true);
		}
		else
		{
			ACE_ERROR_RETURN((LM_ERROR, ACE_TEXT("PartialFWUpdateService::Invalid data block.\n")), -1);
		}
		break;
	case MB_PFWU_START_EVENT:
		UNS_DEBUG(L"PartialFWUpdateService: MB_PFWU_START_EVENT\n");
		if (getAllowFlashUpdate())
		{
			partialFWUpdate();
		}
		else
		{
			UNS_DEBUG(L"Feature disabled in registry\n");
		}
		return 1;
		break;
	case MB_PUBLISH_EVENT:
		pGMS_AlertIndication = dynamic_cast<GMS_AlertIndication*>(mbPtr->data_block());
		if (pGMS_AlertIndication != nullptr)
		{
			return handlePublishEvent(*pGMS_AlertIndication);
		}
		else
		{
			ACE_ERROR_RETURN((LM_ERROR, ACE_TEXT("PartialFWUpdateService::Invalid data block.\n")), -1);
		}
	}

	ACE_ERROR_RETURN((LM_ERROR, ACE_TEXT("PartialFWUpdateService::Invalid Message.\n")), -1);
}




int PartialFWUpdateService::handlePublishEvent(const GMS_AlertIndication & alert)
{

	switch (alert.category)
	{

	case CATEGORY_UNS:
		switch (alert.id)
		{
		case EVENT_PORT_FORWARDING_SERVICE_AVAILABLE:
		{
			UNS_DEBUG(L"%s got EVENT_PORT_FORWARDING_SERVICE_AVAILABLE. schedPFUAfterResume_: %d, m_PfuRequiredButNoPfw: %d\n", name().c_str(), schedPFUAfterResume_, m_PfuRequiredButNoPfw);

			if (schedPFUAfterResume_)
			{
				schedPFUAfterResume_ = false;

				//Starting PFWUp flow. There is no need to do this in sleep and in hibernate, but there is need
				// in hiberboot (Win 8 and up).
				//In hibernate the PFWU is done in the init, and here it will be duplicate. So if more than 5 seconds passed from the init, there may be hiberboot, and do PFWU.
				// Otherwise, we are right after the init and do nothing
				ACE_Time_Value now = ACE_OS::gettimeofday();
				if ((now.sec() - initTimestamp.sec()) > 5)
					startPFWUpMessage();
			}

			if (m_PfuRequiredButNoPfw)
			{
				m_PfuRequiredButNoPfw = false;
				startPFWUpMessage();
			}

			return 1;
			break;
		}
		default:
			ACE_ERROR_RETURN((LM_ERROR, ACE_TEXT("PartialFWUpdateService::Invalid Message id.\n")), -1);
			break;

		}
		break;

	default:
		ACE_ERROR_RETURN((LM_ERROR, ACE_TEXT("PartialFWUpdateService::Invalid Message category.\n")), -1);
		break;
	}
}

// Registry handlers
bool getBoolRegistryKey(DATA_NAME storageName , bool defaultValue)
{

	DWORD value;
	if (!(DSinstance().GetDataValue(storageName, value, false)))
	{
		return defaultValue;
	}
	if (value == 0)
	{
		return false;
	}
	else if (value == 1)
	{
		return true;
	}
	else //default behaviour -  true
		return defaultValue;
}

bool PartialFWUpdateService::getAllowFlashUpdate() const
{
	return getBoolRegistryKey(ALLOW_FLASH_UPDATE, true);
}

bool PartialFWUpdateService::getPartialFWUpdateImagePath(std::wstring& value)
{
	return DSinstance().GetDataValue(PARTIAL_FWU_IMAGE_PATH, value, false);
}

// Publish events
void PartialFWUpdateService::publishPartialFWUpgrade_begin(PARTIAL_FWU_MODULE module)
{
	ACE_TString moduleStr;

	switch (module)
	{
	case PARTIAL_FWU_MODULE::LANGUAGE:
		moduleStr = ACE_TEXT("Language update");
		break;
	case PARTIAL_FWU_MODULE::WLAN:
		moduleStr = ACE_TEXT("WLAN uCode update");
		break;
	default:
		return;
	}
	UNS_DEBUG(L"publishPartialFWUpgrade_begin %s\n", moduleStr.c_str());
	sendAlertIndicationMessage(CATEGORY_PARTIAL_FW_UPDATE, EVENT_PARTIAL_FWU_BEGIN, PARTIAL_FW_UPDATE_BEGIN_MESSAGE_INIT);
}

void PartialFWUpdateService::publishPartialFWUpgrade_failed(PARTIAL_FWU_MODULE module, const std::wstring& returnValue, int error)
{
	FuncEntryExit<decltype(error)> fee(this, L"publishPartialFWUpgrade_failed", error);
	unsigned long eventID = EVENT_PARTIAL_FWU_END_FAILURE_LANG;
	if(module == PARTIAL_FWU_MODULE::WLAN)
		eventID = EVENT_PARTIAL_FWU_END_FAILURE_WLAN;
	std::wstringstream strStream, errorStream;
	strStream << returnValue <<L".";

	errorStream << error;
	sendAlertIndicationMessage(CATEGORY_PARTIAL_FW_UPDATE, eventID,
		ACE_TEXT_WCHAR_TO_TCHAR(strStream.str().c_str()), ACE_TEXT_WCHAR_TO_TCHAR(errorStream.str().c_str()));

}

void PartialFWUpdateService::publishPartialFWUpgrade_end(PARTIAL_FWU_MODULE module, int returnValue)
{
	std::wstring state;
	unsigned long eventID;
	std::wstringstream strStream;
	std::wstringstream tmpbuffer_s;

	FuncEntryExit<decltype(returnValue)> fee(this, L"publishPartialFWUpgrade_end", returnValue);

	if(returnValue == 0)
	{
		state = L"success";
		if(module == PARTIAL_FWU_MODULE::WLAN)
			eventID = EVENT_PARTIAL_FWU_END_SUCCESS_WLAN;
		else
			eventID = EVENT_PARTIAL_FWU_END_SUCCESS_LANG;
	}
	else
	{
		state = L"failed with error ";
		if(module == PARTIAL_FWU_MODULE::WLAN)
			eventID = EVENT_PARTIAL_FWU_END_FAILURE_WLAN;
		else
			eventID = EVENT_PARTIAL_FWU_END_FAILURE_LANG;
		tmpbuffer_s<<returnValue;
	}
	strStream << PARTIAL_FW_UPDATE_END_INIT << state;

	ACE_TString arg;
	if ((eventID == EVENT_PARTIAL_FWU_END_FAILURE_LANG) || (eventID == EVENT_PARTIAL_FWU_END_FAILURE_WLAN))
		arg = ACE_TEXT_WCHAR_TO_TCHAR(tmpbuffer_s.str().c_str());

	sendAlertIndicationMessage(CATEGORY_PARTIAL_FW_UPDATE, eventID,
		ACE_TEXT_WCHAR_TO_TCHAR(strStream.str().c_str()), arg);
}

void PartialFWUpdateService::publishMissingImageFile(PARTIAL_FWU_MODULE module)
{
	unsigned long eventID;

	if(module == PARTIAL_FWU_MODULE::WLAN)
		eventID = EVENT_PARTIAL_FWU_MISSING_IMAGE_WLAN;
	else
		eventID = EVENT_PARTIAL_FWU_MISSING_IMAGE_LANG;
	UNS_DEBUG(L"publishMissingImageFile %d\n", module);
	sendAlertIndicationMessage(CATEGORY_PARTIAL_FW_UPDATE, eventID, MISSING_IMAGE_FILE_MSG);
}

bool PartialFWUpdateService::checkImageFileExist(std::wstring &imagePath)
{
	bool retVal = false;
	std::wstring lmsPath;
	std::wstring path;
	std::wstring value;

	FuncEntryExit<decltype(retVal)>(this, L"checkImageFileExist", retVal);

	if (GetServiceDirectory(L"LMS", lmsPath) != true)
	{
		UNS_ERROR("PartialFWUpdateService::checkImageFileExist Failed getting LMS path\n");
		return retVal;
	}
	lmsPath = lmsPath.substr(0, lmsPath.length() - 7); // 7 is length of "LMS.exe", we need the directory, not the file.


	if (getPartialFWUpdateImagePath(value)) //check if we have an explicit image path in registry
	{
		UNS_DEBUG(L"PFU image from registry: '%W'\n", value.c_str());
		if (value.find(L":\\") == 1) //Absolute path
		{
			path = value;
		}
		else if (value.find(L".\\") == 0) //Relative path beginning with ".\"
		{
			path = lmsPath + value.substr(2, value.size() - 2); //concatenate the relative path, substr is used to eliminate the ".\"

		}
		else
		{
			path = lmsPath + value;
		}
	}
	else //no path in registry, use the executable path
	{
		if (!getImageFileNameByFwVersion(value, lmsPath))
			return false; //TODO - another event log message?

		path = lmsPath + value;
	}

	UNS_DEBUG(L"checkImageFileExist path: '%W'\n", path.c_str());
	if(checkFileExist(path))
	{
		imagePath = path;
		retVal = true;
	}
	else
	{
		UNS_ERROR(L"File is missing: '%W'\n", path.c_str());
	}
	return retVal;
}

const wchar_t* templateOfPfu = L"PFU.BIN";

static int
selector(const ACE_DIRENT *d)
{
	return ACE_OS::strnstr(d->d_name, templateOfPfu, ACE_OS::strlen(templateOfPfu)) > 0;
}

bool PartialFWUpdateService::LoadFwUpdateLibDll()
{
	try
	{
		if (!pfwuWrapper) // Initialize only once
		{
			using namespace Intel::MEI_Client::MKHI_Client;
			using namespace Intel::MEI_Client;

			GetFWVersionCommand  getFWVersionCommand;
			GET_FW_VER_RESPONSE version = getFWVersionCommand.getResponse();

			pfwuWrapper = PFWUpdateDllWrapperFactory::Create(version.FTMajor, version.FTMinor);
		}
		return true;
	}
	catch (std::exception e)
	{
		UNS_ERROR(L"LoadFwUpdateLibDll failed. Error: %C\n", e.what());
	}
	catch (...) {}
	return false;
}

class PFUBase
{
public:
	PFUBase() : major(0), minor(0), hotfix(0), build(0) {}
	PFUBase(uint16_t _major, uint16_t _minor, uint16_t _hotfix, uint16_t _build) :
		major(_major), minor(_minor), hotfix(_hotfix), build(_build) {}
	PFUBase& operator = (const PFUBase &other)
	{
		if (this != &other)
		{
			major = other.major;
			minor = other.minor;
			hotfix = other.hotfix;
			build = other.build;
		}
		return *this;
	}
	PFUBase(const PFUBase &other)
	{
		major = other.major;
		minor = other.minor;
		hotfix = other.hotfix;
		build = other.build;
	}

	friend bool operator < (const PFUBase &left, const PFUBase &right) noexcept
	{
		if (left.major < right.major)
			return true;
		if (left.major > right.major)
			return false;
		if (left.minor < right.minor)
			return true;
		if (left.minor > right.minor)
			return false;
		if (left.hotfix < right.hotfix)
			return true;
		if (left.hotfix > right.hotfix)
			return false;
		if (left.build < right.build)
			return true;
		if (left.build > right.build)
			return false;
		return false;
	}

	friend bool operator == (const PFUBase &left, const PFUBase &right) noexcept
	{
		return ((left.major == right.major) &&
			(left.minor == right.minor) &&
			(left.hotfix == right.hotfix) &&
			(left.build == right.build));
	}
public:
	uint16_t major;
	uint16_t minor;
	uint16_t hotfix;
	uint16_t build;
};

class PFUFile : public PFUBase
{
public:
	PFUFile(const std::wstring &_filename, bool production) : filename(_filename)
	{
		// The file name is in following format: MMmmHF_PX_PFU.bin
		// MM - major
		// mm - minor
		// HF - hotfix
		// PX - PP for pre-production and PD for production
		wchar_t buf[3];

		if (filename.length() != 17)
		{
			throw std::invalid_argument("wrong file name size");
		}
		buf[0] = filename[0];
		buf[1] = filename[1];
		buf[2] = '\0';
		major = _wtoi(buf);
		if (!major)
		{
			throw std::invalid_argument("major is zero");
		}
		buf[0] = filename[2];
		buf[1] = filename[3];
		buf[2] = '\0';
		minor = _wtoi(buf);
		buf[0] = filename[4];
		buf[1] = filename[5];
		buf[2] = '\0';
		hotfix = _wtoi(buf);
		build = 0;
		if (filename[6] != '_' || filename[7] != 'P')
		{
			throw std::invalid_argument("_P is missed");
		}
		if (production != (filename[8] == 'D'))
		{
			throw std::domain_error("production type does not match");
		}
	}
	PFUFile& operator = (const PFUFile &other)
	{
		if (this != &other)
		{
			PFUBase::operator=(other);
			filename = other.filename;
		}
		return *this;
	}
	PFUFile(const PFUFile &other) : PFUBase(other)
	{
		filename = other.filename;
	}
	PFUFile(const PFUBase &other) : PFUBase(other) {}
	~PFUFile() {}

public:
	std::wstring filename;
};

class PFUMap
{
public:
	PFUMap(bool _production) : production(_production) {}
	void add(const std::wstring &filename)
	{
		try
		{
			pfu_set.insert(PFUFile(filename, production));
		}
		catch (const std::exception &ex)
		{
			UNS_DEBUG(L"ignoring PFU '%W' %W %C\n",
					  filename.c_str(), (production) ? L"PD" : L"PP", ex.what());
		}
	}

	// Look for PFU file with version lower or equal to target,
	// same major number
	std::wstring get_pfu(const PFUBase &target)
	{
		if (pfu_set.empty())
		{
			throw std::out_of_range("set is empty");
		}
		auto it = pfu_set.upper_bound(target);
		if (it == pfu_set.begin())
		{
			throw std::out_of_range("too old");
		}
		it = std::prev(it);

		if (it->major != target.major)
		{
			throw std::out_of_range("major is wrong");
		}
		// For ME11 any minor number is acceptable
		// For ME12 and up minor should be in the same backet of 5
		if ((it->major > 11) && !in_same_backet(it->minor, target.minor))
		{
			throw std::out_of_range("minor is wrong");
		}
		return it->filename;
	}
private:
	std::set<PFUFile> pfu_set;
	bool production;

	bool in_same_backet(uint16_t left, uint16_t right)
	{ // backet of 5 (0-4, 5-9, etc.)
		return ((left / 5) == (right / 5));
	}
};

//get the image file name according to FW version, return false at failure
bool PartialFWUpdateService::getImageFileNameByFwVersion(std::wstring &fileName, const std::wstring &lmsPath)
{
	try
	{
		using namespace Intel::MEI_Client::MKHI_Client;
		using namespace Intel::MEI_Client;

		bool isProduction = false;

		GetFWVersionCommand getFWVersionCommand;
		GET_FW_VER_RESPONSE fwVersion = getFWVersionCommand.getResponse();

		if (fwVersion.FTMajor >= 12) //ME12 and later - use PlatformType
		{
			GetPlatformTypeCommand getPlatformTypeCommand;
			MKHI_PLATFORM_TYPE platformType = getPlatformTypeCommand.getResponse();

			isProduction = platformType.Fields.ProdSigned;
		}
		else //ME11 and before - use ImageType
		{
			GetImageTypeCommand getImageTypeCommand;
			MKHI_IMAGE_TYPE imageType = getImageTypeCommand.getResponse();

			isProduction = imageType.ImageSignData;
		}

		//Get existing *PFU.BIN files in LMS folder
		ACE_Dirent_Selector lmsDir;
		// Pass in function that'll specify the selection criteria.
		int status = lmsDir.open(ACE_TEXT_WCHAR_TO_TCHAR(lmsPath.c_str()), selector, ACE_SCANDIR_COMPARATOR(ACE_OS::alphasort));
		if (status == -1)
		{
			UNS_ERROR("PartialFWUpdateService::getImageFileNameByFwVersion Failed opening: %W\n", lmsPath.c_str());
			return false;
		}

		PFUMap pfuMap(isProduction);
		for (int n = 0; n < lmsDir.length(); ++n)
		{
			pfuMap.add(ACE_TEXT_ALWAYS_WCHAR(lmsDir[n]->d_name));
		}

		status = lmsDir.close();
		if (status == -1)
		{
			UNS_ERROR("PartialFWUpdateService::getImageFileNameByFwVersion Failed closing: %W\n", lmsPath.c_str());
			return false;
		}

		fileName = pfuMap.get_pfu(PFUBase(fwVersion.FTMajor, fwVersion.FTMinor, fwVersion.FTHotFix, fwVersion.FTBuildNo));

		return true;
	}
	catch (Intel::MEI_Client::MKHI_Client::MKHIErrorException& e)
	{
		UNS_ERROR(L"PartialFWUpdateService::getImageFileNameByFwVersion failed: %C\n", e.what());
	}
	catch (Intel::MEI_Client::MEIClientException& e)
	{
		UNS_ERROR(L"PartialFWUpdateService::getImageFileNameByFwVersion failed: %C\n", e.what());
	}
	catch (std::out_of_range& e)
	{
		UNS_ERROR(L"PartialFWUpdateService::getImageFileNameByFwVersion The best match PFU file is not found: %C\n", e.what());
	}
	catch (std::exception& e)
	{
		UNS_ERROR(L"Exception in PartialFWUpdateService::getImageFileNameByFwVersion: %C\n", e.what());
	}
	catch(...)
	{
		UNS_ERROR(L"Exception in PartialFWUpdateService::getImageFileNameByFwVersion\n");
	}
	return false;

}

bool PartialFWUpdateService::isMESKU() const
{
	bool res = false;
	FuncEntryExit<decltype(res)>(this, L"isMESKU", res);
	//Lock lock(FWUpdate_Client::FWUpdateCommand::getInternalSemaphore());
	try
	{
		using namespace Intel::MEI_Client;
		//NOTE: we can't convert this call to MKHI command, since calling this command check also that
		//FWUpdate Client isn't caught by an external application. Otherwise the program will get stuck
		// at the Lock constructor in the beginning of invokePartialFWUpdateFlow if the handle is caught
		MKHI_Client::GetPlatformTypeCommand getPlatformTypeCommand;
		MKHI_Client::MKHI_PLATFORM_TYPE Platform = getPlatformTypeCommand.getResponse();

		UNS_DEBUG(L"FW ImageType=%d\n",Platform.Fields.ImageType);
		res = (Platform.Fields.ImageType == MKHI_Client::ME_FULL_8MB);
	}
	catch (Intel::MEI_Client::MKHI_Client::MKHIErrorException& e)
	{
		UNS_ERROR(L"GetPlatformTypeCommand failed %C\n", e.what());
	}
	catch (Intel::MEI_Client::MEIClientException& e)
	{
		UNS_ERROR(L"GetPlatformTypeCommand %C\n", e.what());
	}
	catch (std::exception& e)
	{
		UNS_ERROR(L"Exception in GetPlatformTypeCommand %C\n", e.what());
	}

	return res;
}

bool PartialFWUpdateService::updateLanguageChangeCode(UINT32 languageID, LANGUAGE_FLOW_MODE mode)
{
	bool res = false;
	FuncEntryExit<decltype(res)>(this, L"updateLanguageChangeCode", res);
	bool defaultLangSet = (languageID == DEFAULT_LANG_ID);

	if (defaultLangSet)
	{
		languageID = getUCLanguageID();
	}

	SIOWSManClient client(m_mainService->GetPortForwardingPort());
	unsigned short currentLang = 0;

	if (!client.GetSpriteLanguage(&currentLang))
	{
		publishPartialFWUpgrade_failed(PARTIAL_FWU_MODULE::LANGUAGE, L"- Failed to get FW status", 8725);
		return res;
	}

	UNS_DEBUG(L"Current language %u\n", (unsigned int)currentLang);
	UNS_DEBUG(L"Requested language %s%d\n", defaultLangSet ? "(System Default) " : "", languageID);

	unsigned short expectedLang = 0;
	if(!client.GetExpectedLanguage(&expectedLang))
	{
		UNS_ERROR(L"Failed to get expected language\n");
		publishPartialFWUpgrade_failed(PARTIAL_FWU_MODULE::LANGUAGE, L"- Failed to get FW status", 8725);
		return res;
	}

	if (expectedLang != languageID)
	{
		if (!client.SetExpectedLanguage((unsigned short)languageID))
		{
			UNS_ERROR(L"failed to set expected language %d\n", languageID);
			publishPartialFWUpgrade_failed(PARTIAL_FWU_MODULE::LANGUAGE, L"- Failed to set FW status", 8725);
			return res;
		}
	}

	// If on INIT_MODE, perform PFU even if new language equals current one,
	// Use case: PFU from corrupted PFU Partition (0 in FW) to English (0)
	if (mode == LANGUAGE_FLOW_MODE::MANUAL && currentLang == languageID)
	{
		UNS_DEBUG(L"Current language is the requested one\n");
		if (defaultLangSet)
		{
			DSinstance().DeleteDataVal(LastLanguageUpdate);
		}
		else
		{
			DSinstance().SetDataValue(LastLanguageUpdate, languageID, true);
		}
		publishPartialFWUpgrade_end(PARTIAL_FWU_MODULE::LANGUAGE, 0);

		res = true;
		return res;
	}

	res = invokePartialFWUpdateFlow(PARTIAL_FWU_MODULE::LANGUAGE, LOCL_ID);

	if (res && (mode == LANGUAGE_FLOW_MODE::MANUAL))
	{
		if (defaultLangSet)
		{
			DSinstance().DeleteDataVal(LastLanguageUpdate);
		}
		else
		{
			DSinstance().SetDataValue(LastLanguageUpdate, languageID, true);
		}
	}

	return res;
}

bool PartialFWUpdateService::invokePartialFWUpdateFlow(PARTIAL_FWU_MODULE module, UINT32 partialID)
{
	bool res = false;
	FuncEntryExit<decltype(res)>(this, L"invokePartialFWUpdateFlow", res);

	UNS_DEBUG(L"Partition: 0x%X\n", partialID);
	publishPartialFWUpgrade_begin(module);
	std::wstring imagePath;
	if (!checkImageFileExist(imagePath))
	{
		publishMissingImageFile(module);
		return res;
	}

	UNS_DEBUG(L"Start PFU update\n");

	uint32_t retcode = pfwuWrapper->performPFWU(partialID, imagePath);
	publishPartialFWUpgrade_end(module, retcode);
	return retcode == 0;
}

bool PartialFWUpdateService::partialFWUpdate(int _langID, LANGUAGE_FLOW_MODE _mode, bool _toPublishFailure)
{
	bool res = false;
	langID = _langID;
	mode = _mode;
	FuncEntryExit<decltype(res)>(this, L"partialFWUpdate", res);


	if (!m_mainService->GetPortForwardingPort()) {
		UNS_DEBUG(L"%s: Error - Port Forwarding did not start yet, aborting partialFWUpdate operation. (Will perform it when gets event of EVENT_PORT_FORWARDING_SERVICE_AVAILABLE\n", name().c_str());
		m_PfuRequiredButNoPfw = true;
		return res;
	}

	PARTIAL_FWU_MODULE module = (mode == LANGUAGE_FLOW_MODE::INITIAL) ? PARTIAL_FWU_MODULE::WLAN : PARTIAL_FWU_MODULE::LANGUAGE;

	if (!isMESKU())
	{
		UNS_DEBUG(L"Not ME SKU\n");
		if(_toPublishFailure)
			publishPartialFWUpgrade_failed(module, L"- Not ME SKU", 1);
		return res;
	}

	if (!LoadFwUpdateLibDll())
	{
		UNS_ERROR(L"Failed to load FwUpdateLib_Dll\n");
		if(_toPublishFailure)
			publishPartialFWUpgrade_failed(module, L"- Failed to load FwUpdateLib_Dll", 2);
		return res;
	}


	/* COMMENT OUT AS W/A START */
	int ret = pfwuWrapper->waitForFwInitDone();
	if (ret != 0)
	{
		publishPartialFWUpgrade_end(module, ret);
		return res;
	}
	/* COMMENT OUT AS W/A END */

	UNS_DEBUG(L"After Init phase\n");

	if (mode == LANGUAGE_FLOW_MODE::MANUAL)
	{
		UNS_DEBUG(L"Manual Mode\n");
		res = updateLanguageChangeCode(langID, LANGUAGE_FLOW_MODE::MANUAL);
		return res;
	}

	//mode == INITIAL_MODE:

	// TODO: do nothing with failure?
	if (!SetExpectedWithLocalOSLanguage())
	{
		UNS_ERROR(L"updateLanguageChangeCode - cause LANG PFWU - failed to set expected language\n");
	}

	bool isLoclPfuNeeded = false, isWcodPfuNeeded = false;
	uint32_t requiredLanguage = DEFAULT_LANG_ID;
	ret = pfwuWrapper->isPfwuRequired(isLoclPfuNeeded, isWcodPfuNeeded, requiredLanguage);
	if (ret != 0)
	{
		publishPartialFWUpgrade_end(PARTIAL_FWU_MODULE::WLAN, ret);
		return res;
	}

	if (isWcodPfuNeeded)
	{
		UNS_DEBUG(L"WCOD PFU is required\n");
		res &= invokePartialFWUpdateFlow(PARTIAL_FWU_MODULE::WLAN, WOCD_ID);
	}
	if (isLoclPfuNeeded)
	{
		UNS_DEBUG(L"LOCL PFU is required\n");
		res &= updateLanguageChangeCode(requiredLanguage, LANGUAGE_FLOW_MODE::INITIAL);
	}
	return res;
}

bool PartialFWUpdateService::SetExpectedWithLocalOSLanguage() const
{
	bool res = false;
	FuncEntryExit<decltype(res)>(this, L"SetExpectedWithLocalOSLanguage", res);

	unsigned long languageId;
	bool retVal = DSinstance().GetDataValue(LastLanguageUpdate, languageId);
	UNS_DEBUG(L"Is Windows Default Language: %d\n", !retVal ? 1 : 0);

	if (!retVal)
	{
		unsigned short lang = (unsigned short)getUCLanguageID();
		SIOWSManClient wsman(m_mainService->GetPortForwardingPort());
		unsigned short expectedLang = 0;

		if (!wsman.GetExpectedLanguage(&expectedLang))
		{
			UNS_ERROR(L"GetExpectedLanguage failure - lang %u\n", (unsigned int)expectedLang);
			return res;
		}
		UNS_DEBUG(L"expectedLang: %d\n", (unsigned int)expectedLang);

		if (lang != expectedLang)
		{
			if (wsman.SetExpectedLanguage(lang))
			{
				UNS_DEBUG(L"SetExpectedLanguage success - set lang %u\n", (unsigned int)lang);
			}
			else
			{
				UNS_ERROR(L"SetExpectedLanguage failure - set lang %u\n", (unsigned int)lang);
				return res;
			}
		}
	}
	res = true;
	return res;
}

unsigned int PartialFWUpdateService::getUCLanguageID() const
{
	SIOWSManClient::LanguageId lang = SIOWSManClient::English;  //default language
	FuncEntryExit<decltype(lang)> fee(this, L"getUCLanguageID", lang);

	LCID lcid =  GetSystemDefaultLCID();
	int languageId = PRIMARYLANGID(lcid);
	int sublanguageId = SUBLANGID(lcid);


	switch(languageId)
	{
	case LANG_ENGLISH:
		lang = SIOWSManClient::English;
		break;
	case LANG_FRENCH :
		lang = SIOWSManClient::French;
		break;
	case LANG_GERMAN :
		lang = SIOWSManClient::German;
		break;
	case LANG_CHINESE :
		switch (sublanguageId)
		{
		case SUBLANG_CHINESE_SIMPLIFIED:
		case SUBLANG_CHINESE_SINGAPORE:
			lang = SIOWSManClient::Chinese_Simplified;
			break;
		case SUBLANG_CHINESE_TRADITIONAL:
		case SUBLANG_CHINESE_HONGKONG:
		case SUBLANG_CHINESE_MACAU:
			lang = SIOWSManClient::Chinese_Traditional;
			break;
		}
		break;
	case LANG_JAPANESE :
		lang = SIOWSManClient::Gapanese;
		break;
	case LANG_RUSSIAN :
		lang = SIOWSManClient::Russian;
		break;
	case LANG_ITALIAN :
		lang = SIOWSManClient::Italian;
		break;
	case LANG_SPANISH :
		lang = SIOWSManClient::Spanish;
		break;
	case LANG_PORTUGUESE:
		switch (sublanguageId)
		{
		case SUBLANG_PORTUGUESE_BRAZILIAN:
			lang = SIOWSManClient::Portuguese_Brazil;
			break;
		case SUBLANG_PORTUGUESE:
		default:
			lang = SIOWSManClient::Portuguese_Portugal;
			break;
		}
		break;
	case  LANG_KOREAN :
		lang = SIOWSManClient::Korean;
		break;
	case LANG_ARABIC:
		lang = SIOWSManClient::Arabic;
		break;
	case LANG_CZECH:
		lang = SIOWSManClient::Czech;
		break;
	case LANG_DANISH:
		lang = SIOWSManClient::Danish;
		break;
	case LANG_GREEK:
		lang = SIOWSManClient::Greek;
		break;
	case LANG_FINNISH:
		lang = SIOWSManClient::Finnish;
		break;
	case LANG_HEBREW:
		lang = SIOWSManClient::Hebrew;
		break;
	case LANG_HUNGARIAN:
		lang = SIOWSManClient::Hungarian;
		break;
	case LANG_DUTCH:
		lang = SIOWSManClient::Dutch;
		break;
	case LANG_NORWEGIAN:
		lang = SIOWSManClient::Norwegian;
		break;
	case LANG_POLISH:
		lang = SIOWSManClient::Polish;
		break;
	case LANG_SLOVAK:
		lang = SIOWSManClient::Slovak;
		break;
	case LANG_SLOVENIAN:
		lang = SIOWSManClient::Slovenian;
		break;
	case LANG_SWEDISH:
		lang = SIOWSManClient::Swedish;
		break;
	case LANG_THAI:
		lang = SIOWSManClient::Thai;
		break;
	case LANG_TURKISH:
		lang = SIOWSManClient::Turkish;
		break;
	default:
		break;
	}

	return lang;
}
