/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2010-2020 Intel Corporation
 */
#include "Configurator.h"
#include "LoadedServices.h"
#include "DependancyManager.h"

#include "Tools.h"
#include "UNSEventsDefinition.h"

#include "HECIException.h"
#include "CFG_SetOverrideProsetAdapterSwitchingCommand.h"
#include "GetFWVersionCommand.h"
#include "GMSExternalLogger.h"
#ifdef WIN32
#include <cguid.h>
#include <comdef.h>
#include <Wbemidl.h>
#include <Dbt.h>
#include <ShlObj.h>
#include <atlbase.h>
#include <propvarutil.h>
#include <functiondiscoverykeys.h>
#include <VersionHelpers.h>
#endif // WIN32

#include "DataStorageGenerator.h"


//Wsman
#include "SyncIpClient.h"
#include "TimeSynchronizationClient.h"
#include "WifiPortClient.h"
#include "WlanWSManClient.h"

#include <cstdint>
#include <chrono>
#include <thread>
#ifdef WIN32
//Change to #include <Powersetting.h> in VS 2015
#include <PowrProf.h>
#endif
#include <memory>

#define NUM_RETRIES 3
#define LME_EXISTS_LOOP_DELAY 200

/********************************** Help functions **********************************/
#ifdef WIN32

const wchar_t APP_ID[] = L"Intel.IMSS";
const wchar_t SHORTCUT_PATH[] = L"\\Programs\\Intel\\Intel(R) Management Engine Components\\Intel(R) Management and Security Status.lnk";
const std::wstring IMSS_EXE = L"IMSS\\PrivacyIconClient.exe";

HRESULT CreateIMSSShortcut()
{
	if (!IsWindows8OrGreater()) //abort this function
	{
		return S_OK;
	}

	HRESULT hr = E_FAIL;
	std::wstring exePath;
	wchar_t fullSortcutPath[MAX_PATH];

	//Get IMSS shortcut path
	if (!SHGetSpecialFolderPathW(NULL, fullSortcutPath, CSIDL_COMMON_STARTMENU, false))
		return hr;
	wcscat_s(fullSortcutPath, MAX_PATH, SHORTCUT_PATH);

	//Get IMSS executable path
	if (GetServiceDirectory(L"LMS", exePath) != true)
		return hr;
	size_t pos = exePath.find(L"LMS");
	size_t charNum = exePath.size() - pos;
	exePath.replace(pos, charNum, IMSS_EXE);

	//Check if IMSS executable exists

	if (!checkFileExist(exePath))
		return hr;

	//Create the shortcut with the desired properties

	CComPtr<IShellLink> shellLink;
	hr = CoCreateInstance(CLSID_ShellLink, nullptr, CLSCTX_INPROC_SERVER, IID_PPV_ARGS(&shellLink));
	if (!SUCCEEDED(hr))
		return hr;

	std::wstring wrkDir = exePath.substr(0, exePath.rfind(L'\\'));
	hr = shellLink->SetWorkingDirectory(wrkDir.c_str());
	if (!SUCCEEDED(hr))
		return hr;

	hr = shellLink->SetPath(exePath.c_str());
	if (!SUCCEEDED(hr))
		return hr;

	hr = shellLink->SetArguments(L"");
	if (!SUCCEEDED(hr))
		return hr;

	CComPtr<IPropertyStore> propertyStore;
	hr = shellLink.QueryInterface(&propertyStore);
	if (!SUCCEEDED(hr))
		return hr;

	PROPVARIANT appIdPropVar;
	hr = InitPropVariantFromString(APP_ID, &appIdPropVar);
	if (!SUCCEEDED(hr))
		return hr;

	hr = propertyStore->SetValue(PKEY_AppUserModel_ID, appIdPropVar);
	if (SUCCEEDED(hr))
	{
		hr = propertyStore->Commit();
		if (SUCCEEDED(hr))
		{
			CComPtr<IPersistFile> persistFile;
			hr = shellLink.QueryInterface(&persistFile);
			if (SUCCEEDED(hr))
			{
				hr = persistFile->Save(fullSortcutPath, TRUE);
			}
		}
	}
	PropVariantClear(&appIdPropVar);

	return hr;
}
#else
void CreateIMSSShortcut() {}
#endif // WIN32

//check if LME exists in FW
//to be used only BEFORE starting PortForwardingService
bool Configurator::IsLMEExists() const
{
	auto res = true;
	FuncEntryExit<decltype(res)> fee(this, L"IsLMEExists", res);
	std::unique_ptr<Intel::MEI_Client::HECI> heci(Intel::MEI_Client::GenerateLMEClient());

	for (int i = 1; i <= NUM_RETRIES; i++)
	{
		UNS_DEBUG(L"Trial # %d\n", i);

		try
		{
			heci->Init(); // heci init succeeded => LME exists
			UNS_DEBUG(L"heci Init succeeded\n");
			heci->Deinit();
			return res;
		}
		catch (Intel::MEI_Client::HeciNoClientException& e)
		{
			heci->Deinit();
			UNS_WARNING(L"Heci init failed, LME doesn't exist. %C\n", e.what());
			res = false;
			return res;
		}
		catch(Intel::MEI_Client::HECIException& e)
		{
			// heci init failed with another error than missing LME - retry a few times before defining as failure
			heci->Deinit();
			UNS_ERROR(L"Heci init failed. %C\n", e.what());
		}
		std::this_thread::sleep_for(std::chrono::milliseconds(LME_EXISTS_LOOP_DELAY));
	}

	// heci init failed with another error than missing LME
	UNS_ERROR(L"LME doesn't exist - too many Heci init retries.\n");
	res = false;
	return res;
}

void GetSkuAndBrand(Intel::MEI_Client::MKHI_Client::MKHI_PLATFORM_TYPE& platform,
	Intel::MEI_Client::MKHI_Client::MEFWCAPS_SKU_MKHI& stateData)
{
	Intel::MEI_Client::MKHI_Client::GetFWCapsCommand getFeaturesStateCommand(Intel::MEI_Client::MKHI_Client::FEATURES_ENABLED);
	Intel::MEI_Client::MKHI_Client::GetPlatformTypeCommand getPlatformTypeCommand;

	stateData = getFeaturesStateCommand.getResponse();
	platform = getPlatformTypeCommand.getResponse();
}

