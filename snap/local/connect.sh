#!/bin/bash
sudo snap connect lms:shutdown :shutdown
sudo snap connect lms:network-observe :network-observe
sudo snap connect lms:network-manager :network-manager
sudo snap connect lms:hardware-observe :hardware-observe
sudo snap connect lms:network-control :network-control
