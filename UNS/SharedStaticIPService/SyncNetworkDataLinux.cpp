/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2009-2020 Intel Corporation
 */
/*++

@file: SyncNetworkDataLinux.cpp

--*/
#include <netlink/route/route.h>
#include <netlink/route/addr.h>
#include <net/if.h>
#include <resolv.h>
#include "SyncNetworkData.h"
#include "SyncIpClient.h"

#include <sstream>

#include "global.h"

static std::string emptyAddress("0.0.0.0");

bool SyncNetworkData::ValidateLinkStatus()
{
	int res;
	FuncEntryExit<decltype(res)> fee(this, L"ValidateLinkStatus", res);

	struct nl_cache *link_cache, *addr_cache;
	struct nl_sock *sock;
	struct nl_object *obj;
	unsigned int flags;

	sock = nl_socket_alloc();
	if (!sock) {
		res = -ENOMEM;
		UNS_ERROR(L"ValidateLinkStatus nl_socket_alloc failed\n");
		return false;
	}

	res = nl_connect(sock, NETLINK_ROUTE);
	if (res) {
		UNS_ERROR(L"ValidateLinkStatus nl_connect failed %d\n", res);
		goto out;
	}

	res = rtnl_link_alloc_cache(sock, AF_UNSPEC, &link_cache);
	if (res) {
		UNS_ERROR(L"ValidateLinkStatus rtnl_link_alloc_cache failed %d\n", res);
		goto out;
	}

	res = -ENOENT;
	for (obj = nl_cache_get_first(link_cache);
	     obj != NULL; obj = nl_cache_get_next(obj))
	{
		struct rtnl_link *link = (struct rtnl_link *)obj;

		UNS_DEBUG(L"ValidateLinkStatus m_NICindex ?= rtnl_link_get_ifindex(link) %d %d\n",
			  m_NICindex, rtnl_link_get_ifindex(link));
		if (m_NICindex != rtnl_link_get_ifindex(link))
			continue;

		flags = rtnl_link_get_flags(link);

		if (!(flags & IFF_RUNNING)) {
			UNS_ERROR(L"ValidateLinkStatus flags not IFF_RUNNING %d\n", flags);
			res = -EFAULT;
			break;
		}
		res = 0;
		break;
	}
	nl_cache_free(link_cache);

	if (res)
		goto out;

	res = rtnl_addr_alloc_cache(sock, &addr_cache);
	if (res) {
		UNS_ERROR(L"ValidateLinkStatus rtnl_addr_alloc_cache failed %d\n", res);
		goto out;
	}

	res = -ENOENT;
	for (obj = nl_cache_get_first(addr_cache);
	     obj != NULL; obj = nl_cache_get_next(obj))
	{
		struct rtnl_addr *addr = (struct rtnl_addr *) obj;

		UNS_DEBUG(L"ValidateLinkStatus m_NICindex ?= rtnl_addr_get_ifindex(addr) %d %d\n",
			  m_NICindex, rtnl_addr_get_ifindex(addr));
		if (m_NICindex != rtnl_addr_get_ifindex(addr))
			continue;

		flags = rtnl_addr_get_flags(addr);
		if (flags & IFA_F_SECONDARY) {
			UNS_ERROR(L"ValidateLinkStatus flags is IFA_F_SECONDARY %d\n", flags);
			res = -EFAULT;
			break;
		}
		res = 0;
		break;
	}
	nl_cache_free(addr_cache);
out:
	nl_socket_free(sock);
	return (res == 0);
}

#if defined(USE_NM) || defined(USE_CONNMAN)
#include <gio/gio.h>

