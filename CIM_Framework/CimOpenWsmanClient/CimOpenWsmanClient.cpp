//----------------------------------------------------------------------------
//
// Copyright (c) 2003 - 2021 Intel Corporation  All Rights Reserved.
//
//  File:       CimOpenWsmanClient.cpp
//
//  Contents:   An implementation of the ICimWsmanClient interface using openwsman
//
//----------------------------------------------------------------------------

#include <string.h>
#include "CimException.h"
#include "CimOpenWsmanClient.h"
#include "OpenWsmanClient.h"
#include "WsmanEPR.h"
#include "WsmanFilter.h"

using namespace std;

namespace Intel
{
	namespace WSManagement
	{
		using WsmanExceptionNamespace::GeneralWsmanException;
		using Intel::Manageability::Exceptions::WSManException;
		using Intel::Manageability::Exceptions::HTTPException;


		// Construct from params.
		CimOpenWsmanClient::CimOpenWsmanClient(const string& host,
			const int port,
			bool secure,
			AuthMethod auth_method,
			const string& username,
			const string& password,
			// search for a client proxy address include proxy port
			const string& proxy,
			// search for a client proxy user name
			const string& proxy_username,
			// search for a client proxy password
			const string proxy_password,
			// determines which cert store to search
			const bool local,
			// search for a client cert with this name
			const string& cert,
			// search for a client cert with this oid
			const string &oid

		)
			: cl(NULL)
		{
			connection.authmethod = auth_method;
			connection.host = host;
			connection.port = port;
			connection.username = username;
			connection.password = password;
			connection.secure = secure;
			connection.certificate = cert;
			connection.local = local;
			connection.oid = oid;
			connection.proxy_host = proxy;
			connection.proxy_user = proxy_username;
			connection.proxy_password = proxy_password;

			OpenConnection();
		}


		CimOpenWsmanClient::CimOpenWsmanClient(const ConnectionInfo &Connection)
			: cl(NULL),
			  connection(Connection)
		{
			OpenConnection();
		}

		void CimOpenWsmanClient::OpenConnection()
		{
			try
			{
				cl = new OpenWsmanClient(connection.host,
					connection.port,
					"/wsman",
					connection.secure ? "https" : "http",
					connection.authmethod == DIGEST ? "digest" : "gss",
					connection.username,
					connection.password,
					connection.proxy_host,
					connection.proxy_user,
					connection.proxy_password
#ifdef WIN32
					,
					connection.local,
					connection.certificate,
					connection.oid
#endif // WIN32
				);
				cl->AllowSelfSignedServerCert();
			}
			catch (GeneralWsmanException& ex)
			{
				WSManException ex1(ex.what());
				throw ex1;
			}


		}

		// Destructor.
		CimOpenWsmanClient::~CimOpenWsmanClient()
		{
			if (cl != NULL)
			{
				delete cl;
			}
		}

		// ConnectionInfo
		ConnectionInfo CimOpenWsmanClient::Connection() const
		{
			return connection;
		}

		// Creates a new instance of a resource.
		string CimOpenWsmanClient::Create(const string& resourceUri, const string& data) const
		{
			string ret;
			try
			{
				ret = cl->Create(resourceUri, data);
			}
			catch (WsmanSoapFault& ex)
			{
				string exStirng = ex.GetFaultReason().empty() ? "" : ex.GetFaultReason();
				exStirng += ex.GetFaultDetail().empty() ? "" : ("\n" + ex.GetFaultDetail());
				WSManException ex1(exStirng);
				throw ex1;
			}
			catch (WsmanClientException& ex)
			{
				HTTPException ex1(ex.what());
				throw ex1;
			}
			return ret;
		}

		// Identify.
		string CimOpenWsmanClient::Identify() const
		{
			return cl->Identify();
		}

		// Delete a resource.
		void CimOpenWsmanClient::Delete(const string& resourceUri, const NameValuePairs* s) const
		{
			try
			{
				cl->Delete(resourceUri, s);
			}
			catch (WsmanSoapFault& ex)
			{
				string exStirng = ex.GetFaultReason().empty() ? "" : ex.GetFaultReason();
				exStirng += ex.GetFaultDetail().empty() ? "" : ("\n" + ex.GetFaultDetail());
				WSManException ex1(exStirng);
				throw ex1;
			}
			catch (WsmanClientException& ex)
			{
				HTTPException ex1(ex.what());
				throw ex1;
			}
		}

		// Enumerate resource.
		void CimOpenWsmanClient::Enumerate(const string& resourceUri, vector<string>& enumRes, const NameValuePairs* s) const
		{
			try
			{
				cl->Enumerate(resourceUri, enumRes, s);
			}
			catch (WsmanSoapFault& ex)
			{
				string exStirng = ex.GetFaultReason().empty() ? "" : ex.GetFaultReason();
				exStirng += ex.GetFaultDetail().empty() ? "" : ("\n" + ex.GetFaultDetail());
				WSManException ex1(exStirng);
				throw ex1;
			}
			catch (WsmanClientException& ex)
			{
				HTTPException ex1(ex.what());
				throw ex1;
			}
		}

