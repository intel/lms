/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2003-2021 Intel Corporation
 */
/*++

@file: wmiinfrastructure.h

--*/
#ifndef __MWI_TYPES_H_
#define __MWI_TYPES_H_

#include <atlbase.h>

#include <string>
#include <sstream>
#define STATUS_SUCCESS 0
#define _WIN32_DCOM
#include    <objbase.h>
#include    <atlbase.h>
#include    <atlsafe.h>
#include    <atlstr.h>
#include    <atlcom.h>
#include    <atlcomcli.h>
#include    <vector>
#include    <string>
#include    <comdef.h>
#include    <comutil.h>
#include    <wbemcli.h>
#include    <wbemprov.h>
#include    <objbase.h>
#include    <Wmiutils.h>
#include    <functional>
#include    <map>
#include "DebugPrints.h"

#ifndef ASSERT
#ifdef _DEBUG
#include    <assert.h>
#define ASSERT(x)   assert(x)
#else
#define ASSERT(x)
#endif
#endif

//  WMI stuff   -------------------------------------------------------------
typedef unsigned __int64    uint64;
typedef unsigned __int32    uint32;
typedef unsigned __int16    uint16;
typedef unsigned __int8     uint8;

typedef signed __int64      sint64;
typedef signed __int32      sint32;
typedef signed __int16      sint16;
typedef signed __int8       sint8;

//  mof -> variant conversion   ---------------------------------------------
// please refer to http://msdn2.microsoft.com/en-us/library/aa392716.aspx
template<typename T>inline variant_t mof2var(T            data)       {return variant_t(data);}   // default
template<>          inline variant_t mof2var(uint8        data)  {return variant_t((signed short)data);}
template<>          inline variant_t mof2var(uint16       data)  {return variant_t((signed long )data);}
template<>          inline variant_t mof2var(uint32       data)  {return variant_t((signed long )data);}

template<>          inline variant_t mof2var(sint8  data)  {return variant_t((signed short)data);}
template<>          inline variant_t mof2var(sint16 data)  {return variant_t((signed long )data);}
template<>          inline variant_t mof2var(sint32 data)  {return variant_t((signed long )data);}

template<>          inline variant_t mof2var(uint64 data)
{
    wchar_t     temp[128];
    swprintf_s(temp, sizeof(temp) / sizeof(temp[0]), L"%I64u", data);
    return variant_t(temp);
}

template<>          inline variant_t mof2var(sint64 data)
{
    wchar_t     temp[128];
    swprintf_s(temp, sizeof(temp) / sizeof(temp[0]), L"%I64d", data);
    return variant_t(temp);
}

template<>          inline variant_t mof2var(std::wstring data)  {return variant_t(data.c_str());}

//  variant -> mof conversion   ---------------------------------------------
template<typename T>  inline T         var2mof(variant_t   data)   {return (T)data;}   // default
template<>            inline uint64    var2mof(variant_t   data)
{
    uint64      res;
    swscanf_s(data.bstrVal, L"%I64u", &res);

    return res;
}
template<>            inline sint64    var2mof(variant_t   data)
{
    sint64      res;
    swscanf_s(data.bstrVal, L"%I64d", &res);

    return res;
}

template<>             inline std::wstring   var2mof(variant_t   data)   {return data.bstrVal;}

//typedef CString         String;
//typedef CString         Datetime;

DEFINE_AUTOMATION_TYPE_FUNCTION(bool		, bool			,VT_BOOL)

template <>
struct _ATL_AutomationType<std::wstring>
{
    typedef CComBSTR _typewrapper ;
    enum { type = VT_BSTR};
    static void* GetT(const std::wstring& t) throw()
	{
        return  CComBSTR(t.c_str()).Copy();
	}
};

#define INVALID_PARAMETER 2
#define GetParamBREAKIF(exp,s1)    \
	if(exp != S_OK) {\
	hr = WBEM_E_INVALID_METHOD_PARAMETERS; \
	UNS_ERROR("Bad WMI param %s\n", s1); \
	break; } \
	else \
	hr = WBEM_S_NO_ERROR;

#define GetRequiredParamBREAKIF(exp, b,s1)    \
	if(exp != S_OK) {\
	hr = ERROR_IN_PARAMETER; \
	UNS_ERROR("Bad WMI param %s\n", s1); \
	break; }\
	if(!b) {\
	hr = MISSING_MANDATORY_PARAMETER; \
	UNS_ERROR("Required WMI param %s\n", s1); \
	break; }\
	hr = WBEM_S_NO_ERROR;


