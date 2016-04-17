#/****************************************************************************
# Copyright (c) 2013-2014 cocos2d-x.org
# Copyright (c) 2015 Chukong Technologies Inc.
#
# http://www.cocos2d-x.org
#
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:

# The above copyright notice and this permission notice shall be included in
# all copies or substantial portions of the Software.

# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
# THE SOFTWARE.
# ****************************************************************************/
cmake_minimum_required(VERSION 3.1)

include(cmake/PCHSupport.cmake)
include(cmake/SetupCocos2d.cmake)

set(APP_NAME MyGame)
project (${APP_NAME})

set(SDK_ROOT ${CMAKE_SOURCE_DIR}/../SDK/)

set(PLATFORM_SPECIFIC_SRC)
set(PLATFORM_SPECIFIC_HEADERS)
if(MACOSX OR APPLE)
    set(PLATFORM_SPECIFIC_SRC
      proj.ios_mac/mac/main.cpp
    )
elseif(LINUX)
    set(PLATFORM_SPECIFIC_SRC
      proj.linux/main.cpp
    )
elseif ( WIN32 )
    set(PLATFORM_SPECIFIC_SRC
      proj.win32/main.cpp
    )
    set(PLATFORM_SPECIFIC_HEADERS
      proj.win32/main.h
      proj.win32/resource.h
    )
elseif(ANDROID)
    set(PLATFORM_SPECIFIC_SRC
      proj.android-studio/app/jni/hellocpp/main.cpp
    )
endif()


include_directories(
  /usr/include/GLFW
  ${SDK_ROOT}/include/cocos2d/cocos
  ${SDK_ROOT}/include/cocos2d/cocos/platform
  ${SDK_ROOT}/include/cocos2d/cocos/audio/include
  ${CMAKE_CURRENT_SOURCE_DIR}/includes
)
link_directories(
  ${SDK_ROOT}/lib32
)

aux_source_directory(Classes CLASSES_SRC)
file (GLOB CLASSES_HEADERS "Classes/*.h")
set(GAME_SRC
  ${CLASSES_DIR}
  ${PLATFORM_SPECIFIC_SRC}
)
set(GAME_HEADERS
  ${CLASSES_SRC}
  ${PLATFORM_SPECIFIC_HEADERS}
  ${CMAKE_CURRENT_SOURCE_DIR}/includes/cocos_custom.h
)
add_executable(${APP_NAME} ${GAME_SRC} ${GAME_HEADERS})
target_link_libraries(${APP_NAME}
    cocos2d cocos2dInternal tinyxml2 unzip xxhash recast flatbuffers
    z freetype fontconfig webp tiff png12 jpeg GLEW glfw GL X11 pthread)

set(APP_BIN_DIR "${CMAKE_BINARY_DIR}/bin")

set_target_properties(${APP_NAME} PROPERTIES
     RUNTIME_OUTPUT_DIRECTORY  "${APP_BIN_DIR}")

if ( WIN32 )
  #also copying dlls to binary directory for the executable to run
  add_custom_command(
    TARGET ${APP_NAME}
    PRE_BUILD
    COMMAND ${CMAKE_COMMAND} -E remove_directory ${APP_BIN_DIR}/Resources
    COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_CURRENT_SOURCE_DIR}/Resources ${APP_BIN_DIR}/Resources
    COMMENT " Running Resource directory copying"
    )
elseif( ANDROID )

else()
  add_custom_command(
    TARGET ${APP_NAME}
    PRE_BUILD
    COMMAND ${CMAKE_COMMAND} -E remove_directory ${APP_BIN_DIR}/Resources
    COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_CURRENT_SOURCE_DIR}/Resources ${APP_BIN_DIR}/Resources
    COMMENT " Running Resource directory copying"
    )
endif()