#ifdef WIN32
bool Configurator::MEIEnabled() const
{
	bool meiEnabled = false;
	IWbemLocator *loc = NULL;
	IWbemServices *svc = NULL;
	IWbemClassObject *obj = NULL;
	ULONG uReturn = 0;

	FuncEntryExit<decltype(meiEnabled)> fee(this, L"MEIEnabled", meiEnabled);

	HRESULT hres = CoCreateInstance(__uuidof(WbemLocator), 0, CLSCTX_INPROC_SERVER, __uuidof(IWbemLocator), (LPVOID *) &loc);
 
	if (!FAILED(hres))
	{
		// Connect to the root\cimv2 namespace with
		// the current user and obtain pointer pSvc
		// to make IWbemServices calls.
		hres = loc->ConnectServer(L"ROOT\\CIMV2", NULL, NULL, 0, NULL, 0, 0, &svc );
    
		if (!FAILED(hres))
		{
				IEnumWbemClassObject* enumerator = NULL;
				hres = svc->ExecQuery(L"WQL",L"SELECT Status FROM Win32_PnPEntity where Caption =\"Intel(R) Management Engine Interface \"",
										WBEM_FLAG_FORWARD_ONLY | WBEM_FLAG_RETURN_IMMEDIATELY, NULL, &enumerator);
    
				if (!FAILED(hres))
				{
					if (enumerator)//we have only one instance
					{
						HRESULT hr = enumerator->Next(WBEM_INFINITE, 1, &obj, &uReturn);

						if(uReturn != 0)
						{
							VARIANT vtProp;
							hr = obj->Get(L"Status", 0, &vtProp, 0, 0);
							if (wcscmp(vtProp.bstrVal,L"OK")==0)
							{
								meiEnabled = true;
							}
						}
					}
				}
				else
				{
					UNS_ERROR(L"isMEIEnabled() failed to connect to exec WMI query\n");
				}
		}
		else
		{
			UNS_ERROR(L"isMEIEnabled() failed to connect to WMI server\n");
		}
	}
	else 
	{
		UNS_ERROR(L"isMEIEnabled() failed in CoCreateInstance()\n");
	}
	if (svc!= NULL) svc->Release();
	if (loc!= NULL) loc->Release();
	if (obj!= NULL) obj->Release();
	return meiEnabled;
}
#else
bool Configurator::MEIEnabled() const
{
	struct stat buf;
	static const std::vector<std::string> devnode =
	{ "/dev/mei", "/dev/mei0", "/dev/mei1", "/dev/mei2", "/dev/mei3" };

	for (std::vector<std::string>::const_iterator it = devnode.begin();
		it != devnode.end(); ++it)
	{
		if (!lstat(it->c_str(), &buf))
			return true;
	}
	return false;
}
#endif //WIN32

static const int CONFIGURATOR_CHECK_RETRIES = 3; // Retry if wsman fails (usually with timeout)

//check if service SharedStaticIP should be loaded
bool CheckSharedStaticIPLoad()
{
	bool sharedStaticIP = false;
	UNS_DEBUG(L"Configurator:CheckSharedStaticIPLoad\n");

	bool ret = false;
	for (int i = 0; i < CONFIGURATOR_CHECK_RETRIES; i++)
	{
		SyncIpClient syncIpClient;
		ret = syncIpClient.GetSharedStaticIpState(&sharedStaticIP);
		if (ret)
			break;
		UNS_ERROR(L"Configurator:: getSharedStaticIpState failed to receive current state\n");
	}
	UNS_DEBUG(L"Configurator:CheckSharedStaticIPLoad %d\n", sharedStaticIP);
	return ret && sharedStaticIP;
}

//check if service Timesync should be loaded
bool CheckTimeSyncStateLoad()
{
	bool timeSyncState = false;
	UNS_DEBUG(L"Configurator::CheckTimeSyncStateLoad\n");

	bool ret = false;
	for (int i = 0; i < CONFIGURATOR_CHECK_RETRIES; i++)
	{
		TimeSynchronizationClient timeClient;
		ret = timeClient.GetLocalTimeSyncEnabledState(timeSyncState);
		if (ret)
			break;
		UNS_ERROR(L"Configurator:: GetLocalTimeSyncEnabledState failed to receive current state\n");
	}
	UNS_DEBUG(L"Configurator::CheckTimeSyncStateLoad %d", timeSyncState);
	return ret && timeSyncState;
}

namespace
{
#ifdef WIN32
	bool CheckIfServiceInstalled(const ACE_TString & ServiceName)
	{
		bool result = false;

		auto h_scm = OpenSCManager(nullptr, nullptr, SC_MANAGER_CONNECT);
		if (h_scm == nullptr)
		{
			return false;
		}

		auto h_service = OpenService(h_scm, ServiceName.c_str(), SERVICE_INTERROGATE);
		if (h_service != nullptr)
		{
			CloseServiceHandle(h_service);
			result = true;
		}
		CloseServiceHandle(h_scm);
		return result;
	}
#else
bool CheckIfServiceInstalled(const ACE_TString & ServiceName)
	{
		UNS_DEBUG(L"Configurator:: CheckIfServiceInstalled not implemented\n");
		return true;
	}
#endif
}

//check if service WiFiProfileSync should be loaded
#ifdef WIN32
bool CheckWiFiProfileSyncRequired()
{
	bool enabled;
	UNS_DEBUG(L"Configurator::CheckWiFiProfileSyncRequired\n");

	WifiPortClient WifiPort;
	size_t ports = 0;
	bool ret = WifiPort.PortsNum(ports);
	if (!ret)
		UNS_ERROR(L"Configurator:: WifiPort failed to receive current state\n");

	UNS_DEBUG(L"Configurator:: WifiPort found %d ports\n", ports);
	if (ports == 0) {
		enabled = false;
		return enabled;
	}

	WlanWSManClient WlanWSMan;
	enabled = true;
	ret = WlanWSMan.LocalProfileSynchronizationEnabled(enabled);
	if (!ret)
		UNS_ERROR(L"Configurator:: WlanWSMan failed to receive current state\n");
	if (!enabled) {
		UNS_DEBUG(L"Configurator:: LocalProfileSynchronization disabled in FW\n");
		return enabled;
	}

	enabled = !CheckIfServiceInstalled(ACE_TEXT("EvtEng"));
	if (!enabled)
		UNS_DEBUG(L"Configurator:: Have ProSet, LocalProfileSynchronization disabled\n");
	
	return enabled;
}
#else // WIN32
bool CheckWiFiProfileSyncRequired()
{
	bool enabled;
	UNS_DEBUG(L"Configurator::CheckWiFiProfileSyncRequired\n");

	UNS_DEBUG(L"Configurator:: WiFiProfileSync supported only on Windows\n");
	enabled = false;
	return enabled;
}
#endif // WIN32

