## [2113.0.0.0]

### Added
 - WMIProv: enable build with CMake
 - CMake: add Windows SDK hint in find MC
 - CMake: add Conan install code

### Fixed
 - CMake: Windows: fix build with 3.16
 - WMIProvTest: account for unability to open remote session
 - WSManClientTest: fix UTC time retrieval
 - WMIProvTest: account for AMT not ready
 - WMIProv: fix debug print in WindowsEventLog
 - fix run in console mode
 - PortForwadingService: call DeInit in LMEConnection destructor
 - WMIProv: drop unused and unchnaged parameters from functions
 - CMake: fix build with downloaded GTest

### Changed
 - CMake: drop Lms prefix from static libraries
 - snap: make snapcraft.yaml static
 - CMake: assorted Windows fixes
 - MEWMIProv: CMake: compile files with non-standard capitalization and add export
 - CMake: do not link default libraries in Universal build

## [2109.0.0.0]

### Added
 - MEIClient: UPID: Add value map for OEMPlatformIDType
 - MEWMIProv: add tests for more interfaces

### Fixed
 - MEWMIProv: Test: fix conan imports
 - LMS: Weak Manifest File Permission
 - LMS: fix errors and warnings reported by VS2019
 - WMIProv: fix build with unicode charset

### Changed
 - LMS: Conan: pick MeTee 3.0.1

## [2107.1.0.0]

### Fixed
 - LMS: fix style and spelling errors

### Changed
 - PartialFWUpdate: on WCOD update on ME16 and newer

### Removed
 - Linux: Build: drop ability to define external version
 - DBus: remove deprecated methods

## [2107.0.0.0]

### Fixed
 - Fix WatchdogError Registry Variable name
 - Update external libraries part in README
 - WindowsEventLog: Remove redundant linebreak from messages logged to Event Viewer
 - CIM_Framework: fix CMake Win build

### Changed
 - Add password cleanup and remove the encryption
 - CMake: link ACE in modern way
 - Conan: use explicit static runtime (MT)
 - CIM_Framework: OpenWsman: Debug: enable LinkTimeCodeGeneration
 - Obtain GTest from Conan
 - Obtain libxml2 and ACE from Conan

### Added
 - PortForwardingService: fail Init if updateEnterpriseAccessStatus failed
 - CMake: Set /SDL Flag

## [2102.1.0.0]

### Fixed
 - WifiProfileSync: rewrite OS profile storage logic

### Deprecated
 - PartialFWUpdate: remove support for ME10 and older FW

### Added
 - WMI provider: add more test

## [2102.0.0.0]

### Fixed
 - CIM_Framework: CimOpenWsmanClient: add 100_SUPRESS to Invoke
 - IPRefreshService: fix update of adapters list
 - WifiProfileSync: perform sync only if required
 - Configurator: avoid toggling services that does not exists
 - Configurator: continue execution if dependencies are no-ops

### Changed
 - WMIProv: Build: use internal version

### Added
 - IP Refresh: add prints on failed refresh
 - Audit Log: Add UEFI/CSME WiFi Profile Sharing report

## [2052.1.0.0]

### Fixed
 - PortForwardingService: fix port forwarding started event condition

### Changed
 - Add option to pull metee from conan

## [2052.0.0.0]

### Fixed
 - Watchdog: Linux: fix enable on provision
 - CIM_Framework: openwsman: pull code till commit 52932db5a01573ddd5ea0fbdbd2aa8f2cf6834ae
 - Watchdog: Linux: retry with short timeout on error

### Added
 - Linux: Add Watchdog documentation

### Deprecated
 - Remove AntiTheft code from IMSS and LMS COM. GetATDeviceInfo COM method is deprecated.

## [2049.0.0.0]

### Fixed
 - MEIClient: use size_t instead of int for buffer sizes
 - WMIProvider: A bulk fix for programming issues
 - MEIClient: Separate metee headers

