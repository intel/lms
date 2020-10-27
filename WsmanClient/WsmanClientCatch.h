/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2018-2020 Intel Corporation
 */
/*++

@file: WsmanClientCatch.h

--*/

#ifndef _WSMAN_CLIENT_CATCH_H
#define _WSMAN_CLIENT_CATCH_H


#define CATCH_exception_return(func) \
	catch (std::exception& e) \
	{ \
		const char* reason = e.what(); \
		WSMAN_ERROR("Error: Exception in " func " %C\n", reason); \
		return false; \
	}
#define CATCH_exception_return_AMT_code(func) \
	catch (std::exception& e) \
	{ \
		const char* reason = e.what(); \
		WSMAN_ERROR("Error: Exception in " func " %C\n", reason); \
		return WSMAN_AMT_INTERNAL_ERROR; \
	}
#define CATCH_exception(func) \
	catch (std::exception& e) \
	{ \
		const char* reason = e.what(); \
		WSMAN_ERROR("Error: Exception in " func " %C\n", reason); \
	}
#define CATCH_exception_debug(func) \
	catch (std::exception& e) \
	{ \
		const char* reason = e.what(); \
		WSMAN_DEBUG("Error: Exception in " func " %C\n", reason); \
	}


#endif // _WSMAN_CLIENT_CATCH_H