#ifdef WIN32
namespace
{
	typedef decltype(PowerReadACValue) PowerReadXXValue;

	std::unique_ptr<uint8_t[]> ReadValue(PowerReadXXValue ReadFunc, DWORD * dataSize)
	{
		*dataSize = 0;

		DWORD dwRet = ReadFunc(
			nullptr,
			&GUID_TYPICAL_POWER_SAVINGS,
			&NO_SUBGROUP_GUID,
			&GUID_LOCK_CONSOLE_ON_WAKE,
			nullptr,
			nullptr,
			dataSize
		);
		std::unique_ptr<uint8_t[]> data;

		while (dwRet == ERROR_MORE_DATA ||
			(dwRet == ERROR_SUCCESS && data == nullptr)) // for some reason call to PowerReadXXValue above returns ERROR_SUCCESS instead ERROR_MORE_DATA
		{
			data.reset(new uint8_t[*dataSize]);

			dwRet = ReadFunc(
				nullptr,
				&GUID_TYPICAL_POWER_SAVINGS,
				&NO_SUBGROUP_GUID,
				&GUID_LOCK_CONSOLE_ON_WAKE,
				nullptr,
				data.get(),
				dataSize
			);
		}
		return dwRet == ERROR_SUCCESS ? std::move(data) : nullptr;
	}
}
	

bool Configurator::PasswordOnWakeupDisabled() const
{
	bool result = false;
	FuncEntryExit<decltype(result)> fee(this, L"PasswordOnWakeupDisabled", result);

	SYSTEM_POWER_STATUS sPS = { 0 };
	auto res = GetSystemPowerStatus(
		&sPS
		);
	if (res == 0)
		return result;

	if (sPS.ACLineStatus == 255)
		return result;

	DWORD dataSize = 0;

	auto acdcRes = ReadValue( (sPS.ACLineStatus == 1) ? PowerReadACValue : PowerReadDCValue, &dataSize);
		
	if (acdcRes == nullptr)
		return result;

	if (dataSize != sizeof(DWORD))
		return result;

	result = *reinterpret_cast<DWORD*>(acdcRes.get()) == 0;
	return result;
}
#else
bool Configurator::PasswordOnWakeupDisabled() const { return true;}
#endif

/****************************************************************************************/

int Configurator::init (int argc, ACE_TCHAR *argv[])
{
	FuncEntryExit<void> fee(this, L"init");

	initSubService(argc, argv);

	UNS_DEBUG(L"Configurator, 0x%x\n", this);

	//add to the map, services that demand special test before loading
	//the test will be performed in the start of the service (is StartAceService())
	m_checkLoadMap[GMS_SHAREDSTATICIPSERVICE] = CheckSharedStaticIPLoad;
	m_checkLoadMap[GMS_TIMESYNCSERVICE] = CheckTimeSyncStateLoad;
	m_checkLoadMap[GMS_WIFIPROFILESYNCSERVICE] = CheckWiFiProfileSyncRequired;

	deferredResumeTimerId_ = -1;

	LoadedServices *svc = theLoadedServices::instance();
	if (svc == NULL)
	{
		UNS_CRITICAL(L"Configurator couldn't initialize LoadedServices, FATAL ERROR!!\n");
		return -1;
	}

	AsyncActivationManager *mng = theAsyncActivationManager::instance();
	if (mng == NULL)
	{
		UNS_CRITICAL(L"Configurator couldn't initialize AsyncActivationManager, FATAL ERROR!!\n");
		return -1;
	}

	DependencyManager* depMan = theDependencyManager::instance();
	if(depMan == NULL)
	{
		UNS_CRITICAL(L"Configurator couldn't initialize DependancyManager, FATAL ERROR!!\n");
		return -1;
	}
	depMan->ReadDependencies();

	ServicesBatchCommand::SetServicesManager(this);

	UNS_DEBUG(L"Success\n");
	return 0;
}

int Configurator::fini (void)
{	
	FuncEntryExit<void> fee(this, L"fini");
	theDependencyManager::close();
	theLoadedServices::close();
	//There can be crash in Linux on shut-down if messages are left in the queue.
	//Clean-up messages in the queue to ensure that memory is released orderly.
	this->reactor()->purge_pending_notifications(this);
	UNS_DEBUG(L"Success\n");
	return 0;
}

void Configurator::HandleAceMessage(int type, MessageBlockPtr &mbPtr)
{
	FuncEntryExit<void> fee(this, L"Configurator::HandleAceMessage");
	
	switch (type) {
			case MB_ME_CONFIGURED:
			{
				UNS_DEBUG(L"ME_CONFIGURED\n");
				CreateIMSSShortcut();
				sendAlertIndicationMessage(CATEGORY_GENERAL, EVENT_PROVISIONING, ACE_TEXT("Intel(R) ME configured"));
			}
			break;
		case MB_SERVICE_STATUS_CHANGED:
			{
				UNS_DEBUG(L"SERVICE_STATUS_CHANGED\n");
				ServiceStatus* statusMChangeMsg = dynamic_cast<ServiceStatus*> (mbPtr->data_block());
				if (statusMChangeMsg == NULL)
				{
					UNS_ERROR(L"Invalid Status Change Message\n");
					return;
				}
				ACE_TString serviceName = statusMChangeMsg->serviceName;
				SERVICE_STATUS_TYPE status = statusMChangeMsg->status;
				statusMChangeMsg->release();//TODO::to remove it when we use GMS_COMMON dll
				mbPtr->replace_data_block(new ACE_Data_Block());
				UNS_DEBUG(L"serviceName: %s, status: %d\n", serviceName.c_str(), status);
				ChangeServiceState(serviceName, status);
			}break;
		case MB_TASK_COMPLETED:
			{
				//Add the dummy services dependency which was removed back 
				UNS_DEBUG(L"TASK_COMPLETED\n");
				if (m_onToggleService)
				{
					theDependencyManager::instance()->AddDummyDependencies(m_toggeledService);
					m_toggeledService.clear();
				}

				UNS_DEBUG(L"Message type %d process completed\n", m_inProcessType);
				m_onToggleService = m_inProcess = false;
				if(!m_nextTasks.empty())
				{
					MessageBlockPtr mb_ptr(m_nextTasks.front()->duplicate());
					m_nextTasks.pop();
					ExecuteTask(mb_ptr);
				}
			}break;
		default:
			ExecuteTask(mbPtr);
	}		
}

