Intel(R) AMT LMS
================
Intel Local Manageability Service allows applications
to access the Intel Active Management Technology (AMT) firmware via
the Intel Management Engine Interface (MEI).

## Build prerequisites

### Windows

#### ACE
1. Download ACE library from [ACE Download page](http://download.dre.vanderbilt.edu/).
2. Configure ACE_ROOT environmental variable with download location.
3. Configure ACE_LIB environmental variables with %ACE_ROOT%\lib.
4. Copy ace-config-win.h to ${ACE_ROOT}/ace/config.h - note that Windows LMS requires ACE compiled with WCHAR support.
5. Build ACE library.

#### libxml
1. Download libxml from [GNOME Download page](https://gitlab.gnome.org/GNOME/libxml2/-/archive/master/libxml2-master.zip') and build it or use prebuilt binary.
2. Configure LIBXML2_LIBRARY environmental variable with compiled library full path.
3. Configure LIBXML2_INCLUDE_DIR environmental variable with full path to libxml2 include directory.

### Linux

#### ACE
 * You can use the ACE package provided by your distribution (libace-dev package in Debian).
 * Alternatively:
   1. Download ACE library from [ACE Download page](http://download.dre.vanderbilt.edu/).
   2. Configure ACE_ROOT environmental variable with download location.
   3. Configure ACE_LIB environmental variables with ${ACE_ROOT}/lib.
   4. Build ACE with default Linux configuration [Building and Installing ACE on UNIX](http://www.dre.vanderbilt.edu/~schmidt/DOC_ROOT/ACE/ACE-INSTALL.html#unix).

### Cross-platform

#### MeTee library
CMake script downloads the MeTee library sources from [GitHub](https://github.com/intel/metee)
if library is not found in the system paths.
One can set environment variable METEE_LIB_PATH to pre-compiled library and METEE_HEADER_PATH for headers to
help CMake in library search.

#### OpenWsman library
The in-tree copy of OpenWsman library is located at CIM_Framework/openwsman/ directory.
The sources are from 2.6.9 version from [GitHub](https://github.com/Openwsman/openwsman) with local modifications:
* Static analysis fixes
* Passwords are stored encrypted on Windows
* CMake build enabled on Windows

#### GoogleTest (only for builds with unit-tests enabled)

For builds that includes unit-tests CMake script downloads googletest from [GitHub](https://github.com/google/googletest).
To skip automatic download one can download it manually to Common/googletest directory.

## Build dependencies

### Windows
* VisualStudio 2017 with CMake support.

### Linux
#### Tools
* cmake
* C++ compiler
* python3

#### Libraries

* gio-2.0 (libglib2.0-dev package in Debian)
* libcurl (libcurl4-openssl-dev package in Debian)
* libxerces-c (libxerces-c-dev package in Debian)
* libnl-3 (libnl-3-dev package in Debian)
* libnl-route-3 (libnl-route-3-dev package in Debian)
* libxml2 (libxml2-dev package in Debian)

##### Optional dependencies for building DBus interface documentation:
* xsltproc
* docbook-xsl

#### NetworkManager or Connman support

LMS utilizes network service for querying the host network parameters, it can work with NetworkManager, Connman, or directly with netlink.
The support is detected during CMake configuration.

The CMake detects availability of the manager by looking for a package config file.
The package config files are usually part of a Linux distribution development package such as network-manager-dev and connman-dev in Debian.
One of them should be installed to enable configuration time detection.
In Yocto the desired service should be configured in the recipe. 

## Build

### Windows

1. Create `build` directory
2. Run `cmake -G "Visual Studio 15 2017" -A <Build_arch> <srcdir>` from the `build` directory (best to set build_arch to Win32)
3. Run `cmake --build . --config Release --target package -j <nproc>` from the `build` directory to build an archive with all executables and libraries (e.g. lms-1.0.0-win32.zip)

### Linux

1. Create `build` directory
2. Run `cmake <srcdir>` from the `build` directory
3. Run `make -j$(nproc) package` from the `build` directory to build a Debian package (e.g. lms-1.0.0-Linux.deb)

## Install

### Windows

1. Unpack bin directory from build-generated archive.
2. Run `lms-installer.bat install` from unpacked archive.

### Linux

1. `sudo dpkg -i <generated .deb package>`
