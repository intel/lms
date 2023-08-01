/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2017-2023 Intel Corporation
 */
#ifndef DATA_INTERFACE_BE_H
#define DATA_INTERFACE_BE_H
#include "AMT_COM_Interface_defs.h"


namespace Intel {
	namespace LMS {

		class Common_BE
		{
		public:
			Common_BE(unsigned int port) : m_port(port) {};

		protected:
			const unsigned int m_port;
		};


		enum class LMS_ERROR
		{
			OK = 0,
			FAIL = 1,
			UNEXPECTED = 2,
			INVALIDARG = 3,
			NOT_AVAILABLE_NOW = 4,
			NOT_SUPPORTED_BY_FW = 5,
		};

	}
}
#endif // DATA_INTERFACE_BE_H
