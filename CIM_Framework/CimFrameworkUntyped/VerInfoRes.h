// Copyright (C) 2003 Intel Corporation
#include "../version.h"

#define TO_STR(x) #x
#define TO_STR2(x) TO_STR(x) "\0"
 
#define MCSDK_PRODUCTVERSION MAJOR_VERSION, MINOR_VERSION, QUICK_FIX_NUMBER
#define MCSDK_PRODUCTVERSION_STR TO_STR2(MAJOR_VERSION.MINOR_VERSION.QUICK_FIX_NUMBER)

#define MCSDK_FILEVERSION MCSDK_PRODUCTVERSION, VER_BUILD
#define MCSDK_FILEVERSION_STR MCSDK_PRODUCTVERSION_STR "." TO_STR2(VER_BUILD)

#define MCSDK_BUILD_NUM_STR TO_STR2(VER_BUILD)


#define COMPANY_NAME        "Intel Corporation\0"
#define MODULE_NAME         "CimFrameworkUntyped\0"
#define PRODUCT_BUILDVER    MCSDK_FILEVERSION_STR
#define INTERNAL_NAME       "CimFrameworkUntyped\0"
#define COPYRIGHT_STRING    "Copyright � 2004-2014 Intel Corporation, All rights reserved\0" 
#define ORIGINAL_NAME       "CimFrameworkUntyped.dll\0"
#define PRODUCT_NAME        "CimFrameworkUntyped Dynamic Link Library\0"
#define LEGAL_TRADEMARK     "\0"
#define OLE_SELFREG         "\0"
#define PRODUCT_VERSION     MCSDK_PRODUCTVERSION_STR
#define BUILD_NUMBER        MCSDK_BUILD_NUM_STR