#if defined(USE_NM)
static void get_dns(const char *path, std::vector<std::string> &dns)
{
	GDBusProxy *proxy;
	GVariant *ret;
	GVariantIter *iter;
	char str[256] = {0};
	unsigned int data;

	proxy = g_dbus_proxy_new_for_bus_sync(G_BUS_TYPE_SYSTEM,
					G_DBUS_PROXY_FLAGS_NONE,
					NULL,
					"org.freedesktop.NetworkManager",
					path,
					"org.freedesktop.NetworkManager.IP4Config",
					NULL, NULL);
	if (!proxy) {
		UNS_ERROR(L"can't have dbus proxy\n");
		return;
	}

	ret = g_dbus_proxy_get_cached_property(proxy, "Nameservers");
	if (!ret) {
		UNS_ERROR(L"can't get Nameservers\n");
		goto out;
	}

	g_variant_get(ret, "au", &iter);
	while (g_variant_iter_loop(iter, "u", &data)) {
		inet_ntop(AF_INET, &data, str, sizeof(str));
		str[sizeof(str)-1] = '\0';
		dns.push_back(str);
	}
	g_variant_iter_free(iter);
	g_variant_unref(ret);
out:
	g_object_unref(proxy);
}

static void
get_device_ip4(const char *obj_path, std::vector<std::string> &dns)
{
	GDBusProxy *proxy;
	GVariant *ret = NULL, *path_value = NULL;
	const char *path = NULL;
	GError *error = NULL;

	proxy = g_dbus_proxy_new_for_bus_sync(G_BUS_TYPE_SYSTEM,
					G_DBUS_PROXY_FLAGS_NONE,
					NULL,
					"org.freedesktop.NetworkManager",
					obj_path,
					"org.freedesktop.DBus.Properties",
					NULL, NULL);
	if (!proxy) {
		UNS_ERROR(L"can't have dbus proxy\n");
		return;
	}

	ret = g_dbus_proxy_call_sync(proxy,
				"Get",
				g_variant_new ("(ss)",
					"org.freedesktop.NetworkManager.Device",
					"Ip4Config"),
				G_DBUS_CALL_FLAGS_NONE, -1,
				NULL, &error);
	if (!ret) {
		g_dbus_error_strip_remote_error (error);
		UNS_ERROR(L"AdapterListInfo Failed to get Ip4Config property: %C\n",
			  error->message);
		g_error_free(error);
		goto out;
	}

	g_variant_get(ret, "(v)", &path_value);
	if (!g_variant_is_of_type(path_value, G_VARIANT_TYPE_OBJECT_PATH)) {
		UNS_ERROR(L"AdapterListInfo Unexpected type returned getting Connection property: %C\n",
			  g_variant_get_type_string(path_value));
		goto out;
	}

	path = g_variant_get_string(path_value, NULL);
	if (path)
		get_dns(path, dns);
out:
	if (path_value)
		g_variant_unref(path_value);
	if (ret)
		g_variant_unref(ret);
	g_object_unref(proxy);
}

static void
get_device(GDBusProxy *proxy, const std::string &link_name, std::vector<std::string> &dns)
{
	GError *error = NULL;
	GVariant *ret = NULL;
	char *path;

	ret = g_dbus_proxy_call_sync(proxy,
				     "GetDeviceByIpIface",
				     g_variant_new ("(s)", link_name.c_str()),
				     G_DBUS_CALL_FLAGS_NONE, -1,
				     NULL, &error);
	if (!ret) {
		g_dbus_error_strip_remote_error(error);
		UNS_ERROR(L"Failed to %C GetDeviceByIpIface : %C\n", link_name.c_str(), error->message);
		g_error_free(error);
		return;
	}

	g_variant_get(ret, "(&o)", &path);
	get_device_ip4(path, dns);
	g_variant_unref(ret);
}

static void get_dns_list(const std::string &link_name, std::vector<std::string> &dns,
			 bool &/*is_dhcp*/, std::string &/*gw*/)
{
	GDBusProxy *proxy;

	proxy = g_dbus_proxy_new_for_bus_sync(G_BUS_TYPE_SYSTEM,
					G_DBUS_PROXY_FLAGS_NONE,
					NULL,
					"org.freedesktop.NetworkManager",
					"/org/freedesktop/NetworkManager",
					"org.freedesktop.NetworkManager",
					NULL, NULL);
	if(proxy) {
		get_device(proxy, link_name, dns);
		g_object_unref(proxy);
	}
}
#endif // defined(USE_NM)

