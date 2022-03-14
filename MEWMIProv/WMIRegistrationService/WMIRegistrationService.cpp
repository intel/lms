//SPDX-License-Identifier: Apache-2.0
//
//Copyright (C) 2021-2022 Intel Corporation
#include "shlwapi.h"
#include <sstream>
#include "WMIRegistrationService.h"
#include "EventLog.h"
#include "EventLogMessages.h" // auto generated from mc file
#include "pathcch.h"
#include "Shlobj.h"

namespace WMIRegistrationService
{
    //
    // Settings of the service
    //
    #define SERVICE_NAME             L"Intel(R) WMI Registration Service"
    const unsigned int SERVICE_FLAGS_STARTED = 0x0;
    const unsigned int SERVICE_FLAGS_DONE = 0x1;
    const unsigned int WAIT_FOR_COMPILITION_IN_MILLI = 1000000;
    const unsigned int STATUS_SUCCESS = 0;
    const unsigned int STATUS_UNSUCCESSFUL = -1;
    const unsigned int SERVICE_WAIT_HINT_TIME = 30000; // 30 seconds
    const unsigned int DEBUG_MSG_LEN = 260;

    //
    // Service context
    //
    SERVICE_STATUS_HANDLE StatusHandle     = NULL;
    volatile LONG         ControlFlags     = 0;
    HANDLE                StopRequestEvent = NULL;
    HANDLE                StopWaitObject   = NULL;

    void DbgPrint(_In_ const wchar_t* args, ...)
    {
        std::wstring dbgPrefix = SERVICE_NAME;
        dbgPrefix += L": ";
        wchar_t msg[DEBUG_MSG_LEN + 1];
        //no point in checking return code, nothing to do if fails.
        wcscpy_s(msg, DEBUG_MSG_LEN, dbgPrefix.c_str());
        va_list varl;
        va_start(varl, args);
        vswprintf_s(&msg[dbgPrefix.size()], DEBUG_MSG_LEN - dbgPrefix.size(), args, varl);
        va_end(varl);

        OutputDebugString(msg);
    }

    _Check_return_
        std::wstring GetServicePath()
    {
        WCHAR szSource[MAX_PATH];
        std::wstring source;

        DWORD pathErr = GetModuleFileName(0, szSource, MAX_PATH);
        if (pathErr == 0)
        {
            DbgPrint(L"GetModuleFileName Failed with %ul ", GetLastError());
        }

        HRESULT hr = PathCchRemoveFileSpec(szSource, MAX_PATH);
        if (hr != S_OK)
        {
            DbgPrint(L"PathCchRemoveExtension Failed with %ul ", hr);
            return std::wstring();
        }
        source = std::wstring(szSource);
        DbgPrint(L"Service exe path is %s", source.c_str());
        return source;
    }

    std::wstring GetServiceState(_In_ DWORD currnetState)
    {
        std::wstring state;
        switch (currnetState)
        {
        case SERVICE_STOPPED:
            state = L"SERVICE_STOPPED";
            break;
        case SERVICE_START_PENDING:
            state = L"SERVICE_START_PENDING";
            break;
        case SERVICE_STOP_PENDING:
            state = L"SERVICE_STOP_PENDING";
            break;
        case SERVICE_RUNNING:
            state = L"SERVICE_RUNNING";
            break;
        case SERVICE_CONTINUE_PENDING:
            state = L"SERVICE_CONTINUE_PENDING";
            break;
        case SERVICE_PAUSE_PENDING:
            state = L"SERVICE_PAUSE_PENDING";
            break;
        case SERVICE_PAUSED:
            state = L"SERVICE_PAUSED";
            break;
        default:
            state = L"UNKNOWN STATE";
            break;
        }
        return state;
    }

