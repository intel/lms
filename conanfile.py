#!/usr/bin/env python3
# SPDX-License-Identifier: Apache-2.0
# Copyright (C) 2021-2026 Intel Corporation
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
            self.requires("libxml2/2.15.1@mesw/stable")
            self.requires("ACE/8.0.5@mesw/stable")
        else:
            if os.environ.get("LOCAL_ACE", None):
                self.requires("ACE/8.0.5@mesw/stable")
        if self.options.build_tests:
            self.requires("gtest/1.12.1@mesw/stable")
