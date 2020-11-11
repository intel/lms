# SPDX-License-Identifier: Apache-2.0
# Copyright (C) 2020 Intel Corporation
param (
  [string]$process = "set",
  [string]$pfuname = "PFU.BIN"
)

$registryPath = "HKLM:\SYSTEM\CurrentControlSet\Services\LMS\IntelAMTUNS"
$Name = "PartialFWUImagePath"

if ($process -eq 'set')
{
  $value = (Get-Item $pfuname).FullName
}
else
{
  $value = ""
}

if (!(Test-Path $registryPath))
{
  New-Item -Path $registryPath -Force | Out-Null
}
New-ItemProperty -Path $registryPath -Name $name -Value $value -PropertyType STRING -Force | Out-Null