    BOOL UpdateServiceStatus(
        _In_ SERVICE_STATUS_HANDLE hHandle,
        _In_  DWORD  dwCurrentState,
        _In_  DWORD  dwWin32ExitCode
    )
    {
        SERVICE_STATUS Status;

        DbgPrint(L"Update service state to %s", GetServiceState(dwCurrentState));

        static DWORD dwCheckPoint = 1;

        Status.dwServiceType = SERVICE_WIN32_OWN_PROCESS;
        Status.dwCurrentState = dwCurrentState;
        Status.dwWin32ExitCode = dwWin32ExitCode;
        Status.dwServiceSpecificExitCode = ERROR_SUCCESS;

        if (dwCurrentState == SERVICE_START_PENDING)
        {
            Status.dwControlsAccepted = 0;
        }
        else
        {
            Status.dwControlsAccepted = SERVICE_ACCEPT_STOP;
        }

        if ((dwCurrentState == SERVICE_RUNNING) ||
            (dwCurrentState == SERVICE_STOPPED))
        {
            Status.dwCheckPoint = 0;
            Status.dwWaitHint = 0;
        }
        else
        {
            Status.dwCheckPoint = dwCheckPoint++;
            Status.dwWaitHint = SERVICE_WAIT_HINT_TIME;
        }

        return SetServiceStatus(hHandle, &Status);
    }

    _Check_return_
        DWORD ExecuteMofcomp(_In_ std::wstring param)
    {
        DWORD status = STATUS_SUCCESS;
        SHELLEXECUTEINFO info = { 0 };
        std::wstring path, mofcompPath, mofcompParams;
        DWORD exitCode, waitErr = 0;
        HRESULT err = S_OK;
        BOOL res = TRUE;
        PWCHAR systemFolder;
        DbgPrint(L"ExecuteMofcomp Entry");

        err = SHGetKnownFolderPath(FOLDERID_System, 0, NULL, &systemFolder);
        if (err != S_OK)
        {
            DbgPrint(L"SHGetKnownFolderPath failed with status %lu ", GetLastError());
            status = STATUS_UNSUCCESSFUL;
            goto end;
        }
        path = std::wstring(systemFolder);
        //free allocated pointer
        CoTaskMemFree(systemFolder);

        path += L"\\wbem\\mofcomp.exe";

        if (!PathFileExists(path.c_str()))
        {
            DbgPrint(L"PathFileExists failed");
            status = STATUS_UNSUCCESSFUL;
            goto end;
        }

        mofcompPath = L"\"" + path + L"\"";
        mofcompParams = L"\"" + param + L"\"";

        DbgPrint(L"mofcomp path is: %s ", mofcompPath);
        DbgPrint(L"param is: %s ", mofcompParams);

        info.cbSize = sizeof(SHELLEXECUTEINFOW);
        info.fMask = SEE_MASK_DEFAULT | SEE_MASK_NOCLOSEPROCESS;
        info.hwnd = NULL;
        info.lpVerb = L"open";
        info.lpFile = mofcompPath.c_str();
        info.lpParameters = mofcompParams.c_str();
        info.lpDirectory = NULL;
        info.nShow = SW_SHOW;

        res = ShellExecuteEx(&info);
        if (!res)
        {
            DbgPrint(L"ShellExecuteEx failed with status %d", GetLastError());
            status = STATUS_UNSUCCESSFUL;
            goto end;
        }

        if (!info.hProcess)
        {
            DbgPrint(L"Procces handle is Null");
            status = STATUS_UNSUCCESSFUL;
            goto end;
        }

        waitErr = WaitForSingleObject(info.hProcess, WAIT_FOR_COMPILITION_IN_MILLI);
        if (waitErr != WAIT_OBJECT_0)
        {
            DbgPrint(L"WaitForSingleObject failed with status %lu", waitErr);
            status = STATUS_UNSUCCESSFUL;
            goto end;
        }


        res = GetExitCodeProcess(info.hProcess, &exitCode);
        if (res == 0)
        {
            DbgPrint(L"GetExitCodeProcess failed with status %lu", GetLastError());
            status = STATUS_UNSUCCESSFUL;
            goto end;
        }

        if (exitCode != STATUS_SUCCESS)
        {
            DbgPrint(L"Execution failed with exit code %lu", exitCode);
            status = STATUS_UNSUCCESSFUL;
            goto end;
        }

    end:
        DbgPrint(L"ExecuteMofcomp Exit");
        return status;
    }