#if defined(USE_CONNMAN)
static void
connman_get_data(GDBusProxy *proxy, const std::string &link_name,
		 std::vector<std::string> &dns, bool &is_dhcp,
		 std::string &gw)
{
	GError *error = NULL;
	GVariant *ret;
	GVariantIter *iter, *iter1;
	const char *dummy = NULL;
	std::string interface_name;
	std::string gateway;
	std::vector<std::string> iface_dns;

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

	while (g_variant_iter_loop(iter, "(&oa{sv})", &dummy, &iter1)) {
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
			} else if (key_str == "Nameservers") {// Extract nameservers for this interface
				GVariantIter *iter2 = NULL;
				const char *str = NULL;
				g_variant_get (value, "as", &iter2);
				while (g_variant_iter_loop(iter2, "s", &str))
					iface_dns.push_back(str);
				g_variant_iter_free(iter2);
			} else if (key_str == "IPv4") {// Extract dhcp state and gw for this interface
				GVariantIter *iter_ipv4 = NULL;
				GVariant *val = NULL;
				const char *key_ipv4;
				g_variant_get(value, "a{sv}", &iter_ipv4);
				while (g_variant_iter_loop(iter_ipv4, "{&sv}", &key_ipv4, &val)) {
					if (!key_ipv4)
						continue;
					std::string key_ipv4_str(key_ipv4);
					if (key_ipv4_str == "Method") {
						const char *method = g_variant_get_string(val, NULL);
						if (method)
							is_dhcp = (std::string("dhcp") == method);
					} else if (key_ipv4_str == "Gateway") {
						const char *gw_ptr = g_variant_get_string(val, NULL);
						if (gw_ptr && gw_ptr[0] != '\0')
							gateway = gw_ptr;
					}
				}
				g_variant_iter_free(iter_ipv4);
			} else if (key_str == "IPv4.Configuration") {// Extract gw for this interface
				GVariantIter *iter_ipv4c = NULL;
				GVariant *val = NULL;
				const char *key_ipv4c;
				g_variant_get(value, "a{sv}", &iter_ipv4c);
				while (g_variant_iter_loop(iter_ipv4c, "{&sv}", &key_ipv4c, &val)) {
					if (!key_ipv4c)
						continue;
					std::string key_ipv4c_str(key_ipv4c);
					if (key_ipv4c_str == "Gateway") {
						const char *gw_ptr = g_variant_get_string(val, NULL);
						if (gw_ptr && gw_ptr[0] != '\0')
							gateway = gw_ptr;
					}
				}
				g_variant_iter_free(iter_ipv4c);
			}
		}

		if (!interface_name.empty() && link_name == interface_name) {
			if (gw == emptyAddress)
				gw = gateway;
			dns = iface_dns;
			break;
		}
		interface_name.clear();
		iface_dns.clear();
	}

	g_variant_iter_free(iter);
	g_variant_unref(ret);
}

static void get_dns_list(const std::string &link_name, std::vector<std::string> &dns,
			 bool &is_dhcp, std::string &gw)
{
	GDBusProxy *proxy;

	proxy = g_dbus_proxy_new_for_bus_sync(G_BUS_TYPE_SYSTEM,
					      G_DBUS_PROXY_FLAGS_NONE,
					      NULL,
					      "net.connman",
					      "/",
					      "net.connman.Manager",
					      NULL, NULL);
	if(proxy) {
		connman_get_data(proxy, link_name, dns, is_dhcp, gw);
		g_object_unref(proxy);
	}
}

#endif // defined(USE_CONNMAN)
#endif // defined(USE_NM) || defined(USE_CONNMAN)

struct __netParam {
	int udi;

	std::string ip;
	unsigned int prefixlen;
	std::string gw;
	bool dhcp;
	std::vector<std::string> dns;
};

