/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2009-2024 Intel Corporation
 */
/*++

@file: AdapterListInfoLinux.cpp

--*/

#include "AdapterListInfo.h"
#include "global.h"


#include <netlink/route/addr.h>
#include <resolv.h>
#include <sys/socket.h>

#include <vector>

std::mutex AdapterListInfo::_localDNSLock;
std::mutex AdapterListInfo::_initLock;
SuffixMap AdapterListInfo::_localDNSSuffixes;
SuffixMap AdapterListInfo::_copyOfLocalDNSSuffixes;
ACE_thread_t AdapterListInfo::_thread = 0;
AdapterCallback AdapterListInfo::_cb = NULL;

class SelectAlarm
{
public:
	SelectAlarm()
	{
		if (pipe(_pipefd) == -1) {
			_pipefd[0] = -1;
			_pipefd[1] = -1;
		}
	}
	~SelectAlarm()
	{
		if (_pipefd[0] != -1)
			close(_pipefd[0]);
		if (_pipefd[1] != -1)
			close(_pipefd[1]);
	}
	SelectAlarm(const SelectAlarm&) = delete;
	SelectAlarm& operator = (const SelectAlarm&) = delete;
	int getFD() {return _pipefd[0];}
	int alarm()
	{
		char data = '0';
		return write(_pipefd[1], &data, 1);
	}
	int clean()
	{
		char data;
		return read(_pipefd[0], &data, 1);
	}
private:
	int _pipefd[2];
};
static SelectAlarm selectAlarm;

static ACE_THR_FUNC_RETURN _detectAddrChange(void *params)
{
	UNS_DEBUG(L"AdapterListInfo starting\n");
	struct nl_sock *sock;
	int ret;

	sock = nl_socket_alloc();
	if (!sock)
		return ACE_THR_FUNC_RETURN(-ENOMEM);
	ret = nl_connect(sock, NETLINK_ROUTE);
	if (ret) {
		UNS_ERROR(L"AdapterListInfo nl_connect failed %d\n", ret);
		goto out;
	}
	nl_socket_add_memberships(sock, RTNLGRP_LINK,
				  RTNLGRP_IPV4_NETCONF, RTNLGRP_IPV6_NETCONF,
				  RTNLGRP_IPV4_IFADDR, RTNLGRP_IPV6_IFADDR,
				  RTNLGRP_IPV4_ROUTE, RTNLGRP_IPV6_ROUTE,
				  RTNLGRP_IPV4_MROUTE, RTNLGRP_IPV6_MROUTE,
				  RTNLGRP_IPV4_RULE, RTNLGRP_IPV6_RULE,
				  RTNLGRP_IPV6_PREFIX,
				  0);
	nl_socket_set_nonblocking(sock);

	while (true) {
		int fdcount;
		fd_set fdset;
		int nlfd = nl_socket_get_fd(sock);
		int alfd = selectAlarm.getFD();

		FD_ZERO(&fdset);
		FD_SET(alfd, &fdset);
		FD_SET(nlfd, &fdset);
		fdcount = std::max(alfd, nlfd) + 1;

		ret = select(fdcount, &fdset, NULL, NULL, NULL);
		if (ret == -1) {
			UNS_ERROR(L"AdapterListInfo select failed %d\n", errno);
			break;
		} else {
			if (FD_ISSET(nlfd, &fdset)) {
				UNS_DEBUG(L"AdapterListInfo IP Address table changed...\n");
				nl_recvmsgs_default(sock);
			}
			if (FD_ISSET(selectAlarm.getFD(), &fdset)) {
				UNS_DEBUG(L"AdapterListInfo alarm...\n");
				selectAlarm.clean();
				break;
			}
		}
		AdapterListInfo::PerformUpdate(params);
	}
out:
	nl_socket_free(sock);
	UNS_DEBUG(L"AdapterListInfo closing\n");
	return 0;
}