    VOID ServiceStop(_In_ DWORD ExitCode)
    {
        DbgPrint(L"ServiceStop Entry");
        if (StatusHandle == NULL)
        {
            DbgPrint(L"StatusHandle is NULL");
            return;
        }
        DWORD status = STATUS_SUCCESS;
        UpdateServiceStatus(StatusHandle, SERVICE_STOP_PENDING, ExitCode);

        // wait for service to register to WMI
        while ((InterlockedOr(&ControlFlags, 0) & SERVICE_FLAGS_DONE) != 1);

        std::wstring path = GetServicePath();
        if (!path.empty())
        {
            std::wstring removeParam = path + L"\\ME\\remove.mof";

            DbgPrint(L"Starting WMI unregistration.");
            status = ExecuteMofcomp(removeParam);
            if (status != STATUS_SUCCESS)
            {
                DbgPrint(L"ExecuteMofcomp with %s failed.", removeParam);
            }
        }
        if (StopWaitObject != NULL)
        {
            UnregisterWait(StopWaitObject);
        }

        if (StopRequestEvent != NULL)
        {
            CloseHandle(StopRequestEvent);
        }

        WriteToEventLog(EVENT_LOG_INFORMATION, MSG_SERVICE_STOP);
        DbgPrint(L"ServiceStop Exit");
        UpdateServiceStatus(StatusHandle, SERVICE_STOPPED, ExitCode);
    }

    namespace
    {
        DWORD MofRegistration()
        {
            DWORD status = STATUS_SUCCESS;
            std::wstring buildParam, registerParam = { 0 };
            std::wstring path = GetServicePath();
            if (path.empty())
            {
                DbgPrint(L"GetServicePath failed.");
                goto end;
            }
            buildParam = path + L"\\ME\\wmi_build.mof";
            registerParam = path + L"\\ME\\register.mof";

            DbgPrint(L"Starting WMI registration.");
            status = ExecuteMofcomp(buildParam);
            if (status != STATUS_SUCCESS)
            {
                DbgPrint(L"ExecuteMofcomp with %s failed.", buildParam.c_str());
                goto end;
            }

            status = ExecuteMofcomp(registerParam);
            if (status != STATUS_SUCCESS)
            {
                DbgPrint(L"ExecuteMofcomp with %s failed.", registerParam.c_str());
                goto end;
            }
            DbgPrint(L"WMI registration finished successfully.");

            WriteToEventLog(EVENT_LOG_INFORMATION, MSG_REGISTRATION_SUCCESS);
        end:
            if (status != STATUS_SUCCESS)
            {
                WriteToEventLog(EVENT_LOG_ERROR, MSG_REGISTRATION_FAILURE);
            }
            return status;
        }

        bool IMSSUninstall()
        {
            bool corporate_sku = false;

            DbgPrint(L"Uninstall IMSS, if needed.");
            if (!IsSKUCorporate(corporate_sku))
                return false;
            if (corporate_sku)
                return true;

            DbgPrint(L"Try to uninstall IMSS.");

            UNINSTALLIMSS_STATUS status;
            status = UninstallIMSS();
            switch (status)
            {
            case UNINSTALLIMSS_STATUS::FAILED:
                DbgPrint(L"Uninstall IMSS failed.");
                WriteToEventLog(EVENT_LOG_INFORMATION, MSG_IMSS_REMOVAL_FAILURE);
                return false;
            case UNINSTALLIMSS_STATUS::SUCCCEDED:
                WriteToEventLog(EVENT_LOG_INFORMATION, MSG_IMSS_REMOVAL_SUCCESS);
                DbgPrint(L"Uninstall IMSS succeeded.");
                return true;
            default:
                return true;
            }
        }
    }

    _Check_return_
    DWORD WINAPI ServiceRunningWorkerThread(_In_ PVOID)
    {
        DWORD status = STATUS_SUCCESS;
        DWORD first_run_try = 0, imss_flow_done = 0;
        DbgPrint(L"ServiceRunningWorkerThread Entry");

        InterlockedOr(&ControlFlags, SERVICE_FLAGS_STARTED);

        status = MofRegistration();
        if (status != STATUS_SUCCESS)
        {
            goto end;
        }

        if (!RegistryRead(L"ImssUninstallFlowDone", imss_flow_done))
        {
            status = STATUS_UNSUCCESSFUL;
            goto end;
        }
        if (imss_flow_done)
        {
            status = STATUS_SUCCESS;
            goto end;
        }

        if (!RegistryRead(L"FirstRunTry", first_run_try))
        {
            status = STATUS_UNSUCCESSFUL;
            goto end;
        }

        if (++first_run_try > 3)
        {
            if (!RegistryWrite(L"ImssUninstallFlowDone", 1))
            {
                status = STATUS_UNSUCCESSFUL;
                goto end;
            }
            status = STATUS_SUCCESS;
            goto end;
        }

        if (!RegistryWrite(L"FirstRunTry", first_run_try))
        {
            status = STATUS_UNSUCCESSFUL;
            goto end;
        }

        if (IMSSUninstall())
        {
            if (!RegistryWrite(L"ImssUninstallFlowDone", 1))
            {
                status = STATUS_UNSUCCESSFUL;
                goto end;
            }
        }
        status = STATUS_SUCCESS;
end:
        InterlockedOr(&ControlFlags, SERVICE_FLAGS_DONE);
        DbgPrint(L"ServiceRunningWorkerThread Exit");
        return status;
    }