int getNetParam(std::string m_MacAddress, struct __netParam* param)
{
	struct nl_cache *link_cache, *addr_cache, *route_cache;
	struct nl_sock *sock;
	struct nl_object *obj;
	char buf[128];
#if defined(USE_NM) || defined(USE_CONNMAN)
	std::string link_name;
#endif // defined(USE_NM) || defined(USE_CONNMAN)
	int res;

	buf[127] = '\0';

	sock = nl_socket_alloc();
	if (!sock) {
		UNS_ERROR(L"getNetParam nl_socket_alloc failed\n");
		res = -ENODEV;
		return res;
	}

	res = nl_connect(sock, NETLINK_ROUTE);
	if (res) {
		UNS_ERROR(L"getNetParam nl_connect failed %d\n", res);
		goto out;
	}

	res = rtnl_link_alloc_cache(sock, AF_UNSPEC, &link_cache);
	if (res) {
		UNS_ERROR(L"getNetParam rtnl_link_alloc_cache failed %d\n", res);
		goto out;
	}

	for (obj = nl_cache_get_first(link_cache);
	     obj != NULL; obj = nl_cache_get_next(obj))
	{
		struct rtnl_link *link = (struct rtnl_link *)obj;

		struct nl_addr *mac = rtnl_link_get_addr(link);
		if (mac)
			nl_addr2str(mac, buf, sizeof(buf) - 1);
		else
			buf[0] = '\0';

		UNS_DEBUG(L"getNetParam MAC %C\n", buf);
		if (m_MacAddress == buf) {
			param->udi = rtnl_link_get_ifindex(link);
			UNS_DEBUG(L"getNetParam ifindex %d\n", param->udi);
#if defined(USE_NM) || defined(USE_CONNMAN)
			char *ptr = rtnl_link_get_name(link);
			if (ptr)
				link_name = ptr;
#endif // defined(USE_NM) || defined(USE_CONNMAN)
			break;
		}
	}
	nl_cache_free(link_cache);

	if (param->udi < 0) {
		UNS_ERROR(L"getNetParam no MAC %C\n", m_MacAddress.c_str());
		res = -ENOENT;
		goto out;
	}

	res = rtnl_addr_alloc_cache(sock, &addr_cache);
	if (res) {
		UNS_ERROR(L"getNetParam rtnl_adr_alloc_cache failed %d\n", res);
		goto out;
	}

	res = -ENOENT;
	for (obj = nl_cache_get_first(addr_cache);
	     obj != NULL; obj = nl_cache_get_next(obj))
	{
		struct rtnl_addr *addr = (struct rtnl_addr *) obj;

		UNS_DEBUG(L"getNetParam ifindex %d\n", rtnl_addr_get_ifindex(addr));
		if (rtnl_addr_get_ifindex(addr) != param->udi)
			continue;

		UNS_DEBUG(L"getNetParam family %d\n", rtnl_addr_get_family(addr));
		if (rtnl_addr_get_family(addr) != AF_INET)
			continue;

		struct nl_addr *ip = rtnl_addr_get_local(addr);
		if (ip)
			inet_ntop(AF_INET, nl_addr_get_binary_addr(ip), buf, sizeof(buf) - 1);
		else
			buf[0] = '\0';
		param->ip = buf;
		param->prefixlen = rtnl_addr_get_prefixlen(addr);

		param->dhcp = !(rtnl_addr_get_flags(addr) & IFA_F_PERMANENT);

		res = 0;
		break;
	}
	nl_cache_free(addr_cache);

	if (res)
		goto out;

	res = rtnl_route_alloc_cache(sock, AF_INET, 0, &route_cache);
	if (res) {
		UNS_ERROR(L"getNetParam rtnl_route_alloc_cache failed %d\n", res);
		goto out;
	}

	param->gw = emptyAddress;
	for (obj = nl_cache_get_first(route_cache);
	     obj != NULL; obj = nl_cache_get_next(obj))
	{
		struct rtnl_route *route = (struct rtnl_route *)obj;

		struct rtnl_nexthop* hop = rtnl_route_nexthop_n(route, 0);
		if(!hop)
			continue;

		int index = rtnl_route_nh_get_ifindex(hop);
		if (index != param->udi)
			continue;

		struct nl_addr* gw = rtnl_route_nh_get_gateway(hop);
		if (gw != NULL && nl_addr_get_len(gw) != 0) {
			nl_addr2str(gw, buf, sizeof(buf) - 1);
			param->gw = buf;
			break;
		}
	}
	nl_cache_free(route_cache);

#if defined(USE_NM) || defined(USE_CONNMAN)
	get_dns_list(link_name, param->dns, param->dhcp, param->gw);
#else
	struct __res_state dns_state;
	memset(&dns_state, 0 , sizeof(dns_state));
	res_ninit(&dns_state);
	for (int i = 0; i < MAXNS; i++)
		if (dns_state.nsaddr_list[i].sin_addr.s_addr)
			param->dns.push_back(inet_ntoa(dns_state.nsaddr_list[i].sin_addr));
#endif // defined(USE_NM) || defined(USE_CONNMAN)

	res = 0;
out:
	nl_socket_free(sock);
	return res;
}