#define BREAKIF(exp)	\
	hr = exp;							\
	if(hr != S_OK)	{\
	UNS_ERROR("Bad WMI param\n"); \
	break; }

#define RETURNIF(exp)                                                       \
    do{                                                                     \
        HRESULT hr = exp;                                                   \
        if(hr != S_OK)                                                      \
        {                                                                   \
			UNS_ERROR("Bad WMI param\n");                                   \
			return hr;                                                      \
        }                                                                   \
    }while(0)

//  ImpliedType -------------------------------------------------------------
template<typename T>
struct ImpliedType
{typedef T                                      type;};

template<typename T>
struct ImpliedType<CComPtr<T> >
{typedef typename ImpliedType<T*>::type         type;};

template<>
struct ImpliedType<IWbemClassObject*>
{typedef ImpliedType<IUnknown*>::type           type;};

//  Logging -----------------------------------------------------------------
template <typename T>
inline
CString ConvertToStr(T data){return  _T("object");};

template <>
inline
CString ConvertToStr(uint32 data){CString res; res.Format(_T("0x%08x"), data);return  res;};

template <>
inline
CString ConvertToStr(uint16 data){CString res; res.Format(_T("0x%04x"), data);return  res;};

template <>
inline
CString ConvertToStr(uint8 data) {CString res; res.Format(_T("0x%02x"), data);return  res;};

template <>
inline
CString ConvertToStr(std::wstring data){return  data.c_str();};

//  WMIGet  -----------------------------------------------------------------
template<typename T>
static
HRESULT  WMIGetClass(   IWbemServices*      srv,
                        IWbemClassObject*   obj,
                        BSTR                name,
                        T&                  var)
{
    return  E_FAIL;
}


//  WMIGet  -----------------------------------------------------------------
template<bool log, typename T>
static
HRESULT WMIGet(         IWbemServices*      srv,
			   IWbemClassObject*   obj,
			   BSTR                name,
			   T&                  var,			   bool&				specified)
{
	_variant_t  val;

	ASSERT(obj);
	HRESULT hr;
	do {
		BREAKIF(obj->Get(name, 0, &val, NULL, NULL));
		specified = false;
		if(val.vt != VT_NULL)
		{
			var = var2mof<T>(val);
			specified = true;
			/*    if(log)

			Debug.Param() << "    wmiget - " << name << " : " << ConvertToStr<T>(var);
			else
			Debug.Param() << "    wmiget - " << name << " : ********";*/
		}

		return  S_OK;
	}while (0);
	UNS_ERROR("Invalid Parameter %W\n", name);

	return hr;
}

template<bool log>
static
HRESULT WMIGet(IWbemServices*      srv,
			   IWbemClassObject*   obj,
			   BSTR                name,
			   std::wstring&       var,
			   bool&               specified)
{
	_variant_t  val;

	ASSERT(obj);
HRESULT hr;
	do
	{
		specified = false;
		BREAKIF(obj->Get(name, 0, &val, NULL, NULL));
		if(val.vt != VT_NULL)
		{
			var = val.bstrVal;
			specified = true;
			/* if(log)
			Debug.Param() << "    wmiget - " << name << " : " << var;
			else
			Debug.Param() << "    wmiget - " << name << " : ********";*/
		}

		return  S_OK;
	} while (0);
	UNS_ERROR("Invalid Parameter %W\n", name);
	return hr;
}

//  WMIGetArrayElement  -----------------------------------------------------
template<typename T>
static
HRESULT WMIGetArrayElement(SAFEARRAY* array, long index, T& elem)
{
    SafeArrayGetElement(array, &index, (void*)&elem);

    return  S_OK;
}

template<>
static
HRESULT WMIGetArrayElement(SAFEARRAY* array, long index, std::wstring& elem)
{
    BSTR    str;
    SafeArrayGetElement(array, &index, &str);

    elem    = str;

    return  S_OK;
}

