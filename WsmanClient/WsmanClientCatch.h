/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2018-2024 Intel Corporation
 */
/*++

@file: WsmanClientCatch.h

--*/

#ifndef _WSMAN_CLIENT_CATCH_H
#define _WSMAN_CLIENT_CATCH_H

#ifdef WIN32
#include <atlbase.h>

#define CATCH_exception_return(func) \
	catch (const std::exception& e) \
	{ \
		const char* reason = e.what(); \
		WSMAN_ERROR("Error: Exception in " func " %C\n", reason); \
		return false; \
	} \
	catch (const ATL::CAtlException& e) \
	{ \
		WSMAN_ERROR("Error: AtlException in " func " hr = 0x%X\n", e.m_hr); \
		return false; \
	}
#define CATCH_exception_return_AMT_code(func) \
	catch (const std::exception& e) \
	{ \
		const char* reason = e.what(); \
		WSMAN_ERROR("Error: Exception in " func " %C\n", reason); \
		return WSMAN_AMT_INTERNAL_ERROR; \
	} \
	catch (const ATL::CAtlException& e) \
	{ \
		WSMAN_ERROR("Error: AtlException in " func " hr = 0x%X\n", e.m_hr); \
		return WSMAN_AMT_INTERNAL_ERROR; \
	}
#define CATCH_exception(func) \
	catch (const std::exception& e) \
	{ \
		const char* reason = e.what(); \
		WSMAN_ERROR("Error: Exception in " func " %C\n", reason); \
	} \
	catch (const ATL::CAtlException& e) \
	{ \
		WSMAN_ERROR("Error: AtlException in " func " hr = 0x%X\n", e.m_hr); \
	}
#define CATCH_exception_debug(func) \
	catch (const std::exception& e) \
	{ \
		const char* reason = e.what(); \
		WSMAN_DEBUG("Error: Exception in " func " %C\n", reason); \
	} \
	catch (const ATL::CAtlException& e) \
	{ \
		WSMAN_DEBUG("Error: AtlException in " func " hr = 0x%X\n", e.m_hr); \
	}

#else // WIN32

#define CATCH_exception_return(func) \
	catch (const std::exception& e) \
	{ \
		const char* reason = e.what(); \
		WSMAN_ERROR("Error: Exception in " func " %C\n", reason); \
		return false; \
	}
#define CATCH_exception_return_AMT_code(func) \
	catch (const std::exception& e) \
	{ \
		const char* reason = e.what(); \
		WSMAN_ERROR("Error: Exception in " func " %C\n", reason); \
		return WSMAN_AMT_INTERNAL_ERROR; \
	}
#define CATCH_exception(func) \
	catch (const std::exception& e) \
	{ \
		const char* reason = e.what(); \
		WSMAN_ERROR("Error: Exception in " func " %C\n", reason); \
	}
#define CATCH_exception_debug(func) \
	catch (const std::exception& e) \
	{ \
		const char* reason = e.what(); \
		WSMAN_DEBUG("Error: Exception in " func " %C\n", reason); \
	}

#endif

#endif // _WSMAN_CLIENT_CATCH_H