const ACE_TString Configurator::name()
{
	return GMS_CONFIGURATOR;
}

bool Configurator::StartAceService(const ACE_TString &serviceName)
{
	FuncEntryExit<void> fee(this, L"StartAceService");
	UNS_DEBUG(L"StartAceService: %s\n", serviceName.c_str());

	if (theLoadedServices::instance()->IsLoaded(serviceName))
	{
		UNS_ERROR(L"Trying to start already started service %s\n", serviceName.c_str());
		return false;
	}

	// we need to check using Wsman query if the service should be loaded
	bool needSpecialCheck = (m_checkLoadMap.find(serviceName) != m_checkLoadMap.end());

	if (needSpecialCheck)
	{
		UNS_DEBUG(L"%s: needSpecialCheck\n", serviceName.c_str());

		if (!m_mainService->GetPortForwardingStarted()) {
			UNS_DEBUG(L"%s: Port Forwarding did not start yet, delay StartAceService operation till Port Forwarding start.\n", serviceName.c_str());
			theLoadedServices::instance()->RemoveServiceToLoad(serviceName);
			theLoadedServices::instance()->UnlockService(serviceName);
			theLoadedServices::instance()->AddServiceToWaitForPfw(serviceName);
			return true;
		}

		CheckLoadFunc *checkLoadFunc = m_checkLoadMap[serviceName];
		if (checkLoadFunc && !checkLoadFunc()){ //if the service should not be loaded
			if(m_onToggleService == true)
				return false;
			else
			{
				UNS_DEBUG(L"the requested service %s should not start.\n", serviceName.c_str());
				theLoadedServices::instance()->RemoveServiceToLoad(serviceName);
				theLoadedServices::instance()->UnlockService(serviceName);
				return true;
			}
		}
	}

	return m_mainService->StartAceService(serviceName);
}

bool Configurator::StopAceService(const ACE_TString &serviceName)
{
	FuncEntryExit<void> fee(this, L"StopAceService");

	if (!theLoadedServices::instance()->IsLoaded(serviceName))
	{
		UNS_ERROR(L"Trying to stop not running service %s\n", serviceName.c_str());
		return false;
	}

	if (theLoadedServices::instance()->IsActive(serviceName))
	{
		UNS_DEBUG(L"Deactivating %s\n", serviceName.c_str());
			
		MessageBlockPtr mbPtr(new ACE_Message_Block(), deleteMessageBlockPtr);
		mbPtr->data_block(new StopServiceDataBlock(m_meiEnabled));
		mbPtr->msg_type(MB_STOP_SERVICE);
		mbPtr->msg_priority(5); //This message should be with the highest priority
		return m_mainService->sendMessage(serviceName,mbPtr);
	}

	//brutally killing - the service is loaded but not active
	FiniAceService(serviceName);
	
	return true;
}
	
bool Configurator::SuspendAceService(const ACE_TString &serviceName)
{
	FuncEntryExit<void> fee(this, L"SuspendAceService");
	if (theLoadedServices::instance()->IsActive(serviceName))
	{
		UNS_DEBUG(L"Deactivating %s\n", serviceName.c_str());
			
		MessageBlockPtr mbPtr(new ACE_Message_Block(), deleteMessageBlockPtr);
		mbPtr->data_block(new ACE_Data_Block());
		mbPtr->msg_type(MB_SUSPEND_SERVICE);
		mbPtr->msg_priority(5); //This message should be with the highest priority
		return m_mainService->sendMessage(serviceName,mbPtr);
	}

	return false;
}

bool Configurator::ResumeAceService(const ACE_TString &serviceName)
{
	return m_mainService->ResumeAceService(serviceName);
}

int Configurator::handle_timeout (const ACE_Time_Value &current_time,const void *arg)
{
	FuncEntryExit<void> fee(this, L"handle_timeout");
	UNS_DEBUG(L"%s service  arg=%lu\n",name().c_str(), arg);
	if (arg == &deferredResumeTimerId_)
	{
		deferredResumeTimerId_ = -1;
		MessageBlockPtr mbPtr(new ACE_Message_Block(), deleteMessageBlockPtr);
		mbPtr->msg_type(MB_DEFERRED_RESUME);
		mbPtr->msg_priority(4);//priority higher than other messages (except stop service).
		this->putq(mbPtr->duplicate());
		return -1;
	}
	if (m_scanningNum<NUM_RETRIES)
	{
		ScanConfiguration();
		m_scanningNum++;
	}
	else
	{
		ACE_Reactor::instance()->cancel_timer (this);
		StopAllServices();
		TaskCompleted();
	}
	return 0;
}

void Configurator::StopAllServices(bool stopMainService)
{
	FuncEntryExit<void> fee(this, L"StopAllServices" );

	m_needToStop = stopMainService;

	ServicesBatchStopCommand stopMisc;
	NamesList remainingServices;
	theLoadedServices::instance()->GetAllLoadedServices(remainingServices);
	if(!remainingServices.empty())
	{
		if(stopMisc.Execute(remainingServices) != ServicesBatchCommand::ExecuteCommandResult::SUCCESS)
			TaskCompleted();
	}
	else if(stopMainService)
		m_mainService->SetStop();

	m_mainService->SetStopped(stopMainService);

	UNS_DEBUG(L"StopAll done\n");

	if(remainingServices.empty())
		TaskCompleted();
}

bool Configurator::SuspendResumeAllServices(const ServicesBatchCommand &command)
{
	FuncEntryExit<void> fee(this, L"SuspendResumeAllServices");

	NamesList loadedServices;
	theLoadedServices::instance()->GetAllLoadedServices(loadedServices);
	if(command.Execute(loadedServices) != ServicesBatchCommand::ExecuteCommandResult::SUCCESS)
	{
		TaskCompleted();
		return false;
	}
	return true;
}