//  WMIGet  -----------------------------------------------------------------
template<bool log, typename T>
static
HRESULT  WMIGet(        IWbemServices*      srv,
                        IWbemClassObject*   obj,
                        BSTR                name,
                        std::vector<T>&     vec)
{
    _variant_t          val;
    CIMTYPE             type;
    IWbemClassObject*   child   = obj;
    T                   var;

    ASSERT(obj);

    RETURNIF(obj->Get(name, 0, &val, &type, NULL));
    SAFEARRAY*  array   = val.parray;

    for(ULONG i = 0; i < array->rgsabound->cElements; i++)
    {
        LONG    ix  = i;

        WMIGetArrayElement(array, ix, var);

        vec.push_back(var);

        ix++;
    }
    return  S_OK;
}

//  WMIGet  -----------------------------------------------------------------
template<typename T>
static
HRESULT  WMIGetClass(   IWbemServices*      srv,
                        IWbemClassObject*   obj,
                        BSTR                name,
                        std::vector<T>&     vec)
{
    _variant_t  val;
    CIMTYPE     type;
    IWbemClassObject*   child   = obj;

    ASSERT(obj);
    vec.clear();
    RETURNIF(obj->Get(name, 0, &val, &type, NULL));

    if(val.vt != VT_NULL)
    {
        SAFEARRAY*  array   = val.parray;

        for(ULONG i = 0; i < array->rgsabound->cElements; i++)
        {
            LONG    ix  = i;

            CComPtr<IWbemClassObject>   elem;
			T data;
            SafeArrayGetElement(array, &ix, &data);
           // RETURNIF(WMIGetClass(srv, elem, NULL, var));

            vec.push_back(data);

            ix++;
        }
    }

    return  S_OK;
}


static HRESULT  WMIGetClass(   IWbemServices*      srv,
                        IWbemClassObject*   obj,
                        BSTR                name,
                        std::vector<std::wstring>&     vec)
{
    _variant_t  val;
    CIMTYPE     type;

    ASSERT(obj);
    vec.clear();
    RETURNIF(obj->Get(name, 0, &val, &type, NULL));

    if(val.vt != VT_NULL)
    {
        SAFEARRAY*  array   = val.parray;

        for(ULONG i = 0; i < array->rgsabound->cElements; i++)
        {
            LONG    ix  = i;

            CComPtr<IWbemClassObject>   elem;
			BSTR data;
            SafeArrayGetElement(array, &ix, &data);
           // RETURNIF(WMIGetClass(srv, elem, NULL, var));

            vec.push_back(data);

            ix++;
        }
    }

    return  S_OK;
}


//  Validate    --------------------------------------------------------------
template<typename T>
static
void    Validate(       T&                  var)
{
}

template<typename T>
static
void    Validate(       std::vector<T>&     var)
{
    for(size_t i = 0; i < var.size(); i++)
        Validate(var[i]);
}

//  WMIPut  -----------------------------------------------------------------
template<typename T>
static
HRESULT  WMIPutClass(    IWbemServices*      srv,
                        IWbemClassObject*   obj,
                        BSTR                name,
                        T&                  var)
{
    return  E_FAIL;
}

//  WMIPut  -----------------------------------------------------------------
template<bool log, typename T>
static
HRESULT  WMIPut(        IWbemClassObject*   obj,
                        BSTR                name,
                        T&                  var)
{
    _variant_t  val(mof2var(var));
    RETURNIF(obj->Put(name, 0, &val, 0));
 /*   if(log)
        Debug.Param() << "    wmiput - " << name << " : " << ConvertToStr<T>(var);
    else
        Debug.Param() << "    wmiput - " << name << " : ********";*/

    return  S_OK;
}

//  WMIPut  -----------------------------------------------------------------
template<bool log>
static
HRESULT  WMIPut(
                        IWbemClassObject*   obj,
                        BSTR                name,
                        std::wstring&       var)
{
	variant_t  val(var.c_str());

	if (0 == wcscmp(name, L"Password")) //Zero the memory of the decrypted password
	{
		HRESULT hr = obj->Put(name, 0, &val, 0);
		memset(val.bstrVal, 0, (var.size() * sizeof(wchar_t)));
		if (hr != S_OK)
		{
			UNS_ERROR("Bad WMI Param %W\n", name);
			return hr;
		}
	}
	else
	{
		RETURNIF(obj->Put(name, 0, &val, 0));
	}

 /*   if(log)
        Debug.Param() << "    wmiput - " << name << " : " << var;
    else
        Debug.Param() << "    wmiput - " << name << " : ********";*/

    return  S_OK;
}

