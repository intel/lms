@rem SPDX-License-Identifier: Apache-2.0 */
@rem
@rem Copyright (C) 2010-2020 Intel Corporation
@rem

rem compile mof files and create namespace
mofcomp wmi_build.mof

rem register the MeProv as the provider
mofcomp register.mof

rem register ..\MeProv.dll using 64-bit regsvr32
%SystemRoot%\System32\regsvr32.exe ..\MeProv.dll

pause