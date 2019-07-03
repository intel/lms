#!/bin/bash
# SPDX-License-Identifier: Apache-2.0
# Copyright (C) 2019 Intel Corporation

SEV_TXT=$1
test -z $SEV_TXT && SEV_TXT=DEBUG
SEV_BIN=02

test $SEV_TXT == TRACE && SEV_BIN=01
test $SEV_TXT == DEBUG && SEV_BIN=02
test $SEV_TXT == WARNING && SEV_BIN=03
test $SEV_TXT == ERROR && SEV_BIN=04
test $SEV_TXT == CRITICAL && SEV_BIN=05

echo "Setting severity" ${SEV_BIN}
mkdir -p /etc/lms/IntelAMTUNS_/
echo -n -e \\x34\\x${SEV_BIN}\\x00\\x00\\x00\\x00\\x00\\x00\\x00 > /etc/lms/IntelAMTUNS_/LMSLoggingSeverity