//  WMIPut  -----------------------------------------------------------------
template<typename T>
static
HRESULT  WMIPut(
                        IWbemClassObject*   obj,
                        BSTR                name,
                        std::vector<T>&     var)
{
    CComSafeArray<ImpliedType<T>::type> array((ULONG)var.size());

    for(size_t i = 0; i < var.size(); i++)
    {
        array.SetAt((ULONG)i, var[i]);
    }
    _variant_t  val;

    val.vt      = VT_ARRAY | array.GetType();
    val.parray  = array.m_psa;

    RETURNIF(obj->Put(name, 0, &val, 0));

    return  S_OK;
}

template<bool log>
static
HRESULT  WMIPut(
                        IWbemClassObject*           obj,
                        BSTR                        name,
                        std::vector<std::wstring>&  var)
{
    CComSafeArray<BSTR>     array((ULONG)var.size());

    for(size_t i = 0; i < var.size(); i++)
    {
        CComBSTR    bstr(var[i].c_str());
        array.SetAt((ULONG)i, bstr);
    }
    _variant_t  val;

    val.vt      = VT_ARRAY | array.GetType();
    val.parray  = array.m_psa;

    RETURNIF(obj->Put(name, 0, &val, 0));

    return  S_OK;
}

template<typename T>
static
HRESULT WMIPutClass(
            IWbemServices*      srv,
            IWbemClassObject*   obj,
            BSTR                name,
            std::vector<T>&     var)
{
    std::vector<CComPtr<IWbemClassObject> > objects;
    CComPtr<IWbemClassObject>               root;

    srv->GetObject(T::_typename(), 0, NULL, &root.p, NULL);

    for(size_t i = 0; i < var.size(); i++)
    {
        CComPtr<IWbemClassObject>               object;
        root->SpawnInstance(0, &object.p);
        objects.push_back(object);

        RETURNIF(WMIPutClass(srv, object, NULL, var[i]));
    }

    RETURNIF(WMIPut<1>(srv, obj, name, objects));

    return S_OK;
}

//  WMIPut  -----------------------------------------------------------------
template<typename T>
static
HRESULT  WMIPutClass(    IWbemServices*      srv,
                        IWbemClassObject*   obj,
                        BSTR                name,
                        BSTR                type,
                        std::vector<T>&     var)
{
    CComSafeArray<IUnknown*, VT_UNKNOWN>    array(var.size());
    CComPtr<IWbemClassObject>               root;
    std::vector<CComPtr<IWbemClassObject> > objects;

    ASSERT(srv);

    srv->GetObject(type, 0, NULL, &root.p, NULL);               ASSERT(root);

    for(size_t i = 0; i < var.size(); i++)
    {
        CComPtr<IWbemClassObject>           chld;
        root->SpawnInstance(0, &chld.p);

        objects.push_back(chld);
        WMIPutClass(srv, chld, NULL, type, var[i]);

        _variant_t  var;
        var.vt      = VT_UNKNOWN;
        chld.QueryInterface(IID_IWbemClassObject, &var.punkVal);

        array.SetAt(i, var[i]);
    }

    _variant_t  var;
    var.vt      = VT_ARRAY;
    var.parray  = &array.m_psa;

    obj->Put(name, 0, &var, CIM_OBJECT | CIM_FLAG_ARRAY);

    return  S_OK;
}

//  WMIGetMember    ---------------------------------------------------------
static
HRESULT WMIGetMember(
                        IWbemServices*              srv,
                        IWbemClassObject*           root,
                        CComPtr<IWbemClassObject>&  embedded,
                        BSTR                        name,
                        BSTR                        type)
{
    if(name)
    {
        _variant_t  var;

        ASSERT(root);

        RETURNIF(root->Get(name, 0, &var, NULL, NULL));
        if(var.vt != VT_NULL)
            RETURNIF(var.punkVal->QueryInterface(IID_IWbemClassObject, (void**)&embedded.p));
        else
            return  E_INVALIDARG;
    }
    else
    {
        embedded    = root;
    }

    return  S_OK;
}

//  WMIGetMember    ---------------------------------------------------------
static
HRESULT WMIPutMember(
                        IWbemServices*              srv,
                        IWbemClassObject**           root,
                        BSTR                        type)
{
	HRESULT hr = WBEM_S_NO_ERROR;

    CComPtr<IWbemClassObject>   spClass;

    ASSERT(srv);

    RETURNIF(srv->GetObject(type, 0, NULL, &spClass.p, NULL));   ASSERT(spClass);
    RETURNIF(spClass->SpawnInstance(0, root));            ASSERT(root);

    return hr;
}

