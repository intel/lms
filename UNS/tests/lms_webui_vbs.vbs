' SPDX-License-Identifier: Apache-2.0
' Copyright (C) 2019-2023 Intel Corporation

On Error Resume Next
MyError = 0
set http = CreateObject("microsoft.xmlhttp")
http.open "GET","http://127.0.0.1:16993",false
http.send
htmlpage = http.responsetext
If Err.Number <> 0 Then
' WScript.Echo "Http Get at 127.0.0.1:16993 failed"
  Err.Clear
  MyError=1
else TestString = InStr("htmlpage", "Active Management Technology")
	 If Err.Number <> 0 Then
'		WScript.Echo "Http Get did not return Active Management Technology"
		Err.Clear
		MyError=1
	end if
end if

WScript.Quit MyError