int Configurator::SuspendAllServices()
{
	FuncEntryExit<void> fee(this, L"SuspendAllServices");
	ServicesBatchSuspendCommand suspendAll;
	return SuspendResumeAllServices(suspendAll);
}

bool Configurator::ResumeAllServices()
{
	FuncEntryExit<void> fee(this, L"ResumeAllServices");
	ServicesBatchResumeCommand resumeAll;
	return SuspendResumeAllServices(resumeAll);
}


namespace
{
	Intel::MEI_Client::MKHI_Client::GET_FW_VER_RESPONSE GetFwVersion()
	{
		try
		{
			Intel::MEI_Client::MKHI_Client::GetFWVersionCommand getFWVersionCommand;
			Intel::MEI_Client::MKHI_Client::GET_FW_VER_RESPONSE res = getFWVersionCommand.getResponse();
			UNS_DEBUG(L"FW Version %d.%d.%d.%d\n", res.FTMajor, res.FTMinor, res.FTHotFix, res.FTBuildNo);
			return res;
		}
		catch (std::exception& e)
		{
			UNS_ERROR(L"Could not get FW version. %C\n", e.what());
			Intel::MEI_Client::MKHI_Client::GET_FW_VER_RESPONSE emptyFwVer = { 0 };
			return emptyFwVer;
		}
	}
}

#ifdef WIN32
	void Configurator::DoOverrideProsetAdapterSwitching() const
	{
		FuncEntryExit<void> fee(this, L"DoOverrideProsetAdapterSwitching");

		if (IsWindows8OrGreater())
			return;

		unsigned long prosetOverride = 0;
		if(!DSinstance().GetDataValue(OverrideProsetAdapterSwitching, prosetOverride))
			return;

		UNS_DEBUG(L"OverrideProsetAdapterSwitching value=%d\n", prosetOverride);
		
		try
		{
			using namespace Intel::MEI_Client::AMTHI_Client;			
			CFG_SetOverrideProsetAdapterSwitchingCommand cmd(prosetOverride);
			AMT_HOSTIF_CFG_SET_OVERRIDE_PROSET_ADAPTER_SWITCHING_RESPONSE res = cmd.getResponse();
			UNS_DEBUG(L"Set Proset status %d\n", res.Status);
		}
		catch (std::exception& e)
		{
			UNS_ERROR(L"Could not set Proset override. %C\n", e.what());
		}
	}
#else
	void Configurator::DoOverrideProsetAdapterSwitching() const {}
#endif // WIN32

void Configurator::ScanConfiguration()
{
	FuncEntryExit<void> fee(this, L"ScanConfiguration");
	ACE_Time_Value interval(5);
	ACE_Reactor::instance()->schedule_timer (this, 0,interval,interval);
	
	try
	{	
		m_fwVer = GetFwVersion();

		if (!m_SkuAndBrandScanned)
		{
			GetSkuAndBrand(m_platform, m_stateData);
			m_LME_exists = IsLMEExists();
			UNS_DEBUG(L"platform=0x%X FWCaps=0x%X LME_exists=%d\n" , m_platform, m_stateData, m_LME_exists);
		}
		m_SkuAndBrandScanned = true;

		DoOverrideProsetAdapterSwitching();
		
		ServicesBatchStartCommand batch;
		ServiceNamesList services;

		services.Read(DUMMY_SERVICES);

		if(m_platform.Fields.ImageType != Intel::MEI_Client::MKHI_Client::ME_FULL_8MB)
		{
			services.Read(SKU_1_5_GROUP);
		}
		else
		{
			if (!m_LME_exists)
			{
				services.Read(SKU_5_NO_LME_GROUP);
			}
			else
			{
				services.Read(SKU_5_GROUP);
			}

			switch (m_platform.Fields.Brand) 
			{
				case Intel::MEI_Client::MKHI_Client::BrandAMT:
				case Intel::MEI_Client::MKHI_Client::BrandStdMng:
				case Intel::MEI_Client::MKHI_Client::BrandL3:
					{
						if (!m_stateData.Fields.Amt)// Manageability disabled in MEBx
							break;
						
						services.Read(MANAGABILITY_GROUP);
						
					}
					break;
				case Intel::MEI_Client::MKHI_Client::BrandSBT:
				case Intel::MEI_Client::MKHI_Client::NoBrand:
				default:
					break;
			}
		}

		NamesList servicesNames;
		services.GetNames(servicesNames);
		theDependencyManager::instance()->FillAbsoluteDependencies(servicesNames);
		theLoadedServices::instance()->SetServicesToLoad(servicesNames);

		if(batch.Execute(servicesNames) != ServicesBatchCommand::ExecuteCommandResult::SUCCESS)
			TaskCompleted();

		ACE_Reactor::instance()->cancel_timer (this);
	}
	catch (std::exception& e)
	{
		UNS_ERROR(L"Exception in EnvironmentScanning. %C\n", e.what());

		if(!MEIEnabled())
		{
			m_scanningNum=0;
			GMSExternalLogger::instance().WarningLog(ACE_TEXT("LMS cannot connect to Intel(R) MEI driver"));
			UNS_DEBUG(L"MEI state: disabled\n");
			ACE_Reactor::instance()->cancel_timer (this);//wait for MEI enable
			m_meiEnabled = false;
			TaskCompleted();
		}
		else
		{
			UNS_DEBUG(L"MEI state: enabled\n");
		}
	}
}

void Configurator::OnToggleService(const ACE_TString &service, bool val)
{
	FuncEntryExit<void> fee(this, L"OnToggleService");
	bool isLoaded = theLoadedServices::instance()->IsLoaded(service);
	if (val == isLoaded)
	{
		TaskCompleted();
		return;
	}
	
	m_onToggleService = true;
	ServiceNamesList services;
	services.AddName(service);	
	if(val) //start the service
	{
		theLoadedServices::instance()->AddServiceToLoad(service);
		ServicesBatchStartCommand	batchStartCommand;
		if(batchStartCommand.Execute(services) != ServicesBatchCommand::ExecuteCommandResult::SUCCESS)
		{
			TaskCompleted();
		}
	}
	else //stop the service
	{
		//Save the service name (to enable re-adding of dummy services dependency)
		m_toggeledService = service;
		//Remove the dependency of dummy subservices (to prevent removing of "last" services, bug #214992)
		theDependencyManager::instance()->RemoveDummyDependencies(service);

		theLoadedServices::instance()->RemoveServiceToLoad(service);
		ServicesBatchStopCommand	batchStopCommand;
		if(batchStopCommand.Execute(services) != ServicesBatchCommand::ExecuteCommandResult::SUCCESS)
			TaskCompleted();
	}
}
	        