static
HRESULT WMIExecMethod(  IWbemServices*      srv,
                        BSTR                oname,
                        BSTR                mname,
                        IWbemClassObject*   iparam,
                        IWbemClassObject*&  oparam)
{
    HRESULT hr;
    hr  = srv->ExecMethod(oname, mname, 0, NULL, iparam, &oparam, NULL);

    if(hr == 0x800706bf)
    {
        hr  = srv->ExecMethod(oname, mname, 0, NULL, iparam, &oparam, NULL);
    }

    return  hr;
}

static
HRESULT WMIGetMethodOParams(
                        IWbemClassObject*   pOClass,
                        BSTR                name,
                        IWbemClassObject**  oparam)
{
    CComPtr<IWbemClassObject>   oParamClass;

    ASSERT(pOClass);

    RETURNIF(pOClass->GetMethod(name, 0, NULL, &oParamClass));  ASSERT(oParamClass);
    RETURNIF(oParamClass->SpawnInstance(0, oparam));            ASSERT(oparam);

    return  S_OK;
}
static
HRESULT WMIGetMethodIParams(
                        IWbemServices*      srv,
                        IWbemClassObject*   pOClass,
                        BSTR                name,
                        IWbemClassObject**  iparam)
{
    CComPtr<IWbemClassObject>   iParamClass;

    ASSERT(pOClass);

    RETURNIF(pOClass->GetMethod(name, 0, &iParamClass.p, NULL));
    RETURNIF(iParamClass->SpawnInstance(0, iparam));            ASSERT(iparam);

    return  S_OK;
}

