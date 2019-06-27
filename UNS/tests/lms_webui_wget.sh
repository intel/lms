#!/bin/bash -x
# SPDX-License-Identifier: Apache-2.0
# Copyright (C) 2019 Intel Corporation

#get login page of webui (or 404 error, that is represented by return code 8)
wget --no-proxy http://127.0.0.1:16992 -O - | grep -q "Active Management Technology"
test $? -eq 0 -o $? -eq 8 || exit $?