bool AdapterListInfo::Init(AdapterCallback cb, void *params)
{
	std::lock_guard<std::mutex> l(_initLock);
	bool res;

	_cb = cb;

	if (!PerformUpdate(params))
		return false;

	if (!_thread) {
		res = (ACE_Thread::spawn(_detectAddrChange, params,
					 THR_NEW_LWP | THR_JOINABLE,
					 &_thread) == 0);
	} else {
		UNS_ERROR(L"AdapterListInfo we already have thread %u!\n", _thread);
		res = true;
	}

	return res;
}

void AdapterListInfo::Deinit()
{
	std::lock_guard<std::mutex> l(_initLock);

	if (!_thread)
		return;

	selectAlarm.alarm();
	ACE_Thread::join(_thread, NULL, NULL);
	_thread = 0;
}

#if !defined(USE_NM) && !defined(USE_CONNMAN)

int AdapterListInfo::UpdateAdapterListInfo()
{
	int result;

	struct nl_cache *addr_cache;
	struct nl_sock *sock;
	struct nl_object *obj;

	std::vector<std::string> domains;
	std::vector<std::string>::const_iterator domain;
	struct __res_state dns_state;
	res_ninit(&dns_state);
	for (int i = 0; i < MAXDNSRCH && dns_state.dnsrch[i]; i++)
		domains.push_back(dns_state.dnsrch[i]);
	domain = domains.cbegin();

	sock = nl_socket_alloc();
	if (!sock)
		return -ENOMEM;
	result = nl_connect(sock, NETLINK_ROUTE);
	if (result) {
		UNS_ERROR(L"AdapterListInfo nl_connect failed %d\n", result);
		goto out;
	}

	result = rtnl_addr_alloc_cache(sock, &addr_cache);
	if (result) {
		UNS_ERROR(L"AdapterListInfo rtnl_link_alloc_cache failed %d\n", result);
		goto out;
	}

	{
		std::lock_guard<std::mutex> l(_localDNSLock);
		_localDNSSuffixes.clear();

		obj = nl_cache_get_first(addr_cache);
		while (obj) {
			std::string localDnsSuffixStr = "";
			struct rtnl_addr *addr = (struct rtnl_addr *)obj;
			struct nl_addr *ip = rtnl_addr_get_local(addr);
			if (!ip)
				continue;

			sockaddr_storage saddr;
			socklen_t salen = sizeof(saddr);
			memset(&saddr, 0, salen);
			if (nl_addr_fill_sockaddr(ip, (sockaddr *)&saddr, &salen))
				continue;

			if (domain != domains.end()) {
				localDnsSuffixStr = *domain;
				domain++;
			}
			_localDNSSuffixes[saddr] = localDnsSuffixStr;
			char buf[INET6_ADDRSTRLEN];
			nl_addr2str(ip, buf, INET6_ADDRSTRLEN);
			UNS_DEBUG(L"AdapterListInfo DnsSuffix %C '%C'\n", buf, localDnsSuffixStr.c_str());

			obj = nl_cache_get_next(obj);
		}

		_copyOfLocalDNSSuffixes = _localDNSSuffixes;
	}

	result = 0;

	nl_cache_free(addr_cache);

out:
	nl_socket_free(sock);
	return result;
}
#else //!defined(USE_NM) && !defined(USE_CONNMAN)

#include <gio/gio.h>
#include <map>
#include <string>

typedef std::map<std::string, std::string> domains_map_t; //domain by link name
typedef domains_map_t::const_iterator domains_iterator_t;

#if defined(USE_NM)
static void get_domains(const char *path, const char* iface, domains_map_t &domains)
{
	GDBusProxy *proxy;
	GVariant *ret;
	GVariantIter *iter;
	const gchar *str;

	proxy = g_dbus_proxy_new_for_bus_sync (G_BUS_TYPE_SYSTEM,
					       G_DBUS_PROXY_FLAGS_NONE,
					       NULL,
					       "org.freedesktop.NetworkManager",
					       path,
					       "org.freedesktop.NetworkManager.IP4Config",
					       NULL, NULL);
	if (!proxy) {
		UNS_ERROR(L"AdapterListInfo can't have dbus proxy\n");
		return;
	}

	ret = g_dbus_proxy_get_cached_property(proxy, "Domains");
	if (ret) {
		g_variant_get(ret, "as", &iter);
		while (g_variant_iter_loop(iter, "s", &str)) {
			domains[iface] = str;
			UNS_DEBUG(L"Local DNS suffix: %C\n", str);
		}
		g_variant_iter_free(iter);
		g_variant_unref(ret);
	}
	g_object_unref(proxy);
}