#define WbemServicesEmptyBODY   {return WBEM_E_NOT_SUPPORTED;}
class   WbemServicesEmpty
    : public IWbemServices
{
    public:
        STDMETHOD(OpenNamespace)(
            const BSTR                              strNamespace,
            long                                    lFlags,
            IWbemContext __RPC_FAR*                 pCtx,
            IWbemServices __RPC_FAR *__RPC_FAR*     ppWorkingNamespace,
            IWbemCallResult __RPC_FAR *__RPC_FAR*   ppResult)           {return WBEM_E_NOT_SUPPORTED;}
        STDMETHOD(CancelAsyncCall)(
            IWbemObjectSink __RPC_FAR *             pSink)              {return WBEM_E_NOT_SUPPORTED;}
        STDMETHOD(QueryObjectSink)(
            long                                    lFlags,
            IWbemObjectSink __RPC_FAR *__RPC_FAR *  ppResponseHandler)  {return WBEM_E_NOT_SUPPORTED;}

        STDMETHOD(GetObject)(
            const BSTR                              strObjectPath,
            long                                    lFlags,
            IWbemContext __RPC_FAR*                 pCtx,
            IWbemClassObject __RPC_FAR *__RPC_FAR *ppObject,
            IWbemCallResult __RPC_FAR *__RPC_FAR*   ppCallResult)       {return WBEM_E_NOT_SUPPORTED;}
        STDMETHOD(GetObjectAsync)(
            const BSTR                              strObjectPath,
            long                                    lFlags,
            IWbemContext __RPC_FAR*                 pCtx,
            IWbemObjectSink __RPC_FAR*              pResponseHandler)   {return WBEM_E_NOT_SUPPORTED;}
        STDMETHOD(PutClass)(
            IWbemClassObject __RPC_FAR*             pObject,
            long                                    lFlags,
            IWbemContext __RPC_FAR*                 pCtx,
            IWbemCallResult __RPC_FAR *__RPC_FAR*   ppCallResult)       {return WBEM_E_NOT_SUPPORTED;}

        STDMETHOD(PutClassAsync)(
            IWbemClassObject __RPC_FAR*             pObject,
            long                                    lFlags,
            IWbemContext __RPC_FAR*                 pCtx,
            IWbemObjectSink __RPC_FAR*              pResponseHandler)   {return WBEM_E_NOT_SUPPORTED;}

        STDMETHOD(DeleteClass)(
            const BSTR strClass,
            long                                    lFlags,
            IWbemContext __RPC_FAR*                 pCtx,
            IWbemCallResult __RPC_FAR *__RPC_FAR*   ppCallResult)       {return WBEM_E_NOT_SUPPORTED;}

        STDMETHOD(DeleteClassAsync)(
            const BSTR strClass,
            long                                    lFlags,
            IWbemContext __RPC_FAR*                 pCtx,
            IWbemObjectSink __RPC_FAR*              pResponseHandler)   {return WBEM_E_NOT_SUPPORTED;}

        STDMETHOD(CreateClassEnum)(
            const BSTR strSuperclass,
            long                                    lFlags,
            IWbemContext __RPC_FAR*                 pCtx,
            IEnumWbemClassObject __RPC_FAR *__RPC_FAR *ppEnum)          {return WBEM_E_NOT_SUPPORTED;}

        STDMETHOD(CreateClassEnumAsync)(
            const BSTR strSuperclass,
            long                                    lFlags,
            IWbemContext __RPC_FAR*                 pCtx,
            IWbemObjectSink __RPC_FAR*              pResponseHandler)   {return WBEM_E_NOT_SUPPORTED;}

        STDMETHOD(PutInstance)(
            IWbemClassObject __RPC_FAR *pInst,
            long                                    lFlags,
            IWbemContext __RPC_FAR*                 pCtx,
            IWbemCallResult __RPC_FAR *__RPC_FAR*   ppCallResult)       {return WBEM_E_NOT_SUPPORTED;}

        STDMETHOD(PutInstanceAsync)(
            IWbemClassObject __RPC_FAR *pInst,
            long                                    lFlags,
            IWbemContext __RPC_FAR*                 pCtx,
            IWbemObjectSink __RPC_FAR*              pResponseHandler)   {return WBEM_E_NOT_SUPPORTED;}

        STDMETHOD(DeleteInstance)(
            const BSTR                              strObjectPath,
            long                                    lFlags,
            IWbemContext __RPC_FAR*                 pCtx,
            IWbemCallResult __RPC_FAR *__RPC_FAR*   ppCallResult)       {return WBEM_E_NOT_SUPPORTED;}

        STDMETHOD(DeleteInstanceAsync)(
            const BSTR                              strObjectPath,
            long                                    lFlags,
            IWbemContext __RPC_FAR*                 pCtx,
            IWbemObjectSink __RPC_FAR*              pResponseHandler)   {return WBEM_E_NOT_SUPPORTED;}

        STDMETHOD(CreateInstanceEnum)(
            const BSTR strClass,
            long                                    lFlags,
            IWbemContext __RPC_FAR*                 pCtx,
            IEnumWbemClassObject __RPC_FAR *__RPC_FAR*  ppEnum)         {return WBEM_E_NOT_SUPPORTED;}

        STDMETHOD(CreateInstanceEnumAsync)(
            const BSTR strClass,
            long                                    lFlags,
            IWbemContext __RPC_FAR*                 pCtx,
            IWbemObjectSink __RPC_FAR*              pResponseHandler)   {return WBEM_E_NOT_SUPPORTED;}

        STDMETHOD(ExecQuery)(
            const BSTR strQueryLanguage,
            const BSTR strQuery,
            long                                    lFlags,
            IWbemContext __RPC_FAR*                 pCtx,
            IEnumWbemClassObject __RPC_FAR *__RPC_FAR*  ppEnum)         {return WBEM_E_NOT_SUPPORTED;}

        STDMETHOD(ExecQueryAsync)(
            const BSTR strQueryLanguage,
            const BSTR strQuery,
            long                                    lFlags,
            IWbemContext __RPC_FAR*                 pCtx,
            IWbemObjectSink __RPC_FAR*              pResponseHandler)   {return WBEM_E_NOT_SUPPORTED;}

        STDMETHOD(ExecNotificationQuery)(
            const BSTR strQueryLanguage,
            const BSTR strQuery,
            long                                    lFlags,
            IWbemContext __RPC_FAR*                 pCtx,
            IEnumWbemClassObject __RPC_FAR *__RPC_FAR*  ppEnum)         {return WBEM_E_NOT_SUPPORTED;}

        STDMETHOD(ExecNotificationQueryAsync)(
            const BSTR strQueryLanguage,
            const BSTR strQuery,
            long                                    lFlags,
            IWbemContext __RPC_FAR*                 pCtx,
            IWbemObjectSink __RPC_FAR*              pResponseHandler)   {return WBEM_E_NOT_SUPPORTED;}

        STDMETHOD(ExecMethod)(
            const BSTR                              strObjectPath,
            const BSTR                              strMethodName,
            long                                    lFlags,
            IWbemContext __RPC_FAR*                 pCtx,
            IWbemClassObject __RPC_FAR*             pInParams,
            IWbemClassObject __RPC_FAR *__RPC_FAR*  ppOutParams,
            IWbemCallResult __RPC_FAR *__RPC_FAR*   ppCallResult)       {return WBEM_E_NOT_SUPPORTED;}

        STDMETHOD(ExecMethodAsync)(
            const BSTR                              strObjectPath,
            const BSTR                              strMethodName,
            long                                    lFlags,
            IWbemContext __RPC_FAR*                 pCtx,
            IWbemClassObject __RPC_FAR*             pInParams,
            IWbemObjectSink __RPC_FAR*              pResponseHandler)   {return WBEM_E_NOT_SUPPORTED;}
};

