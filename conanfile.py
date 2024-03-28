#!/usr/bin/env python3
# SPDX-License-Identifier: Apache-2.0
# Copyright (C) 2021-2023 Intel Corporation
from conans import ConanFile
import os

class LMSConan(ConanFile):
    name = "lms"
    generators = "cmake", "cmake_find_package", "visual_studio"
    settings = "os"
    options = {"build_tests": [True, False]}
    default_options = {"build_tests": False}

    def requirements(self):
        if self.settings.os == "Windows":
            self.requires("libxml2/2.12.2@mesw/stable")
            self.requires("ACE/7.1.2@mesw/stable")
        else:
            if os.environ.get("LOCAL_ACE", None):
                self.requires("ACE/7.1.2@mesw/stable")
        if self.options.build_tests:
            self.requires("gtest/1.10.0@mesw/stable")
