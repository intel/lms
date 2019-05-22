
rem compile mof files and create namespace
mofcomp wmi_build.mof

rem register the MeProv as the provider
mofcomp register.mof

rem register ..\MeProf.dll
regsvr32 ..\MeProv.dll

pause