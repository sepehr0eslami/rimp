cmake_minimum_required(VERSION 3.11.0)

project(rimp VERSION 1.1.1)

# Variables for important folders.
include("${PROJECT_SOURCE_DIR}/cmake/folders.cmake")

# Using modern C++.
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${cmake_dir}/Modules")
# So I can include configured files from "src/" directory without using "../"
set(CMAKE_INCLUDE_CURRENT_DIR On)

# Put the VERSION variable defined in "project()" command above, to
# a header file so I can use it in all of the source files.
configure_file("${cmake_dir}/rimp_version.h.in" rimp_version.h)

# When building in Debug mode, Check the code-style.
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    include("${cmake_dir}/check_code_style.cmake")
endif()

add_subdirectory(external/SQLite)

# Variable for the actuall source files that need to be compiled.
file(GLOB_RECURSE source_files "${source_dir}/*.cpp")

# Build the project's executable
add_executable(rimp ${source_files})

target_link_libraries(rimp PUBLIC SQLite3)

install(TARGETS rimp DESTINATION "bin")

option(COMP_INSTALL "Whether to Install Shell Completion Scripts or Not" ON)
if(${COMP_INSTALL})
    include ("${cmake_dir}/completion_install.cmake")
endif()
