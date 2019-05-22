//----------------------------------------------------------------------------
//
// Copyright (c) 2003 - 2018 Intel Corporation  All Rights Reserved.
//
//  File:       CimWsman.h
//
//  Contents:   Library independent interface to WS-Management transport
//
//----------------------------------------------------------------------------

#ifndef _CIMWSMAN_H
#define _CIMWSMAN_H 1

#include "CimBasicNamespaces.h"
#include "NameValuePairs.h"
#include "CimReference.h"

namespace Intel
{
namespace WSManagement
{
	using std::string;
	using std::vector;
	using Intel::Manageability::Cim::CimReference;
	using Intel::Manageability::Cim::WsManSelectors;
	
	enum NotificationDeliveryMode {
		WSMAN_DELIVERY_PUSH = 0,
		WSMAN_DELIVERY_PUSHWITHACK,
		WSMAN_DELIVERY_EVENTS,
		WSMAN_DELIVERY_PULL
	};

	struct CIMUNTYPEDFRAMEWORK_API SubscribeInfo {
		string filter;
		string dialect;
		string delivery_uri;
		NotificationDeliveryMode delivery_mode;
		NameValuePairs *selectorset;
		float heartbeat_interval;
		float expires;

		SubscribeInfo();
		~SubscribeInfo();
	};

	enum AuthMethod {
		DIGEST,
		KERBEROS,
	};

	struct CIMUNTYPEDFRAMEWORK_API ConnectionInfo {
		AuthMethod authmethod;
		string certificate;
		bool local;
		string oid;
		string host;
		int port;

		string username;
		string password;
		
		string proxy_host;
		string proxy_user;
		string proxy_password;
		bool secure;

		ConnectionInfo();
		~ConnectionInfo();
	};

	struct CIMUNTYPEDFRAMEWORK_API EnumerateFilter {
		string dialect;
		string query;
		CimReference reference;  //for "http://schemas.dmtf.org/wsman/cimbinding/associationFilter"
		WsManSelectors selectorset;  //for "http://schemas.dmtf.org/wbem/wsman/1/wsman/SelectorFilter" dialect
		enum QueryType {
			AllInstances,
			AssociatedInstance,
			AssociationInstance,
		} assocType;
		string associationClass;
		string resultClass;
		string role;
		string resultRole;
		vector<string> resultProperties;

		EnumerateFilter();
		~EnumerateFilter();
	};
	
	enum EnumerateType {
		OBJECT_ONLY,
		EPR_ONLY,
		OBJECT_AND_EPR,
	};

	struct CIMUNTYPEDFRAMEWORK_API EnumerateOptions {
		EnumerateType type;
		EnumerateFilter filter;

		EnumerateOptions();
		~EnumerateOptions();
	};


	// Wsman Client Interface class
	class CIMUNTYPEDFRAMEWORK_API ICimWsmanClient
	{
	public:
		// Destructor.
		virtual ~ICimWsmanClient(){}

		// Connection Info
		virtual ConnectionInfo Connection() const = 0;

		// Identify
		virtual string Identify() const = 0;
		
		// Creates a new instance of a resource.
		virtual string Create(const string &resourceUri, const string &xmlData) const = 0;

		// Delete a resource.
		virtual void Delete(const string &resourceUri, const NameValuePairs *s = NULL) const = 0;

		// Enumerate a resource. 
		virtual void Enumerate(const string &resourceUri, vector<string> &enumRes, const NameValuePairs *s = NULL) const = 0;

		// Enumerate a resource. 
		virtual void Enumerate(vector<string> &enumRes, const EnumerateFilter &filter) const = 0;

		// Enumerate reference. 
		virtual void EnumerateRef(vector<string> &enumRes, const EnumerateFilter &filter) const = 0;

		// Retrieve a resource.
		virtual string Get(const string &resourceUri, const NameValuePairs *s = NULL) const = 0;

		// Update a resource.
		virtual string Put(const string &resourceUri, const string &content, const NameValuePairs *s = NULL) const = 0;

		// Invokes a method and returns the results of the method call.
		virtual string Invoke(const string &resourceUri, const string &methodName, const string &content, const NameValuePairs *s = NULL) const = 0;

		// Submit a subscription
		virtual string Subscribe(const string &resourceUri, const SubscribeInfo &info, string &identifier) const = 0;

		// Renew a subscription
		virtual string Renew(const string &resourceUri, const string &identifier, float expire, const NameValuePairs *s = NULL) const = 0;

		// Terminate a subscription
		virtual void Unsubscribe(const string &resourceUri, const string &identifier, const NameValuePairs *s = NULL) const = 0;
	
		// Set auth method
		virtual void SetAuth(const char *auth_method = "digest")= 0;

		// Set user name
		virtual void SetUserName(const char *user_name)= 0;

		// Set passsword
		virtual void SetPassword(const char *password)= 0;

		// Set encoding
		virtual void SetEncoding(const char *encoding)= 0;

		// Set CIM namespace
		virtual void SetNamespace(const char *ns)= 0;

	};
} // namespace WSManagement
} // namespace Intel
#endif
