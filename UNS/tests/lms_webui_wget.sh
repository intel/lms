#!/bin/bash -x
# SPDX-License-Identifier: Apache-2.0
# Copyright (C) 2019-2023 Intel Corporation

#get login page of webui (or 404 error, that is represented by return code 8)
wget --no-proxy http://127.0.0.1:16993 -O -
ret=$?
test $ret -eq 8 && exit 0
test $ret -ne 0 && exit $ret
wget --no-proxy http://127.0.0.1:16993 -O - | grep -q "Active Management Technology" || exit $?
exit 0