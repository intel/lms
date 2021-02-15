#!/usr/bin/env python3
# SPDX-License-Identifier: Apache-2.0
# Copyright (C) 2021 Intel Corporation
from conans import ConanFile
import os

class LMSConan(ConanFile):
    name = "lms"
    generators = "cmake", "cmake_find_package", "visual_studio"
    settings = "os"

    def requirements(self):
        self.requires("metee/3.0.1@mesw/stable")
        if self.settings.os == "Windows":
            self.requires("libxml2/2.9.10@mesw/stable")
            self.requires("ACE/6.5.11@mesw/stable")
        else:
            if os.environ.get("LOCAL_ACE", None):
                self.requires("ACE/6.5.11@mesw/stable")
        gtest = os.environ.get("BUILD_TESTS", "0")
        if gtest == "1" or gtest == "YES" or gtest == "Y" or gtest == "ON":
            self.requires("gtest/1.10.0@mesw/stable")
