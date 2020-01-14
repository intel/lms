/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2017-2020 Intel Corporation
 */
#ifndef DATA_INTERFACE_BE_H
#define DATA_INTERFACE_BE_H
#include "AMT_COM_Interface_defs.h"


namespace Intel {
	namespace LMS {

		class Common_BE
		{
		public:
			Common_BE(bool isPfwUp) :m_isPfwUp(isPfwUp) {};

		protected:
			bool m_isPfwUp;
		};


		typedef enum LMS_ERROR
		{
			ERROR_OK = 0,
			ERROR_FAIL = 1,
			ERROR_UNEXPECTED = 2,
			ERROR_INVALIDARG = 3,
			ERROR_NOT_AVAILABLE_NOW = 4,
			ERROR_NOT_SUPPORTED_BY_FW = 5,
		} LMS_ERROR;

	}
}
#endif // DATA_INTERFACE_BE_H
