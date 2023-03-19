#!/bin/bash -x
# SPDX-License-Identifier: Apache-2.0
# Copyright (C) 2019-2023 Intel Corporation

addr=https://127.0.0.1:16993
#get login page of webui
curl --insecure --noproxy "*" -L $addr
if [ $? -eq 7 ]; then
 #leagcy system without tls
 addr=http://127.0.0.1:16992
fi
curl --insecure --noproxy "*" -L $addr | grep -q "Active Management Technology"
echo $?