//  parser  -----------------------------------------------------------------
template<typename T>
std::wistream&  operator>>(std::wistream& str, std::vector<T>& data)
{
    match(str, '{');
    do
    {
        T   temp;

        str >> std::ws >> temp >> std::ws;

        data.push_back(temp);

        if(str.peek() == '}')
            break;
    }
    while(1);

    match(str, '}');

    return  str;
}

static
std::wistream& match(std::wistream& stream, wchar_t chr)
{
    std::ws(stream);

    wchar_t next;

    stream >> next;

    if(next != chr)
    {
		//do something!

    }

    return  stream;
}

static
std::wistream& operator>>(std::wistream& stream, unsigned char& data)
{
    std::ws(stream);
	data	= 0x00;
    while(!stream.eof() && stream.peek() != ' ')
    {
        int temp;
        temp    = stream.get();

        if(stream.eof())
            break;

        data    = data * 10 + temp - '0';
    }
    return  stream;
}

static
std::wistream& operator>>(std::wistream& stream, std::wstring& data)
{
    std::ws(stream);
    if(stream.peek() == L'\'')

    {
        wchar_t chr;
        stream >> chr;
        std::getline(stream, data, L'\'');
    }
    else if(stream.peek() == '\"')
    {
        wchar_t chr;
        stream >> chr;
        std::getline(stream, data, L'\"');
    }
    else
    {
        std::getline(stream, data, L' ');
    }

    return  stream;
}

//  printer -----------------------------------------------------------------
template<typename T>
std::wostream& operator<<(std::wostream& stream, const std::vector<T>& data)
{
    std::wstring    prefix  = L"";
    stream << L"{";

    for(size_t i = 0; i < data.size(); i++)
    {
        stream << prefix << data[i];

        prefix  = L" ";
    }

    stream << L"}";

    return  stream;
}

inline
std::wostream&   operator<<(std::wostream& stream, uint8 data)
{
    stream  << std::dec << (int)data;
    return  stream;
}

//  cli stuff   -------------------------------------------------------------
static
HRESULT         ProcessObjectPath(
                            const wchar_t*      member,
                            std::wstring&       root,
                            std::wstring&       tail,
                            long&               index)
{
    const wchar_t*  dot     = wcschr(member, L'.');
    const wchar_t*  open    = wcschr(member, L'[');

    root    = member;
    index   = -1;
    tail    = L"";

    if(dot == NULL)
        return  S_OK;;

    root    = member;
    tail.assign(dot + 1);
    index   = -1;

    if(open && open < dot && *(dot - 1) == ']')
    {
        root.assign(member, open - member);
        index   = _wtoi(std::wstring(open + 1, dot - open - 1).c_str());
    }
    else
    {
        root.assign(member, dot - member);
    }

    return  S_OK;
}

//  SetMember   -------------------------------------------------------------
template<typename T>
static
HRESULT         SetMember(  std::vector<T>& data,
                            unsigned long   index,
                            const wchar_t*  member,
                            const wchar_t*  value)
{
    T*              it;

    if(!_wcsicmp(value, L"new"))
    {
        data.push_back(T());
        return  S_OK;
    }

    if(!_wcsicmp(value, L"clear"))
    {
        data.clear();
        return  S_OK;
    }

    if((index != -1) && index >= data.size() || data.empty())
    {
        data.push_back(T());
        it  = &data.back();
    }
    else if(index == -1)
        it  = &data.back();
    else
        it  = &data.at(index);

    SetMember(*it, member, value);

    return  S_OK;
}