void Configurator::ChangeServiceState(ACE_TString &serviceName, int status)
{
	ServiceNamesList services;
	FuncEntryExit<decltype(status)> fee(this, L"ChangeServiceState", status);

	switch (status) 
	{
		// The unloading of service and all the ones that depends on it was finished.
		case STATUS_UNLOADCOMPLETE:
			FiniAceService(serviceName);
			//Refreshing the waiting list of services that might have been waiting to the service
			if(theAsyncActivationManager::instance()->RefreshOnUnload(services))
			{
				//stopping all the services that were in waiting list.
				ServicesBatchStopCommand command;
				if(command.Execute(services) != ServicesBatchCommand::ExecuteCommandResult::SUCCESS)
					TaskCompleted();
			}
			else if(serviceName.compare(FIRST_SERVICE) == 0)
			{
				TaskCompleted();
			}
			break;
		// Loading the service and the ones it depends on was completed.
		case STATUS_LOADCOMPLETE:
			theLoadedServices::instance()->AddService(serviceName);
			//Raising MEI Enabled event.
			if(m_gotMeiEnabled && (serviceName.compare(STATUS_EVENT_HANDLER) == 0))
			{
				m_gotMeiEnabled = false;
				sendAlertIndicationMessage(CATEGORY_UNS, EVENT_SERVICE_HECI_ENABLE, ACE_TEXT("MEI driver enabled"));
			}

			//Refreshing the waiting list of services that might have been waiting for the service to load
			if (theAsyncActivationManager::instance()->RefreshOnLoad(services))
			{
				//starting all the services that were in waiting list.
				ServicesBatchStartCommand command;
				if(command.Execute(services) != ServicesBatchCommand::ExecuteCommandResult::SUCCESS)
					TaskCompleted();
			}
			else if(serviceName.compare(LAST_SERVICE) == 0 || serviceName.compare(AMT_ENABLE_LAST_SERVICE) == 0 || serviceName.compare(WAITING_FOR_PFW_LAST_SERVICE) == 0)
			{
				TaskCompleted();
			}
			break;
		// Suspending the service and the ones that depended on it was finished
		case STATUS_SUSPENDCOMPLETE:
			theLoadedServices::instance()->SetActive(serviceName, false);
			CompleteSuspendAceService(serviceName);
			//Refreshing the waiting list of services that might have been waiting for the service to suspend
			if (theAsyncActivationManager::instance()->RefreshOnSuspend(services))
			{
				// Suspending all the services that were in waiting list.
				ServicesBatchSuspendCommand command;
				if(command.Execute(services) != ServicesBatchCommand::ExecuteCommandResult::SUCCESS)
					TaskCompleted();
			}
			else if(serviceName.compare(FIRST_SERVICE) == 0)
			{
				TaskCompleted();
			}
			break;
		// Resuming the service and the ones that depended on it was finished
		case STATUS_RESUMECOMPLETE:
			theLoadedServices::instance()->SetActive(serviceName);
			//Refreshing the waiting list of services that might have been waiting for the service to resume
			if (theAsyncActivationManager::instance()->RefreshOnResume(services))
			{
				// Resuming all the services that were in waiting list.
				ServicesBatchResumeCommand command;
				if(command.Execute(services) != ServicesBatchCommand::ExecuteCommandResult::SUCCESS)
					TaskCompleted();
			}
			else if(serviceName.compare(LAST_SERVICE) == 0)
			{
				sendAlertIndicationMessage(CATEGORY_UNS, EVENT_SERVICE_RESUME, ACE_TEXT("Local Management Service resumed."));
				TaskCompleted();
			}
			break;
		default:
			UNS_ERROR(L"Invalid Service State\n");
	}

	if(m_onToggleService)
	{
		TaskCompleted();
	}
}

int Configurator::UpdateConfiguration(const ChangeConfiguration *conf)
{
	FuncEntryExit<decltype(conf->type)> fee(this, L"UpdateConfiguration", conf->type);
	switch(conf->type)
	{
		case IP_SYNC_CONF:
			UNS_DEBUG(L"Got Static IP Status: %d\n", conf->value);
			OnToggleService(GMS_SHAREDSTATICIPSERVICE, (bool) conf->value);
			break;
		case WIFI_PROFILE_SYNC_CONF:
			UNS_DEBUG(L"Got WiFi Profile Sync Status: %d\n",  conf->value);
			OnToggleService(GMS_WIFIPROFILESYNCSERVICE, conf->value != 0);
			break;
		case TIME_SYNC_CONF: //Handles the changes in the LocalTimeSyncEnable field in the FW
			UNS_DEBUG(L"Got Time Sync Status: %d\n",  conf->value);
			//Starts or stops the service according to the configuration change
			OnToggleService(GMS_TIMESYNCSERVICE, (bool) conf->value);
			break;
		case AMT_ENABLE_CONF:
			{
				UNS_DEBUG(L"Got AMT Status: %d\n", conf->value);
				
				if(conf->value != 0)
				{
					ServiceNamesList services;
					services.Read(MANAGABILITY_GROUP);
					services.AddName(AMT_ENABLE_LAST_SERVICE);
					
					NamesList svc;
					services.GetNames(svc);
					NamesList::const_iterator endIt = svc.end();
					for(NamesList::const_iterator it = svc.begin(); it != endIt; ++it)
						theLoadedServices::instance()->AddServiceToLoad(*it);

					ServicesBatchStartCommand batch;
					if(batch.Execute(services) != ServicesBatchCommand::ExecuteCommandResult::SUCCESS)
						TaskCompleted();
				}
				else
				{
					TaskCompleted();
				}
				break;
			}

		case PFW_ENABLE_CONF:
		{
			UNS_DEBUG(L"Got Port Forwarding Status: %d\n", conf->value);

			if (conf->value != 0)
			{		
				NamesList servicesNames;
				theLoadedServices::instance()->GetAllWaitingForPfwServices(servicesNames);
				if (servicesNames.empty())
				{
					TaskCompleted();
					break;
				}

				servicesNames.push_back(WAITING_FOR_PFW_LAST_SERVICE); //When it will "start" - TaskCompleted() will be called

				NamesList::const_iterator endIt = servicesNames.end();
				for (NamesList::const_iterator it = servicesNames.begin(); it != endIt; ++it)
				{
					theLoadedServices::instance()->AddServiceToLoad(*it);
				}
				
				ServicesBatchStartCommand batch;
				if (batch.Execute(servicesNames) != ServicesBatchCommand::ExecuteCommandResult::SUCCESS)
				{
					UNS_ERROR(L"Starting the services that waited for Port forwarding to start - Failed.\n");
					TaskCompleted();
				}

				theLoadedServices::instance()->ClearServicesToWaitForPfw();
			}
			else
			{
				TaskCompleted();
			}
			break;
		}
		default:
			UNS_ERROR(L"Configurator::Invalid Message\n");
			return -1;
	}
	return 0;
}