    _Check_return_
        DWORD WINAPI ServiceStopWorkerThread(_In_ PVOID /*lpThreadParameter*/)
    {
        ServiceStop(ERROR_SUCCESS);

        return 0;
    }

    VOID CALLBACK ServiceStopCallback(
        _In_ PVOID   lpParameter,
        _In_ BOOLEAN /*TimerOrWaitFired*/
    )
    {
        //
        // Since wait object can not be unregistered in callback function, queue
        // another thread
        //
        QueueUserWorkItem(ServiceStopWorkerThread,
            lpParameter,
            WT_EXECUTEDEFAULT);
    }

    _Check_return_
        DWORD WINAPI ServiceCtrlHandler(
            _In_ DWORD Ctrl,
            _In_ DWORD dwEventType,
            _In_ LPVOID lpEventData,
            _In_ LPVOID lpContext
        )
    {
        switch (Ctrl)
        {
        case SERVICE_CONTROL_STOP:
            //
            // Set service stop event
            //
            UpdateServiceStatus(StatusHandle, SERVICE_STOP_PENDING, ERROR_SUCCESS);
            SetEvent(StopRequestEvent);
            break;

        default:
            break;
        }
        return NO_ERROR;
    }

    VOID WINAPI ServiceMain(DWORD, LPTSTR*)
    {
        DWORD Err = ERROR_SUCCESS;

        DbgPrint(L"ServiceMain Entry");
        StatusHandle = RegisterServiceCtrlHandlerExW((LPWSTR)SERVICE_NAME,
            ServiceCtrlHandler, NULL);

        if (StatusHandle == NULL)
        {
            DbgPrint(L"RegisterServiceCtrlHandlerExW Failed");
            Err = GetLastError();
            goto cleanup;
        }

        UpdateServiceStatus(StatusHandle,
            SERVICE_START_PENDING,
            ERROR_SUCCESS);

        //
        // Register callback function for stop event
        //
        StopRequestEvent = CreateEvent(NULL, TRUE, FALSE, NULL);

        if (StopRequestEvent == NULL)
        {
            Err = GetLastError();
            DbgPrint(L"Event Creation Failed with Error", Err);
            goto cleanup;
        }

        if (!RegisterWaitForSingleObject(&StopWaitObject,
            StopRequestEvent,
            ServiceStopCallback,
            NULL,
            INFINITE,
            WT_EXECUTEONLYONCE | WT_EXECUTEINPERSISTENTTHREAD))
        {
            Err = GetLastError();
            DbgPrint(L"RegisterWaitForSingleObject Failed with Error", Err);
            goto cleanup;
        }

        UpdateServiceStatus(StatusHandle,
            SERVICE_START_PENDING,
            ERROR_SUCCESS);

        //
        // Queue the main service function for execution in a worker thread.
        //
        QueueUserWorkItem(&ServiceRunningWorkerThread,
            NULL,
            WT_EXECUTELONGFUNCTION);

        UpdateServiceStatus(StatusHandle,
            SERVICE_RUNNING,
            ERROR_SUCCESS);

        WriteToEventLog(EVENT_LOG_INFORMATION, MSG_SERVICE_START);

    cleanup:

        if (Err != ERROR_SUCCESS)
        {
            ServiceStop(Err);
        }

        DbgPrint(L"ServiceMain Exit");
    }
};

_Check_return_
INT main()
{
    WMIRegistrationService::DbgPrint(L"main entry");

    SetDefaultDllDirectories(LOAD_LIBRARY_SEARCH_SYSTEM32);

    SERVICE_TABLE_ENTRY serviceTable[] =
    {
        { SERVICE_NAME, (LPSERVICE_MAIN_FUNCTION)WMIRegistrationService::ServiceMain },
        { NULL, NULL }
    };

    return StartServiceCtrlDispatcher(serviceTable);
}