### Added
 - Windows: PFU sideloading script
 - Linux: add WatchdogService

## [2046.0.0.0]

### Fixed
 - WiFiProfileSync: improve logging of profile add/update failures
 - CMake: fix spelling in options text
 - CMake: make AMT_COM_interface object library
 - WiFiProfileSync: add profile update in full sync
 - snap: update snap template
 - Windows: fix standalone install script

### Added
 - CMake: add PDB generation

### Fixed

## [2044.0.0.0]

### Fixed
 - WMIProv: Add basic flow-tests WMI provider
 - WiFiProfileSync: improve logging of profile add/update failures
 - WMIProv: re-enable logging

## [2043.0.0.0]

### Fixed
 - WMIProv: drop unused code
 - CIM_Framework: CMake: fix library dependencies
 - AMT_COM_Interface: fix a typo in AMT_COM_Interface.idl

## [2042.0.0.0]

### Fixed
  - Windows: compare PFUpdateLib path case insensitive.
  - WMIProv: get admin credentials from the WsmanClient.
  - Fix some trivial typos and style issues

## [2041.0.0.0]

### Fixed
  - CMake: default to MeTee 3.0.0 from GitHub
  - CMake: take AMT_COM_Interface as usual lib
  - WMIProv: CMake: pick version.h path
  - LMS: AMT_COM: push pack version into lms.exe


## [2039.1.0.0]

### Fixed
 - CIM_Framework: turn OFF BUILD_LIBCIM
 - Fix dll signature verification

## [2039.0.0.0]

### Fixed
 - DataInterfaceBackend: fix signed/unsigned mismatch warning
 - WMIProv: code cleanup
 - Configurator: add missing \n in debug print
 - WsmanClient: separate logging macros

## [2036.1.0.0]

### Added
 - WMI Provider: Crossover Canyon Unique Platform ID WMI Provider APIs

## [2036.0.0.0]

### Fixed
 - Bundled 3rd party libraries updated to the latest versions
 - PartialFWUpdate: print better error message for unmatched PFU files
 - Bring back resource for ATL events

## [2034.0.0.0]

### Added
 - PartialFWUpdateService: Add ability to select PFU files by HotFix number

### Fixed
 - openwsman: fix potential NULL pointer dereference
 - PartialFWUpdateService: drop redundant initSubService

### Changed
 - [Windows] WMIProv: remove unused functions
 - Statically link all local libraries. Only FWUpdate libraries are left as shared objects.

### Deprecated
 - Drop ME10 support
 - [Windows] Deprecate IsRebootAfterProvisioningNeeded COM method.

## [2022.0.0.0]

### Added
 - Add module name in invalid message prints to differentiate errors from different modules.
 - Enable ACE debug in debug builds.
 - Add a flag to disable export/import prefixes to enable build of static libraries.
 - AMT_COM_Test: Add IsMeasuredBootState test.
 - AMT_COM_Test: print error number in exception catch.

### Fixed
 - CMake: pick external ACE only if library and header found.
 - [Windows] Fix 'unreferenced formal parameter' warnings.
 - [Windows] HostChangesNotificationService: fix original file name in resource.
 - Do not set FLog size to 0 if FW request to obtain FLog size failed to eliminate false events.
 - [Windows] Add mutex to ensure that HECI notifier is finished it execution before it can be disabled.
 - [Linux] Enable no-strict-overflow and no-delete-null-pointer-checks flag for GCC only.
 - Fix spelling issues found by codespell.
 - [Windows] Pass NULL for device path as required by MeTee on Windows (required for MeTee 2.2.2).
 - [Windows] lms-installer.bat - dropped unused and added new registry entries.

### Changed
 - Move FuncEnterExit into classes to add more granular logging.
 - Consolidate MB_SERVICE_STATUS_CHANGED.
 - [Linux] CIM_Framework: CimFramework: explicitly link pthread.
 - [Linux] Choose network service at build configuration time - use NETWORK_NM and NETWORK_CM CMake options to select desired network backend.
 - Modernize cmake files.

