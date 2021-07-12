/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2010-2015 Intel Corporation
 */
//Note : "windows.h" or another file contatinig definitions of BOOL,INT32,UINT32 etc. should be included before this file

#pragma once //to prevent IntelliSense error
#ifndef __AMT_COM_INTERFACE_DEFS_H_
#define __AMT_COM_INTERFACE_DEFS_H_


typedef enum USER_CONSENT_POLICY {
		NOT_REQUIRED = 0,
		KVM_ONLY = 1,
		ALL_SESSIONS = 4294967295
	} USER_CONSENT_POLICY;

#define MAX_DISPLAY_NUMBER_LEGACY 3
#define MAX_DISPLAY_NUMBER_LATEST 4

	typedef struct DISPLAY_PARAMETERS_
	{
		int IsActive;
		int UpperLeftX;
		int UpperLeftY;
		unsigned int SizeX;
		unsigned int SizeY;
		unsigned int Pipe;
	}DISPLAY_PARAMETERS;

	typedef enum REDIRECTION_SESSION_TYPE
	{
		SOL_S = 0,
		IDER_S = 1,
		KVM_S = 2
	}REDIRECTION_SESSION_TYPE;

	typedef struct EXTENDED_DISPLAY_PARAMETERS_
	{
		DISPLAY_PARAMETERS DisplayParameters[MAX_DISPLAY_NUMBER_LATEST];
	}EXTENDED_DISPLAY_PARAMETERS;

	typedef enum FEATURE_STATE {
		NOT_PRESENT,
		DISABLED,
		ENABLED,
		AVAILABLE
	} FEATURE_STATE;

	typedef enum FEATURES {
		AMT = 0,
		IRWT,
		QST,
		TDT,
		SOFTCREEK,
		VE,
		DT,
		NAND,
		MPC,
		ICC_OVER_CLOCK_IN,PAV,SPK,RCA,RPAT,IPV6,KVM,OCH,DAL,TLS,CILA,
		LAKEHOUSTON,
		PSR,
		FEATURES_NUM
	} FEATURES;

	typedef enum CUSTOMER_TYPE {
		CORPORATE,
		CONSUMER,
		WRONG_CUSTOMER_TYPE

	} CUSTOMER_TYPE;

	typedef enum PLATFORM_TYPE {
		MOBILE,
		DESKTOP,
		SERVER,
		WORKSTATION
	} PLATFORM_TYPE;

	typedef enum MENAGEABILTY_MODE {
		NONE,
		NOT_KNOWN,
		VPRO,
		STANDARD,
		L3,
		SBT
	} MENAGEABILTY_MODE;


#endif //#ifndef __AMT_COM_INTERFACE_DEFS_H_