//  GetMember   -------------------------------------------------------------
template<typename T>
static
HRESULT         GetMember(  std::vector<T>& data,
                            unsigned long   index,
                            const wchar_t*  member,
                            std::wstring&   value)
{
    T*              it;

    if((index == -1 || index >= data.size()) && !data.empty())
    {
        it  = &data.back();
    }
    else if(!data.empty())
        it  = &data.at(index);
    else
    {
        value   = L"";
        return  S_OK;
    }

    GetMember(*it, member, value);

    return  S_OK;
}


template<typename T>
HRESULT     SetValue(T& member, const wchar_t* value)
{
    unsigned long   temp;
    swscanf_s(value, L"%i", &temp);
    member  = (T)temp;
    return  S_OK;
}

static
HRESULT     SetValue(std::wstring& member, const wchar_t* value)
{
    member  = value;
    return  S_OK;
}

template<typename T>
HRESULT     GetValue(T& member, std::wstring& value)
{
    wchar_t temp[128];

    swprintf_s(temp, sizeof(temp) / sizeof(temp[0]), L"%d", member);
    value   = temp;
    return  S_OK;
}

static
HRESULT     GetValue(std::wstring& member, std::wstring& value)
{
    value   = member;
    return  S_OK;
}

static
HRESULT     GetKeysList(std::map <std::wstring, CComVariant>&keyList, const std::wstring& strClass)
{

	HRESULT hr = WBEM_E_PROVIDER_FAILURE;
	try {
		CComPtr<IWbemPath>pParser;
			hr = CoCreateInstance(CLSID_WbemDefPath,
			0,
			CLSCTX_INPROC_SERVER,
			IID_IWbemPath,
			(LPVOID *)&pParser);
		// -- do something
		if (FAILED(hr))
		{
			return hr;
		}
		pParser->SetText(WBEMPATH_CREATE_ACCEPT_ALL,strClass.c_str());
		wchar_t className [256];
		unsigned long size = 256;
		pParser->GetClassName(&size,className);

	CComPtr<IWbemPathKeyList> pIKeyList;
	hr = pParser->GetKeyList(&pIKeyList);
	if (FAILED(hr))
	{
		return hr;
	}
	unsigned long ulNumKeys;
	hr = pIKeyList->GetCount(&ulNumKeys);

	if(FAILED(hr))
	{
		return hr;
	}
		//Get values of key properties
	unsigned long uKeyNameBufferSize = 256;//strClass + 1;
	WCHAR  * wKeyName = new WCHAR[uKeyNameBufferSize];
	if (NULL == wKeyName)
	{
		return WBEM_E_OUT_OF_MEMORY;
	}
	CComVariant vValue;
	unsigned long ulApparentCimType;
	for (unsigned long i = 0; i < ulNumKeys; i++)
	{
		uKeyNameBufferSize = 256;
		hr = pIKeyList->GetKey2(i, 0L, &uKeyNameBufferSize,
								wKeyName, &vValue, &ulApparentCimType);
		keyList[wKeyName] = vValue;
		//TODO: save vValue for later use
	}

	delete[] wKeyName;
	}
	catch (...)
	{
		UNS_ERROR("%C Bad catch", __FUNCTION__);
	}
	return hr;
}
static HRESULT WMIHandleSetStatus(IWbemServices* pNamespace,IWbemObjectSink  __RPC_FAR* pResponseHandler,unsigned long hrInput)
{
	try
	{
		if (hrInput == STATUS_SUCCESS)
		{
			pResponseHandler->SetStatus(WBEM_STATUS_COMPLETE, hrInput,NULL, NULL);
			return S_OK;
		}
		// not ok.
		CComPtr<IWbemClassObject> obj;
		do
		{
			HRESULT  hr;
			RETURNIF(WMIPutMember(pNamespace, &obj, L"__ExtendedStatus"));
			std::wstringstream str;
			str << L"Function failed with return code = " << hrInput << std::endl;
			BREAKIF(WMIPut<1>(obj, L"Description", str.str()));
			uint32 xx = hrInput;
			BREAKIF(WMIPut<1>(obj, L"StatusCode",xx));
		}
		while(0);
		pResponseHandler->SetStatus(WBEM_STATUS_COMPLETE, WBEM_E_PROVIDER_FAILURE,L"Error", obj);
		UNS_ERROR("Function failed with return code = %u\n", hrInput);
	}
	catch (...)
	{
		UNS_ERROR("%C Bad catch", __FUNCTION__);
	}
	return S_OK;
}

#endif
