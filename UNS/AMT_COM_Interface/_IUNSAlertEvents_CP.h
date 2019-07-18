/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2009-2019 Intel Corporation
 */
/*++

@file: _IUNSAlertEvents_CP.h

--*/

#pragma once
#include "global.h"

template<class T>
class CProxy_IUNSAlertEvents :
	public IConnectionPointImpl<T, &__uuidof(_IUNSAlertEvents)>
{
public:
	HRESULT Fire_Alert(USHORT category,
				ULONG id,
				BSTR message,
				BSTR messageArg,
				BSTR messageID, 
				BSTR dateTime)
	{
		HRESULT hr = S_OK;
		T * pThis = static_cast<T *>(this);
		int cConnections = m_vec.GetSize();
		
		for (int iConnection = 0; iConnection < cConnections; iConnection++)
		{
			pThis->Lock();
			CComPtr<IUnknown> punkConnection = m_vec.GetAt(iConnection);
			pThis->Unlock();

			IDispatch * pConnection = static_cast<IDispatch *>(punkConnection.p);

			if (pConnection)
			{
				CComVariant avarParams[6];
				avarParams[5] = category;
				avarParams[5].vt = VT_UI2;
				avarParams[4] = id;
				avarParams[4].vt = VT_UI4;
				avarParams[3] = message;
				avarParams[3].vt = VT_BSTR;
				avarParams[2] = messageArg;
				avarParams[2].vt = VT_BSTR;
				avarParams[1] = messageID;
				avarParams[1].vt = VT_BSTR;
				avarParams[0] = dateTime;
				avarParams[0].vt = VT_BSTR;
				DISPPARAMS params = { avarParams, NULL, 6, 0 };
				hr = pConnection->Invoke(1, IID_NULL, LOCALE_USER_DEFAULT, DISPATCH_METHOD, &params, NULL, NULL, NULL);
				if (hr!=S_OK)
				{
					UNS_DEBUG(L"Invoke (%d) returned hr=0x%X\n", iConnection, hr);
				}
			}
		}
		return hr;
	}
};

