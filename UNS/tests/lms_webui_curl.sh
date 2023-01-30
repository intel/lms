#!/bin/bash -x
# SPDX-License-Identifier: Apache-2.0
# Copyright (C) 2019-2032 Intel Corporation

#get login page of webui
curl --noproxy "*" -L http://127.0.0.1:16993 | grep -q "Active Management Technology"