		// Retrieve a resource.
		string CimOpenWsmanClient::Get(const string& resourceUri, const NameValuePairs* s) const
		{
			string ret;
			try
			{
				ret = cl->GetWithFlags(resourceUri, s, FLAG_SUPRESS_100_CONTINUE);
			}
			catch (WsmanSoapFault& ex)
			{
				string exStirng = ex.GetFaultReason().empty() ? "" : ex.GetFaultReason();
				exStirng += ex.GetFaultDetail().empty() ? "" : ("\n" + ex.GetFaultDetail());
				WSManException ex1(exStirng);
				throw ex1;
			}
			catch (WsmanClientException& ex)
			{
				HTTPException ex1(ex.what());
				throw ex1;
			}
			return ret;
		}

		// Update a resource.
		string CimOpenWsmanClient::Put(const string& resourceUri, const string& content, const NameValuePairs* s) const
		{
			string ret;
			try
			{
				ret = cl->PutWithFlags(resourceUri, content, s, FLAG_SUPRESS_100_CONTINUE);
			}
			catch (WsmanSoapFault& ex)
			{
				string exStirng = ex.GetFaultReason().empty() ? "" : ex.GetFaultReason();
				exStirng += ex.GetFaultDetail().empty() ? "" : ("\n" + ex.GetFaultDetail());
				WSManException ex1(exStirng);
				throw ex1;
			}
			catch (WsmanClientException& ex)
			{
				HTTPException ex1(ex.what());
				throw ex1;
			}
			return ret;
		}

		// Invokes a method and returns the results of the method call.
		string CimOpenWsmanClient::Invoke(const string& resourceUri, const string& methodName, const string& content, const NameValuePairs* s) const
		{
			string ret;
			try
			{
				WsmanOptions options(FLAG_SUPRESS_100_CONTINUE);
				options.setNamespace(cl->GetNamespace());
				options.addSelectors(s);
				ret = cl->Invoke(resourceUri, methodName, content, options);
			}
			catch (WsmanSoapFault& ex)
			{
				string exStirng = ex.GetFaultReason().empty() ? "" : ex.GetFaultReason();
				exStirng += ex.GetFaultDetail().empty() ? "" : ("\n" + ex.GetFaultDetail());
				WSManException ex1(exStirng);
				throw ex1;
			}
			catch (WsmanClientException& ex)
			{
				HTTPException ex1(ex.what());
				throw ex1;
			}
			return ret;

		}

		// Submit a subscription
		string CimOpenWsmanClient::Subscribe(const string& resourceUri, const SubscribeInfo& info, string& identifier) const
		{
			WsmanClientNamespace::SubscribeInfo wsInfo;
			wsInfo.filter = info.filter;
			wsInfo.dialect = info.dialect;
			wsInfo.delivery_uri = info.delivery_uri;
			wsInfo.delivery_mode = (WsmanClientNamespace::NotificationDeliveryMode) info.delivery_mode;
			wsInfo.selectorset = info.selectorset;
			wsInfo.heartbeat_interval = info.heartbeat_interval;
			wsInfo.expires = info.expires;

			return cl->Subscribe(resourceUri, wsInfo, identifier);
		}

		// "Special" Enumerate
		void CimOpenWsmanClient::Enumerate(vector<string>& enumRes, const EnumerateFilter& filter) const
		{
			string enumerateURI = "http://schemas.dmtf.org/wbem/wscim/1/*";
			WsmanAssocType assocType;
			string assocClass;
			string resultClass;
			string role;
			string resultRole;
			vector<string> resultProp;

			CimReference tempReference = filter.reference;
			WsmanEPR epr(tempReference.ResourceURI(), tempReference.Address());
			WsManSelectors::const_iterator iter;
			WsManSelectors tempSelectors = tempReference.Selectors();
			NameValuePairs nvp;
			for (iter = tempSelectors.begin(); iter != tempSelectors.end(); iter++)
			{
				epr.addTextSelector(iter->first, iter->second);
				nvp.insert(pair<string, string>(iter->first, iter->second));
			}

			WsmanOptions opts(FLAG_NONE);

			try
			{

				if (filter.assocType == Intel::WSManagement::EnumerateFilter::AllInstances)
				{
					cl->Enumerate(filter.reference.ResourceURI(), enumRes, &nvp);
				}
				else
				{
					// Enumerate associations
					assocType = (filter.assocType == Intel::WSManagement::EnumerateFilter::AssociatedInstance ? WSMAN_ASSOCIATED : WSMAN_ASSOCIATOR);
					assocClass = filter.associationClass;
					resultClass = filter.resultClass;
					role = filter.role;
					resultRole = filter.resultRole;
					resultProp = filter.resultProperties;

					WsmanFilter wsman_filter(epr, assocType, assocClass, resultClass, role, resultRole, resultProp);
					cl->Enumerate(enumerateURI, enumRes, opts, wsman_filter);
				}
			}
			catch (WsmanSoapFault& ex)
			{
				WSManException ex1(ex.GetFaultReason());
				throw ex1;
			}
			catch (WsmanClientException& ex)
			{
				HTTPException ex1(ex.what());
				throw ex1;
			}
		}

