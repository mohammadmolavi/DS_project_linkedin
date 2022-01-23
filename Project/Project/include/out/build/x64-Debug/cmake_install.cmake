# Install script for directory: G:/term 3/Data Structures/finalproject-mohammadmolavi/Project/Project/include

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "G:/term 3/Data Structures/finalproject-mohammadmolavi/Project/Project/include/out/install/x64-Debug")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Debug")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/json/allocator.h;/json/assertions.h;/json/config.h;/json/forwards.h;/json/json.h;/json/json_features.h;/json/reader.h;/json/value.h;/json/version.h;/json/writer.h")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "/json" TYPE FILE FILES
    "G:/term 3/Data Structures/finalproject-mohammadmolavi/Project/Project/include/json/allocator.h"
    "G:/term 3/Data Structures/finalproject-mohammadmolavi/Project/Project/include/json/assertions.h"
    "G:/term 3/Data Structures/finalproject-mohammadmolavi/Project/Project/include/json/config.h"
    "G:/term 3/Data Structures/finalproject-mohammadmolavi/Project/Project/include/json/forwards.h"
    "G:/term 3/Data Structures/finalproject-mohammadmolavi/Project/Project/include/json/json.h"
    "G:/term 3/Data Structures/finalproject-mohammadmolavi/Project/Project/include/json/json_features.h"
    "G:/term 3/Data Structures/finalproject-mohammadmolavi/Project/Project/include/json/reader.h"
    "G:/term 3/Data Structures/finalproject-mohammadmolavi/Project/Project/include/json/value.h"
    "G:/term 3/Data Structures/finalproject-mohammadmolavi/Project/Project/include/json/version.h"
    "G:/term 3/Data Structures/finalproject-mohammadmolavi/Project/Project/include/json/writer.h"
    )
endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "G:/term 3/Data Structures/finalproject-mohammadmolavi/Project/Project/include/out/build/x64-Debug/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