## [2011.0.0.0]

### Added
 - Add special error for requests not supported by the system (G_IO_ERROR_NOT_SUPPORTED on DBus, E_NOINTERFACE on COM)
 - MEIClient: make exceptions hierarchical for ease of catching
 - Reduce calls to FW by retrieving only required info
 - PortForwardingService: demote traffic dump to TRACE level
 - WMIProvider: mark mof removal as nofail
 - StatusEventHandler: improve WifiProfileSync detection
 - code quality improvements

### Fixed
 - Avoid WS-MAN calls till port forwarding is available in different code paths
 - MEIClient: CMake: fix build with Ninja
 - [Windows] WifiProfileSync: OWE PSKPassPhrase should be NULL
 - PowerOperationService: set default value for reboot reason message to the correct variable
 - [Windows] WiFiProfileSync: consolidate all operation in one WsManClient instance to avoid crash
 - [Windows] WiFiProfileService: plug memleak in error path

### Deprecated
 - Drop AMT 7 support from SetSpriteLanguage DBus and COM methods
 - Drop unused LMSstarted event and deprecate reset COM method.
 - Deprecate unused DBus and COM interfaces:
    - GetProvisioningMode
    - GetProvisioningTlsMode
    - getWebUIState
    - TerminateKVMSession
    - UpdateScreenSettings
    - ProxyAddProxyEntry
    - GetFeaturesState
    - GetPlatformType
    - OpenUserInitiatedConnection

## [2003.0.0.0]

### Fixed
 - [Windows] Fix build with CMake
 - [Windows] Explicitly ask for CMake 3.12 in AMT_COM_Interface
 - Delete LastLanguageUpdate registry value for default language set and fix it usage
 - WifiProfileSync: Add support for OWE in WPA3 protocol
 - PortForwarding: try re-init if mei is fast-disconnected to fix service stale on CSME reset

## [2001.0.0.0]

### Added
 - Update internal copy of openwsman code to latest upstream tip
 - [Windows] Support for WPA3 protocol in WiFiProfileSync
 - Improve code quality (variable shadowing, unused code, code style, etc.)
 - [Windows] Push some prints from debug to trace to lighten logs in WiFiProfileSync
 - [Windows] Clean up the memory management in IPRefresh service.
 - [Windows] Add build option to bypass DLL signatures check
 - Add IsMeasuredBootState method to DBus and COM interfaces

### Fixed
 - [Windows] Fix DLL signature check
 - [Windows] Remove logging of AP password in WiFiProfileSync
 - Replace non-threadsafe functions
 - Fix various cases where service failed to stop
 - [Windows] Fix socket creation on Windows 8.1
 - Fix initialization sequence for cases when MEI is not ready yet
 - [CMake] fix build-depend on MeTee to ensure proper build order
 - Fix buffer overflow in RegistryStorage
 - Fixes for bunch of security issues (check return values, input validation, use secure functions)

## [1932.0.0.0]

### Added
 - Improve debug prints in WsManClient code and print errors in Release builds

### Fixed
 - AuditLogWSManClient: Add parse to value 3 in InitType

## [1930.0.0.0]

### Added
 - Traffic dump into general log
 - The log system was updated:
   - different log levels
   - ability to enable logs above specified severity
   - the debug is enabled using the lms_enable_logging_severity.sh/bat script
 - Fix and add scripts for LMS testing
 - Conditionally add tests to installation package for ease of continuous integration
 - [Linux] load service libraries using full name to ease on Yocto integration

### Fixed
 - Build instructions updated
 - Fix vector size initialization in port forwarding
 - [Windows] Release HECI device on driver unload to allow restart-less update
 - [Linux] make storage directories traversable (set executable bit for new directories created in /etc/lms)


