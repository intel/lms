#!/usr/bin/env python3
# SPDX-License-Identifier: Apache-2.0
# Copyright (C) 2010-2019 Intel Corporation
"""
LMS DBus interface unit-tests

Call every DBus method, should not throw exception.
Test also incorrect input.

TODO: Alarm, check output.
"""
import unittest
import dbus

DBUS_DEST = 'com.intel.amt.lms'
DBUS_OBJ = '/com/intel/amt/lms'
DBUS_IFACE = 'com.intel.amt.lms.'

class ManageabilityTestCase(unittest.TestCase):
    """Manageability interface test"""

    def setUp(self):
        bus = dbus.SystemBus()
        proxy = bus.get_object(DBUS_DEST, DBUS_OBJ)
        self.iface = dbus.Interface(proxy,
                                    dbus_interface=DBUS_IFACE + 'Manageability')

    def tearDown(self):
        #os.close(self.fd)
        pass

    def test_GetTheFeatureState(self):
        '''GetTheFeatureState test method'''
        for i in [x for x in range(0, 21) if x not in (6, 8)]:
            with self.subTest(i=i):
                self.iface.GetTheFeatureState(i)
        for i in (22, 100000000):
            with self.subTest(i=i):
                with self.assertRaises(dbus.exceptions.DBusException) as the_exp:
                    self.iface.GetTheFeatureState(i)
                self.assertEqual(the_exp.exception.get_dbus_message(), 'Invalid argument')

    def test_GetFeaturesState(self):
        '''GetFeaturesState test method'''
        self.iface.GetFeaturesState()

    def test_GetCustomerType(self):
        '''GetCustomerType test method'''
        self.iface.GetCustomerType()

    def test_GetPlatformType(self):
        '''GetPlatformType test method'''
        self.iface.GetPlatformType()

    def test_GetMenageabiltyMode(self):
        '''GetMenageabiltyMode test method'''
        self.iface.GetMenageabiltyMode()

    def test_GetFWInfo(self):
        '''GetFWInfo test method'''
        self.iface.GetFWInfo()

    def test_GetPMCVersion(self):
        '''GetPMCVersion test method'''
        self.iface.GetPMCVersion()

