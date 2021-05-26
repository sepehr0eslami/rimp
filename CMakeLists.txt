cmake_minimum_required(VERSION 3.0.0)

project(Rimp VERSION 0.0.0)

# Using modern C++.
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# So I can include configured files from "src/" directory without using "../"
set(CMAKE_INCLUDE_CURRENT_DIR On)

# Variable for the folder containing CMake/Project related files.
set(cmake_folder "${PROJECT_SOURCE_DIR}/cmake")

# Put the VERSION variable defined in "project()" command above, to
# a header file so I can use it in all of the source files.
configure_file("${cmake_folder}/rimp_version.h.in" rimp_version.h)

# When building in Debug mode, Check the code-style.
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    include("${cmake_folder}/check_code_style.cmake")
endif()

# Variables for actuall source_dir and source_files to be compiled.
set(source_dir "${PROJECT_SOURCE_DIR}/src")
file(GLOB_RECURSE source_files "${source_dir}/*.cpp")

# Build the project's executable
add_executable(${PROJECT_NAME} ${source_files})