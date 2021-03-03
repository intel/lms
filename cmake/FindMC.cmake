# SPDX-License-Identifier: Apache-2.0
# Copyright (C) 2021 Intel Corporation

#CMAKE_MC_COMPILER - path to mc.exe
if(WIN32)
  if("${CMAKE_GENERATOR}" MATCHES "Visual Studio")
    get_filename_component(kit10_dir "[HKEY_LOCAL_MACHINE\\SOFTWARE\\Microsoft\\Windows Kits\\Installed Roots;KitsRoot10]" REALPATH)
    file(GLOB kit10_list ${kit10_dir}/bin/10.*)
    if(X64)
      foreach(tmp_elem ${kit10_list})
        if(IS_DIRECTORY ${tmp_elem})
          list(APPEND kit10_bindir "${tmp_elem}/x64")
        endif()
      endforeach()
    else()
      foreach(tmp_elem ${kit10_list})
        if(IS_DIRECTORY ${tmp_elem})
          list(APPEND kit10_bindir "${tmp_elem}/x86")
        endif()
      endforeach()
    endif()
  endif()
  find_program (CMAKE_MC_COMPILER mc.exe HINTS ${kit10_bindir} REQUIRED)
endif()