@rem SPDX-License-Identifier: Apache-2.0 */
@rem
@rem Copyright (C) 2010-2020 Intel Corporation
@rem

rem compile mof files and create namespace
mofcomp wmi_build.mof

rem register the MeProv as the provider
mofcomp register.mof

rem register ..\MeProf.dll
regsvr32 ..\MeProv.dll

pause