static void get_device_ip4(const char *obj_path, domains_map_t &domains)
{
	GDBusProxy *proxy;
	GVariant *ret_iface = NULL, *ret_ip4cfg = NULL, *path_value = NULL;
	const char *path = NULL;
	const char *iface = NULL;
	GError *error = NULL;

	proxy = g_dbus_proxy_new_for_bus_sync(G_BUS_TYPE_SYSTEM,
					      G_DBUS_PROXY_FLAGS_NONE,
					      NULL,
					      "org.freedesktop.NetworkManager",
					      obj_path,
					      "org.freedesktop.DBus.Properties",
					      NULL, NULL);
	if (!proxy) {
		UNS_ERROR(L"AdapterListInfo can't have dbus proxy\n");
		return;
	}

	ret_iface = g_dbus_proxy_call_sync(proxy,
					   "Get",
					   g_variant_new ("(ss)",
						"org.freedesktop.NetworkManager.Device",
						"Interface"
					   ),
					   G_DBUS_CALL_FLAGS_NONE, -1,
					   NULL, &error);
	if (!ret_iface) {
		g_dbus_error_strip_remote_error (error);
		UNS_ERROR(L"AdapterListInfo Failed to get Interface property: %C\n",
			  error->message);
		g_error_free(error);
		goto out;
	}
	g_variant_get(ret_iface, "(v)", &path_value);
	iface = g_variant_get_string (path_value, NULL);

	ret_ip4cfg = g_dbus_proxy_call_sync(proxy,
					    "Get",
					    g_variant_new ("(ss)",
						"org.freedesktop.NetworkManager.Device",
						"Ip4Config"
					    ),
					    G_DBUS_CALL_FLAGS_NONE, -1,
					    NULL, &error);
	if (!ret_ip4cfg) {
		g_dbus_error_strip_remote_error (error);
		UNS_ERROR(L"AdapterListInfo Failed to get Ip4Config property: %C\n",
			  error->message);
		g_error_free(error);
		goto out;
	}

	g_variant_get(ret_ip4cfg, "(v)", &path_value);
	if (!g_variant_is_of_type (path_value, G_VARIANT_TYPE_OBJECT_PATH)) {
		UNS_ERROR(L"AdapterListInfo Unexpected type returned getting Connection property: %C\n",
			  g_variant_get_type_string (path_value));
		goto out;
	}

	path = g_variant_get_string (path_value, NULL);
	if (path && iface)
		get_domains(path, iface, domains);
out:
	g_variant_unref (path_value);
	g_variant_unref (ret_iface);
	g_variant_unref (ret_ip4cfg);
	g_object_unref (proxy);
}

static void get_devices(GDBusProxy *proxy, domains_map_t &domains)
{
	GError *error = NULL;
	GVariant *ret = NULL, *value = NULL;
	char **paths;
	size_t i;

	ret = g_dbus_proxy_call_sync(proxy,
				     "Get",
				      g_variant_new ("(ss)",
					"org.freedesktop.NetworkManager",
					"Devices"
				      ),
				      G_DBUS_CALL_FLAGS_NONE, -1,
				      NULL, &error);
	if (!ret) {
		g_dbus_error_strip_remote_error(error);
		UNS_ERROR(L"AdapterListInfo Failed to get Devices property: %C\n", error->message);
		g_error_free(error);
		return;
	}

	g_variant_get(ret, "(v)", &value);

	if (!g_variant_is_of_type (value, G_VARIANT_TYPE ("ao"))) {
		UNS_ERROR(L"AdapterListInfo Unexpected type returned getting Devices: %C\n",
			  g_variant_get_type_string(value));
		goto out;
	}

	paths = g_variant_dup_objv(value, NULL);
	if (!paths) {
		UNS_ERROR(L"AdapterListInfo Could not retrieve active connections property\n");
		goto out;
	}

	for (i = 0; paths[i]; i++)
		get_device_ip4(paths[i], domains);
	g_strfreev(paths);

out:
	g_variant_unref(value);
	g_variant_unref(ret);
}

