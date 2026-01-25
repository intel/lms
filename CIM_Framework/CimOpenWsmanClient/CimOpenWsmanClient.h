//----------------------------------------------------------------------------
//
//  Copyright (C) Intel Corporation, 2007-2009
//
//  File:       CimOpenWsmanClient.h
//
//  Contents:   An implementation of the ICimWsmanClient interface using openwsman
//
//----------------------------------------------------------------------------

#ifndef __CIM_OPEN_WSMAN_CLIENT_H
#define __CIM_OPEN_WSMAN_CLIENT_H

#include "CimWsman.h"
//#include "openwsmanclient.h"

namespace WsmanClientNamespace {
	class OpenWsmanClient;
};

namespace Intel
{
	namespace WSManagement
	{
		using namespace WsmanClientNamespace;
		using Intel::Manageability::Cim::CimReference;
		using Intel::Manageability::Cim::WsManSelectors;

		class CimOpenWsmanClient : public ICimWsmanClient
		{
		private:
			OpenWsmanClient* cl;
			ConnectionInfo connection;
			// Copy constructor is declared private
			// operator = is declared private

			//setting connection fields
			void setHost(const string& host);
			void setPortNum(const int port);
			void setSecure(const bool secure);
			void setAuth(const AuthMethod auth_method);
			void setUserName(const string& user_name);
			void setPassword(const string& password);
			void setProxy(const string& proxy, const string& proxy_username, const string& roxy_password);
			void setClientCert(const string& caOid, const string& caName, const bool localCert);

			// validation for connection fields
			void validateHost(const string &host);
			void validatePortNum(int port);
			void validateUserName(const string& user_name);
			void validatePassword(const string& password);

			//validate client certificate params
			void validateClientCert(const string& caName);

			//validation for proxy params
			void validateProxy(const string& proxy, const string& proxy_username, const string& proxy_password);
			void validateProxyUsername(const string& user_name);
			void validateProxyPassword(const string& password);

			void OpenConnection(bool acceptSelfSignedCert = false);
		public:
			CimOpenWsmanClient(const CimOpenWsmanClient& cl) = delete;
			CimOpenWsmanClient& operator=(const CimOpenWsmanClient& other) = delete;
			// Construct from params.
			explicit CimOpenWsmanClient(const string& host = "localhost",
				const int port = 80,
				bool secure = false,
				AuthMethod auth_method = DIGEST,
				const string& username = "",
				const string& password = "",
				// search for a client proxy address include proxy port
				const string& proxy = "",
				// search for a client proxy user name
				const string& proxy_username = "",
				// search for a client proxy password
				const string proxy_password = "",
				// determines which cert store to search
				const bool local = false,
				// search for a client cert with this name
				const string& cert = "",
				// search for a client cert with this oid
				const string& oid = "",
				// accept self-signed certificate
				const bool acceptSelfSignedCert = false
			);

			explicit CimOpenWsmanClient(const ConnectionInfo& Connection, const bool acceptSelfSignedCert = false);

			// Destructor.
			virtual ~CimOpenWsmanClient();

			// ConnectionInfo
			virtual ConnectionInfo Connection() const;

			// Creates a new instance of a resource.
			virtual string Create(const string& resourceUri, const string& data) const;

			// Identify.
			virtual string Identify() const;

			// Delete a resource.
			virtual void Delete(const string& resourceUri, const NameValuePairs* s = NULL) const;

			// Enumerate resource.
			virtual void Enumerate(const string& resourceUri, vector<string>& enumRes, const NameValuePairs* s = NULL) const;

			// Enumerate a resource. 
			virtual void Enumerate(vector<string>& enumRes, const EnumerateFilter& filter) const;

			// Enumerate reference. 
			virtual void EnumerateRef(vector<string>& enumRes, const EnumerateFilter& filter) const;

			// Retrieve a resource.
			virtual string Get(const string& resourceUri, const NameValuePairs* s = NULL) const;

			// Update a resource.
			virtual string Put(const string& resourceUri, const string& content, const NameValuePairs* s = NULL) const;

			// Invokes a method and returns the results of the method call.
			virtual string Invoke(const string& resourceUri, const string& methodName, const string& content, const NameValuePairs* s = NULL) const;

			// Submit a subscription
			virtual string Subscribe(const string& resourceUri, const SubscribeInfo& info, string& identifier) const;

			// Renew a subscription
			virtual string Renew(const string& resourceUri, const string& identifier, float expire, const NameValuePairs* s = NULL) const;

			// Terminate a subscription
			virtual void Unsubscribe(const string& resourceUri, const string& identifier, const NameValuePairs* s = NULL) const;

			// Set auth method for existing client
			virtual void SetAuth(const char* auth_method = "digest");

			// Set user name for existing client
			virtual void SetUserName(const char* user_name);

			// Set passsword for existing client
			virtual void SetPassword(const char* password);

			// Set encoding for existing client
			virtual void SetEncoding(const char* encoding);

			// Set CIM namespace
			virtual void SetNamespace(const char* ns);

#if defined (_WIN32) || defined (_WIN64)

			// Set client certificate params
			void SetClientCert(const char* caOid = NULL, const char* caName = NULL, const bool localCert = false);
			void SetProxy(const char* proxy = NULL, const char* proxy_username = NULL, const char* proxy_password = NULL);
#else
			// Set server certificate params
			void SetServerCert(const char* cainfo = NULL, const char* capath = NULL);

			// Set client certificates params
			void SetClientCert(const char* cert, const char* key);
#endif
		};
	} // namespace WSManagement
} // namespace Intel
#endif