bool SyncNetworkData::CheckNetworkData(bool &needSync, bool &isEmptyAddress, bool &IPv4Enabled)
{
	bool res = false;
	FuncEntryExit<decltype(res)> fee(this, L"CheckNetworkData", res);

	needSync = false;
	IPv4Enabled = false;

	UNS_DEBUG(L"DhcpEnabled=%d IpAddress=%C SubnetMask=%C MacAddress=%C DefaultGateway=%C\n", m_DHCPEnabled, m_IpAddress.c_str(), m_SubnetMask.c_str(), m_MacAddress.c_str(), m_DefaultGateway.c_str());

	if (m_MacAddress.empty())
	{
		return res;
	}

	struct __netParam param;
	if(getNetParam(m_MacAddress, &param))
	{
		return res;
	}

	IPv4Enabled = true;
	m_NICindex = param.udi;
	if (m_IpAddress != param.ip)
	{
		m_IpAddress.assign(param.ip);
		needSync = true;
	}
	uint32_t mask = !param.prefixlen ?
			 0 :
			 (0xFFFFFFFF << (32 - param.prefixlen)) & 0xFFFFFFFF;
	std::stringstream strMask;
	strMask << (mask >> 24) << "." << ((mask >> 16) & 0xFF) << "."
		<< ((mask >> 8) & 0xFF) << "." << (mask & 0xFF);
	if (m_SubnetMask != strMask.str())
	{
		m_SubnetMask.assign(strMask.str());
		needSync = true;
	}
	// Check if gateway is present - if not - not connected to a network;
	if (param.gw.length())
	{
		if (m_DefaultGateway != param.gw)
		{
			m_DefaultGateway.assign(param.gw);
			needSync = true;
		}
	}
	else
	{
		if (!m_DefaultGateway.empty())
		{
			m_DefaultGateway.clear();
		}
	}
	if (m_DHCPEnabled != param.dhcp)
	{
		m_DHCPEnabled = param.dhcp;
		needSync = true;
	}

	if (!m_DHCPEnabled &&
	    ((m_IpAddress.compare(emptyAddress) == 0) ||
	     (m_DefaultGateway.compare(emptyAddress) == 0)))
	{
		needSync = false;
		isEmptyAddress = true;
	}

	if (IPv4Enabled && !isEmptyAddress)
	{
		std::string _PrimaryDNS(""), _SecondaryDNS("");
		if (param.dns.size() > 0)
			_PrimaryDNS = param.dns[0];
		if (param.dns.size() > 1)
			_SecondaryDNS = param.dns[1];
		if (m_PrimaryDNS != _PrimaryDNS)
		{
			m_PrimaryDNS = _PrimaryDNS;
			needSync = true;
		}
		if (m_SecondaryDNS != _SecondaryDNS)
		{
			m_SecondaryDNS = _SecondaryDNS;
			needSync = true;
		}
	}

	UNS_DEBUG(L"new settings updated: DhcpEnabled=%d IpAddress=%C SubnetMask=%C MacAddress=%C DefaultGateway=%C\n",
		  m_DHCPEnabled, m_IpAddress.c_str(), m_SubnetMask.c_str(), m_MacAddress.c_str(), m_DefaultGateway.c_str());
	UNS_DEBUG(L"DNS Settings: PrimaryDNS %C, SecondaryDNS %C, return %d\n",
		  m_PrimaryDNS.c_str(), m_SecondaryDNS.c_str(),res);

	res = true;
	return res;
}