class PTHITestCase(unittest.TestCase):
    """PTHI interface test"""

    def setUp(self):
        bus = dbus.SystemBus()
        proxy = bus.get_object(DBUS_DEST, DBUS_OBJ)
        self.iface = dbus.Interface(proxy,
                                    dbus_interface=DBUS_IFACE + 'PTHI')

    def tearDown(self):
        #os.close(self.fd)
        pass

    def test_GetAMTVersion(self):
        '''GetAMTVersion test method'''
        self.iface.GetAMTVersion()

    def test_GetLMSVersion(self):
        '''GetLMSVersion test method'''
        self.iface.GetLMSVersion()

    def test_GetProvisioningMode(self):
        '''GetProvisioningMode test method'''
        self.iface.GetProvisioningMode()

    def test_GetProvisioningTlsMode(self):
        '''GetProvisioningTlsMode test method'''
        self.iface.GetProvisioningTlsMode()

    def test_GetProvisioningState(self):
        '''GetProvisioningState test method'''
        self.iface.GetProvisioningState()

    def test_GetNetworkConnectionStatus(self):
        '''GetNetworkConnectionStatus test method'''
        self.iface.GetNetworkConnectionStatus()

    def test_GetUserInitiatedEnabled(self):
        '''GetUserInitiatedEnabled test method'''
        self.iface.GetUserInitiatedEnabled()

    def test_getWebUIState(self):
        '''getWebUIState test method'''
        self.iface.getWebUIState()

    def test_GetPowerPolicy(self):
        '''GetPowerPolicy test method'''
        self.iface.GetPowerPolicy()

    def test_GetLastResetReason(self):
        '''GetLastResetReason test method'''
        self.iface.GetLastResetReason()

    def test_GetRedirectionStatus(self):
        '''GetRedirectionStatus test method'''
        self.iface.GetRedirectionStatus()

    def test_GetSystemDefenseStatus(self):
        '''GetSystemDefenseStatus test method'''
        self.iface.GetSystemDefenseStatus()

    def test_GetNetworkSettingsWired(self):
        '''GetNetworkSettings test method (wired)'''
        self.iface.GetNetworkSettings(0)

    @unittest.skip("Requires wireless card")
    def test_GetNetworkSettingsWireless(self):
        '''GetNetworkSettings test method (wireless)'''
        self.iface.GetNetworkSettings(1)

    def test_GetNetworkSettingsFail(self):
        '''GetNetworkSettings test method (wrong parameters)'''
        for i in (2, 100000000):
            with self.subTest(i=i):
                with self.assertRaises(dbus.exceptions.DBusException) as the_exp:
                    self.iface.GetNetworkSettings(i)
                self.assertEqual(the_exp.exception.get_dbus_message(), 'Invalid argument')

    def test_GetIPv6NetworkSettingsWired(self):
        '''GetIPv6NetworkSettings test method (wired)'''
        self.iface.GetIPv6NetworkSettings(0)

    @unittest.skip("Requires wireless card")
    def test_GetIPv6NetworkSettingsWireless(self):
        '''GetIPv6NetworkSettings test method (wireless)'''
        self.iface.GetIPv6NetworkSettings(1)

    def test_GetIPv6NetworkSettingsFail(self):
        '''GetIPv6NetworkSettings test method (wrong parameters)'''
        for i in (2, 100000000):
            with self.subTest(i=i):
                with self.assertRaises(dbus.exceptions.DBusException) as the_exp:
                    self.iface.GetIPv6NetworkSettings(i)
                self.assertEqual(the_exp.exception.get_dbus_message(), 'Invalid argument')

    def test_GetSystemUUID(self):
        '''GetSystemUUID test method'''
        self.iface.GetSystemUUID()

    def test_UserInitiatedConnection(self):
        '''*UserInitiatedConnection test method'''
        self.iface.InitiateUserConnection()
        self.iface.OpenUserInitiatedConnection()
        self.iface.CloseUserInitiatedConnection()

    def test_TerminateKVMSession(self):
        '''TerminateKVMSession test method'''
        self.iface.TerminateKVMSession()

    def test_GetKVMRedirectionState(self):
        '''GetKVMRedirectionState test method'''
        self.iface.GetKVMRedirectionState()

    def test_Sprite(self):
        '''Sprite related test method'''
        #no PFU on Linux
        #self.iface.SetSpriteLanguage(1)
        #lang = self.iface.GetSpriteLanguage()
        #self.assertEqual(lang, 1)
        self.iface.SetSpriteZoom(2)
        lang, zoom = self.iface.GetSpriteParameters()
        #self.assertEqual(lang, 1)
        self.assertEqual(zoom, 2)

    def test_GetConfigurationInfo(self):
        '''GetConfigurationInfo test method'''
        self.iface.GetConfigurationInfo()

    def test_TerminateRemedySessions(self):
        '''TerminateRemedySessions test method'''
        self.iface.TerminateRemedySessions()

    def test_GetUserConsentState(self):
        '''GetUserConsentState test method'''
        self.iface.GetUserConsentState()

    def test_GetWLANLinkInfo(self):
        '''GetWLANLinkInfo test method'''
        self.iface.GetWLANLinkInfo()

    def test_SetLinkPreferenceToHost(self):
        '''SetLinkPreferenceToHost test method'''
        self.iface.SetLinkPreferenceToHost()

    def test_userInitiatedPolicyRuleExists(self):
        '''userInitiatedPolicyRuleExists test method'''
        self.iface.userInitiatedPolicyRuleExists()

    def test_userInitiatedPolicyRuleForLocalMpsExists(self):
        '''userInitiatedPolicyRuleForLocalMpsExists test method'''
        self.iface.userInitiatedPolicyRuleForLocalMpsExists()

    def test_snmpEventSubscriberExists(self):
        '''snmpEventSubscriberExists test method'''
        self.iface.snmpEventSubscriberExists()

    def test_CILAFilterCollectionSubscriptionExists(self):
        '''CILAFilterCollectionSubscriptionExists test method'''
        self.iface.CILAFilterCollectionSubscriptionExists()

    def test_UpdateScreenSettings2(self):
        '''UpdateScreenSettings2 test method'''
        self.iface.UpdateScreenSettings2([(True, 1, 2, 3, 4, 5), (False, 98, 99, 100, 44, 55)], 2)
        with self.assertRaises(dbus.exceptions.DBusException) as the_exp:
            self.iface.UpdateScreenSettings2([(True, 1, 2, 3, 4, 5)], 2)
        self.assertEqual(the_exp.exception.get_dbus_message(), 'Invalid argument')
        with self.assertRaises(dbus.exceptions.DBusException) as the_exp:
            self.iface.UpdateScreenSettings2([(True, 1, 2, 3, 4, 5), (False, 98, 99, 100, 44, 55)], 1)
        self.assertEqual(the_exp.exception.get_dbus_message(), 'Invalid argument')

    @unittest.skip("Requires specially configured FW")
    def test_GetRedirectionSessionLinkTechnology_SOL(self):
        '''GetRedirectionSessionLinkTechnology SOL test method'''
        self.iface.GetRedirectionSessionLinkTechnology(0)

    @unittest.skip("Requires specially configured FW")
    def test_GetRedirectionSessionLinkTechnology_IDER(self):
        '''GetRedirectionSessionLinkTechnology IDER test method'''
        self.iface.GetRedirectionSessionLinkTechnology(1)

    @unittest.skip("Requires specially configured FW")
    def test_GetRedirectionSessionLinkTechnology_KVM(self):
        '''GetRedirectionSessionLinkTechnology KVM test method'''
        self.iface.GetRedirectionSessionLinkTechnology(2)

    def test_GetRedirectionSessionLinkTechnology_Argument(self):
        '''GetRedirectionSessionLinkTechnology out of range argument test method'''
        with self.assertRaises(dbus.exceptions.DBusException) as the_exp:
            self.iface.GetRedirectionSessionLinkTechnology(3)
        self.assertEqual(the_exp.exception.get_dbus_message(), 'Invalid argument')

class AT_DeviceTestCase(unittest.TestCase):
    """AT_Device interface test"""

    def setUp(self):
        bus = dbus.SystemBus()
        proxy = bus.get_object(DBUS_DEST, DBUS_OBJ)
        self.iface = dbus.Interface(proxy,
                                    dbus_interface=DBUS_IFACE + 'AT_Device')

    def tearDown(self):
        pass

    def test_GetAuditLogs(self):
        '''GetAuditLogs test method'''
        self.iface.GetAuditLogs()

class UNSAlertTestCase(unittest.TestCase):
    """UNSAlert interface test"""

    def setUp(self):
        bus = dbus.SystemBus()
        proxy = bus.get_object(DBUS_DEST, DBUS_OBJ)
        self.iface = dbus.Interface(proxy,
                                    dbus_interface=DBUS_IFACE + 'UNSAlert')

    def tearDown(self):
        pass

    def test_GetIMSSEventHistory(self):
        '''GetIMSSEventHistory test method'''
        self.iface.GetIMSSEventHistory()

if __name__ == '__main__':
    unittest.main()
