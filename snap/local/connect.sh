#!/bin/bash
# SPDX-License-Identifier: Apache-2.0
# Copyright (C) 2019-2021 Intel Corporation

sudo snap connect lms:shutdown :shutdown
sudo snap connect lms:network-observe :network-observe
sudo snap connect lms:network-manager :network-manager
sudo snap connect lms:hardware-observe :hardware-observe
sudo snap connect lms:network-control :network-control