void Configurator::FiniAceService(const ACE_TString &serviceName)
{
	FuncEntryExit<void> fee(this, L"FiniAceService");
	UNS_DEBUG(L"%s\n", serviceName.c_str());
	if (!theLoadedServices::instance()->IsLoaded(serviceName))
	{
		UNS_ERROR(L"trying to stop not running service\n");
		return;
	}
	
	m_mainService->StopAceService(serviceName);
	theLoadedServices::instance()->RemoveService(serviceName);

	NamesList services;
	theLoadedServices::instance()->GetAllLoadedServices(services);

	if(services.empty())
	{
		UNS_DEBUG(L"LAST ONE\n");
		theLoadedServices::instance()->ClearServicesToLoad();

		if (m_needToStop)
		{
			m_mainService->SetStop();
		}
	}
}

bool Configurator::CompleteSuspendAceService(const ACE_TString &serviceName)
{
	FuncEntryExit<void> fee(this, L"CompleteSuspendAceService");
	bool ret = m_mainService->SuspendAceService(serviceName);
	UNS_DEBUG(L"COMPLETING SUSPEND for %s\n", serviceName.c_str());
	NamesList services;
	theLoadedServices::instance()->GetAllActiveServices(services);
	if (services.empty())
	{
		UNS_DEBUG(L"LAST ONE TO SUSPEND\n");
		m_mainService->SetSuspend();
	}

	return ret;
}

void Configurator::DeviceEventRequested(uint32_t dwEventType, bool wasOnOurGUID)
{
	FuncEntryExit<void> fee(this, L"DeviceEventRequested");
	MessageBlockPtr mbPtr(new ACE_Message_Block(), deleteMessageBlockPtr);
	MessageBlockPtr mbEventPtr(new ACE_Message_Block(), deleteMessageBlockPtr);

	UNS_DEBUG(L"Event %d\n", dwEventType);
	
	switch(dwEventType)
	{
#ifdef WIN32
		case DBT_DEVICEQUERYREMOVE:	
			TaskCompleted();
			break;
		case DBT_DEVICEREMOVEPENDING:
			TaskCompleted();
			break;
		case DBT_DEVICEQUERYREMOVEFAILED:
			mbEventPtr->data_block(new ACE_Data_Block());
			mbEventPtr->msg_type(MB_MEI_DISABLE_FAILED);
			m_mainService->sendMessage(GMS_PORTFORWARDINGSERVICE,mbEventPtr);
			TaskCompleted();
			break;
		case DBT_DEVICEARRIVAL:
			if (wasOnOurGUID)
			{
				UNS_DEBUG(L"LMS connected to Intel(R) MEI driver\n");
				GMSExternalLogger::instance().DebugLog(ACE_TEXT("LMS connected to Intel(R) MEI driver"));
				m_gotMeiEnabled = true;
				m_meiEnabled = true;
				ScanConfiguration();
			}
			break;
		case DBT_DEVICEREMOVECOMPLETE:
			if (wasOnOurGUID)
			{
				UNS_DEBUG(L"LMS lost connection to Intel(R) MEI driver\n");
				GMSExternalLogger::instance().WarningLog(ACE_TEXT("LMS lost connection to Intel(R) MEI driver"));
				m_meiEnabled = false;

				mbEventPtr->data_block(new GMS_AlertIndication(CATEGORY_UNS,EVENT_SERVICE_HECI_DISABLE,getDateTime(),ACTIVE_MESSAGEID, ACE_TEXT("MEI driver disabled")));
				mbEventPtr->msg_type(MB_PUBLISH_EVENT);
				mbEventPtr->msg_priority(6);//priority higher than stop service
				m_mainService->sendMessage(EVENT_MANAGER,mbEventPtr);

				StopAllServices(false);
			}
			break;  
#endif // WIN32
		default:
			TaskCompleted();
	}
}


void Configurator::CancelDeferredResumeTimer()
{
	if (deferredResumeTimerId_ == -1)
		return;

	ACE_Reactor::instance()->cancel_timer(deferredResumeTimerId_);
	deferredResumeTimerId_ = -1;
	return;	
}

