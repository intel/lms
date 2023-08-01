# SPDX-License-Identifier: Apache-2.0
# Copyright (C) 2023 Intel Corporation

$url = "https://127.0.0.1:16993"

try {
    $res = Invoke-WebRequest -Uri $url -Method Get
}
catch {
    Write "Error calling {$url}"
    $url = "http://127.0.0.1:16992"
}

if (!$res) {
    try {
        $res = Invoke-WebRequest -Uri $url -Method Get
    }
    catch {
        Write-Error "Error calling {$url}"
        Exit 1
    }
}

$statusCode = $res.StatusCode
if ($statusCode -ne 200) {
    Write-Error "Error calling {$url} - Http Status Code {$statusCode}"
    Exit 1
}

if ($res.Content.Contains("Active Management Technology") -eq $false) {
    Write-Error "Http Get did not return Active Management Technology"
    Exit 1
}

Exit 0
