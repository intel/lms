/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2003-2024 Intel Corporation
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
	UNS_ERROR("Bad WMI param %d\n", hr); \
	break; }

#define RETURNIF(exp)                                                       \
    do{                                                                     \
        HRESULT hr = exp;                                                   \
        if(hr != S_OK)                                                      \
        {                                                                   \
			UNS_ERROR("Bad WMI param %d\n", hr);                            \
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
HRESULT  WMIGetClass(   IWbemServices*      srv,
                        IWbemClassObject*   obj,
                        LPCWSTR             name,
                        T&                  var)
{
    return  E_FAIL;
}


//  WMIGet  -----------------------------------------------------------------
template<bool log, typename T>
HRESULT WMIGet(IWbemServices*      srv,
			   IWbemClassObject*   obj,
			   LPCWSTR             name,
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
HRESULT WMIGet(IWbemServices*      srv,
			   IWbemClassObject*   obj,
			   LPCWSTR             name,
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
HRESULT WMIGetArrayElement(SAFEARRAY* array, long index, T& elem)
{
    SafeArrayGetElement(array, &index, (void*)&elem);

    return  S_OK;
}

template<>
inline HRESULT WMIGetArrayElement(SAFEARRAY* array, long index, std::wstring& elem)
{
    BSTR    str;
    SafeArrayGetElement(array, &index, &str);

    elem    = str;

    return  S_OK;
}

//  WMIGet  -----------------------------------------------------------------
template<bool log, typename T>
HRESULT  WMIGet(        IWbemServices*      srv,
                        IWbemClassObject*   obj,
                        LPCWSTR             name,
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
HRESULT  WMIGetClass(   IWbemServices*      srv,
                        IWbemClassObject*   obj,
                        LPCWSTR             name,
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

template<>
HRESULT  WMIGetClass(
    IWbemServices*             srv,
    IWbemClassObject*          obj,
    LPCWSTR                    name,
    std::vector<std::wstring>& vec);

//  Validate    --------------------------------------------------------------
template<typename T>
void    Validate(       T&                  var)
{
}

template<typename T>
void    Validate(       std::vector<T>&     var)
{
    for(size_t i = 0; i < var.size(); i++)
        Validate(var[i]);
}

//  WMIPut  -----------------------------------------------------------------
template<typename T>
HRESULT  WMIPutClass(   IWbemServices*      srv,
                        IWbemClassObject*   obj,
                        LPCWSTR             name,
                        T&                  var)
{
    return  E_FAIL;
}

//  WMIPut  -----------------------------------------------------------------
template<bool log, typename T>
HRESULT  WMIPut(        IWbemClassObject*   obj,
                        LPCWSTR             name,
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
HRESULT WMIPut(IWbemClassObject* obj, LPCWSTR name, std::wstring& var);

//  WMIPut  -----------------------------------------------------------------
template<typename T>
HRESULT  WMIPut(
                        IWbemClassObject*   obj,
                        LPCWSTR             name,
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
HRESULT  WMIPut(        
                        IWbemClassObject*           obj,
                        LPCWSTR                     name,
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
HRESULT WMIPutClass(
            IWbemServices*      srv,
            IWbemClassObject*   obj,
            LPCWSTR             name,
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
HRESULT  WMIPutClass(    IWbemServices*      srv,
                        IWbemClassObject*   obj,
                        LPCWSTR             name,
                        LPCWSTR             type,
                        std::vector<T>&     var)
{
    CComSafeArray<IUnknown*, VT_UNKNOWN>    array(var.size());
    CComPtr<IWbemClassObject>               root;
    std::vector<CComPtr<IWbemClassObject> > objects;

    ASSERT(srv);

    srv->GetObject(CComBSTR(type), 0, NULL, &root.p, NULL);               ASSERT(root);

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
HRESULT WMIGetMember(
    IWbemServices*              srv,
    IWbemClassObject*           root,
    CComPtr<IWbemClassObject>&  embedded,
    LPCWSTR                     name,
    LPCWSTR                     type);

//  WMIGetMember    ---------------------------------------------------------
HRESULT WMIPutMember(
    IWbemServices*     srv,
    IWbemClassObject** root,
    LPCWSTR            type);

HRESULT WMIGetMethodOParams(
    IWbemClassObject*  pOClass,
    LPCWSTR            name,
    IWbemClassObject** oparam);

HRESULT WMIGetMethodIParams(
    IWbemServices* srv,
    IWbemClassObject*  pOClass,
    LPCWSTR            name,
    IWbemClassObject** iparam);

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

inline
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

inline
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

inline
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

HRESULT ProcessObjectPath(
    const wchar_t* member,
    std::wstring& root,
    std::wstring& tail,
    long& index);

//  SetMember   -------------------------------------------------------------
template<typename T>
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

template<>
inline HRESULT SetValue<>(std::wstring& member, const wchar_t* value)
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

template<>
inline HRESULT GetValue(std::wstring& member, std::wstring& value)
{
    value   = member;
    return  S_OK;
}

HRESULT GetKeysList(std::map <std::wstring, CComVariant>& keyList, const std::wstring& strClass);
HRESULT WMIHandleSetStatus(IWbemServices* pNamespace, IWbemObjectSink  __RPC_FAR* pResponseHandler, unsigned long hrInput);

#endif