void Configurator::ExecuteTask(MessageBlockPtr& mbPtr)
{
	FuncEntryExit<void> fee(this, L"ExecuteTask");

	int type=mbPtr->msg_type();
	if (m_serviceIsClosed || m_needToStop)
	{
		UNS_DEBUG(L"We already closed, come back tomorrow. %d\n", type);
		if (!m_inProcess) //otherwise, the TaskCompleted refers to the task that is in process, instead of this new coming task.
		{
			TaskCompleted();
		}
		return;
	}

	if(!m_inProcess)
	{
		UNS_DEBUG(L"Message type %d process started\n", type);


		m_inProcess = true;
		m_inProcessType = type;
		switch(type)
		{
			case MB_DEVICE_EVENT:
				{
					DeviceEventDataBlock *devEvent = dynamic_cast<DeviceEventDataBlock*>(mbPtr->data_block());
					if (devEvent != nullptr)
					{
						DeviceEventRequested(devEvent->eventType, devEvent->wasOnOurGuid);
					}
					else
					{
						UNS_ERROR(L"Invalid data block.\n");
					}
				}break;
				case MB_CONFIGURATION_CHANGE:
				{
					UNS_DEBUG(L"got ongoing event\n");
					ChangeConfiguration *event = dynamic_cast<ChangeConfiguration*>(mbPtr->data_block());
					if (event != nullptr)
					{
						UpdateConfiguration(event);
					}
					else
					{
						UNS_ERROR(L"Invalid data block.\n");
					}
				}break;
			case MB_CONFIGURATION_START:
				{
					UNS_DEBUG(L"got start event\n");
					ScanConfiguration(); 
				}break;
			case MB_CONFIGURATION_STOP:
				{
					UNS_DEBUG(L"got stop event\n");
					CancelDeferredResumeTimer();
					StopAllServices();
				}break;
			case MB_WTS_SESSION_UNLOCK:
				UNS_DEBUG(L"got unlock event\n");

				if (m_fwVer.FTMajor == 0) { //not initialized  yet
					m_fwVer = GetFwVersion();
				}

				if (m_fwVer.FTMajor < 12) //else - do nothing. the ResumeAllServices() was called by MB_CONFIGURATION_RESUME
				{
					if (deferredResumeTimerId_ != -1 && ACE_Reactor::instance()->cancel_timer(deferredResumeTimerId_)) // login before deferredResumeTimerId_ is timed-out
					{
						deferredResumeTimerId_ = -1;
						ResumeAllServices();
					}
				}

				TaskCompleted();
				break;
			case MB_DEFERRED_RESUME: // deferredResumeTimerId_ is timed-out (before login)
				UNS_DEBUG(L"deferred resume event\n");
				ResumeAllServices();
				TaskCompleted();
				break;
			case MB_CONFIGURATION_RESUME:
				{
					UNS_DEBUG(L"got resume event\n");

					if (m_fwVer.FTMajor == 0) { //not initialized  yet
						m_fwVer = GetFwVersion();
					}
					CancelDeferredResumeTimer();

					//On ME12 and later, there is no need in the WA of deferred resume.
					if (m_fwVer.FTMajor >= 12 || PasswordOnWakeupDisabled())
					{
						//doesn't set up time so MB_WTS_SESSION_UNLOCK will NOT call ResumeAllServices latter 
						ResumeAllServices();
					}
					else
					{
						// LMS resume flow will not happen immediately
						// It will happen after some timeout

						// Reason: Calling ResumeAllServices causes to all of LMS component refresh their state
						// resulting in LOT of communication between LMS and FW 
						// However there are other process (such MFA) which also want to run flows on Resume against FW and
						// These processes are very sensitive to any delay in the communications.
						// So deferring LMS resume for some period of time event solves that problem

						deferredResumeTimerId_ = ACE_Reactor::instance()->schedule_timer (this, &deferredResumeTimerId_, ACE_Time_Value(90), ACE_Time_Value::zero); // will trigger MB_DEFERRED_RESUME event (when timeout)
					}

					TaskCompleted();
				}break;
			case MB_CONFIGURATION_SUSPEND:
				{
					UNS_DEBUG(L"got suspend event\n");
					CancelDeferredResumeTimer();
					SuspendAllServices();
					TaskCompleted();
				}break;
			case MB_PORT_FORWARDING_STARTED:
				{
					UNS_DEBUG(L"got PORT_FORWARDING_STARTED event\n");

					m_mainService->SetPortForwardingStarted(true);

					sendAlertIndicationMessage(CATEGORY_UNS, EVENT_PORT_FORWARDING_SERVICE_AVAILABLE, ACE_TEXT("Port Forwarding Service started"));
					
					MessageBlockPtr pfwPtr(new ACE_Message_Block(), deleteMessageBlockPtr);
					pfwPtr->data_block(new ChangeConfiguration(PFW_ENABLE_CONF, 1));
					pfwPtr->msg_type(MB_CONFIGURATION_CHANGE);
					this->putq(pfwPtr->duplicate());
					
					TaskCompleted();
				}break;
			case MB_PORT_FORWARDING_STOPPED: 
				{
					UNS_DEBUG(L"got PORT_FORWARDING_STOPPED event\n");

					PortForwardingStoppedBlock* pfwStoppedMsg = dynamic_cast<PortForwardingStoppedBlock*> (mbPtr->data_block());
					if (pfwStoppedMsg == NULL)
					{
						UNS_ERROR(L"Invalid Port Forwarding Stopped Message\n");
						TaskCompleted();
						return;
					}
					bool publishFailure = pfwStoppedMsg->m_publishFailure;
					UNS_DEBUG(L"Publish Failure: %d\n", publishFailure);

					m_mainService->SetPortForwardingStarted(false);

					if (publishFailure) {
						sendAlertIndicationMessage(CATEGORY_UNS, EVENT_PORT_FORWARDING_SERVICE_UNAVAILABLE, ACE_TEXT("Port Forwarding Service failed"));
					}

					TaskCompleted();
				}break;
			default:
				TaskCompleted();
		}
	}
	else
	{
		MessageBlockPtr taskMbPtr(new ACE_Message_Block(), deleteMessageBlockPtr);
		switch(type) //For messages with special DataBlock
		{
			case MB_DEVICE_EVENT:
				taskMbPtr->data_block(new DeviceEventDataBlock(*((DeviceEventDataBlock*)mbPtr->data_block())));
				break;
			case MB_CONFIGURATION_CHANGE:
				taskMbPtr->data_block(new ChangeConfiguration(*((ChangeConfiguration*)mbPtr->data_block())));
				break;
			case MB_PORT_FORWARDING_STOPPED:
				taskMbPtr->data_block(new PortForwardingStoppedBlock(*((PortForwardingStoppedBlock*)mbPtr->data_block())));
				break;
			default:
				taskMbPtr->data_block(new ACE_Data_Block());
		}
		taskMbPtr->msg_type(type);
		m_nextTasks.push(taskMbPtr);
		UNS_DEBUG(L"Message type %d in process, defer %d\n", m_inProcessType, type);
	}
}

void Configurator::TaskCompleted()
{
	FuncEntryExit<void> fee(this, L"TaskCompleted");

	UNS_DEBUG(L"Message type %d scheduled to complete\n", m_inProcessType);

	MessageBlockPtr mbPtr(new ACE_Message_Block(), deleteMessageBlockPtr);
	mbPtr->data_block(new ACE_Data_Block());
	mbPtr->msg_type(MB_TASK_COMPLETED);
	this->putq(mbPtr->duplicate());
}

LMS_SUBSERVICE_DEFINE(CONFIGURATOR, Configurator)