static int get_domains_map(domains_map_t &domains)
{
	GDBusProxy *proxy;

	proxy = g_dbus_proxy_new_for_bus_sync(G_BUS_TYPE_SYSTEM,
					      G_DBUS_PROXY_FLAGS_NONE,
					      NULL,
					      "org.freedesktop.NetworkManager",
					      "/org/freedesktop/NetworkManager",
					      "org.freedesktop.DBus.Properties",
					      NULL, NULL);
	if (!proxy) {
		UNS_ERROR(L"AdapterListInfo can't have dbus proxy\n");
		return -EFAULT;
	}
	get_devices(proxy, domains);
	g_object_unref(proxy);
	return 0;
}

#elif defined(USE_CONNMAN)

static void connman_get_data(GDBusProxy *proxy, domains_map_t &domains)
{
	GError *error = NULL;
	GVariant *ret;
	GVariantIter *iter, *iter1;
	const char *unused = NULL;
	std::string interface_name;
	std::vector<std::string> iface_domains;

	ret = g_dbus_proxy_call_sync(proxy,
				     "GetServices",
				     NULL,
				     G_DBUS_CALL_FLAGS_NONE, -1,
				     NULL, &error);
	if (!ret) {
		g_dbus_error_strip_remote_error(error);
		UNS_ERROR(L"AdapterListInfo Failed to call GetServices: %C\n", error->message);
		g_error_free(error);
		return;
	}
	g_variant_get(ret, "(a(oa{sv}))", &iter);

	while (g_variant_iter_loop(iter, "(&oa{sv})", &unused, &iter1)) {
		const char *key = NULL;
		GVariant *value = NULL;

		while (g_variant_iter_loop(iter1, "{&sv}", &key, &value)) {
			if (!key)
				continue;
			std::string key_str(key);
			if (key_str == "Ethernet") {// Extract interface name
				GVariantIter *iter2 = NULL;
				GVariant *val = NULL;
				const char *key1;
				g_variant_get(value, "a{sv}", &iter2);
				while (g_variant_iter_loop(iter2, "{&sv}", &key1, &val)) {
					if (!key1)
						continue;
					std::string key1_str(key1);
					if (key1_str == "Interface") {
						interface_name = g_variant_get_string(val, NULL);
						break;
					}
				}
				g_variant_iter_free(iter2);
			} else if (key_str == "Domains") {// Extract domains list for this interface
				GVariantIter *iter2 = NULL;
				const char *str = NULL;
				g_variant_get(value, "as", &iter2);
				while (g_variant_iter_loop(iter2, "s", &str))
					iface_domains.push_back(str);
				g_variant_iter_free(iter2);
			}
		}

		UNS_DEBUG(L"AdapterListInfo get_devices '%C' %d domains\n",
			  interface_name.c_str(), iface_domains.size());
		if (!interface_name.empty() && !iface_domains.empty()) {
			std::vector<std::string>::const_iterator it;
			for (it = iface_domains.begin(); it != iface_domains.end(); ++it)
				domains[interface_name] = *it;
		}
		interface_name.clear();
		iface_domains.clear();
	}

	g_variant_iter_free(iter);
	g_variant_unref(ret);
}

static int get_domains_map(domains_map_t &domains)
{
	GDBusProxy *proxy;

	proxy = g_dbus_proxy_new_for_bus_sync(G_BUS_TYPE_SYSTEM,
					      G_DBUS_PROXY_FLAGS_NONE,
					      NULL,
					      "net.connman",
					      "/",
					      "net.connman.Manager",
					      NULL, NULL);
	if (!proxy) {
		UNS_ERROR(L"AdapterListInfo can't have dbus proxy\n");
		return -EFAULT;
	}
	connman_get_data(proxy, domains);
	g_object_unref(proxy);
	return 0;
}
#endif // defined(USE_CONNMAN)

