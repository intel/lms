/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2018 Intel Corporation
 */
/*++

@file: WsmanClientCatch.h

--*/

#ifndef _WSMAN_CLIENT_CATCH_H
#define _WSMAN_CLIENT_CATCH_H

#ifdef _DEBUG
#define CATCH_exception_return(func) \
	catch (std::exception& e) \
	{ \
		const char* reason = e.what(); \
		DbgPrint("\nError: Exception in " func " %s\n", reason); \
		return false; \
	}
#define CATCH_exception(func) \
	catch (std::exception& e) \
	{ \
		const char* reason = e.what(); \
		DbgPrint("\nError: Exception in " func " %s\n", reason); \
	}
#else
#define CATCH_exception_return(func) \
	catch (std::exception&) {return false;}
#define CATCH_exception(func) \
	catch (std::exception&) {}
#endif // _DEBUG

#endif // _WSMAN_CLIENT_CATCH_H