		// "Special" Enumerate of references
		void CimOpenWsmanClient::EnumerateRef(vector<string>& enumRes, const EnumerateFilter& filter) const
		{
			string enumerateURI = "http://schemas.dmtf.org/wbem/wscim/1/*";
			WsmanAssocType assocType;
			string assocClass;
			string resultClass;
			string role;
			string resultRole;
			vector<string> resultProp;

			CimReference tempReference = filter.reference;
			WsmanEPR epr(tempReference.ResourceURI(), tempReference.Address());
			WsManSelectors::const_iterator iter;
			WsManSelectors tempSelectors = tempReference.Selectors();
			NameValuePairs nvp;
			for (iter = tempSelectors.begin(); iter != tempSelectors.end(); iter++)
			{
				epr.addTextSelector(iter->first, iter->second);
				nvp.insert(pair<string, string>(iter->first, iter->second));
			}


			WsmanOptions opts(FLAG_ENUMERATION_ENUM_EPR);

			try
			{
				if (filter.assocType == Intel::WSManagement::EnumerateFilter::AllInstances)
				{
					WsmanFilter empty_filter;
					cl->Enumerate(filter.reference.ResourceURI(), enumRes, opts, empty_filter);
				}
				else
				{
					// Enumerate associations
					assocType = (filter.assocType == Intel::WSManagement::EnumerateFilter::AssociatedInstance ? WSMAN_ASSOCIATED : WSMAN_ASSOCIATOR);
					assocClass = filter.associationClass;
					resultClass = filter.resultClass;
					role = filter.role;
					resultRole = filter.resultRole;
					resultProp = filter.resultProperties;


					WsmanFilter wsman_filter(epr, assocType, assocClass, resultClass, role, resultRole, resultProp);
					cl->Enumerate(enumerateURI, enumRes, opts, wsman_filter);
				}
			}
			catch (WsmanSoapFault& ex)
			{
				WSManException ex1(ex.GetFaultReason());
				throw ex1;
			}
			catch (WsmanClientException& ex)
			{
				HTTPException ex1(ex.what());
				throw ex1;
			}



		}


		// Renew a subscription
		string CimOpenWsmanClient::Renew(const string& resourceUri, const string& identifier, float expire, const NameValuePairs* s) const
		{
			return cl->Renew(resourceUri, identifier, expire, s);
		}

		// Terminate a subscription
		void CimOpenWsmanClient::Unsubscribe(const string& resourceUri, const string& identifier, const NameValuePairs* s) const
		{
			cl->Unsubscribe(resourceUri, identifier, s);
		}

		// Set auth method
		void CimOpenWsmanClient::SetAuth(const char* auth_method)
		{
			connection.authmethod = (strcmp(auth_method, "digest") == 0) ? DIGEST : KERBEROS;
			cl->SetAuth(auth_method);
		}


		// Set user name
		void CimOpenWsmanClient::SetUserName(const char* user_name)
		{
			connection.username = user_name;
			cl->SetUserName(user_name);
		}

		// Set passsword
		void CimOpenWsmanClient::SetPassword(const char* password)
		{
			connection.password = password;
			cl->SetPassword(password);
		}

		// Set encoding
		void CimOpenWsmanClient::SetEncoding(const char* encoding)
		{
			cl->SetEncoding(encoding);
		}
		// Set CIM namespace
		void CimOpenWsmanClient::SetNamespace(const char* ns)
		{
			cl->SetNamespace(ns);
		}

#if defined (_WIN32) || defined (_WIN64)
		// Set client certificate params
		void CimOpenWsmanClient::SetClientCert(const char* caOid, const char* caName, const bool localCert)
		{
			connection.oid = caOid;
			connection.certificate = caName;
			connection.local = localCert;
			cl->SetClientCert(caOid, caName, localCert);
		}
		void CimOpenWsmanClient::SetProxy(const char* proxy, const char* proxy_username, const char* proxy_password)
		{
			connection.proxy_host = proxy;
			connection.proxy_user = proxy_username;
			connection.proxy_password = proxy_password;
			delete cl;
			cl = NULL;
			OpenConnection();
			//cl->SetProxy(false,proxy, proxy_username, proxy_password);
		}

#else
		// Set server certificate params
		void CimOpenWsmanClient::SetServerCert(const char* cainfo, const char* capath)
		{
			cl->SetServerCert(cainfo, capath);
		}

		// Set client certificates params
		void CimOpenWsmanClient::SetClientCert(const char* cert, const char* key)
		{
			cl->SetClientCert(cert, key);
		}
#endif

	} // namespace WSManagement
} // namespace Intel