int AdapterListInfo::UpdateAdapterListInfo()
{
	int result;
	struct nl_cache *addr_cache = NULL;
	struct nl_cache *link_cache = NULL;
	struct nl_sock *sock;
	struct nl_object *obj;

	domains_map_t domains;
	domains_iterator_t domains_it;

	result = get_domains_map(domains);
	if (result)
		return result;

	sock = nl_socket_alloc();
	if (!sock)
		return -ENOMEM;
	result = nl_connect(sock, NETLINK_ROUTE);
	if (result) {
		UNS_ERROR(L"AdapterListInfo nl_connect failed %d\n", result);
		goto out;
	}

	result = rtnl_addr_alloc_cache(sock, &addr_cache);
	if (result) {
		UNS_ERROR(L"AdapterListInfo rtnl_link_alloc_cache failed %d\n", result);
		goto out;
	}

	result = rtnl_link_alloc_cache(sock, AF_UNSPEC, &link_cache);
	if (result) {
		UNS_ERROR(L"AdapterListInfo rtnl_link_alloc_cache failed %d\n", result);
		nl_cache_free(addr_cache);
		goto out;
	}

	{
		std::lock_guard<std::mutex> l(_localDNSLock);
		_localDNSSuffixes.clear();

		for (obj = nl_cache_get_first(addr_cache); obj; obj = nl_cache_get_next(obj)) {
			std::string localDnsSuffixStr = "";
			struct rtnl_addr *addr = (struct rtnl_addr *)obj;
			int scope = rtnl_addr_get_scope(addr);
			struct nl_addr *ip = rtnl_addr_get_local(addr);
			if (!ip)
				continue;

			sockaddr_storage saddr;
			socklen_t salen = sizeof(saddr);
			memset(&saddr, 0, salen);
			if (nl_addr_fill_sockaddr(ip, (sockaddr *)&saddr, &salen))
				continue;

			if (rtnl_addr_get_family(addr) == AF_INET6 &&
			    scope == RT_SCOPE_LINK) {
				// Push scope field into address to align with getpeername
				((sockaddr_in6 *)&saddr)->sin6_scope_id = rtnl_addr_get_ifindex(addr);
			}

			char buf[std::max(INET6_ADDRSTRLEN, IFNAMSIZ)];
			char *ptr = rtnl_link_i2name(link_cache, rtnl_addr_get_ifindex(addr), buf, sizeof(buf));
			if (ptr) {
				UNS_DEBUG(L"AdapterListInfo link name '%C'\n", ptr);
				domains_it = domains.find(ptr);
				if (domains_it != domains.end())
					localDnsSuffixStr = domains_it->second;
			}

			nl_addr2str(ip, buf, sizeof(buf));
			UNS_DEBUG(L"AdapterListInfo DnsSuffix %C '%C'\n", buf, localDnsSuffixStr.c_str());

			_localDNSSuffixes[saddr] = localDnsSuffixStr;
		}

		_copyOfLocalDNSSuffixes = _localDNSSuffixes;
	}

	nl_cache_free(addr_cache);
	nl_cache_free(link_cache);

out:
	nl_socket_free(sock);
	return 0;
}
#endif // defined(USE_NM) || defined(USE_CONNMAN)

std::string AdapterListInfo::GetDNSSuffixFromLocalIP(const sockaddr_storage &ip)
{
	std::string dns;

	std::lock_guard<std::mutex> l(_localDNSLock);

	SuffixMap::iterator it = _localDNSSuffixes.find(ip);
	if (it != _localDNSSuffixes.end()) {
		dns = it->second;
	}
	else {
		dns = "";
	}

	return dns;
}

bool AdapterListInfo::PerformUpdate(void *params)
{
	UNS_DEBUG(L"---> Check for update in Adapter ...\n");
	if (UpdateAdapterListInfo() != 0)
		return false;
	if (_cb != NULL) {
		SuffixMap suffixes(GetLocalDNSSuffixList());//to copy it under lock
		_cb(params, suffixes);
	}
	return true;
}
